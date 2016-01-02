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

#include "OpcUaStackUtility/NodeSet/NodeSetClientReader.h"
#include "OpcUaStackCore/Base/Log.h"
#include "OpcUaStackClient/ServiceSet/AttributeService.h"
#include "OpcUaStackClient/ServiceSet/ViewService.h"
#include "OpcUaStackClient/ServiceAccess/NamespaceArray.h"

using namespace OpcUaStackClient;

namespace OpcUaStackUtility
{

	NodeSetClientReader::NodeSetClientReader(void)
	: SessionServiceIf()
	, client_()
	, nodeSetNamespace_()
	, condition_()
	, error_(false)
	{
		client_.init();
		client_.start();
	}

	NodeSetClientReader::~NodeSetClientReader(void)
	{
		client_.stop();
		client_.cleanup();
	}

	bool 
	NodeSetClientReader::readNodes(
		const std::string& sessionConfigPrefix, Config& sessionConfig,
		const std::string& secureChannelConfigPrefix, Config& secureChannelConfig,
		uint32_t operationTimeout
	)
	{
		OpcUaNodeId nodeId;
		nodeId.set(84);
		return readNodes(
			sessionConfigPrefix, sessionConfig,
			secureChannelConfigPrefix, secureChannelConfig,
			nodeId,
			operationTimeout
		);
	}

	bool
	NodeSetClientReader::readNodes(
		const std::string& sessionConfigPrefix, Config& sessionConfig,
		const std::string& secureChannelConfigPrefix, Config& secureChannelConfig,
		OpcUaNodeId& nodeId,
		uint32_t operationTimeout
	)
	{
		bool rc;

		operationTimeout_ = operationTimeout;

		// open session to opc ua server. A condition is used to wait for
		// the end of the operation
		condition_.conditionInit();
		session_ = client_.sessionManager().getNewSession(
			sessionConfigPrefix, sessionConfig,
			secureChannelConfigPrefix, secureChannelConfig,
			this
		);
		session_->open();
		rc = condition_.waitForCondition(operationTimeout_);
		if (!rc) {
			Log(Error, "activate session timeout in node set client reader");
			return false;
		}
		if (error_) {
			session_->close();
			Log(Error, "activate Session error");
			return false;
		}

		// read namespace array from opc ua server
		if (!readNamespaceArray()) {
			session_->close();
			Log(Error, "read namespace array error");
			return false;
		}

		// browse nodes from opc ua server
		nodeIdSet_.clear();
		if (!browse(nodeId)) {
			session_->close();
			Log(Error, "browse nodes error");
			return false;
		}
		if (nodeIdSet_.size() == 0) {
			session_->close();
			Log(Error, "browse nodes error, because no nodes found");
			return false;
		}

		session_->close();
		return true;
	}

	NodeSetNamespace& 
	NodeSetClientReader::nodeSetNamespace(void)
	{
		return nodeSetNamespace_;
	}

	bool 
	NodeSetClientReader::readNamespaceArray(void)
	{
#if 0 // FIXME:
		NamespaceArray namespaceArray(session_);
		if (!namespaceArray.readSync()) return false;
		nodeSetNamespace_.clear();
		nodeSetNamespace_.decodeNamespaceUris(namespaceArray.namespaceVec());
#endif
		return true;
	}

	bool 
	NodeSetClientReader::browse(OpcUaNodeId& nodeId)
	{
		Log(Debug, "browse begin");
		ReferenceDescription::SPtr referenceDescription = ReferenceDescription::construct();
		referenceDescription->expandedNodeId()->nodeIdValue(nodeId.nodeIdValue());
		referenceDescription->expandedNodeId()->namespaceIndex(nodeId.namespaceIndex());
		referenceDescription->browseName().set("Root");
		referenceDescription->displayName().set("", "Root");
		referenceDescription->nodeClass(NodeClassType_Object);
		
		std::vector<OpcUaNodeId> nodeIdVec;
		ReferenceDescription::Vec referenceDescriptionVec;
		
		nodeIdVec.push_back(nodeId);
		referenceDescriptionVec.push_back(referenceDescription);

		bool rc = browse(nodeIdVec, referenceDescriptionVec);
		Log(Debug, "browse end");
		return rc;
	}

