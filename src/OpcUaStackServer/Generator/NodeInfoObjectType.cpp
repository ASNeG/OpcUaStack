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

#include <boost/algorithm/string.hpp>

#include "OpcUaStackCore/BuildInTypes/OpcUaIdentifier.h"
#include "OpcUaStackServer/Generator/NodeInfoObjectType.h"
#include "OpcUaStackServer/InformationModel/InformationModelAccess.h"
#include "OpcUaStackServer/NodeSet/NodeSetNamespace.h"

using namespace OpcUaStackCore;

namespace OpcUaStackServer
{

	NodeInfoObjectType::NodeInfoObjectType(void)
	: numberNamespaceMap_("OpcUaStackServer")
	, informationModel_()
	, objectTypeNodeId_()
	, parentObjectTypeNodeId_()
	, baseNode_()
	, namespaceName_("")
	, className_("")
	, directory_("")

	, variableTypeFieldMap_()
	, methodTypeFieldMap_()
	{
	}

	NodeInfoObjectType::~NodeInfoObjectType(void)
	{
	}

	bool
	NodeInfoObjectType::init(
		const OpcUaNodeId& objectTypeNodeId,
		InformationModel::SPtr& informationModel
	)
	{
		NodeSetNamespace nodeSetNamespace;

		objectTypeNodeId_ = objectTypeNodeId;
		objectTypeNamespaceName_ = nodeSetNamespace.globalNamespaceVec()[objectTypeNodeId_.namespaceIndex()];
		informationModel_ = informationModel;

		InformationModelAccess ima;
		ima.informationModel(informationModel_);

		//
		// find node in opc ua information model
		//
		baseNode_ = informationModel_->find(objectTypeNodeId);
		if (baseNode_.get() == nullptr) {
			Log(Error, "object type node identifier not exist in information model")
				.parameter("ObjectTypeNode", objectTypeNodeId);
			return false;
		}

		//
		// set namespace name
		//
		namespaceName_ = numberNamespaceMap_.getNamespaceName(objectTypeNodeId_.namespaceIndex());

		//
		// set class name
		//
		boost::optional<OpcUaLocalizedText&> displayName = baseNode_->getDisplayName();
		if (!displayName) {
			Log(Error, "display name not found")
			    .parameter("ObjectTypeNode", objectTypeNodeId_);
		}
		className_ = displayName->text().value();
		className_ = boost::to_upper_copy(className_.substr(0,1)) + className_.substr(1);


		//
		// set directory
		//
		if (objectTypeNodeId_.namespaceIndex() == 0) {
			directory_ = "StandardObjectType";
		}
		else {
			directory_ = "CustomerObjectType";
		}

		//
		// set description
		//
		OpcUaLocalizedText description;
		baseNode_->getDescription(description);
		description_ = description.text().toStdString();

		return readNodes(objectTypeNodeId);
	}

	OpcUaNodeId&
	NodeInfoObjectType::objectTypeNodeId(void)
	{
		return objectTypeNodeId_;
	}

	std::string&
	NodeInfoObjectType::objectTypeNamespaceName(void)
	{
		return objectTypeNamespaceName_;
	}

	std::string&
	NodeInfoObjectType::className(void)
	{
		return className_;
	}

	std::string&
	NodeInfoObjectType::namespaceName(void)
	{
		return namespaceName_;
	}

	std::string
	NodeInfoObjectType::directory(void)
	{
		return directory_;
	}

	std::string&
	NodeInfoObjectType::description(void)
	{
		return description_;
	}

	VariableTypeField::Map&
	NodeInfoObjectType::variableTypeFieldMap(void)
	{
		return variableTypeFieldMap_;
	}

	MethodTypeField::Map&
	NodeInfoObjectType::methodTypeFieldMap(void)
	{
		return methodTypeFieldMap_;
	}

	bool
	NodeInfoObjectType::readNodes(const OpcUaNodeId& objectTypeNodeId)
	{
		InformationModelAccess ima;
		ima.informationModel(informationModel_);

		//
		// find node in opc ua information model
		//
		BaseNodeClass::SPtr baseNode = informationModel_->find(objectTypeNodeId);
		if (baseNode.get() == nullptr) {
			Log(Error, "object type node identifier not exist in information model")
				.parameter("ObjectTypeNode", objectTypeNodeId);
			return false;
		}

		BrowseName browseName(objectTypeNodeId);
		browseName.pathNames()->resize(10);
		if (!readChilds(baseNode, browseName)) {
			Log(Error, "read childs error")
				.parameter("ObjectTypeNodeId", objectTypeNodeId);
			return false;
		}

		if (objectTypeNodeId == OpcUaNodeId(58)) {
			return true;
		}

		// find parent node identifier
		OpcUaNodeId parentObjectTypeNodeId;
		if (!ima.getSubType(baseNode, parentObjectTypeNodeId)) {
			Log(Error, "parent object type node identifier do not not exist in information model")
				.parameter("ObjectTypeNodeId", objectTypeNodeId)
				.parameter("DisplayName", *baseNode->getDisplayName());
			return false;
		}

		return readNodes(parentObjectTypeNodeId);
	}

