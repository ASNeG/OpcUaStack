#ifndef __OpcUaStackClient_Subscription_h__
#define __OpcUaStackClient_Subscription_h__

#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/Base/IOService.h"
#include "OpcUaStackCore/Component/Component.h"
#include "OpcUaStackClient/ServiceSet/SubscriptionService.h"
#include "OpcUaStackClient/ServiceSet/SubscriptionIf.h"

using namespace OpcUaStackCore;

namespace OpcUaStackClient
{

	class DLLEXPORT Subscription
	: public  OpcUaStackCore::ObjectPool<Subscription>
	, SubscriptionServiceIf
	{
	  public:
		typedef boost::shared_ptr<Subscription> SPtr;

		typedef enum
		{
			S_Closed,
			S_Connecting,
			S_Connected,
			S_Closing,
			S_Reconnecting
		} State;

		Subscription(IOService& ioService);
		~Subscription(void);

		void componentSession(Component* componentSession);
		void subscriptionIf(SubscriptionIf* subscriptionIf);

		void open(void);
		void close(void);

		//- SubscriptionServiceIf ---------------------------------------------
        virtual void subscriptionServiceCreateSubscriptionResponse(ServiceTransactionCreateSubscription::SPtr serviceTransactionCreateSubscription);
        virtual void subscriptionServiceModifySubscriptionResponse(ServiceTransactionModifySubscription::SPtr serviceTransactionModifySubscription);
        virtual void subscriptionServiceTransferSubscriptionsResponse(ServiceTransactionTransferSubscriptions::SPtr serviceTransactionTransferSubscriptions);
        virtual void subscriptionServiceDeleteSubscriptionsResponse(ServiceTransactionDeleteSubscriptions::SPtr serviceTransactionDeleteSubscriptions);
        //- SubscriptionServiceIf ---------------------------------------------

	  private:
		// requested subscription parameter
		double requestedPublishingInterval_;
		uint32_t requestedLifetimeCount_;
		uint32_t requestedMaxKeepAliveCount_;
		uint32_t maxNotificationsPerPublish_;
		bool publishingEnabled_;
		uint8_t priority_;

		// revised subscription parameter
		uint32_t subscriptionId_;
		double revisedPublishingInterval_;
		uint32_t revisedLifetimeCount_;
		uint32_t revisedMaxKeepAliveCount_;

		bool reconnect_;
		State state_;
		SubscriptionService subscriptionService_;
		SubscriptionIf* subscriptionIf_;
	};

}

#endif
