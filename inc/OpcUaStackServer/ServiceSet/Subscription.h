#ifndef __OpcUaStackServer_Subscription_h__
#define __OpcUaStackServer_Subscription_h__

#include <boost/thread/mutex.hpp>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/Base/ObjectPool.h"
#include <map>

using namespace OpcUaStackCore;

namespace OpcUaStackServer
{

	class DLLEXPORT Subscription : public ObjectPool<Subscription>
	{
	  public:
		Subscription(void);
		~Subscription(void);

		uint32_t subscriptionId(void);

	  private:

		static uint32_t uniqueSubscriptionId(void);
		static boost::mutex mutex_;
		static uint32_t uniqueSubscriptionId_;

		uint32_t subscriptionId_;
	};

	typedef std::map<uint32_t, Subscription::SPtr> SubscriptionMap;
}

#endif