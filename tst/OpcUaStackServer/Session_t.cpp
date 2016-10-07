#include "unittest.h"
#include "OpcUaStackCore/Base/Config.h"
#include "OpcUaStackCore/Base/IOService.h"
#include "OpcUaStackCore/Base/Utility.h"
#include "OpcUaStackCore/Base/ConfigXml.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaIdentifier.h"
#include "OpcUaStackCore/ServiceSet/AnonymousIdentityToken.h"
#include "OpcUaStackCore/ServiceSet/ExtensibleParameter.h"
#include "OpcUaStackCore/ServiceSet/EventFilter.h"
#include "OpcUaStackCore/ServiceSet/LiteralOperand.h"

#include "OpcUaStackServer/NodeSet/NodeSetXmlParser.h"
#include "OpcUaStackServer/InformationModel/InformationModelNodeSet.h"
#include "OpcUaStackServer/ServiceSet/SessionManager.h"
#include "OpcUaStackServer/ServiceSet/DiscoveryService.h"
#include "OpcUaStackServer/ServiceSet/EndpointDescriptionConfig.h"
#include "OpcUaStackServer/ServiceManager/ServiceManager.h"

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
	Config serverConfig;
	IOService ioService;

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
	endpoint.addValue("DiscoveryUrl", "opc.tcp://localhost:4841/0.0.0.0");
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
	endpoint.addValue("DiscoveryUrl", "opc.tcp://localhost:4841/0.0.0.0");
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
	endpoint.addValue("DiscoveryUrl", "opc.tcp://localhost:4841/0.0.0.0");
	endpoint.setValue("SecurityPolicyUri", "http://opcfoundation.org/UA/SecurityPolicy#None");

	userTokenPolicy.clear();
	userTokenPolicy.setValue("PolicyId", "OpcUaStack");
	userTokenPolicy.setValue("TokenType", "Anonymous");
	endpoint.setChild("UserTokenPolicy", userTokenPolicy);

	endpoint.setValue("TransportProfileUri", "http://opcfoundation.org/UA-Profile/Transport/uatcp-uasc-uabinary");
	endpoint.setValue("SecurityLevel", "3");
	serverConfig.addChild("TestConfig.EndpointDescription", endpoint);


	boost::optional<Config> childConfig = serverConfig.getChild("TestConfig");
	EndpointDescriptionArray::SPtr endpointDescriptionArray = EndpointDescriptionArray::construct();
	rc = EndpointDescriptionConfig::endpointDescriptions(
		endpointDescriptionArray, 
		"TestConfig", 
		&*childConfig,
		"Unknown"
	);
	BOOST_REQUIRE(rc == true);
	

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// server configuration : secure channel
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	serverConfig.setValue("TestConfig.EndpointUrl", "opc.tcp://" + std::string(TEST_HOST) + ":" + std::string(TEST_PORT));


	ExtensibleParameter ep;
	ep.registerFactoryElement<AnonymousIdentityToken>(OpcUaId_AnonymousIdentityToken_Encoding_DefaultBinary);
	ep.registerFactoryElement<EventFilter>(OpcUaId_EventFilter_Encoding_DefaultBinary);
	ep.registerFactoryElement<LiteralOperand>(OpcUaId_LiteralOperand_Encoding_DefaultBinary);

	ConfigXml configXml;
	NodeSetXmlParser nodeSetXmlParser;
	InformationModel::SPtr informationModel = InformationModel::construct();
	SessionManager sessionManager;
	ServiceManager serviceManager;

	//
	// create information model
	//
	BOOST_REQUIRE(configXml.parse("TestData/Opc.Ua.NodeSet2.xml") == true);
	BOOST_REQUIRE(nodeSetXmlParser.decode(configXml.ptree()) == true);
	BOOST_REQUIRE(InformationModelNodeSet::initial(informationModel, nodeSetXmlParser) == true);

	OpcUaString::SPtr stringValue;
	

	{ // set NamespaceArray	
		OpcUaVariant variant;
		
		stringValue = OpcUaString::construct();
		*stringValue = "http://opcfoundation.org/UA/";
		variant.variant(0, stringValue);
		
		variant.arrayLength(1);
		BOOST_REQUIRE(informationModel->setValue(OpcUaId_Server_NamespaceArray, AttributeId_Value, variant) == true);
	}

	{ // ServerStatus
		OpcUaVariant variant;
		variant.variant((OpcUaUInt32)0);
		BOOST_REQUIRE(informationModel->setValue(OpcUaId_Server_ServerStatus_State, AttributeId_Value, variant) == true);
	}
	

	//
	// create services
	// 
	BOOST_REQUIRE(serviceManager.init(sessionManager) == true);
	BOOST_REQUIRE(serviceManager.informatinModel(informationModel) == true);
	BOOST_REQUIRE(serviceManager.ioService(&ioService));
	serviceManager.init();


	//
	// create session manager
	//
	DiscoveryService::SPtr discoveryService = DiscoveryService::construct();
	discoveryService->endpointDescriptionArray(endpointDescriptionArray);
	sessionManager.discoveryService(discoveryService);
	sessionManager.ioService(&ioService);
	
	//
	// start session manager
	//
	ioService.start();
	sessionManager.openServerSocket(
		"TestConfig", serverConfig,
		"TestConfig", serverConfig
	);
	
	IOService::secSleep(40000);

	ioService.stop();
}

BOOST_AUTO_TEST_SUITE_END()