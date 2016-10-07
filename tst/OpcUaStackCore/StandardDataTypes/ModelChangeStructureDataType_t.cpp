#include "unittest.h"
#include "OpcUaStackCore/Core/Core.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaIdentifier.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaExtensionObject.h"
#include "OpcUaStackCore/StandardDataTypes/ModelChangeStructureDataType.h"

using namespace OpcUaStackCore;

BOOST_AUTO_TEST_SUITE(ModelChangeStructureDataType_)

BOOST_AUTO_TEST_CASE(ModelChangeStructureDataType_)
{
	std::cout << "ModelChangeStructureDataType_t" << std::endl;
}

BOOST_AUTO_TEST_CASE(ModelChangeStructureDataType_encode_decode)
{
	ModelChangeStructureDataType value1;
	ModelChangeStructureDataType value2;

	OpcUaNodeId nodeId1, nodeId2;
	nodeId1.nodeId((OpcUaInt32)11);
	nodeId2.nodeId((OpcUaInt32)12);

	value1.affected(nodeId1);
	value1.affectedType(nodeId2);
	value1.verb((OpcUaByte)1);

	std::stringstream ss;
	value1.opcUaBinaryEncode(ss);
	value2.opcUaBinaryDecode(ss);

	BOOST_REQUIRE(value2.affected() == nodeId1);
	BOOST_REQUIRE(value2.affectedType() == nodeId2);
	BOOST_REQUIRE(value2.verb() == (OpcUaByte)1);
}

BOOST_AUTO_TEST_CASE(ModelChangeStructureDataType_ExtensionObject)
{
	Core core;
	core.init();

	OpcUaExtensionObject value1;
	OpcUaExtensionObject value2;

	OpcUaNodeId nodeId1, nodeId2;
	nodeId1.nodeId((OpcUaInt32)11);
	nodeId2.nodeId((OpcUaInt32)12);

	OpcUaNodeId typeId;
	typeId.set(OpcUaId_ModelChangeStructureDataType_Encoding_DefaultBinary);
	value1.typeId(typeId);
	value1.parameter<ModelChangeStructureDataType>()->affected(nodeId1);
	value1.parameter<ModelChangeStructureDataType>()->affectedType(nodeId2);
	value1.parameter<ModelChangeStructureDataType>()->verb((OpcUaByte)1);

	std::stringstream ss;
	value1.opcUaBinaryEncode(ss);
	value2.opcUaBinaryDecode(ss);

	BOOST_REQUIRE(value2.parameter<ModelChangeStructureDataType>()->affected() == nodeId1);
	BOOST_REQUIRE(value2.parameter<ModelChangeStructureDataType>()->affectedType() == nodeId2);
	BOOST_REQUIRE(value2.parameter<ModelChangeStructureDataType>()->verb() == (OpcUaByte)1);
}

BOOST_AUTO_TEST_CASE(ModelChangeStructureDataType_ExtensionObject_copyTo)
{
	Core core;
	core.init();

	OpcUaExtensionObject value1;
	OpcUaExtensionObject value2;

	OpcUaNodeId nodeId1, nodeId2;
	nodeId1.nodeId((OpcUaInt32)11);
	nodeId2.nodeId((OpcUaInt32)12);

	OpcUaNodeId typeId;
	typeId.set(OpcUaId_ModelChangeStructureDataType_Encoding_DefaultBinary);
	value1.typeId(typeId);
	value1.parameter<ModelChangeStructureDataType>()->affected(nodeId1);
	value1.parameter<ModelChangeStructureDataType>()->affectedType(nodeId2);
	value1.parameter<ModelChangeStructureDataType>()->verb((OpcUaByte)1);

	value1.copyTo(value2);

	BOOST_REQUIRE(value2.parameter<ModelChangeStructureDataType>()->affected() == nodeId1);
	BOOST_REQUIRE(value2.parameter<ModelChangeStructureDataType>()->affectedType() == nodeId2);
	BOOST_REQUIRE(value2.parameter<ModelChangeStructureDataType>()->verb() == (OpcUaByte)1);
}


BOOST_AUTO_TEST_SUITE_END()

