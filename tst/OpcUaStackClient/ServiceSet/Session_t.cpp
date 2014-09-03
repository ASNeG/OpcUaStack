#include "unittest.h"
#include "OpcUaStackCore/Base/Config.h"
#include "OpcUaStackCore/Base/IOService.h"
#include "OpcUaStackCore/Base/Utility.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaIdentifier.h"
#include "OpcUaStackCore/ServiceSet/AnonymousIdentityToken.h"
#include "OpcUaStackCore/ServiceSet/ExtensibleParameter.h"
#include "OpcUaStackClient/ServiceSet/SessionManager.h"
#include "OpcUaStackClient/ServiceSet/SessionTestHandler.h"
#include <boost/asio/error.hpp>

using namespace OpcUaStackCore;
using namespace OpcUaStackClient;

BOOST_AUTO_TEST_SUITE(Session_)

BOOST_AUTO_TEST_CASE(Session_)
{
	std::cout << "Session_t" << std::endl;
}

BOOST_AUTO_TEST_CASE(Session_open)
{
	SessionTestHandler sessionTestHandler;

	ExtensibleParameter ep;
	ep.registerFactoryElement<AnonymousIdentityToken>(OpcUaId_AnonymousIdentityToken_Encoding_DefaultBinary);

	SessionManager sessionManager;
	sessionManager.start();

	Config sessionConfig; 
	sessionConfig.setValue("TestConfig.EndpointUrl", "opc.tcp://127.0.0.1:4841");
	sessionConfig.setValue("TestConfig.SessionName", "urn:127.0.0.1:Company:MyAppl");
	sessionConfig.setValue("TestConfig.ApplicationDescription.ApplicationUri", "urn:127.0.0.1:Company:MyAppl");
	sessionConfig.setValue("TestConfig.ApplicationDescription.ProductUri", "urn:Company:MyAppl");
	sessionConfig.setValue("TestConfig.ApplicationDescription.ApplicationName.Locale", "en");
	sessionConfig.setValue("TestConfig.ApplicationDescription.ApplicationName.Text", "MyAppl");

	Config secureChannelConfig;
	secureChannelConfig.setValue("TestConfig.EndpointUrl", "opc.tcp://127.0.0.1:4841");
	secureChannelConfig.setValue("TestConfig.SecurityPolicyUri", "http://opcfoundation.org/UA/SecurityPolicy#None");

	Session::SPtr session = sessionManager.getNewSession(
		"TestConfig", sessionConfig,
		"TestConfig", secureChannelConfig,
		&sessionTestHandler
	);

	// createSession
	sessionTestHandler.createSessionCompleteCondition_.condition(1, 0);
	session->createSession();
	BOOST_REQUIRE(sessionTestHandler.createSessionCompleteCondition_.waitForCondition(1000) == true);

	// activateSession
	sessionTestHandler.activateSessionCompleteCondition_.condition(1, 0);
	session->activateSession();
	BOOST_REQUIRE(sessionTestHandler.activateSessionCompleteCondition_.waitForCondition(1000) == true);

	IOService::secSleep(1000);
	sessionManager.stop();
}

BOOST_AUTO_TEST_SUITE_END()