#include "OpcUaStackCore/ServiceSet/DeleteSubscriptionRequest.h"

namespace OpcUaStackCore
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// OpcUa DeleteSubscriptionRequest
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------

	DeleteSubscriptionRequest::DeleteSubscriptionRequest(void)
	: ObjectPool<DeleteSubscriptionRequest>()
	, requestHeaderSPtr_(RequestHeader::construct())
	, subscriptionIdArraySPtr_(OpcUaUInt32Array::construct())
	{
	}

	DeleteSubscriptionRequest::~DeleteSubscriptionRequest(void)
	{
	}
	
	void 
	DeleteSubscriptionRequest::requestHeader(const RequestHeader::SPtr requestHeader)
	{
		requestHeaderSPtr_ = requestHeader;
	}
	
	RequestHeader::SPtr 
	DeleteSubscriptionRequest::requestHeader(void) const
	{
		return requestHeaderSPtr_;
	}
		
	void 
	DeleteSubscriptionRequest::subscriptionIds(const OpcUaUInt32Array::SPtr subscriptionIds)
	{
		subscriptionIdArraySPtr_ = subscriptionIds;
	}
	
	OpcUaUInt32Array::SPtr 
	DeleteSubscriptionRequest::subscriptionIds(void) const
	{
		return subscriptionIdArraySPtr_;
	}

	void 
	DeleteSubscriptionRequest::opcUaBinaryEncode(std::ostream& os) const
	{
		requestHeaderSPtr_->opcUaBinaryEncode(os);
		subscriptionIdArraySPtr_->opcUaBinaryEncode(os);
	}
	
	void 
	DeleteSubscriptionRequest::opcUaBinaryDecode(std::istream& is)
	{
		requestHeaderSPtr_->opcUaBinaryDecode(is);
		subscriptionIdArraySPtr_->opcUaBinaryDecode(is);
	}
}