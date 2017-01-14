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
	, classTemplateFile_("")
	, namespaceName_("OpcUaStackCore")
	{
	}

	ComplexDataCodeGenerator::~ComplexDataCodeGenerator(void)
	{
	}

	void
	ComplexDataCodeGenerator::classTemplateFile(const std::string& classTemplateFile)
	{
		classTemplateFile_ = classTemplateFile;
	}

	void
	ComplexDataCodeGenerator::namespaceName(const std::string& namespaceName)
	{
		namespaceName_ = namespaceName;
	}

	bool
	ComplexDataCodeGenerator::generate(ComplexDataType& complexDataType)
	{
		// read class template file
		if (!readClassTemplateFile()) {
			return false;
		}

		// subst template file parameter
		uint32_t size = complexDataType.size();
		for (uint32_t idx=0; idx<size; idx++) {
			ComplexDataTypeItem::SPtr item = complexDataType.complexDataTypeItem(idx);

			// handle namespace name
			// FIXME: todo

			// handle class name
			// FIXME: todo
		}

		return true;
	}

	bool
	ComplexDataCodeGenerator::readClassTemplateFile(void)
	{
		boost::filesystem::ifstream in;
		in.open(classTemplateFile_, std::ios::in);

		if (!in) {
			Log(Error, "read class template file error")
				.parameter("FileName", classTemplateFile_);
			return false;
		}

		std::stringstream ss;
		ss << in.rdbuf();
		content_ = ss.str();

		in.close();
		return true;
	}

}


