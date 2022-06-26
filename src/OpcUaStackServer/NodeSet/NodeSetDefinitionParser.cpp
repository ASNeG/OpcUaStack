/*
   Copyright 2018-2022 Kai Huebl (kai@huebl-sgh.de)

   Lizenziert gemäß Apache Licence Version 2.0 (die „Lizenz“); Nutzung dieser
   Datei nur in Übereinstimmung mit der Lizenz erlaubt.
   Eine Kopie der Lizenz erhalten Sie auf http://www.apache.org/licenses/LICENSE-2.0.

   Sofern nicht gemäß geltendem Recht vorgeschrieben oder schriftlich vereinbart,
   erfolgt die Bereitstellung der im Rahmen der Lizenz verbreiteten Software OHNE
   GEWÄHR ODER VORBEHALTE – ganz gleich, ob ausdrücklich oder stillschweigend.

   Informationen über die jeweiligen Bedingungen für Genehmigungen und Einschränkungen
   im Rahmen der Lizenz finden Sie in der Lizenz.

   Autor: Kai Huebl (kai@huebl-sgh.de)


  <xs:element name="Definition" type="DataTypeDefinition" minOccurs="0"></xs:element>

  <xs:complexType name="DataTypeDefinition">
    <xs:sequence>
      <xs:element name="Field" type="DataTypeField" minOccurs="0" maxOccurs="unbounded"></xs:element>
    </xs:sequence>
    <xs:attribute name="Name" type="QualifiedName" use="required"></xs:attribute>
    <xs:attribute name="SymbolicName" type="SymbolicName" use="optional" default=""></xs:attribute>
    <xs:attribute name="IsUnion" type="xs:boolean" use="optional" default="false"></xs:attribute>
    <xs:attribute name="IsOptionSet" type="xs:boolean" use="optional" default="false"></xs:attribute>

    <!-- BaseType is obsolete and no longer used. Left in for backwards compatibility. -->
    <xs:attribute name="BaseType" type="QualifiedName" use="optional" default=""></xs:attribute>
  </xs:complexType>

  <xs:complexType name="DataTypeField">
    <xs:sequence>
      <xs:element name="DisplayName" type="LocalizedText" minOccurs="0" maxOccurs="unbounded"></xs:element>
      <xs:element name="Description" type="LocalizedText" minOccurs="0" maxOccurs="unbounded"></xs:element>
      <xs:element name="Documentation" type="xs:string" minOccurs="0" maxOccurs="1"></xs:element>
    </xs:sequence>
    <xs:attribute name="Name" type="xs:string" use="required"></xs:attribute>
    <xs:attribute name="SymbolicName" type="SymbolicName" use="optional"></xs:attribute>
    <xs:attribute name="DataType" type="NodeId" default="i=24"></xs:attribute>
    <xs:attribute name="ValueRank" type="ValueRank" default="-1"></xs:attribute>
    <xs:attribute name="ArrayDimensions" type="ArrayDimensions" default=""></xs:attribute>
    <xs:attribute name="MaxStringLength" type="xs:unsignedInt" default="0"></xs:attribute>
    <xs:attribute name="Value" type="xs:int" default="-1"></xs:attribute>
    <xs:attribute name="IsOptional" type="xs:boolean" use="optional" default="false"></xs:attribute>
  </xs:complexType>

 */

#include <boost/make_shared.hpp>
#include <boost/date_time/date_facet.hpp>
#include <locale>
#include "OpcUaStackServer/NodeSet/NodeSetDefinitionParser.h"
#include "OpcUaStackCore/Base/Log.h"

using namespace OpcUaStackCore;

namespace OpcUaStackServer
{

	NodeSetDefinitionParser::NodeSetDefinitionParser(NodeSetAlias* nodeSetAlias)
	: nodeSetAlias_(nodeSetAlias)
	{
	}

	NodeSetDefinitionParser::~NodeSetDefinitionParser(void)
	{
	}

