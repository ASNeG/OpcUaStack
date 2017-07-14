/*
   Copyright 2015-2017 Kai Huebl (kai@huebl-sgh.de)

   Lizenziert gemäß Apache Licence Version 2.0 (die „Lizenz“); Nutzung dieser
   Datei nur in Übereinstimmung mit der Lizenz erlaubt.
   Eine Kopie der Lizenz erhalten Sie auf http://www.apache.org/licenses/LICENSE-2.0.

   Sofern nicht gemäß geltendem Recht vorgeschrieben oder schriftlich vereinbart,
   erfolgt die Bereitstellung der im Rahmen der Lizenz verbreiteten Software OHNE
   GEWÄHR ODER VORBEHALTE – ganz gleich, ob ausdrücklich oder stillschweigend.

   Informationen über die jeweiligen Bedingungen für Genehmigungen und Einschränkungen
   im Rahmen der Lizenz finden Sie in der Lizenz.

   Autor: Samuel Huebl (samuel.huebl@asneg.de)
 */

#include "OpcUaStackCore/StandardDataTypes/SubscriptionDiagnosticsDataType.h"

namespace OpcUaStackCore
{

	SubscriptionDiagnosticsDataType::SubscriptionDiagnosticsDataType(void)
	: Object()
	, sessionId_()
	, subscriptionId_()
	, priority_()
	, publishingInterval_()
	, maxKeepAliveCount_()
	, maxLifetimeCount_()
	, maxNotificationsPerPublish_()
	, publishingEnabled_()
	, modifiyCount_()
	, enableCount_()
	, disableCount_()
	, republishRequestCount_()
	, republishMessageRequestCount_()
	, republishMessageCount_()
	, transferRequestCount_()
	, transferredToAltClientCount_()
	, transferredToSameClientCount_()
	, publishRequestCount_()
	, dataChangeNotificationsCount_()
	, eventNotificationsCount_()
	, notificationsCount_()
	, latePublishRequestCount_()
	, currentKeepAliveCount_()
	, currentLifetimeCount_()
	, unacknowledgedMessageCount_()
	, discardedMessageCount_()
	, monitoredItemCount_()
	, disabledMonitoredItemCount_()
	, monitoringQueueOverflowCount_()
	, nextSequenceNumber_()
	, eventQueueOverflowCount_()
	{
	}

	SubscriptionDiagnosticsDataType::~SubscriptionDiagnosticsDataType(void)
	{
	}

	OpcUaNodeId&
	SubscriptionDiagnosticsDataType::sessionId(void)
	{
		return sessionId_;
	}

	void
	SubscriptionDiagnosticsDataType::sessionId(OpcUaNodeId sessionId)
	{
		sessionId_ = sessionId;
	}

	OpcUaUInt32&
	SubscriptionDiagnosticsDataType::subscriptionId(void)
	{
		return subscriptionId_;
	}

	void
	SubscriptionDiagnosticsDataType::subscriptionId(OpcUaUInt32 subscriptionId)
	{
		subscriptionId_ = subscriptionId;
	}

	OpcUaByte&
	SubscriptionDiagnosticsDataType::priority(void)
	{
		return priority_;
	}

	void
	SubscriptionDiagnosticsDataType::priority(OpcUaByte priority)
	{
		priority_ = priority;
	}

	OpcUaDouble&
	SubscriptionDiagnosticsDataType::publishingInterval(void)
	{
		return publishingInterval_;
	}

	void
	SubscriptionDiagnosticsDataType::publishingInterval(OpcUaDouble publishingInterval)
	{
		publishingInterval_ = publishingInterval;
	}

	OpcUaUInt32&
	SubscriptionDiagnosticsDataType::maxKeepAliveCount(void)
	{
		return maxKeepAliveCount_;
	}

	void
	SubscriptionDiagnosticsDataType::maxKeepAliveCount(OpcUaUInt32 maxKeepAliveCount)
	{
		maxKeepAliveCount_ = maxKeepAliveCount;
	}

