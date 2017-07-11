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

#include <boost/lexical_cast.hpp>
#include "BuildConfig.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaType.h"
#include "OpcUaStackCore/DataType/DataTypeGenerator.h"
#include "OpcUaStackCore/Base/Log.h"

namespace OpcUaStackCore
{

	DataTypeGenerator::DataTypeGenerator(void)
	: binaryEncodingNodeId_((OpcUaUInt32)0)
	, xmlEncodingNodeId_((OpcUaUInt32)0)
	, dataTypeGeneratorIf_(nullptr)
	, projectNamespace_("OpcUaStackCore")
	, projectDirectory_("StandardDataTypes")
	, dataTypeDefinition_()
	, superTypeDataTypeDefinition_()
	, sourceContent_("")
	, headerContent_("")
	{
	}

	DataTypeGenerator::~DataTypeGenerator(void)
	{
	}

	void
	DataTypeGenerator::binaryEncodingNodeId(OpcUaNodeId& binaryEncodingNodeId)
	{
		binaryEncodingNodeId_ = binaryEncodingNodeId;
	}

	void
	DataTypeGenerator::xmlEncodingNodeId(OpcUaNodeId& xmlEncodingNodeId)
	{
		xmlEncodingNodeId_ = xmlEncodingNodeId;
	}

	void
	DataTypeGenerator::dataTypeGeneratorIf(DataTypeGeneratorIf* dataTypeGeneratorIf)
	{
		dataTypeGeneratorIf_ = dataTypeGeneratorIf;
	}

	void
	DataTypeGenerator::projectNamespace(const std::string& projectNamespace)
	{
		projectNamespace_ = projectNamespace;
	}

	void
	DataTypeGenerator::projectDirectory(const std::string& projectDirectory)
	{
		projectDirectory_ = projectDirectory;
	}

	void
	DataTypeGenerator::dataTypeDefinition(DataTypeDefinition::SPtr& dataTypeDefinition)
	{
		dataTypeDefinition_ = dataTypeDefinition;
	}

	void
	DataTypeGenerator::superTypeDataTypeDefinition(DataTypeDefinition::SPtr& dataTypeDefinition)
	{
		superTypeDataTypeDefinition_ = dataTypeDefinition;
	}

	std::string&
	DataTypeGenerator::sourceFileContent(void)
	{
		return sourceContent_;
	}

	std::string&
	DataTypeGenerator::headerFileContent(void)
	{
		return headerContent_;
	}

	bool
	DataTypeGenerator::generate(void)
	{
		if (dataTypeDefinition_.get() == nullptr) {
			Log(Error, "data type generation error - data type definition is null");
			return false;
		}

		return
			generateHeader() &&
			generateSource();
	}

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// header functions
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
		ss << "    DataTypeClass: " << dataTypeDefinition_->name().name().value() << std::endl;
		ss << std::endl;
		ss << "    Generated Source Code - please do not change this source code" << std::endl;
		ss << std::endl;
		ss << "    DataTypeCodeGenerator Version:"  << std::endl;
		ss << "        OpcUaStackCore - " << VERSION_MAJOR << "." << VERSION_MINOR << "." << VERSION_PATCH << std::endl;
		ss << std::endl;
		ss << "    Autor: Kai Huebl (kai@huebl-sgh.de)" << std::endl;
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
		ss << "#ifndef __" << projectNamespace_ << "_" << dataTypeDefinition_->name().name().value() << "_h__" << std::endl;
		ss << "#define __" << projectNamespace_ << "_" << dataTypeDefinition_->name().name().value() << "_h__" << std::endl;

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
		ss << "namespace " << projectNamespace_ << std::endl;
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
		std::string className = dataTypeDefinition_->name().name().value();
		std::stringstream ss;

