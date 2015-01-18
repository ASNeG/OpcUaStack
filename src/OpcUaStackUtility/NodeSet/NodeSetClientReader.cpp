#include "OpcUaStackUtility/NodeSet/NodeSetClientReader.h"
#include "OpcUaStackCore/Base/Log.h"
#include "OpcUaStackClient/ServiceSet/AttributeService.h"
#include "OpcUaStackClient/ServiceSet/ViewService.h"

using namespace OpcUaStackClient;

namespace OpcUaStackUtility
{

	NodeSetClientReader::NodeSetClientReader(void)
	: client_()
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
		session_->createSession();
		rc = condition_.waitForCondition(operationTimeout_);
		if (!rc) {
			Log(Error, "create session timeout in node set client reader");
			return false;
		}
		if (error_) {
			session_->closeSession();
			Log(Error, "create Session error");
			return false;
		}

		// activate session on the opc ua server. A condition is used to wait
		// for the end of the operation
		condition_.conditionInit();
		session_->activateSession();
		rc = condition_.waitForCondition(operationTimeout_);
		if (!rc) {
			Log(Error, "activate session timeout in node set client reader");
			return false;
		}
		if (error_) {
			session_->closeSession();
			Log(Error, "activate Session error");
			return false;
		}

		// read namespace array from opc ua server
		if (!readNamespaceArray()) {
			session_->closeSession();
			Log(Error, "read namespace array error");
			return false;
		}

		// browse nodes from opc ua server
		nodeIdMap_.clear();
		OpcUaNodeId nodeId;
		nodeId.set(84);
		if (!browse(nodeId)) {
			session_->closeSession();
			Log(Error, "browse nodes error");
			return false;
		}
		if (nodeIdMap_.size() == 0) {
			session_->closeSession();
			Log(Error, "browse nodes error, because no nodes found");
			return false;
		}

		std::cout << "Nodes=" << nodeIdMap_.size() << std::endl;

		// read information model from opc ua server
		if (!readInformationModel()) {
			session_->closeSession();
			Log(Error, "read nodes error");
			return false;
		}

		session_->closeSession();
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
		AttributeService attributeService;
		attributeService.componentSession(session_->component());

		//
		// read namespace array
		//
		ServiceTransactionRead::SPtr readTrx = ServiceTransactionRead::construct();
		
		ReadValueId::SPtr readValueIdSPtr = ReadValueId::construct();
		readValueIdSPtr->nodeId((OpcUaInt16)0, (OpcUaInt32)2255);
		readValueIdSPtr->attributeId((OpcUaInt32) 13);
		readValueIdSPtr->dataEncoding().namespaceIndex((OpcUaInt16) 0);

		ReadRequest::SPtr req = readTrx->request();
		req->maxAge(0);
		req->timestampsToReturn(2);
		req->readValueIdArray()->set(readValueIdSPtr);

		attributeService.sendSync(readTrx);

		//
		// check response
		//
		if (readTrx->responseHeader()->serviceResult() != Success) {
			Log(Error, "read namespace array response error")
				.parameter("NodeId", readValueIdSPtr->nodeId())
				.parameter("AttributeId", readValueIdSPtr->attributeId())
				.parameter("ResultCode", OpcUaStatusCodeMap::longString(readTrx->responseHeader()->serviceResult()));
			return false;
		}
		if (readTrx->response()->dataValueArray()->size() != 1) {
			Log(Error, "read namespace array array size error")
				.parameter("NodeId", readValueIdSPtr->nodeId())
				.parameter("AttributeId", readValueIdSPtr->attributeId())
				.parameter("ArraySize", readTrx->response()->dataValueArray()->size());
			return false;
		}

		//
		// check data value
		//
		OpcUaDataValue::SPtr dataValue;
		readTrx->response()->dataValueArray()->get(0, dataValue);
		OpcUaVariant::SPtr variant = dataValue->variant();
		if (dataValue->statusCode() != Success) {
			Log(Error, "read namespace array data value error")
				.parameter("NodeId", readValueIdSPtr->nodeId())
				.parameter("AttributeId", readValueIdSPtr->attributeId())
				.parameter("StatusCode", OpcUaStatusCodeMap::longString(dataValue->statusCode()));
		}

		if (variant->arrayLength() == 0) {
			Log(Error, "read namespace array data value array length error")
				.parameter("NodeId", readValueIdSPtr->nodeId())
				.parameter("AttributeId", readValueIdSPtr->attributeId())
				.parameter("ValueArrayLen", variant->arrayLength());
		}

