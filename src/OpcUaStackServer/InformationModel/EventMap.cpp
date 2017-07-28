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

#include "OpcUaStackServer/InformationModel/EventMap.h"
#include "OpcUaStackCore/Base/Log.h"

namespace OpcUaStackServer
{

	EventMap::EventMap(void)
	: eventFilterBaseMap_()
	{
	}

	EventMap::~EventMap(void)
	{
	}

	void
	EventMap::clear(void)
	{
		eventFilterBaseMap_.clear();
	}

	bool
	EventMap::existEvent(OpcUaNodeId& nodeId)
	{
		EventFilterBaseMap::iterator it;
		it = eventFilterBaseMap_.find(nodeId);
		if (it != eventFilterBaseMap_.end());
	}

	bool
	EventMap::registerEvent(OpcUaNodeId& nodeId, EventFilterBase::SPtr& eventFilterBase)
	{
		if (existEvent(nodeId)) {
			return false;
		}

		eventFilterBaseMap_.insert(std::make_pair(nodeId, eventFilterBase));
		return true;
	}

	bool
	EventMap::deregisterEvent(OpcUaNodeId& nodeId)
	{
		EventFilterBaseMap::iterator it;
		it = eventFilterBaseMap_.find(nodeId);
		if (it == eventFilterBaseMap_.end()) {
			return true;
		}
		eventFilterBaseMap_.erase(it);
		return true;
	}

	EventFilterBase::SPtr
	EventMap::getEvent(OpcUaNodeId& nodeId)
	{
		EventFilterBase::SPtr eventFilterBase;

		EventFilterBaseMap::iterator it;
		it = eventFilterBaseMap_.find(nodeId);
		if (it == eventFilterBaseMap_.end()) {
			return eventFilterBase;
		}
		return it->second;
	}

}
