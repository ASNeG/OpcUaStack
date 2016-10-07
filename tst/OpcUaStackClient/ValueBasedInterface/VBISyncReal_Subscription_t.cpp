#include "unittest.h"
#include "OpcUaStackClient/ValueBasedInterface/VBIClient.h"
#include "OpcUaStackClient/ValueBasedInterface/VBIClientHandlerTest.h"

using namespace OpcUaStackClient;

#ifdef REAL_SERVER

BOOST_AUTO_TEST_SUITE(VBISyncReal_Subscription_)

BOOST_AUTO_TEST_CASE(VBISyncReal_Subscription_)
{
	std::cout << "VBISyncReal_Subscription_t" << std::endl;
}

BOOST_AUTO_TEST_CASE(VBISyncReal_Subscription_create_delete)
{
	OpcUaStatusCode statusCode;
	VBIClient client;

	// connect session
	ConnectContext connectContext;
	connectContext.endpointUrl_ = REAL_SERVER_URI;
	connectContext.sessionName_ = REAL_SESSION_NAME;
	BOOST_REQUIRE(client.syncConnect(connectContext) == Success);

	// create subscription
	uint32_t subscriptionId;
	BOOST_REQUIRE(client.syncCreateSubscription(subscriptionId) == Success);

	// delete subscription
	BOOST_REQUIRE(client.syncDeleteSubscription(subscriptionId) == Success);

	// disconnect session
	BOOST_REQUIRE(client.syncDisconnect() == Success);
}

BOOST_AUTO_TEST_CASE(VBISyncReal_Subscription_create_delete_callback)
{
	VBIClientHandlerTest vbiClientHandlerTest;
	OpcUaStatusCode statusCode;
	VBIClient client;

	// connect session
	ConnectContext connectContext;
	connectContext.endpointUrl_ = REAL_SERVER_URI;
	connectContext.sessionName_ = REAL_SESSION_NAME;
	BOOST_REQUIRE(client.syncConnect(connectContext) == Success);

	// set subscription change callback
	client.setSubscriptionChangeCallback(
		boost::bind(&VBIClientHandlerTest::subscriptionChangeCallback, &vbiClientHandlerTest, _1, _2)
	);

	// create subscription
	uint32_t subscriptionId;
	vbiClientHandlerTest.subscriptionChangeCallback_.initEvent();
	BOOST_REQUIRE(client.syncCreateSubscription(subscriptionId) == Success);
	BOOST_REQUIRE(vbiClientHandlerTest.subscriptionChangeCallback_.waitForEvent(1000) == true);
	BOOST_REQUIRE(vbiClientHandlerTest.subscriptionState_ == SS_Open);

	// delete subscription
	vbiClientHandlerTest.subscriptionChangeCallback_.initEvent();
	BOOST_REQUIRE(client.syncDeleteSubscription(subscriptionId) == Success);
	BOOST_REQUIRE(vbiClientHandlerTest.subscriptionChangeCallback_.waitForEvent(1000) == true);
	BOOST_REQUIRE(vbiClientHandlerTest.subscriptionState_ == SS_Close);

	// disconnect session
	BOOST_REQUIRE(client.syncDisconnect() == Success);
}


BOOST_AUTO_TEST_SUITE_END()

#endif
