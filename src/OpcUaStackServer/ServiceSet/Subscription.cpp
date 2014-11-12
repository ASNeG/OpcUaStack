#include "OpcUaStackServer/ServiceSet/Subscription.h"
#include "OpcUaStackCore/ServiceSet/DataChangeNotification.h"

namespace OpcUaStackServer
{

	uint32_t Subscription::uniqueSubscriptionId_ = 0;
	uint32_t Subscription::sequenceNumber_;
	boost::mutex Subscription::mutex_;

	uint32_t 
	Subscription::uniqueSubscriptionId(void) 
	{ 
		boost::mutex::scoped_lock g(mutex_);
		uniqueSubscriptionId_++;
		return uniqueSubscriptionId_;
	}

	uint32_t 
	Subscription::sequenceNumber(void)
	{
		boost::mutex::scoped_lock g(mutex_);
		sequenceNumber_++;
		if (sequenceNumber_ == 0) sequenceNumber_;
		return sequenceNumber_;
	}

	Subscription::Subscription(void)
	: subscriptionId_(uniqueSubscriptionId())
	, slotTimerElement_(SlotTimerElement::construct())
	, retransmissionQueue_()
	, monitorManager_()
	{
	}

	Subscription::~Subscription(void)
	{
		retransmissionQueue_.clear();
	}

	uint32_t 
	Subscription::subscriptionId(void)
	{
		return subscriptionId_;
	}

	void 
	Subscription::publishingInterval(double publishingInterval)
	{
		publishingInterval_ = publishingInterval;
	}
		
	SlotTimerElement::SPtr 
	Subscription::slotTimerElement(void)
	{
		return slotTimerElement_;
	}

	void 
	Subscription::lifetimeCount(uint32_t lifetimeCount)
	{
		lifetimeCount_ = lifetimeCount;
		actLifetimeCount_ = lifetimeCount;
	}

	void 
	Subscription::maxKeepAliveCount(uint32_t maxKeepAliveCount)
	{
		maxKeepAliveCount_ = maxKeepAliveCount;
		actMaxKeepAliveCount_  = maxKeepAliveCount;
	}

	void 
	Subscription::ioService(IOService* ioService)
	{
		ioService_ = ioService;
		monitorManager_.ioService(ioService);
	}

	void 
	Subscription::informationModel(InformationModel::SPtr informationModel)
	{
		monitorManager_.informationModel(informationModel);
	}
		
	uint32_t 
	Subscription::publishPre(void)
	{
		return 0;
	}

	PublishResult 
	Subscription::publish(ServiceTransactionPublish::SPtr trx)
	{
		if (trx.get() == NULL) {
			actLifetimeCount_--;
			if (actLifetimeCount_ == 0) return SubscriptionTimeout;

			if (actMaxKeepAliveCount_ == 0) return NothingTodo;

			// calculate keepalive count
			actMaxKeepAliveCount_--;
			if (actMaxKeepAliveCount_ == 0) return NeedAttention;

			return NothingTodo;
		}

		// check lifetime counter
		actLifetimeCount_ = lifetimeCount_;

		ExtensibleParameter::SPtr extensibleParameter = ExtensibleParameter::construct();
		extensibleParameter->parameterTypeId().nodeId(OpcUaId_DataChangeNotification_Encoding_DefaultBinary);
		DataChangeNotification::SPtr dataChangeNotification = extensibleParameter->parameter<DataChangeNotification>();
		
		OpcUaStatusCode statusCode = monitorManager_.receive(dataChangeNotification->monitoredItems());
		if (dataChangeNotification->monitoredItems()->size() > 0) {
			actMaxKeepAliveCount_ = maxKeepAliveCount_;

			PublishResponse::SPtr publishResponse = trx->response();
			publishResponse->notificationMessage()->notificationData()->set(0, extensibleParameter);
			publishResponse->notificationMessage()->publishTime().dateTime(boost::posix_time::microsec_clock::local_time());
			publishResponse->notificationMessage()->sequenceNumber(sequenceNumber());
			publishResponse->subscriptionId(subscriptionId_);
			publishResponse->moreNotifications(false);

			if (statusCode == BadOutOfMemory) return NeedAttention;
			return SendPublish;
		}

		// check keepalive counter
		actMaxKeepAliveCount_--;
		if (actMaxKeepAliveCount_ == 0) {
			actMaxKeepAliveCount_  = maxKeepAliveCount_;

			createKeepalive(trx);
			return SendPublish;
		}

		return NothingTodo;
	}

	void 
	Subscription::createKeepalive(ServiceTransactionPublish::SPtr trx)
	{
		PublishRequest::SPtr publishRequest = trx->request();
		PublishResponse::SPtr publishResponse = trx->response();
		ServiceTransaction::SPtr serviceTransaction = trx;

		publishResponse->notificationMessage()->publishTime().dateTime(boost::posix_time::microsec_clock::local_time());
		publishResponse->notificationMessage()->sequenceNumber(sequenceNumber());
		publishResponse->subscriptionId(subscriptionId_);
		publishResponse->moreNotifications(false);
	}

	void 
	Subscription::retransmissionQueue(SubscriptionAcknowledgement::SPtr subscriptionAcknowledgement)
	{
		retransmissionQueue_.erase(subscriptionAcknowledgement->sequenceNumber());
	}
		
	void 
	Subscription::retransmissionQueue(PublishResponse::SPtr publishResponse)
	{
		publishResponse->availableSequenceNumbers()->resize(retransmissionQueue_.size());

		uint32_t idx = 0;
		RetransmissionQueue::iterator it;
		for (it=retransmissionQueue_.begin(); it!=retransmissionQueue_.end(); it++) {
			publishResponse->availableSequenceNumbers()->set(idx, it->first);
			idx++;
		}

		retransmissionQueue_.insert(std::make_pair(publishResponse->notificationMessage()->sequenceNumber(), publishResponse));
	}


	OpcUaStatusCode 
	Subscription::receive(ServiceTransactionCreateMonitoredItems::SPtr trx)
	{
		return monitorManager_.receive(trx);
	}

	OpcUaStatusCode 
	Subscription::receive(ServiceTransactionDeleteMonitoredItems::SPtr trx)
	{
		return monitorManager_.receive(trx);
	}

	OpcUaStatusCode 
	Subscription::receive(ServiceTransactionModifyMonitoredItems::SPtr trx)
	{
		return monitorManager_.receive(trx);
	}

	OpcUaStatusCode 
	Subscription::receive(ServiceTransactionSetMonitoringMode::SPtr trx)
	{
		return monitorManager_.receive(trx);
	}

	OpcUaStatusCode 
	Subscription::receive(ServiceTransactionSetTriggering::SPtr trx)
	{
		return monitorManager_.receive(trx);
	}

}