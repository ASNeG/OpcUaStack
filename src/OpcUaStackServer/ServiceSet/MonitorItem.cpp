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
#include "OpcUaStackServer/ServiceSet/MonitorItem.h"
#include "OpcUaStackServer/ServiceSet/MonitorItemId.h"
#include "OpcUaStackServer/AddressSpaceModel/AttributeAccess.h"

using namespace OpcUaStackCore;

namespace OpcUaStackServer
{

	MonitorItem::MonitorItem(void)
	: monitorItemId_(MonitorItemId::monitorItemId())
	, monitorItemList_()
	, baseNodeClass_()
	, attribute_(nullptr)
	, dataValue_()
	, slotTimerElement_(boost::make_shared<SlotTimerElement>())
	, userContext_()
	{
	}

	MonitorItem::~MonitorItem(void)
	{
		monitorItemList_.clear();
	}

	uint32_t 
	MonitorItem::monitorItemId(void)
	{
		return monitorItemId_;
	}

	uint32_t
	MonitorItem::samplingInterval(void)
	{
		return samplingInterval_;
	}

	uint32_t
	MonitorItem::queSize(void)
	{
		return queSize_;
	}

	bool
	MonitorItem::discardOldest()
	{
	    return discardOldest_;
	}

	SlotTimerElement::SPtr 
	MonitorItem::slotTimerElement(void)
	{
		return slotTimerElement_;
	}

	MonitoredItemCreateRequest::SPtr 
	MonitorItem::monitoredItemCreateRequest(void)
	{
		return monitoredItemCreateRequest_;
	}

	void
	MonitorItem::userContext(UserContext::SPtr& userContext)
	{
		userContext_ = userContext;
	}

	UserContext::SPtr&
	MonitorItem::userContext(void)
	{
		return userContext_;
	}

	uint32_t 
	MonitorItem::size(void)
	{
		return monitorItemList_.size();
	}

	OpcUaStatusCode 
	MonitorItem::receive(
		BaseNodeClass::SPtr& baseNodeClass,
		MonitoredItemCreateRequest::SPtr& monitoredItemCreateRequest
	)
	{
		baseNodeClass_ = baseNodeClass;
		monitoredItemCreateRequest_ = monitoredItemCreateRequest;
		queSize_ = monitoredItemCreateRequest->requestedParameters().queueSize();
		discardOldest_ = monitoredItemCreateRequest->requestedParameters().discardOldest();
		clientHandle_ = monitoredItemCreateRequest->requestedParameters().clientHandle();

		// check sampling
		samplingInterval_ = (uint32_t)monitoredItemCreateRequest->requestedParameters().samplingInterval();
		OpcUaDouble nodeSamplingInterval;
		if (baseNodeClass->getMinimumSamplingInterval(nodeSamplingInterval) && samplingInterval_ < nodeSamplingInterval) {
		    samplingInterval_ = nodeSamplingInterval;
		}

		// check attribute
		boost::shared_lock<boost::shared_mutex> lock(baseNodeClass->mutex());
		attribute_ = baseNodeClass->attribute((AttributeId)monitoredItemCreateRequest->itemToMonitor().attributeId());
		if (attribute_ == nullptr) {
			Log(Debug, "attribute not exist")
				.parameter("Node", monitoredItemCreateRequest->itemToMonitor().nodeId())
				.parameter("Attr", monitoredItemCreateRequest->itemToMonitor().attributeId());
			return BadNodeIdUnknown;
		}

		auto monitoredItemNotification = boost::make_shared<MonitoredItemNotification>();
		if (attribute_->exist() == false) {
			Log(Debug, "read value error, because value not exist")
				.parameter("Node", monitoredItemCreateRequest->itemToMonitor().nodeId())
				.parameter("Attr", monitoredItemCreateRequest->itemToMonitor().attributeId());
			monitoredItemNotification->value().statusCode(BadDataUnavailable);
			monitorItemListPushBack(monitoredItemNotification);
			return Success;
		}

		// read attribute
		if (!AttributeAccess::copy(*attribute_, monitoredItemNotification->value())) {
			Log(Debug, "read value error, because value error")
				.parameter("Node", monitoredItemCreateRequest->itemToMonitor().nodeId())
				.parameter("Attr", monitoredItemCreateRequest->itemToMonitor().attributeId());
			monitoredItemNotification->value().statusCode(BadDataUnavailable);
			monitorItemListPushBack(monitoredItemNotification);
			return Success;
		}

		monitoredItemNotification->value().statusCode(Success);
		monitorItemListPushBack(monitoredItemNotification);
		return Success;
	}

	OpcUaStatusCode 
	MonitorItem::receive(MonitoredItemNotificationArray& monitoredItemNotificationArray)
	{
		uint32_t freeSize = monitoredItemNotificationArray.freeSize();
		do {
			if (monitorItemList_.size() == 0) return Success;
			if (freeSize == 0) return BadOutOfMemory;
			freeSize--;

			monitoredItemNotificationArray.push_back(monitorItemList_.front());

			monitorItemList_.pop_front();
		} while (true);

		return Success;
	}

	SampleResult 
	MonitorItem::sample(void)
	{
		auto baseNodeClass = baseNodeClass_.lock();

		if (baseNodeClass.get() == nullptr) {
			// base node class no longer exist. Generate final notification if necessary
			if (dataValue_.statusCode() == BadNodeClassInvalid) {
				return NodeNoLongerExist;
			}

			// insert notification into queue
			auto monitoredItemNotification = boost::make_shared<MonitoredItemNotification>();
			monitoredItemNotification->value().statusCode(BadNodeClassInvalid);
			monitorItemListPushBack(monitoredItemNotification);
			return NodeNoLongerExist;
		}

		boost::shared_lock<boost::shared_mutex> lock(baseNodeClass->mutex());

		// check whether an event should be generated
		if (!AttributeAccess::trigger(dataValue_, *attribute_)) {
			return Ok;
		}

		auto monitoredItemNotification = boost::make_shared<MonitoredItemNotification>();
		if (!AttributeAccess::copy(*attribute_, monitoredItemNotification->value())) {
			// data value is not available
			if (dataValue_.statusCode() == BadDataUnavailable) {
				return Ok;
			}

			// insert notification
			monitoredItemNotification->value().statusCode(BadDataUnavailable);
			monitorItemListPushBack(monitoredItemNotification);
			return Ok;
		}
		AttributeAccess::copy(*attribute_, dataValue_);
		lock.unlock();

		// insert notification
		monitorItemListPushBack(monitoredItemNotification);
		return Ok;
	}

	void 
	MonitorItem::monitorItemListPushBack(
		MonitoredItemNotification::SPtr& monitoredItemNotification
	)
	{
		uint32_t actQueueSize = monitorItemList_.size();

		Log(Trace, "monitor item sample")
			.parameter("MonitorItemId", monitorItemId_)
			.parameter("ActQueueSize", actQueueSize)
			.parameter("MaxQueueSize", queSize_);
		
		if (actQueueSize >= queSize_) {
		    if (discardOldest_) {
		        monitorItemList_.pop_front();
		    } else {
		        monitorItemList_.pop_back();
		    }
		}

		monitoredItemNotification->clientHandle() = clientHandle_;
		monitorItemList_.push_back(monitoredItemNotification);
	}

	BaseNodeClass::SPtr
	MonitorItem::baseNodeClass(void)
	{
		BaseNodeClass::SPtr baseNodeClass = baseNodeClass_.lock();
		return baseNodeClass;
	}

}
