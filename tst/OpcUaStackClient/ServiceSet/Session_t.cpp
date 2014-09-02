#include "unittest.h"
#include "OpcUaStackCore/Base/Config.h"
#include "OpcUaStackCore/Base/IOService.h"
#include "OpcUaStackCore/Base/Utility.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaIdentifier.h"
#include "OpcUaStackCore/ServiceSet/AnonymousIdentityToken.h"
#include "OpcUaStackCore/ServiceSet/ExtensibleParameter.h"
#include "OpcUaStackClient/ServiceSet/SessionTestHandler.h"
#include "OpcUaStackClient/ServiceSet/Session.h"
#include "OpcUaStackClient/ServiceSet/SessionConfig.h"
#include "opcUaStackClient/SecureChannel/SecureChannelTestHandler.h"
#include "OpcUaStackClient/SecureChannel/SecureChannelClient.h"
#include "OpcUaStackClient/SecureChannel/SecureChannelClientConfig.h"
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
	OpcUaNodeId nodeId;
	SessionTestHandler sessionTestHandler;
	SecureChannelTestHandler secureChannelTestHandler;
	IOService ioService;
	ioService.start(1);

	ExtensibleParameter ep;
	ep.registerFactoryElement<AnonymousIdentityToken>(OpcUaId_AnonymousIdentityToken_Encoding_DefaultBinary);

	Config configSession; 
	configSession.setValue("TestConfig.EndpointUrl", "opc.tcp://127.0.0.1:4841");
	configSession.setValue("TestConfig.SessionName", "urn:127.0.0.1:Company:MyAppl");
	configSession.setValue("TestConfig.ApplicationDescription.ApplicationUri", "urn:127.0.0.1:Company:MyAppl");
	configSession.setValue("TestConfig.ApplicationDescription.ProductUri", "urn:Company:MyAppl");
	configSession.setValue("TestConfig.ApplicationDescription.ApplicationName.Locale", "en");
	configSession.setValue("TestConfig.ApplicationDescription.ApplicationName.Text", "MyAppl");

	Config configSecureChannel;
	configSecureChannel.setValue("TestConfig.EndpointUrl", "opc.tcp://127.0.0.1:4841");
	configSecureChannel.setValue("TestConfig.SecurityPolicyUri", "http://opcfoundation.org/UA/SecurityPolicy#None");

	Session::SPtr session = Session::construct();
	SessionConfig::initial(session, "TestConfig", &configSession);
	session->sessionIf(&sessionTestHandler);
	session->sessionSecureChannelIf(&sessionTestHandler);
	session->sessionApplicationIf(&sessionTestHandler);

	SecureChannelClient::SPtr secureChannel = SecureChannelClient::construct(ioService);
	SecureChannelClientConfig::initial(secureChannel, "TestConfig", &configSecureChannel);
	secureChannel->secureChannelIf(&secureChannelTestHandler);
	secureChannel->debugMode(true);

	//
	// connect to server
	//
	session->connect();
	BOOST_REQUIRE(sessionTestHandler.connectToSecureChannelCount_ == 1);

	secureChannelTestHandler.connectCondition_.condition(1, 0);
	secureChannel->connect();
	BOOST_REQUIRE(secureChannelTestHandler.connectCondition_.waitForCondition(1000) == true);

	//
	// send CreateSessionRequest
	//
	session->createSession();
	BOOST_REQUIRE(sessionTestHandler.createSessionRequestCount_ == 1);

	nodeId.set(OpcUaId_CreateSessionRequest_Encoding_DefaultBinary);

	secureChannelTestHandler.receiveCondition_.condition(1, 0);
	secureChannel->send(nodeId, sessionTestHandler.sb_);
	BOOST_REQUIRE(secureChannelTestHandler.receiveCondition_.waitForCondition(1000) == true);
	session->receive(secureChannelTestHandler.nodeId_, secureChannelTestHandler.sb_); 
	std::iostream ios(&secureChannelTestHandler.sb_);

	//
	// send ActivateSessionRequest
	//
	session->activateSession();
	BOOST_REQUIRE(sessionTestHandler.activateSessionRequestCount_ == 1);

	nodeId.set(OpcUaId_ActivateSessionRequest_Encoding_DefaultBinary);
	
	secureChannelTestHandler.receiveCondition_.condition(1, 0);
	secureChannel->send(nodeId, sessionTestHandler.sb_);
	BOOST_REQUIRE(secureChannelTestHandler.receiveCondition_.waitForCondition(1000) == true);
	session->receive(secureChannelTestHandler.nodeId_, secureChannelTestHandler.sb_); 

	IOService::msecSleep(200000);

	Config::destroy();
	ioService.stop();
}

BOOST_AUTO_TEST_SUITE_END()