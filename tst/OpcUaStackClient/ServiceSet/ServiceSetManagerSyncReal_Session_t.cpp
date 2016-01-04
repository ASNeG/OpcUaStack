#include "unittest.h"
#include "OpcUaStackClient/ServiceSet/ServiceSetManager.h"

using namespace OpcUaStackClient;

#ifdef REAL_SERVER

BOOST_AUTO_TEST_SUITE(ServiceSetManagerSyncReal_Session_)

BOOST_AUTO_TEST_CASE(ServiceSetManagerSyncReal_Session_)
{
	std::cout << "ServiceSetManagerSyncReal_Session_t" << std::endl;
}

BOOST_AUTO_TEST_CASE(ServiceSetManagerSyncReal_Session_session_connect_disconnect)
{
	SessionServiceIfTestHandler sessionServiceIfTestHandler;
	ServiceSetManager serviceSetManager;
	SessionServiceConfig sessionServiceConfig;

	// set secure channel configuration
	sessionServiceConfig.sessionServiceIf_ = &sessionServiceIfTestHandler;
	sessionServiceConfig.secureChannelClient_->endpointUrl(REAL_SERVER_URI);

	// create session service
	SessionService::SPtr sessionService;
	sessionService = serviceSetManager.sessionService(sessionServiceConfig);
	BOOST_REQUIRE(sessionService.get() != nullptr);

	// connect session
	BOOST_REQUIRE(sessionService->syncConnect() == Success);

	// disconnect session
	BOOST_REQUIRE(sessionService->syncDisconnect() == Success);
}

BOOST_AUTO_TEST_CASE(ServiceSetManagerSyncReal_Session_session_connect_disconnect_two_times)
{
	SessionServiceIfTestHandler sessionServiceIfTestHandler;
	ServiceSetManager serviceSetManager;
	SessionServiceConfig sessionServiceConfig;

	// set secure channel configuration
	sessionServiceConfig.sessionServiceIf_ = &sessionServiceIfTestHandler;
	sessionServiceConfig.secureChannelClient_->endpointUrl(REAL_SERVER_URI);

	// create session service
	SessionService::SPtr sessionService;
	sessionService = serviceSetManager.sessionService(sessionServiceConfig);
	BOOST_REQUIRE(sessionService.get() != nullptr);

	// connect session
	BOOST_REQUIRE(sessionService->syncConnect() == Success);

	// disconnect session
	BOOST_REQUIRE(sessionService->syncDisconnect() == Success);

	// connect session
	BOOST_REQUIRE(sessionService->syncConnect() == Success);

	// disconnect session
	BOOST_REQUIRE(sessionService->syncDisconnect() == Success);
}


BOOST_AUTO_TEST_SUITE_END()

#endif
