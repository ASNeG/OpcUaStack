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
		receiveCondition_.conditionValueInc();
		return true;
	}

	Condition receiveCondition_;
	NetworkMessage receivedMessage_;
};

BOOST_AUTO_TEST_SUITE(UDPConnectionManager_)

BOOST_AUTO_TEST_CASE(UDPConnectionManager_)
{
	std::cout << "UDPConnectionManager_t" << std::endl;
}

BOOST_AUTO_TEST_CASE(UDPConnectionManager_HandleUDPMessage)
{
	IOThread::SPtr ioThread = constructSPtr<IOThread>();
	ioThread->startup();

	UDPConnectionManager connManager;
	MockNetworkReceiver::SPtr receiver = constructSPtr<MockNetworkReceiver>();

	connManager.registerReceiverIf(receiver);
	connManager.ioThread(ioThread);
	BOOST_REQUIRE(connManager.startup() == true);

	boost::asio::ip::udp::endpoint connManagerEndpoint(
				boost::asio::ip::address::from_string(connManager.address()),
				connManager.port());

	// create UDP client
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

	BOOST_REQUIRE(udpClient.open() == true);
	receiver->receiveCondition_.condition(0, 1);
	udpClient.sendTo(
		buffer,
		connManagerEndpoint
	);

	BOOST_REQUIRE(receiver->receiveCondition_.waitForCondition(10000) == true);
	BOOST_REQUIRE(receiver->receivedMessage_ == message);

	ioThread->shutdown();
	connManager.shutdown();

	udpClient.close();
}

BOOST_AUTO_TEST_SUITE_END()
