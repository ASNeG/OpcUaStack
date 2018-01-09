/*
   Copyright 2015-2018 Kai Huebl (kai@huebl-sgh.de)

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
#include "OpcUaStackServer/InformationModel/InformationModelAccess.h"
#include "OpcUaStackServer/InformationModel/NamespaceArray.h"
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
			case OpcUaId_BrowsePathToNodeIdRequest_Encoding_DefaultBinary:
				receiveBrowsePathToNodeIdRequest(serviceTransaction);
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
		bool applicationContextArray = false;
		if (registerForwardNodeRequest->applicationContextArray()->size() == registerForwardNodeRequest->nodesToRegister()->size()) {
			applicationContextArray = true;
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
				forwardNodeSync = constructSPtr<ForwardNodeSync>();
			}
			forwardNodeSync->updateFrom(*registerForwardNodeRequest->forwardNodeSync());
			if (applicationContextArray) {
				BaseClass::SPtr baseClass;
				registerForwardNodeRequest->applicationContextArray()->get(idx, baseClass);
				if (baseClass.get() != nullptr) {
					forwardNodeSync->writeService().applicationContext(baseClass);
					forwardNodeSync->readService().applicationContext(baseClass);
					forwardNodeSync->writeService().applicationContext(baseClass);
					forwardNodeSync->readHService().applicationContext(baseClass);
					forwardNodeSync->methodService().applicationContext(baseClass);
					forwardNodeSync->monitoredItemStartService().applicationContext(baseClass);
					forwardNodeSync->monitoredItemStopService().applicationContext(baseClass);
				}
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

		// register new namespace
		NodeSetNamespace nodeSetNamespace;
		if (namespaceInfoRequest->newNamespaceUri() != "") {
			nodeSetNamespace.addNewGlobalNamespace(namespaceInfoRequest->newNamespaceUri());

			NamespaceArray nsa;
			nsa.informationModel(informationModel_);
			nsa.addNamespaceName(namespaceInfoRequest->newNamespaceUri());
		}

		// read global namespaces
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

		//
		// find object node
		//
		BaseNodeClass::SPtr baseNodeClass = informationModel_->find(fireEventRequest->nodeId());
		if (baseNodeClass.get() == nullptr) {
			Log(Debug, "fire event error, because node not exist in information model")
				.parameter("Trx", serviceTransaction->transactionId())
				.parameter("Node", fireEventRequest->nodeId());

			trx->statusCode(BadNodeIdUnknown);
			trx->componentSession()->send(serviceTransaction);
			return;
		}

		//
		// get nodes from event hierarchy
		//
		std::vector<OpcUaNodeId> nodeIdVec;
		std::vector<OpcUaNodeId>::iterator nodeIt;;

		std::set<OpcUaNodeId> duplicateNodeIdSet;
		std::set<OpcUaNodeId> workNodeIdSet;

		workNodeIdSet.insert(fireEventRequest->nodeId());

		while (workNodeIdSet.size() != 0)
		{
			// get first node from node id set
			OpcUaNodeId nodeId = *workNodeIdSet.begin();
			workNodeIdSet.erase(workNodeIdSet.begin());

			nodeIdVec.push_back(nodeId);
			duplicateNodeIdSet.insert(nodeId);

			// get base class
			BaseNodeClass::SPtr node = informationModel_->find(nodeId);
			if (node.get() == nullptr) continue;

			// get all parent nodes of event notifier reference (backward)
			InformationModelAccess ima(informationModel_);
			OpcUaNodeId referenceTypeNodeId(OpcUaId_HasNotifier);
			std::vector<OpcUaNodeId> parentNodeIdVec;
			bool success = ima.getParentHierarchically(
				baseNodeClass,
				referenceTypeNodeId,
				parentNodeIdVec
			);
			if (!success) {
				continue;
			}

			std::vector<OpcUaNodeId>::iterator itpn;
			for (itpn = parentNodeIdVec.begin(); itpn != parentNodeIdVec.end(); itpn++) {
				// check duplicate
				if (duplicateNodeIdSet.find(*itpn) != duplicateNodeIdSet.end()) {
					continue;
				}
				workNodeIdSet.insert(*itpn);
			}
		};

		//
		// find event filter
		//
		EventHandlerMap& eventHandlerMap = informationModel_->eventHandlerMap();

		EventHandlerBase::Vec eventHandlerBaseVec;
		EventHandlerBase::Vec::iterator it;

		for (nodeIt = nodeIdVec.begin(); nodeIt != nodeIdVec.end(); nodeIt++) {
			boost::mutex::scoped_lock g(eventHandlerMap.mutex());
			eventHandlerMap.getEvent(*nodeIt, eventHandlerBaseVec);
			for (it = eventHandlerBaseVec.begin(); it != eventHandlerBaseVec.end(); it++) {
				EventHandlerBase::SPtr eventHandlerBase = *it;

				Log(Debug, "fire event")
				    .parameter("NumberEvents", eventHandlerBaseVec.size())
					.parameter("Node", fireEventRequest->nodeId())
					.parameter("EventId", eventHandlerBase->eventId());

				eventHandlerBase->fireEvent(fireEventRequest->nodeId(), fireEventRequest->eventBase());
			}
		}

		trx->statusCode(Success);
		trx->componentSession()->send(serviceTransaction);
	}

	void
	ApplicationService::receiveBrowsePathToNodeIdRequest(ServiceTransaction::SPtr serviceTransaction)
	{
		ServiceTransactionBrowsePathToNodeId::SPtr trx = boost::static_pointer_cast<ServiceTransactionBrowsePathToNodeId>(serviceTransaction);

		BrowsePathToNodeIdRequest::SPtr req = trx->request();
		BrowsePathToNodeIdResponse::SPtr res = trx->response();

		uint32_t size = req->browseNameArray()->size();
		if (size == 0) {
			trx->statusCode(BadInvalidArgument);
			trx->componentSession()->send(serviceTransaction);
		}

		res->nodeIdResults()->resize(size);
		for (uint32_t idx = 0; idx < size; idx++) {
			BrowseName::SPtr browseName;
			req->browseNameArray()->get(idx, browseName);
			NodeIdResult::SPtr nodeIdResult = constructSPtr<NodeIdResult>();

			getNodeIdFromBrowsePath(browseName, nodeIdResult);
			res->nodeIdResults()->set(idx, nodeIdResult);
		}

		trx->statusCode(Success);
		trx->componentSession()->send(serviceTransaction);
	}

	void
	ApplicationService::getNodeIdFromBrowsePath(
		BrowseName::SPtr& browseName,
		NodeIdResult::SPtr& nodeIdResult
	)
	{
		//
		// check parameter
		//
		if (browseName->pathNames()->size() == 0) {
			nodeIdResult->nodeId(browseName->nodeId());
			nodeIdResult->statusCode(Success);
			return;
		}

		//
		// find object node
		//
		BaseNodeClass::SPtr baseNodeClass = informationModel_->find(browseName->nodeId());
		if (baseNodeClass.get() == nullptr) {
			Log(Debug, "browse path from node id error, because node not exist in information model")
				.parameter("Node", browseName->nodeId());

			nodeIdResult->statusCode(BadNodeIdUnknown);
			return;
		}

		//
		// translate browse path to node id
		//
		for (uint32_t idx = 0; idx < browseName->pathNames()->size(); idx++) {
			OpcUaQualifiedName::SPtr pathElement;
			browseName->pathNames()->get(idx, pathElement);

			ReferenceItemMap& referenceItemMap = baseNodeClass->referenceItemMap();
			ReferenceItemMultiMap::iterator it;

			bool found = false;
			for (it = referenceItemMap.referenceItemMultiMap().begin(); it != referenceItemMap.referenceItemMultiMap().end(); it++) {
				OpcUaNodeId referenceTypeNodeId = it->first;
				ReferenceItem::SPtr referenceItem = it->second;

				BaseNodeClass::SPtr baseNodeClassTarget = informationModel_->find(referenceItem->nodeId_);
				if (baseNodeClassTarget.get() == nullptr) {
					continue;
				}

				if (baseNodeClassTarget->browseName().data() == *pathElement) {
					nodeIdResult->nodeId(referenceItem->nodeId_);
					baseNodeClass = baseNodeClassTarget;
					found = true;
					break;
				}
			}

			if (!found) {
				nodeIdResult->statusCode(BadNodeIdUnknown);
				return;
			}
		}

		nodeIdResult->statusCode(Success);
		return;
	}

}