	bool
	NodeSetClientReader::browse(
		OpcUaNodeId& nodeId,
		ReferenceDescription::SPtr referenceDescription,
		OpcUaByteString::SPtr continuationPoint
	)
	{
		IOThread ioThread;
		ViewService viewService(&ioThread);  // FIXME: error......
		viewService.componentSession(session_->component());

		ServiceTransactionBrowseNext::SPtr browseNextTrx = ServiceTransactionBrowseNext::construct();
		BrowseNextRequest::SPtr req = browseNextTrx->request();

		req->continuationPoints()->resize(1);
		req->continuationPoints()->push_back(continuationPoint);

		viewService.syncSend(browseNextTrx);

		//
		// check response
		//
		if (browseNextTrx->responseHeader()->serviceResult() != Success) {
			Log(Error, "browse next nodes response error")
				.parameter("ResultCode", OpcUaStatusCodeMap::longString(browseNextTrx->responseHeader()->serviceResult()));
			return false;
		}
		if (browseNextTrx->response()->results()->size() != 1) {
			Log(Error, "browse next nodes array size error")
				.parameter("Nodes", nodeId)
				.parameter("ArraySize", browseNextTrx->response()->results()->size());
			return false;
		}

		//
		// check dataValue
		//
		BrowseResultArray::SPtr browseResultArray = browseNextTrx->response()->results();
		BrowseResult::SPtr browseResult;
		browseResultArray->get(0, browseResult);

		if (browseResult->statusCode() != Success) {
			Log(Error, "browse next node result error")
				.parameter("NodeId", nodeId)
				.parameter("StatusCode", OpcUaStatusCodeMap::longString(browseResult->statusCode()));
		}

		Log(Debug, "browse response")
			.parameter("NodeId", nodeId)
			.parameter("References", browseResult->references()->size());

		//
		// read node information from browse result
		//
		std::vector<OpcUaNodeId> newNodeIdVec;
		ReferenceDescription::Vec newReferenceDescriptionVec;
		ReferenceDescription::Vec allReferenceDescriptionVec;

		ReferenceDescriptionArray::SPtr references = browseResult->references();
		if (references->size() == 0) return true;
		for (uint32_t idx=0; idx<references->size(); idx++) {
			ReferenceDescription::SPtr referenceDescription;
			references->get(idx, referenceDescription);

			// check if node already exist
			OpcUaNodeId nodeId;
			nodeId.nodeIdValue(referenceDescription->expandedNodeId()->nodeIdValue());
			nodeId.namespaceIndex(referenceDescription->expandedNodeId()->namespaceIndex());

			allReferenceDescriptionVec.push_back(referenceDescription);
			if (nodeIdSet_.find(nodeId) != nodeIdSet_.end()) {
				continue;
			}
			nodeIdSet_.insert(nodeId);
			newNodeIdVec.push_back(nodeId);
			newReferenceDescriptionVec.push_back(referenceDescription);
		}

		bool rc = createNode(nodeId, referenceDescription, allReferenceDescriptionVec);
		if (!rc) return false;

		//
		// check if the answer is completely arrived
		//
		if (browseResult->continuationPoint().exist()) {
			Log(Debug, "browse continuation point found")
				.parameter("NodeId", nodeId);

			OpcUaByteString::SPtr continuationPoint = OpcUaByteString::construct();
			browseResult->continuationPoint().copyTo(*continuationPoint);

			if (!browse(nodeId, referenceDescription, continuationPoint)) return false;
		}

		if (newNodeIdVec.size() > 0) {
			if (!browse(newNodeIdVec, newReferenceDescriptionVec)) return false;
		}

		return true;
	}

	bool 
	NodeSetClientReader::browse(
		std::vector<OpcUaNodeId>& nodeIdVec,
		ReferenceDescription::Vec& referenceDescriptionVec
	)
	{
		IOThread ioThread;
		ViewService viewService(&ioThread);  // FIXME: error....
		viewService.componentSession(session_->component());

		//
		// browse node
		//
		ServiceTransactionBrowse::SPtr browseTrx = ServiceTransactionBrowse::construct();
		BrowseRequest::SPtr req = browseTrx->request();

		req->nodesToBrowse()->resize(nodeIdVec.size());
		for (uint32_t idx=0; idx<nodeIdVec.size(); idx++) {
			BrowseDescription::SPtr browseDescription = BrowseDescription::construct();
			nodeIdVec[idx].copyTo(*browseDescription->nodeId());
			browseDescription->browseDirection(BrowseDirection_Both);
			browseDescription->nodeClassMask(0xFFFFFFFF);
			browseDescription->resultMask(0xFFFFFFFF);
			req->nodesToBrowse()->push_back(browseDescription);
		}

		viewService.syncSend(browseTrx);

		//
		// check response
		//
		if (browseTrx->responseHeader()->serviceResult() != Success) {
			Log(Error, "browse nodes response error")
				.parameter("ResultCode", OpcUaStatusCodeMap::longString(browseTrx->responseHeader()->serviceResult()));
			return false;
		}
		if (browseTrx->response()->results()->size() != nodeIdVec.size()) {
			Log(Error, "browse nodes array size error")
				.parameter("Nodes", nodeIdVec.size())
				.parameter("ArraySize", browseTrx->response()->results()->size());
			return false;
		}

		//
		// check dataValue
		// 
		BrowseResultArray::SPtr browseResultArray = browseTrx->response()->results();
		for (uint32_t pos=0; pos<browseResultArray->size(); pos++) {
			BrowseResult::SPtr browseResult;
			browseResultArray->get(pos, browseResult);

			if (browseResult->statusCode() != Success) {
				Log(Error, "browse node result error")
					.parameter("NodeId", nodeIdVec[pos])
					.parameter("StatusCode", OpcUaStatusCodeMap::longString(browseResult->statusCode()));
			}

			Log(Debug, "browse response")
				.parameter("NodeId", nodeIdVec[pos])
				.parameter("References", browseResult->references()->size());

			//
			// read node information from browse result
			//
			std::vector<OpcUaNodeId> newNodeIdVec;
			ReferenceDescription::Vec newReferenceDescriptionVec;
			ReferenceDescription::Vec allReferenceDescriptionVec;

			ReferenceDescriptionArray::SPtr references = browseResult->references();
			if (references->size() == 0) continue;
			for (uint32_t idx=0; idx<references->size(); idx++) {
				ReferenceDescription::SPtr referenceDescription;
				references->get(idx, referenceDescription);

				// check if node already exist
				OpcUaNodeId nodeId;
				nodeId.nodeIdValue(referenceDescription->expandedNodeId()->nodeIdValue());
				nodeId.namespaceIndex(referenceDescription->expandedNodeId()->namespaceIndex());

				allReferenceDescriptionVec.push_back(referenceDescription);
				if (nodeIdSet_.find(nodeId) != nodeIdSet_.end()) {
					continue;
				}
				nodeIdSet_.insert(nodeId);
				newNodeIdVec.push_back(nodeId);
				newReferenceDescriptionVec.push_back(referenceDescription);
			}

			bool rc = createNode(nodeIdVec[pos], referenceDescriptionVec[pos], allReferenceDescriptionVec);
			if (!rc) return false;

			//
			// check if the answer is completely arrived
			//
			if (browseResult->continuationPoint().exist()) {
				BrowseDescription::SPtr browseDescription;
				req->nodesToBrowse()->get(pos, browseDescription);

				Log(Debug, "browse continuation point found")
					.parameter("NodeId", *browseDescription->nodeId());

				OpcUaByteString::SPtr continuationPoint = OpcUaByteString::construct();
				browseResult->continuationPoint().copyTo(*continuationPoint);

				if (!browse(nodeIdVec[pos], referenceDescriptionVec[pos], continuationPoint)) return false;
			}

			if (newNodeIdVec.size() > 0) {
				if (!browse(newNodeIdVec, newReferenceDescriptionVec)) return false;
			}
		}

		return true;
	}

