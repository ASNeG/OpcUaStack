#include "unittest.h"
#include "OpcUaStackClient/CryptoManagerTest.h"
#include "OpcUaStackClient/ValueBasedInterface/VBIClient.h"
#include "OpcUaStackClient/ValueBasedInterface/VBIClientHandlerTest.h"

using namespace OpcUaStackClient;

#ifdef REAL_SERVER

BOOST_AUTO_TEST_SUITE(VBISyncReal_Subscription_)

struct GValueFixture {
	GValueFixture(void)
    : cond_()
	, subscriptionState_()
	, subscriptionId_(0)
    {}
    ~GValueFixture(void)
    {}

    Condition cond_;
    SubscriptionState subscriptionState_;
    uint32_t subscriptionId_;
};

BOOST_AUTO_TEST_CASE(VBISyncReal_Subscription_)
{
	std::cout << "VBISyncReal_Subscription_t" << std::endl;
}

BOOST_AUTO_TEST_CASE(VBISyncReal_Subscription_create_delete)
{
	OpcUaStatusCode statusCode;
	VBIClient client;

	//
	// init certificate and crypto manager
	//
	CryptoManager::SPtr cryptoManager = CryptoManagerTest::getInstance();
	BOOST_REQUIRE(cryptoManager.get() != nullptr);

	// connect session
	ConnectContext connectContext;
	connectContext.endpointUrl_ = REAL_SERVER_URI;
	connectContext.sessionName_ = REAL_SESSION_NAME;
	connectContext.cryptoManager_ = cryptoManager;
	connectContext.secureChannelLog_ = true;
	BOOST_REQUIRE(client.syncConnect(connectContext) == Success);

	// create subscription
	uint32_t subscriptionId;
	BOOST_REQUIRE(client.syncCreateSubscription(subscriptionId) == Success);

	// delete subscription
	BOOST_REQUIRE(client.syncDeleteSubscription(subscriptionId) == Success);

	// disconnect session
	BOOST_REQUIRE(client.syncDisconnect() == Success);
}

BOOST_FIXTURE_TEST_CASE(VBISyncReal_Subscription_create_delete_callback, GValueFixture)
{
	VBIClientHandlerTest vbiClientHandlerTest;
	OpcUaStatusCode statusCode;
	VBIClient client;

	//
	// init certificate and crypto manager
	//
	CryptoManager::SPtr cryptoManager = CryptoManagerTest::getInstance();
	BOOST_REQUIRE(cryptoManager.get() != nullptr);

	// connect session
	ConnectContext connectContext;
	connectContext.endpointUrl_ = REAL_SERVER_URI;
	connectContext.sessionName_ = REAL_SESSION_NAME;
	connectContext.cryptoManager_ = cryptoManager;
	connectContext.secureChannelLog_ = true;
	BOOST_REQUIRE(client.syncConnect(connectContext) == Success);

	// set subscription change handler
	client.setSubscriptionChangeHandler(
		[this](SubscriptionState subscriptionState, uint32_t subscriptionId) {
			subscriptionState_ = subscriptionState;
			subscriptionId_ = subscriptionId;
			cond_.sendEvent();
		}
	);

	// create subscription
	uint32_t subscriptionId;
	cond_.initEvent();
	BOOST_REQUIRE(client.syncCreateSubscription(subscriptionId) == Success);
	BOOST_REQUIRE(cond_.waitForEvent(1000) == true);
	BOOST_REQUIRE(subscriptionState_ == SS_Open);

	// delete subscription
	cond_.initEvent();
	BOOST_REQUIRE(client.syncDeleteSubscription(subscriptionId) == Success);
	BOOST_REQUIRE(cond_.waitForEvent(1000) == true);
	BOOST_REQUIRE(subscriptionState_ == SS_Close);

	// disconnect session
	BOOST_REQUIRE(client.syncDisconnect() == Success);
}


BOOST_AUTO_TEST_SUITE_END()

#endif
