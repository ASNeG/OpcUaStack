
#include "unittest.h"
#include "OpcUaStackCore/Core/Core.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaIdentifier.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaExtensionObject.h"
#include "OpcUaStackCore/StandardDataTypes/ServerDiagnosticsSummaryDataType.h"

using namespace OpcUaStackCore;

BOOST_AUTO_TEST_SUITE(ServerDiagnosticsSummaryDataType_)

BOOST_AUTO_TEST_CASE(ServerDiagnosticsSummaryDataType_)
{
	std::cout << "ServerDiagnosticsSummaryDataType_t" << std::endl;
}

BOOST_AUTO_TEST_CASE(ServerDiagnosticsSummaryDataType_encode_decode)
{
	ServerDiagnosticsSummaryDataType value1;
	ServerDiagnosticsSummaryDataType value2;

	value1.serverViewCount() = 1;
	value1.currentSessionCount() = 2;
	value1.cumulatedSessionCount() = 3;
	value1.securityRejectedSessionCount() = 4;
	value1.rejectedSessionCount() = 5;
	value1.sessionTimeoutCount() = 6;
	value1.sessionAbortCount() = 7;
	value1.publishingIntervalCount() = 9;
	value1.currentSubscriptionCount() = 10;
	value1.cumulatedSubscriptionCount() = 11;
	value1.securityRejectedRequestsCount() = 12;
	value1.rejectedRequestsCount() = 13;

	std::stringstream ss;
	value1.opcUaBinaryEncode(ss);
	value2.opcUaBinaryDecode(ss);

	BOOST_REQUIRE(value2.serverViewCount() == 1);
	BOOST_REQUIRE(value2.currentSessionCount() == 2);
	BOOST_REQUIRE(value2.cumulatedSessionCount() == 3);
	BOOST_REQUIRE(value2.securityRejectedSessionCount() == 4);
	BOOST_REQUIRE(value2.rejectedSessionCount() == 5);
	BOOST_REQUIRE(value2.sessionTimeoutCount() == 6);
	BOOST_REQUIRE(value2.sessionAbortCount() == 7);
	BOOST_REQUIRE(value2.publishingIntervalCount() == 9);
	BOOST_REQUIRE(value2.currentSubscriptionCount() == 10);
	BOOST_REQUIRE(value2.cumulatedSubscriptionCount() == 11);
	BOOST_REQUIRE(value2.securityRejectedRequestsCount() == 12);
	BOOST_REQUIRE(value2.rejectedRequestsCount() == 13);
}

BOOST_AUTO_TEST_CASE(ServerDiagnosticsSummaryDataType_ExtensionObject)
{
	Core core;
	core.init();

	OpcUaExtensionObject value1;
	OpcUaExtensionObject value2;

	OpcUaNodeId typeId;
	typeId.set(OpcUaId_ServerDiagnosticsSummaryDataType_Encoding_DefaultBinary);
	value1.typeId(typeId);
	value1.parameter<ServerDiagnosticsSummaryDataType>()->serverViewCount() = 1;
	value1.parameter<ServerDiagnosticsSummaryDataType>()->currentSessionCount() = 2;
	value1.parameter<ServerDiagnosticsSummaryDataType>()->cumulatedSessionCount() = 3;
	value1.parameter<ServerDiagnosticsSummaryDataType>()->securityRejectedSessionCount() = 4;
	value1.parameter<ServerDiagnosticsSummaryDataType>()->rejectedSessionCount() = 5;
	value1.parameter<ServerDiagnosticsSummaryDataType>()->sessionTimeoutCount() = 6;
	value1.parameter<ServerDiagnosticsSummaryDataType>()->sessionAbortCount() = 7;
	value1.parameter<ServerDiagnosticsSummaryDataType>()->publishingIntervalCount() = 9;
	value1.parameter<ServerDiagnosticsSummaryDataType>()->currentSubscriptionCount() = 10;
	value1.parameter<ServerDiagnosticsSummaryDataType>()->cumulatedSubscriptionCount() = 11;
	value1.parameter<ServerDiagnosticsSummaryDataType>()->securityRejectedRequestsCount() = 12;
	value1.parameter<ServerDiagnosticsSummaryDataType>()->rejectedRequestsCount() = 13;

	std::stringstream ss;
	value1.opcUaBinaryEncode(ss);
	value2.opcUaBinaryDecode(ss);

	BOOST_REQUIRE(value2.parameter<ServerDiagnosticsSummaryDataType>()->serverViewCount() == 1);
	BOOST_REQUIRE(value2.parameter<ServerDiagnosticsSummaryDataType>()->currentSessionCount() == 2);
	BOOST_REQUIRE(value2.parameter<ServerDiagnosticsSummaryDataType>()->cumulatedSessionCount() == 3);
	BOOST_REQUIRE(value2.parameter<ServerDiagnosticsSummaryDataType>()->securityRejectedSessionCount() == 4);
	BOOST_REQUIRE(value2.parameter<ServerDiagnosticsSummaryDataType>()->rejectedSessionCount() == 5);
	BOOST_REQUIRE(value2.parameter<ServerDiagnosticsSummaryDataType>()->sessionTimeoutCount() == 6);
	BOOST_REQUIRE(value2.parameter<ServerDiagnosticsSummaryDataType>()->sessionAbortCount() == 7);
	BOOST_REQUIRE(value2.parameter<ServerDiagnosticsSummaryDataType>()->publishingIntervalCount() == 9);
	BOOST_REQUIRE(value2.parameter<ServerDiagnosticsSummaryDataType>()->currentSubscriptionCount() == 10);
	BOOST_REQUIRE(value2.parameter<ServerDiagnosticsSummaryDataType>()->cumulatedSubscriptionCount() == 11);
	BOOST_REQUIRE(value2.parameter<ServerDiagnosticsSummaryDataType>()->securityRejectedRequestsCount() == 12);
	BOOST_REQUIRE(value2.parameter<ServerDiagnosticsSummaryDataType>()->rejectedRequestsCount() == 13);
}

