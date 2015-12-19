#include "unittest.h"
#include "OpcUaStackCore/Core/Core.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaIdentifier.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaExtensionObject.h"
#include "OpcUaStackCore/StandardDataTypes/SubscriptionDiagnosticsDataType.h"

using namespace OpcUaStackCore;

BOOST_AUTO_TEST_SUITE(SubscriptionDiagnosticsDataType_)

BOOST_AUTO_TEST_CASE(SubscriptionDiagnosticsDataType_)
{
	std::cout << "SubscriptionDiagnosticsDataType_t" << std::endl;
}

BOOST_AUTO_TEST_CASE(SubscriptionDiagnosticsDataType_encode_decode)
{
	SubscriptionDiagnosticsDataType value1;
	SubscriptionDiagnosticsDataType value2;

	OpcUaNodeId sessionId;
	sessionId.nodeId((OpcUaInt32)11);

	value1.sessionId(sessionId);
	value1.subscriptionId(1);
	value1.priority((OpcUaByte)2);
	value1.publishingInterval(3);
	value1.maxKeepAliveCount(4);
	value1.maxLifetimeCount(5);
	value1.maxNotificationsPerPublish(6);
	value1.publishingEnabled(true);
	value1.modifiyCount(7);
	value1.enableCount(8);
	value1.disableCount(9);
	value1.republishRequestCount(10);
	value1.republishMessageRequestCount(11);
	value1.republishMessageCount(12);
	value1.transferRequestCount(13);
	value1.transferredToAltClientCount(14);
	value1.transferredToSameClientCount(15);
	value1.publishRequestCount(16);
	value1.dataChangeNotificationsCount(17);
	value1.eventNotificationsCount(18);
	value1.notificationsCount(19);
	value1.latePublishRequestCount(20);
	value1.currentKeepAliveCount(21);
	value1.currentLifetimeCount(22);
	value1.unacknowledgedMessageCount(23);
	value1.discardedMessageCount(24);
	value1.monitoredItemCount(25);
	value1.disabledMonitoredItemCount(26);
	value1.monitoringQueueOverflowCount(27);
	value1.nextSequenceNumber(28);
	value1.eventQueueOverflowCount(29);

	std::stringstream ss;
	value1.opcUaBinaryEncode(ss);
	value2.opcUaBinaryDecode(ss);

	BOOST_REQUIRE(value2.sessionId() == sessionId);
	BOOST_REQUIRE(value2.subscriptionId() == 1);
	BOOST_REQUIRE(value2.priority() == (OpcUaByte)2);
	BOOST_REQUIRE(value2.publishingInterval() == 3);
	BOOST_REQUIRE(value2.maxKeepAliveCount() == 4);
	BOOST_REQUIRE(value2.maxLifetimeCount() == 5);
	BOOST_REQUIRE(value2.maxNotificationsPerPublish() == 6);
	BOOST_REQUIRE(value2.publishingEnabled() == true);
	BOOST_REQUIRE(value2.modifiyCount() == 7);
	BOOST_REQUIRE(value2.enableCount() == 8);
	BOOST_REQUIRE(value2.disableCount() == 9);
	BOOST_REQUIRE(value2.republishRequestCount() == 10);
	BOOST_REQUIRE(value2.republishMessageRequestCount() == 11);
	BOOST_REQUIRE(value2.republishMessageCount() == 12);
	BOOST_REQUIRE(value2.transferRequestCount() == 13);
	BOOST_REQUIRE(value2.transferredToAltClientCount() == 14);
	BOOST_REQUIRE(value2.transferredToSameClientCount() == 15);
	BOOST_REQUIRE(value2.publishRequestCount() == 16);
	BOOST_REQUIRE(value2.dataChangeNotificationsCount() == 17);
	BOOST_REQUIRE(value2.eventNotificationsCount() == 18);
	BOOST_REQUIRE(value2.notificationsCount() == 19);
	BOOST_REQUIRE(value2.latePublishRequestCount() == 20);
	BOOST_REQUIRE(value2.currentKeepAliveCount() == 21);
	BOOST_REQUIRE(value2.currentLifetimeCount() == 22);
	BOOST_REQUIRE(value2.unacknowledgedMessageCount() == 23);
	BOOST_REQUIRE(value2.discardedMessageCount() == 24);
	BOOST_REQUIRE(value2.monitoredItemCount() == 25);
	BOOST_REQUIRE(value2.disabledMonitoredItemCount() == 26);
	BOOST_REQUIRE(value2.monitoringQueueOverflowCount() == 27);
	BOOST_REQUIRE(value2.nextSequenceNumber() == 28);
	BOOST_REQUIRE(value2.eventQueueOverflowCount() == 29);
}

