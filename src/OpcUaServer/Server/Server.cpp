#include "OpcUaStackCore/Base/Log.h"
#include "OpcUaServer/Server/Server.h"
#include "OpcUaStackCore/Utility/Environment.h"
#include <iostream>

using namespace OpcUaStackCore;

namespace OpcUaServer
{

	Server::Server(void)
	: configurationFile_("")
	, config_(nullptr)
	, server_()
	, client_()
	, fileLogger_()
	, applicationManager_()
	{
	}

	Server::~Server(void)
	{
	}

	bool
	Server::startup(const std::string& configurationFile)
	{
		configurationFile_ = Environment::getAbsolutePath(configurationFile);

		// read configuration file
		if (!readConfigurationFile()) {
			Log(Error, "shutdown server, because read configuration error");
			return false;
		}

		// intial logging
		if (!initLogging()) {
			Log(Error, "shutdown server, because init log error");
			return false;
		}

		// initial opc ua server
		if (!server_.init()) {
			Log(Error, "shutdown server, because init server error");
			return false;
		}

		// initial opc ua client
		if (!client_.init()) {
			Log(Error, "shutdown server, because init client error");
			return false;
		}

		// initial application library manager
		applicationManager_.config(*config_);
		if (!applicationManager_.startup()) {
			Log(Error, "shutdown server, because startup application manager error");
			return false;
		}

		// register application libraries
		ApplicationLibrary::Map::iterator it;
		for (
			it = applicationManager_.applicationLibraryMap().begin();
			it != applicationManager_.applicationLibraryMap().end();
			it++
		) {
			ApplicationLibrary::SPtr applicationLibrary = it->second;
			server_.applicationManager().registerApplication(
				it->first,
				applicationLibrary->applicationIf()
			);

			applicationLibrary->applicationIf()->config(config_);
		}
		return true;
	}

	bool
	Server::start(void)
	{
		server_.start();
		client_.start();
		return true;
	}

	void
	Server::stop(void)
	{
		client_.stop();
		server_.stop();
	}

	void 
	Server::shutdown(void)
	{
		// deregister application libraries
		ApplicationLibrary::Map::iterator it;
		for (
			it = applicationManager_.applicationLibraryMap().begin();
			it != applicationManager_.applicationLibraryMap().end();
			it++
		) {
			ApplicationLibrary::SPtr applicationLibrary = it->second;
			server_.applicationManager().deregisterApplication(
				it->first
			);
		}

		// shutdown application library manager
		applicationManager_.shutdown();

		// shutdown opc ua client
		client_.shutdown();

		// shutdown opc ua server
		server_.shutdown();
	}

	bool 
	Server::readConfigurationFile(void)
	{
		config_ = Config::instance();
		ConfigXml configXml;
		if (!configXml.parse(configurationFile_, true)) {
			std::string errorMessage = configXml.errorMessage();
			Log(Error, "read configuration error")
				.parameter("ErrorMessage", errorMessage);
			return false;
		}

		server_.config(*config_);
		return true;
	}

	bool
	Server::initLogging(void)
	{
		boost::optional<Config> childConfig = config_->getChild("OpcUaServer.Logging.FileLogger");
		if (!childConfig) {
			fileLogger_.logFileName("OpcUaServer.log");
			OpcUaStackCore::Log::logIf(&fileLogger_);
		    return true;
		}

		std::string logFileName;
		childConfig->getConfigParameter("LogFileName", logFileName, "");
		if (logFileName == "") logFileName = "OpcUaServer.log";

		fileLogger_.logFileName(logFileName);
		OpcUaStackCore::Log::logIf(&fileLogger_);
		return true;
	}

}
