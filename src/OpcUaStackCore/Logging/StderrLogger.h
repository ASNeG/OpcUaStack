/*
   Copyright 2019 Kai Huebl (kai@huebl-sgh.de)

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

#ifndef __OpcUaStackCore_StderrLogger_h__
#define __OpcUaStackCore_StderrLogger_h__

#include <boost/thread/mutex.hpp>
#include "OpcUaStackCore/Base/Log.h"

namespace OpcUaStackCore
{

	class DLLEXPORT StderrLogger
	: public LogIf
	{
	  public:
		StderrLogger(void);
		virtual ~StderrLogger(void);

		static void logLevel(const LogLevel& logLevel);
		static LogLevel logLevel(void);

		//- LogIf -------------------------------------------------------------
		bool logout(LogLevel logLevel, const std::string& message);
		LogLevel getLogLevel(void);
		//- LogIf -------------------------------------------------------------

	  private:
		static LogLevel logLevel_;
	};

}

#endif