	OpcUaUInt32&
	SubscriptionDiagnosticsDataType::maxLifetimeCount(void)
	{
		return maxLifetimeCount_;
	}

	void
	SubscriptionDiagnosticsDataType::maxLifetimeCount(OpcUaUInt32 maxLifetimeCount)
	{
		maxLifetimeCount_ = maxLifetimeCount;
	}

	OpcUaUInt32&
	SubscriptionDiagnosticsDataType::maxNotificationsPerPublish(void)
	{
		return maxNotificationsPerPublish_;
	}

	void
	SubscriptionDiagnosticsDataType::maxNotificationsPerPublish(OpcUaUInt32 maxNotificationsPerPublish)
	{
		maxNotificationsPerPublish_ = maxNotificationsPerPublish;
	}

	OpcUaBoolean&
	SubscriptionDiagnosticsDataType::publishingEnabled(void)
	{
		return publishingEnabled_;
	}

	void
	SubscriptionDiagnosticsDataType::publishingEnabled(OpcUaBoolean publishingEnabled)
	{
		publishingEnabled_ = publishingEnabled;
	}

	OpcUaUInt32&
	SubscriptionDiagnosticsDataType::modifiyCount(void)
	{
		return modifiyCount_;
	}

	void
	SubscriptionDiagnosticsDataType::modifiyCount(OpcUaUInt32 modifiyCount)
	{
		modifiyCount_ = modifiyCount;
	}

	OpcUaUInt32&
	SubscriptionDiagnosticsDataType::enableCount(void)
	{
		return enableCount_;
	}

	void
	SubscriptionDiagnosticsDataType::enableCount(OpcUaUInt32 enableCount)
	{
		enableCount_ = enableCount;
	}

	OpcUaUInt32&
	SubscriptionDiagnosticsDataType::disableCount(void)
	{
		return disableCount_;
	}

	void
	SubscriptionDiagnosticsDataType::disableCount(OpcUaUInt32 disableCount)
	{
		disableCount_ = disableCount;
	}

	OpcUaUInt32&
	SubscriptionDiagnosticsDataType::republishRequestCount(void)
	{
		return republishRequestCount_;
	}

	void
	SubscriptionDiagnosticsDataType::republishRequestCount(OpcUaUInt32 republishRequestCount)
	{
		republishRequestCount_ = republishRequestCount;
	}

	OpcUaUInt32&
	SubscriptionDiagnosticsDataType::republishMessageRequestCount(void)
	{
		return republishMessageRequestCount_;
	}

	void
	SubscriptionDiagnosticsDataType::republishMessageRequestCount(OpcUaUInt32 republishMessageRequestCount)
	{
		republishMessageRequestCount_ = republishMessageRequestCount;
	}

	OpcUaUInt32&
	SubscriptionDiagnosticsDataType::republishMessageCount(void)
	{
		return republishMessageCount_;
	}

	void
	SubscriptionDiagnosticsDataType::republishMessageCount(OpcUaUInt32 republishMessageCount)
	{
		republishMessageCount_ = republishMessageCount;
	}

	OpcUaUInt32&
	SubscriptionDiagnosticsDataType::transferRequestCount(void)
	{
		return transferRequestCount_;
	}

	void
	SubscriptionDiagnosticsDataType::transferRequestCount(OpcUaUInt32 transferRequestCount)
	{
		transferRequestCount_ = transferRequestCount;
	}

	OpcUaUInt32&
	SubscriptionDiagnosticsDataType::transferredToAltClientCount(void)
	{
		return transferredToAltClientCount_;
	}

	void
	SubscriptionDiagnosticsDataType::transferredToAltClientCount(OpcUaUInt32 transferredToAltClientCount)
	{
		transferredToAltClientCount_ = transferredToAltClientCount;
	}

	OpcUaUInt32&
	SubscriptionDiagnosticsDataType::transferredToSameClientCount(void)
	{
		return transferredToSameClientCount_;
	}

	void
	SubscriptionDiagnosticsDataType::transferredToSameClientCount(OpcUaUInt32 transferredToSameClientCount)
	{
		transferredToSameClientCount_ = transferredToSameClientCount;
	}

