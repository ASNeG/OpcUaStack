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

		// init event handler
		eventHandler_->callback().reset(boost::bind(&EventItem::fireEvent, this, _1));

		EventHandlerBase::SPtr eventHandlerBase = boost::static_pointer_cast<EventHandlerBase>(eventHandler_);
		informationModel_->eventHandlerMap().registerEvent(nodeId_, eventHandlerBase);
		monitoredItemCreateResult->statusCode(Success);

		return Success;
	}

	uint32_t
	EventItem::eventItemId(void)
	{
		return eventItemId_;
	}

	void
	EventItem::clear(void)
	{
		informationModel_->eventHandlerMap().deregisterEvent(nodeId_, eventHandler_->eventId());
	}

	void
	EventItem::fireEvent(EventBase::SPtr eventBase)
	{
		std::cout << "EventItem::fireEvent" << std::endl;
	}


}
