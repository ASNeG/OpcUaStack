#include "unittest.h"
#include "OpcUaStackCore/Base/Condition.h"
#include "OpcUaStackCore/Core/Core.h"
#include "OpcUaStackClient/ServiceSet/Session.h"
#include "OpcUaStackClient/ServiceSet/AttributeService.h"

#ifdef REAL_SERVER

using namespace OpcUaStackCore;
using namespace OpcUaStackClient;

class SubscriptionRealTest
: public SessionIf
{
  public:
	SessionState sessionState_;

	Condition sessionStateUpdate_;
	void sessionStateUpdate(SessionBase& session, SessionState sessionState)
	{
		std::cout << "handleConnect client" << std::endl;
		sessionState_ = sessionState;
		sessionStateUpdate_.conditionValueDec();
	}
};

BOOST_AUTO_TEST_SUITE(SubscriptionReal_)

BOOST_AUTO_TEST_CASE(SubscriptionReal_)
{
	std::cout << "SubscriptionReal_t" << std::endl;
}

BOOST_AUTO_TEST_CASE(SubscriptionReal_async_read)
{
	Core core;
	core.init();

	IOThread ioThread;
	ioThread.startup();

	// set secure channel configuration
	SecureChannelClientConfig::SPtr secureChannelClientConfig = construct<SecureChannelClientConfig>();
	secureChannelClientConfig->endpointUrl(REAL_SERVER_URI);
	secureChannelClientConfig->debug(false);
	secureChannelClientConfig->debugHeader(false);

	// set session configuration
	SessionConfig::SPtr sessionConfig = construct<SessionConfig>();
	sessionConfig->sessionName_ = "urn:127.0.0.1:ASNeG.de:ASNeG-Client";
	sessionConfig->applicationDescription_->applicationUri("urn:127.0.0.1:ASNeG.de:ASNeG-Client");
	sessionConfig->applicationDescription_->productUri("urn:ASNeG.de:ASNeG-Client");
	sessionConfig->applicationDescription_->applicationName().set("en", "ASNeG-Client");

	// init session
	SubscriptionRealTest attributeRealTest;
	Session session(&ioThread);
	session.sessionIf(&attributeRealTest);

	// connect session
	attributeRealTest.sessionStateUpdate_.condition(1,0);
	session.asyncConnect(sessionConfig, secureChannelClientConfig);
	BOOST_REQUIRE(attributeRealTest.sessionStateUpdate_.waitForCondition(1000) == true);
	BOOST_REQUIRE(attributeRealTest.sessionState_ == SS_Connect);

	// disconnect session
	attributeRealTest.sessionStateUpdate_.condition(1,0);
	session.asyncDisconnect();
	BOOST_REQUIRE(attributeRealTest.sessionStateUpdate_.waitForCondition(1000) == true);
	BOOST_REQUIRE(attributeRealTest.sessionState_ == SS_Disconnect);

	ioThread.shutdown();
}

BOOST_AUTO_TEST_SUITE_END()

#endif
