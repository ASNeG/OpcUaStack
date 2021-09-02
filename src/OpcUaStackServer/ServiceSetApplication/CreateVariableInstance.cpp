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
#include "OpcUaStackServer/ServiceSetApplication/CreateVariableInstance.h"
#include "OpcUaStackServer/ServiceSetApplication/NodeReferenceApplication.h"

using namespace OpcUaStackCore;

namespace OpcUaStackServer
{

	CreateVariableInstance::CreateVariableInstance(void)
	: resultCode_(Success)
	, namespaceName_("")
	, displayName_()
	, parentNodeId_()
	, referenceTypeNodeId_()
	, variableInstance_()
	{
	}

	CreateVariableInstance::CreateVariableInstance(
		const std::string& namespaceName,
		const OpcUaLocalizedText& displayName,
		const OpcUaNodeId& parentNodeId,
		const OpcUaNodeId& referenceTypeNodeId,
		Object::SPtr& variableInstance
	)
	: resultCode_(Success)
	, namespaceName_(namespaceName)
	, displayName_(displayName)
	, parentNodeId_(parentNodeId)
	, referenceTypeNodeId_(referenceTypeNodeId)
	, variableInstance_(variableInstance)
	{
	}

	CreateVariableInstance::~CreateVariableInstance(void)
	{
	}

	void
	CreateVariableInstance::namespaceName(const std::string& namespaceName)
	{
		namespaceName_ = namespaceName;
	}

	std::string&
	CreateVariableInstance::namespaceName(void)
	{
		return namespaceName_;
	}

	void
	CreateVariableInstance::displayName(const OpcUaLocalizedText& displayName)
	{
		displayName_ = displayName;
	}

	OpcUaLocalizedText&
	CreateVariableInstance::displayName(void)
	{
		return displayName_;
	}

	void
	CreateVariableInstance::parentNodeId(const OpcUaNodeId& parentNodeId)
	{
		parentNodeId_ = parentNodeId;
	}

	OpcUaNodeId&
	CreateVariableInstance::parentnodeId(void)
	{
		return parentNodeId_;
	}

	void
	CreateVariableInstance::referenceTypeNodeId(const OpcUaNodeId& referenceTypeNodeId)
	{
		referenceTypeNodeId_ = referenceTypeNodeId;
	}

	OpcUaNodeId&
	CreateVariableInstance::referenceTypeNodeId(void)
	{
		return referenceTypeNodeId_;
	}

	void
	CreateVariableInstance::variableInstance(Object::SPtr& variableInstance)
	{
		variableInstance_ = variableInstance;
	}

	Object::SPtr&
	CreateVariableInstance::variableInstace(void)
	{
		return variableInstance_;
	}

	bool
	CreateVariableInstance::addNodeId(const std::string& nodeName, const OpcUaStackCore::OpcUaNodeId& nodeId)
	{
		if (nodeIdMap_.find(nodeName) != nodeIdMap_.end()) {
			return false;
		}

		nodeIdMap_.insert(std::make_pair(nodeName, nodeId));
		return true;
	}

	bool
	CreateVariableInstance::query(ApplicationServiceIf* applicationServiceIf)
	{
		resultCode_ = Success;

		// create response
		auto trx = boost::make_shared<ServiceTransactionCreateVariable>();
		trx->request()->namespaceName(namespaceName_);
		trx->request()->displayName(displayName_);
		trx->request()->parentNodeId(parentNodeId_);
		trx->request()->referenceTypeNodeId(referenceTypeNodeId_);
		trx->request()->variableInstance(variableInstance_);

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
	CreateVariableInstance::resultCode(void)
	{
		return resultCode_;
	}

}
