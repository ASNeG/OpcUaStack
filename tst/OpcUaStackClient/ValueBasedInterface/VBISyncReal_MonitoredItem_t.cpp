#include "unittest.h"
#include "OpcUaStackClient/CryptoManagerTest.h"
#include "OpcUaStackClient/ValueBasedInterface/VBIClient.h"

using namespace OpcUaStackClient;

#ifdef REAL_SERVER

BOOST_AUTO_TEST_SUITE(VBISyncReal_MonitoredItem_)

struct GValueFixture {
	GValueFixture(void)
    : cond_()
	, cond1_()
	, sessionState_(SessionServiceStateId::None)
	, statusCode_(Success)
	, subscriptionId_(0)
	, clientHandle_(0)
	, dataValue_()
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
};

BOOST_AUTO_TEST_CASE(VBISyncReal_MonitoredItem_)
{
	std::cout << "VBISyncReal_MonitoredItem_t" << std::endl;
}

BOOST_AUTO_TEST_CASE(VBISyncReal_MonitoredItem_create_delete)
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

	// create monitored item
	uint32_t clientHandle = 2345;
	OpcUaNodeId nodeId;
	nodeId.set((OpcUaUInt32)2258);
	uint32_t monitoredItemId;
	BOOST_REQUIRE(client.syncCreateMonitoredItem(nodeId, subscriptionId, clientHandle, monitoredItemId) == Success);

	// delete monitored item
	BOOST_REQUIRE(client.syncDeleteMonitoredItem(subscriptionId, monitoredItemId) == Success);

	// delete subscription
	BOOST_REQUIRE(client.syncDeleteSubscription(subscriptionId) == Success);

	// disconnect session
	BOOST_REQUIRE(client.syncDisconnect() == Success);
}

BOOST_FIXTURE_TEST_CASE(VBISyncReal_MonitoredItem_create_delete_callback, GValueFixture)
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
	//connectContext.secureChannelLog_ = true;
	BOOST_REQUIRE(client.syncConnect(connectContext) == Success);

	// set data change handler
	client.setDataChangeHandler(
		[this](OpcUaUInt32 clientHandle, OpcUaDataValue& dataValue) {
			clientHandle_ = clientHandle;
			dataValue_ = dataValue;
			cond1_.sendEvent();
		}
	);

	// create subscription
	uint32_t subscriptionId;
	BOOST_REQUIRE(client.syncCreateSubscription(subscriptionId) == Success);

	// create monitored item
	uint32_t clientHandle = 3344;
	OpcUaNodeId nodeId;
	nodeId.set((OpcUaUInt32)2258);
	uint32_t monitoredItemId;
	cond1_.initEvent();
	BOOST_REQUIRE(client.syncCreateMonitoredItem(nodeId, subscriptionId, clientHandle, monitoredItemId) == Success);
	BOOST_REQUIRE(cond1_.waitForEvent(1000) == true);
	BOOST_REQUIRE(clientHandle_ == clientHandle);

	// delete monitored item
	BOOST_REQUIRE(client.syncDeleteMonitoredItem(subscriptionId, monitoredItemId) == Success);

	// delete subscription
	BOOST_REQUIRE(client.syncDeleteSubscription(subscriptionId) == Success);

	// disconnect session
	BOOST_REQUIRE(client.syncDisconnect() == Success);
}

BOOST_FIXTURE_TEST_CASE(VBISyncReal_MonitoredItem_data_change, GValueFixture)
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

	// set data change callback
	client.setDataChangeHandler(
		[this](OpcUaUInt32 clientHandle, OpcUaDataValue& dataValue) {
			clientHandle_ = clientHandle;
			dataValue_ = dataValue;
			cond1_.sendEvent();
		}
	);

	// create subscription
	uint32_t subscriptionId;
	BOOST_REQUIRE(client.syncCreateSubscription(subscriptionId) == Success);

	// create monitored item
	uint32_t clientHandle = 3344;
	OpcUaNodeId nodeId;
	nodeId.set(218,3);
	uint32_t monitoredItemId;
	cond1_.initEvent();
	BOOST_REQUIRE(client.syncCreateMonitoredItem(nodeId, subscriptionId, clientHandle, monitoredItemId) == Success);
	BOOST_REQUIRE(cond1_.waitForEvent(1000) == true);
	BOOST_REQUIRE(clientHandle_ == clientHandle);

	// data change
	for (uint32_t idx=0; idx<2; idx++) {
		cond1_.initEvent();
		BOOST_REQUIRE(cond1_.waitForEvent(5000) == true);
	}

	// delete monitored item
	BOOST_REQUIRE(client.syncDeleteMonitoredItem(subscriptionId, monitoredItemId) == Success);

	// delete subscription
	BOOST_REQUIRE(client.syncDeleteSubscription(subscriptionId) == Success);

	// disconnect session
	BOOST_REQUIRE(client.syncDisconnect() == Success);
}

BOOST_AUTO_TEST_SUITE_END()

#endif