	bool 
	NodeSetClientReader::createNode(
		OpcUaNodeId& nodeId, 
		ReferenceDescription::SPtr nodeReferenceDescription, 
		ReferenceDescription::Vec& referenceDescriptionVec
	)
	{
		bool rc;
		switch (nodeReferenceDescription->nodeClass())
		{
			case NodeClassType_Object:
			{
				rc = readObject(
					nodeId, 
					nodeReferenceDescription, 
					referenceDescriptionVec
				);
				break;
			}
			case NodeClassType_Variable:
			{
				rc = readVariable(
					nodeId, 
					nodeReferenceDescription, 
					referenceDescriptionVec
				);
				break;
			}
			case NodeClassType_Method:
			{
				rc = readMethod(
					nodeId, 
					nodeReferenceDescription, 
					referenceDescriptionVec
				);
				break;
			}
			case NodeClassType_ObjectType:
			{
				rc = readObjectType(
					nodeId, 
					nodeReferenceDescription, 
					referenceDescriptionVec
				);
				break;
			}
			case NodeClassType_VariableType:
			{
				rc = readVariableType(
					nodeId, 
					nodeReferenceDescription, 
					referenceDescriptionVec
				);
				break;
			}
			case NodeClassType_ReferenceType:
			{
				rc = readReferenceType(
					nodeId, 
					nodeReferenceDescription, 
					referenceDescriptionVec
				);
				break;
			}
			case NodeClassType_DataType:
			{
				rc = readDataType(
					nodeId, 
					nodeReferenceDescription, 
					referenceDescriptionVec
				);
				break;
			}
			case NodeClassType_View:
			{
				rc = readView(
					nodeId, 
					nodeReferenceDescription, 
					referenceDescriptionVec
				);
				break;
			}
			default:
			{
				Log(Error, "node class unknown")
					.parameter("NodeId", nodeId)
					.parameter("NodeClass", nodeReferenceDescription->nodeClass())
					.parameter("DisplayName", nodeReferenceDescription->browseName().name().value());
				return false;
			}
		}

		if (!rc) return false;
		return true;
	}

	bool 
	NodeSetClientReader::checkVariantType(
		OpcUaNodeId& nodeId, 
		const std::string& attributeName, 
		OpcUaVariant::SPtr variant,
		OpcUaBuildInType buildInType
	)
	{
		if (variant->variantType() == buildInType) return true;

		Log(Error, "build in type invalid in attribute")
			.parameter("NodeId", nodeId)
			.parameter("AttributeName", attributeName)
			.parameter("ActualType", variant->variantType())
			.parameter("ExpectedType", buildInType);
		return false;
	}
	
