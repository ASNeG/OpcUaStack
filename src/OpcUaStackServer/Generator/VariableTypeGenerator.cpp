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

			if (!createNodeElementVec(fullName, *it)) {
				return false;
			}
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
			generateHeaderComments() &&
			generateHeaderBegin() &&
			generateHeaderClassBegin("    ") &&
				generateHeaderClassPublic("        ") &&
				generateHeaderClassPrivate("    ") &&
		    generateHeaderClassEnd("    ") &&
			generateHeaderEnd();
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

	bool
	VariableTypeGenerator::generateHeaderBegin(void)
	{
		std::stringstream ss;

		//
		// added defines
		//
		ss << std::endl;
		ss << "#ifndef __" << projectNamespace_ << "_" << variableTypeName_ << "_h__" << std::endl;
		ss << "#define __" << projectNamespace_ << "_" << variableTypeName_ << "_h__" << std::endl;

		//
		// added includes
		//
		ss << std::endl;
		ss << "#include <boost/shared_ptr.hpp>" << std::endl;
		ss << "#include \"OpcUaStackCore/Base/os.h\"" << std::endl;
		ss << "#include \"OpcUaStackCore/BuildInTypes/BuildInTypes.h\"" << std::endl;
		ss << "#include \"" << parentProjectNamespace_ << "/" << parentProjectDirectory_ << "/" << parentVariableTypeName_ << ".h\"" << std::endl;

		//
		// added namespace
		//
		if (projectNamespace_ != parentProjectNamespace_) {
			ss << "using namespace " << parentProjectNamespace_ << ";";
			ss << std::endl;
		}
		ss << std::endl;
		ss << "namespace " << projectNamespace_ << std::endl;
		ss << "{" << std::endl;

		headerContent_ += ss.str();
		return true;
	}

	bool
	VariableTypeGenerator::generateHeaderEnd(void)
	{
		std::stringstream ss;

		//
		// added namespace
		//
		ss << std::endl;
		ss << "}" << std::endl;

		//
		// added defines
		//
		ss << std::endl;
		ss << "#endif" << std::endl;

		headerContent_ += ss.str();
		return true;
	}

	bool
	VariableTypeGenerator::generateHeaderClassBegin(const std::string& prefix)
	{
		std::stringstream ss;

		//
		// added class
		//
		ss << prefix << std::endl;
		ss << prefix << "class DLLEXPORT " << variableTypeName_ << std::endl;
		ss << prefix << ": public " << parentVariableTypeName_ << std::endl;
		ss << prefix << "{" << std::endl;
		ss << prefix << "  public:" << std::endl;
		ss << prefix << "    typedef boost::shared_ptr<" << variableTypeName_  << "> SPtr;" << std::endl;
		ss << prefix << std::endl;
		ss << prefix << "    " << variableTypeName_ << "(void);" << std::endl;
		ss << prefix << "    virtual ~" << variableTypeName_ << "(void);" << std::endl;

		headerContent_ += ss.str();
		return true;
	}

	bool
	VariableTypeGenerator::generateHeaderClassEnd(const std::string& prefix)
	{
		std::stringstream ss;

		//
		// added class
		//
		ss << prefix << std::endl;
		ss << prefix << "};" << std::endl;

		headerContent_ += ss.str();
		return true;
	}

	bool
	VariableTypeGenerator::generateHeaderClassPublic(const std::string& prefix)
	{
		// FIXME: todo
		return true;
	}

	bool
	VariableTypeGenerator::generateHeaderClassPrivate(const std::string& prefix)
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
		return
			generateSourceComments() &&
			generateSourceIncludes() &&
			generateSourceClassBegin() &&
				generateSourceClassConstructor("    ") &&
				generateSourceClassDestructor("    ") &&
				generateSourceClassGetter("    ") &&
				generateSourceClassSetter("    ") &&
				generateSourceClassNamespaceUri("    ") &&
				generateSourceClassGet("    ") &&
			generateSourceClassEnd();
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

	bool
	VariableTypeGenerator::generateSourceIncludes(void)
	{
		std::stringstream ss;

		ss << std::endl;
		ss << "#include \"" << projectNamespace_ << "/" << projectDirectory_ << "/" << variableTypeName_ << ".h\"" << std::endl;

		sourceContent_ += ss.str();
		return true;
	}

	bool
	VariableTypeGenerator::generateSourceClassBegin(void)
	{
		std::stringstream ss;

		//
		// namespace
		//
		ss << std::endl;
		ss << "namespace " <<  projectNamespace_ << std::endl;
		ss << "{" << std::endl;

		sourceContent_ += ss.str();
		return true;
	}

	bool
	VariableTypeGenerator::generateSourceClassEnd(void)
	{
		std::stringstream ss;

		//
		// namespace
		//
		ss << std::endl;
		ss << "}" << std::endl;

		sourceContent_ += ss.str();
		return true;
	}

	bool
	VariableTypeGenerator::generateSourceClassConstructor(const std::string& prefix)
	{
		std::stringstream ss;

		ss << prefix << std::endl;
		ss << prefix << variableTypeName_ << "::" << variableTypeName_ << "(void)" << std::endl;
		ss << prefix << ": " << parentVariableTypeName_ << "()" << std::endl;
		ss << prefix << "{" << std::endl;
		ss << prefix << "}" << std::endl;

		sourceContent_ += ss.str();
		return true;
	}

	bool
	VariableTypeGenerator::generateSourceClassDestructor(const std::string& prefix)
	{
		std::stringstream ss;

		ss << prefix << std::endl;
		ss << prefix << variableTypeName_ << "::~" << variableTypeName_ << "(void)" << std::endl;
		ss << prefix << "{" << std::endl;
		ss << prefix << "}" << std::endl;

		sourceContent_ += ss.str();
		return true;
	}

	bool
	VariableTypeGenerator::generateSourceClassGetter(const std::string& prefix)
	{
		// FIXME: todo
		return true;
	}

	bool
	VariableTypeGenerator::generateSourceClassSetter(const std::string& prefix)
	{
		// FIXME: todo
		return true;
	}

	bool
	VariableTypeGenerator::generateSourceClassNamespaceUri(const std::string& prefix)
	{
		std::stringstream ss;

		ss << prefix << std::endl;
		ss << prefix << "void" << std::endl;
		ss << prefix << variableTypeName_ << "::" << "mapNamespaceUri(void)" << std::endl;
		ss << prefix << "{" << std::endl;
		ss << prefix << "    uint32_t namespaceIndex;" << std::endl;
		ss << prefix << "    " << parentVariableTypeName_ << "::mapNamespaceUri();" << std::endl;
		ss << prefix << std::endl;
		ss << prefix << "    OpcUaVariant::SPtr variableTypeVariable = constructSPtr<OpcUaVariant>();" << std::endl;
		ss << prefix << "    variableTypeVariable->setValue(eventVariables_.variableType());" << std::endl;
		ss << prefix << std::endl;
		ss << prefix << "    setNamespaceIndex(eventVariables_.namespaceUri(), namespaceIndex, eventVariables_.browseName(), variableTypeVariable);" << std::endl;
		ss << prefix << std::endl;
		ss << prefix << "    variableType(variableTypeVariable);" << std::endl;
		ss << prefix << "    eventVariables_.variableType(variableTypeVariable);" << std::endl;
		ss << prefix << "    eventVariables_.namespaceIndex(namespaceIndex);" << std::endl;
		ss << prefix << "}" << std::endl;

		sourceContent_ += ss.str();
		return true;
	}

	bool
	VariableTypeGenerator::generateSourceClassGet(const std::string& prefix)
	{
		std::stringstream ss;

		ss << std::endl;
		ss << prefix << "OpcUaVariant::SPtr" << std::endl;
		ss << prefix << variableTypeName_ << "::" << "get(" << std::endl;
		ss << prefix << "	OpcUaNodeId& variableType," << std::endl;
		ss << prefix << "	std::list<OpcUaQualifiedName::SPtr>& browseNameList," << std::endl;
		ss << prefix << "	EventResult::Code& resultCode" << std::endl;
		ss << prefix << ")" << std::endl;
		ss << prefix << "{" << std::endl;
		ss << prefix << "    resultCode = EventResult::Success;" << std::endl;
		ss << std::endl;
		ss << prefix << "    // check whether variableType and typeNodeId are identical" << std::endl;
		ss << prefix << "    if (variableType == eventVariables_.variableType()) {" << std::endl;
		ss << prefix << "	    return eventVariables_.get(browseNameList, resultCode);" << std::endl;
		ss << prefix << "    }" << std::endl;
		ss << std::endl;
		ss << prefix << "    // the start item was not found. We delegate the search to the base class" << std::endl;
		ss << prefix << "    OpcUaVariant::SPtr variant;" << std::endl;
		ss << prefix << "    variant = " << parentVariableTypeName_ << "::get(variableType, browseNameList, resultCode);" << std::endl;
		ss << prefix << "    if (resultCode != EventResult::Success || browseNameList.empty()) {" << std::endl;
		ss << prefix << "	    return variant;" << std::endl;
		ss << prefix << "    }" << std::endl;
		ss << std::endl;
		ss << prefix << "    return eventVariables_.get(browseNameList, resultCode);" << std::endl;
		ss << prefix << "}" << std::endl;

		sourceContent_ += ss.str();
		return true;
	}

}
