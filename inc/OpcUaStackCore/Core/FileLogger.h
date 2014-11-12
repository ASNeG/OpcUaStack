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
		~FileLogger(void);

		//- LogIf -------------------------------------------------------------
		bool logout(LogLevel logLevel, const std::string& message);
		//- LogIf -------------------------------------------------------------

	  private:
		bool isOpen_;
	    boost::filesystem::ofstream ofStream_;
	};

}

#endif