	bool
	NodeSetClientReader::readAttributes(
		OpcUaNodeId nodeId, 
		std::vector<AttributeId>& attributeIdVec, 
		std::vector<OpcUaDataValue::SPtr>& dataValueVec)
	{
#if 0 // FIXME:
		AttributeService attributeService;
		attributeService.componentSession(session_->component());

		//
		// read attributes
		//
		ServiceTransactionRead::SPtr readTrx = ServiceTransactionRead::construct();

		ReadRequest::SPtr req = readTrx->request();
		req->maxAge(0);
		req->timestampsToReturn(2);
		req->readValueIdArray()->resize(attributeIdVec.size());
		
		for (uint32_t idx=0; idx<attributeIdVec.size(); idx++) {
			ReadValueId::SPtr readValueIdSPtr = ReadValueId::construct();
			nodeId.copyTo(*readValueIdSPtr->nodeId());
			readValueIdSPtr->attributeId(attributeIdVec[idx]);
			readValueIdSPtr->dataEncoding().namespaceIndex((OpcUaInt16) 0);
			req->readValueIdArray()->push_back(readValueIdSPtr);
		}

		attributeService.syncSend(readTrx);

		//
		// check response
		//
		if (readTrx->responseHeader()->serviceResult() != Success) {
			Log(Error, "read attributes response error")
				.parameter("NodeId", nodeId)
				.parameter("ResultCode", OpcUaStatusCodeMap::longString(readTrx->responseHeader()->serviceResult()));
			return false;
		}
		if (readTrx->response()->dataValueArray()->size() != attributeIdVec.size()) {
			Log(Error, "read attributes array size error")
				.parameter("NodeId", nodeId)
				.parameter("ArraySize", readTrx->response()->dataValueArray()->size());
			return false;
		}

		//
		// check data value
		//
		Log(Debug, "node set client reader read response")
			.parameter("Trx", readTrx->transactionId())
			.parameter("NumberNodes", attributeIdVec.size());
		for (uint32_t idx=0; idx<attributeIdVec.size(); idx++) {
			
			OpcUaDataValue::SPtr dataValue;
			bool rc = readTrx->response()->dataValueArray()->get(idx, dataValue);
			
			if (rc == false || dataValue.get() == nullptr || dataValue->statusCode() != Success) {
				Log(Warning, "read attributes data value error")
					.parameter("NodeId", nodeId)
					.parameter("StatusCode", OpcUaStatusCodeMap::longString(dataValue->statusCode()));
				dataValue.reset();

				Log(Debug, "readValue")
					.parameter("Trx", readTrx->transactionId())
					.parameter("Idx", idx)
					.parameter("NodeId", nodeId)
					.parameter("Attr", attributeIdVec[idx])
					.parameter("Data", "null");
			}
			else {
				Log(Debug, "readValue")
					.parameter("Trx", readTrx->transactionId())
					.parameter("Idx", idx)
					.parameter("NodeId", nodeId)
					.parameter("Attr", attributeIdVec[idx])
					.parameter("Data", *dataValue);
			}
			dataValueVec.push_back(dataValue);
		}
#endif
		return true;
	}

	bool 
	NodeSetClientReader::readNodeBase(
		OpcUaNodeId& nodeId, 
		BaseNodeClass::SPtr baseNodeClass,
		ReferenceDescription::SPtr referenceDescription, 
		std::vector<OpcUaDataValue::SPtr>& dataValueVec)
	{
		uint16_t localNamepaceIndex;
		uint16_t globalNamespaceIndex;

		// set nodeId and replace local namespace by global namespace index
		nodeId.copyTo(baseNodeClass->nodeId().data());
		localNamepaceIndex = baseNodeClass->nodeId().data().namespaceIndex();
		globalNamespaceIndex = nodeSetNamespace_.mapToGlobalNamespaceIndex(localNamepaceIndex);
		baseNodeClass->nodeId().data().namespaceIndex(globalNamespaceIndex);

		// set browse name and replace local namespace by global namespace index
		referenceDescription->browseName().copyTo(baseNodeClass->browseName().data());
		globalNamespaceIndex = baseNodeClass->browseName().data().namespaceIndex();
		globalNamespaceIndex = nodeSetNamespace_.mapToGlobalNamespaceIndex(localNamepaceIndex);
		baseNodeClass->browseName().data().namespaceIndex(globalNamespaceIndex);

		// set display name
		referenceDescription->displayName().copyTo(baseNodeClass->displayName().data());

		if (dataValueVec[0].get() != nullptr) {
			if (!checkVariantType(nodeId, "Description", dataValueVec[0]->variant(), OpcUaBuildInType_OpcUaLocalizedText)) return false;
			OpcUaLocalizedText::SPtr description = dataValueVec[0]->variant()->variantSPtr<OpcUaLocalizedText>();
			description->copyTo(baseNodeClass->description().data());
		}

		if (dataValueVec[1].get() != nullptr) {
			if (!checkVariantType(nodeId, "WriteMask", dataValueVec[1]->variant(), OpcUaBuildInType_OpcUaUInt32)) return false;
			OpcUaUInt32 writeMask = dataValueVec[1]->variant()->variant<OpcUaUInt32>();
			baseNodeClass->writeMask().data(writeMask);
		}

		if (dataValueVec[2].get() != nullptr) {
			if (!checkVariantType(nodeId, "UserWriteMask", dataValueVec[2]->variant(), OpcUaBuildInType_OpcUaUInt32)) return false;
			OpcUaUInt32 userWriteMask = dataValueVec[2]->variant()->variant<OpcUaUInt32>();
			baseNodeClass->userWriteMask().data(userWriteMask);
		}

		return true;
	}

