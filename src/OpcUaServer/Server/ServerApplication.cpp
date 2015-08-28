#include <boost/thread.hpp>
#include <boost/filesystem.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>
#include "BuildConfig.h"
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
		installationPath_ = Environment::getInstallationPath(BIN_DIR);
		
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
				+ std::string("/") + std::string(CONF_DIR)
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
		config->alias("@BIN_DIR@", std::string(CONF_DIR));
		config->alias("@CONF_DIR@", std::string(CONF_DIR));
		config->alias("@LOG_DIR@", std::string(LOG_DIR));
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
