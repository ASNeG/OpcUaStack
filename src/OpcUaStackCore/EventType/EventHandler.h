/*
   Copyright 2017-2019 Kai Huebl (kai@huebl-sgh.de)

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

#ifndef __OpcUaStackCore_EventHandler_h__
#define __OpcUaStackCore_EventHandler_h__

#include "OpcUaStackCore/EventType/EventHandlerBase.h"

namespace OpcUaStackCore
{

	class DLLEXPORT EventHandler
	: public EventHandlerBase
	{
	  public:
		using SPtr = boost::shared_ptr<EventHandler>;
		using EventCallback = std::function<void (EventBase::SPtr& eventBase)>;

		EventHandler(void);
		virtual ~EventHandler(void);

		void eventCallback(EventCallback& eventCallback);
		EventCallback eventCallback(void);

		// - interface EventHandlerBase
		virtual bool fireEvent(OpcUaNodeId& nodeId, EventBase::SPtr& eventBase);
		// - interface EventHandlerBase

	  private:
		EventCallback eventCallback_ = nullptr;
	};


}

#endif
