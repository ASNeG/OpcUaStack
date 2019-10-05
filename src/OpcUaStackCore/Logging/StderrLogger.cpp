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
#include "OpcUaStackCore/Logging/StderrLogger.h"
#include <iostream>

namespace OpcUaStackCore
{

	LogLevel StderrLogger::logLevel_ = Trace;

	StderrLogger::StderrLogger(void)
	{
	}

	StderrLogger::~StderrLogger(void)
	{
	}

	void
	StderrLogger::logLevel(const LogLevel& logLevel)
	{
		logLevel_ = logLevel;
	}

	LogLevel
	StderrLogger::logLevel(void)
	{
		return logLevel_;
	}

	bool 
	StderrLogger::logout(LogLevel logLevel, const std::string& message)
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

		std::cerr << now << " " << logLevelString << " " << message << std::endl;

		return true;
	}

	LogLevel
	StderrLogger::getLogLevel(void)
	{
		return logLevel();
	}

}
