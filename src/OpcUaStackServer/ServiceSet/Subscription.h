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

#ifndef __OpcUaStackServer_Subscription_h__
#define __OpcUaStackServer_Subscription_h__

#include <boost/thread/mutex.hpp>
#include "OpcUaStackCore/BuildInTypes/OpcUaStatusCode.h"
#include "OpcUaStackCore/Utility/SlotTimer.h"
#include "OpcUaStackCore/ServiceSet/SubscriptionServiceTransaction.h"
#include "OpcUaStackCore/ServiceSet/MonitoredItemServiceTransaction.h"
#include "OpcUaStackServer/ServiceSetApplication/ForwardGlobalSync.h"
#include "OpcUaStackServer/ServiceSet/MonitorManager.h"
#include "OpcUaStackServer/ServiceSet/AcknowledgementManager.h"
#include "OpcUaStackServer/InformationModel/InformationModel.h"
#include <map>

namespace OpcUaStackServer
{

	typedef std::map<uint32_t, OpcUaStackCore::PublishResponse::SPtr> RetransmissionQueue;
	typedef enum
	{
		NothingTodo,
		NeedAttention,
		SendPublish,
		SendPublishKeepalive,
		SubscriptionTimeout,
	} PublishResult;

	class DLLEXPORT Subscription
	: public OpcUaStackCore::Object
	{
	  public:
		typedef boost::shared_ptr<Subscription> SPtr;

		Subscription(void);
		~Subscription(void);

		uint32_t subscriptionId(void);
		void publishingInterval(double publishingInterval);	
		void lifetimeCount(uint32_t lifetimeCount);
		void maxKeepAliveCount(uint32_t maxKeepAliveCount);
		void ioThread(OpcUaStackCore::IOThread* ioThread);
		void strand(boost::shared_ptr<boost::asio::io_service::strand>& strand);
		void informationModel(InformationModel::SPtr& informationModel);
		void forwardGlobalSync(ForwardGlobalSync::SPtr& forwardGlobalSync);
		OpcUaStackCore::OpcUaStatusCode receiveAcknowledgement(uint32_t acknowledgmentNumber);

		void retransmissionQueue(OpcUaStackCore::SubscriptionAcknowledgement::SPtr& subscriptionAcknowledgement);
		void retransmissionQueue(OpcUaStackCore::PublishResponse::SPtr& publishResponse);

		PublishResult publish(OpcUaStackCore::ServiceTransactionPublish::SPtr& trx);
		uint32_t publishPre(void);

		// monitored item
		OpcUaStackCore::OpcUaStatusCode receive(OpcUaStackCore::ServiceTransactionCreateMonitoredItems::SPtr trx);
		OpcUaStackCore::OpcUaStatusCode receive(OpcUaStackCore::ServiceTransactionDeleteMonitoredItems::SPtr trx);
		OpcUaStackCore::OpcUaStatusCode receive(OpcUaStackCore::ServiceTransactionModifyMonitoredItems::SPtr trx);
		OpcUaStackCore::OpcUaStatusCode receive(OpcUaStackCore::ServiceTransactionSetMonitoringMode::SPtr trx);
		OpcUaStackCore::OpcUaStatusCode receive(OpcUaStackCore::ServiceTransactionSetTriggering::SPtr trx);

		OpcUaStackCore::SlotTimerElement::SPtr slotTimerElement(void);

	  private:
		void createKeepalive(OpcUaStackCore::ServiceTransactionPublish::SPtr& trx);

		static uint32_t uniqueSubscriptionId(void);
		static boost::mutex mutex_;
		static uint32_t uniqueSubscriptionId_;

		AcknowledgementManager acknowledgementManager_;
		uint32_t subscriptionId_;
		double publishingInterval_;
		uint32_t lifetimeCount_;
		uint32_t actLifetimeCount_;
		uint32_t maxKeepAliveCount_;
		uint32_t actMaxKeepAliveCount_;
		OpcUaStackCore::SlotTimerElement::SPtr slotTimerElement_;
		RetransmissionQueue retransmissionQueue_;

		OpcUaStackCore::IOThread* ioThread_;
		boost::shared_ptr<boost::asio::io_service::strand> strand_ = nullptr;
		MonitorManager monitorManager_;
	};

	typedef std::map<uint32_t, Subscription::SPtr> SubscriptionMap;
}

#endif
