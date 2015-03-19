#include "OpcUaStackCore/Base/Log.h"
#include "OpcUaStackServer/Application/ApplicationManager.h"

namespace OpcUaStackServer
{

	ApplicationManager::ApplicationManager(void)
	: applicationMap_()
	{
	}

	ApplicationManager::~ApplicationManager(void)
	{
	}

	bool
	ApplicationManager::registerApplication(const std::string& applicationName, ApplicationIf* applicationIf)
	{
		Application::Map::iterator it;
		it = applicationMap_.find(applicationName);
		if (it != applicationMap_.end()) {
			Log(Error, "cannot construct application, because application already exist")
			    .parameter("ApplicationName", applicationName);
			return false;
		}

		Application::SPtr application = Application::construct();
		application->applicationIf(applicationIf);
		application->applicationName(applicationName);
		applicationMap_.insert(
			std::make_pair(applicationName, application)
		);

		return true;
	}

	bool
	ApplicationManager::deregisterApplication(const std::string& applicationName)
	{
		Application::Map::iterator it;
		it = applicationMap_.find(applicationName);
		if (it == applicationMap_.end()) {
			Log(Error, "cannot destruct application, because application not excist")
				.parameter("ApplicationName", applicationName);
			return false;
		}

		applicationMap_.erase(applicationName);

		return true;
	}

	bool
	ApplicationManager::startup(void)
	{
		Application::Map::iterator it;
		for (it = applicationMap_.begin(); it !=  applicationMap_.end(); it++) {
			Application::SPtr application = it->second;
			if (!application->startup()) return false;
		}
		return true;
	}

	bool
	ApplicationManager::shutdown(void)
	{
		Application::Map::iterator it;
		for (it = applicationMap_.begin(); it !=  applicationMap_.end(); it++) {
			Application::SPtr application = it->second;
			application->shutdown();
		}
		return true;
	}

}
