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

namespace OpcUaStackServer
{

	VariableTypeField::VariableTypeField(void)
	: name_("")
	, variableName_("")
	, functionName_("")
	, typeNamespaceName_("")
	, typeNodeId_("")
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
	VariableTypeField::typeNamespaceName(const std::string& typeNamespaceName)
	{
		typeNamespaceName_ = typeNamespaceName;
	}

	std::string&
	VariableTypeField::typeNamespaceName(void)
	{
		return typeNamespaceName_;
	}

	void
	VariableTypeField::typeNodeId(const OpcUaNodeId& typeNodeId)
	{
		typeNodeId_ = typeNodeId;
	}

	OpcUaNodeId&
	VariableTypeField::typeNodeId(void)
	{
		return typeNodeId_;
	}

}
