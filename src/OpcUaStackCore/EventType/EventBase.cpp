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

#include "OpcUaStackCore/EventType/EventBase.h"
#include "OpcUaStackCore/Base/Log.h"

namespace OpcUaStackCore
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// class EventBase
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	EventBase::EventBase(void)
	: namespaceArray_(nullptr)
	{
	}

	EventBase::~EventBase(void)
	{
	}

	void
	EventBase::namespaceArray(std::vector<std::string>* namespaceArray)
	{
		namespaceArray_ = namespaceArray;
		mapNamespaceUri();
		namespaceArray_ = nullptr;
	}

	int32_t
	EventBase::findNamespaceIndex(const std::string& namespaceUri)
	{
		if (namespaceArray_ == nullptr) return -1;

		for (uint32_t idx=0; idx<namespaceArray_->size(); idx++) {
			if ((*namespaceArray_)[idx] == namespaceUri) return idx;
		}
		return -1;
	}

	bool
	EventBase::setNamespaceIndex(
		const std::string& namespaceUri,
		uint32_t& namespaceIndex,
		OpcUaQualifiedName& browseName,
		OpcUaVariant::SPtr& eventType
	)
	{
		int32_t ns = findNamespaceIndex(namespaceUri);
		if (ns < 0) {
			namespaceIndex = 0;
		}
		else {
			namespaceIndex = ns;
		}

		browseName.namespaceIndex(namespaceIndex);

		OpcUaNodeId typeNodeId;
		eventType->getValue(typeNodeId);
		typeNodeId.namespaceIndex(namespaceIndex);

		OpcUaVariant::SPtr variant = boost::make_shared<OpcUaVariant>();
		variant->setValue(typeNodeId);
		eventType->setValue(typeNodeId);

		return true;
	}


	EventResult::Code
	EventBase::get(
		OpcUaNodeId& eventType,
		std::list<OpcUaQualifiedName::SPtr>& browseNameList,
		OpcUaVariant::SPtr& variant
	)
	{
		std::string browsePath = "";
		std::list<OpcUaQualifiedName::SPtr>::iterator it;
		for (it = browseNameList.begin(); it != browseNameList.end(); it++) {
			OpcUaQualifiedName::SPtr browseName = *it;

			if (browsePath != "") browsePath.append(",");
			browsePath.append(browseName->toString());
		}
		Log(Debug, "get event browse path in event")
		    .parameter("NodeId", eventType.toString())
			.parameter("BrowsePath", browsePath);

		EventResult::Code resultCode = EventResult::Success;

		if (browseNameList.empty()) {

			OpcUaQualifiedName::SPtr browseName = boost::make_shared<OpcUaQualifiedName>("EMPTY", eventType.namespaceIndex());
			browseNameList.push_back(browseName);

			//Log(Debug, "browse path not exist in event - browse path empty");
			//return EventResult::BadBrowseNameListEmpty;
		}

		variant = get(eventType, browseNameList, resultCode);
		if (resultCode != EventResult::Success) {
			Log(Debug, "browse path not exist in event");
			return resultCode;
		}

	   	if (!browseNameList.empty()) {
	   		Log(Debug, "browse path not exist in event");
	    	return EventResult::BadValueNotExist;
	    }

	   	Log(Debug, "browse path exist in event");
		return EventResult::Success;
	}

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// SimpleAttributeIf
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
    bool
	EventBase::getAttribute(
        OpcUaNodeId& typeId,
		std::list<OpcUaQualifiedName::SPtr>& browsePath,
		OpcUaUInt32 attributeId,
		OpcUaString& numericRange,
		OpcUaVariant& value
	)
    {
    	std::list<OpcUaQualifiedName::SPtr> tmpBrowsePath = browsePath;

    	OpcUaVariant::SPtr variant;
    	EventResult::Code resultCode = get(typeId, tmpBrowsePath, variant);
    	if (resultCode != EventResult::Success) {
    		return false;
    	}

    	value.copyFrom(*variant);
    	return true;
    }

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// virtual interface functions
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	void
	EventBase::mapNamespaceUri(void)
	{
		return;
	}

	OpcUaVariant::SPtr
	EventBase::get(
		OpcUaNodeId& eventType,
		std::list<OpcUaQualifiedName::SPtr>& browseNameList,
		EventResult::Code& resultCode
	)
	{
		resultCode = EventResult::BadEventTypeNotExist;
		OpcUaVariant::SPtr variant;
		return variant;
	}

}
