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

#include "OpcUaStackCore/EventDataTypes/BaseEventType.h"

namespace OpcUaStackCore
{

	BaseEventType::BaseEventType(void)
	: Object()
	, ExtensionObjectBase()
	, eventId_(constructSPtr<OpcUaByteString>())
	{
	}

	BaseEventType::~BaseEventType(void)
	{
	}

	ExtensionObjectBase::SPtr
	BaseEventType::factory(void)
	{
		BaseEventType::SPtr baseEventType = constructSPtr<BaseEventType>();
		return baseEventType;
	}

	OpcUaNodeId
	BaseEventType::binaryTypeId(void)
	{
		return OpcUaNodeId(2041);
	}

	OpcUaNodeId
	BaseEventType::xmlTypeId(void)
	{
		return OpcUaNodeId("Unknown-Type-Id");
	}

	void
	BaseEventType::opcUaBinaryEncode(std::ostream& os) const
	{
#if 0
		for (uint32_t idx = 0; idx < complexDataType_->size(); idx++) {
			OpcUaVariantValue::Vec& variantValueVec = variantVec_[idx]->variant();
			OpcUaBuildInType itemType = complexDataType_->complexDataTypeItemVec()[idx].itemType();

			if (variantValueVec.empty()) {
				return;
			}
			if (variantValueVec[0].variantType() != itemType) {
				return;
			}

			variantValueVec[0].opcUaBinaryEncode(os, itemType);
		}
#endif
	}

	void
	BaseEventType::opcUaBinaryDecode(std::istream& is)
	{
#if 0
		for (uint32_t idx = 0; idx < complexDataType_->size(); idx++) {
			OpcUaVariantValue::Vec variantValueVec;
			OpcUaBuildInType itemType = complexDataType_->complexDataTypeItemVec()[idx].itemType();
			OpcUaVariantValue variantValue;

			variantValueVec.push_back(variantValue);
			variantValueVec[0].opcUaBinaryDecode(is, itemType);

			variantVec_[idx]->variant(variantValueVec);
		}
#endif
	}

	bool
	BaseEventType::encode(boost::property_tree::ptree& pt, Xmlns& xmlns) const
	{
		return false;
	}

	bool
	BaseEventType::decode(boost::property_tree::ptree& pt, Xmlns& xmlns)
	{
		return false;
	}

	void
	BaseEventType::copyTo(ExtensionObjectBase& extensionObjectBase)
	{
		BaseEventType* dst = dynamic_cast<BaseEventType*>(&extensionObjectBase);
		copyTo(*dst);
	}

	bool
	BaseEventType::equal(ExtensionObjectBase& extensionObjectBase) const
	{
		BaseEventType* dst = dynamic_cast<BaseEventType*>(&extensionObjectBase);
		return *this == *dst;
	}

	void
	BaseEventType::out(std::ostream& os)
	{
#if 0
		os << "Name=" << complexDataType_->name();
		os << ", Type=" << complexDataType_->binaryTypeId();
		os << ", Value={";
		for (uint32_t idx = 0; idx < complexDataType_->size(); idx++) {
			if (idx != 0) os << ", ";
			os << complexDataType_->complexDataTypeItemVec()[idx].itemName() << "=";
			variantVec_[idx]->out(os);
		}
		os << "}";
#endif
	}

	void
	BaseEventType::copyTo(BaseEventType& baseEventType)
	{
#if 0
		for (uint32_t idx = 0; idx < complexDataType_->size(); idx++) {
			baseEventType.getValue(idx)->copyFrom(*variantVec_[idx]);
		}
#endif
	}

	bool
	BaseEventType::operator==(const BaseEventType& baseEventType) const
	{
#if 0
		BaseEventType* cdv = const_cast<BaseEventType*>(&baseEventType);
		for (uint32_t idx = 0; idx < complexDataType_->size(); idx++) {
		    if (!(*cdv->getValue(idx) == *variantVec_[idx])) {
		    	return false;
		    }
		}
#endif
		return true;
	}

}


