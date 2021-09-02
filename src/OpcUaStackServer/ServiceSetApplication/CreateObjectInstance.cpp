/*
   Copyright 2019-2021 Kai Huebl (kai@huebl-sgh.de)

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

#include "OpcUaStackServer/ServiceSetApplication/ApplicationServiceTransaction.h"
#include "OpcUaStackServer/ServiceSetApplication/CreateObjectInstance.h"
#include "OpcUaStackServer/ServiceSetApplication/NodeReferenceApplication.h"

using namespace OpcUaStackCore;

namespace OpcUaStackServer
{

	CreateObjectInstance::CreateObjectInstance(void)
	: resultCode_(Success)
	, namespaceName_("")
	, displayName_()
	, parentNodeId_()
	, referenceTypeNodeId_()
	, objectInstance_()
	{
	}

	CreateObjectInstance::CreateObjectInstance(
		const std::string& namespaceName,
		const OpcUaLocalizedText& displayName,
		const OpcUaNodeId& parentNodeId,
		const OpcUaNodeId& referenceTypeNodeId,
		Object::SPtr& objectInstance
	)
	: resultCode_(Success)
	, namespaceName_(namespaceName)
	, displayName_(displayName)
	, parentNodeId_(parentNodeId)
	, referenceTypeNodeId_(referenceTypeNodeId)
	, objectInstance_(objectInstance)
	{
	}

	CreateObjectInstance::~CreateObjectInstance(void)
	{
	}

	void
	CreateObjectInstance::namespaceName(const std::string& namespaceName)
	{
		namespaceName_ = namespaceName;
	}

	std::string&
	CreateObjectInstance::namespaceName(void)
	{
		return namespaceName_;
	}

	void
	CreateObjectInstance::displayName(const OpcUaLocalizedText& displayName)
	{
		displayName_ = displayName;
	}

	OpcUaLocalizedText&
	CreateObjectInstance::displayName(void)
	{
		return displayName_;
	}

	void
	CreateObjectInstance::parentNodeId(const OpcUaNodeId& parentNodeId)
	{
		parentNodeId_ = parentNodeId;
	}

	OpcUaNodeId&
	CreateObjectInstance::parentnodeId(void)
	{
		return parentNodeId_;
	}

	void
	CreateObjectInstance::referenceTypeNodeId(const OpcUaNodeId& referenceTypeNodeId)
	{
		referenceTypeNodeId_ = referenceTypeNodeId;
	}

	OpcUaNodeId&
	CreateObjectInstance::referenceTypeNodeId(void)
	{
		return referenceTypeNodeId_;
	}

	void
	CreateObjectInstance::objectInstance(Object::SPtr& objectInstance)
	{
		objectInstance_ = objectInstance;
	}

	Object::SPtr&
	CreateObjectInstance::objectInstance(void)
	{
		return objectInstance_;
	}

	bool
	CreateObjectInstance::addNodeId(const std::string& nodeName, const OpcUaStackCore::OpcUaNodeId& nodeId)
	{
		if (nodeIdMap_.find(nodeName) != nodeIdMap_.end()) {
			return false;
		}

		nodeIdMap_.insert(std::make_pair(nodeName, nodeId));
		return true;
	}

	bool
	CreateObjectInstance::query(ApplicationServiceIf* applicationServiceIf)
	{
		resultCode_ = Success;

		// create response
		auto trx = boost::make_shared<ServiceTransactionCreateObject>();
		trx->request()->namespaceName(namespaceName_);
		trx->request()->displayName(displayName_);
		trx->request()->parentNodeId(parentNodeId_);
		trx->request()->referenceTypeNodeId(referenceTypeNodeId_);
		trx->request()->objectInstance(objectInstance_);

		for (auto nodeIdElementIt : nodeIdMap_) {
			trx->request()->addNodeId(nodeIdElementIt.first, nodeIdElementIt.second);
		}

		// send query to application service
		applicationServiceIf->sendSync(trx);
		resultCode_ = trx->statusCode();
	  	if (resultCode_ != Success) {
	  		return false;
	  	}
		return true;
	}

	OpcUaStatusCode
	CreateObjectInstance::resultCode(void)
	{
		return resultCode_;
	}

}
