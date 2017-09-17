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
		ss << prefix << "class " << eventTypeName_ << std::endl;
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
		OpcUaQualifiedName browseName;
		bool success;
		std::stringstream ss;

		InformationModelAccess ima;
		OpcUaNodeId referenceType(46);
		std::vector<OpcUaNodeId> childNodeIdVec;
		std::vector<OpcUaNodeId>::iterator it;
		ima.informationModel(informationModel_);
		success = ima.getChildHierarchically(
			eventTypeNode_,
			referenceType,
			childNodeIdVec
		);
		if (!success) {
			Log(Error, "event properties error")
				.parameter("EventType", eventTypeNodeId_);
			return false;
		}

		ss << prefix << std::endl;
		for (it = childNodeIdVec.begin(); it != childNodeIdVec.end(); it++) {

			// get property node class
			BaseNodeClass::SPtr propertyNodeClass = informationModel_->find(*it);
			if (!propertyNodeClass) {
				Log(Error, "property node class not exist in information model")
					.parameter("EventType", eventTypeNodeId_)
					.parameter("PropertyNodeId", *it);
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
			propertyName[0] = boost::to_lower_copy(propertyName.substr(0,1))[0];

			ss << prefix << "bool " << propertyName << "(OpcUaVariant::SPtr& variable);" << std::endl;
			ss << prefix << "OpcUaVariant::SPtr " << propertyName << "(void);" << std::endl;
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
		OpcUaNodeId referenceType(46);
		std::vector<OpcUaNodeId> childNodeIdVec;
		std::vector<OpcUaNodeId>::iterator it;
		ima.informationModel(informationModel_);
		success = ima.getChildHierarchically(
			eventTypeNode_,
			referenceType,
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

			// get property class name
			if (!propertyNodeClass->getBrowseName(browseName)) {
				Log(Error, "property name not found in node")
					.parameter("EventType", eventTypeNodeId_)
					.parameter("PropertyNodeId", *it);
				return false;
			}
			std::string propertyName = browseName.name().toStdString();

			ss << prefix << "    eventVariables_.registerEventVariable(\"" << propertyName << "\", OpcUaBuildInType_OpcUaNodeId);" << std::endl;
		}


		ss << prefix << std::endl;
		ss << prefix << "    OpcUaVariant::SPtr eventType = constructSPtr<OpcUaVariant>();" << std::endl;
		ss << prefix << "    eventType->setValue(OpcUaNodeId((OpcUaUInt32)" << eventTypeNumber_ << "));" << std::endl;
		ss << prefix << "    eventVariables_.setValue(\"" << eventTypeName_ << "\", eventType);" << std::endl;
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

		OpcUaQualifiedName browseName;
		bool success;

		InformationModelAccess ima;
		OpcUaNodeId referenceType(46);
		std::vector<OpcUaNodeId> childNodeIdVec;
		std::vector<OpcUaNodeId>::iterator it;
		ima.informationModel(informationModel_);
		success = ima.getChildHierarchically(
			eventTypeNode_,
			referenceType,
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

			// get property class name
			if (!propertyNodeClass->getBrowseName(browseName)) {
				Log(Error, "property name not found in node")
					.parameter("EventType", eventTypeNodeId_)
					.parameter("PropertyNodeId", *it);
				return false;
			}
			std::string propertyName = browseName.name().toStdString();
			std::string propertyNameLower = propertyName;
			propertyNameLower[0] = boost::to_lower_copy(propertyNameLower.substr(0,1))[0];

			ss << prefix << std::endl;
			ss << prefix << "OpcUaVariant::SPtr " << std::endl;
			ss << prefix << eventTypeName_ << "::" << propertyNameLower << "(void)" << std::endl;
			ss << prefix << "{" << std::endl;
			ss << prefix << "	OpcUaVariant::SPtr value;" << std::endl;
			ss << prefix << "	eventVariables_.getValue(\"" << propertyNameLower << "\", value);" << std::endl;
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

		OpcUaQualifiedName browseName;
		bool success;

		InformationModelAccess ima;
		OpcUaNodeId referenceType(46);
		std::vector<OpcUaNodeId> childNodeIdVec;
		std::vector<OpcUaNodeId>::iterator it;
		ima.informationModel(informationModel_);
		success = ima.getChildHierarchically(
			eventTypeNode_,
			referenceType,
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

			// get property class name
			if (!propertyNodeClass->getBrowseName(browseName)) {
				Log(Error, "property name not found in node")
					.parameter("EventType", eventTypeNodeId_)
					.parameter("PropertyNodeId", *it);
				return false;
			}
			std::string propertyName = browseName.name().toStdString();
			std::string propertyNameLower = propertyName;
			propertyNameLower[0] = boost::to_lower_copy(propertyNameLower.substr(0,1))[0];

			ss << prefix << std::endl;
			ss << prefix << "bool " << std::endl;
			ss << prefix << eventTypeName_ << "::" << propertyNameLower << "(OpcUaVariant::SPtr& " << propertyNameLower << ")" << std::endl;
			ss << prefix << "{" << std::endl;
			ss << prefix << "	return eventVariables_.setValue(\"" << propertyName << "\", " << propertyNameLower << ");" << std::endl;
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
		ss << prefix << "    OpcUaVariant::SPtr eventType;" << std::endl;
		ss << prefix << "    eventVariables_.getValue(\"" << eventTypeName_ << "\", eventType);" << std::endl;
		ss << prefix << std::endl;
		ss << prefix << "    setNamespaceIndex(eventVariables_.namespaceUri(), namespaceIndex, eventVariables_.browseName(), eventType);" << std::endl;
		ss << prefix << std::endl;
		ss << prefix << "	eventVariables_.setValue(\"" << eventTypeName_ << "\", eventType);" << std::endl;
		ss << prefix << "	eventVariables_.namespaceIndex(namespaceIndex);" << std::endl;
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
		ss << prefix << "	resultCode = EventResult::Success;" << std::endl;
		ss << std::endl;
		ss << prefix << "	OpcUaNodeId typeNodeId;" << std::endl;
		ss << prefix << "	OpcUaVariant::SPtr tmpVariant;" << std::endl;
		ss << prefix << "	eventVariables_.getValue(\"" << eventTypeName_ << "\", tmpVariant);" << std::endl;
		ss << prefix << "	tmpVariant->getValue(typeNodeId);" << std::endl;
		ss << std::endl;
		ss << prefix << "	// check whether eventType and typeNodeId are identical" << std::endl;
		ss << prefix << "	if (eventType == typeNodeId) {" << std::endl;
		ss << prefix << "		return eventVariables_.get(browseNameList, resultCode);" << std::endl;
		ss << prefix <<	"	}" << std::endl;
		ss << std::endl;
		ss << prefix << "	// the start item was not found. We delegate the search to the base class" << std::endl;
		ss << prefix << "	OpcUaVariant::SPtr variant;" << std::endl;
		ss << prefix << "	variant = BaseEventType::get(eventType, browseNameList, resultCode);" << std::endl;
		ss << prefix << "	if (resultCode != EventResult::Success || browseNameList.empty()) {" << std::endl;
		ss << prefix << "		return variant;" << std::endl;
		ss << prefix << "	}" << std::endl;
		ss << std::endl;
		ss << prefix << "	return eventVariables_.get(browseNameList, resultCode);" << std::endl;
		ss << prefix << "}" << std::endl;

		sourceContent_ += ss.str();
		return true;
	}

}
