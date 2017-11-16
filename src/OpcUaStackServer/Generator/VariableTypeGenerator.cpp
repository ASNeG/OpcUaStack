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

#include <OpcUaStackServer/Generator/VariableTypeGenerator.h>
#include "BuildConfig.h"
#include "OpcUaStackCore/Base/Log.h"
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
		if (!createVariableElementVec("", variableTypeNodeId_)) {
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
	bool
	VariableTypeGenerator::createVariableElementVec(
		const std::string& prefix,
		OpcUaNodeId& nodeId
	)
	{
		// FIXME: todo
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
		// FIXME: todo
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
		// FIXME: todo
		return true;
	}

}
