#include "OpcUaStackClient/ServiceSet/SubscriptionManager.h"

namespace OpcUaStackClient
{

	SubscriptionManager::SubscriptionManager(IOService& ioService)
	: componentSession_(NULL)
	{
	}

	SubscriptionManager::~SubscriptionManager(void)
	{
	}

	void
	SubscriptionManager::componentSession(Component* componentSession)
	{
		componentSession_ = componentSession;
	}

	Subscription::SPtr
	SubscriptionManager::getNewSubscription(
		void
	)
	{
		Subscription::SPtr subscription;
		return subscription;
	}

	void
	SubscriptionManager::deleteSubscription(const Subscription::SPtr& subscription)
	{
	}

}
