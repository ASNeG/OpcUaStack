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
	, browsePathArraySPtr_(BrowsePathArray::construct())
	{
	}

	TranslateBrowsePathsToNodeIdsRequest::~TranslateBrowsePathsToNodeIdsRequest(void)
	{
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
		browsePathArraySPtr_->opcUaBinaryEncode(os);
	}
	
	void 
	TranslateBrowsePathsToNodeIdsRequest::opcUaBinaryDecode(std::istream& is)
	{
		browsePathArraySPtr_->opcUaBinaryDecode(is);
	}

}