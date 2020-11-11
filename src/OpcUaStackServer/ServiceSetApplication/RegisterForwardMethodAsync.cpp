/*
   Copyright 2020 Kai Huebl (kai@huebl-sgh.de)

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
#include "OpcUaStackServer/ServiceSetApplication/RegisterForwardMethodAsync.h"
#include "OpcUaStackServer/ServiceSetApplication/NodeReferenceApplication.h"

using namespace OpcUaStackCore;

namespace OpcUaStackServer
{

	RegisterForwardMethodAsync::RegisterForwardMethodAsync(void)
	: objectNodeId_()
	, methodNodeId_()
	, resultCode_(Success)
	, forwardMethodAsync_()
	{
	}

	RegisterForwardMethodAsync::RegisterForwardMethodAsync(const OpcUaNodeId& objectNodeId, const OpcUaNodeId& methodNodeId)
	: objectNodeId_(objectNodeId)
	, methodNodeId_(methodNodeId)
	, resultCode_(Success)
	, forwardMethodAsync_()
	{
	}

	RegisterForwardMethodAsync::~RegisterForwardMethodAsync(void)
	{
	}

	void
	RegisterForwardMethodAsync::objectNodeId(const OpcUaNodeId& objectNodeId)
	{
		objectNodeId_ = objectNodeId;
	}

	void
	RegisterForwardMethodAsync::methodNodeId(const OpcUaNodeId& methodNodeId)
	{
		methodNodeId_ = methodNodeId;
	}

	void
	RegisterForwardMethodAsync::activate(void)
	{
		forwardMethodAsync_.methodService().activate();
	}

	void
	RegisterForwardMethodAsync::applicationContext(BaseClass::SPtr& applicationContext)
	{
		forwardMethodAsync_.methodService().applicationContext(applicationContext);
	}

	bool
	RegisterForwardMethodAsync::query(ApplicationServiceIf* applicationServiceIf)
	{
		resultCode_ = Success;

		// create response
		auto trx = boost::make_shared<ServiceTransactionRegisterForwardMethodAsync>();
	  	trx->request()->objectNodeId(objectNodeId_);
	  	trx->request()->methodNodeId(methodNodeId_);
	  	trx->request()->forwardMethodAsync()->updateFrom(forwardMethodAsync_);

		// send query to application service
		applicationServiceIf->sendSync(trx);
		resultCode_ = trx->statusCode();
	  	if (resultCode_ != Success) {
	  		return false;
	  	}
		return true;
	}

	OpcUaStatusCode
	RegisterForwardMethodAsync::resultCode(void)
	{
		return resultCode_;
	}

}
