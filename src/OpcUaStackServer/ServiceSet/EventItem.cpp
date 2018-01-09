/*
   Copyright 2017-2018 Kai Huebl (kai@huebl-sgh.de)

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

#include <iostream>
#include "OpcUaStackCore/Base/Log.h"
#include "OpcUaStackCore/ServiceSet/EventFilter.h"
#include "OpcUaStackCore/StandardEventType/BaseEventType.h"
#include "OpcUaStackServer/NodeSet/NodeSetNamespace.h"
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
	, browseName_()
	, eventFieldListList_()
	, clientHandle_(0)
	, eventBase_()
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

	void
	EventItem::browseName(OpcUaQualifiedName& browseName)
	{
		browseName.copyTo(browseName_);
	}

	OpcUaStatusCode
	EventItem::receive(
		MonitoredItemCreateRequest::SPtr& monitoredItemCreateRequest,
		MonitoredItemCreateResult::SPtr& monitoredItemCreateResult
	)
	{
		OpcUaStatusCode statusCode;

		if (monitoredItemCreateRequest.get() == nullptr) {
			return BadInvalidArgument;
		}
		if (monitoredItemCreateResult.get() == nullptr) {
			return BadInvalidArgument;
		}

		nodeId_ = *monitoredItemCreateRequest->itemToMonitor().nodeId();
		clientHandle_ = monitoredItemCreateRequest->requestedParameters().clientHandle();

		// get event filter
		EventFilter::SPtr eventFilter;
		eventFilter = monitoredItemCreateRequest->requestedParameters().filter().parameter<EventFilter>();
		if (eventFilter.get() == nullptr) {
			return BadInvalidArgument;
		}

		// create event filter result
		//EventFilterResult::SPtr eventFilterResult = monitoredItemCreateResult->filterResult().parameter<EventFilterResult>(OpcUaId_EventFilterResult_Encoding_DefaultBinary);

		EventFilterResult::SPtr eventFilterResult = constructSPtr<EventFilterResult>();

		// select clause
		SimpleAttributeOperandArray::SPtr selectClauses = eventFilter->selectClauses();
		OpcUaStatusCodeArray::SPtr selectClauseResults = eventFilterResult->selectClauseResults();
		statusCode = receive(selectClauses, selectClauseResults);
		if (statusCode != Success) {
			monitoredItemCreateResult->statusCode(statusCode);
			return statusCode;
		}

		// construct where filter
		whereFilter_ = constructSPtr<FilterStack>();
		whereFilter_->simpleAttributeIf(this);
		if (eventFilter->whereClause().elements()->size() != 0) {
			bool whereFilterIsValid = whereFilter_->receive(eventFilter->whereClause(), eventFilterResult->whereClauseResult());
			if (!whereFilterIsValid) {
				statusCode = OpcUaStatusCode::BadMonitoredItemFilterInvalid;
				monitoredItemCreateResult->statusCode(statusCode);
				return statusCode;
			}
		}

		// register event handler
		EventHandlerMap& eventHandlerMap = informationModel_->eventHandlerMap();
		eventHandler_->callback().reset(boost::bind(&EventItem::fireEvent, this, _1));
		eventHandler_->eventId(eventItemId_);
		EventHandlerBase::SPtr eventHandlerBase = boost::static_pointer_cast<EventHandlerBase>(eventHandler_);

		boost::mutex::scoped_lock g(eventHandlerMap.mutex());
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
	EventItem::erase(void)
	{
		clear();
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
		boost::posix_time::ptime now = boost::posix_time::microsec_clock::universal_time();
		BaseEventType::SPtr baseEventType = boost::static_pointer_cast<BaseEventType>(eventBase);
		// FIXME: lock

		// check event
		if (eventBase.get() == nullptr) {
			return;
		}

		// map namespace
		NodeSetNamespace nodeSetNamespace;
		eventBase->namespaceArray(&nodeSetNamespace.globalNamespaceVec());

		// generate event id if necessary
		if (baseEventType->eventId().get() == nullptr) {
			boost::posix_time::ptime time = boost::posix_time::microsec_clock::local_time();

			OpcUaByteString byteString;
			byteString.value((char*)&time, sizeof(boost::posix_time::ptime));

			OpcUaVariant::SPtr variant = constructSPtr<OpcUaVariant>();
			variant->setValue(byteString);

			baseEventType->eventId(variant);
		}

		// set source node id if necessary
		if (baseEventType->sourceNode().get() == nullptr) {
			OpcUaVariant::SPtr variant = constructSPtr<OpcUaVariant>();
			variant->setValue(nodeId_);
			baseEventType->sourceNode(variant);
		}

		// set source name if necessary
		if (baseEventType->sourceName().get() == nullptr) {
			OpcUaVariant::SPtr variant = constructSPtr<OpcUaVariant>();
			variant->setValue(browseName_.name());
			baseEventType->sourceName(variant);
		}

		// set time if necessary
		if (baseEventType->time().get() == nullptr) {
			OpcUaVariant::SPtr variant = constructSPtr<OpcUaVariant>();
			variant->setValue(OpcUaDateTime(now));
			baseEventType->time(variant);
		}

		// set receive time if necessary
		if (baseEventType->time().get() == nullptr) {
			OpcUaVariant::SPtr variant = constructSPtr<OpcUaVariant>();
			variant->setValue(OpcUaDateTime(now));
			baseEventType->receiveTime(variant);
		}

		// set message if necessary
		if (baseEventType->time().get() == nullptr) {
			OpcUaVariant::SPtr variant = constructSPtr<OpcUaVariant>();
			variant->setValue(OpcUaLocalizedText("", browseName_.name().toStdString()));
			baseEventType->message(variant);
		}

		// set severity if necessary
		if (baseEventType->time().get() == nullptr) {
			OpcUaVariant::SPtr variant = constructSPtr<OpcUaVariant>();
			variant->setValue((OpcUaUInt16)100);
			baseEventType->severity(variant);
		}

		// process select clause
		bool resultCode;
		eventBase_ = eventBase;
	    bool rc = whereFilter_->process(resultCode);
	    eventBase_.reset();
		if (!rc) {
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
			OpcUaVariant::SPtr value;
			EventResult::Code resultCode = eventBase->get(
				simpleAttributeOperand->typeId(),
				browseNameList,
				value
			);

			// insert variant into event field list
			EventField::SPtr eventField;
			eventField = constructSPtr<EventField>();
			if (resultCode != EventResult::Success) {
				value = constructSPtr<OpcUaVariant>();

			}
			else {
			}
			eventField->variant(value);
			eventFieldList->eventFields()->push_back(eventField);
		}

		boost::mutex::scoped_lock g(eventFieldListListMutex_);
		eventFieldListList_.push_back(eventFieldList);
	}

	OpcUaStatusCode
	EventItem::receive(EventFieldListArray::SPtr eventFieldListArray)
	{
		boost::mutex::scoped_lock g(eventFieldListListMutex_);
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
		statusCodeArray = constructSPtr<OpcUaStatusCodeArray>();
		statusCodeArray->resize(selectClauses->size());
		for (uint32_t idx=0; idx<selectClauses->size(); idx++) {
			// FIXME: check if attributes exist in type system

			statusCodeArray->set(idx, (OpcUaStatusCode)Success);
		}

		return Success;
	}


	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
    bool
	EventItem::getAttribute(
        OpcUaNodeId& typeId,
		std::list<OpcUaQualifiedName::SPtr>& browsePath,
		OpcUaUInt32 attributeId,
		OpcUaString& numericRange,
		OpcUaVariant& value
	)
    {
    	if (eventBase_.get() == nullptr) {
    		return false;
    	}

    	return eventBase_->getAttribute(
    		typeId, browsePath, attributeId, numericRange, value
    	);
    }

}
