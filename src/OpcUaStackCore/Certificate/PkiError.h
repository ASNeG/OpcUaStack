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

#ifndef __OpcUaStackCore_PkiError_h__
#define __OpcUaStackCore_PkiError_h__

#include <list>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/Base/Log.h"


namespace OpcUaStackCore
{

	class DLLEXPORT PkiError
	{
	  public:
		PkiError(void);
		~PkiError(void);

		void openSSLError(void);
		void openSSLError(const std::string& message);
		void getError(std::list<std::string>& errorList);
		void logError(LogLevel logLevel, const std::string& logMessage);

	  private:
		std::list<std::string> errorList_;
	};

}

#endif
