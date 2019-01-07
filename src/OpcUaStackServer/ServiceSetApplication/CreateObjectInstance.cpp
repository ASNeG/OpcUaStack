/*
   Copyright 2019 Kai Huebl (kai@huebl-sgh.de)

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

#include "OpcUaStackCore/ServiceSetApplication/ApplicationServiceTransaction.h"
#include "OpcUaStackServer/ServiceSetApplication/CreateObjectInstance.h"
#include "OpcUaStackServer/ServiceSetApplication/NodeReferenceApplication.h"

namespace OpcUaStackServer
{

	CreateObjectInstance::CreateObjectInstance(void)
	: resultCode_(Success)
	, parentNodeId_()
	, referenceTypeNodeId_()
	, variableInstance_()
	{
	}

	CreateObjectInstance::CreateObjectInstance(
		const OpcUaNodeId& parentNodeId,
		const OpcUaNodeId& referenceTypeNodeId,
		Object::SPtr& variableInstance
	)
	: resultCode_(Success)
	, parentNodeId_(parentNodeId)
	, referenceTypeNodeId_(referenceTypeNodeId)
	, variableInstance_(variableInstance)
	{
	}

	CreateObjectInstance::~CreateObjectInstance(void)
	{
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
	CreateObjectInstance::variableInstance(Object::SPtr& variableInstance)
	{
		variableInstance_ = variableInstance;
	}

	Object::SPtr&
	CreateObjectInstance::variableInstace(void)
	{
		return variableInstance_;
	}

	bool
	CreateObjectInstance::query(ApplicationServiceIf* applicationServiceIf)
	{
		resultCode_ = Success;

		// create response
		auto trx = constructSPtr<ServiceTransactionCreateObject>();

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
