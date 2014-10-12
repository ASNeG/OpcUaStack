#include "OpcUaStackServer/ServiceSet/SubscriptionManager.h"

namespace OpcUaStackServer
{

	SubscriptionManager::SubscriptionManager(void)
	: ioService_(nullptr)
	{
	}

	SubscriptionManager::~SubscriptionManager(void)
	{
	}

	void 
	SubscriptionManager::ioService(IOService* ioService)
	{
		ioService_ = ioService;
	}

	OpcUaStatusCode 
	SubscriptionManager::receive(ServiceTransactionCreateSubscription::SPtr trx)
	{
		CreateSubscriptionRequest::SPtr createSubscriptionRequest = trx->request();
		CreateSubscriptionResponse::SPtr createSubscriptionResponse = trx->response();

		Subscription::SPtr subscription = Subscription::construct();
		subscriptionMap_.insert(std::make_pair(subscription->subscriptionId(), subscription));

		createSubscriptionResponse->subscriptionId(subscription->subscriptionId());
		createSubscriptionResponse->revisedPublishingInterval(createSubscriptionRequest->requestedPublishingInterval());
		createSubscriptionResponse->revisedLifetimeCount(createSubscriptionRequest->requestedLifetimeCount());
		createSubscriptionResponse->revisedMaxKeepAliveCount(createSubscriptionRequest->requestedMaxKeepAliveCount());

		return Success;
	}

	OpcUaStatusCode 
	SubscriptionManager::receive(ServiceTransactionDeleteSubscriptions::SPtr trx)
	{
		DeleteSubscriptionsRequest::SPtr deleteSubscriptionsRequest = trx->request();
		DeleteSubscriptionsResponse::SPtr deleteSubscriptionsResponse = trx->response();

		OpcUaUInt32 id;
		deleteSubscriptionsResponse->results()->resize(deleteSubscriptionsRequest->subscriptionIds()->size());
		for (uint32_t idx = 0; idx < deleteSubscriptionsRequest->subscriptionIds()->size(); idx++) {
			if (deleteSubscriptionsRequest->subscriptionIds()->get(idx, id)) {
				subscriptionMap_.erase((uint32_t)id);
			}
			deleteSubscriptionsResponse->results()->set(0, Success);
		}
	
		return Success;
	}

	OpcUaStatusCode 
	SubscriptionManager::receive(ServiceTransactionPublish::SPtr trx)
	{
		serviceTransactionPublishList_.push_back(trx);
		return Success;
	}

}