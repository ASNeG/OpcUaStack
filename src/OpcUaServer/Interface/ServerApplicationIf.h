#ifndef __OpcUaServer_ServerApplicationIf_h__
#define __OpcUaServer_ServerApplicationIf_h__

#include <string>

namespace OpcUaServer
{

	class ServerApplicationIf
	{
	  public:
		ServerApplicationIf(void) {}
		virtual ~ServerApplicationIf(void) {}

		virtual void serviceName(const std::string& serviceName, unsigned int argc, char** argv) {}
		virtual bool startup(void) = 0;
		virtual bool shutdown(void) = 0;
		virtual bool run(void) = 0;
		virtual void stop(void) = 0;
	};

}

#endif