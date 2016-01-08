#include "unittest.h"
#include "OpcUaStackClient/ServiceSet/ServiceSetManager.h"

using namespace OpcUaStackClient;

#ifdef REAL_SERVER

BOOST_AUTO_TEST_SUITE(ServiceSetManagerAsyncReal_Session_)

BOOST_AUTO_TEST_CASE(ServiceSetManagerAsyncReal_Session_)
{
	std::cout << "ServiceSetManagerAsyncReal_Session_t" << std::endl;
}

BOOST_AUTO_TEST_CASE(ServiceSetManagerAsyncReal_Session_session_connect_disconnect)
{
	ServiceSetManager serviceSetManager;
	SessionServiceIfTestHandler sessionServiceIfTestHandler;

	// set secure channel configuration
	SessionServiceConfig sessionServiceConfig;
	sessionServiceConfig.sessionServiceIf_ = &sessionServiceIfTestHandler;
	sessionServiceConfig.secureChannelClient_->endpointUrl(REAL_SERVER_URI);
	sessionServiceConfig.session_->sessionName_(REAL_SESSION_NAME);

	// create session
	SessionService::SPtr sessionService;
	sessionService = serviceSetManager.sessionService(sessionServiceConfig);
	BOOST_REQUIRE(sessionService.get() != nullptr);

	// connect session
	sessionServiceIfTestHandler.sessionStateUpdate_.condition(1,0);
	sessionService->asyncConnect();
	BOOST_REQUIRE(sessionServiceIfTestHandler.sessionStateUpdate_.waitForCondition(1000) == true);
	BOOST_REQUIRE(sessionServiceIfTestHandler.sessionState_ == SS_Connect);

	// disconnect session
	sessionServiceIfTestHandler.sessionStateUpdate_.condition(1,0);
	sessionService->asyncDisconnect();
	BOOST_REQUIRE(sessionServiceIfTestHandler.sessionStateUpdate_.waitForCondition(1000) == true);
	BOOST_REQUIRE(sessionServiceIfTestHandler.sessionState_ == SS_Disconnect);
}

BOOST_AUTO_TEST_CASE(ServiceSetManagerAsyncReal_Session_session_connect_disconnect_two_times)
{
	SessionServiceIfTestHandler sessionServiceIfTestHandler;
	ServiceSetManager serviceSetManager;
	SessionServiceConfig sessionServiceConfig;

	// set secure channel configuration
	sessionServiceConfig.sessionServiceIf_ = &sessionServiceIfTestHandler;
	sessionServiceConfig.secureChannelClient_->endpointUrl(REAL_SERVER_URI);
	sessionServiceConfig.session_->sessionName_(REAL_SESSION_NAME);

	// create session
	SessionService::SPtr sessionService;
	sessionService = serviceSetManager.sessionService(sessionServiceConfig);
	BOOST_REQUIRE(sessionService.get() != nullptr);

	// connect session
	sessionServiceIfTestHandler.sessionStateUpdate_.condition(1,0);
	sessionService->asyncConnect();
	BOOST_REQUIRE(sessionServiceIfTestHandler.sessionStateUpdate_.waitForCondition(1000) == true);
	BOOST_REQUIRE(sessionServiceIfTestHandler.sessionState_ == SS_Connect);

	// disconnect session
	sessionServiceIfTestHandler.sessionStateUpdate_.condition(1,0);
	sessionService->asyncDisconnect();
	BOOST_REQUIRE(sessionServiceIfTestHandler.sessionStateUpdate_.waitForCondition(1000) == true);
	BOOST_REQUIRE(sessionServiceIfTestHandler.sessionState_ == SS_Disconnect);

	// connect session
	sessionServiceIfTestHandler.sessionStateUpdate_.condition(1,0);
	sessionService->asyncConnect();
	BOOST_REQUIRE(sessionServiceIfTestHandler.sessionStateUpdate_.waitForCondition(1000) == true);
	BOOST_REQUIRE(sessionServiceIfTestHandler.sessionState_ == SS_Connect);

	// disconnect session
	sessionServiceIfTestHandler.sessionStateUpdate_.condition(1,0);
	sessionService->asyncDisconnect();
	BOOST_REQUIRE(sessionServiceIfTestHandler.sessionStateUpdate_.waitForCondition(1000) == true);
	BOOST_REQUIRE(sessionServiceIfTestHandler.sessionState_ == SS_Disconnect);
}


BOOST_AUTO_TEST_SUITE_END()

#endif
