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

#include <OpcUaStackServer/Generator/MethodTypeField.h>

namespace OpcUaStackServer
{

	MethodTypeField::MethodTypeField(void)
	: name_("")
	, variableName_("")
	, functionName_("")
	{
	}

	MethodTypeField::~MethodTypeField(void)
	{
	}

	void
	MethodTypeField::name(const std::string& name)
	{
		name_ = name;
	}

	std::string&
	MethodTypeField::name(void)
	{
		return name_;
	}

	void
	MethodTypeField::variableName(const std::string& variableName)
	{
		variableName_ = variableName;
	}

	std::string&
	MethodTypeField::variableName(void)
	{
		return variableName_;
	}

	void
	MethodTypeField::functionName(const std::string& functionName)
	{
		functionName_ = functionName;
	}

	std::string&
	MethodTypeField::functionName(void)
	{
		return functionName_;
	}

}
