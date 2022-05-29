#include "unittest.h"

#include <future>

#include "OpcUaStackPubSub/Connection/UDPConnection.h"
#include "OpcUaStackPubSub/MessageTransport/MessageTransport.h"
#include "OpcUaStackPubSub/NetworkMessageWriterGroup/NetworkMessageWriterGroup.h"
#include "OpcUaStackPubSub/NetworkMessage/NetworkMessage.h"
//#include "OpcUaStackPubSub/NetworkMessage/NetworkMessageHeader.h"

using namespace OpcUaStackCore;
using namespace OpcUaStackPubSub;

class DLLEXPORT TestUDPConnection
{
  public:

	TestUDPConnection(std::promise<void>* promise) {
		promise_ = promise;
	}

	~TestUDPConnection(void) {
	}

	void
	receive(MessageBusError error, const MessageBusMember::WPtr& handleFrom, Message::SPtr& message) {
		event_ = boost::static_pointer_cast<NetworkRecvEvent>(message);
		promise_->set_value();
	}

	std::promise<void>* promise_ = nullptr;
	NetworkRecvEvent::SPtr event_;
};

BOOST_AUTO_TEST_SUITE(MessageTransport_)

BOOST_AUTO_TEST_CASE(MessageTransport_)
{
	std::cout << "MessageTransport_t" << std::endl;
}


BOOST_AUTO_TEST_CASE(MessageTransport_send_receive_message)
{
	// start thread pool
	auto ioThread = boost::make_shared<IOThread>("TestThread1");
	ioThread->numberThreads(6);
	BOOST_REQUIRE(ioThread->startup() == true);

	// start message bus
	MessageBusConfig messageBusConfig;
	messageBusConfig.ioThread(ioThread);
	MessageBus::SPtr messageBus = boost::make_shared<MessageBus>(messageBusConfig);

	// register sender and receiver
	auto udpConnectionMember = messageBus->registerMember("UDPConnection");
	auto messageTransportMember = messageBus->registerMember("MessageTransport");
	auto receiver = messageBus->registerMember("receiver");

	// create udp connection
	auto udpConnection = boost::make_shared<UDPConnection>(
		"127.0.0.1",				// receiver address
		5678,						// receiver port
		"127.0.0.1",				// target address
		5679,						// target port
		"MessageTransport",	     	// message bus name of the message transport module
		"UDPConnection",			// message bus name of the udp connection module
		ioThread,					// thread
		messageBus					// message bus
	);
	udpConnection->startup();

	auto messageTransport = boost::make_shared<MessageTransport>(
		"receiver",
		"MessageTransport",
		ioThread,
		messageBus
	);
	messageTransport->startup();

	// receive
	std::promise<void> promise;
	auto future = promise.get_future();
	TestUDPConnection testCon(&promise);

	messageBus->messageReceive(
	    receiver,
		[&testCon](MessageBusError error, const MessageBusMember::WPtr& handleFrom, Message::SPtr& message) mutable {
			testCon.receive(error, handleFrom, message);
		}
	);

	// send network message to message transport module
	auto event = boost::make_shared<NetworkSendEvent>();
	std::ostream os(&event->streamBuf());
	os << "Dies ist eine Message";
	
	messageBus->messageSend(udpConnectionMember, messageTransportMember, event);
    
	// wait for receiver to finish
	BOOST_REQUIRE(future.wait_for(std::chrono::seconds(1)) == std::future_status::ready);

	// check received message
	boost::asio::streambuf::const_buffers_type bufs = testCon.event_->streamBuf().data();
	std::string str(
		boost::asio::buffers_begin(bufs),
		boost::asio::buffers_begin(bufs) + testCon.event_->streamBuf().size()
	);

	BOOST_REQUIRE(str == std::string("Dies ist eine Message"));

	messageTransport->shutdown();
	messageTransport.reset();

	// delete udp connection
	udpConnection->shutdown();
    udpConnection.reset();	
	
	// stop thread pool
	BOOST_REQUIRE(ioThread->shutdown() == true);
}

BOOST_AUTO_TEST_SUITE_END()