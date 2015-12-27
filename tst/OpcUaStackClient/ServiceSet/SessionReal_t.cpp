
#include "unittest.h"
#include "OpcUaStackCore/Base/Condition.h"
#include "OpcUaStackCore/Core/Core.h"
#include "OpcUaStackClient/ServiceSet/Session.h"

#ifdef REAL_SERVER

using namespace OpcUaStackCore;
using namespace OpcUaStackClient;

class SessionTestReal
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


BOOST_AUTO_TEST_SUITE(SessionReal_)

BOOST_AUTO_TEST_CASE(SessionReal_)
{
	std::cout << "SessionReal_t" << std::endl;
}

BOOST_AUTO_TEST_CASE(SessionReal_connect_disconnect_secure_channel)
{
	IOService ioService;
	ioService.start(1);

	SessionTestReal sessionTestReal;

	// set secure channel configuration
	SecureChannelClientConfig::SPtr secureChannelClientConfig = construct<SecureChannelClientConfig>();
	secureChannelClientConfig->endpointUrl(REAL_SERVER_URI);
	secureChannelClientConfig->debug(false);
	secureChannelClientConfig->debugHeader(true);

	// init session
	Session session(ioService);
	session.sessionIf(&sessionTestReal);

	// connect session
	sessionTestReal.sessionStateUpdate_.condition(1,0);
	session.asyncConnect(secureChannelClientConfig);
	BOOST_REQUIRE(sessionTestReal.sessionStateUpdate_.waitForCondition(1000) == true);
	BOOST_REQUIRE(sessionTestReal.sessionState_ == SS_Connect);

	// disconnect session
	sessionTestReal.sessionStateUpdate_.condition(1,0);
	session.asyncDisconnect();
	BOOST_REQUIRE(sessionTestReal.sessionStateUpdate_.waitForCondition(1000) == true);
	BOOST_REQUIRE(sessionTestReal.sessionState_ == SS_Disconnect);

	ioService.stop();
}

BOOST_AUTO_TEST_CASE(SessionReal_connect_disconnect_session)
{
	Core core;
	core.init();

	IOService ioService;
	ioService.start(1);

	SessionTestReal sessionTestReal;

	// set secure channel configuration
	SecureChannelClientConfig::SPtr secureChannelClientConfig = construct<SecureChannelClientConfig>();
	secureChannelClientConfig->endpointUrl(REAL_SERVER_URI);
	secureChannelClientConfig->debug(false);
	secureChannelClientConfig->debugHeader(true);

	// set session configuration
	SessionConfig::SPtr sessionConfig = construct<SessionConfig>();
	sessionConfig->sessionName_ = "urn:127.0.0.1:ASNeG.de:ASNeG-Client";
	sessionConfig->applicationDescription_->applicationUri("urn:127.0.0.1:ASNeG.de:ASNeG-Client");
	sessionConfig->applicationDescription_->productUri("urn:ASNeG.de:ASNeG-Client");
	sessionConfig->applicationDescription_->applicationName().set("en", "ASNeG-Client");

	// init session
	Session session(ioService);
	session.sessionIf(&sessionTestReal);

	// connect session
	sessionTestReal.sessionStateUpdate_.condition(1,0);
	session.asyncConnect(sessionConfig, secureChannelClientConfig);
	BOOST_REQUIRE(sessionTestReal.sessionStateUpdate_.waitForCondition(1000) == true);
	BOOST_REQUIRE(sessionTestReal.sessionState_ == SS_Connect);

	// disconnect session
	sessionTestReal.sessionStateUpdate_.condition(1,0);
	session.asyncDisconnect();
	BOOST_REQUIRE(sessionTestReal.sessionStateUpdate_.waitForCondition(1000) == true);
	BOOST_REQUIRE(sessionTestReal.sessionState_ == SS_Disconnect);

	ioService.stop();
}

BOOST_AUTO_TEST_SUITE_END()

#endif
