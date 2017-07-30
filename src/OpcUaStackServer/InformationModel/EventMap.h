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

#ifndef __OpcUaStackServer_EventMap_h__
#define __OpcUaStackServer_EventMap_h__

#include <OpcUaStackCore/EventType/EventHandlerBase.h>
#include <map>
#include "OpcUaStackCore/Base/os.h"

using namespace OpcUaStackCore;

namespace OpcUaStackServer
{

	class DLLEXPORT EventMap
	{
	  public:
		typedef std::multimap<OpcUaNodeId, EventHandlerBase::SPtr> EventHandlerBaseMap;

		EventMap(void);
		~EventMap(void);

		void clear(void);
		bool existEvent(OpcUaNodeId& nodeId);
		bool registerEvent(OpcUaNodeId& nodeId, EventHandlerBase::SPtr& eventHandlerBase);
		bool deregisterEvent(OpcUaNodeId& nodeId, uint32_t eventId);
		void getEvent(OpcUaNodeId& nodeId, EventHandlerBase::Vec& eventHandlerBaseVec);

	  private:
		EventHandlerBaseMap eventHandlerBaseMap_;
	};

}

#endif
