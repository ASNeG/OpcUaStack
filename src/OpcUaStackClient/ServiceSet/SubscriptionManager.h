#ifndef __OpcUaStackClient_SubscriptionManager_h__
#define __OpcUaStackClient_SubscriptionManager_h__

#include <set>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackClient/ServiceSet/SubscriptionService.h"
#include "OpcUaStackClient/ServiceSet/SubscriptionManagerIf.h"

namespace OpcUaStackClient
{

	class DLLEXPORT SubscriptionManager
	: public SubscriptionService
	, public SubscriptionServicePublishIf
	{
	  public:
		SubscriptionManager(void);
		virtual ~SubscriptionManager(void);

		void publishCount(uint32_t publishCount);
		uint32_t publishCount(void);
		void subscriptionManagerIf(SubscriptionManagerIf* subscriptionManagerIf);

		//- Component -----------------------------------------------------------------
		virtual void receive(Message::SPtr message);
		//- Component -----------------------------------------------------------------

	    //- SubscriptionServicePublish ----------------------------------------
	    virtual void subscriptionServiceSetPublishingModeResponse(ServiceTransactionSetPublishingMode::SPtr serviceTransactionSetPublishingMode);
	    virtual void subscriptionServicePublishResponse(ServiceTransactionPublish::SPtr serviceTransactionPublish);
	    virtual void subscriptionServiceRepublishResponse(ServiceTransactionRepublish::SPtr serviceTransactionRepublish);
		//- SubscriptionServicePublishIf --------------------------------------

	  private:
	    void subscriptionServiceCreateSubscriptionResponse(ServiceTransactionCreateSubscription::SPtr serviceTransactionCreateSubscription);
	    void subscriptionServiceDeleteSubscriptionsResponse(ServiceTransactionDeleteSubscriptions::SPtr serviceTransactionDeleteSubscriptions);

	    void createSubscription(uint32_t subscriptionId);
	    void deleteSubscription(uint32_t subscriptionId);
	    void sendPublishRequests(void);

	    void receivePublishResponse(const PublishResponse::SPtr& publishResponse);
	    void dataChangeNotification(const ExtensibleParameter::SPtr& extensibleParameter);

	    uint32_t publishCount_;
	    uint32_t actPublishCount_;
	    typedef std::set<uint32_t> SubscriptionSet;
	    SubscriptionSet subscriptionSet_;
	    SubscriptionServiceIf* subscriptionServiceIf_;
	    SubscriptionManagerIf* subscriptionManagerIf_;
	};

}

#endif
