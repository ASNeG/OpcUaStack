#include "unittest.h"
#include "OpcUaStackClient/ValueBasedInterface/VBIClient.h"
#include "OpcUaStackClient/ValueBasedInterface/VBIClientHandlerTest.h"

using namespace OpcUaStackClient;

#ifdef REAL_SERVER

BOOST_AUTO_TEST_SUITE(VBISyncReal_MonitoredItem_)

BOOST_AUTO_TEST_CASE(VBISyncReal_MonitoredItem_)
{
	std::cout << "VBISyncReal_MonitoredItem_t" << std::endl;
}

BOOST_AUTO_TEST_CASE(VBISyncReal_MonitoredItem_session_connect_disconnect)
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

	// create monitored item
	OpcUaNodeId nodeId;
	nodeId.set((OpcUaUInt32)2258);
	uint32_t monitoredItemId;
	BOOST_REQUIRE(client.syncCreateMonitoredItem(nodeId, subscriptionId, monitoredItemId) == Success);

	// delete monitored item
	BOOST_REQUIRE(client.syncDeleteMonitoredItem(subscriptionId, monitoredItemId) == Success);

	// delete subscription
	BOOST_REQUIRE(client.syncDeleteSubscription(subscriptionId) == Success);

	// disconnect session
	BOOST_REQUIRE(client.syncDisconnect() == Success);
}

BOOST_AUTO_TEST_SUITE_END()

#endif
