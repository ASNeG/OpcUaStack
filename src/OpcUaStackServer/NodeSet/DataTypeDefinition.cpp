/*
   Copyright 2017 Kai Huebl (kai@huebl-sgh.de)

   Lizenziert gemäß Apache Licence Version 2.0 (die „Lizenz“); Nutzung dieser
   Datei nur in Übereinstimmung mit der Lizenz erlaubt.
   Eine Kopie der Lizenz erhalten Sie auf http://www.apache.org/licenses/LICENSE-2.0.

   Sofern nicht gemäß geltendem Recht vorgeschrieben oder schriftlich vereinbart,
   erfolgt die Bereitstellung der im Rahmen der Lizenz verbreiteten Software OHNE
   GEWÄHR ODER VORBEHALTE – ganz gleich, ob ausdrücklich oder stillschweigend.

   Informationen über die jeweiligen Bedingungen für Genehmigungen und Einschränkungen
   im Rahmen der Lizenz finden Sie in der Lizenz.

   Autor: Kai Huebl (kai@huebl-sgh.de)
 */

#include "OpcUaStackServer/NodeSet/DataTypeDefinition.h"
#include "OpcUaStackCore/Base/Log.h"

using namespace OpcUaStackCore;

namespace OpcUaStackServer
{

	// ---------------------------------------------------------------------------
	// ---------------------------------------------------------------------------
	//
	// DataTypeElement
	//
	// ---------------------------------------------------------------------------
	// ---------------------------------------------------------------------------
	DataTypeDefinition::DataTypeDefinition(void)
	: dataSubType_(None)
	, nested_(false)
	, name_()
	, baseType_()
	, isUnion_(false)
	, dataFields_()
	{
	}

	DataTypeDefinition::~DataTypeDefinition(void)
	{
	}

	DataSubType
	DataTypeDefinition::dataSubType(void)
	{
		return dataSubType_;
	}

	void
	DataTypeDefinition::dataSubType(DataSubType dataSubType)
	{
		dataSubType_ = dataSubType;
	}

	OpcUaQualifiedName&
	DataTypeDefinition::name(void)
	{
		return name_;
	}

	void
	DataTypeDefinition::name(OpcUaQualifiedName& name)
	{
		name.copyTo(name_);
	}

	OpcUaQualifiedName&
	DataTypeDefinition::baseType(void)
	{
		return baseType_;
	}

	void
	DataTypeDefinition::baseType(OpcUaQualifiedName& baseType)
	{
		baseType.copyTo(baseType_);
	}

	OpcUaBoolean
	DataTypeDefinition::isUnion(void)
	{
		return isUnion_;
	}

	void
	DataTypeDefinition::isUnion(OpcUaBoolean isUnion)
	{
		isUnion_ = isUnion;
	}

	DataTypeField::Vec&
	DataTypeDefinition::dataFields(void)
	{
		return dataFields_;
	}

	void
	DataTypeDefinition::dataField(DataTypeField::SPtr& dataField)
	{
		dataFields_.push_back(dataField);
	}

	bool
	DataTypeDefinition::decode(boost::property_tree::ptree& ptree)
	{
		if (nested_) {
			// decode name
			boost::optional<std::string> name = ptree.get_optional<std::string>("<xmlattr>.Name");
			if (!name) {
				Log(Error, "missing attribute in data type definition")
					.parameter("Attribute", "Name");
				return false;
			}
			if (!name_.fromString(*name)) {
				Log(Error, "invalid attribute in data type definition")
					.parameter("Attribute", "Name")
					.parameter("Value", *name);
				return false;
			}

			// decode base type
			boost::optional<std::string> baseType = ptree.get_optional<std::string>("<xmlattr>.BaseType");
			if (baseType) {
				if (!baseType_.fromString(*name)) {
					Log(Error, "invalid attribute in data type definition")
						.parameter("Attribute", "BaseType")
						.parameter("Value", *baseType);
					return false;
				}
			}
		}

		// decode isUnion (default: false)
		boost::optional<std::string> isUnion = ptree.get_optional<std::string>("<xmlattr>.IsUnion");
		if (isUnion) {
			if (*isUnion == "true") {
				isUnion_ = true;
			}
			else {
				isUnion_ = false;
			}
		}

		// decode data type fields
		boost::property_tree::ptree::iterator it;
		for (it = ptree.begin(); it != ptree.end(); it++) {
			if (it->first != "Field") continue;

			DataTypeField::SPtr field = constructSPtr<DataTypeField>();
			if (!field->decode(it->second)) return false;
			dataFields_.push_back(field);
		}

		return false;
	}

	bool
	DataTypeDefinition::encode(boost::property_tree::ptree& ptree)
	{
		if (nested_) {

		}

		return false;
	}

	bool
	DataTypeDefinition::decode(boost::property_tree::ptree& ptree, Object::SPtr& dataTypeDefinition)
	{
		// FIXME: todo
		return false;
	}

	bool
	DataTypeDefinition::encode(boost::property_tree::ptree& ptree, Object::SPtr& dataTypeDefinition)
	{
		// FIXME: todo
		return false;
	}

}
