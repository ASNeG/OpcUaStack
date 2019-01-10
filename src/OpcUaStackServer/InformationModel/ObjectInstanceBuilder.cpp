/*
   Copyright 2019 Kai Huebl (kai@huebl-sgh.de)

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
#include "OpcUaStackServer/InformationModel/ObjectInstanceBuilder.h"
#include "OpcUaStackServer/InformationModel/InformationModelAccess.h"
#include "OpcUaStackServer/InformationModel/NamespaceArray.h"
#include "OpcUaStackServer/NodeSet/NodeSetNamespace.h"
#include "OpcUaStackServer/AddressSpaceModel/VariableTypeNodeClass.h"


using namespace OpcUaStackCore;

namespace OpcUaStackServer
{

	ObjectInstanceBuilder::ObjectInstanceBuilder(void)
	: informationModel_()
	, namespaceIndex_(0)
	, objectBase_()

	, objectNodeClassMap_()
	{
	}

	ObjectInstanceBuilder::~ObjectInstanceBuilder(void)
	{
	}

	OpcUaStatusCode
	ObjectInstanceBuilder::createObjectInstance(
		InformationModel::SPtr& informationModel,
		const std::string& namespaceName,
		const OpcUaLocalizedText& displayName,
		OpcUaNodeId& parentNodeId,
		OpcUaNodeId& referenceTypeNodeId,
		ObjectBase::SPtr& objectBase
	)
	{
		informationModel_ = informationModel;
		objectBase_ = objectBase;

		// get namespace index
		if (!getNamespaceIndex(namespaceName)) {
			Log(Error, "get namesapce index error")
				.parameter("NamespaceName", namespaceName);
			return BadInternalError;
		}

		// find object type namespace index from namespace name
		NodeSetNamespace nodeSetNamespace;
		uint16_t namespaceIndex = nodeSetNamespace.mapToGlobalNamespaceIndex(objectBase->objectTypeNamespaceName());
		if (namespaceIndex == 0xFFFF) {
			Log(Error, "object type namespace name do not exist")
				.parameter("NamespaceName", objectBase->objectTypeNamespaceName());
			return BadInternalError;
		}
		objectBase->objectTypeNodeId().namespaceIndex(namespaceIndex);

		// get parent node class
		BaseNodeClass::SPtr parentBaseNode = informationModel_->find(parentNodeId);
		if (parentBaseNode.get() == nullptr) {
			Log(Error, "parent node id do not exist")
				.parameter("ParentNodeId", parentNodeId);
			return BadInternalError;
		}

		ObjectNodeClass::SPtr objectNodeClass = readObjects(parentNodeId, objectBase->objectTypeNodeId());
		if (objectNodeClass.get() == nullptr) {
			Log(Error, "create object type error")
				.parameter("ObjectTypeNodeId", objectBase->objectTypeNodeId());
			return BadInternalError;
		}
		objectNodeClass->setDisplayName(displayName);

		// added reference
		parentBaseNode->referenceItemMap().add(referenceTypeNodeId, true, *objectNodeClass->getNodeId());
		objectNodeClass->referenceItemMap().add(referenceTypeNodeId, false, parentNodeId);

		return Success;
	}

	bool
	ObjectInstanceBuilder::getNamespaceIndex(const std::string& namespaceName)
	{
		// get namespace index from namespace name
		NodeSetNamespace nodeSetNamespace;
		namespaceIndex_ = nodeSetNamespace.mapToGlobalNamespaceIndex(namespaceName);
		if (namespaceIndex_ != 0xFFFF) return true;

		// the namespace name do not exist in the information model
		nodeSetNamespace.addNewGlobalNamespace(namespaceName);

		NamespaceArray nsa;
		nsa.informationModel(informationModel_);
		nsa.addNamespaceName(namespaceName);

		namespaceIndex_ = nodeSetNamespace.mapToGlobalNamespaceIndex(namespaceName);
		return true;
	}

	ObjectNodeClass::SPtr
	ObjectInstanceBuilder::readObjects(
		const OpcUaNodeId& parentNodeId,
		const OpcUaNodeId& objectTypeNodeId
	)
	{
		InformationModelAccess ima;
		ima.informationModel(informationModel_);

		//
		// find node in opc ua information model
		//
		BaseNodeClass::SPtr baseNodeTemplate = informationModel_->find(objectTypeNodeId);
		if (baseNodeTemplate.get() == nullptr) {
			Log(Error, "object type node identifier not exist in information model")
				.parameter("ObjectTypeNode", objectTypeNodeId);
			ObjectNodeClass::SPtr objectNodeClass;
			return objectNodeClass;
		}

		BrowseName browseName(objectTypeNodeId);
		browseName.pathNames()->resize(10);
		BaseNodeClass::SPtr objectNodeClass = readChilds(parentNodeId, baseNodeTemplate, browseName);
		if (objectNodeClass.get() == nullptr) {
			Log(Error, "read childs error")
				.parameter("ObjectTypeNodeId", objectTypeNodeId);
			ObjectNodeClass::SPtr objectNodeClass;
			return objectNodeClass;
		}

		if (objectTypeNodeId == OpcUaNodeId(58)) {
			return boost::static_pointer_cast<ObjectNodeClass>(objectNodeClass);
		}

		// find parent node identifier
		OpcUaNodeId parentObjectTypeNodeId;
		if (!ima.getSubType(baseNodeTemplate, parentObjectTypeNodeId)) {
			Log(Error, "parent object type node identifier do not not exist in information model")
				.parameter("ObjectTypeNodeId", objectTypeNodeId)
				.parameter("DisplayName", *baseNodeTemplate->getDisplayName());
			ObjectNodeClass::SPtr objectNodeClass;
			return objectNodeClass;
		}

		return readObjects(parentNodeId, parentObjectTypeNodeId);
	}

	BaseNodeClass::SPtr
	ObjectInstanceBuilder::readChilds(
		const OpcUaNodeId& parentNodeId,
		const BaseNodeClass::SPtr& baseNodeTemplate,
		BrowseName& browseNames
	)
	{
		InformationModelAccess ima;
		ima.informationModel(informationModel_);

		// create node class
		BaseNodeClass::SPtr nodeClass;
		switch (*baseNodeTemplate->getNodeClass())
		{
			case NodeClass::EnumObject:
			case NodeClass::EnumObjectType:
			{
				nodeClass = createObjectInstance(baseNodeTemplate, browseNames);
				if (nodeClass.get() == nullptr) {
					Log(Error, "create object node error")
						.parameter("NodeId", *baseNodeTemplate->getNodeId())
						.parameter("BrowseName", browseNames);
					return nodeClass;
				}
				break;
			}
			case NodeClass::EnumVariable:
			{
				nodeClass = createVariableInstance(baseNodeTemplate, browseNames);
				if (nodeClass.get() == nullptr) {
					Log(Error, "create variable node error")
						.parameter("NodeId", *baseNodeTemplate->getNodeId())
						.parameter("BrowseName", browseNames);
					return nodeClass;
				}
				break;
			}
			case NodeClass::EnumMethod:
			{
				nodeClass = createMethodInstance(parentNodeId, baseNodeTemplate, browseNames);
				if (nodeClass.get() == nullptr) {
					Log(Error, "create method node error")
						.parameter("NodeId", *baseNodeTemplate->getNodeId())
						.parameter("BrowseName", browseNames);
					return nodeClass;
				}
				break;
			}
			default:
			{
				Log(Error, "create node error - template node class error")
					.parameter("NodeClass", *baseNodeTemplate->getNodeClass())
					.parameter("NodeId", *baseNodeTemplate->getNodeId());
				return nodeClass;
			}
		}

		// find childs
		BaseNodeClass::Vec childBaseNodeClassVec;
		std::vector<OpcUaNodeId> referenceTypeNodeIdVec;
		if (!ima.getChildHierarchically(baseNodeTemplate, childBaseNodeClassVec, referenceTypeNodeIdVec)) {
			Log(Error, "get hierachically child error")
				.parameter("NodeId", *baseNodeTemplate->getNodeId())
				.parameter("DispalyName", *baseNodeTemplate->getDisplayName());
			BaseNodeClass::SPtr baseNodeClass;
			return baseNodeClass;
		}

		size_t size = browseNames.pathNames()->size();
		for (uint32_t idx = 0; idx < childBaseNodeClassVec.size(); idx++) {
			// ignore HasSubType references
			if (referenceTypeNodeIdVec[idx] == OpcUaNodeId(45)) continue;

			BaseNodeClass::SPtr baseNodeClassChildTemplate = childBaseNodeClassVec[idx];
			OpcUaQualifiedName browseName = *childBaseNodeClassVec[idx]->getBrowseName();

			// only nodes with modelling rules are allowed
			OpcUaNodeId modellingRule;
			if (!baseNodeClassChildTemplate->referenceItemMap().getHasModellingRule(modellingRule)) {
				continue;
			}

			// handle childs of node
			browseNames.pathNames()->set(size, constructSPtr<OpcUaQualifiedName>(browseName));
			BaseNodeClass::SPtr nodeClassChild = readChilds(*nodeClass->getNodeId(), baseNodeClassChildTemplate, browseNames);
			if (nodeClassChild.get() == nullptr) {
				Log(Error, "read childs error")
					.parameter("NodeId", *baseNodeTemplate->getNodeId())
					.parameter("BrowseName", browseName);
				BaseNodeClass::SPtr baseNodeClass;
				return baseNodeClass;
			}
			browseNames.pathNames()->pop_back();

			// create reference between parent and child
			if (!nodeClass->referenceItemMap().exist(referenceTypeNodeIdVec[idx], true, *nodeClassChild->getNodeId())) {
				nodeClass->referenceItemMap().add(referenceTypeNodeIdVec[idx], true, *nodeClassChild->getNodeId());
				nodeClassChild->referenceItemMap().add(referenceTypeNodeIdVec[idx], false, *nodeClass->getNodeId());
			}
		}


		return nodeClass;
	}

	ObjectNodeClass::SPtr
	ObjectInstanceBuilder::createObjectInstance(
		const BaseNodeClass::SPtr& baseNodeTemplate,
		BrowseName& browsePath
	)
	{
		ObjectNodeClass::SPtr objectNode;

		// create object name
		std::string objectName;
		for (uint32_t idx = 0; idx < browsePath.pathNames()->size(); idx++) {
			OpcUaQualifiedName::SPtr browseName;
			browsePath.pathNames()->get(idx, browseName);
			if (!objectName.empty()) objectName += "_";
			objectName += browseName->name().toStdString();
		}
		if (!objectName.empty()) objectName += "_";
		objectName += "Object";

		// check if variable node already exist
		auto it = objectNodeClassMap_.find(objectName);
		if (it != objectNodeClassMap_.end()) return it->second;

		// create object instance
		InformationModelAccess ima;
		ima.informationModel(informationModel_);
		OpcUaNodeId nodeId = ima.createUniqueNodeId(namespaceIndex_);

		switch (*baseNodeTemplate->getNodeClass())
		{
			case NodeClass::EnumObject:
			{
				OpcUaNodeId typeDefintionNode;
				baseNodeTemplate->referenceItemMap().getHasTypeDefinition(typeDefintionNode);

				BaseNodeClass::SPtr objectTypeNode = informationModel_->find(typeDefintionNode);
				if (objectTypeNode.get() == nullptr) {
					Log(Error, "object type definition node not found in information model")
						.parameter("ObjectTypeNode", typeDefintionNode)
						.parameter("ObjectNode", *baseNodeTemplate->getNodeId());
					ObjectNodeClass::SPtr objectNode;
					return objectNode;
				}

				ObjectNodeClass::SPtr objectNode0 = boost::static_pointer_cast<ObjectNodeClass>(baseNodeTemplate);
				objectNode = constructSPtr<ObjectNodeClass>(nodeId, *objectNode0.get());

				objectNode->referenceItemMap().add(
					ReferenceType_HasTypeDefinition,
					true,
					*objectTypeNode->getNodeId()
				);

				objectTypeNode->referenceItemMap().add(
					ReferenceType_HasTypeDefinition,
					false,
					*objectNode->getNodeId()
				);

				break;
			}
			case NodeClass::EnumObjectType:
			{
				ObjectTypeNodeClass::SPtr objectTypeNode = boost::static_pointer_cast<ObjectTypeNodeClass>(baseNodeTemplate);
				objectNode = constructSPtr<ObjectNodeClass>(nodeId, *objectTypeNode.get());

				objectNode->referenceItemMap().add(
					ReferenceType_HasTypeDefinition,
					true,
					*objectTypeNode->getNodeId()
				);

				objectTypeNode->referenceItemMap().add(
					ReferenceType_HasTypeDefinition,
					false,
					*objectNode->getNodeId()
				);

				break;
			}
			default:
			{
				Log(Error, "create object node error - template node class error")
					.parameter("NodeClass", *baseNodeTemplate->getNodeClass())
					.parameter("NodeId", *baseNodeTemplate->getNodeId())
					.parameter("ObjectName", objectName);
				return objectNode;
			}
		}

		objectNodeClassMap_.insert(std::make_pair(objectName, objectNode));

		// added new variable node to information model
		informationModel_->insert(objectNode);
		return objectNode;
	}

	VariableNodeClass::SPtr
	ObjectInstanceBuilder::createVariableInstance(
		const BaseNodeClass::SPtr& baseNodeTemplate,
		BrowseName& browsePath
	)
	{
		VariableNodeClass::SPtr variableNode;

		// create variable variable name
		bool serverVariableExist = true;
		std::string variableName;
		for (uint32_t idx = 0; idx < browsePath.pathNames()->size(); idx++) {
			OpcUaQualifiedName::SPtr browseName;
			browsePath.pathNames()->get(idx, browseName);
			if (!variableName.empty()) variableName += "_";
			variableName += browseName->name().toStdString();

			if (browseName->name().toStdString() == "InputArguments") serverVariableExist = false;
			if (browseName->name().toStdString() == "OutputArguments") serverVariableExist = false;
		}
		if (!variableName.empty()) variableName += "_";
		variableName += "Variable";

		ServerVariable::SPtr serverVariable;
		if (serverVariableExist) {

			// find server variable
			serverVariable = objectBase_->getServerVariable(variableName);
			if (serverVariable.get() == nullptr) {
				Log(Error, "server variable do not exist in variable")
					.parameter("VariableName", variableName);
				return variableNode;
			}

			// check if variable node already exist
			BaseNodeClass::SPtr node = serverVariable->baseNode().lock();
			if (node.get() != nullptr) return boost::static_pointer_cast<VariableNodeClass>(node);
		}

		// create variable instance
		InformationModelAccess ima;
		ima.informationModel(informationModel_);
		OpcUaNodeId nodeId = ima.createUniqueNodeId(namespaceIndex_);
		switch (*baseNodeTemplate->getNodeClass())
		{
			case NodeClass::EnumVariable:
			{
				OpcUaNodeId typeDefintionNode;
				baseNodeTemplate->referenceItemMap().getHasTypeDefinition(typeDefintionNode);

				BaseNodeClass::SPtr variableTypeNode = informationModel_->find(typeDefintionNode);
				if (variableTypeNode.get() == nullptr) {
					Log(Error, "variable type definition node not found in information model")
						.parameter("VariableTypeNode", typeDefintionNode)
						.parameter("VariableNode", *baseNodeTemplate->getNodeId());
					VariableNodeClass::SPtr variableNode;
					return variableNode;
				}

				VariableNodeClass::SPtr variableNode0 = boost::static_pointer_cast<VariableNodeClass>(baseNodeTemplate);
				variableNode = constructSPtr<VariableNodeClass>(nodeId, *variableNode0.get());

				variableNode->referenceItemMap().add(
					ReferenceType_HasTypeDefinition,
					true,
					*variableTypeNode->getNodeId()
				);

				variableTypeNode->referenceItemMap().add(
					ReferenceType_HasTypeDefinition,
					false,
					*variableNode->getNodeId()
				);

				break;
			}
			default:
			{
				Log(Error, "create variable node error - template node class error")
					.parameter("NodeClass", *baseNodeTemplate->getNodeClass())
					.parameter("NodeId", *baseNodeTemplate->getNodeId())
					.parameter("VariableName", variableName);
				return variableNode;
			}
		}

		// connect server instance with server variable
		if (serverVariableExist) {
			serverVariable->baseNode(variableNode);
		}

		// added new variable node to information model
		informationModel_->insert(variableNode);
		return variableNode;
	}

	MethodNodeClass::SPtr
	ObjectInstanceBuilder::createMethodInstance(
		const OpcUaNodeId& parentNodeId,
		const BaseNodeClass::SPtr& baseNodeTemplate,
		BrowseName& browsePath
	)
	{
		MethodNodeClass::SPtr methodNode;

		// create method name
		std::string methodName = browsePath.stringId("Method");

		// find server variable
		ServerMethod::SPtr serverMethod = objectBase_->getServerMethod(methodName);
		if (serverMethod.get() == nullptr) {
			Log(Error, "server method do not exist")
				.parameter("MethodName", methodName);
			return methodNode;
		}

		// create object instance
		InformationModelAccess ima;
		ima.informationModel(informationModel_);
		OpcUaNodeId nodeId = ima.createUniqueNodeId(namespaceIndex_);

		MethodNodeClass::SPtr methodNode0 = boost::static_pointer_cast<MethodNodeClass>(baseNodeTemplate);
		methodNode = constructSPtr<MethodNodeClass>(nodeId, *methodNode0.get());

		// register method callback
		ForwardMethodSync::SPtr forwardMethodSync = constructSPtr<ForwardMethodSync>();
		forwardMethodSync->methodService().setCallback(boost::bind(&ServerMethod::method, serverMethod.get(), _1));
		informationModel_->methodMap().registerMethod(
			parentNodeId,
			nodeId,
			forwardMethodSync
		);

		// added new method node to information model
		informationModel_->insert(methodNode);
		return methodNode;
	}

}

