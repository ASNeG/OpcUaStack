#include "unittest.h"
#include "OpcUaStackClient/CryptoManagerTest.h"
#include "OpcUaStackClient/ServiceSet/ServiceSetManager.h"

using namespace OpcUaStackClient;

#ifdef REAL_SERVER

BOOST_AUTO_TEST_SUITE(ServiceSetManagerAsyncReal_Subscription)

struct GValueFixture {
	GValueFixture(void)
    : cond_()
	, sessionState_(SessionServiceStateId::None)
    {}
    ~GValueFixture(void)
    {}

    Condition cond_;
    SessionServiceStateId sessionState_;
};

BOOST_AUTO_TEST_CASE(ServiceSetManagerAsyncReal_Subscription)
{
	std::cout << "ServiceSetManagerAsyncReal_Subscription_t" << std::endl;
}

BOOST_FIXTURE_TEST_CASE(ServiceSetManagerAsyncReal_Subscriptionsubscription_create_delete, GValueFixture)
{
	ServiceSetManager serviceSetManager;
	SubscriptionServiceIfTestHandler subscriptionServiceIfTestHandler;

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
	sessionServiceConfig.sessionServiceChangeHandler_ =
		[this] (SessionBase& session, SessionServiceStateId sessionState) {
			if (sessionState == SessionServiceStateId::Established ||
				sessionState == SessionServiceStateId::Disconnected) {
				sessionState_ = sessionState;
				cond_.sendEvent();
			}
		};

	// create session
	SessionService::SPtr sessionService;
	sessionService = serviceSetManager.sessionService(sessionServiceConfig);
	BOOST_REQUIRE(sessionService.get() != nullptr);

	// connect secure channel
	cond_.condition(1,0);
	sessionService->asyncConnect();
	BOOST_REQUIRE(cond_.waitForCondition(1000) == true);
	BOOST_REQUIRE(sessionState_ == SessionServiceStateId::Established);

	// create subscription service
	SubscriptionService::SPtr subscriptionService;
	SubscriptionServiceConfig subscriptionServiceConfig;
	subscriptionServiceConfig.subscriptionServiceIf_ = &subscriptionServiceIfTestHandler;
	subscriptionService = serviceSetManager.subscriptionService(sessionService, subscriptionServiceConfig);

	// create subscription
	ServiceTransactionCreateSubscription::SPtr subCreateTrx = constructSPtr<ServiceTransactionCreateSubscription>();
	CreateSubscriptionRequest::SPtr subCreateReq = subCreateTrx->request();
	CreateSubscriptionResponse::SPtr subCreateRes = subCreateTrx->response();
	subscriptionServiceIfTestHandler.subscriptionServiceCreateSubscriptionResponse_.condition(1,0);
	subscriptionService->asyncSend(subCreateTrx);
	BOOST_REQUIRE(subscriptionServiceIfTestHandler.subscriptionServiceCreateSubscriptionResponse_.waitForCondition(1000) == true);
	BOOST_REQUIRE(subCreateTrx->responseHeader()->serviceResult() == Success);
	uint32_t subscriptionId = subCreateRes->subscriptionId();

	// delete subscription
	ServiceTransactionDeleteSubscriptions::SPtr subDeleteTrx = constructSPtr<ServiceTransactionDeleteSubscriptions>();
	DeleteSubscriptionsRequest::SPtr subDeleteReq = subDeleteTrx->request();
	DeleteSubscriptionsResponse::SPtr subDeleteRes = subDeleteTrx->response();
	subDeleteReq->subscriptionIds()->resize(1);
	subDeleteReq->subscriptionIds()->set(0, subscriptionId);
	subscriptionServiceIfTestHandler.subscriptionServiceDeleteSubscriptionsResponse_.condition(1,0);
	subscriptionService->asyncSend(subDeleteTrx);
	BOOST_REQUIRE(subscriptionServiceIfTestHandler.subscriptionServiceDeleteSubscriptionsResponse_.waitForCondition(1000) == true);
	BOOST_REQUIRE(subDeleteTrx->responseHeader()->serviceResult() == Success);
	BOOST_REQUIRE(subDeleteRes->results()->size() == 1);
	OpcUaStatusCode statusCode;
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
