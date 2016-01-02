#include "unittest.h"
#include "OpcUaStackCore/Base/Condition.h"
#include "OpcUaStackCore/Core/Core.h"
#include "OpcUaStackClient/ServiceSet/SessionService.h"
#include "OpcUaStackClient/ServiceSet/SubscriptionService.h"
#include "OpcUaStackClient/ServiceSet/MonitoredItemService.h"

#ifdef REAL_SERVER

using namespace OpcUaStackCore;
using namespace OpcUaStackClient;

class MonitoredItemRealTest
: public SessionServiceIf
{
  public:
	SessionState sessionState_;
	Condition sessionStateUpdate_;
	void sessionStateUpdate(SessionBase& session, SessionState sessionState)
	{
		std::cout << "handleConnect client" << std::endl;
		sessionState_ = sessionState;
		sessionStateUpdate_.conditionValueDec();
	}
};

class MonitoredItemRealTestSubscriptionManager
: public SubscriptionManagerIf
, public SubscriptionServiceIf
, public SubscriptionServicePublishIf
, public MonitoredItemServiceIf
{
  public:
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// SubscriptionManagerIf
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	Condition dataChangeNotification_;
	void dataChangeNotification(const MonitoredItemNotification::SPtr& monitoredItem)
	{
		dataChangeNotification_.conditionValueDec();
	}

	SubscriptionState subscriptionState_;
	Condition subscriptionStateUpdate_;
    void subscriptionStateUpdate(SubscriptionState subscriptionState, uint32_t subscriptionId)
    {
    	subscriptionState_ = subscriptionState;
    	subscriptionStateUpdate_.conditionValueDec();
    }

    // ------------------------------------------------------------------------
    // ------------------------------------------------------------------------
    //
    // SubscriptionServicePublishIf
    //
    // ------------------------------------------------------------------------
    // ------------------------------------------------------------------------
    Condition subscriptionServiceCreateSubscriptionResponse_;
    void subscriptionServiceCreateSubscriptionResponse(ServiceTransactionCreateSubscription::SPtr serviceTransactionCreateSubscription)
    {
    	subscriptionServiceCreateSubscriptionResponse_.conditionValueDec();
    }

    Condition subscriptionServiceModifySubscriptionResponse_;
    void subscriptionServiceModifySubscriptionResponse(ServiceTransactionModifySubscription::SPtr serviceTransactionModifySubscription)
    {
    	subscriptionServiceModifySubscriptionResponse_.conditionValueDec();
    }

    Condition subscriptionServiceTransferSubscriptionsResponse_;
    void subscriptionServiceTransferSubscriptionsResponse(ServiceTransactionTransferSubscriptions::SPtr serviceTransactionTransferSubscriptions)
    {
    	subscriptionServiceTransferSubscriptionsResponse_.conditionValueDec();
    }

    Condition subscriptionServiceDeleteSubscriptionsResponse_;
    void subscriptionServiceDeleteSubscriptionsResponse(ServiceTransactionDeleteSubscriptions::SPtr serviceTransactionDeleteSubscriptions)
    {
    	subscriptionServiceDeleteSubscriptionsResponse_.conditionValueDec();
    }

    // ------------------------------------------------------------------------
    // ------------------------------------------------------------------------
    //
    // SubscriptionServiceIf
    //
    // ------------------------------------------------------------------------
    // ------------------------------------------------------------------------
    Condition subscriptionServiceSetPublishingModeResponse_;
    void subscriptionServiceSetPublishingModeResponse(ServiceTransactionSetPublishingMode::SPtr serviceTransactionSetPublishingMode)
    {
    	subscriptionServiceSetPublishingModeResponse_.conditionValueDec();
    }

    Condition subscriptionServicePublishResponse_;
    void subscriptionServicePublishResponse(ServiceTransactionPublish::SPtr serviceTransactionPublish)
    {
    	subscriptionServicePublishResponse_.conditionValueDec();
    }

    Condition subscriptionServiceRepublishResponse_;
    void subscriptionServiceRepublishResponse(ServiceTransactionRepublish::SPtr serviceTransactionRepublish)
    {
    	subscriptionServiceRepublishResponse_.conditionValueDec();
    }

    // ------------------------------------------------------------------------
    // ------------------------------------------------------------------------
    //
    // MonitoredItemServiceIf
    //
    // ------------------------------------------------------------------------
    // ------------------------------------------------------------------------
    Condition monitoredItemServiceCreateMonitoredItemsResponse_;
    void monitoredItemServiceCreateMonitoredItemsResponse(ServiceTransactionCreateMonitoredItems::SPtr serviceTransactionCreateMonitoredItems)
    {
    	monitoredItemServiceCreateMonitoredItemsResponse_.conditionValueDec();
    }

    Condition monitoredItemServiceDeleteMonitoredItemsResponse_;
    void monitoredItemServiceDeleteMonitoredItemsResponse(ServiceTransactionDeleteMonitoredItems::SPtr serviceTransactionDeleteMonitoredItems)
    {
    	monitoredItemServiceDeleteMonitoredItemsResponse_.conditionValueDec();
    }

    Condition monitoredItemServiceModifyMonitoredItemsResponse_;
    void monitoredItemServiceModifyMonitoredItemsResponse(ServiceTransactionModifyMonitoredItems::SPtr serviceTransactionModifyMonitoredItems)
    {
    	monitoredItemServiceModifyMonitoredItemsResponse_.conditionValueDec();
    }

    Condition monitoredItemServiceSetMonitoringModeResponse_;
    void monitoredItemServiceSetMonitoringModeResponse(ServiceTransactionSetMonitoringMode::SPtr serviceTransactionSetMonitoringMode)
    {
    	monitoredItemServiceSetMonitoringModeResponse_.conditionValueDec();
    }

    Condition monitoredItemServiceSetTriggeringResponse_;
    void monitoredItemServiceSetTriggeringResponse(ServiceTransactionSetTriggering::SPtr serviceTransactionSetTriggering)
    {
    	monitoredItemServiceSetTriggeringResponse_.conditionValueDec();
    }

};


