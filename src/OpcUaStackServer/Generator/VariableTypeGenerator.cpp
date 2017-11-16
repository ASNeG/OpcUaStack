/*
   Copyright 2017 Kai Huebl (kai@huebl-sgh.de)

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

#include "BuildConfig.h"
#include "OpcUaStackCore/Base/Log.h"
#include "OpcUaStackServer/Generator/VariableTypeGenerator.h"
#include "OpcUaStackServer/InformationModel/InformationModelAccess.h"

namespace OpcUaStackServer
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// VariableTypeGenerator
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	VariableTypeGenerator::VariableTypeGenerator(void)
	: sourceContent_("")
	, headerContent_("")
	, informationModel_(nullptr)
	, variableTypeNodeId_()
	, parentVariableTypeNodeId_()
	, variableTypeNode_()
	, parentVariableTypeNode_()
	, variableTypeNumber_(0)
	, variableTypeName_("")
	, parentVariableTypeName_("")
	, projectNamespace_("")
	, parentProjectNamespace_("")
	, projectDirectory_("")
	, parentProjectDirectory_("")
	, namespaceUri_("")
	, nodeElementVec_()
	{
	}

	VariableTypeGenerator::~VariableTypeGenerator(void)
	{
	}

	bool
	VariableTypeGenerator::generate(void)
	{
		OpcUaQualifiedName browseName;

		// check information model
		if (informationModel_ == nullptr) {
			Log(Error, "information model is empty");
			return false;
		}

		// find variable node
		variableTypeNode_ = informationModel_->find(variableTypeNodeId_);
		if (!variableTypeNode_) {
			Log(Error, "event type do not not exist in information model")
				.parameter("VariableType", variableTypeNodeId_);
			return false;
		}

		// get variable type number
		if (variableTypeNodeId_.nodeIdType() != OpcUaBuildInType_OpcUaUInt32) {
			Log(Error, "variable type node id mismatch - id must be a uint32 value")
				.parameter("VariableType", variableTypeNodeId_);
			return false;
		}
		variableTypeNumber_ = variableTypeNodeId_.nodeId<uint32_t>();

		// find parent variable type node
		InformationModelAccess ima;
		ima.informationModel(informationModel_);
		if (!ima.getSubType(variableTypeNode_, parentVariableTypeNodeId_)) {
			Log(Error, "parent variable type do not not exist in information model")
				.parameter("VariableType", variableTypeNodeId_);
			return false;
		}
		parentVariableTypeNode_ = informationModel_->find(parentVariableTypeNodeId_);
		if (!parentVariableTypeNode_) {
			Log(Error, "parent variable type do not not exist in information model")
				.parameter("VariableType", variableTypeNodeId_);
			return false;
		}

		// get variable type name
		if (!variableTypeNode_->getBrowseName(browseName)) {
			Log(Error, "variable name not found in node")
				.parameter("VariableType", variableTypeNodeId_);
			return false;
		}
		variableTypeName_ = browseName.name().toStdString();

		// get opc ua namesapce name
		if (variableTypeNodeId_.namespaceIndex() != 0) {
			// FIXME: todo
		}

		// get parent variable type name
		if (!parentVariableTypeNode_->getBrowseName(browseName)) {
			Log(Error, "parent variable name not found in node")
				.parameter("VariableType", variableTypeNodeId_)
				.parameter("ParentVariableType", parentVariableTypeNodeId_);
			return false;
		}
		parentVariableTypeName_ = browseName.name().toStdString();

		// set project directory
		if (projectDirectory_ == "") {
			if (variableTypeNodeId_.namespaceIndex() == 0) {
				projectDirectory_ = "StandardVariableType";
			}
			else {
				projectDirectory_ = "CustomerVariableType";
			}
		}

		// set parent project directory
		if (parentProjectDirectory_ == "") {
			if (parentVariableTypeNodeId_.namespaceIndex() == 0) {
				parentProjectDirectory_ = "StandardVariableType";
			}
			else {
				parentProjectDirectory_ = "CustomerVariableType";
			}
		}

		// set project namespace
		if (projectNamespace_ == "") {
			projectNamespace_ = "OpcUaStackCore";
		}

		// set parent project namespace
		if (parentProjectNamespace_ == "") {
			parentProjectNamespace_ = "OpcUaStackCore";
		}

		// create variable element list
		if (!createNodeElementVec("", variableTypeNodeId_)) {
			return false;
		}

		// generate source file and header file
		return generateSource() && generateHeader();
	}

	void
	VariableTypeGenerator::informationModel(InformationModel::SPtr& informationModel)
	{
		informationModel_ = informationModel;
	}

	void
	VariableTypeGenerator::variableType(OpcUaNodeId& variableTypeNodeId)
	{
		variableTypeNodeId_ = variableTypeNodeId;
	}

	std::string&
	VariableTypeGenerator::sourceContent(void)
	{
		return sourceContent_;
	}

	std::string&
	VariableTypeGenerator::headerContent(void)
	{
		return headerContent_;
	}

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// private functions
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	std::string
	VariableTypeGenerator::getTypeNameFromNodeId(OpcUaNodeId& typeNodeId)
	{
		// build in type possible
		if (typeNodeId.namespaceIndex() == 0 && typeNodeId.nodeIdType() == OpcUaBuildInType_OpcUaUInt32) {
			uint32_t type;
			uint16_t namespaceIndex;
			typeNodeId.get(type, namespaceIndex);
			std::string buildInType = OpcUaBuildInTypeMap::buildInType2String((OpcUaBuildInType)type);
			if (buildInType != "Unknown") return buildInType;
		}

		// get property node class
		BaseNodeClass::SPtr nodeClass = informationModel_->find(typeNodeId);
		if (!nodeClass) {
			return "Unknown";
		}

		// get property class name
		OpcUaQualifiedName browseName;
		if (!nodeClass->getBrowseName(browseName)) {
			return "Unknown";
		}

		return browseName.name().toStdString();
	}

	bool
	VariableTypeGenerator::createNodeElementVec(
		const std::string& prefix,
		OpcUaNodeId& nodeId
	)
	{
		bool success;

		BaseNodeClass::SPtr nodeClass = informationModel_->find(nodeId);
		if (!nodeClass) {
			Log(Error, "node not exist in information model")
				.parameter("PropertyNodeId", nodeId);
			return false;
		}

		InformationModelAccess ima;
		std::vector<OpcUaNodeId> referenceTypeVec;
		referenceTypeVec.push_back(OpcUaNodeId(46));
		referenceTypeVec.push_back(OpcUaNodeId(47));
		std::vector<OpcUaNodeId> childNodeIdVec;
		std::vector<OpcUaNodeId>::iterator it;
		ima.informationModel(informationModel_);
		success = ima.getChildHierarchically(
			nodeClass,
			referenceTypeVec,
			childNodeIdVec
		);
		if (!success) {
			Log(Error, "variable properties error")
				.parameter("VariableType", variableTypeNodeId_);
			return false;
		}

		for (it = childNodeIdVec.begin(); it != childNodeIdVec.end(); it++) {
			// get child node class
			BaseNodeClass::SPtr childNodeClass = informationModel_->find(*it);
			if (!childNodeClass) {
				Log(Error, "child node not exist in information model")
					.parameter("ParentNodeId", nodeId)
					.parameter("ChildNodeId", *it);
				return false;
			}

			// use only variable class
			NodeClassType nodeClassType;
			childNodeClass->getNodeClass(nodeClassType);
			if (nodeClassType != NodeClassType_Variable) {
				continue;
			}

			// get browse name
			OpcUaQualifiedName browseName;
			if (!childNodeClass->getBrowseName(browseName)) {
				Log(Error, "browse name not found in node")
					.parameter("ParentNodeId", nodeId)
					.parameter("ChildNodeId", *it);
				return false;
			}

			// create full name
			std::string fullName = prefix;
			if (prefix.size() > 0) {
				fullName.append("_");
			}
			fullName.append(browseName.toString());

			// create function name
			std::string functionName = fullName;
			functionName[0] = boost::to_lower_copy(functionName.substr(0,1))[0];

			// create global variable name
			std::string globalVariableName = functionName;
			globalVariableName.append("_");

			// create local variable name
			std::string localVariableName = functionName;

			// create data type name
			// get property type
			OpcUaNodeId dataTypeNodeId;
			if (!childNodeClass->getDataType(dataTypeNodeId)) {
				Log(Error, "child data type not found in node")
					.parameter("ParentNodeId", nodeId)
					.parameter("ChildNodeId", *it);
				return false;
			}
			std::string dataTypeName = getTypeNameFromNodeId(dataTypeNodeId);
			if (dataTypeName == "Unknown") {
				Log(Error, "child data type is not a build in type")
					.parameter("ParentNodeId", nodeId)
					.parameter("ChildNodeId", *it)
					.parameter("DataTypeNodeId", dataTypeNodeId);
				return false;
			}

			// create new variable element
			NodeElement::SPtr nodeElement = constructSPtr<NodeElement>();
			nodeElement->prefix(prefix);
			nodeElement->nodeId(*it);
			nodeElement->browseName(browseName);
			nodeElement->fullName(fullName);
			nodeElement->globalVariableName(globalVariableName);
			nodeElement->localVariableName(localVariableName);
			nodeElement->functionName(functionName);
			nodeElement->dataTypeName(dataTypeName);
			nodeElement->log();
			nodeElementVec_.push_back(nodeElement);

			//if (!createNodeElementVec(fullName, *it)) {
			//	return false;
			//}
		}

		return true;
	}

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// header functions
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	bool
	VariableTypeGenerator::generateHeader(void)
	{
		return
			generateHeaderComments();
	}

	bool
	VariableTypeGenerator::generateHeaderComments(void)
	{
		std::stringstream ss;

		ss << "/*" << std::endl;
		ss << "    VariableTypeClass: " << variableTypeName_ << std::endl;
		ss << std::endl;
		ss << "    Generated Source Code - please do not change this source code" << std::endl;
		ss << std::endl;
		ss << "    VariableTypeCodeGenerator Version:"  << std::endl;
		ss << "        OpcUaStackCore - " << VERSION_MAJOR << "." << VERSION_MINOR << "." << VERSION_PATCH << std::endl;
		ss << std::endl;
		ss << "    Autor: Kai Huebl (kai@huebl-sgh.de)" << std::endl;
		ss << "*/" << std::endl;

		headerContent_ += ss.str();
		return true;
	}

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// source functions
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	bool
	VariableTypeGenerator::generateSource(void)
	{
		return
			generateSourceComments();
	}

	bool
	VariableTypeGenerator::generateSourceComments(void)
	{
		std::stringstream ss;

		ss << "/*" << std::endl;
		ss << "    VariableTypeClass: " << variableTypeName_ << std::endl;
		ss << std::endl;
		ss << "    Generated Source Code - please do not change this source code" << std::endl;
		ss << std::endl;
		ss << "    VariableTypeCodeGenerator Version:" << std::endl;
		ss << "        OpcUaStackCore - " << VERSION_MAJOR << "." << VERSION_MINOR << "." << VERSION_PATCH  << std::endl;
		ss << std::endl;
		ss << "    Autor: Kai Huebl (kai@huebl-sgh.de)" << std::endl;
		ss << "*/" << std::endl;

		sourceContent_ += ss.str();
		return true;
	}

}
