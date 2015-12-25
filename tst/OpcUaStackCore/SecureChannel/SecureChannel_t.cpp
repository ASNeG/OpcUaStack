
#include "unittest.h"
#include "OpcUaStackCore/Base/Condition.h"
#include "OpcUaStackCore/SecureChannel/SecureChannelClient.h"

using namespace OpcUaStackCore;

class SecureChannelClientTest
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
};

BOOST_AUTO_TEST_SUITE(SecureChannel_)

BOOST_AUTO_TEST_CASE(SecureChannel)
{
	std::cout << "SecureChannel_t" << std::endl;
}

BOOST_AUTO_TEST_CASE(SecureChannel_Connect_Disconnect)
{
	OpcUaStackCore::SecureChannel* secureChannel;
	SecureChannelClientTest secureChannelClientTest;

	IOService ioService;
	ioService.start(1);

	SecureChannelClient secureChannelClient(&ioService);
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
}

BOOST_AUTO_TEST_SUITE_END()
