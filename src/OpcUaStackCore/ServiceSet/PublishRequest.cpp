#include "OpcUaStackCore/ServiceSet/PublishRequest.h"

namespace OpcUaStackCore
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// OpcUa PublishRequest
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------

	PublishRequest::PublishRequest(void)
	: ObjectPool<PublishRequest>()
	, subscriptionAcknowledgementArraySPtr_(SubscriptionAcknowledgementArray::construct())
	{
	}

	PublishRequest::~PublishRequest(void)
	{
	}

	void 
	PublishRequest::subscriptionAcknowledgements(const SubscriptionAcknowledgementArray::SPtr subscriptionAcknowledgements)
	{
		subscriptionAcknowledgementArraySPtr_ = subscriptionAcknowledgements;
	}
	
	SubscriptionAcknowledgementArray::SPtr 
	PublishRequest::subscriptionAcknowledgements(void) const
	{
		return subscriptionAcknowledgementArraySPtr_;
	}

	void 
	PublishRequest::opcUaBinaryEncode(std::ostream& os) const
	{
		subscriptionAcknowledgementArraySPtr_->opcUaBinaryEncode(os);
	}
	
	void 
	PublishRequest::opcUaBinaryDecode(std::istream& is)
	{
		subscriptionAcknowledgementArraySPtr_->opcUaBinaryDecode(is);
	}
}