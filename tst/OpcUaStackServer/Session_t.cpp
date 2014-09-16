#include "unittest.h"
#include "OpcUaStackCore/Base/Config.h"
#include "OpcUaStackCore/Base/IOService.h"
#include "OpcUaStackCore/Base/Utility.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaIdentifier.h"
#include "OpcUaStackCore/ServiceSet/AnonymousIdentityToken.h"
#include "OpcUaStackCore/ServiceSet/ExtensibleParameter.h"

#include "OpcUaStackServer/ServiceSet/SessionManager.h"
#include "OpcUaStackServer/ServiceSet/AttributeService.h"

#include <boost/asio/error.hpp>


#define TEST_HOST		"127.0.0.1"
#define TEST_PORT		"4842"


using namespace OpcUaStackCore;
using namespace OpcUaStackServer;

BOOST_AUTO_TEST_SUITE(Session_)

BOOST_AUTO_TEST_CASE(Session_)
{
	std::cout << "Session_t" << std::endl;
}

BOOST_AUTO_TEST_CASE(Session_open)
{
	bool rc;

	ExtensibleParameter ep;
	ep.registerFactoryElement<AnonymousIdentityToken>(OpcUaId_AnonymousIdentityToken_Encoding_DefaultBinary);

	OpcUaStackServer::SessionManager sessionManagerServer;

	OpcUaStackServer::AttributeService attributeServiceServer;
	
	TransactionManager::SPtr transactionManager = TransactionManager::construct();
	ServiceTransactionRead::SPtr serviceTransactionReadSPtr = ServiceTransactionRead::construct();
	serviceTransactionReadSPtr->serviceTransactionIfService(&attributeServiceServer);
	transactionManager->registerTransaction(serviceTransactionReadSPtr);
	sessionManagerServer.transactionManager(transactionManager);
	
	sessionManagerServer.start();

	Config serverConfig;

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// server configuration : session
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	Config endpoint;
	Config userTokenPolicy;

	endpoint.clear();
	endpoint.setValue("EndpointUrl", "opc.tcp://" + std::string(TEST_HOST) + ":" + std::string(TEST_PORT) + "/0.0.0.0");
	endpoint.setValue("ApplicationUri", "urn:localhost:compyny:Unittest");
	endpoint.setValue("ProductUri", "urn:company:Unittest");
	endpoint.setValue("ApplicationName", "company Unittest");
	endpoint.addValue("DiscoveryUrl", "opt.tcp://localhost:4841/0.0.0.0");
	endpoint.setValue("SecurityPolicyUri", "http://opcfoundation.org/UA/SecurityPolicy#None");

	userTokenPolicy.clear();
	userTokenPolicy.setValue("PolicyId", "OpcUaStack");
	userTokenPolicy.setValue("TokenType", "Anonymous");
	endpoint.setChild("UserTokenPolicy", userTokenPolicy);

	endpoint.setValue("TransportProfileUri", "http://opcfoundation.org/UA-Profile/Transport/uatcp-uasc-uabinary");
	endpoint.setValue("SecurityLevel", "0");
	serverConfig.addChild("TestConfig.EndpointDescription", endpoint);


	endpoint.clear();
	endpoint.setValue("EndpointUrl", "opc.tcp://" + std::string(TEST_HOST) + ":" + std::string(TEST_PORT) + "/0.0.0.0");
	endpoint.setValue("ApplicationUri", "urn:localhost:compyny:Unittest");
	endpoint.setValue("ProductUri", "urn:company:Unittest");
	endpoint.setValue("ApplicationName", "company Unittest");
	endpoint.addValue("DiscoveryUrl", "opt.tcp://localhost:4841/0.0.0.0");
	endpoint.setValue("SecurityPolicyUri", "http://opcfoundation.org/UA/SecurityPolicy#None");

	userTokenPolicy.clear();
	userTokenPolicy.setValue("PolicyId", "OpcUaStack");
	userTokenPolicy.setValue("TokenType", "Anonymous");
	endpoint.setChild("UserTokenPolicy", userTokenPolicy);

	endpoint.setValue("TransportProfileUri", "http://opcfoundation.org/UA-Profile/Transport/uatcp-uasc-uabinary");
	endpoint.setValue("SecurityLevel", "1");
	serverConfig.addChild("TestConfig.EndpointDescription", endpoint);


	endpoint.clear();
	endpoint.setValue("EndpointUrl", "opc.tcp://" + std::string(TEST_HOST) + ":" + std::string(TEST_PORT) + "/0.0.0.0");
	endpoint.setValue("ApplicationUri", "urn:localhost:compyny:Unittest");
	endpoint.setValue("ProductUri", "urn:company:Unittest");
	endpoint.setValue("ApplicationName", "company Unittest");
	endpoint.addValue("DiscoveryUrl", "opt.tcp://localhost:4841/0.0.0.0");
	endpoint.setValue("SecurityPolicyUri", "http://opcfoundation.org/UA/SecurityPolicy#None");

	userTokenPolicy.clear();
	userTokenPolicy.setValue("PolicyId", "OpcUaStack");
	userTokenPolicy.setValue("TokenType", "Anonymous");
	endpoint.setChild("UserTokenPolicy", userTokenPolicy);

	endpoint.setValue("TransportProfileUri", "http://opcfoundation.org/UA-Profile/Transport/uatcp-uasc-uabinary");
	endpoint.setValue("SecurityLevel", "3");
	serverConfig.addChild("TestConfig.EndpointDescription", endpoint);

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// server configuration : secure channel
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	serverConfig.setValue("TestConfig.EndpointUrl", "opc.tcp://" + std::string(TEST_HOST) + ":" + std::string(TEST_PORT));

	rc = sessionManagerServer.openServerSocket(
		"TestConfig", serverConfig,
		"TestConfig", serverConfig
	);
	BOOST_REQUIRE(rc == true);

	IOService::secSleep(40000);

	sessionManagerServer.stop();
}

BOOST_AUTO_TEST_SUITE_END()