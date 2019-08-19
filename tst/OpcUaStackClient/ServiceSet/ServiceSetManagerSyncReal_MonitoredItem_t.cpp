#include "unittest.h"
#include "OpcUaStackClient/CryptoManagerTest.h"
#include "OpcUaStackClient/ServiceSet/ServiceSetManager.h"

using namespace OpcUaStackCore;
using namespace OpcUaStackClient;

#ifdef REAL_SERVER

BOOST_AUTO_TEST_SUITE(ServiceSetManagerSyncReal_MonitoredItem)

struct GValueFixture {
	GValueFixture(void)
    : cond_()
	, cond1_()
    {}
    ~GValueFixture(void)
    {}

    Condition cond_;
    Condition cond1_;
};

BOOST_AUTO_TEST_CASE(ServiceSetManagerSyncReal_MonitoredItem)
{
	std::cout << "ServiceSetManagerSyncReal_MonitoredItem_t" << std::endl;
}

BOOST_FIXTURE_TEST_CASE(ServiceSetManagerSyncReal_MonitoredItem_create_delete, GValueFixture)
{
	OpcUaStatusCode statusCode;
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

	// create session
	auto sessionService = serviceSetManager.sessionService(sessionServiceConfig);
	BOOST_REQUIRE(sessionService.get() != nullptr);

	// connect secure channel
	BOOST_REQUIRE(sessionService->syncConnect() == Success);

	// create subscription service
	SubscriptionServiceConfig subscriptionServiceConfig;
	subscriptionServiceConfig.subscriptionStateUpdateHandler_ =
		[this](SubscriptionState subscriptionState, uint32_t subscriptionId) {
		};
	subscriptionServiceConfig.dataChangeNotificationHandler_ =
		[this](const MonitoredItemNotification::SPtr& monitoredItem) {
			cond1_.sendEvent();
		};
	auto subscriptionService = serviceSetManager.subscriptionService(sessionService, subscriptionServiceConfig);

	// create subscription
	auto subCreateTrx = constructSPtr<ServiceTransactionCreateSubscription>();
	auto subCreateReq = subCreateTrx->request();
	auto subCreateRes = subCreateTrx->response();
	subscriptionService->syncSend(subCreateTrx);
	BOOST_REQUIRE(subCreateTrx->responseHeader()->serviceResult() == Success);
	uint32_t subscriptionId = subCreateRes->subscriptionId();

	// create monitored item service
	MonitoredItemServiceConfig monitoredItemServiceConfig;
	MonitoredItemService::SPtr monitoredItemService;
	monitoredItemService = serviceSetManager.monitoredItemService(sessionService, monitoredItemServiceConfig);

	// create monitored item
	auto monCreateTrx = constructSPtr<ServiceTransactionCreateMonitoredItems>();
	auto monCreateReq = monCreateTrx->request();
	auto monCreateRes = monCreateTrx->response();
	monCreateReq->subscriptionId(subscriptionId);

	auto monitoredItemCreateRequest = constructSPtr<MonitoredItemCreateRequest>();
	monitoredItemCreateRequest->itemToMonitor().nodeId()->set(2258,0);
	monitoredItemCreateRequest->requestedParameters().clientHandle(2258);

	monCreateReq->itemsToCreate()->resize(1);
	monCreateReq->itemsToCreate()->set(0, monitoredItemCreateRequest);
	cond1_.initEvent();
	monitoredItemService->syncSend(monCreateTrx);
	BOOST_REQUIRE(monCreateTrx->statusCode() == Success);
	BOOST_REQUIRE(monCreateRes->results()->size() == 1);

	MonitoredItemCreateResult::SPtr createMonResult;
	monCreateRes->results()->get(0, createMonResult);
	BOOST_REQUIRE(createMonResult->statusCode() == Success);
	uint32_t monitoredItemId = createMonResult->monitoredItemId();

	BOOST_REQUIRE(cond1_.waitForCondition(1000) == true);


	// delete monitored item
	auto monDeleteTrx = constructSPtr<ServiceTransactionDeleteMonitoredItems>();
	auto monDeleteReq = monDeleteTrx->request();
	monDeleteReq->subscriptionId(subscriptionId);

	monDeleteReq->monitoredItemIds()->resize(1);
	monDeleteReq->monitoredItemIds()->set(0, createMonResult->monitoredItemId());

	monitoredItemService->syncSend(monDeleteTrx);
	BOOST_REQUIRE(monDeleteTrx->statusCode() == Success);

	DeleteMonitoredItemsResponse::SPtr monDeleteRes = monDeleteTrx->response();
	BOOST_REQUIRE(monDeleteRes->results()->size() == 1);

	monDeleteRes->results()->get(0, statusCode);
	BOOST_REQUIRE(statusCode == Success);

	// delete subscription
	auto subDeleteTrx = constructSPtr<ServiceTransactionDeleteSubscriptions>();
	auto subDeleteReq = subDeleteTrx->request();
	auto subDeleteRes = subDeleteTrx->response();
	subDeleteReq->subscriptionIds()->resize(1);
	subDeleteReq->subscriptionIds()->set(0, subscriptionId);
	subscriptionService->syncSend(subDeleteTrx);
	BOOST_REQUIRE(subDeleteTrx->responseHeader()->serviceResult() == Success);
	BOOST_REQUIRE(subDeleteRes->results()->size() == 1);
	subDeleteRes->results()->get(0, statusCode);
	BOOST_REQUIRE(statusCode == Success);

	// disconnect secure channel
	BOOST_REQUIRE(sessionService->syncDisconnect() == Success);
}


