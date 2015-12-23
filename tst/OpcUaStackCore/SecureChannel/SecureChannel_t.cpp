
#include "unittest.h"
#include "OpcUaStackCore/SecureChannel/SecureChannelClient.h"

using namespace OpcUaStackCore;

class SecureChannelClientTest
: public SecureChannelClientIf
{
  public:
	void handleError(SecureChannel* secureChannel)
  	{
		std::cout << "handleError" << std::endl;
	}

	void handleConnect(SecureChannel* secureChannel)
	{
		std::cout << "handleConnect" << std::endl;
	}

	void handleDisconnect(SecureChannel* secureChannel)
	{
		std::cout << "handleConnect" << std::endl;
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

	// client connect to server

}

BOOST_AUTO_TEST_SUITE_END()
