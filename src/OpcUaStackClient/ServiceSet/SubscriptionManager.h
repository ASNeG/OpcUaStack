#ifndef __OpcUaStackClient_SubscriptionManager_h__
#define __OpcUaStackClient_SubscriptionManager_h__

#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackClient/ServiceSet/SubscriptionService.h"

namespace OpcUaStackClient
{

	class DLLEXPORT SubscriptionManager
	: public SubscriptionService
	, public SubscriptionServiceIf
	, public SubscriptionServicePublishIf
	{
	  public:
		SubscriptionManager(void);
		virtual ~SubscriptionManager(void);

		void publishCount(uint32_t publishCount);
		uint32_t publishCount(void);

		//- SubscriptionService -----------------------------------------------
		virtual void subscriptionServiceIf(SubscriptionServiceIf* subscriptionServiceIf);
		//- SubscriptionService -----------------------------------------------

		//- SubscriptionServiceIf ---------------------------------------------
	    virtual void subscriptionServiceCreateSubscriptionResponse(ServiceTransactionCreateSubscription::SPtr serviceTransactionCreateSubscription);
	    virtual void subscriptionServiceModifySubscriptionResponse(ServiceTransactionModifySubscription::SPtr serviceTransactionModifySubscription);
	    virtual void subscriptionServiceTransferSubscriptionsResponse(ServiceTransactionTransferSubscriptions::SPtr serviceTransactionTransferSubscriptions);
	    virtual void subscriptionServiceDeleteSubscriptionsResponse(ServiceTransactionDeleteSubscriptions::SPtr serviceTransactionDeleteSubscriptions);
	    //- SubscriptionServiceIf ---------------------------------------------

	    //- SubscriptionServicePublish ----------------------------------------
	    virtual void subscriptionServiceSetPublishingModeResponse(ServiceTransactionSetPublishingMode::SPtr serviceTransactionSetPublishingMode);
	    virtual void subscriptionServicePublishResponse(ServiceTransactionPublish::SPtr serviceTransactionPublish);
	    virtual void subscriptionServiceRepublishResponse(ServiceTransactionRepublish::SPtr serviceTransactionRepublish);
		//- SubscriptionServicePublishIf --------------------------------------

	  private:
	    void createSubscription(uint32_t subscriptionId);
	    void deleteSubscription(uint32_t subscriptionId);

	    uint32_t publishCount_;
	    uint32_t actPublishCount_;
	    typedef std::set<uint32_t> SubscriptionSet;
	    SubscriptionSet subscriptionSet_;
	    SubscriptionServiceIf* subscriptionServiceIf_;
	};

}

#endif
