#ifndef __OpcUaStackServer_Application_h__
#define __OpcUaStackServer_Application_h__

#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/Component/Component.h"
#include "OpcUaStackServer/Application/ApplicationBase.h"

#include <map>

namespace OpcUaStackServer
{

	class DLLEXPORT Application
	: public ApplicationBase
	, public ObjectPool<Application>
	{
	  public:
		typedef boost::shared_ptr<Application> SPtr;
		typedef std::map<std::string, Application::SPtr> Map;

		typedef enum
		{
			ApplConstruct,
			ApplStartup,
			ApplShutdown
		} State;

		Application(void);
		~Application(void);

		void applicationIf(ApplicationIf* applicationIf);
		void applicationName(const std::string& applicationName);
		void serviceComponent(Component* serviceComponent);

		bool startup(void);
		bool shutdown(void);

		//- Component -----------------------------------------------------------------
		void receive(Message::SPtr message);
		//- Component -----------------------------------------------------------------

	  private:
		State state_;
		ApplicationIf* applicationIf_;
		std::string applicationName_;
		Component* serviceComponent_;
	};

}

#endif
