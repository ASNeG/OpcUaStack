#include "unittest.h"

#include "OpcUaStackCore/Base/ConfigXml.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaIdentifier.h"
#include "OpcUaStackCore/DataType/DataTypeDefinition.h"

using namespace OpcUaStackCore;

BOOST_AUTO_TEST_SUITE(DataTypeDefinition_)

BOOST_AUTO_TEST_CASE(DataTypeDefinition_)
{
	std::cout << "DataTypeDefinition_t" << std::endl;
}


BOOST_AUTO_TEST_CASE(DataTypeDefinition_read_Enum_Simple)
{
	bool success;

	// read opc ua nodeset
	ConfigXml configXml;
    success = configXml.parse("../tst/data/DataTypeDefinition.Enum.Simple.xml");
    BOOST_REQUIRE(success == true);

    // decode simple enum type
    DataTypeDefinition::SPtr definition = constructSPtr<DataTypeDefinition>();
    definition->dataSubType(Enumeration);
    success = definition->decode(configXml.ptree());

    BOOST_REQUIRE(success == true);
    BOOST_REQUIRE(definition->name() == OpcUaQualifiedName("EnumSimpleType",1));
    BOOST_REQUIRE(definition->dataFields().size() == 3);
    BOOST_REQUIRE(definition->dataFields()[0]->name().value() == "Enum1");
    BOOST_REQUIRE(definition->dataFields()[1]->name().value() == "Enum2");
    BOOST_REQUIRE(definition->dataFields()[2]->name().value() == "Enum3");
    BOOST_REQUIRE(definition->dataFields()[0]->value() == 0);
    BOOST_REQUIRE(definition->dataFields()[1]->value() == 1);
    BOOST_REQUIRE(definition->dataFields()[2]->value() == 2);
}

BOOST_AUTO_TEST_CASE(DataTypeDefinition_write_Enum_Simple)
{
	bool success;
	DataTypeDefinition::SPtr definition;
	DataTypeField::SPtr field;
	OpcUaQualifiedName dataTypeName;
	OpcUaString fieldName;

	//
	// create simple enumeration
	//
	definition = constructSPtr<DataTypeDefinition>();
	definition->dataSubType(Enumeration);
	dataTypeName.set("EnumSimpleType",1);
	definition->name(dataTypeName);

	field = constructSPtr<DataTypeField>();
	fieldName.value("Enum1");
	field->name(fieldName);
	field->value(0);
	definition->dataField(field);

	field = constructSPtr<DataTypeField>();
	fieldName.value("Enum2");
	field->name(fieldName);
	field->value(1);
	definition->dataField(field);

	field = constructSPtr<DataTypeField>();
	fieldName.value("Enum3");
	field->name(fieldName);
	field->value(2);
	definition->dataField(field);

	// encode and write eimple enum to file
	ConfigXml configXmlWrite;
	success = definition->encode(configXmlWrite.ptree());
	BOOST_REQUIRE(success == true);

	success = configXmlWrite.write("test.xml");
	BOOST_REQUIRE(success == true);

	//
	// read opc ua nodeset
	//
	ConfigXml configXmlRead;
    success = configXmlRead.parse("test.xml");
    BOOST_REQUIRE(success == true);

    // decode simple enum type
    definition = constructSPtr<DataTypeDefinition>();
    definition->dataSubType(Enumeration);
    success = definition->decode(configXmlRead.ptree());

    BOOST_REQUIRE(success == true);
    BOOST_REQUIRE(definition->name() == OpcUaQualifiedName("EnumSimpleType",1));
    BOOST_REQUIRE(definition->dataFields().size() == 3);
    BOOST_REQUIRE(definition->dataFields()[0]->name().value() == "Enum1");
    BOOST_REQUIRE(definition->dataFields()[1]->name().value() == "Enum2");
    BOOST_REQUIRE(definition->dataFields()[2]->name().value() == "Enum3");
    BOOST_REQUIRE(definition->dataFields()[0]->value() == 0);
    BOOST_REQUIRE(definition->dataFields()[1]->value() == 1);
    BOOST_REQUIRE(definition->dataFields()[2]->value() == 2);
}

