#include "OpcUaStackClient/ServiceSet/SubscriptionManager.h"

namespace OpcUaStackClient
{

	SubscriptionManager::SubscriptionManager(void)
	: SubscriptionService()
	, subscriptionServiceIf_(NULL)
	{
	}

	SubscriptionManager::~SubscriptionManager(void)
	{
	}

	void
	SubscriptionManager::subscriptionServiceIf(SubscriptionServiceIf* subscriptionServiceIf)
	{
		subscriptionServiceIf_ = subscriptionServiceIf;
		SubscriptionService::subscriptionServiceIf(this);
	}

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// SubscriptionServiceIf
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
    void
    SubscriptionManager::subscriptionServiceCreateSubscriptionResponse(ServiceTransactionCreateSubscription::SPtr serviceTransactionCreateSubscription)
    {
    	subscriptionServiceIf_->subscriptionServiceCreateSubscriptionResponse(serviceTransactionCreateSubscription);
    }

    void
    SubscriptionManager::subscriptionServiceModifySubscriptionResponse(ServiceTransactionModifySubscription::SPtr serviceTransactionModifySubscription)
    {
    	subscriptionServiceIf_->subscriptionServiceModifySubscriptionResponse(serviceTransactionModifySubscription);
    }

    void
    SubscriptionManager::subscriptionServiceTransferSubscriptionsResponse(ServiceTransactionTransferSubscriptions::SPtr serviceTransactionTransferSubscriptions)
    {
    	subscriptionServiceIf_->subscriptionServiceTransferSubscriptionsResponse(serviceTransactionTransferSubscriptions);
    }

    void
    SubscriptionManager::subscriptionServiceDeleteSubscriptionsResponse(ServiceTransactionDeleteSubscriptions::SPtr serviceTransactionDeleteSubscriptions)
    {
    	subscriptionServiceIf_->subscriptionServiceDeleteSubscriptionsResponse(serviceTransactionDeleteSubscriptions);
    }

    void
    SubscriptionManager::subscriptionServiceSetPublishingModeResponse(ServiceTransactionSetPublishingMode::SPtr serviceTransactionSetPublishingMode)
    {
    	subscriptionServiceIf_->subscriptionServiceSetPublishingModeResponse(serviceTransactionSetPublishingMode);
    }

    void
    SubscriptionManager::subscriptionServicePublishResponse(ServiceTransactionPublish::SPtr serviceTransactionPublish)
    {
    	subscriptionServiceIf_->subscriptionServicePublishResponse(serviceTransactionPublish);
    }

    void
    SubscriptionManager::subscriptionServiceRepublishResponse(ServiceTransactionRepublish::SPtr serviceTransactionRepublish)
    {
    	subscriptionServiceIf_->subscriptionServiceRepublishResponse(serviceTransactionRepublish);
    }

}
