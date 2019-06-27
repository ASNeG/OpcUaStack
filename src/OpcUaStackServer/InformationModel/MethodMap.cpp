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

#include "OpcUaStackServer/InformationModel/MethodMap.h"
#include "OpcUaStackCore/Base/Log.h"

namespace OpcUaStackServer
{

	MethodMap::MethodMap(void)
	: forwardMethodSyncMap_()
	{
	}

	MethodMap::~MethodMap(void)
	{
	}

	void
	MethodMap::clear(void)
	{
		forwardMethodSyncMap_.clear();
	}

	bool
	MethodMap::existMethod(const OpcUaNodeId& objectNodeId, const OpcUaNodeId& methodNodeId)
	{
		MethodId methodId;
		ForwardMethodSyncMap::iterator it;

		methodId.objectNodeId().copyFrom(objectNodeId);
		methodId.methodNodeId().copyFrom(methodNodeId);
		it = forwardMethodSyncMap_.find(methodId);
		return (it != forwardMethodSyncMap_.end());
	}

	bool
	MethodMap::registerMethod(
		const OpcUaNodeId& objectNodeId,
		const OpcUaNodeId& methodNodeId,
		ForwardMethodSync::SPtr& forwardMethodSync
	)
	{
		if (existMethod(objectNodeId, methodNodeId)) {
			deregisterMethod(objectNodeId, methodNodeId);
		}

		MethodId methodId;
		methodId.objectNodeId().copyFrom(objectNodeId);
		methodId.methodNodeId().copyFrom(methodNodeId);

		forwardMethodSyncMap_.insert(std::make_pair(methodId, forwardMethodSync));

		return true;
	}

	bool
	MethodMap::deregisterMethod(const OpcUaNodeId& objectNodeId, const OpcUaNodeId& methodNodeId)
	{
		MethodId methodId;
		methodId.objectNodeId().copyFrom(objectNodeId);
		methodId.methodNodeId().copyFrom(methodNodeId);

		ForwardMethodSyncMap::iterator it;
		it = forwardMethodSyncMap_.find(methodId);
		if (it == forwardMethodSyncMap_.end()) return true;
		forwardMethodSyncMap_.erase(it);

		return true;
	}

	ForwardMethodSync::SPtr
	MethodMap::getMethod(const OpcUaNodeId& objectNodeId, const OpcUaNodeId& methodNodeId)
	{
		MethodId methodId;
		methodId.objectNodeId().copyFrom(objectNodeId);
		methodId.methodNodeId().copyFrom(methodNodeId);

		ForwardMethodSyncMap::iterator it;
		it = forwardMethodSyncMap_.find(methodId);
		if (it != forwardMethodSyncMap_.end()) {
			return it->second;
		}

		ForwardMethodSync::SPtr forwardMethodSync;
		return forwardMethodSync;
	}

}
