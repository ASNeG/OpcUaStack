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
#include "OpcUaStackCore/DataType/DataTypeGenerator.h"
#include "OpcUaStackCore/Base/Log.h"

namespace OpcUaStackCore
{

	DataTypeGenerator::DataTypeGenerator(void)
	: projectNamespace_("OpcUaStackCore")
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
			generateHeaderComments();
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
			generateSourceComments();
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

}
