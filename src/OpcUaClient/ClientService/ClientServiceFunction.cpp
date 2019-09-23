/*
   Copyright 2016-2019 Kai Huebl (kai@huebl-sgh.de)

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

#include "OpcUaClient/ClientCommand/CommandFunction.h"
#include "OpcUaClient/ClientService/ClientServiceFunction.h"

using namespace OpcUaStackCore;
using namespace OpcUaStackClient;

namespace OpcUaClient
{

	ClientServiceFunction::ClientServiceFunction(void)
	: ClientServiceBase()
	{
	}

	ClientServiceFunction::~ClientServiceFunction(void)
	{
	}

	ClientServiceBase::SPtr
	ClientServiceFunction::createClientService(void)
	{
		return boost::make_shared<ClientServiceFunction>();
	}

	bool
	ClientServiceFunction::run(ClientServiceManager& clientServiceManager, CommandBase::SPtr& commandBase)
	{
		OpcUaStatusCode statusCode;
		CommandFunction::SPtr commandFunction = boost::static_pointer_cast<CommandFunction>(commandBase);

		// create new or get existing client object
		ClientAccessObject::SPtr clientAccessObject;
		clientAccessObject = clientServiceManager.getClientAccessObject(commandFunction->session());
		if (clientAccessObject.get() == nullptr) {
			std::stringstream ss;
			ss << "get client access object failed:"
			   << " Session=" << commandFunction->session();
			errorMessage(ss.str());
			return false;
		}

		// check session
		if (clientAccessObject->sessionService_.get() == nullptr) {
			std::stringstream ss;
			ss << "session object not exist: "
			   << " Session=" << commandFunction->session();
			return false;
		}

		// get or create method service
		MethodService::SPtr methodService;
		methodService = clientAccessObject->getOrCreateMethodService();
		if (methodService.get() == nullptr) {
			std::stringstream ss;
			ss << "get client method service failed"
			   << " Session=" << commandFunction->session();
			errorMessage(ss.str());
			return false;
		}

		// create method request
		ServiceTransactionCall::SPtr trx = boost::make_shared<ServiceTransactionCall>();
		CallRequest::SPtr req = trx->request();

		CallMethodRequest::SPtr callMethodRequest = boost::make_shared<CallMethodRequest>();
		callMethodRequest->objectId()->copyFrom(commandFunction->objectNodeId());
		callMethodRequest->methodId()->copyFrom(commandFunction->functionNodeId());
		callMethodRequest->inputArguments()->resize(commandFunction->inputVariantVec().size());
		for (uint32_t idx=0; idx<commandFunction->inputVariantVec().size(); idx++) {
			callMethodRequest->inputArguments()->set(idx, commandFunction->inputVariantVec()[idx]);
		}

		req->methodsToCall()->resize(1);
		req->methodsToCall()->set(0, callMethodRequest);

		// send read request
	    methodService->syncSend(trx);

		// process function response
		statusCode = trx->statusCode();
		if (statusCode != Success) {
			std::stringstream ss;
			ss << "function error: "
			   << " Session=" << commandFunction->session()
			   << " StatusCode=" << OpcUaStatusCodeMap::shortString(statusCode);
			errorMessage(ss.str());
			return false;
		}

		CallResponse::SPtr res = trx->response();
		if (res->results()->size() == 0) {
			std::stringstream ss;
			ss << "function response length error: "
			   << " Session=" << commandFunction->session();
			errorMessage(ss.str());
			return false;
		}

		for (uint32_t idx=0; idx<res->results()->size(); idx++) {
			CallMethodResult::SPtr callMethodResult;
			res->results()->get(idx, callMethodResult);

			if (callMethodResult->statusCode() != Success) {
				std::cout << OpcUaStatusCodeMap::shortString(callMethodResult->statusCode()) << std::endl;
				return false;
			}

			uint32_t args = callMethodResult->outputArguments()->size();
			for (uint32_t pos = 0; pos < args; pos++) {
				OpcUaVariant::SPtr variant;
				callMethodResult->outputArguments()->get(pos, variant);
				variant->out(std::cout); std::cout << std::endl;
			}

			std::cout << OpcUaStatusCodeMap::shortString(callMethodResult->statusCode()) << std::endl;
		}

		return true;
	}

}

