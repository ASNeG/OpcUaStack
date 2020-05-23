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

#ifndef __OpcUaStackClient_SubscriptionManager_h__
#define __OpcUaStackClient_SubscriptionManager_h__

#include <OpcUaStackCore/MessageBus/MessageBus.h>
#include <set>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackClient/ServiceSet/SubscriptionServiceBase.h"
#include "OpcUaStackClient/ServiceSet/SubscriptionServiceHandler.h"

namespace OpcUaStackClient
{

	class DLLEXPORT SubscriptionService
	: public SubscriptionServiceBase
	, public SubscriptionServicePublishIf
	{
	  public:
		typedef boost::shared_ptr<SubscriptionService> SPtr;

		SubscriptionService(
			const std::string& serviceName,
			OpcUaStackCore::IOThread* ioThread,
			OpcUaStackCore::MessageBus::SPtr& messageBus
		);
		virtual ~SubscriptionService(void);

		void setConfiguration(
			OpcUaStackCore::MessageBusMember::WPtr& sessionMember,
			const DataChangeNotificationHandler& dataChangeNotificationHandler,
			boost::shared_ptr<boost::asio::io_service::strand>& dataChangeNotificationHandlerStrand,
			const EventNotificationHandler& eventNotificationHandler,
			boost::shared_ptr<boost::asio::io_service::strand>& eventNotificationHandlerStrand,
			const SubscriptionStateUpdateHandler& subscriptionStateUpdateHandler,
			boost::shared_ptr<boost::asio::io_service::strand>& subscriptionStateUpdateHandlerStrand,
			uint32_t publishCount,
			uint32_t requestTimeout
		);
		void publishCount(uint32_t publishCount);
		uint32_t publishCount(void);

		void syncSend(const OpcUaStackCore::ServiceTransactionCreateSubscription::SPtr& serviceTransactionCreateSubscription);
		void asyncSend(const OpcUaStackCore::ServiceTransactionCreateSubscription::SPtr& serviceTransactionCreateSubscription);
		void syncSend(const OpcUaStackCore::ServiceTransactionModifySubscription::SPtr& serviceTransactionModifySubscription);
		void asyncSend(const OpcUaStackCore::ServiceTransactionModifySubscription::SPtr& serviceTransactionModifySubscription);
		void syncSend(const OpcUaStackCore::ServiceTransactionTransferSubscriptions::SPtr& serviceTransactionTransferSubscriptions);
		void asyncSend(const OpcUaStackCore::ServiceTransactionTransferSubscriptions::SPtr& serviceTransactionTransferSubscriptions);
		void syncSend(const OpcUaStackCore::ServiceTransactionDeleteSubscriptions::SPtr& serviceTransactionDeleteSubscriptions);
		void asyncSend(const OpcUaStackCore::ServiceTransactionDeleteSubscriptions::SPtr& serviceTransactionDeleteSubscriptions);
		void syncSend(const OpcUaStackCore::ServiceTransactionSetPublishingMode::SPtr& serviceTransactionSetPublishingMode);
		void asyncSend(const OpcUaStackCore::ServiceTransactionSetPublishingMode::SPtr& serviceTransactionSetPublishingMode);
		void syncSend(const OpcUaStackCore::ServiceTransactionPublish::SPtr& serviceTransactionPublish);
		void asyncSend(const OpcUaStackCore::ServiceTransactionPublish::SPtr& serviceTransactionPublish);
		void syncSend(const OpcUaStackCore::ServiceTransactionRepublish::SPtr& serviceTransactionRepublish);
		void asyncSend(const OpcUaStackCore::ServiceTransactionRepublish::SPtr& serviceTransactionRepublish);

	    //- SubscriptionServicePublish ----------------------------------------
	    virtual void subscriptionServiceSetPublishingModeResponse(OpcUaStackCore::ServiceTransactionSetPublishingMode::SPtr serviceTransactionSetPublishingMode);
	    virtual void subscriptionServicePublishResponse(OpcUaStackCore::ServiceTransactionPublish::SPtr serviceTransactionPublish);
	    virtual void subscriptionServiceRepublishResponse(OpcUaStackCore::ServiceTransactionRepublish::SPtr serviceTransactionRepublish);
		//- SubscriptionServicePublishIf --------------------------------------

	  private:
	    void receive(
	    	const OpcUaStackCore::MessageBusMember::WPtr& handleFrom,
	    	OpcUaStackCore::Message::SPtr message
		);

	    void subscriptionServiceCreateSubscriptionResponse(OpcUaStackCore::ServiceTransactionCreateSubscription::SPtr serviceTransactionCreateSubscription);
	    void subscriptionServiceDeleteSubscriptionsResponse(OpcUaStackCore::ServiceTransactionDeleteSubscriptions::SPtr serviceTransactionDeleteSubscriptions);

	    void sendDeleteSubscriptions(const OpcUaStackCore::ServiceTransactionDeleteSubscriptions::SPtr& serviceTransactionDeleteSubscriptions);
	    void createSubscription(uint32_t subscriptionId);
	    void deleteSubscriptionRequest(uint32_t subscriptionId);
	    void deleteSubscriptionResponse(uint32_t subscriptionId);
	    void sendPublishRequests(void);

	    void receivePublishResponse(const OpcUaStackCore::PublishResponse::SPtr& publishResponse);
	    void dataChangeNotification(const OpcUaStackCore::OpcUaExtensibleParameter::SPtr& extensibleParameter);
	    void eventNotification(const OpcUaStackCore::OpcUaExtensibleParameter::SPtr& extensibleParameter);

	    DataChangeNotificationHandler dataChangeNotificationHandler_ = nullptr;
	    boost::shared_ptr<boost::asio::io_service::strand> dataChangeNotificationHandlerStrand_ = nullptr;
		EventNotificationHandler eventNotificationHandler_ = nullptr;
		boost::shared_ptr<boost::asio::io_service::strand> eventNotificationHandlerStrand_ = nullptr;
		SubscriptionStateUpdateHandler subscriptionStateUpdateHandler_ = nullptr;
		boost::shared_ptr<boost::asio::io_service::strand> subscriptionStateUpdateHandlerStrand_ = nullptr;
	    uint32_t publishCount_;
	    uint32_t actPublishCount_;
	    uint32_t requestTimeout_;
	    typedef std::set<uint32_t> SubscriptionSet;
	    SubscriptionSet subscriptionSet_;
	    SubscriptionSet subscriptionSetPendingDelete_;
	};

}

#endif
