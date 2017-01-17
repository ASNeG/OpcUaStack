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

#include "OpcUaStackCore/ComplexDataTypes/ComplexDataCodeGenerator.h"

namespace OpcUaStackCore
{

	ComplexDataCodeGenerator::ComplexDataCodeGenerator(void)
	: contentHeader_("")
	, contentSource_("")
	, classTemplateFileHeader_("")
	, classTemplateFileSource_("")
	, superType_("")
	, projectNamespace_("")
	, projectFolder_("")
	, projectNamespaceSuperType_("")
	, projectFolderSuperType_("")
	, values_("")
	, valuesInit_("")
	, valuesEncode_("")
	, valuesDecode_("")
	, valuesOut_("")
	, valuesCopyTo_("")
	, valuesEqual_("")
	, binaryTypeId_("unknown-type-id")
	, xmlTypeId_("unknown-type-id")
	{
	}

	ComplexDataCodeGenerator::~ComplexDataCodeGenerator(void)
	{
	}

	void
	ComplexDataCodeGenerator::classTemplateFileHeader(const std::string& classTemplateFileHeader)
	{
		classTemplateFileHeader_ = classTemplateFileHeader;
	}

	void
	ComplexDataCodeGenerator::classTemplateFileSource(const std::string& classTemplateFileSource)
	{
		classTemplateFileSource_ = classTemplateFileSource;
	}

	std::string&
	ComplexDataCodeGenerator::contentHeader(void)
	{
		return contentHeader_;
	}

	std::string&
	ComplexDataCodeGenerator::contentSource(void)
	{
		return contentSource_;
	}

	bool
	ComplexDataCodeGenerator::generate(ComplexDataType& complexDataType, ComplexDataType& complexDataTypeSuperType)
	{
		projectNamespaceSuperType_ = complexDataTypeSuperType.projectNamespace();
		projectFolderSuperType_ = complexDataTypeSuperType.projectFolder();
		return generate(complexDataType);
	}

	bool
	ComplexDataCodeGenerator::generate(ComplexDataType& complexDataType)
	{
		superType_ = complexDataType.supertype();
		projectNamespace_ = complexDataType.projectNamespace();
		projectFolder_ = complexDataType.projectFolder();

		if (projectNamespaceSuperType_ == "") {
			projectNamespaceSuperType_ = complexDataType.projectNamespace();
		}
		if (projectFolderSuperType_ == "") {
			projectFolderSuperType_ = complexDataType.projectFolder();
		}

		if (!generateHeader(complexDataType)) {
			return false;
		}

		if (!generateSource(complexDataType)) {
			return false;
		}

		return true;
	}

    bool
    ComplexDataCodeGenerator::generateHeader(ComplexDataType& complexDataType)
    {
		// read class template file
		if (!readClassTemplateFileHeader()) {
			return false;
		}

		// subst super type
		if (!substSuperType(contentHeader_)) {
			return false;
		}

		// subst namespace name
		if (!substProjectNamespace(contentHeader_)) {
			return false;
		}

		// subst class name
		if (!substClassName(contentHeader_, complexDataType.name())) {
			return false;
		}

		// subst folder
		if (!substProjectFolder(contentHeader_)) {
			return false;
		}

		// subst values
		uint32_t size = complexDataType.size();
		for (uint32_t idx=0; idx<size; idx++) {
			ComplexDataTypeItem::SPtr item = complexDataType.complexDataTypeItem(idx);

			std::string valueName = item->itemName();
			valueName[0] = std::tolower	(valueName[0]);
			values_ += "            ";
			values_ +=  OpcUaBuildInTypeMap::buildInType2CPPType(item->itemType()) + " " + valueName + "_;";
			values_ += "\n";
		}
		if (!substValues(contentHeader_)) {
			return false;
		}

		return true;
    }