BOOST_AUTO_TEST_CASE(DataTypeDefinition_read_Enum_Gap)
{
	bool success;

	// read opc ua nodeset
	ConfigXml configXml;
    success = configXml.parse("../tst/data/DataTypeDefinition.Enum.Gap.xml");
    BOOST_REQUIRE(success == true);

    // decode simple enum type
    DataTypeDefinition::SPtr definition = constructSPtr<DataTypeDefinition>();
    definition->dataSubType(Enumeration);
    success = definition->decode(configXml.ptree());

    BOOST_REQUIRE(success == true);
    BOOST_REQUIRE(definition->name() == OpcUaQualifiedName("EnumGapType",1));
    BOOST_REQUIRE(definition->dataFields().size() == 3);
    BOOST_REQUIRE(definition->dataFields()[0]->name().value() == "Enum1");
    BOOST_REQUIRE(definition->dataFields()[1]->name().value() == "Enum2");
    BOOST_REQUIRE(definition->dataFields()[2]->name().value() == "Enum3");
    BOOST_REQUIRE(definition->dataFields()[0]->value() == -1);
    BOOST_REQUIRE(definition->dataFields()[1]->value() == 1);
    BOOST_REQUIRE(definition->dataFields()[2]->value() == 7);
}

BOOST_AUTO_TEST_CASE(DataTypeDefinition_read_Structure_Simple)
{
	bool success;

	// read opc ua nodeset
	ConfigXml configXml;
    success = configXml.parse("../tst/data/DataTypeDefinition.Structure.Simple.xml");
    BOOST_REQUIRE(success == true);

    // decode simple enum type
    DataTypeDefinition::SPtr definition = constructSPtr<DataTypeDefinition>();
    definition->dataSubType(Structure);
    success = definition->decode(configXml.ptree());

    BOOST_REQUIRE(success == true);
    BOOST_REQUIRE(definition->name() == OpcUaQualifiedName("MyStructureType",1));
    BOOST_REQUIRE(definition->dataFields().size() == 3);
    BOOST_REQUIRE(definition->dataFields()[0]->name().value() == "Element1");
    BOOST_REQUIRE(definition->dataFields()[0]->isOptional() == false);
    BOOST_REQUIRE(definition->dataFields()[0]->dataType() == OpcUaNodeId(OpcUaBuildInType_OpcUaDouble));
    BOOST_REQUIRE(definition->dataFields()[0]->description() == OpcUaLocalizedText("", "todo"));
    BOOST_REQUIRE(definition->dataFields()[1]->name().value() == "Element2");
    BOOST_REQUIRE(definition->dataFields()[1]->isOptional() == false);
    BOOST_REQUIRE(definition->dataFields()[1]->dataType() == OpcUaNodeId(OpcUaBuildInType_OpcUaDouble));
    BOOST_REQUIRE(definition->dataFields()[1]->description() == OpcUaLocalizedText());
    BOOST_REQUIRE(definition->dataFields()[2]->name().value() == "Element3");
    BOOST_REQUIRE(definition->dataFields()[2]->isOptional() == true);
    BOOST_REQUIRE(definition->dataFields()[2]->dataType() == OpcUaNodeId(OpcUaBuildInType_OpcUaDouble));
    BOOST_REQUIRE(definition->dataFields()[2]->description() == OpcUaLocalizedText());
}

BOOST_AUTO_TEST_CASE(DataTypeDefinition_write_Structure_Simple)
{
	bool success;
	DataTypeDefinition::SPtr definition;
	DataTypeField::SPtr field;
	OpcUaQualifiedName dataTypeName;
	OpcUaString fieldName;
	OpcUaNodeId dataType;
	OpcUaLocalizedText description;

	//
	// create simple structure
	//
	definition = constructSPtr<DataTypeDefinition>();
	definition->dataSubType(Structure);
	dataTypeName.set("MyStructureType",1);
	definition->name(dataTypeName);

	field = constructSPtr<DataTypeField>();
	fieldName.value("Element1");
	field->name(fieldName);
	dataType.set(OpcUaBuildInType_OpcUaDouble);
	field->dataType(dataType);
	description.set("", "todo");
	field->description(description);
	definition->dataField(field);

	field = constructSPtr<DataTypeField>();
	fieldName.value("Element2");
	field->name(fieldName);
	dataType.set(OpcUaBuildInType_OpcUaDouble);
	field->dataType(dataType);
	definition->dataField(field);

	field = constructSPtr<DataTypeField>();
	fieldName.value("Element3");
	field->name(fieldName);
	dataType.set(OpcUaBuildInType_OpcUaDouble);
	field->dataType(dataType);
	field->isOptional(true);
	definition->dataField(field);

	// encode and write eimple enum to file
	ConfigXml configXmlWrite;
	success = definition->encode(configXmlWrite.ptree());
	BOOST_REQUIRE(success == true);


	//
	// read xml file
	//
	success = configXmlWrite.write("test.xml");
	BOOST_REQUIRE(success == true);

	ConfigXml configXml;
    success = configXml.parse("test.xml");
    BOOST_REQUIRE(success == true);

    // decode simple enum type
    definition = constructSPtr<DataTypeDefinition>();
    definition->dataSubType(Structure);
    success = definition->decode(configXml.ptree());

    BOOST_REQUIRE(success == true);
    BOOST_REQUIRE(definition->name() == OpcUaQualifiedName("MyStructureType",1));
    BOOST_REQUIRE(definition->dataFields().size() == 3);
    BOOST_REQUIRE(definition->dataFields()[0]->name().value() == "Element1");
    BOOST_REQUIRE(definition->dataFields()[0]->isOptional() == false);
    BOOST_REQUIRE(definition->dataFields()[0]->dataType() == OpcUaNodeId(OpcUaBuildInType_OpcUaDouble));
    BOOST_REQUIRE(definition->dataFields()[0]->description() == OpcUaLocalizedText("", "todo"));
    BOOST_REQUIRE(definition->dataFields()[1]->name().value() == "Element2");
    BOOST_REQUIRE(definition->dataFields()[1]->isOptional() == false);
    BOOST_REQUIRE(definition->dataFields()[1]->dataType() == OpcUaNodeId(OpcUaBuildInType_OpcUaDouble));
    BOOST_REQUIRE(definition->dataFields()[1]->description() == OpcUaLocalizedText());
    BOOST_REQUIRE(definition->dataFields()[2]->name().value() == "Element3");
    BOOST_REQUIRE(definition->dataFields()[2]->isOptional() == true);
    BOOST_REQUIRE(definition->dataFields()[2]->dataType() == OpcUaNodeId(OpcUaBuildInType_OpcUaDouble));
    BOOST_REQUIRE(definition->dataFields()[2]->description() == OpcUaLocalizedText());
}

