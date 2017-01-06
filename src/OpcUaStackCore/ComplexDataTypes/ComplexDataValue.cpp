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

#include "OpcUaStackCore/ComplexDataTypes/ComplexDataValue.h"

namespace OpcUaStackCore
{

	ComplexDataValue::ComplexDataValue(void)
	: Object()
	, ExtensionObjectBase()
	, complexDataType_()
	, variantVec_()
	{
	}

	ComplexDataValue::~ComplexDataValue(void)
	{
	}

	ExtensionObjectBase::SPtr
	ComplexDataValue::factory(void)
	{
		ComplexDataValue::SPtr complexDataTypeValue = constructSPtr<ComplexDataValue>();
		complexDataTypeValue->complexDataType(complexDataType_);
		return complexDataTypeValue;
	}

	OpcUaNodeId
	ComplexDataValue::binaryTypeId(void)
	{
		if (!complexDataType_) {
			OpcUaNodeId tmp("Unknown-Type-Id");
			return tmp;
		}
		return complexDataType_->binaryTypeId();
	}

	OpcUaNodeId
	ComplexDataValue::xmlTypeId(void)
	{
		if (!complexDataType_) {
			OpcUaNodeId tmp("Unknown-Type-Id");
			return tmp;
		}
		return complexDataType_->xmlTypeId();
	}

	void
	ComplexDataValue::opcUaBinaryEncode(std::ostream& os) const
	{
		// FIXME: todo
	}

	void
	ComplexDataValue::opcUaBinaryDecode(std::istream& is)
	{
		// FIXME: todo
	}

	bool
	ComplexDataValue::encode(boost::property_tree::ptree& pt, Xmlns& xmlns) const
	{
		// FIXME: todo
		return true;
	}

	bool
	ComplexDataValue::decode(boost::property_tree::ptree& pt, Xmlns& xmlns)
	{
		// FIXME: too
		return true;
	}

	void
	ComplexDataValue::copyTo(ExtensionObjectBase& extensionObjectBase)
	{
		// FIXME: todo
	}

	bool
	ComplexDataValue::equal(ExtensionObjectBase& extensionObjectBase) const
	{
		// FIXME: todo
		return true;
	}

	void
	ComplexDataValue::out(std::ostream& os)
	{
		// FIXME: todo
	}

	void
	ComplexDataValue::complexDataType(ComplexDataType::SPtr& complexDataType)
	{
		complexDataType_ = complexDataType;
	}

	int32_t
	ComplexDataValue::name2Index(const std::string& name)
	{
		if (!complexDataType_) {
			return -1;
		}
		return complexDataType_->name2Index(name);
	}

	std::string
	ComplexDataValue::index2Name(uint32_t index)
	{
		if (!complexDataType_) {
			return "";
		}
		return complexDataType_->index2Name(index);
	}

	OpcUaVariant::SPtr
	ComplexDataValue::getValue(const std::string& itemName)
	{
		int32_t index = name2Index(itemName);
		if (index == -1) {
			OpcUaVariant::SPtr tmp;
			return tmp;
		}
		return variantVec_[index];
	}

	OpcUaVariant::SPtr
	ComplexDataValue::getValue(uint32_t itemIndex)
	{
		if (itemIndex >= variantVec_.size()) {
			OpcUaVariant::SPtr tmp;
			return tmp;
		}
		return variantVec_[itemIndex];
	}

	bool
	ComplexDataValue::setValue(const std::string& itemName, OpcUaVariant::SPtr& variant)
	{
		int32_t index = name2Index(itemName);
		if (index == -1) {
			return false;
		}
		variantVec_[index] = variant;
		return true;
	}

	bool
	ComplexDataValue::setValue(uint32_t itemIndex, OpcUaVariant::SPtr& variant)
	{
		if (itemIndex >= variantVec_.size()) {
			return false;
		}
		variantVec_[itemIndex] = variant;
		return true;
	}

}


