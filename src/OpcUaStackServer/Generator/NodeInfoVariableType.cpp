/*
   Copyright 2018-2019 Kai Huebl (kai@huebl-sgh.de)

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

#include "OpcUaStackServer/Generator/NodeInfoVariableType.h"
#include "OpcUaStackServer/InformationModel/InformationModelAccess.h"
#include "OpcUaStackServer/NodeSet/NodeSetNamespace.h"

using namespace OpcUaStackCore;

namespace OpcUaStackServer
{

	NodeInfoVariableType::NodeInfoVariableType(void)
	: numberNamespaceMap_("OpcUaStackServer")
	, informationModel_()
	, variableTypeNodeId_()
	, parentVariableTypeNodeId_()
	, baseNode_()
	, namespaceName_("")
	, className_("")
	, directory_("")

	, variableTypeFieldMap_()
	{
	}

	NodeInfoVariableType::~NodeInfoVariableType(void)
	{
	}

	bool
	NodeInfoVariableType::init(
		const OpcUaNodeId& variableTypeNodeId,
		InformationModel::SPtr& informationModel
	)
	{
		NodeSetNamespace nodeSetNamespace;

		variableTypeNodeId_ = variableTypeNodeId;
		variableTypeNamespaceName_ = nodeSetNamespace.globalNamespaceVec()[variableTypeNodeId_.namespaceIndex()];
		informationModel_ = informationModel;

		InformationModelAccess ima;
		ima.informationModel(informationModel_);

		//
		// find node in opc ua information model
		//
		baseNode_ = informationModel_->find(variableTypeNodeId);
		if (baseNode_.get() == nullptr) {
			Log(Error, "variable type node identifier not exist in information model")
				.parameter("VariableTypeNode", variableTypeNodeId);
			return false;
		}

		//
		// set namespace name
		//
		namespaceName_ = numberNamespaceMap_.getNamespaceName(variableTypeNodeId_.namespaceIndex());

		//
		// set class name
		//
		boost::optional<OpcUaLocalizedText&> displayName = baseNode_->getDisplayName();
		if (!displayName) {
			Log(Error, "display name not found")
			    .parameter("VariableTypeNode", variableTypeNodeId_);
		}
		className_ = displayName->text().value();
		className_ = boost::to_upper_copy(className_.substr(0,1)) + className_.substr(1);


		//
		// set directory
		//
		if (variableTypeNodeId_.namespaceIndex() == 0) {
			directory_ = "StandardVariableType";
		}
		else {
			directory_ = "CustomerVariableType";
		}

		//
		// set description
		//
		OpcUaLocalizedText description;
		baseNode_->getDescription(description);
		description_ = description.text().toStdString();

		return readValues(variableTypeNodeId);
	}

	OpcUaNodeId&
	NodeInfoVariableType::variableTypeNodeId(void)
	{
		return variableTypeNodeId_;
	}

	std::string&
	NodeInfoVariableType::variableTypeNamespaceName(void)
	{
		return variableTypeNamespaceName_;
	}

	std::string&
	NodeInfoVariableType::className(void)
	{
		return className_;
	}

	std::string&
	NodeInfoVariableType::namespaceName(void)
	{
		return namespaceName_;
	}

	std::string
	NodeInfoVariableType::directory(void)
	{
		return directory_;
	}

	std::string&
	NodeInfoVariableType::description(void)
	{
		return description_;
	}

	VariableTypeField::Map&
	NodeInfoVariableType::variableTypeFieldMap(void)
	{
		return variableTypeFieldMap_;
	}

	bool
	NodeInfoVariableType::readValues(const OpcUaNodeId& variableTypeNodeId)
	{
		InformationModelAccess ima;
		ima.informationModel(informationModel_);

		//
		// find node in opc ua information model
		//
		BaseNodeClass::SPtr baseNode = informationModel_->find(variableTypeNodeId);
		if (baseNode.get() == nullptr) {
			Log(Error, "variable type node identifier not exist in information model")
				.parameter("VariableTypeNode", variableTypeNodeId);
			return false;
		}

		BrowseName browseName(variableTypeNodeId);
		browseName.pathNames()->resize(10);
		if (!readChilds(baseNode, browseName)) {
			Log(Error, "read childs error")
				.parameter("VariableTypeNodeId", variableTypeNodeId);
			return false;
		}

		if (variableTypeNodeId == OpcUaNodeId(62)) {
			return true;
		}

		// find parent node identifier
		OpcUaNodeId parentVariableTypeNodeId;
		if (!ima.getSubType(baseNode, parentVariableTypeNodeId)) {
			Log(Error, "parent variable type node identifier do not not exist in information model")
				.parameter("VariableTypeNodeId", variableTypeNodeId)
				.parameter("DisplayName", *baseNode->getDisplayName());
			return false;
		}

		return readValues(parentVariableTypeNodeId);
	}

	bool
	NodeInfoVariableType::readChilds(const BaseNodeClass::SPtr& baseNode, BrowseName& browseNames)
	{
		InformationModelAccess ima;
		ima.informationModel(informationModel_);

		// read node information
		if (!readNodeInfo(baseNode, browseNames)) {
			Log(Error, "read node information error")
				.parameter("NodeId", baseNode->getNodeId())
				.parameter("BrowseName", browseNames);
			return false;
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

			// handle child nodes
			browseNames.pathNames()->set(size, boost::make_shared<OpcUaQualifiedName>(browseName));
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
	NodeInfoVariableType::readNodeInfo(const BaseNodeClass::SPtr& baseNode, BrowseName& browsePath)
	{
		VariableTypeField::SPtr variableTypeField = boost::make_shared<VariableTypeField>();

		Log(Debug, "read node information")
			.parameter("NodeId", *baseNode->getNodeId())
			.parameter("DisplayName", *baseNode->getDisplayName())
			.parameter("BrowsePath", browsePath);

		// create name
		std::string name;
		for (uint32_t idx = 0; idx < browsePath.pathNames()->size(); idx++) {
			OpcUaQualifiedName::SPtr browseName;
			browsePath.pathNames()->get(idx, browseName);
			if (!name.empty()) name += "_";
			name += browseName->name().toStdString();
		}
		if (!name.empty()) name += "_";
		name += "Variable";
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

	std::string
	NodeInfoVariableType::getIdentifierAsString(OpcUaNodeId& nodeId)
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
