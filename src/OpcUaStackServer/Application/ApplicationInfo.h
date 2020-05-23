/*
   Copyright 2016-2020 Kai Huebl (kai@huebl-sgh.de)

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

#ifndef __OpcUaStackServer_ApplicationInfo_h__
#define __OpcUaStackServer_ApplicationInfo_h__

#include <string>
#include <stdint.h>
#include "OpcUaStackCore/Base/os.h"

namespace OpcUaStackServer
{

	class DLLEXPORT ApplicationInfo
	{
	  public:
		ApplicationInfo(void);
		virtual ~ApplicationInfo(void);

		void applicationName(const std::string& applicationName);
		std::string applicationName(void);
		void libraryName(const std::string& libraryName);
		std::string libraryName(void);
		void configFileName(const std::string& configFileName);
		std::string configFileName(void);
		void threadPoolName(const std::string& threadPoolName);
		std::string threadPoolName(void);
		void numberThreads(uint32_t numberThreads);
		uint32_t numberThreads(void);

		void confDir(const std::string& confDir);
		std::string confDir(void);

	  private:
		std::string applicationName_ = "";
		std::string libraryName_ = "";
		std::string configFileName_ = "";
		std::string threadPoolName_ = "ThrAppl";
		uint32_t numberThreads_ = 2;
		std::string confDir_ = "";

	};

}

#endif
