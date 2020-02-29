/*
   Copyright 2015-2020 Kai Huebl (kai@huebl-sgh.de)

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

#include "OpcUaStackCore/ServiceSet/SubscriptionServiceTransaction.h"
#include "OpcUaStackClient/ServiceSet/ClientServiceBase.h"

namespace OpcUaStackClient
{

	class DLLEXPORT SubscriptionServicePublishIf
	{
	  public:
		virtual ~SubscriptionServicePublishIf(void) {}
		virtual void subscriptionServiceSetPublishingModeResponse(OpcUaStackCore::ServiceTransactionSetPublishingMode::SPtr serviceTransactionSetPublishingMode) {};
		virtual void subscriptionServicePublishResponse(OpcUaStackCore::ServiceTransactionPublish::SPtr serviceTransactionPublish) {};
		virtual void subscriptionServiceRepublishResponse(OpcUaStackCore::ServiceTransactionRepublish::SPtr serviceTransactionRepublish) {};
	};

	class DLLEXPORT SubscriptionServiceBase
	: public ClientServiceBase
	{
	  public:
		boost::shared_ptr<SubscriptionServiceBase> SPtr;

		SubscriptionServiceBase(void);
		~SubscriptionServiceBase(void);

		void subscriptionServicePublishIf(SubscriptionServicePublishIf* subscriptionServicePublishIf);

		void syncSend(OpcUaStackCore::ServiceTransactionCreateSubscription::SPtr& serviceTransactionCreateSubscription);
		void asyncSend(OpcUaStackCore::ServiceTransactionCreateSubscription::SPtr& serviceTransactionCreateSubscription);
		void syncSend(OpcUaStackCore::ServiceTransactionModifySubscription::SPtr& serviceTransactionModifySubscription);
		void asyncSend(OpcUaStackCore::ServiceTransactionModifySubscription::SPtr& serviceTransactionModifySubscription);
		void syncSend(OpcUaStackCore::ServiceTransactionTransferSubscriptions::SPtr& serviceTransactionTransferSubscriptions);
		void asyncSend(OpcUaStackCore::ServiceTransactionTransferSubscriptions::SPtr& serviceTransactionTransferSubscriptions);
		void syncSend(OpcUaStackCore::ServiceTransactionDeleteSubscriptions::SPtr& serviceTransactionDeleteSubscriptions);
		void asyncSend(OpcUaStackCore::ServiceTransactionDeleteSubscriptions::SPtr& serviceTransactionDeleteSubscriptions);
		void syncSend(OpcUaStackCore::ServiceTransactionSetPublishingMode::SPtr& serviceTransactionSetPublishingMode);
		void asyncSend(OpcUaStackCore::ServiceTransactionSetPublishingMode::SPtr& serviceTransactionSetPublishingMode);
		void syncSend(OpcUaStackCore::ServiceTransactionPublish::SPtr& serviceTransactionPublish);
		void asyncSend(OpcUaStackCore::ServiceTransactionPublish::SPtr& serviceTransactionPublish);
		void syncSend(OpcUaStackCore::ServiceTransactionRepublish::SPtr& serviceTransactionRepublish);
		void asyncSend(OpcUaStackCore::ServiceTransactionRepublish::SPtr& serviceTransactionRepublish);

		//- Component -----------------------------------------------------------------
		virtual void receive(OpcUaStackCore::Message::SPtr message);
		//- Component -----------------------------------------------------------------

	  protected:
		OpcUaStackCore::MessageBusMember::WPtr sessionMember_;

	  private:
		SubscriptionServicePublishIf* subscriptionServicePublishIf_;
	};

}

#endif
