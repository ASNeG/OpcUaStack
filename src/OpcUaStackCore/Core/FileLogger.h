#ifndef __OpcUaStackCore_FileLogger_h__
#define __OpcUaStackCore_Filelogger_h__

#include <boost/filesystem/fstream.hpp>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/Base/Log.h"

namespace OpcUaStackCore
{

	class DLLEXPORT FileLogger : public LogIf
	{
	  public:
		FileLogger(void);
		virtual ~FileLogger(void);

		static void logFileName(const std::string logFileName);
		static std::string logFileName(void);

		//- LogIf -------------------------------------------------------------
		bool logout(LogLevel logLevel, const std::string& message);
		//- LogIf -------------------------------------------------------------

	  private:
		bool openLogFile(void);
		bool closeLogFile(void);
		static std::string logFileName_;

		bool isOpen_;
	    boost::filesystem::ofstream ofStream_;
	};

}

#endif
