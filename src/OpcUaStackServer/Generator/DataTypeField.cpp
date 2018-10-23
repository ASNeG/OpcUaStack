/*
   Copyright 2018 Kai Huebl (kai@huebl-sgh.de)

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

#include <OpcUaStackServer/Generator/DataTypeField.h>

namespace OpcUaStackServer
{

	DataTypeField::DataTypeField(void)
	: name_("")
	, variableName_("")
	, parameterName_("")
	, variableType_("")
	, description_("")
	, array_(false)
	, smartpointer_(false)
	, number_(false)
	, boolean_(false)
	, byte_(false)
	, enumeration_(false)
	, structure_(false)
	, optional_(false)
	{
	}

	DataTypeField::~DataTypeField(void)
	{
	}

	void
	DataTypeField::name(const std::string& name)
	{
		name_ = name;
	}

	std::string&
	DataTypeField::name(void)
	{
		return name_;
	}

	void
	DataTypeField::variableName(const std::string& variableName)
	{
		variableName_ = variableName;
	}

	std::string&
	DataTypeField::variableName(void)
	{
		return variableName_;
	}

	void
	DataTypeField::parameterName(const std::string& parameterName)
	{
		parameterName_ = parameterName;
	}

	std::string&
	DataTypeField::parameterName(void)
	{
		return parameterName_;
	}

	void
	DataTypeField::variableType(const std::string& variableType)
	{
		variableType_ = variableType;
	}

	std::string&
	DataTypeField::variableType(void)
	{
		return variableType_;
	}

	void
	DataTypeField::description(const std::string& description)
	{
		description_ = description;
	}

	std::string&
	DataTypeField::description(void)
	{
		return description_;
	}

	void
	DataTypeField::array(bool array)
	{
		array_ = array;
	}

	bool
	DataTypeField::array(void)
	{
		return array_;
	}

	void
	DataTypeField::smartpointer(bool smartpointer)
	{
		smartpointer_ = smartpointer;
	}

	bool
	DataTypeField::smartpointer(void)
	{
		return smartpointer_;
	}

	void
	DataTypeField::number(bool number)
	{
		number_ = number;
	}

	bool
	DataTypeField::number(void)
	{
		return number_;
	}

	void
	DataTypeField::boolean(bool boolean)
	{
		boolean_ = boolean;
	}

	bool
	DataTypeField::boolean(void)
	{
		return boolean_;
	}

	void
	DataTypeField::byte(bool byte)
	{
		byte_ = byte;
	}

	bool
	DataTypeField::byte(void)
	{
		return byte_;
	}

	void
	DataTypeField::enumeration(bool enumeration)
	{
		enumeration_ = enumeration;
	}

	bool
	DataTypeField::enumeration(void)
	{
		return enumeration_;
	}

	void
	DataTypeField::structure(bool structure)
	{
		structure_ = structure;
	}

	bool
	DataTypeField::structure(void)
	{
		return structure_;
	}

	void
	DataTypeField::optional(bool optional)
	{
		optional_ = optional;
	}

	bool
	DataTypeField::optional(void)
	{
		return optional_;
	}

}
