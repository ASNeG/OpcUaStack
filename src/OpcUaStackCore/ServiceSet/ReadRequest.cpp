#include "OpcUaStackCore/ServiceSet/ReadRequest.h"

namespace OpcUaStackCore
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// OpcUa ReadRequest
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------

	ReadRequest::ReadRequest(void)
	: ObjectPool<ReadRequest>()
	, requestHeaderSPtr_(RequestHeader::construct())
	, maxAge_()
	, timestampsToReturn_()
	, readValueIdArraySPtr_(ReadValueIdArray::construct())
	{
	}

	ReadRequest::~ReadRequest(void)
	{
	}

	void 
	ReadRequest::requestHeader(const RequestHeader::SPtr requestHeaderSPtr)
	{
		requestHeaderSPtr_ = requestHeaderSPtr;
	}

	RequestHeader::SPtr 
	ReadRequest::requestHeader(void) const
	{
		return requestHeaderSPtr_;
	}

	void 
	ReadRequest::maxAge(const OpcUaDouble& maxAge)
	{
		maxAge_ = maxAge;
	}
	
	OpcUaDouble 
	ReadRequest::maxAge(void) const
	{
		return maxAge_;
	}
	
	void 
	ReadRequest::timestampsToReturn(const OpcUaInt32& timestampsToReturn)
	{
		timestampsToReturn_ = timestampsToReturn;
	}
	
	OpcUaInt32 
	ReadRequest::timestampsToReturn(void) const
	{
		return timestampsToReturn_;
	}
	
	void 
	ReadRequest::readValueIdArray(const ReadValueIdArray::SPtr readValueIdArraySPtr)
	{
		readValueIdArraySPtr_ = readValueIdArraySPtr;
	}
	
	ReadValueIdArray::SPtr 
	ReadRequest::readValueIdArray(void) const
	{
		return readValueIdArraySPtr_;
	}

	void 
	ReadRequest::opcUaBinaryEncode(std::ostream& os) const
	{
		requestHeaderSPtr_->opcUaBinaryEncode(os);
		OpcUaNumber::opcUaBinaryEncode(os, maxAge_);
		OpcUaNumber::opcUaBinaryEncode(os, timestampsToReturn_);
		readValueIdArraySPtr_->opcUaBinaryEncode(os);
	}
	
	void 
	ReadRequest::opcUaBinaryDecode(std::istream& is)
	{
		requestHeaderSPtr_->opcUaBinaryDecode(is);
		OpcUaNumber::opcUaBinaryDecode(is, maxAge_);
		OpcUaNumber::opcUaBinaryDecode(is, timestampsToReturn_);
		readValueIdArraySPtr_->opcUaBinaryDecode(is);
	}

}