BOOST_AUTO_TEST_CASE(SubscriptionDiagnosticsDataType_ExtensionObject)
{
	Core core;
	core.init();

	OpcUaExtensionObject value1;
	OpcUaExtensionObject value2;

	OpcUaNodeId sessionId;
	sessionId.nodeId((OpcUaInt32)11);

	OpcUaNodeId typeId;
	typeId.set(OpcUaId_SubscriptionDiagnosticsDataType_Encoding_DefaultBinary);
	value1.typeId(typeId);
	value1.parameter<SubscriptionDiagnosticsDataType>()->sessionId(sessionId);
	value1.parameter<SubscriptionDiagnosticsDataType>()->subscriptionId(1);
	value1.parameter<SubscriptionDiagnosticsDataType>()->priority((OpcUaByte)2);
	value1.parameter<SubscriptionDiagnosticsDataType>()->publishingInterval(3);
	value1.parameter<SubscriptionDiagnosticsDataType>()->maxKeepAliveCount(4);
	value1.parameter<SubscriptionDiagnosticsDataType>()->maxLifetimeCount(5);
	value1.parameter<SubscriptionDiagnosticsDataType>()->maxNotificationsPerPublish(6);
	value1.parameter<SubscriptionDiagnosticsDataType>()->publishingEnabled(true);
	value1.parameter<SubscriptionDiagnosticsDataType>()->modifiyCount(7);
	value1.parameter<SubscriptionDiagnosticsDataType>()->enableCount(8);
	value1.parameter<SubscriptionDiagnosticsDataType>()->disableCount(9);
	value1.parameter<SubscriptionDiagnosticsDataType>()->republishRequestCount(10);
	value1.parameter<SubscriptionDiagnosticsDataType>()->republishMessageRequestCount(11);
	value1.parameter<SubscriptionDiagnosticsDataType>()->republishMessageCount(12);
	value1.parameter<SubscriptionDiagnosticsDataType>()->transferRequestCount(13);
	value1.parameter<SubscriptionDiagnosticsDataType>()->transferredToAltClientCount(14);
	value1.parameter<SubscriptionDiagnosticsDataType>()->transferredToSameClientCount(15);
	value1.parameter<SubscriptionDiagnosticsDataType>()->publishRequestCount(16);
	value1.parameter<SubscriptionDiagnosticsDataType>()->dataChangeNotificationsCount(17);
	value1.parameter<SubscriptionDiagnosticsDataType>()->eventNotificationsCount(18);
	value1.parameter<SubscriptionDiagnosticsDataType>()->notificationsCount(19);
	value1.parameter<SubscriptionDiagnosticsDataType>()->latePublishRequestCount(20);
	value1.parameter<SubscriptionDiagnosticsDataType>()->currentKeepAliveCount(21);
	value1.parameter<SubscriptionDiagnosticsDataType>()->currentLifetimeCount(22);
	value1.parameter<SubscriptionDiagnosticsDataType>()->unacknowledgedMessageCount(23);
	value1.parameter<SubscriptionDiagnosticsDataType>()->discardedMessageCount(24);
	value1.parameter<SubscriptionDiagnosticsDataType>()->monitoredItemCount(25);
	value1.parameter<SubscriptionDiagnosticsDataType>()->disabledMonitoredItemCount(26);
	value1.parameter<SubscriptionDiagnosticsDataType>()->monitoringQueueOverflowCount(27);
	value1.parameter<SubscriptionDiagnosticsDataType>()->nextSequenceNumber(28);
	value1.parameter<SubscriptionDiagnosticsDataType>()->eventQueueOverflowCount(29);

	std::stringstream ss;
	value1.opcUaBinaryEncode(ss);
	value2.opcUaBinaryDecode(ss);

	BOOST_REQUIRE(value2.parameter<SubscriptionDiagnosticsDataType>()->sessionId() == sessionId);
	BOOST_REQUIRE(value2.parameter<SubscriptionDiagnosticsDataType>()->subscriptionId() == 1);
	BOOST_REQUIRE(value2.parameter<SubscriptionDiagnosticsDataType>()->priority() == (OpcUaByte)2);
	BOOST_REQUIRE(value2.parameter<SubscriptionDiagnosticsDataType>()->publishingInterval() == 3);
	BOOST_REQUIRE(value2.parameter<SubscriptionDiagnosticsDataType>()->maxKeepAliveCount() == 4);
	BOOST_REQUIRE(value2.parameter<SubscriptionDiagnosticsDataType>()->maxLifetimeCount() == 5);
	BOOST_REQUIRE(value2.parameter<SubscriptionDiagnosticsDataType>()->maxNotificationsPerPublish() == 6);
	BOOST_REQUIRE(value2.parameter<SubscriptionDiagnosticsDataType>()->publishingEnabled() == true);
	BOOST_REQUIRE(value2.parameter<SubscriptionDiagnosticsDataType>()->modifiyCount() == 7);
	BOOST_REQUIRE(value2.parameter<SubscriptionDiagnosticsDataType>()->enableCount() == 8);
	BOOST_REQUIRE(value2.parameter<SubscriptionDiagnosticsDataType>()->disableCount() == 9);
	BOOST_REQUIRE(value2.parameter<SubscriptionDiagnosticsDataType>()->republishRequestCount() == 10);
	BOOST_REQUIRE(value2.parameter<SubscriptionDiagnosticsDataType>()->republishMessageRequestCount() == 11);
	BOOST_REQUIRE(value2.parameter<SubscriptionDiagnosticsDataType>()->republishMessageCount() == 12);
	BOOST_REQUIRE(value2.parameter<SubscriptionDiagnosticsDataType>()->transferRequestCount() == 13);
	BOOST_REQUIRE(value2.parameter<SubscriptionDiagnosticsDataType>()->transferredToAltClientCount() == 14);
	BOOST_REQUIRE(value2.parameter<SubscriptionDiagnosticsDataType>()->transferredToSameClientCount() == 15);
	BOOST_REQUIRE(value2.parameter<SubscriptionDiagnosticsDataType>()->publishRequestCount() == 16);
	BOOST_REQUIRE(value2.parameter<SubscriptionDiagnosticsDataType>()->dataChangeNotificationsCount() == 17);
	BOOST_REQUIRE(value2.parameter<SubscriptionDiagnosticsDataType>()->eventNotificationsCount() == 18);
	BOOST_REQUIRE(value2.parameter<SubscriptionDiagnosticsDataType>()->notificationsCount() == 19);
	BOOST_REQUIRE(value2.parameter<SubscriptionDiagnosticsDataType>()->latePublishRequestCount() == 20);
	BOOST_REQUIRE(value2.parameter<SubscriptionDiagnosticsDataType>()->currentKeepAliveCount() == 21);
	BOOST_REQUIRE(value2.parameter<SubscriptionDiagnosticsDataType>()->currentLifetimeCount() == 22);
	BOOST_REQUIRE(value2.parameter<SubscriptionDiagnosticsDataType>()->unacknowledgedMessageCount() == 23);
	BOOST_REQUIRE(value2.parameter<SubscriptionDiagnosticsDataType>()->discardedMessageCount() == 24);
	BOOST_REQUIRE(value2.parameter<SubscriptionDiagnosticsDataType>()->monitoredItemCount() == 25);
	BOOST_REQUIRE(value2.parameter<SubscriptionDiagnosticsDataType>()->disabledMonitoredItemCount() == 26);
	BOOST_REQUIRE(value2.parameter<SubscriptionDiagnosticsDataType>()->monitoringQueueOverflowCount() == 27);
	BOOST_REQUIRE(value2.parameter<SubscriptionDiagnosticsDataType>()->nextSequenceNumber() == 28);
	BOOST_REQUIRE(value2.parameter<SubscriptionDiagnosticsDataType>()->eventQueueOverflowCount() == 29);
}

