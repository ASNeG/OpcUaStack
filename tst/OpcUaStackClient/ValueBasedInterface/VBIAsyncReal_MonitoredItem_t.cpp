#include "unittest.h"
#include "OpcUaStackCore/Base/Condition.h"
#include "OpcUaStackClient/CryptoManagerTest.h"
#include "OpcUaStackClient/ValueBasedInterface/VBIClient.h"

using namespace OpcUaStackCore;
using namespace OpcUaStackClient;

#ifdef REAL_SERVER

BOOST_AUTO_TEST_SUITE(VBIAsyncReal_MonitoredItem_)

struct GValueFixture {
	GValueFixture(void)
    : cond_()
	, cond1_()
	, sessionState_(SessionServiceStateId::None)
	, statusCode_(Success)
	, subscriptionId_(0)
	, clientHandle_(0)
	, dataValue_()
	, monitoredItemId_(0)
    {}
    ~GValueFixture(void)
    {}

    Condition cond_;
    Condition cond1_;
    SessionServiceStateId sessionState_;
    OpcUaStatusCode statusCode_;
    uint32_t subscriptionId_;
    OpcUaUInt32 clientHandle_;
    OpcUaDataValue dataValue_;
    uint32_t monitoredItemId_;
};

BOOST_AUTO_TEST_CASE(VBIAsyncReal_MonitoredItem_)
{
	std::cout << "VBIAsyncReal_MonitoredItem_t" << std::endl;
}

BOOST_FIXTURE_TEST_CASE(VBIAsyncReal_MonitoredItem_create_delete, GValueFixture)
{
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

	// create monitored item
	uint32_t clientHandle = 334455;
	OpcUaNodeId nodeId;
	nodeId.set((OpcUaUInt32)2258);
	cond_.initEvent();
	client.asyncCreateMonitoredItem(
		nodeId,
		subscriptionId,
		clientHandle,
		[this](OpcUaStatusCode statusCode, OpcUaNodeId& nodeId, uint32_t monitoredItemId) {
			statusCode_ = statusCode;
			monitoredItemId_ = monitoredItemId;
			cond_.sendEvent();
		}
	);
	BOOST_REQUIRE(cond_.waitForEvent(1000) == true);
	BOOST_REQUIRE(statusCode_ == Success);
	uint32_t monitoredItemId = monitoredItemId_;

	// delete monitored item
	cond_.initEvent();
	client.asyncDeleteMonitoredItem(
		subscriptionId,
		monitoredItemId,
		[this](OpcUaStatusCode statusCode, uint32_t subscriptionId, uint32_t monitoredItemId) {
			statusCode_ = statusCode;
			subscriptionId_ = subscriptionId;
			monitoredItemId_ = monitoredItemId;
			cond_.sendEvent();
		}
	);
	BOOST_REQUIRE(cond_.waitForEvent(1000) == true);
	BOOST_REQUIRE(statusCode_ == Success);
	BOOST_REQUIRE(monitoredItemId == monitoredItemId_);
	BOOST_REQUIRE(subscriptionId == subscriptionId_);

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

BOOST_FIXTURE_TEST_CASE(VBIAsyncReal_MonitoredItem_create_delete_callback, GValueFixture)
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

	// set data change handler
	client.setDataChangeHandler(
		[this](OpcUaUInt32 clientHandle, OpcUaDataValue& dataValue) {
			clientHandle_ = clientHandle;
			dataValue_ = dataValue;
			cond1_.sendEvent();
		}
	);

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

	// create monitored item
	uint32_t clientHandle = 332201;
	OpcUaNodeId nodeId;
	nodeId.set((OpcUaUInt32)2258);
	cond1_.initEvent();
	cond_.initEvent();
	client.asyncCreateMonitoredItem(
		nodeId,
		subscriptionId,
		clientHandle,
		[this](OpcUaStatusCode statusCode, OpcUaNodeId& nodeId, uint32_t monitoredItemId) {
			statusCode_ = statusCode;
			monitoredItemId_ = monitoredItemId;
			cond_.sendEvent();
		}
	);
	BOOST_REQUIRE(cond_.waitForEvent(1000) == true);
	BOOST_REQUIRE(statusCode_ == Success);
	uint32_t monitoredItemId = monitoredItemId_;
	BOOST_REQUIRE(cond1_.waitForEvent(1000) == true);

#if 0
	while (true) {
		vbiClientHandlerTest.dataChangeCallback_.initEvent();
		vbiClientHandlerTest.dataChangeCallback_.waitForEvent(1000);
	}
#endif

	// delete monitored item
	cond_.initEvent();
	client.asyncDeleteMonitoredItem(
		subscriptionId,
		monitoredItemId,
		[this](OpcUaStatusCode statusCode, uint32_t subscriptionId, uint32_t monitoredItemId) {
			statusCode_ = statusCode;
			subscriptionId_ = subscriptionId;
			monitoredItemId_ = monitoredItemId;
			cond_.sendEvent();
		}
	);
	BOOST_REQUIRE(cond_.waitForEvent(1000) == true);
	BOOST_REQUIRE(statusCode_ == Success);
	BOOST_REQUIRE(monitoredItemId == monitoredItemId_);
	BOOST_REQUIRE(subscriptionId == subscriptionId_);

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

BOOST_FIXTURE_TEST_CASE(VBIAsyncReal_MonitoredItem_data_change, GValueFixture)
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

	// set data change callback
	client.setDataChangeHandler(
		[this](OpcUaUInt32 clientHandle, OpcUaDataValue& dataValue) {
			clientHandle_ = clientHandle;
			dataValue_ = dataValue;
			cond1_.sendEvent();
		}
	);

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

	// create monitored item
	uint32_t clientHandle = 332201;
	OpcUaNodeId nodeId;
	nodeId.set((OpcUaUInt32)2258);
	cond1_.initEvent();
	cond_.initEvent();
	client.asyncCreateMonitoredItem(
		nodeId,
		subscriptionId,
		clientHandle,
		[this](OpcUaStatusCode statusCode, OpcUaNodeId& nodeId, uint32_t monitoredItemId) {
			statusCode_ = statusCode;
			monitoredItemId_ = monitoredItemId;
			cond_.sendEvent();
		}
	);
	BOOST_REQUIRE(cond_.waitForEvent(1000) == true);
	BOOST_REQUIRE(statusCode_ == Success);
	uint32_t monitoredItemId = monitoredItemId_;
	BOOST_REQUIRE(cond1_.waitForEvent(1000) == true);

	for (uint32_t idx=0; idx<2; idx++) {
		cond1_.initEvent();
		cond1_.waitForEvent(3000);
	}

	// delete monitored item
	cond_.initEvent();
	client.asyncDeleteMonitoredItem(
		subscriptionId,
		monitoredItemId,
		[this](OpcUaStatusCode statusCode, uint32_t subscriptionId, uint32_t monitoredItemId) {
			statusCode_ = statusCode;
			subscriptionId_ = subscriptionId;
			monitoredItemId_ = monitoredItemId;
			cond_.sendEvent();
		}
	);
	BOOST_REQUIRE(cond_.waitForEvent(1000) == true);
	BOOST_REQUIRE(statusCode_ == Success);
	BOOST_REQUIRE(monitoredItemId == monitoredItemId_);
	BOOST_REQUIRE(subscriptionId == subscriptionId_);

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

BOOST_AUTO_TEST_SUITE_END()

#endif
