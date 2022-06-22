/*
   Copyright 2019-2022 Kai Huebl (kai@huebl-sgh.de)

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
#include "OpcUaStackServer/Generator/ObjectTypeGenerator.h"
#include "OpcUaStackServer/InformationModel/InformationModelAccess.h"

using namespace OpcUaStackCore;

namespace OpcUaStackServer
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// ObjectTypeGenerator
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	ObjectTypeGenerator::ObjectTypeGenerator(void)
	: informationModel_()
	, sourceContent_("")
	, headerContent_("")

	, nodeInfo_()
	{
	}

	ObjectTypeGenerator::~ObjectTypeGenerator(void)
	{
	}

	bool
	ObjectTypeGenerator::generate(const OpcUaNodeId& objectType)
	{
		// check parameter
		if (informationModel_.get() == nullptr) {
			Log(Error, "invalid parameter - information model is null");
			return false;
		}

		// create node infos
		if (!nodeInfo_.init(objectType, informationModel_)) {
			return false;
		}

		// generate header and source content
		return
			generateHeader() &&
			generateSource();
	}

	void
	ObjectTypeGenerator::informationModel(InformationModel::SPtr& informationModel)
	{
		informationModel_ = informationModel;
	}

	bool
	ObjectTypeGenerator::setNamespaceEntry(const std::string& namespaceEntry)
	{
		nodeInfo_.setNamespaceEntry(namespaceEntry);
		return false;
	}

	std::string&
	ObjectTypeGenerator::sourceContent(void)
	{
		return sourceContent_;
	}

	std::string&
	ObjectTypeGenerator::headerContent(void)
	{
		return headerContent_;
	}


	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// header
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	bool
	ObjectTypeGenerator::generateHeader(void)
	{
		return
			generateHeaderComments() &&
			generateHeaderBegin() &&
			    generateHeaderClassBegin("   ") &&
				    generateHeaderClassPublicFunction("        ") &&
			        generateHeaderClassPrivate("    ") &&
			        generateHeaderClassValueDefinition("        ") &&
				generateHeaderClassEnd("   ") &&
			generateHeaderEnd();
	}

	bool
	ObjectTypeGenerator::generateHeaderComments(void)
	{
		std::stringstream ss;

		ss << "/*" << std::endl;
		ss << "    ObjectTypeClass: " << nodeInfo_.className() << std::endl;
		ss << std::endl;
		ss << "    Generated Source Code - please do not change this source code" << std::endl;
		ss << std::endl;
		ss << "    ObjectTypeCodeGenerator Version:"  << std::endl;
		ss << "        OpcUaStackCore - " << VERSION_MAJOR << "." << VERSION_MINOR << "." << VERSION_PATCH << std::endl;
		ss << std::endl;
		ss << "    Autor:     Kai Huebl (kai@huebl-sgh.de)" << std::endl;
		ss << "*/" << std::endl;

		headerContent_ += ss.str();
		return true;
	}

	bool
	ObjectTypeGenerator::generateHeaderBegin(void)
	{
		std::stringstream ss;

		//
		// added defines
		//
		ss << std::endl;
		ss << "#ifndef __" << nodeInfo_.namespaceName() << "_" << nodeInfo_.className() << "_h__" << std::endl;
		ss << "#define __" << nodeInfo_.namespaceName() << "_" << nodeInfo_.className() << "_h__" << std::endl;

		//
		// added includes
		//
		ss << std::endl;
		ss << "#include \"OpcUaStackServer/StandardVariableType/VariableBase.h\"" << std::endl;
		ss << "#include \"OpcUaStackServer/StandardObjectType/ObjectBase.h\"" << std::endl;

		//
		// added namespace
		//
		ss << std::endl;
		ss << "namespace " << nodeInfo_.namespaceName() << std::endl;
		ss << "{" << std::endl;

		headerContent_ += ss.str();
		return true;
	}

	bool
	ObjectTypeGenerator::generateHeaderEnd(void)
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
	ObjectTypeGenerator::generateHeaderClassBegin(const std::string& prefix)
	{
		std::stringstream ss;

		//
		// added class
		//
		ss << prefix << std::endl;
		ss << prefix << "class DLLEXPORT " << nodeInfo_.className() << std::endl;
		ss << prefix << ": public ObjectBase" << std::endl;

		ss << prefix << "{" << std::endl;
		ss << prefix << "  public:" << std::endl;
		ss << prefix << "    typedef boost::shared_ptr<" << nodeInfo_.className()  << "> SPtr;" << std::endl;
		ss << prefix << "    typedef std::vector<" << nodeInfo_.className() << "::SPtr> Vec;" << std::endl;
		ss << prefix << std::endl;
		ss << prefix << "    " << nodeInfo_.className() << "(void);" << std::endl;
		ss << prefix << "    " << nodeInfo_.className() << "(const " << nodeInfo_.className() << "& value);" << std::endl;
		ss << prefix << "    virtual ~" << nodeInfo_.className() << "(void);" << std::endl;

		headerContent_ += ss.str();
		return true;
	}

	bool
	ObjectTypeGenerator::generateHeaderClassPublicFunction(const std::string& prefix)
	{
		std::stringstream ss;

		for (auto& variableTypeField : nodeInfo_.variableTypeFieldMap()) {
			auto& vt  = variableTypeField.second;
			ss << std::endl;
			ss << prefix << "//" << std::endl;
			ss << prefix << "// " << vt->dataTypeDescription() << std::endl;
			ss << prefix << "//" << std::endl;
			ss << prefix << "void " << vt->functionName() << "(ServerVariable::SPtr& serverVariable);" << std::endl;
			ss << prefix << "ServerVariable::SPtr& " << vt->functionName() << "(void);" << std::endl;
			ss << prefix << "bool get_" << vt->name() << "(OpcUaStackCore::OpcUaDataValue& dataValue);" << std::endl;
			ss << prefix << "bool set_" << vt->name() << "(const OpcUaStackCore::OpcUaDataValue& dataValue);" << std::endl;
		}

		for (auto& methodTypeField : nodeInfo_.methodTypeFieldMap()) {
			auto& vt  = methodTypeField.second;
			ss << std::endl;
			ss << prefix << "virtual void call_" << vt->name() << "(OpcUaStackCore::ApplicationMethodContext* applicationMethodContext);" << std::endl;
		}

		headerContent_ += ss.str();
		return true;
	}

	bool
	ObjectTypeGenerator::generateHeaderClassEnd(const std::string& prefix)
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
	ObjectTypeGenerator::generateHeaderClassPrivate(const std::string& prefix)
	{
		std::stringstream ss;

		//
		// added private
		//
		ss << prefix << std::endl;
		ss << prefix << "  private:" << std::endl;

		headerContent_ += ss.str();
		return true;
	}

	bool
	ObjectTypeGenerator::generateHeaderClassValueDefinition(const std::string& prefix)
	{
		std::stringstream ss;

		//
		// added value definition
		//
		for (auto& variableTypeField : nodeInfo_.variableTypeFieldMap()) {
			ss << prefix << "ServerVariable::SPtr " << variableTypeField.second->variableName() << ";" << std::endl;
		}

		//
		// added method definition
		//
		for (auto& methodTypeField : nodeInfo_.methodTypeFieldMap()) {
			ss << prefix << "ServerMethod::SPtr " << methodTypeField.second->variableName() << ";" << std::endl;
		}

		headerContent_ += ss.str();
		return true;
	}

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// source
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	bool
	ObjectTypeGenerator::generateSource(void)
	{
		return
			generateSourceComments() &&
			generateSourceIncludes() &&
			generateSourceClassBegin() &&
			    generateSourceClassConstructor("    ") &&
				generateSourceClassDestructor("    ") &&
				generateSourceClassSetterGetter("    ") &&
				generateSourceClassMethod("    ") &&
			generateSourceClassEnd();
	}

	bool
	ObjectTypeGenerator::generateSourceComments(void)
	{
		std::stringstream ss;

		ss << "/*" << std::endl;
		ss << "    VariableTypeClass: " << nodeInfo_.className() << std::endl;
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
	ObjectTypeGenerator::generateSourceIncludes(void)
	{
		std::stringstream ss;

		ss << std::endl;
		ss << "#include \"" << nodeInfo_.namespaceName() << "/" << nodeInfo_.directory() << "/" << nodeInfo_.className() << ".h\"" << std::endl;

		sourceContent_ += ss.str();
		return true;
	}

	bool
	ObjectTypeGenerator::generateSourceClassBegin(void)
	{
		std::stringstream ss;

		//
		// namespace
		//

		ss << "using namespace OpcUaStackCore;" << std::endl;
		ss << std::endl;
		ss << "namespace " <<  nodeInfo_.namespaceName() << std::endl;
		ss << "{" << std::endl;

		sourceContent_ += ss.str();
		return true;
	}

	bool
	ObjectTypeGenerator::generateSourceClassEnd(void)
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
	ObjectTypeGenerator::generateSourceClassConstructor(const std::string& prefix)
	{
		std::stringstream ss;

		//
		// added constructor
		//
		ss << prefix << std::endl;
		if (nodeInfo_.description() != "") {
			ss << prefix << "/**" << std::endl;
			ss << prefix << " * " << nodeInfo_.description() << std::endl;
			ss << prefix << " */" << std::endl;
		}

		ss << prefix << nodeInfo_.className() << "::" << nodeInfo_.className() << "(void)" << std::endl;
		ss << prefix << ": ObjectBase()" << std::endl;

		for (auto& variableTypeField : nodeInfo_.variableTypeFieldMap()) {
			auto& vt = variableTypeField.second;
			ss << prefix << ", " << vt->variableName() << "(boost::make_shared<ServerVariable>(\"" << vt->name() << "\"))" << std::endl;
		}

		for (auto& methodTypeField : nodeInfo_.methodTypeFieldMap()) {
			auto& vt = methodTypeField.second;
			ss << prefix << ", " << vt->variableName() << "(boost::make_shared<ServerMethod>(\"" << vt->name() << "\"))" << std::endl;
		}

		ss << prefix << "{" << std::endl;

		ss << prefix << "    objectTypeNamespaceName(\"" << nodeInfo_.objectTypeNamespaceName() << "\");" << std::endl;
		ss << prefix << "    objectTypeNodeId(" << nodeInfo_.getIdentifierAsString(nodeInfo_.objectTypeNodeId()) << ");" << std::endl;

		for (auto& variableTypeField : nodeInfo_.variableTypeFieldMap()) {
			auto& vt = variableTypeField.second;
			ss << prefix << "    setServerVariable(" << vt->variableName() << ");" << std::endl;
		}

		for (auto& methodTypeField : nodeInfo_.methodTypeFieldMap()) {
			auto& vt = methodTypeField.second;
			ss << prefix << "    setServerMethod(" << vt->variableName() << ");" << std::endl;
		}

		for (auto& methodTypeField : nodeInfo_.methodTypeFieldMap()) {
			auto& vt = methodTypeField.second;
			ss << prefix << "    " << vt->variableName() << "->registerMethod(boost::bind(&" << nodeInfo_.className() << "::call_" << vt->name() << ", this, boost::placeholder::_1));" << std::endl;
		}

		ss << prefix << "}" << std::endl;

		//
		// added copy constructor
		//
		ss << prefix << std::endl;
		if (nodeInfo_.description() != "") {
			ss << prefix << "/**" << std::endl;
			ss << prefix << " * " << nodeInfo_.description() << std::endl;
			ss << prefix << " */" << std::endl;
		}

		ss << prefix << nodeInfo_.className() << "::" << nodeInfo_.className() << "(const " <<nodeInfo_.className()  << "& value)" << std::endl;
		ss << prefix << ": ObjectBase()" << std::endl;

		for (auto& variableTypeField : nodeInfo_.variableTypeFieldMap()) {
			auto& vt = variableTypeField.second;
			ss << prefix << ", " << vt->variableName() << "(boost::make_shared<ServerVariable>(\"" << vt->name() << "\"))" << std::endl;
		}

		for (auto& methodTypeField : nodeInfo_.methodTypeFieldMap()) {
			auto& vt = methodTypeField.second;
			ss << prefix << ", " << vt->variableName() << "(boost::make_shared<ServerMethod>(\"" << vt->name() << "\"))" << std::endl;
		}

		ss << prefix << "{" << std::endl;

		ss << prefix << "    objectTypeNamespaceName(\"" << nodeInfo_.objectTypeNamespaceName() << "\");" << std::endl;
		ss << prefix << "    objectTypeNodeId(" << nodeInfo_.getIdentifierAsString(nodeInfo_.objectTypeNodeId()) << ");" << std::endl;

		for (auto& variableTypeField : nodeInfo_.variableTypeFieldMap()) {
			auto& vt = variableTypeField.second;
			ss << prefix << "    setServerVariable(" << vt->variableName() << ");" << std::endl;
		}

		for (auto& methodTypeField : nodeInfo_.methodTypeFieldMap()) {
			auto& vt = methodTypeField.second;
			ss << prefix << "    setServerMethod(" << vt->variableName() << ");" << std::endl;
		}

		for (auto& methodTypeField : nodeInfo_.methodTypeFieldMap()) {
			auto& vt = methodTypeField.second;
			ss << prefix << "    " << vt->variableName() << "->registerMethod(boost::bind(&" << nodeInfo_.className() << "::call_" << vt->name() << ", this, boost::placeholder::_1));" << std::endl;
		}

		ss << prefix << "}" << std::endl;

		sourceContent_ += ss.str();
		return true;
	}

	bool
	ObjectTypeGenerator::generateSourceClassDestructor(const std::string& prefix)
	{
		std::stringstream ss;

		//
		// added destructor
		//
		ss << prefix << std::endl;
		ss << prefix << nodeInfo_.className() << "::~" << nodeInfo_.className() << "(void)" << std::endl;
		ss << prefix << "{" << std::endl;
		ss << prefix << "}" << std::endl;

		sourceContent_ += ss.str();
		return true;
	}

	bool
	ObjectTypeGenerator::generateSourceClassSetterGetter(const std::string& prefix)
	{
		std::stringstream ss;

		//
		// getter method (Server Variable)
		//
		for (auto& variableTypeField : nodeInfo_.variableTypeFieldMap()) {
			auto& vt = variableTypeField.second;

			ss << std::endl;
			ss << prefix << "ServerVariable::SPtr&" << std::endl;
			ss << prefix << nodeInfo_.className() << "::" << vt->functionName() << "(void)" << std::endl;
			ss << prefix << "{" << std::endl;
			ss << prefix << "    return " << vt->variableName() << ";" << std::endl;
			ss << prefix << "}" << std::endl;
		}

		//
		// setter method (ServerVariable)
		//
		for (auto& variableTypeField : nodeInfo_.variableTypeFieldMap()) {
			auto& vt = variableTypeField.second;

			ss << std::endl;
			ss << prefix << "void" << std::endl;
			ss << prefix << nodeInfo_.className() << "::" << vt->functionName() << "(ServerVariable::SPtr& serverVariable)" << std::endl;
			ss << prefix << "{" << std::endl;
			ss << prefix << "    "<< vt->variableName() << " = serverVariable;" << std::endl;
			ss << prefix << "}" << std::endl;
		}

		//
		// getter method (OpcUaDataValue)
		//
		for (auto& variableTypeField : nodeInfo_.variableTypeFieldMap()) {
			auto& vt = variableTypeField.second;

			ss << std::endl;
			ss << prefix << "bool" << std::endl;
			ss << prefix << nodeInfo_.className() << "::" << "get_" << vt->name() << "(OpcUaDataValue& dataValue)" << std::endl;
			ss << prefix << "{" << std::endl;
			ss << prefix << "    return " << vt->variableName() << "->getDataValue(dataValue);" << std::endl;
			ss << prefix << "}" << std::endl;
		}

		//
		// setter method (OpcUaDataValue)
		//
		for (auto& variableTypeField : nodeInfo_.variableTypeFieldMap()) {
			auto& vt = variableTypeField.second;

			ss << std::endl;
			ss << prefix << "bool" << std::endl;
			ss << prefix << nodeInfo_.className() << "::" << "set_" << vt->name() << "(const OpcUaDataValue& dataValue)" << std::endl;
			ss << prefix << "{" << std::endl;
			ss << prefix << "    return " << vt->variableName() << "->setDataValue(dataValue);" << std::endl;
			ss << prefix << "}" << std::endl;
		}

		sourceContent_ += ss.str();
		return true;
	}

	bool
	ObjectTypeGenerator::generateSourceClassMethod(const std::string& prefix)
	{
		std::stringstream ss;

		for (auto& methodTypeField : nodeInfo_.methodTypeFieldMap()) {
			auto& vt = methodTypeField.second;

			ss << std::endl;
			ss << prefix << "void" << std::endl;
			ss << prefix << nodeInfo_.className() << "::call_" << vt->name() << "(ApplicationMethodContext* applicationMethodContext)" << std::endl;
			ss << prefix << "{" << std::endl;
			ss << prefix << "    applicationMethodContext->statusCode_ = BadNotSupported;" << std::endl;
			ss << prefix << "}" << std::endl;
		}

		sourceContent_ += ss.str();
		return true;
	}

}
