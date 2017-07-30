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
	, eventHandler_(constructSPtr<EventHandler>())
	, nodeId_()
	, eventFieldListList_()
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
		// FIXME: lock...

		nodeId_ = *monitoredItemCreateRequest->itemToMonitor().nodeId();

		// get event filter
		EventFilter::SPtr eventFilter;
		eventFilter = monitoredItemCreateRequest->requestedParameters().filter().parameter<EventFilter>();
		if (eventFilter.get() == nullptr) {
			return BadInvalidArgument;
		}

		//
		// FIXME: construct filter stack
		//

		// register event handler
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
		std::cout << "EventItem::fireEvent" << std::endl;

		// FIXME: todo
		// process where clause
		// process select clause

		// FIXME: lock

		//
		//
		// FIXME: test code
		//
		//
		//

		OpcUaVariant::SPtr variant;
		EventField::SPtr eventField;

		EventFieldList::SPtr eventFieldList = constructSPtr<EventFieldList>();
		eventFieldList->clientHandle(4711);
		eventFieldList->eventFields()->resize(1);

		// event id (OpcUaByteString)
		OpcUaByteString::SPtr eventId = constructSPtr<OpcUaByteString>();
		eventId->value("EventId");
		variant = constructSPtr<OpcUaVariant>();
		variant->set(eventId);
		eventField = constructSPtr<EventField>();
		eventField->variant(variant);
		eventFieldList->eventFields()->push_back(eventField);

		// event type (OpcUaNodeId - 17)
		// local time (OpcUaDateTime)
		// message (OpcUaLocalizedText)
		// receive time (OpcUaDateTime)
		// severity (OpcUaUInt16)
		// source name (OpcUaString)
		// source node (OpcUaNodeId)
		// time (OpcUaDatetime)

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

}
