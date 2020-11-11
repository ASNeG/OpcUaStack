/*
   Copyright 2018-2020 Kai Huebl (kai@huebl-sgh.de)

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
#include "OpcUaStackServer/ServiceSetApplication/CreateNodeInstance.h"
#include "OpcUaStackServer/ServiceSetApplication/NodeReferenceApplication.h"

using namespace OpcUaStackCore;

namespace OpcUaStackServer
{

	CreateNodeInstance::CreateNodeInstance(void)
	: resultCode_(Success)
	, name_("")
	, nodeClass_()
	, parentNodeId_()
	, nodeId_()
	, displayName_()
	, browseName_()
	, referenceNodeId_()
	, typeNodeId_()
	{
	}

	CreateNodeInstance::CreateNodeInstance(
		const std::string& name,
		const NodeClass::Enum nodeClass,
		const OpcUaNodeId& parentNodeId,
		const OpcUaNodeId& nodeId,
		const OpcUaLocalizedText& displayName,
		const OpcUaQualifiedName& browseName,
		const OpcUaNodeId& referenceNodeId,
		const OpcUaNodeId& typeNodeId
	)
	: resultCode_(Success)
	, name_(name)
	, nodeClass_(nodeClass)
	, parentNodeId_(parentNodeId)
	, nodeId_(nodeId)
	, displayName_(displayName)
	, browseName_(browseName)
	, referenceNodeId_(referenceNodeId)
	, typeNodeId_(typeNodeId)
	{
	}

	CreateNodeInstance::~CreateNodeInstance(void)
	{
	}

	void
	CreateNodeInstance::name(const std::string& name)
	{
		name_ = name;
	}

	void
	CreateNodeInstance::nodeClassType(NodeClass::Enum nodeClass)
	{
		nodeClass_ = nodeClass;
	}

	void
	CreateNodeInstance::parentNodeId(const OpcUaNodeId& parentNodeId)
	{
		parentNodeId_ = parentNodeId;
	}

	void
	CreateNodeInstance::nodeId(const OpcUaNodeId& nodeId)
	{
		nodeId_ = nodeId;
	}

	void
	CreateNodeInstance::displayName(const OpcUaLocalizedText& displayName)
	{
		displayName_ = displayName;
	}

	void
	CreateNodeInstance::browseName(const OpcUaQualifiedName& browseName)
	{
		browseName_ = browseName;
	}

	void
	CreateNodeInstance::referenceNodeId(const OpcUaNodeId& referenceNodeId)
	{
		referenceNodeId_ = referenceNodeId;
	}

	void
	CreateNodeInstance::typeNodeId(const OpcUaNodeId& typeNodeId)
	{
		typeNodeId_ = typeNodeId;
	}

	bool
	CreateNodeInstance::query(ApplicationServiceIf* applicationServiceIf)
	{
		resultCode_ = Success;

		// create response
		auto trx = boost::make_shared<ServiceTransactionCreateNodeInstance>();
		trx->request()->name() = name_;
		trx->request()->nodeClassType() = nodeClass_;
		trx->request()->parentNodeId() = parentNodeId_;
	  	trx->request()->nodeId() = nodeId_;
	  	trx->request()->displayName() = displayName_;
	  	trx->request()->browseName() = browseName_;
	  	trx->request()->referenceNodeId() = referenceNodeId_;
	  	trx->request()->typeNodeId() = typeNodeId_;

		// send query to application service
		applicationServiceIf->sendSync(trx);
		resultCode_ = trx->statusCode();
		if (resultCode_ == Success) {
			baseNodeClass_ = trx->response()->baseNodeClass();
		}
		else {
			baseNodeClass_.reset();
			return false;
		}
		return true;
	}

	OpcUaStatusCode
	CreateNodeInstance::resultCode(void)
	{
		return resultCode_;
	}

	BaseNodeClass::WPtr&
	CreateNodeInstance::baseNodeClass(void)
	{
		return baseNodeClass_;
	}

}
