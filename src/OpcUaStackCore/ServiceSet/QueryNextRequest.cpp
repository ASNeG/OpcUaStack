#include "OpcUaStackCore/ServiceSet/QueryNextRequest.h"

namespace OpcUaStackCore
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// OpcUa QueryNextRequest
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------

	QueryNextRequest::QueryNextRequest(void)
	: ObjectPool<QueryNextRequest>()
	, requestHeaderSPtr_(RequestHeader::construct())
	, releaseContinuationPoint_()
	, continuationPoint_()
	{
	}


	QueryNextRequest::~QueryNextRequest(void)
	{
	}

	void 
	QueryNextRequest::requestHeader(const RequestHeader::SPtr requestHeader)
	{
		requestHeaderSPtr_ = requestHeader;
	}

	RequestHeader::SPtr 
	QueryNextRequest::requestHeader(void) const
	{
		return requestHeaderSPtr_;
	}

	void 
	QueryNextRequest::releaseContinuationPoint(const OpcUaBoolean& releaseContinuationPoint)
	{
		releaseContinuationPoint_ = releaseContinuationPoint;
	}
	
	OpcUaBoolean 
	QueryNextRequest::releaseContinuationPoint(void)
	{
		return releaseContinuationPoint_;
	}
	
	void 
	QueryNextRequest::continuationPoint(const OpcUaByteString& continuationPoint)
	{
		continuationPoint_ = continuationPoint;
	}
	
	OpcUaByteString& 
	QueryNextRequest::continuationPoint(void)
	{
		return continuationPoint_;
	}

	void 
	QueryNextRequest::opcUaBinaryEncode(std::ostream& os) const
	{
		requestHeaderSPtr_->opcUaBinaryEncode(os);
		OpcUaNumber::opcUaBinaryEncode(os, releaseContinuationPoint_);
		continuationPoint_.opcUaBinaryEncode(os);
	}
	
	void 
	QueryNextRequest::opcUaBinaryDecode(std::istream& is)
	{
		requestHeaderSPtr_->opcUaBinaryDecode(is);
		OpcUaNumber::opcUaBinaryDecode(is, releaseContinuationPoint_);
		continuationPoint_.opcUaBinaryDecode(is);
	}
}