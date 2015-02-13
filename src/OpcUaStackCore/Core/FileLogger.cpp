#include "OpcUaStackCore/Core/FileLogger.h"

namespace OpcUaStackCore
{

	std::string FileLogger::logFileName_ = "trace.log";

	FileLogger::FileLogger(void)
	: isOpen_(false)
	{
		ofStream_.open(logFileName(), std::ios::out);
		if (ofStream_) isOpen_ = true;  
	}

	FileLogger::~FileLogger(void)
	{
		if (isOpen_) ofStream_.close();
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
	FileLogger::logout(LogLevel logLevel, const std::string& message)
	{
		std::string logLevelString = "Unknown"; 

		switch (logLevel)
		{
			case Error: logLevelString = "ERR"; break;
			case Warning: logLevelString = "WRN"; break;
			case Info: logLevelString = "INF"; break;
			case Debug: logLevelString = "DBG"; break;
			case Trace: logLevelString = "TRC"; break;
		}

		if (isOpen_) {
			ofStream_ << logLevelString << " " << message << std::endl;
		}
		else {
			std::cout << logLevelString << " " << message << std::endl;
		}

		return true;
	}

}
