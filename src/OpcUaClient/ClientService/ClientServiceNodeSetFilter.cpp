/*
   Copyright 2016-2019 Kai Huebl (kai@huebl-sgh.de)

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
#include "OpcUaClient/ClientCommand/CommandNodeSetFilter.h"
#include "OpcUaClient/ClientService/ClientServiceNodeSetFilter.h"

using namespace OpcUaStackCore;
using namespace OpcUaStackClient;
using namespace OpcUaStackServer;

namespace OpcUaClient
{

	ClientServiceNodeSetFilter::ClientServiceNodeSetFilter(void)
	: ClientServiceBase()
	, state_(S_Init)
	, browseCompleted_()
	, readCompleted_()
	, attributeService_()
	, baseNodeClass_()
	, readNodeId_()
	, informationModel_(boost::make_shared<InformationModel>())
	, nodeSetNamespace_()
	, browseStatusCode_(Success)
	, readStatusCode_(Success)
	, readNamespaceArrayStatusCode_(Success)
	{
	}

	ClientServiceNodeSetFilter::~ClientServiceNodeSetFilter(void)
	{
	}

	ClientServiceBase::SPtr
	ClientServiceNodeSetFilter::createClientService(void)
	{
		return boost::make_shared<ClientServiceNodeSetFilter>();
	}

	bool
	ClientServiceNodeSetFilter::run(ClientServiceManager& clientServiceManager, CommandBase::SPtr& commandBase)
	{
		bool rc;
		CommandNodeSetFilter::SPtr commandNodeSetFilter = boost::static_pointer_cast<CommandNodeSetFilter>(commandBase);

		// read node set file
		ConfigXml configXmlRead;
		rc = configXmlRead.read(commandNodeSetFilter->srcNodeSetName());
		if (!rc) {
			std::stringstream ss;
			ss << "read nodeset error"
			   << " SrcNodeSetName=" << commandNodeSetFilter->srcNodeSetName();
			errorMessage(ss.str());
			return false;
		}

		NodeSetXmlParser nodeSetXmlParserRead;
		rc = nodeSetXmlParserRead.decode(configXmlRead.ptree());
		if (!rc) {
			std::stringstream ss;
			ss << "read nodeset decode function error"
			   << " SrcNodeSetName=" << commandNodeSetFilter->srcNodeSetName();
			errorMessage(ss.str());
			return false;
		}

		rc = InformationModelNodeSet::initial(informationModel_, nodeSetXmlParserRead);
		if (!rc) {
			std::stringstream ss;
			ss << "read nodeset initial function error"
			   << " SrcNodeSetName=" << commandNodeSetFilter->srcNodeSetName();
			errorMessage(ss.str());
			return false;
		}


		// write nodeset to file
		NodeSetXmlParser nodeSetXmlParserWrite;
		rc = InformationModelNodeSet::initial(nodeSetXmlParserWrite, informationModel_, commandNodeSetFilter->namespaceUriVec());
		if (!rc) {
			std::stringstream ss;
			ss << "write nodeset initial function error"
			   << " DstNodeSetName=" << commandNodeSetFilter->dstNodeSetName();
			errorMessage(ss.str());
			return false;
		}

		ConfigXml configXmlWrite;
		rc = nodeSetXmlParserWrite.encode(configXmlWrite.ptree());
		if (!rc) {
			std::stringstream ss;
			ss << "write nodeset encode function error"
			   << " DstNodeSetName=" << commandNodeSetFilter->dstNodeSetName();
			errorMessage(ss.str());
			return false;
		}

		rc = configXmlWrite.write(commandNodeSetFilter->dstNodeSetName());
		if (!rc) {
			std::stringstream ss;
			ss << "write nodeset error"
			   << " DstNodeSetName=" << commandNodeSetFilter->dstNodeSetName();
			errorMessage(ss.str());
			return false;
		}

		return true;
	}

	void
	ClientServiceNodeSetFilter::viewServiceBrowseDone(OpcUaStatusCode statusCode)
	{
		Log(Debug, "browse done")
		    .parameter("StatusCode", OpcUaStatusCodeMap::shortString(statusCode));

		browseStatusCode_ = statusCode;
		browseCompleted_.set_value(true);

	}

	void
	ClientServiceNodeSetFilter::viewServiceBrowseResult(
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

			// add reference to node
			if (statusCode == Success) {
				ReferenceItem::SPtr referenceItem = boost::make_shared<ReferenceItem>();

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
	}

	OpcUaStatusCode
	ClientServiceNodeSetFilter::readNodeAttributes(
		OpcUaNodeId::SPtr& parentNodeId,
		NodeClass::Enum nodeClassType
	)
	{
		// check if node already exist
		BaseNodeClass::SPtr baseNodeClass = informationModel_->find(readNodeId_);
		if (baseNodeClass.get() != nullptr) return BadNodeIdExists;

		switch (nodeClassType)
		{
			case NodeClass::EnumObject:
			{
				baseNodeClass_ = boost::make_shared<ObjectNodeClass>();
				break;
			}
			case NodeClass::EnumVariable:
			{
				baseNodeClass_ = boost::make_shared<VariableNodeClass>();
				break;
			}
			case NodeClass::EnumMethod:
			{
				baseNodeClass_ = boost::make_shared<MethodNodeClass>();
				break;
			}
			case NodeClass::EnumObjectType:
			{
				baseNodeClass_ = boost::make_shared<ObjectTypeNodeClass>();
				break;
			}
			case NodeClass::EnumVariableType:
			{
				baseNodeClass_ = boost::make_shared<VariableTypeNodeClass>();
				break;
			}
			case NodeClass::EnumReferenceType:
			{
				baseNodeClass_ = boost::make_shared<ReferenceTypeNodeClass>();
				break;
			}
			case NodeClass::EnumDataType:
			{
				baseNodeClass_ = boost::make_shared<DataTypeNodeClass>();
				break;
			}
			case NodeClass::EnumView:
			{
				baseNodeClass_ = boost::make_shared<ViewNodeClass>();
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
		auto future = readCompleted_.get_future();
		attributeServiceNode.asyncReadNode();

		// wait for the end of the read node request
		future.wait();

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
	ClientServiceNodeSetFilter::readNamespaceArray(void)
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
		auto future = readCompleted_.get_future();
		attributeServiceNode.asyncReadNode();

		// wait for the end of the read node request
		future.wait();
		if (readStatusCode_ != Success) return readStatusCode_;
		return readNamespaceArrayStatusCode_;
	}

	void
	ClientServiceNodeSetFilter::attributeServiceNodeDone(OpcUaStatusCode statusCode)
	{
		if (statusCode != Success) {
			Log(Error, "read node attributes error")
				.parameter("ReadNodeId", readNodeId_.toString())
				.parameter("StatusCode", OpcUaStatusCodeMap::shortString(statusCode));
		}
		readStatusCode_ = statusCode;
		readCompleted_.set_value(true);
	}

	void
	ClientServiceNodeSetFilter::attributeServiceNodeResult(AttributeId attributeId, OpcUaDataValue::SPtr& dataValue)
	{
		if (state_ == S_ReadNamespaceArray) {
			handleNamespaceArray(dataValue);
		}
		else {
			baseNodeClass_->set(attributeId, dataValue);
		}
	}

	void
	ClientServiceNodeSetFilter::handleNamespaceArray(OpcUaDataValue::SPtr& dataValue)
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
	ClientServiceNodeSetFilter::createRootNode(OpcUaNodeId& rootNodeId)
	{
		baseNodeClass_ = boost::make_shared<ObjectNodeClass>();

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

