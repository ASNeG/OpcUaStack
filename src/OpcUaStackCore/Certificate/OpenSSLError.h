/*
   Copyright 2018-2019 Kai Huebl (kai@huebl-sgh.de)

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

#ifndef __OpcUaStackCore_OpenSSLError_h__
#define __OpcUaStackCore_OpenSSLError_h__

#include <list>
#include <string>

#include "OpcUaStackCore/Base/Log.h"

namespace OpcUaStackCore
{

	class DLLEXPORT OpenSSLError
	{
	  public:
		OpenSSLError(void);
		OpenSSLError(const std::list<std::string>& errorList);
		virtual ~OpenSSLError(void);

		bool isError(void);
		void addOpenSSLError(void);
		void addError(const std::string& message);
		void addError(const std::list<std::string>& errorList);
		std::list<std::string> errorList(void);
		void log(LogLevel logLevel, const std::string& message);

	  private:
		std::list<std::string> errorList_;
	};

}

#endif
