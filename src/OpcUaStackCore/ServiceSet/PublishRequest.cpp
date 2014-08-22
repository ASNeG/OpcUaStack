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
	, requestHeaderSPtr_(RequestHeader::construct())
	, subscriptionAcknowledgementArraySPtr_(SubscriptionAcknowledgementArray::construct())
	{
	}

	PublishRequest::~PublishRequest(void)
	{
	}

	void 
	PublishRequest::requestHeader(const RequestHeader::SPtr requestHeader)
	{
		requestHeaderSPtr_ = requestHeader;
	}

	RequestHeader::SPtr 
	PublishRequest::requestHeader(void) const
	{
		return requestHeaderSPtr_;
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
		requestHeaderSPtr_->opcUaBinaryEncode(os);
		subscriptionAcknowledgementArraySPtr_->opcUaBinaryEncode(os);
	}
	
	void 
	PublishRequest::opcUaBinaryDecode(std::istream& is)
	{
		requestHeaderSPtr_->opcUaBinaryDecode(is);
		subscriptionAcknowledgementArraySPtr_->opcUaBinaryDecode(is);
	}
}