		//
		// add namespace array from data value into node set namespace array 
		//
		std::vector<std::string> namespaceUriVec;
		for (int32_t idx=0; idx < variant->arrayLength(); idx++) {
			namespaceUriVec.push_back(variant->variant()[idx].variantSPtr<OpcUaString>()->value());
		}
		nodeSetNamespace_.clear();
		nodeSetNamespace_.decodeNamespaceUris(namespaceUriVec);
		return true;
	}

	bool 
	NodeSetClientReader::browse(OpcUaNodeId& nodeId)
	{
		std::vector<OpcUaNodeId> nodeIdVec;
		nodeIdVec.push_back(nodeId);
		return browse(nodeIdVec);
	}

	bool 
	NodeSetClientReader::browse(std::vector<OpcUaNodeId>& nodeIdVec)
	{
		ViewService viewService;
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
			browseDescription->browseDirection(BrowseDirection_Forward);
			req->nodesToBrowse()->push_back(browseDescription);
		}

		viewService.sendSync(browseTrx);

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
		for (uint32_t pos=0; pos<nodeIdVec.size(); pos++) {
			BrowseResult::SPtr browseResult;
			browseTrx->response()->results()->get(pos, browseResult);
			if (browseResult->statusCode() != Success) {
				Log(Error, "browse node result error")
					.parameter("NodeId", nodeIdVec[pos])
					.parameter("StatusCode", OpcUaStatusCodeMap::longString(browseResult->statusCode()));
			}

			//
			// read node information from browse result
			//
			std::vector<OpcUaNodeId> newNodeIdVec;
			ReferenceDescriptionArray::SPtr references = browseResult->references();
			if (references->size() == 0) continue;
			for (uint32_t idx=0; idx<references->size(); idx++) {
				ReferenceDescription::SPtr referenceDescription;
				references->get(idx, referenceDescription);

				// check if node already exist
				OpcUaNodeId nodeId;
				nodeId.nodeIdValue(referenceDescription->nodeId()->nodeIdValue());
				nodeId.namespaceIndex(referenceDescription->nodeId()->namespaceIndex());

				if (nodeIdMap_.find(nodeId) != nodeIdMap_.end()) {
					continue;
				}
				nodeIdMap_.insert(std::make_pair(nodeId, referenceDescription));
				newNodeIdVec.push_back(nodeId);
			}

			if (!browse(newNodeIdVec)) return false;
		}

		return true;
	}

	bool
	NodeSetClientReader::readInformationModel(void)
	{
		NodeIdMap::iterator it;
		for (it=nodeIdMap_.begin(); it!=nodeIdMap_.end(); it++) {
			OpcUaNodeId nodeId = it->first;
			ReferenceDescription::SPtr referenceDescription = it->second;

			bool rc;
			switch (referenceDescription->nodeClass())
			{
				case NodeClassType_Object:
				{
					rc = readObject(nodeId, referenceDescription);
					break;
				}
				case NodeClassType_Variable:
				{
					rc = readVariable(nodeId, referenceDescription);
					break;
				}
				case NodeClassType_Method:
				{
					rc = readMethod(nodeId, referenceDescription);
					break;
				}
				case NodeClassType_ObjectType:
				{
					rc = readObjectType(nodeId, referenceDescription);
					break;
				}
				case NodeClassType_VariableType:
				{
					rc = readVariableType(nodeId, referenceDescription);
					break;
				}
				case NodeClassType_ReferenceType:
				{
					rc = readReferenceType(nodeId, referenceDescription);
					break;
				}
				case NodeClassType_DataType:
				{
					rc = readDataType(nodeId, referenceDescription);
					break;
				}
				case NodeClassType_View:
				{
					rc = readView(nodeId, referenceDescription);
					break;
				}
				default:
				{
					Log(Error, "node class unknown")
						.parameter("NodeId", nodeId)
						.parameter("NodeClass", referenceDescription->nodeClass())
						.parameter("DisplayName", referenceDescription->browseName().name().value());
					return false;
				}
			}

			if (!rc) return false;
		}

		return true;
	}

	bool
	NodeSetClientReader::readAttributes(
		OpcUaNodeId nodeId, 
		std::vector<AttributeId>& attributeIdVec, 
		std::vector<OpcUaDataValue::SPtr>& dataValueVec)
	{
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

		attributeService.sendSync(readTrx);

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
		for (uint32_t idx=0; idx<attributeIdVec.size(); idx++) {
			OpcUaDataValue::SPtr dataValue;
			readTrx->response()->dataValueArray()->get(idx, dataValue);
			
			if (dataValue.get() == nullptr || dataValue->statusCode() != Success) {
				dataValue.reset();
				Log(Warning, "read attributes data value error")
					.parameter("NodeId", nodeId)
					.parameter("StatusCode", OpcUaStatusCodeMap::longString(dataValue->statusCode()));
			}
			dataValueVec.push_back(dataValue);
		}

		return true;
	}

	bool 
	NodeSetClientReader::readNodeBase(
		OpcUaNodeId& nodeId, 
		BaseNodeClass::SPtr baseNodeClass,
		ReferenceDescription::SPtr referenceDescription, 
		std::vector<OpcUaDataValue::SPtr>& dataValueVec)
	{
		nodeId.copyTo(baseNodeClass->nodeId().data());
		referenceDescription->browseName().copyTo(baseNodeClass->browseName().data());
		referenceDescription->displayName().copyTo(baseNodeClass->displayName().data());
		
		if (dataValueVec[0].get() != nullptr) {
			OpcUaLocalizedText::SPtr description = dataValueVec[0]->variant()->variantSPtr<OpcUaLocalizedText>();
			description->copyTo(baseNodeClass->description().data());
		}

		if (dataValueVec[1].get() != nullptr) {
			OpcUaUInt32 writeMask = dataValueVec[1]->variant()->variant<OpcUaUInt32>();
			baseNodeClass->writeMask().data(writeMask);
		}

		if (dataValueVec[2].get() != nullptr) {
			OpcUaUInt32 userWriteMask = dataValueVec[2]->variant()->variant<OpcUaUInt32>();
			baseNodeClass->userWriteMask().data(userWriteMask);
		}

		return true;
	}

	bool 
	NodeSetClientReader::readObject(OpcUaNodeId& nodeId, ReferenceDescription::SPtr referenceDescription)
	{
		ObjectNodeClass::SPtr objectNodeClass = ObjectNodeClass::construct();

		std::vector<AttributeId> attributeIdVec;
		std::vector<OpcUaDataValue::SPtr> dataValueVec;
		attributeIdVec.push_back(AttributeId_Description);
		attributeIdVec.push_back(AttributeId_WriteMask);
		attributeIdVec.push_back(AttributeId_UserWriteMask);
		attributeIdVec.push_back(AttributeId_EventNotifier);
		if (!readAttributes(nodeId, attributeIdVec, dataValueVec)) return false;

		if (!readNodeBase(nodeId, objectNodeClass, referenceDescription, dataValueVec)) return false;
	
		if (dataValueVec[3].get() != nullptr && dataValueVec[3]->statusCode() == Success) {
			OpcUaByte eventNotifier = dataValueVec[3]->variant()->variant<OpcUaByte>();
			objectNodeClass->eventNotifier().data(eventNotifier);
		}

		objectNodeClassVec().push_back(objectNodeClass);

		return true;
	}

	bool 
	NodeSetClientReader::readVariable(OpcUaNodeId& nodeId, ReferenceDescription::SPtr referenceDescription)
	{
		VariableNodeClass::SPtr variableNodeClass = VariableNodeClass::construct();

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

		if (!readNodeBase(nodeId, variableNodeClass, referenceDescription, dataValueVec)) return false;
	
#if 0
		if (dataValueVec[3].get() != nullptr) {
			dataValueVec[3]->copyTo(variableNodeClass->value().data());
		}
#endif

		if (dataValueVec[4].get() != nullptr && dataValueVec[4]->statusCode() == Success) {
			OpcUaNodeId::SPtr dataType = dataValueVec[4]->variant()->variantSPtr<OpcUaNodeId>();
			dataType->copyTo(variableNodeClass->dataType().data());
		}

		if (dataValueVec[5].get() != nullptr && dataValueVec[5]->statusCode() == Success) {
			OpcUaUInt32 valueRank = dataValueVec[5]->variant()->variant<OpcUaUInt32>();
			variableNodeClass->valueRank().data(valueRank);
		}

		if (dataValueVec[6].get() != nullptr && dataValueVec[6]->statusCode() == Success) {
			OpcUaByte accessLevel = dataValueVec[6]->variant()->variant<OpcUaByte>();
			variableNodeClass->accessLevel().data(accessLevel);
		}

		if (dataValueVec[7].get() != nullptr && dataValueVec[7]->statusCode() == Success) {
			OpcUaByte userAccessLevel = dataValueVec[7]->variant()->variant<OpcUaByte>();
			variableNodeClass->userAccessLevel().data(userAccessLevel);
		}

		if (dataValueVec[8].get() != nullptr && dataValueVec[8]->statusCode() == Success) {
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
	NodeSetClientReader::readMethod(OpcUaNodeId& nodeId, ReferenceDescription::SPtr referenceDescription)
	{
		MethodNodeClass::SPtr methodNodeClass = MethodNodeClass::construct();

		std::vector<AttributeId> attributeIdVec;
		std::vector<OpcUaDataValue::SPtr> dataValueVec;
		attributeIdVec.push_back(AttributeId_Description);
		attributeIdVec.push_back(AttributeId_WriteMask);
		attributeIdVec.push_back(AttributeId_UserWriteMask);
		attributeIdVec.push_back(AttributeId_Executable);
		attributeIdVec.push_back(AttributeId_UserExecutable);
		if (!readAttributes(nodeId, attributeIdVec, dataValueVec)) return false;

		if (!readNodeBase(nodeId, methodNodeClass, referenceDescription, dataValueVec)) return false;
	
		if (dataValueVec[3].get() != nullptr && dataValueVec[3]->statusCode() == Success) {
			OpcUaBoolean executable = dataValueVec[3]->variant()->variant<OpcUaBoolean>();
			methodNodeClass->executable().data(executable);
		}

		if (dataValueVec[4].get() != nullptr&& dataValueVec[3]->statusCode() == Success) {
			OpcUaBoolean userExecutable = dataValueVec[4]->variant()->variant<OpcUaBoolean>();
			methodNodeClass->userExecutable().data(userExecutable);
		}

		methodNodeClassVec().push_back(methodNodeClass);

		return true;
	}

	bool 
	NodeSetClientReader::readObjectType(OpcUaNodeId& nodeId, ReferenceDescription::SPtr referenceDescription)
	{
		ObjectTypeNodeClass::SPtr objectTypeNodeClass = ObjectTypeNodeClass::construct();

		std::vector<AttributeId> attributeIdVec;
		std::vector<OpcUaDataValue::SPtr> dataValueVec;
		attributeIdVec.push_back(AttributeId_Description);
		attributeIdVec.push_back(AttributeId_WriteMask);
		attributeIdVec.push_back(AttributeId_UserWriteMask);
		attributeIdVec.push_back(AttributeId_IsAbstract);
		if (!readAttributes(nodeId, attributeIdVec, dataValueVec)) return false;

		if (!readNodeBase(nodeId, objectTypeNodeClass, referenceDescription, dataValueVec)) return false;
	
		if (dataValueVec[3].get() != nullptr && dataValueVec[3]->statusCode() == Success) {
			OpcUaBoolean isAbstract = dataValueVec[3]->variant()->variant<OpcUaBoolean>();
			objectTypeNodeClass->isAbstract().data(isAbstract);
		}

		objectTypeNodeClassVec().push_back(objectTypeNodeClass);

		return true;
	}

	bool 
	NodeSetClientReader::readVariableType(OpcUaNodeId& nodeId, ReferenceDescription::SPtr referenceDescription)
	{
		VariableTypeNodeClass::SPtr variableTypeNodeClass = VariableTypeNodeClass::construct();

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

		if (!readNodeBase(nodeId, variableTypeNodeClass, referenceDescription, dataValueVec)) return false;
	
#if 0
		if (dataValueVec[3].get() != nullptr) {
			dataValueVec[3]->copyTo(variableTypeNodeClass->value().data());
		}
#endif

		if (dataValueVec[4].get() != nullptr && dataValueVec[4]->statusCode() == Success) {
			OpcUaNodeId::SPtr dataType = dataValueVec[4]->variant()->variantSPtr<OpcUaNodeId>();
			dataType->copyTo(variableTypeNodeClass->dataType().data());
		}

		if (dataValueVec[5].get() != nullptr && dataValueVec[5]->statusCode() == Success) {
			OpcUaUInt32 valueRank = dataValueVec[5]->variant()->variant<OpcUaUInt32>();
			variableTypeNodeClass->valueRank().data(valueRank);
		}

#if 0
		if (dataValueVec[6].get() != nullptr && dataValueVec[6]->statusCode() == Success) {
			//OpcUaUInt32Array::SPtr arrayDimensions = dataValueVec[6]->variant()->variantSPtr<OpcUaInt32Array>();
			//arrayDimensions->copyTo(variableNodeClass->arrayDimensions().data());
		}
#endif

		if (dataValueVec[7].get() != nullptr && dataValueVec[7]->statusCode() == Success) {
			OpcUaBoolean isAbstract = dataValueVec[7]->variant()->variant<OpcUaBoolean>();
			variableTypeNodeClass->isAbstract().data(isAbstract);
		}

		variableTypeNodeClassVec().push_back(variableTypeNodeClass);

		return true;
	}

	bool 
	NodeSetClientReader::readReferenceType(OpcUaNodeId& nodeId, ReferenceDescription::SPtr referenceDescription)
	{
		ReferenceTypeNodeClass::SPtr referenceTypeNodeClass = ReferenceTypeNodeClass::construct();

		std::vector<AttributeId> attributeIdVec;
		std::vector<OpcUaDataValue::SPtr> dataValueVec;
		attributeIdVec.push_back(AttributeId_Description);
		attributeIdVec.push_back(AttributeId_WriteMask);
		attributeIdVec.push_back(AttributeId_UserWriteMask);
		attributeIdVec.push_back(AttributeId_IsAbstract);
		attributeIdVec.push_back(AttributeId_Symmetric);
		//attributeIdVec.push_back(AttributeId_InverseName);
		if (!readAttributes(nodeId, attributeIdVec, dataValueVec)) return false;

		if (!readNodeBase(nodeId, referenceTypeNodeClass, referenceDescription, dataValueVec)) return false;
	
		if (dataValueVec[3].get() != nullptr && dataValueVec[3]->statusCode() == Success) {
			OpcUaBoolean isAbstract = dataValueVec[3]->variant()->variant<OpcUaBoolean>();
			referenceTypeNodeClass->isAbstract().data(isAbstract);
		}

		if (dataValueVec[4].get() != nullptr && dataValueVec[4]->statusCode() == Success) {
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
	NodeSetClientReader::readDataType(OpcUaNodeId& nodeId, ReferenceDescription::SPtr referenceDescription)
	{
		DataTypeNodeClass::SPtr dataTypeNodeClass = DataTypeNodeClass::construct();

		std::vector<AttributeId> attributeIdVec;
		std::vector<OpcUaDataValue::SPtr> dataValueVec;
		attributeIdVec.push_back(AttributeId_Description);
		attributeIdVec.push_back(AttributeId_WriteMask);
		attributeIdVec.push_back(AttributeId_UserWriteMask);
		attributeIdVec.push_back(AttributeId_IsAbstract);
		if (!readAttributes(nodeId, attributeIdVec, dataValueVec)) return false;

		if (!readNodeBase(nodeId, dataTypeNodeClass, referenceDescription, dataValueVec)) return false;
	
		if (dataValueVec[3].get() != nullptr && dataValueVec[3]->statusCode() == Success) {
			OpcUaBoolean isAbstract = dataValueVec[3]->variant()->variant<OpcUaBoolean>();
			dataTypeNodeClass->isAbstract().data(isAbstract);
		}

		dataTypeNodeClassVec().push_back(dataTypeNodeClass);

		return true;
	}

	bool 
	NodeSetClientReader::readView(OpcUaNodeId& nodeId, ReferenceDescription::SPtr referenceDescription)
	{
		ViewNodeClass::SPtr viewNodeClass = ViewNodeClass::construct();

		std::vector<AttributeId> attributeIdVec;
		std::vector<OpcUaDataValue::SPtr> dataValueVec;
		attributeIdVec.push_back(AttributeId_Description);
		attributeIdVec.push_back(AttributeId_WriteMask);
		attributeIdVec.push_back(AttributeId_UserWriteMask);
		attributeIdVec.push_back(AttributeId_ContainsNoLoops);
		attributeIdVec.push_back(AttributeId_EventNotifier);
		if (!readAttributes(nodeId, attributeIdVec, dataValueVec)) return false;

		if (!readNodeBase(nodeId, viewNodeClass, referenceDescription, dataValueVec)) return false;
	
		if (dataValueVec[3].get() != nullptr && dataValueVec[3]->statusCode() == Success) {
			OpcUaBoolean containsNoLoops = dataValueVec[3]->variant()->variant<OpcUaBoolean>();
			viewNodeClass->containsNoLoops().data(containsNoLoops);
		}

		if (dataValueVec[4].get() != nullptr && dataValueVec[4]->statusCode() == Success) {
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
	NodeSetClientReader::error(void)
	{
		Log(Error, "session error in node set client reader");
		error_ = true;
		condition_.conditionTrue();
	}

	void 
	NodeSetClientReader::createSessionComplete(OpcUaStatusCode opcUaStatusCode)
	{
		Log(Debug, "create session complete in node set client reader")
			.parameter("StatusCode", opcUaStatusCode);
		if (opcUaStatusCode != Success) error_ = true;
		condition_.conditionTrue();
	}

	void 
	NodeSetClientReader::activateSessionComplete(OpcUaStatusCode opcUaStatusCode)
	{
		Log(Debug, "activate session complete in node set client reader")
			.parameter("StatusCode", opcUaStatusCode);
		if (opcUaStatusCode != Success) error_ = true;
		condition_.conditionTrue();
	}

}