#include "OpcUaStackCore/ServiceSet/CreateSubscriptionResponse.h"

namespace OpcUaStackCore
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// OpcUa CreateSubscriptionResponse
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------

	CreateSubscriptionResponse::CreateSubscriptionResponse(void)
	: ObjectPool<CreateSubscriptionResponse>()
	, responseHeaderSPtr_(ResponseHeader::construct())
	, subscriptionId_()
	, revisedPublishingInterval_()
	, revisedLifetimeCount_()
	, revisedMaxKeepAliveCount_()
	{
	}

	CreateSubscriptionResponse::~CreateSubscriptionResponse(void)
	{
	}

	void 
	CreateSubscriptionResponse::responseHeader(const ResponseHeader::SPtr responseHeader)
	{
		responseHeaderSPtr_ = responseHeader;
	}

	ResponseHeader::SPtr 
	CreateSubscriptionResponse::responseHeader(void) const
	{
		return responseHeaderSPtr_;
	}

	void 
	CreateSubscriptionResponse::subscriptionId(const OpcUaUInt32& subscriptionId)
	{
		subscriptionId_ = subscriptionId;
	}

	OpcUaUInt32 
	CreateSubscriptionResponse::subscriptionId(void) const
	{
		return subscriptionId_;
	}
	
	void 
	CreateSubscriptionResponse::revisedPublishingInterval(const OpcUaDouble& revisedPublishingInterval)
	{
		revisedPublishingInterval_ = revisedPublishingInterval;
	}
	
	OpcUaDouble 
	CreateSubscriptionResponse::revisedPublishingInterval(void) const
	{
		return revisedPublishingInterval_;
	}

	void 
	CreateSubscriptionResponse::revisedLifetimeCount(const OpcUaUInt32& revisedLifetimeCount)
	{
		revisedLifetimeCount_ = revisedLifetimeCount;
	}
	
	OpcUaUInt32 
	CreateSubscriptionResponse::revisedLifetimeCount(void) const
	{
		return revisedLifetimeCount_;
	}
	
	void 
	CreateSubscriptionResponse::revisedMaxKeepAliveCount(const OpcUaUInt32& revisedMaxKeepAliveCount)
	{
		revisedMaxKeepAliveCount_ = revisedMaxKeepAliveCount;
	}
	
	OpcUaUInt32 
	CreateSubscriptionResponse::revisedMaxKeepAliveCount(void) const
	{
		return revisedMaxKeepAliveCount_;
	}

	void 
	CreateSubscriptionResponse::opcUaBinaryEncode(std::ostream& os) const
	{
		responseHeaderSPtr_->opcUaBinaryEncode(os);
		OpcUaNumber::opcUaBinaryEncode(os, subscriptionId_);
		OpcUaNumber::opcUaBinaryEncode(os, revisedPublishingInterval_);
		OpcUaNumber::opcUaBinaryEncode(os, revisedLifetimeCount_);
		OpcUaNumber::opcUaBinaryEncode(os, revisedMaxKeepAliveCount_);
	}
	
	void 
	CreateSubscriptionResponse::opcUaBinaryDecode(std::istream& is)
	{
		responseHeaderSPtr_->opcUaBinaryDecode(is);
		OpcUaNumber::opcUaBinaryDecode(is, subscriptionId_);
		OpcUaNumber::opcUaBinaryDecode(is, revisedPublishingInterval_);
		OpcUaNumber::opcUaBinaryDecode(is, revisedLifetimeCount_);
		OpcUaNumber::opcUaBinaryDecode(is, revisedMaxKeepAliveCount_);
	}
}