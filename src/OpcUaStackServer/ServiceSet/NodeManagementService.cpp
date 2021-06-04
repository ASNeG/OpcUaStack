/*
   Copyright 2015-2021 Kai Huebl (kai@huebl-sgh.de)

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

#include "OpcUaStackCore/BuildInTypes/OpcUaIdentifier.h"
#include "OpcUaStackCore/Base/Log.h"
#include "OpcUaStackCore/StandardDataTypes/ObjectAttributes.h"
#include "OpcUaStackCore/StandardDataTypes/VariableAttributes.h"
#include "OpcUaStackServer/ServiceSet/NodeManagementService.h"
#include "OpcUaStackServer/AddressSpaceModel/ObjectNodeClass.h"
#include "OpcUaStackServer/AddressSpaceModel/VariableNodeClass.h"
#include "OpcUaStackServer/InformationModel/InformationModelAccess.h"

using namespace OpcUaStackCore;

namespace OpcUaStackServer
{

	NodeManagementService::NodeManagementService(
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

		// activate receiver
		activateReceiver(
			[this](const OpcUaStackCore::MessageBusMember::WPtr& handleFrom, Message::SPtr& message){
				receive(handleFrom, message);
			}
		);
	}

	NodeManagementService::~NodeManagementService(void)
	{
		// deactivate receiver
		deactivateReceiver();
		messageBus_->deregisterMember(messageBusMember_);
	}

	void 
	NodeManagementService::receive(
		const OpcUaStackCore::MessageBusMember::WPtr& handleFrom,
		Message::SPtr& message
	)
	{
		// We have to remember the sender of the message. This enables us to
		// send a reply for the received message later
		auto serviceTransaction = boost::static_pointer_cast<ServiceTransaction>(message);
		serviceTransaction->memberServiceSession(handleFrom);

		switch (serviceTransaction->nodeTypeRequest().nodeId<uint32_t>()) 
		{
			case OpcUaId_AddNodesRequest_Encoding_DefaultBinary:
				receiveAddNodesRequest(serviceTransaction);
				break;
			case OpcUaId_AddReferencesRequest_Encoding_DefaultBinary:
				receiveAddReferencesRequest(serviceTransaction);
				break;
			case OpcUaId_DeleteNodesRequest_Encoding_DefaultBinary:
				receiveDeleteNodesRequest(serviceTransaction);
				break;
			case OpcUaId_DeleteReferencesRequest_Encoding_DefaultBinary:
				receiveDeleteReferencesRequest(serviceTransaction);
				break;
			default:
				Log(Debug, "receive invalid request type identifier")
					.parameter("RequestTypeId", serviceTransaction->nodeTypeRequest().nodeId<uint32_t>());
				serviceTransaction->statusCode(BadInternalError);
				sendAnswer(serviceTransaction);
		}
	}

	void
	NodeManagementService::sendAnswer(OpcUaStackCore::ServiceTransaction::SPtr& serviceTransaction)
	{
		messageBus_->messageSend(
			messageBusMember_,
			serviceTransaction->memberServiceSession(),
			serviceTransaction
		);
	}

	void 
	NodeManagementService::receiveAddNodesRequest(ServiceTransaction::SPtr serviceTransaction)
	{
		OpcUaStatusCode statusCode = Success;
		auto trx = boost::static_pointer_cast<ServiceTransactionAddNodes>(serviceTransaction);
		auto addNodesRequest = trx->request();
		auto addNodesResponse = trx->response();

		uint32_t size = addNodesRequest->nodesToAdd()->size();
		addNodesResponse->results()->resize(size);

		Log(Debug, "node management service add nodes request")
			.parameter("Trx", serviceTransaction->transactionId())
			.parameter("NumberNodes", size);

		for (uint32_t idx=0; idx<size; idx++) {
			auto addNodesResult = boost::make_shared<AddNodesResult>();
			addNodesResponse->results()->set(idx, addNodesResult);
			
			AddNodesItem::SPtr addNodesItem;
			addNodesRequest->nodesToAdd()->get(idx, addNodesItem);

			statusCode = addNode(idx, addNodesItem, addNodesResult);
			if (statusCode != Success) break; 
		}

		serviceTransaction->statusCode(statusCode);
		sendAnswer(serviceTransaction);
	}

	void 
	NodeManagementService::receiveAddReferencesRequest(ServiceTransaction::SPtr serviceTransaction)
	{
		// FIXME:
		serviceTransaction->statusCode(BadInternalError);
		sendAnswer(serviceTransaction);
	}

	void 
	NodeManagementService::receiveDeleteNodesRequest(ServiceTransaction::SPtr serviceTransaction)
	{
		OpcUaStatusCode statusCode = Success;
		auto trx = boost::static_pointer_cast<ServiceTransactionDeleteNodes>(serviceTransaction);
		auto deleteNodesRequest = trx->request();
		auto deleteNodesResponse = trx->response();

		uint32_t size = deleteNodesRequest->nodesToDelete()->size();
		deleteNodesResponse->results()->resize(size);

		Log(Debug, "node management service delete nodes request")
			.parameter("Trx", serviceTransaction->transactionId())
			.parameter("NumberNodes", size);

		for (uint32_t idx=0; idx<size; idx++) {
			auto deleteNodesResult = boost::make_shared<DeleteNodesResult>();
			deleteNodesResponse->results()->set(idx, deleteNodesResult);

			DeleteNodesItem::SPtr deleteNodesItem;
			deleteNodesRequest->nodesToDelete()->get(idx, deleteNodesItem);

			statusCode = deleteNode(idx, deleteNodesItem, deleteNodesResult);
			if (statusCode != Success) break;
		}

		serviceTransaction->statusCode(statusCode);
		sendAnswer(serviceTransaction);
	}

	void 
	NodeManagementService::receiveDeleteReferencesRequest(ServiceTransaction::SPtr serviceTransaction)
	{
		// FIXME:
		serviceTransaction->statusCode(BadInternalError);
		sendAnswer(serviceTransaction);
	}


	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// add node
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	OpcUaStatusCode 
	NodeManagementService::addNodeAndReference(
		uint32_t pos,
		BaseNodeClass::SPtr baseNodeClass,
		AddNodesItem::SPtr& addNodesItem
	)
	{
		bool rc;

		// set parent node identifier
		OpcUaNodeId parentNodeId;
		parentNodeId.namespaceIndex(addNodesItem->parentNodeId().namespaceIndex());
		parentNodeId.nodeIdValue(addNodesItem->parentNodeId().nodeIdValue());

		// check if node already exist
		auto nodeClass = informationModel_->find(*baseNodeClass->getNodeId());
		if (nodeClass.get() != nullptr) {
			Log(Debug, "add node and reference error, because node already exist")
				.parameter("NodeId", *baseNodeClass->getNodeId());
			return BadNodeIdExists;
		}

		// find parent node
		auto parentBaseNodeClass = informationModel_->find(parentNodeId);
		if (parentBaseNodeClass.get() == nullptr) {
			Log(Debug, "add node and reference error, because parent node already exist")
				.parameter("NodeId", parentNodeId);
			return BadParentNodeIdInvalid;
		}

		// create hierarchical reference
		boost::unique_lock<boost::shared_mutex> lock1(baseNodeClass->mutex());
		rc = baseNodeClass->referenceItemMap().add(
			addNodesItem->referenceTypeId(),
			false,
			*parentBaseNodeClass->getNodeId()
		);
		if (!rc) {
			Log(Debug, "add node and reference error, because add reference item error")
				.parameter("NodeId", *baseNodeClass->getNodeId());
			return BadReferenceTypeIdInvalid;
		}

		boost::unique_lock<boost::shared_mutex> lock2(parentBaseNodeClass->mutex());
		rc = parentBaseNodeClass->referenceItemMap().add(
			addNodesItem->referenceTypeId(),
			true,
			*baseNodeClass->getNodeId()
		);
		if (!rc) {
			Log(Debug, "add node and reference error, because add inverse reference item error")
				.parameter("NodeId", *baseNodeClass->getNodeId());
			return BadReferenceTypeIdInvalid;
		}

		// add type reference to node
		OpcUaNodeId nodeType;
		nodeType.nodeIdValue(addNodesItem->typeDefinition().nodeIdValue());
		nodeType.namespaceIndex(addNodesItem->typeDefinition().namespaceIndex());
		baseNodeClass->referenceItemMap().add(ReferenceType_HasTypeDefinition, true, nodeType);

		// add node to information model
		return addNode(pos, baseNodeClass);
	}

	OpcUaStatusCode
	NodeManagementService::addNode(uint32_t pos, BaseNodeClass::SPtr baseNodeClass)
	{
		if ((informationModel_->find(baseNodeClass->nodeId().data())).get() != nullptr) {
			Log(Error, "node already exist")
					.parameter("Pos", pos)
					.parameter("BrowseName", baseNodeClass->browseName());
			return BadNodeIdExists;
		}
		informationModel_->insert(baseNodeClass);
		return Success;
	}

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// add node functions
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	OpcUaStatusCode 
	NodeManagementService::addNode(uint32_t pos, AddNodesItem::SPtr addNodesItem, AddNodesResult::SPtr addNodesResult)
	{
		switch (addNodesItem->nodeClass().enumeration())
		{
			case NodeClass::EnumObject:
			{
				return addNodeObject(pos, addNodesItem, addNodesResult);
			}
			case NodeClass::EnumVariable:
			{
				return addNodeVariable(pos, addNodesItem, addNodesResult);
			}
			case NodeClass::EnumMethod:
			case NodeClass::EnumObjectType:
			case NodeClass::EnumVariableType:
			case NodeClass::EnumReferenceType:
			case NodeClass::EnumDataType:
			case NodeClass::EnumView:
			case NodeClass::EnumUnspecified:
			default:
			{
				Log(Error, "invalid node class")
					.parameter("Pos", pos)
					.parameter("BrowseName", addNodesItem->browseName())
					.parameter("NodeClass", addNodesItem->nodeClass().enumeration());
				addNodesResult->statusCode(BadInternalError);
			}
		}
		return Success;
	}

	OpcUaStatusCode 
	NodeManagementService::addBaseNodeClass(
		uint32_t pos,
		BaseNodeClass::SPtr baseNodeClass,
		AddNodesItem::SPtr addNodesItem,
		AddNodesResult::SPtr addNodesResult
	)
	{
		OpcUaNodeId nodeId;
		nodeId.namespaceIndex(addNodesItem->requestedNewNodeId().namespaceIndex());
		nodeId.nodeIdValue(addNodesItem->requestedNewNodeId().nodeIdValue());
		baseNodeClass->setNodeId(nodeId);
		NodeClass::Enum nodeClassType = addNodesItem->nodeClass().enumeration();
		baseNodeClass->setNodeClass(nodeClassType);
		baseNodeClass->setBrowseName(addNodesItem->browseName());

		return Success;
	}

	OpcUaStatusCode 
	NodeManagementService::addNodeObject(
		uint32_t pos,
		AddNodesItem::SPtr addNodesItem,
		AddNodesResult::SPtr addNodesResult
	)
	{
		OpcUaStatusCode statusCode;
		auto objectNodeClass = boost::make_shared<ObjectNodeClass>();

		// set base attributes
		statusCode = addBaseNodeClass(pos, objectNodeClass, addNodesItem, addNodesResult);
		if (statusCode != Success) return statusCode;

		// get object attributes 
		if (addNodesItem->nodeAttributes().parameterTypeId().nodeId<uint32_t>() != OpcUaId_ObjectAttributes) {
			Log(Error, "invalid attribute type")
				.parameter("Pos", pos)
				.parameter("BrowseName", addNodesItem->browseName())
				.parameter("AttributeType", addNodesItem->nodeAttributes().parameterTypeId().nodeId<uint32_t>());
			addNodesResult->statusCode(BadInvalidArgument);
			return Success;
		}
		auto objectAttributes = addNodesItem->nodeAttributes().parameter<ObjectAttributes>();

		// set additional object attributes
		objectNodeClass->setDisplayName(objectAttributes->displayName());
		objectNodeClass->setDescription(objectAttributes->description());
		objectNodeClass->setWriteMask(objectAttributes->writeMask());
		objectNodeClass->setUserWriteMask(objectAttributes->userWriteMask());

		objectNodeClass->setEventNotifier(objectAttributes->eventNotifier());

		// added node and reference
		statusCode = addNodeAndReference(pos, objectNodeClass, addNodesItem);
		addNodesResult->statusCode(statusCode);

		return Success;
	}

	OpcUaStatusCode
	NodeManagementService::addNodeVariable(
		uint32_t pos,
		AddNodesItem::SPtr addNodesItem,
		AddNodesResult::SPtr addNodesResult
	)
	{
		OpcUaStatusCode statusCode;
		auto variableNodeClass = boost::make_shared<VariableNodeClass>();

		// set base attributes
		statusCode = addBaseNodeClass(pos, variableNodeClass, addNodesItem, addNodesResult);
		if (statusCode != Success) return statusCode;

		// get object attributes
		if (addNodesItem->nodeAttributes().parameterTypeId().nodeId<uint32_t>() != OpcUaId_VariableAttributes) {
			Log(Error, "invalid attribute type")
				.parameter("Pos", pos)
				.parameter("BrowseName", addNodesItem->browseName())
				.parameter("AttributeType", addNodesItem->nodeAttributes().parameterTypeId().nodeId<uint32_t>());
			addNodesResult->statusCode(BadInvalidArgument);
			return Success;
		}
		auto variableAttributes = addNodesItem->nodeAttributes().parameter<VariableAttributes>();

		// create data value
		OpcUaDataValue dataValue;
		OpcUaDateTime now(boost::posix_time::microsec_clock::universal_time());
		variableAttributes->value().copyTo(*dataValue.variant().get());
		dataValue.serverTimestamp(now);
		dataValue.sourceTimestamp(now);

		// set additional object attributes
		variableNodeClass->setDisplayName(variableAttributes->displayName());
		variableNodeClass->setDescription(variableAttributes->description());
		variableNodeClass->setWriteMask(variableAttributes->writeMask());
		variableNodeClass->setUserWriteMask(variableAttributes->userWriteMask());

		variableNodeClass->setValue(dataValue);
		variableNodeClass->setDataType(variableAttributes->dataType());
		variableNodeClass->setValueRank(variableAttributes->valueRank());
		variableNodeClass->setArrayDimensions(variableAttributes->arrayDimensions());
		variableNodeClass->setAccessLevel(variableAttributes->accessLevel());
		variableNodeClass->setUserAccessLevel(variableAttributes->userAccessLevel());
		variableNodeClass->setMinimumSamplingInterval(variableAttributes->minimumSamplingInterval());
		variableNodeClass->setHistorizing(variableAttributes->historizing());

		// added node and reference
		statusCode = addNodeAndReference(pos, variableNodeClass, addNodesItem);
		addNodesResult->statusCode(statusCode);

		return Success;
	}

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// delete node functions
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	OpcUaStackCore::OpcUaStatusCode
	NodeManagementService::deleteNode(
		uint32_t pos,
		OpcUaStackCore::DeleteNodesItem::SPtr deleteNodesItem,
		OpcUaStackCore::DeleteNodesResult::SPtr deleteNodesResult
	)
	{
		// find node to delete
		auto baseNodeClass = informationModel_->find(deleteNodesItem->nodeId());
		if (baseNodeClass.get() == nullptr) {
			Log(Debug, "delete node error, because node not exist")
				.parameter("NodeId", deleteNodesItem->nodeId());
			deleteNodesResult->statusCode(BadNodeIdUnknown);
			return Success;
		}

		if (deleteNodesItem->deleteTargetReferences() == true) {
			// delete all references
			InformationModelAccess ima(informationModel_);
			if (!ima.remove(deleteNodesItem->nodeId())) {
				Log(Debug, "delete node error, because remove command failed")
					.parameter("NodeId", deleteNodesItem->nodeId());
				deleteNodesResult->statusCode(BadUnexpectedError);
				return Success;
			}
		}
		else {
			// delete only the references for which the node to delete is the source
			InformationModelAccess ima(informationModel_);
			BaseNodeClass::Vec parentBaseNodeClassVec;
			if (!ima.getParentHierarchically(baseNodeClass, parentBaseNodeClassVec)) {
				Log(Debug, "delete node error, because get parent command failed")
					.parameter("NodeId", deleteNodesItem->nodeId());
				deleteNodesResult->statusCode(BadUnexpectedError);
				return Success;
			}

			for (auto parentNodeClass : parentBaseNodeClassVec) {
				for (auto referenceItem : parentNodeClass->referenceItemMap()) {
					if (referenceItem->nodeId_ == deleteNodesItem->nodeId()) {
						parentNodeClass->referenceItemMap().remove(referenceItem->typeId_, referenceItem);
					}
				}
			}

			// delete node id
			if (informationModel_->remove(deleteNodesItem->nodeId()) == true) {
				Log(Debug, "delete node error, because remove command failed")
					.parameter("NodeId", deleteNodesItem->nodeId());
				deleteNodesResult->statusCode(BadNodeIdUnknown);
			}
			else {
				deleteNodesResult->statusCode(Success);
			}
		}

		return Success;
	}

}
