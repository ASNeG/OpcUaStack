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
	{
	}

	EventBase::~EventBase(void)
	{
	}

	void
	EventBase::registerVariant(OpcUaNodeId& parentEventType, OpcUaNodeId& eventType, OpcUaQualifiedName& browseName, OpcUaVariant::SPtr& variant)
	{
		// FIXME: todo
	}

	bool
	EventBase::exist(OpcUaNodeId& eventType, OpcUaQualifiedName::SPtr& browseName)
	{
		// FIXME: todo
		return false;
	}

	bool
	EventBase::exist(OpcUaNodeId& eventType, OpcUaQualifiedNameArray::SPtr& browseNameArray)
	{
		// FIXME: todo
		return false;
	}

	OpcUaVariant::SPtr
	EventBase::get(OpcUaNodeId& eventType, OpcUaQualifiedNameArray::SPtr& browseNameArray)
	{
		OpcUaVariant::SPtr variant;

		// FIXME: todo

		return variant;
	}

	OpcUaVariant::SPtr
	EventBase::get(OpcUaNodeId& eventType, OpcUaQualifiedName::SPtr& browseName)
	{
		OpcUaVariant::SPtr variant;

		// FIXME: todo

		return variant;
	}

}
