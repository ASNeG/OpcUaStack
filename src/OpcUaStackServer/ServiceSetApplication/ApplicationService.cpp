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
#include "OpcUaStackServer/InformationModel/InformationModelManager.h"
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
			case OpcUaId_RegisterForwardNodeRequest_Encoding_DefaultBinary:
				receiveRegisterForwardNodeRequest(serviceTransaction);
				break;
			case OpcUaId_RegisterForwardMethodRequest_Encoding_DefaultBinary:
				receiveRegisterForwardMethodRequest(serviceTransaction);
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
			case OpcUaId_CreateNodeInstanceRequest_Encoding_DefaultBinary:
				receiveCreateNodeInstanceRequest(serviceTransaction);
				break;
			case OpcUaId_DelNodeInstanceRequest_Encoding_DefaultBinary:
				receiveDelNodeInstanceRequest(serviceTransaction);
				break;
			case OpcUaId_FireEventRequest_Encoding_DefaultBinary:
				receiveFireEventRequest(serviceTransaction);
				break;
			default:
				Log(Error, "application service received unknown message type")
					.parameter("TypeId", serviceTransaction->nodeTypeRequest());

				serviceTransaction->statusCode(BadInternalError);
				serviceTransaction->componentSession()->send(serviceTransaction);
		}
	}

	void
	ApplicationService::receiveRegisterForwardNodeRequest(ServiceTransaction::SPtr serviceTransaction)
	{
		ServiceTransactionRegisterForwardNode::SPtr trx = boost::static_pointer_cast<ServiceTransactionRegisterForwardNode>(serviceTransaction);

		RegisterForwardNodeRequest::SPtr registerForwardNodeRequest = trx->request();
		RegisterForwardNodeResponse::SPtr registerForwardNodeResponse = trx->response();

		Log(Debug, "application service register forward node request")
			.parameter("Trx", serviceTransaction->transactionId())
			.parameter("NumberNodes", registerForwardNodeRequest->nodesToRegister()->size());

		if (registerForwardNodeRequest->nodesToRegister()->size() == 0) {
			trx->statusCode(BadNothingToDo);
			trx->componentSession()->send(serviceTransaction);
			return;
		}
		if (registerForwardNodeRequest->nodesToRegister()->size() > 1000) { // FIXME: todo
			trx->statusCode(BadTooManyOperations);
			trx->componentSession()->send(serviceTransaction);
			return;
		}

		// register forward
		registerForwardNodeResponse->statusCodeArray()->resize(registerForwardNodeRequest->nodesToRegister()->size());
		for (uint32_t idx = 0; idx < registerForwardNodeRequest->nodesToRegister()->size(); idx++) {
			OpcUaDataValue::SPtr dataValue = constructSPtr<OpcUaDataValue>();
			registerForwardNodeResponse->statusCodeArray()->set(idx, Success);

			OpcUaNodeId::SPtr nodeId;
			if (!registerForwardNodeRequest->nodesToRegister()->get(idx, nodeId)) {
				registerForwardNodeResponse->statusCodeArray()->set(idx, BadNodeIdInvalid);
				Log(Debug, "register forward node error, because node request parameter node id invalid")
					.parameter("Trx", serviceTransaction->transactionId())
					.parameter("Idx", idx);
				continue;
			}

			// find node
			BaseNodeClass::SPtr baseNodeClass = informationModel_->find(nodeId);
			if (baseNodeClass.get() == nullptr) {
				registerForwardNodeResponse->statusCodeArray()->set(idx, BadNodeIdUnknown);
				Log(Debug, "register forward node error, because node not exist in information model")
					.parameter("Trx", serviceTransaction->transactionId())
					.parameter("Idx", idx)
					.parameter("Node", *nodeId);
				continue;
			}

			// create or update forward info
			ForwardNodeSync::SPtr forwardNodeSync = baseNodeClass->forwardNodeSync();
			if (forwardNodeSync.get() == nullptr) {
				forwardNodeSync = registerForwardNodeRequest->forwardNodeSync();
			}
			else {
				forwardNodeSync->updateFrom(*registerForwardNodeRequest->forwardNodeSync());
			}
			baseNodeClass->forwardNodeSync(forwardNodeSync);

			Log(Debug, "register forward node")
				.parameter("Trx", serviceTransaction->transactionId())
				.parameter("Idx", idx)
				.parameter("Node", *nodeId);
		}

		trx->statusCode(Success);
		trx->componentSession()->send(serviceTransaction);
	}

	void
	ApplicationService::receiveRegisterForwardMethodRequest(ServiceTransaction::SPtr serviceTransaction)
	{
		BaseNodeClass::SPtr baseNodeClass;
		ServiceTransactionRegisterForwardMethod::SPtr trx = boost::static_pointer_cast<ServiceTransactionRegisterForwardMethod>(serviceTransaction);

		RegisterForwardMethodRequest::SPtr registerForwardMethodRequest = trx->request();
		RegisterForwardMethodResponse::SPtr registerForwardMethodResponse = trx->response();

		Log(Debug, "application service register forward method request")
			.parameter("Trx", serviceTransaction->transactionId())
			.parameter("ObjectNodeId", registerForwardMethodRequest->objectNodeId().toString())
			.parameter("MethodNodeId", registerForwardMethodRequest->methodNodeId().toString());

		// find object node
		baseNodeClass = informationModel_->find(registerForwardMethodRequest->objectNodeId());
		if (baseNodeClass.get() == nullptr) {
			registerForwardMethodResponse->statusCode(BadNodeIdUnknown);
			Log(Debug, "register forward method error, because object node not exist in information model")
				.parameter("Trx", serviceTransaction->transactionId())
				.parameter("ObjectNode", registerForwardMethodRequest->objectNodeId().toString());

			trx->statusCode(Success);
			trx->componentSession()->send(serviceTransaction);
			return;
		}

		// find method node
		baseNodeClass = informationModel_->find(registerForwardMethodRequest->methodNodeId());
		if (baseNodeClass.get() == nullptr) {
			registerForwardMethodResponse->statusCode(BadNodeIdUnknown);
			Log(Debug, "register forward method error, because function node not exist in information model")
				.parameter("Trx", serviceTransaction->transactionId())
				.parameter("MethodNode", registerForwardMethodRequest->methodNodeId().toString());

			trx->statusCode(Success);
			trx->componentSession()->send(serviceTransaction);
			return;
		}

		// register/deregister method call
		if (!registerForwardMethodRequest->forwardMethodSync()->methodService().isCallback()) {
			informationModel_->methodMap().deregisterMethod(
				registerForwardMethodRequest->objectNodeId(),
				registerForwardMethodRequest->methodNodeId()
			);
		}
		else {
			informationModel_->methodMap().registerMethod(
				registerForwardMethodRequest->objectNodeId(),
				registerForwardMethodRequest->methodNodeId(),
				registerForwardMethodRequest->forwardMethodSync()
			);
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

		forwardGlobalSync()->updateFrom(*registerForwardGlobalRequest->forwardGlobalSync());

		trx->statusCode(Success);
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

	void
	ApplicationService::receiveCreateNodeInstanceRequest(ServiceTransaction::SPtr serviceTransaction)
	{
		ServiceTransactionCreateNodeInstance::SPtr trx = boost::static_pointer_cast<ServiceTransactionCreateNodeInstance>(serviceTransaction);

		CreateNodeInstanceRequest::SPtr createNodeInstanceRequest = trx->request();
		CreateNodeInstanceResponse::SPtr createNodeInstanceResponse = trx->response();

		Log(Debug, "application service create node instance request")
			.parameter("Trx", serviceTransaction->transactionId());

		//
		// create new node instance
		//
		AddNodeRule addNodeRule;
		addNodeRule.delemiter("/");
		addNodeRule.displayPath(createNodeInstanceRequest->name());
		InformationModelManager imm(informationModel_);
		bool success = imm.addNode(
			createNodeInstanceRequest->nodeClassType(),
			addNodeRule,
			createNodeInstanceRequest->parentNodeId(),
			createNodeInstanceRequest->nodeId(),
			createNodeInstanceRequest->displayName(),
			createNodeInstanceRequest->browseName(),
			createNodeInstanceRequest->referenceNodeId(),
			createNodeInstanceRequest->typeNodeId()
		);

		if (success) {
			trx->statusCode(Success);
		}
		else {
			trx->statusCode(BadInternalError);
		}
		trx->componentSession()->send(serviceTransaction);
	}

	void
	ApplicationService::receiveDelNodeInstanceRequest(ServiceTransaction::SPtr serviceTransaction)
	{
		ServiceTransactionDelNodeInstance::SPtr trx = boost::static_pointer_cast<ServiceTransactionDelNodeInstance>(serviceTransaction);

		DelNodeInstanceRequest::SPtr delNodeInstanceRequest = trx->request();
		DelNodeInstanceResponse::SPtr delNodeInstanceResponse = trx->response();

		Log(Debug, "application service del node instance request")
			.parameter("Trx", serviceTransaction->transactionId());

		//
		// create new node instance
		//
		InformationModelManager imm(informationModel_);
		bool success = imm.delNode(
			delNodeInstanceRequest->nodeId()
		);

		if (success) {
			trx->statusCode(Success);
		}
		else {
			trx->statusCode(BadInternalError);
		}
		trx->componentSession()->send(serviceTransaction);
	}

	void
	ApplicationService::receiveFireEventRequest(ServiceTransaction::SPtr serviceTransaction)
	{
		ServiceTransactionFireEvent::SPtr trx = boost::static_pointer_cast<ServiceTransactionFireEvent>(serviceTransaction);

		FireEventRequest::SPtr fireEventRequest = trx->request();
		FireEventResponse::SPtr fireEventResponse = trx->response();

		// FIXME: todo - fire event handling

		trx->statusCode(Success);
		trx->componentSession()->send(serviceTransaction);
	}

}
