#include "unittest.h"
#include "OpcUaStackCore/Core/Core.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaIdentifier.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaExtensionObject.h"
#include "OpcUaStackCore/StandardDataTypes/RedundantServerDataType.h"

using namespace OpcUaStackCore;

BOOST_AUTO_TEST_SUITE(RedundantServerDataType_)

BOOST_AUTO_TEST_CASE(RedundantServerDataType_)
{
	std::cout << "RedundantServerDataType_t" << std::endl;
}

BOOST_AUTO_TEST_CASE(RedundantServerDataType_encode_decode)
{
	RedundantServerDataType value1;
	RedundantServerDataType value2;

	OpcUaString serverId("12345");

	value1.serverId(serverId);
	value1.serviceLevel((OpcUaByte)1);
	value1.serverState((OpcUaUInt32)2);

	std::stringstream ss;
	value1.opcUaBinaryEncode(ss);
	value2.opcUaBinaryDecode(ss);

	BOOST_REQUIRE(value2.serverId() == serverId);
	BOOST_REQUIRE(value2.serviceLevel() == (OpcUaByte)1);
	BOOST_REQUIRE(value2.serverState() == (OpcUaByte)2);
}

BOOST_AUTO_TEST_CASE(RedundantServerDataType_ExtensionObject)
{
	Core core;
	core.init();

	OpcUaExtensionObject value1;
	OpcUaExtensionObject value2;

	OpcUaString serverId("12345");

	OpcUaNodeId typeId;
	typeId.set(OpcUaId_RedundantServerDataType_Encoding_DefaultBinary);
	value1.typeId(typeId);
	value1.parameter<RedundantServerDataType>()->serverId(serverId);
	value1.parameter<RedundantServerDataType>()->serviceLevel((OpcUaByte)1);
	value1.parameter<RedundantServerDataType>()->serverState((OpcUaUInt32)2);

	std::stringstream ss;
	value1.opcUaBinaryEncode(ss);
	value2.opcUaBinaryDecode(ss);

	BOOST_REQUIRE(value2.parameter<RedundantServerDataType>()->serverId() == serverId);
	BOOST_REQUIRE(value2.parameter<RedundantServerDataType>()->serviceLevel() == (OpcUaByte)1);
	BOOST_REQUIRE(value2.parameter<RedundantServerDataType>()->serverState() == (OpcUaByte)2);
}

BOOST_AUTO_TEST_CASE(RedundantServerDataType_ExtensionObject_copyTo)
{
	Core core;
	core.init();

	OpcUaExtensionObject value1;
	OpcUaExtensionObject value2;

	OpcUaString serverId("12345");

	OpcUaNodeId typeId;
	typeId.set(OpcUaId_RedundantServerDataType_Encoding_DefaultBinary);
	value1.typeId(typeId);
	value1.parameter<RedundantServerDataType>()->serverId(serverId);
	value1.parameter<RedundantServerDataType>()->serviceLevel((OpcUaByte)1);
	value1.parameter<RedundantServerDataType>()->serverState((OpcUaUInt32)2);

	value1.copyTo(value2);

	BOOST_REQUIRE(value2.parameter<RedundantServerDataType>()->serverId() == serverId);
	BOOST_REQUIRE(value2.parameter<RedundantServerDataType>()->serviceLevel() == (OpcUaByte)1);
	BOOST_REQUIRE(value2.parameter<RedundantServerDataType>()->serverState() == (OpcUaByte)2);
}


BOOST_AUTO_TEST_SUITE_END()

