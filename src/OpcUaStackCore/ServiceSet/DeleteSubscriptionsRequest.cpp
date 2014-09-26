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
	, subscriptionIdArraySPtr_(OpcUaUInt32Array::construct())
	{
	}

	DeleteSubscriptionsRequest::~DeleteSubscriptionsRequest(void)
	{
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
		subscriptionIdArraySPtr_->opcUaBinaryEncode(os);
	}
	
	void 
	DeleteSubscriptionsRequest::opcUaBinaryDecode(std::istream& is)
	{
		subscriptionIdArraySPtr_->opcUaBinaryDecode(is);
	}
}