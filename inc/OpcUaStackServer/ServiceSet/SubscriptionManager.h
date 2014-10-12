#ifndef __OpcUaStackServer_SubscriptionManager_h__
#define __OpcUaStackServer_SubscriptionManager_h__

#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/Base/IOService.h"
#include "OpcUaStackServer/ServiceSet/Subscription.h"
#include "OpcUaStackCore/ServiceSet/SubscriptionServiceTransaction.h"

namespace OpcUaStackServer
{

	typedef std::list<ServiceTransactionPublish::SPtr> ServiceTransactionPublishList; 

	class DLLEXPORT SubscriptionManager : public ObjectPool<SubscriptionManager>
	{
	  public:
		SubscriptionManager(void);
		~SubscriptionManager(void);

		void ioService(IOService* ioService);

		OpcUaStatusCode receive(ServiceTransactionCreateSubscription::SPtr trx);
		OpcUaStatusCode receive(ServiceTransactionDeleteSubscriptions::SPtr trx);
		OpcUaStatusCode receive(ServiceTransactionPublish::SPtr trx);

	  private:
		IOService* ioService_;
		SubscriptionMap subscriptionMap_;
		ServiceTransactionPublishList serviceTransactionPublishList_;
	};

}

#endif