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
          Upendar Reddy Sama (upendarreddysama3@gmail.com)
 */

#include <bitset>
#include "OpcUaStackCore/BuildInTypes/OpcUaIdentifier.h"
#include "OpcUaStackCore/Base/Log.h"
#include "OpcUaStackCore/ServiceSet/ViewServiceTransaction.h"
#include "OpcUaStackServer/ServiceSet/ViewService.h"
#include "OpcUaStackServer/AddressSpaceModel/AttributeAccess.h"
#include "OpcUaStackCore/ServiceSet/ContinuationPointManager.h"

using namespace OpcUaStackCore;

namespace OpcUaStackServer
{

	ViewService::ViewService(
		const std::string &serviceName,
		OpcUaStackCore::IOThread::SPtr &ioThread,
		OpcUaStackCore::MessageBus::SPtr &messageBus,
		OpcUaStackCore::ContinuationPointManager::SPtr &continuationPointManager)
	: ServerServiceBase()
	{
		// set parameter in server service base
		serviceName_ = serviceName;
		ioThread_ = ioThread.get();
		strand_ = ioThread->createStrand();
		messageBus_ = messageBus;
		continuationPointManger_ = continuationPointManager;

		// register message bus receiver
		MessageBusMemberConfig messageBusMemberConfig;
		messageBusMemberConfig.strand(strand_);
		messageBusMember_ = messageBus_->registerMember(serviceName_, messageBusMemberConfig);

		// activate receiver
		activateReceiver(
			[this](const MessageBusMember::WPtr &handleFrom, Message::SPtr &message)
			{
				receive(handleFrom, message);
			});
	}

	ViewService::~ViewService(void)
	{
		// deactivate receiver
		deactivateReceiver();
		messageBus_->deregisterMember(messageBusMember_);
	}

