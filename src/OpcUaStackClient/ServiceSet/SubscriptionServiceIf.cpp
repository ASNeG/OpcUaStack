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
	: subscriptionServiceCreateSubscriptionResponse_()
	, subscriptionServiceModifySubscriptionResponse_()
	, subscriptionServiceTransferSubscriptionsResponse_()
	, subscriptionServiceDeleteSubscriptionsResponse_()
	, subscriptionServiceSetPublishingModeResponse_()
	, subscriptionServiceSetPublishingModeResponse_()
	, subscriptionServiceRepublishResponse_()
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
    SubscriptionServiceIfTestHandler::subscriptionServiceSetPublishingModeResponse(ServiceTransactionSetPublishingMode::SPtr serviceTransactionSetPublishingMode)
    {
    	subscriptionServiceSetPublishingModeResponse_.conditionValueDec();
    }

    void
    SubscriptionServiceIfTestHandler::subscriptionServicePublishResponse(ServiceTransactionPublish::SPtr serviceTransactionPublish)
    {
    	subscriptionServicePublishResponse_.conditionValueDec();
    }

    void
    SubscriptionServiceIfTestHandler::subscriptionServiceRepublishResponse(ServiceTransactionRepublish::SPtr serviceTransactionRepublish)
    {
    	subscriptionServiceRepublishResponse_.conditionValueDec();
    }

}
