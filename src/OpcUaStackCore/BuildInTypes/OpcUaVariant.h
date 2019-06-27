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

#ifndef __OpcUaStackCore_OpcUaVariant__
#define __OpcUaStackCore_OpcUaVariant__

#include <boost/property_tree/ptree.hpp>
#include "OpcUaStackCore/BuildInTypes/Xmlns.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaNumber.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaVariant.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaDateTime.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaGuid.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaByteString.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaXmlElement.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaNodeId.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaExpandedNodeId.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaStatusCode.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaQualifiedName.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaLocalizedText.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaExtensionObject.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaType.h"
#include "OpcUaStackCore/Base/os.h"

namespace OpcUaStackCore
{
	class DLLEXPORT OpcUaVariantSPtr
	{
	  public:
		OpcUaVariantSPtr(void);
		~OpcUaVariantSPtr(void);

		OpcUaBuildInType opcUaBuildInType_;
		Object::SPtr objectSPtr_;
	};

	class OpcUaVariantNullType
	{
	  public:
		OpcUaVariantNullType(void) {}
		~OpcUaVariantNullType(void) {}
	};

	typedef boost::variant<
		OpcUaVariantNullType,
		OpcUaBoolean,
		OpcUaSByte,
		OpcUaByte,
		OpcUaInt16,
		OpcUaUInt16,
		OpcUaInt32,
		OpcUaUInt32,
		OpcUaInt64,
		OpcUaUInt64,
		OpcUaFloat,
		OpcUaDouble,
		OpcUaDateTime,
		OpcUaStatusCode,
		OpcUaVariantSPtr
	> OpcUaVariantValueType;

	typedef std::vector<OpcUaUInt32> OpcUaArrayDimensionsVec;

	class DLLEXPORT OpcUaVariantValue
	{
	  public:
		typedef std::vector<OpcUaVariantValue> Vec;

		OpcUaVariantValue(void);
		~OpcUaVariantValue(void);

		OpcUaBuildInType variantType(void) const;
		bool isNull(void) const;

		template<typename VAL>
		  void variant(const VAL& val) {
			  variantValue_ = val;
		  }
		void variant(const OpcUaGuid::SPtr valSPtr);
		void variant(const OpcUaByteString::SPtr valSPtr);
		void variant(const OpcUaString::SPtr valSPtr);
		void variant(const OpcUaXmlElement::SPtr valSPtr);
		void variant(const OpcUaNodeId::SPtr valSPtr);
		void variant(const OpcUaExpandedNodeId::SPtr valSPtr);
		void variant(const OpcUaQualifiedName::SPtr valSPtr);
		void variant(const OpcUaLocalizedText::SPtr valSPtr);
		void variant(const OpcUaExtensionObject::SPtr valSPtr);

		template<typename VAL> 
		  VAL variant(void) const
		  {
		      return boost::get<VAL>(variantValue_);
		  }
		template<typename VAL>
		  typename VAL::SPtr variantSPtr(void) const
		  {
		      OpcUaVariantSPtr val = boost::get<OpcUaVariantSPtr>(variantValue_);
			  return boost::static_pointer_cast<VAL>(val.objectSPtr_);
		  }

		bool fromString(const std::string& string);
		bool fromString(OpcUaBuildInType type, const std::string& string);
		void copyTo(OpcUaVariantValue& variantValue);

		void out(std::ostream& os) const;
		friend std::ostream& operator<<(std::ostream& os, const OpcUaVariantValue& value) {
			value.out(os);
			return os;
		}

		bool operator!=(OpcUaVariantValue& variantValue);
		bool operator==(OpcUaVariantValue& variantValue);
		bool operator<(OpcUaVariantValue& variantValue);
		bool operator<=(OpcUaVariantValue& variantValue);
		bool operator>(OpcUaVariantValue& variantValue);
		bool operator>=(OpcUaVariantValue& variantValue);

