#ifndef __OpcUaStackClient_SubscriptionService_h__
#define __OpcUaStackClient_SubscriptionService_h__

#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/Component/Component.h"
#include "OpcUaStackCore/ServiceSet/SubscriptionServiceTransaction.h"
#include "OpcUaStackClient/ServiceSet/Session.h"

using namespace OpcUaStackCore;

namespace OpcUaStackClient
{

	class DLLEXPORT SubscriptionServiceIf
	{
	  public:
		virtual ~SubscriptionServiceIf(void) {}

        virtual void subscriptionServiceCreateSubscriptionResponse(ServiceTransactionCreateSubscription::SPtr serviceTransactionCreateSubscription) {};
        virtual void subscriptionServiceModifySubscriptionResponse(ServiceTransactionModifySubscription::SPtr serviceTransactionModifySubscription) {};
        virtual void subscriptionServiceTransferSubscriptionsResponse(ServiceTransactionTransferSubscriptions::SPtr serviceTransactionTransferSubscriptions) {};
        virtual void subscriptionServiceDeleteSubscriptionsResponse(ServiceTransactionDeleteSubscriptions::SPtr serviceTransactionDeleteSubscriptions) {};
	};

	class DLLEXPORT SubscriptionService
	: public Component
	{
	  public:
		boost::shared_ptr<SubscriptionService> SPtr;

		SubscriptionService(void);
		~SubscriptionService(void);

		void componentSession(Component* componentSession);
		void subscriptionServiceIf(SubscriptionServiceIf* subscriptionServiceIf);

		void sendSync(ServiceTransactionCreateSubscription::SPtr serviceTransactionCreateSubscription);
		void send(ServiceTransactionCreateSubscription::SPtr serviceTransactionCreateSubscription);
		void sendSync(ServiceTransactionModifySubscription::SPtr serviceTransactionModifySubscription);
		void send(ServiceTransactionModifySubscription::SPtr serviceTransactionModifySubscription);
		void sendSync(ServiceTransactionTransferSubscriptions::SPtr serviceTransactionTransferSubscriptions);
		void send(ServiceTransactionTransferSubscriptions::SPtr serviceTransactionTransferSubscriptions);
		void sendSync(ServiceTransactionDeleteSubscriptions::SPtr serviceTransactionDeleteSubscriptions);
		void send(ServiceTransactionDeleteSubscriptions::SPtr serviceTransactionDeleteSubscriptions);

		//- Component -----------------------------------------------------------------
		virtual void receive(Message::SPtr message);
		//- Component -----------------------------------------------------------------

	  private:
		Component* componentSession_;

		SubscriptionServiceIf* subscriptionServiceIf_;
	};

}

#endif
