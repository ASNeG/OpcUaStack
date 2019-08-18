/*
   Copyright 2015-2019 Kai Huebl (kai@huebl-sgh.de)

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
#include "OpcUaStackServer/Application/ApplicationManager.h"

using namespace OpcUaStackCore;

namespace OpcUaStackServer
{

	ApplicationManager::ApplicationManager(void) 
	: applicationMap_()
	, serviceComponent_(nullptr)
	{
	}

	ApplicationManager::~ApplicationManager(void)
	{
	}

	void
	ApplicationManager::cryptoManager(CryptoManager::SPtr& cryptoManager)
	{
		cryptoManager_ = cryptoManager;
	}

	bool 
	ApplicationManager::registerApplication(
		const std::string& applicationName,
		ApplicationIf* applicationIf,
		ReloadIf* reloadIf
	)
	{
		Application::Map::iterator it;
		it = applicationMap_.find(applicationName);
		if (it != applicationMap_.end()) {
			Log(Error, "cannot construct application, because application already exist")
			    .parameter("ApplicationName", applicationName);
			return false;
		}

		Application::SPtr application = constructSPtr<Application>();
		application->applicationIf(applicationIf);
		application->reloadIf(reloadIf);
		application->applicationName(applicationName);
		application->serviceComponent(serviceComponent_);
		application->applicationIf()->cryptoManager(cryptoManager_);
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

	void
	ApplicationManager::serviceComponent(Component* serviceComponent)
	{
		serviceComponent_ = serviceComponent;
	}

	bool
	ApplicationManager::startup(void)
	{
		Application::Map::iterator it;
		for (it = applicationMap_.begin(); it !=  applicationMap_.end(); it++) {
			Application::SPtr application = it->second;
			application->serviceComponent(serviceComponent_);
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
