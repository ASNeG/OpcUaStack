#include "OpcUaStackCore/SecureChannel/SequenceHeader.h"

namespace OpcUaStackCore
{

	SequenceHeader::SequenceHeader(void)
	: sequenceNumber_()
	, requestId_()
	{
	}
		
	SequenceHeader::~SequenceHeader(void)
	{
	}

	void 
	SequenceHeader::sequenceNumber(const OpcUaUInt32& sequenceNumber)
	{
		sequenceNumber_ = sequenceNumber;
	}
		
	OpcUaUInt32  
	SequenceHeader::sequenceNumber(void) const
	{
		return sequenceNumber_;
	}
		
	void  
	SequenceHeader::requestId(const OpcUaUInt32& requestId)
	{
		requestId_ = requestId;
	}
		
	OpcUaUInt32  
	SequenceHeader::requestId(void) const
	{
		return requestId_;
	}

	void 
	SequenceHeader::opcUaBinaryEncode(std::ostream& os) const
	{
		OpcUaStackCore::opcUaBinaryEncode(os, sequenceNumber_);
		OpcUaStackCore::opcUaBinaryEncode(os, requestId_);
	}

	void 
	SequenceHeader::opcUaBinaryDecode(std::istream& is)
	{
		OpcUaStackCore::opcUaBinaryDecode(is, sequenceNumber_);
		OpcUaStackCore::opcUaBinaryDecode(is, requestId_);
	}

}