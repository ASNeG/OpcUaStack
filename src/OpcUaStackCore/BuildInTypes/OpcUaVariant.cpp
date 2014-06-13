#include "OpcUaStackCore/BuildInTypes/OpcUaVariant.h"

namespace OpcUaStackCore
{

	class OpcUaVariantTypeVisitor : public boost::static_visitor<>
	{
	  public:
		void operator()(OpcUaVariantNullType) { opcUaBuildInType_ = OpcUaBuildInType::OpcUaBuildInType_Unknown; }
		void operator()(OpcUaBoolean) { opcUaBuildInType_ = OpcUaBuildInType::OpcUaBuildInType_OpcUaBoolean; }
		void operator()(OpcUaSByte) { opcUaBuildInType_ = OpcUaBuildInType::OpcUaBuildInType_OpcUaSByte; }
		void operator()(OpcUaByte) { opcUaBuildInType_ = OpcUaBuildInType::OpcUaBuildInType_OpcUaByte; }
		void operator()(OpcUaInt16) { opcUaBuildInType_ = OpcUaBuildInType::OpcUaBuildInType_OpcUaInt16; }
		void operator()(OpcUaUInt16) { opcUaBuildInType_ = OpcUaBuildInType::OpcUaBuildInType_OpcUaUInt16; }
		void operator()(OpcUaInt32) { opcUaBuildInType_ = OpcUaBuildInType::OpcUaBuildInType_OpcUaInt32; }
		void operator()(OpcUaUInt32) { opcUaBuildInType_ = OpcUaBuildInType::OpcUaBuildInType_OpcUaUInt32; }
		void operator()(OpcUaInt64) { opcUaBuildInType_ = OpcUaBuildInType::OpcUaBuildInType_OpcUaInt64; }
		void operator()(OpcUaUInt64) { opcUaBuildInType_ = OpcUaBuildInType::OpcUaBuildInType_OpcUaUInt64; }
		void operator()(OpcUaFloat) { opcUaBuildInType_ = OpcUaBuildInType::OpcUaBuildInType_OpcUaFloat; }
		void operator()(OpcUaDouble) { opcUaBuildInType_ = OpcUaBuildInType::OpcUaBuildInType_OpcUaDouble; }
		void operator()(OpcUaDateTime) { opcUaBuildInType_ = OpcUaBuildInType::OpcUaBuildInType_OpcUaDateTime; }
		void operator()(OpcUaStatusCode) { opcUaBuildInType_ = OpcUaBuildInType::OpcUaBuildInType_OpcUaStatusCode; }
		void operator()(OpcUaVariantSPtr opcUaVariantSPtr) {  opcUaBuildInType_ = opcUaVariantSPtr.opcUaBuildInType_; }
		
		OpcUaBuildInType opcUaBuildInType_;
	};

	OpcUaVariantSPtr::OpcUaVariantSPtr(void)
	: opcUaBuildInType_()
	, objectSPtr_()
	{
	}
	
	OpcUaVariantSPtr::~OpcUaVariantSPtr(void)
	{
	}
		

	OpcUaVariant::OpcUaVariant(void)
	:  ObjectPool<OpcUaVariant>()
	, opcUaVariantValueVec_()
	, arrayLength_(-1)
	, arrayDimensionsVec_()
	{
	}
		
	OpcUaVariant::~OpcUaVariant(void)
	{
	}

	void 
	OpcUaVariant::arrayLength(const OpcUaInt32& arrayLength)
	{
		arrayLength_ = arrayLength;
	}

	OpcUaInt32 
	OpcUaVariant::arrayLength(void)
	{
		return arrayLength_;
	}

	void 
	OpcUaVariant::arrayDimension(const OpcUaInt32& arrayDimensions)
	{
		arrayDimensionsVec_.clear();
		arrayDimensionsVec_[0] = arrayDimensions;
	}
	
	OpcUaInt32 
	OpcUaVariant::arrayDimension(void)
	{
		if (arrayDimensionsVec_.size() == 0) {
			return -1;
		}
		return arrayDimensionsVec_[0];
	}

