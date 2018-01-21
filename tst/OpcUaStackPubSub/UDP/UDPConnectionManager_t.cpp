#include "unittest.h"

#include <iostream>
#include <boost/asio.hpp>

#include "OpcUaStackPubSub/UDP/UDPConnectionManager.h"
#include "OpcUaStackPubSub/DataSetMessage/KeepAliveMessage.h"

#include "OpcUaStackCore/Network/UDPClient.h"

using namespace OpcUaStackCore;
using namespace OpcUaStackPubSub;


class MockNetworkReceiver : public NetworkReceiverIf
{
public:
	typedef boost::shared_ptr<MockNetworkReceiver> SPtr;

	MockNetworkReceiver() : NetworkReceiverIf()
	{

	}

	bool receive(const NetworkMessage& message)
	{
		std::cout << "Ujdfkjshdkjf";
		receivedMessage_ = message;
		return true;
	}

	NetworkMessage receivedMessage_;
};

BOOST_AUTO_TEST_SUITE(UDPConnectionManager_)

BOOST_AUTO_TEST_CASE(UDPConnectionManager_)
{
	std::cout << "UDPConnectionManager_t" << std::endl;
}

BOOST_AUTO_TEST_CASE(UDPConnectionManager_HandleUDPMessage)
{
	UDPConnectionManager connManager;
	MockNetworkReceiver::SPtr receiver = constructSPtr<MockNetworkReceiver>();

	connManager.registerReceiverIf(receiver);
	connManager.startup();

	boost::asio::ip::udp::endpoint connManagerEndpoint(
				boost::asio::ip::address::from_string(connManager.address()),
				connManager.port());

	// create UDP client
	IOThread::SPtr ioThread = constructSPtr<IOThread>();
	ioThread->startup();

	UDPClient udpClient;
	udpClient.ioThread(ioThread);
	udpClient.endpoint(connManagerEndpoint);

	NetworkMessage message;
	OpcUaUInt16 writerId = 0x100;
	DataSetMessageArray::SPtr dataSetMessages = constructSPtr<DataSetMessageArray>();
	dataSetMessages->resize(1);
	dataSetMessages->push_back(constructSPtr<KeepAliveMessage>());

	message.dataSetPayloadHeader()->dataSetWriterIds()->resize(1);
	message.dataSetPayloadHeader()->dataSetWriterIds()->push_back(writerId);
	message.dataSetPayload()->count(1);
	message.dataSetPayload()->dataSetMessages(dataSetMessages);


	boost::asio::streambuf buffer;
	std::ostream os(&buffer);
	message.opcUaBinaryEncode(os);

	udpClient.open();
	udpClient.sendTo(
		buffer,
		connManagerEndpoint
	);

	boost::this_thread::sleep_for(boost::chrono::seconds(1));


	BOOST_REQUIRE(receiver->receivedMessage_ == message);


	ioThread->shutdown();
	connManager.shutdown();

	udpClient.close();
}

BOOST_AUTO_TEST_SUITE_END()
