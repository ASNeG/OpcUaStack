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

#include <boost/lexical_cast.hpp>
#include "OpcUaStackCore/DataType/DataTypeField.h"
#include "OpcUaStackCore/Base/Log.h"

namespace OpcUaStackCore
{

	// ---------------------------------------------------------------------------
	// ---------------------------------------------------------------------------
	//
	// DataTypeElement
	//
	// ---------------------------------------------------------------------------
	// ---------------------------------------------------------------------------
	DataTypeField::DataTypeField(void)
	: dataTypeFieldIf_(nullptr)
	, dataSubType_(None)
	, name_()
	, dataType_()
	, valueRank_(-1)
	, description_()
	, dataTypeDefinition_()
	, value_(0)
	, isOptional_(false)
	{
	}

	DataTypeField::~DataTypeField(void)
	{
	}

	void
	DataTypeField::dataTypeFieldIf(DataTypeFieldIf* dataTypeFieldIf)
	{
		dataTypeFieldIf_ = dataTypeFieldIf;
	}

	DataSubType&
	DataTypeField::dataSubType(void)
	{
		return dataSubType_;
	}

	void
	DataTypeField::dataSubType(DataSubType& dataSubType)
	{
		dataSubType_ = dataSubType;
	}

	OpcUaString&
	DataTypeField::name(void)
	{
		return name_;
	}

	void
	DataTypeField::name(OpcUaString& name)
	{
		name.copyTo(name_);
	}

	OpcUaNodeId&
	DataTypeField::dataType(void)
	{
		return dataType_;
	}

	void
	DataTypeField::dataType(OpcUaNodeId& dataType)
	{
		dataType.copyTo(dataType_);
	}

	OpcUaInt32
	DataTypeField::valueRank(void)
	{
		return valueRank_;
	}

	void
	DataTypeField::valueRank(OpcUaInt32 valueRank)
	{
		valueRank_ = valueRank;
	}

	OpcUaLocalizedText&
	DataTypeField::description(void)
	{
		return description_;
	}

	void
	DataTypeField::description(OpcUaLocalizedText& description)
	{
		description.copyTo(description_);
	}

	Object::SPtr&
	DataTypeField::dataTypeDefinition(void)
	{
		return dataTypeDefinition_;
	}

	void
	DataTypeField::dataTypeDefinition(Object::SPtr& dataTypeDefinition)
	{
		dataTypeDefinition_ = dataTypeDefinition;
	}

	OpcUaInt32
	DataTypeField::value(void)
	{
		return value_;
	}

	void
	DataTypeField::value(OpcUaInt32 value)
	{
		value_ = value;
	}

	OpcUaBoolean
	DataTypeField::isOptional(void)
	{
		return isOptional_;
	}

	void
	DataTypeField::isOptional(OpcUaBoolean isOptional)
	{
		isOptional_ = isOptional;
	}

	bool
	DataTypeField::decode(boost::property_tree::ptree& ptree)
	{
		if (dataSubType_ == Structure) {
			return decodeStruct(ptree);
		}
		else if (dataSubType_ == Enumeration) {
			return decodeEnum(ptree);
		}
		return false;
	}

	bool
	DataTypeField::encode(boost::property_tree::ptree& ptree)
	{
		if (dataSubType_ == Structure) {
			return encodeStruct(ptree);
		}
		else if (dataSubType_ == Enumeration) {
			return encodeEnum(ptree);
		}
		return false;
	}

	bool
	DataTypeField::decodeEnum(boost::property_tree::ptree& ptree)
	{
		// decode name
		boost::optional<std::string> name = ptree.get_optional<std::string>("<xmlattr>.Name");
		if (!name) {
			Log(Error, "missing attribute in data type field")
				.parameter("Attribute", "Name");
			return false;
		}
		name_.value(*name);

		// decode description (optional)
		boost::optional<std::string> description = ptree.get_optional<std::string>("Description");
		if (description) {
			description_.locale("");
			description_.text(*description);
		}

		// decode value
		boost::optional<std::string> value = ptree.get_optional<std::string>("<xmlattr>.Value");
		if (!value) {
			Log(Error, "missing attribute in data type field")
				.parameter("Attribute", "Value");
			return false;
		}
		try {
			value_ = (OpcUaInt32)boost::lexical_cast<OpcUaUInt32>(*value);
		} catch(boost::bad_lexical_cast& e) {
			Log(Error, "invalid attribute in data type field")
				.parameter("Attribute", "Value")
				.parameter("Value", *value)
				.parameter("What", e.what());
			return false;
		}

		return true;
	}