	bool 
	NodeSetClientReader::addReferences(
		BaseNodeClass::SPtr baseNodeClass,
		ReferenceDescription::Vec& referenceDescriptionVec
	)
	{
		ReferenceDescription::Vec::iterator it;
		for (it=referenceDescriptionVec.begin(); it!=referenceDescriptionVec.end(); it++) {
			ReferenceDescription::SPtr referenceDescription = *it;
			ReferenceItem::SPtr referenceItem = ReferenceItem::construct();

			referenceItem->nodeId_.nodeIdValue(referenceDescription->expandedNodeId()->nodeIdValue());
			referenceItem->nodeId_.namespaceIndex(referenceDescription->expandedNodeId()->namespaceIndex());
			referenceItem->isForward_ = referenceDescription->isForward();
			
			// replace local namespace by global namespace index
			uint16_t localNamespaceIndex = referenceItem->nodeId_.namespaceIndex();
			uint16_t globalNamespaceIndex = nodeSetNamespace_.mapToGlobalNamespaceIndex(localNamespaceIndex);
			referenceItem->nodeId_.namespaceIndex(globalNamespaceIndex);

			baseNodeClass->referenceItemMap().add(
				*referenceDescription->referenceTypeId(),
				referenceItem
			);
		}
		return true;
	}

	bool 
	NodeSetClientReader::readObject(
		OpcUaNodeId& nodeId, 
		ReferenceDescription::SPtr nodeReferenceDescription,
		ReferenceDescription::Vec& referenceDescriptionVec
	)
	{
		ObjectNodeClass::SPtr objectNodeClass = ObjectNodeClass::construct();
		if (!addReferences(objectNodeClass, referenceDescriptionVec)) return false;

		std::vector<AttributeId> attributeIdVec;
		std::vector<OpcUaDataValue::SPtr> dataValueVec;
		attributeIdVec.push_back(AttributeId_Description);
		attributeIdVec.push_back(AttributeId_WriteMask);
		attributeIdVec.push_back(AttributeId_UserWriteMask);
		attributeIdVec.push_back(AttributeId_EventNotifier);
		if (!readAttributes(nodeId, attributeIdVec, dataValueVec)) return false;

		if (!readNodeBase(nodeId, objectNodeClass, nodeReferenceDescription, dataValueVec)) return false;
	
		if (dataValueVec[3].get() != nullptr && dataValueVec[3]->statusCode() == Success) {
			if (!checkVariantType(nodeId, "EventNotifier", dataValueVec[3]->variant(), OpcUaBuildInType_OpcUaByte)) return false;
			OpcUaByte eventNotifier = dataValueVec[3]->variant()->variant<OpcUaByte>();
			objectNodeClass->eventNotifier().data(eventNotifier);
		}

		objectNodeClassVec().push_back(objectNodeClass);

		return true;
	}

	bool 
	NodeSetClientReader::readVariable(
		OpcUaNodeId& nodeId, 
		ReferenceDescription::SPtr nodeReferenceDescription,
		ReferenceDescription::Vec& referenceDescriptionVec
	)
	{
		VariableNodeClass::SPtr variableNodeClass = VariableNodeClass::construct();
		if (!addReferences(variableNodeClass, referenceDescriptionVec)) return false;

		std::vector<AttributeId> attributeIdVec;
		std::vector<OpcUaDataValue::SPtr> dataValueVec;
		attributeIdVec.push_back(AttributeId_Description);
		attributeIdVec.push_back(AttributeId_WriteMask);
		attributeIdVec.push_back(AttributeId_UserWriteMask);
		attributeIdVec.push_back(AttributeId_UserWriteMask);
		//attributeIdVec.push_back(AttributeId_Value);
		attributeIdVec.push_back(AttributeId_DataType);
		attributeIdVec.push_back(AttributeId_ValueRank);
		attributeIdVec.push_back(AttributeId_AccessLevel);
		attributeIdVec.push_back(AttributeId_UserAccessLevel);
		attributeIdVec.push_back(AttributeId_Historizing);
		attributeIdVec.push_back(AttributeId_Historizing);
		//attributeIdVec.push_back(AttributeId_ArrayDimensions);
		attributeIdVec.push_back(AttributeId_MinimumSamplingInterval);

		if (!readAttributes(nodeId, attributeIdVec, dataValueVec)) return false;

		if (!readNodeBase(nodeId, variableNodeClass, nodeReferenceDescription, dataValueVec)) return false;

#if 0
		if (dataValueVec[3].get() != nullptr) {
			dataValueVec[3]->copyTo(variableNodeClass->value().data());
		}
#endif 

		if (dataValueVec[4].get() != nullptr && dataValueVec[4]->statusCode() == Success) {
			if (!checkVariantType(nodeId, "DataType", dataValueVec[4]->variant(), OpcUaBuildInType_OpcUaNodeId)) return false;
			OpcUaNodeId::SPtr dataType = dataValueVec[4]->variant()->variantSPtr<OpcUaNodeId>();
			dataType->copyTo(variableNodeClass->dataType().data());
		}

		if (dataValueVec[5].get() != nullptr && dataValueVec[5]->statusCode() == Success) {
			if (!checkVariantType(nodeId, "ValueRank", dataValueVec[5]->variant(), OpcUaBuildInType_OpcUaInt32)) return false;
			OpcUaInt32 valueRank = dataValueVec[5]->variant()->variant<OpcUaInt32>();
			variableNodeClass->valueRank().data(valueRank);
		}

		if (dataValueVec[6].get() != nullptr && dataValueVec[6]->statusCode() == Success) {
			if (!checkVariantType(nodeId, "AccessLevel", dataValueVec[6]->variant(), OpcUaBuildInType_OpcUaByte)) return false;
			OpcUaByte accessLevel = dataValueVec[6]->variant()->variant<OpcUaByte>();
			variableNodeClass->accessLevel().data(accessLevel);
		}

		if (dataValueVec[7].get() != nullptr && dataValueVec[7]->statusCode() == Success) {
			if (!checkVariantType(nodeId, "UserAccessLevel", dataValueVec[7]->variant(), OpcUaBuildInType_OpcUaByte)) return false;
			OpcUaByte userAccessLevel = dataValueVec[7]->variant()->variant<OpcUaByte>();
			variableNodeClass->userAccessLevel().data(userAccessLevel);
		}

		if (dataValueVec[8].get() != nullptr && dataValueVec[8]->statusCode() == Success) {
			if (!checkVariantType(nodeId, "Hitoizing", dataValueVec[8]->variant(), OpcUaBuildInType_OpcUaBoolean)) return false;
			OpcUaBoolean historizing = dataValueVec[8]->variant()->variant<OpcUaBoolean>();
			variableNodeClass->historizing().data(historizing);
		}

#if 0
		if (dataValueVec[9].get() != nullptr && dataValueVec[9]->statusCode() == Success) {
			//OpcUaUInt32Array::SPtr arrayDimensions = dataValueVec[9]->variant()->variantSPtr<OpcUaInt32Array>();
			//arrayDimensions->copyTo(variableNodeClass->arrayDimensions().data());
		}
#endif

#if 0
		if (dataValueVec[10].get() != nullptr && dataValueVec[10]->statusCode() == Success) {
			OpcUaDouble minimumSamplingInterval = dataValueVec[10]->variant()->variant<OpcUaDouble>();
			variableNodeClass->minimumSamplingInterval().data(minimumSamplingInterval);
		}
#endif

		variableNodeClassVec().push_back(variableNodeClass);

		return true;
	}

