/*
   Copyright 2015 Kai Huebl (kai@huebl-sgh.de)

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

#include "OpcUaStackCore/Base/Log.h"
#include "OpcUaServer/ApplicationLibrary/ApplicationManager.h"

namespace OpcUaServer
{

	ApplicationManager::ApplicationManager(void)
	: applicationLibraryMap_()
	, config_(nullptr)
	{
	}

	ApplicationManager::~ApplicationManager(void)
	{
		applicationLibraryMap_.clear();
	}

	bool
	ApplicationManager::startup(void)
	{
		std::string configurationFileName = config_->getValue("Global.ConfigurationFileName", "Unknown");

		std::vector<Config> applicationVec;
		config_->getChilds("OpcUaServer.Application", applicationVec);
		if (applicationVec.size() == 0) {
			Log(Info, "no application in configuration available")
				.parameter("ConfigurationFileName", configurationFileName)
				.parameter("ParameterPath", "OpcUaServer.Application");
			return true;
		}

		std::vector<Config>::iterator it;
		for (it = applicationVec.begin(); it != applicationVec.end(); it++) {
			boost::optional<std::string> moduleName = it->getValue("ApplicationLibrary");
			if (!moduleName) {
				Log(Info, "no application library in configuration available")
					.parameter("ConfigurationFileName", configurationFileName)
					.parameter("ParameterPath", "OpcUaServer.Application.ApplicationLibrary");
				return false;
			}

			Log(Info, "load application library")
			    .parameter("ModuleName", *moduleName);

			ApplicationLibrary::SPtr applicationLibrary = ApplicationLibrary::construct();
			applicationLibrary->moduleName(*moduleName);
			if (!applicationLibrary->startup()) {
				return false;
			}

			// call startup function
			ApplicationIf* applicationIf;
			applicationIf = applicationLibrary->applicationIf();

			applicationLibraryMap_.insert(
				std::make_pair(*moduleName, applicationLibrary)
			);

		}

		return true;
	}

	bool
	ApplicationManager::shutdown(void)
	{
		return true;
	}

	void
	ApplicationManager::config(Config& config)
	{
		config_ = &config;
	}

	Config&
	ApplicationManager::config(void)
	{
		return *config_;
	}

	ApplicationLibrary::Map&
	ApplicationManager::applicationLibraryMap(void)
	{
		return applicationLibraryMap_;
	}

}