	OpcUaUInt32&
	SubscriptionDiagnosticsDataType::publishRequestCount(void)
	{
		return publishRequestCount_;
	}

	void
	SubscriptionDiagnosticsDataType::publishRequestCount(OpcUaUInt32 publishRequestCount)
	{
		publishRequestCount_ = publishRequestCount;
	}

	OpcUaUInt32&
	SubscriptionDiagnosticsDataType::dataChangeNotificationsCount(void)
	{
		return dataChangeNotificationsCount_;
	}

	void
	SubscriptionDiagnosticsDataType::dataChangeNotificationsCount(OpcUaUInt32 dataChangeNotificationsCount)
	{
		dataChangeNotificationsCount_ = dataChangeNotificationsCount;
	}

	OpcUaUInt32&
	SubscriptionDiagnosticsDataType::eventNotificationsCount(void)
	{
		return eventNotificationsCount_;
	}

	void
	SubscriptionDiagnosticsDataType::eventNotificationsCount(OpcUaUInt32 eventNotificationsCount)
	{
		eventNotificationsCount_ = eventNotificationsCount;
	}

	OpcUaUInt32&
	SubscriptionDiagnosticsDataType::notificationsCount(void)
	{
		return notificationsCount_;
	}

	void
	SubscriptionDiagnosticsDataType::notificationsCount(OpcUaUInt32 notificationsCount)
	{
		notificationsCount_ = notificationsCount;
	}

	OpcUaUInt32&
	SubscriptionDiagnosticsDataType::latePublishRequestCount(void)
	{
		return latePublishRequestCount_;
	}

	void
	SubscriptionDiagnosticsDataType::latePublishRequestCount(OpcUaUInt32 latePublishRequestCount)
	{
		latePublishRequestCount_ = latePublishRequestCount;
	}

	OpcUaUInt32&
	SubscriptionDiagnosticsDataType::currentKeepAliveCount(void)
	{
		return currentKeepAliveCount_;
	}

	void
	SubscriptionDiagnosticsDataType::currentKeepAliveCount(OpcUaUInt32 currentKeepAliveCount)
	{
		currentKeepAliveCount_ = currentKeepAliveCount;
	}

	OpcUaUInt32&
	SubscriptionDiagnosticsDataType::currentLifetimeCount(void)
	{
		return currentLifetimeCount_;
	}

	void
	SubscriptionDiagnosticsDataType::currentLifetimeCount(OpcUaUInt32 currentLifetimeCount)
	{
		currentLifetimeCount_ = currentLifetimeCount;
	}

	OpcUaUInt32&
	SubscriptionDiagnosticsDataType::unacknowledgedMessageCount(void)
	{
		return unacknowledgedMessageCount_;
	}

	void
	SubscriptionDiagnosticsDataType::unacknowledgedMessageCount(OpcUaUInt32 unacknowledgedMessageCount)
	{
		unacknowledgedMessageCount_ = unacknowledgedMessageCount;
	}

	OpcUaUInt32&
	SubscriptionDiagnosticsDataType::discardedMessageCount(void)
	{
		return discardedMessageCount_;
	}

	void
	SubscriptionDiagnosticsDataType::discardedMessageCount(OpcUaUInt32 discardedMessageCount)
	{
		discardedMessageCount_ = discardedMessageCount;
	}

	OpcUaUInt32&
	SubscriptionDiagnosticsDataType::monitoredItemCount(void)
	{
		return monitoredItemCount_;
	}

	void
	SubscriptionDiagnosticsDataType::monitoredItemCount(OpcUaUInt32 monitoredItemCount)
	{
		monitoredItemCount_ = monitoredItemCount;
	}

	OpcUaUInt32&
	SubscriptionDiagnosticsDataType::disabledMonitoredItemCount(void)
	{
		return disabledMonitoredItemCount_;
	}

	void
	SubscriptionDiagnosticsDataType::disabledMonitoredItemCount(OpcUaUInt32 disabledMonitoredItemCount)
	{
		disabledMonitoredItemCount_ = disabledMonitoredItemCount;
	}

