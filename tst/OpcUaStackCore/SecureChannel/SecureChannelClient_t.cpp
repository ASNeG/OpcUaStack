#include "unittest.h"
#include "OpcUaStackCore/SecureChannel/SecureChannelClient.h"

#include <boost/asio/error.hpp>

using namespace OpcUaStackCore;

BOOST_AUTO_TEST_SUITE(SecureChannelClient_)

BOOST_AUTO_TEST_CASE(SecureChannelClient_)
{
	std::cout << "SecureChannelClient_t" << std::endl;
}

BOOST_AUTO_TEST_CASE(TCPAcceptor_cancel)
{
	IOService ioService;
	ioService.start(1);

	SecurityHeader::SPtr securityHeaderSPtr = SecurityHeader::construct();
	securityHeaderSPtr->securityPolicyUri((OpcUaByte*)"http://opcfoundation.org/UA/SecurityPolicy#None", (OpcUaInt32)strlen("http://opcfoundation.org/UA/SecurityPolicy#None"));

	SecureChannelClient secureChannelClient(ioService);
	secureChannelClient.helloMessage()->endpointUrl("opc.tcp://127.0.0.1:4841");
	secureChannelClient.securityHeader(securityHeaderSPtr);
	secureChannelClient.connect();

	IOService::msecSleep(10000000);

	ioService.stop();
}

BOOST_AUTO_TEST_SUITE_END()