	bool 
	NodeSetClientReader::readMethod(
		OpcUaNodeId& nodeId, 
		ReferenceDescription::SPtr nodeReferenceDescription,
		ReferenceDescription::Vec& referenceDescriptionVec
	)
	{
		MethodNodeClass::SPtr methodNodeClass = MethodNodeClass::construct();
		if (!addReferences(methodNodeClass, referenceDescriptionVec)) return false;

		std::vector<AttributeId> attributeIdVec;
		std::vector<OpcUaDataValue::SPtr> dataValueVec;
		attributeIdVec.push_back(AttributeId_Description);
		attributeIdVec.push_back(AttributeId_WriteMask);
		attributeIdVec.push_back(AttributeId_UserWriteMask);
		attributeIdVec.push_back(AttributeId_Executable);
		attributeIdVec.push_back(AttributeId_UserExecutable);
		if (!readAttributes(nodeId, attributeIdVec, dataValueVec)) return false;

		if (!readNodeBase(nodeId, methodNodeClass, nodeReferenceDescription, dataValueVec)) return false;
	
		if (dataValueVec[3].get() != nullptr && dataValueVec[3]->statusCode() == Success) {
			if (!checkVariantType(nodeId, "Executable", dataValueVec[4]->variant(), OpcUaBuildInType_OpcUaBoolean)) return false;
			OpcUaBoolean executable = dataValueVec[3]->variant()->variant<OpcUaBoolean>();
			methodNodeClass->executable().data(executable);
		}

		if (dataValueVec[4].get() != nullptr&& dataValueVec[4]->statusCode() == Success) {
			if (!checkVariantType(nodeId, "UserExecutable", dataValueVec[4]->variant(), OpcUaBuildInType_OpcUaBoolean)) return false;
			OpcUaBoolean userExecutable = dataValueVec[4]->variant()->variant<OpcUaBoolean>();
			methodNodeClass->userExecutable().data(userExecutable);
		}

		methodNodeClassVec().push_back(methodNodeClass);

		return true;
	}

	bool 
	NodeSetClientReader::readObjectType(
		OpcUaNodeId& nodeId, 
		ReferenceDescription::SPtr nodeReferenceDescription,
		ReferenceDescription::Vec& referenceDescriptionVec
	)
	{
		ObjectTypeNodeClass::SPtr objectTypeNodeClass = ObjectTypeNodeClass::construct();
		if (!addReferences(objectTypeNodeClass, referenceDescriptionVec)) return false;

		std::vector<AttributeId> attributeIdVec;
		std::vector<OpcUaDataValue::SPtr> dataValueVec;
		attributeIdVec.push_back(AttributeId_Description);
		attributeIdVec.push_back(AttributeId_WriteMask);
		attributeIdVec.push_back(AttributeId_UserWriteMask);
		attributeIdVec.push_back(AttributeId_IsAbstract);
		if (!readAttributes(nodeId, attributeIdVec, dataValueVec)) return false;

		if (!readNodeBase(nodeId, objectTypeNodeClass, nodeReferenceDescription, dataValueVec)) return false;
	
		if (dataValueVec[3].get() != nullptr && dataValueVec[3]->statusCode() == Success) {
			if (!checkVariantType(nodeId, "IsAbstract", dataValueVec[3]->variant(), OpcUaBuildInType_OpcUaBoolean)) return false;
			OpcUaBoolean isAbstract = dataValueVec[3]->variant()->variant<OpcUaBoolean>();
			objectTypeNodeClass->isAbstract().data(isAbstract);
		}

		objectTypeNodeClassVec().push_back(objectTypeNodeClass);

		return true;
	}

