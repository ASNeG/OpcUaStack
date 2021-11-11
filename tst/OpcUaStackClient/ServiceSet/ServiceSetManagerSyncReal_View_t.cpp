#include "unittest.h"
#include "OpcUaStackClient/CryptoManagerTest.h"
#include "OpcUaStackClient/ServiceSet/ServiceSetManager.h"

using namespace OpcUaStackCore;
using namespace OpcUaStackClient;

#ifdef REAL_SERVER

struct ViewFixture
{
	ViewFixture()
	{
		continuationPoints = boost::make_shared<OpcUaByteStringArray>();
		std::cout << "View Fixture has started" << std::endl;
		// init certificate and crypto manager
		auto cryptoManager = CryptoManagerTest::getInstance();
		BOOST_REQUIRE(cryptoManager.get() != nullptr);

		// set secure channel configuration
		SessionServiceConfig sessionServiceConfig;
		sessionServiceConfig.secureChannelClient_->endpointUrl(REAL_SERVER_URI);
		sessionServiceConfig.secureChannelClient_->cryptoManager(cryptoManager);
		sessionServiceConfig.session_->sessionName(REAL_SESSION_NAME);

		// create session
		sessionService = serviceSetManager.sessionService(sessionServiceConfig);
		BOOST_REQUIRE(sessionService.get() != nullptr);

		// connect secure channel
		BOOST_REQUIRE(sessionService->syncConnect() == Success);

		// create view service
		ViewServiceConfig viewServiceConfig;
		viewService = serviceSetManager.viewService(sessionService, viewServiceConfig);
		BOOST_REQUIRE(viewService.get() != nullptr);
	}
	~ViewFixture()
	{
		// disconnect secure channel
		BOOST_REQUIRE(sessionService->syncDisconnect() == Success);
	}

	ServiceSetManager serviceSetManager;
	SessionService::SPtr sessionService;
	ViewService::SPtr viewService;
	OpcUaByteStringArray::SPtr continuationPoints;
};

BOOST_AUTO_TEST_SUITE(ServiceSetManagerSyncReal_View_)

BOOST_AUTO_TEST_CASE(ServiceSetManagerSyncReal_View_)
{
	std::cout << "ServiceSetManagerSyncReal_View_t" << std::endl;
}

BOOST_AUTO_TEST_CASE(ServiceSetManagerSyncReal_View_discovery_GetEndpoints)
{
#if 0
	ServiceSetManager serviceSetManager;

	//
	// init certificate and crypto manager
	//
	auto cryptoManager = CryptoManagerTest::getInstance();
	BOOST_REQUIRE(cryptoManager.get() != nullptr);

	// set secure channel configuration
	SessionServiceConfig sessionServiceConfig;
	sessionServiceConfig.secureChannelClient_->endpointUrl(REAL_SERVER_URI);
	sessionServiceConfig.secureChannelClient_->cryptoManager(cryptoManager);
	sessionServiceConfig.session_->sessionName(REAL_SESSION_NAME);

	// create session
	auto sessionService = serviceSetManager.sessionService(sessionServiceConfig);
	BOOST_REQUIRE(sessionService.get() != nullptr);

	// connect secure channel
	BOOST_REQUIRE(sessionService->syncConnect() == Success);

	// create view service
	ViewService::SPtr viewService;
	ViewServiceConfig viewServiceConfig;
	viewService = serviceSetManager.viewService(sessionService, viewServiceConfig);
	BOOST_REQUIRE(viewService.get() != nullptr);

	// call view
	auto trx = boost::make_shared<ServiceTransactionBrowse>();
	auto req = trx->request();
	req->nodesToBrowse()->resize(1);

	BrowseDescription::SPtr browseDescription = boost::make_shared<BrowseDescription>();
	browseDescription->nodeId()->set(84, 0);
	browseDescription->browseDirection(BrowseDirection_Both);
	browseDescription->nodeClassMask(0xFFFFFFFF);
	browseDescription->resultMask(0xFFFFFFFF);
	req->nodesToBrowse()->push_back(browseDescription);

	viewService->syncSend(trx);
	BOOST_REQUIRE(trx->responseHeader()->serviceResult() == Success);

	BrowseResponse::SPtr res = trx->response();
	BOOST_REQUIRE(res->results()->size() == 1);

	BrowseResult::SPtr browseResult = boost::make_shared<BrowseResult>();
	res->results()->get(0, browseResult);
	BOOST_REQUIRE(browseResult->statusCode() == Success);
	BOOST_REQUIRE(browseResult->references()->size() > 0);

	for (auto reference : *browseResult->references())
	{
		std::cout << "BrowseName=" << (*reference).browseName() << std::endl;
		std::cout << "DisplayName=" << (*reference).displayName() << std::endl;
	}

	// disconnect secure channel
	BOOST_REQUIRE(sessionService->syncDisconnect() == Success);
#endif
}

