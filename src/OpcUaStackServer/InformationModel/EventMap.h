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

#include <map>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/EventType/EventFilterBase.h"

using namespace OpcUaStackCore;

namespace OpcUaStackServer
{

	class DLLEXPORT EventMap
	{
	  public:
		typedef std::multimap<OpcUaNodeId, EventFilterBase::SPtr> EventFilterBaseMap;

		EventMap(void);
		~EventMap(void);

		void clear(void);
		bool existEvent(OpcUaNodeId& nodeId);
		bool registerEvent(OpcUaNodeId& nodeId, EventFilterBase::SPtr& eventFilterBase);
		bool deregisterEvent(OpcUaNodeId& nodeId, uint32_t eventId);
		void getEvent(OpcUaNodeId& nodeId, EventFilterBase::Vec& eventFilterBaseVec);

	  private:
		EventFilterBaseMap eventFilterBaseMap_;
	};

}

#endif
