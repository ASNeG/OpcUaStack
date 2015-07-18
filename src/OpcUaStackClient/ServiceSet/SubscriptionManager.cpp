#include "OpcUaStackCore/Base/Log.h"
#include "OpcUaStackClient/ServiceSet/SubscriptionManager.h"

using namespace OpcUaStackCore;

namespace OpcUaStackClient
{

	SubscriptionManager::SubscriptionManager(void)
	: SubscriptionService()
	, subscriptionServiceIf_(NULL)
	, subscriptionSet_()
	, publishCount_(5)
	, actPublishCount_(0)
	{
		subscriptionServicePublishIf(this);
	}

	SubscriptionManager::~SubscriptionManager(void)
	{
	}

	void
	SubscriptionManager::publishCount(uint32_t publishCount)
	{
		publishCount_ = publishCount;
	}

	uint32_t
	SubscriptionManager::publishCount(void)
	{
		return publishCount_;
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
    	if (serviceTransactionCreateSubscription->statusCode() == Success) {
    		CreateSubscriptionResponse::SPtr res = serviceTransactionCreateSubscription->response();
    		createSubscription(res->subscriptionId());
    	}
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
    	if (serviceTransactionDeleteSubscriptions->statusCode() == Success) {
    		DeleteSubscriptionsRequest::SPtr req = serviceTransactionDeleteSubscriptions->request();
    		DeleteSubscriptionsResponse::SPtr res = serviceTransactionDeleteSubscriptions->response();

    		if (req->subscriptionIds()->size() != res->results()->size()) {
    			Log(Error, "Invalid number of entries in delete subscription response")
    				.parameter("ExpectedSize", req->subscriptionIds()->size())
    				.parameter("ReceivedSize", res->results()->size());
    		}
    		else {
    			for (uint32_t pos=0; pos<res->results()->size(); pos++) {
    				OpcUaStatusCode statusCode;
    				res->results()->get(pos, statusCode);

    				uint32_t subscriptionId;
    				req->subscriptionIds()->get(pos, subscriptionId);

    				if (statusCode == Success) {
    					deleteSubscription(subscriptionId);
    				}
    			}
    		}
        }
    	subscriptionServiceIf_->subscriptionServiceDeleteSubscriptionsResponse(serviceTransactionDeleteSubscriptions);
    }

    void
    SubscriptionManager::subscriptionServiceSetPublishingModeResponse(ServiceTransactionSetPublishingMode::SPtr serviceTransactionSetPublishingMode)
    {
    }

    void
    SubscriptionManager::subscriptionServicePublishResponse(ServiceTransactionPublish::SPtr serviceTransactionPublish)
    {
    }

    void
    SubscriptionManager::subscriptionServiceRepublishResponse(ServiceTransactionRepublish::SPtr serviceTransactionRepublish)
    {
    }

    // --------------------------------------------------------------
    // --------------------------------------------------------------
    //
    // management of subscription
    //
    // ------------------------------------------------------------------------
    // ------------------------------------------------------------------------
    void
    SubscriptionManager::createSubscription(uint32_t subscriptionId)
    {
    	SubscriptionSet::iterator it;
    	it = subscriptionSet_.find(subscriptionId);
    	if (it != subscriptionSet_.end()) {
    		Log(Error, "cannot create subscription, because subscription already exist")
    			.parameter("SubscriptionId", subscriptionId);
    		return;
    	}

    	subscriptionSet_.insert(subscriptionId);

    	if (subscriptionSet_.size() != 1) return;
    }

    void
    SubscriptionManager::deleteSubscription(uint32_t subscriptionId)
    {
    	SubscriptionSet::iterator it;
    	it = subscriptionSet_.find(subscriptionId);
    	if (it == subscriptionSet_.end()) {
    	    Log(Error, "cannot delete subscription, because subscription not exist")
    	    	.parameter("SubscriptionId", subscriptionId);
    	    return;
    	}

    	subscriptionSet_.erase(it);
    }

}
