#ifndef __OpcUaServer_ServerApplication_h__
#define __OpcUaServer_ServerApplication_h__

#include "OpcUaServer/Interface/ServerApplicationIf.h"

namespace OpcUaServer
{
	class ServerApplication
	: public ServerApplicationIf
	{
	  public:
		ServerApplication(void);
		~ServerApplication(void);

		virtual bool startup(void);
		virtual bool shutdown(void);
		virtual bool run(void);
		virtual void stop(void);

	  private:
		bool running_;
	};
}

#endif