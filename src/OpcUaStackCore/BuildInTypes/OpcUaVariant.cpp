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
		

	// -------------------------------------------------------------------------
	// -------------------------------------------------------------------------
	//
	// OpcUaVariantValue
	//
	// -------------------------------------------------------------------------
	// -------------------------------------------------------------------------
	OpcUaVariantValue::OpcUaVariantValue(void)
	: variantValue_()
	{
	}
	
	OpcUaVariantValue::~OpcUaVariantValue(void)
	{
	}

	OpcUaBuildInType 
	OpcUaVariantValue::variantType(void) const
	{
		OpcUaVariantTypeVisitor opcUaVariantTypeVisitor;
		boost::apply_visitor(opcUaVariantTypeVisitor, variantValue_);
		return opcUaVariantTypeVisitor.opcUaBuildInType_;
	}

	void 
	OpcUaVariantValue::variant(const OpcUaGuid::SPtr valSPtr) 
	{
		OpcUaVariantSPtr val;
		val.opcUaBuildInType_ = OpcUaBuildInType_OpcUaGuid;
		val.objectSPtr_ = valSPtr;
		variantValue_ = val;
	}

	void  
	OpcUaVariantValue::variant(const OpcUaXmlElement::SPtr valSPtr)
	{
		OpcUaVariantSPtr val;
		val.opcUaBuildInType_ = OpcUaBuildInType_OpcUaXmlElement;
		val.objectSPtr_ = valSPtr;
		val.objectSPtr_ = valSPtr;
		variantValue_ = val;
	}

	void  
	OpcUaVariantValue::variant(const OpcUaNodeId::SPtr valSPtr)
	{
		OpcUaVariantSPtr val;
		val.opcUaBuildInType_ = OpcUaBuildInType_OpcUaNodeId;
		val.objectSPtr_ = valSPtr;
		val.objectSPtr_ = valSPtr;
		variantValue_ = val;
	}

	void  
	OpcUaVariantValue::variant(const OpcUaExpandedNodeId::SPtr valSPtr)
	{
		OpcUaVariantSPtr val;
		val.opcUaBuildInType_ = OpcUaBuildInType_OpcUaExpandedNodeId;
		val.objectSPtr_ = valSPtr;
		val.objectSPtr_ = valSPtr;
		variantValue_ = val;
	}

	void  
	OpcUaVariantValue::variant(const OpcUaQualifiedName::SPtr valSPtr)
	{
		OpcUaVariantSPtr val;
		val.opcUaBuildInType_ = OpcUaBuildInType_OpcUaQualifiedName;
		val.objectSPtr_ = valSPtr;
		val.objectSPtr_ = valSPtr;
		variantValue_ = val;
	}

	void  
	OpcUaVariantValue::variant(const OpcUaLocalizedText::SPtr valSPtr)
	{
		OpcUaVariantSPtr val;
		val.opcUaBuildInType_ = OpcUaBuildInType_OpcUaLocalizedText;
		val.objectSPtr_ = valSPtr;
		val.objectSPtr_ = valSPtr;
		variantValue_ = val;
	}	
	void  
	OpcUaVariantValue::variant(const OpcUaExtensionObject::SPtr valSPtr)
	{
		OpcUaVariantSPtr val;
		val.opcUaBuildInType_ = OpcUaBuildInType_OpcUaExtensionObject;
		val.objectSPtr_ = valSPtr;
		val.objectSPtr_ = valSPtr;
		variantValue_ = val;
	}

	void 
	OpcUaVariantValue::opcUaBinaryEncode(std::ostream& os, OpcUaBuildInType variantType) const
	{
		switch (variantType) 
		{
			case  OpcUaBuildInType::OpcUaBuildInType_OpcUaBoolean:
			{
				OpcUaStackCore::opcUaBinaryEncode(os, boost::get<OpcUaBoolean>(variantValue_));
				break;
			}
			case  OpcUaBuildInType::OpcUaBuildInType_OpcUaSByte:
			{
				OpcUaStackCore::opcUaBinaryEncode(os, boost::get<OpcUaSByte>(variantValue_));
				break;
			}
			case  OpcUaBuildInType::OpcUaBuildInType_OpcUaByte:
			{
				OpcUaStackCore::opcUaBinaryEncode(os, boost::get<OpcUaByte>(variantValue_));
				break;
			}
			case  OpcUaBuildInType::OpcUaBuildInType_OpcUaInt16:
			{
				OpcUaStackCore::opcUaBinaryEncode(os, boost::get<OpcUaInt16>(variantValue_));
				break;
			}
			case  OpcUaBuildInType::OpcUaBuildInType_OpcUaUInt16:
			{
				OpcUaStackCore::opcUaBinaryEncode(os, boost::get<OpcUaUInt16>(variantValue_));
				break;
			}
			case  OpcUaBuildInType::OpcUaBuildInType_OpcUaInt32:
			{
				OpcUaStackCore::opcUaBinaryEncode(os, boost::get<OpcUaInt32>(variantValue_));
				break;
			}
			case  OpcUaBuildInType::OpcUaBuildInType_OpcUaUInt32:
			{
				OpcUaStackCore::opcUaBinaryEncode(os, boost::get<OpcUaUInt32>(variantValue_));
				break;
			}
			case  OpcUaBuildInType::OpcUaBuildInType_OpcUaInt64:
			{
				OpcUaStackCore::opcUaBinaryEncode(os, boost::get<OpcUaInt64>(variantValue_));
				break;
			}
			case  OpcUaBuildInType::OpcUaBuildInType_OpcUaUInt64:
			{
				OpcUaStackCore::opcUaBinaryEncode(os, boost::get<OpcUaUInt64>(variantValue_));
				break;
			}
			case  OpcUaBuildInType::OpcUaBuildInType_OpcUaFloat:
			{
				OpcUaStackCore::opcUaBinaryEncode(os, boost::get<OpcUaFloat>(variantValue_));
				break;
			}
			case  OpcUaBuildInType::OpcUaBuildInType_OpcUaDouble:
			{
				OpcUaStackCore::opcUaBinaryEncode(os, boost::get<OpcUaDouble>(variantValue_));
				break;
			}
			case  OpcUaBuildInType::OpcUaBuildInType_OpcUaDateTime:
			{
				OpcUaStackCore::opcUaBinaryEncode(os, boost::get<OpcUaDateTime>(variantValue_));
				break;
			}
			case  OpcUaBuildInType::OpcUaBuildInType_OpcUaStatusCode:
			{
				OpcUaStackCore::opcUaBinaryEncode(os, boost::get<OpcUaStatusCode>(variantValue_));
				break;
			}
			case  OpcUaBuildInType::OpcUaBuildInType_OpcUaGuid:
			{
				OpcUaVariantSPtr opcUaVariantSPtr =  boost::get<OpcUaVariantSPtr>(variantValue_);
				OpcUaGuid::SPtr opcUaGuidSPtr = boost::static_pointer_cast<OpcUaGuid>(opcUaVariantSPtr.objectSPtr_);
				OpcUaStackCore::opcUaBinaryEncode(os,*opcUaGuidSPtr);
				break;
			}
			case  OpcUaBuildInType::OpcUaBuildInType_OpcUaByteString:
			{
				OpcUaVariantSPtr opcUaVariantSPtr =  boost::get<OpcUaVariantSPtr>(variantValue_);
				OpcUaByteString::SPtr opcUaByteStringSPtr = boost::static_pointer_cast<OpcUaByteString>(opcUaVariantSPtr.objectSPtr_);
				OpcUaStackCore::opcUaBinaryEncode(os,*opcUaByteStringSPtr);
				break;
			}
			case  OpcUaBuildInType::OpcUaBuildInType_OpcUaXmlElement:
			{
				OpcUaVariantSPtr opcUaVariantSPtr =  boost::get<OpcUaVariantSPtr>(variantValue_);
				OpcUaXmlElement::SPtr opcUaXmlElementSPtr = boost::static_pointer_cast<OpcUaXmlElement>(opcUaVariantSPtr.objectSPtr_);
				OpcUaStackCore::opcUaBinaryEncode(os,*opcUaXmlElementSPtr);
				break;
			}
			case  OpcUaBuildInType::OpcUaBuildInType_OpcUaNodeId:
			{
				OpcUaVariantSPtr opcUaVariantSPtr =  boost::get<OpcUaVariantSPtr>(variantValue_);
				OpcUaNodeId::SPtr opcUaNodeIdSPtr = boost::static_pointer_cast<OpcUaNodeId>(opcUaVariantSPtr.objectSPtr_);
				OpcUaStackCore::opcUaBinaryEncode(os,*opcUaNodeIdSPtr);
				break;
			}
			case  OpcUaBuildInType::OpcUaBuildInType_OpcUaExpandedNodeId:
			{
				OpcUaVariantSPtr opcUaVariantSPtr =  boost::get<OpcUaVariantSPtr>(variantValue_);
				OpcUaExpandedNodeId::SPtr opcUaExpandedNodeIdSPtr = boost::static_pointer_cast<OpcUaExpandedNodeId>(opcUaVariantSPtr.objectSPtr_);
				OpcUaStackCore::opcUaBinaryEncode(os,*opcUaExpandedNodeIdSPtr);
				break;
			}
			case  OpcUaBuildInType::OpcUaBuildInType_OpcUaQualifiedName:
			{
				OpcUaVariantSPtr opcUaVariantSPtr =  boost::get<OpcUaVariantSPtr>(variantValue_);
				OpcUaQualifiedName::SPtr opcUaQualifiedNameSPtr = boost::static_pointer_cast<OpcUaQualifiedName>(opcUaVariantSPtr.objectSPtr_);
				OpcUaStackCore::opcUaBinaryEncode(os,*opcUaQualifiedNameSPtr);
				break;
			}
			case  OpcUaBuildInType::OpcUaBuildInType_OpcUaLocalizedText:
			{
				OpcUaVariantSPtr opcUaVariantSPtr =  boost::get<OpcUaVariantSPtr>(variantValue_);
				OpcUaLocalizedText::SPtr opcUaLocalizedTextSPtr = boost::static_pointer_cast<OpcUaLocalizedText>(opcUaVariantSPtr.objectSPtr_);
				OpcUaStackCore::opcUaBinaryEncode(os,*opcUaLocalizedTextSPtr);
				break;
			}
			case  OpcUaBuildInType::OpcUaBuildInType_OpcUaExtensionObject:
			{
				OpcUaVariantSPtr opcUaVariantSPtr =  boost::get<OpcUaVariantSPtr>(variantValue_);
				OpcUaExtensionObject::SPtr opcUaExtensionObjectSPtr = boost::static_pointer_cast<OpcUaExtensionObject>(opcUaVariantSPtr.objectSPtr_);
				OpcUaStackCore::opcUaBinaryEncode(os,*opcUaExtensionObjectSPtr);
				break;
			}
		}
	}
		
	void 
	OpcUaVariantValue::opcUaBinaryDecode(std::istream& is, OpcUaBuildInType variantType)
	{
		OpcUaVariantValueType opcUaVariantValue;
		switch (variantType) 
		{
			case  OpcUaBuildInType::OpcUaBuildInType_OpcUaBoolean:
			{
				OpcUaBoolean opcUaBoolean;
				OpcUaStackCore::opcUaBinaryDecode(is, opcUaBoolean);
				opcUaVariantValue = opcUaBoolean;
				variantValue_ = opcUaVariantValue;
				break;
			}
			case  OpcUaBuildInType::OpcUaBuildInType_OpcUaSByte:
			{
				OpcUaSByte opcUaSByte;
				OpcUaStackCore::opcUaBinaryDecode(is, opcUaSByte);
				opcUaVariantValue = opcUaSByte;
				variantValue_ = opcUaVariantValue;
				break;
			}
			case  OpcUaBuildInType::OpcUaBuildInType_OpcUaByte:
			{
				OpcUaByte opcUaByte;
				OpcUaStackCore::opcUaBinaryDecode(is, opcUaByte);
				opcUaVariantValue = opcUaByte;
				variantValue_ = opcUaVariantValue;
				break;
			}
			case  OpcUaBuildInType::OpcUaBuildInType_OpcUaInt16:
			{
				OpcUaInt16 opcUaInt16;
				OpcUaStackCore::opcUaBinaryDecode(is, opcUaInt16);
				opcUaVariantValue = opcUaInt16;
				variantValue_ = opcUaVariantValue;
				break;
			}
			case  OpcUaBuildInType::OpcUaBuildInType_OpcUaUInt16:
			{
				OpcUaUInt16 opcUaUInt16;
				OpcUaStackCore::opcUaBinaryDecode(is, opcUaUInt16);
				opcUaVariantValue = opcUaUInt16;
				variantValue_ = opcUaVariantValue;
				break;
			}
			case  OpcUaBuildInType::OpcUaBuildInType_OpcUaInt32:
			{
				OpcUaInt32 opcUaInt32;
				OpcUaStackCore::opcUaBinaryDecode(is, opcUaInt32);
				opcUaVariantValue = opcUaInt32;
				variantValue_ = opcUaVariantValue;
				break;
			}
			case  OpcUaBuildInType::OpcUaBuildInType_OpcUaUInt32:
			{
				OpcUaUInt32 opcUaUInt32;
				OpcUaStackCore::opcUaBinaryDecode(is, opcUaUInt32);
				opcUaVariantValue = opcUaUInt32;
				variantValue_ = opcUaVariantValue;
				break;
			}
			case  OpcUaBuildInType::OpcUaBuildInType_OpcUaInt64:
			{
				OpcUaInt64 opcUaInt64;
				OpcUaStackCore::opcUaBinaryDecode(is, opcUaInt64);
				opcUaVariantValue = opcUaInt64;
				variantValue_ = opcUaVariantValue;
				break;
			}
			case  OpcUaBuildInType::OpcUaBuildInType_OpcUaUInt64:
			{
				OpcUaUInt64 opcUaUInt64;
				OpcUaStackCore::opcUaBinaryDecode(is, opcUaUInt64);
				opcUaVariantValue = opcUaUInt64;
				variantValue_ = opcUaVariantValue;
				break;
			}
			case  OpcUaBuildInType::OpcUaBuildInType_OpcUaFloat:
			{
				OpcUaFloat opcUaFloat;
				OpcUaStackCore::opcUaBinaryDecode(is, opcUaFloat);
				opcUaVariantValue = opcUaFloat;
				variantValue_ = opcUaVariantValue;
				break;
			}
			case  OpcUaBuildInType::OpcUaBuildInType_OpcUaDouble:
			{
				OpcUaDouble opcUaDouble;
				OpcUaStackCore::opcUaBinaryDecode(is, opcUaDouble);
				opcUaVariantValue = opcUaDouble;
				variantValue_ = opcUaVariantValue;
				break;
			}
			case  OpcUaBuildInType::OpcUaBuildInType_OpcUaDateTime:
			{
				OpcUaDateTime opcUaDateTime;
				OpcUaStackCore::opcUaBinaryDecode(is, opcUaDateTime);
				opcUaVariantValue = opcUaDateTime;
				variantValue_ = opcUaVariantValue;
				break;
			}
			case  OpcUaBuildInType::OpcUaBuildInType_OpcUaStatusCode:
			{
				OpcUaStatusCode opcUaStatusCode;
				OpcUaStackCore::opcUaBinaryDecode(is, opcUaStatusCode);
				opcUaVariantValue = opcUaStatusCode;
				variantValue_ = opcUaVariantValue;
				break;
			}
			case  OpcUaBuildInType::OpcUaBuildInType_OpcUaGuid:
			{
				OpcUaVariantSPtr val;

				OpcUaGuid::SPtr opcUaGuidSPtr = OpcUaGuid::construct();
				OpcUaStackCore::opcUaBinaryDecode(is, *opcUaGuidSPtr);
				val.objectSPtr_ = opcUaGuidSPtr;
				val.opcUaBuildInType_ = OpcUaBuildInType::OpcUaBuildInType_OpcUaGuid;
				variantValue_ = val;
				break;
			}
			case  OpcUaBuildInType::OpcUaBuildInType_OpcUaByteString:
			{
				OpcUaVariantSPtr val;

				OpcUaByteString::SPtr opcUaByteStringSPtr = OpcUaByteString::construct();
				OpcUaStackCore::opcUaBinaryDecode(is, *opcUaByteStringSPtr);
				val.objectSPtr_ = opcUaByteStringSPtr;
				val.opcUaBuildInType_ = OpcUaBuildInType::OpcUaBuildInType_OpcUaByteString;
				variantValue_ = val;
				break;
			}
			case  OpcUaBuildInType::OpcUaBuildInType_OpcUaXmlElement:
			{
				OpcUaVariantSPtr val;

				OpcUaXmlElement::SPtr opcUaXmlElementSPtr = OpcUaXmlElement::construct();
				OpcUaStackCore::opcUaBinaryDecode(is, *opcUaXmlElementSPtr);
				val.objectSPtr_ = opcUaXmlElementSPtr;
				val.opcUaBuildInType_ = OpcUaBuildInType::OpcUaBuildInType_OpcUaXmlElement;
				variantValue_ = val;
				break;
			}
			case  OpcUaBuildInType::OpcUaBuildInType_OpcUaNodeId:
			{
				OpcUaVariantSPtr val;

				OpcUaNodeId::SPtr opcUaNodeIdSPtr = OpcUaNodeId::construct();
				OpcUaStackCore::opcUaBinaryDecode(is, *opcUaNodeIdSPtr);
				val.objectSPtr_ = opcUaNodeIdSPtr;
				val.opcUaBuildInType_ = OpcUaBuildInType::OpcUaBuildInType_OpcUaNodeId;
				variantValue_ = val;
				break;
			}
			case  OpcUaBuildInType::OpcUaBuildInType_OpcUaExpandedNodeId:
			{
				OpcUaVariantSPtr val;

				OpcUaExpandedNodeId::SPtr opcUaExpandedNodeIdSPtr = OpcUaExpandedNodeId::construct();
				OpcUaStackCore::opcUaBinaryDecode(is, *opcUaExpandedNodeIdSPtr);
				val.objectSPtr_ = opcUaExpandedNodeIdSPtr;
				val.opcUaBuildInType_ = OpcUaBuildInType::OpcUaBuildInType_OpcUaExpandedNodeId;
				variantValue_ = val;
				break;
			}
			case  OpcUaBuildInType::OpcUaBuildInType_OpcUaQualifiedName:
			{
				OpcUaVariantSPtr val;

				OpcUaQualifiedName::SPtr opcUaQualifiedNameSPtr = OpcUaQualifiedName::construct();
				OpcUaStackCore::opcUaBinaryDecode(is, *opcUaQualifiedNameSPtr);
				val.objectSPtr_ = opcUaQualifiedNameSPtr;
				val.opcUaBuildInType_ = OpcUaBuildInType::OpcUaBuildInType_OpcUaQualifiedName;
				variantValue_ = val;
				break;
			}
			case  OpcUaBuildInType::OpcUaBuildInType_OpcUaLocalizedText:
			{
				OpcUaVariantSPtr val;

				OpcUaLocalizedText::SPtr opcUaLocalizedTextSPtr = OpcUaLocalizedText::construct();
				OpcUaStackCore::opcUaBinaryDecode(is, *opcUaLocalizedTextSPtr);
				val.objectSPtr_ = opcUaLocalizedTextSPtr;
				val.opcUaBuildInType_ = OpcUaBuildInType::OpcUaBuildInType_OpcUaLocalizedText;
				variantValue_ = val;
				break;
			}
			case  OpcUaBuildInType::OpcUaBuildInType_OpcUaExtensionObject:
			{
				OpcUaVariantSPtr val;

				OpcUaExtensionObject::SPtr opcUaExtensionObjectSPtr = OpcUaExtensionObject::construct();
				OpcUaStackCore::opcUaBinaryDecode(is, *opcUaExtensionObjectSPtr);
				val.objectSPtr_ = opcUaExtensionObjectSPtr;
				val.opcUaBuildInType_ = OpcUaBuildInType::OpcUaBuildInType_OpcUaExtensionObject;
				variantValue_ = val;
				break;
			}
		}
	}


	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// OpcUaVariant
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	OpcUaVariant::OpcUaVariant(void)
	:  ObjectPool<OpcUaVariant>()
	, variantValueVec_()
	, arrayLength_(-1)
	, arrayDimensionsVec_()
	{
		clear();
	}
		
	OpcUaVariant::~OpcUaVariant(void)
	{
	}

	void 
	OpcUaVariant::clear(void)
	{
		OpcUaVariantValue variantValue;
		variantValueVec_.clear();
		variantValueVec_.push_back(variantValue);

		arrayLength_ = -1;
		arrayDimensionsVec_.clear();
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
	OpcUaVariant::arrayDimension(const OpcUaArrayDimensionsVec& arrayDimensionsVec)
	{
		if (arrayLength_ < 2) {
			return;
		}
		if (arrayDimensionsVec.size() == 0) {
			return;
		}

		uint32_t count = 0;
		OpcUaArrayDimensionsVec::const_iterator it;
		for (it = arrayDimensionsVec.begin(); it != arrayDimensionsVec.end(); it++) {
			if (it == arrayDimensionsVec.begin()) {
				count = *it;
			}
			else {
				count *= *it;
			}
		}

		if (arrayLength_ != count) {
			return;
		}

		arrayDimensionsVec_.clear();
		arrayDimensionsVec_ = arrayDimensionsVec;
	}
	
	OpcUaArrayDimensionsVec 
	OpcUaVariant::arrayDimension(void)
	{
		return arrayDimensionsVec_;
	}

	void 
	OpcUaVariant::variant(const OpcUaVariantValue::Vec& variantValueVec)
	{
		variantValueVec_ = variantValueVec;
		arrayLength_ = variantValueVec_.size();
	}

	OpcUaVariantValue::Vec& 
	OpcUaVariant::variant(void)
	{
		return variantValueVec_;
	}

	OpcUaBuildInType 
	OpcUaVariant::variantType(void) const
	{
		if (variantValueVec_.size() == 0) {
			return OpcUaBuildInType::OpcUaBuildInType_Unknown;
		}
		return variantValueVec_[0].variantType();
	}

	void 
	OpcUaVariant::opcUaBinaryEncode(std::ostream& os) const
	{
		OpcUaBuildInType variantType = this->variantType();
		OpcUaByte encodingMask = (OpcUaByte)variantType;

		if (variantType == OpcUaBuildInType::OpcUaBuildInType_Unknown && variantValueVec_.size() != 0) {
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

		if (arrayLength_ == -1) {
		    variantValueVec_[0].opcUaBinaryEncode(os, variantType);
		}
		else if (arrayLength_ == 0) {
		} 
		else {
			OpcUaVariantValue::Vec::const_iterator it;
			for (it = variantValueVec_.begin(); it != variantValueVec_.end(); it++) {
				it->opcUaBinaryEncode(os, variantType);
			}
		}

		if (arrayDimensionsVec_.size() > 0) {
			OpcUaArrayDimensionsVec::const_iterator it;
			for (it = arrayDimensionsVec_.begin(); it != arrayDimensionsVec_.end(); it++) {
				OpcUaStackCore::opcUaBinaryEncode(os, *it);
			}
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

		OpcUaByte encodingMaskTmp = encodingMask & 0x3F;

		if (arrayLength_ == -1) {
		    variantValueVec_[0].opcUaBinaryDecode(is, (OpcUaBuildInType)encodingMaskTmp);
		}
		else if (arrayLength_ == 0) {
			variantValueVec_.clear();
		}
		else {
			variantValueVec_.clear();
			for (uint32_t idx=0; idx<(uint32_t)arrayLength_; idx++) {
				OpcUaVariantValue variantValue;
				variantValue.opcUaBinaryDecode(is, (OpcUaBuildInType)encodingMaskTmp);
				variantValueVec_.push_back(variantValue);
			}
		}

		arrayDimensionsVec_.clear();

		if (arrayLength_ < 2) {
			return;
		}

		if ((encodingMask & 128) == 128) {
			OpcUaUInt32 arrayDimensions;
			OpcUaStackCore::opcUaBinaryDecode(is, arrayDimensions);
			arrayDimensionsVec_.push_back(arrayDimensions);
			OpcUaUInt32 count = arrayDimensions;

			while (count < (uint32_t)arrayLength_) {
				OpcUaStackCore::opcUaBinaryDecode(is, arrayDimensions);
				arrayDimensionsVec_.push_back(arrayDimensions);
				count = count * arrayDimensions;
			}
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