BOOST_AUTO_TEST_SUITE(MonitoredItemReal_)

BOOST_AUTO_TEST_CASE(MonitoredItemReal_)
{
	std::cout << "MonitoredItemReal_t" << std::endl;
}

BOOST_AUTO_TEST_CASE(MonitoredItemReal_async_create_delete_subscription)
{
	Core core;
	core.init();

	IOThread ioThread1;
	IOThread ioThread2;
	IOThread ioThread3;
	ioThread1.startup();
	ioThread2.startup();
	ioThread3.startup();

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// set secure channel configuration
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	SecureChannelClientConfig::SPtr secureChannelClientConfig = constructSPtr<SecureChannelClientConfig>();
	secureChannelClientConfig->endpointUrl(REAL_SERVER_URI);
	secureChannelClientConfig->debug(false);
	secureChannelClientConfig->debugHeader(false);

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// set session configuration
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	SessionConfig::SPtr sessionConfig = constructSPtr<SessionConfig>();
	sessionConfig->sessionName_ = "urn:127.0.0.1:ASNeG.de:ASNeG-Client";
	sessionConfig->applicationDescription_->applicationUri("urn:127.0.0.1:ASNeG.de:ASNeG-Client");
	sessionConfig->applicationDescription_->productUri("urn:ASNeG.de:ASNeG-Client");
	sessionConfig->applicationDescription_->applicationName().set("en", "ASNeG-Client");

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// init session
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	MonitoredItemRealTest monitoredItemRealTest;
	SessionService sessionService(&ioThread1);
	sessionService.sessionServiceIf(&monitoredItemRealTest);

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// connect session
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	monitoredItemRealTest.sessionStateUpdate_.condition(1,0);
	sessionService.asyncConnect(sessionConfig, secureChannelClientConfig);
	BOOST_REQUIRE(monitoredItemRealTest.sessionStateUpdate_.waitForCondition(1000) == true);
	BOOST_REQUIRE(monitoredItemRealTest.sessionState_ == SS_Connect);

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// init subscription manager
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	MonitoredItemRealTestSubscriptionManager monitoredItemRealTestSubscriptionManager;
	SubscriptionService subscriptionManager(&ioThread2);
	subscriptionManager.ioThread(&ioThread2);
	subscriptionManager.subscriptionManagerIf(&monitoredItemRealTestSubscriptionManager);
	subscriptionManager.subscriptionServiceIf(&monitoredItemRealTestSubscriptionManager);
	subscriptionManager.subscriptionServicePublishIf(&monitoredItemRealTestSubscriptionManager);
	subscriptionManager.componentSession(sessionService.component());

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// create subscription
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	ServiceTransactionCreateSubscription::SPtr createTrx = constructSPtr<ServiceTransactionCreateSubscription>();
	CreateSubscriptionRequest::SPtr createReq = createTrx->request();
	monitoredItemRealTestSubscriptionManager.subscriptionServiceCreateSubscriptionResponse_.condition(1,0);
	subscriptionManager.asyncSend(createTrx);
	BOOST_REQUIRE(monitoredItemRealTestSubscriptionManager.subscriptionServiceCreateSubscriptionResponse_.waitForCondition(1000) == true);
	BOOST_REQUIRE(createTrx->responseHeader()->serviceResult() == 0);
	CreateSubscriptionResponse::SPtr createRes = createTrx->response();
	uint32_t subscriptionId = createRes->subscriptionId();

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// init monitored item service
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	MonitoredItemService monitoredItemService;
	monitoredItemService.ioThread(&ioThread3);
	monitoredItemService.monitoredItemServiceIf(&monitoredItemRealTestSubscriptionManager);
	monitoredItemService.componentSession(sessionService.component());

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// create monitored item
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	ServiceTransactionCreateMonitoredItems::SPtr monCreateTrx = constructSPtr<ServiceTransactionCreateMonitoredItems>();
	CreateMonitoredItemsRequest::SPtr monCreateReq = monCreateTrx->request();
	monCreateReq->subscriptionId(subscriptionId);

	MonitoredItemCreateRequest::SPtr monitoredItemCreateRequest = MonitoredItemCreateRequest::construct();
	monitoredItemCreateRequest->itemToMonitor().nodeId()->set((uint32_t)2258);
	monitoredItemCreateRequest->requestedParameters().clientHandle(2258);

	monCreateReq->itemsToCreate()->resize(1);
	monCreateReq->itemsToCreate()->set(0, monitoredItemCreateRequest);

	monitoredItemRealTestSubscriptionManager.dataChangeNotification_.condition(1, 0);
	monitoredItemRealTestSubscriptionManager.monitoredItemServiceCreateMonitoredItemsResponse_.condition(1, 0);
	monitoredItemService.send(monCreateTrx);

	BOOST_REQUIRE(monitoredItemRealTestSubscriptionManager.monitoredItemServiceCreateMonitoredItemsResponse_.waitForCondition(1000) == true);
	CreateMonitoredItemsResponse::SPtr monCreateRes = monCreateTrx->response();
	BOOST_REQUIRE(monCreateTrx->statusCode() == Success);
	BOOST_REQUIRE(monCreateRes->results()->size() == 1);

	MonitoredItemCreateResult::SPtr createMonResult;
	monCreateRes->results()->get(0, createMonResult);

	BOOST_REQUIRE(monitoredItemRealTestSubscriptionManager.dataChangeNotification_.waitForCondition(1000) == true);


	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// delete monitored item request
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------


	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// delete subscription
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	ServiceTransactionDeleteSubscriptions::SPtr deleteTrx = constructSPtr<ServiceTransactionDeleteSubscriptions>();
	DeleteSubscriptionsRequest::SPtr deleteReq = deleteTrx->request();
	deleteReq->subscriptionIds()->resize(1);
	deleteReq->subscriptionIds()->set(0, subscriptionId);
	monitoredItemRealTestSubscriptionManager.subscriptionServiceDeleteSubscriptionsResponse_.condition(1,0);
	subscriptionManager.asyncSend(deleteTrx);
	BOOST_REQUIRE(monitoredItemRealTestSubscriptionManager.subscriptionServiceDeleteSubscriptionsResponse_.waitForCondition(1000) == true);
	BOOST_REQUIRE(deleteTrx->responseHeader()->serviceResult() == 0);

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// disconnect session
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	monitoredItemRealTest.sessionStateUpdate_.condition(1,0);
	sessionService.asyncDisconnect();
	BOOST_REQUIRE(monitoredItemRealTest.sessionStateUpdate_.waitForCondition(1000) == true);
	BOOST_REQUIRE(monitoredItemRealTest.sessionState_ == SS_Disconnect);

	ioThread1.shutdown();
	ioThread2.shutdown();
	ioThread3.shutdown();
}

BOOST_AUTO_TEST_SUITE_END()

#endif