	void
	ViewService::receive(
		const OpcUaStackCore::MessageBusMember::WPtr &handleFrom,
		Message::SPtr &message)
	{
		// We have to remember the sender of the message. This enables us to
		// send a reply for the received message later
		auto serviceTransaction = boost::static_pointer_cast<ServiceTransaction>(message);
		serviceTransaction->memberServiceSession(handleFrom);

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
			sendAnswer(serviceTransaction);
		}
	}

	void
	ViewService::sendAnswer(OpcUaStackCore::ServiceTransaction::SPtr &serviceTransaction)
	{
		messageBus_->messageSend(
			messageBusMember_,
			serviceTransaction->memberServiceSession(),
			serviceTransaction);
	}

	void
	ViewService::receiveBrowseRequest(ServiceTransaction::SPtr serviceTransaction)
	{
		auto trx = boost::static_pointer_cast<ServiceTransactionBrowse>(serviceTransaction);
		auto browseRequest = trx->request();
		auto browseResponse = trx->response();

		sessionId_ = serviceTransaction->sessionId();
		uint32_t nodes = browseRequest->nodesToBrowse()->size();
		OpcUaUInt32 requestMaxReferencesPerNode = browseRequest->requestMaxReferencesPerNode();

		Log(Debug, "attribute service browse request")
			.parameter("Trx", serviceTransaction->transactionId())
			.parameter("NumberNodes", nodes);

		BrowseResultArray::SPtr browseResultArray = boost::make_shared<BrowseResultArray>();
		browseResponse->results(browseResultArray);
		browseResultArray->resize(nodes);

		for (uint32_t idx = 0; idx < nodes; idx++) {
			BrowseDescription::SPtr browseDescription;
			browseRequest->nodesToBrowse()->get(idx, browseDescription);

			BrowseResult::SPtr browseResult = boost::make_shared<BrowseResult>();
			browseResultArray->set(idx, browseResult);

			ReferenceDescriptionVec::iterator it;
			ReferenceDescriptionVec referenceDescriptionVec;
			OpcUaStatusCode statusCode = browseNode(
				browseDescription,
				referenceDescriptionVec,
				requestMaxReferencesPerNode
			);
			browseResult->statusCode(statusCode);
			if (statusCode != Success) {
				continue;
			}

			if (continuationPoint_) {
				browseResult->continuationPoint(continuationPoint_->name_);
				continuationPoint_.reset();
			}

			if (referenceDescriptionVec.size() > 0) {
				auto referenceDescriptionArray = boost::make_shared<ReferenceDescriptionArray>();
				referenceDescriptionArray->resize(referenceDescriptionVec.size());
				browseResult->references(referenceDescriptionArray);
				for (it = referenceDescriptionVec.begin(); it != referenceDescriptionVec.end(); it++)
				{
					Log(Debug, "reference")
						.parameter("Trx", serviceTransaction->transactionId())
						.parameter("SourceNodeId", browseDescription->nodeId())
						.parameter("TargetNodeId", (*it)->expandedNodeId())
						.parameter("TargetDisplayName", (*it)->displayName().text())
						.parameter("ReferenceType", ReferenceTypeMap::nodeIdToString(*(*it)->referenceTypeId()));

					referenceDescriptionArray->push_back(*it);
				}
			}

			Log(Debug, "attribute service browse request")
				.parameter("Trx", serviceTransaction->transactionId())
				.parameter("NodeId", *browseDescription->nodeId())
				.parameter("References", referenceDescriptionVec.size())
				.parameter("StatusCode", OpcUaStatusCodeMap::shortString(statusCode));
		}

		serviceTransaction->statusCode(Success);
		sendAnswer(serviceTransaction);
	}

	void
	ViewService::receiveBrowseNextRequest(ServiceTransaction::SPtr serviceTransaction)
	{
		Log(Debug, "attribute service browse next request")
			.parameter("Trx", serviceTransaction->transactionId());

		auto trx = boost::static_pointer_cast<ServiceTransactionBrowseNext>(serviceTransaction);
		auto browseNextRequest = trx->request();
		auto browseNextResponse = trx->response();

		bool releaseContinuationPoints = browseNextRequest->releaseContinuationPoints();

		auto continuationPointArray = browseNextRequest->continuationPoints();
		auto continuationPointsSize = continuationPointArray->size();

		auto browseResultArray = boost::make_shared<BrowseResultArray>();
		browseResultArray->resize(static_cast<uint32_t>(continuationPointsSize));
		browseNextResponse->results(browseResultArray);

		for (size_t idx = 0; idx < continuationPointsSize; ++idx)
		{
			auto browseResult = boost::make_shared<BrowseResult>();
			browseResultArray->set(idx, browseResult);

			OpcUaByteString::SPtr continuationPointStr;
			if (!continuationPointArray->get(idx, continuationPointStr)) {
				browseResult->statusCode(BadContinuationPointInvalid);
				continue;
			}


			if (releaseContinuationPoints) {
				continuationPointManger_->deleteContinuationPoint(*continuationPointStr);
				browseResult->statusCode(Success);
				continue;
			}

			auto continuationPoint = continuationPointManger_->getContinuationPoint(*continuationPointStr);
			if (!continuationPoint) {
				browseResult->statusCode(BadContinuationPointInvalid);
				continue;
			}

			// calculate number of elements in browse result
			OpcUaInt32 requestMaxReferencesPerNode = continuationPoint->requestMaxReferencesPerNode_;
			if (requestMaxReferencesPerNode > continuationPoint->referenceDescriptionList_.size()) {
				requestMaxReferencesPerNode = continuationPoint->referenceDescriptionList_.size();
			}

			// add reference elements to browse result
			auto resultReferenceArray = boost::make_shared<ReferenceDescriptionArray>();
			resultReferenceArray->resize(requestMaxReferencesPerNode);
			browseResult->references(resultReferenceArray);

			for (size_t i = 0; i < requestMaxReferencesPerNode; i++) {
				resultReferenceArray->push_back(continuationPoint->referenceDescriptionList_.front());
				continuationPoint->referenceDescriptionList_.pop_front();
			}

			// delete continuation point
			if (continuationPoint->referenceDescriptionList_.size() == 0) {
				continuationPointManger_->deleteContinuationPoint(*continuationPointStr);
			}
			else {
				continuationPoint->expireTime_ = boost::posix_time::second_clock::universal_time() + boost::posix_time::seconds(60);

				browseResult->continuationPoint(*continuationPointStr);
			}

		}

		serviceTransaction->statusCode(Success);
		sendAnswer(serviceTransaction);
	}

	void
	ViewService::receiveTranslateBrowsePathsToNodeIdsRequest(ServiceTransaction::SPtr serviceTransaction)
	{
		ServiceTransactionTranslateBrowsePathsToNodeIds::SPtr trx = boost::static_pointer_cast<ServiceTransactionTranslateBrowsePathsToNodeIds>(serviceTransaction);
		TranslateBrowsePathsToNodeIdsRequest::SPtr request = trx->request();
		TranslateBrowsePathsToNodeIdsResponse::SPtr response = trx->response();

		BrowsePathArray::SPtr browsePaths = request->browsePaths();
		if (browsePaths->size() == 0)
		{
			Log(Debug, "no browse path elements exist")
				.parameter("TransactionId", serviceTransaction->transactionId());
			serviceTransaction->statusCode(Success);
			sendAnswer(serviceTransaction);
			return;
		}

		response->results()->resize(browsePaths->size());

		for (uint32_t idx = 0; idx < browsePaths->size(); idx++)
		{

			BrowsePath::SPtr browsePath;
			if (!browsePaths->get(idx, browsePath))
			{
				Log(Debug, "browse paths invalid")
					.parameter("TransactionId", serviceTransaction->transactionId());

				serviceTransaction->statusCode(BadInternalError);
				sendAnswer(serviceTransaction);
				return;
			}

			OpcUaNodeId::SPtr actualNode = browsePath->startingNode();
			RelativePath *relativePath = &browsePath->relativePath();

			BrowsePathResult::SPtr result = boost::make_shared<BrowsePathResult>();
			result->statusCode(Success);
			response->results()->push_back(result);

			if (relativePath->elements().size() == 0)
			{
				result->statusCode(BadInvalidArgument);
				continue;
			}

			for (uint32_t idx = 0; idx < relativePath->elements().size(); idx++)
			{
				RelativePathElement::SPtr relativePathElement;
				if (!relativePath->elements().get(idx, relativePathElement))
				{
					result->statusCode(BadInvalidArgument);
					continue;
				}

				Log(Debug, "TranslateBrowsePathsToNodeId")
					.parameter("NodeId", *actualNode);
				Log(Debug, "  --")
					.parameter("PathElement", relativePathElement->targetName().toString());

				if (!getNodeFromPathElement(*actualNode, relativePathElement->targetName()))
				{
					Log(Debug, "node id not found")
						.parameter("NodeId", *actualNode)
						.parameter("PathElement", relativePathElement->targetName().toString());
					result->statusCode(BadNotFound);
					break;
				}
			}

			if (result->statusCode() == Success)
			{
				result->targets()->resize(1);

				BrowsePathTarget::SPtr browsePathTarget = boost::make_shared<BrowsePathTarget>();

				OpcUaExpandedNodeId::SPtr targetNodeId = boost::make_shared<OpcUaExpandedNodeId>();
				actualNode->copyTo(*targetNodeId);

				browsePathTarget->tragetId(targetNodeId);
				browsePathTarget->remainingPathIndex(0xFFFFFFFF);
				result->targets()->push_back(browsePathTarget);
			}
		}

		serviceTransaction->statusCode(Success);
		sendAnswer(serviceTransaction);
	}

	void
	ViewService::receiveRegisterNodesRequest(ServiceTransaction::SPtr serviceTransaction)
	{
		// FIXME:
		serviceTransaction->statusCode(BadInternalError);
		sendAnswer(serviceTransaction);
	}

	void
	ViewService::receiveUnregisterNodesRequest(ServiceTransaction::SPtr serviceTransaction)
	{
		// FIXME:
		serviceTransaction->statusCode(BadInternalError);
		sendAnswer(serviceTransaction);
	}

	OpcUaStatusCode
	ViewService::browseNode(
		BrowseDescription::SPtr &browseDescription,
		ReferenceDescriptionVec &referenceDescriptionVec,
		const OpcUaUInt32 requestedMaxReferencesPerNode)
	{
		auto baseNodeClass = informationModel_->find(*browseDescription->nodeId());
		if (baseNodeClass.get() == nullptr)
		{
			return BadNodeIdUnknown;
		}
       
	    std::list<OpcUaStackCore::ReferenceDescription::SPtr> referenceDescriptionList;

		OpcUaUInt32 resultMask = browseDescription->resultMask();

		ReferenceItemMap &referenceItemMap = baseNodeClass->referenceItemMap();
		Log(Debug, "read references")
			.parameter("NodeId", baseNodeClass->nodeId())
			.parameter("References", referenceItemMap.size());

		for (const auto &referenceItem : referenceItemMap) {
			OpcUaNodeId referenceTypeNodeId = referenceItem->typeId_;

			if (browseDescription->browseDirection() == BrowseDirection_Forward) {
				if (!referenceItem->isForward_)
					continue;
			}

			if (browseDescription->browseDirection() == BrowseDirection_Inverse) {
				if (referenceItem->isForward_)
					continue;
			}

			if (checkReferenceType(referenceTypeNodeId, browseDescription) != Success) {
				continue;
			}

			auto baseNodeClassTarget = informationModel_->find(referenceItem->nodeId_);
			if (baseNodeClassTarget.get() == nullptr)
			{
				Log(Debug, "target node not found")
					.parameter("NodeId", baseNodeClass->nodeId())
					.parameter("TargetNodeId", referenceItem->nodeId_);
				continue;
			}

			auto referenceDescription = boost::make_shared<ReferenceDescription>();

			auto targetNodeId = boost::make_shared<OpcUaExpandedNodeId>();
			baseNodeClassTarget->nodeId().data().copyTo(*targetNodeId);
			referenceDescription->expandedNodeId(targetNodeId);

			std::bitset<6> resultMaskBits = resultMask;

			if (resultMaskBits.test(Browse_ReferenceType)) {
				referenceTypeNodeId.copyTo(*referenceDescription->referenceTypeId());
			}

			if (resultMaskBits.test(Browse_IsForward)) {
				referenceDescription->isForward(referenceItem->isForward_);
			}

			if (resultMaskBits.test(Browse_NodeClass)) {
				referenceDescription->nodeClass(baseNodeClassTarget->nodeClass().data());
			}

			if (resultMaskBits.test(Browse_BrowseName)) {
				referenceDescription->browseName(baseNodeClassTarget->browseName().data());
			}

			if (resultMaskBits.test(Browse_DisplayName)) {
				referenceDescription->displayName(baseNodeClassTarget->displayName().data());
			}

			if (resultMaskBits.test(Browse_TypeDefinition)) {
				auto itp = baseNodeClassTarget->referenceItemMap().equal_range(*ReferenceTypeMap::hasTypeDefinitionTypeNodeId());
				if (itp.first != itp.second) {
					ReferenceItem::SPtr referenceItem = itp.first->second;
					referenceItem->nodeId_.copyTo(*referenceDescription->typeDefinition());
				}
			}

			if (requestedMaxReferencesPerNode == 0 || referenceDescriptionVec.size() < requestedMaxReferencesPerNode) {
				referenceDescriptionVec.push_back(referenceDescription);
			}
			else {
				referenceDescriptionList.push_back(referenceDescription);
			}
		}

		if (referenceDescriptionList.size() > 0)
		{
			continuationPoint_ = boost::make_shared<ContinuationPoint>();

			continuationPoint_->expireTime_ = boost::posix_time::second_clock::universal_time() + boost::posix_time::seconds(60);
			continuationPoint_->sessionId_ = sessionId_;
			continuationPoint_->referenceDescriptionList_ = referenceDescriptionList;
			continuationPoint_->requestMaxReferencesPerNode_ = requestedMaxReferencesPerNode;

			continuationPointManger_->addContinuationPoint(continuationPoint_);
		}
		return Success;
	}

	OpcUaStatusCode
	ViewService::checkReferenceType(OpcUaNodeId &referenceTypeNodeId, BrowseDescription::SPtr &browseDescription)
	{
		OpcUaNodeId nullNodeId;
		nullNodeId.set(0);
		if (*browseDescription->referenceTypeId() == nullNodeId)
			return Success;

		OpcUaNodeId allNodeId;
		allNodeId.set(31);
		if (*browseDescription->referenceTypeId() == allNodeId)
			return Success;

		BaseNodeClass::SPtr baseNodeClass = informationModel_->find(referenceTypeNodeId);
		if (baseNodeClass.get() == nullptr)
		{
			return BadNotFound;
		}
		return hashSubtype(baseNodeClass, browseDescription);
		return Success;
	}

	OpcUaStatusCode
	ViewService::hashSubtype(BaseNodeClass::SPtr baseNodeClass, BrowseDescription::SPtr browseDescription, uint32_t hopCounter)
	{

		if (hopCounter == 0)
			return BadInternalError;

		if (*browseDescription->referenceTypeId() == baseNodeClass->nodeId().data())
		{
			return Success;
		}

		auto it = baseNodeClass->referenceItemMap().equal_range(*ReferenceTypeMap::hasSubtypeTypeNodeId());
		if (it.first == it.second)
		{
			return BadNotFound;
		}

		for (auto itl = it.first; itl != it.second; ++itl)
		{
			ReferenceItem::SPtr referenceItem = itl->second;

			if (referenceItem->isForward_)
				continue;

			BaseNodeClass::SPtr baseNodeClassTarget = informationModel_->find(referenceItem->nodeId_);
			if (baseNodeClassTarget.get() == nullptr)
			{
				return BadNodeIdUnknown;
			}

			return hashSubtype(baseNodeClassTarget, browseDescription, hopCounter - 1);
		}

		return BadNotFound;
	}

	bool
	ViewService::getNodeFromPathElement(OpcUaNodeId &nodeId, OpcUaQualifiedName &pathElement)
	{
		BaseNodeClass::SPtr baseNodeClass = informationModel_->find(nodeId);
		if (baseNodeClass.get() == nullptr)
		{
			return false;
		}

		ReferenceItemMap &referenceItemMap = baseNodeClass->referenceItemMap();
		for (auto it = referenceItemMap.begin(); it != referenceItemMap.end(); ++it)
		{
			ReferenceItem::SPtr referenceItem = *it;
			OpcUaNodeId referenceTypeNodeId = referenceItem->typeId_;

			BaseNodeClass::SPtr baseNodeClassTarget = informationModel_->find(referenceItem->nodeId_);
			if (baseNodeClassTarget.get() == nullptr)
			{
				continue;
			}

			if (baseNodeClassTarget->browseName().data() == pathElement)
			{
				referenceItem->nodeId_.copyTo(nodeId);
				return true;
			}
		}

		return false;
	}
}
