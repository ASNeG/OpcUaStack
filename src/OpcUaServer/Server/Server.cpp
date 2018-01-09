/*
   Copyright 2015-2018 Kai Huebl (kai@huebl-sgh.de)

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

#include "OpcUaStackCore/Base/Log.h"
#include "OpcUaServer/Server/Server.h"
#include "OpcUaStackCore/Utility/Environment.h"
#include "BuildConfig.h"
#include <iostream>

using namespace OpcUaStackCore;

namespace OpcUaServer
{

	Server::Server(void)
	: configurationFile_("")
	, config_(nullptr)
	, server_()
	, fileLogger_()
	, applicationManager_()
	, reloadIf_(nullptr)
	{
	}

	Server::~Server(void)
	{
	}

	void
	Server::reloadIf(ReloadIf* reloadIf)
	{
		reloadIf_ = reloadIf;
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
		logServerInfo();

		// initial application library manager
		applicationManager_.config(*config_);
		if (!applicationManager_.startup()) {
			Log(Error, "shutdown server, because startup application manager error");
			return false;
		}

		// initial opc ua server
		if (!server_.init()) {
			Log(Error, "shutdown server, because init server error");
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
			bool success = server_.applicationManager().registerApplication(
				it->first,
				applicationLibrary->applicationIf(),
				reloadIf_
			);
			if (!success) return false;

			applicationLibrary->applicationIf()->config(config_);
		}
		return true;
	}

	bool
	Server::start(void)
	{
		// start opc ua server
		server_.start();

		// start discovery client
		if (!discoveryClient_.startup(*config_)) {
			return false;
		}

		// log components
		std::vector<std::string> componentNameVec;
		Component::getComponentNames(componentNameVec);
		std::vector<std::string>::iterator it;
		for (it = componentNameVec.begin(); it != componentNameVec.end(); it++) {
			Component* component = Component::getComponent(*it);
			if (component == nullptr) {
				Log(Debug, "Component")
					.parameter("Name", *it);
				continue;
			}
			else {
				component->logComponent();
			}
		}

		return true;
	}

	void
	Server::stop(void)
	{
		// shutdown discovery client
		discoveryClient_.shutdown();

		// stop opc ua server
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

		// read log file name
		std::string logFileName;
		childConfig->getConfigParameter("LogFileName", logFileName, "");
		if (logFileName == "") logFileName = "OpcUaServer.log";
		fileLogger_.logFileName(logFileName);

		// read max log file number
		uint32_t maxLogFileNumber;
		childConfig->getConfigParameter("MaxLogFileNumber", maxLogFileNumber, "20");
		fileLogger_.maxLogFileNumber(maxLogFileNumber);

		// read max log file size
		uint32_t maxLogFileSize;
		childConfig->getConfigParameter("MaxLogFileSize", maxLogFileSize, "5000000");
		fileLogger_.maxLogFileSize(maxLogFileSize);

		// read log level
		LogLevel logLevel;
		std::string logLevelString;
		childConfig->getConfigParameter("LogLevel", logLevelString, "Trace");
		if (logLevelString == "Error") logLevel = Error;
		else if (logLevelString == "Warning") logLevel = Warning;
		else if (logLevelString == "Info") logLevel = Info;
		else if (logLevelString == "Debug") logLevel = Debug;
		else logLevel = Trace;
		fileLogger_.logLevel(logLevel);

		// init logging
		OpcUaStackCore::Log::logIf(&fileLogger_);

		return true;
	}

	void
	Server::logServerInfo(void)
	{
		std::stringstream version;
		std::stringstream boostVersion;
		std::stringstream openSSLVersion;
		std::stringstream confDir;

		version        << "  OpcUaServer version      : "
			<< VERSION_MAJOR << "." << VERSION_MINOR << "." << VERSION_PATCH;
		boostVersion   << "  Boost Library version    : "
			<< BOOST_VERSION_MAJOR << "." << BOOST_VERSION_MINOR;
		openSSLVersion << "  Open SSL Library version : "
			<< OPENSSL_VERSION_MAJOR << "." << OPENSSL_VERSION_MINOR << "." << OPENSSL_VERSION_PATCH;
		confDir        << "  Config Directory         : "
			<< Environment::confDir();

		Log(Info, "Start OpcUaServer");
		Log(Info, version.str());
		Log(Info, boostVersion.str());
		Log(Info, openSSLVersion.str());
		Log(Info, confDir.str());
	}

}
