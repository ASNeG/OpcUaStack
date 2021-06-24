/*
   Copyright 2015-2021 Kai Huebl (kai@huebl-sgh.de)

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
#include "OpcUaStackServer/ServiceSet/SubscriptionManager.h"

using namespace OpcUaStackCore;

namespace OpcUaStackServer
{

	SubscriptionManager::SubscriptionManager(void)
	: ioThread_(nullptr)
	, minPublishingInterval_(10)
	, minLifetimeCount_(2)
    , minMaxKeepAliveCount_(2)
	, sessionId_(0)
	{
	}

	SubscriptionManager::~SubscriptionManager(void)
	{
	}

	void 
	SubscriptionManager::ioThread(IOThread* ioThread)
	{
		ioThread_ = ioThread;
	}

	void
	SubscriptionManager::messageBus(OpcUaStackCore::MessageBus::SPtr& messageBus)
	{
		messageBus_ = messageBus;
	}

	void
	SubscriptionManager::messageBusMember(OpcUaStackCore::MessageBusMember::WPtr& messageBusMember)
	{
		messageBusMember_ = messageBusMember;
	}

	void
	SubscriptionManager::strand(boost::shared_ptr<boost::asio::io_service::strand>& strand)
	{
		strand_ = strand;
	}

	void 
	SubscriptionManager::informationModel(InformationModel::SPtr informationModel)
	{
		informationModel_ = informationModel;
	}

	void
	SubscriptionManager::forwardGlobalSync(ForwardGlobalSync::SPtr& forwardGlobalSync)
	{
		forwardGlobalSync_ = forwardGlobalSync;
	}

	void
	SubscriptionManager::sessionId(uint32_t sessionId) 
	{
		sessionId_ = sessionId;
	}

	size_t
	SubscriptionManager::size(void)
	{
		return subscriptionMap_.size();
	}

	OpcUaStatusCode 
	SubscriptionManager::receive(ServiceTransactionCreateSubscription::SPtr& trx)
	{
		auto createSubscriptionRequest = trx->request();
		auto createSubscriptionResponse = trx->response();

		auto subscription = boost::make_shared<Subscription>();
		subscription->ioThread(ioThread_);
		subscription->strand(strand_);
		subscription->informationModel(informationModel_);
		subscription->forwardGlobalSync(forwardGlobalSync_);
		subscriptionMap_.insert(std::make_pair(subscription->subscriptionId(), subscription));

		// calculate publishing interval
		double publishingInterval = createSubscriptionRequest->requestedPublishingInterval();
		if (minPublishingInterval_ > publishingInterval) publishingInterval = minPublishingInterval_;
		subscription->publishingInterval(publishingInterval);

		// calculate lifetime count
		uint32_t lifetimeCount = createSubscriptionRequest->requestedLifetimeCount();
		if (lifetimeCount < minLifetimeCount_) lifetimeCount = minLifetimeCount_;
		subscription->lifetimeCount(lifetimeCount);

		// calculate max keepalive count
		uint32_t maxKeepAliveCount = createSubscriptionRequest->requestedMaxKeepAliveCount();
		if (maxKeepAliveCount < minMaxKeepAliveCount_) maxKeepAliveCount = minMaxKeepAliveCount_;
		subscription->maxKeepAliveCount(maxKeepAliveCount);

		// start subscription timer
		auto slotTimerElement = subscription->slotTimerElement();
		slotTimerElement->interval((uint32_t)publishingInterval);
		slotTimerElement->timeoutCallback(
			strand_,
			[this, subscription](void) {
				subscriptionPublishTimeout(subscription);
			}
		);
		ioThread_->slotTimer()->start(slotTimerElement);

		// send create subscription response
		createSubscriptionResponse->subscriptionId(subscription->subscriptionId());
		createSubscriptionResponse->revisedPublishingInterval(publishingInterval);
		createSubscriptionResponse->revisedLifetimeCount(lifetimeCount);
		createSubscriptionResponse->revisedMaxKeepAliveCount(maxKeepAliveCount);

		Log(Debug, "create subscription")
			.parameter("Trx", trx->transactionId())
			.parameter("SessionId", trx->sessionId())
			.parameter("Subscription", subscription->subscriptionId());

		return Success;
	}

	OpcUaStatusCode 
	SubscriptionManager::receive(ServiceTransactionDeleteSubscriptions::SPtr& trx)
	{
		auto deleteSubscriptionsRequest = trx->request();
		auto deleteSubscriptionsResponse = trx->response();

		OpcUaUInt32 id;
		deleteSubscriptionsResponse->results()->resize(deleteSubscriptionsRequest->subscriptionIds()->size());
		for (uint32_t idx = 0; idx < deleteSubscriptionsRequest->subscriptionIds()->size(); idx++) {
			if (deleteSubscriptionsRequest->subscriptionIds()->get(idx, id)) {
				auto it = subscriptionMap_.find((uint32_t)id);
				if (it != subscriptionMap_.end()) {
					// stop subscription timer
					ioThread_->slotTimer()->stop(it->second->slotTimerElement());
					it->second->slotTimerElement()->timeoutCallback(nullptr);
				}

				subscriptionMap_.erase((uint32_t)id);

				Log(Debug, "delete subscription")
				    .parameter("Trx", trx->transactionId())
				    .parameter("SessionId", trx->sessionId())
					.parameter("Subscription", id);
			}
			deleteSubscriptionsResponse->results()->set(idx, Success);
		}

		if (subscriptionMap_.size() == 0) {
			// answer all open publish requests with status code BadNoSubscriptions

			while (serviceTransactionPublishList_.size() != 0) {
				auto trx = serviceTransactionPublishList_.front();
				serviceTransactionPublishList_.pop_front();

				OpcUaNodeId typeId;
				typeId.set(OpcUaId_PublishResponse_Encoding_DefaultBinary);
				trx->statusCode(BadNoSubscription);
				sendAnswer(trx);
			}
		}
	
		return Success;
	}

	OpcUaStatusCode 
	SubscriptionManager::receive(ServiceTransactionPublish::SPtr& trx)
	{
		// get publish request
		auto publishRequest = trx->request();

		// check acknowledgement list
		if (trx->request()->subscriptionAcknowledgements()->size() > 0) {
			trx->response()->results()->resize(trx->request()->subscriptionAcknowledgements()->size());
			for (uint32_t idx = 0; idx < trx->request()->subscriptionAcknowledgements()->size(); idx++) {
				SubscriptionAcknowledgement::SPtr subscriptionAcknowledgement;
				trx->request()->subscriptionAcknowledgements()->get(idx, subscriptionAcknowledgement);

				OpcUaStatusCode statusCode;
				statusCode = receiveAcknowledgement(
					subscriptionAcknowledgement->subscriptionId(),
					subscriptionAcknowledgement->sequenceNumber()
				);
				trx->response()->results()->set(idx, statusCode);
			}
		}

		// save publish request
		serviceTransactionPublishList_.push_back(trx);
		return Success;
	}

	void 
	SubscriptionManager::subscriptionPublishTimeout(Subscription::SPtr subscription)
	{
		ServiceTransactionPublish::SPtr trx;
		if (serviceTransactionPublishList_.size() != 0) {
		    trx = serviceTransactionPublishList_.front();
		}

		PublishResult publishResult = subscription->publish(trx);
		switch (publishResult)
		{
			case NothingTodo:
			{
				break;
			}
			case NeedAttention:
			{
				// FIXME: todo  - trx can be empty here
				break;
			}
			case SendPublish:
			case SendPublishKeepalive:
			{
				serviceTransactionPublishList_.pop_front();

				std::string mode = "Normal";
				if (publishResult == SendPublishKeepalive) mode = "Keepalive";

				Log(Debug, "publish response")
					.parameter("Mode", mode)
					.parameter("Trx", trx->transactionId())
					.parameter("SubscriptionId", subscription->subscriptionId())
					.parameter("SequenceNumber", trx->response()->notificationMessage()->sequenceNumber())
					.parameter("Unack-SequenceNumber", *trx->response()->availableSequenceNumbers());

				OpcUaNodeId typeId;
				typeId.set(OpcUaId_PublishResponse_Encoding_DefaultBinary);
				trx->statusCode(Success);
				sendAnswer(trx);
				break;
			}
			case SubscriptionTimeout:
			{
				Log(Debug, "timeout subscription")
					.parameter("SessionId", sessionId_)
					.parameter("Subscription", subscription->subscriptionId());

				ioThread_->slotTimer()->stop(subscription->slotTimerElement());
				subscription->slotTimerElement()->timeoutCallback(nullptr);

				subscriptionMap_.erase(subscription->subscriptionId());
				break;
			}
		}
	}

	OpcUaStatusCode 
	SubscriptionManager::receive(ServiceTransactionCreateMonitoredItems::SPtr trx)
	{
		CreateMonitoredItemsRequest::SPtr createMonitoredItemsRequest = trx->request();

		SubscriptionMap::iterator it;
		it = subscriptionMap_.find(createMonitoredItemsRequest->subscriptionId());
		if (it == subscriptionMap_.end()) return BadSubscriptionIdInvalid;
		return it->second->receive(trx);
	}

	OpcUaStatusCode 
	SubscriptionManager::receive(ServiceTransactionDeleteMonitoredItems::SPtr trx)
	{
		DeleteMonitoredItemsRequest::SPtr deleteMonitoredItemsRequest = trx->request();

		SubscriptionMap::iterator it;
		it = subscriptionMap_.find(deleteMonitoredItemsRequest->subscriptionId());
		if (it == subscriptionMap_.end()) return BadSubscriptionIdInvalid;
		return it->second->receive(trx);
	}

	OpcUaStatusCode 
	SubscriptionManager::receive(ServiceTransactionModifyMonitoredItems::SPtr trx)
	{
		ModifyMonitoredItemsRequest::SPtr modifyMonitoredItemsRequest = trx->request();

		SubscriptionMap::iterator it;
		it = subscriptionMap_.find(modifyMonitoredItemsRequest->subscriptionId());
		if (it == subscriptionMap_.end()) return BadSubscriptionIdInvalid;
		return it->second->receive(trx);
	}

	OpcUaStatusCode 
	SubscriptionManager::receive(ServiceTransactionSetMonitoringMode::SPtr trx)
	{
		SetMonitoringModeRequest::SPtr setMonitoringModeRequest = trx->request();

		SubscriptionMap::iterator it;
		it = subscriptionMap_.find(setMonitoringModeRequest->subscriptionId());
		if (it == subscriptionMap_.end()) return BadSubscriptionIdInvalid;
		return it->second->receive(trx);
	}

	OpcUaStatusCode 
	SubscriptionManager::receive(ServiceTransactionSetTriggering::SPtr trx)
	{
		SetTriggeringRequest::SPtr setTriggeringRequest = trx->request();

		SubscriptionMap::iterator it;
		it = subscriptionMap_.find(setTriggeringRequest->subscriptionId());
		if (it == subscriptionMap_.end()) return BadSubscriptionIdInvalid;
		return it->second->receive(trx);
	}

	OpcUaStatusCode
	SubscriptionManager::receiveAcknowledgement(uint32_t subscriptionId, uint32_t acknowledgmentNumber)
	{
		SubscriptionMap::iterator it;
		it = subscriptionMap_.find(subscriptionId);
		if (it == subscriptionMap_.end()) return BadNotFound;
		return it->second->receiveAcknowledgement(acknowledgmentNumber);
	}

	void
	SubscriptionManager::sendAnswer(const ServiceTransaction::SPtr& serviceTransaction)
	{
		messageBus_->messageSend(
			messageBusMember_,
			serviceTransaction->memberServiceSession(),
			serviceTransaction
		);
	}

}
