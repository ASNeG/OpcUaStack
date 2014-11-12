#include "OpcUaStackCore/Base/Log.h"
#include "OpcUaStackServer/ServiceSet/MonitorItem.h"
#include "OpcUaStackServer/AddressSpaceModel/AttributeAccess.h"

namespace OpcUaStackServer
{

	boost::mutex MonitorItem::mutex_;
	uint32_t MonitorItem::uniqueMonitorItemId_ = 0;

	uint32_t 
	MonitorItem::uniqueMonitorItemId(void)
	{
		boost::mutex::scoped_lock g(mutex_);
		uniqueMonitorItemId_++;
		return uniqueMonitorItemId_;
	}

	MonitorItem::MonitorItem(void)
	: monitorItemId_(uniqueMonitorItemId())
	, monitorItemList_()
	, baseNodeClass_()
	, attribute_(nullptr)
	, dataValue_()
	, slotTimerElement_(SlotTimerElement::construct())
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

	uint32_t 
	MonitorItem::size(void)
	{
		return monitorItemList_.size();
	}

	OpcUaStatusCode 
	MonitorItem::receive(BaseNodeClass::SPtr baseNodeClass, MonitoredItemCreateRequest::SPtr monitoredItemCreateRequest)
	{
		baseNodeClass_ = baseNodeClass;
		monitoredItemCreateRequest_ = monitoredItemCreateRequest;
		samplingInterval_ = (uint32_t)monitoredItemCreateRequest->requestedParameters().samplingInterval();
		samplingInterval_ = 500; // FIXME:
		queSize_ = monitoredItemCreateRequest->requestedParameters().queueSize();
		clientHandle_ = monitoredItemCreateRequest->requestedParameters().clientHandle();

		// check attribute
		attribute_ = baseNodeClass->attribute((AttributeId)monitoredItemCreateRequest->itemToMonitor().attributeId());
		if (attribute_ == nullptr) {
			Log(Debug, "attribute not exist")
				.parameter("Node", monitoredItemCreateRequest->itemToMonitor().nodeId())
				.parameter("Attr", monitoredItemCreateRequest->itemToMonitor().attributeId());
			return BadNodeIdUnknown;
		}

		MonitoredItemNotification::SPtr monitoredItemNotification = MonitoredItemNotification::construct();
		if (attribute_->exist() == false) {
			Log(Debug, "read value error, because value not exist")
				.parameter("Node", monitoredItemCreateRequest->itemToMonitor().nodeId())
				.parameter("Attr", monitoredItemCreateRequest->itemToMonitor().attributeId());
			monitoredItemNotification->dataValue().statusCode(BadDataUnavailable);
			monitorItemListPushBack(monitoredItemNotification);
			return Success;
		}

		// read attribute
		if (!AttributeAccess::copy(*attribute_, monitoredItemNotification->dataValue())) {
			Log(Debug, "read value error, because value error")
				.parameter("Node", monitoredItemCreateRequest->itemToMonitor().nodeId())
				.parameter("Attr", monitoredItemCreateRequest->itemToMonitor().attributeId());
			monitoredItemNotification->dataValue().statusCode(BadDataUnavailable);
			monitorItemListPushBack(monitoredItemNotification);
			return Success;
		}

		monitoredItemNotification->dataValue().statusCode(Success);
		monitorItemListPushBack(monitoredItemNotification);
		return Success;
	}

	OpcUaStatusCode 
	MonitorItem::receive(MonitoredItemNotificationArray::SPtr monitoredItemNotificationArray)
	{
		uint32_t freeSize = monitoredItemNotificationArray->freeSize();
		do {
			if (monitorItemList_.size() == 0) return Success;
			if (freeSize == 0) return BadOutOfMemory;
			freeSize--;

			monitoredItemNotificationArray->push_back(monitorItemList_.front());
			monitorItemList_.pop_front();
		} while (true);

		return Success;
	}

	SampleResult 
	MonitorItem::sample(void)
	{
		BaseNodeClass::SPtr baseNodeClass = baseNodeClass_.lock();
		if (baseNodeClass.get() == nullptr) {

			// base node class no longer exist. Generate final notification if necessary
			if (dataValue_.statusCode() == BadNodeClassInvalid) return NodeNoLongerExist;

			// insert notification into queue
			MonitoredItemNotification::SPtr monitoredItemNotification = MonitoredItemNotification::construct();
			monitoredItemNotification->dataValue().statusCode(BadNodeClassInvalid);
			monitorItemListPushBack(monitoredItemNotification);
			return NodeNoLongerExist;
		}

		// check wheater an event schould be generated
		if (!AttributeAccess::trigger(dataValue_, *attribute_)) return Ok; 
		
		MonitoredItemNotification::SPtr monitoredItemNotification = MonitoredItemNotification::construct();
		if (!AttributeAccess::copy(*attribute_, monitoredItemNotification->dataValue())) {
			// data value is not available
			if (dataValue_.statusCode() == BadDataUnavailable) return Ok;

			// insert notification
			monitoredItemNotification->dataValue().statusCode(BadDataUnavailable);
			monitorItemListPushBack(monitoredItemNotification);
			return Ok;
		}

		// insert notification
		monitoredItemNotification->dataValue().statusCode(Success);
		monitorItemListPushBack(monitoredItemNotification);
		return Ok;
	}

	void 
	MonitorItem::monitorItemListPushBack(MonitoredItemNotification::SPtr monitoredItemNotification)
	{
		uint32_t actQueueSize = monitorItemList_.size();

		Log(Trace, "monitor item sample")
			.parameter("MonitorItemId", monitorItemId_)
			.parameter("ActQueueSize", actQueueSize)
			.parameter("MaxQueueSize", queSize_);
		
		if (actQueueSize >= queSize_) return;
		monitoredItemNotification->clientHandle(clientHandle_);
		monitorItemList_.push_back(monitoredItemNotification);
	}

}