	OpcUaUInt32&
	SubscriptionDiagnosticsDataType::monitoringQueueOverflowCount(void)
	{
		return monitoringQueueOverflowCount_;
	}

	void
	SubscriptionDiagnosticsDataType::monitoringQueueOverflowCount(OpcUaUInt32 monitoringQueueOverflowCount)
	{
		monitoringQueueOverflowCount_ = monitoringQueueOverflowCount;
	}

	OpcUaUInt32&
	SubscriptionDiagnosticsDataType::nextSequenceNumber(void)
	{
		return nextSequenceNumber_;
	}

	void
	SubscriptionDiagnosticsDataType::nextSequenceNumber(OpcUaUInt32 nextSequenceNumber)
	{
		nextSequenceNumber_ = nextSequenceNumber;
	}

	OpcUaUInt32&
	SubscriptionDiagnosticsDataType::eventQueueOverflowCount(void)
	{
		return eventQueueOverflowCount_;
	}

	void
	SubscriptionDiagnosticsDataType::eventQueueOverflowCount(OpcUaUInt32 eventQueueOverflowCount)
	{
		eventQueueOverflowCount_ = eventQueueOverflowCount;
	}

	void
	SubscriptionDiagnosticsDataType::copyTo(SubscriptionDiagnosticsDataType& subscriptionDiagnosticsDataType)
	{
		sessionId_.copyTo(subscriptionDiagnosticsDataType.sessionId());
		subscriptionDiagnosticsDataType.subscriptionId(subscriptionId_);
		subscriptionDiagnosticsDataType.priority(priority_);
		subscriptionDiagnosticsDataType.publishingInterval(publishingInterval_);
		subscriptionDiagnosticsDataType.maxKeepAliveCount(maxKeepAliveCount_);
		subscriptionDiagnosticsDataType.maxLifetimeCount(maxLifetimeCount_);
		subscriptionDiagnosticsDataType.maxNotificationsPerPublish(maxNotificationsPerPublish_);
		subscriptionDiagnosticsDataType.publishingEnabled(publishingEnabled_);
		subscriptionDiagnosticsDataType.modifiyCount(modifiyCount_);
		subscriptionDiagnosticsDataType.enableCount(enableCount_);
		subscriptionDiagnosticsDataType.disableCount(disableCount_);
		subscriptionDiagnosticsDataType.republishRequestCount(republishRequestCount_);
		subscriptionDiagnosticsDataType.republishMessageRequestCount(republishMessageRequestCount_);
		subscriptionDiagnosticsDataType.republishMessageCount(republishMessageCount_);
		subscriptionDiagnosticsDataType.transferRequestCount(transferRequestCount_);
		subscriptionDiagnosticsDataType.transferredToAltClientCount(transferredToAltClientCount_);
		subscriptionDiagnosticsDataType.transferredToSameClientCount(transferredToSameClientCount_);
		subscriptionDiagnosticsDataType.publishRequestCount(publishRequestCount_);
		subscriptionDiagnosticsDataType.dataChangeNotificationsCount(dataChangeNotificationsCount_);
		subscriptionDiagnosticsDataType.eventNotificationsCount(eventNotificationsCount_);
		subscriptionDiagnosticsDataType.notificationsCount(notificationsCount_);
		subscriptionDiagnosticsDataType.latePublishRequestCount(latePublishRequestCount_);
		subscriptionDiagnosticsDataType.currentKeepAliveCount(currentKeepAliveCount_);
		subscriptionDiagnosticsDataType.currentLifetimeCount(currentLifetimeCount_);
		subscriptionDiagnosticsDataType.unacknowledgedMessageCount(unacknowledgedMessageCount_);
		subscriptionDiagnosticsDataType.discardedMessageCount(discardedMessageCount_);
		subscriptionDiagnosticsDataType.monitoredItemCount(monitoredItemCount_);
		subscriptionDiagnosticsDataType.disabledMonitoredItemCount(disabledMonitoredItemCount_);
		subscriptionDiagnosticsDataType.monitoringQueueOverflowCount(monitoringQueueOverflowCount_);
		subscriptionDiagnosticsDataType.nextSequenceNumber(nextSequenceNumber_);
		subscriptionDiagnosticsDataType.eventQueueOverflowCount(eventQueueOverflowCount_);
	}

