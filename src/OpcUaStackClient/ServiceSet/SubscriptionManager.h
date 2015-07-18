#ifndef __OpcUaClientStack_SubscriptionManager_h__
#define __OpcUaClientStack_SubscriptionManager_h__

#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/Base/IOService.h"
#include "OpcUaStackCore/Component/Component.h"
#include "OpcUaStackClient/ServiceSet/Subscription.h"

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

		void componentSession(Component* componentSession);

		Subscription::SPtr getNewSubscription(void);
		void deleteSubscription(const Subscription::SPtr& subscription);

	  private:
		Component* componentSession_;
	};

}

#endif
