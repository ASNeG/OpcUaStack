#include "OpcUaServer/Server/Server.h"
#include <iostream>

namespace OpcUaServer
{

	Server::Server(void)
	: configurationFile_("")
	, config_(nullptr)
	{
	}

	Server::~Server(void)
	{
	}

	void 
	Server::startup(const std::string& configurationFile)
	{
		configurationFile_ = configurationFile;

		if (!readConfigurationFile()) {
			return;
		}

		if (!initLogging()) {
			return;
		}
	}

	bool 
	Server::readConfigurationFile(void)
	{
		config_ = Config::instance();
		ConfigXml configXml;
		if (!configXml.parse(configurationFile_, true)) {
			std::string errorMessage = configXml.errorMessage();
			std::cout << "read configuration error: " <<  errorMessage << std::endl;
			return false;
		}
		return true;
	}

	bool
	Server::initLogging(void)
	{
		return true;
	}

}