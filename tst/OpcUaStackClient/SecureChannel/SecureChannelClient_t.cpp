#include "unittest.h"
#include "OpcUaStackCore/Base/Config.h"
#include "OpcUaStackClient/SecureChannel/SecureChannelClient.h"
#include "OpcUaStackClient/SecureChannel/SecureChannelClientConfig.h"

#include <boost/asio/error.hpp>

using namespace OpcUaStackCore;
using namespace OpcUaStackClient;

BOOST_AUTO_TEST_SUITE(SecureChannelClient_)

BOOST_AUTO_TEST_CASE(SecureChannelClient_)
{
	std::cout << "SecureChannel_t" << std::endl;
}

BOOST_AUTO_TEST_CASE(SecureChannelClient_open)
{
	IOService ioService;
	ioService.start(1);

	Config* config = Config::instance();
	config->clear();
	config->setValue("TestConfig.EndpointUrl", "opc.tcp://127.0.0.1:4841");
	config->setValue("TestConfig.SecurityPolicyUri", "http://opcfoundation.org/UA/SecurityPolicy#None");

	SecureChannelClient::SPtr secureChannelClient = SecureChannelClient::construct(ioService);
	SecureChannelClientConfig::initial(secureChannelClient, "TestConfig");
	secureChannelClient->connect();

	IOService::msecSleep(10000000);

	Config::destroy();
	ioService.stop();
}

BOOST_AUTO_TEST_SUITE_END()
