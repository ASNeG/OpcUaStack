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
	, serviceName_("")
	, installationPath_("")
	, server_()
	{
	}

	ServerApplication::~ServerApplication(void)
	{
	}

	void 
	ServerApplication::serviceName(const std::string& serviceName, unsigned int argc, char** argv)
	{
		serviceName_ = serviceName;
		installationPath_ = Environment::getInstallationPath(Environment::binDir());
		
		// if we are on windows the installation directory of a component can
		// differ from the installation directory of the opc ua server. In this
		// case, we must determine the installation directory of the component.
		boost::filesystem::path installDirectory(installationPath_);
		if (installDirectory.has_leaf()) {
			installDirectory.remove_leaf();
			installDirectory /= serviceName_;

			if (boost::filesystem::exists(installDirectory)) {
				installationPath_ = installDirectory.string();
			}
		}

		// determine the path of the configuration file
		if (argc == 1) {
		    configFileName_ = installationPath_
				+ std::string("/") + Environment::confDir()
				+ std::string("/") + serviceName_ 
				+ std::string("/OpcUaServer.xml");
		}
		else if (argc == 2) {
			configFileName_ = argv[1];
		}
	}

	bool 
	ServerApplication::startup(void)
	{
		// set global config alias variables
		Config* config = Config::instance();
		config->alias("@BIN_DIR@", Environment::binDir());
		config->alias("@CONF_DIR@", Environment::confDir());
		config->alias("@LOG_DIR@", Environment::logDir());
		config->alias("@INSTALL_DIR@", installationPath_);

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
		if (!server_.startup(configFileName_)) return false;
		if (!server_.start()) return false;
		
		running_ = true;
		while (running_) boost::this_thread::sleep(boost::posix_time::seconds(1));
		server_.shutdown();
		return true;
	}

	void 
	ServerApplication::stop(void)
	{
		server_.stop();
		running_ = false;
	}

}
