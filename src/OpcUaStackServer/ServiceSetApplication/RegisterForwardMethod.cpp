/*
   Copyright 2018 Kai Huebl (kai@huebl-sgh.de)

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
#include "OpcUaStackServer/ServiceSetApplication/RegisterForwardMethod.h"
#include "OpcUaStackServer/ServiceSetApplication/NodeReferenceApplication.h"

namespace OpcUaStackServer
{

	RegisterForwardMethod::RegisterForwardMethod(void)
	: resultCode_(Success)
	, forwardNodeSync_()
	{
	}

	RegisterForwardMethod::~RegisterForwardMethod(void)
	{
	}

	void
	RegisterForwardMethod::setMethodCallback(Callback& callback)
	{
		forwardNodeSync_.methodService().setCallback(callback);
	}

	bool
	RegisterForwardMethod::query(ApplicationServiceIf* applicationServiceIf)
	{
		if (nodes_.size() == 0) return false;

		resultCode_ = Success;

		// create response
		auto trx = constructSPtr<ServiceTransactionRegisterForwardMethod>();

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
