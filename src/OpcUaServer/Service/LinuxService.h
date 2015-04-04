#ifndef __OpcUaServer_LinuxService_h__
#define __OpcUaServer_LinuxService_h__

#include "OpcUaServer/Interface/ServerApplicationIf.h"

namespace OpcUaServer
{

	class LinuxService
	{
	  public:
		static LinuxService* instance_;
		static LinuxService* instance(void);

		LinuxService(void);
		virtual ~LinuxService(void);

		void usage(void);
		void main(const std::string& applicationName, unsigned int argc, char** argv);

		void serverApplicationIf(ServerApplicationIf* serverApplicationIf);

	  private:
		ServerApplicationIf* serverApplicationIf_;
	};

}

#endif
