/*
   Copyright 2015-2021 Kai Huebl (kai@huebl-sgh.de)

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
#include "OpcUaStackCore/MessageBus/MessageBus.h"
#include "OpcUaStackCore/ServiceSet/SubscriptionServiceTransaction.h"
#include "OpcUaStackCore/ServiceSet/MonitoredItemServiceTransaction.h"
#include "OpcUaStackServer/ServiceSetApplication/ForwardGlobalSync.h"
#include "OpcUaStackServer/ServiceSet/Subscription.h"
#include "OpcUaStackServer/InformationModel/InformationModel.h"

#include <set>

namespace OpcUaStackServer
{

	typedef std::list<OpcUaStackCore::ServiceTransactionPublish::SPtr> ServiceTransactionPublishList;
	typedef std::list<uint32_t> SubscriptionIdList;

	class DLLEXPORT SubscriptionManager
	: public OpcUaStackCore::Object
	{
	  public:
		typedef boost::shared_ptr<SubscriptionManager> SPtr;

		SubscriptionManager(void);
		~SubscriptionManager(void);

		void ioThread(OpcUaStackCore::IOThread* ioThread);
		void messageBus(OpcUaStackCore::MessageBus::SPtr& messageBus);
		void messageBusMember(OpcUaStackCore::MessageBusMember::WPtr& messageBusMember);
		void strand(boost::shared_ptr<boost::asio::io_service::strand>& strand);
		void informationModel(InformationModel::SPtr informationModel);
		void forwardGlobalSync(ForwardGlobalSync::SPtr& forwardGlobalSync);
		void sessionId(uint32_t sessionId);

		OpcUaStackCore::OpcUaStatusCode receive(OpcUaStackCore::ServiceTransactionCreateSubscription::SPtr& trx);
		OpcUaStackCore::OpcUaStatusCode receive(OpcUaStackCore::ServiceTransactionDeleteSubscriptions::SPtr& trx);
		OpcUaStackCore::OpcUaStatusCode receive(OpcUaStackCore::ServiceTransactionPublish::SPtr& trx);

		OpcUaStackCore::OpcUaStatusCode receive(OpcUaStackCore::ServiceTransactionCreateMonitoredItems::SPtr trx);
		OpcUaStackCore::OpcUaStatusCode receive(OpcUaStackCore::ServiceTransactionDeleteMonitoredItems::SPtr trx);
		OpcUaStackCore::OpcUaStatusCode receive(OpcUaStackCore::ServiceTransactionModifyMonitoredItems::SPtr trx);
		OpcUaStackCore::OpcUaStatusCode receive(OpcUaStackCore::ServiceTransactionSetMonitoringMode::SPtr trx);
		OpcUaStackCore::OpcUaStatusCode receive(OpcUaStackCore::ServiceTransactionSetTriggering::SPtr trx);

		size_t size(void);

	  private:
		void sendAnswer(const OpcUaStackCore::ServiceTransaction::SPtr& serviceTransaction);
		void subscriptionPublishTimeout(Subscription::SPtr subscription);
		OpcUaStackCore::OpcUaStatusCode receiveAcknowledgement(uint32_t subscriptionId, uint32_t acknowledgmentNumber);

		OpcUaStackCore::IOThread* ioThread_;
		OpcUaStackCore::MessageBus::SPtr messageBus_ = nullptr;
		boost::shared_ptr<boost::asio::io_service::strand> strand_ = nullptr;
		OpcUaStackCore::MessageBusMember::WPtr messageBusMember_;
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
