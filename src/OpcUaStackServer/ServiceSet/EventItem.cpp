/*
   Copyright 2017 Kai Huebl (kai@huebl-sgh.de)

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
#include "OpcUaStackCore/ServiceSet/EventFilter.h"
#include "OpcUaStackServer/ServiceSet/EventItem.h"
#include "OpcUaStackServer/ServiceSet/MonitorItemId.h"

namespace OpcUaStackServer
{


	EventItem::EventItem(void)
	: eventItemId_(MonitorItemId::monitorItemId())
	, informationModel_()
	, whereFilter_()
	, selectClauses_()
	, eventHandler_(constructSPtr<EventHandler>())
	, nodeId_()
	, eventFieldListList_()
	, clientHandle_(0)
	{
	}

	EventItem::~EventItem(void)
	{
		clear();
	}

	void
	EventItem::informationModel(InformationModel::SPtr& informationModel)
	{
		informationModel_ = informationModel;
	}

	OpcUaStatusCode
	EventItem::receive(
		MonitoredItemCreateRequest::SPtr& monitoredItemCreateRequest,
		MonitoredItemCreateResult::SPtr& monitoredItemCreateResult
	)
	{
		OpcUaStatusCode statusCode;

		nodeId_ = *monitoredItemCreateRequest->itemToMonitor().nodeId();
		clientHandle_ = monitoredItemCreateRequest->requestedParameters().clientHandle();

		// get event filter
		EventFilter::SPtr eventFilter;
		eventFilter = monitoredItemCreateRequest->requestedParameters().filter().parameter<EventFilter>();
		if (eventFilter.get() == nullptr) {
			return BadInvalidArgument;
		}

		// select clause
		SimpleAttributeOperandArray::SPtr selectClauses = eventFilter->selectClauses();
		OpcUaStatusCodeArray::SPtr statusCodeArray = monitoredItemCreateResult->filterResult().parameter<EventFilterResult>()->selectClauseResults();
		statusCode = receive(selectClauses, statusCodeArray);
		if (statusCode != Success) {
			monitoredItemCreateResult->statusCode(statusCode);
			return statusCode;
		}

		// construct where filter
		whereFilter_ = constructSPtr<FilterStack>();
		statusCode = whereFilter_->receive(eventFilter->whereClause(), monitoredItemCreateResult->filterResult().parameter<EventFilterResult>()->whereClauseResult());
		if (statusCode != Success) {
			monitoredItemCreateResult->statusCode(statusCode);
			return statusCode;
		}

		// register event handler
		// FIXME: lock...
		EventHandlerMap& eventHandlerMap = informationModel_->eventHandlerMap();
		boost::mutex::scoped_lock g(eventHandlerMap.mutex());
		eventHandler_->callback().reset(boost::bind(&EventItem::fireEvent, this, _1));
		EventHandlerBase::SPtr eventHandlerBase = boost::static_pointer_cast<EventHandlerBase>(eventHandler_);
		eventHandlerMap.registerEvent(nodeId_, eventHandlerBase);

		monitoredItemCreateResult->statusCode(Success);

		return Success;
	}

	uint32_t
	EventItem::size(void)
	{
		return eventFieldListList_.size();
	}

	uint32_t
	EventItem::eventItemId(void)
	{
		return eventItemId_;
	}

	void
	EventItem::clear(void)
	{
		EventHandlerMap& eventHandlerMap = informationModel_->eventHandlerMap();
		boost::mutex::scoped_lock g(eventHandlerMap.mutex());
		eventHandlerMap.deregisterEvent(nodeId_, eventHandler_->eventId());
	}

	void
	EventItem::fireEvent(EventBase::SPtr eventBase)
	{
		// FIXME: lock

		// check event
		if (eventBase.get() == nullptr) {
			return;
		}

		// map namespace
		// FIXME: todo

		// process select clause
		whereFilter_->simpleAttributeIf(eventBase.get());

		bool resultCode;
		if (!whereFilter_->process(resultCode)) {
			Log(Error, "processEventFilter error");
			return;
		}
		if (!resultCode) {
			// ignore event
			return;
		}

		// process where clause
		EventFieldList::SPtr eventFieldList = constructSPtr<EventFieldList>();
		eventFieldList->clientHandle(clientHandle_);
		eventFieldList->eventFields()->resize(selectClauses_->size());

		for (uint32_t idx=0; idx<selectClauses_->size(); idx++) {

			// get simple attribute operand
			SimpleAttributeOperand::SPtr simpleAttributeOperand;
			selectClauses_->get(idx, simpleAttributeOperand);

			std::list<OpcUaQualifiedName::SPtr> browseNameList;
			for (uint32_t j=0; j<simpleAttributeOperand->browsePath()->size(); j++) {
				OpcUaQualifiedName::SPtr browseName;
				simpleAttributeOperand->browsePath()->get(j, browseName);
				browseNameList.push_back(browseName);
			}

			// get variant value from event
			OpcUaVariant::SPtr value = constructSPtr<OpcUaVariant>();
			EventBase::ResultCode resultCode = eventBase->get(
				simpleAttributeOperand->typeId(),
				browseNameList,
				value
			);

			// insert variant into event field list
			EventField::SPtr eventField;
			eventField = constructSPtr<EventField>();
			if (resultCode == EventBase::Success) {
				eventField->variant(value);
			}
			eventFieldList->eventFields()->push_back(eventField);
		}

		eventFieldListList_.push_back(eventFieldList);
	}

	OpcUaStatusCode
	EventItem::receive(EventFieldListArray::SPtr eventFieldListArray)
	{
		// FIXME: lock

		uint32_t freeSize = eventFieldListArray->freeSize();
		do {
			if (eventFieldListList_.size() == 0) return Success;
			if (freeSize == 0) return BadOutOfMemory;
			freeSize--;

			eventFieldListArray->push_back(eventFieldListList_.front());
			eventFieldListList_.pop_front();
		} while (true);

		return Success;
	}

	OpcUaStatusCode
	EventItem::receive(SimpleAttributeOperandArray::SPtr& selectClauses, OpcUaStatusCodeArray::SPtr& statusCodeArray)
	{
		if (selectClauses.get() == nullptr) {
			return BadContentFilterInvalid;
		}
		if (selectClauses->size() == 0) {
			return BadContentFilterInvalid;
		}

		selectClauses_ = selectClauses;
		for (uint32_t idx=0; idx<selectClauses->size(); idx++) {
			// FIXME: check if attributes exist in type system
		}

		return Success;
	}


}
