#ifndef __OpcUaStackCore_OpcUaVariant__
#define __OpcUaStackCore_OpcUaVariant__

#include "OpcUaStackCore/BuildInTypes/OpcUaNumber.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaString.h"
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
	> OpcUaVariantValue;

	typedef std::vector<OpcUaVariantValue> OpcUaVariantValueVec;
	typedef std::vector<OpcUaUInt32> ArrayDimensionsVec;

	class DLLEXPORT OpcUaVariant : public ObjectPool<OpcUaVariant>
	{
	  public:
	    OpcUaVariant(void);
		virtual ~OpcUaVariant(void);

		void arrayLength(const OpcUaInt32& arrayLength);
		OpcUaInt32 arrayLength(void);
		void arrayDimension(const OpcUaInt32& arrayDimensions);
		OpcUaInt32 arrayDimension(void);

		OpcUaBuildInType variantType(void) const;
		template<typename VAL>
		  void variant(const VAL& val) {
			  OpcUaVariantValue opcUaVariantValue;
			  opcUaVariantValue = val;
			  arrayLength_ = -1;
			  opcUaVariantValueVec_.clear();
			  opcUaVariantValueVec_.push_back(opcUaVariantValue);
		  }
		void variant(const OpcUaGuid::SPtr valSPtr);
		void variant(const OpcUaXmlElement::SPtr valSPtr);
		void variant(const OpcUaNodeId::SPtr valSPtr);
		void variant(const OpcUaExpandedNodeId::SPtr valSPtr);
		void variant(const OpcUaQualifiedName::SPtr valSPtr);
		void variant(const OpcUaLocalizedText::SPtr valSPtr);
		void variant(const OpcUaExtensionObject::SPtr valSPtr);

		template<typename VAL> 
		  VAL variant(void) const
		  {
			  if (opcUaVariantValueVec_.size() < 1) {
				  return VAL();
			  }
		      return boost::get<VAL>(opcUaVariantValueVec_[0]);
		  }
		template<typename VAL>
		  typename VAL::SPtr variantSPtr(void) const
		  {
			  if (opcUaVariantValueVec_.size() < 1) {
				  return VAL::SPtr();
			  }
		      OpcUaVariantSPtr val = boost::get<OpcUaVariantSPtr>(opcUaVariantValueVec_[0]);
			  return boost::static_pointer_cast<VAL>(val.objectSPtr_);
		  }

		void opcUaBinaryEncode(std::ostream& os) const;
		void opcUaBinaryDecode(std::istream& is);

	  private:
		OpcUaInt32 arrayLength_;
		ArrayDimensionsVec arrayDimensionsVec_;
		OpcUaVariantValueVec opcUaVariantValueVec_;
	};

	DLLEXPORT void opcUaBinaryEncode(std::ostream& os, const OpcUaVariant& value);
	DLLEXPORT void opcUaBinaryDecode(std::istream& is, OpcUaVariant& value);


};

#endif