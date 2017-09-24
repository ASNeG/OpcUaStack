/*
   Copyright 2015-2017 Kai Huebl (kai@huebl-sgh.de)

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
#include "OpcUaServer/Server/ServerApplication.h"
#include "OpcUaStackCore/Base/Config.h"
#include "OpcUaStackCore/Utility/Environment.h"

using namespace OpcUaStackCore;

namespace OpcUaServer
{

	ServerApplication::ServerApplication(void)
	: ServerApplicationIf()
	, running_(false)
	, restart_(false)
	, serviceName_("")
	, server_()
	, configFileName_("")
	{
	}

	ServerApplication::~ServerApplication(void)
	{
	}

	void 
	ServerApplication::serviceCommandLine(const std::string& configFileName, unsigned int argc, char** argv)
	{
		configFileName_ = boost::filesystem::absolute(configFileName).string();
		std::string configFilePath = boost::filesystem::path(configFileName_).parent_path().string();
		Environment::confDir(configFilePath);
	}

	bool 
	ServerApplication::startup(void)
	{
		// set global config alias variables
		Config* config = Config::instance();
		config->alias("@CONF_DIR@", Environment::confDir());
		return true;
	}

	bool 
	ServerApplication::shutdown(void)
	{

		return true;
	}

	bool 
	ServerApplication::run(void)
	{
		server_.restartIf(this);
		if (!server_.startup(configFileName_)) return false;
		if (!server_.start()) return false;
		
		running_ = true;
		while (running_) {
			if (restart_) {
				processRestart();
				restart_ = false;
			}
			boost::this_thread::sleep(boost::posix_time::seconds(1));
		}
		server_.shutdown();
		return true;
	}

	void 
	ServerApplication::stop(void)
	{
		server_.stop();
		running_ = false;
	}

	void
	ServerApplication::restart(void)
	{
		restart_ = true;
	}

	void
	ServerApplication::processRestart(void)
	{
		// FIXME: todo
		std::cout << "process restart..." << std::endl;
	}

}