BOOST_FIXTURE_TEST_CASE(ServiceSetManagerSyncReal_MonitoredItem_data_change, GValueFixture)
{
	OpcUaStatusCode statusCode;
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

	// create session
	SessionService::SPtr sessionService;
	sessionService = serviceSetManager.sessionService(sessionServiceConfig);
	BOOST_REQUIRE(sessionService.get() != nullptr);

	// connect secure channel
	BOOST_REQUIRE(sessionService->syncConnect() == Success);

	// create subscription service
	SubscriptionServiceConfig subscriptionServiceConfig;
	subscriptionServiceConfig.subscriptionStateUpdateHandler_ =
		[this](SubscriptionState subscriptionState, uint32_t subscriptionId) {
		};
	subscriptionServiceConfig.dataChangeNotificationHandler_ =
		[this](const MonitoredItemNotification::SPtr& monitoredItem) {
			cond1_.sendEvent();
		};
	SubscriptionService::SPtr subscriptionService;
	subscriptionService = serviceSetManager.subscriptionService(sessionService, subscriptionServiceConfig);

	// create subscription
	auto subCreateTrx = constructSPtr<ServiceTransactionCreateSubscription>();
	auto subCreateReq = subCreateTrx->request();
	auto subCreateRes = subCreateTrx->response();
	subscriptionService->syncSend(subCreateTrx);
	BOOST_REQUIRE(subCreateTrx->responseHeader()->serviceResult() == Success);
	uint32_t subscriptionId = subCreateRes->subscriptionId();

	// create monitored item service
	MonitoredItemServiceConfig monitoredItemServiceConfig;
	auto monitoredItemService = serviceSetManager.monitoredItemService(sessionService, monitoredItemServiceConfig);

	// create monitored item
	auto monCreateTrx = constructSPtr<ServiceTransactionCreateMonitoredItems>();
	auto monCreateReq = monCreateTrx->request();
	auto monCreateRes = monCreateTrx->response();
	monCreateReq->subscriptionId(subscriptionId);

	auto monitoredItemCreateRequest = constructSPtr<MonitoredItemCreateRequest>();
	monitoredItemCreateRequest->itemToMonitor().nodeId()->set(218,3);
	monitoredItemCreateRequest->requestedParameters().clientHandle(218);

	monCreateReq->itemsToCreate()->resize(1);
	monCreateReq->itemsToCreate()->set(0, monitoredItemCreateRequest);
	cond1_.initEvent();
	monitoredItemService->syncSend(monCreateTrx);
	BOOST_REQUIRE(monCreateTrx->statusCode() == Success);
	BOOST_REQUIRE(monCreateRes->results()->size() == 1);

	MonitoredItemCreateResult::SPtr createMonResult;
	monCreateRes->results()->get(0, createMonResult);
	BOOST_REQUIRE(createMonResult->statusCode() == Success);
	uint32_t monitoredItemId = createMonResult->monitoredItemId();

	BOOST_REQUIRE(cond1_.waitForCondition(1000) == true);


	// data change
	for (uint32_t idx=0; idx<2; idx++) {
		cond1_.initEvent();
		BOOST_REQUIRE(cond1_.waitForEvent(4000) == true);
	}


	// delete monitored item
	auto monDeleteTrx = constructSPtr<ServiceTransactionDeleteMonitoredItems>();
	auto monDeleteReq = monDeleteTrx->request();
	monDeleteReq->subscriptionId(subscriptionId);

	monDeleteReq->monitoredItemIds()->resize(1);
	monDeleteReq->monitoredItemIds()->set(0, createMonResult->monitoredItemId());

	monitoredItemService->syncSend(monDeleteTrx);
	BOOST_REQUIRE(monDeleteTrx->statusCode() == Success);

	auto monDeleteRes = monDeleteTrx->response();
	BOOST_REQUIRE(monDeleteRes->results()->size() == 1);

	monDeleteRes->results()->get(0, statusCode);
	BOOST_REQUIRE(statusCode == Success);

	// delete subscription
	auto subDeleteTrx = constructSPtr<ServiceTransactionDeleteSubscriptions>();
	auto subDeleteReq = subDeleteTrx->request();
	auto subDeleteRes = subDeleteTrx->response();
	subDeleteReq->subscriptionIds()->resize(1);
	subDeleteReq->subscriptionIds()->set(0, subscriptionId);

	subscriptionService->syncSend(subDeleteTrx);
	BOOST_REQUIRE(subDeleteTrx->responseHeader()->serviceResult() == Success);
	BOOST_REQUIRE(subDeleteRes->results()->size() == 1);
	subDeleteRes->results()->get(0, statusCode);
	BOOST_REQUIRE(statusCode == Success);

	// disconnect secure channel
	BOOST_REQUIRE(sessionService->syncDisconnect() == Success);
}


BOOST_AUTO_TEST_SUITE_END()

#endif