	bool
	DataTypeField::decodeStruct(boost::property_tree::ptree& ptree)
	{
		// decode name
		boost::optional<std::string> name = ptree.get_optional<std::string>("<xmlattr>.Name");
		if (!name) {
			Log(Error, "missing attribute in data type field")
				.parameter("Attribute", "Name");
			return false;
		}
		name_.value(*name);

		// decode valueRank  (default: -1)
		boost::optional<std::string> valueRank = ptree.get_optional<std::string>("<xmlattr>.ValueRank");
		if (valueRank) {
			try {
				valueRank_ = (OpcUaInt32)boost::lexical_cast<OpcUaInt32>(*valueRank);
			} catch(boost::bad_lexical_cast& e) {
				Log(Error, "invalid attribute in data type field")
					.parameter("Attribute", "ValueRank")
					.parameter("Value", *valueRank)
					.parameter("What", e.what());
				return false;
			}
		}

		// decode description (optional)
		boost::optional<std::string> description = ptree.get_optional<std::string>("Description");
		if (description) {
			description_.fromString(*description);
		}

		// decode isOptional (default: false)
		boost::optional<std::string> isOptional = ptree.get_optional<std::string>("<xmlattr>.IsOptional");
		if (isOptional) {
			if (*isOptional == "true") {
				isOptional_ = true;
			}
			else {
				isOptional_ = false;
			}
		}

		// decode dataType or dataTypeDefinition
		boost::optional<std::string> dataType = ptree.get_optional<std::string>("<xmlattr>.DataType");
		if (dataType) {
			OpcUaBuildInType type = OpcUaBuildInTypeMap::string2BuildInType(*dataType);
			if (type != OpcUaBuildInType_Unknown) {
				dataType_.set((uint32_t)type);
			}
			else {
				if (!dataType_.fromString(*dataType)) {
					Log(Error, "invalid attribute in data type field")
						.parameter("Attribute", "DataType")
						.parameter("Value", *dataType);
					return false;
				}
			}
			return true;
		}

		boost::optional<boost::property_tree::ptree&> dataTypeDefinition = ptree.get_child_optional("Definition");
		if (!dataTypeDefinition) {
			Log(Error, "missing attribute in data type field")
				.parameter("Attribute", "DataType/Definition");
			return false;
		}

		if (dataTypeFieldIf_ == nullptr) return false;

		return dataTypeFieldIf_->decode(*dataTypeDefinition, dataTypeDefinition_);
	}

	bool
	DataTypeField::encodeEnum(boost::property_tree::ptree& ptree)
	{

		// decode name
		ptree.put("<xmlattr>.Name", name_.value());

		// decode description
		if (description_.text().size() > 0) {
			std::stringstream ss;

			if (description_.locale().value().size() > 0) {
				ss << description_.locale().value() << ",";
			}
			ss << description_.text().value();
			ptree.put("Description", ss.str());
		}

		// decode value
		std::stringstream ss;
		ss << value_;
		ptree.put("<xmlattr>.Value", ss.str());

		return true;
	}

	bool
	DataTypeField::encodeStruct(boost::property_tree::ptree& ptree)
	{
		// decode name
		ptree.put("<xmlattr>.Name", name_.value());

		// encode valueRank
		std::stringstream ss;
		ss << valueRank_;
		ptree.put("<xmlattr>.ValueRank", ss.str());

		// encode description (optional)
		if (description_.text().size() > 0) {
			ptree.put("Description", description_.text());
		}

		// encode isOptional
		if (isOptional_) {
			ptree.put("<xmlattr>.IsOptional", "true");
		}

		// encode dataType or dataTypeDefinition
		if (dataTypeDefinition_.get() != nullptr) {
			if (dataTypeFieldIf_ == nullptr) return false;

			boost::property_tree::ptree tree;
			if (!dataTypeFieldIf_->encode(tree, dataTypeDefinition_)) {
				return false;
			}

			ptree.add_child("Definition", tree.get_child("Definition"));
		}
		else {
			if (dataType_.namespaceIndex() == 0 && dataType_.nodeIdType() == OpcUaBuildInType_OpcUaUInt32) {
				OpcUaUInt32 id = dataType_.nodeId<OpcUaUInt32>();
				std::string typeString = OpcUaBuildInTypeMap::buildInType2String((OpcUaBuildInType)id);
				if (typeString == "Unknown") {
					ptree.put("<xmlattr>.DataType", dataType_.toString());
				}
				else {
					ptree.put("<xmlattr>.DataType", typeString);
				}
			}
			else {
				ptree.put("<xmlattr>.DataType", dataType_.toString());
			}
		}

		return true;
	}


}
