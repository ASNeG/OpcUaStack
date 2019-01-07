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
#include "OpcUaStackServer/ServiceSetApplication/RegisterForwardGlobal.h"
#include "OpcUaStackServer/ServiceSetApplication/NodeReferenceApplication.h"

namespace OpcUaStackServer
{

	RegisterForwardGlobal::RegisterForwardGlobal(void)
	: resultCode_(Success)
	, forwardGlobalSync_()
	{
	}

	RegisterForwardGlobal::~RegisterForwardGlobal(void)
	{
	}

	void
	RegisterForwardGlobal::setRegisterServerCallback(Callback& callback)
	{
		forwardGlobalSync_.registerServerService().setCallback(callback);
	}

	void
	RegisterForwardGlobal::setFindServersCallback(Callback& callback)
	{
		forwardGlobalSync_.findServersService().setCallback(callback);
	}

	void
	RegisterForwardGlobal::setEventItemStartCallback(Callback& callback)
	{
		forwardGlobalSync_.eventItemStartService().setCallback(callback);
	}

	void
	RegisterForwardGlobal::setEventItemStopCallback(Callback& callback)
	{
		forwardGlobalSync_.eventItemStopService().setCallback(callback);
	}

	void
	RegisterForwardGlobal::setAuthenticationCallback(Callback& callback)
	{
		forwardGlobalSync_.authenticationService().setCallback(callback);
	}

	void
	RegisterForwardGlobal::setAutorizationCallback(Callback& callback)
	{
		forwardGlobalSync_.autorizationService().setCallback(callback);
	}

	void
	RegisterForwardGlobal::setCloseSessionCallback(Callback& callback)
	{
		forwardGlobalSync_.closeSessionService().setCallback(callback);
	}

	void
	RegisterForwardGlobal::setNodeNewCallback(Callback& callback)
	{
		forwardGlobalSync_.nodeNewService().setCallback(callback);
	}

	void
	RegisterForwardGlobal::setNodeDeleteCallback(Callback& callback)
	{
		forwardGlobalSync_.nodeDeleteService().setCallback(callback);
	}

	bool
	RegisterForwardGlobal::query(ApplicationServiceIf* applicationServiceIf)
	{
		resultCode_ = Success;

		// create request
		auto trx = constructSPtr<ServiceTransactionRegisterForwardGlobal>();
		trx->request()->forwardGlobalSync()->updateFrom(forwardGlobalSync_);

		// send query to application service
		applicationServiceIf->sendSync(trx);
		resultCode_ = trx->statusCode();
	  	if (resultCode_ != Success) {
	  		return false;
	  	}

		return true;
	}

	OpcUaStatusCode
	RegisterForwardGlobal::resultCode(void)
	{
		return resultCode_;
	}

}
