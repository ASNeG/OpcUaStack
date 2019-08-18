/*
   Copyright 2018 Kai Huebl (kai@huebl-sgh.de)

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
#include "OpcUaStackServer/Generator/NodeInfo.h"
#include "OpcUaStackServer/InformationModel/InformationModelAccess.h"
#include "OpcUaStackServer/NodeSet/NodeSetNamespace.h"

using namespace OpcUaStackCore;

namespace OpcUaStackServer
{

	NodeInfo::NodeInfo(void)
	: numberNamespaceMap_()
	, informationModel_()

	, dataTypeNamespaceName_("")
	, dataTypeNodeId_()
	, parentDataTypeNodeId_()
	, baseNode_()
	, parentBaseNode_()
	, namespaceName_("")
	, parentNamespaceName_("")
	, className_("")
	, parentClassName_("")
	, directory_("")
	, parentDirectory_("")
	, isStructureType_(false)
	, parentIsStructureType_(false)
	, isAbstract_(false)
	, parentIsAbstract_(false)
	, defaultBinaryNodeId_()
	, defaultXMLNodeId_()
	, defaultJSONNodeId_()
	, description_("")
	{
	}

	NodeInfo::~NodeInfo(void)
	{
	}

	void
	NodeInfo::log(void)
	{
		Log(Info, "NodeInfo")
		    .parameter("DataTypeNodeId", dataTypeNodeId_)
			.parameter("ParentDataTypeNodeId", parentDataTypeNodeId_)
			.parameter("NamespaceName", namespaceName_)
			.parameter("ParentNamespaceName", parentNamespaceName_)
			.parameter("ClassName", className_)
			.parameter("ParentClassName", parentClassName_)
			.parameter("Directory", directory_)
			.parameter("ParentDirectory", parentDirectory_)
			.parameter("IsStructureType", isStructureType_)
			.parameter("ParentIsStructureType", parentIsStructureType_)
			.parameter("IsAbstract", isAbstract_)
			.parameter("ParentIsAbstract", parentIsAbstract_);
	}

	bool
	NodeInfo::setNamespaceEntry(const std::string& namespaceEntry)
	{
		return numberNamespaceMap_.addNamespace(namespaceEntry);
	}

	std::string
	NodeInfo::dataTypeNamespaceName(void)
	{
		return dataTypeNamespaceName_;
	}

	OpcUaNodeId
	NodeInfo::dataTypeNodeId(void)
	{
		return dataTypeNodeId_;
	}

	OpcUaNodeId
	NodeInfo::parentDataTypeNodeId(void)
	{
		return parentDataTypeNodeId_;
	}

	InformationModel::SPtr&
	NodeInfo::informationModel(void)
	{
		return informationModel_;
	}

	BaseNodeClass::SPtr&
	NodeInfo::baseNode(void)
	{
		return baseNode_;
	}

	BaseNodeClass::SPtr&
	NodeInfo::parentBaseNode(void)
	{
		return parentBaseNode_;
	}

	std::string&
	NodeInfo::namespaceName(void)
	{
		return namespaceName_;
	}

	std::string&
	NodeInfo::parentNamespaceName(void)
	{
		return parentNamespaceName_;
	}

	std::string&
	NodeInfo::className(void)
	{
		return className_;
	}

	std::string&
	NodeInfo::parentClassName(void)
	{
		return parentClassName_;
	}

	std::string&
	NodeInfo::directory(void)
	{
		return directory_;
	}

	std::string&
	NodeInfo::parentDirectory(void)
	{
		return parentDirectory_;
	}

	bool
	NodeInfo::isStructureType(void)
	{
		return isStructureType_;
	}

	bool
	NodeInfo::parentIsStructureType(void)
	{
		return parentIsStructureType_;
	}

	bool
	NodeInfo::isAbstract(void)
	{
		return isAbstract_;
	}

	bool
	NodeInfo::parentIsAbstract(void)
	{
		return parentIsAbstract_;
	}

	NumberNamespaceMap&
	NodeInfo::numberNamespaceMap(void)
	{
		return numberNamespaceMap_;
	}

	OpcUaNodeId&
	NodeInfo::defaultBinaryNodeId(void)
	{
		return defaultBinaryNodeId_;
	}

	OpcUaNodeId&
	NodeInfo::defaultXMLNodeId(void)
	{
		return defaultXMLNodeId_;
	}

	OpcUaNodeId&
	NodeInfo::defaultJSONNodeId(void)
	{
		return defaultJSONNodeId_;
	}

	std::string&
	NodeInfo::description(void)
	{
		return description_;
	}

	bool
	NodeInfo::init(
		const OpcUaNodeId& dataTypeNodeId,
		InformationModel::SPtr& informationModel
	)
	{
		dataTypeNodeId_ = dataTypeNodeId;
		informationModel_ = informationModel;

		InformationModelAccess ima;
		ima.informationModel(informationModel_);

		//
		// find node in opc ua information model
		//
		baseNode_ = informationModel_->find(dataTypeNodeId);
		if (baseNode_.get() == nullptr) {
			Log(Error, "data type node identifier not exist in information model")
				.parameter("DataTypeNode", dataTypeNodeId);
			return false;
		}

		//
		// find parent node in opc ua information model
		//
		if (!ima.getSubType(baseNode_, parentDataTypeNodeId_)) {
			Log(Error, "parent data type node identifier do not not exist in information model")
				.parameter("DataTypeNodeId", dataTypeNodeId_);
			return false;
		}
		parentBaseNode_ = informationModel_->find(parentDataTypeNodeId_);
		if (!parentBaseNode_) {
			Log(Error, "parent data type node instance do not not exist in information model")
				.parameter("DataTypeNodeId", dataTypeNodeId_)
				.parameter("ParentDataTypeNodeId", parentDataTypeNodeId_);
			return false;
		}

		//
		// set namespace name
		//
		namespaceName_ = numberNamespaceMap_.getNamespaceName(dataTypeNodeId_.namespaceIndex());

		//
		// set namespace name of parent
		//
		parentNamespaceName_ = numberNamespaceMap_.getNamespaceName(parentDataTypeNodeId_.namespaceIndex());

		//
		// set class name
		//
		boost::optional<OpcUaLocalizedText&> displayName = baseNode_->getDisplayName();
		if (!displayName) {
			Log(Error, "display name not found")
			    .parameter("DataTypeNode", dataTypeNodeId_);
		}
		className_ = displayName->text().value();
		className_ = boost::to_upper_copy(className_.substr(0,1)) + className_.substr(1);

		//
		// set class name of parent
		//
		boost::optional<OpcUaLocalizedText&> parentDisplayName = parentBaseNode_->getDisplayName();
		if (!parentDisplayName) {
			Log(Error, "display name not found")
			    .parameter("ParentDataTypeNode", parentDataTypeNodeId_);
		}
		parentClassName_ = parentDisplayName->text().value();
		parentClassName_ = boost::to_upper_copy(parentClassName_.substr(0,1)) + parentClassName_.substr(1);

		//
		// set directory
		//
		if (dataTypeNodeId_.namespaceIndex() == 0) {
			directory_ = "StandardDataTypes";
		}
		else {
			directory_ = "CustomerDataTypes";
		}

		//
		// set directory of parent
		//
		if (parentDataTypeNodeId_.namespaceIndex() == 0) {
			parentDirectory_ = "StandardDataTypes";
		}
		else {
			parentDirectory_ = "CustomerDataTypes";
		}

		//
		// set structure type flag
		//
		if (dataTypeNodeId_ == OpcUaNodeId(22)) {
			isStructureType_ = true;
		}

		//
		// set structure type flag of parent
		//
		if (parentDataTypeNodeId_ == OpcUaNodeId(22)) {
			parentIsStructureType_ = true;
		}

		//
		// set is abstract
		//
		baseNode_->getIsAbstract(isAbstract_);

		//
		// set is abstract of parent node
		//
		parentBaseNode_->getIsAbstract(parentIsAbstract_);

		//
		// set data type namespace name
		//
		dataTypeNamespaceName_ = getNamespaceName(dataTypeNodeId_);

		//
		// check if base class is a structure
		//
		bool isStructureType = ima.isDataTypeStructure(baseNode_);

		//
		// set default binary encoding node identifier
		//
		if (isStructureType) {
			if (!ima.getBinaryEncodingNode(baseNode_, defaultBinaryNodeId_)) {
				Log(Error, "default binary encoding node identifier do not not exist in information model")
					.parameter("DataTypeNodeId", dataTypeNodeId_);
				return false;
			}
		}

		//
		// set default XML encoding node identifier
		//
		if (isStructureType) {
			if (!ima.getXMLEncodingNode(baseNode_, defaultXMLNodeId_)) {
				Log(Error, "default xml encoding node identifier do not not exist in information model")
					.parameter("DataTypeNodeId", dataTypeNodeId_);
				return false;
			}
		}

		//
		// set default JSON encoding node identifier
		//
		if (isStructureType) {
			if (!ima.getJSONEncodingNode(baseNode_, defaultJSONNodeId_)) {
				Log(Error, "default json encoding node identifier do not not exist in information model")
					.parameter("DataTypeNodeId", dataTypeNodeId_);
				return false;
			}
		}

		//
		// set description
		//
		OpcUaLocalizedText description;
		baseNode_->getDescription(description);
		description_ = description.text().toStdString();

		return true;
	}

	std::string
	NodeInfo::getIdentifierAsString(OpcUaNodeId& nodeId)
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

	std::string
	NodeInfo::getNamespaceName(OpcUaNodeId& nodeId)
	{
		NodeSetNamespace nodeSetNamespace;

		// check namespaces
		if (nodeId.namespaceIndex() >= nodeSetNamespace.globalNamespaceVec().size()) {
			return "NamespaceUnknown";
		}

		return nodeSetNamespace.globalNamespaceVec()[nodeId.namespaceIndex()];
	}

}
