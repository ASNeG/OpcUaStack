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
		//nodeInfo_.log();

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
				generateHeaderClassValueArray("    ") &&
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
		ss << "    Autor:     Kai Huebl (kai@huebl-sgh.de)" << std::endl;
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
		ss << "#include \"OpcUaStackCore/BuildInTypes/XmlNumber.h\"" << std::endl;

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
		EnumTypeField::Vec enumTypeFieldVec;
		EnumTypeField::Vec::iterator it;
		std::stringstream ss;

		enumTypeFieldVec = nodeInfo_.fields();

		//
		// added class
		//
		ss << prefix << std::endl;
		if (nodeInfo_.description() != "") {
			ss << prefix << "/**" << std::endl;
			ss << prefix << " * " << nodeInfo_.description() << std::endl;
			ss << prefix << " */" << std::endl;
		}

		ss << prefix << "class DLLEXPORT " << nodeInfo_.className() << std::endl;

		//
		// added base classes
		//
		ss << prefix << ": public Object" << std::endl;
		ss << prefix << ", public ExtensionObjectBase" << std::endl;


		ss << prefix << "{" << std::endl;
		ss << prefix << "  public:" << std::endl;

		ss << prefix << "    typedef boost::shared_ptr<" << nodeInfo_.className()  << "> SPtr;" << std::endl;

		// added enum
		ss << prefix << std::endl;
		ss << prefix << "    typedef enum {" << std::endl;
		for (it = enumTypeFieldVec.begin(); it != enumTypeFieldVec.end(); it++) {
			EnumTypeField::SPtr enumTypeField = *it;
			ss << prefix << "        Enum" << enumTypeField->name() << " = " << enumTypeField->value() << ",";
			if (enumTypeField->description() != "") {
				ss << prefix << " //!< " << enumTypeField->description();
			}
			ss << std::endl;
		}
		ss << prefix << "    } Enum;" << std::endl;

		// constructor and destructor
		ss << prefix << std::endl;
		ss << prefix << "    " << nodeInfo_.className() << "(void);" << std::endl;
		ss << prefix << "    " << nodeInfo_.className() << "(Enum enumeration);" << std::endl;
		ss << prefix << "    " << nodeInfo_.className() << "(" << nodeInfo_.className() << "& value);" << std::endl;
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
		ss << prefix << "virtual std::string namespaceName(void);" << std::endl;
		ss << prefix << "virtual std::string typeName(void);" << std::endl;
		ss << prefix << "virtual OpcUaNodeId typeId(void);" << std::endl;
		ss << prefix << "virtual OpcUaNodeId binaryTypeId(void);" << std::endl;
		ss << prefix << "virtual OpcUaNodeId xmlTypeId(void);" << std::endl;
		ss << prefix << "virtual OpcUaNodeId jsonTypeId(void);" << std::endl;
		ss << prefix << "virtual void opcUaBinaryEncode(std::ostream& os) const;" << std::endl;
		ss << prefix << "virtual void opcUaBinaryDecode(std::istream& is);" << std::endl;
		ss << prefix << "virtual bool xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns);" << std::endl;
		ss << prefix << "virtual bool xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns);" << std::endl;
		ss << prefix << "virtual bool xmlDecode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns);" << std::endl;
		ss << prefix << "virtual bool xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns);" << std::endl;
		ss << prefix << "virtual bool jsonEncode(boost::property_tree::ptree& pt, const std::string& element);" << std::endl;
		ss << prefix << "virtual bool jsonEncode(boost::property_tree::ptree& pt);" << std::endl;
		ss << prefix << "virtual bool jsonDecode(boost::property_tree::ptree& pt, const std::string& element);" << std::endl;
		ss << prefix << "virtual bool jsonDecode(boost::property_tree::ptree& pt);" << std::endl;
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
		ss << prefix << "bool operator!=(const " << nodeInfo_.className() << "& value) const;" << std::endl;
		ss << prefix << nodeInfo_.className() << "& operator=(const " << nodeInfo_.className() << "& value);" << std::endl;
		ss << prefix << nodeInfo_.className() << "& operator=(const Enum& value);" << std::endl;

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
		ss << prefix << "int32_t& value(void);" << std::endl;
		ss << prefix << "void enumeration(Enum enumeration);" << std::endl;
		ss << prefix << "Enum enumeration(void);" << std::endl;
		ss << prefix << "Enum str2Enum(const std::string& enumerationString);" << std::endl;
		ss << prefix << "std::string enum2Str(Enum enumeration);" << std::endl;
		ss << prefix << "std::string enum2Str(void);" << std::endl;
		ss << prefix << "std::string toString(void);" << std::endl;
		ss << prefix << "bool exist(const std::string& enumerationString);" << std::endl;
		ss << prefix << "bool exist(Enum enumeration);" << std::endl;

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

		ss << prefix << "int32_t value_;" << std::endl;

		headerContent_ += ss.str();
		return true;
	}

	bool
	EnumTypeGenerator::generateHeaderClassValueArray(const std::string& prefix)
	{
		std::stringstream ss;

		ss << prefix << std::endl;
		ss << prefix << "class DLLEXPORT " << nodeInfo_.className() << "Array" << std::endl;
		ss << prefix << ": public OpcUaArray<" << nodeInfo_.className() << "::SPtr, SPtrTypeCoder<" << nodeInfo_.className() << "> >" << std::endl;
		ss << prefix << ", public Object" << std::endl;
		ss << prefix << "{" << std::endl;
		ss << prefix << "  public:" << std::endl;
		ss << prefix << "	   typedef boost::shared_ptr<" << nodeInfo_.className() << "Array> SPtr;" << std::endl;
		ss << prefix << "};" << std::endl;

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
				generateSourceClassPublicNE("    ") &&
				generateSourceClassPublicAssign1("    ") &&
				generateSourceClassPublicCP("    ") &&
				generateSourceClassExtensionObjectBase("    ") &&
				generateSourceClassFactory("    ") &&
				generateSourceClassBinaryTypeId("    ") &&
				generateSourceClassXmlTypeId("    ") &&
				generateSourceClassJsonTypeId("    ") &&
				generateSourceClassNamespaceName("    ") &&
				generateSourceClassTypeName("    ") &&
				generateSourceClassTypeId("    ") &&
				generateSourceClassBinaryEncode("    ") &&
				generateSourceClassBinaryDecode("    ") &&
				generateSourceClassXmlEncode("    ") &&
				generateSourceClassXmlDecode("    ") &&
				generateSourceClassJsonEncode("    ") &&
				generateSourceClassJsonDecode("    ") &&
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

		ss << prefix << std::endl;
		ss << prefix << nodeInfo_.className() << "::" << nodeInfo_.className() << "(Enum enumeration)" << std::endl;
		ss << prefix << ": Object()" << std::endl;
		ss << prefix << ", ExtensionObjectBase()" << std::endl;
		ss << prefix << ", value_(enumeration)" << std::endl;
		ss << prefix << "{" << std::endl;
		ss << prefix << "}" << std::endl;

		ss << prefix << std::endl;
		ss << prefix << nodeInfo_.className() << "::" << nodeInfo_.className() << "(" << nodeInfo_.className() << "& value)" << std::endl;
		ss << prefix << ": Object()" << std::endl;
		ss << prefix << ", ExtensionObjectBase()" << std::endl;
		ss << prefix << ", value_(value.enumeration())" << std::endl;
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
		EnumTypeField::Vec enumTypeFieldVec;
		EnumTypeField::Vec::iterator it;
		std::stringstream ss;

		enumTypeFieldVec = nodeInfo_.fields();

		//
		// getter function
		//
		ss << prefix << std::endl;
		ss << prefix << "int32_t&" << std::endl;
		ss << prefix << nodeInfo_.className() << "::value(void)" << std::endl;
		ss << prefix << "{" << std::endl;
		ss << prefix << "    return value_;" << std::endl;
		ss << prefix << "}" << std::endl;


		//
		// setter function
		//
		ss << prefix << std::endl;
		ss << prefix << "void" << std::endl;
		ss << prefix << nodeInfo_.className() << "::enumeration(" << nodeInfo_.className() << "::Enum enumeration)" << std::endl;
		ss << prefix << "{" << std::endl;
		ss << prefix << "    value_ = enumeration;" << std::endl;
		ss << prefix << "}" << std::endl;


		//
		// getter function
		//
		ss << prefix << std::endl;
		ss << prefix << nodeInfo_.className() << "::Enum" << std::endl;
		ss << prefix << nodeInfo_.className() << "::enumeration(void)" << std::endl;
		ss << prefix << "{" << std::endl;
		ss << prefix << "    return (Enum)value_;" << std::endl;
		ss << prefix << "}" << std::endl;


		//
		// map string to enum function
		//
		ss << prefix << std::endl;
		ss << prefix << nodeInfo_.className() << "::Enum" << std::endl;
		ss << prefix << nodeInfo_.className() << "::str2Enum(const std::string& enumerationString)" << std::endl;
		ss << prefix << "{" << std::endl;
		for (it = enumTypeFieldVec.begin(); it != enumTypeFieldVec.end(); it++) {
			EnumTypeField::SPtr enumTypeField = *it;
			ss << prefix << "    if (enumerationString == \"" << enumTypeField->name() << "\") return (Enum)" << enumTypeField->value() << ";" << std::endl;
		}
		ss << prefix << "    return (Enum)0;" << std::endl;
		ss << prefix << "}" << std::endl;


		//
		// map enum to string function
		//
		ss << prefix << std::endl;
		ss << prefix << "std::string" << std::endl;
		ss << prefix << nodeInfo_.className() << "::enum2Str(Enum enumeration)" << std::endl;
		ss << prefix << "{" << std::endl;
		for (it = enumTypeFieldVec.begin(); it != enumTypeFieldVec.end(); it++) {
			EnumTypeField::SPtr enumTypeField = *it;
			ss << prefix << "    if (enumeration == " << enumTypeField->value() << ") return \""<< enumTypeField->name() << "\";" << std::endl;
		}
		ss << prefix << "    return \"Unknown\";" << std::endl;
		ss << prefix << "}" << std::endl;

		ss << prefix << std::endl;
		ss << prefix << "std::string" << std::endl;
		ss << prefix << nodeInfo_.className() << "::enum2Str(void)" << std::endl;
		ss << prefix << "{" << std::endl;
		ss << prefix << "    return enum2Str((Enum)value_);" << std::endl;
		ss << prefix << "}" << std::endl;

		ss << prefix << std::endl;
		ss << prefix << "std::string" << std::endl;
		ss << prefix << nodeInfo_.className() << "::toString(void)" << std::endl;
		ss << prefix << "{" << std::endl;
		ss << prefix << "    return enum2Str((Enum)value_);" << std::endl;
		ss << prefix << "}" << std::endl;



		//
		// exist function
		//
		ss << prefix << std::endl;
		ss << prefix << "bool" << std::endl;
		ss << prefix << nodeInfo_.className() << "::exist(const std::string& enumerationString)" << std::endl;
		ss << prefix << "{" << std::endl;
		for (it = enumTypeFieldVec.begin(); it != enumTypeFieldVec.end(); it++) {
			EnumTypeField::SPtr enumTypeField = *it;
			ss << prefix << "    if (enumerationString == \"" << enumTypeField->name() << "\") return true;" << std::endl;
		}
		ss << prefix << "    return false;" << std::endl;
		ss << prefix << "}" << std::endl;


		//
		// exist function
		//
		ss << prefix << std::endl;
		ss << prefix << "bool" << std::endl;
		ss << prefix << nodeInfo_.className() << "::exist(Enum enumeration)" << std::endl;
		ss << prefix << "{" << std::endl;
		for (it = enumTypeFieldVec.begin(); it != enumTypeFieldVec.end(); it++) {
			EnumTypeField::SPtr enumTypeField = *it;
			ss << prefix << "    if (enumeration == " << enumTypeField->value() << ") return true;" << std::endl;
		}
		ss << prefix << "    return false;" << std::endl;
		ss << prefix << "}" << std::endl;


		sourceContent_ += ss.str();
		return true;
	}

	bool
	EnumTypeGenerator::generateSourceClassPublicNE(const std::string& prefix)
	{
		std::stringstream ss;

		ss << prefix << std::endl;
		ss << prefix << "bool" << std::endl;
		ss << prefix << nodeInfo_.className() << "::operator!=(const " << nodeInfo_.className() << "& value) const" << std::endl;
		ss << prefix << "{" << std::endl;
		ss << prefix << "    return !this->operator==(value);" << std::endl;
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
	EnumTypeGenerator::generateSourceClassPublicAssign1(const std::string& prefix)
	{
		std::stringstream ss;

		ss << prefix << std::endl;
		ss << prefix << nodeInfo_.className() << "&"<< std::endl;
		ss << prefix << nodeInfo_.className() << "::operator=(const " << nodeInfo_.className() << "& value)" << std::endl;
		ss << prefix << "{" << std::endl;
		ss << prefix << "    value_ = const_cast<" << nodeInfo_.className() << "&>(value).value();" << std::endl;
		ss << prefix << "    return *this;" << std::endl;
		ss << prefix << "}" << std::endl;

		ss << prefix << std::endl;
		ss << prefix << nodeInfo_.className() << "&"<< std::endl;
		ss << prefix << nodeInfo_.className() << "::operator=(const Enum& value)" << std::endl;
		ss << prefix << "{" << std::endl;
		ss << prefix << "    value_ = value;" << std::endl;
		ss << prefix << "    return *this;" << std::endl;
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
	EnumTypeGenerator::generateSourceClassNamespaceName(const std::string& prefix)
	{
		std::stringstream ss;

		ss << prefix << std::endl;
		ss << prefix << "std::string" << std::endl;
		ss << prefix << nodeInfo_.className() << "::namespaceName(void)" << std::endl;
		ss << prefix << "{" << std::endl;
		ss << prefix << "	return \"" << nodeInfo_.dataTypeNamespaceName() << "\";" << std::endl;
		ss << prefix << "}" << std::endl;

		sourceContent_ += ss.str();
		return true;
	}

	bool
	EnumTypeGenerator::generateSourceClassTypeName(const std::string& prefix)
	{
		std::stringstream ss;

		ss << prefix << std::endl;
		ss << prefix << "std::string" << std::endl;
		ss << prefix << nodeInfo_.className() << "::typeName(void)" << std::endl;
		ss << prefix << "{" << std::endl;
		ss << prefix << "	return \"" << nodeInfo_.className() << "\";" << std::endl;
		ss << prefix << "}" << std::endl;

		sourceContent_ += ss.str();
		return true;
	}

	bool
	EnumTypeGenerator::generateSourceClassTypeId(const std::string& prefix)
	{
		std::stringstream ss;

		OpcUaNodeId dataTypeNodeId = nodeInfo_.dataTypeNodeId();

		ss << prefix << std::endl;
		ss << prefix << "OpcUaNodeId" << std::endl;
		ss << prefix << nodeInfo_.className() << "::typeId(void)" << std::endl;
		ss << prefix << "{" << std::endl;
		ss << prefix << "	return OpcUaNodeId(" << nodeInfo_.getIdentifierAsString(dataTypeNodeId) << "," << dataTypeNodeId.namespaceIndex() << ");" << std::endl;
		ss << prefix << "}" << std::endl;

		sourceContent_ += ss.str();
		return true;
	}


	bool
	EnumTypeGenerator::generateSourceClassBinaryTypeId(const std::string& prefix)
	{
		std::stringstream ss;

		ss << prefix << std::endl;
		ss << prefix << "OpcUaNodeId" << std::endl;
		ss << prefix << nodeInfo_.className() << "::binaryTypeId(void)" << std::endl;
		ss << prefix << "{" << std::endl;
		ss << prefix << "	return OpcUaNodeId(0, 0);" << std::endl;
		ss << prefix << "}" << std::endl;

		sourceContent_ += ss.str();
		return true;
	}

	bool
	EnumTypeGenerator::generateSourceClassXmlTypeId(const std::string& prefix)
	{
		std::stringstream ss;

		ss << prefix << std::endl;
		ss << prefix << "OpcUaNodeId" << std::endl;
		ss << prefix << nodeInfo_.className() << "::xmlTypeId(void)" << std::endl;
		ss << prefix << "{" << std::endl;
		ss << prefix << "	return OpcUaNodeId(0, 0);" << std::endl;
		ss << prefix << "}" << std::endl;

		sourceContent_ += ss.str();
		return true;
	}

	bool
	EnumTypeGenerator::generateSourceClassJsonTypeId(const std::string& prefix)
	{
		std::stringstream ss;

		ss << prefix << std::endl;
		ss << prefix << "OpcUaNodeId" << std::endl;
		ss << prefix << nodeInfo_.className() << "::jsonTypeId(void)" << std::endl;
		ss << prefix << "{" << std::endl;
		ss << prefix << "	return OpcUaNodeId(0, 0);" << std::endl;
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
	EnumTypeGenerator::generateSourceClassXmlEncode(const std::string& prefix)
	{
		std::stringstream ss;

		ss << prefix << std::endl;
		ss << prefix <<  "bool" << std::endl;
		ss << prefix <<  nodeInfo_.className() << "::xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)" << std::endl;
		ss << prefix << "{" << std::endl;
	    ss << prefix << "    if(!XmlNumber::xmlEncode(pt, value_, element))" << std::endl;
	    ss << prefix << "    {" << std::endl;
		ss << prefix << "	     Log(Error, \""<< nodeInfo_.className() << " json encoder error\")" << std::endl;
		ss << prefix << "		     .parameter(\"Element\", element);" << std::endl;
	    ss << prefix << "        return false;" << std::endl;
	    ss << prefix << "    }" << std::endl;
	    ss << prefix << "    return true;" << std::endl;
		ss << prefix << "}" << std::endl;

		ss << prefix << std::endl;
		ss << prefix << "bool" << std::endl;
		ss << prefix << nodeInfo_.className() << "::xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns)" << std::endl;
		ss << prefix << "{" << std::endl;
	    ss << prefix << "    if(!XmlNumber::xmlEncode(pt, value_)) {" << std::endl;
	    ss << prefix << "	     Log(Error, \""<< nodeInfo_.className() << " json encoder error\");" << std::endl;
	    ss << prefix << "        return false;" << std::endl;
	    ss << prefix << "    }" << std::endl;
	    ss << prefix << "    return true;" << std::endl;
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
		ss << prefix <<  nodeInfo_.className() << "::xmlDecode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)" << std::endl;
		ss << prefix << "{" << std::endl;
		ss << prefix << "    boost::optional<boost::property_tree::ptree&> tree = pt.get_child_optional(element);" << std::endl;
		ss << prefix << "    if (!tree) {" << std::endl;
		ss << prefix << "	     Log(Error, \""<< nodeInfo_.className() << " json decoder error\")" << std::endl;
		ss << prefix << "		     .parameter(\"Element\", element);" << std::endl;
		ss << prefix << "        return false;" << std::endl;
	    ss << prefix << "     }" << std::endl;
		ss << prefix << "    return xmlDecode(*tree, xmlns);" << std::endl;
		ss << prefix << "}" << std::endl;

		ss << prefix << std::endl;
		ss << prefix <<  "bool" << std::endl;
		ss << prefix << nodeInfo_.className() << "::xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns)" << std::endl;
		ss << prefix << "{" << std::endl;
	    ss << prefix << "    if(!XmlNumber::xmlDecode(pt, value_)) {" << std::endl;
	    ss << prefix << "	     Log(Error, \""<< nodeInfo_.className() << " json decoder error\");" << std::endl;
	    ss << prefix << "        return false;" << std::endl;
	 	ss << prefix << "    }" << std::endl;
	    ss << prefix << "    return true;" << std::endl;
		ss << prefix << "}" << std::endl;

		sourceContent_ += ss.str();
		return true;
	}

	bool
	EnumTypeGenerator::generateSourceClassJsonEncode(const std::string& prefix)
	{
		std::stringstream ss;

		ss << prefix << std::endl;
		ss << prefix <<  "bool" << std::endl;
		ss << prefix <<  nodeInfo_.className() << "::jsonEncode(boost::property_tree::ptree& pt, const std::string& element)" << std::endl;
		ss << prefix << "{" << std::endl;
		ss << prefix << "    boost::property_tree::ptree elementTree;" << std::endl;
		ss << prefix << "    if (!jsonEncode(elementTree)) {" << std::endl;
		ss << prefix << "	     Log(Error, \""<< nodeInfo_.className() << " json encoder error\")" << std::endl;
		ss << prefix << "		     .parameter(\"Element\", element);" << std::endl;
		ss << prefix << " 	     return false;" << std::endl;
		ss << prefix << "    }" << std::endl;
		ss << prefix << "    pt.push_back(std::make_pair(element, elementTree));" << std::endl;
		ss << prefix << "    return true;" << std::endl;
		ss << prefix << "}" << std::endl;

		ss << prefix << std::endl;
		ss << prefix << "bool" << std::endl;
		ss << prefix << nodeInfo_.className() << "::jsonEncode(boost::property_tree::ptree& pt)" << std::endl;
		ss << prefix << "{" << std::endl;
		ss << prefix << "    if(!JsonNumber::jsonEncode(pt, value_))" << std::endl;
		ss << prefix << "    {" << std::endl;
		ss << prefix << "	     Log(Error, \""<< nodeInfo_.className() << " json encoder error\")" << std::endl;
		ss << prefix << "		     .parameter(\"Element\", \"Value\");" << std::endl;
		ss << prefix << "       return false;" << std::endl;
	    ss << prefix << "    }" << std::endl;
	    ss << prefix << "    return true;" << std::endl;
		ss << prefix << "}" << std::endl;

		sourceContent_ += ss.str();
		return true;
	}

	bool
	EnumTypeGenerator::generateSourceClassJsonDecode(const std::string& prefix)
	{
		std::stringstream ss;

		ss << prefix << std::endl;
		ss << prefix <<  "bool" << std::endl;
		ss << prefix <<  nodeInfo_.className() << "::jsonDecode(boost::property_tree::ptree& pt, const std::string& element)" << std::endl;
		ss << prefix << "{" << std::endl;
		ss << prefix << "    boost::optional<boost::property_tree::ptree&> tmpTree;" << std::endl;
        ss << prefix << std::endl;
		ss << prefix << "    tmpTree = pt.get_child_optional(element);" << std::endl;
		ss << prefix << "    if (!tmpTree) {" << std::endl;
		ss << prefix << " 	     Log(Error, \"" << nodeInfo_.className() << " json decoder error\")" << std::endl;
		ss << prefix << "		    .parameter(\"Element\", element);" << std::endl;
		ss << prefix << "		 return false;" << std::endl;
		ss << prefix << "    }" << std::endl;
		ss << prefix << "    return jsonDecode(*tmpTree);" << std::endl;
		ss << prefix << "}" << std::endl;

		ss << prefix << std::endl;
		ss << prefix <<  "bool" << std::endl;
		ss << prefix << nodeInfo_.className() << "::jsonDecode(boost::property_tree::ptree& pt)" << std::endl;
		ss << prefix << "{" << std::endl;
		ss << prefix << "    if(!JsonNumber::jsonDecode(pt, value_)) {" << std::endl;
		ss << prefix << "        Log(Error, \"" << nodeInfo_.className() << " decode json error - decode failed\");" << std::endl;
		ss << prefix << "        return false;" << std::endl;
		ss << prefix << "    }" << std::endl;
		ss << prefix << "    return true;" << std::endl;
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
