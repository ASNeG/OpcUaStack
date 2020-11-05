/*
   Copyright 2017-2020 Kai Huebl (kai@huebl-sgh.de)

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

using namespace OpcUaStackCore;

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
	MethodMap::existMethodSync(
		const OpcUaNodeId& objectNodeId,
		const OpcUaNodeId& methodNodeId
	)
	{
		MethodId methodId;

		methodId.objectNodeId().copyFrom(objectNodeId);
		methodId.methodNodeId().copyFrom(methodNodeId);
		auto it = forwardMethodSyncMap_.find(methodId);
		return (it != forwardMethodSyncMap_.end());
	}

	bool
	MethodMap::existMethodAsync(
		const OpcUaNodeId& objectNodeId,
		const OpcUaNodeId& methodNodeId
	)
	{
		MethodId methodId;

		methodId.objectNodeId().copyFrom(objectNodeId);
		methodId.methodNodeId().copyFrom(methodNodeId);
		auto it = forwardMethodAsyncMap_.find(methodId);
		return (it != forwardMethodAsyncMap_.end());
	}

	bool
	MethodMap::registerMethodSync(
		const OpcUaNodeId& objectNodeId,
		const OpcUaNodeId& methodNodeId,
		ForwardMethodSync::SPtr& forwardMethodSync
	)
	{
		if (existMethodSync(objectNodeId, methodNodeId)) {
			deregisterMethodSync(objectNodeId, methodNodeId);
		}

		MethodId methodId;
		methodId.objectNodeId().copyFrom(objectNodeId);
		methodId.methodNodeId().copyFrom(methodNodeId);

		forwardMethodSyncMap_.insert(std::make_pair(methodId, forwardMethodSync));

		return true;
	}

	bool
	MethodMap::registerMethodAsync(
		const OpcUaNodeId& objectNodeId,
		const OpcUaNodeId& methodNodeId,
		ForwardMethodAsync::SPtr& forwardMethodAsync
	)
	{
		if (existMethodAsync(objectNodeId, methodNodeId)) {
			deregisterMethodAsync(objectNodeId, methodNodeId);
		}

		MethodId methodId;
		methodId.objectNodeId().copyFrom(objectNodeId);
		methodId.methodNodeId().copyFrom(methodNodeId);

		forwardMethodAsyncMap_.insert(std::make_pair(methodId, forwardMethodAsync));

		return true;
	}

	bool
	MethodMap::deregisterMethodSync(
		const OpcUaNodeId& objectNodeId,
		const OpcUaNodeId& methodNodeId
	)
	{
		MethodId methodId;
		methodId.objectNodeId().copyFrom(objectNodeId);
		methodId.methodNodeId().copyFrom(methodNodeId);

		auto it = forwardMethodSyncMap_.find(methodId);
		if (it == forwardMethodSyncMap_.end()) return true;
		forwardMethodSyncMap_.erase(it);

		return true;
	}

	bool
	MethodMap::deregisterMethodAsync(
		const OpcUaNodeId& objectNodeId,
		const OpcUaNodeId& methodNodeId
	)
	{
		MethodId methodId;
		methodId.objectNodeId().copyFrom(objectNodeId);
		methodId.methodNodeId().copyFrom(methodNodeId);

		auto it = forwardMethodAsyncMap_.find(methodId);
		if (it == forwardMethodAsyncMap_.end()) return true;
		forwardMethodAsyncMap_.erase(it);

		return true;
	}

	ForwardMethodSync::SPtr
	MethodMap::getMethodSync(
		const OpcUaNodeId& objectNodeId,
		const OpcUaNodeId& methodNodeId
	)
	{
		MethodId methodId;
		methodId.objectNodeId().copyFrom(objectNodeId);
		methodId.methodNodeId().copyFrom(methodNodeId);

		auto it = forwardMethodSyncMap_.find(methodId);
		if (it != forwardMethodSyncMap_.end()) {
			return it->second;
		}

		ForwardMethodSync::SPtr forwardMethodSync;
		return forwardMethodSync;
	}

	ForwardMethodAsync::SPtr
	MethodMap::getMethodAsync(
		const OpcUaNodeId& objectNodeId,
		const OpcUaNodeId& methodNodeId
	)
	{
		MethodId methodId;
		methodId.objectNodeId().copyFrom(objectNodeId);
		methodId.methodNodeId().copyFrom(methodNodeId);

		auto it = forwardMethodAsyncMap_.find(methodId);
		if (it != forwardMethodAsyncMap_.end()) {
			return it->second;
		}

		ForwardMethodAsync::SPtr forwardMethodAsync;
		return forwardMethodAsync;
	}

}
