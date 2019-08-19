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

#ifndef __OpcUaStackServer_SubscriptionService_h__
#define __OpcUaStackServer_SubscriptionService_h__

#include "OpcUaStackCore/ServiceSetApplication/ForwardGlobalSync.h"
#include "OpcUaStackCore/ServiceSet/SubscriptionServiceTransaction.h"
#include "OpcUaStackCore/ServiceSet/MonitoredItemServiceTransaction.h"
#include "OpcUaStackServer/ServiceSet/ServiceSetBase.h"
#include "OpcUaStackServer/ServiceSet/SubscriptionManager.h"

namespace OpcUaStackServer
{

	class DLLEXPORT SubscriptionService 
	: public ServiceSetBase
	, public OpcUaStackCore::Object
	{
	  public:
		typedef boost::shared_ptr<SubscriptionService> SPtr;
		typedef std::map<uint32_t, SubscriptionManager::SPtr> SubscriptionManagerMap;

		SubscriptionService(void);
		~SubscriptionService(void);

		bool init(void);

		//- Component -----------------------------------------------------------------
		void receive(OpcUaStackCore::Message::SPtr message);
		//- Component -----------------------------------------------------------------

	  private:
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
