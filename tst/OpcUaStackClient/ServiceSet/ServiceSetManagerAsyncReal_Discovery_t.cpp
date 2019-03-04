#include "unittest.h"
#include "OpcUaStackClient/CryptoManagerTest.h"
#include "OpcUaStackClient/ServiceSet/ServiceSetManager.h"

using namespace OpcUaStackClient;

#ifdef REAL_SERVER

BOOST_AUTO_TEST_SUITE(ServiceSetManagerAsyncReal_Discovery_)

BOOST_AUTO_TEST_CASE(ServiceSetManagerAsyncReal_Discovery_)
{
	std::cout << "ServiceSetManagerAsyncReal_Discovery_t" << std::endl;
}

#if 0
BOOST_AUTO_TEST_CASE(ServiceSetManagerAsyncReal_Discovery_discovery_GetEndpoints)
{
	ServiceSetManager serviceSetManager;
	DiscoveryServiceIfTestHandler discoveryServiceIfTestHandler;
	SessionServiceIfTestHandler sessionIfTestHandler;


	//
	// init certificate and crypto manager
	//
	CryptoManager::SPtr cryptoManager = CryptoManagerTest::getInstance();
	BOOST_REQUIRE(cryptoManager.get() != nullptr);

	// set secure channel configuration
	SessionServiceConfig sessionServiceConfig;
	sessionServiceConfig.mode_ = SessionService::M_SecureChannel;
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
	BOOST_REQUIRE(sessionIfTestHandler.sessionState_ == SS_Connect);

	// create discovery service
	DiscoveryService::SPtr discoveryService;
	DiscoveryServiceConfig discoveryServiceConfig;
	discoveryServiceConfig.discoveryServiceIf_ = &discoveryServiceIfTestHandler;
	discoveryService = serviceSetManager.discoveryService(sessionService, discoveryServiceConfig);
	BOOST_REQUIRE(discoveryService.get() != nullptr);

	// create and send GetEndpointsRequest
	ServiceTransactionGetEndpoints::SPtr trx;
	trx = constructSPtr<ServiceTransactionGetEndpoints>();
	GetEndpointsRequest::SPtr req = trx->request();
	req->endpointUrl(REAL_SERVER_URI);

	discoveryServiceIfTestHandler.discoveryServiceGetEndpointsResponse_.condition(1,0);
	discoveryService->asyncSend(trx);
	discoveryServiceIfTestHandler.discoveryServiceGetEndpointsResponse_.waitForCondition(1000);
	GetEndpointsResponse::SPtr res = trx->response();
	BOOST_REQUIRE(trx->statusCode() == Success);
	BOOST_REQUIRE(res->endpoints()->size() > 0);

	// disconnect secure channel
	sessionIfTestHandler.sessionStateUpdate_.condition(1,0);
	sessionService->asyncDisconnect();
	BOOST_REQUIRE(sessionIfTestHandler.sessionStateUpdate_.waitForCondition(1000) == true);
	BOOST_REQUIRE(sessionIfTestHandler.sessionState_ == SS_Disconnect);
}
#endif

BOOST_AUTO_TEST_SUITE_END()

#endif
