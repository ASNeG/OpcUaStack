#include "OpcUaStackCore/ServiceSet/DeleteSubscriptionsRequest.h"

namespace OpcUaStackCore
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// OpcUa DeleteSubscriptionsRequest
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------

	DeleteSubscriptionsRequest::DeleteSubscriptionsRequest(void)
	: ObjectPool<DeleteSubscriptionsRequest>()
	, requestHeaderSPtr_(RequestHeader::construct())
	, subscriptionIdArraySPtr_(OpcUaUInt32Array::construct())
	{
	}

	DeleteSubscriptionsRequest::~DeleteSubscriptionsRequest(void)
	{
	}
	
	void 
	DeleteSubscriptionsRequest::requestHeader(const RequestHeader::SPtr requestHeader)
	{
		requestHeaderSPtr_ = requestHeader;
	}
	
	RequestHeader::SPtr 
	DeleteSubscriptionsRequest::requestHeader(void) const
	{
		return requestHeaderSPtr_;
	}
		
	void 
	DeleteSubscriptionsRequest::subscriptionIds(const OpcUaUInt32Array::SPtr subscriptionIds)
	{
		subscriptionIdArraySPtr_ = subscriptionIds;
	}
	
	OpcUaUInt32Array::SPtr 
	DeleteSubscriptionsRequest::subscriptionIds(void) const
	{
		return subscriptionIdArraySPtr_;
	}

	void 
	DeleteSubscriptionsRequest::opcUaBinaryEncode(std::ostream& os) const
	{
		requestHeaderSPtr_->opcUaBinaryEncode(os);
		subscriptionIdArraySPtr_->opcUaBinaryEncode(os);
	}
	
	void 
	DeleteSubscriptionsRequest::opcUaBinaryDecode(std::istream& is)
	{
		requestHeaderSPtr_->opcUaBinaryDecode(is);
		subscriptionIdArraySPtr_->opcUaBinaryDecode(is);
	}
}