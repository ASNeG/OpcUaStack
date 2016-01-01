#include "unittest.h"
#include "OpcUaStackCore/Base/Condition.h"
#include "OpcUaStackCore/Core/Core.h"
#include "OpcUaStackClient/ServiceSet/SessionService.h"
#include "OpcUaStackClient/ServiceSet/SubscriptionService.h"

#ifdef REAL_SERVER

using namespace OpcUaStackCore;
using namespace OpcUaStackClient;

class SubscriptionRealTest
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

class SubscriptionRealTestSubscriptionManager
: public SubscriptionManagerIf
, public SubscriptionServiceIf
, public SubscriptionServicePublishIf
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

};


BOOST_AUTO_TEST_SUITE(SubscriptionReal_)

BOOST_AUTO_TEST_CASE(SubscriptionReal_)
{
	std::cout << "SubscriptionReal_t" << std::endl;
}

BOOST_AUTO_TEST_CASE(SubscriptionReal_async_create_delete_subscription)
{
	Core core;
	core.init();

	IOThread ioThread1;
	IOThread ioThread2;
	ioThread1.startup();
	ioThread2.startup();

	// set secure channel configuration
	SecureChannelClientConfig::SPtr secureChannelClientConfig = constructSPtr<SecureChannelClientConfig>();
	secureChannelClientConfig->endpointUrl(REAL_SERVER_URI);
	secureChannelClientConfig->debug(true);
	secureChannelClientConfig->debugHeader(true);

	// set session configuration
	SessionConfig::SPtr sessionConfig = constructSPtr<SessionConfig>();
	sessionConfig->sessionName_ = "urn:127.0.0.1:ASNeG.de:ASNeG-Client";
	sessionConfig->applicationDescription_->applicationUri("urn:127.0.0.1:ASNeG.de:ASNeG-Client");
	sessionConfig->applicationDescription_->productUri("urn:ASNeG.de:ASNeG-Client");
	sessionConfig->applicationDescription_->applicationName().set("en", "ASNeG-Client");

	// init session
	SubscriptionRealTest subscriptionRealTest;
	SessionService sessionService(&ioThread1);
	sessionService.sessionServiceIf(&subscriptionRealTest);

	// connect session
	subscriptionRealTest.sessionStateUpdate_.condition(1,0);
	sessionService.asyncConnect(sessionConfig, secureChannelClientConfig);
	BOOST_REQUIRE(subscriptionRealTest.sessionStateUpdate_.waitForCondition(1000) == true);
	BOOST_REQUIRE(subscriptionRealTest.sessionState_ == SS_Connect);

	// init subscription manager
	SubscriptionRealTestSubscriptionManager subscriptionRealTestSubscriptionManager;
	SubscriptionService subscriptionManager;
	subscriptionManager.ioThread(&ioThread2);
	subscriptionManager.subscriptionManagerIf(&subscriptionRealTestSubscriptionManager);
	subscriptionManager.subscriptionServiceIf(&subscriptionRealTestSubscriptionManager);
	subscriptionManager.subscriptionServicePublishIf(&subscriptionRealTestSubscriptionManager);
	subscriptionManager.componentSession(sessionService.component());

	// create subscription
	ServiceTransactionCreateSubscription::SPtr createTrx = constructSPtr<ServiceTransactionCreateSubscription>();
	CreateSubscriptionRequest::SPtr createReq = createTrx->request();
	subscriptionRealTestSubscriptionManager.subscriptionServiceCreateSubscriptionResponse_.condition(1,0);
	subscriptionManager.asyncSend(createTrx);
	BOOST_REQUIRE(subscriptionRealTestSubscriptionManager.subscriptionServiceCreateSubscriptionResponse_.waitForCondition(1000) == true);
	BOOST_REQUIRE(createTrx->responseHeader()->serviceResult() == 0);
	CreateSubscriptionResponse::SPtr createRes = createTrx->response();
	uint32_t subscriptionId = createRes->subscriptionId();

	// delete subscription
	ServiceTransactionDeleteSubscriptions::SPtr deleteTrx = constructSPtr<ServiceTransactionDeleteSubscriptions>();
	DeleteSubscriptionsRequest::SPtr deleteReq = deleteTrx->request();
	deleteReq->subscriptionIds()->resize(1);
	deleteReq->subscriptionIds()->set(0, subscriptionId);
	subscriptionRealTestSubscriptionManager.subscriptionServiceDeleteSubscriptionsResponse_.condition(1,0);
	subscriptionManager.asyncSend(deleteTrx);
	BOOST_REQUIRE(subscriptionRealTestSubscriptionManager.subscriptionServiceDeleteSubscriptionsResponse_.waitForCondition(1000) == true);
	BOOST_REQUIRE(deleteTrx->responseHeader()->serviceResult() == 0);

	// disconnect session
	subscriptionRealTest.sessionStateUpdate_.condition(1,0);
	sessionService.asyncDisconnect();
	BOOST_REQUIRE(subscriptionRealTest.sessionStateUpdate_.waitForCondition(1000) == true);
	BOOST_REQUIRE(subscriptionRealTest.sessionState_ == SS_Disconnect);

	ioThread1.shutdown();
	ioThread2.shutdown();
}