	bool
	NodeSetDefinitionParser::decode(
		boost::property_tree::ptree& ptreeValue,
		StructureDefinitionExpand::SPtr& structureDefinition,
		bool decodeDefinition
	)
	{
		// create new structure type definition structure
		if (structureDefinition.get() == nullptr) {
			structureDefinition = boost::make_shared<StructureDefinitionExpand>();
		}

		if (decodeDefinition) {
			// find Definition element
			auto tree = ptreeValue.get_child_optional("Definition");
			if (!tree) {
				Log(Error, "missing element in data type definition")
					.parameter("Element", "Definition");
				return false;
			}
			return decodeStructureDefinition(*tree, structureDefinition);
		}

		// decode structure definition
		return decodeStructureDefinition(ptreeValue, structureDefinition);
	}

	bool
	NodeSetDefinitionParser::encode(
		StructureDefinitionExpand::SPtr& structureDefinition,
		boost::property_tree::ptree& ptreeValue,
		bool encodeDefinition
	)
	{
		// encode structure definition
		boost::property_tree::ptree ptreeChild;
		if (!encodeStructureDefinition(structureDefinition, ptreeChild)) {
			return false;
		}

		if (encodeDefinition) {
			// added definition element
			ptreeValue.add_child("Definition", ptreeChild);
		}
		else {
			ptreeValue = ptreeChild;
		}

		return true;
	}

	bool
	NodeSetDefinitionParser::decode(
		boost::property_tree::ptree& ptreeValue,
		EnumDefinitionExpand::SPtr& enumDefinition,
		bool decodeDefinition
	)
	{
		// create new enum type definition structure
		if (enumDefinition.get() == nullptr) {
			enumDefinition = boost::make_shared<EnumDefinitionExpand>();
		}

		if (decodeDefinition) {
			// find Definition element
			boost::optional<boost::property_tree::ptree&> tree = ptreeValue.get_child_optional("Definition");
			if (!tree) {
				Log(Error, "missing element in data type definition")
					.parameter("Element", "Definition");
				return false;
			}
			return decodeEnumDefinition(*tree, enumDefinition);
		}

		// decode structure definition
		return decodeEnumDefinition(ptreeValue, enumDefinition);
	}

	bool
	NodeSetDefinitionParser::encode(
		EnumDefinitionExpand::SPtr& enumDefinition,
		boost::property_tree::ptree& ptreeValue,
		bool encodeDefinition
	)
	{
		// encode enum definition
		boost::property_tree::ptree ptreeChild;
		if (!encodeEnumDefinition(enumDefinition, ptreeChild)) {
			return false;
		}

		if (encodeDefinition) {
			// added definition element
			ptreeValue.add_child("Definition", ptreeChild);
		}
		else {
			ptreeValue = ptreeChild;
		}

		return true;
	}

	bool
	NodeSetDefinitionParser::decodeStructureDefinition(
		boost::property_tree::ptree& ptreeValue,
		StructureDefinitionExpand::SPtr& structureDefinition
	)
	{
		// decode Name attribute
		boost::optional<std::string> name = ptreeValue.get_optional<std::string>("<xmlattr>.Name");
		if (!name) {
			Log(Error, "missing attribute in structure type definition")
				.parameter("Attribute", "Name");
			return false;
		}
		structureDefinition->name(*name);

		// decode symbolic name attribute
		boost::optional<std::string> symbolicName = ptreeValue.get_optional<std::string>("<xmlattr>.SymbolicName");
        if (symbolicName) {
        	structureDefinition->symbolicName(*symbolicName);
        }

        // decode is union attribute
        boost::optional<std::string> isUnion = ptreeValue.get_optional<std::string>("<xmlattr>.IsUnion");
        if (isUnion && *isUnion == "true") {
        	structureDefinition->structureType(2);
        }
        else {
        	structureDefinition->structureType(0);
        }

        // decode is option attribute
        boost::optional<std::string> isOption = ptreeValue.get_optional<std::string>("<xmlattr>.IsOption");
        // nothing to do with this attribute

		// decode field elements
        StructureField::Vec structureFieldVec;
		boost::property_tree::ptree::iterator it;
		for (it = ptreeValue.begin(); it != ptreeValue.end(); it++) {
			if (it->first != "Field") continue;

			StructureField::SPtr structureField = boost::make_shared<StructureField>();
			if (!decodeStructureField(it->second, structureField)) {
				return false;
			}
			structureFieldVec.push_back(structureField);
		}

		if (structureFieldVec.size() == 0) {
			Log(Error, "missing element in structure type definition")
				.parameter("Element", "Field");
			return false;
		}

		structureDefinition->fields()->resize(structureFieldVec.size());
		structureDefinition->fields()->push_back_vec(structureFieldVec);

		return true;
	}

