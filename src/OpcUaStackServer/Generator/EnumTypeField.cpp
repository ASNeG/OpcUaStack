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

#include <OpcUaStackServer/Generator/EnumTypeField.h>

namespace OpcUaStackServer
{

	EnumTypeField::EnumTypeField(void)
	: name_("")
	, value_(-1)
	, description_("")
	{
	}

	EnumTypeField::~EnumTypeField(void)
	{
	}

	void
	EnumTypeField::name(const std::string& name)
	{
		name_ = name;
	}

	std::string&
	EnumTypeField::name(void)
	{
		return name_;
	}

	void
	EnumTypeField::value(int32_t value)
	{
		value_ = value;
	}

	int32_t
	EnumTypeField::value(void)
	{
		return value_;
	}

	void
	EnumTypeField::description(const std::string& description)
	{
		description_ = description;
	}

	std::string&
	EnumTypeField::description(void)
	{
		return description_;
	}

}
