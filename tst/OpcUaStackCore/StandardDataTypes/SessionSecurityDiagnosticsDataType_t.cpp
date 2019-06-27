#include "unittest.h"
#include "OpcUaStackCore/Core/Core.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaIdentifier.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaExtensionObject.h"
#include "OpcUaStackCore/StandardDataTypes/SessionSecurityDiagnosticsDataType.h"

using namespace OpcUaStackCore;

BOOST_AUTO_TEST_SUITE(SessionSecurityDiagnosticsDataType_)

BOOST_AUTO_TEST_CASE(SessionSecurityDiagnosticsDataType_)
{
	std::cout << "SessionSecurityDiagnosticsDataType_t" << std::endl;
}

BOOST_AUTO_TEST_CASE(SessionSecurityDiagnosticsDataType_encode_decode)
{
	SessionSecurityDiagnosticsDataType value1;
	SessionSecurityDiagnosticsDataType value2;

	OpcUaNodeId sessionId;
	sessionId.nodeId((OpcUaInt32)11);
	OpcUaString clientUserIdOfSession("string1");
	OpcUaString authenticationMechanism("string2");
	OpcUaString encoding("string3");
	OpcUaString transportProtocol("string4");
	OpcUaString securityPolicyUri("string5");

	value1.sessionId(sessionId);
	value1.clientUserIdOfSession(clientUserIdOfSession);
	value1.authenticationMechanism(authenticationMechanism);
	value1.encoding(encoding);
	value1.transportProtocol(transportProtocol);
	value1.securityMode(1);
	value1.securityPolicyUri(securityPolicyUri);
	value1.clientCertificate().value("abc", 3);

	std::stringstream ss;
	value1.opcUaBinaryEncode(ss);
	value2.opcUaBinaryDecode(ss);

	BOOST_REQUIRE(value2.sessionId() == sessionId);
	BOOST_REQUIRE(value2.clientUserIdOfSession() == clientUserIdOfSession);
	BOOST_REQUIRE(value2.authenticationMechanism() == authenticationMechanism);
	BOOST_REQUIRE(value2.encoding() == encoding);
	BOOST_REQUIRE(value2.transportProtocol() == transportProtocol);
	BOOST_REQUIRE(value2.securityMode() == 1);
	BOOST_REQUIRE(value2.securityPolicyUri() == securityPolicyUri);
	BOOST_REQUIRE(value2.clientCertificate().exist() == true);
}

BOOST_AUTO_TEST_CASE(SessionSecurityDiagnosticsDataType_ExtensionObject)
{
	Core core;
	core.init();

	OpcUaExtensionObject value1;
	OpcUaExtensionObject value2;

	OpcUaNodeId sessionId;
	sessionId.nodeId((OpcUaInt32)11);
	OpcUaString clientUserIdOfSession("string1");
	OpcUaString authenticationMechanism("string2");
	OpcUaString encoding("string3");
	OpcUaString transportProtocol("string4");
	OpcUaString securityPolicyUri("string5");

	OpcUaNodeId typeId;
	typeId.set(OpcUaId_SessionSecurityDiagnosticsDataType_Encoding_DefaultBinary);
	value1.typeId(typeId);
	value1.parameter<SessionSecurityDiagnosticsDataType>()->sessionId(sessionId);
	value1.parameter<SessionSecurityDiagnosticsDataType>()->clientUserIdOfSession(clientUserIdOfSession);
	value1.parameter<SessionSecurityDiagnosticsDataType>()->authenticationMechanism(authenticationMechanism);
	value1.parameter<SessionSecurityDiagnosticsDataType>()->encoding(encoding);
	value1.parameter<SessionSecurityDiagnosticsDataType>()->transportProtocol(transportProtocol);
	value1.parameter<SessionSecurityDiagnosticsDataType>()->securityMode(1);
	value1.parameter<SessionSecurityDiagnosticsDataType>()->securityPolicyUri(securityPolicyUri);
	value1.parameter<SessionSecurityDiagnosticsDataType>()->clientCertificate().value("abc", 3);

	std::stringstream ss;
	value1.opcUaBinaryEncode(ss);
	value2.opcUaBinaryDecode(ss);

	BOOST_REQUIRE(value2.parameter<SessionSecurityDiagnosticsDataType>()->sessionId() == sessionId);
	BOOST_REQUIRE(value2.parameter<SessionSecurityDiagnosticsDataType>()->clientUserIdOfSession() == clientUserIdOfSession);
	BOOST_REQUIRE(value2.parameter<SessionSecurityDiagnosticsDataType>()->authenticationMechanism() == authenticationMechanism);
	BOOST_REQUIRE(value2.parameter<SessionSecurityDiagnosticsDataType>()->encoding() == encoding);
	BOOST_REQUIRE(value2.parameter<SessionSecurityDiagnosticsDataType>()->transportProtocol() == transportProtocol);
	BOOST_REQUIRE(value2.parameter<SessionSecurityDiagnosticsDataType>()->securityMode() == 1);
	BOOST_REQUIRE(value2.parameter<SessionSecurityDiagnosticsDataType>()->securityPolicyUri() == securityPolicyUri);
	BOOST_REQUIRE(value2.parameter<SessionSecurityDiagnosticsDataType>()->clientCertificate().exist() == true);
}