	bool
	NodeSetDefinitionParser::encodeStructureDefinition(
		StructureDefinitionExpand::SPtr& structureDefinition,
		boost::property_tree::ptree& ptreeValue
	)
	{
		// encode name attribute
		ptreeValue.put("<xmlattr>.Name", structureDefinition->name());

		// encode is union attribute
		if (structureDefinition->structureType() == 2) {
			ptreeValue.put("<xmlattr>.IsUnion", "true");
		}

		// encode field elements
		uint32_t size = structureDefinition->fields()->size();
		for (uint32_t idx = 0; idx<size; idx++) {
			StructureField::SPtr structureField;
			structureDefinition->fields()->get(idx, structureField);

			boost::property_tree::ptree ptreeChild;
			if (!encodeStructureField(structureField, ptreeChild)) {
				return false;
			}

			// added field element
			ptreeValue.add_child("Field", ptreeChild);
		}

		return true;
	}

	bool
	NodeSetDefinitionParser::decodeStructureField(
		boost::property_tree::ptree& ptreeValue,
		StructureField::SPtr& structureField
	)
	{
		// decode Name attribute
		boost::optional<std::string> name = ptreeValue.get_optional<std::string>("<xmlattr>.Name");
		if (!name) {
			Log(Error, "missing attribute in structure field")
				.parameter("Attribute", "Name");
			return false;
		}
		OpcUaString nameValue(*name);
		structureField->name() = nameValue;

		// decode symbolic name attribute
		boost::optional<std::string> symbolicName = ptreeValue.get_optional<std::string>("<xmlattr>.SymbolicName");

        // decode data type attribute
		boost::optional<std::string> dataType = ptreeValue.get_optional<std::string>("<xmlattr>.DataType");
		if (!dataType) {
			dataType = "i=24";
		}

		bool alias = false;
		if (nodeSetAlias_ != nullptr) {
			alias = nodeSetAlias_->map(*dataType, structureField->dataType());
		}
		if (alias == false) {
			if (!structureField->dataType().fromString(*dataType)) {
				Log(Error, "invalid attribute in structure field")
					.parameter("Attribute", "DataType")
					.parameter("Value", *dataType);
				return false;
			}
		}

		// decode value rank attribute
		boost::optional<int32_t> valueRank = ptreeValue.get_optional<int32_t>("<xmlattr>.ValueRank");
		if (!valueRank) {
			valueRank = -1;
		}
		structureField->valueRank() = *valueRank;

		// decode array dimension attribute

		// decode max string length attribute
		boost::optional<uint32_t> maxStringLength = ptreeValue.get_optional<uint32_t>("<xmlattr>.MaxStringLength");
		if (!maxStringLength) {
			maxStringLength = 0;
		}
		structureField->maxStringLength() = *maxStringLength;

		// decode value attribute
		boost::optional<int32_t> value = ptreeValue.get_optional<int32_t>("<xmlattr>.Value");

		// decode is optional attribute
        boost::optional<std::string> isOptional = ptreeValue.get_optional<std::string>("<xmlattr>.IsOptional");
        if (isOptional && *isOptional == "true") {
        	structureField->isOptional() = true;
        }
        else {
        	structureField->isOptional() =  false;
        }

        // decode description element
         boost::optional<std::string> description = ptreeValue.get_optional<std::string>("Description");
         if (description) {
        	 structureField->description() = OpcUaLocalizedText("", *description);
         }

		return true;
	}

