#include "unittest.h"
#include "OpcUaStackClient/ServiceSet/ServiceSetManager.h"

using namespace OpcUaStackClient;

#ifdef REAL_SERVER

BOOST_AUTO_TEST_SUITE()

BOOST_AUTO_TEST_CASE(ServiceSetManagerAsyncReal_Query_)
{
	std::cout << "ServiceSetManagerAsyncReal_Query_t" << std::endl;
}

BOOST_AUTO_TEST_CASE(ServiceSetManagerAsyncReal_Query_cc)
{
	QueryServiceIfTestHandler queryServiceIfTestHandler;
	ServiceSetManager serviceSetManager;
	SessionServiceIfTestHandler sessionIfTestHandler;
	SessionServiceConfig sessionServiceConfig;

	// set secure channel configuration
	sessionServiceConfig.sessionServiceIf_ = &sessionIfTestHandler;
	sessionServiceConfig.secureChannelClient_->endpointUrl(REAL_SERVER_URI);

	// create session
	SessionService::SPtr sessionService;
	sessionService = serviceSetManager.sessionService(sessionServiceConfig);
	BOOST_REQUIRE(sessionService.get() != nullptr);

	// connect secure channel
	sessionIfTestHandler.sessionStateUpdate_.condition(1,0);
	sessionService->asyncConnect();
	BOOST_REQUIRE(sessionIfTestHandler.sessionStateUpdate_.waitForCondition(1000) == true);
	BOOST_REQUIRE(sessionIfTestHandler.sessionState_ == SS_Connect);

	// create query service
	QueryService::SPtr queryService;
	QueryServiceConfig queryServiceConfig;
	queryServiceConfig.queryServiceIf_ = &queryServiceIfTestHandler;
	queryService = serviceSetManager.queryService(sessionService, queryServiceConfig);
	BOOST_REQUIRE(queryService.get() != nullptr);

	// FIXME:

	// disconnect secure channel
	sessionIfTestHandler.sessionStateUpdate_.condition(1,0);
	sessionService->asyncDisconnect();
	BOOST_REQUIRE(sessionIfTestHandler.sessionStateUpdate_.waitForCondition(1000) == true);
	BOOST_REQUIRE(sessionIfTestHandler.sessionState_ == SS_Disconnect);
}


BOOST_AUTO_TEST_SUITE_END()

#endif
