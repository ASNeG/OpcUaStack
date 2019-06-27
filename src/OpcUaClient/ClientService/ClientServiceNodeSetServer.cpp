/*
   Copyright 2016 Kai Huebl (kai@huebl-sgh.de)

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

#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/Base/Log.h"
#include "OpcUaStackCore/Base/ConfigXml.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaAttributeId.h"
#include "OpcUaStackServer/AddressSpaceModel/ObjectNodeClass.h"
#include "OpcUaStackServer/AddressSpaceModel/VariableNodeClass.h"
#include "OpcUaStackServer/AddressSpaceModel/MethodNodeClass.h"
#include "OpcUaStackServer/AddressSpaceModel/ObjectTypeNodeClass.h"
#include "OpcUaStackServer/AddressSpaceModel/VariableTypeNodeClass.h"
#include "OpcUaStackServer/AddressSpaceModel/ReferenceTypeNodeClass.h"
#include "OpcUaStackServer/AddressSpaceModel/DataTypeNodeClass.h"
#include "OpcUaStackServer/AddressSpaceModel/ViewNodeClass.h"
#include "OpcUaStackServer/InformationModel/InformationModelNodeSet.h"
#include "OpcUaStackServer/NodeSet/NodeSetXmlParser.h"
#include "OpcUaClient/ClientCommand/CommandNodeSetServer.h"
#include "OpcUaClient/ClientService/ClientServiceNodeSetServer.h"

using namespace OpcUaStackCore;

namespace OpcUaClient
{

	ClientServiceNodeSetServer::ClientServiceNodeSetServer(void)
	: ClientServiceBase()
	, state_(S_Init)
	, browseCompleted_()
	, readCompleted_()
	, attributeService_()
	, baseNodeClass_()
	, readNodeId_()
	, informationModel_(constructSPtr<InformationModel>())
	, nodeSetNamespace_()
	, browseStatusCode_(Success)
	, readStatusCode_(Success)
	, readNamespaceArrayStatusCode_(Success)
	{
	}

	ClientServiceNodeSetServer::~ClientServiceNodeSetServer(void)
	{
	}

	ClientServiceBase::SPtr
	ClientServiceNodeSetServer::createClientService(void)
	{
		return constructSPtr<ClientServiceNodeSetServer>();
	}

	bool
	ClientServiceNodeSetServer::run(ClientServiceManager& clientServiceManager, CommandBase::SPtr& commandBase)
	{
		OpcUaStatusCode statusCode;
		CommandNodeSetServer::SPtr commandNodeSetServer = boost::static_pointer_cast<CommandNodeSetServer>(commandBase);

		// create new or get existing client object
		ClientAccessObject::SPtr clientAccessObject;
		clientAccessObject = clientServiceManager.getClientAccessObject(commandNodeSetServer->session());
		if (clientAccessObject.get() == nullptr) {
			std::stringstream ss;
			ss << "get client access object failed:"
			   << " Session=" << commandNodeSetServer->session();
			errorMessage(ss.str());
			return false;
		}

		// check session
		if (clientAccessObject->sessionService_.get() == nullptr) {
			std::stringstream ss;
			ss << "session object not exist: "
			   << " Session=" << commandNodeSetServer->session();
			return false;
		}

		// get or create attribute service
		attributeService_ = clientAccessObject->getOrCreateAttributeService();
		if (attributeService_.get() == nullptr) {
			std::stringstream ss;
			ss << "get client attribute service failed"
			   << " Session=" << commandNodeSetServer->session();
			errorMessage(ss.str());
			return false;
		}

		// get or create view service
		ViewService::SPtr viewService;
		viewService = clientAccessObject->createViewService();
		if (viewService.get() == nullptr) {
			std::stringstream ss;
			ss << "get client view service failed"
			   << " Session=" << commandNodeSetServer->session();
			errorMessage(ss.str());
			return false;
		}

		// read namespace array
		state_ = S_ReadNamespaceArray;
		statusCode = readNamespaceArray();
		if (statusCode != Success) {
			std::stringstream ss;
			ss << "read namespace array error"
			   << " Session=" << commandNodeSetServer->session()
			   << " StatusCode=" << OpcUaStatusCodeMap::shortString(browseStatusCode_);
			errorMessage(ss.str());
			return false;
		}

		// create start node
		state_ = S_Browse;
		OpcUaNodeId rootNodeId;
		rootNodeId.set((OpcUaUInt32)84);
		if (!createRootNode(rootNodeId)) {
			std::stringstream ss;
			ss << "create start node error"
			   << " Session=" << commandNodeSetServer->session()
			   << " StartNodeId=" << rootNodeId.toString();
			errorMessage(ss.str());
			return false;
		}

		// browse opc ua server information model
		OpcUaNodeId::Vec nodeIdVec;
		OpcUaNodeId::SPtr nodeId = constructSPtr<OpcUaNodeId>();
		nodeId->copyFrom(rootNodeId);
		nodeIdVec.push_back(nodeId);
		commandNodeSetServer->validateCommand();

		ViewServiceBrowse viewServiceBrowse;
		viewServiceBrowse.viewService(viewService);
		viewServiceBrowse.nodeIdVec(nodeIdVec);
		viewServiceBrowse.recursive(true);
		viewServiceBrowse.viewServiceBrowseIf(this);
		viewServiceBrowse.asyncBrowse();

		// wait for the end of the browse request
		browseCompleted_.waitForCondition();
		if (browseStatusCode_ != Success) {
			std::stringstream ss;
			ss << "browse error"
			   << " Session=" << commandNodeSetServer->session()
			   << " StatusCode=" << OpcUaStatusCodeMap::shortString(browseStatusCode_);
			errorMessage(ss.str());
			return false;
		}

		state_ = S_CheckReferences;
		informationModel_->checkForwardReferences();

		// write nodeset to file
		bool rc;
		state_ = S_WriteNodeSet;
		NodeSetXmlParser nodeSetXmlParserWrite;
		rc = InformationModelNodeSet::initial(nodeSetXmlParserWrite, informationModel_, commandNodeSetServer->namespaceUriVec());
		if (!rc) {
			std::stringstream ss;
			ss << "write nodeset initial function error"
			   << " Session=" << commandNodeSetServer->session();
			errorMessage(ss.str());
			return false;
		}

		ConfigXml configXmlWrite;
		rc = nodeSetXmlParserWrite.encode(configXmlWrite.ptree());
		if (!rc) {
			std::stringstream ss;
			ss << "write nodeset encode function error"
			   << " Session=" << commandNodeSetServer->session();
			errorMessage(ss.str());
			return false;
		}

		rc = configXmlWrite.write(commandNodeSetServer->nodeSetName());
		if (!rc) {
			std::stringstream ss;
			ss << "write nodeset error"
			   << " Session=" << commandNodeSetServer->session();
			errorMessage(ss.str());
			return false;
		}

		return true;
	}

	void
	ClientServiceNodeSetServer::viewServiceBrowseDone(OpcUaStatusCode statusCode)
	{
		Log(Debug, "browse done")
		    .parameter("StatusCode", OpcUaStatusCodeMap::shortString(statusCode));

		browseStatusCode_ = statusCode;
		browseCompleted_.conditionTrue();

	}

	void
	ClientServiceNodeSetServer::viewServiceBrowseResult(
		OpcUaStatusCode statusCode,
		OpcUaNodeId::SPtr& nodeId,
		ReferenceDescription::Vec& referenceDescriptionVec
	)
	{
		// check status code
		if (statusCode != Success) {
			Log(Error, "browse result node error")
				.parameter("NodeId", nodeId->toString())
				.parameter("StatusCode", OpcUaStatusCodeMap::shortString(statusCode));
			return;
		}

		// get node from information model
		BaseNodeClass::SPtr baseNodeClass;
		baseNodeClass = informationModel_->find(nodeId);
		if (baseNodeClass.get() == nullptr) {
			Log(Error, "node id not exist in browse request")
				.parameter("NodeId", nodeId->toString());
			return;
		}

		ReferenceDescription::Vec::iterator it;
		for (it = referenceDescriptionVec.begin(); it != referenceDescriptionVec.end(); it++) {
			ReferenceDescription::SPtr referenceDescription = *it;

			// read all node attributes
			OpcUaStatusCode statusCode;
			readNodeId_.nodeIdValue(referenceDescription->expandedNodeId()->nodeIdValue());
			readNodeId_.namespaceIndex(referenceDescription->expandedNodeId()->namespaceIndex());
			statusCode = readNodeAttributes(nodeId, referenceDescription->nodeClass());

			if (statusCode != Success && statusCode != BadNodeIdExists) {
				Log(Warning, "browse result node error")
					.parameter("StatusCode", OpcUaStatusCodeMap::shortString(statusCode));
				continue;
			}

			// add reference to node
			ReferenceItem::SPtr referenceItem = constructSPtr<ReferenceItem>();

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
	}

	OpcUaStatusCode
	ClientServiceNodeSetServer::readNodeAttributes(
		OpcUaNodeId::SPtr& parentNodeId,
		NodeClassType nodeClassType
	)
	{
		// check if node already exist
		BaseNodeClass::SPtr baseNodeClass = informationModel_->find(readNodeId_);
		if (baseNodeClass.get() != nullptr) return BadNodeIdExists;

		switch (nodeClassType)
		{
			case NodeClassType_Object:
			{
				baseNodeClass_ = constructSPtr<ObjectNodeClass>();
				break;
			}
			case NodeClassType_Variable:
			{
				baseNodeClass_ = constructSPtr<VariableNodeClass>();
				break;
			}
			case NodeClassType_Method:
			{
				baseNodeClass_ = constructSPtr<MethodNodeClass>();
				break;
			}
			case NodeClassType_ObjectType:
			{
				baseNodeClass_ = constructSPtr<ObjectTypeNodeClass>();
				break;
			}
			case NodeClassType_VariableType:
			{
				baseNodeClass_ = constructSPtr<VariableTypeNodeClass>();
				break;
			}
			case NodeClassType_ReferenceType:
			{
				baseNodeClass_ = constructSPtr<ReferenceTypeNodeClass>();
				break;
			}
			case NodeClassType_DataType:
			{
				baseNodeClass_ = constructSPtr<DataTypeNodeClass>();
				break;
			}
			case NodeClassType_View:
			{
				baseNodeClass_ = constructSPtr<ViewNodeClass>();
				break;
			}
			default:
			{
				Log(Error, "invalid node class parameter found in reference")
					.parameter("ParentNodeId", parentNodeId->toString())
					.parameter("NodeId", readNodeId_.toString())
					.parameter("NodeClassType", nodeClassType);
				return BadViewParameterMismatch;
			}
		}

		// create read node request information
		AttributeServiceNode attributeServiceNode;
		attributeServiceNode.attributeService(attributeService_);
		attributeServiceNode.nodeId(readNodeId_);
		attributeServiceNode.attributeIds(nodeClassType);
		attributeServiceNode.attributeServiceNodeIf(this);

		// send read node request
		readCompleted_.conditionInit();
		attributeServiceNode.asyncReadNode();

		// wait for the end of the read node request
		readCompleted_.waitForCondition();

		// insert new node
		if (readStatusCode_ == Success) {
			uint16_t localNamepaceIndex;
			uint16_t globalNamespaceIndex;

			// replace local namespace by global namespace index in nodeid
			localNamepaceIndex = readNodeId_.namespaceIndex();
			globalNamespaceIndex = nodeSetNamespace_.mapToGlobalNamespaceIndex(localNamepaceIndex);
			readNodeId_.namespaceIndex(globalNamespaceIndex);

			// replace local namespace by global namespace index in browsename
			if (baseNodeClass_->getBrowseName()) {
				baseNodeClass_->getBrowseName()->namespaceIndex();
				globalNamespaceIndex = nodeSetNamespace_.mapToGlobalNamespaceIndex(localNamepaceIndex);
				baseNodeClass_->getBrowseName()->namespaceIndex(globalNamespaceIndex);
			}

			baseNodeClass_->setNodeId(readNodeId_);
			informationModel_->insert(baseNodeClass_);
		}
		return readStatusCode_;
	}

	OpcUaStatusCode
	ClientServiceNodeSetServer::readNamespaceArray(void)
	{
		Log(Debug, "read namespace array");

		readNodeId_.set(2255);

		// create read node request information
		AttributeServiceNode attributeServiceNode;
		attributeServiceNode.attributeService(attributeService_);
		attributeServiceNode.nodeId(readNodeId_);
		attributeServiceNode.attributeIds(AttributeId_Value);
		attributeServiceNode.attributeServiceNodeIf(this);

		// send read node request
		readCompleted_.conditionInit();
		attributeServiceNode.asyncReadNode();

		// wait for the end of the read node request
		readCompleted_.waitForCondition();
		if (readStatusCode_ != Success) return readStatusCode_;
		return readNamespaceArrayStatusCode_;
	}

	void
	ClientServiceNodeSetServer::attributeServiceNodeDone(OpcUaStatusCode statusCode)
	{
		if (statusCode != Success) {
			Log(Error, "read node attributes error")
				.parameter("ReadNodeId", readNodeId_.toString())
				.parameter("StatusCode", OpcUaStatusCodeMap::shortString(statusCode));
		}
		readStatusCode_ = statusCode;
		readCompleted_.conditionTrue();
	}

	void
	ClientServiceNodeSetServer::attributeServiceNodeResult(AttributeId attributeId, OpcUaDataValue::SPtr& dataValue)
	{
		if (state_ == S_ReadNamespaceArray) {
			handleNamespaceArray(dataValue);
		}
		else {
			baseNodeClass_->set(attributeId, dataValue);
		}
	}

	void
	ClientServiceNodeSetServer::handleNamespaceArray(OpcUaDataValue::SPtr& dataValue)
	{
		readNamespaceArrayStatusCode_ = dataValue->statusCode();
		if (readNamespaceArrayStatusCode_ != Success) {
			Log(Error, "read namespace array data error")
				.parameter("ReadNodeId", readNodeId_.toString())
				.parameter("StatusCode", OpcUaStatusCodeMap::shortString(readNamespaceArrayStatusCode_));
			return;
		}

		if (!dataValue->variant()->isArray()) {
			readNamespaceArrayStatusCode_ = BadTypeMismatch;
			Log(Error, "read namespace array array error")
				.parameter("ReadNodeId", readNodeId_.toString())
				.parameter("StatusCode", OpcUaStatusCodeMap::shortString(readNamespaceArrayStatusCode_));
			return;
		}

		if (dataValue->variant()->variantType() != OpcUaBuildInType_OpcUaString) {
			readNamespaceArrayStatusCode_ = BadTypeMismatch;
			Log(Error, "read namespace array type error")
				.parameter("ReadNodeId", readNodeId_.toString())
				.parameter("StatusCode", OpcUaStatusCodeMap::shortString(readNamespaceArrayStatusCode_));
			return;
		}

		std::vector<std::string> serverNamespaceArray;
		for (uint32_t idx = 0; idx < dataValue->variant()->arrayLength(); idx++) {
			OpcUaString::SPtr namespaceIndexName;
			namespaceIndexName = dataValue->variant()->variantSPtr<OpcUaString>(idx);
			serverNamespaceArray.push_back(namespaceIndexName->value());

			Log(Debug, "read namespace index name")
			    .parameter("NamespaceIndexName", namespaceIndexName->value());
		}

		nodeSetNamespace_.decodeNamespaceUris(serverNamespaceArray);
	}

	bool
	ClientServiceNodeSetServer::createRootNode(OpcUaNodeId& rootNodeId)
	{
		baseNodeClass_ = constructSPtr<ObjectNodeClass>();

		baseNodeClass_->setNodeId(rootNodeId);
		OpcUaQualifiedName browseName("Root");
		baseNodeClass_->setBrowseName(browseName);
		OpcUaLocalizedText displayName("Root", "en");
		baseNodeClass_->setDisplayName(displayName);
		OpcUaUInt32 writeMask = 0;
		baseNodeClass_->setWriteMask(writeMask);
		OpcUaUInt32 userWriteMask = 0;
		baseNodeClass_->setUserWriteMask(userWriteMask);
		OpcUaByte eventNotifier = 0x00;
		baseNodeClass_->setEventNotifier(eventNotifier);

		informationModel_->insert(baseNodeClass_);
		return true;
	}

}

