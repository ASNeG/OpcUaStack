/*
   Copyright 2015-2019 Kai Huebl (kai@huebl-sgh.de)

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

#include "OpcUaStackCore/BuildInTypes/OpcUaDataValue.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaStatus.h"
#include "OpcUaStackCore/Base/Utility.h"

namespace OpcUaStackCore
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// OpcUaDataValue
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	OpcUaDataValue::OpcUaDataValue(void)
	:  Object()
	, opcUaVariantSPtr_()
	, opcUaStatusCode_()
	, sourceTimestamp_()		
	, sourcePicoseconds_(0)
	, serverTimestamp_()
	, serverPicoseconds_(0)
	{
	}

	OpcUaDataValue::OpcUaDataValue(const OpcUaDataValue& value)
	:  Object()
	, opcUaVariantSPtr_()
	, opcUaStatusCode_()
	, sourceTimestamp_()
	, sourcePicoseconds_(0)
	, serverTimestamp_()
	, serverPicoseconds_(0)
	{
		const_cast<OpcUaDataValue*>(&value)->copyTo(*this);
	}

	OpcUaDataValue::OpcUaDataValue(const OpcUaNullValue& value, OpcUaStatusCode statusCode, const OpcUaDateTime& sourceTimestamp)
	:  Object()
	, opcUaVariantSPtr_()
	, opcUaStatusCode_(statusCode)
	, sourceTimestamp_(sourceTimestamp)
	, sourcePicoseconds_(0)
	, serverTimestamp_()
	, serverPicoseconds_(0)
	{
	}

	OpcUaDataValue::OpcUaDataValue(const OpcUaBoolean& value, OpcUaStatusCode statusCode, const OpcUaDateTime& sourceTimestamp)
	:  Object()
	, opcUaVariantSPtr_()
	, opcUaStatusCode_(statusCode)
	, sourceTimestamp_(sourceTimestamp)
	, sourcePicoseconds_(0)
	, serverTimestamp_()
	, serverPicoseconds_(0)
	{
		variant()->setValue(value);
	}

	OpcUaDataValue::OpcUaDataValue(const OpcUaByte& value, OpcUaStatusCode statusCode, const OpcUaDateTime& sourceTimestamp)
	:  Object()
	, opcUaVariantSPtr_()
	, opcUaStatusCode_(statusCode)
	, sourceTimestamp_(sourceTimestamp)
	, sourcePicoseconds_(0)
	, serverTimestamp_()
	, serverPicoseconds_(0)
	{
		variant()->setValue(value);
	}

	OpcUaDataValue::OpcUaDataValue(const OpcUaSByte& value, OpcUaStatusCode statusCode, const OpcUaDateTime& sourceTimestamp)
	:  Object()
	, opcUaVariantSPtr_()
	, opcUaStatusCode_(statusCode)
	, sourceTimestamp_(sourceTimestamp)
	, sourcePicoseconds_(0)
	, serverTimestamp_()
	, serverPicoseconds_(0)
	{
		variant()->setValue(value);
	}

	OpcUaDataValue::OpcUaDataValue(const OpcUaInt16& value, OpcUaStatusCode statusCode, const OpcUaDateTime& sourceTimestamp)
	:  Object()
	, opcUaVariantSPtr_()
	, opcUaStatusCode_(statusCode)
	, sourceTimestamp_(sourceTimestamp)
	, sourcePicoseconds_(0)
	, serverTimestamp_()
	, serverPicoseconds_(0)
	{
		variant()->setValue(value);
	}

	OpcUaDataValue::OpcUaDataValue(const OpcUaUInt16& value, OpcUaStatusCode statusCode, const OpcUaDateTime& sourceTimestamp)
	:  Object()
	, opcUaVariantSPtr_()
	, opcUaStatusCode_(statusCode)
	, sourceTimestamp_(sourceTimestamp)
	, sourcePicoseconds_(0)
	, serverTimestamp_()
	, serverPicoseconds_(0)
	{
		variant()->setValue(value);
	}

	OpcUaDataValue::OpcUaDataValue(const OpcUaInt32& value, OpcUaStatusCode statusCode, const OpcUaDateTime& sourceTimestamp)
	:  Object()
	, opcUaVariantSPtr_()
	, opcUaStatusCode_(statusCode)
	, sourceTimestamp_(sourceTimestamp)
	, sourcePicoseconds_(0)
	, serverTimestamp_()
	, serverPicoseconds_(0)
	{
		variant()->setValue(value);
	}

	OpcUaDataValue::OpcUaDataValue(const OpcUaUInt32& value, OpcUaStatusCode statusCode, const OpcUaDateTime& sourceTimestamp)
	:  Object()
	, opcUaVariantSPtr_()
	, opcUaStatusCode_(statusCode)
	, sourceTimestamp_(sourceTimestamp)
	, sourcePicoseconds_(0)
	, serverTimestamp_()
	, serverPicoseconds_(0)
	{
		variant()->setValue(value);
	}

	OpcUaDataValue::OpcUaDataValue(const OpcUaInt64& value, OpcUaStatusCode statusCode, const OpcUaDateTime& sourceTimestamp)
	:  Object()
	, opcUaVariantSPtr_()
	, opcUaStatusCode_(statusCode)
	, sourceTimestamp_(sourceTimestamp)
	, sourcePicoseconds_(0)
	, serverTimestamp_()
	, serverPicoseconds_(0)
	{
		variant()->setValue(value);
	}

	OpcUaDataValue::OpcUaDataValue(const OpcUaUInt64& value, OpcUaStatusCode statusCode, const OpcUaDateTime& sourceTimestamp)
	:  Object()
	, opcUaVariantSPtr_()
	, opcUaStatusCode_(statusCode)
	, sourceTimestamp_(sourceTimestamp)
	, sourcePicoseconds_(0)
	, serverTimestamp_()
	, serverPicoseconds_(0)
	{
		variant()->setValue(value);
	}

	OpcUaDataValue::OpcUaDataValue(const OpcUaFloat& value, OpcUaStatusCode statusCode, const OpcUaDateTime& sourceTimestamp)
	:  Object()
	, opcUaVariantSPtr_()
	, opcUaStatusCode_(statusCode)
	, sourceTimestamp_(sourceTimestamp)
	, sourcePicoseconds_(0)
	, serverTimestamp_()
	, serverPicoseconds_(0)
	{
		variant()->setValue(value);
	}

	OpcUaDataValue::OpcUaDataValue(const OpcUaDouble& value, OpcUaStatusCode statusCode, const OpcUaDateTime& sourceTimestamp)
	:  Object()
	, opcUaVariantSPtr_()
	, opcUaStatusCode_(statusCode)
	, sourceTimestamp_(sourceTimestamp)
	, sourcePicoseconds_(0)
	, serverTimestamp_()
	, serverPicoseconds_(0)
	{
		variant()->setValue(value);
	}

	OpcUaDataValue::OpcUaDataValue(const OpcUaString& value, OpcUaStatusCode statusCode, const OpcUaDateTime& sourceTimestamp)
	:  Object()
	, opcUaVariantSPtr_()
	, opcUaStatusCode_(statusCode)
	, sourceTimestamp_(sourceTimestamp)
	, sourcePicoseconds_(0)
	, serverTimestamp_()
	, serverPicoseconds_(0)
	{
		variant()->setValue(value);
	}

	OpcUaDataValue::OpcUaDataValue(const OpcUaDateTime& value, OpcUaStatusCode statusCode, const OpcUaDateTime& sourceTimestamp)
	:  Object()
	, opcUaVariantSPtr_()
	, opcUaStatusCode_(statusCode)
	, sourceTimestamp_(sourceTimestamp)
	, sourcePicoseconds_(0)
	, serverTimestamp_()
	, serverPicoseconds_(0)
	{
		variant()->setValue(value);
	}

	OpcUaDataValue::OpcUaDataValue(const OpcUaGuid& value, OpcUaStatusCode statusCode, const OpcUaDateTime& sourceTimestamp)
	:  Object()
	, opcUaVariantSPtr_()
	, opcUaStatusCode_(statusCode)
	, sourceTimestamp_(sourceTimestamp)
	, sourcePicoseconds_(0)
	, serverTimestamp_()
	, serverPicoseconds_(0)
	{
		variant()->setValue(value);
	}

	OpcUaDataValue::OpcUaDataValue(const OpcUaByteString& value, OpcUaStatusCode statusCode, const OpcUaDateTime& sourceTimestamp)
	:  Object()
	, opcUaVariantSPtr_()
	, opcUaStatusCode_(statusCode)
	, sourceTimestamp_(sourceTimestamp)
	, sourcePicoseconds_(0)
	, serverTimestamp_()
	, serverPicoseconds_(0)
	{
		variant()->setValue(value);
	}

	OpcUaDataValue::OpcUaDataValue(const OpcUaXmlElement& value, OpcUaStatusCode statusCode, const OpcUaDateTime& sourceTimestamp)
	:  Object()
	, opcUaVariantSPtr_()
	, opcUaStatusCode_(statusCode)
	, sourceTimestamp_(sourceTimestamp)
	, sourcePicoseconds_(0)
	, serverTimestamp_()
	, serverPicoseconds_(0)
	{
		variant()->setValue(value);
	}

	OpcUaDataValue::OpcUaDataValue(const OpcUaNodeId& value, OpcUaStatusCode statusCode, const OpcUaDateTime& sourceTimestamp)
	:  Object()
	, opcUaVariantSPtr_()
	, opcUaStatusCode_(statusCode)
	, sourceTimestamp_(sourceTimestamp)
	, sourcePicoseconds_(0)
	, serverTimestamp_()
	, serverPicoseconds_(0)
	{
		variant()->setValue(value);
	}

	OpcUaDataValue::OpcUaDataValue(const OpcUaExpandedNodeId& value, OpcUaStatusCode statusCode, const OpcUaDateTime& sourceTimestamp)
	:  Object()
	, opcUaVariantSPtr_()
	, opcUaStatusCode_(statusCode)
	, sourceTimestamp_(sourceTimestamp)
	, sourcePicoseconds_(0)
	, serverTimestamp_()
	, serverPicoseconds_(0)
	{
		variant()->setValue(value);
	}

	OpcUaDataValue::OpcUaDataValue(const OpcUaStatusCode& value, OpcUaStatusCode statusCode, const OpcUaDateTime& sourceTimestamp)
	:  Object()
	, opcUaVariantSPtr_()
	, opcUaStatusCode_(statusCode)
	, sourceTimestamp_(sourceTimestamp)
	, sourcePicoseconds_(0)
	, serverTimestamp_()
	, serverPicoseconds_(0)
	{
		variant()->setValue(value);
	}

	OpcUaDataValue::OpcUaDataValue(const OpcUaQualifiedName& value, OpcUaStatusCode statusCode, const OpcUaDateTime& sourceTimestamp)
	:  Object()
	, opcUaVariantSPtr_()
	, opcUaStatusCode_(statusCode)
	, sourceTimestamp_(sourceTimestamp)
	, sourcePicoseconds_(0)
	, serverTimestamp_()
	, serverPicoseconds_(0)
	{
		variant()->setValue(value);
	}

	OpcUaDataValue::OpcUaDataValue(const OpcUaLocalizedText& value, OpcUaStatusCode statusCode, const OpcUaDateTime& sourceTimestamp)
	:  Object()
	, opcUaVariantSPtr_()
	, opcUaStatusCode_(statusCode)
	, sourceTimestamp_(sourceTimestamp)
	, sourcePicoseconds_(0)
	, serverTimestamp_()
	, serverPicoseconds_(0)
	{
		variant()->setValue(value);
	}

	OpcUaDataValue::OpcUaDataValue(const OpcUaExtensionObject& value, OpcUaStatusCode statusCode, const OpcUaDateTime& sourceTimestamp)
	:  Object()
	, opcUaVariantSPtr_()
	, opcUaStatusCode_(statusCode)
	, sourceTimestamp_(sourceTimestamp)
	, sourcePicoseconds_(0)
	, serverTimestamp_()
	, serverPicoseconds_(0)
	{
		variant()->setValue(value);
	}

	OpcUaDataValue::OpcUaDataValue(const OpcUaBooleanArray& value, OpcUaStatusCode statusCode, const OpcUaDateTime& sourceTimestamp)
	:  Object()
	, opcUaVariantSPtr_(constructSPtr<OpcUaVariant>())
	, opcUaStatusCode_(statusCode)
	, sourceTimestamp_(sourceTimestamp)
	, sourcePicoseconds_(0)
	, serverTimestamp_()
	, serverPicoseconds_(0)
	{
		for (uint32_t idx = 0; idx < value.size(); idx++) {
			OpcUaBoolean val;
			const_cast<OpcUaBooleanArray*>(&value)->get(idx, val);
			opcUaVariantSPtr_->pushBack(val);
		}
	}

	OpcUaDataValue::OpcUaDataValue(const OpcUaByteArray& value, OpcUaStatusCode statusCode, const OpcUaDateTime& sourceTimestamp)
	:  Object()
	, opcUaVariantSPtr_(constructSPtr<OpcUaVariant>())
	, opcUaStatusCode_(statusCode)
	, sourceTimestamp_(sourceTimestamp)
	, sourcePicoseconds_(0)
	, serverTimestamp_()
	, serverPicoseconds_(0)
	{
		for (uint32_t idx = 0; idx < value.size(); idx++) {
			OpcUaByte val;
			const_cast<OpcUaByteArray*>(&value)->get(idx, val);
			opcUaVariantSPtr_->pushBack(val);
		}
	}

	OpcUaDataValue::OpcUaDataValue(const OpcUaSByteArray& value, OpcUaStatusCode statusCode, const OpcUaDateTime& sourceTimestamp)
	:  Object()
	, opcUaVariantSPtr_(constructSPtr<OpcUaVariant>())
	, opcUaStatusCode_(statusCode)
	, sourceTimestamp_(sourceTimestamp)
	, sourcePicoseconds_(0)
	, serverTimestamp_()
	, serverPicoseconds_(0)
	{
		for (uint32_t idx = 0; idx < value.size(); idx++) {
			OpcUaSByte val;
			const_cast<OpcUaSByteArray*>(&value)->get(idx, val);
			opcUaVariantSPtr_->pushBack(val);
		}
	}

	OpcUaDataValue::OpcUaDataValue(const OpcUaInt16Array& value, OpcUaStatusCode statusCode, const OpcUaDateTime& sourceTimestamp)
	:  Object()
	, opcUaVariantSPtr_(constructSPtr<OpcUaVariant>())
	, opcUaStatusCode_(statusCode)
	, sourceTimestamp_(sourceTimestamp)
	, sourcePicoseconds_(0)
	, serverTimestamp_()
	, serverPicoseconds_(0)
	{
		for (uint32_t idx = 0; idx < value.size(); idx++) {
			OpcUaInt16 val;
			const_cast<OpcUaInt16Array*>(&value)->get(idx, val);
			opcUaVariantSPtr_->pushBack(val);
		}
	}

	OpcUaDataValue::OpcUaDataValue(const OpcUaUInt16Array& value, OpcUaStatusCode statusCode, const OpcUaDateTime& sourceTimestamp)
	:  Object()
	, opcUaVariantSPtr_(constructSPtr<OpcUaVariant>())
	, opcUaStatusCode_(statusCode)
	, sourceTimestamp_(sourceTimestamp)
	, sourcePicoseconds_(0)
	, serverTimestamp_()
	, serverPicoseconds_(0)
	{
		for (uint32_t idx = 0; idx < value.size(); idx++) {
			OpcUaUInt16 val;
			const_cast<OpcUaUInt16Array*>(&value)->get(idx, val);
			opcUaVariantSPtr_->pushBack(val);
		}
	}

	OpcUaDataValue::OpcUaDataValue(const OpcUaInt32Array& value, OpcUaStatusCode statusCode, const OpcUaDateTime& sourceTimestamp)
	:  Object()
	, opcUaVariantSPtr_(constructSPtr<OpcUaVariant>())
	, opcUaStatusCode_(statusCode)
	, sourceTimestamp_(sourceTimestamp)
	, sourcePicoseconds_(0)
	, serverTimestamp_()
	, serverPicoseconds_(0)
	{
		for (uint32_t idx = 0; idx < value.size(); idx++) {
			OpcUaInt32 val;
			const_cast<OpcUaInt32Array*>(&value)->get(idx, val);
			opcUaVariantSPtr_->pushBack(val);
		}
	}

	OpcUaDataValue::OpcUaDataValue(const OpcUaUInt32Array& value, OpcUaStatusCode statusCode, const OpcUaDateTime& sourceTimestamp)
	:  Object()
	, opcUaVariantSPtr_(constructSPtr<OpcUaVariant>())
	, opcUaStatusCode_(statusCode)
	, sourceTimestamp_(sourceTimestamp)
	, sourcePicoseconds_(0)
	, serverTimestamp_()
	, serverPicoseconds_(0)
	{
		for (uint32_t idx = 0; idx < value.size(); idx++) {
			OpcUaUInt32 val;
			const_cast<OpcUaUInt32Array*>(&value)->get(idx, val);
			opcUaVariantSPtr_->pushBack(val);
		}
	}

	OpcUaDataValue::OpcUaDataValue(const OpcUaInt64Array& value, OpcUaStatusCode statusCode, const OpcUaDateTime& sourceTimestamp)
	:  Object()
	, opcUaVariantSPtr_(constructSPtr<OpcUaVariant>())
	, opcUaStatusCode_(statusCode)
	, sourceTimestamp_(sourceTimestamp)
	, sourcePicoseconds_(0)
	, serverTimestamp_()
	, serverPicoseconds_(0)
	{
		for (uint32_t idx = 0; idx < value.size(); idx++) {
			OpcUaInt64 val;
			const_cast<OpcUaInt64Array*>(&value)->get(idx, val);
			opcUaVariantSPtr_->pushBack(val);
		}
	}

	OpcUaDataValue::OpcUaDataValue(const OpcUaUInt64Array& value, OpcUaStatusCode statusCode, const OpcUaDateTime& sourceTimestamp)
	:  Object()
	, opcUaVariantSPtr_(constructSPtr<OpcUaVariant>())
	, opcUaStatusCode_(statusCode)
	, sourceTimestamp_(sourceTimestamp)
	, sourcePicoseconds_(0)
	, serverTimestamp_()
	, serverPicoseconds_(0)
	{
		for (uint32_t idx = 0; idx < value.size(); idx++) {
			OpcUaUInt64 val;
			const_cast<OpcUaUInt64Array*>(&value)->get(idx, val);
			opcUaVariantSPtr_->pushBack(val);
		}
	}

	OpcUaDataValue::OpcUaDataValue(const OpcUaFloatArray& value, OpcUaStatusCode statusCode, const OpcUaDateTime& sourceTimestamp)
	:  Object()
	, opcUaVariantSPtr_(constructSPtr<OpcUaVariant>())
	, opcUaStatusCode_(statusCode)
	, sourceTimestamp_(sourceTimestamp)
	, sourcePicoseconds_(0)
	, serverTimestamp_()
	, serverPicoseconds_(0)
	{
		for (uint32_t idx = 0; idx < value.size(); idx++) {
			OpcUaFloat val;
			const_cast<OpcUaFloatArray*>(&value)->get(idx, val);
			opcUaVariantSPtr_->pushBack(val);
		}
	}

	OpcUaDataValue::OpcUaDataValue(const OpcUaDoubleArray& value, OpcUaStatusCode statusCode, const OpcUaDateTime& sourceTimestamp)
	:  Object()
	, opcUaVariantSPtr_(constructSPtr<OpcUaVariant>())
	, opcUaStatusCode_(statusCode)
	, sourceTimestamp_(sourceTimestamp)
	, sourcePicoseconds_(0)
	, serverTimestamp_()
	, serverPicoseconds_(0)
	{
		for (uint32_t idx = 0; idx < value.size(); idx++) {
			OpcUaDouble val;
			const_cast<OpcUaDoubleArray*>(&value)->get(idx, val);
			opcUaVariantSPtr_->pushBack(val);
		}
	}

	OpcUaDataValue::OpcUaDataValue(const OpcUaStringArray& value, OpcUaStatusCode statusCode, const OpcUaDateTime& sourceTimestamp)
	:  Object()
	, opcUaVariantSPtr_(constructSPtr<OpcUaVariant>())
	, opcUaStatusCode_(statusCode)
	, sourceTimestamp_(sourceTimestamp)
	, sourcePicoseconds_(0)
	, serverTimestamp_()
	, serverPicoseconds_(0)
	{
		for (uint32_t idx = 0; idx < value.size(); idx++) {
			OpcUaString::SPtr val;
			const_cast<OpcUaStringArray*>(&value)->get(idx, val);
			opcUaVariantSPtr_->pushBack(val);
		}
	}

	OpcUaDataValue::OpcUaDataValue(const OpcUaDateTimeArray& value, OpcUaStatusCode statusCode, const OpcUaDateTime& sourceTimestamp)
	:  Object()
	, opcUaVariantSPtr_(constructSPtr<OpcUaVariant>())
	, opcUaStatusCode_(statusCode)
	, sourceTimestamp_(sourceTimestamp)
	, sourcePicoseconds_(0)
	, serverTimestamp_()
	, serverPicoseconds_(0)
	{
		for (uint32_t idx = 0; idx < value.size(); idx++) {
			OpcUaDateTime val;
			const_cast<OpcUaDateTimeArray*>(&value)->get(idx, val);
			opcUaVariantSPtr_->pushBack(val);
		}
	}

	OpcUaDataValue::OpcUaDataValue(const OpcUaGuidArray& value, OpcUaStatusCode statusCode, const OpcUaDateTime& sourceTimestamp)
	:  Object()
	, opcUaVariantSPtr_(constructSPtr<OpcUaVariant>())
	, opcUaStatusCode_(statusCode)
	, sourceTimestamp_(sourceTimestamp)
	, sourcePicoseconds_(0)
	, serverTimestamp_()
	, serverPicoseconds_(0)
	{
		for (uint32_t idx = 0; idx < value.size(); idx++) {
			OpcUaGuid::SPtr val;
			const_cast<OpcUaGuidArray*>(&value)->get(idx, val);
			opcUaVariantSPtr_->pushBack(val);
		}
	}

	OpcUaDataValue::OpcUaDataValue(const OpcUaByteStringArray& value, OpcUaStatusCode statusCode, const OpcUaDateTime& sourceTimestamp)
	:  Object()
	, opcUaVariantSPtr_(constructSPtr<OpcUaVariant>())
	, opcUaStatusCode_(statusCode)
	, sourceTimestamp_(sourceTimestamp)
	, sourcePicoseconds_(0)
	, serverTimestamp_()
	, serverPicoseconds_(0)
	{
		for (uint32_t idx = 0; idx < value.size(); idx++) {
			OpcUaByteString::SPtr val;
			const_cast<OpcUaByteStringArray*>(&value)->get(idx, val);
			opcUaVariantSPtr_->pushBack(val);
		}
	}

	OpcUaDataValue::OpcUaDataValue(const OpcUaXmlElementArray& value, OpcUaStatusCode statusCode, const OpcUaDateTime& sourceTimestamp)
	:  Object()
	, opcUaVariantSPtr_(constructSPtr<OpcUaVariant>())
	, opcUaStatusCode_(statusCode)
	, sourceTimestamp_(sourceTimestamp)
	, sourcePicoseconds_(0)
	, serverTimestamp_()
	, serverPicoseconds_(0)
	{
		for (uint32_t idx = 0; idx < value.size(); idx++) {
			OpcUaXmlElement::SPtr val;
			const_cast<OpcUaXmlElementArray*>(&value)->get(idx, val);
			opcUaVariantSPtr_->pushBack(val);
		}
	}

	OpcUaDataValue::OpcUaDataValue(const OpcUaNodeIdArray& value, OpcUaStatusCode statusCode, const OpcUaDateTime& sourceTimestamp)
	:  Object()
	, opcUaVariantSPtr_(constructSPtr<OpcUaVariant>())
	, opcUaStatusCode_(statusCode)
	, sourceTimestamp_(sourceTimestamp)
	, sourcePicoseconds_(0)
	, serverTimestamp_()
	, serverPicoseconds_(0)
	{
		for (uint32_t idx = 0; idx < value.size(); idx++) {
			OpcUaNodeId::SPtr val;
			const_cast<OpcUaNodeIdArray*>(&value)->get(idx, val);
			opcUaVariantSPtr_->pushBack(val);
		}
	}

	OpcUaDataValue::OpcUaDataValue(const OpcUaExpandedNodeIdArray& value, OpcUaStatusCode statusCode, const OpcUaDateTime& sourceTimestamp)
	:  Object()
	, opcUaVariantSPtr_(constructSPtr<OpcUaVariant>())
	, opcUaStatusCode_(statusCode)
	, sourceTimestamp_(sourceTimestamp)
	, sourcePicoseconds_(0)
	, serverTimestamp_()
	, serverPicoseconds_(0)
	{
		for (uint32_t idx = 0; idx < value.size(); idx++) {
			OpcUaExpandedNodeId::SPtr val;
			const_cast<OpcUaExpandedNodeIdArray*>(&value)->get(idx, val);
			opcUaVariantSPtr_->pushBack(val);
		}
	}

	OpcUaDataValue::OpcUaDataValue(const OpcUaStatusCodeArray& value, OpcUaStatusCode statusCode, const OpcUaDateTime& sourceTimestamp)
	:  Object()
	, opcUaVariantSPtr_(constructSPtr<OpcUaVariant>())
	, opcUaStatusCode_(statusCode)
	, sourceTimestamp_(sourceTimestamp)
	, sourcePicoseconds_(0)
	, serverTimestamp_()
	, serverPicoseconds_(0)
	{
		for (uint32_t idx = 0; idx < value.size(); idx++) {
			OpcUaStatusCode val;
			const_cast<OpcUaStatusCodeArray*>(&value)->get(idx, val);
			opcUaVariantSPtr_->pushBack(val);
		}
	}

	OpcUaDataValue::OpcUaDataValue(const OpcUaQualifiedNameArray& value, OpcUaStatusCode statusCode, const OpcUaDateTime& sourceTimestamp)
	:  Object()
	, opcUaVariantSPtr_(constructSPtr<OpcUaVariant>())
	, opcUaStatusCode_(statusCode)
	, sourceTimestamp_(sourceTimestamp)
	, sourcePicoseconds_(0)
	, serverTimestamp_()
	, serverPicoseconds_(0)
	{
		for (uint32_t idx = 0; idx < value.size(); idx++) {
			OpcUaQualifiedName::SPtr val;
			const_cast<OpcUaQualifiedNameArray*>(&value)->get(idx, val);
			opcUaVariantSPtr_->pushBack(val);
		}
	}

	OpcUaDataValue::OpcUaDataValue(const OpcUaLocalizedTextArray& value, OpcUaStatusCode statusCode, const OpcUaDateTime& sourceTimestamp)
	:  Object()
	, opcUaVariantSPtr_(constructSPtr<OpcUaVariant>())
	, opcUaStatusCode_(statusCode)
	, sourceTimestamp_(sourceTimestamp)
	, sourcePicoseconds_(0)
	, serverTimestamp_()
	, serverPicoseconds_(0)
	{
		for (uint32_t idx = 0; idx < value.size(); idx++) {
			OpcUaLocalizedText::SPtr val;
			const_cast<OpcUaLocalizedTextArray*>(&value)->get(idx, val);
			opcUaVariantSPtr_->pushBack(val);
		}
	}

	OpcUaDataValue::OpcUaDataValue(const OpcUaExtensionObjectArray& value, OpcUaStatusCode statusCode, const OpcUaDateTime& sourceTimestamp)
	:  Object()
	, opcUaVariantSPtr_(constructSPtr<OpcUaVariant>())
	, opcUaStatusCode_(statusCode)
	, sourceTimestamp_(sourceTimestamp)
	, sourcePicoseconds_(0)
	, serverTimestamp_()
	, serverPicoseconds_(0)
	{
		for (uint32_t idx = 0; idx < value.size(); idx++) {
			OpcUaExtensionObject::SPtr val;
			const_cast<OpcUaExtensionObjectArray*>(&value)->get(idx, val);
			opcUaVariantSPtr_->pushBack(val);
		}
	}

	OpcUaDataValue::OpcUaDataValue(const std::vector<OpcUaBoolean>& value, OpcUaStatusCode statusCode, const OpcUaDateTime& sourceTimestamp)
	: Object()
	, opcUaVariantSPtr_(constructSPtr<OpcUaVariant>())
	, opcUaStatusCode_(statusCode)
	, sourceTimestamp_(sourceTimestamp)
	, sourcePicoseconds_(0)
	, serverTimestamp_()
	, serverPicoseconds_(0)
	{
		for (auto it : value) opcUaVariantSPtr_->pushBack(it);
	}

	OpcUaDataValue::OpcUaDataValue(const std::vector<OpcUaByte>& value, OpcUaStatusCode statusCode, const OpcUaDateTime& sourceTimestamp)
	: Object()
	, opcUaVariantSPtr_(constructSPtr<OpcUaVariant>())
	, opcUaStatusCode_(statusCode)
	, sourceTimestamp_(sourceTimestamp)
	, sourcePicoseconds_(0)
	, serverTimestamp_()
	, serverPicoseconds_(0)
	{
		for (auto it : value) opcUaVariantSPtr_->pushBack(it);
	}

	OpcUaDataValue::OpcUaDataValue(const std::vector<OpcUaSByte>& value, OpcUaStatusCode statusCode, const OpcUaDateTime& sourceTimestamp)
	: Object()
	, opcUaVariantSPtr_(constructSPtr<OpcUaVariant>())
	, opcUaStatusCode_(statusCode)
	, sourceTimestamp_(sourceTimestamp)
	, sourcePicoseconds_(0)
	, serverTimestamp_()
	, serverPicoseconds_(0)
	{
		for (auto it : value) opcUaVariantSPtr_->pushBack(it);
	}

	OpcUaDataValue::OpcUaDataValue(const std::vector<OpcUaInt16>& value, OpcUaStatusCode statusCode, const OpcUaDateTime& sourceTimestamp)
	: Object()
	, opcUaVariantSPtr_(constructSPtr<OpcUaVariant>())
	, opcUaStatusCode_(statusCode)
	, sourceTimestamp_(sourceTimestamp)
	, sourcePicoseconds_(0)
	, serverTimestamp_()
	, serverPicoseconds_(0)
	{
		for (auto it : value) opcUaVariantSPtr_->pushBack(it);
	}

	OpcUaDataValue::OpcUaDataValue(const std::vector<OpcUaUInt16>& value, OpcUaStatusCode statusCode, const OpcUaDateTime& sourceTimestamp)
	: Object()
	, opcUaVariantSPtr_(constructSPtr<OpcUaVariant>())
	, opcUaStatusCode_(statusCode)
	, sourceTimestamp_(sourceTimestamp)
	, sourcePicoseconds_(0)
	, serverTimestamp_()
	, serverPicoseconds_(0)
	{
		for (auto it : value) opcUaVariantSPtr_->pushBack(it);
	}

	OpcUaDataValue::OpcUaDataValue(const std::vector<OpcUaInt32>& value, OpcUaStatusCode statusCode, const OpcUaDateTime& sourceTimestamp)
	: Object()
	, opcUaVariantSPtr_(constructSPtr<OpcUaVariant>())
	, opcUaStatusCode_(statusCode)
	, sourceTimestamp_(sourceTimestamp)
	, sourcePicoseconds_(0)
	, serverTimestamp_()
	, serverPicoseconds_(0)
	{
		for (auto it : value) opcUaVariantSPtr_->pushBack(it);
	}

	OpcUaDataValue::OpcUaDataValue(const std::vector<OpcUaUInt32>& value, OpcUaStatusCode statusCode, const OpcUaDateTime& sourceTimestamp)
	: Object()
	, opcUaVariantSPtr_(constructSPtr<OpcUaVariant>())
	, opcUaStatusCode_(statusCode)
	, sourceTimestamp_(sourceTimestamp)
	, sourcePicoseconds_(0)
	, serverTimestamp_()
	, serverPicoseconds_(0)
	{
		for (auto it : value) opcUaVariantSPtr_->pushBack(it);
	}

	OpcUaDataValue::OpcUaDataValue(const std::vector<OpcUaInt64>& value, OpcUaStatusCode statusCode, const OpcUaDateTime& sourceTimestamp)
	: Object()
	, opcUaVariantSPtr_(constructSPtr<OpcUaVariant>())
	, opcUaStatusCode_(statusCode)
	, sourceTimestamp_(sourceTimestamp)
	, sourcePicoseconds_(0)
	, serverTimestamp_()
	, serverPicoseconds_(0)
	{
		for (auto it : value) opcUaVariantSPtr_->pushBack(it);
	}

	OpcUaDataValue::OpcUaDataValue(const std::vector<OpcUaUInt64>& value, OpcUaStatusCode statusCode, const OpcUaDateTime& sourceTimestamp)
	: Object()
	, opcUaVariantSPtr_(constructSPtr<OpcUaVariant>())
	, opcUaStatusCode_(statusCode)
	, sourceTimestamp_(sourceTimestamp)
	, sourcePicoseconds_(0)
	, serverTimestamp_()
	, serverPicoseconds_(0)
	{
		for (auto it : value) opcUaVariantSPtr_->pushBack(it);
	}

	OpcUaDataValue::OpcUaDataValue(const std::vector<OpcUaFloat>& value, OpcUaStatusCode statusCode, const OpcUaDateTime& sourceTimestamp)
	: Object()
	, opcUaVariantSPtr_(constructSPtr<OpcUaVariant>())
	, opcUaStatusCode_(statusCode)
	, sourceTimestamp_(sourceTimestamp)
	, sourcePicoseconds_(0)
	, serverTimestamp_()
	, serverPicoseconds_(0)
	{
		for (auto it : value) opcUaVariantSPtr_->pushBack(it);
	}

	OpcUaDataValue::OpcUaDataValue(const std::vector<OpcUaDouble>& value, OpcUaStatusCode statusCode, const OpcUaDateTime& sourceTimestamp)
	: Object()
	, opcUaVariantSPtr_(constructSPtr<OpcUaVariant>())
	, opcUaStatusCode_(statusCode)
	, sourceTimestamp_(sourceTimestamp)
	, sourcePicoseconds_(0)
	, serverTimestamp_()
	, serverPicoseconds_(0)
	{
		for (auto it : value) opcUaVariantSPtr_->pushBack(it);
	}

	OpcUaDataValue::OpcUaDataValue(const std::vector<OpcUaString::SPtr>& value, OpcUaStatusCode statusCode, const OpcUaDateTime& sourceTimestamp)
	: Object()
	, opcUaVariantSPtr_(constructSPtr<OpcUaVariant>())
	, opcUaStatusCode_(statusCode)
	, sourceTimestamp_(sourceTimestamp)
	, sourcePicoseconds_(0)
	, serverTimestamp_()
	, serverPicoseconds_(0)
	{
		for (auto it : value) opcUaVariantSPtr_->pushBack(it);
	}

	OpcUaDataValue::OpcUaDataValue(const std::vector<OpcUaDateTime>& value, OpcUaStatusCode statusCode, const OpcUaDateTime& sourceTimestamp)
	: Object()
	, opcUaVariantSPtr_(constructSPtr<OpcUaVariant>())
	, opcUaStatusCode_(statusCode)
	, sourceTimestamp_(sourceTimestamp)
	, sourcePicoseconds_(0)
	, serverTimestamp_()
	, serverPicoseconds_(0)
	{
		for (auto it : value) opcUaVariantSPtr_->pushBack(it);
	}

	OpcUaDataValue::OpcUaDataValue(const std::vector<OpcUaGuid::SPtr>& value, OpcUaStatusCode statusCode, const OpcUaDateTime& sourceTimestamp)
	: Object()
	, opcUaVariantSPtr_(constructSPtr<OpcUaVariant>())
	, opcUaStatusCode_(statusCode)
	, sourceTimestamp_(sourceTimestamp)
	, sourcePicoseconds_(0)
	, serverTimestamp_()
	, serverPicoseconds_(0)
	{
		for (auto it : value) opcUaVariantSPtr_->pushBack(it);
	}

	OpcUaDataValue::OpcUaDataValue(const std::vector<OpcUaByteString::SPtr>& value, OpcUaStatusCode statusCode, const OpcUaDateTime& sourceTimestamp)
	: Object()
	, opcUaVariantSPtr_(constructSPtr<OpcUaVariant>())
	, opcUaStatusCode_(statusCode)
	, sourceTimestamp_(sourceTimestamp)
	, sourcePicoseconds_(0)
	, serverTimestamp_()
	, serverPicoseconds_(0)
	{
		for (auto it : value) opcUaVariantSPtr_->pushBack(it);
	}

	OpcUaDataValue::OpcUaDataValue(const std::vector<OpcUaXmlElement::SPtr>& value, OpcUaStatusCode statusCode, const OpcUaDateTime& sourceTimestamp)
	: Object()
	, opcUaVariantSPtr_(constructSPtr<OpcUaVariant>())
	, opcUaStatusCode_(statusCode)
	, sourceTimestamp_(sourceTimestamp)
	, sourcePicoseconds_(0)
	, serverTimestamp_()
	, serverPicoseconds_(0)
	{
		for (auto it : value) opcUaVariantSPtr_->pushBack(it);
	}

	OpcUaDataValue::OpcUaDataValue(const std::vector<OpcUaNodeId::SPtr>& value, OpcUaStatusCode statusCode, const OpcUaDateTime& sourceTimestamp)
	: Object()
	, opcUaVariantSPtr_(constructSPtr<OpcUaVariant>())
	, opcUaStatusCode_(statusCode)
	, sourceTimestamp_(sourceTimestamp)
	, sourcePicoseconds_(0)
	, serverTimestamp_()
	, serverPicoseconds_(0)
	{
		for (auto it : value) opcUaVariantSPtr_->pushBack(it);
	}

	OpcUaDataValue::OpcUaDataValue(const std::vector<OpcUaExpandedNodeId::SPtr>& value, OpcUaStatusCode statusCode, const OpcUaDateTime& sourceTimestamp)
	: Object()
	, opcUaVariantSPtr_(constructSPtr<OpcUaVariant>())
	, opcUaStatusCode_(statusCode)
	, sourceTimestamp_(sourceTimestamp)
	, sourcePicoseconds_(0)
	, serverTimestamp_()
	, serverPicoseconds_(0)
	{
		for (auto it : value) opcUaVariantSPtr_->pushBack(it);
	}

	OpcUaDataValue::OpcUaDataValue(const std::vector<OpcUaStatusCode>& value, OpcUaStatusCode statusCode, const OpcUaDateTime& sourceTimestamp)
	: Object()
	, opcUaVariantSPtr_(constructSPtr<OpcUaVariant>())
	, opcUaStatusCode_(statusCode)
	, sourceTimestamp_(sourceTimestamp)
	, sourcePicoseconds_(0)
	, serverTimestamp_()
	, serverPicoseconds_(0)
	{
		for (auto it : value) opcUaVariantSPtr_->pushBack(it);
	}

	OpcUaDataValue::OpcUaDataValue(const std::vector<OpcUaQualifiedName::SPtr>& value, OpcUaStatusCode statusCode, const OpcUaDateTime& sourceTimestamp)
	: Object()
	, opcUaVariantSPtr_(constructSPtr<OpcUaVariant>())
	, opcUaStatusCode_(statusCode)
	, sourceTimestamp_(sourceTimestamp)
	, sourcePicoseconds_(0)
	, serverTimestamp_()
	, serverPicoseconds_(0)
	{
		for (auto it : value) opcUaVariantSPtr_->pushBack(it);
	}

	OpcUaDataValue::OpcUaDataValue(const std::vector<OpcUaLocalizedText::SPtr>& value, OpcUaStatusCode statusCode, const OpcUaDateTime& sourceTimestamp)
	: Object()
	, opcUaVariantSPtr_(constructSPtr<OpcUaVariant>())
	, opcUaStatusCode_(statusCode)
	, sourceTimestamp_(sourceTimestamp)
	, sourcePicoseconds_(0)
	, serverTimestamp_()
	, serverPicoseconds_(0)
	{
		for (auto it : value) opcUaVariantSPtr_->pushBack(it);
	}

	OpcUaDataValue::OpcUaDataValue(const std::vector<OpcUaExtensionObject::SPtr>& value, OpcUaStatusCode statusCode, const OpcUaDateTime& sourceTimestamp)
	: Object()
	, opcUaVariantSPtr_(constructSPtr<OpcUaVariant>())
	, opcUaStatusCode_(statusCode)
	, sourceTimestamp_(sourceTimestamp)
	, sourcePicoseconds_(0)
	, serverTimestamp_()
	, serverPicoseconds_(0)
	{
		for (auto it : value) opcUaVariantSPtr_->pushBack(it);
	}
		
	OpcUaDataValue::~OpcUaDataValue(void)
	{
	}

	bool
	OpcUaDataValue::exist(void)
	{
		if (opcUaVariantSPtr_.get() != nullptr) return false;
		if (opcUaStatusCode_ != Success) return false;
		if (sourceTimestamp_.exist()) return false;
		if (serverTimestamp_.exist()) return false;
		return true;
	}

	bool
	OpcUaDataValue::isNullVariant(void)
	{
		return opcUaVariantSPtr_.get() == nullptr;
	}

	OpcUaVariant::SPtr 
	OpcUaDataValue::variant(void)
	{
		if (opcUaVariantSPtr_.get() == nullptr) {
			opcUaVariantSPtr_ = constructSPtr<OpcUaVariant>();
		}
		return opcUaVariantSPtr_;
	}

	void 
	OpcUaDataValue::statusCode(const OpcUaStatusCode& opcUaStatusCode)
	{
		opcUaStatusCode_ = opcUaStatusCode;
	}

	OpcUaStatusCode  
	OpcUaDataValue::statusCode(void)
	{
		return opcUaStatusCode_;
	}

	void  
	OpcUaDataValue::sourceTimestamp(const OpcUaDateTime& sourceTimestamp)
	{
		sourceTimestamp_ = sourceTimestamp;
	}

	OpcUaDateTime&  
	OpcUaDataValue::sourceTimestamp(void)
	{
		return sourceTimestamp_;
	}

	void  
	OpcUaDataValue::sourcePicoseconds(const OpcUaUInt16& sourcePicoseconds)
	{
		sourcePicoseconds_ = sourcePicoseconds;
	}

	OpcUaInt16  
	OpcUaDataValue::sourcePicoseconds(void)
	{
		return sourcePicoseconds_;
	}

	void  
	OpcUaDataValue::serverTimestamp(const OpcUaDateTime& serverTimestamp)
	{
		serverTimestamp_ = serverTimestamp;
	}

	OpcUaDateTime&  
	OpcUaDataValue::serverTimestamp(void)
	{
		return serverTimestamp_;
	}

	void  
	OpcUaDataValue::serverPicoseconds(const OpcUaUInt16& serverPicoseconds)
	{
		serverPicoseconds_ = serverPicoseconds;
	}

	OpcUaInt16  
	OpcUaDataValue::serverPicoseconds(void)
	{
		return serverPicoseconds_;
	}

	void 
	OpcUaDataValue::reset(void)
	{
		opcUaVariantSPtr_.reset();
		opcUaStatusCode_ = Success;
		sourceTimestamp_ = 0;
		serverTimestamp_ = 0;
		sourcePicoseconds_ = 0;
		serverPicoseconds_ = 0;
	}

    bool
	OpcUaDataValue::setValue(const OpcUaNullValue& value)
    {
    	opcUaVariantSPtr_.reset();
    	return true;
    }

    bool
	OpcUaDataValue::setValue(const OpcUaBoolean& value)
    {
    	variant()->setValue(value);
    	return true;
    }

    bool
	OpcUaDataValue::setValue(const OpcUaByte& value)
    {
    	variant()->setValue(value);
    	return true;
    }

    bool
	OpcUaDataValue::setValue(const OpcUaSByte& value)
    {
    	variant()->setValue(value);
    	return true;
    }

    bool
	OpcUaDataValue::setValue(const OpcUaInt16& value)
    {
    	variant()->setValue(value);
    	return true;
    }

    bool
	OpcUaDataValue::setValue(const OpcUaUInt16& value)
    {
    	variant()->setValue(value);
    	return true;
    }

    bool
	OpcUaDataValue::setValue(const OpcUaInt32& value)
    {
    	variant()->setValue(value);
    	return true;
    }

    bool
	OpcUaDataValue::setValue(const OpcUaUInt32& value)
    {
    	variant()->setValue(value);
    	return true;
    }

    bool
	OpcUaDataValue::setValue(const OpcUaInt64& value)
    {
    	variant()->setValue(value);
    	return true;
    }

    bool
	OpcUaDataValue::setValue(const OpcUaUInt64& value)
    {
    	variant()->setValue(value);
    	return true;
    }

    bool
	OpcUaDataValue::setValue(const OpcUaFloat& value)
    {
    	variant()->setValue(value);
    	return true;
    }

    bool
	OpcUaDataValue::setValue(const OpcUaDouble& value)
    {
    	variant()->setValue(value);
    	return true;
    }

    bool
	OpcUaDataValue::setValue(const OpcUaString& value)
    {
    	variant()->setValue(value);
    	return true;
    }

    bool
	OpcUaDataValue::setValue(const OpcUaDateTime& value)
    {
    	variant()->setValue(value);
    	return true;
    }

    bool
	OpcUaDataValue::setValue(const OpcUaGuid& value)
    {
    	variant()->setValue(value);
    	return true;
    }

    bool
	OpcUaDataValue::setValue(const OpcUaByteString& value)
    {
    	variant()->setValue(value);
    	return true;
    }

    bool
	OpcUaDataValue::setValue(const OpcUaXmlElement& value)
    {
    	variant()->setValue(value);
    	return true;
    }

    bool
	OpcUaDataValue::setValue(const OpcUaNodeId& value)
    {
    	variant()->setValue(value);
    	return true;
    }

    bool
	OpcUaDataValue::setValue(const OpcUaExpandedNodeId& value)
    {
    	variant()->setValue(value);
    	return true;
    }

    bool
	OpcUaDataValue::setValue(const OpcUaStatusCode& value)
    {
    	variant()->setValue(value);
    	return true;
    }

    bool
	OpcUaDataValue::setValue(const OpcUaQualifiedName& value)
    {
    	variant()->setValue(value);
    	return true;
    }

    bool
	OpcUaDataValue::setValue(const OpcUaLocalizedText& value)
    {
    	variant()->setValue(value);
    	return true;
    }

    bool
	OpcUaDataValue::setValue(const OpcUaExtensionObject& value)
    {
    	variant()->setValue(value);
    	return true;
    }

    bool
 	OpcUaDataValue::setValue(const OpcUaBooleanArray& value)
     {
 		opcUaVariantSPtr_ = constructSPtr<OpcUaVariant>();
 		for (uint32_t idx = 0; idx < value.size(); idx++) {
 			OpcUaBoolean val;
 			if (!const_cast<OpcUaBooleanArray*>(&value)->get(idx, val)) {
 				return false;
 			}
 			opcUaVariantSPtr_->pushBack(val);
 		}
 		return true;
     }

 	bool
 	OpcUaDataValue::setValue(const OpcUaByteArray& value)
     {
 		opcUaVariantSPtr_ = constructSPtr<OpcUaVariant>();
 		for (uint32_t idx = 0; idx < value.size(); idx++) {
 			OpcUaByte val;
 			if (!const_cast<OpcUaByteArray*>(&value)->get(idx, val)) {
 				return false;
 			}
 			opcUaVariantSPtr_->pushBack(val);
 		}
 		return true;
     }

 	bool
 	OpcUaDataValue::setValue(const OpcUaSByteArray& value)
     {
 		opcUaVariantSPtr_ = constructSPtr<OpcUaVariant>();
 		for (uint32_t idx = 0; idx < value.size(); idx++) {
 			OpcUaSByte val;
 			if (!const_cast<OpcUaSByteArray*>(&value)->get(idx, val)) {
 				return false;
 			}
 			opcUaVariantSPtr_->pushBack(val);
 		}
 		return true;
     }

 	bool
 	OpcUaDataValue::setValue(const OpcUaInt16Array& value)
     {
 		opcUaVariantSPtr_ = constructSPtr<OpcUaVariant>();
 		for (uint32_t idx = 0; idx < value.size(); idx++) {
 			OpcUaInt16 val;
 			if (!const_cast<OpcUaInt16Array*>(&value)->get(idx, val)) {
 				return false;
 			}
 			opcUaVariantSPtr_->pushBack(val);
 		}
 		return true;
     }

 	bool
 	OpcUaDataValue::setValue(const OpcUaUInt16Array& value)
     {
 		opcUaVariantSPtr_ = constructSPtr<OpcUaVariant>();
 		for (uint32_t idx = 0; idx < value.size(); idx++) {
 			OpcUaUInt16 val;
 			if (!const_cast<OpcUaUInt16Array*>(&value)->get(idx, val)) {
 				return false;
 			}
 			opcUaVariantSPtr_->pushBack(val);
 		}
 		return true;
     }

 	bool
 	OpcUaDataValue::setValue(const OpcUaInt32Array& value)
     {
 		opcUaVariantSPtr_ = constructSPtr<OpcUaVariant>();
 		for (uint32_t idx = 0; idx < value.size(); idx++) {
 			OpcUaInt32 val;
 			if (!const_cast<OpcUaInt32Array*>(&value)->get(idx, val)) {
 				return false;
 			}
 			opcUaVariantSPtr_->pushBack(val);
 		}
 		return true;
     }

 	bool
 	OpcUaDataValue::setValue(const OpcUaUInt32Array& value)
     {
 		opcUaVariantSPtr_ = constructSPtr<OpcUaVariant>();
 		for (uint32_t idx = 0; idx < value.size(); idx++) {
 			OpcUaUInt32 val;
 			if (!const_cast<OpcUaUInt32Array*>(&value)->get(idx, val)) {
 				return false;
 			}
 			opcUaVariantSPtr_->pushBack(val);
 		}
 		return true;
     }

 	bool
 	OpcUaDataValue::setValue(const OpcUaInt64Array& value)
     {
 		opcUaVariantSPtr_ = constructSPtr<OpcUaVariant>();
 		for (uint32_t idx = 0; idx < value.size(); idx++) {
 			OpcUaInt64 val;
 			if (!const_cast<OpcUaInt64Array*>(&value)->get(idx, val)) {
 				return false;
 			}
 			opcUaVariantSPtr_->pushBack(val);
 		}
 		return true;
     }

 	bool
 	OpcUaDataValue::setValue(const OpcUaUInt64Array& value)
     {
 		opcUaVariantSPtr_ = constructSPtr<OpcUaVariant>();
 		for (uint32_t idx = 0; idx < value.size(); idx++) {
 			OpcUaUInt64 val;
 			if (!const_cast<OpcUaUInt64Array*>(&value)->get(idx, val)) {
 				return false;
 			}
 			opcUaVariantSPtr_->pushBack(val);
 		}
 		return true;
     }

 	bool
 	OpcUaDataValue::setValue(const OpcUaDoubleArray& value)
     {
 		opcUaVariantSPtr_ = constructSPtr<OpcUaVariant>();
 		for (uint32_t idx = 0; idx < value.size(); idx++) {
 			OpcUaDouble val;
 			if (!const_cast<OpcUaDoubleArray*>(&value)->get(idx, val)) {
 				return false;
 			}
 			opcUaVariantSPtr_->pushBack(val);
 		}
 		return true;
     }

 	bool
 	OpcUaDataValue::setValue(const OpcUaFloatArray& value)
     {
 		opcUaVariantSPtr_ = constructSPtr<OpcUaVariant>();
 		for (uint32_t idx = 0; idx < value.size(); idx++) {
 			OpcUaFloat val;
 			if (!const_cast<OpcUaFloatArray*>(&value)->get(idx, val)) {
 				return false;
 			}
 			opcUaVariantSPtr_->pushBack(val);
 		}
 		return true;
     }

 	bool
 	OpcUaDataValue::setValue(const OpcUaStringArray& value)
     {
 		opcUaVariantSPtr_ = constructSPtr<OpcUaVariant>();
 		for (uint32_t idx = 0; idx < value.size(); idx++) {
 			OpcUaString::SPtr val;
 			if (!const_cast<OpcUaStringArray*>(&value)->get(idx, val)) {
 				return false;
 			}
 			opcUaVariantSPtr_->pushBack(val);
 		}
 		return true;
     }

 	bool
 	OpcUaDataValue::setValue(const OpcUaDateTimeArray& value)
     {
 		opcUaVariantSPtr_ = constructSPtr<OpcUaVariant>();
 		for (uint32_t idx = 0; idx < value.size(); idx++) {
 			OpcUaDateTime val;
 			if (!const_cast<OpcUaDateTimeArray*>(&value)->get(idx, val)) {
 				return false;
 			}
 			opcUaVariantSPtr_->pushBack(val);
 		}
 		return true;
     }

 	bool
 	OpcUaDataValue::setValue(const OpcUaGuidArray& value)
     {
 		opcUaVariantSPtr_ = constructSPtr<OpcUaVariant>();
 		for (uint32_t idx = 0; idx < value.size(); idx++) {
 			OpcUaGuid::SPtr val;
 			if (!const_cast<OpcUaGuidArray*>(&value)->get(idx, val)) {
 				return false;
 			}
 			opcUaVariantSPtr_->pushBack(val);
 		}
 		return true;
     }

 	bool
 	OpcUaDataValue::setValue(const OpcUaByteStringArray& value)
     {
 		opcUaVariantSPtr_ = constructSPtr<OpcUaVariant>();
 		for (uint32_t idx = 0; idx < value.size(); idx++) {
 			OpcUaByteString::SPtr val;
 			if (!const_cast<OpcUaByteStringArray*>(&value)->get(idx, val)) {
 				return false;
 			}
 			opcUaVariantSPtr_->pushBack(val);
 		}
 		return true;
     }

 	bool
 	OpcUaDataValue::setValue(const OpcUaXmlElementArray& value)
     {
 		opcUaVariantSPtr_ = constructSPtr<OpcUaVariant>();
 		for (uint32_t idx = 0; idx < value.size(); idx++) {
 			OpcUaXmlElement::SPtr val;
 			if (!const_cast<OpcUaXmlElementArray*>(&value)->get(idx, val)) {
 				return false;
 			}
 			opcUaVariantSPtr_->pushBack(val);
 		}
 		return true;
     }

 	bool
 	OpcUaDataValue::setValue(const OpcUaNodeIdArray& value)
     {
 		opcUaVariantSPtr_ = constructSPtr<OpcUaVariant>();
 		for (uint32_t idx = 0; idx < value.size(); idx++) {
 			OpcUaNodeId::SPtr val;
 			if (!const_cast<OpcUaNodeIdArray*>(&value)->get(idx, val)) {
 				return false;
 			}
 			opcUaVariantSPtr_->pushBack(val);
 		}
 		return true;
     }

 	bool
 	OpcUaDataValue::setValue(const OpcUaExpandedNodeIdArray& value)
     {
 		opcUaVariantSPtr_ = constructSPtr<OpcUaVariant>();
 		for (uint32_t idx = 0; idx < value.size(); idx++) {
 			OpcUaExpandedNodeId::SPtr val;
 			if (!const_cast<OpcUaExpandedNodeIdArray*>(&value)->get(idx, val)) {
 				return false;
 			}
 			opcUaVariantSPtr_->pushBack(val);
 		}
 		return true;
     }

 	bool
 	OpcUaDataValue::setValue(const OpcUaStatusCodeArray& value)
     {
 		opcUaVariantSPtr_ = constructSPtr<OpcUaVariant>();
 		for (uint32_t idx = 0; idx < value.size(); idx++) {
 			OpcUaStatusCode val;
 			if (!const_cast<OpcUaStatusCodeArray*>(&value)->get(idx, val)) {
 				return false;
 			}
 			opcUaVariantSPtr_->pushBack(val);
 		}
 		return true;
     }

 	bool
 	OpcUaDataValue::setValue(const OpcUaQualifiedNameArray& value)
     {
 		opcUaVariantSPtr_ = constructSPtr<OpcUaVariant>();
 		for (uint32_t idx = 0; idx < value.size(); idx++) {
 			OpcUaQualifiedName::SPtr val;
 			if (!const_cast<OpcUaQualifiedNameArray*>(&value)->get(idx, val)) {
 				return false;
 			}
 			opcUaVariantSPtr_->pushBack(val);
 		}
 		return true;
     }

 	bool
 	OpcUaDataValue::setValue(const OpcUaLocalizedTextArray& value)
     {
 		opcUaVariantSPtr_ = constructSPtr<OpcUaVariant>();
 		for (uint32_t idx = 0; idx < value.size(); idx++) {
 			OpcUaLocalizedText::SPtr val;
 			if (!const_cast<OpcUaLocalizedTextArray*>(&value)->get(idx, val)) {
 				return false;
 			}
 			opcUaVariantSPtr_->pushBack(val);
 		}
 		return true;
     }

 	bool
 	OpcUaDataValue::setValue(const OpcUaExtensionObjectArray& value)
     {
 		opcUaVariantSPtr_ = constructSPtr<OpcUaVariant>();
 		for (uint32_t idx = 0; idx < value.size(); idx++) {
 			OpcUaExtensionObject::SPtr val;
 			if (!const_cast<OpcUaExtensionObjectArray*>(&value)->get(idx, val)) {
 				return false;
 			}
 			opcUaVariantSPtr_->pushBack(val);
 		}
 		return true;
     }

     bool
 	OpcUaDataValue::setValue(const std::vector<OpcUaBoolean>& value)
     {
 		opcUaVariantSPtr_ = constructSPtr<OpcUaVariant>();
 		for (auto it : value) opcUaVariantSPtr_->pushBack(it);
 		return true;
     }

     bool
 	OpcUaDataValue::setValue(const std::vector<OpcUaByte>& value)
     {
 		opcUaVariantSPtr_ = constructSPtr<OpcUaVariant>();
 		for (auto it : value) opcUaVariantSPtr_->pushBack(it);
 		return true;
     }

     bool
 	OpcUaDataValue::setValue(const std::vector<OpcUaSByte>& value)
     {
 		opcUaVariantSPtr_ = constructSPtr<OpcUaVariant>();
 		for (auto it : value) opcUaVariantSPtr_->pushBack(it);
 		return true;
     }

     bool
 	OpcUaDataValue::setValue(const std::vector<OpcUaInt16>& value)
     {
 		opcUaVariantSPtr_ = constructSPtr<OpcUaVariant>();
 		for (auto it : value) opcUaVariantSPtr_->pushBack(it);
 		return true;
     }

     bool
 	OpcUaDataValue::setValue(const std::vector<OpcUaUInt16>& value)
     {
 		opcUaVariantSPtr_ = constructSPtr<OpcUaVariant>();
 		for (auto it : value) opcUaVariantSPtr_->pushBack(it);
 		return true;
     }

     bool
 	OpcUaDataValue::setValue(const std::vector<OpcUaInt32>& value)
     {
 		opcUaVariantSPtr_ = constructSPtr<OpcUaVariant>();
 		for (auto it : value) opcUaVariantSPtr_->pushBack(it);
 		return true;
     }

     bool
 	OpcUaDataValue::setValue(const std::vector<OpcUaUInt32>& value)
     {
 		opcUaVariantSPtr_ = constructSPtr<OpcUaVariant>();
 		for (auto it : value) opcUaVariantSPtr_->pushBack(it);
 		return true;
     }

     bool
 	OpcUaDataValue::setValue(const std::vector<OpcUaInt64>& value)
     {
 		opcUaVariantSPtr_ = constructSPtr<OpcUaVariant>();
 		for (auto it : value) opcUaVariantSPtr_->pushBack(it);
 		return true;
     }

     bool
 	OpcUaDataValue::setValue(const std::vector<OpcUaUInt64>& value)
     {
 		opcUaVariantSPtr_ = constructSPtr<OpcUaVariant>();
 		for (auto it : value) opcUaVariantSPtr_->pushBack(it);
 		return true;
     }

     bool
 	OpcUaDataValue::setValue(const std::vector<OpcUaDouble>& value)
     {
 		opcUaVariantSPtr_ = constructSPtr<OpcUaVariant>();
 		for (auto it : value) opcUaVariantSPtr_->pushBack(it);
 		return true;
     }

     bool
 	OpcUaDataValue::setValue(const std::vector<OpcUaFloat>& value)
     {
 		opcUaVariantSPtr_ = constructSPtr<OpcUaVariant>();
 		for (auto it : value) opcUaVariantSPtr_->pushBack(it);
 		return true;
     }

     bool
 	OpcUaDataValue::setValue(const std::vector<OpcUaString::SPtr>& value)
     {
 		opcUaVariantSPtr_ = constructSPtr<OpcUaVariant>();
 		for (auto it : value) opcUaVariantSPtr_->pushBack(it);
 		return true;
     }

     bool
 	OpcUaDataValue::setValue(const std::vector<OpcUaDateTime>& value)
     {
 		opcUaVariantSPtr_ = constructSPtr<OpcUaVariant>();
 		for (auto it : value) opcUaVariantSPtr_->pushBack(it);
 		return true;
     }

     bool
 	OpcUaDataValue::setValue(const std::vector<OpcUaGuid::SPtr>& value)
     {
 		opcUaVariantSPtr_ = constructSPtr<OpcUaVariant>();
 		for (auto it : value) opcUaVariantSPtr_->pushBack(it);
 		return true;
     }

     bool
 	OpcUaDataValue::setValue(const std::vector<OpcUaByteString::SPtr>& value)
     {
 		opcUaVariantSPtr_ = constructSPtr<OpcUaVariant>();
 		for (auto it : value) opcUaVariantSPtr_->pushBack(it);
 		return true;
     }

     bool
 	OpcUaDataValue::setValue(const std::vector<OpcUaXmlElement::SPtr>& value)
     {
 		opcUaVariantSPtr_ = constructSPtr<OpcUaVariant>();
 		for (auto it : value) opcUaVariantSPtr_->pushBack(it);
 		return true;
     }

     bool
 	OpcUaDataValue::setValue(const std::vector<OpcUaNodeId::SPtr>& value)
     {
 		opcUaVariantSPtr_ = constructSPtr<OpcUaVariant>();
 		for (auto it : value) opcUaVariantSPtr_->pushBack(it);
 		return true;
     }

     bool
 	OpcUaDataValue::setValue(const std::vector<OpcUaExpandedNodeId::SPtr>& value)
     {
 		opcUaVariantSPtr_ = constructSPtr<OpcUaVariant>();
 		for (auto it : value) opcUaVariantSPtr_->pushBack(it);
 		return true;
     }

     bool
 	OpcUaDataValue::setValue(const std::vector<OpcUaStatusCode>& value)
     {
 		opcUaVariantSPtr_ = constructSPtr<OpcUaVariant>();
 		for (auto it : value) opcUaVariantSPtr_->pushBack(it);
 		return true;
     }

     bool
 	OpcUaDataValue::setValue(const std::vector<OpcUaQualifiedName::SPtr>& value)
     {
 		opcUaVariantSPtr_ = constructSPtr<OpcUaVariant>();
 		for (auto it : value) opcUaVariantSPtr_->pushBack(it);
 		return true;
     }

     bool
 	OpcUaDataValue::setValue(const std::vector<OpcUaLocalizedText::SPtr>& value)
     {
 		opcUaVariantSPtr_ = constructSPtr<OpcUaVariant>();
 		for (auto it : value) opcUaVariantSPtr_->pushBack(it);
 		return true;
     }

     bool
 	OpcUaDataValue::setValue(const std::vector<OpcUaExtensionObject::SPtr>& value)
     {
 		opcUaVariantSPtr_ = constructSPtr<OpcUaVariant>();
 		for (auto it : value) opcUaVariantSPtr_->pushBack(it);
 		return true;
     }

    bool
	OpcUaDataValue::getValue(OpcUaBoolean& value)
    {
    	if (opcUaVariantSPtr_.get() == nullptr) {
    		return false;
    	}
    	return opcUaVariantSPtr_->getValue(value);
    }

    bool
	OpcUaDataValue::getValue(OpcUaByte& value)
    {
    	if (opcUaVariantSPtr_.get() == nullptr) {
    		return false;
    	}
    	return opcUaVariantSPtr_->getValue(value);
    }

    bool
	OpcUaDataValue::getValue(OpcUaSByte& value)
    {
    	if (opcUaVariantSPtr_.get() == nullptr) {
    		return false;
    	}
    	return opcUaVariantSPtr_->getValue(value);
    }

    bool
	OpcUaDataValue::getValue(OpcUaInt16& value)
    {
    	if (opcUaVariantSPtr_.get() == nullptr) {
    		return false;
    	}
    	return opcUaVariantSPtr_->getValue(value);
    }

    bool
	OpcUaDataValue::getValue(OpcUaUInt16& value)
    {
    	if (opcUaVariantSPtr_.get() == nullptr) {
    		return false;
    	}
    	return opcUaVariantSPtr_->getValue(value);
    }

    bool
	OpcUaDataValue::getValue(OpcUaInt32& value)
    {
    	if (opcUaVariantSPtr_.get() == nullptr) {
    		return false;
    	}
    	return opcUaVariantSPtr_->getValue(value);
    }

    bool
	OpcUaDataValue::getValue(OpcUaUInt32& value)
    {
    	if (opcUaVariantSPtr_.get() == nullptr) {
    		return false;
    	}
    	return opcUaVariantSPtr_->getValue(value);
    }

    bool
	OpcUaDataValue::getValue(OpcUaInt64& value)
    {
    	if (opcUaVariantSPtr_.get() == nullptr) {
    		return false;
    	}
    	return opcUaVariantSPtr_->getValue(value);
    }

    bool
	OpcUaDataValue::getValue(OpcUaUInt64& value)
    {
    	if (opcUaVariantSPtr_.get() == nullptr) {
    		return false;
    	}
    	return opcUaVariantSPtr_->getValue(value);
    }

    bool
	OpcUaDataValue::getValue(OpcUaDouble& value)
    {
    	if (opcUaVariantSPtr_.get() == nullptr) {
    		return false;
    	}
    	return opcUaVariantSPtr_->getValue(value);
    }

    bool
 	OpcUaDataValue::getValue(OpcUaFloat& value)
     {
     	if (opcUaVariantSPtr_.get() == nullptr) {
     		return false;
     	}
     	return opcUaVariantSPtr_->getValue(value);
     }

    bool
	OpcUaDataValue::getValue(OpcUaString& value)
    {
    	if (opcUaVariantSPtr_.get() == nullptr) {
    		return false;
    	}
    	return opcUaVariantSPtr_->getValue(value);
    }

    bool
	OpcUaDataValue::getValue(OpcUaDateTime& value)
    {
    	if (opcUaVariantSPtr_.get() == nullptr) {
    		return false;
    	}
    	return opcUaVariantSPtr_->getValue(value);
    }

    bool
	OpcUaDataValue::getValue(OpcUaGuid& value)
    {
    	if (opcUaVariantSPtr_.get() == nullptr) {
    		return false;
    	}
    	return opcUaVariantSPtr_->getValue(value);
    }

    bool
	OpcUaDataValue::getValue(OpcUaByteString& value)
    {
    	if (opcUaVariantSPtr_.get() == nullptr) {
    		return false;
    	}
    	return opcUaVariantSPtr_->getValue(value);
    }

    bool
	OpcUaDataValue::getValue(OpcUaXmlElement& value)
    {
    	if (opcUaVariantSPtr_.get() == nullptr) {
    		return false;
    	}
    	return opcUaVariantSPtr_->getValue(value);
    }

    bool
	OpcUaDataValue::getValue(OpcUaNodeId& value)
    {
    	if (opcUaVariantSPtr_.get() == nullptr) {
    		return false;
    	}
    	return opcUaVariantSPtr_->getValue(value);
    }

    bool
	OpcUaDataValue::getValue(OpcUaExpandedNodeId& value)
    {
    	if (opcUaVariantSPtr_.get() == nullptr) {
    		return false;
    	}
    	return opcUaVariantSPtr_->getValue(value);
    }

    bool
	OpcUaDataValue::getValue(OpcUaStatusCode& value)
    {
    	if (opcUaVariantSPtr_.get() == nullptr) {
    		return false;
    	}
    	return opcUaVariantSPtr_->getValue(value);
    }

    bool
	OpcUaDataValue::getValue(OpcUaQualifiedName& value)
    {
    	if (opcUaVariantSPtr_.get() == nullptr) {
    		return false;
    	}
    	return opcUaVariantSPtr_->getValue(value);
    }

    bool
	OpcUaDataValue::getValue(OpcUaLocalizedText& value)
    {
    	if (opcUaVariantSPtr_.get() == nullptr) {
    		return false;
    	}
    	return opcUaVariantSPtr_->getValue(value);
    }

    bool
	OpcUaDataValue::getValue(OpcUaExtensionObject& value)
    {
    	if (opcUaVariantSPtr_.get() == nullptr) {
    		return false;
    	}
    	return opcUaVariantSPtr_->getValue(value);
    }

     bool
 	OpcUaDataValue::getValue(OpcUaBooleanArray& value)
     {
     	if (opcUaVariantSPtr_.get() == nullptr) {
     		return false;
     	}
     	if (!opcUaVariantSPtr_->isArray()) {
     		return false;
     	}
     	value.resize(opcUaVariantSPtr_->arrayLength());
     	for (uint32_t idx = 0; idx < opcUaVariantSPtr_->arrayLength(); idx++) {
     		value.push_back(opcUaVariantSPtr_->get<OpcUaBoolean>(idx));
     	}
     	return true;
     }

     bool
 	OpcUaDataValue::getValue(OpcUaByteArray& value)
     {
     	if (opcUaVariantSPtr_.get() == nullptr) {
     		return false;
     	}
     	if (!opcUaVariantSPtr_->isArray()) {
     		return false;
     	}
     	value.resize(opcUaVariantSPtr_->arrayLength());
     	for (uint32_t idx = 0; idx < opcUaVariantSPtr_->arrayLength(); idx++) {
     		value.push_back(opcUaVariantSPtr_->get<OpcUaByte>(idx));
     	}
     	return true;
     }

     bool
 	OpcUaDataValue::getValue(OpcUaSByteArray& value)
     {
        	if (opcUaVariantSPtr_.get() == nullptr) {
         	return false;
         }
         if (!opcUaVariantSPtr_->isArray()) {
         	return false;
         }
         value.resize(opcUaVariantSPtr_->arrayLength());
         for (uint32_t idx = 0; idx < opcUaVariantSPtr_->arrayLength(); idx++) {
         	value.push_back(opcUaVariantSPtr_->get<OpcUaSByte>(idx));
         }
         return true;
     }

     bool
 	OpcUaDataValue::getValue(OpcUaInt16Array& value)
     {
        	if (opcUaVariantSPtr_.get() == nullptr) {
         	return false;
         }
         if (!opcUaVariantSPtr_->isArray()) {
         	return false;
         }
         value.resize(opcUaVariantSPtr_->arrayLength());
         for (uint32_t idx = 0; idx < opcUaVariantSPtr_->arrayLength(); idx++) {
         	value.push_back(opcUaVariantSPtr_->get<OpcUaInt16>(idx));
         }
         return true;
     }

     bool
 	OpcUaDataValue::getValue(OpcUaUInt16Array& value)
     {
        	if (opcUaVariantSPtr_.get() == nullptr) {
         	return false;
         }
         if (!opcUaVariantSPtr_->isArray()) {
         	return false;
         }
         value.resize(opcUaVariantSPtr_->arrayLength());
         for (uint32_t idx = 0; idx < opcUaVariantSPtr_->arrayLength(); idx++) {
         	value.push_back(opcUaVariantSPtr_->get<OpcUaUInt16>(idx));
         }
         return true;
     }

     bool
 	OpcUaDataValue::getValue(OpcUaInt32Array& value)
     {
       	if (opcUaVariantSPtr_.get() == nullptr) {
         	return false;
         }
         if (!opcUaVariantSPtr_->isArray()) {
         	return false;
         }
         value.resize(opcUaVariantSPtr_->arrayLength());
         for (uint32_t idx = 0; idx < opcUaVariantSPtr_->arrayLength(); idx++) {
         	value.push_back(opcUaVariantSPtr_->get<OpcUaInt32>(idx));
         }
         return true;
     }

     bool
 	OpcUaDataValue::getValue(OpcUaUInt32Array& value)
     {
       	if (opcUaVariantSPtr_.get() == nullptr) {
         	return false;
         }
         if (!opcUaVariantSPtr_->isArray()) {
         	return false;
         }
         value.resize(opcUaVariantSPtr_->arrayLength());
         for (uint32_t idx = 0; idx < opcUaVariantSPtr_->arrayLength(); idx++) {
         	value.push_back(opcUaVariantSPtr_->get<OpcUaUInt32>(idx));
         }
         return true;
     }

     bool
 	OpcUaDataValue::getValue(OpcUaInt64Array& value)
     {
       	if (opcUaVariantSPtr_.get() == nullptr) {
         	return false;
         }
         if (!opcUaVariantSPtr_->isArray()) {
         	return false;
         }
         value.resize(opcUaVariantSPtr_->arrayLength());
         for (uint32_t idx = 0; idx < opcUaVariantSPtr_->arrayLength(); idx++) {
         	value.push_back(opcUaVariantSPtr_->get<OpcUaInt64>(idx));
         }
         return true;
     }

     bool
 	OpcUaDataValue::getValue(OpcUaUInt64Array& value)
     {
      	if (opcUaVariantSPtr_.get() == nullptr) {
         	return false;
         }
         if (!opcUaVariantSPtr_->isArray()) {
         	return false;
         }
         value.resize(opcUaVariantSPtr_->arrayLength());
         for (uint32_t idx = 0; idx < opcUaVariantSPtr_->arrayLength(); idx++) {
         	value.push_back(opcUaVariantSPtr_->get<OpcUaUInt64>(idx));
         }
         return true;
     }

     bool
 	OpcUaDataValue::getValue(OpcUaDoubleArray& value)
     {
      	if (opcUaVariantSPtr_.get() == nullptr) {
         	return false;
         }
         if (!opcUaVariantSPtr_->isArray()) {
         	return false;
         }
         value.resize(opcUaVariantSPtr_->arrayLength());
         for (uint32_t idx = 0; idx < opcUaVariantSPtr_->arrayLength(); idx++) {
         	value.push_back(opcUaVariantSPtr_->get<OpcUaDouble>(idx));
         }
         return true;
     }

     bool
 	OpcUaDataValue::getValue(OpcUaFloatArray& value)
     {
      	if (opcUaVariantSPtr_.get() == nullptr) {
         	return false;
         }
         if (!opcUaVariantSPtr_->isArray()) {
         	return false;
         }
         value.resize(opcUaVariantSPtr_->arrayLength());
         for (uint32_t idx = 0; idx < opcUaVariantSPtr_->arrayLength(); idx++) {
         	value.push_back(opcUaVariantSPtr_->get<OpcUaFloat>(idx));
         }
         return true;
     }

     bool
 	OpcUaDataValue::getValue(OpcUaStringArray& value)
     {
     	if (opcUaVariantSPtr_.get() == nullptr) {
         	return false;
         }
         if (!opcUaVariantSPtr_->isArray()) {
         	return false;
         }
         value.resize(opcUaVariantSPtr_->arrayLength());
         for (uint32_t idx = 0; idx < opcUaVariantSPtr_->arrayLength(); idx++) {
         	value.push_back(opcUaVariantSPtr_->getSPtr<OpcUaString>(idx));
         }
         return true;
     }

     bool
 	OpcUaDataValue::getValue(OpcUaDateTimeArray& value)
     {
     	if (opcUaVariantSPtr_.get() == nullptr) {
         	return false;
         }
         if (!opcUaVariantSPtr_->isArray()) {
         	return false;
         }
         value.resize(opcUaVariantSPtr_->arrayLength());
         for (uint32_t idx = 0; idx < opcUaVariantSPtr_->arrayLength(); idx++) {
         	value.push_back(opcUaVariantSPtr_->get<OpcUaDateTime>(idx));
         }
         return true;
     }

     bool
 	OpcUaDataValue::getValue(OpcUaGuidArray& value)
     {
     	if (opcUaVariantSPtr_.get() == nullptr) {
         	return false;
         }
         if (!opcUaVariantSPtr_->isArray()) {
         	return false;
         }
         value.resize(opcUaVariantSPtr_->arrayLength());
         for (uint32_t idx = 0; idx < opcUaVariantSPtr_->arrayLength(); idx++) {
         	value.push_back(opcUaVariantSPtr_->getSPtr<OpcUaGuid>(idx));
         }
         return true;
     }

     bool
 	OpcUaDataValue::getValue(OpcUaByteStringArray& value)
     {
     	if (opcUaVariantSPtr_.get() == nullptr) {
         	return false;
         }
         if (!opcUaVariantSPtr_->isArray()) {
         	return false;
         }
         value.resize(opcUaVariantSPtr_->arrayLength());
         for (uint32_t idx = 0; idx < opcUaVariantSPtr_->arrayLength(); idx++) {
         	value.push_back(opcUaVariantSPtr_->getSPtr<OpcUaByteString>(idx));
         }
         return true;
     }

     bool
 	OpcUaDataValue::getValue(OpcUaXmlElementArray& value)
     {
     	if (opcUaVariantSPtr_.get() == nullptr) {
         	return false;
         }
         if (!opcUaVariantSPtr_->isArray()) {
         	return false;
         }
         value.resize(opcUaVariantSPtr_->arrayLength());
         for (uint32_t idx = 0; idx < opcUaVariantSPtr_->arrayLength(); idx++) {
         	value.push_back(opcUaVariantSPtr_->getSPtr<OpcUaXmlElement>(idx));
         }
         return true;
     }

     bool
 	OpcUaDataValue::getValue(OpcUaNodeIdArray& value)
     {
     	if (opcUaVariantSPtr_.get() == nullptr) {
         	return false;
         }
         if (!opcUaVariantSPtr_->isArray()) {
         	return false;
         }
         value.resize(opcUaVariantSPtr_->arrayLength());
         for (uint32_t idx = 0; idx < opcUaVariantSPtr_->arrayLength(); idx++) {
         	value.push_back(opcUaVariantSPtr_->getSPtr<OpcUaNodeId>(idx));
         }
         return true;
     }

     bool
 	OpcUaDataValue::getValue(OpcUaExpandedNodeIdArray& value)
     {
     	if (opcUaVariantSPtr_.get() == nullptr) {
         	return false;
         }
         if (!opcUaVariantSPtr_->isArray()) {
         	return false;
         }
         value.resize(opcUaVariantSPtr_->arrayLength());
         for (uint32_t idx = 0; idx < opcUaVariantSPtr_->arrayLength(); idx++) {
         	value.push_back(opcUaVariantSPtr_->getSPtr<OpcUaExpandedNodeId>(idx));
         }
         return true;
     }

     bool
 	OpcUaDataValue::getValue(OpcUaStatusCodeArray& value)
     {
     	if (opcUaVariantSPtr_.get() == nullptr) {
         	return false;
         }
         if (!opcUaVariantSPtr_->isArray()) {
         	return false;
         }
         value.resize(opcUaVariantSPtr_->arrayLength());
         for (uint32_t idx = 0; idx < opcUaVariantSPtr_->arrayLength(); idx++) {
         	value.push_back(opcUaVariantSPtr_->get<OpcUaStatusCode>(idx));
         }
         return true;
     }

     bool
 	OpcUaDataValue::getValue(OpcUaQualifiedNameArray& value)
     {
     	if (opcUaVariantSPtr_.get() == nullptr) {
         	return false;
         }
         if (!opcUaVariantSPtr_->isArray()) {
         	return false;
         }
         value.resize(opcUaVariantSPtr_->arrayLength());
         for (uint32_t idx = 0; idx < opcUaVariantSPtr_->arrayLength(); idx++) {
         	value.push_back(opcUaVariantSPtr_->getSPtr<OpcUaQualifiedName>(idx));
         }
         return true;
     }

     bool
 	OpcUaDataValue::getValue(OpcUaLocalizedTextArray& value)
     {
     	if (opcUaVariantSPtr_.get() == nullptr) {
         	return false;
         }
         if (!opcUaVariantSPtr_->isArray()) {
         	return false;
         }
         value.resize(opcUaVariantSPtr_->arrayLength());
         for (uint32_t idx = 0; idx < opcUaVariantSPtr_->arrayLength(); idx++) {
         	value.push_back(opcUaVariantSPtr_->getSPtr<OpcUaLocalizedText>(idx));
         }
         return true;
     }

     bool
 	OpcUaDataValue::getValue(OpcUaExtensionObjectArray& value)
     {
     	if (opcUaVariantSPtr_.get() == nullptr) {
         	return false;
         }
         if (!opcUaVariantSPtr_->isArray()) {
         	return false;
         }
         value.resize(opcUaVariantSPtr_->arrayLength());
         for (uint32_t idx = 0; idx < opcUaVariantSPtr_->arrayLength(); idx++) {
         	value.push_back(opcUaVariantSPtr_->getSPtr<OpcUaExtensionObject>(idx));
         }
         return true;
     }


     bool
 	OpcUaDataValue::getValue(std::vector<OpcUaBoolean>& value)
     {
     	if (opcUaVariantSPtr_.get() == nullptr) {
         	return false;
         }
         if (!opcUaVariantSPtr_->isArray()) {
         	return false;
         }
         for (uint32_t idx = 0; idx < opcUaVariantSPtr_->arrayLength(); idx++) {
         	value.push_back(opcUaVariantSPtr_->get<OpcUaBoolean>(idx));
         }
         return true;
     }

     bool
 	OpcUaDataValue::getValue(std::vector<OpcUaByte>& value)
     {
     	if (opcUaVariantSPtr_.get() == nullptr) {
         	return false;
         }
         if (!opcUaVariantSPtr_->isArray()) {
         	return false;
         }
         for (uint32_t idx = 0; idx < opcUaVariantSPtr_->arrayLength(); idx++) {
         	value.push_back(opcUaVariantSPtr_->get<OpcUaByte>(idx));
         }
         return true;
     }

     bool
 	OpcUaDataValue::getValue(std::vector<OpcUaSByte>& value)
     {
     	if (opcUaVariantSPtr_.get() == nullptr) {
         	return false;
         }
         if (!opcUaVariantSPtr_->isArray()) {
         	return false;
         }
         for (uint32_t idx = 0; idx < opcUaVariantSPtr_->arrayLength(); idx++) {
         	value.push_back(opcUaVariantSPtr_->get<OpcUaSByte>(idx));
         }
         return true;
     }

     bool
 	OpcUaDataValue::getValue(std::vector<OpcUaInt16>& value)
     {
     	if (opcUaVariantSPtr_.get() == nullptr) {
         	return false;
         }
         if (!opcUaVariantSPtr_->isArray()) {
         	return false;
         }
         for (uint32_t idx = 0; idx < opcUaVariantSPtr_->arrayLength(); idx++) {
         	value.push_back(opcUaVariantSPtr_->get<OpcUaInt16>(idx));
         }
         return true;
     }

     bool
 	OpcUaDataValue::getValue(std::vector<OpcUaUInt16>& value)
     {
     	if (opcUaVariantSPtr_.get() == nullptr) {
         	return false;
         }
         if (!opcUaVariantSPtr_->isArray()) {
         	return false;
         }
         for (uint32_t idx = 0; idx < opcUaVariantSPtr_->arrayLength(); idx++) {
         	value.push_back(opcUaVariantSPtr_->get<OpcUaUInt16>(idx));
         }
         return true;
     }

     bool
 	OpcUaDataValue::getValue(std::vector<OpcUaInt32>& value)
     {
     	if (opcUaVariantSPtr_.get() == nullptr) {
         	return false;
         }
         if (!opcUaVariantSPtr_->isArray()) {
         	return false;
         }
         for (uint32_t idx = 0; idx < opcUaVariantSPtr_->arrayLength(); idx++) {
         	value.push_back(opcUaVariantSPtr_->get<OpcUaInt32>(idx));
         }
         return true;
     }

     bool
 	OpcUaDataValue::getValue(std::vector<OpcUaUInt32>& value)
     {
     	if (opcUaVariantSPtr_.get() == nullptr) {
         	return false;
         }
         if (!opcUaVariantSPtr_->isArray()) {
         	return false;
         }
         for (uint32_t idx = 0; idx < opcUaVariantSPtr_->arrayLength(); idx++) {
         	value.push_back(opcUaVariantSPtr_->get<OpcUaUInt32>(idx));
         }
         return true;
     }

     bool
 	OpcUaDataValue::getValue(std::vector<OpcUaInt64>& value)
     {
        	if (opcUaVariantSPtr_.get() == nullptr) {
             return false;
         }
         if (!opcUaVariantSPtr_->isArray()) {
             return false;
         }
         for (uint32_t idx = 0; idx < opcUaVariantSPtr_->arrayLength(); idx++) {
             value.push_back(opcUaVariantSPtr_->get<OpcUaInt64>(idx));
         }
         return true;
     }

     bool
 	OpcUaDataValue::getValue(std::vector<OpcUaUInt64>& value)
     {
        	if (opcUaVariantSPtr_.get() == nullptr) {
             return false;
         }
         if (!opcUaVariantSPtr_->isArray()) {
             return false;
         }
         for (uint32_t idx = 0; idx < opcUaVariantSPtr_->arrayLength(); idx++) {
             value.push_back(opcUaVariantSPtr_->get<OpcUaUInt64>(idx));
         }
         return true;
     }

     bool
 	OpcUaDataValue::getValue(std::vector<OpcUaDouble>& value)
     {
        	if (opcUaVariantSPtr_.get() == nullptr) {
             return false;
         }
         if (!opcUaVariantSPtr_->isArray()) {
             return false;
         }
         for (uint32_t idx = 0; idx < opcUaVariantSPtr_->arrayLength(); idx++) {
             value.push_back(opcUaVariantSPtr_->get<OpcUaDouble>(idx));
         }
         return true;
     }

     bool
 	OpcUaDataValue::getValue(std::vector<OpcUaFloat>& value)
     {
        	if (opcUaVariantSPtr_.get() == nullptr) {
             return false;
         }
         if (!opcUaVariantSPtr_->isArray()) {
             return false;
         }
         for (uint32_t idx = 0; idx < opcUaVariantSPtr_->arrayLength(); idx++) {
             value.push_back(opcUaVariantSPtr_->get<OpcUaFloat>(idx));
         }
         return true;
     }

     bool
 	OpcUaDataValue::getValue(std::vector<OpcUaString::SPtr>& value)
     {
        	if (opcUaVariantSPtr_.get() == nullptr) {
             return false;
         }
         if (!opcUaVariantSPtr_->isArray()) {
             return false;
         }
         for (uint32_t idx = 0; idx < opcUaVariantSPtr_->arrayLength(); idx++) {
             value.push_back(opcUaVariantSPtr_->getSPtr<OpcUaString>(idx));
         }
         return true;
     }

     bool
 	OpcUaDataValue::getValue(std::vector<OpcUaDateTime>& value)
     {
        	if (opcUaVariantSPtr_.get() == nullptr) {
             return false;
         }
         if (!opcUaVariantSPtr_->isArray()) {
             return false;
         }
         for (uint32_t idx = 0; idx < opcUaVariantSPtr_->arrayLength(); idx++) {
             value.push_back(opcUaVariantSPtr_->get<OpcUaDateTime>(idx));
         }
         return true;
     }

     bool
 	OpcUaDataValue::getValue(std::vector<OpcUaGuid::SPtr>& value)
     {
        	if (opcUaVariantSPtr_.get() == nullptr) {
             return false;
         }
         if (!opcUaVariantSPtr_->isArray()) {
             return false;
         }
         for (uint32_t idx = 0; idx < opcUaVariantSPtr_->arrayLength(); idx++) {
             value.push_back(opcUaVariantSPtr_->getSPtr<OpcUaGuid>(idx));
         }
         return true;
     }

     bool
 	OpcUaDataValue::getValue(std::vector<OpcUaByteString::SPtr>& value)
     {
        	if (opcUaVariantSPtr_.get() == nullptr) {
             return false;
         }
         if (!opcUaVariantSPtr_->isArray()) {
             return false;
         }
         for (uint32_t idx = 0; idx < opcUaVariantSPtr_->arrayLength(); idx++) {
             value.push_back(opcUaVariantSPtr_->getSPtr<OpcUaByteString>(idx));
         }
         return true;
     }

     bool
 	OpcUaDataValue::getValue(std::vector<OpcUaXmlElement::SPtr>& value)
     {
        	if (opcUaVariantSPtr_.get() == nullptr) {
             return false;
         }
         if (!opcUaVariantSPtr_->isArray()) {
             return false;
         }
         for (uint32_t idx = 0; idx < opcUaVariantSPtr_->arrayLength(); idx++) {
             value.push_back(opcUaVariantSPtr_->getSPtr<OpcUaXmlElement>(idx));
         }
         return true;
     }

     bool
 	OpcUaDataValue::getValue(std::vector<OpcUaNodeId::SPtr>& value)
     {
        	if (opcUaVariantSPtr_.get() == nullptr) {
             return false;
         }
         if (!opcUaVariantSPtr_->isArray()) {
             return false;
         }
         for (uint32_t idx = 0; idx < opcUaVariantSPtr_->arrayLength(); idx++) {
             value.push_back(opcUaVariantSPtr_->getSPtr<OpcUaNodeId>(idx));
         }
         return true;
     }

     bool
 	OpcUaDataValue::getValue(std::vector<OpcUaExpandedNodeId::SPtr>& value)
     {
       	if (opcUaVariantSPtr_.get() == nullptr) {
             return false;
         }
         if (!opcUaVariantSPtr_->isArray()) {
             return false;
         }
         for (uint32_t idx = 0; idx < opcUaVariantSPtr_->arrayLength(); idx++) {
             value.push_back(opcUaVariantSPtr_->getSPtr<OpcUaExpandedNodeId>(idx));
         }
         return true;
     }

     bool
 	OpcUaDataValue::getValue(std::vector<OpcUaStatusCode>& value)
     {
      	if (opcUaVariantSPtr_.get() == nullptr) {
             return false;
         }
         if (!opcUaVariantSPtr_->isArray()) {
             return false;
         }
         for (uint32_t idx = 0; idx < opcUaVariantSPtr_->arrayLength(); idx++) {
             value.push_back(opcUaVariantSPtr_->get<OpcUaStatusCode>(idx));
         }
         return true;
     }

     bool
 	OpcUaDataValue::getValue(std::vector<OpcUaQualifiedName::SPtr>& value)
     {
       	if (opcUaVariantSPtr_.get() == nullptr) {
             return false;
         }
         if (!opcUaVariantSPtr_->isArray()) {
             return false;
         }
         for (uint32_t idx = 0; idx < opcUaVariantSPtr_->arrayLength(); idx++) {
             value.push_back(opcUaVariantSPtr_->getSPtr<OpcUaQualifiedName>(idx));
         }
         return true;
     }

     bool
 	OpcUaDataValue::getValue(std::vector<OpcUaLocalizedText::SPtr>& value)
     {
       	if (opcUaVariantSPtr_.get() == nullptr) {
             return false;
         }
         if (!opcUaVariantSPtr_->isArray()) {
             return false;
         }
         for (uint32_t idx = 0; idx < opcUaVariantSPtr_->arrayLength(); idx++) {
             value.push_back(opcUaVariantSPtr_->getSPtr<OpcUaLocalizedText>(idx));
         }
         return true;
     }

     bool
 	 OpcUaDataValue::getValue(std::vector<OpcUaExtensionObject::SPtr>& value)
     {
      	if (opcUaVariantSPtr_.get() == nullptr) {
             return false;
         }
         if (!opcUaVariantSPtr_->isArray()) {
             return false;
         }
         for (uint32_t idx = 0; idx < opcUaVariantSPtr_->arrayLength(); idx++) {
             value.push_back(opcUaVariantSPtr_->getSPtr<OpcUaExtensionObject>(idx));
         }
         return true;
     }

    void
	OpcUaDataValue::set(const OpcUaNullValue& value, OpcUaStatusCode statusCode, const OpcUaDateTime& sourceTimestamp)
    {
    	opcUaVariantSPtr_.reset();
    	opcUaStatusCode_ = statusCode;
    	sourceTimestamp_ = sourceTimestamp;
    }

    void
	OpcUaDataValue::set(const OpcUaBoolean& value, OpcUaStatusCode statusCode, const OpcUaDateTime& sourceTimestamp)
    {
    	variant()->setValue(value);
    	opcUaStatusCode_ = statusCode;
    	sourceTimestamp_ = sourceTimestamp;
    }

    void
	OpcUaDataValue::set(const OpcUaByte& value, OpcUaStatusCode statusCode, const OpcUaDateTime& sourceTimestamp)
    {
    	variant()->setValue(value);
    	opcUaStatusCode_ = statusCode;
    	sourceTimestamp_ = sourceTimestamp;
    }

    void
	OpcUaDataValue::set(const OpcUaSByte& value, OpcUaStatusCode statusCode, const OpcUaDateTime& sourceTimestamp)
    {
    	variant()->setValue(value);
    	opcUaStatusCode_ = statusCode;
    	sourceTimestamp_ = sourceTimestamp;
    }

    void
	OpcUaDataValue::set(const OpcUaInt16& value, OpcUaStatusCode statusCode, const OpcUaDateTime& sourceTimestamp)
    {
    	variant()->setValue(value);
    	opcUaStatusCode_ = statusCode;
    	sourceTimestamp_ = sourceTimestamp;
    }

    void
	OpcUaDataValue::set(const OpcUaUInt16& value, OpcUaStatusCode statusCode, const OpcUaDateTime& sourceTimestamp)
    {
    	variant()->setValue(value);
    	opcUaStatusCode_ = statusCode;
    	sourceTimestamp_ = sourceTimestamp;
    }

    void
	OpcUaDataValue::set(const OpcUaInt32& value, OpcUaStatusCode statusCode, const OpcUaDateTime& sourceTimestamp)
    {
    	variant()->setValue(value);
    	opcUaStatusCode_ = statusCode;
    	sourceTimestamp_ = sourceTimestamp;
    }

    void
	OpcUaDataValue::set(const OpcUaUInt32& value, OpcUaStatusCode statusCode, const OpcUaDateTime& sourceTimestamp)
    {
    	variant()->setValue(value);
    	opcUaStatusCode_ = statusCode;
    	sourceTimestamp_ = sourceTimestamp;
    }

    void
	OpcUaDataValue::set(const OpcUaInt64& value, OpcUaStatusCode statusCode, const OpcUaDateTime& sourceTimestamp)
    {
    	variant()->setValue(value);
    	opcUaStatusCode_ = statusCode;
    	sourceTimestamp_ = sourceTimestamp;
    }

    void
	OpcUaDataValue::set(const OpcUaUInt64& value, OpcUaStatusCode statusCode, const OpcUaDateTime& sourceTimestamp)
    {
    	variant()->setValue(value);
    	opcUaStatusCode_ = statusCode;
    	sourceTimestamp_ = sourceTimestamp;
    }

    void
	OpcUaDataValue::set(const OpcUaString& value, OpcUaStatusCode statusCode, const OpcUaDateTime& sourceTimestamp)
    {
    	variant()->setValue(value);
    	opcUaStatusCode_ = statusCode;
    	sourceTimestamp_ = sourceTimestamp;
    }

    void
	OpcUaDataValue::set(const OpcUaDateTime& value, OpcUaStatusCode statusCode, const OpcUaDateTime& sourceTimestamp)
    {
    	variant()->setValue(value);
    	opcUaStatusCode_ = statusCode;
    	sourceTimestamp_ = sourceTimestamp;
    }

    void
	OpcUaDataValue::set(const OpcUaGuid& value, OpcUaStatusCode statusCode, const OpcUaDateTime& sourceTimestamp)
    {
    	variant()->setValue(value);
    	opcUaStatusCode_ = statusCode;
    	sourceTimestamp_ = sourceTimestamp;
    }

    void
	OpcUaDataValue::set(const OpcUaByteString& value, OpcUaStatusCode statusCode, const OpcUaDateTime& sourceTimestamp)
    {
    	variant()->setValue(value);
    	opcUaStatusCode_ = statusCode;
    	sourceTimestamp_ = sourceTimestamp;
    }

    void
	OpcUaDataValue::set(const OpcUaXmlElement& value, OpcUaStatusCode statusCode, const OpcUaDateTime& sourceTimestamp)
    {
    	variant()->setValue(value);
    	opcUaStatusCode_ = statusCode;
    	sourceTimestamp_ = sourceTimestamp;
    }

    void
	OpcUaDataValue::set(const OpcUaNodeId& value, OpcUaStatusCode statusCode, const OpcUaDateTime& sourceTimestamp)
    {
    	variant()->setValue(value);
    	opcUaStatusCode_ = statusCode;
    	sourceTimestamp_ = sourceTimestamp;
    }

    void
	OpcUaDataValue::set(const OpcUaExpandedNodeId& value, OpcUaStatusCode statusCode, const OpcUaDateTime& sourceTimestamp)
    {
    	variant()->setValue(value);
    	opcUaStatusCode_ = statusCode;
    	sourceTimestamp_ = sourceTimestamp;
    }

    void
	OpcUaDataValue::set(const OpcUaStatusCode& value, OpcUaStatusCode statusCode, const OpcUaDateTime& sourceTimestamp)
    {
    	variant()->setValue(value);
    	opcUaStatusCode_ = statusCode;
    	sourceTimestamp_ = sourceTimestamp;
    }

    void
	OpcUaDataValue::set(const OpcUaQualifiedName& value, OpcUaStatusCode statusCode, const OpcUaDateTime& sourceTimestamp)
    {
    	variant()->setValue(value);
    	opcUaStatusCode_ = statusCode;
    	sourceTimestamp_ = sourceTimestamp;
    }

    void
	OpcUaDataValue::set(const OpcUaLocalizedText& value, OpcUaStatusCode statusCode, const OpcUaDateTime& sourceTimestamp)
    {
    	variant()->setValue(value);
    	opcUaStatusCode_ = statusCode;
    	sourceTimestamp_ = sourceTimestamp;
    }

    void
	OpcUaDataValue::set(const OpcUaExtensionObject& value, OpcUaStatusCode statusCode, const OpcUaDateTime& sourceTimestamp)
    {
    	variant()->setValue(value);
    	opcUaStatusCode_ = statusCode;
    	sourceTimestamp_ = sourceTimestamp;
    }

    void
 	OpcUaDataValue::set(const OpcUaBooleanArray& value, OpcUaStatusCode statusCode, const OpcUaDateTime& sourceTimestamp)
     {
 		opcUaVariantSPtr_ = constructSPtr<OpcUaVariant>();
 		for (uint32_t idx = 0; idx < value.size(); idx++) {
 			OpcUaBoolean val;
 			const_cast<OpcUaBooleanArray*>(&value)->get(idx, val);
 			opcUaVariantSPtr_->pushBack(val);
 		}
     	opcUaStatusCode_ = statusCode;
     	sourceTimestamp_ = sourceTimestamp;
     }

     void
 	OpcUaDataValue::set(const OpcUaByteArray& value, OpcUaStatusCode statusCode, const OpcUaDateTime& sourceTimestamp)
     {
 		opcUaVariantSPtr_ = constructSPtr<OpcUaVariant>();
 		for (uint32_t idx = 0; idx < value.size(); idx++) {
 			OpcUaByte val;
 			const_cast<OpcUaByteArray*>(&value)->get(idx, val);
 			opcUaVariantSPtr_->pushBack(val);
 		}
     	opcUaStatusCode_ = statusCode;
     	sourceTimestamp_ = sourceTimestamp;
     }

     void
 	OpcUaDataValue::set(const OpcUaSByteArray& value, OpcUaStatusCode statusCode, const OpcUaDateTime& sourceTimestamp)
     {
 		opcUaVariantSPtr_ = constructSPtr<OpcUaVariant>();
 		for (uint32_t idx = 0; idx < value.size(); idx++) {
 			OpcUaSByte val;
 			const_cast<OpcUaSByteArray*>(&value)->get(idx, val);
 			opcUaVariantSPtr_->pushBack(val);
 		}
     	opcUaStatusCode_ = statusCode;
     	sourceTimestamp_ = sourceTimestamp;
     }

     void
 	OpcUaDataValue::set(const OpcUaInt16Array& value, OpcUaStatusCode statusCode, const OpcUaDateTime& sourceTimestamp)
     {
 		opcUaVariantSPtr_ = constructSPtr<OpcUaVariant>();
 		for (uint32_t idx = 0; idx < value.size(); idx++) {
 			OpcUaInt16 val;
 			const_cast<OpcUaInt16Array*>(&value)->get(idx, val);
 			opcUaVariantSPtr_->pushBack(val);
 		}
     	opcUaStatusCode_ = statusCode;
     	sourceTimestamp_ = sourceTimestamp;
     }

     void
 	OpcUaDataValue::set(const OpcUaUInt16Array& value, OpcUaStatusCode statusCode, const OpcUaDateTime& sourceTimestamp)
     {
 		opcUaVariantSPtr_ = constructSPtr<OpcUaVariant>();
 		for (uint32_t idx = 0; idx < value.size(); idx++) {
 			OpcUaUInt16 val;
 			const_cast<OpcUaUInt16Array*>(&value)->get(idx, val);
 			opcUaVariantSPtr_->pushBack(val);
 		}
     	opcUaStatusCode_ = statusCode;
     	sourceTimestamp_ = sourceTimestamp;
     }

     void
 	OpcUaDataValue::set(const OpcUaInt32Array& value, OpcUaStatusCode statusCode, const OpcUaDateTime& sourceTimestamp)
     {
 		opcUaVariantSPtr_ = constructSPtr<OpcUaVariant>();
 		for (uint32_t idx = 0; idx < value.size(); idx++) {
 			OpcUaInt32 val;
 			const_cast<OpcUaInt32Array*>(&value)->get(idx, val);
 			opcUaVariantSPtr_->pushBack(val);
 		}
     	opcUaStatusCode_ = statusCode;
     	sourceTimestamp_ = sourceTimestamp;
     }

     void
 	OpcUaDataValue::set(const OpcUaUInt32Array& value, OpcUaStatusCode statusCode, const OpcUaDateTime& sourceTimestamp)
     {
 		opcUaVariantSPtr_ = constructSPtr<OpcUaVariant>();
 		for (uint32_t idx = 0; idx < value.size(); idx++) {
 			OpcUaUInt32 val;
 			const_cast<OpcUaUInt32Array*>(&value)->get(idx, val);
 			opcUaVariantSPtr_->pushBack(val);
 		}
     	opcUaStatusCode_ = statusCode;
     	sourceTimestamp_ = sourceTimestamp;
     }

     void
 	OpcUaDataValue::set(const OpcUaInt64Array& value, OpcUaStatusCode statusCode, const OpcUaDateTime& sourceTimestamp)
     {
 		opcUaVariantSPtr_ = constructSPtr<OpcUaVariant>();
 		for (uint32_t idx = 0; idx < value.size(); idx++) {
 			OpcUaInt64 val;
 			const_cast<OpcUaInt64Array*>(&value)->get(idx, val);
 			opcUaVariantSPtr_->pushBack(val);
 		}
     	opcUaStatusCode_ = statusCode;
     	sourceTimestamp_ = sourceTimestamp;
     }

     void
 	OpcUaDataValue::set(const OpcUaUInt64Array& value, OpcUaStatusCode statusCode, const OpcUaDateTime& sourceTimestamp)
     {
 		opcUaVariantSPtr_ = constructSPtr<OpcUaVariant>();
 		for (uint32_t idx = 0; idx < value.size(); idx++) {
 			OpcUaUInt64 val;
 			const_cast<OpcUaUInt64Array*>(&value)->get(idx, val);
 			opcUaVariantSPtr_->pushBack(val);
 		}
     	opcUaStatusCode_ = statusCode;
     	sourceTimestamp_ = sourceTimestamp;
     }

     void
 	OpcUaDataValue::set(const OpcUaStringArray& value, OpcUaStatusCode statusCode, const OpcUaDateTime& sourceTimestamp)
     {
 		opcUaVariantSPtr_ = constructSPtr<OpcUaVariant>();
 		for (uint32_t idx = 0; idx < value.size(); idx++) {
 			OpcUaString::SPtr val;
 			const_cast<OpcUaStringArray*>(&value)->get(idx, val);
 			opcUaVariantSPtr_->pushBack(val);
 		}
     	opcUaStatusCode_ = statusCode;
     	sourceTimestamp_ = sourceTimestamp;
     }

     void
 	OpcUaDataValue::set(const OpcUaDateTimeArray& value, OpcUaStatusCode statusCode, const OpcUaDateTime& sourceTimestamp)
     {
 		opcUaVariantSPtr_ = constructSPtr<OpcUaVariant>();
 		for (uint32_t idx = 0; idx < value.size(); idx++) {
 			OpcUaDateTime val;
 			const_cast<OpcUaDateTimeArray*>(&value)->get(idx, val);
 			opcUaVariantSPtr_->pushBack(val);
 		}
     	opcUaStatusCode_ = statusCode;
     	sourceTimestamp_ = sourceTimestamp;
     }

     void
 	OpcUaDataValue::set(const OpcUaGuidArray& value, OpcUaStatusCode statusCode, const OpcUaDateTime& sourceTimestamp)
     {
 		opcUaVariantSPtr_ = constructSPtr<OpcUaVariant>();
 		for (uint32_t idx = 0; idx < value.size(); idx++) {
 			OpcUaGuid::SPtr val;
 			const_cast<OpcUaGuidArray*>(&value)->get(idx, val);
 			opcUaVariantSPtr_->pushBack(val);
 		}
     	opcUaStatusCode_ = statusCode;
     	sourceTimestamp_ = sourceTimestamp;
     }

     void
 	OpcUaDataValue::set(const OpcUaByteStringArray& value, OpcUaStatusCode statusCode, const OpcUaDateTime& sourceTimestamp)
     {
 		opcUaVariantSPtr_ = constructSPtr<OpcUaVariant>();
 		for (uint32_t idx = 0; idx < value.size(); idx++) {
 			OpcUaByteString::SPtr val;
 			const_cast<OpcUaByteStringArray*>(&value)->get(idx, val);
 			opcUaVariantSPtr_->pushBack(val);
 		}
     	opcUaStatusCode_ = statusCode;
     	sourceTimestamp_ = sourceTimestamp;
     }

     void
 	OpcUaDataValue::set(const OpcUaXmlElementArray& value, OpcUaStatusCode statusCode, const OpcUaDateTime& sourceTimestamp)
     {
 		opcUaVariantSPtr_ = constructSPtr<OpcUaVariant>();
 		for (uint32_t idx = 0; idx < value.size(); idx++) {
 			OpcUaXmlElement::SPtr val;
 			const_cast<OpcUaXmlElementArray*>(&value)->get(idx, val);
 			opcUaVariantSPtr_->pushBack(val);
 		}
     	opcUaStatusCode_ = statusCode;
     	sourceTimestamp_ = sourceTimestamp;
     }

     void
 	OpcUaDataValue::set(const OpcUaNodeIdArray& value, OpcUaStatusCode statusCode, const OpcUaDateTime& sourceTimestamp)
     {
 		opcUaVariantSPtr_ = constructSPtr<OpcUaVariant>();
 		for (uint32_t idx = 0; idx < value.size(); idx++) {
 			OpcUaNodeId::SPtr val;
 			const_cast<OpcUaNodeIdArray*>(&value)->get(idx, val);
 			opcUaVariantSPtr_->pushBack(val);
 		}
     	opcUaStatusCode_ = statusCode;
     	sourceTimestamp_ = sourceTimestamp;
     }

     void
 	OpcUaDataValue::set(const OpcUaExpandedNodeIdArray& value, OpcUaStatusCode statusCode, const OpcUaDateTime& sourceTimestamp)
     {
 		opcUaVariantSPtr_ = constructSPtr<OpcUaVariant>();
 		for (uint32_t idx = 0; idx < value.size(); idx++) {
 			OpcUaExpandedNodeId::SPtr val;
 			const_cast<OpcUaExpandedNodeIdArray*>(&value)->get(idx, val);
 			opcUaVariantSPtr_->pushBack(val);
 		}
     	opcUaStatusCode_ = statusCode;
     	sourceTimestamp_ = sourceTimestamp;
     }

     void
 	OpcUaDataValue::set(const OpcUaStatusCodeArray& value, OpcUaStatusCode statusCode, const OpcUaDateTime& sourceTimestamp)
     {
 		opcUaVariantSPtr_ = constructSPtr<OpcUaVariant>();
 		for (uint32_t idx = 0; idx < value.size(); idx++) {
 			OpcUaStatusCode val;
 			const_cast<OpcUaStatusCodeArray*>(&value)->get(idx, val);
 			opcUaVariantSPtr_->pushBack(val);
 		}
     	opcUaStatusCode_ = statusCode;
     	sourceTimestamp_ = sourceTimestamp;
     }

     void
 	OpcUaDataValue::set(const OpcUaQualifiedNameArray& value, OpcUaStatusCode statusCode, const OpcUaDateTime& sourceTimestamp)
     {
 		opcUaVariantSPtr_ = constructSPtr<OpcUaVariant>();
 		for (uint32_t idx = 0; idx < value.size(); idx++) {
 			OpcUaQualifiedName::SPtr val;
 			const_cast<OpcUaQualifiedNameArray*>(&value)->get(idx, val);
 			opcUaVariantSPtr_->pushBack(val);
 		}
     	opcUaStatusCode_ = statusCode;
     	sourceTimestamp_ = sourceTimestamp;
     }

     void
 	OpcUaDataValue::set(const OpcUaLocalizedTextArray& value, OpcUaStatusCode statusCode, const OpcUaDateTime& sourceTimestamp)
     {
 		opcUaVariantSPtr_ = constructSPtr<OpcUaVariant>();
 		for (uint32_t idx = 0; idx < value.size(); idx++) {
 			OpcUaLocalizedText::SPtr val;
 			const_cast<OpcUaLocalizedTextArray*>(&value)->get(idx, val);
 			opcUaVariantSPtr_->pushBack(val);
 		}
     	opcUaStatusCode_ = statusCode;
     	sourceTimestamp_ = sourceTimestamp;
     }

     void
 	OpcUaDataValue::set(const OpcUaExtensionObjectArray& value, OpcUaStatusCode statusCode, const OpcUaDateTime& sourceTimestamp)
     {
 		opcUaVariantSPtr_ = constructSPtr<OpcUaVariant>();
 		for (uint32_t idx = 0; idx < value.size(); idx++) {
 			OpcUaExtensionObject::SPtr val;
 			const_cast<OpcUaExtensionObjectArray*>(&value)->get(idx, val);
 			opcUaVariantSPtr_->pushBack(val);
 		}
     	opcUaStatusCode_ = statusCode;
     	sourceTimestamp_ = sourceTimestamp;
     }

     void
 	OpcUaDataValue::set(const std::vector<OpcUaBoolean>& value, OpcUaStatusCode statusCode, const OpcUaDateTime& sourceTimestamp)
     {
     	opcUaVariantSPtr_ = constructSPtr<OpcUaVariant>();
     	for (auto it = value.begin(); it != value.end(); it++) {
     		opcUaVariantSPtr_->pushBack(*it);
     	}
        	opcUaStatusCode_ = statusCode;
         sourceTimestamp_ = sourceTimestamp;
     }

     void
 	OpcUaDataValue::set(const std::vector<OpcUaByte>& value, OpcUaStatusCode statusCode, const OpcUaDateTime& sourceTimestamp)
     {
     	opcUaVariantSPtr_ = constructSPtr<OpcUaVariant>();
     	for (auto it = value.begin(); it != value.end(); it++) {
     		opcUaVariantSPtr_->pushBack(*it);
     	}
        	opcUaStatusCode_ = statusCode;
         sourceTimestamp_ = sourceTimestamp;
     }

     void
 	OpcUaDataValue::set(const std::vector<OpcUaSByte>& value, OpcUaStatusCode statusCode, const OpcUaDateTime& sourceTimestamp)
     {
     	opcUaVariantSPtr_ = constructSPtr<OpcUaVariant>();
     	for (auto it = value.begin(); it != value.end(); it++) {
     		opcUaVariantSPtr_->pushBack(*it);
     	}
        	opcUaStatusCode_ = statusCode;
         sourceTimestamp_ = sourceTimestamp;
     }

     void
 	OpcUaDataValue::set(const std::vector<OpcUaInt16>& value, OpcUaStatusCode statusCode, const OpcUaDateTime& sourceTimestamp)
     {
     	opcUaVariantSPtr_ = constructSPtr<OpcUaVariant>();
     	for (auto it = value.begin(); it != value.end(); it++) {
     		opcUaVariantSPtr_->pushBack(*it);
     	}
        	opcUaStatusCode_ = statusCode;
         sourceTimestamp_ = sourceTimestamp;
     }

     void
 	OpcUaDataValue::set(const std::vector<OpcUaUInt16>& value, OpcUaStatusCode statusCode, const OpcUaDateTime& sourceTimestamp)
     {
     	opcUaVariantSPtr_ = constructSPtr<OpcUaVariant>();
     	for (auto it = value.begin(); it != value.end(); it++) {
     		opcUaVariantSPtr_->pushBack(*it);
     	}
        	opcUaStatusCode_ = statusCode;
         sourceTimestamp_ = sourceTimestamp;
     }

     void
 	OpcUaDataValue::set(const std::vector<OpcUaInt32>& value, OpcUaStatusCode statusCode, const OpcUaDateTime& sourceTimestamp)
     {
     	opcUaVariantSPtr_ = constructSPtr<OpcUaVariant>();
     	for (auto it = value.begin(); it != value.end(); it++) {
     		opcUaVariantSPtr_->pushBack(*it);
     	}
        	opcUaStatusCode_ = statusCode;
         sourceTimestamp_ = sourceTimestamp;
     }

     void
 	OpcUaDataValue::set(const std::vector<OpcUaUInt32>& value, OpcUaStatusCode statusCode, const OpcUaDateTime& sourceTimestamp)
     {
     	opcUaVariantSPtr_ = constructSPtr<OpcUaVariant>();
     	for (auto it = value.begin(); it != value.end(); it++) {
     		opcUaVariantSPtr_->pushBack(*it);
     	}
        	opcUaStatusCode_ = statusCode;
         sourceTimestamp_ = sourceTimestamp;
     }

     void
 	OpcUaDataValue::set(const std::vector<OpcUaInt64>& value, OpcUaStatusCode statusCode, const OpcUaDateTime& sourceTimestamp)
     {
     	opcUaVariantSPtr_ = constructSPtr<OpcUaVariant>();
     	for (auto it = value.begin(); it != value.end(); it++) {
     		opcUaVariantSPtr_->pushBack(*it);
     	}
        	opcUaStatusCode_ = statusCode;
         sourceTimestamp_ = sourceTimestamp;
     }

     void
 	OpcUaDataValue::set(const std::vector<OpcUaUInt64>& value, OpcUaStatusCode statusCode, const OpcUaDateTime& sourceTimestamp)
     {
     	opcUaVariantSPtr_ = constructSPtr<OpcUaVariant>();
     	for (auto it = value.begin(); it != value.end(); it++) {
     		opcUaVariantSPtr_->pushBack(*it);
     	}
        	opcUaStatusCode_ = statusCode;
         sourceTimestamp_ = sourceTimestamp;
     }

     void
 	OpcUaDataValue::set(const std::vector<OpcUaString::SPtr>& value, OpcUaStatusCode statusCode, const OpcUaDateTime& sourceTimestamp)
     {
     	opcUaVariantSPtr_ = constructSPtr<OpcUaVariant>();
     	for (auto it = value.begin(); it != value.end(); it++) {
     		opcUaVariantSPtr_->pushBack(*it);
     	}
        	opcUaStatusCode_ = statusCode;
         sourceTimestamp_ = sourceTimestamp;
     }

     void
 	OpcUaDataValue::set(const std::vector<OpcUaDateTime>& value, OpcUaStatusCode statusCode, const OpcUaDateTime& sourceTimestamp)
     {
     	opcUaVariantSPtr_ = constructSPtr<OpcUaVariant>();
     	for (auto it = value.begin(); it != value.end(); it++) {
     		opcUaVariantSPtr_->pushBack(*it);
     	}
        	opcUaStatusCode_ = statusCode;
         sourceTimestamp_ = sourceTimestamp;
     }

     void
 	OpcUaDataValue::set(const std::vector<OpcUaGuid::SPtr>& value, OpcUaStatusCode statusCode, const OpcUaDateTime& sourceTimestamp)
     {
     	opcUaVariantSPtr_ = constructSPtr<OpcUaVariant>();
     	for (auto it = value.begin(); it != value.end(); it++) {
     		opcUaVariantSPtr_->pushBack(*it);
     	}
        	opcUaStatusCode_ = statusCode;
         sourceTimestamp_ = sourceTimestamp;
     }

     void
 	OpcUaDataValue::set(const std::vector<OpcUaByteString::SPtr>& value, OpcUaStatusCode statusCode, const OpcUaDateTime& sourceTimestamp)
     {
     	opcUaVariantSPtr_ = constructSPtr<OpcUaVariant>();
     	for (auto it = value.begin(); it != value.end(); it++) {
     		opcUaVariantSPtr_->pushBack(*it);
     	}
        	opcUaStatusCode_ = statusCode;
         sourceTimestamp_ = sourceTimestamp;
     }

     void
 	OpcUaDataValue::set(const std::vector<OpcUaXmlElement::SPtr>& value, OpcUaStatusCode statusCode, const OpcUaDateTime& sourceTimestamp)
     {
     	opcUaVariantSPtr_ = constructSPtr<OpcUaVariant>();
     	for (auto it = value.begin(); it != value.end(); it++) {
     		opcUaVariantSPtr_->pushBack(*it);
     	}
        	opcUaStatusCode_ = statusCode;
         sourceTimestamp_ = sourceTimestamp;
     }

     void
 	OpcUaDataValue::set(const std::vector<OpcUaNodeId::SPtr>& value, OpcUaStatusCode statusCode, const OpcUaDateTime& sourceTimestamp)
     {
     	opcUaVariantSPtr_ = constructSPtr<OpcUaVariant>();
     	for (auto it = value.begin(); it != value.end(); it++) {
     		opcUaVariantSPtr_->pushBack(*it);
     	}
        	opcUaStatusCode_ = statusCode;
         sourceTimestamp_ = sourceTimestamp;
     }

     void
 	OpcUaDataValue::set(const std::vector<OpcUaExpandedNodeId::SPtr>& value, OpcUaStatusCode statusCode, const OpcUaDateTime& sourceTimestamp)
     {
     	opcUaVariantSPtr_ = constructSPtr<OpcUaVariant>();
     	for (auto it = value.begin(); it != value.end(); it++) {
     		opcUaVariantSPtr_->pushBack(*it);
     	}
        	opcUaStatusCode_ = statusCode;
         sourceTimestamp_ = sourceTimestamp;
     }

     void
 	OpcUaDataValue::set(const std::vector<OpcUaStatusCode>& value, OpcUaStatusCode statusCode, const OpcUaDateTime& sourceTimestamp)
     {
     	opcUaVariantSPtr_ = constructSPtr<OpcUaVariant>();
     	for (auto it = value.begin(); it != value.end(); it++) {
     		opcUaVariantSPtr_->pushBack(*it);
     	}
        	opcUaStatusCode_ = statusCode;
         sourceTimestamp_ = sourceTimestamp;
     }

     void
 	OpcUaDataValue::set(const std::vector<OpcUaQualifiedName::SPtr>& value, OpcUaStatusCode statusCode, const OpcUaDateTime& sourceTimestamp)
     {
     	opcUaVariantSPtr_ = constructSPtr<OpcUaVariant>();
     	for (auto it = value.begin(); it != value.end(); it++) {
     		opcUaVariantSPtr_->pushBack(*it);
     	}
        	opcUaStatusCode_ = statusCode;
         sourceTimestamp_ = sourceTimestamp;
     }

     void
 	OpcUaDataValue::set(const std::vector<OpcUaLocalizedText::SPtr>& value, OpcUaStatusCode statusCode, const OpcUaDateTime& sourceTimestamp)
     {
     	opcUaVariantSPtr_ = constructSPtr<OpcUaVariant>();
     	for (auto it = value.begin(); it != value.end(); it++) {
     		opcUaVariantSPtr_->pushBack(*it);
     	}
        	opcUaStatusCode_ = statusCode;
         sourceTimestamp_ = sourceTimestamp;
     }

     void
 	OpcUaDataValue::set(const std::vector<OpcUaExtensionObject::SPtr>& value, OpcUaStatusCode statusCode, const OpcUaDateTime& sourceTimestamp)
     {
     	opcUaVariantSPtr_ = constructSPtr<OpcUaVariant>();
     	for (auto it = value.begin(); it != value.end(); it++) {
     		opcUaVariantSPtr_->pushBack(*it);
     	}
        	opcUaStatusCode_ = statusCode;
         sourceTimestamp_ = sourceTimestamp;
     }


	void 
	OpcUaDataValue::out(std::ostream& os) const
	{
		bool outputExist = false;
		if (opcUaVariantSPtr_.get() != NULL) {
			os << "Value=";
		    os << *opcUaVariantSPtr_;
			outputExist = true;
		}
		if (opcUaStatusCode_ != 0) {
			if (outputExist) os << ",";
			os << "Status=" << OpcUaStatusCodeMap::shortString(opcUaStatusCode_);
			outputExist = true;
		}
		if (sourceTimestamp_.exist()) {
			if (outputExist) os << ",";
			os << "SourceTime=" << sourceTimestamp_;
			outputExist = true;
		}
		if (serverTimestamp_.exist()) {
			if (outputExist) os << ",";
			os << "ServerTime=" << serverTimestamp_;
			outputExist = true;
		}
		if (sourcePicoseconds_ != 0) {
			if (outputExist) os << ",";
			os << "SourcePicoSec=" << sourcePicoseconds_;
			outputExist = true;
		}
		if (serverPicoseconds_ != 0) {
			if (outputExist) os << ",";
			os << "ServerPicoSec=" << serverPicoseconds_;
			outputExist = true;
		}
	}

	void 
	OpcUaDataValue::copyFrom(OpcUaDataValue& dataValue)
	{
		dataValue.copyTo(*this);
	}

	void
	OpcUaDataValue::copyTo(OpcUaDataValue& dataValue)
	{
		if (opcUaVariantSPtr_.get() != NULL) {
		    opcUaVariantSPtr_->copyTo(*dataValue.variant());
		}
		if (opcUaStatusCode_ != dataValue.statusCode()) {
		    dataValue.statusCode(opcUaStatusCode_);
		}
		if (sourceTimestamp_.exist()) {
			dataValue.sourceTimestamp(sourceTimestamp_);
		}
		if (serverTimestamp_.exist()) {
			dataValue.serverTimestamp(serverTimestamp_);
		}
		if (sourcePicoseconds_ != 0) {
			dataValue.sourcePicoseconds(sourcePicoseconds_);
		}
		if (serverPicoseconds_ != 0) {
			dataValue.serverPicoseconds(serverPicoseconds_);
		}
	}

	bool
	OpcUaDataValue::operator<(const OpcUaDataValue& dataValue) const
	{
		OpcUaDataValue* actValue = const_cast<OpcUaDataValue*>(this);
		OpcUaDataValue* tmpValue = const_cast<OpcUaDataValue*>(&dataValue);

		if (actValue->isNullVariant() && !tmpValue->isNullVariant()) return true;
		if (!actValue->isNullVariant() && tmpValue->isNullVariant()) return false;
		if (!actValue->isNullVariant() && !tmpValue->isNullVariant()) {
			if (*actValue->variant() < *tmpValue->variant()) return true;
		}
		if (actValue->opcUaStatusCode_ << tmpValue->opcUaStatusCode_) return true;
		if (actValue->sourceTimestamp_ << tmpValue->sourceTimestamp_) return true;
		if (actValue->sourcePicoseconds_ << tmpValue->sourcePicoseconds_) return true;
		if (actValue->serverTimestamp_ << tmpValue->serverTimestamp_) return true;
		if (actValue->serverPicoseconds_ << tmpValue->serverPicoseconds_) return true;

		return false;
	}

	bool
	OpcUaDataValue::operator!=(const OpcUaDataValue& opcUaDataValue) const
	{
		return !operator==(opcUaDataValue);
	}

	bool
	OpcUaDataValue::operator==(const OpcUaDataValue& opcUaDataValue) const
	{
		OpcUaDataValue* actValue = const_cast<OpcUaDataValue*>(this);
		OpcUaDataValue* tmpValue = const_cast<OpcUaDataValue*>(&opcUaDataValue);

		// variant
		if (actValue->isNullVariant() && !tmpValue->isNullVariant()) return false;
		if (!actValue->isNullVariant() && tmpValue->isNullVariant()) return false;
		if (!actValue->isNullVariant() && !tmpValue->isNullVariant()) {
			if (*actValue->variant() != *tmpValue->variant()) return false;
		}

		// status code
		if (actValue->statusCode() != tmpValue->statusCode()) return false;

		// source time
		if (actValue->sourceTimestamp() != tmpValue->sourceTimestamp()) return false;
		if (actValue->serverPicoseconds() != tmpValue->sourcePicoseconds()) return false;

		// server time
		if (actValue->serverTimestamp() != tmpValue->serverTimestamp()) return false;
		if (actValue->serverPicoseconds() != tmpValue->serverPicoseconds()) return false;

		return true;
	}

	void 
	OpcUaDataValue::opcUaBinaryEncode(std::ostream& os) const
	{
		OpcUaByte encodingMask = 0x00;

		if (opcUaVariantSPtr_.get() != NULL) {
			encodingMask += 0x01;
		}
		if (opcUaStatusCode_ != 0) {
			encodingMask += 0x02;
		}
		if (sourceTimestamp_.exist()) {
			encodingMask += 0x04;
		}
		if (serverTimestamp_.exist()) {
			encodingMask += 0x08;
		}
		if (sourcePicoseconds_ != 0) {
			encodingMask += 0x10;
		}
		if (serverPicoseconds_ != 0) {
			encodingMask += 0x20;
		}

		OpcUaNumber::opcUaBinaryEncode(os,encodingMask);
		if (opcUaVariantSPtr_.get() != NULL) {
			opcUaVariantSPtr_->opcUaBinaryEncode(os);
		}
		if (opcUaStatusCode_ != 0) {
			OpcUaNumber::opcUaBinaryEncode(os,opcUaStatusCode_);
		}
		if (sourceTimestamp_.exist()) {
			sourceTimestamp_.opcUaBinaryEncode(os);
		}
		if (sourcePicoseconds_ != 0) {
			OpcUaNumber::opcUaBinaryEncode(os,sourcePicoseconds_);
		}
		if (serverTimestamp_.exist()) {
			serverTimestamp_.opcUaBinaryEncode(os);
		}
		if (serverPicoseconds_ != 0) {
			OpcUaNumber::opcUaBinaryEncode(os,serverPicoseconds_);
		}
	}
		

	void 
	OpcUaDataValue::opcUaBinaryDecode(std::istream& is)
	{
		OpcUaByte encodingMask;
		OpcUaNumber::opcUaBinaryDecode(is,encodingMask);

		if ((encodingMask & 0x01) == 0x01) {
			opcUaVariantSPtr_ = constructSPtr<OpcUaVariant>();
			opcUaVariantSPtr_->opcUaBinaryDecode(is);
		}
		if ((encodingMask & 0x02) == 0x02) {
			OpcUaInt32 tmp;
			OpcUaNumber::opcUaBinaryDecode(is,tmp); opcUaStatusCode_ = (OpcUaStatusCode)tmp;
		}
		if ((encodingMask & 0x04) == 0x04) {
			sourceTimestamp_.opcUaBinaryDecode(is);
		}
		if ((encodingMask & 0x08) == 0x08) {
			serverTimestamp_.opcUaBinaryDecode(is);
		}
		if ((encodingMask & 0x10) == 0x10) {
			OpcUaNumber::opcUaBinaryDecode(is,sourcePicoseconds_);
		}	
		if ((encodingMask & 0x20) == 0x20) {
			OpcUaNumber::opcUaBinaryDecode(is,serverPicoseconds_);
		}
	}

	bool
	OpcUaDataValue::xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
	{
		boost::property_tree::ptree elementTree;
		if (!xmlEncode(elementTree, xmlns)) return false;
		pt.push_back(std::make_pair(xmlns.addPrefix(element), elementTree));
		return true;
	}

	bool
	OpcUaDataValue::xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns)
	{
		if (opcUaVariantSPtr_.get() != nullptr) {
			if (!opcUaVariantSPtr_->xmlEncode(pt, "Value", xmlns)) {
				Log(Error, "DataValue xml encoder error")
					.parameter("Structure", "DataValue")
					.parameter("Element", "Value");
				return false;
			}
		}

		if (opcUaStatusCode_ != 0) {
			OpcUaUInt32 statusCode = opcUaStatusCode_;
			if (!XmlNumber::xmlEncode(pt, statusCode, "StatusCode")) {
				Log(Error, "DataValue xml encoder error")
					.parameter("Structure", "DataValue")
					.parameter("Element", "StatusCode");
				return false;
			}
		}

		if (sourceTimestamp_.exist()) {
			if (!sourceTimestamp_.xmlEncode(pt, "SourceTimestamp", xmlns)) {
				Log(Error, "DataValue xml encoder error")
					.parameter("Structure", "DataValue")
					.parameter("Element", "SourceTimestamp");
				return false;
			}
		}

		if (serverTimestamp_.exist()) {
			if (!serverTimestamp_.xmlEncode(pt, "ServerTimestamp", xmlns)) {
				Log(Error, "DataValue xml encoder error")
					.parameter("Structure", "DataValue")
					.parameter("Element", "ServerTimestamp");
				return false;
			}
		}

		if (sourcePicoseconds_ != 0) {
			if (!XmlNumber::xmlEncode(pt, sourcePicoseconds_, "SourcePicoseconds")) {
				Log(Error, "DataValue xml encoder error")
					.parameter("Structure", "DataValue")
					.parameter("Element", "SourcePicoseconds");
				return false;
			}
		}

		if (serverPicoseconds_ != 0) {
			if (!XmlNumber::xmlEncode(pt, serverPicoseconds_, "ServerPicoseconds")) {
				Log(Error, "DataValue xml encoder error")
					.parameter("Structure", "DataValue")
					.parameter("Element", "ServerPicoseconds");
				return false;
			}
		}

		return true;
	}

	bool
	OpcUaDataValue::xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns)
	{
		boost::optional<boost::property_tree::ptree&> tmpTree;

		tmpTree = pt.get_child_optional(xmlns.addPrefix("Value"));
		if (!tmpTree) {
			opcUaVariantSPtr_.reset();
		}
		else {
			opcUaVariantSPtr_ = constructSPtr<OpcUaVariant>();
			if (!opcUaVariantSPtr_->xmlDecode(*tmpTree, xmlns)) {
				opcUaVariantSPtr_.reset();
				Log(Error, "DataValue xml decoder error")
					.parameter("Structure", "DataValue")
					.parameter("Element", "Value");
				return false;
			}
		}

		tmpTree = pt.get_child_optional(xmlns.addPrefix("StatusCode"));
		if (!tmpTree) {
			// nothing to do
		}
		else {
			uint32_t statusCode;
			if (!XmlNumber::xmlDecode(*tmpTree, statusCode)) {
				Log(Error, "DataValue xml decoder error")
					.parameter("Structure", "DataValue")
					.parameter("Element", "StatusCode");
				return false;
			}
			opcUaStatusCode_ = (OpcUaStatusCode)statusCode;
		}

		tmpTree = pt.get_child_optional(xmlns.addPrefix("SourceTimestamp"));
		if (!tmpTree) {
			// nothing to do
		}
		else {
			if (!sourceTimestamp_.xmlDecode(*tmpTree, xmlns)) {
				Log(Error, "DataValue xml decoder error")
					.parameter("Structure", "DataValue")
					.parameter("Element", "SourceTimestamp");
				return false;
			}
		}

		tmpTree = pt.get_child_optional(xmlns.addPrefix("ServerTimestamp"));
		if (!tmpTree) {
			// nothing to do
		}
		else {
			if (!serverTimestamp_.xmlDecode(*tmpTree, xmlns)) {
				Log(Error, "DataValue xml decoder error")
					.parameter("Structure", "DataValue")
					.parameter("Element", "ServerTimestamp");
				return false;
			}
		}

		tmpTree = pt.get_child_optional(xmlns.addPrefix("SourcePicoseconds"));
		if (!tmpTree) {
			sourcePicoseconds_ = 0;
		}
		else {
			if (!XmlNumber::xmlDecode(*tmpTree, sourcePicoseconds_)) {
				Log(Error, "DataValue xml decoder error")
					.parameter("Structure", "DataValue")
					.parameter("Element", "SourcePicoseconds");
				return false;
			}
		}

		tmpTree = pt.get_child_optional(xmlns.addPrefix("ServerPicoseconds"));
		if (!tmpTree) {
			serverPicoseconds_ = 0;
		}
		else {
			if (!XmlNumber::xmlDecode(*tmpTree, serverPicoseconds_)) {
				Log(Error, "DataValue xml decoder error")
					.parameter("Structure", "DataValue")
					.parameter("Element", "ServerPicoseconds");
				return false;
			}
		}

		return true;
	}

	bool
	OpcUaDataValue::jsonEncodeImpl(boost::property_tree::ptree &pt) const
	{
		// add value
		if (opcUaVariantSPtr_.get() != nullptr) {
			if (!opcUaVariantSPtr_->jsonEncode(pt, "Value")) {
				Log(Error, "OpcUaDataValue json encode error")
		        	.parameter("Element", "Value");
				return false;
			}
		}

		// add status code
		OpcUaStatus status(opcUaStatusCode_);
		if (!status.jsonEncode(pt, "Status")) {
			Log(Error, "OpcUaDataValue json encode error")
		        .parameter("Element", "Status");
			return false;
		}

		// add source timestamp
		if (sourceTimestamp_.exist()) {
			if (!sourceTimestamp_.jsonEncode(pt, "SourceTimestamp")) {
				Log(Error, "OpcUaDataValue json encode error")
		        	.parameter("Element", "SourceTimestamp");
				return false;
			}
		}

		// add server timestamp
		if (serverTimestamp_.exist()) {
			if (!serverTimestamp_.jsonEncode(pt, "ServerTimestamp")) {
				Log(Error, "OpcUaDataValue json encode error")
		        	.parameter("Element", "ServerTimestamp");
				return false;
			}
		}

		// added source picoseconds
		if (sourcePicoseconds_ != 0) {
			if (!JsonNumber::jsonEncode(pt, sourcePicoseconds_, "SourcePicoSeconds")) {
				Log(Error, "OpcUaDataValue json encode error")
		        	.parameter("Element", "SourcePicoSeconds");
				return false;
			}
		}

		// added server picoseconds
		if (serverPicoseconds_ != 0) {
			if (!JsonNumber::jsonEncode(pt, serverPicoseconds_, "ServerPicoSeconds")) {
				Log(Error, "OpcUaDataValue json encode error")
		    		.parameter("Element", "ServerPicoSeconds");
				return false;
			}
		}

		return true;
	}

	bool
	OpcUaDataValue::jsonDecodeImpl(const boost::property_tree::ptree &pt)
	{
		// get value
		//opcUaVariantSPtr_.reset();
		auto tmpTree = pt.get_child_optional("Value");
		if (tmpTree) {
			opcUaVariantSPtr_ = constructSPtr<OpcUaVariant>();
			if (!opcUaVariantSPtr_->jsonDecode(*tmpTree)) {
				Log(Error, "OpcUaDataValue json decode error")
			        .parameter("Element", "Value");
				return false;
			}
		}

		// get status code
		OpcUaStatus status(Success);
		tmpTree = pt.get_child_optional("Status");
		if (tmpTree) {
			if (!status.jsonDecode(pt, "Status")) {
				Log(Error, "OpcUaDataValue json decode error")
		        	.parameter("Element", "Status");
				return false;
			}
		}
		opcUaStatusCode_ = status.enumeration();

		// get source timestamp
		tmpTree = pt.get_child_optional("SourceTimestamp");
		if (tmpTree) {
			if (!sourceTimestamp_.jsonDecode(pt, "SourceTimestamp")) {
				Log(Error, "OpcUaDataValue json decode error")
		        	.parameter("Element", "SourceTimestamp");
				return false;
			}
		}

		// get server timestamp
		tmpTree = pt.get_child_optional("ServerTimestamp");
		if (tmpTree) {
			if (!serverTimestamp_.jsonDecode(pt, "ServerTimestamp")) {
				Log(Error, "OpcUaDataValue json decode error")
		        	.parameter("Element", "ServerTimestamp");
				return false;
			}
		}

		// get source pico seconds
		tmpTree = pt.get_child_optional("SourcePicoSeconds");
		if (tmpTree) {
			if (!JsonNumber::jsonDecode(pt, sourcePicoseconds_, "SourcePicoSeconds")) {
				Log(Error, "OpcUaDataValue json decode error")
		        	.parameter("Element", "SourcePicoSeconds");
				return false;
			}
		}

		// get server pico seconds
		tmpTree = pt.get_child_optional("ServerPicoSeconds");
		if (tmpTree) {
			if (!JsonNumber::jsonDecode(pt, serverPicoseconds_, "ServerPicoSeconds")) {
				Log(Error, "OpcUaDataValue json decode error")
		        	.parameter("Element", "ServerPicoSeconds");
				return false;
			}
		}

		return true;
	}

}