	bool 
	NodeSetClientReader::readVariableType(
		OpcUaNodeId& nodeId, 
		ReferenceDescription::SPtr nodeReferenceDescription,
		ReferenceDescription::Vec& referenceDescriptionVec
	)
	{
		VariableTypeNodeClass::SPtr variableTypeNodeClass = VariableTypeNodeClass::construct();
		if (!addReferences(variableTypeNodeClass, referenceDescriptionVec)) return false;

		std::vector<AttributeId> attributeIdVec;
		std::vector<OpcUaDataValue::SPtr> dataValueVec;
		attributeIdVec.push_back(AttributeId_Description);
		attributeIdVec.push_back(AttributeId_WriteMask);
		attributeIdVec.push_back(AttributeId_UserWriteMask);
		attributeIdVec.push_back(AttributeId_UserWriteMask);
		//attributeIdVec.push_back(AttributeId_Value);
		attributeIdVec.push_back(AttributeId_DataType);
		attributeIdVec.push_back(AttributeId_ValueRank);
		attributeIdVec.push_back(AttributeId_ValueRank);
		//attributeIdVec.push_back(AttributeId_ArrayDimensions);
		attributeIdVec.push_back(AttributeId_IsAbstract);
		if (!readAttributes(nodeId, attributeIdVec, dataValueVec)) return false;

		if (!readNodeBase(nodeId, variableTypeNodeClass, nodeReferenceDescription, dataValueVec)) return false;
	
#if 0
		if (dataValueVec[3].get() != nullptr) {
			dataValueVec[3]->copyTo(variableTypeNodeClass->value().data());
		}
#endif

		if (dataValueVec[4].get() != nullptr && dataValueVec[4]->statusCode() == Success) {
			if (!checkVariantType(nodeId, "DataType", dataValueVec[4]->variant(), OpcUaBuildInType_OpcUaNodeId)) return false;
			OpcUaNodeId::SPtr dataType = dataValueVec[4]->variant()->variantSPtr<OpcUaNodeId>();
			dataType->copyTo(variableTypeNodeClass->dataType().data());
		}

		if (dataValueVec[5].get() != nullptr && dataValueVec[5]->statusCode() == Success) {
			if (!checkVariantType(nodeId, "ValueRank", dataValueVec[5]->variant(), OpcUaBuildInType_OpcUaInt32)) return false;
			OpcUaInt32 valueRank = dataValueVec[5]->variant()->variant<OpcUaInt32>();
			variableTypeNodeClass->valueRank().data(valueRank);
		}

#if 0
		if (dataValueVec[6].get() != nullptr && dataValueVec[6]->statusCode() == Success) {
			//OpcUaUInt32Array::SPtr arrayDimensions = dataValueVec[6]->variant()->variantSPtr<OpcUaInt32Array>();
			//arrayDimensions->copyTo(variableNodeClass->arrayDimensions().data());
		}
#endif

		if (dataValueVec[7].get() != nullptr && dataValueVec[7]->statusCode() == Success) {
			if (!checkVariantType(nodeId, "IsAbstract", dataValueVec[7]->variant(), OpcUaBuildInType_OpcUaBoolean)) return false;
			OpcUaBoolean isAbstract = dataValueVec[7]->variant()->variant<OpcUaBoolean>();
			variableTypeNodeClass->isAbstract().data(isAbstract);
		}

		variableTypeNodeClassVec().push_back(variableTypeNodeClass);

		return true;
	}

	bool 
	NodeSetClientReader::readReferenceType(
		OpcUaNodeId& nodeId, 
		ReferenceDescription::SPtr nodeReferenceDescription,
		ReferenceDescription::Vec& referenceDescriptionVec
	)
	{
		ReferenceTypeNodeClass::SPtr referenceTypeNodeClass = ReferenceTypeNodeClass::construct();
		if (!addReferences(referenceTypeNodeClass, referenceDescriptionVec)) return false;

		std::vector<AttributeId> attributeIdVec;
		std::vector<OpcUaDataValue::SPtr> dataValueVec;
		attributeIdVec.push_back(AttributeId_Description);
		attributeIdVec.push_back(AttributeId_WriteMask);
		attributeIdVec.push_back(AttributeId_UserWriteMask);
		attributeIdVec.push_back(AttributeId_IsAbstract);
		attributeIdVec.push_back(AttributeId_Symmetric);
		//attributeIdVec.push_back(AttributeId_InverseName);
		if (!readAttributes(nodeId, attributeIdVec, dataValueVec)) return false;

		if (!readNodeBase(nodeId, referenceTypeNodeClass, nodeReferenceDescription, dataValueVec)) return false;
	
		if (dataValueVec[3].get() != nullptr && dataValueVec[3]->statusCode() == Success) {
			if (!checkVariantType(nodeId, "IsAbstract", dataValueVec[3]->variant(), OpcUaBuildInType_OpcUaBoolean)) return false;
			OpcUaBoolean isAbstract = dataValueVec[3]->variant()->variant<OpcUaBoolean>();
			referenceTypeNodeClass->isAbstract().data(isAbstract);
		}

		if (dataValueVec[4].get() != nullptr && dataValueVec[4]->statusCode() == Success) {
			if (!checkVariantType(nodeId, "Symmetric", dataValueVec[4]->variant(), OpcUaBuildInType_OpcUaBoolean)) return false;
			OpcUaBoolean symmetric = dataValueVec[4]->variant()->variant<OpcUaBoolean>();
			referenceTypeNodeClass->symmetric().data(symmetric);
		}

#if 0
		if (dataValueVec[5].get() != nullptr && dataValueVec[5]->statusCode() == Success) {
			OpcUaLocalizedText::SPtr inverseName = dataValueVec[5]->variant()->variantSPtr<OpcUaLocalizedText>();
			inverseName->copyTo(referenceTypeNodeClass->inverseName().data());
		}
#endif

		referenceTypeNodeClassVec().push_back(referenceTypeNodeClass);

		return true;
	}

