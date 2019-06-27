#include "unittest.h"
#include "OpcUaStackCore/Core/Core.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaIdentifier.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaExtensionObject.h"
#include "OpcUaStackCore/StandardDataTypes/SessionDiagnosticsDataType.h"

using namespace OpcUaStackCore;

BOOST_AUTO_TEST_SUITE(SessionDiagnosticsDataType_)

BOOST_AUTO_TEST_CASE(SessionDiagnosticsDataType_)
{
	std::cout << "SessionDiagnosticsDataType_t" << std::endl;
}

BOOST_AUTO_TEST_CASE(SessionDiagnosticsDataType_encode_decode)
{
	SessionDiagnosticsDataType value1;
	SessionDiagnosticsDataType value2;

	OpcUaDateTime now(boost::posix_time::microsec_clock::local_time());
	OpcUaNodeId sessionId;
	sessionId.nodeId((OpcUaInt32)11);
	OpcUaString sessionName("name");
	OpcUaString serverUri("uri");
	OpcUaString endpointUri("endpointuri");
	OpcUaLocalizedText applicationName("de", "name");

	value1.sessionId(sessionId);
	value1.sessionName(sessionName);
	value1.clientDescription()->applicationUri("applicationUri");
	value1.clientDescription()->productUri("productUri");
	value1.clientDescription()->applicationName(applicationName);
	value1.clientDescription()->applicationType(AT_Server);
	value1.clientDescription()->gatewayServerUri("serverUri");
	value1.clientDescription()->discoveryProfileUri("profileUri");
	value1.serverUri(serverUri);
	value1.endpointUri(endpointUri);
	value1.actualSessionTimeout(2);
	value1.maxResponseMessageSize(3);
	value1.clientConnectionTime(now);
	value1.clientLastContactTime(now);
	value1.currentSubscriptionsCount(4);
	value1.currentMonitoredItemsCount(5);
	value1.currentPublishRequestsInQueue(6);
	value1.currentPublishTimerExpirations(7);

	std::stringstream ss;
	value1.opcUaBinaryEncode(ss);
	value2.opcUaBinaryDecode(ss);

	BOOST_REQUIRE(value2.sessionId() == sessionId);
	BOOST_REQUIRE(value2.sessionName() == sessionName);
	BOOST_REQUIRE(value2.clientDescription()->applicationUri() == "applicationUri");
	BOOST_REQUIRE(value2.clientDescription()->productUri() == "productUri");
	BOOST_REQUIRE(value2.clientDescription()->applicationName() == applicationName);
	BOOST_REQUIRE(value2.clientDescription()->applicationType() == AT_Server);
	BOOST_REQUIRE(value2.clientDescription()->gatewayServerUri() == "serverUri");
	BOOST_REQUIRE(value2.clientDescription()->discoveryProfileUri() == "profileUri");
	BOOST_REQUIRE(value2.serverUri() == serverUri);
	BOOST_REQUIRE(value2.endpointUri() == endpointUri);
	BOOST_REQUIRE(value2.actualSessionTimeout() == 2);
	BOOST_REQUIRE(value2.maxResponseMessageSize() == 3);
	BOOST_REQUIRE(value2.clientConnectionTime() == now);
	BOOST_REQUIRE(value2.clientLastContactTime() == now);
	BOOST_REQUIRE(value2.currentSubscriptionsCount() == 4);
	BOOST_REQUIRE(value2.currentMonitoredItemsCount() == 5);
	BOOST_REQUIRE(value2.currentPublishRequestsInQueue() == 6);
	BOOST_REQUIRE(value2.currentPublishTimerExpirations() == 7);
}