	bool
	NodeInfoObjectType::readChilds(const BaseNodeClass::SPtr& baseNode, BrowseName& browseNames)
	{
		InformationModelAccess ima;
		ima.informationModel(informationModel_);

		// read node information
		switch (*baseNode->getNodeClass())
		{
			case NodeClass::EnumObjectType:
			{
				if (!readObjectTypeInfo(baseNode, browseNames)) {
					Log(Error, "read object type information error")
						.parameter("NodeId", baseNode->getNodeId())
						.parameter("BrowseName", browseNames);
					return false;
				}
				break;
			}
			case NodeClass::EnumObject:
			{
				if (!readObjectInfo(baseNode, browseNames)) {
					Log(Error, "read object information error")
						.parameter("NodeId", baseNode->getNodeId())
						.parameter("BrowseName", browseNames);
					return false;
				}
				break;
			}
			case NodeClass::EnumVariable:
			{
				if (!readVariableInfo(baseNode, browseNames)) {
					Log(Error, "read variable information error")
						.parameter("NodeId", baseNode->getNodeId())
						.parameter("BrowseName", browseNames);
					return false;
				}
				break;
			}
			case NodeClass::EnumMethod:
			{
				if (!readMethodInfo(baseNode, browseNames)) {
					Log(Error, "read method information error")
						.parameter("NodeId", baseNode->getNodeId())
						.parameter("BrowseName", browseNames);
					return false;
				}
				break;
			}
			default:
			{
				Log(Error, "invalid class name found in read child function")
					.parameter("NodeId", baseNode->getNodeId())
					.parameter("BrowseName", browseNames);
				return false;
			}

		}

		// find childs
		BaseNodeClass::Vec childBaseNodeClassVec;
		std::vector<OpcUaNodeId> referenceTypeNodeIdVec;
		if (!ima.getChildHierarchically(baseNode, childBaseNodeClassVec, referenceTypeNodeIdVec)) {
			Log(Error, "get hierachically child error")
				.parameter("NodeId", *baseNode->getNodeId())
				.parameter("DispalyName", *baseNode->getDisplayName());
			return false;
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

			// ignore optional place holder nodes
			if (modellingRule == OpcUaNodeId(OpcUaId_ModellingRule_OptionalPlaceholder)) {
				continue;
			}

			// handle child nodes
			browseNames.pathNames()->set(size, constructSPtr<OpcUaQualifiedName>(browseName));
			if (!readChilds(baseNodeClassChildTemplate, browseNames)) {
				Log(Error, "read childs error")
					.parameter("NodeId", *baseNode->getNodeId())
					.parameter("BrowseName", browseName);
				return false;
			}
			browseNames.pathNames()->pop_back();
		}

		return true;
	}

	bool
	NodeInfoObjectType::readObjectTypeInfo(const BaseNodeClass::SPtr& baseNode, BrowseName& browsePath)
	{
		return true;
	}

	bool
	NodeInfoObjectType::readObjectInfo(const BaseNodeClass::SPtr& baseNode, BrowseName& browsePath)
	{
		return true;
	}

