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
#include "OpcUaStackServer/Forward/ForwardServiceTransaction.h"

using namespace OpcUaStackCore;

namespace OpcUaStackServer
{

	MethodService::MethodService(
		const std::string& serviceName,
		OpcUaStackCore::IOThread::SPtr& ioThread,
		OpcUaStackCore::MessageBus::SPtr& messageBus
	)
	: ServerServiceBase()
	{
		// set parameter in server service base
		serviceName_ = serviceName;
		ServerServiceBase::ioThread_ = ioThread.get();
		strand_ = ioThread->createStrand();
		messageBus_ = messageBus;

		// register message bus receiver
		MessageBusMemberConfig messageBusMemberConfig;
		messageBusMemberConfig.strand(strand_);
		messageBusMember_ = messageBus_->registerMember(serviceName_, messageBusMemberConfig);

		// init forward manager. The forward manager is used to transfer transaction
		// asynchronously to an application.
		auto sendTrxCallback = [this](
			ForwardTransaction::SPtr& forwardTransaction
		)
		{
			sendTrxForwardAsync(forwardTransaction);
		};
		auto recvTrxCallback = [this](
			OpcUaStackCore::OpcUaStatusCode statusCode,
			OpcUaStackCore::ServiceTransaction::SPtr& serviceTransaction,
			ForwardTransaction::SPtr& forwardTransaction
		)
		{
			recvTrxForwardAsync(statusCode, serviceTransaction, forwardTransaction);
		};
		auto finishTrxCallback = [this](
			OpcUaStackCore::ServiceTransaction::SPtr& serviceTransaction
		)
		{
			finishTrxForwardAsync(serviceTransaction);
		};

		forwardManager_ = boost::make_shared<ForwardManager>(
			ioThread_,
			strand_,
			sendTrxCallback,
			recvTrxCallback,
			finishTrxCallback
		);


		// activate receiver
		activateReceiver(
			[this](const OpcUaStackCore::MessageBusMember::WPtr& handleFrom, Message::SPtr& message){
				receive(handleFrom, message);
			}
		);
	}

	MethodService::~MethodService(void)
	{
		// deactivate receiver
		deactivateReceiver();
		messageBus_->deregisterMember(messageBusMember_);
	}

	void 
	MethodService::receive(
		const OpcUaStackCore::MessageBusMember::WPtr& handleFrom,
		OpcUaStackCore::ServiceTransaction::SPtr& serviceTransaction
	)
	{
		// We have to remeber the sender of the message. This enables us to
		// send a reply for the received message later
		serviceTransaction->memberServiceSession(handleFrom);

		switch (serviceTransaction->nodeTypeRequest().nodeId<uint32_t>())
		{
			case OpcUaId_CallRequest_Encoding_DefaultBinary:
				receiveCallRequest(serviceTransaction);
				break;
			default:
				serviceTransaction->statusCode(BadInternalError);
				sendAnswer(serviceTransaction);
		}
	}

	void
	MethodService::receive(
		const MessageBusMember::WPtr& handleFrom,
		ForwardTransaction::SPtr& forwardTransaction
	)
	{
		// receive forward transaction from application. The received forward
		// transaction must be passed to the forward manager.
		forwardManager_->recvTrx(forwardTransaction);
	}

	void
	MethodService::receive(
		const MessageBusMember::WPtr& handleFrom,
		Message::SPtr& message
	)
	{
		if (message->type_ == Message::ServiceTransaction) {
			// receive message from session component
			auto serviceTransaction = boost::static_pointer_cast<ServiceTransaction>(message);
			receive(handleFrom, serviceTransaction);
		}
		else if (message->type_ == Message::ForwardTransaction) {
			// receive message from application component
			auto forwardTransaction = boost::static_pointer_cast<ForwardTransaction>(message);
			receive(handleFrom, forwardTransaction);
		}
		else {
			Log(Error, "receive invalid message type in attribute service")
				.parameter("Type", message->type_);
		}
	}

	void
	MethodService::sendAnswer(OpcUaStackCore::ServiceTransaction::SPtr& serviceTransaction)
	{
		messageBus_->messageSend(
			messageBusMember_,
			serviceTransaction->memberServiceSession(),
			serviceTransaction
		);
	}

	// --------------------------------------------------------------------
	//
	// The following functions are used for asynchronously communication
	// with the application.
	//
	// --------------------------------------------------------------------
	void
	MethodService::sendTrxForwardAsync(
		ForwardTransaction::SPtr& forwardTransaction
	)
	{
		//
		// This function is called by the forward manager when a transaction
		// is to be send to the application.
		//

		// check message bus member source
		auto messageBusMemberSource = messageBusMember_.lock();
		if (!messageBusMemberSource) {
			Log(Error, "send async forward request error in method service, because source message bus member empty")
				.parameter("Name", forwardTransaction->name());
			return;
		}

		// check message bus member target
		auto messageBusMemberTarget = forwardTransaction->messageBusMemberTarget().lock();
		if (!messageBusMemberTarget) {
			Log(Error, "send async forward request error in method service, because target message bus member empty")
				.parameter("Name", forwardTransaction->name());
			return;
		}

		// send forward message to application
		Log(Debug, "send async request")
		    .parameter("Name", forwardTransaction->name())
			.parameter("Sender", messageBusMemberSource->name())
			.parameter("Receiver", messageBusMemberTarget->name());
		messageBus_->messageSend(
			messageBusMember_,
			forwardTransaction->messageBusMemberTarget(),
			forwardTransaction
		);
	}

