#include "OpcUaServer/Server/Server.h"
#include <iostream>

int main(int argc, char** argv)
{
	if (argc != 2) {
		std::cout << "OpcUaServer <ConfigurationFile>" << std::endl;
		return 1;
	}

	std::string configurationFile(argv[1]);
	OpcUaServer::Server server;
	if (!server.initial(configurationFile)) return 1;
	if (!server.start()) return 1;
	server.cleanup();

	return 0;
}