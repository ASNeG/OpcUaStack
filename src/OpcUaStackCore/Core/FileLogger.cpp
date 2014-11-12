#include "OpcUaStackCore/Core/FileLogger.h"

namespace OpcUaStackCore
{

	FileLogger::FileLogger(void)
	: isOpen_(false)
	{
		ofStream_.open("trace.log", std::ios::out);
		if (ofStream_) isOpen_ = true;  
	}

	FileLogger::~FileLogger(void)
	{
		if (isOpen_) ofStream_.close();
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