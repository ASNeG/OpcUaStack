/*
   Copyright 2017-2018 Kai Huebl (kai@huebl-sgh.de)

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

#include <OpcUaStackServer/InformationModel/EventHandlerMap.h>
#include "OpcUaStackCore/Base/Log.h"

namespace OpcUaStackServer
{

	EventHandlerMap::EventHandlerMap(void)
	: eventHandlerBaseMap_()
	, mutex_()
	{
	}

	EventHandlerMap::~EventHandlerMap(void)
	{
	}

	boost::mutex&
	EventHandlerMap::mutex(void)
	{
		return mutex_;
	}

	void
	EventHandlerMap::clear(void)
	{
		eventHandlerBaseMap_.clear();
	}

	bool
	EventHandlerMap::existEvent(OpcUaNodeId& nodeId)
	{
		EventHandlerBaseMap::iterator it;
		it = eventHandlerBaseMap_.find(nodeId);
		return (it != eventHandlerBaseMap_.end());
	}

	bool
	EventHandlerMap::registerEvent(OpcUaNodeId& nodeId, EventHandlerBase::SPtr& eventHandlerBase)
	{
		eventHandlerBaseMap_.insert(std::make_pair(nodeId, eventHandlerBase));
		return true;
	}

	bool
	EventHandlerMap::deregisterEvent(OpcUaNodeId& nodeId, uint32_t eventId)
	{
		EventHandlerBaseMap::iterator it;
		std::pair<EventHandlerBaseMap::iterator, EventHandlerBaseMap::iterator> ret;

		ret = eventHandlerBaseMap_.equal_range(nodeId);
		for (it = ret.first; it != ret.second; ++it) {
			EventHandlerBase::SPtr eventHandlerBase = it->second;
			if (eventHandlerBase->eventId() == eventId) {
				eventHandlerBaseMap_.erase(it);
				return true;
			}
		}

		return true;
	}

	void
	EventHandlerMap::getEvent(OpcUaNodeId& nodeId, EventHandlerBase::Vec& eventHandlerBaseVec)
	{
		EventHandlerBaseMap::iterator it;
		std::pair<EventHandlerBaseMap::iterator, EventHandlerBaseMap::iterator> ret;

		ret = eventHandlerBaseMap_.equal_range(nodeId);
		for (it = ret.first; it != ret.second; ++it) {
			eventHandlerBaseVec.push_back(it->second);
		}
	}

}
