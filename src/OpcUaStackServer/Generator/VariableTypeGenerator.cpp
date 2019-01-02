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
	: informationModel_()
	, sourceContent_("")
	, headerContent_("")

	, nodeInfo_()
	{
	}

	VariableTypeGenerator::~VariableTypeGenerator(void)
	{
	}

	bool
	VariableTypeGenerator::generate(const OpcUaNodeId& variableType)
	{
		// check parameter
		if (informationModel_.get() == nullptr) {
			Log(Error, "invalid parameter - information model is null");
			return false;
		}

		// create node infos
		if (!nodeInfo_.init(variableType, informationModel_)) {
			return false;
		}
		//nodeInfo_.log();

		// generate header and source content
		return
			generateHeader() &&
			generateSource();
	}

	void
	VariableTypeGenerator::informationModel(InformationModel::SPtr& informationModel)
	{
		informationModel_ = informationModel;
	}

	bool
	VariableTypeGenerator::setNamespaceEntry(const std::string& namespaceEntry)
	{
		// FIXME: todo
		return false;
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
	// header
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	bool
	VariableTypeGenerator::generateHeader(void)
	{
		return
			generateHeaderComments() &&
			generateHeaderBegin() &&
			    generateHeaderClassBegin("   ") &&
				    //generateHeaderClassValueGetter("        ") &&
			        //generateHeaderClassExtensionInterface("        ") &&
			        //generateHeaderClassPublic("        ") &&
			        generateHeaderClassPrivate("    ") &&
			        generateHeaderClassValueDefinition("        ") &&
				generateHeaderClassEnd("   ") &&
			generateHeaderEnd();
	}

	bool
	VariableTypeGenerator::generateHeaderComments(void)
	{
		std::stringstream ss;

		ss << "/*" << std::endl;
		ss << "    VariableTypeClass: " << nodeInfo_.className() << std::endl;
		ss << std::endl;
		ss << "    Generated Source Code - please do not change this source code" << std::endl;
		ss << std::endl;
		ss << "    VariableTypeCodeGenerator Version:"  << std::endl;
		ss << "        OpcUaStackCore - " << VERSION_MAJOR << "." << VERSION_MINOR << "." << VERSION_PATCH << std::endl;
		ss << std::endl;
		ss << "    Autor:     Kai Huebl (kai@huebl-sgh.de)" << std::endl;
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
		ss << "#ifndef __" << nodeInfo_.namespaceName() << "_" << nodeInfo_.className() << "_h__" << std::endl;
		ss << "#define __" << nodeInfo_.namespaceName() << "_" << nodeInfo_.className() << "_h__" << std::endl;

		//
		// added includes
		//
		ss << std::endl;
		ss << "#include <boost/shared_ptr.hpp>" << std::endl;
		ss << "#include \"OpcUaStackCore/Base/os.h\"" << std::endl;
		ss << "#include \"OpcUaStackCore/Base/ObjectPool.h\"" << std::endl;
		ss << "#include \"OpcUaStackCore/BuildInTypes/BuildInTypes.h\"" << std::endl;
		ss << "#include \"OpcUaStackServer/VariableType/VariableBase.h\"" << std::endl;

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
		ss << prefix << "class DLLEXPORT " << nodeInfo_.className() << std::endl;
		ss << prefix << ": public VariableBase" << std::endl;

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
	VariableTypeGenerator::generateHeaderClassPrivate(const std::string& prefix)
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
	VariableTypeGenerator::generateHeaderClassValueDefinition(const std::string& prefix)
	{
		std::stringstream ss;

		//
		// added value definition
		//
		for (auto& variableTypeField : nodeInfo_.variableTypeFieldMap()) {
			ss << prefix << "ServerVariable::SPtr " << variableTypeField.second->variableName() << ";" << std::endl;
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
	VariableTypeGenerator::generateSource(void)
	{
		return
			generateSourceComments() &&
			generateSourceIncludes() &&
			generateSourceClassBegin() &&
			    generateSourceClassConstructor("    ") &&
				generateSourceClassDestructor("    ") &&
			generateSourceClassEnd();
	}

	bool
	VariableTypeGenerator::generateSourceComments(void)
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
	VariableTypeGenerator::generateSourceIncludes(void)
	{
		std::stringstream ss;

		ss << std::endl;
		ss << "#include \"" << nodeInfo_.namespaceName() << "/" << nodeInfo_.directory() << "/" << nodeInfo_.className() << ".h\"" << std::endl;

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
		ss << "namespace " <<  nodeInfo_.namespaceName() << std::endl;
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
		ss << prefix << ": VariableBase()" << std::endl;

		//
		// added value definition
		//
		for (auto& variableTypeField : nodeInfo_.variableTypeFieldMap()) {
			ss << prefix << ", " << variableTypeField.second->variableName() << "(constructSPtr<ServerVariable>(\"" << variableTypeField.second->name() << "\"))" << std::endl;
		}

		ss << prefix << "{" << std::endl;
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
		ss << prefix << ": VariableBase()" << std::endl;
		ss << prefix << "{" << std::endl;
		ss << prefix << "}" << std::endl;

		sourceContent_ += ss.str();
		return true;
	}

	bool
	VariableTypeGenerator::generateSourceClassDestructor(const std::string& prefix)
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

}