BOOST_AUTO_TEST_CASE(DataTypeDefinition_read_Structure_Complex)
{
	bool success;

	// read opc ua nodeset
	ConfigXml configXml;
    success = configXml.parse("../tst/data/DataTypeDefinition.Structure.Complex.xml");
    BOOST_REQUIRE(success == true);

    // decode simple enum type
    DataTypeDefinition::SPtr definition = constructSPtr<DataTypeDefinition>();
    definition->dataSubType(Structure);
    success = definition->decode(configXml.ptree());

    BOOST_REQUIRE(success == true);
    BOOST_REQUIRE(definition->name() == OpcUaQualifiedName("MyStructureType",1));
    BOOST_REQUIRE(definition->dataFields().size() == 3);
    BOOST_REQUIRE(definition->dataFields()[0]->name().value() == "Element1");
    BOOST_REQUIRE(definition->dataFields()[0]->isOptional() == false);
    BOOST_REQUIRE(definition->dataFields()[0]->dataType() == OpcUaNodeId("MyType"));
    BOOST_REQUIRE(definition->dataFields()[0]->description() == OpcUaLocalizedText("", "todo"));
    BOOST_REQUIRE(definition->dataFields()[1]->name().value() == "Element2");
    BOOST_REQUIRE(definition->dataFields()[1]->isOptional() == false);
    BOOST_REQUIRE(definition->dataFields()[1]->dataType() == OpcUaNodeId(OpcUaBuildInType_OpcUaDouble));
    BOOST_REQUIRE(definition->dataFields()[1]->description() == OpcUaLocalizedText());
    BOOST_REQUIRE(definition->dataFields()[2]->name().value() == "Element3");
    BOOST_REQUIRE(definition->dataFields()[2]->isOptional() == true);
    BOOST_REQUIRE(definition->dataFields()[2]->dataType() == OpcUaNodeId(OpcUaBuildInType_OpcUaDouble));
    BOOST_REQUIRE(definition->dataFields()[2]->description() == OpcUaLocalizedText());
}

