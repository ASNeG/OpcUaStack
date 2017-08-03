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
		bool& eventTypeFound,
		std::list<OpcUaQualifiedName::SPtr>& browseNameList,
		bool& error
	)
	{
		error = true;
		OpcUaVariant::SPtr variant;
		return variant;
	}

}
