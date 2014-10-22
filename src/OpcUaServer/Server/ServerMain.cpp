#include "OpcUaServer/Server/Server.h"
#include <iostream>

int main(int argc, char* argv)
{
	if (argc != 2) {
		std::cout << "OpcUaServer <ConfigurationFile>" << std::endl;
		return 1;
	}

	std::string configurationFile(argv);
	OpcUaServer::Server server;
	server.startup(configurationFile);

	return 0;
}