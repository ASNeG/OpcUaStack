/*
   Copyright 2019 Kai Huebl (kai@huebl-sgh.de)

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

#include <OpcUaStackServer/Generator/VariableTypeField.h>

using namespace OpcUaStackCore;

namespace OpcUaStackServer
{

	VariableTypeField::VariableTypeField(void)
	: name_("")
	, variableName_("")
	, functionName_("")
	, dataTypeNamespaceName_("")
	, dataTypeNodeId_()
	, dataTypeName_()
	, dataTypeDescription_("")
	, isArray_(false)
	{
	}

	VariableTypeField::~VariableTypeField(void)
	{
	}

	void
	VariableTypeField::name(const std::string& name)
	{
		name_ = name;
	}

	std::string&
	VariableTypeField::name(void)
	{
		return name_;
	}

	void
	VariableTypeField::variableName(const std::string& variableName)
	{
		variableName_ = variableName;
	}

	std::string&
	VariableTypeField::variableName(void)
	{
		return variableName_;
	}

	void
	VariableTypeField::functionName(const std::string& functionName)
	{
		functionName_ = functionName;
	}

	std::string&
	VariableTypeField::functionName(void)
	{
		return functionName_;
	}

	void
	VariableTypeField::dataTypeNamespaceName(const std::string& dataTypeNamespaceName)
	{
		dataTypeNamespaceName_ = dataTypeNamespaceName;
	}

	std::string&
	VariableTypeField::dataTypeNamespaceName(void)
	{
		return dataTypeNamespaceName_;
	}

	void
	VariableTypeField::dataTypeNodeId(const OpcUaNodeId& dataTypeNodeId)
	{
		dataTypeNodeId_ = dataTypeNodeId;
	}

	OpcUaNodeId&
	VariableTypeField::dataTypeNodeId(void)
	{
		return dataTypeNodeId_;
	}

	void
	VariableTypeField::dataTypeName(const std::string& dataTypeName)
	{
		dataTypeName_ = dataTypeName;
	}

	std::string&
	VariableTypeField::dataTypeName(void)
	{
		return dataTypeName_;
	}

	void
	VariableTypeField::dataTypeDescription(const std::string& dataTypeDescription)
	{
		dataTypeDescription_ = dataTypeDescription;
	}

	std::string&
	VariableTypeField::dataTypeDescription(void)
	{
		return dataTypeDescription_;
	}

	void
	VariableTypeField::isArray(bool isArray)
	{
		isArray_ = isArray;
	}

	bool
	VariableTypeField::isArray(void)
	{
		return isArray_;
	}

}
