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
	, namespaceUri_("")
	, typeNodeId_((OpcUaUInt32)2041)
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
		EventBase::mapNamespaceUri();
		namespaceIndex_ = findNamespaceIndex(namespaceUri_);
	}

	OpcUaVariant::SPtr
	BaseEventType::get(
		OpcUaNodeId& eventType,
		bool eventTypeFound,
		std::list<OpcUaQualifiedName::SPtr>& browseNameList,
		bool& error
	)
	{
		// browse name list is empty
		if (browseNameList.empty()) {
			error = true;
			OpcUaVariant::SPtr variant;
			return variant;
		}

		// check event type
		if (eventType != typeNodeId_) {
			OpcUaVariant::SPtr variant;
			variant = BaseEventType::get(eventType, eventTypeFound, browseNameList, error);
			if (error) {
				OpcUaVariant::SPtr variant;
				return variant;
			}

			// FIXME: todo
		}

		// FIXME: todo

		OpcUaVariant::SPtr variant;
		return variant;
	}

	OpcUaVariant::SPtr
	BaseEventType::get(OpcUaQualifiedName::SPtr& browseName)
	{
		OpcUaVariant::SPtr variant;
		return variant;
	}

}