	OpcUaBuildInType 
	OpcUaVariant::variantType(void) const
	{
		if (opcUaVariantValueVec_.size() <  1) {
			return OpcUaBuildInType_Unknown; 
		}
		OpcUaVariantTypeVisitor opcUaVariantTypeVisitor;
		boost::apply_visitor(opcUaVariantTypeVisitor, opcUaVariantValueVec_[0]);
		return opcUaVariantTypeVisitor.opcUaBuildInType_;
	}

	void 
	OpcUaVariant::variant(const OpcUaGuid::SPtr valSPtr) 
	{
		OpcUaVariantSPtr val;
		val.opcUaBuildInType_ = OpcUaBuildInType_OpcUaGuid;
		val.objectSPtr_ = valSPtr;
		arrayLength_ = -1;
		opcUaVariantValueVec_.clear();
		opcUaVariantValueVec_.push_back(val);
	}

	void  
	OpcUaVariant::variant(const OpcUaXmlElement::SPtr valSPtr)
	{
		OpcUaVariantSPtr val;
		val.opcUaBuildInType_ = OpcUaBuildInType_OpcUaXmlElement;
		val.objectSPtr_ = valSPtr;
		arrayLength_ = -1;
		opcUaVariantValueVec_.clear();
		opcUaVariantValueVec_.push_back(val);
	}

	void  
	OpcUaVariant::variant(const OpcUaNodeId::SPtr valSPtr)
	{
		OpcUaVariantSPtr val;
		val.opcUaBuildInType_ = OpcUaBuildInType_OpcUaNodeId;
		val.objectSPtr_ = valSPtr;
		arrayLength_ = -1;
		opcUaVariantValueVec_.clear();
		opcUaVariantValueVec_.push_back(val);
	}

	void  
	OpcUaVariant::variant(const OpcUaExpandedNodeId::SPtr valSPtr)
	{
		OpcUaVariantSPtr val;
		val.opcUaBuildInType_ = OpcUaBuildInType_OpcUaExpandedNodeId;
		val.objectSPtr_ = valSPtr;
		arrayLength_ = -1;
		opcUaVariantValueVec_.clear();
		opcUaVariantValueVec_.push_back(val);
	}

	void  
	OpcUaVariant::variant(const OpcUaQualifiedName::SPtr valSPtr)
	{
		OpcUaVariantSPtr val;
		val.opcUaBuildInType_ = OpcUaBuildInType_OpcUaQualifiedName;
		val.objectSPtr_ = valSPtr;
		arrayLength_ = -1;
		opcUaVariantValueVec_.clear();
		opcUaVariantValueVec_.push_back(val);
	}

	void  
	OpcUaVariant::variant(const OpcUaLocalizedText::SPtr valSPtr)
	{
		OpcUaVariantSPtr val;
		val.opcUaBuildInType_ = OpcUaBuildInType_OpcUaLocalizedText;
		val.objectSPtr_ = valSPtr;
		arrayLength_ = -1;
		opcUaVariantValueVec_.clear();
		opcUaVariantValueVec_.push_back(val);
	}	
	void  
	OpcUaVariant::variant(const OpcUaExtensionObject::SPtr valSPtr)
	{
		OpcUaVariantSPtr val;
		val.opcUaBuildInType_ = OpcUaBuildInType_OpcUaExtensionObject;
		val.objectSPtr_ = valSPtr;
		arrayLength_ = -1;
		opcUaVariantValueVec_.clear();
		opcUaVariantValueVec_.push_back(val);
	}

