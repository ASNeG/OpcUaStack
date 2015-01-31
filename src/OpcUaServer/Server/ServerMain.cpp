#include "OpcUaServer/Server/Server.h"
#include "BuildConfig.h"
#include <iostream>

int main(int argc, char** argv)
{
	std::string configurationFile;

	if (argc != 2) {
		configurationFile = std::string(CONF_DIR) + std::string("/OpcUaServer.xml");
	}
	else {
		configurationFile = argv[1];
	}

	OpcUaServer::Server server;
	if (!server.initial(configurationFile)) return 1;
	if (!server.start()) return 1;
	server.cleanup();

	return 0;
}
