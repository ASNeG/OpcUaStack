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
#include "OpcUaStackServer/ServiceSetApplication/RegisterForwardMethod.h"
#include "OpcUaStackServer/ServiceSetApplication/NodeReferenceApplication.h"

using namespace OpcUaStackCore;

namespace OpcUaStackServer
{

	RegisterForwardMethod::RegisterForwardMethod(void)
	: objectNodeId_()
	, methodNodeId_()
	, resultCode_(Success)
	, forwardMethodSync_()
	{
	}

	RegisterForwardMethod::RegisterForwardMethod(const OpcUaNodeId& objectNodeId, const OpcUaNodeId& methodNodeId)
	: objectNodeId_(objectNodeId)
	, methodNodeId_(methodNodeId)
	, resultCode_(Success)
	, forwardMethodSync_()
	{
	}

	RegisterForwardMethod::~RegisterForwardMethod(void)
	{
	}

	void
	RegisterForwardMethod::objectNodeId(const OpcUaNodeId& objectNodeId)
	{
		objectNodeId_ = objectNodeId;
	}

	void
	RegisterForwardMethod::methodNodeId(const OpcUaNodeId& methodNodeId)
	{
		methodNodeId_ = methodNodeId;
	}

	void
	RegisterForwardMethod::setMethodCallback(ApplicationCallback::Method callback)
	{
		forwardMethodSync_.methodService().setCallback(callback);
	}

	void
	RegisterForwardMethod::applicationContext(BaseClass::SPtr& applicationContext)
	{
		forwardMethodSync_.methodService().applicationContext(applicationContext);
	}

	bool
	RegisterForwardMethod::query(ApplicationServiceIf* applicationServiceIf)
	{
		resultCode_ = Success;

		// create response
		auto trx = boost::make_shared<ServiceTransactionRegisterForwardMethod>();
	  	trx->request()->objectNodeId(objectNodeId_);
	  	trx->request()->methodNodeId(methodNodeId_);
	  	trx->request()->forwardMethodSync()->updateFrom(forwardMethodSync_);

		// send query to application service
		applicationServiceIf->sendSync(trx);
		resultCode_ = trx->statusCode();
	  	if (resultCode_ != Success) {
	  		return false;
	  	}
		return true;
	}

	OpcUaStatusCode
	RegisterForwardMethod::resultCode(void)
	{
		return resultCode_;
	}

}