	bool 
	NodeSetClientReader::readDataType(
		OpcUaNodeId& nodeId, 
		ReferenceDescription::SPtr nodeReferenceDescription,
		ReferenceDescription::Vec& referenceDescriptionVec
	)
	{
		DataTypeNodeClass::SPtr dataTypeNodeClass = DataTypeNodeClass::construct();
		if (!addReferences(dataTypeNodeClass, referenceDescriptionVec)) return false;

		std::vector<AttributeId> attributeIdVec;
		std::vector<OpcUaDataValue::SPtr> dataValueVec;
		attributeIdVec.push_back(AttributeId_Description);
		attributeIdVec.push_back(AttributeId_WriteMask);
		attributeIdVec.push_back(AttributeId_UserWriteMask);
		attributeIdVec.push_back(AttributeId_IsAbstract);
		if (!readAttributes(nodeId, attributeIdVec, dataValueVec)) return false;

		if (!readNodeBase(nodeId, dataTypeNodeClass, nodeReferenceDescription, dataValueVec)) return false;
	
		if (dataValueVec[3].get() != nullptr && dataValueVec[3]->statusCode() == Success) {
			if (!checkVariantType(nodeId, "IsAbstract", dataValueVec[3]->variant(), OpcUaBuildInType_OpcUaBoolean)) return false;
			OpcUaBoolean isAbstract = dataValueVec[3]->variant()->variant<OpcUaBoolean>();
			dataTypeNodeClass->isAbstract().data(isAbstract);
		}

		dataTypeNodeClassVec().push_back(dataTypeNodeClass);

		return true;
	}

	bool 
	NodeSetClientReader::readView(
		OpcUaNodeId& nodeId, 
		ReferenceDescription::SPtr nodeReferenceDescription,
		ReferenceDescription::Vec& referenceDescriptionVec
	)
	{
		ViewNodeClass::SPtr viewNodeClass = ViewNodeClass::construct();
		if (!addReferences(viewNodeClass, referenceDescriptionVec)) return false;

		std::vector<AttributeId> attributeIdVec;
		std::vector<OpcUaDataValue::SPtr> dataValueVec;
		attributeIdVec.push_back(AttributeId_Description);
		attributeIdVec.push_back(AttributeId_WriteMask);
		attributeIdVec.push_back(AttributeId_UserWriteMask);
		attributeIdVec.push_back(AttributeId_ContainsNoLoops);
		attributeIdVec.push_back(AttributeId_EventNotifier);
		if (!readAttributes(nodeId, attributeIdVec, dataValueVec)) return false;

		if (!readNodeBase(nodeId, viewNodeClass, nodeReferenceDescription, dataValueVec)) return false;
	
		if (dataValueVec[3].get() != nullptr && dataValueVec[3]->statusCode() == Success) {
			if (!checkVariantType(nodeId, "ContainsNoLoops", dataValueVec[3]->variant(), OpcUaBuildInType_OpcUaBoolean)) return false;
			OpcUaBoolean containsNoLoops = dataValueVec[3]->variant()->variant<OpcUaBoolean>();
			viewNodeClass->containsNoLoops().data(containsNoLoops);
		}

		if (dataValueVec[4].get() != nullptr && dataValueVec[4]->statusCode() == Success) {
			if (!checkVariantType(nodeId, "EventNotifier", dataValueVec[4]->variant(), OpcUaBuildInType_OpcUaByte)) return false;
			OpcUaByte eventNotifier = dataValueVec[4]->variant()->variant<OpcUaByte>();
			viewNodeClass->eventNotifier().data(eventNotifier);
		}

		viewNodeClassVec().push_back(viewNodeClass);

		return true;
	}

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// SessionIf Interface
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	void 
	NodeSetClientReader::sessionStateUpdate(SessionBase& session, SessionState sessionState)
	{
		switch (sessionState)
		{
			case SS_Connect:
				Log(Debug, "receive session connect in node set client reader");
				break;
			case SS_Disconnect:
				Log(Debug, "receive session disconnect in node set client reader");
				break;
			default:
				Log(Error, "receive invalid session state in node set client reader");
		}

		condition_.conditionTrue();
	}

}