	void
	MethodService::recvTrxForwardAsync(
		OpcUaStackCore::OpcUaStatusCode statusCode,
		OpcUaStackCore::ServiceTransaction::SPtr& serviceTransaction,
		ForwardTransaction::SPtr& forwardTransaction
	)
	{
		//
		// This function is called by the forward manager when a transaction
		// is received from the application or the transaction has timed out.
		//
		switch (forwardTransaction->nodeTypeResponse().nodeId<uint32_t>())
		{
			case OpcUaId_ForwardTransactionMethodResponse_Encoding_DefaultBinary:
			{
				forwardCallAsyncResponse(
					statusCode,
					serviceTransaction,
					forwardTransaction
				);
				break;
			}
		}
	}

	void
	MethodService::finishTrxForwardAsync(
		OpcUaStackCore::ServiceTransaction::SPtr& serviceTransaction
	)
	{
		//
		// This function is called by the forward manager when the forward
		// job is completed.
		//
		serviceTransaction->statusCode(Success);
		sendAnswer(serviceTransaction);
	}

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// call service
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
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
			sendAnswer(serviceTransaction);
			return;
		}
		if (callRequest->methodsToCall()->size() > 1000) { // FIXME: todo
			trx->statusCode(BadTooManyOperations);
			sendAnswer(serviceTransaction);
			return;
		}

		// create forward job
		auto forwardJob = forwardManager_->createJob(serviceTransaction);

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

			// forward read async request
			bool rc = forwardCallAsync(
				forwardJob,
				serviceTransaction->userContext(),
				baseNodeClass,
				idx,
				trx
			);
			if (rc) {
				// the operation is performed asynchronously
				continue;
			}

			// find registered method call in information model
			ForwardMethodSync::SPtr forwardMethodSync;
			forwardMethodSync = informationModel_->methodMap().getMethodSync(*callMethod->objectId(), *callMethod->methodId());
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

			// call forward callbacks
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

		// If there are no asynchronously transactions, the request can be answered
		// immediately.
		if (forwardJob->countPendingTrx() == 0) {
			trx->statusCode(Success);
			sendAnswer(serviceTransaction);
			return;
		}

		// If there are asynchronously transactions, the asynchronously job must
		// be executed.
		forwardManager_->startJob(forwardJob);
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

	void
	MethodService::forwardCallAsyncResponse(
		OpcUaStackCore::OpcUaStatusCode statusCode,
		OpcUaStackCore::ServiceTransaction::SPtr& serviceTransaction,
		ForwardTransaction::SPtr& forwardTransaction
	)
	{
		// get service data
		auto serviceTrx = boost::static_pointer_cast<ServiceTransactionCall>(serviceTransaction);
		auto serviceReq = serviceTrx->request();
		auto serviceResp = serviceTrx->response();

		CallMethodResult::SPtr callMethodResult;
		serviceResp->results()->get(forwardTransaction->idx(), callMethodResult);

		// check status code
		if (statusCode != Success) {
			callMethodResult->statusCode(statusCode);
			return;
		}

		// check status code of forward transaction
		if (forwardTransaction->statusCode() != Success) {
			callMethodResult->statusCode(statusCode);
			return;
		}

		//  get forward data
		auto forwardTrx = boost::static_pointer_cast<ForwardTransactionCall>(forwardTransaction);
		auto forwardReq = forwardTrx->request();
		auto forwardResp = forwardTrx->response();

		// set call result
		forwardResp->result()->copyTo(*callMethodResult);
	}

	bool
	MethodService::forwardCallAsync(
		ForwardJob::SPtr& forwardJob,
		UserContext::SPtr& userContext,
		BaseNodeClass::SPtr baseNodeClass,
		uint32_t idx,
		ServiceTransactionCall::SPtr& readTrx
	)
	{
		auto serviceReq = readTrx->request();
		auto serviceRes = readTrx->response();

		// check if async forwarding is enabled
		CallMethodRequest::SPtr callMethodRequest;
		serviceReq->methodsToCall()->get(idx, callMethodRequest);

		// find registered method call in information model
		ForwardMethodAsync::SPtr forwardMethodAsync;
		forwardMethodAsync = informationModel_->methodMap().getMethodAsync(
			*callMethodRequest->objectId(), *callMethodRequest->methodId()
		);
		if (forwardMethodAsync.get() == nullptr) return false;
		if (!forwardMethodAsync->methodService().isActive()) return false;

		// create new transaction
		auto forwardTrx = boost::make_shared<ForwardTransactionCall>();
		auto forwardReq = forwardTrx->request();
		auto forwardRes = forwardTrx->response();

		// set request parameter
		forwardReq->callMethodRequest(callMethodRequest);

		// set transaction parameter
		forwardTrx->name("AsyncMethod");
		forwardTrx->messageBusMemberTarget(forwardMethodAsync->methodService().messageBusMember());
		forwardTrx->forwardJob(forwardJob);
		forwardTrx->idx(idx);
		forwardTrx->complete(false);
		forwardTrx->userContext(userContext);
		forwardTrx->applicationContext(forwardMethodAsync->methodService().applicationContext());

		// add forward transaction to forward job
		ForwardTransaction::SPtr trx = forwardTrx;
		forwardManager_->addTrx(forwardJob, trx);

		Log(Debug, "handle call operation asynchronously")
			.parameter("ObjectNodeId", *callMethodRequest->objectId())
			.parameter("MethodNodeId", *callMethodRequest->methodId());
		return true;
	}

}