BOOST_AUTO_TEST_CASE(DataTypeDefinition_write_Structure_Complex)
{
	bool success;
	DataTypeDefinition::SPtr definition;
	DataTypeField::SPtr field;
	OpcUaQualifiedName dataTypeName;
	OpcUaString fieldName;
	OpcUaNodeId dataType;
	OpcUaLocalizedText description;

	//
	// create simple structure
	//
	definition = constructSPtr<DataTypeDefinition>();
	definition->dataSubType(Structure);
	dataTypeName.set("MyStructureType",1);
	definition->name(dataTypeName);

	field = constructSPtr<DataTypeField>();
	fieldName.value("Element1");
	field->name(fieldName);
	dataType.set("MyType");
	field->dataType(dataType);
	description.set("", "todo");
	field->description(description);
	definition->dataField(field);

	field = constructSPtr<DataTypeField>();
	fieldName.value("Element2");
	field->name(fieldName);
	dataType.set(OpcUaBuildInType_OpcUaDouble);
	field->dataType(dataType);
	definition->dataField(field);

	field = constructSPtr<DataTypeField>();
	fieldName.value("Element3");
	field->name(fieldName);
	dataType.set(OpcUaBuildInType_OpcUaDouble);
	field->dataType(dataType);
	field->isOptional(true);
	definition->dataField(field);

	// encode and write eimple enum to file
	ConfigXml configXmlWrite;
	success = definition->encode(configXmlWrite.ptree());
	BOOST_REQUIRE(success == true);

	success = configXmlWrite.write("test.xml");
	BOOST_REQUIRE(success == true);


	//
	// read xml file
	//
	ConfigXml configXml;
    success = configXml.parse("test.xml");
    BOOST_REQUIRE(success == true);

    // decode simple enum type
    definition = constructSPtr<DataTypeDefinition>();
    definition->dataSubType(Structure);
    success = definition->decode(configXml.ptree());

    BOOST_REQUIRE(success == true);
    BOOST_REQUIRE(definition->name() == OpcUaQualifiedName("MyStructureType",1));
    BOOST_REQUIRE(definition->dataFields().size() == 3);
    BOOST_REQUIRE(definition->dataFields()[0]->name().value() == "Element1");
    BOOST_REQUIRE(definition->dataFields()[0]->isOptional() == false);
    BOOST_REQUIRE(definition->dataFields()[0]->dataType() == OpcUaNodeId("MyType"));
    BOOST_REQUIRE(definition->dataFields()[0]->description() == OpcUaLocalizedText("", "todo"));
    BOOST_REQUIRE(definition->dataFields()[1]->name().value() == "Element2");
    BOOST_REQUIRE(definition->dataFields()[1]->isOptional() == false);
    BOOST_REQUIRE(definition->dataFields()[1]->dataType() == OpcUaNodeId(OpcUaBuildInType_OpcUaDouble));
    BOOST_REQUIRE(definition->dataFields()[1]->description() == OpcUaLocalizedText());
    BOOST_REQUIRE(definition->dataFields()[2]->name().value() == "Element3");
    BOOST_REQUIRE(definition->dataFields()[2]->isOptional() == true);
    BOOST_REQUIRE(definition->dataFields()[2]->dataType() == OpcUaNodeId(OpcUaBuildInType_OpcUaDouble));
    BOOST_REQUIRE(definition->dataFields()[2]->description() == OpcUaLocalizedText());
}

BOOST_AUTO_TEST_CASE(DataTypeDefinition_read_Structure_Nested)
{
	bool success;

	// read opc ua nodeset
	ConfigXml configXml;
    success = configXml.parse("../tst/data/DataTypeDefinition.Structure.Nested.xml");
    BOOST_REQUIRE(success == true);

    // decode simple enum type
    DataTypeDefinition::SPtr definition = constructSPtr<DataTypeDefinition>();
    definition->dataSubType(Structure);
    success = definition->decode(configXml.ptree());

    BOOST_REQUIRE(success == true);
    BOOST_REQUIRE(definition->name() == OpcUaQualifiedName("MyStructureType",1));
    BOOST_REQUIRE(definition->dataFields().size() == 3);
    BOOST_REQUIRE(definition->dataFields()[0]->name().value() == "Element1");
    BOOST_REQUIRE(definition->dataFields()[0]->isOptional() == false);
    BOOST_REQUIRE(definition->dataFields()[0]->dataType() == OpcUaNodeId(OpcUaBuildInType_OpcUaDouble));
    BOOST_REQUIRE(definition->dataFields()[1]->name().value() == "Element2");
    BOOST_REQUIRE(definition->dataFields()[1]->isOptional() == false);
    BOOST_REQUIRE(definition->dataFields()[2]->name().value() == "Element3");
    BOOST_REQUIRE(definition->dataFields()[2]->isOptional() == true);
    BOOST_REQUIRE(definition->dataFields()[2]->dataType() == OpcUaNodeId(OpcUaBuildInType_OpcUaDouble));

    definition = DataTypeDefinition::definition(definition->dataFields()[1]);
    BOOST_REQUIRE(definition->name() == OpcUaQualifiedName("MyNestedType",1));
    BOOST_REQUIRE(definition->dataFields().size() == 2);
    BOOST_REQUIRE(definition->dataFields()[0]->name().value() == "Element1");
    BOOST_REQUIRE(definition->dataFields()[0]->isOptional() == false);
    BOOST_REQUIRE(definition->dataFields()[0]->dataType() == OpcUaNodeId(OpcUaBuildInType_OpcUaDouble));
    BOOST_REQUIRE(definition->dataFields()[1]->name().value() == "Element2");
    BOOST_REQUIRE(definition->dataFields()[1]->isOptional() == false);
    BOOST_REQUIRE(definition->dataFields()[1]->dataType() == OpcUaNodeId(OpcUaBuildInType_OpcUaDouble));
}

