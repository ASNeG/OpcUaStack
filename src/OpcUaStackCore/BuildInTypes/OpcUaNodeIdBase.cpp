#include "OpcUaStackCore/BuildInTypes/OpcUaNodeIdBase.h"

namespace OpcUaStackCore
{

	class OpcUaTypeVisitor : public boost::static_visitor<>
	{
	  public:
		void operator()(OpcUaNodeIdNullType) { opcUaBuildInType_ = OpcUaBuildInType_Unknown; }
		void operator()(OpcUaUInt32) { opcUaBuildInType_ = OpcUaBuildInType_OpcUaUInt32; }
		void operator()(OpcUaString::SPtr) { opcUaBuildInType_ = OpcUaBuildInType_OpcUaString; }
		void operator()(OpcUaGuid::SPtr) { opcUaBuildInType_ = OpcUaBuildInType_OpcUaGuid; }
		void operator()(OpcUaByteString::SPtr) { opcUaBuildInType_ = OpcUaBuildInType_OpcUaByteString; }

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

		if (type == OpcUaBuildInType_Unknown) {
			return;
		}

		if (namespaceIndex_ == 0 && type == OpcUaBuildInType_OpcUaUInt32) {
			OpcUaUInt32 identifier = boost::get<OpcUaUInt32>(nodeIdValue_);
			if (identifier <= 0xFF) {
				OpcUaByte encodingMask = 0x00+ef;
				OpcUaNumber::opcUaBinaryEncode(os, encodingMask);
				OpcUaNumber::opcUaBinaryEncode(os, (OpcUaStackCore::OpcUaByte)identifier);
				return;
			}
		}

		if (namespaceIndex_ <= 0xFF && type == OpcUaBuildInType_OpcUaUInt32) {
			OpcUaUInt32 identifier = boost::get<OpcUaUInt32>(nodeIdValue_);
			if (identifier <= 0xFFFF) {
				OpcUaByte encodingMask = 0x01+ef;
				OpcUaNumber::opcUaBinaryEncode(os, encodingMask);
				OpcUaNumber::opcUaBinaryEncode(os, (OpcUaStackCore::OpcUaByte)namespaceIndex_);
				OpcUaNumber::opcUaBinaryEncode(os, (OpcUaStackCore::OpcUaUInt16)identifier);
				return;
			}
		}

		switch(type)
		{
			case OpcUaBuildInType_OpcUaUInt32:
			{
				OpcUaByte encodingMask = 0x02+ef;
				OpcUaNumber::opcUaBinaryEncode(os, encodingMask);
				OpcUaNumber::opcUaBinaryEncode(os, namespaceIndex_);
				OpcUaNumber::opcUaBinaryEncode(os, boost::get<OpcUaUInt32>(nodeIdValue_));
				break;
			}
			case OpcUaBuildInType_OpcUaString:
			{
				OpcUaByte encodingMask = 0x03+ef;
				OpcUaNumber::opcUaBinaryEncode(os, encodingMask);
				OpcUaNumber::opcUaBinaryEncode(os, namespaceIndex_);
				boost::get<OpcUaString::SPtr>(nodeIdValue_)->opcUaBinaryEncode(os);
				break;
			}
			case OpcUaBuildInType_OpcUaGuid:
			{
				OpcUaByte encodingMask = 0x04+ef;
				OpcUaNumber::opcUaBinaryEncode(os, encodingMask);
				OpcUaNumber::opcUaBinaryEncode(os, namespaceIndex_);
				boost::get<OpcUaGuid::SPtr>(nodeIdValue_)->opcUaBinaryEncode(os);
				break;
			}
			case OpcUaBuildInType_OpcUaByteString:
			{
				OpcUaByte encodingMask = 0x05+ef;
				OpcUaNumber::opcUaBinaryEncode(os, encodingMask);
				OpcUaNumber::opcUaBinaryEncode(os, namespaceIndex_);
				boost::get<OpcUaByteString::SPtr>(nodeIdValue_)->opcUaBinaryEncode(os);
				break;
			}
		}
	}

	void 
	OpcUaNodeIdBase::opcUaBinaryDecode(std::istream& is)
	{
		OpcUaByte encodingByte;
		OpcUaNumber::opcUaBinaryDecode(is, encodingByte);

		OpcUaByte ef = encodingByte & 0xF0;
		encodingFlag(ef);
		encodingByte &= 0x0F;

		switch (encodingByte)
		{
			case 0x00:
			{
				OpcUaByte identifier;
				namespaceIndex_ = 0;
				OpcUaNumber::opcUaBinaryDecode(is, identifier);
				nodeIdValue_ = (OpcUaInt32)identifier;
				break;
			}
			case 0x01:
			{
				OpcUaByte namespaceIndex;
				OpcUaUInt16 identifier;
				OpcUaNumber::opcUaBinaryDecode(is, namespaceIndex);
				OpcUaNumber::opcUaBinaryDecode(is, identifier);
				namespaceIndex_ = namespaceIndex;
				nodeIdValue_ = (OpcUaInt32)identifier;
				break;
			}
			case 0x02:
			{
				OpcUaInt32 value;
				OpcUaNumber::opcUaBinaryDecode(is, namespaceIndex_);
				OpcUaNumber::opcUaBinaryDecode(is, value);
				nodeIdValue_ = value;
				break;
			}
			case 0x03:
			{
				OpcUaString::SPtr value = OpcUaString::construct();
				OpcUaNumber::opcUaBinaryDecode(is, namespaceIndex_);
				value->opcUaBinaryDecode(is);
				nodeIdValue_ = value;
				break;
			}
			case 0x04:
			{
				OpcUaGuid::SPtr value = OpcUaGuid::construct();
				OpcUaNumber::opcUaBinaryDecode(is, namespaceIndex_);
				value->opcUaBinaryDecode(is);
				nodeIdValue_ = value;
				break;
			}
			case 0x05:
			{
				OpcUaByteString::SPtr value = OpcUaByteString::construct();
				OpcUaNumber::opcUaBinaryDecode(is, namespaceIndex_);
				value->opcUaBinaryDecode(is);
				nodeIdValue_ = value;
				break;
			}
		}
	}

}
