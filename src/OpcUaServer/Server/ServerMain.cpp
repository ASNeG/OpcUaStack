#include "OpcUaServer/Server/Server.h"
#include "OpcUaStackCore/Base/Config.h"
#include "OpcUaStackCore/Utility/Environment.h"
#include "BuildConfig.h"
#include <iostream>


using namespace OpcUaStackCore;

int main(int argc, char** argv)
{
	std::string configurationFile;

	if (argc == 1) {
		std::string installationPath = Environment::getInstallationPath(BIN_DIR);
		configurationFile = installationPath + std::string("/") + std::string(CONF_DIR) + std::string("/OpcUaServer.xml");
	}
	else if (argc == 2) {
		configurationFile = argv[1];
	}
	else {
		std::cout << "usage: OpcUaServer [<ConfigFile>]" << std::endl;
		return 1;
	}


	// set global config alias variables
	Config* config = Config::instance();
	config->alias("@BIN_DIR@", std::string(CONF_DIR));
	config->alias("@CONF_DIR@", std::string(CONF_DIR));
	config->alias("@LOG_DIR@", std::string(LOG_DIR));
	config->alias("@INSTALL_DIR@", std::string(INSTALL_DIR));


	// start server
	OpcUaServer::Server server;
	if (!server.initial(configurationFile)) return 1;
	if (!server.start()) return 1;
	server.cleanup();

	return 0;
}
