/*
   Copyright 2015-2016 Kai Huebl (kai@huebl-sgh.de)

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

#include "OpcUaStackServer/ServiceSet/MonitorManager.h"
#include "OpcUaStackCore/Base/Log.h"
#include "OpcUaStackCore/Application/ApplicationMonitoredItemStartContext.h"
#include "OpcUaStackCore/Application/ApplicationMonitoredItemStopContext.h"

namespace OpcUaStackServer
{

	MonitorManager::MonitorManager(void)
	: ioService_(nullptr)
	, monitorItemMap_()
	, slotTimer_(constructSPtr<SlotTimer>())
	, monitoredItemIds_()
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

	uint32_t 
	MonitorManager::noticicationNumber(void)
	{
		uint32_t notificationNumber = 0;
		MonitorItemMap::iterator it;
		for (it = monitorItemMap_.begin(); it != monitorItemMap_.end(); it++) {
			notificationNumber += it->second->size();
		}
		return notificationNumber;
	}

	bool 
	MonitorManager::notificationAvailable(void)
	{
		MonitorItemMap::iterator it;
		for (it = monitorItemMap_.begin(); it != monitorItemMap_.end(); it++) {
			if (it->second->size() > 0) return true;
		}
		return false;
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
			monitoredItemCreateResult = constructSPtr<MonitoredItemCreateResult>();
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

			// check parameter
			if (monitoredItemCreateRequest->requestedParameters().samplingInterval() < 200) {
				monitoredItemCreateRequest->requestedParameters().samplingInterval(200);
			}
			if (monitoredItemCreateRequest->requestedParameters().queueSize() < 1) {
				monitoredItemCreateRequest->requestedParameters().queueSize(1);
			}

			// create new monitor item
			MonitorItem::SPtr monitorItem = constructSPtr<MonitorItem>();
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

			// forward start monitored item
			forwardStartMonitoredItem(baseNodeClass, monitorItem->monitorItemId());

			// start sample timer
			SlotTimerElement::SPtr slotTimerElement = monitorItem->slotTimerElement();
			slotTimerElement->interval(monitorItem->samplingInterval());
			slotTimerElement->callback().reset(boost::bind(&MonitorManager::sampleTimeout, this, monitorItem));
			slotTimer_->start(slotTimerElement);

			Log(Debug, "monitor item create")
				.parameter("MonitorId", monitorItem->monitorItemId())
				.parameter("Trx", trx->transactionId())
				.parameter("SessionId", trx->sessionId())
				.parameter("NodeId", monitoredItemCreateRequest->itemToMonitor().nodeId())
				.parameter("Subscription", createMonitorItemRequest->subscriptionId());
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

			// forward stop monitored item
			BaseNodeClass::SPtr baseNodeClass = it->second->baseNodeClass();
			if (baseNodeClass.get() != nullptr) {
				forwardStopMonitoredItem(baseNodeClass, monitorItemId);
			}

			Log(Trace, "monitor item remove")
				.parameter("MonitorId", it->second->monitorItemId())
				.parameter("Trx", trx->transactionId())
				.parameter("SessionId", trx->sessionId())
				.parameter("SubscriptionId", deleteMonitorItemRequest->subscriptionId());

			// stop sample timer an remove monitor item#
			slotTimer_->stop(it->second->slotTimerElement());
			monitorItemMap_.erase(it);
			deleteMonitorItemResponse->results()->set(idx, Success);
		}

		return Success;
	}

	OpcUaStatusCode 
	MonitorManager::receive(ServiceTransactionModifyMonitoredItems::SPtr trx)
	{
		return BadNotImplemented;
	}

	OpcUaStatusCode 
	MonitorManager::receive(ServiceTransactionSetMonitoringMode::SPtr trx)
	{
		return BadNotImplemented;
	}

	OpcUaStatusCode 
	MonitorManager::receive(ServiceTransactionSetTriggering::SPtr trx)
	{
		return BadNotImplemented;
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
				Log(Trace, "monitor item no longer exist")
					.parameter("MonitorId", monitorItem->monitorItemId());

				// forward stop monitored item
				// FIXME: todo base not class is not exist...
				//BaseNodeClass::SPtr baseNodeClass = it->second->baseNodeClass();
				//if (baseNodeClass.get() != nullptr) {
				//	forwardStopMonitoredItem(baseNodeClass, monitorItemId);
				//}

				slotTimer_->stop(monitorItem->slotTimerElement());
				monitorItemMap_.erase(monitorItem->monitorItemId());
				break;
		}
	}

	OpcUaStatusCode 
	MonitorManager::receive(MonitoredItemNotificationArray::SPtr monitoredItemNotificationArray)
	{
		uint32_t numberNotifications = 0;
		MonitorItemMap::iterator it;
		for (it = monitorItemMap_.begin(); it != monitorItemMap_.end(); it++) {
			numberNotifications += it->second->size();
		}

		if (numberNotifications == 0) return Success;

		monitoredItemNotificationArray->resize(numberNotifications);
		for (it = monitorItemMap_.begin(); it != monitorItemMap_.end(); it++) {
			OpcUaStatusCode statusCode = it->second->receive(monitoredItemNotificationArray);
			if (statusCode == BadOutOfMemory) return statusCode;
		}

		return Success;
	}

	void
	MonitorManager::forwardStartMonitoredItem(BaseNodeClass::SPtr baseNodeClass, uint32_t monitoredItemId)
	{
		ForwardInfoSync::SPtr forwardInfoSync = baseNodeClass->forwardInfoSync();
		if (forwardInfoSync.get() == nullptr) return;
		if (!forwardInfoSync->monitoredItemStartService().isCallback()) return;

		// find node id in item id map
		MonitoredItemIds::iterator it;
		it = monitoredItemIds_.find(baseNodeClass->nodeId().data());
		if (it != monitoredItemIds_.end()) {
			// not the first monitored item

			std::vector<uint32_t> monitoredItemIds = it->second;
			monitoredItemIds_.erase(it);
			monitoredItemIds.push_back(monitoredItemId);
			monitoredItemIds_.insert(std::make_pair(baseNodeClass->nodeId().data(), monitoredItemIds));

			return;
		}

		// first monitored item
		std::vector<uint32_t> monitoredItemIds;
		monitoredItemIds.push_back(monitoredItemId);
		monitoredItemIds_.insert(std::make_pair(baseNodeClass->nodeId().data(), monitoredItemIds));

		// forward monitored item start
		ApplicationMonitoredItemStartContext context;
		context.nodeId_ = baseNodeClass->nodeId().data();
		context.applicationContext_ = forwardInfoSync->monitoredItemStartService().applicationContext();

		forwardInfoSync->monitoredItemStartService().callback()(&context);
	}

	void
	MonitorManager::forwardStopMonitoredItem(BaseNodeClass::SPtr baseNodeClass, uint32_t monitoredItemId)
	{
		ForwardInfoSync::SPtr forwardInfoSync = baseNodeClass->forwardInfoSync();
		if (forwardInfoSync.get() == nullptr) return;
		if (!forwardInfoSync->monitoredItemStopService().isCallback()) return;
	}

}
