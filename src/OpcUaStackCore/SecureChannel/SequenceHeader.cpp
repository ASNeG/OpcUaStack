#include "OpcUaStackCore/SecureChannel/SequenceHeader.h"

namespace OpcUaStackCore
{

	SequenceHeader::SequenceHeader(void)
	: sequenceNumber_(0)
	, requestId_(0)
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
	SequenceHeader::incSequenceNumber(void)
	{
		sequenceNumber_++;
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
	SequenceHeader::incRequestId(void)
	{
		requestId_++;
	}

	void 
	SequenceHeader::opcUaBinaryEncode(std::ostream& os) const
	{
		OpcUaNumber::opcUaBinaryEncode(os, sequenceNumber_);
		OpcUaNumber::opcUaBinaryEncode(os, requestId_);
	}

	void 
	SequenceHeader::opcUaBinaryDecode(std::istream& is)
	{
		OpcUaNumber::opcUaBinaryDecode(is, sequenceNumber_);
		OpcUaNumber::opcUaBinaryDecode(is, requestId_);
	}

}