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
#include "OpcUaStackServer/Generator/DataTypeGenerator.h"
#include "OpcUaStackServer/InformationModel/InformationModelAccess.h"

namespace OpcUaStackServer
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// DataTypeGenerator
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	DataTypeGenerator::DataTypeGenerator(void)
	: informationModel_()
	, sourceContent_("")
	, headerContent_("")

	, nodeInfo_()
	{
	}

	DataTypeGenerator::~DataTypeGenerator(void)
	{
	}

	bool
	DataTypeGenerator::generate(const OpcUaNodeId& dataType)
	{
		// check parameter
		if (informationModel_.get() == nullptr) {
			Log(Error, "invalid parameter - information model is null");
			return false;
		}

		// create node infos
		if (!nodeInfo_.init(dataType, informationModel_)) {
			return false;
		}
		//nodeInfo_.log();

		// generate header and source content
		return
			generateHeader() &&
			generateSource();
	}

	void
	DataTypeGenerator::informationModel(InformationModel::SPtr& informationModel)
	{
		informationModel_ = informationModel;
	}

	bool
	DataTypeGenerator::setNamespaceEntry(const std::string& namespaceEntry)
	{
		return nodeInfo_.setNamespaceEntry(namespaceEntry);
	}

	std::string&
	DataTypeGenerator::sourceContent(void)
	{
		return sourceContent_;
	}

	std::string&
	DataTypeGenerator::headerContent(void)
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
	DataTypeGenerator::generateHeader(void)
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
	DataTypeGenerator::generateHeaderComments(void)
	{
		std::stringstream ss;

		ss << "/*" << std::endl;
		ss << "    DataTypeClass: " << nodeInfo_.className() << std::endl;
		ss << std::endl;
		ss << "    Generated Source Code - please do not change this source code" << std::endl;
		ss << std::endl;
		ss << "    DataTypeCodeGenerator Version:"  << std::endl;
		ss << "        OpcUaStackCore - " << VERSION_MAJOR << "." << VERSION_MINOR << "." << VERSION_PATCH << std::endl;
		ss << std::endl;
		ss << "    Autor:     Kai Huebl (kai@huebl-sgh.de)" << std::endl;
		ss << "*/" << std::endl;

		headerContent_ += ss.str();
		return true;
	}

	bool
	DataTypeGenerator::generateHeaderBegin(void)
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
		// added parent includes
		//
		if (!nodeInfo_.parentIsStructureType()) {
			ss << "#include \"" << nodeInfo_.parentNamespaceName() << "/" << nodeInfo_.parentDirectory()<< "/" << nodeInfo_.parentClassName() << ".h\"" << std::endl;
		}

		//
		// added field includes
		//
		DataTypeField::Vec::iterator it;
		for (it = nodeInfo_.fields().begin(); it != nodeInfo_.fields().end(); it++) {
			DataTypeField::SPtr dataTypeField = *it;
			if (dataTypeField->includePath() != "") {
				ss << "#include \"" << dataTypeField->includePath() <<  "\"" << std::endl;
			}
		}

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
	DataTypeGenerator::generateHeaderEnd(void)
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
	DataTypeGenerator::generateHeaderClassBegin(const std::string& prefix)
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
		if (!nodeInfo_.parentIsStructureType()) {
			ss << prefix << ": public " << nodeInfo_.parentClassName() << std::endl;
		}
		else {
			ss << prefix << ": public Object" << std::endl;
			ss << prefix << ", public ExtensionObjectBase" << std::endl;
		}


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
	DataTypeGenerator::generateHeaderClassEnd(const std::string& prefix)
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
	DataTypeGenerator::generateHeaderClassExtensionInterface(const std::string& prefix)
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
	DataTypeGenerator::generateHeaderClassPublic(const std::string& prefix)
	{
		std::stringstream ss;

		ss << prefix << std::endl;
		ss << prefix << "void copyTo(" << nodeInfo_.className() << "& value);" << std::endl;
		ss << prefix << "bool operator==(const " << nodeInfo_.className() << "& value) const;" << std::endl;
		ss << prefix << "bool operator!=(const " << nodeInfo_.className() << "& value) const;" << std::endl;

		headerContent_ += ss.str();
		return true;
	}

	bool
	DataTypeGenerator::generateHeaderClassValueGetter(const std::string& prefix)
	{
		std::stringstream ss;

		//
		// added value definition
		//
		DataTypeField::Vec::iterator it;
		DataTypeField::Vec& dataTypeFields =  nodeInfo_.fields();

		ss << prefix << std::endl;

		for (it = dataTypeFields.begin(); it != dataTypeFields.end(); it++) {
			DataTypeField::SPtr dataTypeField = *it;

			ss << prefix << dataTypeField->variableType() << "& " << dataTypeField->parameterName() << "(void);" << std::endl;
		}

		headerContent_ += ss.str();
		return true;
	}

	bool
	DataTypeGenerator::generateHeaderClassPrivate(const std::string& prefix)
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
	DataTypeGenerator::generateHeaderClassValueDefinition(const std::string& prefix)
	{
		std::stringstream ss;

		//
		// added value definition
		//
		DataTypeField::Vec::iterator it;
		DataTypeField::Vec& dataTypeFields = nodeInfo_.fields();

		for (it = dataTypeFields.begin(); it != dataTypeFields.end(); it++) {
			DataTypeField::SPtr dataTypeField = *it;

			ss << prefix << dataTypeField->variableType() << " " << dataTypeField->variableName() << ";" << std::endl;
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
	DataTypeGenerator::generateSource(void)
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
	DataTypeGenerator::generateSourceComments(void)
	{
		std::stringstream ss;

		ss << "/*" << std::endl;
		ss << "    DataTypeClass: " << nodeInfo_.className() << std::endl;
		ss << std::endl;
		ss << "    Generated Source Code - please do not change this source code" << std::endl;
		ss << std::endl;
		ss << "    DataTypeCodeGenerator Version:" << std::endl;
		ss << "        OpcUaStackCore - " << VERSION_MAJOR << "." << VERSION_MINOR << "." << VERSION_PATCH  << std::endl;
		ss << std::endl;
		ss << "    Autor: Kai Huebl (kai@huebl-sgh.de)" << std::endl;
		ss << "*/" << std::endl;

		sourceContent_ += ss.str();
		return true;
	}

	bool
	DataTypeGenerator::generateSourceIncludes(void)
	{
		std::stringstream ss;

		ss << std::endl;
		ss << "#include \"" << nodeInfo_.namespaceName() << "/" << nodeInfo_.directory() << "/" << nodeInfo_.className() << ".h\"" << std::endl;

		sourceContent_ += ss.str();
		return true;
	}

	bool
	DataTypeGenerator::generateSourceClassBegin(void)
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
	DataTypeGenerator::generateSourceClassEnd(void)
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
	DataTypeGenerator::generateSourceClassConstructor(const std::string& prefix)
	{
		std::stringstream ss;

		//
		// added constructor
		//
		ss << prefix << std::endl;
		ss << prefix << nodeInfo_.className() << "::" << nodeInfo_.className() << "(void)" << std::endl;

		if (nodeInfo_.parentIsStructureType() == true) {
			ss << prefix << ": Object()" << std::endl;
			ss << prefix << ", ExtensionObjectBase()" << std::endl;
		}
		else {
			ss << prefix << ": " << nodeInfo_.parentClassName() << "()" << std::endl;
		}

		DataTypeField::Vec::iterator it;
		DataTypeField::Vec& dataTypeFields = nodeInfo_.fields();

		for (it = dataTypeFields.begin(); it != dataTypeFields.end(); it++) {
			DataTypeField::SPtr dataTypeField = *it;

			std::string variableContent = "";
			if (dataTypeField->smartpointer() == true) {
				variableContent = "constructSPtr<" + dataTypeField->name() + ">()";
			}

			ss << prefix << ", " << dataTypeField->variableName() << "(" << variableContent << ")" << std::endl;
		}

		ss << prefix << "{" << std::endl;
		ss << prefix << "}" << std::endl;

		sourceContent_ += ss.str();
		return true;
	}

	bool
	DataTypeGenerator::generateSourceClassDestructor(const std::string& prefix)
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
	DataTypeGenerator::generateSourceClassGetter(const std::string& prefix)
	{
		std::stringstream ss;

		DataTypeField::Vec::iterator it;
		DataTypeField::Vec& dataTypeFields = nodeInfo_.fields();

		for (it = dataTypeFields.begin(); it != dataTypeFields.end(); it++) {
			DataTypeField::SPtr dataTypeField = *it;

			ss << prefix << std::endl;
			ss << prefix << dataTypeField->variableType() << "&" << std::endl;
			ss << prefix << nodeInfo_.className() << "::" << dataTypeField->parameterName() << "(void)" << std::endl;
			ss << prefix << "{" << std::endl;
			ss << prefix << "    return " <<  dataTypeField->variableName() << ";" << std::endl;
			ss << prefix << "}" << std::endl;
		}

		sourceContent_ += ss.str();
		return true;
	}

	bool
	DataTypeGenerator::generateSourceClassPublicEQ(const std::string& prefix)
	{
		std::stringstream ss;

		ss << prefix << std::endl;
		ss << prefix << "bool" << std::endl;
		ss << prefix << nodeInfo_.className() << "::operator==(const " << nodeInfo_.className() << "& value) const" << std::endl;
		ss << prefix << "{" << std::endl;
		ss << prefix << "    " << nodeInfo_.className() << "* dst = const_cast<" << nodeInfo_.className() << "*>(&value);" << std::endl;

		DataTypeField::Vec::iterator it;
		DataTypeField::Vec& dataTypeFields = nodeInfo_.fields();

		for (it = dataTypeFields.begin(); it != dataTypeFields.end(); it++) {
			DataTypeField::SPtr dataTypeField = *it;

			if (dataTypeField->smartpointer() == true) {
				// object can be null

				ss << prefix << "    if (" << dataTypeField->variableName() << ".get() == nullptr && dst->" << dataTypeField->parameterName() << "().get() != nullptr) return false;" << std::endl;
				ss << prefix << "    if (" << dataTypeField->variableName() << ".get() != nullptr && dst->" << dataTypeField->parameterName() << "().get() == nullptr) return false;" << std::endl;

				// equal object
				ss << prefix << "    if (*" << dataTypeField->variableName() << " != *dst->" << dataTypeField->parameterName() << "()) return false;" << std::endl;
			}
			else {
				// equal value
				ss << prefix << "    if (" << dataTypeField->variableName() << " != dst->" << dataTypeField->parameterName() << "()) return false;" << std::endl;
			}

		}

		ss << prefix << "    return true;" << std::endl;
		ss << prefix << "}" << std::endl;

		sourceContent_ += ss.str();
		return true;
	}

	bool
	DataTypeGenerator::generateSourceClassPublicNE(const std::string& prefix)
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
	DataTypeGenerator::generateSourceClassPublicCP(const std::string& prefix)
	{
		std::stringstream ss;

		ss << prefix << std::endl;
		ss << prefix << "void" << std::endl;
		ss << prefix << nodeInfo_.className() << "::copyTo(" << nodeInfo_.className() << "& value)" << std::endl;
		ss << prefix << "{" << std::endl;

		DataTypeField::Vec::iterator it;
		DataTypeField::Vec& dataTypeFields = nodeInfo_.fields();

		for (it = dataTypeFields.begin(); it != dataTypeFields.end(); it++) {
			DataTypeField::SPtr dataTypeField = *it;

			if (dataTypeField->array() == true) {
				ss << prefix << "    if (" << dataTypeField->variableName() << ".get() != nullptr) {" << std::endl;
				ss << prefix << "	    " << dataTypeField->variableName() << "->copyTo(*value." << dataTypeField->parameterName() << "());" << std::endl;
				ss << prefix << "    }" << std::endl;
			}
			else if (dataTypeField->smartpointer() == true) {
				ss << prefix << "    " << dataTypeField->variableName() << ".copyTo(value." << dataTypeField->parameterName() << "());" << std::endl;
			}
			else {
				ss << prefix << "    value." << dataTypeField->variableName() << " = " << dataTypeField->variableName() << ";" << std::endl;
			}
		}

		ss << prefix << "}" << std::endl;

		sourceContent_ += ss.str();
		return true;
	}

	bool
	DataTypeGenerator::generateSourceClassExtensionObjectBase(const std::string& prefix)
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
	DataTypeGenerator::generateSourceClassFactory(const std::string& prefix)
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
	DataTypeGenerator::generateSourceClassBinaryTypeId(const std::string& prefix)
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
	DataTypeGenerator::generateSourceClassXmlTypeId(const std::string& prefix)
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
	DataTypeGenerator::generateSourceClassBinaryEncode(const std::string& prefix)
	{
		std::stringstream ss;

		ss << prefix << std::endl;
		ss << prefix << "void" << std::endl;
		ss << prefix << nodeInfo_.className() << "::opcUaBinaryEncode(std::ostream& os) const" << std::endl;
		ss << prefix << "{" << std::endl;

		DataTypeField::Vec::iterator it;
		DataTypeField::Vec& dataTypeFields = nodeInfo_.fields();

		for (it = dataTypeFields.begin(); it != dataTypeFields.end(); it++) {
			DataTypeField::SPtr dataTypeField = *it;

			if (dataTypeField->array() == true) {
				ss << prefix << "    if (" << dataTypeField->variableName() << ".get() == nullptr) {" << std::endl;
				ss << prefix << "	     OpcUaNumber::opcUaBinaryEncode(os, (OpcUaInt32)-1);" << std::endl;
				ss << prefix << "    }" << std::endl;
				ss << prefix << "    else {" << std::endl;
				ss << prefix << "	     " << dataTypeField->variableName() << "->opcUaBinaryEncode(os);" << std::endl;
				ss << prefix << "    }" << std::endl;
			}
			else if ((dataTypeField->number() == true) ||
					 (dataTypeField->byte() == true) ||
					 (dataTypeField->boolean() == true)) {
				ss << prefix << "    OpcUaNumber::opcUaBinaryEncode(os," << dataTypeField->variableName() << ");" << std::endl;
			}
			else {
				ss << prefix << "    " << dataTypeField->variableName() << ".opcUaBinaryEncode(os);" << std::endl;
			}
		}

		ss << prefix << "}" << std::endl;

		sourceContent_ += ss.str();
		return true;
	}

	bool
	DataTypeGenerator::generateSourceClassBinaryDecode(const std::string& prefix)
	{
		std::stringstream ss;

		ss << prefix << std::endl;
		ss << prefix << "void" << std::endl;
		ss << prefix << nodeInfo_.className() << "::opcUaBinaryDecode(std::istream& is)" << std::endl;
		ss << prefix << "{" << std::endl;

		DataTypeField::Vec::iterator it;
		DataTypeField::Vec& dataTypeFields = nodeInfo_.fields();

		for (it = dataTypeFields.begin(); it != dataTypeFields.end(); it++) {
			DataTypeField::SPtr dataTypeField = *it;

			if (dataTypeField->array() == true) {
				ss << prefix << "    " << dataTypeField->variableName() << "->opcUaBinaryDecode(is);" << std::endl;
			}
			else if (dataTypeField->number() ||
					 dataTypeField->byte() ||
					 dataTypeField->boolean()) {
				ss << prefix << "    OpcUaNumber::opcUaBinaryDecode(is," << dataTypeField->variableName() << ");" << std::endl;
			}
			else {
				ss << prefix << "    " << dataTypeField->variableName() << ".opcUaBinaryDecode(is);" << std::endl;
			}
		}

		ss << prefix << "}" << std::endl;

		sourceContent_ += ss.str();
		return true;
	}



	bool
	DataTypeGenerator::generateSourceClassEncode(const std::string& prefix)
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
	DataTypeGenerator::generateSourceClassDecode(const std::string& prefix)
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
	DataTypeGenerator::generateSourceClassXmlEncode(const std::string& prefix)
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
	DataTypeGenerator::generateSourceClassXmlDecode(const std::string& prefix)
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
	DataTypeGenerator::generateSourceClassCopyTo(const std::string& prefix)
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
	DataTypeGenerator::generateSourceClassEqual(const std::string& prefix)
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
	DataTypeGenerator::generateSourceClassOut(const std::string& prefix)
	{
		std::stringstream ss;

		ss << prefix << std::endl;
		ss << prefix << "void" << std::endl;
		ss << prefix << nodeInfo_.className() << "::out(std::ostream& os)" << std::endl;
		ss << prefix << "{" << std::endl;

		DataTypeField::Vec::iterator it;
		DataTypeField::Vec& dataTypeFields = nodeInfo_.fields();

		bool first = true;
		for (it = dataTypeFields.begin(); it != dataTypeFields.end(); it++) {
			DataTypeField::SPtr dataTypeField = *it;

			if (first) {
				first = false;
				ss << prefix << "    os << \"" << dataTypeField->name() << "=";
			}
			else {
				ss << prefix << "    os << \", " << dataTypeField->name() << "=";
			}

			if (dataTypeField->array() == true) {
				ss << "\"; " << dataTypeField->variableName() << "->out(os);";
			}
			else if (dataTypeField->boolean() == true) {
				ss << "\" << " << dataTypeField->variableName() << ";";
			}
			else if (dataTypeField->byte() == true) {
				ss << "\" << "<< dataTypeField->variableName() << ";";
			}
			else if (dataTypeField->number() == true) {
				ss << "\" << "<< dataTypeField->variableName() << ";";
			}
			else {
				ss << "\"; " << dataTypeField->variableName() << ".out(os);";
			}

			ss << std::endl;
		}

		ss << prefix << "}" << std::endl;

		sourceContent_ += ss.str();
		return true;
	}

}
