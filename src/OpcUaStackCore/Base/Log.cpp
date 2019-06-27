/*
   Copyright 2015-2017 Kai Huebl (kai@huebl-sgh.de)

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

#include <boost/thread.hpp>
#include <boost/lexical_cast.hpp>
#include <iostream>
#include "OpcUaStackCore/Base/Log.h"

namespace OpcUaStackCore
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// LogHandle
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	LogHandle::LogHandle(void)
	: logHandleName_("")
	{
	}

	LogHandle::LogHandle(const std::string& logHandleName)
	: logHandleName_(logHandleName)
	{
	}

	LogHandle::~LogHandle(void)
	{
	}

	void
	LogHandle::logHandleName(const std::string& logHandleName)
	{
		logHandleName_ = logHandleName;
	}

	std::string
	LogHandle::logHandleName(void)
	{
		return logHandleName_;
	}

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// Log
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
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
	: activate_(true)
	, logLevel_(logLevel)
	, message_(message)
	, parameter_("")
	, logHandle_(nullptr)
	{
		if (logIf_ == nullptr) return;
		if (logLevel_ > logIf_->getLogLevel()) activate_ = false;
	}

	Log::~Log(void)
	{
		if (!activate_) return;
		std::string threadId = boost::lexical_cast<std::string>(boost::this_thread::get_id());

		if (logIf() != nullptr) {
			std::string message = "[" + threadId + "] " + message_;
			if (parameter_ != "") {
				message += " : " + parameter_;
			}
			if (logIf_->logout(logLevel_, message)) {
				return;
			}
		}

		std::cout << logLevel() << " [" << threadId << "] " << message_;
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
			case Trace:		return "TRC";
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
