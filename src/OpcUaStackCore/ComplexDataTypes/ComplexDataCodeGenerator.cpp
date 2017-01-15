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
	, namespaceName_("OpcUaStackCore")
	, values_("")
	, folder_("")
	, valuesInit_("")
	, binaryTypeId_("unknown-type-id")
	, xmlTypeId_("unknown-type-id")
	, encode_("")
	, decode_("")
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

	void
	ComplexDataCodeGenerator::namespaceName(const std::string& namespaceName)
	{
		namespaceName_ = namespaceName;
	}

	void
	ComplexDataCodeGenerator::folder(const std::string& folder)
	{
		folder_ = folder;
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
	ComplexDataCodeGenerator::generate(ComplexDataType& complexDataType)
	{
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

		// subst namespace name
		if (!substNamespaceName(contentHeader_)) {
			return false;
		}

		// subst class name
		if (!substClassName(contentHeader_, complexDataType.name())) {
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
		if (!substNamespaceName(contentSource_)) {
			return false;
		}

		// subst class name
		if (!substClassName(contentSource_, complexDataType.name())) {
			return false;
		}

		// subst folder
		if (!substFolder(contentSource_)) {
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

			// values init
			std::string valueName = item->itemName();
			valueName[0] = std::tolower(valueName[0]);
			valuesInit_ += "        , ";
			valuesInit_ += valueName + "_()";  // FIXME: use default value...
			valuesInit_ += "\n";

			// encode

			// decode
		}

		// subst values init
		if (!substValuesInit(contentSource_)) {
			return false;
		}

    	// FIXME: todo
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
	ComplexDataCodeGenerator::substNamespaceName(std::string& content)
	{
		boost::regex regNamespaceName("@NamespaceName@");
		content = boost::regex_replace(content, regNamespaceName, namespaceName_);
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
	ComplexDataCodeGenerator::substFolder(std::string& content)
	{
		boost::regex regFolder("@Folder@");
		content = boost::regex_replace(content, regFolder, folder_);

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
	ComplexDataCodeGenerator::substTypeIds(std::string& content)
	{
		boost::regex regBinaryTypeId("@BinaryTypeId@");
		content = boost::regex_replace(content, regBinaryTypeId, binaryTypeId_);

		boost::regex regXmlTypeId("@XmlTypeId@");
		content = boost::regex_replace(content, regXmlTypeId, xmlTypeId_);

		return true;
	}

}


