/*
   Copyright 2015-2020 Kai Huebl (kai@huebl-sgh.de)

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
		auto it = applicationMap_.find(applicationName);
		if (it != applicationMap_.end()) {
			Log(Error, "cannot construct application, because application already exist")
			    .parameter("ApplicationName", applicationName);
			return false;
		}

		auto application = boost::make_shared<Application>("Application", ioThread_, messageBus_);
		application->applicationIf(applicationIf);
		application->reloadIf(reloadIf);
		application->applicationName(applicationName);
		application->applicationIf()->cryptoManager(cryptoManager_);
		applicationMap_.insert(
			std::make_pair(applicationName, application)
		);

		return true;
	}

	bool
	ApplicationManager::deregisterApplication(const std::string& applicationName)
	{
		auto it = applicationMap_.find(applicationName);
		if (it == applicationMap_.end()) {
			Log(Error, "cannot destruct application, because application not excist")
				.parameter("ApplicationName", applicationName);
			return false;
		}

		applicationMap_.erase(applicationName);

		return true;
	}

	void
	ApplicationManager::ioThread(const OpcUaStackCore::IOThread::SPtr& ioThread)
	{
		ioThread_ = ioThread;
	}

	void
	ApplicationManager::messageBus(const OpcUaStackCore::MessageBus::SPtr& messageBus)
	{
		messageBus_ = messageBus;
	}

	bool
	ApplicationManager::startup(void)
	{
		for (auto it = applicationMap_.begin(); it !=  applicationMap_.end(); it++) {
			auto application = it->second;

			// start application thread pool
			if (application->applicationIf()->applicationInfo()->numberThreads() > 0) {
				auto ioThread = boost::make_shared<IOThread>();
				ioThread->name(application->applicationIf()->applicationInfo()->threadPoolName());
				ioThread->numberThreads(application->applicationIf()->applicationInfo()->numberThreads());
				ioThread->startup();
				application->applicationIf()->applicationThreadPool(ioThread);
			}

			// startup application
			if (!application->startup()) {
				return false;
			}
		}
		return true;
	}

	bool
	ApplicationManager::shutdown(void)
	{
		for (auto it = applicationMap_.begin(); it !=  applicationMap_.end(); it++) {
			auto application = it->second;

			// shutdown application
			application->shutdown();

			// stop application thread pool
			auto ioThread = application->applicationIf()->applicationThreadPool();
			if (ioThread) {
				ioThread->shutdown();
				ioThread.reset();
			}
		}
		return true;
	}

}
