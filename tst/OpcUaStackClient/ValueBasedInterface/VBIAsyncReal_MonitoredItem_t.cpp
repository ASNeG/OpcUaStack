#include "unittest.h"
#include "OpcUaStackCore/Base/Condition.h"
#include "OpcUaStackClient/CryptoManagerTest.h"
#include "OpcUaStackClient/ValueBasedInterface/VBIClient.h"
#include "OpcUaStackClient/ValueBasedInterface/VBIClientHandlerTest.h"

using namespace OpcUaStackCore;
using namespace OpcUaStackClient;

#ifdef REAL_SERVER

BOOST_AUTO_TEST_SUITE(VBIAsyncReal_MonitoredItem_)

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

BOOST_AUTO_TEST_CASE(VBIAsyncReal_MonitoredItem_)
{
	std::cout << "VBIAsyncReal_MonitoredItem_t" << std::endl;
}

BOOST_FIXTURE_TEST_CASE(VBIAsyncReal_MonitoredItem_create_delete, GValueFixture)
{
	VBIClientHandlerTest vbiClientHandlerTest;
	VBIClient client;


	//
	// init certificate and crypto manager
	//
	CryptoManager::SPtr cryptoManager = CryptoManagerTest::getInstance();
	BOOST_REQUIRE(cryptoManager.get() != nullptr);

	// set session change handler
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
	vbiClientHandlerTest.createSubscriptionComplete_.initEvent();
	client.asyncCreateSubscription(
		boost::bind(&VBIClientHandlerTest::createSubscriptionComplete, &vbiClientHandlerTest, _1, _2)
	);
	BOOST_REQUIRE(vbiClientHandlerTest.createSubscriptionComplete_.waitForEvent(1000) == true);
	BOOST_REQUIRE(vbiClientHandlerTest.statusCode_ == Success);
	uint32_t subscriptionId = vbiClientHandlerTest.subscriptionId_;

	// create monitored item
	uint32_t clientHandle = 334455;
	OpcUaNodeId nodeId;
	nodeId.set((OpcUaUInt32)2258);
	vbiClientHandlerTest.createMonitoredItemComplete_.initEvent();
	client.asyncCreateMonitoredItem(
		nodeId,
		subscriptionId,
		clientHandle,
		boost::bind(&VBIClientHandlerTest::createMonitoredItemComplete, &vbiClientHandlerTest, _1, _2, _3)
	);
	BOOST_REQUIRE(vbiClientHandlerTest.createMonitoredItemComplete_.waitForEvent(1000) == true);
	BOOST_REQUIRE(vbiClientHandlerTest.statusCode_ == Success);
	uint32_t monitoredItemId = vbiClientHandlerTest.monitoredItemId_;

	// delete monitored item
	vbiClientHandlerTest.deleteMonitoredItemComplete_.initEvent();
	client.asyncDeleteMonitoredItem(
		subscriptionId,
		monitoredItemId,
		boost::bind(&VBIClientHandlerTest::deleteMonitoredItemComplete, &vbiClientHandlerTest, _1, _2, _3)
	);
	BOOST_REQUIRE(vbiClientHandlerTest.deleteMonitoredItemComplete_.waitForEvent(1000) == true);
	BOOST_REQUIRE(vbiClientHandlerTest.statusCode_ == Success);
	BOOST_REQUIRE(monitoredItemId == vbiClientHandlerTest.monitoredItemId_);
	BOOST_REQUIRE(subscriptionId == vbiClientHandlerTest.subscriptionId_);

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
	cond_.initEvent();
	client.asyncDisconnect();
	BOOST_REQUIRE(cond_.waitForEvent(1000) == true);
	BOOST_REQUIRE(sessionState_ == SessionServiceStateId::Disconnected);
}