		//
		// added class
		//
		ss << prefix << std::endl;
		ss << prefix << "class " << className << std::endl;
		ss << prefix << ": public Object" << std::endl;
		ss << prefix << ", public ExtensionObjectBase" << std::endl;
		ss << prefix << "{" << std::endl;
		ss << prefix << "  public:" << std::endl;
		ss << prefix << "    typedef boost::shared_ptr<" << className  << "> SPtr;" << std::endl;
		ss << prefix << std::endl;
		ss << prefix << "    " << className << "(void);" << std::endl;
		ss << prefix << "    virtual ~" << className << "(void);" << std::endl;

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

		std::string className = dataTypeDefinition_->name().name().value();

		ss << prefix << std::endl;
		ss << prefix << "void copyTo(" << className << "& value);" << std::endl;
		ss << prefix << "bool operator==(const " << className << "& value) const;" << std::endl;

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
	DataTypeGenerator::generateHeaderClassValueGetter(const std::string& prefix)
	{
		std::stringstream ss;

		//
		// added value definition
		//
		DataTypeField::Vec::iterator it;
		DataTypeField::Vec& dataTypeFields = dataTypeDefinition_->dataFields();

		ss << prefix << std::endl;

		for (it = dataTypeFields.begin(); it != dataTypeFields.end(); it++) {
			DataTypeField::SPtr dataTypeField = *it;

			std::string variableName;
			if (!createVariableName(dataTypeField, variableName, true)) return false;

			std::string variableType;
			if (!createVariableType(dataTypeField, variableType, true)) return false;

			ss << prefix << variableType << "& " << variableName << "(void);" << std::endl;
		}

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
		DataTypeField::Vec& dataTypeFields = dataTypeDefinition_->dataFields();

		for (it = dataTypeFields.begin(); it != dataTypeFields.end(); it++) {
			DataTypeField::SPtr dataTypeField = *it;

			std::string variableName;
			if (!createVariableName(dataTypeField, variableName, true)) return false;

			std::string variableType;
			if (!createVariableType(dataTypeField, variableType, true)) return false;

			ss << prefix << variableType << " " << variableName << "_;" << std::endl;
		}

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
				generateSourceClassPublicCP("    ") &&
				generateSourceClassExtensionObjectBase("    ") &&
				generateSourceClassFactory("    ") &&
				generateSourceClassBinaryTypeId("    ") &&
				generateSourceClassXmlTypeId("    ") &&
				generateSourceClassBinaryEncode("    ") &&
				generateSourceClassBinaryDecode("    ") &&
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
		ss << "    DataTypeClass: " << dataTypeDefinition_->name().name().value() << std::endl;
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
		ss << "#include \"" << projectNamespace_ << "/" << projectDirectory_ << "/" << dataTypeDefinition_->name().name().value() << ".h\"" << std::endl;

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
		ss << "namespace " <<  projectNamespace_ << std::endl;
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


		std::string className = dataTypeDefinition_->name().name().value();

		//
		// added constructor
		//
		ss << prefix << std::endl;
		ss << prefix << className << "::" << className << "(void)" << std::endl;

		DataTypeField::Vec::iterator it;
		DataTypeField::Vec& dataTypeFields = dataTypeDefinition_->dataFields();

		std::string delemiter = ": ";
		for (it = dataTypeFields.begin(); it != dataTypeFields.end(); it++) {
			DataTypeField::SPtr dataTypeField = *it;

			std::string variableName;
			if (!createVariableName(dataTypeField, variableName, false)) return false;

			std::string variableType;
			if (!createVariableType(dataTypeField, variableType, false, false)) return false;

			std::string variableContent = "";
			if (dataTypeField->valueRank() >= 0) {
				variableContent = "constructSPtr<" + variableType + ">()";
			}

			ss << prefix << delemiter << variableName << "(" << variableContent << ")" << std::endl;
			delemiter = ", ";
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

		std::string className = dataTypeDefinition_->name().name().value();

		//
		// added destructor
		//
		ss << prefix << std::endl;
		ss << prefix << className << "::~" << className << "(void)" << std::endl;
		ss << prefix << "{" << std::endl;
		ss << prefix << "}" << std::endl;

		sourceContent_ += ss.str();
		return true;
	}

	bool
	DataTypeGenerator::generateSourceClassGetter(const std::string& prefix)
	{
		std::stringstream ss;

		std::string className = dataTypeDefinition_->name().name().value();

		DataTypeField::Vec::iterator it;
		DataTypeField::Vec& dataTypeFields = dataTypeDefinition_->dataFields();

		for (it = dataTypeFields.begin(); it != dataTypeFields.end(); it++) {
			DataTypeField::SPtr dataTypeField = *it;

			std::string variableName;
			if (!createVariableName(dataTypeField, variableName, false)) return false;

			std::string functionName;
			if (!createVariableName(dataTypeField, functionName, false, false)) return false;

			std::string variableType;
			if (!createVariableType(dataTypeField, variableType, false)) return false;

			ss << prefix << std::endl;
			ss << prefix << variableType << "&" << std::endl;
			ss << prefix << className << "::" << functionName << "(void)" << std::endl;
			ss << prefix << "{" << std::endl;
			ss << prefix << "    return " <<  variableName << ";" << std::endl;
			ss << prefix << "}" << std::endl;
		}

		sourceContent_ += ss.str();
		return true;
	}

	bool
	DataTypeGenerator::generateSourceClassPublicEQ(const std::string& prefix)
	{
		std::stringstream ss;

		std::string className = dataTypeDefinition_->name().name().value();

		ss << prefix << std::endl;
		ss << prefix << "bool" << std::endl;
		ss << prefix << className << "::operator==(const " << className << "& value) const" << std::endl;
		ss << prefix << "{" << std::endl;
		ss << prefix << "    " << className << "* dst = const_cast<" << className << "*>(&value);" << std::endl;

		DataTypeField::Vec::iterator it;
		DataTypeField::Vec& dataTypeFields = dataTypeDefinition_->dataFields();

		for (it = dataTypeFields.begin(); it != dataTypeFields.end(); it++) {
			DataTypeField::SPtr dataTypeField = *it;

			std::string variableName;
			if (!createVariableName(dataTypeField, variableName, false)) return false;

			std::string functionName;
			if (!createVariableName(dataTypeField, functionName, false, false)) return false;

			if (dataTypeField->valueRank() >= 0) {
				// object can be null

				ss << prefix << "    if (" << variableName << ".get() == nullptr && dst->" << functionName << "().get() != nullptr) return false;" << std::endl;
				ss << prefix << "    if (" << variableName << ".get() != nullptr && dst->" << functionName << "().get() == nullptr) return false;" << std::endl;

				// equal object
				ss << prefix << "    if (*" << variableName << " != *dst->" << functionName << "()) return false;" << std::endl;
			}
			else {
				// equal value
				ss << prefix << "    if (" << variableName << " != dst->" << functionName << "()) return false;" << std::endl;
			}

		}

		ss << prefix << "    return true;" << std::endl;
		ss << prefix << "}" << std::endl;

		sourceContent_ += ss.str();
		return true;
	}

	bool
	DataTypeGenerator::generateSourceClassPublicCP(const std::string& prefix)
	{
		std::stringstream ss;

		std::string className = dataTypeDefinition_->name().name().value();

		ss << prefix << std::endl;
		ss << prefix << "void" << std::endl;
		ss << prefix << className << "::copyTo(" << className << "& value)" << std::endl;
		ss << prefix << "{" << std::endl;

		DataTypeField::Vec::iterator it;
		DataTypeField::Vec& dataTypeFields = dataTypeDefinition_->dataFields();

		for (it = dataTypeFields.begin(); it != dataTypeFields.end(); it++) {
			DataTypeField::SPtr dataTypeField = *it;

			std::string variableName;
			if (!createVariableName(dataTypeField, variableName, false)) return false;

			std::string functionName;
			if (!createVariableName(dataTypeField, functionName, false, false)) return false;

			if (dataTypeField->valueRank() >= 0) {
				ss << prefix << "    if (" << variableName << ".get() != nullptr) {" << std::endl;
				ss << prefix << "	    " << variableName << "->copyTo(*value." << functionName << "());" << std::endl;
				ss << prefix << "    }" << std::endl;
			}
			else if (isObject(dataTypeField->dataType())) {
				ss << prefix << "    " << variableName << ".copyTo(value." << functionName << "());" << std::endl;
			}
			else {
				ss << prefix << "    value." << functionName << " = " << variableName << ";" << std::endl;
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

		std::string className = dataTypeDefinition_->name().name().value();

		ss << prefix << std::endl;
		ss << prefix << "ExtensionObjectBase::SPtr" << std::endl;
		ss << prefix << className << "::factory(void)" << std::endl;
		ss << prefix << "{" << std::endl;
		ss << prefix << "	return constructSPtr<" << className << ">();" << std::endl;
		ss << prefix << "}" << std::endl;

		sourceContent_ += ss.str();
		return true;
	}

	bool
	DataTypeGenerator::generateSourceClassBinaryTypeId(const std::string& prefix)
	{
		std::stringstream ss;

		std::string className = dataTypeDefinition_->name().name().value();

		ss << prefix << std::endl;
		ss << prefix << "OpcUaNodeId" << std::endl;
		ss << prefix << className << "::binaryTypeId(void)" << std::endl;
		ss << prefix << "{" << std::endl;
		ss << prefix << "	return OpcUaNodeId(" << getIdentifier(binaryEncodingNodeId_) << ", " << (uint32_t)binaryEncodingNodeId_.namespaceIndex() << ");" << std::endl;
		ss << prefix << "}" << std::endl;

		sourceContent_ += ss.str();
		return true;
	}

	bool
	DataTypeGenerator::generateSourceClassXmlTypeId(const std::string& prefix)
	{
		std::stringstream ss;

		std::string className = dataTypeDefinition_->name().name().value();

		ss << prefix << std::endl;
		ss << prefix << "OpcUaNodeId" << std::endl;
		ss << prefix << className << "::xmlTypeId(void)" << std::endl;
		ss << prefix << "{" << std::endl;
		ss << prefix << "	return OpcUaNodeId(" << getIdentifier(xmlEncodingNodeId_) << ", " << (uint32_t)xmlEncodingNodeId_.namespaceIndex() << ");" << std::endl;
		ss << prefix << "}" << std::endl;

		sourceContent_ += ss.str();
		return true;
	}

	bool
	DataTypeGenerator::generateSourceClassBinaryEncode(const std::string& prefix)
	{
		std::stringstream ss;

		std::string className = dataTypeDefinition_->name().name().value();

		ss << prefix << std::endl;
		ss << prefix << "void" << std::endl;
		ss << prefix << className << "::opcUaBinaryEncode(std::ostream& os) const" << std::endl;
		ss << prefix << "{" << std::endl;

		DataTypeField::Vec::iterator it;
		DataTypeField::Vec& dataTypeFields = dataTypeDefinition_->dataFields();

		for (it = dataTypeFields.begin(); it != dataTypeFields.end(); it++) {
			DataTypeField::SPtr dataTypeField = *it;

			std::string variableName;
			if (!createVariableName(dataTypeField, variableName, false)) return false;

			std::string variableType;
			if (!createVariableType(dataTypeField,  variableType, false)) return false;

			if (dataTypeField->valueRank() >= 0) {
				ss << prefix << "    if (" << variableName << ".get() == nullptr) {" << std::endl;
				ss << prefix << "	     OpcUaNumber::opcUaBinaryEncode(os, (OpcUaInt32)-1);" << std::endl;
				ss << prefix << "    }" << std::endl;
				ss << prefix << "    else {" << std::endl;
				ss << prefix << "	     " << variableName << "->opcUaBinaryEncode(os);" << std::endl;
				ss << prefix << "    }" << std::endl;
			}
			else if (isNumber(dataTypeField->dataType()) ||
					 isByte(dataTypeField->dataType()) ||
					 isBoolean(dataTypeField->dataType())) {
				ss << prefix << "    OpcUaNumber::opcUaBinaryEncode(os," << variableName << ");" << std::endl;
			}
			else {
				ss << prefix << "    " << variableName << ".opcUaBinaryEncode(os);" << std::endl;
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

		std::string className = dataTypeDefinition_->name().name().value();

		ss << prefix << std::endl;
		ss << prefix << "void" << std::endl;
		ss << prefix << className << "::opcUaBinaryDecode(std::istream& is)" << std::endl;
		ss << prefix << "{" << std::endl;

		DataTypeField::Vec::iterator it;
		DataTypeField::Vec& dataTypeFields = dataTypeDefinition_->dataFields();

		for (it = dataTypeFields.begin(); it != dataTypeFields.end(); it++) {
			DataTypeField::SPtr dataTypeField = *it;

			std::string variableName;
			if (!createVariableName(dataTypeField, variableName, false)) return false;

			std::string variableType;
			if (!createVariableType(dataTypeField,  variableType, false)) return false;

			if (dataTypeField->valueRank() >= 0) {
				ss << prefix << "    " << variableName << "->opcUaBinaryDecode(is);" << std::endl;
			}
			else if (isNumber(dataTypeField->dataType()) ||
					 isByte(dataTypeField->dataType()) ||
					 isBoolean(dataTypeField->dataType())) {
				ss << prefix << "    OpcUaNumber::opcUaBinaryDecode(is," << variableName << ");" << std::endl;
			}
			else {
				ss << prefix << "    " << variableName << ".opcUaBinaryDecode(os);" << std::endl;
			}
		}

		ss << prefix << "}" << std::endl;

		sourceContent_ += ss.str();
		return true;
	}

	bool
	DataTypeGenerator::generateSourceClassXmlEncode(const std::string& prefix)
	{
		std::stringstream ss;

		std::string className = dataTypeDefinition_->name().name().value();

		ss << prefix << std::endl;
		ss << prefix << "bool" << std::endl;
		ss << prefix << className << "::encode(boost::property_tree::ptree& pt, Xmlns& xmlns) const" << std::endl;
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

		std::string className = dataTypeDefinition_->name().name().value();

		ss << prefix << std::endl;
		ss << prefix << "bool" << std::endl;
		ss << prefix << className << "::decode(boost::property_tree::ptree& pt, Xmlns& xmlns)" << std::endl;
		ss << prefix << "{" << std::endl;
		// FIXME: todo
		ss << prefix << "}" << std::endl;

		sourceContent_ += ss.str();
		return true;
	}

#if 0
    <Argument>
       <Name>SubscriptionId</Name>
       <DataType>
         <Identifier>i=7</Identifier>
       </DataType>
       <ValueRank>-1</ValueRank>
       <ArrayDimensions />
       <Description p5:nil="true" xmlns:p5="http://www.w3.org/2001/XMLSchema-instance" />
     </Argument>

#endif

	bool
	DataTypeGenerator::generateSourceClassCopyTo(const std::string& prefix)
	{
		std::stringstream ss;

		std::string className = dataTypeDefinition_->name().name().value();

		ss << prefix << std::endl;
		ss << prefix << "void" << std::endl;
		ss << prefix << className << "::copyTo(ExtensionObjectBase& extensionObjectBase)" << std::endl;
		ss << prefix << "{" << std::endl;
		ss << prefix << "	" << className <<  "* dst = dynamic_cast<" << className << "*>(&extensionObjectBase);" << std::endl;
		ss << prefix << "	copyTo(*dst);" << std::endl;
		ss << prefix << "}" << std::endl;

		sourceContent_ += ss.str();
		return true;
	}

	bool
	DataTypeGenerator::generateSourceClassEqual(const std::string& prefix)
	{
		std::stringstream ss;

		std::string className = dataTypeDefinition_->name().name().value();

		ss << prefix << std::endl;
		ss << prefix << "bool" << std::endl;
		ss << prefix << className << "::equal(ExtensionObjectBase& extensionObjectBase) const" << std::endl;
		ss << prefix << "{" << std::endl;
		ss << prefix << "	" << className << "* dst = dynamic_cast<" << className << "*>(&extensionObjectBase);" << std::endl;
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
		ss << prefix << "Argument::out(std::ostream& os)" << std::endl;
		ss << prefix << "{" << std::endl;

		DataTypeField::Vec::iterator it;
		DataTypeField::Vec& dataTypeFields = dataTypeDefinition_->dataFields();

		bool first = true;
		for (it = dataTypeFields.begin(); it != dataTypeFields.end(); it++) {
			DataTypeField::SPtr dataTypeField = *it;

			std::string variableName;
			if (!createVariableName(dataTypeField, variableName, false)) return false;

			if (first) {
				first = false;
				ss << prefix << "    os << \"" << dataTypeField->name() << "=";
			}
			else {
				ss << prefix << "    os << \", " << dataTypeField->name() << "=";
			}

			if (dataTypeField->valueRank() >= 0) {
				ss << "\"; " << variableName << "->out(os);";
			}
			else if (isBoolean(dataTypeField->dataType())) {
				ss << "\" << " << variableName << ";";
			}
			else if (isByte(dataTypeField->dataType())) {
				ss << "\" << "<< variableName << ";";
			}
			else if (isNumber(dataTypeField->dataType())) {
				ss << "\" << "<< variableName << ";";
			}
			else {
				ss << "\"; " << variableName << ".out(os);";
			}

			ss << std::endl;
		}

		ss << prefix << "}" << std::endl;

		sourceContent_ += ss.str();
		return true;
	}

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// private function
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
    std::string
    DataTypeGenerator::getIdentifier(OpcUaNodeId& nodeId)
    {
    	if (nodeId.nodeIdType() == OpcUaBuildInType_OpcUaUInt32) {
    		uint16_t namespaceIndex;
    		uint32_t id;
    		nodeId.get(id, namespaceIndex);

    		std::stringstream ss;
    		ss << "(OpcUaUInt32)" << id;

    		return ss.str();
    	}
    	else if (nodeId.nodeIdType() == OpcUaBuildInType_OpcUaString) {
    		uint16_t namespaceIndex;
    		std::string id;
    		nodeId.get(id, namespaceIndex);

       		std::stringstream ss;
        	ss << "\"" << id << "\"";

        	return ss.str();
    	}
       	else if (nodeId.nodeIdType() == OpcUaBuildInType_OpcUaGuid) {
    		uint16_t namespaceIndex;
    		std::string id;
    		nodeId.get(id, namespaceIndex);

       		std::stringstream ss;
        	ss << "\"" << id << "\"";

        	return ss.str();
        }
       	else {
       		return "(OpcUaUInt32)0";
       	}
    	return "";
    }

	std::string
	DataTypeGenerator::getTypeNameFromNodeId(OpcUaNodeId& typeNodeId)
	{
		// build in type possible
		if (typeNodeId.namespaceIndex() == 0 && typeNodeId.nodeIdType() == OpcUaBuildInType_OpcUaUInt32) {
			uint32_t type;
			uint16_t namespaceIndex;
			typeNodeId.get(type, namespaceIndex);
			std::string buildInType = OpcUaBuildInTypeMap::buildInType2String((OpcUaBuildInType)type);
			if (buildInType != "Unknown") return buildInType;
		}

		// map type node id to type string
		if (dataTypeGeneratorIf_ == nullptr) {
			return "Unknown";
		}

		return dataTypeGeneratorIf_->getTypeNameFromNodeId(typeNodeId);
	}

	bool
	DataTypeGenerator::createVariableName(DataTypeField::SPtr& dataTypeField, std::string& variableName, bool headerFile, bool ext)
	{
		variableName = dataTypeField->name().value();
		if (variableName.length() == 0) {
			if (headerFile) {
				Log(Error, "create header file error, because name empty")
					.parameter("StructureName", dataTypeDefinition_->name().name().value());
			}
			else {
				Log(Error, "create source file error, because name empty")
					.parameter("StructureName", dataTypeDefinition_->name().name().value());
			}
			return false;
		}
		variableName[0] = boost::to_lower_copy(variableName.substr(0,1))[0];
		if (ext) {
			variableName += "_";
		}
		return true;
	}

	bool
	DataTypeGenerator::createVariableType(
		DataTypeField::SPtr& dataTypeField,
		std::string& variableType,
		bool headerFile,
		bool sptr
	)
	{
		OpcUaNodeId typeNodeId = dataTypeField->dataType();
		variableType = getTypeNameFromNodeId(typeNodeId);
		if (variableType == "Unknown") {
			std::string variableName;
			createVariableName(dataTypeField, variableName, headerFile);

			if (headerFile) {
				Log(Error, "create header file error, because type node id unknown")
					.parameter("StructureName", dataTypeDefinition_->name().name().value())
					.parameter("VariableName", variableName)
					.parameter("TypeNodeId", typeNodeId);
			}
			else {
				Log(Error, "create source file error, because type node id unknown")
					.parameter("StructureName", dataTypeDefinition_->name().name().value())
					.parameter("VariableName", variableName)
					.parameter("TypeNodeId", typeNodeId);
			}

			return false;
		}

		if (dataTypeField->valueRank() >= 0) {
			variableType += "Array" ;
			if (sptr) variableType += "::SPtr";
		}
		variableType = "OpcUa" + variableType;

		return true;
	}

	bool
	DataTypeGenerator::isBoolean(OpcUaNodeId& typeNodeId)
	{
		if (typeNodeId.nodeIdType() != OpcUaBuildInType_OpcUaUInt32) return false;

		uint16_t namespaceIndex;
		OpcUaUInt32 id;
		typeNodeId.get(id, namespaceIndex);

		return OpcUaBuildInTypeClass::isBoolean((OpcUaBuildInType)id);
	}

	bool
	DataTypeGenerator::isByte(OpcUaNodeId& typeNodeId)
	{
		if (typeNodeId.nodeIdType() != OpcUaBuildInType_OpcUaUInt32) return false;

		uint16_t namespaceIndex;
		OpcUaUInt32 id;
		typeNodeId.get(id, namespaceIndex);

		return OpcUaBuildInTypeClass::isByte((OpcUaBuildInType)id);
	}

    bool
    DataTypeGenerator::isNumber(OpcUaNodeId& typeNodeId)
	{
		if (typeNodeId.nodeIdType() != OpcUaBuildInType_OpcUaUInt32) return false;

		uint16_t namespaceIndex;
		OpcUaUInt32 id;
		typeNodeId.get(id, namespaceIndex);

		return OpcUaBuildInTypeClass::isNumber((OpcUaBuildInType)id);
	}

    bool
    DataTypeGenerator::isObject(OpcUaNodeId& typeNodeId)
	{
    	if (typeNodeId.nodeIdType() != OpcUaBuildInType_OpcUaUInt32) return true;

		uint16_t namespaceIndex;
		OpcUaUInt32 id;
		typeNodeId.get(id, namespaceIndex);

		return OpcUaBuildInTypeClass::isObject((OpcUaBuildInType)id);

		return true;
	}

}
