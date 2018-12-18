/*
   Copyright 2015-2017 Kai Huebl (kai@huebl-sgh.de)

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
#include "OpcUaStackCore/BuildInTypes/DataChangeTrigger.h"
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/Base/os.h"

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
	{
	  public:
		typedef boost::shared_ptr<OpcUaDataValue> SPtr;
		typedef std::vector<OpcUaDataValue::SPtr> Vec;

	    OpcUaDataValue(void);
	    OpcUaDataValue(const OpcUaNullValue& value, OpcUaStatusCode statusCode = Success, const OpcUaDateTime& sourceTimestamp = OpcUaDateTime(boost::posix_time::microsec_clock::universal_time()));
	    OpcUaDataValue(const OpcUaBoolean& value, OpcUaStatusCode statusCode = Success, const OpcUaDateTime& sourceTimestamp = OpcUaDateTime(boost::posix_time::microsec_clock::universal_time()));
	    OpcUaDataValue(const OpcUaByte& value, OpcUaStatusCode statusCode = Success, const OpcUaDateTime& sourceTimestamp = OpcUaDateTime(boost::posix_time::microsec_clock::universal_time()));
	    OpcUaDataValue(const OpcUaSByte& value, OpcUaStatusCode statusCode = Success, const OpcUaDateTime& sourceTimestamp = OpcUaDateTime(boost::posix_time::microsec_clock::universal_time()));
	    OpcUaDataValue(const OpcUaInt16& value, OpcUaStatusCode statusCode = Success, const OpcUaDateTime& sourceTimestamp = OpcUaDateTime(boost::posix_time::microsec_clock::universal_time()));
	    OpcUaDataValue(const OpcUaUInt16& value, OpcUaStatusCode statusCode = Success, const OpcUaDateTime& sourceTimestamp = OpcUaDateTime(boost::posix_time::microsec_clock::universal_time()));
	    OpcUaDataValue(const OpcUaInt32& value, OpcUaStatusCode statusCode = Success, const OpcUaDateTime& sourceTimestamp = OpcUaDateTime(boost::posix_time::microsec_clock::universal_time()));
	    OpcUaDataValue(const OpcUaUInt32& value, OpcUaStatusCode statusCode = Success, const OpcUaDateTime& sourceTimestamp = OpcUaDateTime(boost::posix_time::microsec_clock::universal_time()));
	    OpcUaDataValue(const OpcUaInt64& value, OpcUaStatusCode statusCode = Success, const OpcUaDateTime& sourceTimestamp = OpcUaDateTime(boost::posix_time::microsec_clock::universal_time()));
	    OpcUaDataValue(const OpcUaUInt64& value, OpcUaStatusCode statusCode = Success, const OpcUaDateTime& sourceTimestamp = OpcUaDateTime(boost::posix_time::microsec_clock::universal_time()));
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

		void copyFrom(OpcUaDataValue& dataValue);
		void copyTo(OpcUaDataValue& dataValue);
		bool operator!=(const OpcUaDataValue& opcUaDataValue) const;
		bool operator==(const OpcUaDataValue& opcUaDataValue) const;
		bool trigger(OpcUaDataValue::SPtr dataValue, DataChangeTrigger dataChangeTrigger = DCT_StatusValue);
		bool trigger(OpcUaDataValue& dataValue, DataChangeTrigger dataChangeTrigger = DCT_StatusValue);

		void out(std::ostream& os) const;
		friend std::ostream& operator<<(std::ostream& os, const OpcUaDataValue& value) {
			value.out(os);
			return os;
		}

		void opcUaBinaryEncode(std::ostream& os) const;
		void opcUaBinaryDecode(std::istream& is);
		bool encode(boost::property_tree::ptree& pt) const;
		bool decode(boost::property_tree::ptree& pt, OpcUaBuildInType type, bool isArray);
		bool xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns);
		bool xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns);
		bool xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns);

	  private:
		OpcUaVariant::SPtr opcUaVariantSPtr_;
		OpcUaStatusCode opcUaStatusCode_;
		OpcUaDateTime sourceTimestamp_;
		OpcUaInt16 sourcePicoseconds_;
		OpcUaDateTime serverTimestamp_;
		OpcUaInt16 serverPicoseconds_;
	};


	class OpcUaDataValueArray
	: public OpcUaArray<OpcUaDataValue::SPtr, SPtrTypeCoder<OpcUaDataValue> >
	, public Object
	{
	  public:
		typedef boost::shared_ptr<OpcUaDataValueArray> SPtr;
	};

}

#endif