	bool
	SubscriptionDiagnosticsDataType::operator==(const SubscriptionDiagnosticsDataType& subscriptionDiagnosticsDataType) const
	{
		SubscriptionDiagnosticsDataType* dst = const_cast<SubscriptionDiagnosticsDataType*>(&subscriptionDiagnosticsDataType);
		return
			sessionId_ == dst->sessionId() &&
			subscriptionId_ == dst->subscriptionId() &&
			priority_ == dst->priority() &&
			publishingInterval_ == dst->publishingInterval() &&
			maxKeepAliveCount_ == dst->maxKeepAliveCount() &&
			maxLifetimeCount_ == dst->maxLifetimeCount() &&
			maxNotificationsPerPublish_ == dst->maxNotificationsPerPublish() &&
			publishingEnabled_ == dst->publishingEnabled() &&
			modifiyCount_ == dst->modifiyCount() &&
			enableCount_ == dst->enableCount() &&
			disableCount_ == dst->disableCount() &&
			republishRequestCount_ == dst->republishRequestCount() &&
			republishMessageRequestCount_ == dst->republishMessageRequestCount() &&
			republishMessageCount_ == dst->republishMessageCount() &&
			transferRequestCount_ == dst->transferRequestCount() &&
			transferredToAltClientCount_ == dst->transferredToAltClientCount() &&
			transferredToSameClientCount_ == dst->transferredToSameClientCount() &&
			publishRequestCount_ == dst->publishRequestCount() &&
			dataChangeNotificationsCount_ == dst->dataChangeNotificationsCount() &&
			eventNotificationsCount_ == dst->eventNotificationsCount() &&
			notificationsCount_ == dst->notificationsCount() &&
			latePublishRequestCount_ == dst->latePublishRequestCount() &&
			currentKeepAliveCount_ == dst->currentKeepAliveCount() &&
			currentLifetimeCount_ == dst->currentLifetimeCount() &&
			unacknowledgedMessageCount_ == dst->unacknowledgedMessageCount() &&
			discardedMessageCount_ == dst->discardedMessageCount() &&
			monitoredItemCount_ == dst->monitoredItemCount() &&
			disabledMonitoredItemCount_ == dst->disabledMonitoredItemCount() &&
			monitoringQueueOverflowCount_ == dst->monitoringQueueOverflowCount() &&
			nextSequenceNumber_ == dst->nextSequenceNumber() &&
			eventQueueOverflowCount_ == dst->eventQueueOverflowCount();
	}

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// ExtensionObjectBase
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	ExtensionObjectBase::SPtr
	SubscriptionDiagnosticsDataType::factory(void)
	{
		return constructSPtr<SubscriptionDiagnosticsDataType>();
	}

