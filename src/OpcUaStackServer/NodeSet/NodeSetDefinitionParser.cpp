/*
   Copyright 2018 Kai Huebl (kai@huebl-sgh.de)

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

#include <boost/date_time/date_facet.hpp>
#include <locale>
#include "OpcUaStackServer/NodeSet/NodeSetDefinitionParser.h"
#include "OpcUaStackCore/Base/Log.h"

//using namespace OpcUaStackCore;

namespace OpcUaStackServer
{

	NodeSetDefinitionParser::NodeSetDefinitionParser(void)
	{
	}

	NodeSetDefinitionParser::~NodeSetDefinitionParser(void)
	{
	}

	bool
	NodeSetDefinitionParser::decode(
		boost::property_tree::ptree& ptreeValue,
		StructureDefinition::SPtr& structureDefinition
	)
	{
		// create new structure type definition structure
		structureDefinition = constructSPtr<StructureDefinition>();

		// find Definition element
		boost::optional<boost::property_tree::ptree&> tree = ptreeValue.get_child_optional("Definition");
		if (!tree) {
			Log(Error, "missing element in data type definition")
				.parameter("Element", "Definition");
			return false;
		}
		ptreeValue = *tree;

		// find Name attribute
		boost::optional<std::string> name = ptreeValue.get_optional<std::string>("<xmlattr>.Name");
		if (!name) {
			Log(Error, "missing attribute in data type definition")
				.parameter("Attribute", "Name");
			return false;
		}
		structureDefinition->name(*name);

		// find symbolic name attribute
		boost::optional<std::string> symbolicName = ptreeValue.get_optional<std::string>("<xmlattr>.SymbolicName");
        if (symbolicName) {
        	structureDefinition->symbolicName(*symbolicName);
        }

        // find is union attribute
        boost::optional<std::string> isUnion = ptreeValue.get_optional<std::string>("<xmlattr>.IsUnion");
        if (isUnion && *isUnion == "true") {
        	structureDefinition->structureType(2);
        }
        else {
        	structureDefinition->structureType(0);
        }

        // find is option attribute
        boost::optional<std::string> isOption = ptreeValue.get_optional<std::string>("<xmlattr>.IsOption");
        // nothing to do with this attribute

		// find field elements
        StructureField::Vec structureFieldVec;
		boost::property_tree::ptree::iterator it;
		for (it = ptreeValue.begin(); it != ptreeValue.end(); it++) {
			if (it->first != "Field") continue;

			StructureField::SPtr field = constructSPtr<StructureField>();
			//field->dataSubType(dataSubType_);
			//field->dataTypeFieldIf(this);
			//if (!field->decode(it->second)) {
			//	return false;
			//}
			//dataFields_.push_back(field);
		}

		// FIXME: todo
		return true;
	}

	bool
	NodeSetDefinitionParser::encode(
		StructureDefinition::SPtr& structureDefinition,
		boost::property_tree::ptree& ptreeValue
	)
	{
		// FIXME: todo
		return true;
	}

	bool
	NodeSetDefinitionParser::decodeStructureDefinition(
		boost::property_tree::ptree& ptreeValue,
		StructureDefinition::SPtr& structureDefinition
	)
	{
		// FIXME: todo
		return true;
	}

	bool
	NodeSetDefinitionParser::decodeStructureField(
		boost::property_tree::ptree& ptreeValue,
		StructureField::SPtr& structureField
	)
	{
		// FIXME: todo
		return true;
	}


}
