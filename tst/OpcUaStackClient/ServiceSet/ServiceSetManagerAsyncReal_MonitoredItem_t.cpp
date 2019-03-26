#include "unittest.h"
#include "OpcUaStackClient/CryptoManagerTest.h"
#include "OpcUaStackClient/ServiceSet/ServiceSetManager.h"

using namespace OpcUaStackClient;

#ifdef REAL_SERVER

BOOST_AUTO_TEST_SUITE(ServiceSetManagerAsyncReal_MonitoredItem)

struct GValueFixture {
	GValueFixture(void)
    : cond_()
	, sessionState_(SessionServiceStateId::None)
    {}
    ~GValueFixture(void)
    {}

    Condition cond_;
    Condition cond1_;
    SessionServiceStateId sessionState_;
};

BOOST_AUTO_TEST_CASE(ServiceSetManagerAsyncReal_MonitoredItem)
{
	std::cout << "ServiceSetManagerAsyncReal_MonitoredItem_t" << std::endl;
}

BOOST_FIXTURE_TEST_CASE(ServiceSetManagerAsyncReal_MonitoredItem_create_delete, GValueFixture)
{
	OpcUaStatusCode statusCode;
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
	sessionServiceConfig.sessionServiceChangeHandler_ =
		[this] (SessionBase& session, SessionServiceStateId sessionState) {
			if (sessionState == SessionServiceStateId::Established ||
				sessionState == SessionServiceStateId::Disconnected) {
				sessionState_ = sessionState;
				cond_.sendEvent();
			}
		};

	// create session
	auto sessionService = serviceSetManager.sessionService(sessionServiceConfig);
	BOOST_REQUIRE(sessionService.get() != nullptr);

	// connect secure channel
	cond_.condition(1,0);
	sessionService->asyncConnect();
	BOOST_REQUIRE(cond_.waitForCondition(1000) == true);
	BOOST_REQUIRE(sessionState_ == SessionServiceStateId::Established);

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
	subCreateTrx->resultHandler(
		[this](ServiceTransactionCreateSubscription::SPtr& trx) {
			cond_.sendEvent();
		}
	);
	cond_.initEvent();
	subscriptionService->asyncSend(subCreateTrx);
	BOOST_REQUIRE(cond_.waitForCondition(1000) == true);
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
	monitoredItemCreateRequest->itemToMonitor().nodeId()->set(2258,0);
	monitoredItemCreateRequest->requestedParameters().clientHandle(2258);

	monCreateReq->itemsToCreate()->resize(1);
	monCreateReq->itemsToCreate()->set(0, monitoredItemCreateRequest);
	cond1_.initEvent();
	cond_.initEvent();
	monCreateTrx->resultHandler(
		[this](ServiceTransactionCreateMonitoredItems::SPtr& trx) {
			cond_.sendEvent();
		}
	);
	monitoredItemService->asyncSend(monCreateTrx);
	BOOST_REQUIRE(cond_.waitForCondition(1000) == true);
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
	cond_.initEvent();
	monDeleteTrx->resultHandler(
		[this](ServiceTransactionDeleteMonitoredItems::SPtr& trx) {
			cond_.sendEvent();
		}
	);
	monitoredItemService->asyncSend(monDeleteTrx);
	BOOST_REQUIRE(cond_.waitForCondition(1000) == true);
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
	subDeleteTrx->resultHandler(
		[this](ServiceTransactionDeleteSubscriptions::SPtr& trx) {
			cond_.sendEvent();
		}
	);
	cond_.initEvent();
	subscriptionService->asyncSend(subDeleteTrx);
	BOOST_REQUIRE(cond_.waitForCondition(1000) == true);
	BOOST_REQUIRE(subDeleteTrx->responseHeader()->serviceResult() == Success);
	BOOST_REQUIRE(subDeleteRes->results()->size() == 1);
	subDeleteRes->results()->get(0, statusCode);
	BOOST_REQUIRE(statusCode == Success);

	// disconnect secure channel
	cond_.condition(1,0);
	sessionService->asyncDisconnect();
	BOOST_REQUIRE(cond_.waitForCondition(1000) == true);
	BOOST_REQUIRE(sessionState_ == SessionServiceStateId::Disconnected);
}