    bool
    ComplexDataCodeGenerator::generateSource(ComplexDataType& complexDataType)
    {
		// read class template file
		if (!readClassTemplateFileSource()) {
			return false;
		}

		// subst namespace name
		if (!substProjectNamespace(contentSource_)) {
			return false;
		}

		// subst folder
		if (!substProjectFolder(contentSource_)) {
			return false;
		}

		// subst binary type id and xml type id
		binaryTypeId_ = complexDataType.binaryTypeId().toString();
		xmlTypeId_ = complexDataType.xmlTypeId().toString();
		if (!substTypeIds(contentSource_)) {
			return false;
		}

		// subst values
		valuesInit_ = "";
		uint32_t size = complexDataType.size();
		for (uint32_t idx=0; idx<size; idx++) {
			ComplexDataTypeItem::SPtr item = complexDataType.complexDataTypeItem(idx);
			std::string valueName = item->itemName();
			valueName[0] = std::tolower(valueName[0]);

			// values init
			valuesInit_ += "        , ";
			valuesInit_ += valueName + "_()";  // FIXME: use default value...
			valuesInit_ += "\n";

			// values encode
			valuesEncode_ += "            ";
			if (OpcUaBuildInTypeClass::isObject(item->itemType())) {
				valuesEncode_ += valueName + "_.opcUaBinaryEncode(os);";
			}
			else {
				valuesEncode_ += "OpcUaNumber::opcUaBinaryEncode(os, " + valueName + ");";
			}
			valuesEncode_ += "\n";

			// values decode
			valuesDecode_ += "            ";
			if (OpcUaBuildInTypeClass::isObject(item->itemType())) {
				valuesDecode_ += valueName + "_.opcUaBinaryDecode(is);";
			}
			else {
				valuesDecode_ += "OpcUaNumber::opcUaBinaryDecode(is, " + valueName + ");";
			}
			valuesDecode_ += "\n";

			// values out
			std::string outPrefix = ", ";
			if (idx == 0) outPrefix = "";
			valuesOut_ += "            ";
			if (OpcUaBuildInTypeClass::isObject(item->itemType())) {
				valuesOut_ += "os << \"" + outPrefix + item->itemName() + "=\"; ";
				valuesOut_ += valueName + "_.out(os);";
			}
			else {
				valuesOut_ += "os << \"" + outPrefix + item->itemName() + "=\"";
				valuesOut_ += " << " + valueName + "_;";
			}
			valuesOut_ += "\n";

			// values copy to
			valuesCopyTo_ += "            ";
			if (OpcUaBuildInTypeClass::isObject(item->itemType())) {
				valuesCopyTo_ += valueName + "_.copyTo(@className@." + valueName + "_);";
			}
			else {
				valuesCopyTo_ += "@className@." + valueName + "_ = " + valueName + "_;";
			}
			valuesCopyTo_ += "\n";

			// values equal
			valuesEqual_ += "            ";
			valuesEqual_ += "rc &= (" + valueName + "_ == ptr->" + valueName + "_);";
			valuesEqual_ += "\n";
		}

		// subst values init
		if (!substValuesInit(contentSource_)) {
			return false;
		}

		// subst values encode
		if (!substValuesEncode(contentSource_)) {
			return false;
		}

		// subst values decode
		if (!substValuesDecode(contentSource_)) {
			return false;
		}

		// subst values out
		if (!substValuesOut(contentSource_)) {
			return false;
		}

		// subst values copy to
		if (!substValuesCopyTo(contentSource_)) {
			return false;
		}

		// subst values equal
		if (!substValuesEqual(contentSource_)) {
			return false;
		}

		// subst class name
		if (!substClassName(contentSource_, complexDataType.name())) {
			return false;
		}

    	return true;
    }

	bool
	ComplexDataCodeGenerator::readClassTemplateFileHeader(void)
	{
		boost::filesystem::ifstream in;
		in.open(classTemplateFileHeader_, std::ios::in);

		if (!in) {
			Log(Error, "read header class template file error")
				.parameter("FileName", classTemplateFileHeader_);
			return false;
		}

		std::stringstream ss;
		ss << in.rdbuf();
		contentHeader_ = ss.str();

		in.close();
		return true;
	}

	bool
	ComplexDataCodeGenerator::readClassTemplateFileSource(void)
	{
		boost::filesystem::ifstream in;
		in.open(classTemplateFileSource_, std::ios::in);

		if (!in) {
			Log(Error, "read source class template file error")
				.parameter("FileName", classTemplateFileSource_);
			return false;
		}

		std::stringstream ss;
		ss << in.rdbuf();
		contentSource_ = ss.str();

		in.close();
		return true;
	}

