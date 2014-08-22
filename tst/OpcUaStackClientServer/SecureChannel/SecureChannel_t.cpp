#include "unittest.h"
#include "OpcUaStackCore/Base/Config.h"
#include "OpcUaStackClient/SecureChannel/SecureChannelClient.h"
#include "OpcUaStackClient/SecureChannel/SecureChannelClientConfig.h"
#include "OpcUaStackServer/SecureChannel/SecureChannelServer.h"
#include "OpcUaStackServer/SecureChannel/SecureChannelServerConfig.h"
#include "OpcUaStackCore/TCPChannel/TCPTestHandler.h"
#include "OpcUaStackCore/TCPChannel/TCPAcceptor.h"

#include <boost/asio/error.hpp>

#define SOCKET_ADDRESS	"127.0.0.1"
#define SOCKET_PORT		4841

using namespace OpcUaStackCore;
using namespace OpcUaStackClient;
using namespace OpcUaStackServer;

BOOST_AUTO_TEST_SUITE(SecureChannel_)

BOOST_AUTO_TEST_CASE(SecureChannel_)
{
	std::cout << "SecureChannel_t" << std::endl;
}

BOOST_AUTO_TEST_CASE(SecureChannel_open)
{
	TCPTestHandler tcpTestHandler;
	IOService ioService;
	TCPAcceptor tcpAcceptor(ioService.io_service(), SOCKET_ADDRESS, SOCKET_PORT);
	ioService.start(1);

	Config* config = Config::instance();
	config->clear();
	config->setValue("TestConfigServer.EndpointUrl", "opc.tcp://127.0.0.1:4841");
	config->setValue("TestConfigClient.EndpointUrl", "opc.tcp://127.0.0.1:4841");
	config->setValue("TestConfigClient.SecurityPolicyUri", "http://opcfoundation.org/UA/SecurityPolicy#None");

	SecureChannelServer::SPtr secureChannelServer = SecureChannelServer::construct(ioService);
	SecureChannelServerConfig::initial(secureChannelServer, "TestConfigServer");

	tcpTestHandler.handleAcceptCondition_.condition(0, 1);
	tcpAcceptor.listen();
	tcpAcceptor.async_accept(
		secureChannelServer->tcpConnection().socket(),
		boost::bind(&TCPTestHandler::handleAccept, &tcpTestHandler, boost::asio::placeholders::error)
	);

	SecureChannelClient::SPtr secureChannelClient = SecureChannelClient::construct(ioService);
	SecureChannelClientConfig::initial(secureChannelClient, "TestConfigClient");
	secureChannelClient->connect();

	BOOST_REQUIRE(tcpTestHandler.handleAcceptCondition_.waitForCondition(1000) == true);
	secureChannelServer->connect();

	IOService::msecSleep(10000000);

	Config::destroy();
	ioService.stop();
}

BOOST_AUTO_TEST_SUITE_END()