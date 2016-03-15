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
#include "OpcUaStackServer/AddressSpaceModel/ObjectNodeClass.h"
#include "OpcUaStackServer/AddressSpaceModel/VariableNodeClass.h"
#include "OpcUaStackServer/AddressSpaceModel/MethodNodeClass.h"
#include "OpcUaStackServer/AddressSpaceModel/ObjectTypeNodeClass.h"
#include "OpcUaStackServer/AddressSpaceModel/VariableTypeNodeClass.h"
#include "OpcUaStackServer/AddressSpaceModel/ReferenceTypeNodeClass.h"
#include "OpcUaStackServer/AddressSpaceModel/DataTypeNodeClass.h"
#include "OpcUaStackServer/AddressSpaceModel/ViewNodeClass.h"
#include "OpcUaClient/ClientCommand/CommandNodeSet.h"
#include "OpcUaClient/ClientService/ClientServiceNodeSet.h"

using namespace OpcUaStackCore;

namespace OpcUaClient
{

	ClientServiceNodeSet::ClientServiceNodeSet(void)
	: ClientServiceBase()
	, browseCompleted_()
	, readCompleted_()
	, attributeService_()
	, baseNodeClass_()
	{
	}

	ClientServiceNodeSet::~ClientServiceNodeSet(void)
	{
	}

	ClientServiceBase::SPtr
	ClientServiceNodeSet::createClientService(void)
	{
		return constructSPtr<ClientServiceNodeSet>();
	}

	bool
	ClientServiceNodeSet::run(ClientServiceManager& clientServiceManager, CommandBase::SPtr& commandBase)
	{
		OpcUaStatusCode statusCode;
		CommandNodeSet::SPtr commandNodeSet = boost::static_pointer_cast<CommandNodeSet>(commandBase);

		// create new or get existing client object
		ClientAccessObject::SPtr clientAccessObject;
		clientAccessObject = clientServiceManager.getClientAccessObject(commandNodeSet->session());
		if (clientAccessObject.get() == nullptr) {
			std::stringstream ss;
			ss << "get client access object failed:"
			   << " Session=" << commandNodeSet->session();
			errorMessage(ss.str());
			return false;
		}

		// check session
		if (clientAccessObject->sessionService_.get() == nullptr) {
			std::stringstream ss;
			ss << "session object not exist: "
			   << " Session=" << commandNodeSet->session();
			return false;
		}

		// get or create attribute service
		attributeService_ = clientAccessObject->getOrCreateAttributeService();
		if (attributeService_.get() == nullptr) {
			std::stringstream ss;
			ss << "get client attribute service failed"
			   << " Session=" << commandNodeSet->session();
			errorMessage(ss.str());
			return false;
		}

		// get or create view service
		ViewService::SPtr viewService;
		viewService = clientAccessObject->createViewService();
		if (viewService.get() == nullptr) {
			std::stringstream ss;
			ss << "get client view service failed"
			   << " Session=" << commandNodeSet->session();
			errorMessage(ss.str());
			return false;
		}

		// browse opc ua server information model
		OpcUaNodeId::Vec nodeIdVec;
		OpcUaNodeId::SPtr nodeId = constructSPtr<OpcUaNodeId>();
		nodeId->copyFrom(commandNodeSet->nodeId());
		nodeIdVec.push_back(nodeId);
		commandNodeSet->validateCommand();

		ViewServiceBrowse viewServiceBrowse;
		viewServiceBrowse.viewService(viewService);
		viewServiceBrowse.nodeIdVec(nodeIdVec);
		viewServiceBrowse.recursive(true);
		viewServiceBrowse.viewServiceBrowseIf(this);
		viewServiceBrowse.asyncBrowse();

		// wait for the end of the browse command
		browseCompleted_.waitForCondition();

		return true;
	}

	void
	ClientServiceNodeSet::viewServiceBrowseDone(OpcUaStatusCode statusCode)
	{
		browseCompleted_.conditionTrue();
		std::cout << OpcUaStatusCodeMap::shortString(statusCode) << std::endl;
	}

	void
	ClientServiceNodeSet::viewServiceBrowseResult(
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

		ReferenceDescription::Vec::iterator it;
		for (it = referenceDescriptionVec.begin(); it != referenceDescriptionVec.end(); it++) {
			ReferenceDescription::SPtr referenceDescription = *it;
			readNodeAttributes(nodeId, referenceDescription);
		}
	}

	void
	ClientServiceNodeSet::readNodeAttributes(
		OpcUaNodeId::SPtr& nodeId,
		ReferenceDescription::SPtr& referenceDescription
	)
	{
		OpcUaNodeId readNodeId;
		readNodeId.nodeIdValue(referenceDescription->expandedNodeId()->nodeIdValue());
		readNodeId.namespaceIndex(referenceDescription->expandedNodeId()->namespaceIndex());
		std::cout << "read ..." << readNodeId.toString() << std::endl;

		switch (referenceDescription->nodeClass())
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
					.parameter("ParentNodeId", nodeId->toString())
					.parameter("NodeId", readNodeId.toString())
					.parameter("NodeClassType", referenceDescription->nodeClass());
				return;
			}
		}

		AttributeServiceNode attributeServiceNode;
		attributeServiceNode.attributeService(attributeService_);
		attributeServiceNode.nodeId(readNodeId);
		attributeServiceNode.attributeIds(referenceDescription->nodeClass());
		attributeServiceNode.attributeServiceNodeIf(this);

		readCompleted_.conditionInit();
		attributeServiceNode.asyncReadNode();

		// wait for the end of the browse command
		readCompleted_.waitForCondition();
	}

	void
	ClientServiceNodeSet::attributeServiceNodeDone(OpcUaStatusCode statusCode)
	{
		readCompleted_.conditionTrue();
		std::cout << "StatusCode=" << statusCode << std::endl;
	}

	void
	ClientServiceNodeSet::attributeServiceNodeResult(AttributeId attributeId, OpcUaDataValue::SPtr& dataValue)
	{
		std::cout << ".." << std::endl;
		baseNodeClass_->set(attributeId, dataValue);
	}

}

