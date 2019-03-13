#include "unittest.h"
#include "OpcUaStackClient/CryptoManagerTest.h"
#include "OpcUaStackClient/ServiceSet/ServiceSetManager.h"

using namespace OpcUaStackClient;

#ifdef REAL_SERVER

BOOST_AUTO_TEST_SUITE(ServiceSetManagerAsyncReal_View_)

BOOST_AUTO_TEST_CASE(ServiceSetManagerAsyncReal_View_)
{
	std::cout << "ServiceSetManagerAsyncReal_View_t" << std::endl;
}

BOOST_AUTO_TEST_CASE(ServiceSetManagerAsyncReal_View_discovery_GetEndpoints)
{
	ServiceSetManager serviceSetManager;
	ViewServiceIfTestHandler viewServiceIfTestHandler;
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
	BOOST_REQUIRE(sessionIfTestHandler.sessionState_ == SessionServiceStateId::Established);

	// create view service
	ViewService::SPtr viewService;
	ViewServiceConfig viewServiceConfig;
	viewServiceConfig.viewServiceIf_ = &viewServiceIfTestHandler;
	viewService = serviceSetManager.viewService(sessionService, viewServiceConfig);
	BOOST_REQUIRE(viewService.get() != nullptr);

	// call view
	ServiceTransactionBrowse::SPtr trx = constructSPtr<ServiceTransactionBrowse>();
	BrowseRequest::SPtr req = trx->request();
	req->nodesToBrowse()->resize(1);

	BrowseDescription::SPtr browseDescription = constructSPtr<BrowseDescription>();
	browseDescription->nodeId()->set(84, 0);
	browseDescription->browseDirection(BrowseDirection_Both);
	browseDescription->nodeClassMask(0xFFFFFFFF);
	browseDescription->resultMask(0xFFFFFFFF);
	req->nodesToBrowse()->push_back(browseDescription);

	viewServiceIfTestHandler.viewServiceBrowseResponse_.condition(1,0);
	viewService->asyncSend(trx);
	BOOST_REQUIRE(viewServiceIfTestHandler.viewServiceBrowseResponse_.waitForCondition(1000) == true);
	BOOST_REQUIRE(trx->responseHeader()->serviceResult() == Success);

	BrowseResponse::SPtr res = trx->response();
	BOOST_REQUIRE(res->results()->size() == 1);

	BrowseResult::SPtr browseResult;
	res->results()->get(0, browseResult);
	BOOST_REQUIRE(browseResult->statusCode() == Success);
	BOOST_REQUIRE(browseResult->references()->size() > 0);

	// disconnect secure channel
	sessionIfTestHandler.sessionStateUpdate_.condition(1,0);
	sessionService->asyncDisconnect();
	BOOST_REQUIRE(sessionIfTestHandler.sessionStateUpdate_.waitForCondition(1000) == true);
	BOOST_REQUIRE(sessionIfTestHandler.sessionState_ == SessionServiceStateId::Disconnected);
}


BOOST_AUTO_TEST_SUITE_END()

#endif
