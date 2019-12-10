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

#include <OpcUaStackCore/EventType/EventHandler.h>
#include "OpcUaStackCore/Base/Log.h"

namespace OpcUaStackCore
{

	EventHandler::EventHandler(void)
	: EventHandlerBase()
	{
	}

	EventHandler::~EventHandler(void)
	{
	}

	void
	EventHandler::eventCallback(EventCallback& eventCallback)
	{
		eventCallback_ = eventCallback;
	}

	EventHandler::EventCallback
	EventHandler::eventCallback(void)
	{
		return eventCallback_;
	}

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// interface EventHandlerBase
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	bool
	EventHandler::fireEvent(OpcUaNodeId& nodeId, EventBase::SPtr& eventBase)
	{
		if (!eventCallback_) {
			return false;
		}

		eventCallback_(eventBase);
		return true;
	}

}
