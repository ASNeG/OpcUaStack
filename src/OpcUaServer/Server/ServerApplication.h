#ifndef __OpcUaServer_ServerApplication_h__
#define __OpcUaServer_ServerApplication_h__

#include "OpcUaServer/Interface/ServerApplicationIf.h"
#include "OpcUaServer/Server/Server.h"

namespace OpcUaServer
{
	class ServerApplication
	: public ServerApplicationIf
	{
	  public:
		ServerApplication(void);
		~ServerApplication(void);

		virtual void serviceName(const std::string& serviceName, unsigned int argc, char** argv);
		virtual bool startup(void);
		virtual bool shutdown(void);
		virtual bool run(void);
		virtual void stop(void);

	  private:
		OpcUaServer::Server server_;
		std::string serviceName_;
		std::string configFileName_;
		std::string installationPath_;
		bool running_;
	};
}

#endif