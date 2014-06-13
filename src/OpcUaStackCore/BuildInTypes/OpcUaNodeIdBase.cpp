#include "OpcUaStackCore/BuildInTypes/OpcUaNodeIdBase.h"

namespace OpcUaStackCore
{

	class OpcUaTypeVisitor : public boost::static_visitor<>
	{
	  public:
		void operator()(OpcUaNodeIdNullType) { opcUaBuildInType_ = OpcUaBuildInType::OpcUaBuildInType_Unknown; }
		void operator()(OpcUaUInt32) { opcUaBuildInType_ = OpcUaBuildInType::OpcUaBuildInType_OpcUaUInt32; }
		void operator()(OpcUaString::SPtr) { opcUaBuildInType_ = OpcUaBuildInType::OpcUaBuildInType_OpcUaString; }
		void operator()(OpcUaGuid::SPtr) { opcUaBuildInType_ = OpcUaBuildInType::OpcUaBuildInType_OpcUaGuid; }
		void operator()(OpcUaByteString::SPtr) { opcUaBuildInType_ = OpcUaBuildInType::OpcUaBuildInType_OpcUaByteString; }

		OpcUaBuildInType opcUaBuildInType_;
	};


	OpcUaNodeIdBase::OpcUaNodeIdBase(void)
	: namespaceIndex_(0)
	, nodeIdValue_()
	{
	}

	OpcUaNodeIdBase::~OpcUaNodeIdBase(void)
	{
	}

	void 
	OpcUaNodeIdBase::namespaceIndex(OpcUaUInt16 namespaceIndex)
	{
		namespaceIndex_ = namespaceIndex;
	}

	OpcUaInt16 
	OpcUaNodeIdBase::namespaceIndex(void) const
	{
		return namespaceIndex_;
	}

	OpcUaBuildInType 
	OpcUaNodeIdBase::nodeIdType(void) const
	{
		OpcUaTypeVisitor opcUaTypeVisitor;
		boost::apply_visitor(opcUaTypeVisitor, nodeIdValue_);
		return opcUaTypeVisitor.opcUaBuildInType_;
	}


	OpcUaByte 
	OpcUaNodeIdBase::encodingFlag(void) const
	{
		return 0x00;
	}
		
	void 
	OpcUaNodeIdBase::encodingFlag(OpcUaByte expandedEncodingFlag)
	{
	}