BOOST_FIXTURE_TEST_CASE(ServiceSetManagerAsyncReal_MonitoredItem_data_change, GValueFixture)
{
	OpcUaStatusCode statusCode;
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
	sessionServiceConfig.sessionServiceChangeHandler_ =
		[this] (SessionBase& session, SessionServiceStateId sessionState) {
			if (sessionState == SessionServiceStateId::Established ||
				sessionState == SessionServiceStateId::Disconnected) {
				sessionState_ = sessionState;
				cond_.sendEvent();
			}
		};

	// create session
	auto sessionService = serviceSetManager.sessionService(sessionServiceConfig);
	BOOST_REQUIRE(sessionService.get() != nullptr);

	// connect secure channel
	cond_.condition(1,0);
	sessionService->asyncConnect();
	BOOST_REQUIRE(cond_.waitForCondition(1000) == true);
	BOOST_REQUIRE(sessionState_ == SessionServiceStateId::Established);

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
	subCreateTrx->resultHandler(
		[this](ServiceTransactionCreateSubscription::SPtr& trx) {
			cond_.sendEvent();
		}
	);
	cond_.initEvent();
	subscriptionService->asyncSend(subCreateTrx);
	BOOST_REQUIRE(cond_.waitForCondition(1000) == true);
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


	// data change
	for (uint32_t idx=0; idx<2; idx++) {
		cond1_.initEvent();
		BOOST_REQUIRE(cond1_.waitForEvent(3000) == true);
	}


	// delete monitored item
	auto monDeleteTrx = constructSPtr<ServiceTransactionDeleteMonitoredItems>();
	auto monDeleteReq = monDeleteTrx->request();
	auto monDeleteRes = monDeleteTrx->response();
	monDeleteReq->subscriptionId(subscriptionId);

	monDeleteReq->monitoredItemIds()->resize(1);
	monDeleteReq->monitoredItemIds()->set(0, createMonResult->monitoredItemId());
	monitoredItemService->syncSend(monDeleteTrx);
	BOOST_REQUIRE(monDeleteTrx->statusCode() == Success);


	BOOST_REQUIRE(monDeleteRes->results()->size() == 1);
	monDeleteRes->results()->get(0, statusCode);
	BOOST_REQUIRE(statusCode == Success);

	// delete subscription
	auto subDeleteTrx = constructSPtr<ServiceTransactionDeleteSubscriptions>();
	auto subDeleteReq = subDeleteTrx->request();
	auto subDeleteRes = subDeleteTrx->response();
	subDeleteReq->subscriptionIds()->resize(1);
	subDeleteReq->subscriptionIds()->set(0, subscriptionId);
	subDeleteTrx->resultHandler(
		[this](ServiceTransactionDeleteSubscriptions::SPtr& trx) {
			cond_.sendEvent();
		}
	);
	cond_.initEvent();
	subscriptionService->asyncSend(subDeleteTrx);
	BOOST_REQUIRE(cond_.waitForCondition(1000) == true);
	BOOST_REQUIRE(subDeleteTrx->responseHeader()->serviceResult() == Success);
	BOOST_REQUIRE(subDeleteRes->results()->size() == 1);
	subDeleteRes->results()->get(0, statusCode);
	BOOST_REQUIRE(statusCode == Success);

	// disconnect secure channel
	cond_.condition(1,0);
	sessionService->asyncDisconnect();
	BOOST_REQUIRE(cond_.waitForCondition(1000) == true);
	BOOST_REQUIRE(sessionState_ == SessionServiceStateId::Disconnected);
}


BOOST_AUTO_TEST_SUITE_END()

#endif
