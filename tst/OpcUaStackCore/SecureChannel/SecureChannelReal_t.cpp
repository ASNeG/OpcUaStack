
#include "unittest.h"
#include "OpcUaStackCore/Base/Condition.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaIdentifier.h"
#include "OpcUaStackCore/SecureChannel/SecureChannelClient.h"
#include "OpcUaStackCore/ServiceSet/GetEndpointsRequest.h"

using namespace OpcUaStackCore;

class SecureChannelClientRealTest
: public SecureChannelClientIf
{
  public:
	Condition handleConnect_;
	void handleConnect(SecureChannel* secureChannel)
	{
		std::cout << "handleConnect" << std::endl;
		handleConnect_.conditionValueDec();
	}

	Condition handleDisconnect_;
	void handleDisconnect(SecureChannel* secureChannel)
	{
		std::cout << "handleDisconnect" << std::endl;
		handleDisconnect_.conditionValueDec();
	}

	Condition handleMessageResponse_;
	void handleMessageResponse(SecureChannel* secureChannel)
	{
		std::cout << "handleMessageRequest" << std::endl;
		handleMessageResponse_.conditionValueDec();
	}
};

BOOST_AUTO_TEST_SUITE(SecureChannelReal_)

BOOST_AUTO_TEST_CASE(SecureChannel)
{
	std::cout << "SecureChannelReal_t" << std::endl;
}

BOOST_AUTO_TEST_CASE(SecureChannelReal_Connect_Disconnect)
{
	OpcUaStackCore::SecureChannel* secureChannel;
	SecureChannelClientRealTest secureChannelClientTest;

	IOThread ioThread;
	ioThread.startup();

	SecureChannelClient secureChannelClient(&ioThread);
	secureChannelClient.secureChannelClientIf(&secureChannelClientTest);

	// client connect to server
	secureChannelClientTest.handleConnect_.condition(1,0);
	SecureChannelClientConfig::SPtr secureChannelClientConfig = construct<SecureChannelClientConfig>();
	secureChannelClientConfig->endpointUrl("opt.tcp://192.168.122.99:48010");
	secureChannelClientConfig->debug(false);
	secureChannelClientConfig->debugHeader(true);
	secureChannel = secureChannelClient.connect(secureChannelClientConfig);
	BOOST_REQUIRE(secureChannel != nullptr);
	BOOST_REQUIRE(secureChannelClientTest.handleConnect_.waitForCondition(1000) == true);

	// diconnect
	secureChannelClientTest.handleDisconnect_.condition(1,0);
	secureChannelClient.disconnect(secureChannel);
	BOOST_REQUIRE(secureChannelClientTest.handleDisconnect_.waitForCondition(1000) == true);

	ioThread.shutdown();
}

BOOST_AUTO_TEST_CASE(SecureChannelReal_Connect_Disconnect_with_a_second_channel)
{
	OpcUaStackCore::SecureChannel* secureChannel1;
	OpcUaStackCore::SecureChannel* secureChannel2;
	SecureChannelClientRealTest secureChannelClientTest;

	IOThread ioThread;
	ioThread.startup();

	SecureChannelClient secureChannelClient(&ioThread);
	secureChannelClient.secureChannelClientIf(&secureChannelClientTest);

	SecureChannelClientConfig::SPtr secureChannelClientConfig = construct<SecureChannelClientConfig>();
	secureChannelClientConfig->endpointUrl("opt.tcp://192.168.122.99:48010");
	secureChannelClientConfig->debug(false);
	secureChannelClientConfig->debugHeader(true);

	// client connect to server
	secureChannelClientTest.handleConnect_.condition(1,0);
	secureChannel1 = secureChannelClient.connect(secureChannelClientConfig);
	BOOST_REQUIRE(secureChannel1 != nullptr);
	BOOST_REQUIRE(secureChannelClientTest.handleConnect_.waitForCondition(1000) == true);

	// client connect to server
	secureChannelClientTest.handleConnect_.condition(1,0);
	secureChannel2 = secureChannelClient.connect(secureChannelClientConfig);
	BOOST_REQUIRE(secureChannel2 != nullptr);
	BOOST_REQUIRE(secureChannelClientTest.handleConnect_.waitForCondition(1000) == true);

	// diconnect
	secureChannelClientTest.handleDisconnect_.condition(1,0);
	secureChannelClient.disconnect(secureChannel1);
	BOOST_REQUIRE(secureChannelClientTest.handleDisconnect_.waitForCondition(1000) == true);

	// diconnect
	secureChannelClientTest.handleDisconnect_.condition(1,0);
	secureChannelClient.disconnect(secureChannel2);
	BOOST_REQUIRE(secureChannelClientTest.handleDisconnect_.waitForCondition(1000) == true);

	ioThread.shutdown();
}

BOOST_AUTO_TEST_CASE(SecureChannelReal_Connect_SendRequest_ReceiveResponse_Disconnect)
{
	OpcUaStackCore::SecureChannel* secureChannel;
	SecureChannelClientRealTest secureChannelClientTest;

	IOThread ioThread;
	ioThread.startup();

	SecureChannelClient secureChannelClient(&ioThread);
	secureChannelClient.secureChannelClientIf(&secureChannelClientTest);

	// client connect to server
	secureChannelClientTest.handleConnect_.condition(1,0);
	SecureChannelClientConfig::SPtr secureChannelClientConfig = construct<SecureChannelClientConfig>();
	secureChannelClientConfig->endpointUrl("opt.tcp://192.168.122.99:48010");
	secureChannelClientConfig->debug(true);
	secureChannelClientConfig->debugHeader(true);
	secureChannel = secureChannelClient.connect(secureChannelClientConfig);
	BOOST_REQUIRE(secureChannel != nullptr);
	BOOST_REQUIRE(secureChannelClientTest.handleConnect_.waitForCondition(1000) == true);

	// send request
	boost::asio::streambuf sb;
	std::iostream os(&sb);
	GetEndpointsRequest getEndpointsRequest;
	getEndpointsRequest.endpointUrl("opt.tcp://192.168.122.99:48010");
	getEndpointsRequest.opcUaBinaryEncode(os);

	SecureChannelTransaction::SPtr secureChannelTransaction = SecureChannelTransaction::construct();
	secureChannelTransaction->requestTypeNodeId_. nodeId((uint32_t)OpcUaId_GetEndpointsRequest_Encoding_DefaultBinary);
	secureChannelTransaction->requestId_ = 123;
	secureChannelTransaction->osAppend(sb);

	secureChannelClientTest.handleMessageResponse_.condition(1,0);
	secureChannelClient.asyncWriteMessageRequest(secureChannel, secureChannelTransaction);
	BOOST_REQUIRE(secureChannelClientTest.handleMessageResponse_.waitForCondition(1000) == true);

	// diconnect
	secureChannelClientTest.handleDisconnect_.condition(1,0);
	secureChannelClient.disconnect(secureChannel);
	BOOST_REQUIRE(secureChannelClientTest.handleDisconnect_.waitForCondition(1000) == true);

	ioThread.shutdown();
}

BOOST_AUTO_TEST_SUITE_END()
