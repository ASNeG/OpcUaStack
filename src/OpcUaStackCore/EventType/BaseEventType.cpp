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

#include "OpcUaStackCore/EventType/BaseEventType.h"
#include "OpcUaStackCore/Base/Log.h"

namespace OpcUaStackCore
{

	BaseEventType::BaseEventType(void)
	: EventBase()
	, eventId_(constructSPtr<OpcUaVariant>())
	, eventType_(constructSPtr<OpcUaVariant>())
	, sourceName_(constructSPtr<OpcUaVariant>())
	, localTime_(constructSPtr<OpcUaVariant>())
	, message_(constructSPtr<OpcUaVariant>())
	, receiveTime_(constructSPtr<OpcUaVariant>())
	, severity_(constructSPtr<OpcUaVariant>())
	, sourceNode_(constructSPtr<OpcUaVariant>())
	, time_(constructSPtr<OpcUaVariant>())
	{
		OpcUaNodeId parentType(0);		// FIXME: map namespace string to namespace index!
		OpcUaNodeId type(2041);			// FIXME: map namespace string to namespace index!
		OpcUaQualifiedName browseName;	// FIXME: map namespace string to namespace index!

		browseName.set("EventId");
		registerVariant(parentType, type, browseName, eventId_);

		browseName.set("EventType");
		registerVariant(parentType, type, browseName, eventType_);

		browseName.set("SourceName");
		registerVariant(parentType, type, browseName, sourceName_);

		browseName.set("LocalTime");
		registerVariant(parentType, type, browseName, localTime_);

		browseName.set("Message");
		registerVariant(parentType, type, browseName, message_);

		browseName.set("ReceiveTime");
		registerVariant(parentType, type, browseName, receiveTime_);

		browseName.set("Severity");
		registerVariant(parentType, type, browseName, severity_);

		browseName.set("SourceNode");
		registerVariant(parentType, type, browseName, sourceNode_);

		browseName.set("Time");
		registerVariant(parentType, type, browseName, time_);
	}

	BaseEventType::~BaseEventType(void)
	{
	}

	void
	BaseEventType::eventId(OpcUaByteString::SPtr& eventId)
	{
		// FIXME: todo
	}

	OpcUaByteString::SPtr
	BaseEventType::eventId(void)
	{
		OpcUaByteString::SPtr tmp;
		// FIXME: todo
		return tmp;
	}

}
