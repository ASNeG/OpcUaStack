/*
   Copyright 2017-2021 Kai Huebl (kai@huebl-sgh.de)

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
#include "OpcUaStackCore/StandardDataTypes/EventFilter.h"
#include "OpcUaStackCore/StandardEventType/BaseEventType.h"
#include "OpcUaStackServer/NodeSet/NodeSetNamespace.h"
#include "OpcUaStackServer/ServiceSet/EventItem.h"
#include "OpcUaStackServer/ServiceSet/MonitorItemId.h"

using namespace OpcUaStackCore;

namespace OpcUaStackServer
{


	EventItem::EventItem(void)
	: eventItemId_(MonitorItemId::monitorItemId())
	, informationModel_()
	, whereFilter_()
	, selectClauses_()
	, eventHandler_(boost::make_shared<EventHandler>())
	, nodeId_()
	, browseName_()
	, eventFieldListList_()
	, clientHandle_(0)
	, eventBase_()
	, userContext_()
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

		auto eventFilterResult = boost::make_shared<EventFilterResult>();

		// select clause
		SimpleAttributeOperandArray& selectClauses = eventFilter->selectClauses();
		OpcUaStatusArray& selectClauseResults = eventFilterResult->selectClauseResults();
		statusCode = receive(selectClauses, selectClauseResults);
		if (statusCode != Success) {
			monitoredItemCreateResult->statusCode().enumeration(statusCode);
			return statusCode;
		}

		// construct where filter
		whereFilter_ = boost::make_shared<FilterStack>();
		whereFilter_->simpleAttributeIf(this);
		if (eventFilter->whereClause().elements().size() != 0) {
			bool whereFilterIsValid = whereFilter_->receive(eventFilter->whereClause(), eventFilterResult->whereClauseResult());
			if (!whereFilterIsValid) {
				statusCode = OpcUaStatusCode::BadMonitoredItemFilterInvalid;
				monitoredItemCreateResult->statusCode().enumeration(statusCode);
				return statusCode;
			}
		}

		// register event handler
		EventHandler::EventCallback eventCallback = boost::bind(&EventItem::fireEvent, this, boost::placeholders::_1);
		EventHandlerMap& eventHandlerMap = informationModel_->eventHandlerMap();
		eventHandler_->eventCallback(eventCallback);
		eventHandler_->eventId(eventItemId_);
		EventHandlerBase::SPtr eventHandlerBase = boost::static_pointer_cast<EventHandlerBase>(eventHandler_);

		boost::mutex::scoped_lock g(eventHandlerMap.mutex());
		eventHandlerMap.registerEvent(nodeId_, eventHandlerBase);

		monitoredItemCreateResult->statusCode().enumeration(Success);

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
	EventItem::fireEvent(EventBase::SPtr& eventBase)
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

			auto variant = boost::make_shared<OpcUaVariant>();
			variant->setValue(byteString);

			baseEventType->eventId(variant);
		}

		// set source node id if necessary
		if (baseEventType->sourceNode().get() == nullptr) {
			OpcUaVariant::SPtr variant = boost::make_shared<OpcUaVariant>();
			variant->setValue(nodeId_);
			baseEventType->sourceNode(variant);
		}

		// set source name if necessary
		if (baseEventType->sourceName().get() == nullptr) {
			OpcUaVariant::SPtr variant = boost::make_shared<OpcUaVariant>();
			variant->setValue(browseName_.name());
			baseEventType->sourceName(variant);
		}

		// set time if necessary
		if (baseEventType->time().get() == nullptr) {
			OpcUaVariant::SPtr variant = boost::make_shared<OpcUaVariant>();
			variant->setValue(OpcUaDateTime(now));
			baseEventType->time(variant);
		}

		// set receive time if necessary
		if (baseEventType->receiveTime().get() == nullptr) {
			OpcUaVariant::SPtr variant = boost::make_shared<OpcUaVariant>();
			variant->setValue(OpcUaDateTime(now));
			baseEventType->receiveTime(variant);
		}

		// set message if necessary
		if (baseEventType->message().get() == nullptr) {
			OpcUaVariant::SPtr variant = boost::make_shared<OpcUaVariant>();
			variant->setValue(OpcUaLocalizedText("", browseName_.name().toStdString()));
			baseEventType->message(variant);
		}

		// set severity if necessary
		if (baseEventType->severity().get() == nullptr) {
			OpcUaVariant::SPtr variant = boost::make_shared<OpcUaVariant>();
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
		auto eventFieldList = boost::make_shared<EventFieldList>();
		eventFieldList->clientHandle() = clientHandle_;
		eventFieldList->eventFields().resize(selectClauses_.size());

		for (uint32_t idx=0; idx<selectClauses_.size(); idx++) {

			// get simple attribute operand
			SimpleAttributeOperand::SPtr simpleAttributeOperand;
			selectClauses_.get(idx, simpleAttributeOperand);

			std::list<OpcUaQualifiedName::SPtr> browseNameList;
			for (uint32_t j=0; j<simpleAttributeOperand->browsePath().size(); j++) {
				OpcUaQualifiedName::SPtr browseName;
				simpleAttributeOperand->browsePath().get(j, browseName);
				browseNameList.push_back(browseName);
			}

			// get variant value from event
			auto typeId = simpleAttributeOperand->typeDefinitionId();
			if (typeId == OpcUaNodeId(0)) {
				typeId = OpcUaNodeId(2041);
			}

			OpcUaVariant::SPtr value;
			EventResult::Code resultCode = eventBase->get(
				typeId,
				browseNameList,
				value
			);

			// insert variant into event field list
			if (resultCode != EventResult::Success) {
				value = boost::make_shared<OpcUaVariant>();
			}
			else {
			}
			eventFieldList->eventFields().push_back(value);
		}

		boost::mutex::scoped_lock g(eventFieldListListMutex_);
		eventFieldListList_.push_back(eventFieldList);
	}

	OpcUaStatusCode
	EventItem::receive(EventFieldListArray& eventFieldListArray)
	{
		boost::mutex::scoped_lock g(eventFieldListListMutex_);
		uint32_t freeSize = eventFieldListArray.freeSize();
		do {
			if (eventFieldListList_.size() == 0) return Success;
			if (freeSize == 0) return BadOutOfMemory;
			freeSize--;

			eventFieldListArray.push_back(eventFieldListList_.front());
			eventFieldListList_.pop_front();
		} while (true);

		return Success;
	}

	OpcUaStatusCode
	EventItem::receive(SimpleAttributeOperandArray& selectClauses, OpcUaStatusArray& statusArray)
	{
		if (selectClauses.size() == 0) {
			return BadContentFilterInvalid;
		}

		selectClauses.copyTo(selectClauses_);

		statusArray.resize(selectClauses.size());
		for (uint32_t idx=0; idx<selectClauses.size(); idx++) {
			// FIXME: check if attributes exist in type system

			OpcUaStatus::SPtr status = boost::make_shared<OpcUaStatus>();
			status->enumeration(Success);
			statusArray.set(idx, status);
		}

		return Success;
	}

	void
	EventItem::userContext(UserContext::SPtr& userContext)
	{
		userContext_ = userContext;
	}

	UserContext::SPtr&
	EventItem::userContext(void)
	{
		return userContext_;
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
