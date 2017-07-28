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
	{
	}

	EventMap::~EventMap(void)
	{
	}

	void
	EventMap::clear(void)
	{
		// FIXME:
		// forwardEventSyncMap_.clear();
	}

#if 0
	bool
	EventMap::existEvent(OpcUaNodeId& objectNodeId, OpcUaNodeId& methodNodeId)
	{
		EventId methodId;
		ForwardEventSyncMap::iterator it;

		methodId.objectNodeId().copyFrom(objectNodeId);
		methodId.methodNodeId().copyFrom(methodNodeId);
		it = forwardEventSyncMap_.find(methodId);
		return (it != forwardEventSyncMap_.end());
	}

	bool
	EventMap::registerEvent(
		OpcUaNodeId& objectNodeId,
		OpcUaNodeId& methodNodeId,
		ForwardEventSync::SPtr& forwardEventSync
	)
	{
		if (existEvent(objectNodeId, methodNodeId)) {
			deregisterEvent(objectNodeId, methodNodeId);
		}

		EventId methodId;
		methodId.objectNodeId().copyFrom(objectNodeId);
		methodId.methodNodeId().copyFrom(methodNodeId);

		forwardEventSyncMap_.insert(std::make_pair(methodId, forwardEventSync));

		return true;
	}

	bool
	EventMap::deregisterEvent(OpcUaNodeId& objectNodeId, OpcUaNodeId& methodNodeId)
	{
		EventId methodId;
		methodId.objectNodeId().copyFrom(objectNodeId);
		methodId.methodNodeId().copyFrom(methodNodeId);

		ForwardEventSyncMap::iterator it;
		it = forwardEventSyncMap_.find(methodId);
		if (it == forwardEventSyncMap_.end()) return true;
		forwardEventSyncMap_.erase(it);

		return true;
	}

	ForwardEventSync::SPtr
	EventMap::getEvent(OpcUaNodeId& objectNodeId, OpcUaNodeId& methodNodeId)
	{
		EventId methodId;
		methodId.objectNodeId().copyFrom(objectNodeId);
		methodId.methodNodeId().copyFrom(methodNodeId);

		ForwardEventSyncMap::iterator it;
		it = forwardEventSyncMap_.find(methodId);
		if (it != forwardEventSyncMap_.end()) {
			return it->second;
		}

		ForwardEventSync::SPtr forwardEventSync;
		return forwardEventSync;
	}
#endif

}
