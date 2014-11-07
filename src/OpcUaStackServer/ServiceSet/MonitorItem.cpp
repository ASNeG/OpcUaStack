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

	OpcUaStatusCode 
	MonitorItem::receive(BaseNodeClass::SPtr baseNodeClass, MonitoredItemCreateRequest::SPtr monitoredItemCreateRequest)
	{
		baseNodeClass_ = baseNodeClass;
		monitoredItemCreateRequest_ = monitoredItemCreateRequest;
		samplingInterval_ = monitoredItemCreateRequest->requestedParameters().samplingInterval();
		queSize_ = monitoredItemCreateRequest->requestedParameters().queueSize();

		// check attribute
		attribute_ = baseNodeClass->attribute((AttributeId)monitoredItemCreateRequest->itemToMonitor().attributeId());
		if (attribute_ == nullptr) {
			Log(Debug, "attribute not exist")
				.parameter("Node", monitoredItemCreateRequest->itemToMonitor().nodeId())
				.parameter("Attr", monitoredItemCreateRequest->itemToMonitor().attributeId());
			return BadNodeIdUnknown;
		}

		if (attribute_->exist() == false) {
			Log(Debug, "read value error, because value not exist")
				.parameter("Node", monitoredItemCreateRequest->itemToMonitor().nodeId())
				.parameter("Attr", monitoredItemCreateRequest->itemToMonitor().attributeId());
			dataValue_.statusCode(BadDataUnavailable);
			monitorItemListPushBack(dataValue_);
			return Success;
		}

		// read attribute
		if (!AttributeAccess::copy(*attribute_, dataValue_)) {
			Log(Debug, "read value error, because value error")
				.parameter("Node", monitoredItemCreateRequest->itemToMonitor().nodeId())
				.parameter("Attr", monitoredItemCreateRequest->itemToMonitor().attributeId());
			dataValue_.statusCode(BadDataUnavailable);
			monitorItemListPushBack(dataValue_);
			return Success;
		}

		monitorItemListPushBack(dataValue_);
		return Success;
	}

	SampleResult 
	MonitorItem::sample(void)
	{
		SampleResult sampleResult = Ok;

		OpcUaDataValue::SPtr dataValue;
		dataValue = OpcUaDataValue::construct();

		BaseNodeClass::SPtr baseNodeClass = baseNodeClass_.lock();
		if (baseNodeClass.get() == nullptr) {
			OpcUaDataValue::SPtr dataValue;
			dataValue = OpcUaDataValue::construct();
			dataValue->statusCode(BadDataUnavailable);
			sampleResult = NodeNoLongerExist;
		}
		else {
			
			if (!AttributeAccess::copy(*attribute_, *dataValue)) {
				Log(Debug, "read value error, because value error")
					.parameter("Node", baseNodeClass->nodeId())
					.parameter("Attr", attribute_->id());
				dataValue->statusCode(BadDataUnavailable);
			}

		}

		if (dataChange(dataValue_, *dataValue)) {
			monitorItemListPushBack(dataValue);
			dataValue->copyTo(dataValue_);
		}

		return sampleResult;
	}

	void 
	MonitorItem::monitorItemListPushBack(OpcUaDataValue::SPtr dataValue)
	{
		monitorItemList_.push_back(dataValue);
	}
		
	void 
	MonitorItem::monitorItemListPushBack(OpcUaDataValue& dataValue)
	{
		OpcUaDataValue::SPtr dataValueSPtr;
		dataValueSPtr = OpcUaDataValue::construct();
		dataValue.copyTo(*dataValueSPtr);
		monitorItemListPushBack(dataValueSPtr);
	}

	bool 
	MonitorItem::dataChange(OpcUaDataValue& oldDataValue, OpcUaDataValue& newDataValue)
	{
		return true;
	}

}