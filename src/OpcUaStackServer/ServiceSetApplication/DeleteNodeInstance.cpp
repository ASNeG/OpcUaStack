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
#include "OpcUaStackServer/ServiceSetApplication/DeleteNodeInstance.h"
#include "OpcUaStackServer/ServiceSetApplication/NodeReferenceApplication.h"

using namespace OpcUaStackCore;

namespace OpcUaStackServer
{

	DeleteNodeInstance::DeleteNodeInstance(void)
	: resultCode_(Success)
	, node_()
	{
	}

	DeleteNodeInstance::DeleteNodeInstance(const OpcUaNodeId& node)
	: resultCode_(Success)
	, node_(node)
	{
	}

	DeleteNodeInstance::~DeleteNodeInstance(void)
	{
	}

	void
	DeleteNodeInstance::node(const OpcUaNodeId& node)
	{
		node_ = node;
	}

	bool
	DeleteNodeInstance::query(ApplicationServiceIf* applicationServiceIf)
	{
		resultCode_ = Success;

		// create response
		auto trx = boost::make_shared<ServiceTransactionDelNodeInstance>();
	  	trx->request()->nodeId() = node_;

		// send query to application service
		applicationServiceIf->sendSync(trx);
		resultCode_ = trx->statusCode();
	  	if (resultCode_ != Success) {
	  		return false;
	  	}
		return true;
	}

	OpcUaStatusCode
	DeleteNodeInstance::resultCode(void)
	{
		return resultCode_;
	}

}