	void
	SubscriptionDiagnosticsDataType::opcUaBinaryEncode(std::ostream& os) const
	{
		sessionId_.opcUaBinaryEncode(os);
		OpcUaNumber::opcUaBinaryEncode(os, subscriptionId_);
		OpcUaNumber::opcUaBinaryEncode(os, priority_);
		OpcUaNumber::opcUaBinaryEncode(os, publishingInterval_);
		OpcUaNumber::opcUaBinaryEncode(os, maxKeepAliveCount_);
		OpcUaNumber::opcUaBinaryEncode(os, maxLifetimeCount_);
		OpcUaNumber::opcUaBinaryEncode(os, maxNotificationsPerPublish_);
		OpcUaNumber::opcUaBinaryEncode(os, publishingEnabled_);
		OpcUaNumber::opcUaBinaryEncode(os, modifiyCount_);
		OpcUaNumber::opcUaBinaryEncode(os, enableCount_);
		OpcUaNumber::opcUaBinaryEncode(os, disableCount_);
		OpcUaNumber::opcUaBinaryEncode(os, republishRequestCount_);
		OpcUaNumber::opcUaBinaryEncode(os, republishMessageRequestCount_);
		OpcUaNumber::opcUaBinaryEncode(os, republishMessageCount_);
		OpcUaNumber::opcUaBinaryEncode(os, transferRequestCount_);
		OpcUaNumber::opcUaBinaryEncode(os, transferredToAltClientCount_);
		OpcUaNumber::opcUaBinaryEncode(os, transferredToSameClientCount_);
		OpcUaNumber::opcUaBinaryEncode(os, publishRequestCount_);
		OpcUaNumber::opcUaBinaryEncode(os, dataChangeNotificationsCount_);
		OpcUaNumber::opcUaBinaryEncode(os, eventNotificationsCount_);
		OpcUaNumber::opcUaBinaryEncode(os, notificationsCount_);
		OpcUaNumber::opcUaBinaryEncode(os, latePublishRequestCount_);
		OpcUaNumber::opcUaBinaryEncode(os, currentKeepAliveCount_);
		OpcUaNumber::opcUaBinaryEncode(os, currentLifetimeCount_);
		OpcUaNumber::opcUaBinaryEncode(os, unacknowledgedMessageCount_);
		OpcUaNumber::opcUaBinaryEncode(os, discardedMessageCount_);
		OpcUaNumber::opcUaBinaryEncode(os, monitoredItemCount_);
		OpcUaNumber::opcUaBinaryEncode(os, disabledMonitoredItemCount_);
		OpcUaNumber::opcUaBinaryEncode(os, monitoringQueueOverflowCount_);
		OpcUaNumber::opcUaBinaryEncode(os, nextSequenceNumber_);
		OpcUaNumber::opcUaBinaryEncode(os, eventQueueOverflowCount_);
	}

	void
	SubscriptionDiagnosticsDataType::opcUaBinaryDecode(std::istream& is)
	{
		sessionId_.opcUaBinaryDecode(is);
		OpcUaNumber::opcUaBinaryDecode(is, subscriptionId_);
		OpcUaNumber::opcUaBinaryDecode(is, priority_);
		OpcUaNumber::opcUaBinaryDecode(is, publishingInterval_);
		OpcUaNumber::opcUaBinaryDecode(is, maxKeepAliveCount_);
		OpcUaNumber::opcUaBinaryDecode(is, maxLifetimeCount_);
		OpcUaNumber::opcUaBinaryDecode(is, maxNotificationsPerPublish_);
		OpcUaNumber::opcUaBinaryDecode(is, publishingEnabled_);
		OpcUaNumber::opcUaBinaryDecode(is, modifiyCount_);
		OpcUaNumber::opcUaBinaryDecode(is, enableCount_);
		OpcUaNumber::opcUaBinaryDecode(is, disableCount_);
		OpcUaNumber::opcUaBinaryDecode(is, republishRequestCount_);
		OpcUaNumber::opcUaBinaryDecode(is, republishMessageRequestCount_);
		OpcUaNumber::opcUaBinaryDecode(is, republishMessageCount_);
		OpcUaNumber::opcUaBinaryDecode(is, transferRequestCount_);
		OpcUaNumber::opcUaBinaryDecode(is, transferredToAltClientCount_);
		OpcUaNumber::opcUaBinaryDecode(is, transferredToSameClientCount_);
		OpcUaNumber::opcUaBinaryDecode(is, publishRequestCount_);
		OpcUaNumber::opcUaBinaryDecode(is, dataChangeNotificationsCount_);
		OpcUaNumber::opcUaBinaryDecode(is, eventNotificationsCount_);
		OpcUaNumber::opcUaBinaryDecode(is, notificationsCount_);
		OpcUaNumber::opcUaBinaryDecode(is, latePublishRequestCount_);
		OpcUaNumber::opcUaBinaryDecode(is, currentKeepAliveCount_);
		OpcUaNumber::opcUaBinaryDecode(is, currentLifetimeCount_);
		OpcUaNumber::opcUaBinaryDecode(is, unacknowledgedMessageCount_);
		OpcUaNumber::opcUaBinaryDecode(is, discardedMessageCount_);
		OpcUaNumber::opcUaBinaryDecode(is, monitoredItemCount_);
		OpcUaNumber::opcUaBinaryDecode(is, disabledMonitoredItemCount_);
		OpcUaNumber::opcUaBinaryDecode(is, monitoringQueueOverflowCount_);
		OpcUaNumber::opcUaBinaryDecode(is, nextSequenceNumber_);
		OpcUaNumber::opcUaBinaryDecode(is, eventQueueOverflowCount_);
	}

