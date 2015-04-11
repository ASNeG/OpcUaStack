#ifndef __OpcUaServer_Server_h__
#define __OpcUaServer_Server_h__

#include "OpcUaStackCore/Base/Config.h"
#include "OpcUaStackCore/Base/ConfigXml.h"
#include "OpcUaStackCore/Core/FileLogger.h"
#include "OpcUaStackServer/Server/Server.h"
#include "OpcUaServer/ApplicationLibrary/ApplicationManager.h"

#include "OpcUaServer/Raspberry/Raspberry.h"
#include <string>

using namespace OpcUaStackCore;

namespace OpcUaServer
{

	class Server 
	{
	  public:
		Server(void);
		~Server(void);

		bool startup(const std::string& configurationFile);
		bool start(void);
		void stop(void);
		void shutdown(void);
		
	  private:
		bool readConfigurationFile(void);
		bool initLogging(void);

		std::string configurationFile_;
		Config* config_;
		OpcUaStackServer::Server server_;
		FileLogger fileLogger_;

		ApplicationManager applicationManager_;
		Raspberry raspberry_;
	};

}

#endif
