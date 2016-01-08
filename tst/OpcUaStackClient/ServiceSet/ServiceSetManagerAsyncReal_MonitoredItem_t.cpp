#include "unittest.h"
#include "OpcUaStackClient/ServiceSet/ServiceSetManager.h"

using namespace OpcUaStackClient;

#ifdef REAL_SERVER

BOOST_AUTO_TEST_SUITE(ServiceSetManagerAsyncReal_MonitoredItem)

BOOST_AUTO_TEST_CASE(ServiceSetManagerAsyncReal_MonitoredItem)
{
	std::cout << "ServiceSetManagerAsyncReal_MonitoredItem_t" << std::endl;
}

BOOST_AUTO_TEST_CASE(ServiceSetManagerAsyncReal_MonitoredItem_create_delete)
{
	OpcUaStatusCode statusCode;
	ServiceSetManager serviceSetManager;
	SessionServiceIfTestHandler sessionServiceIfTestHandler;
	SubscriptionServiceIfTestHandler subscriptionServiceIfTestHandler;
	MonitoredItemServiceIfTestHandler monitoredItemServiceIfTestHandler;

	// set secure channel configuration
	SessionServiceConfig sessionServiceConfig;
	sessionServiceConfig.sessionServiceIf_ = &sessionServiceIfTestHandler;
	sessionServiceConfig.secureChannelClient_->endpointUrl(REAL_SERVER_URI);
	sessionServiceConfig.session_->sessionName_(REAL_SESSION_NAME);

	// create session
	SessionService::SPtr sessionService;
	sessionService = serviceSetManager.sessionService(sessionServiceConfig);
	BOOST_REQUIRE(sessionService.get() != nullptr);

	// connect secure channel
	sessionServiceIfTestHandler.sessionStateUpdate_.condition(1,0);
	sessionService->asyncConnect();
	BOOST_REQUIRE(sessionServiceIfTestHandler.sessionStateUpdate_.waitForCondition(1000) == true);
	BOOST_REQUIRE(sessionServiceIfTestHandler.sessionState_ == SS_Connect);

	// create subscription service
	SubscriptionServiceConfig subscriptionServiceConfig;
	subscriptionServiceConfig.subscriptionServiceIf_ = &subscriptionServiceIfTestHandler;
	SubscriptionService::SPtr subscriptionService;
	subscriptionService = serviceSetManager.subscriptionService(sessionService, subscriptionServiceConfig);

	// create subscription
	ServiceTransactionCreateSubscription::SPtr subCreateTrx = ServiceTransactionCreateSubscription::construct();
	CreateSubscriptionRequest::SPtr subCreateReq = subCreateTrx->request();
	CreateSubscriptionResponse::SPtr subCreateRes = subCreateTrx->response();
	subscriptionServiceIfTestHandler.subscriptionServiceCreateSubscriptionResponse_.condition(1,0);
	subscriptionService->asyncSend(subCreateTrx);
	BOOST_REQUIRE(subscriptionServiceIfTestHandler.subscriptionServiceCreateSubscriptionResponse_.waitForCondition(1000) == true);
	BOOST_REQUIRE(subCreateTrx->responseHeader()->serviceResult() == Success);
	uint32_t subscriptionId = subCreateRes->subscriptionId();

	// create monitored item service
	MonitoredItemServiceConfig monitoredItemServiceConfig;
	monitoredItemServiceConfig.monitoredItemServiceIf_ = &monitoredItemServiceIfTestHandler;
	MonitoredItemService::SPtr monitoredItemService;
	monitoredItemService = serviceSetManager.monitoredItemService(sessionService, monitoredItemServiceConfig);

	// create monitored item
	ServiceTransactionCreateMonitoredItems::SPtr monCreateTrx = ServiceTransactionCreateMonitoredItems::construct();
	CreateMonitoredItemsRequest::SPtr monCreateReq = monCreateTrx->request();
	CreateMonitoredItemsResponse::SPtr monCreateRes = monCreateTrx->response();
	monCreateReq->subscriptionId(subscriptionId);

	MonitoredItemCreateRequest::SPtr monitoredItemCreateRequest = MonitoredItemCreateRequest::construct();
	monitoredItemCreateRequest->itemToMonitor().nodeId()->set(2258,0);
	monitoredItemCreateRequest->requestedParameters().clientHandle(2258);

	monCreateReq->itemsToCreate()->resize(1);
	monCreateReq->itemsToCreate()->set(0, monitoredItemCreateRequest);
	subscriptionServiceIfTestHandler.dataChangeNotification_.condition(1, 0);
	monitoredItemServiceIfTestHandler.monitoredItemServiceCreateMonitoredItemsResponse_.condition(1,0);
	monitoredItemService->asyncSend(monCreateTrx);
	BOOST_REQUIRE(monitoredItemServiceIfTestHandler.monitoredItemServiceCreateMonitoredItemsResponse_.waitForCondition(1000) == true);
	BOOST_REQUIRE(monCreateTrx->statusCode() == Success);
	BOOST_REQUIRE(monCreateRes->results()->size() == 1);

	MonitoredItemCreateResult::SPtr createMonResult;
	monCreateRes->results()->get(0, createMonResult);
	BOOST_REQUIRE(createMonResult->statusCode() == Success);
	uint32_t monitoredItemId = createMonResult->monitoredItemId();

	BOOST_REQUIRE(subscriptionServiceIfTestHandler.dataChangeNotification_.waitForCondition(1000) == true);


	// delete monitored item
	ServiceTransactionDeleteMonitoredItems::SPtr monDeleteTrx = ServiceTransactionDeleteMonitoredItems::construct();
	DeleteMonitoredItemsRequest::SPtr monDeleteReq = monDeleteTrx->request();
	monDeleteReq->subscriptionId(subscriptionId);

	monDeleteReq->monitoredItemIds()->resize(1);
	monDeleteReq->monitoredItemIds()->set(0, createMonResult->monitoredItemId());
	monitoredItemServiceIfTestHandler.monitoredItemServiceDeleteMonitoredItemsResponse_.condition(1,0);
	monitoredItemService->asyncSend(monDeleteTrx);
	BOOST_REQUIRE(monitoredItemServiceIfTestHandler.monitoredItemServiceDeleteMonitoredItemsResponse_.waitForCondition(1000) == true);
	BOOST_REQUIRE(monDeleteTrx->statusCode() == Success);

	DeleteMonitoredItemsResponse::SPtr monDeleteRes = monDeleteTrx->response();
	BOOST_REQUIRE(monDeleteRes->results()->size() == 1);

	monDeleteRes->results()->get(0, statusCode);
	BOOST_REQUIRE(statusCode == Success);

	// delete subscription
	ServiceTransactionDeleteSubscriptions::SPtr subDeleteTrx = ServiceTransactionDeleteSubscriptions::construct();
	DeleteSubscriptionsRequest::SPtr subDeleteReq = subDeleteTrx->request();
	DeleteSubscriptionsResponse::SPtr subDeleteRes = subDeleteTrx->response();
	subDeleteReq->subscriptionIds()->resize(1);
	subDeleteReq->subscriptionIds()->set(0, subscriptionId);
	subscriptionServiceIfTestHandler.subscriptionServiceDeleteSubscriptionsResponse_.condition(1,0);
	subscriptionService->asyncSend(subDeleteTrx);
	BOOST_REQUIRE(subscriptionServiceIfTestHandler.subscriptionServiceDeleteSubscriptionsResponse_.waitForCondition(1000) == true);
	BOOST_REQUIRE(subDeleteTrx->responseHeader()->serviceResult() == Success);
	BOOST_REQUIRE(subDeleteRes->results()->size() == 1);
	subDeleteRes->results()->get(0, statusCode);
	BOOST_REQUIRE(statusCode == Success);

	// disconnect secure channel
	sessionServiceIfTestHandler.sessionStateUpdate_.condition(1,0);
	sessionService->asyncDisconnect();
	BOOST_REQUIRE(sessionServiceIfTestHandler.sessionStateUpdate_.waitForCondition(1000) == true);
	BOOST_REQUIRE(sessionServiceIfTestHandler.sessionState_ == SS_Disconnect);
}


BOOST_AUTO_TEST_SUITE_END()

#endif
