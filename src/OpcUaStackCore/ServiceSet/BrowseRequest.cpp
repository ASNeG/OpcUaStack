#include "OpcUaStackCore/ServiceSet/BrowseRequest.h"

namespace OpcUaStackCore
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// OpcUa BrowseRequest
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------

	BrowseRequest::BrowseRequest(void)
	: ObjectPool<BrowseRequest>()
	, view_()
	, requestMaxReferencesPerNode_()
	, nodesToBrowseArraySPtr_(BrowseDescriptionArray::construct())
	{
	}

	BrowseRequest::~BrowseRequest(void)
	{
	}

	void 
	BrowseRequest::view(const ViewDescription& view)
	{
		view_ = view;
	}
	
	ViewDescription& 
	BrowseRequest::view(void)
	{
		return view_;
	}
	
	void 
	BrowseRequest::requestMaxReferencesPerNode(const OpcUaUInt32& requestMaxReferencesPerNode)
	{
		requestMaxReferencesPerNode_ = requestMaxReferencesPerNode;
	}
	
	OpcUaUInt32 
	BrowseRequest::requestMaxReferencesPerNode(void)
	{
		return requestMaxReferencesPerNode_;
	}
	
	void 
	BrowseRequest::nodesToBrowse(const BrowseDescriptionArray::SPtr nodesToBrowse)
	{
		nodesToBrowseArraySPtr_ = nodesToBrowse;
	}
	
	BrowseDescriptionArray::SPtr 
	BrowseRequest::nodesToBrowse(void) const
	{
		return nodesToBrowseArraySPtr_;
	}

	void 
	BrowseRequest::opcUaBinaryEncode(std::ostream& os) const
	{
		view_.opcUaBinaryEncode(os);
		OpcUaNumber::opcUaBinaryEncode(os, requestMaxReferencesPerNode_);
		nodesToBrowseArraySPtr_->opcUaBinaryEncode(os);
	}
	
	void 
	BrowseRequest::opcUaBinaryDecode(std::istream& is)
	{
		view_.opcUaBinaryDecode(is);
		OpcUaNumber::opcUaBinaryDecode(is, requestMaxReferencesPerNode_);
		nodesToBrowseArraySPtr_->opcUaBinaryDecode(is);
	}
}