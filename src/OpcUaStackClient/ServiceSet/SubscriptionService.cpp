/*
   Copyright 2015-2020 Kai Huebl (kai@huebl-sgh.de)

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
#include "OpcUaStackCore/StandardDataTypes/DataChangeNotification.h"
#include "OpcUaStackCore/StandardDataTypes/EventNotificationList.h"
#include "OpcUaStackClient/ServiceSet/SubscriptionService.h"

using namespace OpcUaStackCore;

namespace OpcUaStackClient
{

	SubscriptionService::SubscriptionService(
		const std::string& serviceName,
		IOThread* ioThread,
		MessageBus::SPtr& messageBus
	)
	: SubscriptionServiceBase()
	, subscriptionSet_()
	, subscriptionSetPendingDelete_()
	, publishCount_(5)
	, actPublishCount_(0)
	{
		// set parameter in client service base
		serviceName_ = serviceName;
		ClientServiceBase::ioThread_ = ioThread;
		strand_ = ioThread->createStrand();
		messageBus_ = messageBus;

		subscriptionServicePublishIf(this);
	}

	SubscriptionService::~SubscriptionService(void)
	{
		// deactivate receiver
		deactivateReceiver();
	}

	void
	SubscriptionService::setConfiguration(
		MessageBusMember::WPtr& sessionMember,
		const DataChangeNotificationHandler& dataChangeNotificationHandler,
		boost::shared_ptr<boost::asio::io_service::strand>& dataChangeNotificationHandlerStrand,
		const EventNotificationHandler& eventNotificationHandler,
		boost::shared_ptr<boost::asio::io_service::strand>& eventNotificationHandlerStrand,
		const SubscriptionStateUpdateHandler& subscriptionStateUpdateHandler,
		boost::shared_ptr<boost::asio::io_service::strand>& subscriptionStateUpdateHandlerStrand,
		uint32_t publishCount,
		uint32_t requestTimeout
	)
	{
		sessionMember_ = sessionMember;

		dataChangeNotificationHandler_ = dataChangeNotificationHandler;
		dataChangeNotificationHandlerStrand_ = dataChangeNotificationHandlerStrand;
		eventNotificationHandler_ = eventNotificationHandler;
		eventNotificationHandlerStrand_ = eventNotificationHandlerStrand;
		subscriptionStateUpdateHandler_ = subscriptionStateUpdateHandler;
		subscriptionStateUpdateHandlerStrand_ = subscriptionStateUpdateHandlerStrand;
		publishCount_ = publishCount;
		requestTimeout_ = requestTimeout;

		// register message bus receiver
		MessageBusMemberConfig messageBusMemberConfig;
		messageBusMemberConfig.strand(strand_);
		messageBusMember_ = messageBus_->registerMember(serviceName_, messageBusMemberConfig);

		// activate receiver
		activateReceiver(
			[this](const OpcUaStackCore::MessageBusMember::WPtr& handleFrom, Message::SPtr& message){
				receive(handleFrom, message);
			}
		);
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
	SubscriptionService::syncSend(const ServiceTransactionCreateSubscription::SPtr& serviceTransactionCreateSubscription)
	{
		SubscriptionServiceBase::syncSend(serviceTransactionCreateSubscription);
	}
	void
	SubscriptionService::asyncSend(const ServiceTransactionCreateSubscription::SPtr& serviceTransactionCreateSubscription)
	{
		SubscriptionServiceBase::asyncSend(serviceTransactionCreateSubscription);
	}

	void
	SubscriptionService::syncSend(const ServiceTransactionModifySubscription::SPtr& serviceTransactionModifySubscription)
	{
		SubscriptionServiceBase::syncSend(serviceTransactionModifySubscription);
	}

	void
	SubscriptionService::asyncSend(const ServiceTransactionModifySubscription::SPtr& serviceTransactionModifySubscription)
	{
		SubscriptionServiceBase::asyncSend(serviceTransactionModifySubscription);
	}

	void
	SubscriptionService::syncSend(const ServiceTransactionTransferSubscriptions::SPtr& serviceTransactionTransferSubscriptions)
	{
		SubscriptionServiceBase::syncSend(serviceTransactionTransferSubscriptions);
	}

	void
	SubscriptionService::asyncSend(const ServiceTransactionTransferSubscriptions::SPtr& serviceTransactionTransferSubscriptions)
	{
		SubscriptionServiceBase::asyncSend(serviceTransactionTransferSubscriptions);
	}

	void
	SubscriptionService::syncSend(const ServiceTransactionDeleteSubscriptions::SPtr& serviceTransactionDeleteSubscriptions)
	{
		sendDeleteSubscriptions(serviceTransactionDeleteSubscriptions);
		SubscriptionServiceBase::syncSend(serviceTransactionDeleteSubscriptions);
	}

	void
	SubscriptionService::asyncSend(const ServiceTransactionDeleteSubscriptions::SPtr& serviceTransactionDeleteSubscriptions)
	{
		sendDeleteSubscriptions(serviceTransactionDeleteSubscriptions);
		SubscriptionServiceBase::asyncSend(serviceTransactionDeleteSubscriptions);
	}

	void
	SubscriptionService::syncSend(const ServiceTransactionSetPublishingMode::SPtr& serviceTransactionSetPublishingMode)
	{
		SubscriptionServiceBase::syncSend(serviceTransactionSetPublishingMode);
	}

	void
	SubscriptionService::asyncSend(const ServiceTransactionSetPublishingMode::SPtr& serviceTransactionSetPublishingMode)
	{
		SubscriptionServiceBase::asyncSend(serviceTransactionSetPublishingMode);
	}

	void
	SubscriptionService::syncSend(const ServiceTransactionPublish::SPtr& serviceTransactionPublish)
	{
		SubscriptionServiceBase::syncSend(serviceTransactionPublish);
	}

	void
	SubscriptionService::asyncSend(const ServiceTransactionPublish::SPtr& serviceTransactionPublish)
	{
		SubscriptionServiceBase::asyncSend(serviceTransactionPublish);
	}

	void
	SubscriptionService::syncSend(const ServiceTransactionRepublish::SPtr& serviceTransactionRepublish)
	{
		SubscriptionServiceBase::syncSend(serviceTransactionRepublish);
	}

	void
	SubscriptionService::asyncSend(const ServiceTransactionRepublish::SPtr& serviceTransactionRepublish)
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
	SubscriptionService::receive(
		const OpcUaStackCore::MessageBusMember::WPtr& handleFrom,
		Message::SPtr message
	)
	{
		auto serviceTransaction = boost::static_pointer_cast<ServiceTransaction>(message);
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

		SubscriptionServiceBase::receive(handleFrom, message);
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
    SubscriptionService::sendDeleteSubscriptions(const ServiceTransactionDeleteSubscriptions::SPtr& serviceTransactionDeleteSubscriptions)
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
   		if (subscriptionStateUpdateHandler_) {
   			if (subscriptionStateUpdateHandlerStrand_) {
   				subscriptionStateUpdateHandlerStrand_->dispatch(
   				    [this, subscriptionId](void) {
   					    subscriptionStateUpdateHandler_(SS_Open, subscriptionId);
   				    }
   				);
   			}
   			else {
   			    subscriptionStateUpdateHandler_(SS_Open, subscriptionId);
   			}
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
   		if (subscriptionStateUpdateHandler_) {
 			if (subscriptionStateUpdateHandlerStrand_) {
   				subscriptionStateUpdateHandlerStrand_->dispatch(
   				    [this, subscriptionId](void) {
   					    subscriptionStateUpdateHandler_(SS_Close, subscriptionId);
   				    }
   				);
   			}
   			else {
   			    subscriptionStateUpdateHandler_(SS_Close, subscriptionId);
   			}
    	}
    }

    void
    SubscriptionService::sendPublishRequests(void)
    {
    	if (subscriptionSet_.size() == 0) return;
    	while (actPublishCount_ < publishCount_) {
    		ServiceTransactionPublish::SPtr trx = boost::make_shared<ServiceTransactionPublish>();
    		trx->requestTimeout(requestTimeout_);
    		SubscriptionServiceBase::asyncSend(trx);

    		actPublishCount_++;
    	}
    }

    void
    SubscriptionService::receivePublishResponse(const PublishResponse::SPtr& publishResponse)
    {
    	uint32_t count = publishResponse->notificationMessage()->notificationData().size();
    	for (uint32_t idx=0; idx<count; idx++) {
    		OpcUaExtensibleParameter::SPtr notify;
    		publishResponse->notificationMessage()->notificationData().get(idx, notify);

    		switch (notify->parameterTypeId().nodeId<uint32_t>())
    		{
    			case OpcUaId_DataChangeNotification_Encoding_DefaultBinary:
    				dataChangeNotification(notify);
    				break;
    			case OpcUaId_EventNotificationList_Encoding_DefaultBinary:
    				eventNotification(notify);
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
    SubscriptionService::dataChangeNotification(const OpcUaExtensibleParameter::SPtr& extensibleParameter)
    {
    	auto dataChange = extensibleParameter->parameter<DataChangeNotification>();

    	auto count = dataChange->monitoredItems().size();
    	for (uint32_t idx=0; idx<count; idx++) {
    		MonitoredItemNotification::SPtr monitoredItem;
    		dataChange->monitoredItems().get(idx, monitoredItem);

    		if (dataChangeNotificationHandler_) {
    			if (dataChangeNotificationHandlerStrand_) {
    				dataChangeNotificationHandlerStrand_->dispatch(
    					[this, monitoredItem](void) {
    					    dataChangeNotificationHandler_(monitoredItem);
    				    }
    				);
    			}
    			else {
    			    dataChangeNotificationHandler_(monitoredItem);
    			}
    		}
    	}
    }

    void
	SubscriptionService::eventNotification(const OpcUaExtensibleParameter::SPtr& extensibleParameter)
    {
    	auto eventNotificationList = extensibleParameter->parameter<EventNotificationList>();

    	auto count = eventNotificationList->events().size();
    	for (uint32_t idx=0; idx<count; idx++) {
    		EventFieldList::SPtr eventFieldList;
    		eventNotificationList->events().get(idx, eventFieldList);

    		if (eventNotificationHandler_) {
    			if (eventNotificationHandlerStrand_) {
    				eventNotificationHandlerStrand_->dispatch(
    					[this, eventFieldList](void) {
    					    eventNotificationHandler_(eventFieldList);
    				    }
    				);
    			}
    			else {
    			    eventNotificationHandler_(eventFieldList);
    			}
    		}
    	}
    }
}
