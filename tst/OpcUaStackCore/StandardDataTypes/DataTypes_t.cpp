#include "unittest.h"
#include "boost/asio.hpp"
#include "OpcUaStackCore/Core/Core.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaIdentifier.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaExtensionObject.h"
#include "OpcUaStackCore/StandardDataTypes/EnumDefinitionExpand.h"
#include "OpcUaStackCore/StandardDataTypes/StructureDefinitionExpand.h"

using namespace OpcUaStackCore;

BOOST_AUTO_TEST_SUITE(DataTypes_)

BOOST_AUTO_TEST_CASE(DataTypes_)
{
	std::cout << "DataTypes_t" << std::endl;
}

BOOST_AUTO_TEST_CASE(DataTypes_StructureDefinitionExpand)
{
	StructureDefinitionExpand::SPtr structureTypeDefinition1 = boost::make_shared<StructureDefinitionExpand>();
	DataTypeDefinition::SPtr dataTypeDefinition = structureTypeDefinition1;

	BOOST_REQUIRE(dataTypeDefinition->typeId() == OpcUaNodeId((OpcUaUInt32)99,0));


	StructureDefinitionExpand::SPtr structureTypeDefinition2 = boost::static_pointer_cast<StructureDefinitionExpand>(dataTypeDefinition);
	BOOST_REQUIRE(structureTypeDefinition2->typeId() == OpcUaNodeId((OpcUaUInt32)99,0));
}

BOOST_AUTO_TEST_CASE(DataTypes_EnumDefinitionExpand)
{
	EnumDefinitionExpand::SPtr enumTypeDefinition1 = boost::make_shared<EnumDefinitionExpand>();
	DataTypeDefinition::SPtr dataTypeDefinition = enumTypeDefinition1;

	BOOST_REQUIRE(dataTypeDefinition->typeId() == OpcUaNodeId((OpcUaUInt32)100,0));


	EnumDefinitionExpand::SPtr enumTypeDefinition2 = boost::static_pointer_cast<EnumDefinitionExpand>(dataTypeDefinition);
	BOOST_REQUIRE(enumTypeDefinition2->typeId() == OpcUaNodeId((OpcUaUInt32)100,0));
}

BOOST_AUTO_TEST_SUITE_END()

