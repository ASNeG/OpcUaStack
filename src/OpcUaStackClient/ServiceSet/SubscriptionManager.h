#ifndef __OpcUaStackClient_SubscriptionManager_h__
#define __OpcUaStackClient_SubscriptionManager_h__

#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackClient/ServiceSet/SubscriptionService.h"

namespace OpcUaStackClient
{

	class DLLEXPORT SubscriptionManager
	: public SubscriptionService
	, public SubscriptionServiceIf
	{
	  public:
		SubscriptionManager(void);
		virtual ~SubscriptionManager(void);

		//- SubscriptionService -----------------------------------------------
		virtual void subscriptionServiceIf(SubscriptionServiceIf* subscriptionServiceIf);
		//- SubscriptionService -----------------------------------------------

		//- SubscriptionServiceIf ---------------------------------------------
	    virtual void subscriptionServiceCreateSubscriptionResponse(ServiceTransactionCreateSubscription::SPtr serviceTransactionCreateSubscription);
	    virtual void subscriptionServiceModifySubscriptionResponse(ServiceTransactionModifySubscription::SPtr serviceTransactionModifySubscription);
	    virtual void subscriptionServiceTransferSubscriptionsResponse(ServiceTransactionTransferSubscriptions::SPtr serviceTransactionTransferSubscriptions);
	    virtual void subscriptionServiceDeleteSubscriptionsResponse(ServiceTransactionDeleteSubscriptions::SPtr serviceTransactionDeleteSubscriptions);
	    virtual void subscriptionServiceSetPublishingModeResponse(ServiceTransactionSetPublishingMode::SPtr serviceTransactionSetPublishingMode);
	    virtual void subscriptionServicePublishResponse(ServiceTransactionPublish::SPtr serviceTransactionPublish);
	    virtual void subscriptionServiceRepublishResponse(ServiceTransactionRepublish::SPtr serviceTransactionRepublish);
		//- SubscriptionServiceIf ---------------------------------------------

	  private:
	    SubscriptionServiceIf* subscriptionServiceIf_;
	};

}

#endif
