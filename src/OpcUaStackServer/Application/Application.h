#ifndef __OpcUaStackServer_Application_h__
#define __OpcUaStackServer_Application_h__

#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackServer/Application/ApplicationBase.h"

namespace OpcUaStackServer
{

	class DLLEXPORT Application
	: public ApplicationBase
	, public ObjectPool<ApplicationBase>
	{
	  public:
		typedef boost::shared_ptr<Application> SPtr;

		Application(void);
		~Application(void);

		//- Component -----------------------------------------------------------------
		void receive(Message::SPtr message);
		//- Component -----------------------------------------------------------------

	  private:
	};

}

#endif
