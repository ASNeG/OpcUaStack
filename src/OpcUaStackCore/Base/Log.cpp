#include "OpcUaStackCore/Base/Log.h"
#include <iostream>

namespace OpcUaStackCore
{

	LogIf* Log::logIf_ = nullptr;
	
	void 
	Log::logIf(LogIf* logIf)
	{
		logIf_ = logIf;
	}

	LogIf*
	Log::logIf(void)
	{
		return logIf_;
	}
	
	bool 
	Log::logout(LogLevel logLevel, const std::string& message)
	{
		if (logIf_ == nullptr) return false;
		return logIf_->logout(logLevel, message);
	}

	Log::Log(LogLevel logLevel, const std::string& message)
	: logLevel_(logLevel)
	, message_(message)
	, parameter_("")
	{
	}

	Log::Log(const std::string& message)
	: logLevel_(Info)
	, message_(message)
	, parameter_()
	{
	}

	Log::~Log(void)
	{
		if (logIf() != nullptr) {
			std::string message = message;
			if (parameter_ != "") {
				message += message_ + " : " + parameter_;
			}
			if (logIf_->logout(logLevel_, message)) {
				return;
			}
		}

		std::cout << logLevel() << " " << message_;
		if  (parameter_ != "") {
			std::cout << ": " << parameter_;
		}
		std::cout << std::endl; 
	}

	std::string 
	Log::logLevel(void)
	{
		switch (logLevel_)
		{
			case Error:		return "ERR";
			case Warning:	return "WRN";
			case Info:		return "INF";
			case Debug:		return "DBG";
			default:		return "UKN";
		}
		return "";
	}

	void 
	Log::format(const std::string& parameterName, const std::string& parameterValue)
	{
		if (parameter_ != "") {
			parameter_.append(", ");
		}
		parameter_.append(parameterName);
		parameter_.append("=<");
		parameter_.append(parameterValue);
		parameter_.append(">");
	}

}