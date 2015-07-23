#include "OpcUaStackCore/ServiceSet/CreateSubscriptionRequest.h"

namespace OpcUaStackCore
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// OpcUa CreateSubscriptionRequest
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------

	CreateSubscriptionRequest::CreateSubscriptionRequest(void)
	: ObjectPool<CreateSubscriptionRequest>()
	, requestedPublishingInterval_(100)
	, requestedLifetimeCount_(100)
	, requestedMaxKeepAliveCount_(33)
	, maxNotificationsPerPublish_(65536)
	, publishingEnabled_(true)
	, priority_(0)
	{
	}

	CreateSubscriptionRequest::~CreateSubscriptionRequest(void)
	{
	}

	void 
	CreateSubscriptionRequest::requestedPublishingInterval(const OpcUaDouble& requestedPublishingInterval)
	{
		requestedPublishingInterval_ = requestedPublishingInterval;
	}
	
	OpcUaDouble 
	CreateSubscriptionRequest::requestedPublishingInterval(void) const
	{
		return requestedPublishingInterval_;
	}

	void 
	CreateSubscriptionRequest::requestedLifetimeCount(const OpcUaUInt32& requestedLifetimeCount)
	{
		requestedLifetimeCount_ = requestedLifetimeCount;
	}

	OpcUaUInt32 
	CreateSubscriptionRequest::requestedLifetimeCount(void) const
	{
		return requestedLifetimeCount_;
	}

	void 
	CreateSubscriptionRequest::requestedMaxKeepAliveCount(const OpcUaUInt32& requestedMaxKeepAliveCount)
	{
		requestedMaxKeepAliveCount_ = requestedMaxKeepAliveCount;
	}

	OpcUaUInt32 
	CreateSubscriptionRequest::requestedMaxKeepAliveCount(void) const
	{
		return requestedMaxKeepAliveCount_;
	}

	void 
	CreateSubscriptionRequest::maxNotificationsPerPublish(const OpcUaUInt32& maxNotificationsPerPublish)
	{
		maxNotificationsPerPublish_ = maxNotificationsPerPublish;
	}
	
	OpcUaUInt32 
	CreateSubscriptionRequest::maxNotificationsPerPublish(void) const
	{
		return maxNotificationsPerPublish_;
	}
	
	void 
	CreateSubscriptionRequest::publishingEnabled(const OpcUaBoolean& publishingEnabled)
	{
		publishingEnabled_ = publishingEnabled;
	}

	OpcUaBoolean 
	CreateSubscriptionRequest::publishingEnabled(void) const
	{
		return publishingEnabled_;
	}
	
	void 
	CreateSubscriptionRequest::priority(const OpcUaByte& priority)
	{
		priority_ = priority;
	}

	OpcUaByte 
	CreateSubscriptionRequest::priority(void) const
	{
		return priority_;
	}
	
	void 
	CreateSubscriptionRequest::opcUaBinaryEncode(std::ostream& os) const
	{
		OpcUaNumber::opcUaBinaryEncode(os, requestedPublishingInterval_);
		OpcUaNumber::opcUaBinaryEncode(os, requestedLifetimeCount_);
		OpcUaNumber::opcUaBinaryEncode(os, requestedMaxKeepAliveCount_);
		OpcUaNumber::opcUaBinaryEncode(os, maxNotificationsPerPublish_);
		OpcUaNumber::opcUaBinaryEncode(os, publishingEnabled_);
		OpcUaNumber::opcUaBinaryEncode(os, priority_);
	}
	
	void 
	CreateSubscriptionRequest::opcUaBinaryDecode(std::istream& is)
	{
		OpcUaNumber::opcUaBinaryDecode(is, requestedPublishingInterval_);
		OpcUaNumber::opcUaBinaryDecode(is, requestedLifetimeCount_);
		OpcUaNumber::opcUaBinaryDecode(is, requestedMaxKeepAliveCount_);
		OpcUaNumber::opcUaBinaryDecode(is, maxNotificationsPerPublish_);
		OpcUaNumber::opcUaBinaryDecode(is, publishingEnabled_);
		OpcUaNumber::opcUaBinaryDecode(is, priority_);
	}
}