BOOST_AUTO_TEST_CASE(SessionDiagnosticsDataType_ExtensionObject)
{
	Core core;
	core.init();

	OpcUaExtensionObject value1;
	OpcUaExtensionObject value2;

	OpcUaDateTime now(boost::posix_time::microsec_clock::local_time());
	OpcUaNodeId sessionId;
	sessionId.nodeId((OpcUaInt32)11);
	OpcUaString sessionName("name");
	OpcUaString serverUri("uri");
	OpcUaString endpointUri("endpointuri");
	OpcUaLocalizedText applicationName("de", "name");

	OpcUaNodeId typeId;
	typeId.set(OpcUaId_SessionDiagnosticsDataType_Encoding_DefaultBinary);
	value1.typeId(typeId);
	value1.parameter<SessionDiagnosticsDataType>()->sessionId(sessionId);
	value1.parameter<SessionDiagnosticsDataType>()->sessionName(sessionName);
	value1.parameter<SessionDiagnosticsDataType>()->clientDescription()->applicationUri("applicationUri");
	value1.parameter<SessionDiagnosticsDataType>()->clientDescription()->productUri("productUri");
	value1.parameter<SessionDiagnosticsDataType>()->clientDescription()->applicationName(applicationName);
	value1.parameter<SessionDiagnosticsDataType>()->clientDescription()->applicationType(AT_Server);
	value1.parameter<SessionDiagnosticsDataType>()->clientDescription()->gatewayServerUri("serverUri");
	value1.parameter<SessionDiagnosticsDataType>()->clientDescription()->discoveryProfileUri("profileUri");
	value1.parameter<SessionDiagnosticsDataType>()->serverUri(serverUri);
	value1.parameter<SessionDiagnosticsDataType>()->endpointUri(endpointUri);
	value1.parameter<SessionDiagnosticsDataType>()->actualSessionTimeout(2);
	value1.parameter<SessionDiagnosticsDataType>()->maxResponseMessageSize(3);
	value1.parameter<SessionDiagnosticsDataType>()->clientConnectionTime(now);
	value1.parameter<SessionDiagnosticsDataType>()->clientLastContactTime(now);
	value1.parameter<SessionDiagnosticsDataType>()->currentSubscriptionsCount(4);
	value1.parameter<SessionDiagnosticsDataType>()->currentMonitoredItemsCount(5);
	value1.parameter<SessionDiagnosticsDataType>()->currentPublishRequestsInQueue(6);
	value1.parameter<SessionDiagnosticsDataType>()->currentPublishTimerExpirations(7);

	std::stringstream ss;
	value1.opcUaBinaryEncode(ss);
	value2.opcUaBinaryDecode(ss);

	BOOST_REQUIRE(value2.parameter<SessionDiagnosticsDataType>()->sessionId() == sessionId);
	BOOST_REQUIRE(value2.parameter<SessionDiagnosticsDataType>()->sessionName() == sessionName);
	BOOST_REQUIRE(value2.parameter<SessionDiagnosticsDataType>()->clientDescription()->applicationUri() == "applicationUri");
	BOOST_REQUIRE(value2.parameter<SessionDiagnosticsDataType>()->clientDescription()->productUri() == "productUri");
	BOOST_REQUIRE(value2.parameter<SessionDiagnosticsDataType>()->clientDescription()->applicationName() == applicationName);
	BOOST_REQUIRE(value2.parameter<SessionDiagnosticsDataType>()->clientDescription()->applicationType() == AT_Server);
	BOOST_REQUIRE(value2.parameter<SessionDiagnosticsDataType>()->clientDescription()->gatewayServerUri() == "serverUri");
	BOOST_REQUIRE(value2.parameter<SessionDiagnosticsDataType>()->clientDescription()->discoveryProfileUri() == "profileUri");
	BOOST_REQUIRE(value2.parameter<SessionDiagnosticsDataType>()->serverUri() == serverUri);
	BOOST_REQUIRE(value2.parameter<SessionDiagnosticsDataType>()->endpointUri() == endpointUri);
	BOOST_REQUIRE(value2.parameter<SessionDiagnosticsDataType>()->actualSessionTimeout() == 2);
	BOOST_REQUIRE(value2.parameter<SessionDiagnosticsDataType>()->maxResponseMessageSize() == 3);
	BOOST_REQUIRE(value2.parameter<SessionDiagnosticsDataType>()->clientConnectionTime() == now);
	BOOST_REQUIRE(value2.parameter<SessionDiagnosticsDataType>()->clientLastContactTime() == now);
	BOOST_REQUIRE(value2.parameter<SessionDiagnosticsDataType>()->currentSubscriptionsCount() == 4);
	BOOST_REQUIRE(value2.parameter<SessionDiagnosticsDataType>()->currentMonitoredItemsCount() == 5);
	BOOST_REQUIRE(value2.parameter<SessionDiagnosticsDataType>()->currentPublishRequestsInQueue() == 6);
	BOOST_REQUIRE(value2.parameter<SessionDiagnosticsDataType>()->currentPublishTimerExpirations() == 7);
}

