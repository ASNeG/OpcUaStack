/*
   Copyright 2015-2019 Kai Huebl (kai@huebl-sgh.de)

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

#include "OpcUaStackCore/Component/Component.h"
#include "OpcUaStackCore/ServiceSet/SubscriptionServiceTransaction.h"

using namespace OpcUaStackCore;

namespace OpcUaStackClient
{

	class DLLEXPORT SubscriptionServicePublishIf
	{
	  public:
		virtual ~SubscriptionServicePublishIf(void) {}
		virtual void subscriptionServiceSetPublishingModeResponse(ServiceTransactionSetPublishingMode::SPtr serviceTransactionSetPublishingMode) {};
		virtual void subscriptionServicePublishResponse(ServiceTransactionPublish::SPtr serviceTransactionPublish) {};
		virtual void subscriptionServiceRepublishResponse(ServiceTransactionRepublish::SPtr serviceTransactionRepublish) {};
	};

	class DLLEXPORT SubscriptionServiceBase
	: public Component
	{
	  public:
		boost::shared_ptr<SubscriptionServiceBase> SPtr;

		SubscriptionServiceBase(void);
		~SubscriptionServiceBase(void);

		virtual void componentSession(Component* componentSession);
		void subscriptionServicePublishIf(SubscriptionServicePublishIf* subscriptionServicePublishIf);

		void syncSend(ServiceTransactionCreateSubscription::SPtr& serviceTransactionCreateSubscription);
		void asyncSend(ServiceTransactionCreateSubscription::SPtr& serviceTransactionCreateSubscription);
		void syncSend(ServiceTransactionModifySubscription::SPtr& serviceTransactionModifySubscription);
		void asyncSend(ServiceTransactionModifySubscription::SPtr& serviceTransactionModifySubscription);
		void syncSend(ServiceTransactionTransferSubscriptions::SPtr& serviceTransactionTransferSubscriptions);
		void asyncSend(ServiceTransactionTransferSubscriptions::SPtr& serviceTransactionTransferSubscriptions);
		void syncSend(ServiceTransactionDeleteSubscriptions::SPtr& serviceTransactionDeleteSubscriptions);
		void asyncSend(ServiceTransactionDeleteSubscriptions::SPtr& serviceTransactionDeleteSubscriptions);
		void syncSend(ServiceTransactionSetPublishingMode::SPtr& serviceTransactionSetPublishingMode);
		void asyncSend(ServiceTransactionSetPublishingMode::SPtr& serviceTransactionSetPublishingMode);
		void syncSend(ServiceTransactionPublish::SPtr& serviceTransactionPublish);
		void asyncSend(ServiceTransactionPublish::SPtr& serviceTransactionPublish);
		void syncSend(ServiceTransactionRepublish::SPtr& serviceTransactionRepublish);
		void asyncSend(ServiceTransactionRepublish::SPtr& serviceTransactionRepublish);

		//- Component -----------------------------------------------------------------
		virtual void receive(Message::SPtr message);
		//- Component -----------------------------------------------------------------

	  private:
		Component* componentSession_;
		SubscriptionServicePublishIf* subscriptionServicePublishIf_;
	};

}

#endif
