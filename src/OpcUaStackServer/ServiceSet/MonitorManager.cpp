/*
   Copyright 2015-2018 Kai Huebl (kai@huebl-sgh.de)

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
#include "OpcUaStackCore/Application/ApplicationMonitoredItemStartContext.h"
#include "OpcUaStackCore/Application/ApplicationMonitoredItemStopContext.h"
#include "OpcUaStackCore/Application/ApplicationEventItemStartContext.h"
#include "OpcUaStackCore/Application/ApplicationEventItemStopContext.h"
#include "OpcUaStackServer/ServiceSetApplication/NodeReferenceApplication.h"
#include "OpcUaStackServer/ServiceSet/MonitorManager.h"
#include "OpcUaStackServer/ServiceSet/EventItem.h"

namespace OpcUaStackServer
{

	MonitorManager::MonitorManager(void)
	: ioThread_(nullptr)
	, monitorItemMap_()
	, eventItemMap_()
	, monitoredItemIds_()
	, subscriptionId_(0)
	{
	}

	MonitorManager::~MonitorManager(void)
	{
		//
		// cleanup monitored item
		//
		MonitorItemMap::iterator it1;
		for (it1=monitorItemMap_.begin(); it1!=monitorItemMap_.end(); it1++) {
		    MonitorItem::SPtr monitorItem = it1->second;

		    if (monitorItem->baseNodeClass() != nullptr) {
		        forwardStopMonitoredItem(monitorItem->baseNodeClass(), it1->first);
		    }

			ioThread_->slotTimer()->stop(monitorItem->slotTimerElement());
			monitorItem->slotTimerElement().reset();
		}

		monitorItemMap_.clear();

		//
		// cleanup event item
		//
		EventItem::Map::iterator it2;
		for (it2=eventItemMap_.begin(); it2!=eventItemMap_.end(); it2++) {
		    EventItem::SPtr eventItem = it2->second;

			// forward stop event item
			if (forwardGlobalSync_.get() != nullptr) {
				if (forwardGlobalSync_->eventItemStopService().isCallback()) {
					ApplicationEventItemStopContext context;
					context.applicationContext_ = forwardGlobalSync_->eventItemStopService().applicationContext();
					context.eventItemId_ = it2->second->eventItemId();

					forwardGlobalSync_->eventItemStopService().callback()(&context);
				}
			}
		}

		eventItemMap_.clear();
	}

	void 
	MonitorManager::ioThread(IOThread* ioThread)
	{
		ioThread_ = ioThread;
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

	void
	MonitorManager::forwardGlobalSync(ForwardGlobalSync::SPtr& forwardGlobalSync)
	{
		forwardGlobalSync_ = forwardGlobalSync;
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

			MonitoredItemCreateRequest::SPtr monitoredItemCreateRequest;
			if (createMonitorItemRequest->itemsToCreate()->get(idx, monitoredItemCreateRequest)) {
				OpcUaNodeId parameterTypeId;
				parameterTypeId = monitoredItemCreateRequest->requestedParameters().filter().parameterTypeId();

				if (parameterTypeId == OpcUaNodeId(OpcUaId_EventFilter_Encoding_DefaultBinary)) {

					createEventItem(idx, trx, createMonitorItemRequest, createMonitorItemResponse);
					continue;
				}
			}

			createMonitoredItem(idx, trx, createMonitorItemRequest, createMonitorItemResponse);
		}
		return Success;
	}

	void
	MonitorManager::createMonitoredItem(
		uint32_t idx,
		ServiceTransactionCreateMonitoredItems::SPtr& trx,
		CreateMonitoredItemsRequest::SPtr& createMonitorItemRequest,
		CreateMonitoredItemsResponse::SPtr& createMonitorItemResponse
	)
	{
		MonitoredItemCreateResult::SPtr monitoredItemCreateResult;
		monitoredItemCreateResult = constructSPtr<MonitoredItemCreateResult>();
		createMonitorItemResponse->results()->set(idx, monitoredItemCreateResult);

		// get request parameter
		MonitoredItemCreateRequest::SPtr monitoredItemCreateRequest;
		if (!createMonitorItemRequest->itemsToCreate()->get(idx, monitoredItemCreateRequest)) {
			monitoredItemCreateResult->statusCode(BadInvalidArgument);
			return;
		}

		// find base node class
		BaseNodeClass::SPtr baseNodeClass;
		baseNodeClass = informationModel_->find(monitoredItemCreateRequest->itemToMonitor().nodeId());
		if (baseNodeClass.get() == nullptr) {
			monitoredItemCreateResult->statusCode(BadNodeIdUnknown);
			return;
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
			return;
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
		ioThread_->slotTimer()->start(slotTimerElement);

		Log(Debug, "monitor item create")
			.parameter("MonitorId", monitorItem->monitorItemId())
			.parameter("Trx", trx->transactionId())
			.parameter("SessionId", trx->sessionId())
			.parameter("NodeId", monitoredItemCreateRequest->itemToMonitor().nodeId())
			.parameter("Subscription", createMonitorItemRequest->subscriptionId());
	}

	void
	MonitorManager::createEventItem(
		uint32_t idx,
		ServiceTransactionCreateMonitoredItems::SPtr& trx,
		CreateMonitoredItemsRequest::SPtr& createMonitorItemRequest,
		CreateMonitoredItemsResponse::SPtr& createMonitorItemResponse
	)
	{
		MonitoredItemCreateResult::SPtr monitoredItemCreateResult;
		monitoredItemCreateResult = constructSPtr<MonitoredItemCreateResult>();
		createMonitorItemResponse->results()->set(idx, monitoredItemCreateResult);

		// get request parameter
		MonitoredItemCreateRequest::SPtr monitoredItemCreateRequest;
		if (!createMonitorItemRequest->itemsToCreate()->get(idx, monitoredItemCreateRequest)) {
			monitoredItemCreateResult->statusCode(BadInvalidArgument);
			return;
		}

		// find base node class
		BaseNodeClass::SPtr baseNodeClass;
		baseNodeClass = informationModel_->find(monitoredItemCreateRequest->itemToMonitor().nodeId());
		if (baseNodeClass.get() == nullptr) {
			monitoredItemCreateResult->statusCode(BadNodeIdUnknown);
			return;
		}
		OpcUaQualifiedName browseName;
		baseNodeClass->getBrowseName(browseName);

		// create new event item
		EventItem::SPtr eventItem = constructSPtr<EventItem>();
		eventItem->informationModel(informationModel_);
		eventItem->browseName(browseName);
		OpcUaStatusCode statusCode = eventItem->receive(
			monitoredItemCreateRequest,
			monitoredItemCreateResult
		);

		if (statusCode != Success) {
			monitoredItemCreateResult->statusCode(statusCode);
			return;
		}

		// insert event item into event item map
		monitoredItemCreateResult->statusCode(Success);
		monitoredItemCreateResult->monitoredItemId(eventItem->eventItemId());
		monitoredItemCreateResult->revisedSamplingInterval(0);
		monitoredItemCreateResult->revisedQueueSize(0);
		eventItemMap_.insert(std::make_pair(eventItem->eventItemId(), eventItem));

		// forward start event item
		if (forwardGlobalSync_.get() != nullptr) {
			if (forwardGlobalSync_->eventItemStartService().isCallback()) {
				ApplicationEventItemStartContext context;
				context.applicationContext_ = forwardGlobalSync_->eventItemStartService().applicationContext();
				context.eventItemId_ = eventItem->eventItemId();

				forwardGlobalSync_->eventItemStartService().callback()(&context);
			}
		}

		Log(Debug, "event item create")
			.parameter("EventId", eventItem->eventItemId())
			.parameter("Trx", trx->transactionId())
			.parameter("SessionId", trx->sessionId())
			.parameter("NodeId", monitoredItemCreateRequest->itemToMonitor().nodeId())
			.parameter("Subscription", createMonitorItemRequest->subscriptionId());
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

			bool monitoredItem;

			// find monitor item in monitor map
			MonitorItemMap::iterator it1;
			EventItem::Map::iterator it2;
			it1 = monitorItemMap_.find(monitorItemId);
			if (it1 == monitorItemMap_.end()) {

				it2 = eventItemMap_.find(monitorItemId);
				if (it2 == eventItemMap_.end()) {
					deleteMonitorItemResponse->results()->set(idx, Success);
					continue;
				}
				monitoredItem = false;
			}
			else {
				monitoredItem = true;
			}

			if (monitoredItem) {
				// forward stop monitored item
				BaseNodeClass::SPtr baseNodeClass = it1->second->baseNodeClass();
				if (baseNodeClass.get() != nullptr) {
					forwardStopMonitoredItem(baseNodeClass, monitorItemId);
				}

				Log(Trace, "monitor item remove")
					.parameter("MonitorId", it1->second->monitorItemId())
					.parameter("Trx", trx->transactionId())
					.parameter("SessionId", trx->sessionId())
					.parameter("SubscriptionId", deleteMonitorItemRequest->subscriptionId());

				// stop sample timer an remove monitor item
				ioThread_->slotTimer()->stop(it1->second->slotTimerElement());
				monitorItemMap_.erase(it1);
				deleteMonitorItemResponse->results()->set(idx, Success);
			}
			else {
				// forward stop event item
				if (forwardGlobalSync_.get() != nullptr) {
					if (forwardGlobalSync_->eventItemStopService().isCallback()) {
						ApplicationEventItemStopContext context;
						context.applicationContext_ = forwardGlobalSync_->eventItemStopService().applicationContext();
						context.eventItemId_ = it2->second->eventItemId();

						forwardGlobalSync_->eventItemStopService().callback()(&context);
					}
				}

				Log(Trace, "event item remove")
					.parameter("EventId", it2->second->eventItemId())
					.parameter("Trx", trx->transactionId())
					.parameter("SessionId", trx->sessionId())
					.parameter("SubscriptionId", deleteMonitorItemRequest->subscriptionId());

				it2->second->erase();
				eventItemMap_.erase(it2);
			}
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

				ioThread_->slotTimer()->stop(monitorItem->slotTimerElement());
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

		if (numberNotifications == 0) {
			return Success;
		}

		monitoredItemNotificationArray->resize(numberNotifications);
		for (it = monitorItemMap_.begin(); it != monitorItemMap_.end(); it++) {
			OpcUaStatusCode statusCode = it->second->receive(monitoredItemNotificationArray);
			if (statusCode == BadOutOfMemory) {
				return statusCode;
			}
		}

		return Success;
	}

	OpcUaStatusCode
	MonitorManager::receive(EventFieldListArray::SPtr eventFieldListArray)
	{
		uint32_t numberNotifications = 0;
		EventItem::Map::iterator it;
		for (it = eventItemMap_.begin(); it != eventItemMap_.end(); it++) {
			numberNotifications += it->second->size();
		}

		if (numberNotifications == 0) {
			return Success;
		}

		eventFieldListArray->resize(numberNotifications);
		for (it = eventItemMap_.begin(); it != eventItemMap_.end(); it++) {
			OpcUaStatusCode statusCode = it->second->receive(eventFieldListArray);
			if (statusCode == BadOutOfMemory) {
				return statusCode;
			}
		}

		return Success;
	}

	void
	MonitorManager::forwardStartMonitoredItem(BaseNodeClass::SPtr baseNodeClass, uint32_t monitoredItemId)
	{
		ForwardNodeSync::SPtr forwardNodeSync = baseNodeClass->forwardNodeSync();
		if (forwardNodeSync.get() == nullptr) return;
		if (!forwardNodeSync->monitoredItemStartService().isCallback()) return;

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

		// create node reference
		NodeReferenceApplication::SPtr nodeReference = constructSPtr<NodeReferenceApplication>();
		nodeReference->statusCode(Success);
		nodeReference->baseNodeClass(baseNodeClass);

		// forward monitored item start
		ApplicationMonitoredItemStartContext context;
		context.nodeId_ = baseNodeClass->nodeId().data();
		context.applicationContext_ = forwardNodeSync->monitoredItemStartService().applicationContext();
		context.firstMonitoredItem_ = true;
		context.nodeReference_ = nodeReference;

		forwardNodeSync->monitoredItemStartService().callback()(&context);
	}

	void
	MonitorManager::forwardStopMonitoredItem(BaseNodeClass::SPtr baseNodeClass, uint32_t monitoredItemId)
	{
		ForwardNodeSync::SPtr forwardNodeSync = baseNodeClass->forwardNodeSync();
		if (forwardNodeSync.get() == nullptr) return;
		if (!forwardNodeSync->monitoredItemStopService().isCallback()) return;

		// find node id in item id map
		MonitoredItemIds::iterator it1;
		it1 = monitoredItemIds_.find(baseNodeClass->nodeId().data());
		if (it1 == monitoredItemIds_.end()) {
			// no monitored item exist
			return;
		}
		std::vector<uint32_t> monitoredItemIds = it1->second;

		// delete monitored item from list
		std::vector<uint32_t>::iterator it2;
		std::vector<uint32_t> newMonitoredItemIds;
		for (it2=monitoredItemIds.begin(); it2!=monitoredItemIds.end(); it2++) {
			if (*it2 != monitoredItemId) {
				newMonitoredItemIds.push_back(*it2);
			}
		}

		// check monitored item list
		if (newMonitoredItemIds.size() > 0) {
			monitoredItemIds_.insert(std::make_pair(baseNodeClass->nodeId().data(), monitoredItemIds));
			return;
		}

		// create node reference
		NodeReferenceApplication::SPtr nodeReference = constructSPtr<NodeReferenceApplication>();
		nodeReference->statusCode(Success);
		nodeReference->baseNodeClass(baseNodeClass);

		// forward monitored item stop
		ApplicationMonitoredItemStopContext context;
		context.nodeId_ = baseNodeClass->nodeId().data();
		context.applicationContext_ = forwardNodeSync->monitoredItemStopService().applicationContext();
		context.lastMonitoredItem_ = true;
		context.nodeReference_ = nodeReference;

		forwardNodeSync->monitoredItemStopService().callback()(&context);
	}

}
