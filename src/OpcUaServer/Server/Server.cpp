#include "OpcUaServer/Server/Server.h"
#include "OpcUaStackCore/Utility/Environment.h"
#include <iostream>

using namespace OpcUaStackCore;

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

	bool
	Server::initial(const std::string& configurationFile)
	{
		configurationFile_ = Environment::getAbsolutePath(configurationFile);

		// read configuration file
		if (!readConfigurationFile()) {
			return false;
		}

		// intial logging
		if (!initLogging()) {
			return false;
		}

		return false;
	}

	bool
	Server::start(void)
	{
		return true;
	}

	void
	Server::stop(void)
	{
	}

	void 
	Server::cleanup(void)
	{
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