BOOST_AUTO_TEST_CASE(ServerDiagnosticsSummaryDataType_ExtensionObject_copyTo)
{
	Core core;
	core.init();

	OpcUaExtensionObject value1;
	OpcUaExtensionObject value2;

	OpcUaNodeId typeId;
	typeId.set(OpcUaId_ServerDiagnosticsSummaryDataType_Encoding_DefaultBinary);
	value1.typeId(typeId);
	value1.parameter<ServerDiagnosticsSummaryDataType>()->serverViewCount() = 1;
	value1.parameter<ServerDiagnosticsSummaryDataType>()->currentSessionCount() = 2;
	value1.parameter<ServerDiagnosticsSummaryDataType>()->cumulatedSessionCount() = 3;
	value1.parameter<ServerDiagnosticsSummaryDataType>()->securityRejectedSessionCount() = 4;
	value1.parameter<ServerDiagnosticsSummaryDataType>()->rejectedSessionCount() = 5;
	value1.parameter<ServerDiagnosticsSummaryDataType>()->sessionTimeoutCount() = 6;
	value1.parameter<ServerDiagnosticsSummaryDataType>()->sessionAbortCount() = 7;
	value1.parameter<ServerDiagnosticsSummaryDataType>()->publishingIntervalCount() = 9;
	value1.parameter<ServerDiagnosticsSummaryDataType>()->currentSubscriptionCount() = 10;
	value1.parameter<ServerDiagnosticsSummaryDataType>()->cumulatedSubscriptionCount() = 11;
	value1.parameter<ServerDiagnosticsSummaryDataType>()->securityRejectedRequestsCount() = 12;
	value1.parameter<ServerDiagnosticsSummaryDataType>()->rejectedRequestsCount() = 13;

	value1.copyTo(value2);

	BOOST_REQUIRE(value2.parameter<ServerDiagnosticsSummaryDataType>()->serverViewCount() == 1);
	BOOST_REQUIRE(value2.parameter<ServerDiagnosticsSummaryDataType>()->currentSessionCount() == 2);
	BOOST_REQUIRE(value2.parameter<ServerDiagnosticsSummaryDataType>()->cumulatedSessionCount() == 3);
	BOOST_REQUIRE(value2.parameter<ServerDiagnosticsSummaryDataType>()->securityRejectedSessionCount() == 4);
	BOOST_REQUIRE(value2.parameter<ServerDiagnosticsSummaryDataType>()->rejectedSessionCount() == 5);
	BOOST_REQUIRE(value2.parameter<ServerDiagnosticsSummaryDataType>()->sessionTimeoutCount() == 6);
	BOOST_REQUIRE(value2.parameter<ServerDiagnosticsSummaryDataType>()->sessionAbortCount() == 7);
	BOOST_REQUIRE(value2.parameter<ServerDiagnosticsSummaryDataType>()->publishingIntervalCount() == 9);
	BOOST_REQUIRE(value2.parameter<ServerDiagnosticsSummaryDataType>()->currentSubscriptionCount() == 10);
	BOOST_REQUIRE(value2.parameter<ServerDiagnosticsSummaryDataType>()->cumulatedSubscriptionCount() == 11);
	BOOST_REQUIRE(value2.parameter<ServerDiagnosticsSummaryDataType>()->securityRejectedRequestsCount() == 12);
	BOOST_REQUIRE(value2.parameter<ServerDiagnosticsSummaryDataType>()->rejectedRequestsCount() == 13);
}


BOOST_AUTO_TEST_SUITE_END()