BOOST_AUTO_TEST_CASE(SessionSecurityDiagnosticsDataType_ExtensionObject_copyTo)
{
	Core core;
	core.init();

	OpcUaExtensionObject value1;
	OpcUaExtensionObject value2;

	OpcUaNodeId sessionId;
	sessionId.nodeId((OpcUaInt32)11);
	OpcUaString clientUserIdOfSession("string1");
	OpcUaString authenticationMechanism("string2");
	OpcUaString encoding("string3");
	OpcUaString transportProtocol("string4");
	OpcUaString securityPolicyUri("string5");

	OpcUaNodeId typeId;
	typeId.set(OpcUaId_SessionSecurityDiagnosticsDataType_Encoding_DefaultBinary);
	value1.typeId(typeId);
	value1.parameter<SessionSecurityDiagnosticsDataType>()->sessionId(sessionId);
	value1.parameter<SessionSecurityDiagnosticsDataType>()->clientUserIdOfSession(clientUserIdOfSession);
	value1.parameter<SessionSecurityDiagnosticsDataType>()->authenticationMechanism(authenticationMechanism);
	value1.parameter<SessionSecurityDiagnosticsDataType>()->encoding(encoding);
	value1.parameter<SessionSecurityDiagnosticsDataType>()->transportProtocol(transportProtocol);
	value1.parameter<SessionSecurityDiagnosticsDataType>()->securityMode(1);
	value1.parameter<SessionSecurityDiagnosticsDataType>()->securityPolicyUri(securityPolicyUri);
	value1.parameter<SessionSecurityDiagnosticsDataType>()->clientCertificate().value("abc", 3);

	value1.copyTo(value2);

	BOOST_REQUIRE(value2.parameter<SessionSecurityDiagnosticsDataType>()->sessionId() == sessionId);
	BOOST_REQUIRE(value2.parameter<SessionSecurityDiagnosticsDataType>()->clientUserIdOfSession() == clientUserIdOfSession);
	BOOST_REQUIRE(value2.parameter<SessionSecurityDiagnosticsDataType>()->authenticationMechanism() == authenticationMechanism);
	BOOST_REQUIRE(value2.parameter<SessionSecurityDiagnosticsDataType>()->encoding() == encoding);
	BOOST_REQUIRE(value2.parameter<SessionSecurityDiagnosticsDataType>()->transportProtocol() == transportProtocol);
	BOOST_REQUIRE(value2.parameter<SessionSecurityDiagnosticsDataType>()->securityMode() == 1);
	BOOST_REQUIRE(value2.parameter<SessionSecurityDiagnosticsDataType>()->securityPolicyUri() == securityPolicyUri);
	BOOST_REQUIRE(value2.parameter<SessionSecurityDiagnosticsDataType>()->clientCertificate().exist() == true);
}


BOOST_AUTO_TEST_SUITE_END()
