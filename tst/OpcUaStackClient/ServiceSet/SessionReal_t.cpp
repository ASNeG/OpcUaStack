
#include "unittest.h"
#include "OpcUaStackCore/Base/Condition.h"
#include "OpcUaStackCore/Core/Core.h"
#include "OpcUaStackClient/ServiceSet/SessionService.h"

#ifdef REAL_SERVER

using namespace OpcUaStackCore;
using namespace OpcUaStackClient;

class SessionTestReal
: public SessionServiceIf
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
	IOThread ioThread;
	ioThread.startup();

	SessionTestReal sessionTestReal;

	// set secure channel configuration
	SecureChannelClientConfig::SPtr secureChannelClientConfig = constructSPtr<SecureChannelClientConfig>();
	secureChannelClientConfig->endpointUrl(REAL_SERVER_URI);
	secureChannelClientConfig->debug(false);
	secureChannelClientConfig->debugHeader(true);

	// init session
	SessionService sessionService(&ioThread);
	sessionService.sessionServiceIf(&sessionTestReal);

	// connect session
	sessionTestReal.sessionStateUpdate_.condition(1,0);
	sessionService.asyncConnect(secureChannelClientConfig);
	BOOST_REQUIRE(sessionTestReal.sessionStateUpdate_.waitForCondition(1000) == true);
	BOOST_REQUIRE(sessionTestReal.sessionState_ == SS_Connect);

	// disconnect session
	sessionTestReal.sessionStateUpdate_.condition(1,0);
	sessionService.asyncDisconnect();
	BOOST_REQUIRE(sessionTestReal.sessionStateUpdate_.waitForCondition(1000) == true);
	BOOST_REQUIRE(sessionTestReal.sessionState_ == SS_Disconnect);

	ioThread.shutdown();
}

BOOST_AUTO_TEST_CASE(SessionReal_connect_disconnect_session)
{
	Core core;
	core.init();

	IOThread ioThread;
	ioThread.startup();

	SessionTestReal sessionTestReal;

	// set secure channel configuration
	SecureChannelClientConfig::SPtr secureChannelClientConfig = constructSPtr<SecureChannelClientConfig>();
	secureChannelClientConfig->endpointUrl(REAL_SERVER_URI);
	secureChannelClientConfig->debug(false);
	secureChannelClientConfig->debugHeader(true);

	// set session configuration
	SessionConfig::SPtr sessionConfig = constructSPtr<SessionConfig>();
	sessionConfig->sessionName_ = "urn:127.0.0.1:ASNeG.de:ASNeG-Client";
	sessionConfig->applicationDescription_->applicationUri("urn:127.0.0.1:ASNeG.de:ASNeG-Client");
	sessionConfig->applicationDescription_->productUri("urn:ASNeG.de:ASNeG-Client");
	sessionConfig->applicationDescription_->applicationName().set("en", "ASNeG-Client");

	// init session
	SessionService sessionService(&ioThread);
	sessionService.sessionServiceIf(&sessionTestReal);

	// connect session
	sessionTestReal.sessionStateUpdate_.condition(1,0);
	sessionService.asyncConnect(sessionConfig, secureChannelClientConfig);
	BOOST_REQUIRE(sessionTestReal.sessionStateUpdate_.waitForCondition(1000) == true);
	BOOST_REQUIRE(sessionTestReal.sessionState_ == SS_Connect);

	// disconnect session
	sessionTestReal.sessionStateUpdate_.condition(1,0);
	sessionService.asyncDisconnect();
	BOOST_REQUIRE(sessionTestReal.sessionStateUpdate_.waitForCondition(1000) == true);
	BOOST_REQUIRE(sessionTestReal.sessionState_ == SS_Disconnect);

	ioThread.shutdown();
}

BOOST_AUTO_TEST_SUITE_END()

#endif
