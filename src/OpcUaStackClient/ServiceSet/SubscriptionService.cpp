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
#include "OpcUaStackClient/ServiceSet/SubscriptionService.h"

using namespace OpcUaStackCore;

namespace OpcUaStackClient
{

	SubscriptionService::SubscriptionService(IOThread* ioThread)
	: SubscriptionServiceBase()
	, subscriptionSet_()
	, subscriptionSetPendingDelete_()
	, publishCount_(5)
	, actPublishCount_(0)
	{
		Component::ioThread(ioThread);
		subscriptionServicePublishIf(this);
	}

	SubscriptionService::~SubscriptionService(void)
	{
	}

	void
	SubscriptionService::setConfiguration(
		Component* componentSession,
		uint32_t publishCount,
		uint32_t requestTimeout,
		SubscriptionServiceIf* subscriptionServiceIf
	)
	{
		this->componentSession(componentSession);
		publishCount_ = publishCount;
		requestTimeout_ = requestTimeout;
		this->subscriptionServiceIf(subscriptionServiceIf);
	}

	void
	SubscriptionService::publishCount(uint32_t publishCount)
	{
		publishCount_ = publishCount;
	}

	uint32_t
	SubscriptionService::publishCount(void)
	{
		return publishCount_;
	}

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// send
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	void
	SubscriptionService::syncSend(ServiceTransactionCreateSubscription::SPtr& serviceTransactionCreateSubscription)
	{
		SubscriptionServiceBase::syncSend(serviceTransactionCreateSubscription);
	}
	void
	SubscriptionService::asyncSend(ServiceTransactionCreateSubscription::SPtr& serviceTransactionCreateSubscription)
	{
		SubscriptionServiceBase::asyncSend(serviceTransactionCreateSubscription);
	}

	void
	SubscriptionService::syncSend(ServiceTransactionModifySubscription::SPtr& serviceTransactionModifySubscription)
	{
		SubscriptionServiceBase::syncSend(serviceTransactionModifySubscription);
	}

	void
	SubscriptionService::asyncSend(ServiceTransactionModifySubscription::SPtr& serviceTransactionModifySubscription)
	{
		SubscriptionServiceBase::asyncSend(serviceTransactionModifySubscription);
	}

	void
	SubscriptionService::syncSend(ServiceTransactionTransferSubscriptions::SPtr& serviceTransactionTransferSubscriptions)
	{
		SubscriptionServiceBase::syncSend(serviceTransactionTransferSubscriptions);
	}

	void
	SubscriptionService::asyncSend(ServiceTransactionTransferSubscriptions::SPtr& serviceTransactionTransferSubscriptions)
	{
		SubscriptionServiceBase::asyncSend(serviceTransactionTransferSubscriptions);
	}

	void
	SubscriptionService::syncSend(ServiceTransactionDeleteSubscriptions::SPtr& serviceTransactionDeleteSubscriptions)
	{
		sendDeleteSubscriptions(serviceTransactionDeleteSubscriptions);
		SubscriptionServiceBase::syncSend(serviceTransactionDeleteSubscriptions);
	}

	void
	SubscriptionService::asyncSend(ServiceTransactionDeleteSubscriptions::SPtr& serviceTransactionDeleteSubscriptions)
	{
		sendDeleteSubscriptions(serviceTransactionDeleteSubscriptions);
		SubscriptionServiceBase::asyncSend(serviceTransactionDeleteSubscriptions);
	}

	void
	SubscriptionService::syncSend(ServiceTransactionSetPublishingMode::SPtr& serviceTransactionSetPublishingMode)
	{
		SubscriptionServiceBase::syncSend(serviceTransactionSetPublishingMode);
	}

	void
	SubscriptionService::asyncSend(ServiceTransactionSetPublishingMode::SPtr& serviceTransactionSetPublishingMode)
	{
		SubscriptionServiceBase::asyncSend(serviceTransactionSetPublishingMode);
	}

