#ifndef __OpcUaServer_Server_h__
#define __OpcUaServer_Server_h__

#include "OpcUaStackCore/Base/Config.h"
#include "OpcUaStackCore/Base/ConfigXml.h"
#include <string>

using namespace OpcUaStackCore;

namespace OpcUaServer
{

	class Server
	{
	  public:
		Server(void);
		~Server(void);

		void startup(const std::string& configurationFile);

	  private:
		bool readConfigurationFile(void);
		bool initLogging(void);

		std::string configurationFile_;
		Config* config_;

	};

}

#endif