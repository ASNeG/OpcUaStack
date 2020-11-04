/*
   Copyright 2020 Kai Huebl (kai@huebl-sgh.de)

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

#ifndef __OpcUaStackCore_OpcUaDataValue_h__
#define __OpcUaStackCore_OpcUaDataValue_h__

#include <boost/property_tree/ptree.hpp>
#include "OpcUaStackCore/BuildInTypes/Xmlns.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaNumber.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaVariant.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaStatusCode.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaDateTime.h"
#include "OpcUaStackCore/BuildInTypes/JsonFormatter.h"

namespace OpcUaStackCore
{

	class DLLEXPORT OpcUaNullValue
	{
	  public:
		OpcUaNullValue(void) {}
		~OpcUaNullValue(void) {}
	};


	class DLLEXPORT OpcUaDataValue
	: public Object
	, public JsonFormatter
	{
	  public:
		typedef boost::shared_ptr<OpcUaDataValue> SPtr;
		typedef std::vector<OpcUaDataValue::SPtr> Vec;

	    OpcUaDataValue(void);
	    OpcUaDataValue(const OpcUaDataValue& value);
	    OpcUaDataValue(const OpcUaNullValue& value, OpcUaStatusCode statusCode, const OpcUaDateTime& sourceTimestamp = OpcUaDateTime(boost::posix_time::microsec_clock::universal_time()));
	    OpcUaDataValue(const OpcUaBoolean& value, OpcUaStatusCode statusCode = Success, const OpcUaDateTime& sourceTimestamp = OpcUaDateTime(boost::posix_time::microsec_clock::universal_time()));
	    OpcUaDataValue(const OpcUaByte& value, OpcUaStatusCode statusCode = Success, const OpcUaDateTime& sourceTimestamp = OpcUaDateTime(boost::posix_time::microsec_clock::universal_time()));
	    OpcUaDataValue(const OpcUaSByte& value, OpcUaStatusCode statusCode = Success, const OpcUaDateTime& sourceTimestamp = OpcUaDateTime(boost::posix_time::microsec_clock::universal_time()));
	    OpcUaDataValue(const OpcUaInt16& value, OpcUaStatusCode statusCode = Success, const OpcUaDateTime& sourceTimestamp = OpcUaDateTime(boost::posix_time::microsec_clock::universal_time()));
	    OpcUaDataValue(const OpcUaUInt16& value, OpcUaStatusCode statusCode = Success, const OpcUaDateTime& sourceTimestamp = OpcUaDateTime(boost::posix_time::microsec_clock::universal_time()));
	    OpcUaDataValue(const OpcUaInt32& value, OpcUaStatusCode statusCode = Success, const OpcUaDateTime& sourceTimestamp = OpcUaDateTime(boost::posix_time::microsec_clock::universal_time()));
	    OpcUaDataValue(const OpcUaUInt32& value, OpcUaStatusCode statusCode = Success, const OpcUaDateTime& sourceTimestamp = OpcUaDateTime(boost::posix_time::microsec_clock::universal_time()));
	    OpcUaDataValue(const OpcUaInt64& value, OpcUaStatusCode statusCode = Success, const OpcUaDateTime& sourceTimestamp = OpcUaDateTime(boost::posix_time::microsec_clock::universal_time()));
	    OpcUaDataValue(const OpcUaUInt64& value, OpcUaStatusCode statusCode = Success, const OpcUaDateTime& sourceTimestamp = OpcUaDateTime(boost::posix_time::microsec_clock::universal_time()));
	    OpcUaDataValue(const OpcUaFloat& value, OpcUaStatusCode statusCode = Success, const OpcUaDateTime& sourceTimestamp = OpcUaDateTime(boost::posix_time::microsec_clock::universal_time()));
	    OpcUaDataValue(const OpcUaDouble& value, OpcUaStatusCode statusCode = Success, const OpcUaDateTime& sourceTimestamp = OpcUaDateTime(boost::posix_time::microsec_clock::universal_time()));
	    OpcUaDataValue(const OpcUaString& value, OpcUaStatusCode statusCode = Success, const OpcUaDateTime& sourceTimestamp = OpcUaDateTime(boost::posix_time::microsec_clock::universal_time()));
	    OpcUaDataValue(const OpcUaDateTime& value, OpcUaStatusCode statusCode = Success, const OpcUaDateTime& sourceTimestamp = OpcUaDateTime(boost::posix_time::microsec_clock::universal_time()));
	    OpcUaDataValue(const OpcUaGuid& value, OpcUaStatusCode statusCode = Success, const OpcUaDateTime& sourceTimestamp = OpcUaDateTime(boost::posix_time::microsec_clock::universal_time()));
	    OpcUaDataValue(const OpcUaByteString& value, OpcUaStatusCode statusCode = Success, const OpcUaDateTime& sourceTimestamp = OpcUaDateTime(boost::posix_time::microsec_clock::universal_time()));
	    OpcUaDataValue(const OpcUaXmlElement& value, OpcUaStatusCode statusCode = Success, const OpcUaDateTime& sourceTimestamp = OpcUaDateTime(boost::posix_time::microsec_clock::universal_time()));
	    OpcUaDataValue(const OpcUaNodeId& value, OpcUaStatusCode statusCode = Success, const OpcUaDateTime& sourceTimestamp = OpcUaDateTime(boost::posix_time::microsec_clock::universal_time()));
	    OpcUaDataValue(const OpcUaExpandedNodeId& value, OpcUaStatusCode statusCode = Success, const OpcUaDateTime& sourceTimestamp = OpcUaDateTime(boost::posix_time::microsec_clock::universal_time()));
	    OpcUaDataValue(const OpcUaStatusCode& value, OpcUaStatusCode statusCode = Success, const OpcUaDateTime& sourceTimestamp = OpcUaDateTime(boost::posix_time::microsec_clock::universal_time()));
	    OpcUaDataValue(const OpcUaQualifiedName& value, OpcUaStatusCode statusCode = Success, const OpcUaDateTime& sourceTimestamp = OpcUaDateTime(boost::posix_time::microsec_clock::universal_time()));
	    OpcUaDataValue(const OpcUaLocalizedText& value, OpcUaStatusCode statusCode = Success, const OpcUaDateTime& sourceTimestamp = OpcUaDateTime(boost::posix_time::microsec_clock::universal_time()));
	    OpcUaDataValue(const OpcUaExtensionObject& value, OpcUaStatusCode statusCode = Success, const OpcUaDateTime& sourceTimestamp = OpcUaDateTime(boost::posix_time::microsec_clock::universal_time()));

	    OpcUaDataValue(const OpcUaBooleanArray& value, OpcUaStatusCode statusCode = Success, const OpcUaDateTime& sourceTimestamp = OpcUaDateTime(boost::posix_time::microsec_clock::universal_time()));
	    OpcUaDataValue(const OpcUaByteArray& value, OpcUaStatusCode statusCode = Success, const OpcUaDateTime& sourceTimestamp = OpcUaDateTime(boost::posix_time::microsec_clock::universal_time()));
	    OpcUaDataValue(const OpcUaSByteArray& value, OpcUaStatusCode statusCode = Success, const OpcUaDateTime& sourceTimestamp = OpcUaDateTime(boost::posix_time::microsec_clock::universal_time()));
	    OpcUaDataValue(const OpcUaInt16Array& value, OpcUaStatusCode statusCode = Success, const OpcUaDateTime& sourceTimestamp = OpcUaDateTime(boost::posix_time::microsec_clock::universal_time()));
	    OpcUaDataValue(const OpcUaUInt16Array& value, OpcUaStatusCode statusCode = Success, const OpcUaDateTime& sourceTimestamp = OpcUaDateTime(boost::posix_time::microsec_clock::universal_time()));
	    OpcUaDataValue(const OpcUaInt32Array& value, OpcUaStatusCode statusCode = Success, const OpcUaDateTime& sourceTimestamp = OpcUaDateTime(boost::posix_time::microsec_clock::universal_time()));
	    OpcUaDataValue(const OpcUaUInt32Array& value, OpcUaStatusCode statusCode = Success, const OpcUaDateTime& sourceTimestamp = OpcUaDateTime(boost::posix_time::microsec_clock::universal_time()));
	    OpcUaDataValue(const OpcUaInt64Array& value, OpcUaStatusCode statusCode = Success, const OpcUaDateTime& sourceTimestamp = OpcUaDateTime(boost::posix_time::microsec_clock::universal_time()));
	    OpcUaDataValue(const OpcUaUInt64Array& value, OpcUaStatusCode statusCode = Success, const OpcUaDateTime& sourceTimestamp = OpcUaDateTime(boost::posix_time::microsec_clock::universal_time()));
	    OpcUaDataValue(const OpcUaFloatArray& value, OpcUaStatusCode statusCode = Success, const OpcUaDateTime& sourceTimestamp = OpcUaDateTime(boost::posix_time::microsec_clock::universal_time()));
	    OpcUaDataValue(const OpcUaDoubleArray& value, OpcUaStatusCode statusCode = Success, const OpcUaDateTime& sourceTimestamp = OpcUaDateTime(boost::posix_time::microsec_clock::universal_time()));
	    OpcUaDataValue(const OpcUaStringArray& value, OpcUaStatusCode statusCode = Success, const OpcUaDateTime& sourceTimestamp = OpcUaDateTime(boost::posix_time::microsec_clock::universal_time()));
	    OpcUaDataValue(const OpcUaDateTimeArray& value, OpcUaStatusCode statusCode = Success, const OpcUaDateTime& sourceTimestamp = OpcUaDateTime(boost::posix_time::microsec_clock::universal_time()));
	    OpcUaDataValue(const OpcUaGuidArray& value, OpcUaStatusCode statusCode = Success, const OpcUaDateTime& sourceTimestamp = OpcUaDateTime(boost::posix_time::microsec_clock::universal_time()));
	    OpcUaDataValue(const OpcUaByteStringArray& value, OpcUaStatusCode statusCode = Success, const OpcUaDateTime& sourceTimestamp = OpcUaDateTime(boost::posix_time::microsec_clock::universal_time()));
	    OpcUaDataValue(const OpcUaXmlElementArray& value, OpcUaStatusCode statusCode = Success, const OpcUaDateTime& sourceTimestamp = OpcUaDateTime(boost::posix_time::microsec_clock::universal_time()));
	    OpcUaDataValue(const OpcUaNodeIdArray& value, OpcUaStatusCode statusCode = Success, const OpcUaDateTime& sourceTimestamp = OpcUaDateTime(boost::posix_time::microsec_clock::universal_time()));
	    OpcUaDataValue(const OpcUaExpandedNodeIdArray& value, OpcUaStatusCode statusCode = Success, const OpcUaDateTime& sourceTimestamp = OpcUaDateTime(boost::posix_time::microsec_clock::universal_time()));
	    OpcUaDataValue(const OpcUaStatusCodeArray& value, OpcUaStatusCode statusCode = Success, const OpcUaDateTime& sourceTimestamp = OpcUaDateTime(boost::posix_time::microsec_clock::universal_time()));
	    OpcUaDataValue(const OpcUaQualifiedNameArray& value, OpcUaStatusCode statusCode = Success, const OpcUaDateTime& sourceTimestamp = OpcUaDateTime(boost::posix_time::microsec_clock::universal_time()));
	    OpcUaDataValue(const OpcUaLocalizedTextArray& value, OpcUaStatusCode statusCode = Success, const OpcUaDateTime& sourceTimestamp = OpcUaDateTime(boost::posix_time::microsec_clock::universal_time()));
	    OpcUaDataValue(const OpcUaExtensionObjectArray& value, OpcUaStatusCode statusCode = Success, const OpcUaDateTime& sourceTimestamp = OpcUaDateTime(boost::posix_time::microsec_clock::universal_time()));

	    OpcUaDataValue(const std::vector<OpcUaBoolean>& value, OpcUaStatusCode statusCode = Success, const OpcUaDateTime& sourceTimestamp = OpcUaDateTime(boost::posix_time::microsec_clock::universal_time()));
	    OpcUaDataValue(const std::vector<OpcUaByte>& value, OpcUaStatusCode statusCode = Success, const OpcUaDateTime& sourceTimestamp = OpcUaDateTime(boost::posix_time::microsec_clock::universal_time()));
	    OpcUaDataValue(const std::vector<OpcUaSByte>& value, OpcUaStatusCode statusCode = Success, const OpcUaDateTime& sourceTimestamp = OpcUaDateTime(boost::posix_time::microsec_clock::universal_time()));
	    OpcUaDataValue(const std::vector<OpcUaInt16>& value, OpcUaStatusCode statusCode = Success, const OpcUaDateTime& sourceTimestamp = OpcUaDateTime(boost::posix_time::microsec_clock::universal_time()));
	    OpcUaDataValue(const std::vector<OpcUaUInt16>& value, OpcUaStatusCode statusCode = Success, const OpcUaDateTime& sourceTimestamp = OpcUaDateTime(boost::posix_time::microsec_clock::universal_time()));
	    OpcUaDataValue(const std::vector<OpcUaInt32>& value, OpcUaStatusCode statusCode = Success, const OpcUaDateTime& sourceTimestamp = OpcUaDateTime(boost::posix_time::microsec_clock::universal_time()));
	    OpcUaDataValue(const std::vector<OpcUaUInt32>& value, OpcUaStatusCode statusCode = Success, const OpcUaDateTime& sourceTimestamp = OpcUaDateTime(boost::posix_time::microsec_clock::universal_time()));
	    OpcUaDataValue(const std::vector<OpcUaInt64>& value, OpcUaStatusCode statusCode = Success, const OpcUaDateTime& sourceTimestamp = OpcUaDateTime(boost::posix_time::microsec_clock::universal_time()));
	    OpcUaDataValue(const std::vector<OpcUaUInt64>& value, OpcUaStatusCode statusCode = Success, const OpcUaDateTime& sourceTimestamp = OpcUaDateTime(boost::posix_time::microsec_clock::universal_time()));
	    OpcUaDataValue(const std::vector<OpcUaFloat>& value, OpcUaStatusCode statusCode = Success, const OpcUaDateTime& sourceTimestamp = OpcUaDateTime(boost::posix_time::microsec_clock::universal_time()));
	    OpcUaDataValue(const std::vector<OpcUaDouble>& value, OpcUaStatusCode statusCode = Success, const OpcUaDateTime& sourceTimestamp = OpcUaDateTime(boost::posix_time::microsec_clock::universal_time()));
	    OpcUaDataValue(const std::vector<OpcUaString::SPtr>& value, OpcUaStatusCode statusCode = Success, const OpcUaDateTime& sourceTimestamp = OpcUaDateTime(boost::posix_time::microsec_clock::universal_time()));
	    OpcUaDataValue(const std::vector<OpcUaDateTime>& value, OpcUaStatusCode statusCode = Success, const OpcUaDateTime& sourceTimestamp = OpcUaDateTime(boost::posix_time::microsec_clock::universal_time()));
	    OpcUaDataValue(const std::vector<OpcUaGuid::SPtr>& value, OpcUaStatusCode statusCode = Success, const OpcUaDateTime& sourceTimestamp = OpcUaDateTime(boost::posix_time::microsec_clock::universal_time()));
	    OpcUaDataValue(const std::vector<OpcUaByteString::SPtr>& value, OpcUaStatusCode statusCode = Success, const OpcUaDateTime& sourceTimestamp = OpcUaDateTime(boost::posix_time::microsec_clock::universal_time()));
	    OpcUaDataValue(const std::vector<OpcUaXmlElement::SPtr>& value, OpcUaStatusCode statusCode = Success, const OpcUaDateTime& sourceTimestamp = OpcUaDateTime(boost::posix_time::microsec_clock::universal_time()));
	    OpcUaDataValue(const std::vector<OpcUaNodeId::SPtr>& value, OpcUaStatusCode statusCode = Success, const OpcUaDateTime& sourceTimestamp = OpcUaDateTime(boost::posix_time::microsec_clock::universal_time()));
	    OpcUaDataValue(const std::vector<OpcUaExpandedNodeId::SPtr>& value, OpcUaStatusCode statusCode = Success, const OpcUaDateTime& sourceTimestamp = OpcUaDateTime(boost::posix_time::microsec_clock::universal_time()));
	    OpcUaDataValue(const std::vector<OpcUaStatusCode>& value, OpcUaStatusCode statusCode = Success, const OpcUaDateTime& sourceTimestamp = OpcUaDateTime(boost::posix_time::microsec_clock::universal_time()));
	    OpcUaDataValue(const std::vector<OpcUaQualifiedName::SPtr>& value, OpcUaStatusCode statusCode = Success, const OpcUaDateTime& sourceTimestamp = OpcUaDateTime(boost::posix_time::microsec_clock::universal_time()));
	    OpcUaDataValue(const std::vector<OpcUaLocalizedText::SPtr>& value, OpcUaStatusCode statusCode = Success, const OpcUaDateTime& sourceTimestamp = OpcUaDateTime(boost::posix_time::microsec_clock::universal_time()));
	    OpcUaDataValue(const std::vector<OpcUaExtensionObject::SPtr>& value, OpcUaStatusCode statusCode = Success, const OpcUaDateTime& sourceTimestamp = OpcUaDateTime(boost::posix_time::microsec_clock::universal_time()));



	    ~OpcUaDataValue(void);

		bool exist(void);
		bool isNullVariant(void);
		OpcUaVariant::SPtr variant(void);
		void statusCode(const OpcUaStatusCode& opcUaStatusCode);
		OpcUaStatusCode statusCode(void);
		void sourceTimestamp(const OpcUaDateTime& sourceTimestamp);
		OpcUaDateTime& sourceTimestamp(void);
		void sourcePicoseconds(const OpcUaUInt16& sourcePicoseconds);
		OpcUaInt16 sourcePicoseconds(void);
		void serverTimestamp(const OpcUaDateTime& serverTimestamp);
		OpcUaDateTime& serverTimestamp(void);
		void serverPicoseconds(const OpcUaUInt16& serverPicoseconds);
		OpcUaInt16 serverPicoseconds(void);
		void reset(void);

	    bool setValue(const OpcUaNullValue& value);
	    bool setValue(const OpcUaBoolean& value);
	    bool setValue(const OpcUaByte& value);
	    bool setValue(const OpcUaSByte& value);
	    bool setValue(const OpcUaInt16& value);
	    bool setValue(const OpcUaUInt16& value);
	    bool setValue(const OpcUaInt32& value);
	    bool setValue(const OpcUaUInt32& value);
	    bool setValue(const OpcUaInt64& value);
	    bool setValue(const OpcUaUInt64& value);
	    bool setValue(const OpcUaFloat& value);
	    bool setValue(const OpcUaDouble& value);
	    bool setValue(const OpcUaString& value);
	    bool setValue(const OpcUaDateTime& value);
	    bool setValue(const OpcUaGuid& value);
	    bool setValue(const OpcUaByteString& value);
	    bool setValue(const OpcUaXmlElement& value);
	    bool setValue(const OpcUaNodeId& value);
	    bool setValue(const OpcUaExpandedNodeId& value);
	    bool setValue(const OpcUaStatusCode& value);
	    bool setValue(const OpcUaQualifiedName& value);
	    bool setValue(const OpcUaLocalizedText& value);
	    bool setValue(const OpcUaExtensionObject& value);

	    bool setValue(const OpcUaBooleanArray& value);
	    bool setValue(const OpcUaByteArray& value);
	    bool setValue(const OpcUaSByteArray& value);
	    bool setValue(const OpcUaInt16Array& value);
	    bool setValue(const OpcUaUInt16Array& value);
	    bool setValue(const OpcUaInt32Array& value);
	    bool setValue(const OpcUaUInt32Array& value);
	    bool setValue(const OpcUaInt64Array& value);
	    bool setValue(const OpcUaUInt64Array& value);
	    bool setValue(const OpcUaDoubleArray& value);
	    bool setValue(const OpcUaFloatArray& value);
	    bool setValue(const OpcUaStringArray& value);
	    bool setValue(const OpcUaDateTimeArray& value);
	    bool setValue(const OpcUaGuidArray& value);
	    bool setValue(const OpcUaByteStringArray& value);
	    bool setValue(const OpcUaXmlElementArray& value);
	    bool setValue(const OpcUaNodeIdArray& value);
	    bool setValue(const OpcUaExpandedNodeIdArray& value);
	    bool setValue(const OpcUaStatusCodeArray& value);
	    bool setValue(const OpcUaQualifiedNameArray& value);
	    bool setValue(const OpcUaLocalizedTextArray& value);
	    bool setValue(const OpcUaExtensionObjectArray& value);

	    bool setValue(const std::vector<OpcUaBoolean>& value);
	    bool setValue(const std::vector<OpcUaByte>& value);
	    bool setValue(const std::vector<OpcUaSByte>& value);
	    bool setValue(const std::vector<OpcUaInt16>& value);
	    bool setValue(const std::vector<OpcUaUInt16>& value);
	    bool setValue(const std::vector<OpcUaInt32>& value);
	    bool setValue(const std::vector<OpcUaUInt32>& value);
	    bool setValue(const std::vector<OpcUaInt64>& value);
	    bool setValue(const std::vector<OpcUaUInt64>& value);
	    bool setValue(const std::vector<OpcUaDouble>& value);
	    bool setValue(const std::vector<OpcUaFloat>& value);
	    bool setValue(const std::vector<OpcUaString::SPtr>& value);
	    bool setValue(const std::vector<OpcUaDateTime>& value);
	    bool setValue(const std::vector<OpcUaGuid::SPtr>& value);
	    bool setValue(const std::vector<OpcUaByteString::SPtr>& value);
	    bool setValue(const std::vector<OpcUaXmlElement::SPtr>& value);
	    bool setValue(const std::vector<OpcUaNodeId::SPtr>& value);
	    bool setValue(const std::vector<OpcUaExpandedNodeId::SPtr>& value);
	    bool setValue(const std::vector<OpcUaStatusCode>& value);
	    bool setValue(const std::vector<OpcUaQualifiedName::SPtr>& value);
	    bool setValue(const std::vector<OpcUaLocalizedText::SPtr>& value);
	    bool setValue(const std::vector<OpcUaExtensionObject::SPtr>& value);

	    bool getValue(OpcUaBoolean& value);
	    bool getValue(OpcUaByte& value);
	    bool getValue(OpcUaSByte& value);
	    bool getValue(OpcUaInt16& value);
	    bool getValue(OpcUaUInt16& value);
	    bool getValue(OpcUaInt32& value);
	    bool getValue(OpcUaUInt32& value);
	    bool getValue(OpcUaInt64& value);
	    bool getValue(OpcUaUInt64& value);
	    bool getValue(OpcUaDouble& value);
	    bool getValue(OpcUaFloat& value);
	    bool getValue(OpcUaString& value);
	    bool getValue(OpcUaDateTime& value);
	    bool getValue(OpcUaGuid& value);
	    bool getValue(OpcUaByteString& value);
	    bool getValue(OpcUaXmlElement& value);
	    bool getValue(OpcUaNodeId& value);
	    bool getValue(OpcUaExpandedNodeId& value);
	    bool getValue(OpcUaStatusCode& value);
	    bool getValue(OpcUaQualifiedName& value);
	    bool getValue(OpcUaLocalizedText& value);
	    bool getValue(OpcUaExtensionObject& value);

	    bool getValue(OpcUaBooleanArray& value);
	    bool getValue(OpcUaByteArray& value);
	    bool getValue(OpcUaSByteArray& value);
	    bool getValue(OpcUaInt16Array& value);
	    bool getValue(OpcUaUInt16Array& value);
	    bool getValue(OpcUaInt32Array& value);
	    bool getValue(OpcUaUInt32Array& value);
	    bool getValue(OpcUaInt64Array& value);
	    bool getValue(OpcUaUInt64Array& value);
	    bool getValue(OpcUaDoubleArray& value);
	    bool getValue(OpcUaFloatArray& value);
	    bool getValue(OpcUaStringArray& value);
	    bool getValue(OpcUaDateTimeArray& value);
	    bool getValue(OpcUaGuidArray& value);
	    bool getValue(OpcUaByteStringArray& value);
	    bool getValue(OpcUaXmlElementArray& value);
	    bool getValue(OpcUaNodeIdArray& value);
	    bool getValue(OpcUaExpandedNodeIdArray& value);
	    bool getValue(OpcUaStatusCodeArray& value);
	    bool getValue(OpcUaQualifiedNameArray& value);
	    bool getValue(OpcUaLocalizedTextArray& value);
	    bool getValue(OpcUaExtensionObjectArray& value);

	    bool getValue(std::vector<OpcUaBoolean>& value);
	    bool getValue(std::vector<OpcUaByte>& value);
	    bool getValue(std::vector<OpcUaSByte>& value);
	    bool getValue(std::vector<OpcUaInt16>& value);
	    bool getValue(std::vector<OpcUaUInt16>& value);
	    bool getValue(std::vector<OpcUaInt32>& value);
	    bool getValue(std::vector<OpcUaUInt32>& value);
	    bool getValue(std::vector<OpcUaInt64>& value);
	    bool getValue(std::vector<OpcUaUInt64>& value);
	    bool getValue(std::vector<OpcUaDouble>& value);
	    bool getValue(std::vector<OpcUaFloat>& value);
	    bool getValue(std::vector<OpcUaString::SPtr>& value);
	    bool getValue(std::vector<OpcUaDateTime>& value);
	    bool getValue(std::vector<OpcUaGuid::SPtr>& value);
	    bool getValue(std::vector<OpcUaByteString::SPtr>& value);
	    bool getValue(std::vector<OpcUaXmlElement::SPtr>& value);
	    bool getValue(std::vector<OpcUaNodeId::SPtr>& value);
	    bool getValue(std::vector<OpcUaExpandedNodeId::SPtr>& value);
	    bool getValue(std::vector<OpcUaStatusCode>& value);
	    bool getValue(std::vector<OpcUaQualifiedName::SPtr>& value);
	    bool getValue(std::vector<OpcUaLocalizedText::SPtr>& value);
	    bool getValue(std::vector<OpcUaExtensionObject::SPtr>& value);

	    void set(const OpcUaNullValue& value, OpcUaStatusCode statusCode, const OpcUaDateTime& sourceTimestamp = OpcUaDateTime(boost::posix_time::microsec_clock::universal_time()));
	    void set(const OpcUaBoolean& value, OpcUaStatusCode statusCode = Success, const OpcUaDateTime& sourceTimestamp = OpcUaDateTime(boost::posix_time::microsec_clock::universal_time()));
	    void set(const OpcUaByte& value, OpcUaStatusCode statusCode = Success, const OpcUaDateTime& sourceTimestamp = OpcUaDateTime(boost::posix_time::microsec_clock::universal_time()));
	    void set(const OpcUaSByte& value, OpcUaStatusCode statusCode = Success, const OpcUaDateTime& sourceTimestamp = OpcUaDateTime(boost::posix_time::microsec_clock::universal_time()));
	    void set(const OpcUaInt16& value, OpcUaStatusCode statusCode = Success, const OpcUaDateTime& sourceTimestamp = OpcUaDateTime(boost::posix_time::microsec_clock::universal_time()));
	    void set(const OpcUaUInt16& value, OpcUaStatusCode statusCode = Success, const OpcUaDateTime& sourceTimestamp = OpcUaDateTime(boost::posix_time::microsec_clock::universal_time()));
	    void set(const OpcUaInt32& value, OpcUaStatusCode statusCode = Success, const OpcUaDateTime& sourceTimestamp = OpcUaDateTime(boost::posix_time::microsec_clock::universal_time()));
	    void set(const OpcUaUInt32& value, OpcUaStatusCode statusCode = Success, const OpcUaDateTime& sourceTimestamp = OpcUaDateTime(boost::posix_time::microsec_clock::universal_time()));
	    void set(const OpcUaInt64& value, OpcUaStatusCode statusCode = Success, const OpcUaDateTime& sourceTimestamp = OpcUaDateTime(boost::posix_time::microsec_clock::universal_time()));
	    void set(const OpcUaUInt64& value, OpcUaStatusCode statusCode = Success, const OpcUaDateTime& sourceTimestamp = OpcUaDateTime(boost::posix_time::microsec_clock::universal_time()));
	    void set(const OpcUaFloat& value, OpcUaStatusCode statusCode = Success, const OpcUaDateTime& sourceTimestamp = OpcUaDateTime(boost::posix_time::microsec_clock::universal_time()));
	    void set(const OpcUaDouble& value, OpcUaStatusCode statusCode = Success, const OpcUaDateTime& sourceTimestamp = OpcUaDateTime(boost::posix_time::microsec_clock::universal_time()));
	    void set(const OpcUaString& value, OpcUaStatusCode statusCode = Success, const OpcUaDateTime& sourceTimestamp = OpcUaDateTime(boost::posix_time::microsec_clock::universal_time()));
	    void set(const OpcUaDateTime& value, OpcUaStatusCode statusCode = Success, const OpcUaDateTime& sourceTimestamp = OpcUaDateTime(boost::posix_time::microsec_clock::universal_time()));
	    void set(const OpcUaGuid& value, OpcUaStatusCode statusCode = Success, const OpcUaDateTime& sourceTimestamp = OpcUaDateTime(boost::posix_time::microsec_clock::universal_time()));
	    void set(const OpcUaByteString& value, OpcUaStatusCode statusCode = Success, const OpcUaDateTime& sourceTimestamp = OpcUaDateTime(boost::posix_time::microsec_clock::universal_time()));
	    void set(const OpcUaXmlElement& value, OpcUaStatusCode statusCode = Success, const OpcUaDateTime& sourceTimestamp = OpcUaDateTime(boost::posix_time::microsec_clock::universal_time()));
	    void set(const OpcUaNodeId& value, OpcUaStatusCode statusCode = Success, const OpcUaDateTime& sourceTimestamp = OpcUaDateTime(boost::posix_time::microsec_clock::universal_time()));
	    void set(const OpcUaExpandedNodeId& value, OpcUaStatusCode statusCode = Success, const OpcUaDateTime& sourceTimestamp = OpcUaDateTime(boost::posix_time::microsec_clock::universal_time()));
	    void set(const OpcUaStatusCode& value, OpcUaStatusCode statusCode = Success, const OpcUaDateTime& sourceTimestamp = OpcUaDateTime(boost::posix_time::microsec_clock::universal_time()));
	    void set(const OpcUaQualifiedName& value, OpcUaStatusCode statusCode = Success, const OpcUaDateTime& sourceTimestamp = OpcUaDateTime(boost::posix_time::microsec_clock::universal_time()));
	    void set(const OpcUaLocalizedText& value, OpcUaStatusCode statusCode = Success, const OpcUaDateTime& sourceTimestamp = OpcUaDateTime(boost::posix_time::microsec_clock::universal_time()));
	    void set(const OpcUaExtensionObject& value, OpcUaStatusCode statusCode = Success, const OpcUaDateTime& sourceTimestamp = OpcUaDateTime(boost::posix_time::microsec_clock::universal_time()));

	    void set(const OpcUaBooleanArray& value, OpcUaStatusCode statusCode = Success, const OpcUaDateTime& sourceTimestamp = OpcUaDateTime(boost::posix_time::microsec_clock::universal_time()));
	    void set(const OpcUaByteArray& value, OpcUaStatusCode statusCode = Success, const OpcUaDateTime& sourceTimestamp = OpcUaDateTime(boost::posix_time::microsec_clock::universal_time()));
	    void set(const OpcUaSByteArray& value, OpcUaStatusCode statusCode = Success, const OpcUaDateTime& sourceTimestamp = OpcUaDateTime(boost::posix_time::microsec_clock::universal_time()));
	    void set(const OpcUaInt16Array& value, OpcUaStatusCode statusCode = Success, const OpcUaDateTime& sourceTimestamp = OpcUaDateTime(boost::posix_time::microsec_clock::universal_time()));
	    void set(const OpcUaUInt16Array& value, OpcUaStatusCode statusCode = Success, const OpcUaDateTime& sourceTimestamp = OpcUaDateTime(boost::posix_time::microsec_clock::universal_time()));
	    void set(const OpcUaInt32Array& value, OpcUaStatusCode statusCode = Success, const OpcUaDateTime& sourceTimestamp = OpcUaDateTime(boost::posix_time::microsec_clock::universal_time()));
	    void set(const OpcUaUInt32Array& value, OpcUaStatusCode statusCode = Success, const OpcUaDateTime& sourceTimestamp = OpcUaDateTime(boost::posix_time::microsec_clock::universal_time()));
	    void set(const OpcUaInt64Array& value, OpcUaStatusCode statusCode = Success, const OpcUaDateTime& sourceTimestamp = OpcUaDateTime(boost::posix_time::microsec_clock::universal_time()));
	    void set(const OpcUaUInt64Array& value, OpcUaStatusCode statusCode = Success, const OpcUaDateTime& sourceTimestamp = OpcUaDateTime(boost::posix_time::microsec_clock::universal_time()));
	    void set(const OpcUaFloatArray& value, OpcUaStatusCode statusCode = Success, const OpcUaDateTime& sourceTimestamp = OpcUaDateTime(boost::posix_time::microsec_clock::universal_time()));
	    void set(const OpcUaDoubleArray& value, OpcUaStatusCode statusCode = Success, const OpcUaDateTime& sourceTimestamp = OpcUaDateTime(boost::posix_time::microsec_clock::universal_time()));
	    void set(const OpcUaStringArray& value, OpcUaStatusCode statusCode = Success, const OpcUaDateTime& sourceTimestamp = OpcUaDateTime(boost::posix_time::microsec_clock::universal_time()));
	    void set(const OpcUaDateTimeArray& value, OpcUaStatusCode statusCode = Success, const OpcUaDateTime& sourceTimestamp = OpcUaDateTime(boost::posix_time::microsec_clock::universal_time()));
	    void set(const OpcUaGuidArray& value, OpcUaStatusCode statusCode = Success, const OpcUaDateTime& sourceTimestamp = OpcUaDateTime(boost::posix_time::microsec_clock::universal_time()));
	    void set(const OpcUaByteStringArray& value, OpcUaStatusCode statusCode = Success, const OpcUaDateTime& sourceTimestamp = OpcUaDateTime(boost::posix_time::microsec_clock::universal_time()));
	    void set(const OpcUaXmlElementArray& value, OpcUaStatusCode statusCode = Success, const OpcUaDateTime& sourceTimestamp = OpcUaDateTime(boost::posix_time::microsec_clock::universal_time()));
	    void set(const OpcUaNodeIdArray& value, OpcUaStatusCode statusCode = Success, const OpcUaDateTime& sourceTimestamp = OpcUaDateTime(boost::posix_time::microsec_clock::universal_time()));
	    void set(const OpcUaExpandedNodeIdArray& value, OpcUaStatusCode statusCode = Success, const OpcUaDateTime& sourceTimestamp = OpcUaDateTime(boost::posix_time::microsec_clock::universal_time()));
	    void set(const OpcUaStatusCodeArray& value, OpcUaStatusCode statusCode = Success, const OpcUaDateTime& sourceTimestamp = OpcUaDateTime(boost::posix_time::microsec_clock::universal_time()));
	    void set(const OpcUaQualifiedNameArray& value, OpcUaStatusCode statusCode = Success, const OpcUaDateTime& sourceTimestamp = OpcUaDateTime(boost::posix_time::microsec_clock::universal_time()));
	    void set(const OpcUaLocalizedTextArray& value, OpcUaStatusCode statusCode = Success, const OpcUaDateTime& sourceTimestamp = OpcUaDateTime(boost::posix_time::microsec_clock::universal_time()));
	    void set(const OpcUaExtensionObjectArray& value, OpcUaStatusCode statusCode = Success, const OpcUaDateTime& sourceTimestamp = OpcUaDateTime(boost::posix_time::microsec_clock::universal_time()));

	    void set(const std::vector<OpcUaBoolean>& value, OpcUaStatusCode statusCode = Success, const OpcUaDateTime& sourceTimestamp = OpcUaDateTime(boost::posix_time::microsec_clock::universal_time()));
	    void set(const std::vector<OpcUaByte>& value, OpcUaStatusCode statusCode = Success, const OpcUaDateTime& sourceTimestamp = OpcUaDateTime(boost::posix_time::microsec_clock::universal_time()));
	    void set(const std::vector<OpcUaSByte>& value, OpcUaStatusCode statusCode = Success, const OpcUaDateTime& sourceTimestamp = OpcUaDateTime(boost::posix_time::microsec_clock::universal_time()));
	    void set(const std::vector<OpcUaInt16>& value, OpcUaStatusCode statusCode = Success, const OpcUaDateTime& sourceTimestamp = OpcUaDateTime(boost::posix_time::microsec_clock::universal_time()));
	    void set(const std::vector<OpcUaUInt16>& value, OpcUaStatusCode statusCode = Success, const OpcUaDateTime& sourceTimestamp = OpcUaDateTime(boost::posix_time::microsec_clock::universal_time()));
	    void set(const std::vector<OpcUaInt32>& value, OpcUaStatusCode statusCode = Success, const OpcUaDateTime& sourceTimestamp = OpcUaDateTime(boost::posix_time::microsec_clock::universal_time()));
	    void set(const std::vector<OpcUaUInt32>& value, OpcUaStatusCode statusCode = Success, const OpcUaDateTime& sourceTimestamp = OpcUaDateTime(boost::posix_time::microsec_clock::universal_time()));
	    void set(const std::vector<OpcUaInt64>& value, OpcUaStatusCode statusCode = Success, const OpcUaDateTime& sourceTimestamp = OpcUaDateTime(boost::posix_time::microsec_clock::universal_time()));
	    void set(const std::vector<OpcUaUInt64>& value, OpcUaStatusCode statusCode = Success, const OpcUaDateTime& sourceTimestamp = OpcUaDateTime(boost::posix_time::microsec_clock::universal_time()));

	    void set(const std::vector<OpcUaFloat>& value, OpcUaStatusCode statusCode = Success, const OpcUaDateTime& sourceTimestamp = OpcUaDateTime(boost::posix_time::microsec_clock::universal_time()));
	    void set(const std::vector<OpcUaDouble>& value, OpcUaStatusCode statusCode = Success, const OpcUaDateTime& sourceTimestamp = OpcUaDateTime(boost::posix_time::microsec_clock::universal_time()));


	    void set(const std::vector<OpcUaString::SPtr>& value, OpcUaStatusCode statusCode = Success, const OpcUaDateTime& sourceTimestamp = OpcUaDateTime(boost::posix_time::microsec_clock::universal_time()));
	    void set(const std::vector<OpcUaDateTime>& value, OpcUaStatusCode statusCode = Success, const OpcUaDateTime& sourceTimestamp = OpcUaDateTime(boost::posix_time::microsec_clock::universal_time()));
	    void set(const std::vector<OpcUaGuid::SPtr>& value, OpcUaStatusCode statusCode = Success, const OpcUaDateTime& sourceTimestamp = OpcUaDateTime(boost::posix_time::microsec_clock::universal_time()));
	    void set(const std::vector<OpcUaByteString::SPtr>& value, OpcUaStatusCode statusCode = Success, const OpcUaDateTime& sourceTimestamp = OpcUaDateTime(boost::posix_time::microsec_clock::universal_time()));
	    void set(const std::vector<OpcUaXmlElement::SPtr>& value, OpcUaStatusCode statusCode = Success, const OpcUaDateTime& sourceTimestamp = OpcUaDateTime(boost::posix_time::microsec_clock::universal_time()));
	    void set(const std::vector<OpcUaNodeId::SPtr>& value, OpcUaStatusCode statusCode = Success, const OpcUaDateTime& sourceTimestamp = OpcUaDateTime(boost::posix_time::microsec_clock::universal_time()));
	    void set(const std::vector<OpcUaExpandedNodeId::SPtr>& value, OpcUaStatusCode statusCode = Success, const OpcUaDateTime& sourceTimestamp = OpcUaDateTime(boost::posix_time::microsec_clock::universal_time()));
	    void set(const std::vector<OpcUaStatusCode>& value, OpcUaStatusCode statusCode = Success, const OpcUaDateTime& sourceTimestamp = OpcUaDateTime(boost::posix_time::microsec_clock::universal_time()));
	    void set(const std::vector<OpcUaQualifiedName::SPtr>& value, OpcUaStatusCode statusCode = Success, const OpcUaDateTime& sourceTimestamp = OpcUaDateTime(boost::posix_time::microsec_clock::universal_time()));
	    void set(const std::vector<OpcUaLocalizedText::SPtr>& value, OpcUaStatusCode statusCode = Success, const OpcUaDateTime& sourceTimestamp = OpcUaDateTime(boost::posix_time::microsec_clock::universal_time()));
	    void set(const std::vector<OpcUaExtensionObject::SPtr>& value, OpcUaStatusCode statusCode = Success, const OpcUaDateTime& sourceTimestamp = OpcUaDateTime(boost::posix_time::microsec_clock::universal_time()));


		void copyFrom(OpcUaDataValue& dataValue);
		void copyTo(OpcUaDataValue& dataValue);
		bool operator<(const OpcUaDataValue& dataValue) const;
		bool operator!=(const OpcUaDataValue& opcUaDataValue) const;
		bool operator==(const OpcUaDataValue& opcUaDataValue) const;

		void out(std::ostream& os) const;
		friend std::ostream& operator<<(std::ostream& os, const OpcUaDataValue& value) {
			value.out(os);
			return os;
		}

		bool opcUaBinaryEncode(std::ostream& os) const;
		bool opcUaBinaryDecode(std::istream& is);
		bool xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns);
		bool xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns);
		bool xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns);

      protected:
        bool jsonEncodeImpl(boost::property_tree::ptree &pt) const override;
        bool jsonDecodeImpl(const boost::property_tree::ptree &pt) override;

	  private:
		OpcUaVariant::SPtr opcUaVariantSPtr_;
		OpcUaStatusCode opcUaStatusCode_;
		OpcUaDateTime sourceTimestamp_;
		OpcUaInt16 sourcePicoseconds_;
		OpcUaDateTime serverTimestamp_;
		OpcUaInt16 serverPicoseconds_;
	};


	class DLLEXPORT OpcUaDataValueArray
	: public OpcUaArray<OpcUaDataValue::SPtr, SPtrTypeCoder<OpcUaDataValue> >
	, public Object
	{
	  public:
		typedef boost::shared_ptr<OpcUaDataValueArray> SPtr;
	};

}

#endif
