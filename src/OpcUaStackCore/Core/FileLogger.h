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

#ifndef __OpcUaStackCore_FileLogger_h__
#define __OpcUaStackCore_Filelogger_h__

#include <boost/filesystem/fstream.hpp>
#include <boost/thread/mutex.hpp>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/Base/Log.h"

namespace OpcUaStackCore
{

	class DLLEXPORT FileLogger
	: public LogIf
	{
	  public:
		FileLogger(void);
		virtual ~FileLogger(void);

		static void logFileName(const std::string logFileName);
		static std::string logFileName(void);
		static void maxLogFileNumber(const uint32_t maxLogFileNumber);
		static uint32_t maxLogFileNumber(void);
		static void maxLogFileSize(const uint32_t maxLogFileSize);
		static uint32_t maxLogFileSize(void);
		static void logLevel(const LogLevel& logLevel);
		static LogLevel logLevel(void);

		//- LogIf -------------------------------------------------------------
		bool logout(LogLevel logLevel, const std::string& message);
		LogLevel getLogLevel(void);
		//- LogIf -------------------------------------------------------------

	  private:
		bool openLogFile(void);
		bool closeLogFile(void);
		void checkLogFile(void);
		void rotateLogFile(void);

		static boost::mutex mutex_;
		static uint32_t counter_;
		static std::string logFileName_;
		static uint32_t maxLogFileNumber_;
		static uint32_t maxLogFileSize_;
		static LogLevel logLevel_;

		bool isOpen_;
	    boost::filesystem::ofstream ofStream_;
	};

}

#endif
