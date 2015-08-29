/*
   Copyright 2015 Kai Huebl (kai@huebl-sgh.de)

   Lizenziert gemäß Apache Licence Version 2.0 (die „Lizenz“); Nutzung dieser
   Datei nur in Übereinstimmung mit der Lizenz erlaubt.
   Eine Kopie der Lizenz erhalten Sie auf http://www.apache.org/licenses/LICENSE-2.0.

   Sofern nicht gemäß geltendem Recht vorgeschrieben oder schriftlich vereinbart,
   erfolgt die Bereitstellung der im Rahmen der Lizenz verbreiteten Software OHNE
   GEWÄHR ODER VORBEHALTE – ganz gleich, ob ausdrücklich oder stillschweigend.

   Informationen über die jeweiligen Bedingungen für Genehmigungen und Einschränkungen
   im Rahmen der Lizenz finden Sie in der Lizenz.

   Autor: Kai Huebl (kai@huebl-sgh.de)
 */

#include "OpcUaStackCore/Base/Log.h"
#include "OpcUaStackCore/ServiceSet/DataChangeNotification.h"
#include "OpcUaStackClient/ServiceSet/SubscriptionManager.h"

using namespace OpcUaStackCore;

namespace OpcUaStackClient
{

	SubscriptionManager::SubscriptionManager(void)
	: SubscriptionService()
	, subscriptionServiceIf_(NULL)
	, subscriptionManagerIf_(NULL)
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
	SubscriptionManager::subscriptionManagerIf(SubscriptionManagerIf* subscriptionManagerIf)
	{
		subscriptionManagerIf_ = subscriptionManagerIf;
	}

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// Component
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	void
	SubscriptionManager::receive(Message::SPtr message)
	{
		ServiceTransaction::SPtr serviceTransaction = boost::static_pointer_cast<ServiceTransaction>(message);
		switch (serviceTransaction->nodeTypeResponse().nodeId<uint32_t>())
		{
			case OpcUaId_CreateSubscriptionResponse_Encoding_DefaultBinary:
			{
				subscriptionServiceCreateSubscriptionResponse(
					boost::static_pointer_cast<ServiceTransactionCreateSubscription>(serviceTransaction)
				);
				break;
			}

			case OpcUaId_DeleteSubscriptionsResponse_Encoding_DefaultBinary:
			{
				subscriptionServiceDeleteSubscriptionsResponse(
					boost::static_pointer_cast<ServiceTransactionDeleteSubscriptions>(serviceTransaction)
				);
				break;
			}
		}

		SubscriptionService::receive(message);
	}

    void
    SubscriptionManager::subscriptionServiceCreateSubscriptionResponse(ServiceTransactionCreateSubscription::SPtr serviceTransactionCreateSubscription)
    {
    	if (serviceTransactionCreateSubscription->statusCode() == Success) {
    		CreateSubscriptionResponse::SPtr res = serviceTransactionCreateSubscription->response();
    		createSubscription(res->subscriptionId());
    	}
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
    }

    void
    SubscriptionManager::subscriptionServiceSetPublishingModeResponse(ServiceTransactionSetPublishingMode::SPtr serviceTransactionSetPublishingMode)
    {
    }

    void
    SubscriptionManager::subscriptionServicePublishResponse(ServiceTransactionPublish::SPtr serviceTransactionPublish)
    {
    	actPublishCount_--;

    	// check transaction status code
    	if (serviceTransactionPublish->statusCode() != Success) {
    		Log(Error, "received publish response error")
    			.parameter("StatsCode", OpcUaStatusCodeMap::shortString(serviceTransactionPublish->statusCode()));
    		sendPublishRequests();
    		return;
    	}

    	PublishResponse::SPtr res = serviceTransactionPublish->response();
    	receivePublishResponse(res);
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

    	sendPublishRequests();
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

    void
    SubscriptionManager::sendPublishRequests(void)
    {
    	while (actPublishCount_ < publishCount_) {
    		ServiceTransactionPublish::SPtr trx = ServiceTransactionPublish::construct();
    		trx->requestTimeout(60000); // FIXME:
    		send(trx);

    		actPublishCount_++;
    	}
    }

    void
    SubscriptionManager::receivePublishResponse(const PublishResponse::SPtr& publishResponse)
    {
    	uint32_t count = publishResponse->notificationMessage()->notificationData()->size();
    	for (uint32_t idx=0; idx<count; idx++) {
    		ExtensibleParameter::SPtr notify;
    		publishResponse->notificationMessage()->notificationData()->get(idx, notify);

    		switch (notify->parameterTypeId().nodeId<uint32_t>())
    		{
    			case OpcUaId_DataChangeNotification_Encoding_DefaultBinary:
    				dataChangeNotification(notify);
    				break;
    			default:
    				Log(Error, "receive unknown notification type in publish response")
    				    .parameter("NotificationTypeId", notify->parameterTypeId().toString());
    				break;
    		}
    	}

    	sendPublishRequests();
    }

    void
    SubscriptionManager::dataChangeNotification(const ExtensibleParameter::SPtr& extensibleParameter)
    {
    	DataChangeNotification::SPtr dataChange;
    	dataChange = extensibleParameter->parameter<DataChangeNotification>();

    	uint32_t count = dataChange->monitoredItems()->size();
    	for (uint32_t idx=0; idx<count; idx++) {
    		MonitoredItemNotification::SPtr monitoredItem;
    		dataChange->monitoredItems()->get(idx, monitoredItem);

    		if (subscriptionManagerIf_ != NULL) {
    			subscriptionManagerIf_->dataChangeNotification(monitoredItem);
    		}
    	}
    }
}
