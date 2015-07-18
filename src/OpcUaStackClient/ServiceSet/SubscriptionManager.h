#ifndef __OpcUaClientStack_SubscriptionManager_h__
#define __OpcUaClientStack_SubscriptionManager_h__

#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/Base/IOService.h"
#include "OpcUaStackCore/Component/Component.h"

using namespace OpcUaStackCore;

namespace OpcUaStackClient
{

	class DLLEXPORT SubscriptionManager
	: public ObjectPool<SubscriptionManager>
	{
	  public:
		typedef boost::shared_ptr<SubscriptionManager> SPtr;

		SubscriptionManager(IOService& ioService);
		~SubscriptionManager(void);

		void startup(void);
		void shutdown(void);

		void componentSession(Component* componentSession);

	  private:
		Component* componentSession_;
	};

}

#endif