	void
	SubscriptionService::syncSend(ServiceTransactionPublish::SPtr& serviceTransactionPublish)
	{
		SubscriptionServiceBase::syncSend(serviceTransactionPublish);
	}

	void
	SubscriptionService::asyncSend(ServiceTransactionPublish::SPtr& serviceTransactionPublish)
	{
		SubscriptionServiceBase::asyncSend(serviceTransactionPublish);
	}

	void
	SubscriptionService::syncSend(ServiceTransactionRepublish::SPtr& serviceTransactionRepublish)
	{
		SubscriptionServiceBase::syncSend(serviceTransactionRepublish);
	}

	void
	SubscriptionService::asyncSend(ServiceTransactionRepublish::SPtr& serviceTransactionRepublish)
	{
		SubscriptionServiceBase::asyncSend(serviceTransactionRepublish);
	}


	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// Component
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	void
	SubscriptionService::receive(Message::SPtr message)
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

			case OpcUaId_PublishResponse_Encoding_DefaultBinary:
			{
				subscriptionServicePublishResponse(
					boost::static_pointer_cast<ServiceTransactionPublish>(serviceTransaction)
				);
				return;
			}
		}

		SubscriptionServiceBase::receive(message);
	}

    void
    SubscriptionService::subscriptionServiceCreateSubscriptionResponse(ServiceTransactionCreateSubscription::SPtr serviceTransactionCreateSubscription)
    {
    	if (serviceTransactionCreateSubscription->statusCode() == Success) {
    		CreateSubscriptionResponse::SPtr res = serviceTransactionCreateSubscription->response();
    		createSubscription(res->subscriptionId());
    	}
    }

    void
    SubscriptionService::sendDeleteSubscriptions(ServiceTransactionDeleteSubscriptions::SPtr& serviceTransactionDeleteSubscriptions)
    {
    	DeleteSubscriptionsRequest::SPtr req = serviceTransactionDeleteSubscriptions->request();
    	for (uint32_t pos=0; pos<req->subscriptionIds()->size(); pos++) {
    		uint32_t subscriptionId;
    		req->subscriptionIds()->get(pos, subscriptionId);
    		deleteSubscriptionRequest(subscriptionId);
    	}
    }

    void
    SubscriptionService::subscriptionServiceDeleteSubscriptionsResponse(ServiceTransactionDeleteSubscriptions::SPtr serviceTransactionDeleteSubscriptions)
    {
    	if (serviceTransactionDeleteSubscriptions->statusCode() != Success) {
        	DeleteSubscriptionsRequest::SPtr req = serviceTransactionDeleteSubscriptions->request();
        	for (uint32_t pos=0; pos<req->subscriptionIds()->size(); pos++) {
        		uint32_t subscriptionId;
        		req->subscriptionIds()->get(pos, subscriptionId);
        		subscriptionSet_.insert(subscriptionId);
        	}
        	return;
    	}

        DeleteSubscriptionsRequest::SPtr req = serviceTransactionDeleteSubscriptions->request();
        for (uint32_t pos=0; pos<req->subscriptionIds()->size(); pos++) {
            uint32_t subscriptionId;
            req->subscriptionIds()->get(pos, subscriptionId);
            deleteSubscriptionResponse(subscriptionId);
        }
    }

    void
    SubscriptionService::subscriptionServiceSetPublishingModeResponse(ServiceTransactionSetPublishingMode::SPtr serviceTransactionSetPublishingMode)
    {
    }

    void
    SubscriptionService::subscriptionServicePublishResponse(ServiceTransactionPublish::SPtr serviceTransactionPublish)
    {
    	actPublishCount_--;

		// the session is closed. delete all subscriptions
		if (serviceTransactionPublish->statusCode() == BadSessionClosed) {
			std::vector<uint32_t> subscriptionIdVec_;
			SubscriptionSet::iterator it;
			for (it = subscriptionSet_.begin(); it != subscriptionSet_.end(); it++) {
				subscriptionIdVec_.push_back(*it);
			}

			std::vector<uint32_t>::iterator sIt;
			for (sIt = subscriptionIdVec_.begin(); sIt != subscriptionIdVec_.end(); sIt++) {
				deleteSubscriptionRequest(*sIt);
				deleteSubscriptionResponse(*sIt);
			}
		}

    	// check transaction status code
    	if (serviceTransactionPublish->statusCode() != Success) {
    		Log(Error, "subscription publish response error")
    			.parameter("StatsCode", OpcUaStatusCodeMap::shortString(serviceTransactionPublish->statusCode()));

    		sendPublishRequests();
    		return;
    	}

    	PublishResponse::SPtr res = serviceTransactionPublish->response();
    	receivePublishResponse(res);
    }

    void
    SubscriptionService::subscriptionServiceRepublishResponse(ServiceTransactionRepublish::SPtr serviceTransactionRepublish)
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
    SubscriptionService::createSubscription(uint32_t subscriptionId)
    {
    	SubscriptionSet::iterator it;
    	it = subscriptionSet_.find(subscriptionId);
    	if (it != subscriptionSet_.end()) {
    		Log(Error, "subscription create subscription response, because subscription already exist")
    			.parameter("SubscriptionId", subscriptionId);
    		return;
    	}

    	subscriptionSet_.insert(subscriptionId);
   		if (subscriptionServiceIf_ != NULL) {
    		subscriptionServiceIf_->subscriptionStateUpdate(SS_Open, subscriptionId);
    	}

    	if (subscriptionSet_.size() != 1) return;

    	sendPublishRequests();
    }

    void
    SubscriptionService::deleteSubscriptionRequest(uint32_t subscriptionId)
    {
    	SubscriptionSet::iterator it;
    	it = subscriptionSet_.find(subscriptionId);
    	if (it == subscriptionSet_.end()) {
    	    Log(Error, "subscription delete subscription response error, because subscription not exist")
    	    	.parameter("SubscriptionId", subscriptionId);
    	    return;
    	}
    	subscriptionSet_.erase(it);
    }

    void
    SubscriptionService::deleteSubscriptionResponse(uint32_t subscriptionId)
    {
   		if (subscriptionServiceIf_ != NULL) {
    		subscriptionServiceIf_->subscriptionStateUpdate(SS_Close, subscriptionId);
    	}
    }

    void
    SubscriptionService::sendPublishRequests(void)
    {
    	if (subscriptionSet_.size() == 0) return;
    	while (actPublishCount_ < publishCount_) {
    		ServiceTransactionPublish::SPtr trx = constructSPtr<ServiceTransactionPublish>();
    		trx->requestTimeout(requestTimeout_);
    		SubscriptionServiceBase::asyncSend(trx);

    		actPublishCount_++;
    	}
    }

    void
    SubscriptionService::receivePublishResponse(const PublishResponse::SPtr& publishResponse)
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
    				Log(Error, "subscription publish response error, because notification type in publish response unknown")
    				    .parameter("NotificationTypeId", notify->parameterTypeId().toString());
    				break;
    		}
    	}

    	sendPublishRequests();
    }

    void
    SubscriptionService::dataChangeNotification(const ExtensibleParameter::SPtr& extensibleParameter)
    {
    	DataChangeNotification::SPtr dataChange;
    	dataChange = extensibleParameter->parameter<DataChangeNotification>();

    	uint32_t count = dataChange->monitoredItems()->size();
    	for (uint32_t idx=0; idx<count; idx++) {
    		MonitoredItemNotification::SPtr monitoredItem;
    		dataChange->monitoredItems()->get(idx, monitoredItem);

    		if (subscriptionServiceIf_ != NULL) {
    			subscriptionServiceIf_->dataChangeNotification(monitoredItem);
    		}
    	}
    }
}