	bool
	NodeInfoObjectType::readVariableInfo(const BaseNodeClass::SPtr& baseNode, BrowseName& browsePath)
	{
		VariableTypeField::SPtr variableTypeField = constructSPtr<VariableTypeField>();

		Log(Debug, "read variable information")
			.parameter("NodeId", *baseNode->getNodeId())
			.parameter("DisplayName", *baseNode->getDisplayName())
			.parameter("BrowsePath", browsePath);

		// ignore InputArguments und OutputArguments
		if ((*baseNode->getDisplayName()).text().toStdString() == "InputArguments") return true;
		if ((*baseNode->getDisplayName()).text().toStdString() == "OutputArguments") return true;

		// create name
		std::string name = browsePath.stringId("Variable");
		variableTypeField->name(name);

		// create variable name
		std::string variableName = boost::to_lower_copy(name.substr(0,1)) + name.substr(1) + "_";
		variableTypeField->variableName(variableName);

		// create function name
		std::string functionName = boost::to_lower_copy(name.substr(0,1)) + name.substr(1);
		variableTypeField->functionName(functionName);

		// create data type node identifier
		NodeSetNamespace nodeSetNamespace;
		boost::optional<OpcUaNodeId&> dataTypeNodeId = baseNode->getDataType();
		variableTypeField->dataTypeNodeId(*dataTypeNodeId);
		std::string dataTypeNamespaceName = nodeSetNamespace.globalNamespaceVec()[dataTypeNodeId->namespaceIndex()];
		variableTypeField->dataTypeNamespaceName(dataTypeNamespaceName);

		// create value rank
		boost::optional<OpcUaInt32&> valueRank = baseNode->getValueRank();
		if (*valueRank > -1) variableTypeField->isArray(true);

		// handle build in type
		bool buildInTypeExist = false;
		variableTypeField->dataTypeName("Unknown");
		if (dataTypeNodeId->namespaceIndex() == 0 && dataTypeNodeId->nodeIdType() == OpcUaBuildInType_OpcUaUInt32) {
			uint32_t type;
			uint16_t namespaceIndex;
			dataTypeNodeId->get(type, namespaceIndex);
			std::string buildInTypeName = OpcUaBuildInTypeMap::buildInType2String((OpcUaBuildInType)type);
			if (buildInTypeName != "Unknown") {
				if (*valueRank >= 0) variableTypeField->dataTypeDescription(buildInTypeName + " (Array)");
				else variableTypeField->dataTypeDescription(buildInTypeName);

				buildInTypeExist = true;
			}
		}

		if (buildInTypeExist == false) {
			// get type name
			BaseNodeClass::SPtr baseNode = informationModel_->find(*dataTypeNodeId);
			if (baseNode.get() == nullptr) {
				Log(Error, "data type node identifier not exist in information model")
					.parameter("DataTypeNode", dataTypeNodeId);
				return false;
			}
			OpcUaLocalizedText displayName;
			baseNode->getDisplayName(displayName);
			std::string dataTypeName = displayName.text().toStdString();

			if (*valueRank >= 0) variableTypeField->dataTypeDescription(dataTypeName + " (Array)");
			else variableTypeField->dataTypeDescription(dataTypeName);
		}

		// insert variable type field into map
		variableTypeFieldMap_.insert(std::make_pair(name, variableTypeField));

		return true;
	}

	bool
	NodeInfoObjectType::readMethodInfo(const BaseNodeClass::SPtr& baseNode, BrowseName& browsePath)
	{
		MethodTypeField::SPtr methodTypeField = constructSPtr<MethodTypeField>();

		Log(Debug, "read method information")
			.parameter("NodeId", *baseNode->getNodeId())
			.parameter("DisplayName", *baseNode->getDisplayName())
			.parameter("BrowsePath", browsePath);

		// create name
		std::string name = browsePath.stringId("Method");
		methodTypeField->name(name);

		// create variable name
		std::string variableName = boost::to_lower_copy(name.substr(0,1)) + name.substr(1) + "_";
		methodTypeField->variableName(variableName);

		// create function name
		std::string functionName = boost::to_lower_copy(name.substr(0,1)) + name.substr(1);
		methodTypeField->functionName(functionName);

		// insert method type field into map
		methodTypeFieldMap_.insert(std::make_pair(name, methodTypeField));

		return true;
	}

	std::string
	NodeInfoObjectType::getIdentifierAsString(OpcUaNodeId& nodeId)
	{
    	if (nodeId.nodeIdType() == OpcUaBuildInType_OpcUaUInt32) {
    		uint16_t namespaceIndex;
    		uint32_t id;
    		nodeId.get(id, namespaceIndex);

    		std::stringstream ss;
    		ss << "(OpcUaUInt32)" << id;

    		return ss.str();
    	}
    	else if (nodeId.nodeIdType() == OpcUaBuildInType_OpcUaString) {
    		uint16_t namespaceIndex;
    		std::string id;
    		nodeId.get(id, namespaceIndex);

       		std::stringstream ss;
        	ss << "\"" << id << "\"";

        	return ss.str();
    	}
       	else if (nodeId.nodeIdType() == OpcUaBuildInType_OpcUaGuid) {
    		uint16_t namespaceIndex;
    		std::string id;
    		nodeId.get(id, namespaceIndex);

       		std::stringstream ss;
        	ss << "\"" << id << "\"";

        	return ss.str();
        }
       	else {
       		return "(OpcUaUInt32)0";
       	}
    	return "";
	}

}
