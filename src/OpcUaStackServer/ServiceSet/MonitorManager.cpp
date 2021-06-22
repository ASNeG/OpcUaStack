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

   Autor: Kai Huebl (kai@huebl-sgh.de), Aleksey Timin (atimin@gmail.com)
 */

#include "OpcUaStackCore/Base/Log.h"
#include "OpcUaStackCore/Application/ApplicationAutorizationContext.h"
#include "OpcUaStackCore/Application/ApplicationMonitoredItemStartContext.h"
#include "OpcUaStackCore/Application/ApplicationMonitoredItemStopContext.h"
#include "OpcUaStackCore/Application/ApplicationEventItemStartContext.h"
#include "OpcUaStackCore/Application/ApplicationEventItemStopContext.h"
#include "OpcUaStackServer/ServiceSetApplication/NodeReferenceApplication.h"
#include "OpcUaStackServer/ServiceSet/MonitorManager.h"
#include "OpcUaStackServer/ServiceSet/EventItem.h"

using namespace OpcUaStackCore;

namespace OpcUaStackServer
{

	MonitorManager::MonitorManager(void)
	: monitorItemMap_()
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
		for (auto it : monitorItemMap_ ) {
			auto monitorItem = it.second;
		    if (monitorItem->baseNodeClass() != nullptr) {
		        forwardStopMonitoredItem(
		        	monitorItem->userContext(),
					monitorItem->baseNodeClass(),
					monitorItem->monitorItemId()
				);
		    }

			ioThread_->slotTimer()->stop(monitorItem->slotTimerElement());
			monitorItem->slotTimerElement().reset();
		}
		monitorItemMap_.clear();

