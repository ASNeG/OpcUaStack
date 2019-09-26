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

#include <boost/date_time/posix_time/posix_time.hpp>
#include <boost/filesystem.hpp>
#include "OpcUaStackCore/Logging/StdoutLogger.h"
#include <iostream>

namespace OpcUaStackCore
{

	LogLevel StdoutLogger::logLevel_ = Trace;

	StdoutLogger::StdoutLogger(void)
	{
	}

	StdoutLogger::~StdoutLogger(void)
	{
	}

	void
	StdoutLogger::logLevel(const LogLevel& logLevel)
	{
		logLevel_ = logLevel;
	}

	LogLevel
	StdoutLogger::logLevel(void)
	{
		return logLevel_;
	}

	bool 
	StdoutLogger::logout(LogLevel logLevel, const std::string& message)
	{
		boost::posix_time::ptime now = boost::posix_time::microsec_clock::local_time();
		std::string logLevelString = "Unknown"; 

		switch (logLevel)
		{
			case Error: logLevelString = "ERR"; break;
			case Warning: logLevelString = "WRN"; break;
			case Info: logLevelString = "INF"; break;
			case Debug: logLevelString = "DBG"; break;
			case Trace: logLevelString = "TRC"; break;
			default: logLevelString = "UKN"; break;
		}

		std::cout << now << " " << logLevelString << " " << message << std::endl;

		return true;
	}

	LogLevel
	StdoutLogger::getLogLevel(void)
	{
		return logLevel();
	}

}
