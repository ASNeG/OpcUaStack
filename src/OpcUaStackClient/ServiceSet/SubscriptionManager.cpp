#include "OpcUaStackClient/ServiceSet/SubscriptionManager.h"

namespace OpcUaStackClient
{

	SubscriptionManager::SubscriptionManager(IOService& ioService)
	{
	}

	SubscriptionManager::~SubscriptionManager(void)
	{
	}

	void
	SubscriptionManager::startup(void)
	{
	}

	void
	SubscriptionManager::shutdown(void)
	{
	}

	void
	SubscriptionManager::componentSession(Component* componentSession)
	{
		componentSession_ = componentSession;
	}

}
