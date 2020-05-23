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

#include "OpcUaStackCore/BuildInTypes/OpcUaIdentifier.h"
#include "OpcUaStackCore/Base/Log.h"
#include "OpcUaStackCore/StandardDataTypes/ObjectAttributes.h"
#include "OpcUaStackServer/ServiceSet/NodeManagementService.h"
#include "OpcUaStackServer/AddressSpaceModel/ObjectNodeClass.h"

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
		ServiceTransactionAddNodes::SPtr trx = boost::static_pointer_cast<ServiceTransactionAddNodes>(serviceTransaction);
		AddNodesRequest::SPtr addNodesRequest = trx->request();
		AddNodesResponse::SPtr addNodesResponse = trx->response();

		uint32_t size = addNodesRequest->nodesToAdd()->size();
		addNodesResponse->results()->resize(size);

		Log(Debug, "node management service add nodes request")
			.parameter("Trx", serviceTransaction->transactionId())
			.parameter("NumberNodes", size);

		for (uint32_t idx=0; idx<size; idx++) {
			AddNodesResult::SPtr addNodesResult = boost::make_shared<AddNodesResult>();
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
		// FIXME:
		serviceTransaction->statusCode(BadInternalError);
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
		BaseNodeClass::SPtr baseNodeClass,
		AddNodesItem::SPtr& addNodesItem
	)
	{
		bool rc;

		// set parent node identifier
		OpcUaNodeId parentNodeId;
		parentNodeId.namespaceIndex(addNodesItem->parentNodeId().namespaceIndex());
		parentNodeId.nodeIdValue(addNodesItem->parentNodeId().nodeIdValue());

		// find parent node
		BaseNodeClass::SPtr parentBaseNodeClass = informationModel_->find(parentNodeId);
		if (parentBaseNodeClass.get() == nullptr) {
			return BadParentNodeIdInvalid;
		}

		// create hierarchical reference
		rc = parentBaseNodeClass->referenceItemMap().add(
			addNodesItem->referenceTypeId(),
			true,
			*baseNodeClass->getNodeId()
		);
		if (!rc) return BadReferenceTypeIdInvalid;

		rc = baseNodeClass->referenceItemMap().add(
			addNodesItem->referenceTypeId(),
			false,
			*baseNodeClass->getNodeId()
		);
		if (!rc) return BadReferenceTypeIdInvalid;

		return Success;
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

	OpcUaStatusCode 
	NodeManagementService::addNode(uint32_t pos, AddNodesItem::SPtr addNodesItem, AddNodesResult::SPtr addNodesResult)
	{
		switch (addNodesItem->nodeClass().enumeration())
		{
			case NodeClass::EnumObject: return addNodeObject(pos, addNodesItem, addNodesResult);
			case NodeClass::EnumVariable:
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
					.parameter("BrowseName", addNodesItem->browseName());
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
		//
		// M - NodeId
		// M - NodeClass
		// M - BrowseName
		// M - DisplayName
		// O - Description
		// O - WriteMask
		// O - UserWriteMask
		//

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
		ObjectNodeClass::SPtr objectNodeClass = boost::make_shared<ObjectNodeClass>();

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
		ObjectAttributes::SPtr objectAttributes = addNodesItem->nodeAttributes().parameter<ObjectAttributes>(); 

		// set additional object attributes
		objectNodeClass->setDisplayName(objectAttributes->displayName());
		objectNodeClass->setDescription(objectAttributes->description());
		objectNodeClass->setEventNotifier(objectAttributes->eventNotifier());
		objectNodeClass->setWriteMask(objectAttributes->writeMask());
		objectNodeClass->setUserWriteMask(objectAttributes->userWriteMask());

		// added node and reference
		statusCode = addNodeAndReference(objectNodeClass, addNodesItem);
		addNodesResult->statusCode(statusCode);

		return Success;
	}

}
