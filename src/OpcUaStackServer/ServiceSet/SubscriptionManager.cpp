#include "OpcUaStackCore/Base/Log.h"
#include "OpcUaStackServer/ServiceSet/SubscriptionManager.h"

using namespace OpcUaStackCore;

namespace OpcUaStackServer
{

	SubscriptionManager::SubscriptionManager(void)
	: ioService_(nullptr)
	, slotTimer_(SlotTimer::construct())
	, minPublishingInterval_(10)
	, minLifetimeCount_(2)
    , minMaxKeepAliveCount_(2)
	{
	}

	SubscriptionManager::~SubscriptionManager(void)
	{
		slotTimer_->stopSlotTimerLoop(slotTimer_);
	}

	void 
	SubscriptionManager::ioService(IOService* ioService)
	{
		ioService_ = ioService;
		slotTimer_->startSlotTimerLoop(ioService);
	}

	void 
	SubscriptionManager::informationModel(InformationModel::SPtr informationModel)
	{
		informationModel_ = informationModel;
	}

	void
	SubscriptionManager::sessionId(uint32_t sessionId) 
	{
		sessionId_ = sessionId;
	}

	uint32_t 
	SubscriptionManager::size(void)
	{
		return subscriptionMap_.size();
	}

	OpcUaStatusCode 
	SubscriptionManager::receive(ServiceTransactionCreateSubscription::SPtr trx)
	{
		CreateSubscriptionRequest::SPtr createSubscriptionRequest = trx->request();
		CreateSubscriptionResponse::SPtr createSubscriptionResponse = trx->response();

		Subscription::SPtr subscription = Subscription::construct();
		subscription->ioService(ioService_);
		subscription->informationModel(informationModel_);
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
		SlotTimerElement::SPtr slotTimerElement = subscription->slotTimerElement();
		slotTimerElement->interval((uint32_t)publishingInterval);
		slotTimerElement->callback().reset(boost::bind(&SubscriptionManager::subscriptionPublishTimeout, this, subscription));
		slotTimer_->start(slotTimerElement);

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
	SubscriptionManager::receive(ServiceTransactionDeleteSubscriptions::SPtr trx)
	{
		DeleteSubscriptionsRequest::SPtr deleteSubscriptionsRequest = trx->request();
		DeleteSubscriptionsResponse::SPtr deleteSubscriptionsResponse = trx->response();

		OpcUaUInt32 id;
		deleteSubscriptionsResponse->results()->resize(deleteSubscriptionsRequest->subscriptionIds()->size());
		for (uint32_t idx = 0; idx < deleteSubscriptionsRequest->subscriptionIds()->size(); idx++) {
			if (deleteSubscriptionsRequest->subscriptionIds()->get(idx, id)) {
				SubscriptionMap::iterator it = subscriptionMap_.find((uint32_t)id);
				if (it != subscriptionMap_.end()) {
					// stop subscription timer
					slotTimer_->stop(it->second->slotTimerElement());
				}

				subscriptionMap_.erase((uint32_t)id);

				Log(Debug, "delete subscription")
				    .parameter("Trx", trx->transactionId())
				    .parameter("SessionId", trx->sessionId())
					.parameter("Subscription", id);
			}
			deleteSubscriptionsResponse->results()->set(idx, Success);
		}
	
		return Success;
	}

	OpcUaStatusCode 
	SubscriptionManager::receive(ServiceTransactionPublish::SPtr trx)
	{
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
			{
				serviceTransactionPublishList_.pop_front();

				// FIXME: set unacknowledged sequence numbers...

				OpcUaNodeId typeId;
				typeId.set(OpcUaId_PublishResponse_Encoding_DefaultBinary);
				trx->statusCode(Success);
				trx->componentSession()->send(trx);
				break;
			}
			case SubscriptionTimeout:
			{
				Log(Debug, "timeout subscription")
					.parameter("SessionId", sessionId_)
					.parameter("Subscription", subscription->subscriptionId());

				slotTimer_->stop(subscription->slotTimerElement());
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

}
