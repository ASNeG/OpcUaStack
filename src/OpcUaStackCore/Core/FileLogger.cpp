/*
   Copyright 2015 Kai Huebl (kai@huebl-sgh.de)

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
#include "OpcUaStackCore/Core/FileLogger.h"
#include <iostream>

namespace OpcUaStackCore
{

	std::string FileLogger::logFileName_ = "trace.log";

	FileLogger::FileLogger(void)
	: isOpen_(false)
	, ofStream_()
	{
	}

	FileLogger::~FileLogger(void)
	{
		closeLogFile();
	}

	void
	FileLogger::logFileName(const std::string logFileName)
	{
		logFileName_ = logFileName;
	}

	std::string
	FileLogger::logFileName(void)
	{
		return logFileName_;
	}

	bool
	FileLogger::openLogFile(void)
	{
		ofStream_.open(logFileName(), std::ios::out);
		if (ofStream_) isOpen_ = true;
		return isOpen_ == true;
	}

	bool
	FileLogger::closeLogFile(void)
	{
		if (isOpen_) ofStream_.close();
		isOpen_ = false;
		return true;
	}

	bool 
	FileLogger::logout(LogLevel logLevel, const std::string& message)
	{
		if (!isOpen_) openLogFile();
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

		if (isOpen_) {
			ofStream_ << now << " " << logLevelString << " " << message << std::endl;
		}
		else {
			std::cout << now << " " << logLevelString << " " << message << std::endl;
		}

		return true;
	}

}
