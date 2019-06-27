#include "unittest.h"
#include "OpcUaStackClient/CryptoManagerTest.h"
#include "OpcUaStackClient/ValueBasedInterface/VBIClient.h"

using namespace OpcUaStackClient;

#ifdef REAL_SERVER

BOOST_AUTO_TEST_SUITE(VBIAsyncReal_Subscription_)

struct GValueFixture {
	GValueFixture(void)
    : cond_()
	, cond1_()
	, sessionState_(SessionServiceStateId::None)
	, statusCode_(Success)
	, subscriptionState_()
	, subscriptionId_(0)
    {}
    ~GValueFixture(void)
    {}

    Condition cond_;
    Condition cond1_;
    SessionServiceStateId sessionState_;
    OpcUaStatusCode statusCode_;
    SubscriptionState subscriptionState_;
    uint32_t subscriptionId_;
};

BOOST_AUTO_TEST_CASE(VBIAsyncReal_Subscription_)
{
	std::cout << "VBIAsyncReal_Subscription_t" << std::endl;
}

BOOST_FIXTURE_TEST_CASE(VBIAsyncReal_Subscription_create_delete, GValueFixture)
{
	VBIClient client;


	//
	// init certificate and crypto manager
	//
	CryptoManager::SPtr cryptoManager = CryptoManagerTest::getInstance();
	BOOST_REQUIRE(cryptoManager.get() != nullptr);

	// set session change callback
	client.setSessionChangeHandler(
		[this] (SessionBase& session, SessionServiceStateId sessionState) {
			if (sessionState == SessionServiceStateId::Established ||
				sessionState == SessionServiceStateId::Disconnected) {
				sessionState_ = sessionState;
				cond_.sendEvent();
			}
		}
	);

	// connect session
	ConnectContext connectContext;
	connectContext.endpointUrl_ = REAL_SERVER_URI;
	connectContext.sessionName_ = REAL_SESSION_NAME;
	connectContext.cryptoManager_ = cryptoManager;
	connectContext.secureChannelLog_ = true;
	cond_.initEvent();
	client.asyncConnect(connectContext);
	BOOST_REQUIRE(cond_.waitForEvent(1000) == true);
	BOOST_REQUIRE(sessionState_ == SessionServiceStateId::Established);

	// create subscription
	cond_.initEvent();
	client.asyncCreateSubscription(
		[this](OpcUaStatusCode statusCode, uint32_t subscriptionId) {
			statusCode_ = statusCode;
			subscriptionId_ = subscriptionId;
			cond_.sendEvent();
		}
	);
	BOOST_REQUIRE(cond_.waitForEvent(1000) == true);
	BOOST_REQUIRE(statusCode_ == Success);
	uint32_t subscriptionId = subscriptionId_;

	// delete subscription
	cond_.initEvent();
	client.asyncDeleteSubscription(
		subscriptionId,
		[this](OpcUaStatusCode statusCode, uint32_t subscriptionId) {
			statusCode_ = statusCode;
			subscriptionId_ = subscriptionId;
			cond_.sendEvent();
		}
	);
	BOOST_REQUIRE(cond_.waitForEvent(1000) == true);
	BOOST_REQUIRE(statusCode_ == Success);
	BOOST_REQUIRE(subscriptionId_ == subscriptionId);

	// disconnect session
	cond_.initEvent();
	client.asyncDisconnect();
	BOOST_REQUIRE(cond_.waitForEvent(1000) == true);
	BOOST_REQUIRE(sessionState_ == SessionServiceStateId::Disconnected);
}

BOOST_FIXTURE_TEST_CASE(VBIAsyncReal_Subscription_create_delete_callback, GValueFixture)
{
	VBIClient client;

	//
	// init certificate and crypto manager
	//
	CryptoManager::SPtr cryptoManager = CryptoManagerTest::getInstance();
	BOOST_REQUIRE(cryptoManager.get() != nullptr);

	// set session change callback
	client.setSessionChangeHandler(
		[this] (SessionBase& session, SessionServiceStateId sessionState) {
			if (sessionState == SessionServiceStateId::Established ||
				sessionState == SessionServiceStateId::Disconnected) {
				sessionState_ = sessionState;
				cond_.sendEvent();
			}
		}
	);

	// connect session
	ConnectContext connectContext;
	connectContext.endpointUrl_ = REAL_SERVER_URI;
	connectContext.sessionName_ = REAL_SESSION_NAME;
	connectContext.cryptoManager_ = cryptoManager;
	connectContext.secureChannelLog_ = true;
	cond_.initEvent();
	client.asyncConnect(connectContext);
	BOOST_REQUIRE(cond_.waitForEvent(1000) == true);
	BOOST_REQUIRE(sessionState_ == SessionServiceStateId::Established);

	// set subscription change handler
	client.setSubscriptionChangeHandler(
		[this](SubscriptionState subscriptionState, uint32_t subscriptionId) {
			subscriptionState_ = subscriptionState;
			subscriptionId_ = subscriptionId;
			cond1_.sendEvent();
		}
	);

	// create subscription
	cond1_.initEvent();
	cond_.initEvent();
	client.asyncCreateSubscription(
		[this](OpcUaStatusCode statusCode, uint32_t subscriptionId) {
			statusCode_ = statusCode;
			subscriptionId_ = subscriptionId;
			cond_.sendEvent();
		}
	);
	BOOST_REQUIRE(cond1_.waitForEvent(1000) == true);
	BOOST_REQUIRE(subscriptionState_ == SS_Open);
	BOOST_REQUIRE(cond_.waitForEvent(1000) == true);
	BOOST_REQUIRE(statusCode_ == Success);
	uint32_t subscriptionId = subscriptionId_;

	// delete subscription
	cond1_.initEvent();
	cond_.initEvent();
	client.asyncDeleteSubscription(
		subscriptionId,
		[this](OpcUaStatusCode statusCode, uint32_t subscriptionId) {
			statusCode_ = statusCode;
			subscriptionId_ = subscriptionId;
			cond_.sendEvent();
		}
	);
	BOOST_REQUIRE(cond1_.waitForEvent(1000) == true);
	BOOST_REQUIRE(subscriptionState_ == SS_Close);
	BOOST_REQUIRE(cond_.waitForEvent(1000) == true);
	BOOST_REQUIRE(statusCode_ == Success);
	BOOST_REQUIRE(subscriptionId_ == subscriptionId);

	// disconnect session
	cond_.initEvent();
	client.asyncDisconnect();
	BOOST_REQUIRE(cond_.waitForEvent(1000) == true);
	BOOST_REQUIRE(sessionState_ == SessionServiceStateId::Disconnected);
}

BOOST_AUTO_TEST_SUITE_END()

#endif
