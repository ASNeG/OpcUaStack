#include "OpcUaStackCore/ServiceSet/QueryFirstRequest.h"

namespace OpcUaStackCore
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// OpcUa QueryFirstRequest
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------

	QueryFirstRequest::QueryFirstRequest(void)
	: ObjectPool<QueryFirstRequest>()
	, requestHeaderSPtr_(RequestHeader::construct())
	, view_()
	, nodeTypeArraySPtr_(NodeTypeDescriptionArray::construct())
	, filter_()
	, maxDataSetsToReturn_()
	, maxReferencesToReturn_()
	{
	}


	QueryFirstRequest::~QueryFirstRequest(void)
	{
	}

	void 
	QueryFirstRequest::requestHeader(const RequestHeader::SPtr requestHeader)
	{
		requestHeaderSPtr_ = requestHeader;
	}

	RequestHeader::SPtr 
	QueryFirstRequest::requestHeader(void) const
	{
		return requestHeaderSPtr_;
	}

	void 
	QueryFirstRequest::view(const ViewDescription& view)
	{
		view_ = view;
	}
	
	ViewDescription& 
	QueryFirstRequest::view(void)
	{
		return view_;
	}
	
	void 
	QueryFirstRequest::nodeTypes(const NodeTypeDescriptionArray::SPtr nodeTypes)
	{
		nodeTypeArraySPtr_ = nodeTypes;
	}
	
	NodeTypeDescriptionArray::SPtr 
	QueryFirstRequest::nodeTypes(void) const
	{
		return nodeTypeArraySPtr_;
	}
	
	void 
	QueryFirstRequest::filter(const ContentFilter& filter)
	{
		filter_ = filter;
	}
	
	ContentFilter& 
	QueryFirstRequest::filter(void)
	{
		return filter_;
	}
	
	void 
	QueryFirstRequest::maxDataSetsToReturn(const OpcUaUInt32& maxDataSetsToReturn)
	{
		maxDataSetsToReturn_ = maxDataSetsToReturn;
	}
	
	OpcUaUInt32 
	QueryFirstRequest::maxDataSetsToReturn(void)
	{
		return maxDataSetsToReturn_;
	}
	
	void 
	QueryFirstRequest::maxReferencesToReturn(const OpcUaUInt32& maxReferencesToReturn)
	{
		maxReferencesToReturn_ = maxReferencesToReturn;
	}
	
	OpcUaUInt32 
	QueryFirstRequest::maxReferencesToReturn(void)
	{
		return maxReferencesToReturn_;
	}

	void 
	QueryFirstRequest::opcUaBinaryEncode(std::ostream& os) const
	{
		requestHeaderSPtr_->opcUaBinaryEncode(os);
		view_.opcUaBinaryEncode(os);
		nodeTypeArraySPtr_->opcUaBinaryEncode(os);
		filter_.opcUaBinaryEncode(os);
		OpcUaNumber::opcUaBinaryEncode(os, maxDataSetsToReturn_);
		OpcUaNumber::opcUaBinaryEncode(os, maxReferencesToReturn_);
	}
	
	void 
	QueryFirstRequest::opcUaBinaryDecode(std::istream& is)
	{
		requestHeaderSPtr_->opcUaBinaryDecode(is);
		view_.opcUaBinaryDecode(is);
		nodeTypeArraySPtr_->opcUaBinaryDecode(is);
		filter_.opcUaBinaryDecode(is);
		OpcUaNumber::opcUaBinaryDecode(is, maxDataSetsToReturn_);
		OpcUaNumber::opcUaBinaryDecode(is, maxReferencesToReturn_);
	}
}