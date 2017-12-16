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
#include <boost/filesystem.hpp>
#include "OpcUaStackCore/Core/FileLogger.h"
#include <iostream>

namespace OpcUaStackCore
{

	uint32_t FileLogger::counter_ = 0;
	std::string FileLogger::logFileName_ = "trace.log";
	uint32_t FileLogger::maxLogFileNumber_ = 5;
	uint32_t FileLogger::maxLogFileSize_ = 5000000;
	LogLevel FileLogger::logLevel_ = Trace;
	boost::mutex FileLogger::mutex_;

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

	void
	FileLogger::maxLogFileNumber(const uint32_t maxLogFileNumber)
	{
		maxLogFileNumber_ = maxLogFileNumber;
	}

	uint32_t
	FileLogger::maxLogFileNumber(void)
	{
		return maxLogFileNumber_;
	}

	void
	FileLogger::maxLogFileSize(const uint32_t maxLogFileSize)
	{
		maxLogFileSize_ = maxLogFileSize;
	}

	uint32_t
	FileLogger::maxLogFileSize(void)
	{
		return maxLogFileSize_;
	}

	void
	FileLogger::logLevel(const LogLevel& logLevel)
	{
		logLevel_ = logLevel;
	}

	LogLevel
	FileLogger::logLevel(void)
	{
		return logLevel_;
	}

	bool
	FileLogger::openLogFile(void)
	{
		if (boost::filesystem::exists(boost::filesystem::path(logFileName()))) {
			boost::filesystem::path logFile(logFileName());
			uint32_t logFileSize = (uint32_t)boost::filesystem::file_size(logFile);

			if (logFileSize != 0 ) rotateLogFile();
		}

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

	void
	FileLogger::checkLogFile(void)
	{
		boost::filesystem::path logFile(logFileName());
		uint32_t logFileSize = (uint32_t)boost::filesystem::file_size(logFile);
		if (logFileSize < maxLogFileSize_) return;

		// close log file
		closeLogFile();

		// rotate old log files
		rotateLogFile();

		openLogFile();
	}

	void
	FileLogger::rotateLogFile(void)
	{
		boost::filesystem::path logFile(logFileName());

		// remove oldest log file if necessary
		std::stringstream oldestLogFileName;
		oldestLogFileName << logFileName() << maxLogFileNumber_;
		boost::filesystem::remove(boost::filesystem::path(oldestLogFileName.str()));

		for (uint32_t idx = maxLogFileNumber_- 1; idx > 0; idx--) {
			std::stringstream srcLogFileName;
			std::stringstream dstLogFileName;

			srcLogFileName << logFileName() << idx;
			dstLogFileName << logFileName() << idx+1;

			if (boost::filesystem::exists(boost::filesystem::path(srcLogFileName.str()))) {
				boost::filesystem::rename(
					boost::filesystem::path(srcLogFileName.str()),
					boost::filesystem::path(dstLogFileName.str())
				);
			}
		}

		std::stringstream srcLogFileName;
		std::stringstream dstLogFileName;

		srcLogFileName << logFileName();
		dstLogFileName << logFileName() << "1";

		if (boost::filesystem::exists(boost::filesystem::path(srcLogFileName.str()))) {
			boost::filesystem::rename(
				boost::filesystem::path(srcLogFileName.str()),
				boost::filesystem::path(dstLogFileName.str())
			);
		}
	}

	bool 
	FileLogger::logout(LogLevel logLevel, const std::string& message)
	{
		boost::mutex::scoped_lock g(mutex_);

		if (!isOpen_) openLogFile();
		boost::posix_time::ptime now = boost::posix_time::microsec_clock::local_time();
		std::string logLevelString = "Unknown"; 

		counter_++;
		if (counter_ > 500) {
			counter_ = 0;
			checkLogFile();
		}

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

	LogLevel
	FileLogger::getLogLevel(void)
	{
		return logLevel();
	}

}
