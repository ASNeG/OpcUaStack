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

#include "BuildConfig.h"
#include "OpcUaStackCore/Base/Log.h"
#include "OpcUaStackServer/Generator/EnumTypeGenerator.h"
#include "OpcUaStackServer/InformationModel/InformationModelAccess.h"

namespace OpcUaStackServer
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// EnumTypeGenerator
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	EnumTypeGenerator::EnumTypeGenerator(void)
	: informationModel_()
	, sourceContent_("")
	, headerContent_("")

	, nodeInfo_()
	{
	}

	EnumTypeGenerator::~EnumTypeGenerator(void)
	{
	}

	bool
	EnumTypeGenerator::generate(const OpcUaNodeId& enumType)
	{
		// check parameter
		if (informationModel_.get() == nullptr) {
			Log(Error, "invalid parameter - information model is null");
			return false;
		}

		// create node infos
		if (!nodeInfo_.init(enumType, informationModel_)) {
			return false;
		}
		nodeInfo_.log();

		// generate header and source content
		return
			generateHeader() &&
			generateSource();
	}

	void
	EnumTypeGenerator::informationModel(InformationModel::SPtr& informationModel)
	{
		informationModel_ = informationModel;
	}

	bool
	EnumTypeGenerator::setNamespaceEntry(const std::string& namespaceEntry)
	{
		return nodeInfo_.setNamespaceEntry(namespaceEntry);
	}

	std::string&
	EnumTypeGenerator::sourceContent(void)
	{
		return sourceContent_;
	}

	std::string&
	EnumTypeGenerator::headerContent(void)
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
	EnumTypeGenerator::generateHeader(void)
	{
		return
			generateHeaderComments() &&
			generateHeaderBegin() &&
				generateHeaderClassBegin("    ") &&
					generateHeaderClassValueGetter("        ") &&
				    generateHeaderClassExtensionInterface("        ") &&
				    generateHeaderClassPublic("        ") &&
				    generateHeaderClassPrivate("    ") &&
				    generateHeaderClassValueDefinition("        ") &&
				generateHeaderClassEnd("    ") &&
		    generateHeaderEnd();
	}

	bool
	EnumTypeGenerator::generateHeaderComments(void)
	{
		std::stringstream ss;

		ss << "/*" << std::endl;
		ss << "    EnumTypeClass: " << nodeInfo_.className() << std::endl;
		ss << std::endl;
		ss << "    Generated Source Code - please do not change this source code" << std::endl;
		ss << std::endl;
		ss << "    EnumTypeCodeGenerator Version:"  << std::endl;
		ss << "        OpcUaStackCore - " << VERSION_MAJOR << "." << VERSION_MINOR << "." << VERSION_PATCH << std::endl;
		ss << std::endl;
		ss << "    Autor: Kai Huebl (kai@huebl-sgh.de)" << std::endl;
		ss << "*/" << std::endl;

		headerContent_ += ss.str();
		return true;
	}

	bool
	EnumTypeGenerator::generateHeaderBegin(void)
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
	EnumTypeGenerator::generateHeaderEnd(void)
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
	EnumTypeGenerator::generateHeaderClassBegin(const std::string& prefix)
	{
		std::stringstream ss;

		//
		// added class
		//
		ss << prefix << std::endl;
		ss << prefix << "class " << nodeInfo_.className() << std::endl;

		//
		// added base classes
		//
		ss << prefix << ": public Object" << std::endl;
		ss << prefix << ", public ExtensionObjectBase" << std::endl;


		ss << prefix << "{" << std::endl;
		ss << prefix << "  public:" << std::endl;
		ss << prefix << "    typedef boost::shared_ptr<" << nodeInfo_.className()  << "> SPtr;" << std::endl;
		ss << prefix << std::endl;
		ss << prefix << "    " << nodeInfo_.className() << "(void);" << std::endl;
		ss << prefix << "    virtual ~" << nodeInfo_.className() << "(void);" << std::endl;

		headerContent_ += ss.str();
		return true;
	}

	bool
	EnumTypeGenerator::generateHeaderClassEnd(const std::string& prefix)
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
	EnumTypeGenerator::generateHeaderClassExtensionInterface(const std::string& prefix)
	{
		std::stringstream ss;

		//
		// added extension interface
		//
		ss << prefix << std::endl;
		ss << prefix << "//- ExtensionObjectBase -----------------------------------------------" << std::endl;
		ss << prefix << "virtual ExtensionObjectBase::SPtr factory(void);" << std::endl;
		ss << prefix << "virtual OpcUaNodeId binaryTypeId(void);" << std::endl;
		ss << prefix << "virtual OpcUaNodeId xmlTypeId(void);" << std::endl;
		ss << prefix << "virtual void opcUaBinaryEncode(std::ostream& os) const;" << std::endl;
		ss << prefix << "virtual void opcUaBinaryDecode(std::istream& is);" << std::endl;
		ss << prefix << "virtual bool encode(boost::property_tree::ptree& pt, Xmlns& xmlns) const;" << std::endl;
		ss << prefix << "virtual bool decode(boost::property_tree::ptree& pt, Xmlns& xmlns);" << std::endl;
		ss << prefix << "virtual bool xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns);" << std::endl;
		ss << prefix << "virtual bool xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns);" << std::endl;
		ss << prefix << "virtual bool xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns);" << std::endl;
		ss << prefix << "virtual void copyTo(ExtensionObjectBase& extensionObjectBase);" << std::endl;
		ss << prefix << "virtual bool equal(ExtensionObjectBase& extensionObjectBase) const;" << std::endl;
		ss << prefix << "virtual void out(std::ostream& os);" << std::endl;
		ss << prefix << "//- ExtensionObjectBase -----------------------------------------------" << std::endl;

		headerContent_ += ss.str();
		return true;
	}

	bool
	EnumTypeGenerator::generateHeaderClassPublic(const std::string& prefix)
	{
		std::stringstream ss;

		ss << prefix << std::endl;
		ss << prefix << "void copyTo(" << nodeInfo_.className() << "& value);" << std::endl;
		ss << prefix << "bool operator==(const " << nodeInfo_.className() << "& value) const;" << std::endl;

		headerContent_ += ss.str();
		return true;
	}

	bool
	EnumTypeGenerator::generateHeaderClassValueGetter(const std::string& prefix)
	{
		std::stringstream ss;

		//
		// added value definition
		//
		ss << prefix << std::endl;
		ss << prefix << "uint32_t& value(void);" << std::endl;

		headerContent_ += ss.str();
		return true;
	}

	bool
	EnumTypeGenerator::generateHeaderClassPrivate(const std::string& prefix)
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
	EnumTypeGenerator::generateHeaderClassValueDefinition(const std::string& prefix)
	{
		std::stringstream ss;

		//
		// added value definition
		//
		EnumTypeField::Vec::iterator it;
		EnumTypeField::Vec& dataTypeFields = nodeInfo_.fields();

		ss << prefix << "uint32_t value_;" << std::endl;

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
	EnumTypeGenerator::generateSource(void)
	{
		return
			generateSourceComments() &&
			generateSourceIncludes() &&
			generateSourceClassBegin() &&
				generateSourceClassConstructor("    ") &&
				generateSourceClassDestructor("    ") &&
				generateSourceClassGetter("    ") &&
				generateSourceClassPublicEQ("    ") &&
				generateSourceClassPublicCP("    ") &&
				generateSourceClassExtensionObjectBase("    ") &&
				generateSourceClassFactory("    ") &&
				generateSourceClassBinaryTypeId("    ") &&
				generateSourceClassXmlTypeId("    ") &&
				generateSourceClassBinaryEncode("    ") &&
				generateSourceClassBinaryDecode("    ") &&
				generateSourceClassEncode("    ") &&
				generateSourceClassDecode("    ") &&
				generateSourceClassXmlEncode("    ") &&
				generateSourceClassXmlDecode("    ") &&
				generateSourceClassCopyTo("    ") &&
				generateSourceClassEqual("    ") &&
				generateSourceClassOut("    ") &&
			generateSourceClassEnd();
	}

	bool
	EnumTypeGenerator::generateSourceComments(void)
	{
		std::stringstream ss;

		ss << "/*" << std::endl;
		ss << "    EnumTypeClass: " << nodeInfo_.className() << std::endl;
		ss << std::endl;
		ss << "    Generated Source Code - please do not change this source code" << std::endl;
		ss << std::endl;
		ss << "    EnumTypeCodeGenerator Version:" << std::endl;
		ss << "        OpcUaStackCore - " << VERSION_MAJOR << "." << VERSION_MINOR << "." << VERSION_PATCH  << std::endl;
		ss << std::endl;
		ss << "    Autor: Kai Huebl (kai@huebl-sgh.de)" << std::endl;
		ss << "*/" << std::endl;

		sourceContent_ += ss.str();
		return true;
	}

	bool
	EnumTypeGenerator::generateSourceIncludes(void)
	{
		std::stringstream ss;

		ss << std::endl;
		ss << "#include \"" << nodeInfo_.namespaceName() << "/" << nodeInfo_.directory() << "/" << nodeInfo_.className() << ".h\"" << std::endl;

		sourceContent_ += ss.str();
		return true;
	}

	bool
	EnumTypeGenerator::generateSourceClassBegin(void)
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
	EnumTypeGenerator::generateSourceClassEnd(void)
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
	EnumTypeGenerator::generateSourceClassConstructor(const std::string& prefix)
	{
		std::stringstream ss;

		//
		// added constructor
		//
		ss << prefix << std::endl;
		ss << prefix << nodeInfo_.className() << "::" << nodeInfo_.className() << "(void)" << std::endl;

		ss << prefix << ": Object()" << std::endl;
		ss << prefix << ", ExtensionObjectBase()" << std::endl;
		ss << prefix << ", value_(0)" << std::endl;

		ss << prefix << "{" << std::endl;
		ss << prefix << "}" << std::endl;

		sourceContent_ += ss.str();
		return true;
	}

	bool
	EnumTypeGenerator::generateSourceClassDestructor(const std::string& prefix)
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
	EnumTypeGenerator::generateSourceClassGetter(const std::string& prefix)
	{
		std::stringstream ss;

		ss << prefix << std::endl;
		ss << prefix << "uint32_t&" << std::endl;
		ss << prefix << nodeInfo_.className() << "::value(void)" << std::endl;
		ss << prefix << "{" << std::endl;
		ss << prefix << "    return value_;" << std::endl;
		ss << prefix << "}" << std::endl;

		sourceContent_ += ss.str();
		return true;
	}

	bool
	EnumTypeGenerator::generateSourceClassPublicEQ(const std::string& prefix)
	{
		std::stringstream ss;

		ss << prefix << std::endl;
		ss << prefix << "bool" << std::endl;
		ss << prefix << nodeInfo_.className() << "::operator==(const " << nodeInfo_.className() << "& value) const" << std::endl;
		ss << prefix << "{" << std::endl;
		ss << prefix << "    if (value_ != value.value_) return false;" << std::endl;
		ss << prefix << "    return true;" << std::endl;
		ss << prefix << "}" << std::endl;

		sourceContent_ += ss.str();
		return true;
	}

	bool
	EnumTypeGenerator::generateSourceClassPublicCP(const std::string& prefix)
	{
		std::stringstream ss;

		ss << prefix << std::endl;
		ss << prefix << "void" << std::endl;
		ss << prefix << nodeInfo_.className() << "::copyTo(" << nodeInfo_.className() << "& value)" << std::endl;
		ss << prefix << "{" << std::endl;
		ss << prefix << "    value.value_ = value_;" << std::endl;
		ss << prefix << "}" << std::endl;

		sourceContent_ += ss.str();
		return true;
	}

	bool
	EnumTypeGenerator::generateSourceClassExtensionObjectBase(const std::string& prefix)
	{
		std::stringstream ss;

		ss << prefix << std::endl;
		ss << prefix << "// ------------------------------------------------------------------------" << std::endl;
		ss << prefix << "// ------------------------------------------------------------------------" << std::endl;
		ss << prefix << "//" << std::endl;
		ss << prefix << "// ExtensionObjectBase" << std::endl;
		ss << prefix << "//" << std::endl;
		ss << prefix << "// ------------------------------------------------------------------------" << std::endl;
		ss << prefix << "// ------------------------------------------------------------------------" << std::endl;

		sourceContent_ += ss.str();
		return true;
	}

	bool
	EnumTypeGenerator::generateSourceClassFactory(const std::string& prefix)
	{
		std::stringstream ss;

		ss << prefix << std::endl;
		ss << prefix << "ExtensionObjectBase::SPtr" << std::endl;
		ss << prefix << nodeInfo_.className() << "::factory(void)" << std::endl;
		ss << prefix << "{" << std::endl;
		ss << prefix << "	return constructSPtr<" << nodeInfo_.className() << ">();" << std::endl;
		ss << prefix << "}" << std::endl;

		sourceContent_ += ss.str();
		return true;
	}

	bool
	EnumTypeGenerator::generateSourceClassBinaryTypeId(const std::string& prefix)
	{
		std::stringstream ss;

		// FIXME: todo
		std::string identifier = "0";
		std::string namespaceName = "0";

		ss << prefix << std::endl;
		ss << prefix << "OpcUaNodeId" << std::endl;
		ss << prefix << nodeInfo_.className() << "::binaryTypeId(void)" << std::endl;
		ss << prefix << "{" << std::endl;
		ss << prefix << "	return OpcUaNodeId(" << namespaceName << ", " << identifier << ");" << std::endl;
		ss << prefix << "}" << std::endl;

		sourceContent_ += ss.str();
		return true;
	}

	bool
	EnumTypeGenerator::generateSourceClassXmlTypeId(const std::string& prefix)
	{
		std::stringstream ss;

		// FIXME: todo
		std::string identifier = "0";
		std::string namespaceName = "0";

		ss << prefix << std::endl;
		ss << prefix << "OpcUaNodeId" << std::endl;
		ss << prefix << nodeInfo_.className() << "::xmlTypeId(void)" << std::endl;
		ss << prefix << "{" << std::endl;
		ss << prefix << "	return OpcUaNodeId(" << namespaceName << ", " << identifier << ");" << std::endl;
		ss << prefix << "}" << std::endl;

		sourceContent_ += ss.str();
		return true;
	}

	bool
	EnumTypeGenerator::generateSourceClassBinaryEncode(const std::string& prefix)
	{
		std::stringstream ss;

		ss << prefix << std::endl;
		ss << prefix << "void" << std::endl;
		ss << prefix << nodeInfo_.className() << "::opcUaBinaryEncode(std::ostream& os) const" << std::endl;
		ss << prefix << "{" << std::endl;
		ss << prefix << "    OpcUaNumber::opcUaBinaryEncode(os, value_);" << std::endl;
		ss << prefix << "}" << std::endl;

		sourceContent_ += ss.str();
		return true;
	}

	bool
	EnumTypeGenerator::generateSourceClassBinaryDecode(const std::string& prefix)
	{
		std::stringstream ss;

		ss << prefix << std::endl;
		ss << prefix << "void" << std::endl;
		ss << prefix << nodeInfo_.className() << "::opcUaBinaryDecode(std::istream& is)" << std::endl;
		ss << prefix << "{" << std::endl;
		ss << prefix << "    OpcUaNumber::opcUaBinaryDecode(is, value_);" << std::endl;
		ss << prefix << "}" << std::endl;

		sourceContent_ += ss.str();
		return true;
	}



	bool
	EnumTypeGenerator::generateSourceClassEncode(const std::string& prefix)
	{
		std::stringstream ss;

		ss << prefix << std::endl;
		ss << prefix << "bool" << std::endl;
		ss << prefix << nodeInfo_.className() << "::encode(boost::property_tree::ptree& pt, Xmlns& xmlns) const" << std::endl;
		ss << prefix << "{" << std::endl;
		// FIXME: todo
		ss << prefix << "}" << std::endl;

		sourceContent_ += ss.str();
		return true;
	}

	bool
	EnumTypeGenerator::generateSourceClassDecode(const std::string& prefix)
	{
		std::stringstream ss;

		ss << prefix << std::endl;
		ss << prefix << "bool" << std::endl;
		ss << prefix << nodeInfo_.className() << "::decode(boost::property_tree::ptree& pt, Xmlns& xmlns)" << std::endl;
		ss << prefix << "{" << std::endl;
		// FIXME: todo
		ss << prefix << "}" << std::endl;

		sourceContent_ += ss.str();
		return true;
	}

	bool
	EnumTypeGenerator::generateSourceClassXmlEncode(const std::string& prefix)
	{
		std::stringstream ss;

		ss << prefix << std::endl;
		ss << prefix <<  "bool" << std::endl;
		ss << prefix <<  nodeInfo_.className() << "::xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)" << std::endl;
		ss << prefix << "{" << std::endl;
		// FIXME: todo
		ss << prefix << "}" << std::endl;

		ss << prefix << std::endl;
		ss << prefix << "bool" << std::endl;
		ss << prefix << nodeInfo_.className() << "::xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns)" << std::endl;
		ss << prefix << "{" << std::endl;
		// FIXME: todo
		ss << prefix << "}" << std::endl;

		sourceContent_ += ss.str();
		return true;
	}

	bool
	EnumTypeGenerator::generateSourceClassXmlDecode(const std::string& prefix)
	{
		std::stringstream ss;

		ss << prefix << std::endl;
		ss << prefix <<  "bool" << std::endl;
		ss << prefix << nodeInfo_.className() << "::xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns)" << std::endl;
		ss << prefix << "{" << std::endl;
		// FIXME: todo
		ss << prefix << "}" << std::endl;

		sourceContent_ += ss.str();
		return true;
	}

	bool
	EnumTypeGenerator::generateSourceClassCopyTo(const std::string& prefix)
	{
		std::stringstream ss;

		ss << prefix << std::endl;
		ss << prefix << "void" << std::endl;
		ss << prefix << nodeInfo_.className() << "::copyTo(ExtensionObjectBase& extensionObjectBase)" << std::endl;
		ss << prefix << "{" << std::endl;
		ss << prefix << "	" << nodeInfo_.className() <<  "* dst = dynamic_cast<" << nodeInfo_.className() << "*>(&extensionObjectBase);" << std::endl;
		ss << prefix << "	copyTo(*dst);" << std::endl;
		ss << prefix << "}" << std::endl;

		sourceContent_ += ss.str();
		return true;
	}

	bool
	EnumTypeGenerator::generateSourceClassEqual(const std::string& prefix)
	{
		std::stringstream ss;

		ss << prefix << std::endl;
		ss << prefix << "bool" << std::endl;
		ss << prefix << nodeInfo_.className() << "::equal(ExtensionObjectBase& extensionObjectBase) const" << std::endl;
		ss << prefix << "{" << std::endl;
		ss << prefix << "	" << nodeInfo_.className() << "* dst = dynamic_cast<" << nodeInfo_.className() << "*>(&extensionObjectBase);" << std::endl;
		ss << prefix << "	return *this == *dst;" << std::endl;
		ss << prefix << "}" << std::endl;

		sourceContent_ += ss.str();
		return true;
	}

	bool
	EnumTypeGenerator::generateSourceClassOut(const std::string& prefix)
	{
		std::stringstream ss;

		ss << prefix << std::endl;
		ss << prefix << "void" << std::endl;
		ss << prefix << nodeInfo_.className() << "::out(std::ostream& os)" << std::endl;
		ss << prefix << "{" << std::endl;
		ss << prefix << "    os << \"Value=\" << value_;" << std::endl;
		ss << prefix << "}" << std::endl;

		sourceContent_ += ss.str();
		return true;
	}

}
