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

#include "OpcUaStackCore/StandardEventType/BaseEventType.h"
#include "OpcUaStackCore/Base/Log.h"

namespace OpcUaStackCore
{

	BaseEventType::BaseEventType(void)
	: EventBase()
	, eventVariables_()
	{
		eventVariables_.registerEventVariable("EventId", OpcUaBuildInType_OpcUaByteString);
		eventVariables_.registerEventVariable("EventType", OpcUaBuildInType_OpcUaNodeId);
		eventVariables_.registerEventVariable("SourceName", OpcUaBuildInType_OpcUaString);
		eventVariables_.registerEventVariable("LocalTime", OpcUaBuildInType_OpcUaDateTime);
		eventVariables_.registerEventVariable("Message", OpcUaBuildInType_OpcUaLocalizedText);
		eventVariables_.registerEventVariable("ReceiveTime", OpcUaBuildInType_OpcUaDateTime);
		eventVariables_.registerEventVariable("Severity", OpcUaBuildInType_OpcUaUInt16);
		eventVariables_.registerEventVariable("SourceNode", OpcUaBuildInType_OpcUaNodeId);
		eventVariables_.registerEventVariable("Time", OpcUaBuildInType_OpcUaDateTime);

		eventVariables_.eventType(OpcUaNodeId((OpcUaUInt32)2041));
		eventVariables_.namespaceIndex(0);
		eventVariables_.browseName(OpcUaQualifiedName("BaseEventType"));
		eventVariables_.namespaceUri("");
	}

	BaseEventType::~BaseEventType(void)
	{
	}

	bool
	BaseEventType::eventId(OpcUaVariant::SPtr& eventId)
	{
		return eventVariables_.setValue("EventId", eventId);
	}

	OpcUaVariant::SPtr
	BaseEventType::eventId(void)
	{
		OpcUaVariant::SPtr value;
		eventVariables_.getValue("EventId", value);
		return value;
	}

	bool
	BaseEventType::eventType(OpcUaVariant::SPtr& eventType)
	{
		return eventVariables_.setValue("EventType", eventType);
	}

	OpcUaVariant::SPtr
	BaseEventType::eventType(void)
	{
		OpcUaVariant::SPtr value;
		eventVariables_.getValue("EventType", value);
		return value;
	}

	bool
	BaseEventType::sourceName(OpcUaVariant::SPtr& sourceName)
	{
		return eventVariables_.setValue("SourceName", sourceName);
	}

	OpcUaVariant::SPtr
	BaseEventType::sourceName(void)
	{
		OpcUaVariant::SPtr value;
		eventVariables_.getValue("SourceName", value);
		return value;
	}

	bool
	BaseEventType::localTime(OpcUaVariant::SPtr& localTime)
	{
		return eventVariables_.setValue("LocalTime", localTime);
	}

	OpcUaVariant::SPtr
	BaseEventType::localTime(void)
	{
		OpcUaVariant::SPtr value;
		eventVariables_.getValue("LocalTime", value);
		return value;
	}

	bool
	BaseEventType::message(OpcUaVariant::SPtr& message)
	{
		return eventVariables_.setValue("Message", message);
	}

	OpcUaVariant::SPtr
	BaseEventType::message(void)
	{
		OpcUaVariant::SPtr value;
		eventVariables_.getValue("Message", value);
		return value;
	}

	bool
	BaseEventType::receiveTime(OpcUaVariant::SPtr& receiveTime)
	{
		return eventVariables_.setValue("ReceiveTime", receiveTime);
	}

	OpcUaVariant::SPtr
	BaseEventType::receiveTime(void)
	{
		OpcUaVariant::SPtr value;
		eventVariables_.getValue("ReceiveTime", value);
		return value;
	}

	bool
	BaseEventType::severity(OpcUaVariant::SPtr& severity)
	{
		return eventVariables_.setValue("Severity", severity);
	}

	OpcUaVariant::SPtr
	BaseEventType::severity(void)
	{
		OpcUaVariant::SPtr value;
		eventVariables_.getValue("Severity", value);
		return value;
	}

	bool
	BaseEventType::sourceNode(OpcUaVariant::SPtr& sourceNode)
	{
		return eventVariables_.setValue("SourceNode", sourceNode);
	}

	OpcUaVariant::SPtr
	BaseEventType::sourceNode(void)
	{
		OpcUaVariant::SPtr value;
		eventVariables_.getValue("SourceNode", value);
		return value;
	}

	bool
	BaseEventType::time(OpcUaVariant::SPtr& time)
	{
		return eventVariables_.setValue("Time", time);
	}

	OpcUaVariant::SPtr
	BaseEventType::time(void)
	{
		OpcUaVariant::SPtr value;
		eventVariables_.getValue("Time", value);
		return value;
	}

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// EventBase interface
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	void
	BaseEventType::mapNamespaceUri(void)
	{
		uint32_t namespaceIndex;
		EventBase::mapNamespaceUri();

		OpcUaVariant::SPtr eventTypeVariable = boost::make_shared<OpcUaVariant>();
		eventTypeVariable->setValue(eventVariables_.eventType());

		setNamespaceIndex(eventVariables_.namespaceUri(), namespaceIndex, eventVariables_.browseName(), eventTypeVariable);

		eventType(eventTypeVariable);
		eventVariables_.eventType(eventTypeVariable);
		eventVariables_.namespaceIndex(namespaceIndex);
	}

	OpcUaVariant::SPtr
	BaseEventType::get(
		OpcUaNodeId& eventType,
		std::list<OpcUaQualifiedName::SPtr>& browseNameList,
		EventResult::Code& resultCode
	)
	{
		resultCode = EventResult::Success;

		// check whether eventType and typeNodeId are identical
		if (eventType == eventVariables_.eventType()) {
			return eventVariables_.get(browseNameList, resultCode);
		}

		// the start item was not found. We delegate the search to the base class
		OpcUaVariant::SPtr variant;
		variant = EventBase::get(eventType, browseNameList, resultCode);
		if (resultCode != EventResult::Success || browseNameList.empty()) {
			return variant;
		}

		return eventVariables_.get(browseNameList, resultCode);
	}

}
