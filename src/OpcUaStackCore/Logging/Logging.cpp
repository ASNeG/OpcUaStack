/*
   Copyright 2019 Kai Huebl (kai@huebl-sgh.de)

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

#include <OpcUaStackCore/Logging/Logging.h>
#include "OpcUaStackCore/Logging/FileLogger.h"
#include "OpcUaStackCore/Logging/StdoutLogger.h"
#include "OpcUaStackCore/Logging/StderrLogger.h"

namespace OpcUaStackCore
{

	std::string Logging::defaultLogFile_ = "OpcUaServer.log";

	Logging::Logging(void)
	{
	}

	Logging::~Logging(void)
	{
	}

	void
	Logging::defaultLogFile(const std::string& defaultLogFile)
	{
		defaultLogFile_ = defaultLogFile;
	}

	LogIf*
	Logging::startupLogging(
		OpcUaStackCore::Config* config,
		const std::string& prefix
	)
	{
		assert(config != nullptr);

		// handle file logger configuration if exist
		auto fileLogger = config->getChild(prefix + std::string(".FileLogger"));
		if (fileLogger) {
			auto logIfFileLogger = startupFileLogger(fileLogger);
			if (logIfFileLogger != nullptr) return logIfFileLogger;
		}

		// handle stdout logger if exist
		auto stdoutLogger = config->getChild(prefix + std::string(".StdoutLogger"));
		if (stdoutLogger) {
			auto logIfStdoutLogger = startupStdoutLogger(stdoutLogger);
			if (logIfStdoutLogger != nullptr) return logIfStdoutLogger;
		}

		// handle stderr logger if exist
		auto stderrLogger = config->getChild(prefix + std::string(".StderrLogger"));
		if (stderrLogger) {
			auto logIfSterrLogger = startupStderrLogger(stdoutLogger);
			if (logIfSterrLogger != nullptr) return logIfSterrLogger;
		}

		// use default file logger
		auto defaultLogger = new FileLogger();
		defaultLogger->logFileName(defaultLogFile_);
		return defaultLogger;
	}

	LogIf*
	Logging::startupFileLogger(
		boost::optional<Config>& config
	)
	{
		FileLogger* fileLogger = new FileLogger();

		// read log file name
		std::string logFileName;
		config->getConfigParameter("LogFileName", logFileName, "");
		if (logFileName == "") logFileName = defaultLogFile_;
		fileLogger->logFileName(logFileName);

		// read max log file number
		uint32_t maxLogFileNumber;
		config->getConfigParameter("MaxLogFileNumber", maxLogFileNumber, "20");
		fileLogger->maxLogFileNumber(maxLogFileNumber);

		// read max log file size
		uint32_t maxLogFileSize;
		config->getConfigParameter("MaxLogFileSize", maxLogFileSize, "5000000");
		fileLogger->maxLogFileSize(maxLogFileSize);

		// read log level
		LogLevel logLevel;
		std::string logLevelString;
		config->getConfigParameter("LogLevel", logLevelString, "Trace");
		if (logLevelString == "Error") logLevel = Error;
		else if (logLevelString == "Warning") logLevel = Warning;
		else if (logLevelString == "Info") logLevel = Info;
		else if (logLevelString == "Debug") logLevel = Debug;
		else logLevel = Trace;
		fileLogger->logLevel(logLevel);

		return fileLogger;
	}

	LogIf*
	Logging::startupStderrLogger(
		boost::optional<Config>& config
	)
	{
		StderrLogger* stderrLogger = new StderrLogger();

		// read log level
		LogLevel logLevel;
		std::string logLevelString;
		config->getConfigParameter("LogLevel", logLevelString, "Trace");
		if (logLevelString == "Error") logLevel = Error;
		else if (logLevelString == "Warning") logLevel = Warning;
		else if (logLevelString == "Info") logLevel = Info;
		else if (logLevelString == "Debug") logLevel = Debug;
		else logLevel = Trace;
		stderrLogger->logLevel(logLevel);

		return stderrLogger;
	}

	LogIf*
	Logging::startupStdoutLogger(
		boost::optional<Config>& config
	)
	{
		StdoutLogger* stdoutLogger = new StdoutLogger();

		// read log level
		LogLevel logLevel;
		std::string logLevelString;
		config->getConfigParameter("LogLevel", logLevelString, "Trace");
		if (logLevelString == "Error") logLevel = Error;
		else if (logLevelString == "Warning") logLevel = Warning;
		else if (logLevelString == "Info") logLevel = Info;
		else if (logLevelString == "Debug") logLevel = Debug;
		else logLevel = Trace;
		stdoutLogger->logLevel(logLevel);

		return stdoutLogger;
	}

	void
	Logging::shutdownLogging(
		LogIf* logIf
	)
	{
		if (logIf != nullptr) {
		    delete logIf;
		}
	}

}
