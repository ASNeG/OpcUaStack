#include "unittest.h"
#include "OpcUaStackClient/CryptoManagerTest.h"
#include "OpcUaStackClient/ServiceSet/ServiceSetManager.h"

using namespace OpcUaStackClient;

#ifdef REAL_SERVER

BOOST_AUTO_TEST_SUITE(ServiceSetManagerAsyncReal_NodeManagement_)

BOOST_AUTO_TEST_CASE(ServiceSetManagerAsyncReal_NodeManagement_)
{
	std::cout << "ServiceSetManagerAsyncReal_NodeManagement_t" << std::endl;
}

BOOST_AUTO_TEST_CASE(ServiceSetManagerAsyncReal_NodeManagement_cc)
{
	ServiceSetManager serviceSetManager;
	NodeManagementServiceIfTestHandler nodeManagementServiceIfTestHandler;
	SessionServiceIfTestHandler sessionIfTestHandler;

	//
	// init certificate and crypto manager
	//
	CryptoManager::SPtr cryptoManager = CryptoManagerTest::getInstance();
	BOOST_REQUIRE(cryptoManager.get() != nullptr);

	// set secure channel configuration
	SessionServiceConfig sessionServiceConfig;
	sessionServiceConfig.sessionServiceIf_ = &sessionIfTestHandler;
	sessionServiceConfig.secureChannelClient_->endpointUrl(REAL_SERVER_URI);
	sessionServiceConfig.secureChannelClient_->cryptoManager(cryptoManager);
	sessionServiceConfig.session_->sessionName(REAL_SESSION_NAME);

	// create session
	SessionService::SPtr sessionService;
	sessionService = serviceSetManager.sessionService(sessionServiceConfig);
	BOOST_REQUIRE(sessionService.get() != nullptr);

	// connect secure channel
	sessionIfTestHandler.sessionStateUpdate_.condition(1,0);
	sessionService->asyncConnect();
	BOOST_REQUIRE(sessionIfTestHandler.sessionStateUpdate_.waitForCondition(1000) == true);
	BOOST_REQUIRE(sessionIfTestHandler.sessionState_ == SessionState::Established);

	// create nodeManagement service
	NodeManagementService::SPtr nodeManagementService;
	NodeManagementServiceConfig nodeManagementServiceConfig;
	nodeManagementServiceConfig.nodeManagementServiceIf_ = &nodeManagementServiceIfTestHandler;
	nodeManagementService = serviceSetManager.nodeManagementService(sessionService, nodeManagementServiceConfig);
	BOOST_REQUIRE(nodeManagementService.get() != nullptr);

	// FIXME:

	// disconnect secure channel
	sessionIfTestHandler.sessionStateUpdate_.condition(1,0);
	sessionService->asyncDisconnect();
	BOOST_REQUIRE(sessionIfTestHandler.sessionStateUpdate_.waitForCondition(1000) == true);
	BOOST_REQUIRE(sessionIfTestHandler.sessionState_ == SessionState::Disconnected);
}


BOOST_AUTO_TEST_SUITE_END()

#endif