	bool
	ComplexDataCodeGenerator::substSuperType(std::string& content)
	{
		// super type include
		std::string superTypeInclude = "";
		if (superType_ != "") {
			superTypeInclude += "#include \"@ProjectNamespaceSuperType@/@ProjectFolderSuperType@/@SuperType@.h\"";
		}

		boost::regex regSuperTypeInclude("@SuperTypeInclude@");
		content = boost::regex_replace(content, regSuperTypeInclude, superTypeInclude);

		// super type ineritance
		std::string superTypeInheritance = "";
		if (superType_ != "") {
			superTypeInheritance += "        ";
			superTypeInheritance += ": public " + superType_;
		}

		boost::regex regSuperTypeInheritance("@SuperTypeInheritance@");
		content = boost::regex_replace(content, regSuperTypeInheritance, superTypeInheritance);

		// super type
		std::string superType = "";
		if (superType_ != "") {
			superType = superType_;
		}

		boost::regex regSuperType("@SuperType@");
		content = boost::regex_replace(content, regSuperType, superType);

		// super type project namespace
		boost::regex regProjectNamespaceSuperType("@ProjectNamespaceSuperType@");
		content = boost::regex_replace(content, regProjectNamespaceSuperType, projectNamespaceSuperType_);

		// super type project folder
		boost::regex regProjectFolderSuperType("@ProjectFolderSuperType@");
		content = boost::regex_replace(content, regProjectFolderSuperType, projectFolderSuperType_);

		return true;
	}

	bool
	ComplexDataCodeGenerator::substProjectNamespace(std::string& content)
	{
		boost::regex regProjectNamespace("@ProjectNamespace@");
		content = boost::regex_replace(content, regProjectNamespace, projectNamespace_);
		return true;
	}

	bool
	ComplexDataCodeGenerator::substClassName(std::string& content, const std::string& className)
	{
		boost::regex regClassName("@ClassName@");
		content = boost::regex_replace(content, regClassName, className);

		std::string lowerClassName = className;
		lowerClassName[0] = std::tolower	(lowerClassName[0]);
		boost::regex regclassName("@className@");
		content = boost::regex_replace(content, regclassName, lowerClassName);

		return true;
	}

	bool
	ComplexDataCodeGenerator::substProjectFolder(std::string& content)
	{
		boost::regex regProjectFolder("@ProjectFolder@");
		content = boost::regex_replace(content, regProjectFolder, projectFolder_);

		return true;
	}

	bool
	ComplexDataCodeGenerator::substValues(std::string& content)
	{
		boost::regex regValues("@Values@");
		content = boost::regex_replace(content, regValues, values_);
		return true;
	}

	bool
	ComplexDataCodeGenerator::substValuesInit(std::string& content)
	{
		boost::regex regValuesInit("@ValuesInit@");
		content = boost::regex_replace(content, regValuesInit, valuesInit_);
		return true;
	}

    bool
    ComplexDataCodeGenerator::substValuesEncode(std::string& content)
	{
		boost::regex regValuesEncode("@ValuesEncode@");
		content = boost::regex_replace(content, regValuesEncode, valuesEncode_);
		return true;
	}

    bool
    ComplexDataCodeGenerator::substValuesDecode(std::string& content)
	{
		boost::regex regValuesDecode("@ValuesDecode@");
		content = boost::regex_replace(content, regValuesDecode, valuesDecode_);
		return true;
	}

    bool
    ComplexDataCodeGenerator::substValuesOut(std::string& content)
	{
		boost::regex regValuesOut("@ValuesOut@");
		content = boost::regex_replace(content, regValuesOut, valuesOut_);
		return true;
	}

    bool
    ComplexDataCodeGenerator::substValuesCopyTo(std::string& content)
	{
		boost::regex regValuesCopyTo("@ValuesCopyTo@");
		content = boost::regex_replace(content, regValuesCopyTo, valuesCopyTo_);
		return true;
	}

    bool
    ComplexDataCodeGenerator::substValuesEqual(std::string& content)
	{
		boost::regex regValuesEqual("@ValuesEqual@");
		content = boost::regex_replace(content, regValuesEqual, valuesEqual_);
		return true;
	}

	bool
	ComplexDataCodeGenerator::substTypeIds(std::string& content)
	{
		boost::regex regBinaryTypeId("@BinaryTypeId@");
		content = boost::regex_replace(content, regBinaryTypeId, binaryTypeId_);

		boost::regex regXmlTypeId("@XmlTypeId@");
		content = boost::regex_replace(content, regXmlTypeId, xmlTypeId_);

		return true;
	}



}


