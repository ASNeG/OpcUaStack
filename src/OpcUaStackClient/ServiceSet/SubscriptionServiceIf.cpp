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


#include "OpcUaStackClient/ServiceSet/SubscriptionServiceIf.h"

namespace OpcUaStackClient
{
	SubscriptionServiceIfTestHandler::SubscriptionServiceIfTestHandler(void)
	: SubscriptionServiceIf()
	, subscriptionServiceCreateSubscriptionResponse_()
	, subscriptionServiceModifySubscriptionResponse_()
	, subscriptionServiceTransferSubscriptionsResponse_()
	, subscriptionServiceDeleteSubscriptionsResponse_()

	, dataChangeNotification_()
	, subscriptionStateUpdate_()
	, subscriptionState_(SS_Close)
	{
	}

	SubscriptionServiceIfTestHandler::~SubscriptionServiceIfTestHandler(void)
	{
	}


    void
    SubscriptionServiceIfTestHandler::subscriptionServiceCreateSubscriptionResponse(ServiceTransactionCreateSubscription::SPtr serviceTransactionCreateSubscription)
    {
    	subscriptionServiceCreateSubscriptionResponse_.conditionValueDec();
    }

    void
    SubscriptionServiceIfTestHandler::subscriptionServiceModifySubscriptionResponse(ServiceTransactionModifySubscription::SPtr serviceTransactionModifySubscription)
    {
    	subscriptionServiceModifySubscriptionResponse_.conditionValueDec();
    }

    void
    SubscriptionServiceIfTestHandler::subscriptionServiceTransferSubscriptionsResponse(ServiceTransactionTransferSubscriptions::SPtr serviceTransactionTransferSubscriptions)
    {
    	subscriptionServiceTransferSubscriptionsResponse_.conditionValueDec();
    }

    void
    SubscriptionServiceIfTestHandler::subscriptionServiceDeleteSubscriptionsResponse(ServiceTransactionDeleteSubscriptions::SPtr serviceTransactionDeleteSubscriptions)
    {
    	subscriptionServiceDeleteSubscriptionsResponse_.conditionValueDec();
    }

	void
	SubscriptionServiceIfTestHandler::dataChangeNotification(const MonitoredItemNotification::SPtr& monitoredItem)
	{
		dataChangeNotification_.conditionValueDec();
	}

	void
	SubscriptionServiceIfTestHandler::subscriptionStateUpdate(SubscriptionState subscriptionState, uint32_t subscriptionId)
	{
		subscriptionState_ = subscriptionState;
		subscriptionStateUpdate_.conditionValueDec();
	}

}
