#include "unittest.h"
#include <iostream>
#include "OpcUaStackCore/Base/Log.h"

using namespace OpcUaStackCore;

class MyLogger
: public LogIf
{
	bool logout(LogLevel logLevel, const std::string& message) {
		std::cout << "MyLogger - " << logLevel << " - " << message << std::endl;
		return true;
	}

	LogLevel getLogLevel(void) {
	    return LogLevel::Error;
	}
};


using namespace OpcUaStackCore;

BOOST_AUTO_TEST_SUITE(Log_t)

BOOST_AUTO_TEST_CASE(Log_)
{
	std::cout << "Log_t" << std::endl;
}

BOOST_AUTO_TEST_CASE(Log_stdout)
{
	Log(Error, "This is a message")
		.parameter("ParameterName1", "ParameterValue")
		.parameter("ParameterName2", 1234);
}

BOOST_AUTO_TEST_CASE(Log_MyLogger)
{
	MyLogger myLogger;
	Log::logIf(&myLogger);

        {
	    Log(Error, "This is a message")
	 	    .parameter("ParameterName1", "ParameterValue")
		    .parameter("ParameterName2", 1234);
        }

	Log::logIf(nullptr);
}

BOOST_AUTO_TEST_SUITE_END()
