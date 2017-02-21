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

#include "OpcUaClient/ClientConnection/ConfigBase.h"

namespace OpcUaClient
{

	ConfigBase::ConfigBase(void)
	: elementPrefix_("")
	, configFileName_("")
	{
	}

	ConfigBase::ConfigBase(ConfigBase& cb, const std::string& additionalElementPrefix)
	: elementPrefix_(cb.elementPrefix_ + additionalElementPrefix)
	, configFileName_(cb.configFileName_)
	{
	}

	ConfigBase::~ConfigBase(void)
	{
	}

	void
	ConfigBase::elementPrefix(const std::string& elementPrefix)
	{
		elementPrefix_ = elementPrefix;
	}

	std::string&
	ConfigBase::elementPrefix(void)
	{
		return elementPrefix_;
	}

	void
	ConfigBase::configFileName(const std::string& configFileName)
	{
		configFileName_ = configFileName;
	}

	std::string&
	ConfigBase::configFileName(void)
	{
		return configFileName_;
	}

}
