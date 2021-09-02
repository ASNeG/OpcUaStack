/*
   Copyright 2019-2021 Kai Huebl (kai@huebl-sgh.de)

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
#include "OpcUaStackServer/InformationModel/VariableInstanceBuilder.h"
#include "OpcUaStackServer/InformationModel/InformationModelAccess.h"
#include "OpcUaStackServer/InformationModel/NamespaceArray.h"
#include "OpcUaStackServer/NodeSet/NodeSetNamespace.h"
#include "OpcUaStackServer/AddressSpaceModel/VariableTypeNodeClass.h"

using namespace OpcUaStackCore;

namespace OpcUaStackServer
{

	VariableInstanceBuilder::VariableInstanceBuilder(void)
	: informationModel_()
	, variableNameSet_()
	, namespaceIndex_(0)
	, variableBase_()
	{
	}

	VariableInstanceBuilder::~VariableInstanceBuilder(void)
	{
	}

	OpcUaStatusCode
	VariableInstanceBuilder::createVariableInstance(
		InformationModel::SPtr& informationModel,
		const std::string& namespaceName,
		const OpcUaLocalizedText& displayName,
		OpcUaNodeId& parentNodeId,
		OpcUaNodeId& referenceTypeNodeId,
		VariableBase::SPtr& variableBase,
		NodeIdMap* nodeIdMap
	)
	{
		informationModel_ = informationModel;
		variableBase_ = variableBase;
		nodeIdMap_ = nodeIdMap;

		// get namespace index
		if (!getNamespaceIndex(namespaceName)) {
			Log(Error, "get namesapce index error")
				.parameter("NamespaceName", namespaceName);
			return BadInternalError;
		}

		// find variable type namespace index from namespace name
		NodeSetNamespace nodeSetNamespace;
		uint16_t namespaceIndex = nodeSetNamespace.mapToGlobalNamespaceIndex(variableBase->variableTypeNamespaceName());
		if (namespaceIndex == 0xFFFF) {
			Log(Error, "variable type namespace name do not exist")
				.parameter("NamespaceName", variableBase->variableTypeNamespaceName());
			return BadInternalError;
		}
		variableBase->variableTypeNodeId().namespaceIndex(namespaceIndex);

		// get parent node class
		BaseNodeClass::SPtr parentBaseNode = informationModel_->find(parentNodeId);
		if (parentBaseNode.get() == nullptr) {
			Log(Error, "parent node id do not exist")
				.parameter("ParentNodeId", parentNodeId);
			return BadInternalError;
		}

		VariableNodeClass::SPtr variableNodeClass = readValues(variableBase->variableTypeNodeId());
		if (variableNodeClass.get() == nullptr) {
			Log(Error, "create variable type error")
				.parameter("VariableTypeNodeId", variableBase->variableTypeNodeId());
			return BadInternalError;
		}
		variableNodeClass->setDisplayName(displayName);

		// added reference
		parentBaseNode->referenceItemMap().add(referenceTypeNodeId, true, *variableNodeClass->getNodeId());
		variableNodeClass->referenceItemMap().add(referenceTypeNodeId, false, parentNodeId);

		return Success;
	}

	bool
	VariableInstanceBuilder::getNamespaceIndex(const std::string& namespaceName)
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

	VariableNodeClass::SPtr
	VariableInstanceBuilder::readValues(const OpcUaNodeId& variableTypeNodeId)
	{
		InformationModelAccess ima;
		ima.informationModel(informationModel_);

		//
		// find node in opc ua information model
		//
		BaseNodeClass::SPtr baseNodeTemplate = informationModel_->find(variableTypeNodeId);
		if (baseNodeTemplate.get() == nullptr) {
			Log(Error, "variable type node identifier not exist in information model")
				.parameter("VariableTypeNode", variableTypeNodeId);
			VariableNodeClass::SPtr variableNodeClass;
			return variableNodeClass;
		}

		BrowseName browseName(variableTypeNodeId);
		browseName.pathNames()->resize(10);
		VariableNodeClass::SPtr variableNodeClass = readChilds(baseNodeTemplate, browseName);
		if (variableNodeClass.get() == nullptr) {
			Log(Error, "read childs error")
				.parameter("VariableTypeNodeId", variableTypeNodeId);
			VariableNodeClass::SPtr variableNodeClass;
			return variableNodeClass;
		}

		if (variableTypeNodeId == OpcUaNodeId(62)) {
			return variableNodeClass;
		}

		// find parent node identifier
		OpcUaNodeId parentVariableTypeNodeId;
		if (!ima.getSubType(baseNodeTemplate, parentVariableTypeNodeId)) {
			Log(Error, "parent variable type node identifier do not not exist in information model")
				.parameter("VariableTypeNodeId", variableTypeNodeId)
				.parameter("DisplayName", *baseNodeTemplate->getDisplayName());
			VariableNodeClass::SPtr variableNodeClass;
			return variableNodeClass;
		}

		return readValues(parentVariableTypeNodeId);
	}

	VariableNodeClass::SPtr
	VariableInstanceBuilder::readChilds(
		const BaseNodeClass::SPtr& baseNodeTemplate,
		BrowseName& browseNames
	)
	{
		InformationModelAccess ima;
		ima.informationModel(informationModel_);

		// read node information
		VariableNodeClass::SPtr variableNodeClass = createVariableInstance(baseNodeTemplate, browseNames);
		if (variableNodeClass.get() == nullptr) {
			Log(Error, "create variable node error")
				.parameter("NodeId", *baseNodeTemplate->getNodeId())
				.parameter("BrowseName", browseNames);
			return variableNodeClass;
		}

		// find childs
		BaseNodeClass::Vec childBaseNodeClassVec;
		std::vector<OpcUaNodeId> referenceTypeNodeIdVec;
		if (!ima.getChildHierarchically(baseNodeTemplate, childBaseNodeClassVec, referenceTypeNodeIdVec)) {
			Log(Error, "get hierachically child error")
				.parameter("NodeId", *baseNodeTemplate->getNodeId())
				.parameter("DispalyName", *baseNodeTemplate->getDisplayName());
			VariableNodeClass::SPtr variableNodeClass;
			return variableNodeClass;
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
			browseNames.pathNames()->set(size, boost::make_shared<OpcUaQualifiedName>(browseName));
			VariableNodeClass::SPtr variableNodeClassChild = readChilds(baseNodeClassChildTemplate, browseNames);
			if (variableNodeClassChild.get() == nullptr) {
				Log(Error, "read childs error")
					.parameter("NodeId", *baseNodeTemplate->getNodeId())
					.parameter("BrowseName", browseName);
				VariableNodeClass::SPtr variableNodeClass;
				return variableNodeClass;
			}
			browseNames.pathNames()->pop_back();

			// create reference between parent and child
			if (!variableNodeClass->referenceItemMap().exist(referenceTypeNodeIdVec[idx], true, *variableNodeClassChild->getNodeId())) {
				variableNodeClass->referenceItemMap().add(referenceTypeNodeIdVec[idx], true, *variableNodeClassChild->getNodeId());
				variableNodeClassChild->referenceItemMap().add(referenceTypeNodeIdVec[idx], false, *variableNodeClass->getNodeId());
			}
		}

		return variableNodeClass;
	}

	VariableNodeClass::SPtr
	VariableInstanceBuilder::createVariableInstance(
		const BaseNodeClass::SPtr& baseNodeTemplate,
		BrowseName& browsePath
	)
	{
		VariableNodeClass::SPtr variableNode;

		// create variable variable name
		std::string variableName;
		for (uint32_t idx = 0; idx < browsePath.pathNames()->size(); idx++) {
			OpcUaQualifiedName::SPtr browseName;
			browsePath.pathNames()->get(idx, browseName);
			if (!variableName.empty()) variableName += "_";
			variableName += browseName->name().toStdString();
		}
		if (!variableName.empty()) variableName += "_";
		variableName += "Variable";

		// find server variable
		ServerVariable::SPtr serverVariable = variableBase_->getServerVariable(variableName);
		if (serverVariable.get() == nullptr) {
			Log(Error, "server variable do not exist in variable data type")
				.parameter("VariableName", variableName);
			return variableNode;
		}

		// check if variable node already exist
		BaseNodeClass::SPtr node = serverVariable->baseNode().lock();
		if (node.get() != nullptr) return boost::static_pointer_cast<VariableNodeClass>(node);

		// create variable instance
		InformationModelAccess ima;
		ima.informationModel(informationModel_);

		OpcUaNodeId nodeId = ima.createUniqueNodeId(namespaceIndex_);
		if (nodeIdMap_ != nullptr) {
			auto itNodeId = nodeIdMap_->find(variableName);
			if (itNodeId != nodeIdMap_->end()) {
				nodeId = itNodeId->second;
				if (nodeId.namespaceIndex() == 0) {
					nodeId.namespaceIndex(namespaceIndex_);
				}
			}
		}

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
				variableNode = boost::make_shared<VariableNodeClass>(nodeId, *variableNode0.get());

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
			case NodeClass::EnumVariableType:
			{
				VariableTypeNodeClass::SPtr variableTypeNode = boost::static_pointer_cast<VariableTypeNodeClass>(baseNodeTemplate);
				variableNode = boost::make_shared<VariableNodeClass>(nodeId, *variableTypeNode.get());

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
		serverVariable->baseNode(variableNode);

		// added new variable node to information model
		informationModel_->insert(variableNode);
		return variableNode;
	}

}

