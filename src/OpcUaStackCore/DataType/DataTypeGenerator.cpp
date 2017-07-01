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
#include "OpcUaStackCore/DataType/DataTypeGenerator.h"
#include "OpcUaStackCore/Base/Log.h"

namespace OpcUaStackCore
{

	DataTypeGenerator::DataTypeGenerator(void)
	: projectName_("OpcUaStackCore")
	, projectDirectory_("StandardDataTypes")
	, dataTypeDefinition_()
	, superTypeDataTypeDefinition_()
	, sourceFileContent_("")
	, headerFileContent_("")
	{
	}

	DataTypeGenerator::~DataTypeGenerator(void)
	{
	}

	void
	DataTypeGenerator::projectName(const std::string& projectName)
	{
		projectName_ = projectName;
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
		return sourceFileContent_;
	}

	std::string&
	DataTypeGenerator::headerFileContent(void)
	{
		return headerFileContent_;
	}

	bool
	DataTypeGenerator::generate(void)
	{
		// FIXME: todo
		return true;
	}

}
