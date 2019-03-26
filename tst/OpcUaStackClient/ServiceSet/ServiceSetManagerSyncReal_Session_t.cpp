#include "unittest.h"
#include "OpcUaStackClient/CryptoManagerTest.h"
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
	ServiceSetManager serviceSetManager;

	//
	// init certificate and crypto manager
	//
	CryptoManager::SPtr cryptoManager = CryptoManagerTest::getInstance();
	BOOST_REQUIRE(cryptoManager.get() != nullptr);

	// set secure channel configuration
	SessionServiceConfig sessionServiceConfig;
	sessionServiceConfig.secureChannelClient_->endpointUrl(REAL_SERVER_URI);
	sessionServiceConfig.secureChannelClient_->cryptoManager(cryptoManager);
	sessionServiceConfig.session_->sessionName(REAL_SESSION_NAME);

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
	ServiceSetManager serviceSetManager;
	SessionServiceConfig sessionServiceConfig;

	//
	// init certificate and crypto manager
	//
	CryptoManager::SPtr cryptoManager = CryptoManagerTest::getInstance();
	BOOST_REQUIRE(cryptoManager.get() != nullptr);

	// set secure channel configuration
	sessionServiceConfig.secureChannelClient_->endpointUrl(REAL_SERVER_URI);
	sessionServiceConfig.secureChannelClient_->cryptoManager(cryptoManager);
	sessionServiceConfig.session_->sessionName(REAL_SESSION_NAME);
	sessionServiceConfig.session_->reconnectTimeout(0);

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
