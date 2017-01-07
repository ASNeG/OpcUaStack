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
	, tmp_()
	{
	}

	ComplexDataValue::~ComplexDataValue(void)
	{
		clearVariantValueVec();
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
		if (!complexDataType_) {
			return;
		}

		for (uint32_t idx = 0; idx < complexDataType_->size(); idx++) {
			OpcUaVariantValue::Vec& variantValueVec = variantVec_[idx]->variant();
			OpcUaBuildInType itemType = complexDataType_->complexDataTypeItemVec()[idx].itemType();

			if (variantValueVec.empty()) return;
			if (variantValueVec[0].variantType() != itemType) return;

			variantValueVec[0].opcUaBinaryEncode(os, itemType);
		}
	}

	void
	ComplexDataValue::opcUaBinaryDecode(std::istream& is)
	{
		if (!complexDataType_) {
			return;
		}

		for (uint32_t idx = 0; idx < complexDataType_->size(); idx++) {
			OpcUaVariantValue::Vec variantValueVec;
			OpcUaBuildInType itemType = complexDataType_->complexDataTypeItemVec()[idx].itemType();
			OpcUaVariantValue variantValue;

			variantValueVec.push_back(variantValue);
			variantValueVec[0].opcUaBinaryDecode(is, itemType);
		}
	}

	bool
	ComplexDataValue::encode(boost::property_tree::ptree& pt, Xmlns& xmlns) const
	{
		return false;
	}

	bool
	ComplexDataValue::decode(boost::property_tree::ptree& pt, Xmlns& xmlns)
	{
		return false;
	}

	void
	ComplexDataValue::copyTo(ExtensionObjectBase& extensionObjectBase)
	{
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
	ComplexDataValue::copyTo(ComplexDataValue& complexDataValue)
	{
		// FIXME: todo
	}

	bool
	ComplexDataValue::operator==(const ComplexDataValue& complexDataValue) const
	{
		ComplexDataValue* cdv = const_cast<ComplexDataValue*>(&complexDataValue);
		for (uint32_t idx = 0; idx < complexDataType_->size(); idx++) {
		    if (!(*cdv->getValue(idx) == *variantVec_[idx])) {
		    	return false;
		    }
		}
		return false;
	}

	void
	ComplexDataValue::complexDataType(ComplexDataType::SPtr& complexDataType)
	{
		complexDataType_ = complexDataType;
		clearVariantValueVec();
		createVariantValueVec();
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

	OpcUaVariant::SPtr&
	ComplexDataValue::getValue(const std::string& itemName)
	{
		int32_t index = name2Index(itemName);
		if (index == -1) {
			return tmp_;
		}
		return variantVec_[index];
	}

	OpcUaVariant::SPtr&
	ComplexDataValue::getValue(uint32_t itemIndex)
	{
		if (itemIndex >= variantVec_.size()) {
			return tmp_;
		}
		return variantVec_[itemIndex];
	}

	void
	ComplexDataValue::clearVariantValueVec(void)
	{
		for (uint32_t idx = 0; idx < complexDataType_->size(); idx++) {
			variantVec_[idx] = constructSPtr<OpcUaVariant>();
		}
	}

	void
	ComplexDataValue::createVariantValueVec(void)
	{
		variantVec_.clear();
	}

}


