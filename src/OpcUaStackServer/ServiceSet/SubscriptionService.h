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

#ifndef __OpcUaStackServer_SubscriptionService_h__
#define __OpcUaStackServer_SubscriptionService_h__

#include "OpcUaStackCore/ServiceSet/SubscriptionServiceTransaction.h"
#include "OpcUaStackCore/ServiceSet/MonitoredItemServiceTransaction.h"
#include "OpcUaStackServer/ServiceSetApplication/ForwardGlobalSync.h"
#include "OpcUaStackServer/ServiceSet/ServiceSetBase.h"
#include "OpcUaStackServer/ServiceSet/SubscriptionManager.h"
#include "OpcUaStackServer/ServiceSet/ServerServiceBase.h"

namespace OpcUaStackServer
{

	class DLLEXPORT SubscriptionService 
	: public ServiceSetBase
	, public OpcUaStackCore::Object
	, public OpcUaStackServer::ServerServiceBase
	{
	  public:
		typedef boost::shared_ptr<SubscriptionService> SPtr;
		typedef std::map<uint32_t, SubscriptionManager::SPtr> SubscriptionManagerMap;

		SubscriptionService(
			const std::string& serviceName,
			OpcUaStackCore::IOThread::SPtr& ioThread,
			OpcUaStackCore::MessageBus::SPtr& messageBus
		);
		~SubscriptionService(void);

		bool init(void);

	  private:
		void receive(
			const OpcUaStackCore::MessageBusMember::WPtr& handleFrom,
			OpcUaStackCore::Message::SPtr& message
		);
		void sendAnswer(OpcUaStackCore::ServiceTransaction::SPtr& serviceTransaction);

		 // subscription
		void receiveCreateSubscriptionRequest(OpcUaStackCore::ServiceTransaction::SPtr serviceTransaction);
		void receiveDeleteSubscriptionsRequest(OpcUaStackCore::ServiceTransaction::SPtr serviceTransaction);
		void receiveModifySubscriptionRequest(OpcUaStackCore::ServiceTransaction::SPtr serviceTransaction);
		void receivePublishRequest(OpcUaStackCore::ServiceTransaction::SPtr serviceTransaction);
		void receiveRepublishRequest(OpcUaStackCore::ServiceTransaction::SPtr serviceTransaction);
		void receiveSetPublishingModeRequest(OpcUaStackCore::ServiceTransaction::SPtr serviceTransaction);
		void receiveTransferSubscriptionsRequest(OpcUaStackCore::ServiceTransaction::SPtr serviceTransaction);

		// monitored item
		void receiveCreateMonitoredItemsRequest(OpcUaStackCore::ServiceTransaction::SPtr serviceTransaction);
		void receiveDeleteMonitoredItemsRequest(OpcUaStackCore::ServiceTransaction::SPtr serviceTransaction);
		void receiveModifyMonitoredItemsRequest(OpcUaStackCore::ServiceTransaction::SPtr serviceTransaction);
		void receiveSetMonitoringModeRequest(OpcUaStackCore::ServiceTransaction::SPtr serviceTransaction);
		void receiveSetTriggeringRequest(OpcUaStackCore::ServiceTransaction::SPtr serviceTransaction);

		SubscriptionManagerMap subscriptionManagerMap_;
	};

}

#endif
