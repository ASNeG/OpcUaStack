#include "OpcUaStackCore/ServiceSet/TranslateBrowsePathsToNodeIdsRequest.h"

namespace OpcUaStackCore
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// OpcUa TranslateBrowsePathsToNodeIdsRequest
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------

	TranslateBrowsePathsToNodeIdsRequest::TranslateBrowsePathsToNodeIdsRequest(void)
	: ObjectPool<TranslateBrowsePathsToNodeIdsRequest>()
	, requestHeaderSPtr_(RequestHeader::construct())
	, browsePathArraySPtr_(BrowsePathArray::construct())
	{
	}

	TranslateBrowsePathsToNodeIdsRequest::~TranslateBrowsePathsToNodeIdsRequest(void)
	{
	}

	void 
	TranslateBrowsePathsToNodeIdsRequest::requestHeader(const RequestHeader::SPtr requestHeader)
	{
		requestHeaderSPtr_ = requestHeader;
	}

	RequestHeader::SPtr 
	TranslateBrowsePathsToNodeIdsRequest::requestHeader(void) const
	{
		return requestHeaderSPtr_;
	}

	void 
	TranslateBrowsePathsToNodeIdsRequest::browsePaths(const BrowsePathArray::SPtr browsePaths) 
	{
		browsePathArraySPtr_ = browsePaths;
	}
	
	BrowsePathArray::SPtr 
	TranslateBrowsePathsToNodeIdsRequest::browsePaths(void) const
	{
		return browsePathArraySPtr_;
	}

	void 
	TranslateBrowsePathsToNodeIdsRequest::opcUaBinaryEncode(std::ostream& os) const
	{
		requestHeaderSPtr_->opcUaBinaryEncode(os);
		browsePathArraySPtr_->opcUaBinaryEncode(os);
	}
	
	void 
	TranslateBrowsePathsToNodeIdsRequest::opcUaBinaryDecode(std::istream& is)
	{
		requestHeaderSPtr_->opcUaBinaryDecode(is);
		browsePathArraySPtr_->opcUaBinaryDecode(is);
	}

}