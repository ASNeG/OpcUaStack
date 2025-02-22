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

#ifndef __OpcUaStackServer_EventHandlerMap_h__
#define __OpcUaStackServer_EventHandlerMap_h__

#include <map>
#include <boost/thread/mutex.hpp>
#include "OpcUaStackCore/EventType/EventHandlerBase.h"

namespace OpcUaStackServer
{

	class DLLEXPORT EventHandlerMap
	{
	  public:
		typedef std::multimap<OpcUaStackCore::OpcUaNodeId, OpcUaStackCore::EventHandlerBase::SPtr> EventHandlerBaseMap;

		EventHandlerMap(void);
		~EventHandlerMap(void);

		boost::mutex& mutex(void);
		void clear(void);
		bool existEvent(OpcUaStackCore::OpcUaNodeId& nodeId);
		bool registerEvent(OpcUaStackCore::OpcUaNodeId& nodeId, OpcUaStackCore::EventHandlerBase::SPtr& eventHandlerBase);
		bool deregisterEvent(OpcUaStackCore::OpcUaNodeId& nodeId, uint32_t eventId);
		void getEvent(OpcUaStackCore::OpcUaNodeId& nodeId, OpcUaStackCore::EventHandlerBase::Vec& eventHandlerBaseVec);

	  private:
		EventHandlerBaseMap eventHandlerBaseMap_;
		boost::mutex mutex_;
	};

}

#endif
