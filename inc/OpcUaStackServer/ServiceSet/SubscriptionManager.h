#ifndef __OpcUaStackServer_SubscriptionManager_h__
#define __OpcUaStackServer_SubscriptionManager_h__

#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/Base/IOService.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaStatusCode.h"
#include "OpcUaStackCore/Utility/SlotTimer.h"
#include "OpcUaStackCore/ServiceSet/SubscriptionServiceTransaction.h"
#include "OpcUaStackServer/ServiceSet/Subscription.h"

#include <set>

using namespace OpcUaStackCore;

namespace OpcUaStackServer
{

	typedef std::list<ServiceTransactionPublish::SPtr> ServiceTransactionPublishList; 
	typedef std::list<uint32_t> SubscriptionIdList;

	class DLLEXPORT SubscriptionManager : public ObjectPool<SubscriptionManager>
	{
	  public:
		SubscriptionManager(void);
		~SubscriptionManager(void);

		void ioService(IOService* ioService);
		void sessionId(uint32_t sessionId);

		OpcUaStatusCode receive(ServiceTransactionCreateSubscription::SPtr trx);
		OpcUaStatusCode receive(ServiceTransactionDeleteSubscriptions::SPtr trx);
		OpcUaStatusCode receive(ServiceTransactionPublish::SPtr trx);

		uint32_t size(void);

	  private:
		void subscriptionPublishTimeout(Subscription::SPtr subscription);

		IOService* ioService_;
		SubscriptionMap subscriptionMap_;
		uint32_t sessionId_;

		ServiceTransactionPublishList serviceTransactionPublishList_;
		SubscriptionIdList subscriptionIdList_;

		double minPublishingInterval_;
		uint32_t minLifetimeCount_;
		uint32_t minMaxKeepAliveCount_;
		SlotTimer::SPtr slotTimer_;
	};

}

#endif