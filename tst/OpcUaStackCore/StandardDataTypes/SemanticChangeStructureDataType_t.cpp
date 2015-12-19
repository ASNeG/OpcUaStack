#include "unittest.h"
#include "OpcUaStackCore/Core/Core.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaIdentifier.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaExtensionObject.h"
#include "OpcUaStackCore/StandardDataTypes/SemanticChangeStructureDataType.h"

using namespace OpcUaStackCore;

BOOST_AUTO_TEST_SUITE(SemanticChangeStructureDataType_)

BOOST_AUTO_TEST_CASE(SemanticChangeStructureDataType_)
{
	std::cout << "SemanticChangeStructureDataType_t" << std::endl;
}

BOOST_AUTO_TEST_CASE(SemanticChangeStructureDataType_encode_decode)
{
	SemanticChangeStructureDataType value1;
	SemanticChangeStructureDataType value2;

	OpcUaNodeId nodeId1, nodeId2;
	nodeId1.nodeId((OpcUaInt32)11);
	nodeId2.nodeId((OpcUaInt32)12);

	value1.affected(nodeId1);
	value1.affectedType(nodeId2);

	std::stringstream ss;
	value1.opcUaBinaryEncode(ss);
	value2.opcUaBinaryDecode(ss);

	BOOST_REQUIRE(value2.affected() == nodeId1);
	BOOST_REQUIRE(value2.affectedType() == nodeId2);
}

BOOST_AUTO_TEST_CASE(SemanticChangeStructureDataType_ExtensionObject)
{
	Core core;
	core.init();

	OpcUaNodeId nodeId1, nodeId2;
	nodeId1.nodeId((OpcUaInt32)11);
	nodeId2.nodeId((OpcUaInt32)12);

	OpcUaExtensionObject value1;
	OpcUaExtensionObject value2;

	OpcUaNodeId typeId;
	typeId.set(OpcUaId_SemanticChangeStructureDataType_Encoding_DefaultBinary);
	value1.typeId(typeId);
	value1.parameter<SemanticChangeStructureDataType>()->affected(nodeId1);
	value1.parameter<SemanticChangeStructureDataType>()->affectedType(nodeId2);

	std::stringstream ss;
	value1.opcUaBinaryEncode(ss);
	value2.opcUaBinaryDecode(ss);

	BOOST_REQUIRE(value2.parameter<SemanticChangeStructureDataType>()->affected() == nodeId1);
	BOOST_REQUIRE(value2.parameter<SemanticChangeStructureDataType>()->affectedType() == nodeId2);
}

BOOST_AUTO_TEST_CASE(SemanticChangeStructureDataType_ExtensionObject_copyTo)
{
	Core core;
	core.init();

	OpcUaNodeId nodeId1, nodeId2;
	nodeId1.nodeId((OpcUaInt32)11);
	nodeId2.nodeId((OpcUaInt32)12);

	OpcUaExtensionObject value1;
	OpcUaExtensionObject value2;

	OpcUaNodeId typeId;
	typeId.set(OpcUaId_SemanticChangeStructureDataType_Encoding_DefaultBinary);
	value1.typeId(typeId);
	value1.parameter<SemanticChangeStructureDataType>()->affected(nodeId1);
	value1.parameter<SemanticChangeStructureDataType>()->affectedType(nodeId2);

	value1.copyTo(value2);

	BOOST_REQUIRE(value2.parameter<SemanticChangeStructureDataType>()->affected() == nodeId1);
	BOOST_REQUIRE(value2.parameter<SemanticChangeStructureDataType>()->affectedType() == nodeId2);
}


BOOST_AUTO_TEST_SUITE_END()



