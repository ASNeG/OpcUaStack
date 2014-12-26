#ifndef __OpcUaStackCore_OpcUaVariant__
#define __OpcUaStackCore_OpcUaVariant__

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

		  void copyTo(OpcUaVariantValue& variantValue);

		  void out(std::ostream& os) const;
		  friend std::ostream& operator<<(std::ostream& os, const OpcUaVariantValue& value) {
			  value.out(os);
			  return os;
		  }

		  bool operator!=(OpcUaVariantValue& variantValue);
		  bool operator==(OpcUaVariantValue& variantValue);

		  void opcUaBinaryEncode(std::ostream& os, OpcUaBuildInType variantType) const;
		  void opcUaBinaryDecode(std::istream& is, OpcUaBuildInType variantType);

	  private:
		OpcUaVariantValueType variantValue_;
	};


	class DLLEXPORT OpcUaVariant : public ObjectPool<OpcUaVariant>
	{
	  public:
	    OpcUaVariant(void);
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
		template<typename VAL>
		  void variant(uint32_t pos, const VAL& val) {
			  variantValueVec_[pos].variant(val);
		  }
		template<typename VAL>
		  void variant(const VAL& val) {
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
		  VAL variant(uint32_t pos) const
		  {
			  return variantValueVec_[pos].variant<VAL>();
		  }
		template<typename VAL>
		  typename VAL::SPtr variantSPtr(void) const
		  {
			  return variantValueVec_[0].variantSPtr<VAL>();
		  }
		template<typename VAL>
		  typename VAL::SPtr variantSPtr(uint32_t pos) const
		  {
			  return variantValueVec_[pos].variantSPtr<VAL>();
		  }

		void copyTo(OpcUaVariant& variant);

		bool operator==(OpcUaVariant& variant);
		bool operator!=(OpcUaVariant& variant);

		void out(std::ostream& os) const;
		friend std::ostream& operator<<(std::ostream& os, const OpcUaVariant& value) {
			value.out(os);
			return os;
		}

		void opcUaBinaryEncode(std::ostream& os) const;
		void opcUaBinaryDecode(std::istream& is);

	  private:
		OpcUaInt32 arrayLength_;
		OpcUaArrayDimensionsVec arrayDimensionsVec_;
		OpcUaVariantValue::Vec variantValueVec_;
	};


	class OpcUaVariantArray : public OpcUaArray<OpcUaVariant::SPtr, SPtrTypeCoder<OpcUaVariant> >, public ObjectPool<OpcUaVariantArray> {};

};

#endif
