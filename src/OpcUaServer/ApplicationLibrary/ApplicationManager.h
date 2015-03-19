#ifndef __OpcUaServer_ApplicationManager_h__
#define __OpcUaServer_ApplicationManager_h__

#include "OpcUaStackCore/Base/Config.h"
#include "OpcUaServer/ApplicationLibrary/ApplicationLibrary.h"

using namespace OpcUaStackCore;

namespace OpcUaServer
{

	class ApplicationManager
	{
	  public:
		ApplicationManager(void);
		~ApplicationManager(void);

		bool startup(void);
		bool shutdown(void);

		void config(Config& config);
		Config& config(void);
		ApplicationLibrary::Map& applicationLibraryMap(void);

	  private:
		Config* config_;
		ApplicationLibrary::Map applicationLibraryMap_;
	};

}

#endif