		//
		// cleanup event item
		//
		for (auto it : eventItemMap_) {
		    EventItem::SPtr eventItem = it.second;

			// forward stop event item
			if (forwardGlobalSync_.get() != nullptr) {
				if (forwardGlobalSync_->eventItemStopService().isCallback()) {
					ApplicationEventItemStopContext context;
					context.applicationContext_ = forwardGlobalSync_->eventItemStopService().applicationContext();
					context.eventItemId_ = it.second->eventItemId();
					context.userContext_ = it.second->userContext();

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
	MonitorManager::strand(boost::shared_ptr<boost::asio::io_service::strand>& strand)
	{
		strand_ = strand;
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
		for (auto it = monitorItemMap_.begin(); it != monitorItemMap_.end(); it++) {
			notificationNumber += it->second->size();
		}
		return notificationNumber;
	}

	bool 
	MonitorManager::notificationAvailable(void)
	{
		for (auto it = monitorItemMap_.begin(); it != monitorItemMap_.end(); it++) {
			if (it->second->size() > 0) return true;
		}
		return false;
	}

	OpcUaStatusCode 
	MonitorManager::receive(ServiceTransactionCreateMonitoredItems::SPtr& trx)
	{
		auto createMonitorItemRequest = trx->request();
		auto createMonitorItemResponse = trx->response();

		auto size = createMonitorItemRequest->itemsToCreate()->size();
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
		OpcUaStatusCode statusCode;

		auto monitoredItemCreateResult = boost::make_shared<MonitoredItemCreateResult>();
		createMonitorItemResponse->results()->set(idx, monitoredItemCreateResult);

		// get request parameter
		MonitoredItemCreateRequest::SPtr monitoredItemCreateRequest;
		if (!createMonitorItemRequest->itemsToCreate()->get(idx, monitoredItemCreateRequest)) {
			monitoredItemCreateResult->statusCode().enumeration(BadInvalidArgument);
			return;
		}

		// autorization create monitored item request
		auto serviceTransaction = trx;
		auto& readValueId = monitoredItemCreateRequest->itemToMonitor();
		statusCode = forwardAutorizationCreateMonitoredItem(serviceTransaction->userContext(), readValueId);
		if (statusCode != Success) {
			monitoredItemCreateResult->statusCode().enumeration(statusCode);
			return;
		}

		// find base node class
		auto baseNodeClass = informationModel_->find(monitoredItemCreateRequest->itemToMonitor().nodeId());
		if (baseNodeClass.get() == nullptr) {
			monitoredItemCreateResult->statusCode().enumeration(BadNodeIdUnknown);
			return;
		}

		// check parameter
		if (monitoredItemCreateRequest->requestedParameters().samplingInterval() < 100) {
			monitoredItemCreateRequest->requestedParameters().samplingInterval(100);
		}
		if (monitoredItemCreateRequest->requestedParameters().queueSize() < 1) {
			monitoredItemCreateRequest->requestedParameters().queueSize(1);
		}

		// create new monitor item
		auto monitorItem = boost::make_shared<MonitorItem>();
		monitorItem->userContext(serviceTransaction->userContext());
		statusCode = monitorItem->receive(baseNodeClass, monitoredItemCreateRequest);

		if (statusCode != Success) {
			monitoredItemCreateResult->statusCode().enumeration(statusCode);
			return;
		}

		// insert monitor item into monitor item map
		monitoredItemCreateResult->statusCode().enumeration(Success);
		monitoredItemCreateResult->monitoredItemId() = monitorItem->monitorItemId();
		monitoredItemCreateResult->revisedSamplingInterval() = monitorItem->samplingInterval();
		monitoredItemCreateResult->revisedQueueSize() = monitorItem->queSize();
		monitorItemMap_.insert(std::make_pair(monitorItem->monitorItemId(), monitorItem));

		// forward start monitored item
		forwardStartMonitoredItem(
			monitorItem->userContext(),
			baseNodeClass,
			monitorItem->monitorItemId()
		);

		// start sample timer
		auto slotTimerElement = monitorItem->slotTimerElement();
		slotTimerElement->interval(monitorItem->samplingInterval());
		slotTimerElement->timeoutCallback(
			strand_,
			[this, monitorItem](void) {
				sampleTimeout(monitorItem);
		    }
		);
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
		OpcUaStatusCode statusCode;

		auto monitoredItemCreateResult = boost::make_shared<MonitoredItemCreateResult>();
		createMonitorItemResponse->results()->set(idx, monitoredItemCreateResult);

		// get request parameter
		MonitoredItemCreateRequest::SPtr monitoredItemCreateRequest;
		if (!createMonitorItemRequest->itemsToCreate()->get(idx, monitoredItemCreateRequest)) {
			monitoredItemCreateResult->statusCode().enumeration(BadInvalidArgument);
			return;
		}

		// autorization create event item request
		auto serviceTransaction = trx;
		auto& readValueId = monitoredItemCreateRequest->itemToMonitor();
		statusCode = forwardAutorizationCreateEventItem(serviceTransaction->userContext(), readValueId);
		if (statusCode != Success) {
			monitoredItemCreateResult->statusCode().enumeration(statusCode);
			return;
		}

		// find base node class
		auto baseNodeClass = informationModel_->find(monitoredItemCreateRequest->itemToMonitor().nodeId());
		if (baseNodeClass.get() == nullptr) {
			monitoredItemCreateResult->statusCode().enumeration(BadNodeIdUnknown);
			return;
		}
		OpcUaQualifiedName browseName;
		baseNodeClass->getBrowseName(browseName);

		// create new event item
		auto eventItem = boost::make_shared<EventItem>();
		eventItem->userContext(serviceTransaction->userContext());
		eventItem->informationModel(informationModel_);
		eventItem->browseName(browseName);
		statusCode = eventItem->receive(
			monitoredItemCreateRequest,
			monitoredItemCreateResult
		);

		if (statusCode != Success) {
			monitoredItemCreateResult->statusCode().enumeration(statusCode);
			return;
		}

		// insert event item into event item map
		monitoredItemCreateResult->statusCode().enumeration(Success);
		monitoredItemCreateResult->monitoredItemId() = eventItem->eventItemId();
		monitoredItemCreateResult->revisedSamplingInterval() = 0;
		monitoredItemCreateResult->revisedQueueSize() = 0;
		eventItemMap_.insert(std::make_pair(eventItem->eventItemId(), eventItem));

		// forward start event item
		if (forwardGlobalSync_.get() != nullptr) {
			if (forwardGlobalSync_->eventItemStartService().isCallback()) {
				ApplicationEventItemStartContext context;
				context.applicationContext_ = forwardGlobalSync_->eventItemStartService().applicationContext();
				context.eventItemId_ = eventItem->eventItemId();
				context.userContext_ = eventItem->userContext();

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
	MonitorManager::receive(ServiceTransactionDeleteMonitoredItems::SPtr& trx)
	{
		auto deleteMonitorItemRequest = trx->request();
		auto deleteMonitorItemResponse = trx->response();

		auto size = deleteMonitorItemRequest->monitoredItemIds()->size();
		deleteMonitorItemResponse->results()->resize(size);
		
		for (uint32_t idx=0; idx<size; idx++) {
			
			// get monitor id
			uint32_t monitorItemId;
			if (!deleteMonitorItemRequest->monitoredItemIds()->get(idx, monitorItemId)) {
				deleteMonitorItemResponse->results()->set(idx, BadInvalidArgument);
				continue;
			}

			bool monitoredItem;

			// find monitor item or event item in monitor map
			EventItem::Map::iterator it2;
			auto it1 = monitorItemMap_.find(monitorItemId);
			if (it1 == monitorItemMap_.end()) {

				it2 = eventItemMap_.find(monitorItemId);
				if (it2 == eventItemMap_.end()) {
					deleteMonitorItemResponse->results()->set(idx, BadNothingToDo);
					continue;
				}
				monitoredItem = false;
			}
			else {
				monitoredItem = true;
			}

			if (monitoredItem) {
				// forward stop monitored item
				auto baseNodeClass = it1->second->baseNodeClass();
				if (baseNodeClass.get() != nullptr) {
					forwardStopMonitoredItem(
						it1->second->userContext(),
						baseNodeClass,
						monitorItemId
					);
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
						context.userContext_ = it2->second->userContext();

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
				deleteMonitorItemResponse->results()->set(idx, Success);
			}
		}

		return Success;
	}

	OpcUaStatusCode 
	MonitorManager::receive(ServiceTransactionModifyMonitoredItems::SPtr& trx)
	{
		return BadNotImplemented;
	}

	OpcUaStatusCode 
	MonitorManager::receive(ServiceTransactionSetMonitoringMode::SPtr& trx)
	{
		return BadNotImplemented;
	}

	OpcUaStatusCode 
	MonitorManager::receive(ServiceTransactionSetTriggering::SPtr& trx)
	{
		return BadNotImplemented;
	}

	void 
	MonitorManager::sampleTimeout(MonitorItem::SPtr monitorItem)
	{
		auto sampleResult = monitorItem->sample();
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
	MonitorManager::receive(MonitoredItemNotificationArray& monitoredItemNotificationArray)
	{
		uint32_t numberNotifications = 0;
		MonitorItemMap::iterator it;
		for (it = monitorItemMap_.begin(); it != monitorItemMap_.end(); it++) {
			numberNotifications += it->second->size();
		}

		if (numberNotifications == 0) {
			return Success;
		}

		monitoredItemNotificationArray.resize(numberNotifications);
		for (it = monitorItemMap_.begin(); it != monitorItemMap_.end(); it++) {
			OpcUaStatusCode statusCode = it->second->receive(monitoredItemNotificationArray);
			if (statusCode == BadOutOfMemory) {
				return statusCode;
			}
		}

		return Success;
	}

	OpcUaStatusCode
	MonitorManager::receive(EventFieldListArray& eventFieldListArray)
	{
		uint32_t numberNotifications = 0;
		for (auto it = eventItemMap_.begin(); it != eventItemMap_.end(); it++) {
			numberNotifications += it->second->size();
		}

		if (numberNotifications == 0) {
			return Success;
		}

		eventFieldListArray.resize(numberNotifications);
		for (auto it = eventItemMap_.begin(); it != eventItemMap_.end(); it++) {
			auto statusCode = it->second->receive(eventFieldListArray);
			if (statusCode == BadOutOfMemory) {
				return statusCode;
			}
		}

		return Success;
	}

	void
	MonitorManager::forwardStartMonitoredItem(
		UserContext::SPtr& userContext,
		BaseNodeClass::SPtr baseNodeClass,
		uint32_t monitoredItemId
	)
	{
		// find node id in item id map
		auto it = monitoredItemIds_.find(baseNodeClass->nodeId().data());
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
		NodeReferenceApplication::SPtr nodeReference = boost::make_shared<NodeReferenceApplication>();
		nodeReference->statusCode(Success);
		nodeReference->baseNodeClass(baseNodeClass);


        ForwardNodeSync::SPtr forwardNodeSync = baseNodeClass->forwardNodeSync();
        if (forwardNodeSync && forwardNodeSync->monitoredItemStartService().isCallback()) {
            // forward monitored item start
            ApplicationMonitoredItemStartContext context;
            context.nodeId_ = baseNodeClass->nodeId().data();
            context.applicationContext_ = forwardNodeSync->monitoredItemStartService().applicationContext();
            context.firstMonitoredItem_ = true;
            context.nodeReference_ = nodeReference;
            context.userContext_ = userContext;

            forwardNodeSync->monitoredItemStartService().callback()(&context);
        }
	}

	void
	MonitorManager::forwardStopMonitoredItem(
		UserContext::SPtr& userContext,
		BaseNodeClass::SPtr baseNodeClass,
		uint32_t monitoredItemId
	)
	{
		// find node id in item id map
		auto it1 = monitoredItemIds_.find(baseNodeClass->nodeId().data());
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
		monitoredItemIds_.erase(it1);
		if (newMonitoredItemIds.size() > 0) {
			monitoredItemIds_.insert(std::make_pair(baseNodeClass->nodeId().data(), newMonitoredItemIds));
			return;
		}

		// create node reference
		NodeReferenceApplication::SPtr nodeReference = boost::make_shared<NodeReferenceApplication>();
		nodeReference->statusCode(Success);
		nodeReference->baseNodeClass(baseNodeClass);

        ForwardNodeSync::SPtr forwardNodeSync = baseNodeClass->forwardNodeSync();
        if (forwardNodeSync && forwardNodeSync->monitoredItemStopService().isCallback()) {
            // forward monitored item stop
            ApplicationMonitoredItemStopContext context;
            context.nodeId_ = baseNodeClass->nodeId().data();
            context.applicationContext_ = forwardNodeSync->monitoredItemStopService().applicationContext();
            context.lastMonitoredItem_ = true;
            context.nodeReference_ = nodeReference;
            context.userContext_ = userContext;

            forwardNodeSync->monitoredItemStopService().callback()(&context);
        }
	}

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// autorization
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	OpcUaStatusCode
	MonitorManager::forwardAutorizationCreateMonitoredItem(UserContext::SPtr& userContext, ReadValueId& readValueId)
	{
		if (forwardGlobalSync_.get() == nullptr) return Success;
		if (!forwardGlobalSync_->autorizationService().isCallback()) return Success;

		ApplicationAutorizationContext context;
		context.userContext_ = userContext;
		context.serviceOperation_ = ServiceOperation::MonitoredItem;
		context.nodeId_ = *readValueId.nodeId();
		context.attributeId_ = AttributeId::AttributeId_Value;

		forwardGlobalSync_->autorizationService().callback()(&context);

		return context.statusCode_;
	}

	OpcUaStatusCode
	MonitorManager::forwardAutorizationCreateEventItem(UserContext::SPtr& userContext, ReadValueId& readValueId)
	{
		if (forwardGlobalSync_.get() == nullptr) return Success;
		if (!forwardGlobalSync_->autorizationService().isCallback()) return Success;

		ApplicationAutorizationContext context;
		context.userContext_ = userContext;
		context.serviceOperation_ = ServiceOperation::EventItem;
		context.nodeId_ = *readValueId.nodeId();
		context.attributeId_ = AttributeId::AttributeId_Value;

		forwardGlobalSync_->autorizationService().callback()(&context);

		return context.statusCode_;
	}

    MonitorManager::MonitoredItemIdVector
	MonitorManager::monitoredItemIds()
	{
        return monitoredItemIds_;
	}

}
