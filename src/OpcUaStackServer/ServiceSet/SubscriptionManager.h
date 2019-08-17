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

#ifndef __OpcUaStackServer_SubscriptionManager_h__
#define __OpcUaStackServer_SubscriptionManager_h__

#include "OpcUaStackCore/Base/IOService.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaStatusCode.h"
#include "OpcUaStackCore/Utility/SlotTimer.h"
#include "OpcUaStackCore/ServiceSetApplication/ForwardGlobalSync.h"
#include "OpcUaStackCore/ServiceSet/SubscriptionServiceTransaction.h"
#include "OpcUaStackCore/ServiceSet/MonitoredItemServiceTransaction.h"
#include "OpcUaStackServer/ServiceSet/Subscription.h"
#include "OpcUaStackServer/InformationModel/InformationModel.h"

#include <set>

namespace OpcUaStackServer
{

	typedef std::list<ServiceTransactionPublish::SPtr> ServiceTransactionPublishList; 
	typedef std::list<uint32_t> SubscriptionIdList;

	class DLLEXPORT SubscriptionManager
	: public Object
	{
	  public:
		typedef boost::shared_ptr<SubscriptionManager> SPtr;

		SubscriptionManager(void);
		~SubscriptionManager(void);

		void ioThread(IOThread* ioThread);
		void informationModel(InformationModel::SPtr informationModel);
		void forwardGlobalSync(ForwardGlobalSync::SPtr& forwardGlobalSync);
		void sessionId(uint32_t sessionId);

		OpcUaStatusCode receive(ServiceTransactionCreateSubscription::SPtr trx);
		OpcUaStatusCode receive(ServiceTransactionDeleteSubscriptions::SPtr trx);
		OpcUaStatusCode receive(ServiceTransactionPublish::SPtr trx);

		OpcUaStatusCode receive(ServiceTransactionCreateMonitoredItems::SPtr trx);
		OpcUaStatusCode receive(ServiceTransactionDeleteMonitoredItems::SPtr trx);
		OpcUaStatusCode receive(ServiceTransactionModifyMonitoredItems::SPtr trx);
		OpcUaStatusCode receive(ServiceTransactionSetMonitoringMode::SPtr trx);
		OpcUaStatusCode receive(ServiceTransactionSetTriggering::SPtr trx);

		size_t size(void);

	  private:
		void subscriptionPublishTimeout(Subscription::SPtr subscription);
		OpcUaStatusCode receiveAcknowledgement(uint32_t subscriptionId, uint32_t acknowledgmentNumber);

		IOThread* ioThread_;
		InformationModel::SPtr informationModel_;
		ForwardGlobalSync::SPtr forwardGlobalSync_;
		SubscriptionMap subscriptionMap_;
		uint32_t sessionId_;

		ServiceTransactionPublishList serviceTransactionPublishList_;
		SubscriptionIdList subscriptionIdList_;

		double minPublishingInterval_;
		uint32_t minLifetimeCount_;
		uint32_t minMaxKeepAliveCount_;
	};

}

#endif
