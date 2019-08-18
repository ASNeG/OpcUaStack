#include "unittest.h"
#include "OpcUaStackClient/CryptoManagerTest.h"
#include "OpcUaStackClient/ServiceSet/ServiceSetManager.h"

using namespace OpcUaStackClient;

#ifdef REAL_SERVER

BOOST_AUTO_TEST_SUITE(ServiceSetManagerSyncReal_Discovery_)

BOOST_AUTO_TEST_CASE(ServiceSetManagerSyncReal_Discovery_)
{
	std::cout << "ServiceSetManagerSyncReal_Discovery_t" << std::endl;
}

#if 0
BOOST_AUTO_TEST_CASE(ServiceSetManagerSyncReal_Discovery_discovery_GetEndpoints)
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
	BOOST_REQUIRE(sessionService->syncConnect() == Success);

	// create discovery service
	DiscoveryService::SPtr discoveryService;
	DiscoveryServiceConfig discoveryServiceConfig;
	discoveryServiceConfig.discoveryServiceIf_ = &discoveryServiceIfTestHandler;
	discoveryService = serviceSetManager.discoveryService(sessionService, discoveryServiceConfig);
	BOOST_REQUIRE(discoveryService.get() != nullptr);

	// create and send GetEndpointsRequest
	ServiceTransactionGetEndpoints::SPtr trx;
	trx = boost::make_shared<ServiceTransactionGetEndpoints>();
	GetEndpointsRequest::SPtr req = trx->request();
	req->endpointUrl(REAL_SERVER_URI);

	discoveryService->syncSend(trx);
	GetEndpointsResponse::SPtr res = trx->response();
	BOOST_REQUIRE(trx->statusCode() == Success);
	BOOST_REQUIRE(res->endpoints()->size() > 0);

	// disconnect secure channel
	BOOST_REQUIRE(sessionService->syncDisconnect() == Success);
}
#endif

BOOST_AUTO_TEST_SUITE_END()

#endif
