/*
   Copyright 2015 Kai Huebl (kai@huebl-sgh.de)

   Lizenziert gemäß Apache Licence Version 2.0 (die „Lizenz“); Nutzung dieser
   Datei nur in Übereinstimmung mit der Lizenz erlaubt.
   Eine Kopie der Lizenz erhalten Sie auf http://www.apache.org/licenses/LICENSE-2.0.

   Sofern nicht gemäß geltendem Recht vorgeschrieben oder schriftlich vereinbart,
   erfolgt die Bereitstellung der im Rahmen der Lizenz verbreiteten Software OHNE
   GEWÄHR ODER VORBEHALTE – ganz gleich, ob ausdrücklich oder stillschweigend.

   Informationen über die jeweiligen Bedingungen für Genehmigungen und Einschränkungen
   im Rahmen der Lizenz finden Sie in der Lizenz.

   Autor: Kai Huebl (kai@huebl-sgh.de)
 */

#ifndef __OpcUaStackClient_SubscriptionServiceIf_h__
#define __OpcUaStackClient_SubscriptionServiceIf_h__

#include "OpcUaStackCore/Base/Condition.h"
#include "OpcUaStackCore/ServiceSet/SubscriptionServiceTransaction.h"
#include "OpcUaStackCore/ServiceSet/MonitoredItemNotification.h"

using namespace OpcUaStackCore;

namespace OpcUaStackClient
{

	typedef enum {
		SS_Close,
		SS_Open,
	} SubscriptionState;

	class DLLEXPORT SubscriptionServiceIf
	{
	  public:
		SubscriptionServiceIf(void) {}
		virtual ~SubscriptionServiceIf(void) {}

	    virtual void subscriptionServiceCreateSubscriptionResponse(ServiceTransactionCreateSubscription::SPtr serviceTransactionCreateSubscription) {};
	    virtual void subscriptionServiceModifySubscriptionResponse(ServiceTransactionModifySubscription::SPtr serviceTransactionModifySubscription) {};
	    virtual void subscriptionServiceTransferSubscriptionsResponse(ServiceTransactionTransferSubscriptions::SPtr serviceTransactionTransferSubscriptions) {};
	    virtual void subscriptionServiceDeleteSubscriptionsResponse(ServiceTransactionDeleteSubscriptions::SPtr serviceTransactionDeleteSubscriptions) {};

		virtual void dataChangeNotification(const MonitoredItemNotification::SPtr& monitoredItem) {};
		virtual void subscriptionStateUpdate(SubscriptionState subscriptionState, uint32_t subscriptionId) {};
	};

	class DLLEXPORT SubscriptionServiceIfTestHandler
	: public SubscriptionServiceIf
	{
	  public:
		SubscriptionServiceIfTestHandler(void);
		virtual ~SubscriptionServiceIfTestHandler(void);

		Condition subscriptionServiceCreateSubscriptionResponse_;
	    void subscriptionServiceCreateSubscriptionResponse(ServiceTransactionCreateSubscription::SPtr serviceTransactionCreateSubscription);
	    Condition subscriptionServiceModifySubscriptionResponse_;
	    void subscriptionServiceModifySubscriptionResponse(ServiceTransactionModifySubscription::SPtr serviceTransactionModifySubscription);
	    Condition subscriptionServiceTransferSubscriptionsResponse_;
	    void subscriptionServiceTransferSubscriptionsResponse(ServiceTransactionTransferSubscriptions::SPtr serviceTransactionTransferSubscriptions);
	    Condition subscriptionServiceDeleteSubscriptionsResponse_;
	    void subscriptionServiceDeleteSubscriptionsResponse(ServiceTransactionDeleteSubscriptions::SPtr serviceTransactionDeleteSubscriptions);

	    Condition dataChangeNotification_;
		virtual void dataChangeNotification(const MonitoredItemNotification::SPtr& monitoredItem);
		SubscriptionState subscriptionState_;
		Condition subscriptionStateUpdate_;
		virtual void subscriptionStateUpdate(SubscriptionState subscriptionState, uint32_t subscriptionId);
	};

}

#endif
