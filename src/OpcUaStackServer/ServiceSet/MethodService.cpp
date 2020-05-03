/*
   Copyright 2015-2020 Kai Huebl (kai@huebl-sgh.de)

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

#include "OpcUaStackCore/Base/Log.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaIdentifier.h"
#include "OpcUaStackCore/Application/ApplicationAutorizationContext.h"
#include "OpcUaStackCore/Application/ApplicationMethodContext.h"
#include "OpcUaStackCore/ServiceSet/MethodServiceTransaction.h"
#include "OpcUaStackServer/ServiceSet/MethodService.h"

using namespace OpcUaStackCore;

namespace OpcUaStackServer
{

	MethodService::MethodService(void)
	: ServerServiceBase()
	{
	}

	MethodService::~MethodService(void)
	{
	}

	void 
	MethodService::receive(Message::SPtr message)
	{
		ServiceTransaction::SPtr serviceTransaction = boost::static_pointer_cast<ServiceTransaction>(message);
		switch (serviceTransaction->nodeTypeRequest().nodeId<uint32_t>())
		{
			case OpcUaId_CallRequest_Encoding_DefaultBinary:
				receiveCallRequest(serviceTransaction);
				break;
			default:
				serviceTransaction->statusCode(BadInternalError);
				serviceTransaction->componentSession()->send(serviceTransaction);
		}
	}

	void 
	MethodService::receiveCallRequest(ServiceTransaction::SPtr serviceTransaction)
	{
		OpcUaStatusCode statusCode;

		BaseNodeClass::SPtr baseNodeClass;
		ServiceTransactionCall::SPtr trx = boost::static_pointer_cast<ServiceTransactionCall>(serviceTransaction);

		CallRequest::SPtr callRequest = trx->request();
		CallResponse::SPtr callResponse = trx->response();

		Log(Debug, "method service call request")
			.parameter("Trx", serviceTransaction->transactionId())
			.parameter("NumberCalls", callRequest->methodsToCall()->size());

		// check node id array
		if (callRequest->methodsToCall()->size() == 0) {
			trx->statusCode(BadNothingToDo);
			trx->componentSession()->send(serviceTransaction);
			return;
		}
		if (callRequest->methodsToCall()->size() > 1000) { // FIXME: todo
			trx->statusCode(BadTooManyOperations);
			trx->componentSession()->send(serviceTransaction);
			return;
		}

		// call methods
		callResponse->results()->resize(callRequest->methodsToCall()->size());
		for (uint32_t idx = 0; idx < callRequest->methodsToCall()->size(); idx++) {
			CallMethodResult::SPtr callMethodResult = boost::make_shared<CallMethodResult>();
			callResponse->results()->set(idx, callMethodResult);

			// determine node information
			CallMethodRequest::SPtr callMethod;
			if (!callRequest->methodsToCall()->get(idx, callMethod)) {
				callMethodResult->statusCode(BadNodeIdInvalid);
				Log(Debug, "call method error, because call request parameter invalid")
					.parameter("Trx", serviceTransaction->transactionId())
					.parameter("Idx", idx);
				continue;
			}

			// find object node class instance for the node
			baseNodeClass = informationModel_->find(callMethod->objectId());
			if (baseNodeClass.get() == nullptr) {
				callMethodResult->statusCode(BadNodeIdUnknown);
				Log(Debug, "call method error, because object node not exist in information model")
					.parameter("Trx", serviceTransaction->transactionId())
					.parameter("Idx", idx)
					.parameter("ObjectNode", *callMethod->objectId())
					.parameter("MethodNode", *callMethod->methodId());
				continue;
			}

			// find method node class instance for the node
			BaseNodeClass::SPtr baseNodeClass = informationModel_->find(callMethod->methodId());
			if (baseNodeClass.get() == nullptr) {
				callMethodResult->statusCode(BadNodeIdUnknown);
				Log(Debug, "call method error, because method node not exist in information model")
					.parameter("Trx", serviceTransaction->transactionId())
					.parameter("Idx", idx)
					.parameter("ObjectNode", *callMethod->objectId())
					.parameter("MethodNode", *callMethod->methodId());
				continue;
			}

			// find registered method call in information model
			ForwardMethodSync::SPtr forwardMethodSync;
			forwardMethodSync = informationModel_->methodMap().getMethod(*callMethod->objectId(), *callMethod->methodId());
			if (forwardMethodSync.get() == nullptr) {
				callMethodResult->statusCode(BadServiceUnsupported);
				Log(Debug, "call method error, because service not supported")
			 		.parameter("Trx", serviceTransaction->transactionId())
					.parameter("Idx", idx)
					.parameter("ObjectNode", *callMethod->objectId())
					.parameter("MethodNode", *callMethod->methodId());
				continue;
			}

			if (!forwardMethodSync->methodService().isCallback()) {
				callMethodResult->statusCode(BadServiceUnsupported);
				Log(Debug, "call method error, because service not supported")
					.parameter("Trx", serviceTransaction->transactionId())
					.parameter("Idx", idx)
					.parameter("ObjectNode", *callMethod->objectId())
					.parameter("MethodNode", *callMethod->methodId());
				continue;
			}

			// autorization
			statusCode = forwardAuthorizationMethod(
				serviceTransaction->userContext(),
				*callMethod->objectId(),
				*callMethod->methodId()
			);
			if (statusCode != Success) {
				callMethodResult->statusCode(statusCode);
				continue;
			}

			// call forward calbacks
			ApplicationMethodContext applicationMethodContext;
			applicationMethodContext.objectNodeId_ = *callMethod->objectId();
			applicationMethodContext.methodNodeId_ = *callMethod->methodId();
			applicationMethodContext.inputArguments_ = callMethod->inputArguments();
			applicationMethodContext.outputArguments_ = boost::make_shared<OpcUaVariantArray>();
			applicationMethodContext.statusCode_ = Success;
			applicationMethodContext.applicationContext_ = forwardMethodSync->methodService().applicationContext();
			applicationMethodContext.userContext_ = serviceTransaction->userContext();

			forwardMethodSync->methodService().callback()(&applicationMethodContext);

			// check response
			callMethodResult->statusCode(applicationMethodContext.statusCode_);
			callMethodResult->outputArguments(applicationMethodContext.outputArguments_);

			if (applicationMethodContext.statusCode_ != Success) {
				Log(Debug, "call value error, because service process failed")
					.parameter("Trx", serviceTransaction->transactionId())
					.parameter("Idx", idx)
					.parameter("ObjectNode", *callMethod->objectId())
					.parameter("MethodNode", *callMethod->methodId())
					.parameter("StatusCode", OpcUaStatusCodeMap::shortString(applicationMethodContext.statusCode_));
				continue;
			}
		}

		serviceTransaction->componentSession()->send(serviceTransaction);
	}

	OpcUaStatusCode
	MethodService::forwardAuthorizationMethod(
		UserContext::SPtr& userContext,
		OpcUaNodeId& objectNodeId,
		OpcUaNodeId& funcNodeId
	)
	{
		if (forwardGlobalSync().get() == nullptr) return Success;
		if (!forwardGlobalSync()->autorizationService().isCallback()) return Success;

		ApplicationAutorizationContext context;
		context.userContext_ = userContext;
		context.serviceOperation_ = ServiceOperation::Method;
		context.nodeId_ = objectNodeId;
		context.nodeId1_ = funcNodeId;

		forwardGlobalSync()->autorizationService().callback()(&context);

		return context.statusCode_;
	}

}