	bool
	NodeSetDefinitionParser::encodeStructureField(
		StructureField::SPtr& structureField,
		boost::property_tree::ptree& ptreeValue
	)
	{
		// encode name attribute
		ptreeValue.put("<xmlattr>.Name", structureField->name());

		// encode data type attribute
		if (structureField->dataType() != OpcUaNodeId(24)) {
			ptreeValue.put("<xmlattr>.DataType", structureField->dataType().toString());
		}

		// encode value rank attribute
		if (structureField->valueRank() != -1) {
			ptreeValue.put("<xmlattr>.ValueRank", structureField->valueRank());
		}

		// encode array dimensions

		// encode max string length attribute
		if (structureField->maxStringLength() != 0) {
			ptreeValue.put("<xmlattr>.MaxStringLength", structureField->maxStringLength());
		}

		// encode is optional attribute
		if (structureField->isOptional()) {
			ptreeValue.put("<xmlattr>.IsOptional", "true");
		}

		// encode description element
		if (structureField->description().text().size() > 0) {
			ptreeValue.put("Description", structureField->description().text());
		}

		return true;
	}

	bool
	NodeSetDefinitionParser::decodeEnumDefinition(
		boost::property_tree::ptree& ptreeValue,
		EnumDefinitionExpand::SPtr& enumDefinition
	)
	{
		// decode Name attribute
		boost::optional<std::string> name = ptreeValue.get_optional<std::string>("<xmlattr>.Name");
		if (!name) {
			Log(Error, "missing attribute in enum type definition")
				.parameter("Attribute", "Name");
			return false;
		}
		enumDefinition->name(*name);

		// decode field elements
        EnumField::Vec enumFieldVec;
		boost::property_tree::ptree::iterator it;
		for (it = ptreeValue.begin(); it != ptreeValue.end(); it++) {
			if (it->first != "Field") continue;

			EnumField::SPtr enumField = boost::make_shared<EnumField>();
			if (!decodeEnumField(it->second, enumField)) {
				return false;
			}
			enumFieldVec.push_back(enumField);
		}

		if (enumFieldVec.size() == 0) {
			Log(Error, "missing element in enum type definition")
				.parameter("Element", "Field");
			return false;
		}

		enumDefinition->enumFields()->resize(enumFieldVec.size());
		enumDefinition->enumFields()->push_back_vec(enumFieldVec);

		return true;
	}

	bool
	NodeSetDefinitionParser::encodeEnumDefinition(
		EnumDefinitionExpand::SPtr& enumDefinition,
		boost::property_tree::ptree& ptreeValue
	)
	{
		// encode name attribute
		ptreeValue.put("<xmlattr>.Name", enumDefinition->name());

		// encode field elements
		uint32_t size = enumDefinition->enumFields()->size();
		for (uint32_t idx = 0; idx<size; idx++) {
			EnumField::SPtr enumField;
			enumDefinition->enumFields()->get(idx, enumField);

			boost::property_tree::ptree ptreeChild;
			if (!encodeEnumField(enumField, ptreeChild)) {
				return false;
			}

			// added field element
			ptreeValue.add_child("Field", ptreeChild);
		}

		return true;
	}

	bool
	NodeSetDefinitionParser::decodeEnumField(
		boost::property_tree::ptree& ptreeValue,
		EnumField::SPtr& enumField
	)
	{
		// decode Name attribute
		boost::optional<std::string> name = ptreeValue.get_optional<std::string>("<xmlattr>.Name");
		if (!name) {
			Log(Error, "missing attribute in enum field")
				.parameter("Attribute", "Name");
			return false;
		}
		OpcUaString nameValue(*name);
		enumField->name().value(nameValue);

		// decode value rank attribute
		boost::optional<int32_t> value = ptreeValue.get_optional<int32_t>("<xmlattr>.Value");
		if (!value) {
			value = -1;
		}
		enumField->value() = *value;

        // decode description element
         boost::optional<std::string> description = ptreeValue.get_optional<std::string>("Description");
         if (description) {
        	 enumField->description() = OpcUaLocalizedText("", *description);
         }

		return true;
	}

	bool
	NodeSetDefinitionParser::encodeEnumField(
		EnumField::SPtr& enumField,
		boost::property_tree::ptree& ptreeValue
	)
	{
		// encode name attribute
		ptreeValue.put("<xmlattr>.Name", enumField->name());

		// encode value  attribute
		if (enumField->value() != -1) {
			ptreeValue.put("<xmlattr>.Value", enumField->value());
		}

		// encode description element
		if (enumField->description().text().size() > 0) {
			ptreeValue.put("Description", enumField->description().text());
		}

		return true;
	}

}