	void 
	OpcUaVariant::opcUaBinaryEncode(std::ostream& os) const
	{
		OpcUaBuildInType variantType = this->variantType();
		OpcUaByte encodingMask = (OpcUaByte)variantType;

		if (variantType == OpcUaBuildInType::OpcUaBuildInType_Unknown) {
			return;
		}
		if (opcUaVariantValueVec_.size() < 1) {
			return;
		}
			 
		if (arrayLength_ != -1) {
			encodingMask += 64;
		}

		if (arrayDimensionsVec_.size() > 0) {
			encodingMask += 128;
		}

		OpcUaStackCore::opcUaBinaryEncode(os, encodingMask);
		if (arrayLength_ != -1) {
			OpcUaStackCore::opcUaBinaryEncode(os, arrayLength_);
		}

		OpcUaVariantValue opcUaVariantValue = opcUaVariantValueVec_[0];
		switch (variantType) 
		{
			case  OpcUaBuildInType::OpcUaBuildInType_OpcUaBoolean:
			{
				OpcUaStackCore::opcUaBinaryEncode(os, boost::get<OpcUaBoolean>(opcUaVariantValue));
				break;
			}
			case  OpcUaBuildInType::OpcUaBuildInType_OpcUaSByte:
			{
				OpcUaStackCore::opcUaBinaryEncode(os, boost::get<OpcUaSByte>(opcUaVariantValue));
				break;
			}
			case  OpcUaBuildInType::OpcUaBuildInType_OpcUaByte:
			{
				OpcUaStackCore::opcUaBinaryEncode(os, boost::get<OpcUaByte>(opcUaVariantValue));
				break;
			}
			case  OpcUaBuildInType::OpcUaBuildInType_OpcUaInt16:
			{
				OpcUaStackCore::opcUaBinaryEncode(os, boost::get<OpcUaInt16>(opcUaVariantValue));
				break;
			}
			case  OpcUaBuildInType::OpcUaBuildInType_OpcUaUInt16:
			{
				OpcUaStackCore::opcUaBinaryEncode(os, boost::get<OpcUaUInt16>(opcUaVariantValue));
				break;
			}
			case  OpcUaBuildInType::OpcUaBuildInType_OpcUaInt32:
			{
				OpcUaStackCore::opcUaBinaryEncode(os, boost::get<OpcUaInt32>(opcUaVariantValue));
				break;
			}
			case  OpcUaBuildInType::OpcUaBuildInType_OpcUaUInt32:
			{
				OpcUaStackCore::opcUaBinaryEncode(os, boost::get<OpcUaUInt32>(opcUaVariantValue));
				break;
			}
			case  OpcUaBuildInType::OpcUaBuildInType_OpcUaInt64:
			{
				OpcUaStackCore::opcUaBinaryEncode(os, boost::get<OpcUaInt64>(opcUaVariantValue));
				break;
			}
			case  OpcUaBuildInType::OpcUaBuildInType_OpcUaUInt64:
			{
				OpcUaStackCore::opcUaBinaryEncode(os, boost::get<OpcUaUInt64>(opcUaVariantValue));
				break;
			}
			case  OpcUaBuildInType::OpcUaBuildInType_OpcUaFloat:
			{
				OpcUaStackCore::opcUaBinaryEncode(os, boost::get<OpcUaFloat>(opcUaVariantValue));
				break;
			}
			case  OpcUaBuildInType::OpcUaBuildInType_OpcUaDouble:
			{
				OpcUaStackCore::opcUaBinaryEncode(os, boost::get<OpcUaDouble>(opcUaVariantValue));
				break;
			}
			case  OpcUaBuildInType::OpcUaBuildInType_OpcUaDateTime:
			{
				OpcUaStackCore::opcUaBinaryEncode(os, boost::get<OpcUaDateTime>(opcUaVariantValue));
				break;
			}
			case  OpcUaBuildInType::OpcUaBuildInType_OpcUaStatusCode:
			{
				OpcUaStackCore::opcUaBinaryEncode(os, boost::get<OpcUaStatusCode>(opcUaVariantValue));
				break;
			}
			case  OpcUaBuildInType::OpcUaBuildInType_OpcUaGuid:
			{
				OpcUaVariantSPtr opcUaVariantSPtr =  boost::get<OpcUaVariantSPtr>(opcUaVariantValue);
				OpcUaGuid::SPtr opcUaGuidSPtr = boost::static_pointer_cast<OpcUaGuid>(opcUaVariantSPtr.objectSPtr_);
				OpcUaStackCore::opcUaBinaryEncode(os,*opcUaGuidSPtr);
				break;
			}
			case  OpcUaBuildInType::OpcUaBuildInType_OpcUaByteString:
			{
				OpcUaVariantSPtr opcUaVariantSPtr =  boost::get<OpcUaVariantSPtr>(opcUaVariantValue);
				OpcUaByteString::SPtr opcUaByteStringSPtr = boost::static_pointer_cast<OpcUaByteString>(opcUaVariantSPtr.objectSPtr_);
				OpcUaStackCore::opcUaBinaryEncode(os,*opcUaByteStringSPtr);
				break;
			}
			case  OpcUaBuildInType::OpcUaBuildInType_OpcUaXmlElement:
			{
				OpcUaVariantSPtr opcUaVariantSPtr =  boost::get<OpcUaVariantSPtr>(opcUaVariantValue);
				OpcUaXmlElement::SPtr opcUaXmlElementSPtr = boost::static_pointer_cast<OpcUaXmlElement>(opcUaVariantSPtr.objectSPtr_);
				OpcUaStackCore::opcUaBinaryEncode(os,*opcUaXmlElementSPtr);
				break;
			}
			case  OpcUaBuildInType::OpcUaBuildInType_OpcUaNodeId:
			{
				OpcUaVariantSPtr opcUaVariantSPtr =  boost::get<OpcUaVariantSPtr>(opcUaVariantValue);
				OpcUaNodeId::SPtr opcUaNodeIdSPtr = boost::static_pointer_cast<OpcUaNodeId>(opcUaVariantSPtr.objectSPtr_);
				OpcUaStackCore::opcUaBinaryEncode(os,*opcUaNodeIdSPtr);
				break;
			}
			case  OpcUaBuildInType::OpcUaBuildInType_OpcUaExpandedNodeId:
			{
				OpcUaVariantSPtr opcUaVariantSPtr =  boost::get<OpcUaVariantSPtr>(opcUaVariantValue);
				OpcUaExpandedNodeId::SPtr opcUaExpandedNodeIdSPtr = boost::static_pointer_cast<OpcUaExpandedNodeId>(opcUaVariantSPtr.objectSPtr_);
				OpcUaStackCore::opcUaBinaryEncode(os,*opcUaExpandedNodeIdSPtr);
				break;
			}
			case  OpcUaBuildInType::OpcUaBuildInType_OpcUaQualifiedName:
			{
				OpcUaVariantSPtr opcUaVariantSPtr =  boost::get<OpcUaVariantSPtr>(opcUaVariantValue);
				OpcUaQualifiedName::SPtr opcUaQualifiedNameSPtr = boost::static_pointer_cast<OpcUaQualifiedName>(opcUaVariantSPtr.objectSPtr_);
				OpcUaStackCore::opcUaBinaryEncode(os,*opcUaQualifiedNameSPtr);
				break;
			}
			case  OpcUaBuildInType::OpcUaBuildInType_OpcUaLocalizedText:
			{
				OpcUaVariantSPtr opcUaVariantSPtr =  boost::get<OpcUaVariantSPtr>(opcUaVariantValue);
				OpcUaLocalizedText::SPtr opcUaLocalizedTextSPtr = boost::static_pointer_cast<OpcUaLocalizedText>(opcUaVariantSPtr.objectSPtr_);
				OpcUaStackCore::opcUaBinaryEncode(os,*opcUaLocalizedTextSPtr);
				break;
			}
			case  OpcUaBuildInType::OpcUaBuildInType_OpcUaExtensionObject:
			{
				OpcUaVariantSPtr opcUaVariantSPtr =  boost::get<OpcUaVariantSPtr>(opcUaVariantValue);
				OpcUaExtensionObject::SPtr opcUaExtensionObjectSPtr = boost::static_pointer_cast<OpcUaExtensionObject>(opcUaVariantSPtr.objectSPtr_);
				OpcUaStackCore::opcUaBinaryEncode(os,*opcUaExtensionObjectSPtr);
				break;
			}
		}

		if (arrayDimensionsVec_.size() > 0) {
			OpcUaStackCore::opcUaBinaryEncode(os, arrayDimensionsVec_[0]);
		}
	}
		
