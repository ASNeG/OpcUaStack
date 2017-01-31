/*
   Copyright 2015-2017 Kai Huebl (kai@huebl-sgh.de)

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
#include "OpcUaStackCore/ServiceSetApplication/ApplicationServiceTransaction.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaIdentifier.h"
#include "OpcUaStackServer/ServiceSetApplication/ApplicationService.h"
#include "OpcUaStackServer/ServiceSetApplication/NodeReferenceApplication.h"
#include "OpcUaStackServer/AddressSpaceModel/AttributeAccess.h"
#include "OpcUaStackServer/NodeSet/NodeSetNamespace.h"

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
			case OpcUaId_RegisterForwardGlobalRequest_Encoding_DefaultBinary:
				receiveRegisterForwardGlobalRequest(serviceTransaction);
				break;
			case OpcUaId_GetNodeReferenceRequest_Encoding_DefaultBinary:
				receiveGetNodeReferenceRequest(serviceTransaction);
				break;
			case OpcUaId_NamespaceInfoRequest_Encoding_DefaultBinary:
				receiveNamespaceInfoRequest(serviceTransaction);
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
			trx->statusCode(BadNothingToDo);
			trx->componentSession()->send(serviceTransaction);
			return;
		}
		if (registerForwardRequest->nodesToRegister()->size() > 1000) { // FIXME: todo
			trx->statusCode(BadTooManyOperations);
			trx->componentSession()->send(serviceTransaction);
			return;
		}

		// register forward
		registerForwardResponse->statusCodeArray()->resize(registerForwardRequest->nodesToRegister()->size());
		for (uint32_t idx = 0; idx < registerForwardRequest->nodesToRegister()->size(); idx++) {
			OpcUaDataValue::SPtr dataValue = constructSPtr<OpcUaDataValue>();
			registerForwardResponse->statusCodeArray()->set(idx, Success);

			OpcUaNodeId::SPtr nodeId;
			if (!registerForwardRequest->nodesToRegister()->get(idx, nodeId)) {
				registerForwardResponse->statusCodeArray()->set(idx, BadNodeIdInvalid);
				Log(Debug, "register forward error, because node request parameter node id invalid")
					.parameter("Trx", serviceTransaction->transactionId())
					.parameter("Idx", idx);
				continue;
			}

			// find node
			BaseNodeClass::SPtr baseNodeClass = informationModel_->find(nodeId);
			if (baseNodeClass.get() == nullptr) {
				registerForwardResponse->statusCodeArray()->set(idx, BadNodeIdUnknown);
				Log(Debug, "register forward error, because node not exist in information model")
					.parameter("Trx", serviceTransaction->transactionId())
					.parameter("Idx", idx)
					.parameter("Node", *nodeId);
				continue;
			}

			// create or update forward info
			ForwardInfoSync::SPtr forwardInfoSync = baseNodeClass->forwardInfoSync();
			if (forwardInfoSync.get() == nullptr) {
				forwardInfoSync = registerForwardRequest->forwardInfoSync();
			}
			else {
				forwardInfoSync->updateFrom(*registerForwardRequest->forwardInfoSync());
			}
			baseNodeClass->forwardInfoSync(forwardInfoSync);

			Log(Debug, "register forward")
				.parameter("Trx", serviceTransaction->transactionId())
				.parameter("Idx", idx)
				.parameter("Node", *nodeId);
		}

		trx->statusCode(Success);
		trx->componentSession()->send(serviceTransaction);
	}

	void
	ApplicationService::receiveRegisterForwardGlobalRequest(ServiceTransaction::SPtr serviceTransaction)
	{
		ServiceTransactionRegisterForwardGlobal::SPtr trx = boost::static_pointer_cast<ServiceTransactionRegisterForwardGlobal>(serviceTransaction);

		RegisterForwardGlobalRequest::SPtr registerForwardGlobalRequest = trx->request();
		RegisterForwardGlobalResponse::SPtr registerForwardGlobalResponse = trx->response();

		Log(Debug, "application service register forward global request")
			.parameter("Trx", serviceTransaction->transactionId());

		// FIXME: todo

		trx->statusCode(BadNotImplemented);
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
			trx->statusCode(BadNothingToDo);
			trx->componentSession()->send(serviceTransaction);
			return;
		}
		if (getNodeReferenceRequest->nodes()->size() > 1000) { // FIXME: todo
			trx->statusCode(BadTooManyOperations);
			trx->componentSession()->send(serviceTransaction);
			return;
		}

		// get node reference
		getNodeReferenceResponse->nodeReferenceArray()->resize(getNodeReferenceRequest->nodes()->size());
		for (uint32_t idx = 0; idx < getNodeReferenceRequest->nodes()->size(); idx++) {
			NodeReferenceApplication::SPtr nodeReference = constructSPtr<NodeReferenceApplication>();
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
			nodeReference->baseNodeClass(baseNodeClass);

			Log(Debug, "get node reference")
				.parameter("Trx", serviceTransaction->transactionId())
				.parameter("Idx", idx)
				.parameter("Node", *nodeId);
		}

		trx->statusCode(Success);
		trx->componentSession()->send(serviceTransaction);
	}

	void
	ApplicationService::receiveNamespaceInfoRequest(ServiceTransaction::SPtr serviceTransaction)
	{
		ServiceTransactionNamespaceInfo::SPtr trx = boost::static_pointer_cast<ServiceTransactionNamespaceInfo>(serviceTransaction);

		NamespaceInfoRequest::SPtr namespaceInfoRequest = trx->request();
		NamespaceInfoResponse::SPtr namespaceInfoResponse = trx->response();

		Log(Debug, "application service namespace info request")
			.parameter("Trx", serviceTransaction->transactionId());

		// read global namespaces
		NodeSetNamespace nodeSetNamespace;
		for (uint32_t idx = 0; idx < nodeSetNamespace.globalNamespaceVec().size(); idx++) {
			std::string namespaceName = nodeSetNamespace.globalNamespaceVec()[idx];
			namespaceInfoResponse->index2NamespaceMap().insert(std::make_pair(idx, namespaceName));
			namespaceInfoResponse->namespace2IndexMap().insert(std::make_pair(namespaceName, idx));
		}

		trx->statusCode(Success);
		trx->componentSession()->send(serviceTransaction);
	}

}
