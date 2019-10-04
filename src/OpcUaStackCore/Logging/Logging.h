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

#ifndef __OpcUaStackCore_Logging_h__
#define __OpcUaStackCore_Logging_h__

#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/Base/Config.h"
#include "OpcUaStackCore/Base/Log.h"

namespace OpcUaStackCore
{

	class DLLEXPORT Logging
	{
	  public:
		Logging(void);
		virtual ~Logging(void);

		static LogIf* startupLogging(
			OpcUaStackCore::Config* config,
			const std::string& prefix
		);

		static void shutdownLogging(
			LogIf* logIf
		);

	  private:
		static LogIf* startupFileLogger(
			boost::optional<Config>& config
		);

		static LogIf* startupStderrLogger(
			boost::optional<Config>& config
		);

		static LogIf* startupStdoutLogger(
			boost::optional<Config>& config
		);
	};

}

#endif