BOOST_FIXTURE_TEST_CASE(ServiceSetManagerSyncReal_View_Browse_Request, ViewFixture)
{
#if 0
	// call view
	auto trx = boost::make_shared<ServiceTransactionBrowse>();
	auto req = trx->request();

	req->nodesToBrowse()->resize(1);
	req->requestMaxReferencesPerNode(1);

	BrowseDescription::SPtr browseDescription = boost::make_shared<BrowseDescription>();
	browseDescription->nodeId()->set(84, 0);
	browseDescription->browseDirection(BrowseDirection_Both);
	browseDescription->nodeClassMask(0xFFFFFFFF);
	browseDescription->resultMask(0x08);
	req->nodesToBrowse()->push_back(browseDescription);

	viewService->syncSend(trx);
	BOOST_REQUIRE(trx->responseHeader()->serviceResult() == Success);

	BrowseResponse::SPtr res = trx->response();
	BOOST_REQUIRE(res->results()->size() == 1);

	BrowseResult::SPtr browseResult = boost::make_shared<BrowseResult>();
	res->results()->get(0, browseResult);
	BOOST_REQUIRE(browseResult->statusCode() == Success);
	BOOST_REQUIRE(browseResult->references()->size() == 1);
	BOOST_REQUIRE(browseResult->continuationPoint().size() >= 19);

	for (auto reference : *browseResult->references())
	{
		BOOST_REQUIRE(reference->browseName().toString() == "Objects");
	}
#endif
}

BOOST_FIXTURE_TEST_CASE(ServiceSetManagerSyncReal_View_Browse_NextRequest_WithReleasefalse, ViewFixture)
{

	//
	// send browse request
	//
	auto trx = boost::make_shared<ServiceTransactionBrowse>();
	auto req = trx->request();

	req->nodesToBrowse()->resize(1);
	req->requestMaxReferencesPerNode(1);

	BrowseDescription::SPtr browseDescription = boost::make_shared<BrowseDescription>();
	browseDescription->nodeId()->set(84, 0);
	browseDescription->browseDirection(BrowseDirection_Both);
	browseDescription->nodeClassMask(0xFFFFFFFF);
	browseDescription->resultMask(0x08);
	req->nodesToBrowse()->push_back(browseDescription);

	viewService->syncSend(trx);
	BOOST_REQUIRE(trx->responseHeader()->serviceResult() == Success);

	BrowseResponse::SPtr res = trx->response();
	BOOST_REQUIRE(res->results()->size() == 1);

	BrowseResult::SPtr browseResult = boost::make_shared<BrowseResult>();
	res->results()->get(0, browseResult);
	BOOST_REQUIRE(browseResult->statusCode() == Success);
	BOOST_REQUIRE(browseResult->references()->size() == 1);
	BOOST_REQUIRE(browseResult->continuationPoint().size() >= 19);
	BOOST_REQUIRE((*browseResult->references())[0]->browseName().toString() == "Objects");

	//
	// send browse next request (1)
	//
	auto trx_1 = boost::make_shared<ServiceTransactionBrowseNext>();
	auto req_1 = trx_1->request();

	auto continuationPoint = boost::make_shared<OpcUaByteString>(browseResult->continuationPoint());
	req_1->releaseContinuationPoints(false);
	req_1->continuationPoints()->resize(1);
	req_1->continuationPoints()->push_back(continuationPoint);

	viewService->syncSend(trx_1);
	BOOST_REQUIRE(trx_1->responseHeader()->serviceResult() == Success);

	BrowseNextResponse::SPtr res_1 = trx_1->response();
	BOOST_REQUIRE(res_1->results()->size() == 1);

	BrowseResult::SPtr browseResult_1 = boost::make_shared<BrowseResult>();
	res_1->results()->get(0, browseResult_1);
	BOOST_REQUIRE(browseResult_1->statusCode() == Success);
	BOOST_REQUIRE(browseResult_1->references()->size() == 1);
	BOOST_REQUIRE(browseResult_1->continuationPoint().size() >= 19);
	BOOST_REQUIRE((*browseResult_1->references())[0]->browseName().toString() == "Types");

	//
	// send browse next request (2)
	//
	auto trx_2 = boost::make_shared<ServiceTransactionBrowseNext>();
	auto req_2 = trx_2->request();

	req_2->releaseContinuationPoints(false);
	req_2->continuationPoints()->resize(1);
	req_2->continuationPoints()->push_back(continuationPoint);

	viewService->syncSend(trx_2);
	BOOST_REQUIRE(trx_2->responseHeader()->serviceResult() == Success);

	BrowseNextResponse::SPtr res_2 = trx_2->response();
	BOOST_REQUIRE(res_2->results()->size() == 1);

	BrowseResult::SPtr browseResult_2 = boost::make_shared<BrowseResult>();
	res_2->results()->get(0, browseResult_2);
	BOOST_REQUIRE(browseResult_2->statusCode() == Success);
	BOOST_REQUIRE(browseResult_2->references()->size() == 1);
	BOOST_REQUIRE(browseResult_2->continuationPoint().size() >= 19);
	BOOST_REQUIRE((*browseResult_2->references())[0]->browseName().toString() == "Views");

	//
	// send browse next request (3)
	//
	auto trx_3 = boost::make_shared<ServiceTransactionBrowseNext>();
	auto req_3 = trx_3->request();

	req_3->releaseContinuationPoints(false);
	req_3->continuationPoints()->resize(1);
	req_3->continuationPoints()->push_back(continuationPoint);

	viewService->syncSend(trx_3);
	BOOST_REQUIRE(trx_3->responseHeader()->serviceResult() == Success);

	BrowseNextResponse::SPtr res_3 = trx_3->response();
	BOOST_REQUIRE(res_3->results()->size() == 1);

	BrowseResult::SPtr browseResult_3 = boost::make_shared<BrowseResult>();
	res_3->results()->get(0, browseResult_3);
	BOOST_REQUIRE(browseResult_3->statusCode() == Success);
	BOOST_REQUIRE(browseResult_3->references()->size() == 1);
	BOOST_REQUIRE(browseResult_3->continuationPoint().size() == -1);
	BOOST_REQUIRE((*browseResult_3->references())[0]->browseName().toString() == "FolderType");
}