BOOST_FIXTURE_TEST_CASE(VBIAsyncReal_MonitoredItem_create_delete_callback, GValueFixture)
{
	VBIClientHandlerTest vbiClientHandlerTest;
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

	// set data change callback
	client.setDataChangeCallback(
		boost::bind(&VBIClientHandlerTest::dataChangeCallback, &vbiClientHandlerTest, _1, _2)
	);

	// create subscription
	vbiClientHandlerTest.createSubscriptionComplete_.initEvent();
	client.asyncCreateSubscription(
		boost::bind(&VBIClientHandlerTest::createSubscriptionComplete, &vbiClientHandlerTest, _1, _2)
	);
	BOOST_REQUIRE(vbiClientHandlerTest.createSubscriptionComplete_.waitForEvent(1000) == true);
	BOOST_REQUIRE(vbiClientHandlerTest.statusCode_ == Success);
	uint32_t subscriptionId = vbiClientHandlerTest.subscriptionId_;

	// create monitored item
	uint32_t clientHandle = 332201;
	OpcUaNodeId nodeId;
	nodeId.set((OpcUaUInt32)2258);
	vbiClientHandlerTest.dataChangeCallback_.initEvent();
	vbiClientHandlerTest.createMonitoredItemComplete_.initEvent();
	client.asyncCreateMonitoredItem(
		nodeId,
		subscriptionId,
		clientHandle,
		boost::bind(&VBIClientHandlerTest::createMonitoredItemComplete, &vbiClientHandlerTest, _1, _2, _3)
	);
	BOOST_REQUIRE(vbiClientHandlerTest.createMonitoredItemComplete_.waitForEvent(1000) == true);
	BOOST_REQUIRE(vbiClientHandlerTest.statusCode_ == Success);
	uint32_t monitoredItemId = vbiClientHandlerTest.monitoredItemId_;
	BOOST_REQUIRE(vbiClientHandlerTest.dataChangeCallback_.waitForEvent(1000) == true);
	BOOST_REQUIRE(vbiClientHandlerTest.clientHandle_ == clientHandle);

#if 0
	while (true) {
		vbiClientHandlerTest.dataChangeCallback_.initEvent();
		vbiClientHandlerTest.dataChangeCallback_.waitForEvent(1000);
	}
#endif

	// delete monitored item
	vbiClientHandlerTest.deleteMonitoredItemComplete_.initEvent();
	client.asyncDeleteMonitoredItem(
		subscriptionId,
		monitoredItemId,
		boost::bind(&VBIClientHandlerTest::deleteMonitoredItemComplete, &vbiClientHandlerTest, _1, _2, _3)
	);
	BOOST_REQUIRE(vbiClientHandlerTest.deleteMonitoredItemComplete_.waitForEvent(1000) == true);
	BOOST_REQUIRE(vbiClientHandlerTest.statusCode_ == Success);
	BOOST_REQUIRE(monitoredItemId == vbiClientHandlerTest.monitoredItemId_);
	BOOST_REQUIRE(subscriptionId == vbiClientHandlerTest.subscriptionId_);

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
	cond_.initEvent();
	client.asyncDisconnect();
	BOOST_REQUIRE(cond_.waitForEvent(1000) == true);
	BOOST_REQUIRE(sessionState_ == SessionServiceStateId::Disconnected);
}

BOOST_FIXTURE_TEST_CASE(VBIAsyncReal_MonitoredItem_data_change, GValueFixture)
{
	VBIClientHandlerTest vbiClientHandlerTest;
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

	// set data change callback
	client.setDataChangeCallback(
		boost::bind(&VBIClientHandlerTest::dataChangeCallback, &vbiClientHandlerTest, _1, _2)
	);

	// create subscription
	vbiClientHandlerTest.createSubscriptionComplete_.initEvent();
	client.asyncCreateSubscription(
		boost::bind(&VBIClientHandlerTest::createSubscriptionComplete, &vbiClientHandlerTest, _1, _2)
	);
	BOOST_REQUIRE(vbiClientHandlerTest.createSubscriptionComplete_.waitForEvent(1000) == true);
	BOOST_REQUIRE(vbiClientHandlerTest.statusCode_ == Success);
	uint32_t subscriptionId = vbiClientHandlerTest.subscriptionId_;

	// create monitored item
	uint32_t clientHandle = 332201;
	OpcUaNodeId nodeId;
	nodeId.set((OpcUaUInt32)2258);
	vbiClientHandlerTest.dataChangeCallback_.initEvent();
	vbiClientHandlerTest.createMonitoredItemComplete_.initEvent();
	client.asyncCreateMonitoredItem(
		nodeId,
		subscriptionId,
		clientHandle,
		boost::bind(&VBIClientHandlerTest::createMonitoredItemComplete, &vbiClientHandlerTest, _1, _2, _3)
	);
	BOOST_REQUIRE(vbiClientHandlerTest.createMonitoredItemComplete_.waitForEvent(1000) == true);
	BOOST_REQUIRE(vbiClientHandlerTest.statusCode_ == Success);
	uint32_t monitoredItemId = vbiClientHandlerTest.monitoredItemId_;
	BOOST_REQUIRE(vbiClientHandlerTest.dataChangeCallback_.waitForEvent(1000) == true);
	BOOST_REQUIRE(vbiClientHandlerTest.clientHandle_ == clientHandle);

	for (uint32_t idx=0; idx<2; idx++) {
		vbiClientHandlerTest.dataChangeCallback_.initEvent();
		vbiClientHandlerTest.dataChangeCallback_.waitForEvent(3000);
	}

	// delete monitored item
	vbiClientHandlerTest.deleteMonitoredItemComplete_.initEvent();
	client.asyncDeleteMonitoredItem(
		subscriptionId,
		monitoredItemId,
		boost::bind(&VBIClientHandlerTest::deleteMonitoredItemComplete, &vbiClientHandlerTest, _1, _2, _3)
	);
	BOOST_REQUIRE(vbiClientHandlerTest.deleteMonitoredItemComplete_.waitForEvent(1000) == true);
	BOOST_REQUIRE(vbiClientHandlerTest.statusCode_ == Success);
	BOOST_REQUIRE(monitoredItemId == vbiClientHandlerTest.monitoredItemId_);
	BOOST_REQUIRE(subscriptionId == vbiClientHandlerTest.subscriptionId_);

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
	cond_.initEvent();
	client.asyncDisconnect();
	BOOST_REQUIRE(cond_.waitForEvent(1000) == true);
	BOOST_REQUIRE(sessionState_ == SessionServiceStateId::Disconnected);
}

BOOST_AUTO_TEST_SUITE_END()

#endif
