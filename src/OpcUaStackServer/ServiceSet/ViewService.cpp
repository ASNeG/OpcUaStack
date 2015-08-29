/*
   Copyright 2015 Kai Huebl (kai@huebl-sgh.de)

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
#include "OpcUaStackCore/ServiceSet/ViewServiceTransaction.h"
#include "OpcUaStackServer/ServiceSet/ViewService.h"
#include "OpcUaStackServer/AddressSpaceModel/AttributeAccess.h"


namespace OpcUaStackServer
{

	ViewService::ViewService(void)
	{
	}

	ViewService::~ViewService(void)
	{
	}

	void 
	ViewService::receive(Message::SPtr message)
	{
		ServiceTransaction::SPtr serviceTransaction = boost::static_pointer_cast<ServiceTransaction>(message);
		switch (serviceTransaction->nodeTypeRequest().nodeId<uint32_t>()) 
		{
			case OpcUaId_BrowseRequest_Encoding_DefaultBinary:
				receiveBrowseRequest(serviceTransaction);
				break;
			case OpcUaId_BrowseNextRequest_Encoding_DefaultBinary:
				receiveBrowseNextRequest(serviceTransaction);
				break;
			case OpcUaId_TranslateBrowsePathsToNodeIdsRequest_Encoding_DefaultBinary:
				receiveTranslateBrowsePathsToNodeIdsRequest(serviceTransaction);
				break;
			case OpcUaId_RegisterNodesRequest_Encoding_DefaultBinary:
				receiveRegisterNodesRequest(serviceTransaction);
				break;
			case OpcUaId_UnregisterNodesRequest_Encoding_DefaultBinary:
				receiveUnregisterNodesRequest(serviceTransaction);
				break;
			default:
				serviceTransaction->statusCode(BadInternalError);
				serviceTransaction->componentSession()->send(serviceTransaction);
		}
	}

	void 
	ViewService::receiveBrowseRequest(ServiceTransaction::SPtr serviceTransaction)
	{
		ServiceTransactionBrowse::SPtr trx = boost::static_pointer_cast<ServiceTransactionBrowse>(serviceTransaction);
		BrowseRequest::SPtr browseRequest = trx->request();
		BrowseResponse::SPtr browseResponse = trx->response();


		uint32_t nodes = browseRequest->nodesToBrowse()->size();
		Log(Debug, "attribute service browse request")
			.parameter("Trx", serviceTransaction->transactionId())
			.parameter("NumberNodes", nodes);

		BrowseResultArray::SPtr browseResultArray = BrowseResultArray::construct();
		browseResponse->results(browseResultArray);
		browseResultArray->resize(nodes);

		for (uint32_t idx = 0; idx < nodes; idx++) {
			BrowseDescription::SPtr browseDescription;
			browseRequest->nodesToBrowse()->get(idx, browseDescription);

			BrowseResult::SPtr browseResult = BrowseResult::construct();
			browseResultArray->set(idx, browseResult);

			ReferenceDescriptionVec::iterator it;
			ReferenceDescriptionVec referenceDescriptionVec;
			OpcUaStatusCode statusCode = browseNode(browseDescription, referenceDescriptionVec); 
			browseResult->statusCode(statusCode);

			ReferenceDescriptionArray::SPtr referenceDescriptionArray = ReferenceDescriptionArray::construct();
			referenceDescriptionArray->resize(referenceDescriptionVec.size());
			browseResult->references(referenceDescriptionArray);
			for (it = referenceDescriptionVec.begin(); it != referenceDescriptionVec.end(); it++) {
				Log(Debug, "reference")
					.parameter("Trx", serviceTransaction->transactionId())
					.parameter("SourceNodeId", browseDescription->nodeId())
					.parameter("TargetNodeId", (*it)->expandedNodeId())
					.parameter("TargetDisplayName", (*it)->displayName().text())
					.parameter("ReferenceType", ReferenceTypeMap::nodeIdToString(*(*it)->referenceTypeId()));

				referenceDescriptionArray->push_back(*it);
			}

			Log(Debug, "attribute service browse request")
				.parameter("Trx", serviceTransaction->transactionId())
				.parameter("NodeId", *browseDescription->nodeId())
				.parameter("References", referenceDescriptionVec.size())
				.parameter("StatusCode", OpcUaStatusCodeMap::shortString(statusCode));
		}

		serviceTransaction->statusCode(Success);
		serviceTransaction->componentSession()->send(serviceTransaction);
	}

	void 
	ViewService::receiveBrowseNextRequest(ServiceTransaction::SPtr serviceTransaction)
	{
		// FIXME:
		serviceTransaction->statusCode(BadInternalError);
		serviceTransaction->componentSession()->send(serviceTransaction);
	}

	void 
	ViewService::receiveTranslateBrowsePathsToNodeIdsRequest(ServiceTransaction::SPtr serviceTransaction)
	{
		// FIXME:
		serviceTransaction->statusCode(BadInternalError);
		serviceTransaction->componentSession()->send(serviceTransaction);
	}

	void 
	ViewService::receiveRegisterNodesRequest(ServiceTransaction::SPtr serviceTransaction)
	{
		// FIXME:
		serviceTransaction->statusCode(BadInternalError);
		serviceTransaction->componentSession()->send(serviceTransaction);
	}

	void 
	ViewService::receiveUnregisterNodesRequest(ServiceTransaction::SPtr serviceTransaction)
	{
		// FIXME:
		serviceTransaction->statusCode(BadInternalError);
		serviceTransaction->componentSession()->send(serviceTransaction);
	}

	
	OpcUaStatusCode
	ViewService::browseNode(BrowseDescription::SPtr browseDescription, ReferenceDescriptionVec& referenceDescriptionVec)
	{
		BaseNodeClass::SPtr baseNodeClass = informationModel_->find(*browseDescription->nodeId());
		if (baseNodeClass.get() == nullptr) {
			return BadNodeIdUnknown;
		}

		ReferenceItemMap& referenceItemMap = baseNodeClass->referenceItemMap();
		Log(Debug, "read references")
			.parameter("NodeId", baseNodeClass->nodeId())
			.parameter("References", referenceItemMap.referenceItemMultiMap().size());

		ReferenceItemMultiMap::iterator it;
		for (it = referenceItemMap.referenceItemMultiMap().begin(); it != referenceItemMap.referenceItemMultiMap().end(); it++) {
			OpcUaNodeId referenceTypeNodeId = it->first;
			ReferenceItem::SPtr referenceItem = it->second;

			if (browseDescription->browseDirection() == BrowseDirection_Forward) {
				if (!referenceItem->isForward_) continue;
			}

			if (browseDescription->browseDirection() == BrowseDirection_Inverse) {
				if (referenceItem->isForward_) continue;
			}

			if (checkReferenceType(referenceTypeNodeId, browseDescription) != Success) {
				continue;
			}

			BaseNodeClass::SPtr baseNodeClassTarget = informationModel_->find(referenceItem->nodeId_);
			if (baseNodeClassTarget.get() == nullptr) {
				Log(Debug, "target node not found")
					.parameter("NodeId", baseNodeClass->nodeId())
					.parameter("TargetNodeId", referenceItem->nodeId_);
				continue;
			}

			ReferenceDescription::SPtr referenceDescription = ReferenceDescription::construct();
			referenceDescriptionVec.push_back(referenceDescription);

			OpcUaExpandedNodeId::SPtr targetNodeId = OpcUaExpandedNodeId::construct();
			baseNodeClassTarget->nodeId().data().copyTo(*targetNodeId);
			referenceDescription->expandedNodeId(targetNodeId);
			referenceTypeNodeId.copyTo(*referenceDescription->referenceTypeId());
			referenceDescription->isForward(referenceItem->isForward_);  
			referenceDescription->displayName(baseNodeClassTarget->displayName().data());
			referenceDescription->browseName(baseNodeClassTarget->browseName().data());
			referenceDescription->nodeClass(baseNodeClassTarget->nodeClass().data());

			std::pair<ReferenceItemMultiMap::iterator,ReferenceItemMultiMap::iterator> itp;
			itp = baseNodeClassTarget->referenceItemMap().referenceItemMultiMap().equal_range(*ReferenceTypeMap::hasTypeDefinitionTypeNodeId());
			if (itp.first != itp.second) {
				ReferenceItem::SPtr referenceItem = itp.first->second;
				referenceItem->nodeId_.copyTo(*referenceDescription->typeDefinition());
			}
		}

		return Success;
	}

	OpcUaStatusCode 
	ViewService::checkReferenceType(OpcUaNodeId& referenceTypeNodeId, BrowseDescription::SPtr browseDescription)
	{
		OpcUaNodeId nullNodeId;
		nullNodeId.set(0);
		if (*browseDescription->referenceTypeId() == nullNodeId) return Success;

		BaseNodeClass::SPtr baseNodeClass = informationModel_->find(referenceTypeNodeId);
		if (baseNodeClass.get() == nullptr) {
			return BadNotFound;
		}
		return hashSubtype(baseNodeClass,  browseDescription);
		return Success;
	}

	OpcUaStatusCode 
	ViewService::hashSubtype(BaseNodeClass::SPtr baseNodeClass, BrowseDescription::SPtr browseDescription, uint32_t hopCounter)
	{

		if (hopCounter == 0) return BadInternalError;

		if (*browseDescription->referenceTypeId() == baseNodeClass->nodeId().data()) {
			return Success;
		}

		std::pair<ReferenceItemMultiMap::iterator,ReferenceItemMultiMap::iterator> it;
		it = baseNodeClass->referenceItemMap().referenceItemMultiMap().equal_range(*ReferenceTypeMap::hasSubtypeTypeNodeId());
		if (it.first == it.second) {
			return BadNotFound;
		}

		ReferenceItemMultiMap::iterator itl;
		for (itl = it.first; itl != it.second; itl++) {
			ReferenceItem::SPtr referenceItem  = itl->second;

			if (referenceItem->isForward_) continue;

			BaseNodeClass::SPtr baseNodeClassTarget = informationModel_->find(referenceItem->nodeId_);
			if (baseNodeClassTarget.get() == nullptr) {
				return BadNodeIdUnknown;
			}

			return hashSubtype(baseNodeClassTarget, browseDescription, hopCounter-1);
		}

		return BadNotFound;
	}
}