	void 
	OpcUaVariant::opcUaBinaryDecode(std::istream& is)
	{
		OpcUaByte encodingMask;

		OpcUaStackCore::opcUaBinaryDecode(is, encodingMask);

		arrayLength_ = -1;
		if ((encodingMask & 64) == 64) {
			OpcUaStackCore::opcUaBinaryDecode(is, arrayLength_);
		}

		if ((encodingMask & 128) == 128) {
			arrayDimensionsVec_.clear();
		}
		else {
			arrayDimensionsVec_.clear();
		}

		encodingMask = encodingMask & 0x3F;

		OpcUaVariantValue opcUaVariantValue;
		switch ((OpcUaBuildInType)encodingMask) 
		{
			case  OpcUaBuildInType::OpcUaBuildInType_OpcUaBoolean:
			{
				OpcUaBoolean opcUaBoolean;
				OpcUaStackCore::opcUaBinaryDecode(is, opcUaBoolean);
				opcUaVariantValue = opcUaBoolean;
				opcUaVariantValueVec_.push_back(opcUaVariantValue);
				break;
			}
			case  OpcUaBuildInType::OpcUaBuildInType_OpcUaSByte:
			{
				OpcUaSByte opcUaSByte;
				OpcUaStackCore::opcUaBinaryDecode(is, opcUaSByte);
				opcUaVariantValue = opcUaSByte;
				opcUaVariantValueVec_.push_back(opcUaVariantValue);
				break;
			}
			case  OpcUaBuildInType::OpcUaBuildInType_OpcUaByte:
			{
				OpcUaByte opcUaByte;
				OpcUaStackCore::opcUaBinaryDecode(is, opcUaByte);
				opcUaVariantValue = opcUaByte;
				opcUaVariantValueVec_.push_back(opcUaVariantValue);
				break;
			}
			case  OpcUaBuildInType::OpcUaBuildInType_OpcUaInt16:
			{
				OpcUaInt16 opcUaInt16;
				OpcUaStackCore::opcUaBinaryDecode(is, opcUaInt16);
				opcUaVariantValue = opcUaInt16;
				opcUaVariantValueVec_.push_back(opcUaVariantValue);
				break;
			}
			case  OpcUaBuildInType::OpcUaBuildInType_OpcUaUInt16:
			{
				OpcUaUInt16 opcUaUInt16;
				OpcUaStackCore::opcUaBinaryDecode(is, opcUaUInt16);
				opcUaVariantValue = opcUaUInt16;
				opcUaVariantValueVec_.push_back(opcUaVariantValue);
				break;
			}
			case  OpcUaBuildInType::OpcUaBuildInType_OpcUaInt32:
			{
				OpcUaInt32 opcUaInt32;
				OpcUaStackCore::opcUaBinaryDecode(is, opcUaInt32);
				opcUaVariantValue = opcUaInt32;
				opcUaVariantValueVec_.push_back(opcUaVariantValue);
				break;
			}
			case  OpcUaBuildInType::OpcUaBuildInType_OpcUaUInt32:
			{
				OpcUaUInt32 opcUaUInt32;
				OpcUaStackCore::opcUaBinaryDecode(is, opcUaUInt32);
				opcUaVariantValue = opcUaUInt32;
				opcUaVariantValueVec_.push_back(opcUaVariantValue);
				break;
			}
			case  OpcUaBuildInType::OpcUaBuildInType_OpcUaInt64:
			{
				OpcUaInt64 opcUaInt64;
				OpcUaStackCore::opcUaBinaryDecode(is, opcUaInt64);
				opcUaVariantValue = opcUaInt64;
				opcUaVariantValueVec_.push_back(opcUaVariantValue);
				break;
			}
			case  OpcUaBuildInType::OpcUaBuildInType_OpcUaUInt64:
			{
				OpcUaUInt64 opcUaUInt64;
				OpcUaStackCore::opcUaBinaryDecode(is, opcUaUInt64);
				opcUaVariantValue = opcUaUInt64;
				opcUaVariantValueVec_.push_back(opcUaVariantValue);
				break;
			}
			case  OpcUaBuildInType::OpcUaBuildInType_OpcUaFloat:
			{
				OpcUaFloat opcUaFloat;
				OpcUaStackCore::opcUaBinaryDecode(is, opcUaFloat);
				opcUaVariantValue = opcUaFloat;
				opcUaVariantValueVec_.push_back(opcUaVariantValue);
				break;
			}
			case  OpcUaBuildInType::OpcUaBuildInType_OpcUaDouble:
			{
				OpcUaDouble opcUaDouble;
				OpcUaStackCore::opcUaBinaryDecode(is, opcUaDouble);
				opcUaVariantValue = opcUaDouble;
				opcUaVariantValueVec_.push_back(opcUaVariantValue);
				break;
			}
			case  OpcUaBuildInType::OpcUaBuildInType_OpcUaDateTime:
			{
				OpcUaDateTime opcUaDateTime;
				OpcUaStackCore::opcUaBinaryDecode(is, opcUaDateTime);
				opcUaVariantValue = opcUaDateTime;
				opcUaVariantValueVec_.push_back(opcUaVariantValue);
				break;
			}
			case  OpcUaBuildInType::OpcUaBuildInType_OpcUaStatusCode:
			{
				OpcUaStatusCode opcUaStatusCode;
				OpcUaStackCore::opcUaBinaryDecode(is, opcUaStatusCode);
				opcUaVariantValue = opcUaStatusCode;
				opcUaVariantValueVec_.push_back(opcUaVariantValue);
				break;
			}
			case  OpcUaBuildInType::OpcUaBuildInType_OpcUaGuid:
			{
				OpcUaVariantSPtr val;

				OpcUaGuid::SPtr opcUaGuidSPtr = OpcUaGuid::construct();
				OpcUaStackCore::opcUaBinaryDecode(is, *opcUaGuidSPtr);
				val.objectSPtr_ = opcUaGuidSPtr;
				val.opcUaBuildInType_ = OpcUaBuildInType::OpcUaBuildInType_OpcUaGuid;
				opcUaVariantValue = val;
				opcUaVariantValueVec_.push_back(opcUaVariantValue);
				break;
			}
			case  OpcUaBuildInType::OpcUaBuildInType_OpcUaByteString:
			{
				OpcUaVariantSPtr val;

				OpcUaByteString::SPtr opcUaByteStringSPtr = OpcUaByteString::construct();
				OpcUaStackCore::opcUaBinaryDecode(is, *opcUaByteStringSPtr);
				val.objectSPtr_ = opcUaByteStringSPtr;
				val.opcUaBuildInType_ = OpcUaBuildInType::OpcUaBuildInType_OpcUaByteString;
				opcUaVariantValue = val;
				opcUaVariantValueVec_.push_back(opcUaVariantValue);
				break;
			}
			case  OpcUaBuildInType::OpcUaBuildInType_OpcUaXmlElement:
			{
				OpcUaVariantSPtr val;

				OpcUaXmlElement::SPtr opcUaXmlElementSPtr = OpcUaXmlElement::construct();
				OpcUaStackCore::opcUaBinaryDecode(is, *opcUaXmlElementSPtr);
				val.objectSPtr_ = opcUaXmlElementSPtr;
				val.opcUaBuildInType_ = OpcUaBuildInType::OpcUaBuildInType_OpcUaXmlElement;
				opcUaVariantValue = val;
				opcUaVariantValueVec_.push_back(opcUaVariantValue);
				break;
			}
			case  OpcUaBuildInType::OpcUaBuildInType_OpcUaNodeId:
			{
				OpcUaVariantSPtr val;

				OpcUaNodeId::SPtr opcUaNodeIdSPtr = OpcUaNodeId::construct();
				OpcUaStackCore::opcUaBinaryDecode(is, *opcUaNodeIdSPtr);
				val.objectSPtr_ = opcUaNodeIdSPtr;
				val.opcUaBuildInType_ = OpcUaBuildInType::OpcUaBuildInType_OpcUaNodeId;
				opcUaVariantValue = val;
				opcUaVariantValueVec_.push_back(opcUaVariantValue);
				break;
			}
			case  OpcUaBuildInType::OpcUaBuildInType_OpcUaExpandedNodeId:
			{
				OpcUaVariantSPtr val;

				OpcUaExpandedNodeId::SPtr opcUaExpandedNodeIdSPtr = OpcUaExpandedNodeId::construct();
				OpcUaStackCore::opcUaBinaryDecode(is, *opcUaExpandedNodeIdSPtr);
				val.objectSPtr_ = opcUaExpandedNodeIdSPtr;
				val.opcUaBuildInType_ = OpcUaBuildInType::OpcUaBuildInType_OpcUaExpandedNodeId;
				opcUaVariantValue = val;
				opcUaVariantValueVec_.push_back(opcUaVariantValue);
				break;
			}
			case  OpcUaBuildInType::OpcUaBuildInType_OpcUaQualifiedName:
			{
				OpcUaVariantSPtr val;

				OpcUaQualifiedName::SPtr opcUaQualifiedNameSPtr = OpcUaQualifiedName::construct();
				OpcUaStackCore::opcUaBinaryDecode(is, *opcUaQualifiedNameSPtr);
				val.objectSPtr_ = opcUaQualifiedNameSPtr;
				val.opcUaBuildInType_ = OpcUaBuildInType::OpcUaBuildInType_OpcUaQualifiedName;
				opcUaVariantValue = val;
				opcUaVariantValueVec_.push_back(opcUaVariantValue);
				break;
			}
			case  OpcUaBuildInType::OpcUaBuildInType_OpcUaLocalizedText:
			{
				OpcUaVariantSPtr val;

				OpcUaLocalizedText::SPtr opcUaLocalizedTextSPtr = OpcUaLocalizedText::construct();
				OpcUaStackCore::opcUaBinaryDecode(is, *opcUaLocalizedTextSPtr);
				val.objectSPtr_ = opcUaLocalizedTextSPtr;
				val.opcUaBuildInType_ = OpcUaBuildInType::OpcUaBuildInType_OpcUaLocalizedText;
				opcUaVariantValue = val;
				opcUaVariantValueVec_.push_back(opcUaVariantValue);
				break;
			}
			case  OpcUaBuildInType::OpcUaBuildInType_OpcUaExtensionObject:
			{
				OpcUaVariantSPtr val;

				OpcUaExtensionObject::SPtr opcUaExtensionObjectSPtr = OpcUaExtensionObject::construct();
				OpcUaStackCore::opcUaBinaryDecode(is, *opcUaExtensionObjectSPtr);
				val.objectSPtr_ = opcUaExtensionObjectSPtr;
				val.opcUaBuildInType_ = OpcUaBuildInType::OpcUaBuildInType_OpcUaExtensionObject;
				opcUaVariantValue = val;
				opcUaVariantValueVec_.push_back(opcUaVariantValue);
				break;
			}
			default:
			{
				OpcUaVariantValue opcUaVariantValue;
				opcUaVariantValueVec_.push_back(opcUaVariantValue);
			}
		}

		if (arrayDimensionsVec_.size() > 0) {
			OpcUaUInt32 arrayDimensions;
			OpcUaStackCore::opcUaBinaryDecode(is, arrayDimensions);
			arrayDimensionsVec_.clear();
		}
	}

	void 
	opcUaBinaryEncode(std::ostream& os, const OpcUaVariant& value)
	{
		value.opcUaBinaryEncode(os);
	}

	void 
	opcUaBinaryDecode(std::istream& is, OpcUaVariant& value)
	{
		value.opcUaBinaryDecode(is);
	}

};