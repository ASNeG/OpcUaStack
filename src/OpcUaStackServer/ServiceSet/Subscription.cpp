#include "OpcUaStackServer/ServiceSet/Subscription.h"

namespace OpcUaStackServer
{

	uint32_t Subscription::uniqueSubscriptionId_ = 0;
	boost::mutex Subscription::mutex_;

	uint32_t 
	Subscription::uniqueSubscriptionId(void) 
	{ 
		uniqueSubscriptionId_++;
		return uniqueSubscriptionId_;
	}

	Subscription::Subscription(void)
	: subscriptionId_(uniqueSubscriptionId())
	{
	}

	Subscription::~Subscription(void)
	{
	}

	uint32_t 
	Subscription::subscriptionId(void)
	{
		return subscriptionId_;
	}

}