BOOST_AUTO_TEST_CASE(SubscriptionDiagnosticsDataType_ExtensionObject_copyTo)
{
	Core core;
	core.init();

	OpcUaExtensionObject value1;
	OpcUaExtensionObject value2;

	OpcUaNodeId sessionId;
	sessionId.nodeId((OpcUaInt32)11);

	OpcUaNodeId typeId;
	typeId.set(OpcUaId_SubscriptionDiagnosticsDataType_Encoding_DefaultBinary);
	value1.typeId(typeId);
	value1.parameter<SubscriptionDiagnosticsDataType>()->sessionId(sessionId);
	value1.parameter<SubscriptionDiagnosticsDataType>()->subscriptionId(1);
	value1.parameter<SubscriptionDiagnosticsDataType>()->priority((OpcUaByte)2);
	value1.parameter<SubscriptionDiagnosticsDataType>()->publishingInterval(3);
	value1.parameter<SubscriptionDiagnosticsDataType>()->maxKeepAliveCount(4);
	value1.parameter<SubscriptionDiagnosticsDataType>()->maxLifetimeCount(5);
	value1.parameter<SubscriptionDiagnosticsDataType>()->maxNotificationsPerPublish(6);
	value1.parameter<SubscriptionDiagnosticsDataType>()->publishingEnabled(true);
	value1.parameter<SubscriptionDiagnosticsDataType>()->modifiyCount(7);
	value1.parameter<SubscriptionDiagnosticsDataType>()->enableCount(8);
	value1.parameter<SubscriptionDiagnosticsDataType>()->disableCount(9);
	value1.parameter<SubscriptionDiagnosticsDataType>()->republishRequestCount(10);
	value1.parameter<SubscriptionDiagnosticsDataType>()->republishMessageRequestCount(11);
	value1.parameter<SubscriptionDiagnosticsDataType>()->republishMessageCount(12);
	value1.parameter<SubscriptionDiagnosticsDataType>()->transferRequestCount(13);
	value1.parameter<SubscriptionDiagnosticsDataType>()->transferredToAltClientCount(14);
	value1.parameter<SubscriptionDiagnosticsDataType>()->transferredToSameClientCount(15);
	value1.parameter<SubscriptionDiagnosticsDataType>()->publishRequestCount(16);
	value1.parameter<SubscriptionDiagnosticsDataType>()->dataChangeNotificationsCount(17);
	value1.parameter<SubscriptionDiagnosticsDataType>()->eventNotificationsCount(18);
	value1.parameter<SubscriptionDiagnosticsDataType>()->notificationsCount(19);
	value1.parameter<SubscriptionDiagnosticsDataType>()->latePublishRequestCount(20);
	value1.parameter<SubscriptionDiagnosticsDataType>()->currentKeepAliveCount(21);
	value1.parameter<SubscriptionDiagnosticsDataType>()->currentLifetimeCount(22);
	value1.parameter<SubscriptionDiagnosticsDataType>()->unacknowledgedMessageCount(23);
	value1.parameter<SubscriptionDiagnosticsDataType>()->discardedMessageCount(24);
	value1.parameter<SubscriptionDiagnosticsDataType>()->monitoredItemCount(25);
	value1.parameter<SubscriptionDiagnosticsDataType>()->disabledMonitoredItemCount(26);
	value1.parameter<SubscriptionDiagnosticsDataType>()->monitoringQueueOverflowCount(27);
	value1.parameter<SubscriptionDiagnosticsDataType>()->nextSequenceNumber(28);
	value1.parameter<SubscriptionDiagnosticsDataType>()->eventQueueOverflowCount(29);

	value1.copyTo(value2);

	BOOST_REQUIRE(value2.parameter<SubscriptionDiagnosticsDataType>()->sessionId() == sessionId);
	BOOST_REQUIRE(value2.parameter<SubscriptionDiagnosticsDataType>()->subscriptionId() == 1);
	BOOST_REQUIRE(value2.parameter<SubscriptionDiagnosticsDataType>()->priority() == (OpcUaByte)2);
	BOOST_REQUIRE(value2.parameter<SubscriptionDiagnosticsDataType>()->publishingInterval() == 3);
	BOOST_REQUIRE(value2.parameter<SubscriptionDiagnosticsDataType>()->maxKeepAliveCount() == 4);
	BOOST_REQUIRE(value2.parameter<SubscriptionDiagnosticsDataType>()->maxLifetimeCount() == 5);
	BOOST_REQUIRE(value2.parameter<SubscriptionDiagnosticsDataType>()->maxNotificationsPerPublish() == 6);
	BOOST_REQUIRE(value2.parameter<SubscriptionDiagnosticsDataType>()->publishingEnabled() == true);
	BOOST_REQUIRE(value2.parameter<SubscriptionDiagnosticsDataType>()->modifiyCount() == 7);
	BOOST_REQUIRE(value2.parameter<SubscriptionDiagnosticsDataType>()->enableCount() == 8);
	BOOST_REQUIRE(value2.parameter<SubscriptionDiagnosticsDataType>()->disableCount() == 9);
	BOOST_REQUIRE(value2.parameter<SubscriptionDiagnosticsDataType>()->republishRequestCount() == 10);
	BOOST_REQUIRE(value2.parameter<SubscriptionDiagnosticsDataType>()->republishMessageRequestCount() == 11);
	BOOST_REQUIRE(value2.parameter<SubscriptionDiagnosticsDataType>()->republishMessageCount() == 12);
	BOOST_REQUIRE(value2.parameter<SubscriptionDiagnosticsDataType>()->transferRequestCount() == 13);
	BOOST_REQUIRE(value2.parameter<SubscriptionDiagnosticsDataType>()->transferredToAltClientCount() == 14);
	BOOST_REQUIRE(value2.parameter<SubscriptionDiagnosticsDataType>()->transferredToSameClientCount() == 15);
	BOOST_REQUIRE(value2.parameter<SubscriptionDiagnosticsDataType>()->publishRequestCount() == 16);
	BOOST_REQUIRE(value2.parameter<SubscriptionDiagnosticsDataType>()->dataChangeNotificationsCount() == 17);
	BOOST_REQUIRE(value2.parameter<SubscriptionDiagnosticsDataType>()->eventNotificationsCount() == 18);
	BOOST_REQUIRE(value2.parameter<SubscriptionDiagnosticsDataType>()->notificationsCount() == 19);
	BOOST_REQUIRE(value2.parameter<SubscriptionDiagnosticsDataType>()->latePublishRequestCount() == 20);
	BOOST_REQUIRE(value2.parameter<SubscriptionDiagnosticsDataType>()->currentKeepAliveCount() == 21);
	BOOST_REQUIRE(value2.parameter<SubscriptionDiagnosticsDataType>()->currentLifetimeCount() == 22);
	BOOST_REQUIRE(value2.parameter<SubscriptionDiagnosticsDataType>()->unacknowledgedMessageCount() == 23);
	BOOST_REQUIRE(value2.parameter<SubscriptionDiagnosticsDataType>()->discardedMessageCount() == 24);
	BOOST_REQUIRE(value2.parameter<SubscriptionDiagnosticsDataType>()->monitoredItemCount() == 25);
	BOOST_REQUIRE(value2.parameter<SubscriptionDiagnosticsDataType>()->disabledMonitoredItemCount() == 26);
	BOOST_REQUIRE(value2.parameter<SubscriptionDiagnosticsDataType>()->monitoringQueueOverflowCount() == 27);
	BOOST_REQUIRE(value2.parameter<SubscriptionDiagnosticsDataType>()->nextSequenceNumber() == 28);
	BOOST_REQUIRE(value2.parameter<SubscriptionDiagnosticsDataType>()->eventQueueOverflowCount() == 29);
}


BOOST_AUTO_TEST_SUITE_END()


