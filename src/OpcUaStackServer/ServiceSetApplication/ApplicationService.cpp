#include "OpcUaStackCore/Base/Log.h"
#include "OpcUaStackCore/ServiceSetApplication/ApplicationServiceTransaction.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaIdentifier.h"
#include "OpcUaStackServer/ServiceSetApplication/ApplicationService.h"
#include "OpcUaStackServer/AddressSpaceModel/AttributeAccess.h"

namespace OpcUaStackServer
{

	ApplicationService::ApplicationService(void)
	{
	}

	ApplicationService::~ApplicationService(void)
	{
	}

	void 
	ApplicationService::receive(Message::SPtr message)
	{
		ServiceTransaction::SPtr serviceTransaction = boost::static_pointer_cast<ServiceTransaction>(message);

		switch (serviceTransaction->nodeTypeRequest().nodeId<uint32_t>()) 
		{
			case OpcUaId_RegisterForwardRequest_Encoding_DefaultBinary:
				receiveRegisterForwardRequest(serviceTransaction);
				break;
			case OpcUaId_GetNodeReferenceRequest_Encoding_DefaultBinary:
				receiveGetNodeReferenceRequest(serviceTransaction);
				break;
			default:
				Log(Error, "application service received unknown message type")
					.parameter("TypeId", serviceTransaction->nodeTypeRequest());

				serviceTransaction->statusCode(BadInternalError);
				serviceTransaction->componentSession()->send(serviceTransaction);
		}
	}

	void
	ApplicationService::receiveRegisterForwardRequest(ServiceTransaction::SPtr serviceTransaction)
	{
		ServiceTransactionRegisterForward::SPtr trx = boost::static_pointer_cast<ServiceTransactionRegisterForward>(serviceTransaction);

		RegisterForwardRequest::SPtr registerForwardRequest = trx->request();
		RegisterForwardResponse::SPtr registerForwardResponse = trx->response();

		Log(Debug, "application service register forward request")
			.parameter("Trx", serviceTransaction->transactionId())
			.parameter("NumberNodes", registerForwardRequest->nodesToRegister()->size());

		if (registerForwardRequest->nodesToRegister()->size() == 0) {
			trx->responseHeader()->serviceResult(BadNothingToDo);
			trx->componentSession()->send(serviceTransaction);
			return;
		}
		if (registerForwardRequest->nodesToRegister()->size() > 1000) { // FIXME: todo
			trx->responseHeader()->serviceResult(BadTooManyOperations);
			trx->componentSession()->send(serviceTransaction);
			return;
		}

		// register forward
		registerForwardResponse->statusCodeArray()->resize(registerForwardRequest->nodesToRegister()->size());
		for (uint32_t idx = 0; idx < registerForwardRequest->nodesToRegister()->size(); idx++) {
			OpcUaDataValue::SPtr dataValue = OpcUaDataValue::construct();
			registerForwardResponse->statusCodeArray()->set(idx, Success);

			OpcUaNodeId::SPtr nodeId;
			if (!registerForwardRequest->nodesToRegister()->get(idx, nodeId)) {
				registerForwardResponse->statusCodeArray()->set(idx, BadNodeIdInvalid);
				Log(Debug, "register forward error, because node request parameter node id invalid")
					.parameter("Trx", serviceTransaction->transactionId())
					.parameter("Idx", idx);
				continue;
			}

			BaseNodeClass::SPtr baseNodeClass = informationModel_->find(nodeId);
			if (baseNodeClass.get() == nullptr) {
				registerForwardResponse->statusCodeArray()->set(idx, BadNodeIdUnknown);
				Log(Debug, "register forward error, because node not exist in information model")
					.parameter("Trx", serviceTransaction->transactionId())
					.parameter("Idx", idx)
					.parameter("Node", *nodeId);
				continue;
			}

			baseNodeClass->forwardInfoSync(registerForwardRequest->forwardInfoSync());

			Log(Debug, "register forward")
				.parameter("Trx", serviceTransaction->transactionId())
				.parameter("Idx", idx)
				.parameter("Node", *nodeId);
		}

		trx->responseHeader()->serviceResult(Success);
		trx->componentSession()->send(serviceTransaction);
	}

	void
	ApplicationService::receiveGetNodeReferenceRequest(ServiceTransaction::SPtr serviceTransaction)
	{
		ServiceTransactionGetNodeReference::SPtr trx = boost::static_pointer_cast<ServiceTransactionGetNodeReference>(serviceTransaction);

		GetNodeReferenceRequest::SPtr getNodeReferenceRequest = trx->request();
		GetNodeReferenceResponse::SPtr getNodeReferenceResponse = trx->response();

		Log(Debug, "application service get node reference request")
			.parameter("Trx", serviceTransaction->transactionId())
			.parameter("NumberNodes", getNodeReferenceRequest->nodes()->size());

		if (getNodeReferenceRequest->nodes()->size() == 0) {
			trx->responseHeader()->serviceResult(BadNothingToDo);
			trx->componentSession()->send(serviceTransaction);
			return;
		}
		if (getNodeReferenceRequest->nodes()->size() > 1000) { // FIXME: todo
			trx->responseHeader()->serviceResult(BadTooManyOperations);
			trx->componentSession()->send(serviceTransaction);
			return;
		}

		// get node reference
		getNodeReferenceResponse->nodeReferenceArray()->resize(getNodeReferenceRequest->nodes()->size());
		for (uint32_t idx = 0; idx < getNodeReferenceRequest->nodes()->size(); idx++) {
			NodeReference::SPtr nodeReference = NodeReference::construct();
			nodeReference->statusCode(Success);
			getNodeReferenceResponse->nodeReferenceArray()->set(idx, nodeReference);

			OpcUaNodeId::SPtr nodeId;
			if (!getNodeReferenceRequest->nodes()->get(idx, nodeId)) {
				nodeReference->statusCode(BadNodeIdInvalid);
				Log(Debug, "get node reference error, because node request parameter node id invalid")
					.parameter("Trx", serviceTransaction->transactionId())
					.parameter("Idx", idx);
				continue;
			}

			BaseNodeClass::SPtr baseNodeClass = informationModel_->find(nodeId);
			if (baseNodeClass.get() == nullptr) {
				nodeReference->statusCode(BadNodeIdUnknown);
				Log(Debug, "getNodeReference error, because node not exist in information model")
					.parameter("Trx", serviceTransaction->transactionId())
					.parameter("Idx", idx)
					.parameter("Node", *nodeId);
				continue;
			}

			//baseNodeClass->forwardInfo(registerForwardRequest->forwardInfo());

			Log(Debug, "get node reference")
				.parameter("Trx", serviceTransaction->transactionId())
				.parameter("Idx", idx)
				.parameter("Node", *nodeId);
		}

		trx->responseHeader()->serviceResult(Success);
		trx->componentSession()->send(serviceTransaction);

	}

}
