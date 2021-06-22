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

#include "OpcUaStackServer/ServiceSet/Subscription.h"
#include "OpcUaStackCore/StandardDataTypes/DataChangeNotification.h"

using namespace OpcUaStackCore;

namespace OpcUaStackServer
{

	uint32_t Subscription::uniqueSubscriptionId_ = 0;
	boost::mutex Subscription::mutex_;

	uint32_t 
	Subscription::uniqueSubscriptionId(void) 
	{ 
		boost::mutex::scoped_lock g(mutex_);
		uniqueSubscriptionId_++;
		return uniqueSubscriptionId_;
	}



	Subscription::Subscription(void)
	: subscriptionId_(uniqueSubscriptionId())
	, slotTimerElement_(boost::make_shared<SlotTimerElement>())
	, retransmissionQueue_()
	, monitorManager_()
	, acknowledgementManager_()
	{
	    monitorManager_.subscriptionId(subscriptionId_);
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
	Subscription::ioThread(IOThread* ioThread)
	{
		ioThread_ = ioThread;
		monitorManager_.ioThread(ioThread);
	}

	void
	Subscription::strand(boost::shared_ptr<boost::asio::io_service::strand>& strand)
	{
		strand_ = strand;
		monitorManager_.strand(strand);
	}

	void 
	Subscription::informationModel(InformationModel::SPtr& informationModel)
	{
		monitorManager_.informationModel(informationModel);
	}

	void
	Subscription::forwardGlobalSync(ForwardGlobalSync::SPtr& forwardGlobalSync)
	{
		monitorManager_.forwardGlobalSync(forwardGlobalSync);
	}

	OpcUaStatusCode
	Subscription::receiveAcknowledgement(uint32_t acknowledgmentNumber)
	{
		acknowledgementManager_.deleteNotification(acknowledgmentNumber);
		return Success;
	}

		
	uint32_t 
	Subscription::publishPre(void)
	{
		return 0;
	}

	PublishResult 
	Subscription::publish(ServiceTransactionPublish::SPtr& trx)
	{
		if (trx.get() == NULL) {
			actLifetimeCount_--;

			// check subscription timeout
			if (actLifetimeCount_ == 0) {
				return SubscriptionTimeout;
			}

			// check keepalive count
			if (actMaxKeepAliveCount_ == 0) {
				return NothingTodo;
			}

			// calculate keepalive count
			actMaxKeepAliveCount_--;
			if (actMaxKeepAliveCount_ == 0) {
				return NeedAttention;
			}

			return NothingTodo;
		}

		// set lifetime counter
		actLifetimeCount_ = lifetimeCount_;

		//
		// handle event notification
		//
		auto extensibleParameter = boost::make_shared<OpcUaExtensibleParameter>();
		extensibleParameter->parameterTypeId().nodeId(OpcUaId_EventNotificationList_Encoding_DefaultBinary);
		auto eventNotificationList = extensibleParameter->parameter<EventNotificationList>();

		auto statusCode = monitorManager_.receive(eventNotificationList->events());
		if (eventNotificationList->events().size() > 0) {
			actMaxKeepAliveCount_ = maxKeepAliveCount_;

			uint32_t sequencenumber = acknowledgementManager_.nextSequenceNumber();
			acknowledgementManager_.addNotification(sequencenumber, extensibleParameter);

			auto publishResponse = trx->response();
			publishResponse->notificationMessage()->notificationData().set(0, extensibleParameter);
			publishResponse->notificationMessage()->publishTime().dateTime(boost::posix_time::microsec_clock::local_time());
			publishResponse->notificationMessage()->sequenceNumber() = sequencenumber;
			publishResponse->subscriptionId(subscriptionId_);
			publishResponse->moreNotifications(false);
			acknowledgementManager_.availableSequenceNumbers(publishResponse->availableSequenceNumbers());

			if (statusCode == BadOutOfMemory) {
				return NeedAttention;
			}
			return SendPublish;
		}

		//
		// handle data change notification
		//
		extensibleParameter = boost::make_shared<OpcUaExtensibleParameter>();
		extensibleParameter->parameterTypeId().nodeId(OpcUaId_DataChangeNotification_Encoding_DefaultBinary);
		auto dataChangeNotification = extensibleParameter->parameter<DataChangeNotification>();
		
		statusCode = monitorManager_.receive(dataChangeNotification->monitoredItems());
		if (dataChangeNotification->monitoredItems().size() > 0) {
			actMaxKeepAliveCount_ = maxKeepAliveCount_;

			uint32_t sequencenumber = acknowledgementManager_.nextSequenceNumber();
			acknowledgementManager_.addNotification(sequencenumber, extensibleParameter);

			auto publishResponse = trx->response();
			publishResponse->notificationMessage()->notificationData().set(0, extensibleParameter);
			publishResponse->notificationMessage()->publishTime().dateTime(boost::posix_time::microsec_clock::local_time());
			publishResponse->notificationMessage()->sequenceNumber() = sequencenumber;
			publishResponse->subscriptionId(subscriptionId_);
			publishResponse->moreNotifications(false);
			acknowledgementManager_.availableSequenceNumbers(publishResponse->availableSequenceNumbers());

			if (statusCode == BadOutOfMemory) return NeedAttention;
			return SendPublish;
		}

		// check keepalive counter
		actMaxKeepAliveCount_--;
		if (actMaxKeepAliveCount_ == 0) {
			actMaxKeepAliveCount_  = maxKeepAliveCount_;

			createKeepalive(trx);
			return SendPublishKeepalive;
		}

		return NothingTodo;
	}

	void 
	Subscription::createKeepalive(ServiceTransactionPublish::SPtr& trx)
	{
		auto publishResponse = trx->response();

		uint32_t sequencenumber = acknowledgementManager_.nextSequenceNumber(true);

		publishResponse->notificationMessage()->publishTime().dateTime(boost::posix_time::microsec_clock::local_time());
		publishResponse->notificationMessage()->sequenceNumber() = sequencenumber;
		publishResponse->subscriptionId(subscriptionId_);
		publishResponse->moreNotifications(false);
		acknowledgementManager_.availableSequenceNumbers(publishResponse->availableSequenceNumbers());
	}

	void 
	Subscription::retransmissionQueue(SubscriptionAcknowledgement::SPtr& subscriptionAcknowledgement)
	{
		retransmissionQueue_.erase(subscriptionAcknowledgement->sequenceNumber());
	}
		
	void 
	Subscription::retransmissionQueue(PublishResponse::SPtr& publishResponse)
	{
		publishResponse->availableSequenceNumbers()->resize(retransmissionQueue_.size());

		uint32_t idx = 0;
		for (auto it=retransmissionQueue_.begin(); it!=retransmissionQueue_.end(); it++) {
			publishResponse->availableSequenceNumbers()->set(idx, it->first);
			idx++;
		}

		retransmissionQueue_.insert(std::make_pair(publishResponse->notificationMessage()->sequenceNumber(), publishResponse));
	}


	OpcUaStatusCode 
	Subscription::receive(ServiceTransactionCreateMonitoredItems::SPtr trx)
	{
		// FIXME: todo - handle events

		return monitorManager_.receive(trx);
	}

	OpcUaStatusCode 
	Subscription::receive(ServiceTransactionDeleteMonitoredItems::SPtr trx)
	{
		// FIXME: todo - handle events

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