	void 
	OpcUaNodeIdBase::opcUaBinaryEncode(std::ostream& os) const
	{
		OpcUaBuildInType type =  nodeIdType();
		OpcUaByte ef = encodingFlag();

		if (type == OpcUaBuildInType::OpcUaBuildInType_Unknown) {
			return;
		}

		if (namespaceIndex_ == 0 && type == OpcUaBuildInType::OpcUaBuildInType_OpcUaUInt32) {
			OpcUaUInt32 identifier = boost::get<OpcUaUInt32>(nodeIdValue_);
			if (identifier <= 0xFF) {
				OpcUaByte encodingMask = 0x00+ef;
				OpcUaStackCore::opcUaBinaryEncode(os, encodingMask);
				OpcUaStackCore::opcUaBinaryEncode(os, (OpcUaStackCore::OpcUaByte)identifier);
				return;
			}
		}

		if (namespaceIndex_ <= 0xFF && type == OpcUaBuildInType::OpcUaBuildInType_OpcUaUInt32) {
			OpcUaUInt32 identifier = boost::get<OpcUaUInt32>(nodeIdValue_);
			if (identifier <= 0xFFFF) {
				OpcUaByte encodingMask = 0x01+ef;
				OpcUaStackCore::opcUaBinaryEncode(os, encodingMask);
				OpcUaStackCore::opcUaBinaryEncode(os, (OpcUaStackCore::OpcUaByte)namespaceIndex_);
				OpcUaStackCore::opcUaBinaryEncode(os, (OpcUaStackCore::OpcUaUInt16)identifier);
				return;
			}
		}

		switch(type)
		{
			case OpcUaBuildInType::OpcUaBuildInType_OpcUaUInt32:
			{
				OpcUaByte encodingMask = 0x02+ef;
				OpcUaStackCore::opcUaBinaryEncode(os, encodingMask);
				OpcUaStackCore::opcUaBinaryEncode(os, namespaceIndex_);
				OpcUaStackCore::opcUaBinaryEncode(os, boost::get<OpcUaUInt32>(nodeIdValue_));
				break;
			}
			case OpcUaBuildInType::OpcUaBuildInType_OpcUaString:
			{
				OpcUaByte encodingMask = 0x03+ef;
				OpcUaStackCore::opcUaBinaryEncode(os, encodingMask);
				OpcUaStackCore::opcUaBinaryEncode(os, namespaceIndex_);
				OpcUaStackCore::opcUaBinaryEncode(os, *boost::get<OpcUaString::SPtr>(nodeIdValue_));
				break;
			}
			case OpcUaBuildInType::OpcUaBuildInType_OpcUaGuid:
			{
				OpcUaByte encodingMask = 0x04+ef;
				OpcUaStackCore::opcUaBinaryEncode(os, encodingMask);
				OpcUaStackCore::opcUaBinaryEncode(os, namespaceIndex_);
				OpcUaStackCore::opcUaBinaryEncode(os, *boost::get<OpcUaGuid::SPtr>(nodeIdValue_));
				break;
			}
			case OpcUaBuildInType::OpcUaBuildInType_OpcUaByteString:
			{
				OpcUaByte encodingMask = 0x05+ef;
				OpcUaStackCore::opcUaBinaryEncode(os, encodingMask);
				OpcUaStackCore::opcUaBinaryEncode(os, namespaceIndex_);
				OpcUaStackCore::opcUaBinaryEncode(os, *boost::get<OpcUaByteString::SPtr>(nodeIdValue_));
				break;
			}
		}
	}

	void 
	OpcUaNodeIdBase::opcUaBinaryDecode(std::istream& is)
	{
		OpcUaByte encodingByte;
		OpcUaStackCore::opcUaBinaryDecode(is, encodingByte);

		OpcUaByte ef = encodingByte & 0xF0;
		encodingFlag(ef);
		encodingByte &= 0x0F;

		switch (encodingByte)
		{
			case 0x00:
			{
				OpcUaByte identifier;
				namespaceIndex_ = 0;
				OpcUaStackCore::opcUaBinaryDecode(is, identifier);
				nodeIdValue_ = (OpcUaInt32)identifier;
				break;
			}
			case 0x01:
			{
				OpcUaByte namespaceIndex;
				OpcUaUInt16 identifier;
				OpcUaStackCore::opcUaBinaryDecode(is, namespaceIndex);
				OpcUaStackCore::opcUaBinaryDecode(is, identifier);
				namespaceIndex_ = namespaceIndex;
				nodeIdValue_ = (OpcUaInt32)identifier;
				break;
			}
			case 0x02:
			{
				OpcUaInt32 value;
				OpcUaStackCore::opcUaBinaryDecode(is, namespaceIndex_);
				OpcUaStackCore::opcUaBinaryDecode(is, value);
				nodeIdValue_ = value;
				break;
			}
			case 0x03:
			{
				OpcUaString::SPtr value = OpcUaString::construct();
				OpcUaStackCore::opcUaBinaryDecode(is, namespaceIndex_);
				OpcUaStackCore::opcUaBinaryDecode(is, *value);
				nodeIdValue_ = value;
				break;
			}
			case 0x04:
			{
				OpcUaGuid::SPtr value = OpcUaGuid::construct();
				OpcUaStackCore::opcUaBinaryDecode(is, namespaceIndex_);
				OpcUaStackCore::opcUaBinaryDecode(is, *value);
				nodeIdValue_ = value;
				break;
			}
			case 0x05:
			{
				OpcUaByteString::SPtr value = OpcUaByteString::construct();
				OpcUaStackCore::opcUaBinaryDecode(is, namespaceIndex_);
				OpcUaStackCore::opcUaBinaryDecode(is, *value);
				nodeIdValue_ = value;
				break;
			}
		}
	}

}