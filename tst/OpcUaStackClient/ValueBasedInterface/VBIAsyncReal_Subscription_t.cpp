#include "unittest.h"
#include "OpcUaStackClient/CryptoManagerTest.h"
#include "OpcUaStackClient/ValueBasedInterface/VBIClient.h"
#include "OpcUaStackClient/ValueBasedInterface/VBIClientHandlerTest.h"

using namespace OpcUaStackClient;

#ifdef REAL_SERVER

BOOST_AUTO_TEST_SUITE(VBIAsyncReal_Subscription_)

BOOST_AUTO_TEST_CASE(VBIAsyncReal_Subscription_)
{
	std::cout << "VBIAsyncReal_Subscription_t" << std::endl;
}

BOOST_AUTO_TEST_CASE(VBIAsyncReal_Subscription_create_delete)
{
	VBIClientHandlerTest vbiClientHandlerTest;
	VBIClient client;


	//
	// init certificate and crypto manager
	//
	CryptoManager::SPtr cryptoManager = CryptoManagerTest::getInstance();
	BOOST_REQUIRE(cryptoManager.get() != nullptr);

	// set session change callback
	client.setSessionChangeCallback(
		boost::bind(&VBIClientHandlerTest::sessionStateUpdate, &vbiClientHandlerTest, (uint32_t)1234, _1, _2)
	);

	// connect session
	ConnectContext connectContext;
	connectContext.endpointUrl_ = REAL_SERVER_URI;
	connectContext.sessionName_ = REAL_SESSION_NAME;
	connectContext.cryptoManager_ = cryptoManager;
	connectContext.secureChannelLog_ = true;
	vbiClientHandlerTest.sessionStateUpdate_.initEvent();
	client.asyncConnect(connectContext);
	BOOST_REQUIRE(vbiClientHandlerTest.sessionStateUpdate_.waitForEvent(1000) == true);
	BOOST_REQUIRE(vbiClientHandlerTest.sessionState_ == SessionState::Established);
	BOOST_REQUIRE(vbiClientHandlerTest.clientHandle_ == 1234);

	// create subscription
	vbiClientHandlerTest.createSubscriptionComplete_.initEvent();
	client.asyncCreateSubscription(
		boost::bind(&VBIClientHandlerTest::createSubscriptionComplete, &vbiClientHandlerTest, _1, _2)
	);
	BOOST_REQUIRE(vbiClientHandlerTest.createSubscriptionComplete_.waitForEvent(1000) == true);
	BOOST_REQUIRE(vbiClientHandlerTest.statusCode_ == Success);
	uint32_t subscriptionId = vbiClientHandlerTest.subscriptionId_;

	// delete subscription
	vbiClientHandlerTest.deleteSubscriptionComplete_.initEvent();
	client.asyncDeleteSubscription(
		subscriptionId,
		boost::bind(&VBIClientHandlerTest::deleteSubscriptionComplete, &vbiClientHandlerTest, _1, _2)
	);
	BOOST_REQUIRE(vbiClientHandlerTest.deleteSubscriptionComplete_.waitForEvent(1000) == true);
	BOOST_REQUIRE(vbiClientHandlerTest.statusCode_ == Success);
	BOOST_REQUIRE(vbiClientHandlerTest.subscriptionId_ == subscriptionId);

	// disconnect session
	vbiClientHandlerTest.sessionStateUpdate_.initEvent();
	client.asyncDisconnect();
	BOOST_REQUIRE(vbiClientHandlerTest.sessionStateUpdate_.waitForEvent(1000) == true);
	BOOST_REQUIRE(vbiClientHandlerTest.sessionState_ == SessionState::Disconnected);
	BOOST_REQUIRE(vbiClientHandlerTest.clientHandle_ == 1234);
}

BOOST_AUTO_TEST_CASE(VBIAsyncReal_Subscription_create_delete_callback)
{
	VBIClientHandlerTest vbiClientHandlerTest;
	VBIClient client;

	//
	// init certificate and crypto manager
	//
	CryptoManager::SPtr cryptoManager = CryptoManagerTest::getInstance();
	BOOST_REQUIRE(cryptoManager.get() != nullptr);

	// set session change callback
	client.setSessionChangeCallback(
		boost::bind(&VBIClientHandlerTest::sessionStateUpdate, &vbiClientHandlerTest, (uint32_t)1234, _1, _2)
	);

	// connect session
	ConnectContext connectContext;
	connectContext.endpointUrl_ = REAL_SERVER_URI;
	connectContext.sessionName_ = REAL_SESSION_NAME;
	connectContext.cryptoManager_ = cryptoManager;
	connectContext.secureChannelLog_ = true;
	vbiClientHandlerTest.sessionStateUpdate_.initEvent();
	client.asyncConnect(connectContext);
	BOOST_REQUIRE(vbiClientHandlerTest.sessionStateUpdate_.waitForEvent(1000) == true);
	BOOST_REQUIRE(vbiClientHandlerTest.sessionState_ == SessionState::Established);
	BOOST_REQUIRE(vbiClientHandlerTest.clientHandle_ == 1234);

	// set subscription change callback
	client.setSubscriptionChangeCallback(
		boost::bind(&VBIClientHandlerTest::subscriptionChangeCallback, &vbiClientHandlerTest, _1, _2)
	);

	// create subscription
	vbiClientHandlerTest.subscriptionChangeCallback_.initEvent();
	vbiClientHandlerTest.createSubscriptionComplete_.initEvent();
	client.asyncCreateSubscription(
		boost::bind(&VBIClientHandlerTest::createSubscriptionComplete, &vbiClientHandlerTest, _1, _2)
	);
	BOOST_REQUIRE(vbiClientHandlerTest.subscriptionChangeCallback_.waitForEvent(1000) == true);
	BOOST_REQUIRE(vbiClientHandlerTest.subscriptionState_ == SS_Open);
	BOOST_REQUIRE(vbiClientHandlerTest.createSubscriptionComplete_.waitForEvent(1000) == true);
	BOOST_REQUIRE(vbiClientHandlerTest.statusCode_ == Success);
	uint32_t subscriptionId = vbiClientHandlerTest.subscriptionId_;

	// delete subscription
	vbiClientHandlerTest.subscriptionChangeCallback_.initEvent();
	vbiClientHandlerTest.deleteSubscriptionComplete_.initEvent();
	client.asyncDeleteSubscription(
		subscriptionId,
		boost::bind(&VBIClientHandlerTest::deleteSubscriptionComplete, &vbiClientHandlerTest, _1, _2)
	);
	BOOST_REQUIRE(vbiClientHandlerTest.subscriptionChangeCallback_.waitForEvent(1000) == true);
	BOOST_REQUIRE(vbiClientHandlerTest.subscriptionState_ == SS_Close);
	BOOST_REQUIRE(vbiClientHandlerTest.deleteSubscriptionComplete_.waitForEvent(1000) == true);
	BOOST_REQUIRE(vbiClientHandlerTest.statusCode_ == Success);
	BOOST_REQUIRE(vbiClientHandlerTest.subscriptionId_ == subscriptionId);

	// disconnect session
	vbiClientHandlerTest.sessionStateUpdate_.initEvent();
	client.asyncDisconnect();
	BOOST_REQUIRE(vbiClientHandlerTest.sessionStateUpdate_.waitForEvent(1000) == true);
	BOOST_REQUIRE(vbiClientHandlerTest.sessionState_ == SessionState::Disconnected);
	BOOST_REQUIRE(vbiClientHandlerTest.clientHandle_ == 1234);
}

BOOST_AUTO_TEST_SUITE_END()

#endif
