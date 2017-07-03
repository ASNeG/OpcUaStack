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
	: dataTypeGeneratorIf_(nullptr)
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

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// private function
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
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

}
