#ifndef __OpcUaServer_ApplicationManager_h__
#define __OpcUaServer_ApplicationManager_h__

namespace OpcUaServer
{

	class ApplicationManager
	{
	  public:
		ApplicationManager(void);
		~ApplicationManager(void);

		bool startup(void);
		bool shutdown(void);
	};

}

#endif
