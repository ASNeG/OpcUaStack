/*
   Copyright 2015-2021 Kai Huebl (kai@huebl-sgh.de)

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

#include <boost/thread.hpp>
#include <boost/filesystem.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>
#include <OpcUaServer/Server/ServerLoop.h>
#include "OpcUaStackCore/Base/Config.h"
#include "OpcUaStackCore/Base/Log.h"
#include "OpcUaStackCore/Utility/Environment.h"

using namespace OpcUaStackCore;
using namespace OpcUaStackServer;

namespace OpcUaServer
{

	ServerLoop::ServerLoop(void)
	: ServerLoopIf()
	, running_(false)
	, reload_(false)
	, serviceName_("")
	, server_()
	, configFileName_("")
	, stopSignal_(false)
	, mutex_()
	{
	}

	ServerLoop::~ServerLoop(void)
	{
	}

	void 
	ServerLoop::serviceCommandLine(const std::string& configFileName, unsigned int argc, char** argv)
	{
		configFileName_ = boost::filesystem::absolute(configFileName).string();
		std::string configFilePath = boost::filesystem::path(configFileName_).parent_path().string();
		Environment::confDir(configFilePath);
	}

	bool 
	ServerLoop::startup(void)
	{
		// set global config alias variables
		Config* config = Config::instance();
		config->alias("@CONF_DIR@", Environment::confDir());
		config->alias("@HOSTNAME@", Environment::hostname());
		return true;
	}

	bool 
	ServerLoop::shutdown(void)
	{
		//
		// Shutdown all application server components
		//

		return true;
	}

	bool 
	ServerLoop::loop(void)
	{
		// startup application
		server_.reloadIf(this);

		Log(Debug, "startup server");
		if (!server_.startup(configFileName_)) return false;

		Log(Debug, "start server");
		if (!server_.start()) return false;
		
		// application loop
		bool stopFlag = false;
		{
			boost::mutex::scoped_lock g(mutex_);
			running_ = true;
			if (stopSignal_) {
				stopSignal_ = false;
				stopFlag = true;
			}
		}

		Log(Debug, "service application loop");
		if (stopFlag) {
			stopLoop();
		}
		while (running_) {

			// The reload flag ist set. We want to restart the server
			if (reload_) {
				processReload();
				reload_ = false;
			}
			boost::this_thread::sleep(boost::posix_time::seconds(1));
		}

		// stop server
		Log(Debug, "stop server");
		server_.stop();

		// shutdown server
		Log(Debug, "shutdown server");
		server_.shutdown();

		return true;
	}

	void 
	ServerLoop::stopLoop(void)
	{
		//
		// Receive stop signal to stop all application server components.
		//

		// check if application is starting
		{
			boost::mutex::scoped_lock g(mutex_);
			if (stopSignal_) {
				Log(Debug, "service application stop - ignore");
				return;
			}
			stopSignal_ = true;
			if (!running_) {
				Log(Debug, "service application stop - ignore");
				return;
			}
		}

		running_ = false;
	}

	void
	ServerLoop::reload(void)
	{
		// We want to restart the server. For this we have to set the reload flag.
		// The main loop will check the reload flag.
		Log(Debug, "reload application server");
		reload_ = true;
	}

	void
	ServerLoop::processReload(void)
	{
		// shutdown server
		Log(Debug, "stop server");
		server_.stop();
		Log(Debug, "shutdown server");
		server_.shutdown();
		Config::destroy();
		Log(Debug, "shutdown application server complete");

		boost::this_thread::sleep(boost::posix_time::seconds(5));

		// startup server
		Log(Debug, "startup application server");
		startup();
		Log(Debug, "startup server");
		server_.startup(configFileName_);
		Log(Debug, "start server");
		server_.start();
	}

}
