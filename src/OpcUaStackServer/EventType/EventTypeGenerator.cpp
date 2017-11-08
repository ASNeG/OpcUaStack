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
#include "OpcUaStackServer/EventType/EventTypeGenerator.h"
#include "OpcUaStackServer/InformationModel/InformationModelAccess.h"

namespace OpcUaStackServer
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// VariableElement
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	VariableElement::VariableElement(void)
	: prefix_("")
	, nodeId_()
	, browseName_()
	, fullName_("")
	, variableName_("")
	, functionName_("")
	{
	}

	VariableElement::~VariableElement(void)
	{
	}

	void
	VariableElement::log(void)
	{
		Log(Debug, "Create new variable element")
		    .parameter("NodeId", nodeId_)
			.parameter("Prefix", prefix_)
			.parameter("BrowseName", browseName_)
			.parameter("FullName", fullName_)
			.parameter("VariableName", variableName_)
			.parameter("FunctionName", functionName_);
	}

	void
	VariableElement::prefix(const std::string& prefix)
	{
		prefix_ = prefix;
	}

	std::string
	VariableElement::prefix(void)
	{
		return prefix_;
	}

	void
	VariableElement::nodeId(const OpcUaNodeId& nodeId)
	{
		nodeId_ = nodeId;
	}

	OpcUaNodeId&
	VariableElement::nodeId(void)
	{
		return nodeId_;
	}

	void
	VariableElement::browseName(const OpcUaQualifiedName& browseName)
	{
		browseName_ = browseName;
	}

	OpcUaQualifiedName&
	VariableElement::browseName(void)
	{
		return browseName_;
	}

	void
	VariableElement::fullName(const std::string& fullName)
	{
		fullName_ = fullName;
	}

	std::string&
	VariableElement::fullName(void)
	{
		return fullName_;
	}

	void
	VariableElement::variableName(const std::string& variableName)
	{
		variableName_ = variableName;
	}

	std::string&
	VariableElement::variableName(void)
	{
		return variableName_;
	}

   	void
	VariableElement::functionName(const std::string& functionName)
   	{
   		functionName_ = functionName;
   	}

   	std::string&
	VariableElement::functionName(void)
   	{
   		return functionName_;
   	}

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// EventTypeGenerator
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	EventTypeGenerator::EventTypeGenerator(void)
	: sourceContent_("")
	, headerContent_("")
	, informationModel_(nullptr)
	, eventTypeNodeId_()
	, parentEventTypeNodeId_()
	, eventTypeName_("")
	, parentEventTypeName_("")
	, eventTypeNode_()
	, parentEventTypeNode_()
	, projectNamespace_("")
	, parentProjectNamespace_("")
	, projectDirectory_("")
	, parentProjectDirectory_("")
	, eventTypeNumber_(0)
	, namespaceUri_("")
	{
	}

	EventTypeGenerator::~EventTypeGenerator(void)
	{
	}

	bool
	EventTypeGenerator::generate(void)
	{
		OpcUaQualifiedName browseName;

		// check information model
		if (informationModel_ == nullptr) {
			Log(Error, "information model is empty");
			return false;
		}

		// find event node
		eventTypeNode_ = informationModel_->find(eventTypeNodeId_);
		if (!eventTypeNode_) {
			Log(Error, "event type do not not exist in information model")
				.parameter("EventType", eventTypeNodeId_);
			return false;
		}

		// get event type number
		if (eventTypeNodeId_.nodeIdType() != OpcUaBuildInType_OpcUaUInt32) {
			Log(Error, "event type node id mismatch - id must be a uint32 value")
				.parameter("EventType", eventTypeNodeId_);
			return false;
		}
		eventTypeNumber_ = eventTypeNodeId_.nodeId<uint32_t>();

		// find parent event type node
		InformationModelAccess ima;
		ima.informationModel(informationModel_);
		if (!ima.getSubType(eventTypeNode_, parentEventTypeNodeId_)) {
			Log(Error, "parent event type do not not exist in information model")
				.parameter("EventType", eventTypeNodeId_);
			return false;
		}
		parentEventTypeNode_ = informationModel_->find(parentEventTypeNodeId_);
		if (!parentEventTypeNode_) {
			Log(Error, "parent event type do not not exist in information model")
				.parameter("EventType", eventTypeNodeId_);
			return false;
		}

		// get event type name
		if (!eventTypeNode_->getBrowseName(browseName)) {
			Log(Error, "event name not found in node")
				.parameter("EventType", eventTypeNodeId_);
			return false;
		}
		eventTypeName_ = browseName.name().toStdString();

		// get opc ua namesapce name
		if (eventTypeNodeId_.namespaceIndex() != 0) {
			// FIXME: todo
		}

		// get parent event type name
		if (!parentEventTypeNode_->getBrowseName(browseName)) {
			Log(Error, "parent event name not found in node")
				.parameter("EventType", eventTypeNodeId_)
				.parameter("ParentEventType", parentEventTypeNodeId_);
			return false;
		}
		parentEventTypeName_ = browseName.name().toStdString();

		// set project directory
		if (projectDirectory_ == "") {
			if (eventTypeNodeId_.namespaceIndex() == 0) {
				projectDirectory_ = "StandardEventType";
			}
			else {
				projectDirectory_ = "CustomerEventType";
			}
		}

		// set parent project directory
		if (parentProjectDirectory_ == "") {
			if (parentEventTypeNodeId_.namespaceIndex() == 0) {
				parentProjectDirectory_ = "StandardEventType";
			}
			else {
				parentProjectDirectory_ = "CustomerEventType";
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
		if (!createVariableElementVec("", eventTypeNodeId_)) {
			return false;
		}

		// generate source file and header file
		return generateSource() && generateHeader();
	}

	void
	EventTypeGenerator::informationModel(InformationModel::SPtr& informationModel)
	{
		informationModel_ = informationModel;
	}

	void
	EventTypeGenerator::eventType(OpcUaNodeId& eventType)
	{
		eventTypeNodeId_ = eventType;
	}

	void
	EventTypeGenerator::projectNamespace(const std::string& projectNamespace)
	{
		projectNamespace_ = projectNamespace;
	}

	void
	EventTypeGenerator::parentProjectNamespace(const std::string& parentProjectNamespace)
	{
		parentProjectNamespace_ = parentProjectNamespace;
	}

	std::string&
	EventTypeGenerator::sourceContent(void)
	{
		return sourceContent_;
	}

	std::string&
	EventTypeGenerator::headerContent(void)
	{
		return headerContent_;
	}

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// header functions
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	bool
	EventTypeGenerator::createVariableElementVec(
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
			Log(Error, "event properties error")
				.parameter("EventType", eventTypeNodeId_);
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

			// create variable name
			std::string variableName = functionName;
			variableName.append("_");

			// create new variable element
			VariableElement::SPtr variableElement = constructSPtr<VariableElement>();
			variableElement->prefix(prefix);
			variableElement->nodeId(*it);
			variableElement->browseName(browseName);
			variableElement->fullName(fullName);
			variableElement->variableName(variableName);
			variableElement->functionName(functionName);
			variableElement->log();
			variableElementVec_.push_back(variableElement);

			if (!createVariableElementVec(fullName, *it)) {
				return false;
			}
		}

		return true;
	}

	bool
	EventTypeGenerator::generateHeader(void)
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
	EventTypeGenerator::generateHeaderComments(void)
	{
		std::stringstream ss;

		ss << "/*" << std::endl;
		ss << "    EventTypeClass: " << eventTypeName_ << std::endl;
		ss << std::endl;
		ss << "    Generated Source Code - please do not change this source code" << std::endl;
		ss << std::endl;
		ss << "    EventTypeCodeGenerator Version:"  << std::endl;
		ss << "        OpcUaStackCore - " << VERSION_MAJOR << "." << VERSION_MINOR << "." << VERSION_PATCH << std::endl;
		ss << std::endl;
		ss << "    Autor: Kai Huebl (kai@huebl-sgh.de)" << std::endl;
		ss << "*/" << std::endl;

		headerContent_ += ss.str();
		return true;
	}

	bool
	EventTypeGenerator::generateHeaderBegin(void)
	{
		std::stringstream ss;

		//
		// added defines
		//
		ss << std::endl;
		ss << "#ifndef __" << projectNamespace_ << "_" << eventTypeName_ << "_h__" << std::endl;
		ss << "#define __" << projectNamespace_ << "_" << eventTypeName_ << "_h__" << std::endl;

		//
		// added includes
		//
		ss << std::endl;
		ss << "#include <boost/shared_ptr.hpp>" << std::endl;
		ss << "#include \"OpcUaStackCore/Base/os.h\"" << std::endl;
		ss << "#include \"OpcUaStackCore/BuildInTypes/BuildInTypes.h\"" << std::endl;
		ss << "#include \"" << parentProjectNamespace_ << "/" << parentProjectDirectory_ << "/" << parentEventTypeName_ << ".h\"" << std::endl;

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
	EventTypeGenerator::generateHeaderEnd(void)
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
	EventTypeGenerator::generateHeaderClassBegin(const std::string& prefix)
	{
		std::stringstream ss;

		//
		// added class
		//
		ss << prefix << std::endl;
		ss << prefix << "class DLLEXPORT " << eventTypeName_ << std::endl;
		ss << prefix << ": public " << parentEventTypeName_ << std::endl;
		ss << prefix << "{" << std::endl;
		ss << prefix << "  public:" << std::endl;
		ss << prefix << "    typedef boost::shared_ptr<" << eventTypeName_  << "> SPtr;" << std::endl;
		ss << prefix << std::endl;
		ss << prefix << "    " << eventTypeName_ << "(void);" << std::endl;
		ss << prefix << "    virtual ~" << eventTypeName_ << "(void);" << std::endl;

		headerContent_ += ss.str();
		return true;
	}

	bool
	EventTypeGenerator::generateHeaderClassEnd(const std::string& prefix)
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
	EventTypeGenerator::generateHeaderClassPublic(const std::string& prefix)
	{
		std::stringstream ss;

		VariableElement::Vec::iterator it;
		for (it = variableElementVec_.begin(); it != variableElementVec_.end(); it++) {
			VariableElement::SPtr variableElement = *it;
			std::string functionName = variableElement->functionName();

			ss << prefix << "bool " << functionName << "(OpcUaVariant::SPtr& variable);" << std::endl;
			ss << prefix << "OpcUaVariant::SPtr " << functionName << "(void);" << std::endl;
			ss << prefix << std::endl;
		}

		ss << prefix << std::endl;
		ss << prefix << "//- EventBase interface" << std::endl;
		ss << prefix << "virtual void mapNamespaceUri(void);" << std::endl;
		ss << prefix << std::endl;
		ss << prefix << "virtual OpcUaVariant::SPtr get(" << std::endl;
		ss << prefix << "    OpcUaNodeId& eventType," << std::endl;
		ss << prefix << "    std::list<OpcUaQualifiedName::SPtr>& browseNameList," << std::endl;
		ss << prefix << "    EventResult::Code& resultCode" << std::endl;
		ss << prefix << ");" << std::endl;
		ss << prefix << "//- EventBase interface" << std::endl;
		ss << prefix << std::endl;

		headerContent_ += ss.str();
		return true;
	}

	bool
	EventTypeGenerator::generateHeaderClassPrivate(const std::string& prefix)
	{
		std::stringstream ss;

		//
		// added private
		//
		ss << prefix << std::endl;
		ss << prefix << "  private:" << std::endl;
		ss << prefix << "    EventVariables eventVariables_;" << std::endl;

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
	EventTypeGenerator::generateSource(void)
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
	EventTypeGenerator::generateSourceComments(void)
	{
		std::stringstream ss;

		ss << "/*" << std::endl;
		ss << "    EventTypeClass: " << eventTypeName_ << std::endl;
		ss << std::endl;
		ss << "    Generated Source Code - please do not change this source code" << std::endl;
		ss << std::endl;
		ss << "    EventTypeCodeGenerator Version:" << std::endl;
		ss << "        OpcUaStackCore - " << VERSION_MAJOR << "." << VERSION_MINOR << "." << VERSION_PATCH  << std::endl;
		ss << std::endl;
		ss << "    Autor: Kai Huebl (kai@huebl-sgh.de)" << std::endl;
		ss << "*/" << std::endl;

		sourceContent_ += ss.str();
		return true;
	}

	bool
	EventTypeGenerator::generateSourceIncludes(void)
	{
		std::stringstream ss;

		ss << std::endl;
		ss << "#include \"" << projectNamespace_ << "/" << projectDirectory_ << "/" << eventTypeName_ << ".h\"" << std::endl;

		sourceContent_ += ss.str();
		return true;
	}

	bool
	EventTypeGenerator::generateSourceClassBegin(void)
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
	EventTypeGenerator::generateSourceClassEnd(void)
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
	EventTypeGenerator::generateSourceClassConstructor(const std::string& prefix)
	{
		std::stringstream ss;

		ss << prefix << std::endl;
		ss << prefix << eventTypeName_ << "::" << eventTypeName_ << "(void)" << std::endl;
		ss << prefix << ": " << parentEventTypeName_ << "()" << std::endl;
		ss << prefix << ", eventVariables_()" << std::endl;
		ss << prefix << "{" << std::endl;

		OpcUaQualifiedName browseName;
		bool success;

		InformationModelAccess ima;
		std::vector<OpcUaNodeId> referenceTypeVec;
		referenceTypeVec.push_back(OpcUaNodeId(46));
		referenceTypeVec.push_back(OpcUaNodeId(47));
		std::vector<OpcUaNodeId> childNodeIdVec;
		std::vector<OpcUaNodeId>::iterator it;
		ima.informationModel(informationModel_);
		success = ima.getChildHierarchically(
			eventTypeNode_,
			referenceTypeVec,
			childNodeIdVec
		);
		if (!success) {
			Log(Error, "event properties error")
				.parameter("EventType", eventTypeNodeId_);
			return false;
		}

		for (it = childNodeIdVec.begin(); it != childNodeIdVec.end(); it++) {

			// get property node class
			BaseNodeClass::SPtr propertyNodeClass = informationModel_->find(*it);
			if (!propertyNodeClass) {
				Log(Error, "property node class not exist in information model")
					.parameter("EventType", eventTypeNodeId_)
					.parameter("PropertyNodeId", *it);
				return false;
			}

			// use only variable class
			NodeClassType nodeClassType;
			propertyNodeClass->getNodeClass(nodeClassType);
			if (nodeClassType != NodeClassType_Variable) {
				continue;
			}

			// get property type
			OpcUaNodeId propertyTypeNodeId;
			if (!propertyNodeClass->getDataType(propertyTypeNodeId)) {
				Log(Error, "property data type not found in node")
					.parameter("EventType", eventTypeNodeId_)
					.parameter("PropertyNodeId", *it);
				return false;
			}
			std::string propertyTypeName = getTypeNameFromNodeId(propertyTypeNodeId);
			if (propertyTypeName == "Unknown") {
				Log(Error, "property data type is not a build in type")
					.parameter("EventType", eventTypeNodeId_)
					.parameter("PropertyNodeId", *it)
					.parameter("PropertyTypeNodeId", propertyTypeNodeId);
				return false;
			}

			// get property class name
			if (!propertyNodeClass->getBrowseName(browseName)) {
				Log(Error, "property name not found in node")
					.parameter("EventType", eventTypeNodeId_)
					.parameter("PropertyNodeId", *it);
				return false;
			}
			std::string propertyName = browseName.name().toStdString();

			ss << prefix << "    eventVariables_.registerEventVariable(\"" << propertyName << "\", OpcUaBuildInType_OpcUa" << propertyTypeName << ");" << std::endl;
		}


		ss << prefix << std::endl;
		ss << prefix << "    eventVariables_.eventType(" << "OpcUaNodeId((OpcUaUInt32)" << eventTypeNumber_ << "));" << std::endl;
		ss << prefix << "    eventVariables_.namespaceIndex(0);" << std::endl;
		ss << prefix << "    eventVariables_.browseName(OpcUaQualifiedName(\"" << eventTypeName_ <<  "\"));" << std::endl;
		ss << prefix << "    eventVariables_.namespaceUri(\"" << namespaceUri_ <<  "\");" << std::endl;
		ss << prefix << "}" << std::endl;

		sourceContent_ += ss.str();
		return true;
	}

	bool
	EventTypeGenerator::generateSourceClassDestructor(const std::string& prefix)
	{
		std::stringstream ss;

		ss << prefix << std::endl;
		ss << prefix << eventTypeName_ << "::~" << eventTypeName_ << "(void)" << std::endl;
		ss << prefix << "{" << std::endl;
		ss << prefix << "}" << std::endl;

		sourceContent_ += ss.str();
		return true;
	}

	bool
	EventTypeGenerator::generateSourceClassGetter(const std::string& prefix)
	{
		std::stringstream ss;

		VariableElement::Vec::iterator it;
		for (it = variableElementVec_.begin(); it != variableElementVec_.end(); it++) {
			VariableElement::SPtr variableElement = *it;
			std::string functionName = variableElement->functionName();
			std::string fullName = variableElement->fullName();

			ss << prefix << std::endl;
			ss << prefix << "OpcUaVariant::SPtr " << std::endl;
			ss << prefix << eventTypeName_ << "::" << functionName << "(void)" << std::endl;
			ss << prefix << "{" << std::endl;
			ss << prefix << "	OpcUaVariant::SPtr value;" << std::endl;
			ss << prefix << "	eventVariables_.getValue(\"" << fullName << "\", value);" << std::endl;
			ss << prefix << "	return value;" << std::endl;
			ss << prefix << "}" << std::endl;
		}

		sourceContent_ += ss.str();
		return true;
	}

	bool
	EventTypeGenerator::generateSourceClassSetter(const std::string& prefix)
	{
		std::stringstream ss;

		VariableElement::Vec::iterator it;
		for (it = variableElementVec_.begin(); it != variableElementVec_.end(); it++) {
			VariableElement::SPtr variableElement = *it;
			std::string fullName = variableElement->fullName();
			std::string variableName = variableElement->functionName();
			std::string functionName = variableElement->functionName();

			ss << prefix << std::endl;
			ss << prefix << "bool " << std::endl;
			ss << prefix << eventTypeName_ << "::" << functionName << "(OpcUaVariant::SPtr& " << variableName << ")" << std::endl;
			ss << prefix << "{" << std::endl;
			ss << prefix << "	return eventVariables_.setValue(\"" << fullName << "\", " << variableName << ");" << std::endl;
			ss << prefix << "}" << std::endl;
		}

		sourceContent_ += ss.str();
		return true;
	}

	bool
	EventTypeGenerator::generateSourceClassNamespaceUri(const std::string& prefix)
	{
		std::stringstream ss;

		ss << prefix << std::endl;
		ss << prefix << "void" << std::endl;
		ss << prefix << eventTypeName_ << "::" << "mapNamespaceUri(void)" << std::endl;
		ss << prefix << "{" << std::endl;
		ss << prefix << "    uint32_t namespaceIndex;" << std::endl;
		ss << prefix << "    " << parentEventTypeName_ << "::mapNamespaceUri();" << std::endl;
		ss << prefix << std::endl;
		ss << prefix << "    OpcUaVariant::SPtr eventTypeVariable = constructSPtr<OpcUaVariant>();" << std::endl;
		ss << prefix << "    eventTypeVariable->setValue(eventVariables_.eventType());" << std::endl;
		ss << prefix << std::endl;
		ss << prefix << "    setNamespaceIndex(eventVariables_.namespaceUri(), namespaceIndex, eventVariables_.browseName(), eventTypeVariable);" << std::endl;
		ss << prefix << std::endl;
		ss << prefix << "    eventType(eventTypeVariable);" << std::endl;
		ss << prefix << "    eventVariables_.eventType(eventTypeVariable);" << std::endl;
		ss << prefix << "    eventVariables_.namespaceIndex(namespaceIndex);" << std::endl;
		ss << prefix << "}" << std::endl;

		sourceContent_ += ss.str();
		return true;
	}

	bool
	EventTypeGenerator::generateSourceClassGet(const std::string& prefix)
	{
		std::stringstream ss;

		ss << std::endl;
		ss << prefix << "OpcUaVariant::SPtr" << std::endl;
		ss << prefix << eventTypeName_ << "::" << "get(" << std::endl;
		ss << prefix << "	OpcUaNodeId& eventType," << std::endl;
		ss << prefix << "	std::list<OpcUaQualifiedName::SPtr>& browseNameList," << std::endl;
		ss << prefix << "	EventResult::Code& resultCode" << std::endl;
		ss << prefix << ")" << std::endl;
		ss << prefix << "{" << std::endl;
		ss << prefix << "    resultCode = EventResult::Success;" << std::endl;
		ss << std::endl;
		ss << prefix << "    // check whether eventType and typeNodeId are identical" << std::endl;
		ss << prefix << "    if (eventType == eventVariables_.eventType()) {" << std::endl;
		ss << prefix << "	    return eventVariables_.get(browseNameList, resultCode);" << std::endl;
		ss << prefix << "    }" << std::endl;
		ss << std::endl;
		ss << prefix << "    // the start item was not found. We delegate the search to the base class" << std::endl;
		ss << prefix << "    OpcUaVariant::SPtr variant;" << std::endl;
		ss << prefix << "    variant = " << parentEventTypeName_ << "::get(eventType, browseNameList, resultCode);" << std::endl;
		ss << prefix << "    if (resultCode != EventResult::Success || browseNameList.empty()) {" << std::endl;
		ss << prefix << "	    return variant;" << std::endl;
		ss << prefix << "    }" << std::endl;
		ss << std::endl;
		ss << prefix << "    return eventVariables_.get(browseNameList, resultCode);" << std::endl;
		ss << prefix << "}" << std::endl;

		sourceContent_ += ss.str();
		return true;
	}

	std::string
	EventTypeGenerator::getTypeNameFromNodeId(OpcUaNodeId& typeNodeId)
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

}