BOOST_AUTO_TEST_CASE(DataTypeDefinition_write_Structure_Nested)
{
	bool success;
	DataTypeDefinition::SPtr definition;
	DataTypeDefinition::SPtr nestedDefinition;
	DataTypeField::SPtr field;
	OpcUaQualifiedName dataTypeName;
	OpcUaString fieldName;
	OpcUaNodeId dataType;

	//
	// create complex structure
	//
	nestedDefinition = constructSPtr<DataTypeDefinition>();
	nestedDefinition->dataSubType(Structure);
	dataTypeName.set("MyNestedType",1);
	nestedDefinition->name(dataTypeName);

	field = constructSPtr<DataTypeField>();
	fieldName.value("Element1");
	field->name(fieldName);
	dataType.set(OpcUaBuildInType_OpcUaDouble);
	field->dataType(dataType);
	nestedDefinition->dataField(field);

	field = constructSPtr<DataTypeField>();
	fieldName.value("Element2");
	field->name(fieldName);
	dataType.set(OpcUaBuildInType_OpcUaDouble);
	field->dataType(dataType);
	nestedDefinition->dataField(field);


	definition = constructSPtr<DataTypeDefinition>();
	definition->dataSubType(Structure);
	dataTypeName.set("MyStructureType",1);
	definition->name(dataTypeName);

	field = constructSPtr<DataTypeField>();
	fieldName.value("Element1");
	field->name(fieldName);
	dataType.set(OpcUaBuildInType_OpcUaDouble);
	field->dataType(dataType);
	definition->dataField(field);

	field = constructSPtr<DataTypeField>();
	fieldName.value("Element2");
	field->name(fieldName);
	Object::SPtr object = nestedDefinition;
	field->dataTypeDefinition(object);
	definition->dataField(field);

	field = constructSPtr<DataTypeField>();
	fieldName.value("Element3");
	field->name(fieldName);
	dataType.set(OpcUaBuildInType_OpcUaDouble);
	field->dataType(dataType);
	definition->dataField(field);

	// encode and write structure to file
	ConfigXml configXmlWrite;
	success = definition->encode(configXmlWrite.ptree());
	BOOST_REQUIRE(success == true);

	success = configXmlWrite.write("test.xml");
	BOOST_REQUIRE(success == true);

	// read opc ua nodeset
	ConfigXml configXml;
    success = configXml.parse("test.xml");
    BOOST_REQUIRE(success == true);

    // decode simple enum type
    definition = constructSPtr<DataTypeDefinition>();
    definition->dataSubType(Structure);
    success = definition->decode(configXml.ptree());

    BOOST_REQUIRE(success == true);
    BOOST_REQUIRE(definition->name() == OpcUaQualifiedName("MyStructureType",1));
    BOOST_REQUIRE(definition->dataFields().size() == 3);
    BOOST_REQUIRE(definition->dataFields()[0]->name().value() == "Element1");
    BOOST_REQUIRE(definition->dataFields()[0]->dataType() == OpcUaNodeId(OpcUaBuildInType_OpcUaDouble));
    BOOST_REQUIRE(definition->dataFields()[1]->name().value() == "Element2");
    BOOST_REQUIRE(definition->dataFields()[2]->name().value() == "Element3");
    BOOST_REQUIRE(definition->dataFields()[2]->dataType() == OpcUaNodeId(OpcUaBuildInType_OpcUaDouble));

    definition = DataTypeDefinition::definition(definition->dataFields()[1]);
    BOOST_REQUIRE(definition->name() == OpcUaQualifiedName("MyNestedType",1));
    BOOST_REQUIRE(definition->dataFields().size() == 2);
    BOOST_REQUIRE(definition->dataFields()[0]->name().value() == "Element1");
    BOOST_REQUIRE(definition->dataFields()[0]->dataType() == OpcUaNodeId(OpcUaBuildInType_OpcUaDouble));
    BOOST_REQUIRE(definition->dataFields()[1]->name().value() == "Element2");
    BOOST_REQUIRE(definition->dataFields()[1]->dataType() == OpcUaNodeId(OpcUaBuildInType_OpcUaDouble));
}

BOOST_AUTO_TEST_SUITE_END()


