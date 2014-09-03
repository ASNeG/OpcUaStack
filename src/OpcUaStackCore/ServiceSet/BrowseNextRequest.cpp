#include "OpcUaStackCore/ServiceSet/BrowseNextRequest.h"

namespace OpcUaStackCore
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// OpcUa BrowseNextRequest
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------

	BrowseNextRequest::BrowseNextRequest(void)
	: ObjectPool<BrowseNextRequest>()
	, requestHeaderSPtr_(RequestHeader::construct())
	, releaseContinuationPoints_()
	, continuationPointArraySPtr_(OpcUaByteStringArray::construct())
	{
	}

	BrowseNextRequest::~BrowseNextRequest(void)
	{
	}

	void 
	BrowseNextRequest::requestHeader(const RequestHeader::SPtr requestHeader)
	{
		requestHeaderSPtr_ = requestHeader;
	}

	RequestHeader::SPtr 
	BrowseNextRequest::requestHeader(void) const
	{
		return requestHeaderSPtr_;
	}

	void 
	BrowseNextRequest::releaseContinuationPoints(const OpcUaBoolean& releaseContinuationPoints)
	{
		releaseContinuationPoints_ = releaseContinuationPoints;
	}
	
	OpcUaBoolean 
	BrowseNextRequest::releaseContinuationPoints(void)
	{
		return releaseContinuationPoints_;
	}
	
	void 
	BrowseNextRequest::continuationPoints(const OpcUaByteStringArray::SPtr continuationPoints)
	{
		continuationPointArraySPtr_ = continuationPoints;
	}
	
	OpcUaByteStringArray::SPtr 
	BrowseNextRequest::continuationPoints(void) const
	{
		return continuationPointArraySPtr_;
	}

	void 
	BrowseNextRequest::opcUaBinaryEncode(std::ostream& os) const
	{
		requestHeaderSPtr_->opcUaBinaryEncode(os);
		OpcUaNumber::opcUaBinaryEncode(os, releaseContinuationPoints_);
		continuationPointArraySPtr_->opcUaBinaryEncode(os);
	}
	
	void 
	BrowseNextRequest::opcUaBinaryDecode(std::istream& is)
	{
		requestHeaderSPtr_->opcUaBinaryDecode(is);
		OpcUaNumber::opcUaBinaryDecode(is, releaseContinuationPoints_);
		continuationPointArraySPtr_->opcUaBinaryDecode(is);
	}
}