BOOST_AUTO_TEST_CASE(SessionDiagnosticsDataType_ExtensionObject_copyTo)
{
	Core core;
	core.init();

	OpcUaExtensionObject value1;
	OpcUaExtensionObject value2;

	OpcUaDateTime now(boost::posix_time::microsec_clock::local_time());
	OpcUaNodeId sessionId;
	sessionId.nodeId((OpcUaInt32)11);
	OpcUaString sessionName("name");
	OpcUaString serverUri("uri");
	OpcUaString endpointUri("endpointuri");
	OpcUaLocalizedText applicationName("de", "name");

	OpcUaNodeId typeId;
	typeId.set(OpcUaId_SessionDiagnosticsDataType_Encoding_DefaultBinary);
	value1.typeId(typeId);
	value1.parameter<SessionDiagnosticsDataType>()->sessionId(sessionId);
	value1.parameter<SessionDiagnosticsDataType>()->sessionName(sessionName);
	value1.parameter<SessionDiagnosticsDataType>()->clientDescription()->applicationUri("applicationUri");
	value1.parameter<SessionDiagnosticsDataType>()->clientDescription()->productUri("productUri");
	value1.parameter<SessionDiagnosticsDataType>()->clientDescription()->applicationName(applicationName);
	value1.parameter<SessionDiagnosticsDataType>()->clientDescription()->applicationType(AT_Server);
	value1.parameter<SessionDiagnosticsDataType>()->clientDescription()->gatewayServerUri("serverUri");
	value1.parameter<SessionDiagnosticsDataType>()->clientDescription()->discoveryProfileUri("profileUri");
	value1.parameter<SessionDiagnosticsDataType>()->serverUri(serverUri);
	value1.parameter<SessionDiagnosticsDataType>()->endpointUri(endpointUri);
	value1.parameter<SessionDiagnosticsDataType>()->actualSessionTimeout(2);
	value1.parameter<SessionDiagnosticsDataType>()->maxResponseMessageSize(3);
	value1.parameter<SessionDiagnosticsDataType>()->clientConnectionTime(now);
	value1.parameter<SessionDiagnosticsDataType>()->clientLastContactTime(now);
	value1.parameter<SessionDiagnosticsDataType>()->currentSubscriptionsCount(4);
	value1.parameter<SessionDiagnosticsDataType>()->currentMonitoredItemsCount(5);
	value1.parameter<SessionDiagnosticsDataType>()->currentPublishRequestsInQueue(6);
	value1.parameter<SessionDiagnosticsDataType>()->currentPublishTimerExpirations(7);

	value1.copyTo(value2);

	BOOST_REQUIRE(value2.parameter<SessionDiagnosticsDataType>()->sessionId() == sessionId);
	BOOST_REQUIRE(value2.parameter<SessionDiagnosticsDataType>()->sessionName() == sessionName);
	BOOST_REQUIRE(value2.parameter<SessionDiagnosticsDataType>()->clientDescription()->applicationUri() == "applicationUri");
	BOOST_REQUIRE(value2.parameter<SessionDiagnosticsDataType>()->clientDescription()->productUri() == "productUri");
	BOOST_REQUIRE(value2.parameter<SessionDiagnosticsDataType>()->clientDescription()->applicationName() == applicationName);
	BOOST_REQUIRE(value2.parameter<SessionDiagnosticsDataType>()->clientDescription()->applicationType() == AT_Server);
	BOOST_REQUIRE(value2.parameter<SessionDiagnosticsDataType>()->clientDescription()->gatewayServerUri() == "serverUri");
	BOOST_REQUIRE(value2.parameter<SessionDiagnosticsDataType>()->clientDescription()->discoveryProfileUri() == "profileUri");
	BOOST_REQUIRE(value2.parameter<SessionDiagnosticsDataType>()->serverUri() == serverUri);
	BOOST_REQUIRE(value2.parameter<SessionDiagnosticsDataType>()->endpointUri() == endpointUri);
	BOOST_REQUIRE(value2.parameter<SessionDiagnosticsDataType>()->actualSessionTimeout() == 2);
	BOOST_REQUIRE(value2.parameter<SessionDiagnosticsDataType>()->maxResponseMessageSize() == 3);
	BOOST_REQUIRE(value2.parameter<SessionDiagnosticsDataType>()->clientConnectionTime() == now);
	BOOST_REQUIRE(value2.parameter<SessionDiagnosticsDataType>()->clientLastContactTime() == now);
	BOOST_REQUIRE(value2.parameter<SessionDiagnosticsDataType>()->currentSubscriptionsCount() == 4);
	BOOST_REQUIRE(value2.parameter<SessionDiagnosticsDataType>()->currentMonitoredItemsCount() == 5);
	BOOST_REQUIRE(value2.parameter<SessionDiagnosticsDataType>()->currentPublishRequestsInQueue() == 6);
	BOOST_REQUIRE(value2.parameter<SessionDiagnosticsDataType>()->currentPublishTimerExpirations() == 7);
}


BOOST_AUTO_TEST_SUITE_END()