		void opcUaBinaryEncode(std::ostream& os, OpcUaBuildInType variantType) const;
		void opcUaBinaryDecode(std::istream& is, OpcUaBuildInType variantType);
		bool encode(boost::property_tree::ptree& pt, OpcUaBuildInType opcUaBuildInType) const;
		bool decode(boost::property_tree::ptree& pt, OpcUaBuildInType opcUaBuildInType);
		bool xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns);
		bool xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns);
		bool xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns);

	  private:
		OpcUaVariantValueType variantValue_;
	};


	class DLLEXPORT OpcUaVariant
	: public Object
	{
	  public:
		typedef boost::shared_ptr<OpcUaVariant> SPtr;
		typedef std::vector<OpcUaVariant::SPtr> Vec;

	    OpcUaVariant(void);
	    OpcUaVariant(const OpcUaBoolean value);
	    OpcUaVariant(const OpcUaByte value);
	    OpcUaVariant(const OpcUaSByte value);
	    OpcUaVariant(const OpcUaUInt16 value);
	    OpcUaVariant(const OpcUaInt16 value);
	    OpcUaVariant(const OpcUaUInt32 value);
	    OpcUaVariant(const OpcUaInt32 value);
	    OpcUaVariant(const OpcUaUInt64 value);
	    OpcUaVariant(const OpcUaInt64 value);
	    OpcUaVariant(const OpcUaFloat value);
	    OpcUaVariant(const OpcUaDouble value);
	    OpcUaVariant(const OpcUaString& value);
	    OpcUaVariant(const OpcUaDateTime& value);
	    OpcUaVariant(const OpcUaGuid& value);
	    OpcUaVariant(const OpcUaByteString& value);
	    OpcUaVariant(const OpcUaXmlElement& value);
	    OpcUaVariant(const OpcUaNodeId& value);
	    OpcUaVariant(const OpcUaExpandedNodeId& value);
	    OpcUaVariant(const OpcUaStatusCode& value);
	    OpcUaVariant(const OpcUaQualifiedName& value);
	    OpcUaVariant(const OpcUaLocalizedText& value);
	    OpcUaVariant(const OpcUaExtensionObject& value);
		virtual ~OpcUaVariant(void);

		void clear(void);

		void arrayLength(const OpcUaInt32& arrayLength);
		OpcUaInt32 arrayLength(void);
		bool isArray(void);
		void arrayDimension(const OpcUaArrayDimensionsVec& arrayDimensionsVec);
		OpcUaArrayDimensionsVec& arrayDimension(void);
		void variant(const OpcUaVariantValue::Vec& variantValueVec);
		void variant(const OpcUaBuildInType& opcUaBuildInType);
		OpcUaVariantValue::Vec& variant(void);
		void pushBack(const OpcUaVariantValue& variantValue);

		OpcUaBuildInType variantType(void) const;
		bool isNull(void) const;

		template<typename VAL>
		  void variant(uint32_t pos, const VAL& val) {
			  variantValueVec_[pos].variant(val);
		  }
		template<typename VAL>
		  void set(uint32_t pos, const VAL& val) {
			  variantValueVec_[pos].variant(val);
		  }
		template<typename VAL>
		  void variant(const VAL& val) {
			  clear();
			  variantValueVec_[0].variant(val);
		  }
		template<typename VAL>
		  void set(const VAL& val) {
			  clear();
			  variantValueVec_[0].variant(val);
		  }
		template<typename VAL>
		  void pushBack(const VAL& val) {
			  OpcUaVariantValue variantValue;
			  variantValue.variant(val);
			  pushBack(variantValue);
		  }

		template<typename VAL> 
		  VAL variant(void) const
		  {
			  return variantValueVec_[0].variant<VAL>();
		  }
		template<typename VAL> 
		  VAL get(void) const
		  {
			 return variantValueVec_[0].variant<VAL>();
		  }
		template<typename VAL>
		  VAL variant(uint32_t pos) const
		  {
			  return variantValueVec_[pos].variant<VAL>();
		  }
		template<typename VAL>
		  VAL get(uint32_t pos) const
	      {
			  return variantValueVec_[pos].variant<VAL>();
		  }
		template<typename VAL>
		  typename VAL::SPtr variantSPtr(void) const
		  {
			  return variantValueVec_[0].variantSPtr<VAL>();
		  }
		template<typename VAL>
		  typename VAL::SPtr getSPtr(void) const
		  {
			  return variantValueVec_[0].variantSPtr<VAL>();
		  }
		template<typename VAL>
		  typename VAL::SPtr variantSPtr(uint32_t pos) const
		  {
			  return variantValueVec_[pos].variantSPtr<VAL>();
		  }
		template<typename VAL>
		  typename VAL::SPtr getSPtr(uint32_t pos) const
		  {
			  return variantValueVec_[pos].variantSPtr<VAL>();
		  }

		bool fromString(const std::string& string);
		bool fromString(OpcUaBuildInType type, bool isArray, const std::string& string);

		void copyTo(OpcUaVariant& variant);
		void copyFrom(OpcUaVariant& variant);

		bool operator==(OpcUaVariant& variant);
		bool operator!=(OpcUaVariant& variant);

		void out(std::ostream& os) const;
		friend std::ostream& operator<<(std::ostream& os, const OpcUaVariant& value) {
			value.out(os);
			return os;
		}

		void setValue(const OpcUaBoolean value);
		void setValue(const OpcUaByte value);
		void setValue(const OpcUaSByte value);
		void setValue(const OpcUaUInt16 value);
		void setValue(const OpcUaInt16 value);
		void setValue(const OpcUaUInt32 value);
		void setValue(const OpcUaInt32 value);
		void setValue(const OpcUaUInt64 value);
		void setValue(const OpcUaInt64 value);
		void setValue(const OpcUaFloat value);
		void setValue(const OpcUaDouble value);
		void setValue(const OpcUaString& value);
		void setValue(const OpcUaDateTime& value);
		void setValue(const OpcUaGuid& value);
		void setValue(const OpcUaByteString& value);
		void setValue(const OpcUaXmlElement& value);
		void setValue(const OpcUaNodeId& value);
		void setValue(const OpcUaExpandedNodeId& value);
		void setValue(const OpcUaStatusCode& value);
		void setValue(const OpcUaQualifiedName& value);
		void setValue(const OpcUaLocalizedText& value);
		void setValue(const OpcUaExtensionObject& value);

		bool getValue(OpcUaBoolean& value);
		bool getValue(OpcUaByte& value);
		bool getValue(OpcUaSByte& value);
		bool getValue(OpcUaUInt16& value);
		bool getValue(OpcUaInt16& value);
		bool getValue(OpcUaUInt32& value);
		bool getValue(OpcUaInt32& value);
		bool getValue(OpcUaUInt64& value);
		bool getValue(OpcUaInt64& value);
		bool getValue(OpcUaFloat& value);
		bool getValue(OpcUaDouble& value);
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

		void opcUaBinaryEncode(std::ostream& os) const;
		void opcUaBinaryDecode(std::istream& is);
		bool encode(boost::property_tree::ptree& pt) const;
		bool decode(boost::property_tree::ptree& pt, const OpcUaBuildInType& opcUaBuildInType, bool isArray);
		bool xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns);
		bool xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns);
		bool xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns);

	  private:
		bool xmlEncodeBooleanScalar(boost::property_tree::ptree& pt, Xmlns& xmlns);
		bool xmlEncodeBooleanArray(boost::property_tree::ptree& pt, Xmlns& xmlns);
		bool xmlDecodeBooleanScalar(boost::property_tree::ptree& pt, Xmlns& xmlns, const std::string& element);
		bool xmlDecodeBooleanArray(boost::property_tree::ptree& pt, Xmlns& xmlns, const std::string& element);

		bool xmlEncodeSByteScalar(boost::property_tree::ptree& pt, Xmlns& xmlns);
		bool xmlEncodeSByteArray(boost::property_tree::ptree& pt, Xmlns& xmlns);
		bool xmlDecodeSByteScalar(boost::property_tree::ptree& pt, Xmlns& xmlns, const std::string& element);
		bool xmlDecodeSByteArray(boost::property_tree::ptree& pt, Xmlns& xmlns, const std::string& element);

		bool xmlEncodeByteScalar(boost::property_tree::ptree& pt, Xmlns& xmlns);
		bool xmlEncodeByteArray(boost::property_tree::ptree& pt, Xmlns& xmlns);
		bool xmlDecodeByteScalar(boost::property_tree::ptree& pt, Xmlns& xmlns, const std::string& element);
		bool xmlDecodeByteArray(boost::property_tree::ptree& pt, Xmlns& xmlns, const std::string& element);

		bool xmlEncodeUInt16Scalar(boost::property_tree::ptree& pt, Xmlns& xmlns);
		bool xmlEncodeUInt16Array(boost::property_tree::ptree& pt, Xmlns& xmlns);
		bool xmlDecodeUInt16Scalar(boost::property_tree::ptree& pt, Xmlns& xmlns, const std::string& element);
		bool xmlDecodeUInt16Array(boost::property_tree::ptree& pt, Xmlns& xmlns, const std::string& element);

		bool xmlEncodeInt16Scalar(boost::property_tree::ptree& pt, Xmlns& xmlns);
		bool xmlEncodeInt16Array(boost::property_tree::ptree& pt, Xmlns& xmlns);
		bool xmlDecodeInt16Scalar(boost::property_tree::ptree& pt, Xmlns& xmlns, const std::string& element);
		bool xmlDecodeInt16Array(boost::property_tree::ptree& pt, Xmlns& xmlns, const std::string& element);

		bool xmlEncodeUInt32Scalar(boost::property_tree::ptree& pt, Xmlns& xmlns);
		bool xmlEncodeUInt32Array(boost::property_tree::ptree& pt, Xmlns& xmlns);
		bool xmlDecodeUInt32Scalar(boost::property_tree::ptree& pt, Xmlns& xmlns, const std::string& element);
		bool xmlDecodeUInt32Array(boost::property_tree::ptree& pt, Xmlns& xmlns, const std::string& element);

		bool xmlEncodeInt32Scalar(boost::property_tree::ptree& pt, Xmlns& xmlns);
		bool xmlEncodeInt32Array(boost::property_tree::ptree& pt, Xmlns& xmlns);
		bool xmlDecodeInt32Scalar(boost::property_tree::ptree& pt, Xmlns& xmlns, const std::string& element);
		bool xmlDecodeInt32Array(boost::property_tree::ptree& pt, Xmlns& xmlns, const std::string& element);

		bool xmlEncodeUInt64Scalar(boost::property_tree::ptree& pt, Xmlns& xmlns);
		bool xmlEncodeUInt64Array(boost::property_tree::ptree& pt, Xmlns& xmlns);
		bool xmlDecodeUInt64Scalar(boost::property_tree::ptree& pt, Xmlns& xmlns, const std::string& element);
		bool xmlDecodeUInt64Array(boost::property_tree::ptree& pt, Xmlns& xmlns, const std::string& element);

		bool xmlEncodeInt64Scalar(boost::property_tree::ptree& pt, Xmlns& xmlns);
		bool xmlEncodeInt64Array(boost::property_tree::ptree& pt, Xmlns& xmlns);
		bool xmlDecodeInt64Scalar(boost::property_tree::ptree& pt, Xmlns& xmlns, const std::string& element);
		bool xmlDecodeInt64Array(boost::property_tree::ptree& pt, Xmlns& xmlns, const std::string& element);

		bool xmlEncodeFloatScalar(boost::property_tree::ptree& pt, Xmlns& xmlns);
		bool xmlEncodeFloatArray(boost::property_tree::ptree& pt, Xmlns& xmlns);
		bool xmlDecodeFloatScalar(boost::property_tree::ptree& pt, Xmlns& xmlns, const std::string& element);
		bool xmlDecodeFloatArray(boost::property_tree::ptree& pt, Xmlns& xmlns, const std::string& element);

		bool xmlEncodeDoubleScalar(boost::property_tree::ptree& pt, Xmlns& xmlns);
		bool xmlEncodeDoubleArray(boost::property_tree::ptree& pt, Xmlns& xmlns);
		bool xmlDecodeDoubleScalar(boost::property_tree::ptree& pt, Xmlns& xmlns, const std::string& element);
		bool xmlDecodeDoubleArray(boost::property_tree::ptree& pt, Xmlns& xmlns, const std::string& element);

		bool xmlEncodeDateTimeScalar(boost::property_tree::ptree& pt, Xmlns& xmlns);
		bool xmlEncodeDateTimeArray(boost::property_tree::ptree& pt, Xmlns& xmlns);
		bool xmlDecodeDateTimeScalar(boost::property_tree::ptree& pt, Xmlns& xmlns, const std::string& element);
		bool xmlDecodeDateTimeArray(boost::property_tree::ptree& pt, Xmlns& xmlns, const std::string& element);

		bool xmlEncodeStringScalar(boost::property_tree::ptree& pt, Xmlns& xmlns);
		bool xmlEncodeStringArray(boost::property_tree::ptree& pt, Xmlns& xmlns);
		bool xmlDecodeStringScalar(boost::property_tree::ptree& pt, Xmlns& xmlns, const std::string& element);
		bool xmlDecodeStringArray(boost::property_tree::ptree& pt, Xmlns& xmlns, const std::string& element);

		bool xmlEncodeByteStringScalar(boost::property_tree::ptree& pt, Xmlns& xmlns);
		bool xmlEncodeByteStringArray(boost::property_tree::ptree& pt, Xmlns& xmlns);
		bool xmlDecodeByteStringScalar(boost::property_tree::ptree& pt, Xmlns& xmlns, const std::string& element);
		bool xmlDecodeByteStringArray(boost::property_tree::ptree& pt, Xmlns& xmlns, const std::string& element);

		bool xmlEncodeGuidScalar(boost::property_tree::ptree& pt, Xmlns& xmlns);
		bool xmlEncodeGuidArray(boost::property_tree::ptree& pt, Xmlns& xmlns);
		bool xmlDecodeGuidScalar(boost::property_tree::ptree& pt, Xmlns& xmlns, const std::string& element);
		bool xmlDecodeGuidArray(boost::property_tree::ptree& pt, Xmlns& xmlns, const std::string& element);

		bool xmlEncodeNodeIdScalar(boost::property_tree::ptree& pt, Xmlns& xmlns);
		bool xmlEncodeNodeIdArray(boost::property_tree::ptree& pt, Xmlns& xmlns);
		bool xmlDecodeNodeIdScalar(boost::property_tree::ptree& pt, Xmlns& xmlns, const std::string& element);
		bool xmlDecodeNodeIdArray(boost::property_tree::ptree& pt, Xmlns& xmlns, const std::string& element);

		bool xmlEncodeExpandedNodeIdScalar(boost::property_tree::ptree& pt, Xmlns& xmlns);
		bool xmlEncodeExpandedNodeIdArray(boost::property_tree::ptree& pt, Xmlns& xmlns);
		bool xmlDecodeExpandedNodeIdScalar(boost::property_tree::ptree& pt, Xmlns& xmlns, const std::string& element);
		bool xmlDecodeExpandedNodeIdArray(boost::property_tree::ptree& pt, Xmlns& xmlns, const std::string& element);

		bool xmlEncodeQualifiedNameScalar(boost::property_tree::ptree& pt, Xmlns& xmlns);
		bool xmlEncodeQualifiedNameArray(boost::property_tree::ptree& pt, Xmlns& xmlns);
		bool xmlDecodeQualifiedNameScalar(boost::property_tree::ptree& pt, Xmlns& xmlns, const std::string& element);
		bool xmlDecodeQualifiedNameArray(boost::property_tree::ptree& pt, Xmlns& xmlns, const std::string& element);

		bool xmlEncodeLocalizedTextScalar(boost::property_tree::ptree& pt, Xmlns& xmlns);
		bool xmlEncodeLocalizedTextArray(boost::property_tree::ptree& pt, Xmlns& xmlns);
		bool xmlDecodeLocalizedTextScalar(boost::property_tree::ptree& pt, Xmlns& xmlns, const std::string& element);
		bool xmlDecodeLocalizedTextArray(boost::property_tree::ptree& pt, Xmlns& xmlns, const std::string& element);

		bool xmlEncodeExtensionObjectScalar(boost::property_tree::ptree& pt, Xmlns& xmlns);
		bool xmlEncodeExtensionObjectArray(boost::property_tree::ptree& pt, Xmlns& xmlns);
		bool xmlDecodeExtensionObjectScalar(boost::property_tree::ptree& pt, Xmlns& xmlns, const std::string& element);
		bool xmlDecodeExtensionObjectArray(boost::property_tree::ptree& pt, Xmlns& xmlns, const std::string& element);


		OpcUaInt32 arrayLength_;
		OpcUaArrayDimensionsVec arrayDimensionsVec_;
		OpcUaVariantValue::Vec variantValueVec_;
	};


	class OpcUaVariantArray
	: public OpcUaArray<OpcUaVariant::SPtr, SPtrTypeCoder<OpcUaVariant> >
	, public Object
	{
	  public:
		typedef boost::shared_ptr<OpcUaVariantArray> SPtr;
	};

};

#endif
