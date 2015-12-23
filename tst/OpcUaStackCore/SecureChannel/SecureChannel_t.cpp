
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

	Condition handleEstablished_;
	void handleEstablished(SecureChannel* secureChannel)
	{
		std::cout << "handleEstablished" << std::endl;
		handleEstablished_.conditionValueDec();
	}
};

BOOST_AUTO_TEST_SUITE(SecureChannel_)

BOOST_AUTO_TEST_CASE(SecureChannel)
{
	std::cout << "SecureChannel_t" << std::endl;
}

BOOST_AUTO_TEST_CASE(SecureChannel_Connect_Disconnect)
{
	SecureChannelClientTest secureChannelClientTest;

	IOService ioService;
	ioService.start(1);

	SecureChannelClient secureChannelClient(&ioService);
	secureChannelClient.secureChannelClientIf(&secureChannelClientTest);

	// client connect to server
	secureChannelClientTest.handleConnect_.condition(1,0);
	secureChannelClientTest.handleEstablished_.condition(1,0);
	SecureChannelClientData secureChannelClientData;
	secureChannelClientData.endpointUrl("opt.tcp://192.168.122.99:48010");
	secureChannelClientData.debug(false);
	secureChannelClientData.debugHeader(true);
	BOOST_REQUIRE(secureChannelClient.connect(secureChannelClientData) == true);
	BOOST_REQUIRE(secureChannelClientTest.handleConnect_.waitForCondition(1000) == true);
	BOOST_REQUIRE(secureChannelClientTest.handleEstablished_.waitForCondition(1000) == true);
}

BOOST_AUTO_TEST_SUITE_END()
