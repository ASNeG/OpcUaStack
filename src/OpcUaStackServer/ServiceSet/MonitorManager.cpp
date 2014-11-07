#include "OpcUaStackServer/ServiceSet/MonitorManager.h"
#include "OpcUaStackCore/Base/Log.h"

namespace OpcUaStackServer
{

	MonitorManager::MonitorManager(void)
	: monitorItemMap_()
	, slotTimer_(SlotTimer::construct())
	{
	}

	MonitorManager::~MonitorManager(void)
	{
		MonitorItemMap::iterator it;
		for (it=monitorItemMap_.begin(); it!=monitorItemMap_.end(); it++) {
			slotTimer_->stop(it->second->slotTimerElement());
		}

		monitorItemMap_.clear();
		slotTimer_->stopSlotTimerLoop(slotTimer_);
	}

	void 
	MonitorManager::ioService(IOService* ioService)
	{
		ioService_ = ioService;
		slotTimer_->startSlotTimerLoop(ioService);
	}

	void 
	MonitorManager::subscriptionId(uint32_t subscriptionId)
	{
		subscriptionId_ = subscriptionId;
	}
		
	uint32_t 
	MonitorManager::subscriptionId(void)
	{
		return subscriptionId_;
	}

	void 
	MonitorManager::informationModel(InformationModel::SPtr informationModel)
	{
		informationModel_ = informationModel;
	}

	OpcUaStatusCode 
	MonitorManager::receive(ServiceTransactionCreateMonitoredItems::SPtr trx)
	{
		CreateMonitoredItemsRequest::SPtr createMonitorItemRequest = trx->request();
		CreateMonitoredItemsResponse::SPtr createMonitorItemResponse = trx->response();

		uint32_t size = createMonitorItemRequest->itemsToCreate()->size();
		createMonitorItemResponse->results()->resize(size);

		for (uint32_t idx=0; idx<size; idx++) {
			MonitoredItemCreateResult::SPtr monitoredItemCreateResult;
			monitoredItemCreateResult = MonitoredItemCreateResult::construct();
			createMonitorItemResponse->results()->set(idx, monitoredItemCreateResult);

			// get request parameter
			MonitoredItemCreateRequest::SPtr monitoredItemCreateRequest;
			if (!createMonitorItemRequest->itemsToCreate()->get(idx, monitoredItemCreateRequest)) {
				monitoredItemCreateResult->statusCode(BadInvalidArgument);
				continue;
			}

			// find base node class
			BaseNodeClass::SPtr baseNodeClass;
			baseNodeClass = informationModel_->find(monitoredItemCreateRequest->itemToMonitor().nodeId());
			if (baseNodeClass.get() == nullptr) {
				monitoredItemCreateResult->statusCode(BadNodeIdUnknown);
				continue;
			}

			// create new monitor item
			MonitorItem::SPtr monitorItem = MonitorItem::construct();
			OpcUaStatusCode statusCode = monitorItem->receive(baseNodeClass, monitoredItemCreateRequest);
			if (statusCode != Success) {
				monitoredItemCreateResult->statusCode(statusCode);
				continue;
			}

			// insert monitor item into monitor item map
			monitoredItemCreateResult->statusCode(Success);
			monitoredItemCreateResult->monitoredItemId(monitorItem->monitorItemId());
			monitoredItemCreateResult->revisedSamplingInterval(monitorItem->samplingInterval());
			monitoredItemCreateResult->revisedQueueSize(monitorItem->queSize());
			monitorItemMap_.insert(std::make_pair(monitorItem->monitorItemId(), monitorItem));

			// start sample timer
			SlotTimerElement::SPtr slotTimerElement = monitorItem->slotTimerElement();
			slotTimerElement->interval((uint32_t)monitorItem->samplingInterval());
			slotTimerElement->callback().reset(boost::bind(&MonitorManager::sampleTimeout, this, monitorItem));
			slotTimer_->start(slotTimerElement);

			Log(Debug, "create monitor item")
				.parameter("Trx", trx->transactionId())
				.parameter("NodeId", monitoredItemCreateRequest->itemToMonitor().nodeId())
				.parameter("SessionId", trx->sessionId())
				.parameter("Subscription", createMonitorItemRequest->subscriptionId())
				.parameter("MonitorId", monitorItem->monitorItemId());

		}
		return Success;
	}

	OpcUaStatusCode 
	MonitorManager::receive(ServiceTransactionDeleteMonitoredItems::SPtr trx)
	{
		DeleteMonitoredItemsRequest::SPtr deleteMonitorItemRequest = trx->request();
		DeleteMonitoredItemsResponse::SPtr deleteMonitorItemResponse = trx->response();

		uint32_t size = deleteMonitorItemRequest->monitoredItemIds()->size();
		deleteMonitorItemResponse->results()->resize(size);
		
		for (uint32_t idx=0; idx<size; idx++) {
			
			// get monitor id
			uint32_t monitorItemId;
			if (!deleteMonitorItemRequest->monitoredItemIds()->get(idx, monitorItemId)) {
				deleteMonitorItemResponse->results()->set(idx, BadInvalidArgument);
				continue;
			}

			// find monitor item in monitor map
			MonitorItemMap::iterator it;
			it = monitorItemMap_.find(monitorItemId);
			if (it == monitorItemMap_.end()) {
				deleteMonitorItemResponse->results()->set(idx, Success);
				continue;
			}

			// stop sample timer an remove monitor item#
			slotTimer_->stop(it->second->slotTimerElement());
			monitorItemMap_.erase(it);
			deleteMonitorItemResponse->results()->set(idx, Success);
		}

		return Success;
	}

	void 
	MonitorManager::sampleTimeout(MonitorItem::SPtr monitorItem)
	{
		SampleResult sampleResult = monitorItem->sample();
		switch (sampleResult)
		{
			case Ok:
				// nothing to do
				break;
			case NodeNoLongerExist:
				Log(Debug, "monitor item no longer exist")
					.parameter("MonitorId", monitorItem->monitorItemId());

				slotTimer_->stop(monitorItem->slotTimerElement());
				monitorItemMap_.erase(monitorItem->monitorItemId());
				break;
		}
	}

}