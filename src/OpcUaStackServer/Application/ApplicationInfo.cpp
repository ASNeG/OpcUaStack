/*
   Copyright 2016 Kai Huebl (kai@huebl-sgh.de)

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

#include "OpcUaStackServer/Application/ApplicationInfo.h"

namespace OpcUaStackServer
{

	ApplicationInfo::ApplicationInfo(void)
	{
	}

	ApplicationInfo::~ApplicationInfo(void)
	{
	}

	void
	ApplicationInfo::applicationName(const std::string& applicationName)
	{
		applicationName_ = applicationName;
	}

	std::string
	ApplicationInfo::applicationName(void)
	{
		return applicationName_;
	}

	void
	ApplicationInfo::libraryName(const std::string& libraryName)
	{
		libraryName_ = libraryName;
	}

	std::string
	ApplicationInfo::libraryName(void)
	{
		return libraryName_;
	}

	void
	ApplicationInfo::configFileName(const std::string& configFileName)
	{
		configFileName_ = configFileName;
	}

	std::string
	ApplicationInfo::configFileName(void)
	{
		return configFileName_;
	}

	void
	ApplicationInfo::threadPoolName(const std::string& threadPoolName)
	{
		threadPoolName_ = threadPoolName;
	}

	std::string
	ApplicationInfo::threadPoolName(void)
	{
		return threadPoolName_;
	}

	void
	ApplicationInfo::numberThreads(uint32_t numberThreads)
	{
		numberThreads_ = numberThreads;
	}

	uint32_t
	ApplicationInfo::numberThreads(void)
	{
		return numberThreads_;
	}

	void
	ApplicationInfo::confDir(const std::string& confDir)
	{
		confDir_ = confDir;
	}

	std::string
	ApplicationInfo::confDir(void)
	{
		return confDir_;
	}

}
