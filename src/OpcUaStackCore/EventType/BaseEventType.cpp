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
	, namespaceIndex_(0)
	, typeNodeId_((OpcUaUInt32)2041)
	, browseName_("BaseEventType")
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
		int32_t ns = findNamespaceIndex(namespaceUri_);
		if (ns < 0) namespaceIndex_ = 0;
		namespaceIndex_ = ns;
		browseName_.namespaceIndex(namespaceIndex_);
	}

	OpcUaVariant::SPtr
	BaseEventType::get(
		OpcUaNodeId& eventType,
		bool eventTypeFound,
		std::list<OpcUaQualifiedName::SPtr>& browseNameList,
		bool& error
	)
	{
		// browse name list must contain at least one element
		if (browseNameList.empty()) {
			error = true;
			OpcUaVariant::SPtr variant;
			return variant;
		}

		// check whether eventType and typeNodeId are identical
		if (eventType == typeNodeId_) {
			OpcUaVariant::SPtr variant;
			eventTypeFound = true;

			if (browseNameList.size() == 1) {
				OpcUaQualifiedName::SPtr browseName = browseNameList.front();
				browseNameList.pop_front();

				variant = get(browseName);
				if (variant.get() == nullptr) {
					error = true;
				}
			}

			return variant;
		}

		// the start item was not found. We delegate the search to the base class
		OpcUaVariant::SPtr variant;
		variant = EventBase::get(eventType, eventTypeFound, browseNameList, error);
		if (!eventTypeFound || error || browseNameList.size() == 0) {
			return variant;
		}

		if (browseNameList.size() < 2) {
			error = true;
			return variant;
		}

		// the browse name must match the first element in the browse name list
		OpcUaQualifiedName::SPtr browseName = browseNameList.front();
		browseNameList.pop_front();
		if (*browseName != browseName_) {
			error = true;
			return variant;
		}

		if (browseNameList.size() == 1) {
			OpcUaQualifiedName::SPtr browseName = browseNameList.front();
			browseNameList.pop_front();

			variant = get(browseName);
			if (variant.get() == nullptr) {
				error = true;
			}
		}

		return variant;
	}

	OpcUaVariant::SPtr
	BaseEventType::get(OpcUaQualifiedName::SPtr& browseName)
	{
		if (*browseName == OpcUaQualifiedName("EventId", namespaceIndex_)) {
			return eventId_;
		}
		if (*browseName == OpcUaQualifiedName("EventType", namespaceIndex_)) {
			return eventType_;
		}
		if (*browseName == OpcUaQualifiedName("SourceName", namespaceIndex_)) {
			return sourceName_;
		}
		if (*browseName == OpcUaQualifiedName("LocalTime", namespaceIndex_)) {
			return localTime_;
		}
		if (*browseName == OpcUaQualifiedName("Message", namespaceIndex_)) {
			return message_;
		}
		if (*browseName == OpcUaQualifiedName("ReceiveTime", namespaceIndex_)) {
			return receiveTime_;
		}
		if (*browseName == OpcUaQualifiedName("Severity", namespaceIndex_)) {
			return severity_;
		}
		if (*browseName == OpcUaQualifiedName("SourceNode", namespaceIndex_)) {
			return sourceNode_;
		}
		if (*browseName == OpcUaQualifiedName("Time", namespaceIndex_)) {
			return time_;
		}

		OpcUaVariant::SPtr variant;
		return variant;
	}

}
