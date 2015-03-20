#ifndef __OpcUaStackServer_ApplicationManager_h__
#define __OpcUaStackServer_ApplicationManager_h__

#include "OpcUaStackServer/Application/ApplicationIf.h"
#include "OpcUaStackServer/Application/Application.h"

namespace OpcUaStackServer
{

	class ApplicationManager
	{
	  public:
		ApplicationManager(void);
		~ApplicationManager(void);

		bool registerApplication(const std::string& applicationName, ApplicationIf* applicationIf);
		bool deregisterApplication(const std::string& applicationName);
		void serviceComponent(Component* serviceComponent);

		bool startup(void);
		bool shutdown(void);

	  private:
		Application::Map applicationMap_;
		Component* serviceComponent_;
	};

}

#endif