BOOST_FIXTURE_TEST_CASE(ServiceSetManagerSyncReal_View_Browse_NextRequest_WithReleasetrue, ViewFixture)
{
	//
	// send browse request
	//
	auto trx = boost::make_shared<ServiceTransactionBrowse>();
	auto req = trx->request();

	req->nodesToBrowse()->resize(1);
	req->requestMaxReferencesPerNode(1);

	BrowseDescription::SPtr browseDescription = boost::make_shared<BrowseDescription>();
	browseDescription->nodeId()->set(84, 0);
	browseDescription->browseDirection(BrowseDirection_Both);
	browseDescription->nodeClassMask(0xFFFFFFFF);
	browseDescription->resultMask(0x08);
	req->nodesToBrowse()->push_back(browseDescription);

	viewService->syncSend(trx);
	BOOST_REQUIRE(trx->responseHeader()->serviceResult() == Success);

	BrowseResponse::SPtr res = trx->response();
	BOOST_REQUIRE(res->results()->size() == 1);

	BrowseResult::SPtr browseResult = boost::make_shared<BrowseResult>();
	res->results()->get(0, browseResult);
	BOOST_REQUIRE(browseResult->statusCode() == Success);
	BOOST_REQUIRE(browseResult->references()->size() == 1);
	BOOST_REQUIRE(browseResult->continuationPoint().size() >= 19);
	BOOST_REQUIRE((*browseResult->references())[0]->browseName().toString() == "Objects");

	//
	// send browse next request (1)
	//
	auto trx_1 = boost::make_shared<ServiceTransactionBrowseNext>();
	auto req_1 = trx_1->request();

	auto continuationPoint = boost::make_shared<OpcUaByteString>(browseResult->continuationPoint());
	req_1->releaseContinuationPoints(false);
	req_1->continuationPoints()->resize(1);
	req_1->continuationPoints()->push_back(continuationPoint);

	viewService->syncSend(trx_1);
	BOOST_REQUIRE(trx_1->responseHeader()->serviceResult() == Success);

	BrowseNextResponse::SPtr res_1 = trx_1->response();
	BOOST_REQUIRE(res_1->results()->size() == 1);

	BrowseResult::SPtr browseResult_1 = boost::make_shared<BrowseResult>();
	res_1->results()->get(0, browseResult_1);
	BOOST_REQUIRE(browseResult_1->statusCode() == Success);
	BOOST_REQUIRE(browseResult_1->references()->size() == 1);
	BOOST_REQUIRE(browseResult_1->continuationPoint().size() >= 19);
	BOOST_REQUIRE((*browseResult_1->references())[0]->browseName().toString() == "Types");

	//
	// send browse next request (2) with releaseContinuationPoints is true
	//
	auto trx_2 = boost::make_shared<ServiceTransactionBrowseNext>();
	auto req_2 = trx_2->request();

	req_2->releaseContinuationPoints(true);
	req_2->continuationPoints()->resize(1);
	req_2->continuationPoints()->push_back(continuationPoint);

	viewService->syncSend(trx_2);
	BOOST_REQUIRE(trx_2->responseHeader()->serviceResult() == Success);

	BrowseNextResponse::SPtr res_2 = trx_2->response();
	BOOST_REQUIRE(res_2->results()->size() == 1);

	BrowseResult::SPtr browseResult_2 = boost::make_shared<BrowseResult>();
	res_2->results()->get(0, browseResult_2);
	BOOST_REQUIRE(browseResult_2->statusCode() == Success);
	BOOST_REQUIRE(browseResult_2->references()->size() == 0);
}


BOOST_AUTO_TEST_SUITE_END()

#endif
