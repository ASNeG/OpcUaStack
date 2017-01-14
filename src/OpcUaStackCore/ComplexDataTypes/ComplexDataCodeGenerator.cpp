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
	: content_()
	, classTemplateFileHeader_("")
	, classTemplateFileSource_("")
	, namespaceName_("OpcUaStackCore")
	, values_("")
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

	std::string&
	ComplexDataCodeGenerator::content(void)
	{
		return content_;
	}

	bool
	ComplexDataCodeGenerator::generate(ComplexDataType& complexDataType)
	{
		// read class template file
		if (!readClassTemplateFile()) {
			return false;
		}

		// subst namespace name
		if (!substNamespaceName()) {
			return false;
		}

		// subst class name
		if (!substClassName(complexDataType.name())) {
			return false;
		}

		// subst class values
		uint32_t size = complexDataType.size();
		for (uint32_t idx=0; idx<size; idx++) {
			ComplexDataTypeItem::SPtr item = complexDataType.complexDataTypeItem(idx);

			std::string valueName = item->itemName();
			valueName[0] = std::tolower	(valueName[0]);
			values_ += "            ";
			values_ +=  OpcUaBuildInTypeMap::buildInType2CPPType(item->itemType()) + " " + valueName + "_;";
			values_ += "\n";
		}
		if (!substValues()) {
			return false;
		}

		return true;
	}

	bool
	ComplexDataCodeGenerator::readClassTemplateFile(void)
	{
		boost::filesystem::ifstream in;
		in.open(classTemplateFileHeader_, std::ios::in);

		if (!in) {
			Log(Error, "read class template file error")
				.parameter("FileName", classTemplateFileHeader_);
			return false;
		}

		std::stringstream ss;
		ss << in.rdbuf();
		content_ = ss.str();

		in.close();
		return true;
	}

	bool
	ComplexDataCodeGenerator::substNamespaceName(void)
	{
		boost::regex regNamespaceName("@NamespaceName@");
		content_ = boost::regex_replace(content_, regNamespaceName, namespaceName_);
		return true;
	}

	bool
	ComplexDataCodeGenerator::substClassName(const std::string& className)
	{
		boost::regex regClassName("@ClassName@");
		content_ = boost::regex_replace(content_, regClassName, className);

		std::string lowerClassName = className;
		lowerClassName[0] = std::tolower	(lowerClassName[0]);
		boost::regex regclassName("@className@");
		content_ = boost::regex_replace(content_, regclassName, lowerClassName);

		return true;
	}

	bool
	ComplexDataCodeGenerator::substValues(void)
	{
		boost::regex regValues("@Values@");
		content_ = boost::regex_replace(content_, regValues, values_);
		return true;
	}

}