	bool
	SubscriptionDiagnosticsDataType::xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
	{
		// FIXME: todo
		return false;
	}

	bool
	SubscriptionDiagnosticsDataType::xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns)
	{
		// FIXME: todo
		return false;
	}

	bool
	SubscriptionDiagnosticsDataType::xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns)
	{
		// FIXME: todo
		return false;
	}

	void
	SubscriptionDiagnosticsDataType::copyTo(ExtensionObjectBase& extensionObjectBase)
	{
		SubscriptionDiagnosticsDataType* dst = dynamic_cast<SubscriptionDiagnosticsDataType*>(&extensionObjectBase);
		copyTo(*dst);
	}

	bool
	SubscriptionDiagnosticsDataType::equal(ExtensionObjectBase& extensionObjectBase) const
	{
		SubscriptionDiagnosticsDataType* dst = dynamic_cast<SubscriptionDiagnosticsDataType*>(&extensionObjectBase);
		return *this == *dst;
	}

	void
	SubscriptionDiagnosticsDataType::out(std::ostream& os)
	{
		os << "SessionId=" << sessionId_;
		os << ", SubscriptionId=" << subscriptionId_;
		os << ", Priority=" << priority_;
		os << ", PublishingInterval=" << publishingInterval_;
		os << ", MaxKeepAliveCount=" << maxKeepAliveCount_;
		os << ", MaxLifetimeCount=" << maxLifetimeCount_;
		os << ", MaxNotificationsPerPublish=" << maxNotificationsPerPublish_;
		os << ", PublishingEnabled=" << publishingEnabled_;
		os << ", ModifiyCount=" << modifiyCount_;
		os << ", EnableCount=" << enableCount_;
		os << ", DisableCount=" << disableCount_;
		os << ", RepublishRequestCount=" << republishRequestCount_;
		os << ", RepublishMessageRequestCount=" << republishMessageRequestCount_;
		os << ", RepublishMessageCount=" << republishMessageCount_;
		os << ", TransferRequestCount=" << transferRequestCount_;
		os << ", TransferredToAltClientCount=" << transferredToAltClientCount_;
		os << ", TransferredToSameClientCount=" << transferredToSameClientCount_;
		os << ", PublishRequestCount=" << publishRequestCount_;
		os << ", DataChangeNotificationsCount=" << dataChangeNotificationsCount_;
		os << ", EventNotificationsCount=" << eventNotificationsCount_;
		os << ", NotificationsCount=" << notificationsCount_;
		os << ", LatePublishRequestCount=" << latePublishRequestCount_;
		os << ", CurrentKeepAliveCount=" << currentKeepAliveCount_;
		os << ", CurrentLifetimeCount=" << currentLifetimeCount_;
		os << ", UnacknowledgedMessageCount=" << unacknowledgedMessageCount_;
		os << ", DiscardedMessageCount=" << discardedMessageCount_;
		os << ", MonitoredItemCount=" << monitoredItemCount_;
		os << ", DisabledMonitoredItemCount=" << disabledMonitoredItemCount_;
		os << ", MonitoringQueueOverflowCoun_=" << monitoringQueueOverflowCount_;
		os << ", NextSequenceNumber=" << nextSequenceNumber_;
		os << ", EventQueueOverflowCount=" << eventQueueOverflowCount_;
	}

}

