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

	ComplexDataValue::ComplexDataValue(ComplexDataType::SPtr& complexDataType)
	: Object()
	, ExtensionObjectBase()
	, complexDataType_()
	, variantVec_()
	, tmp_()
	{
		this->complexDataType(complexDataType);
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
			OpcUaBuildInType itemType = complexDataType_->complexDataTypeItemVec()[idx]->itemType();

			if (variantValueVec.empty()) {
				return;
			}
			if (variantValueVec[0].variantType() != itemType) {
				return;
			}

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
			OpcUaBuildInType itemType = complexDataType_->complexDataTypeItemVec()[idx]->itemType();
			OpcUaVariantValue variantValue;

			variantValueVec.push_back(variantValue);
			variantValueVec[0].opcUaBinaryDecode(is, itemType);

			variantVec_[idx]->variant(variantValueVec);
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

	bool
	ComplexDataValue::xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
	{
		// FIXME: todo
		return false;
	}

	bool
	ComplexDataValue::xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns)
	{
		// FIXME: todo
		return false;
	}

	bool
	ComplexDataValue::xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns)
	{
		// FIXME: todo
		return false;
	}

	void
	ComplexDataValue::copyTo(ExtensionObjectBase& extensionObjectBase)
	{
		ComplexDataValue* dst = dynamic_cast<ComplexDataValue*>(&extensionObjectBase);
		copyTo(*dst);
	}

	bool
	ComplexDataValue::equal(ExtensionObjectBase& extensionObjectBase) const
	{
		ComplexDataValue* dst = dynamic_cast<ComplexDataValue*>(&extensionObjectBase);
		return *this == *dst;
	}

	void
	ComplexDataValue::out(std::ostream& os)
	{
		os << "Name=" << complexDataType_->name();
		os << ", Type=" << complexDataType_->binaryTypeId();
		os << ", Value={";
		for (uint32_t idx = 0; idx < complexDataType_->size(); idx++) {
			if (idx != 0) os << ", ";
			os << complexDataType_->complexDataTypeItemVec()[idx]->itemName() << "=";
			variantVec_[idx]->out(os);
		}
		os << "}";
	}

	void
	ComplexDataValue::copyTo(ComplexDataValue& complexDataValue)
	{
		for (uint32_t idx = 0; idx < complexDataType_->size(); idx++) {
			complexDataValue.getValue(idx)->copyFrom(*variantVec_[idx]);
		}
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
		return true;
	}

	void
	ComplexDataValue::complexDataType(ComplexDataType::SPtr& complexDataType)
	{
		complexDataType_ = complexDataType;
		clearVariantValueVec();
		createVariantValueVec();
	}

	int32_t
	ComplexDataValue::size(void)
	{
		if (!complexDataType_) {
			return -1;
		}
		return complexDataType_->size();
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
		variantVec_.clear();
	}

	void
	ComplexDataValue::createVariantValueVec(void)
	{
		for (uint32_t idx = 0; idx < complexDataType_->size(); idx++) {
			OpcUaVariant::SPtr variant = constructSPtr<OpcUaVariant>();
			variantVec_.push_back(variant);
		}
	}

}


