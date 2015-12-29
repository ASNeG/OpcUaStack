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

#ifndef __OpcUaStackClient_SubscriptionService_h__
#define __OpcUaStackClient_SubscriptionService_h__

#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/Component/Component.h"
#include "OpcUaStackCore/ServiceSet/SubscriptionServiceTransaction.h"
#include "OpcUaStackClient/ServiceSet/SessionOld.h"

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

	class DLLEXPORT SubscriptionServicePublishIf
	{
	  public:
		virtual ~SubscriptionServicePublishIf(void) {}

        virtual void subscriptionServiceSetPublishingModeResponse(ServiceTransactionSetPublishingMode::SPtr serviceTransactionSetPublishingMode) {};
        virtual void subscriptionServicePublishResponse(ServiceTransactionPublish::SPtr serviceTransactionPublish) {};
        virtual void subscriptionServiceRepublishResponse(ServiceTransactionRepublish::SPtr serviceTransactionRepublish) {};
	};

	class DLLEXPORT SubscriptionService
	: public Component
	{
	  public:
		boost::shared_ptr<SubscriptionService> SPtr;

		SubscriptionService(void);
		~SubscriptionService(void);

		virtual void componentSession(Component* componentSession);
		virtual void subscriptionServiceIf(SubscriptionServiceIf* subscriptionServiceIf);
		void subscriptionServicePublishIf(SubscriptionServicePublishIf* subscriptionServicePublishIf);

		void sendSync(ServiceTransactionCreateSubscription::SPtr serviceTransactionCreateSubscription);
		void send(ServiceTransactionCreateSubscription::SPtr serviceTransactionCreateSubscription);
		void sendSync(ServiceTransactionModifySubscription::SPtr serviceTransactionModifySubscription);
		void send(ServiceTransactionModifySubscription::SPtr serviceTransactionModifySubscription);
		void sendSync(ServiceTransactionTransferSubscriptions::SPtr serviceTransactionTransferSubscriptions);
		void send(ServiceTransactionTransferSubscriptions::SPtr serviceTransactionTransferSubscriptions);
		void sendSync(ServiceTransactionDeleteSubscriptions::SPtr serviceTransactionDeleteSubscriptions);
		void send(ServiceTransactionDeleteSubscriptions::SPtr serviceTransactionDeleteSubscriptions);
		void sendSync(ServiceTransactionSetPublishingMode::SPtr serviceTransactionSetPublishingMode);
		void send(ServiceTransactionSetPublishingMode::SPtr serviceTransactionSetPublishingMode);
		void sendSync(ServiceTransactionPublish::SPtr serviceTransactionPublish);
		void send(ServiceTransactionPublish::SPtr serviceTransactionPublish);
		void sendSync(ServiceTransactionRepublish::SPtr serviceTransactionRepublish);
		void send(ServiceTransactionRepublish::SPtr serviceTransactionRepublish);

		//- Component -----------------------------------------------------------------
		virtual void receive(Message::SPtr message);
		//- Component -----------------------------------------------------------------

		virtual void sendDeleteSubscriptions(ServiceTransactionDeleteSubscriptions::SPtr serviceTransactionDeleteSubscriptions) = 0;

	  private:
		Component* componentSession_;

		SubscriptionServiceIf* subscriptionServiceIf_;
		SubscriptionServicePublishIf* subscriptionServicePublishIf_;
	};

}

#endif
