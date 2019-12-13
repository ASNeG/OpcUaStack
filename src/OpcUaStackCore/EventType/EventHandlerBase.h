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

#ifndef __OpcUaStackCore_EventHandlerBase_h__
#define __OpcUaStackCore_EventHandlerBase_h__

#include <boost/shared_ptr.hpp>
#include "OpcUaStackCore/EventType/EventBase.h"

namespace OpcUaStackCore
{

	class DLLEXPORT EventHandlerBase
	{
	  public:
		typedef boost::shared_ptr<EventHandlerBase> SPtr;
		typedef std::vector<EventHandlerBase::SPtr> Vec;

		EventHandlerBase(void);
		virtual ~EventHandlerBase(void);

		void eventId(uint32_t eventId);
		uint32_t eventId(void);

		virtual bool fireEvent(OpcUaNodeId& nodeId, EventBase::SPtr& eventBase);

	  private:
		uint32_t eventId_;
	};


}

#endif
