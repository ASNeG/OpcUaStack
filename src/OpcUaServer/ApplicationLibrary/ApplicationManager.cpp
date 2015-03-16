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
				.parameter("ParameterPath", "OpcUaServer.Application.ApplicationLibrary");
			return true;
		}

		std::vector<Config>::iterator it;
		for (it = applicationVec.begin(); it != applicationVec.end(); it++) {
			std::cout << "Library=" << it->getValue("ApplicationLibrary") << std::endl;
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

}