BOOST_AUTO_TEST_CASE(SubscriptionReal_async_create_delete_subscription_2_subscriptions)
{
	Core core;
	core.init();

	IOThread ioThread1;
	IOThread ioThread2;
	ioThread1.startup();
	ioThread2.startup();

	// set secure channel configuration
	SecureChannelClientConfig::SPtr secureChannelClientConfig = constructSPtr<SecureChannelClientConfig>();
	secureChannelClientConfig->endpointUrl(REAL_SERVER_URI);
	secureChannelClientConfig->debug(false);
	secureChannelClientConfig->debugHeader(false);

	// set session configuration
	SessionConfig::SPtr sessionConfig = constructSPtr<SessionConfig>();
	sessionConfig->sessionName_ = "urn:127.0.0.1:ASNeG.de:ASNeG-Client";
	sessionConfig->applicationDescription_->applicationUri("urn:127.0.0.1:ASNeG.de:ASNeG-Client");
	sessionConfig->applicationDescription_->productUri("urn:ASNeG.de:ASNeG-Client");
	sessionConfig->applicationDescription_->applicationName().set("en", "ASNeG-Client");

	// init session
	SubscriptionRealTest subscriptionRealTest;
	SessionService sessionService(&ioThread1);
	sessionService.sessionServiceIf(&subscriptionRealTest);

	// connect session
	subscriptionRealTest.sessionStateUpdate_.condition(1,0);
	sessionService.asyncConnect(sessionConfig, secureChannelClientConfig);
	BOOST_REQUIRE(subscriptionRealTest.sessionStateUpdate_.waitForCondition(1000) == true);
	BOOST_REQUIRE(subscriptionRealTest.sessionState_ == SS_Connect);

	// init subscription manager
	SubscriptionRealTestSubscriptionManager subscriptionRealTestSubscriptionManager;
	SubscriptionService subscriptionManager;
	subscriptionManager.ioThread(&ioThread2);
	subscriptionManager.subscriptionManagerIf(&subscriptionRealTestSubscriptionManager);
	subscriptionManager.subscriptionServiceIf(&subscriptionRealTestSubscriptionManager);
	subscriptionManager.subscriptionServicePublishIf(&subscriptionRealTestSubscriptionManager);
	subscriptionManager.componentSession(sessionService.component());

	// create subscription
	ServiceTransactionCreateSubscription::SPtr createTrx = constructSPtr<ServiceTransactionCreateSubscription>();
	CreateSubscriptionRequest::SPtr createReq = createTrx->request();
	subscriptionRealTestSubscriptionManager.subscriptionServiceCreateSubscriptionResponse_.condition(1,0);
	subscriptionManager.asyncSend(createTrx);
	BOOST_REQUIRE(subscriptionRealTestSubscriptionManager.subscriptionServiceCreateSubscriptionResponse_.waitForCondition(1000) == true);
	BOOST_REQUIRE(createTrx->responseHeader()->serviceResult() == 0);
	CreateSubscriptionResponse::SPtr createRes = createTrx->response();
	uint32_t subscriptionId1 = createRes->subscriptionId();

	subscriptionRealTestSubscriptionManager.subscriptionServiceCreateSubscriptionResponse_.condition(1,0);
	subscriptionManager.asyncSend(createTrx);
	BOOST_REQUIRE(subscriptionRealTestSubscriptionManager.subscriptionServiceCreateSubscriptionResponse_.waitForCondition(1000) == true);
	BOOST_REQUIRE(createTrx->responseHeader()->serviceResult() == 0);
	createRes = createTrx->response();
	uint32_t subscriptionId2 = createRes->subscriptionId();

	// delete subscription
	ServiceTransactionDeleteSubscriptions::SPtr deleteTrx = constructSPtr<ServiceTransactionDeleteSubscriptions>();
	DeleteSubscriptionsRequest::SPtr deleteReq = deleteTrx->request();
	deleteReq->subscriptionIds()->resize(2);
	deleteReq->subscriptionIds()->set(0, subscriptionId1);
	deleteReq->subscriptionIds()->set(1, subscriptionId2);
	subscriptionRealTestSubscriptionManager.subscriptionServiceDeleteSubscriptionsResponse_.condition(1,0);
	subscriptionManager.asyncSend(deleteTrx);
	BOOST_REQUIRE(subscriptionRealTestSubscriptionManager.subscriptionServiceDeleteSubscriptionsResponse_.waitForCondition(1000) == true);
	BOOST_REQUIRE(deleteTrx->responseHeader()->serviceResult() == 0);

	// disconnect session
	subscriptionRealTest.sessionStateUpdate_.condition(1,0);
	sessionService.asyncDisconnect();
	BOOST_REQUIRE(subscriptionRealTest.sessionStateUpdate_.waitForCondition(1000) == true);
	BOOST_REQUIRE(subscriptionRealTest.sessionState_ == SS_Disconnect);

	ioThread1.shutdown();
	ioThread2.shutdown();
}

BOOST_AUTO_TEST_SUITE_END()

#endif
