/*
   Copyright 2015-2019 Kai Huebl (kai@huebl-sgh.de)

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

#ifndef __OpcUaServer_Server_h__
#define __OpcUaServer_Server_h__

#include "OpcUaStackCore/Base/Config.h"
#include "OpcUaStackCore/Base/ConfigXml.h"
#include "OpcUaStackCore/Core/FileLogger.h"
#include "OpcUaStackServer/Server/Server.h"
#include "OpcUaStackServer/Application/ReloadIf.h"
#include "OpcUaServer/Server/DiscoveryClient.h"
#include "OpcUaServer/ApplicationLibrary/ApplicationManager.h"

#include <string>

using namespace OpcUaStackCore;

namespace OpcUaServer
{

	class DLLEXPORT Server 
	{
	  public:
		Server(void);
		~Server(void);

		void reloadIf(ReloadIf* reloadIf);
		bool startup(const std::string& configurationFile);
		bool start(void);
		void stop(void);
		void shutdown(void);

	  private:
		bool readConfigurationFile(void);
		bool initLogging(void);
		void logServerInfo(void);

		std::string configurationFile_;
		Config* config_;
		OpcUaStackServer::Server server_;
		FileLogger fileLogger_;

		ReloadIf* reloadIf_;
		DiscoveryClient discoveryClient_;
		ApplicationManager applicationManager_;
	};

}

#endif
