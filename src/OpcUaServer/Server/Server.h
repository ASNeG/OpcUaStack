/*
   Copyright 2015-2021 Kai Huebl (kai@huebl-sgh.de)

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

#include <OpcUaServer/ApplicationLibrary/ApplicationLibraryManager.h>
#include <OpcUaStackServer/Server/OpcUaServer.h>
#include "OpcUaStackCore/Base/Config.h"
#include "OpcUaStackCore/Base/ConfigXml.h"
#include "OpcUaStackCore/Logging/FileLogger.h"
#include "OpcUaStackServer/Application/ReloadIf.h"
#include "OpcUaServer/Server/DiscoveryClient.h"
#include <string>

namespace OpcUaServer
{

	class DLLEXPORT Server 
	{
	  public:
		Server(void);
		~Server(void);

		void reloadIf(OpcUaStackServer::ReloadIf* reloadIf);
		bool startup(const std::string& configurationFile);
		bool start(void);
		void stop(void);
		void shutdown(void);

	  private:
		bool readConfigurationFile(void);
		bool initLogging(void);
		void logServerInfo(void);

		std::string configurationFile_;
		OpcUaStackCore::Config* config_;
		OpcUaStackServer::OpcUaServer opcuaServer_;
		OpcUaStackCore::FileLogger fileLogger_;

		OpcUaStackServer::ReloadIf* reloadIf_;
		DiscoveryClient::SPtr discoveryClient_;
		ApplicationLibraryManager applicationLibraryManager_;
	};

}

#endif
