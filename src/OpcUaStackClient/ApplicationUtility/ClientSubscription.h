/*
   Copyright 2016-2019 Kai Huebl (kai@huebl-sgh.de)

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

#ifndef __OpcUaStackClient_ClientSubscription_h__
#define __OpcUaStackClient_ClientSubscription_h__

#include "OpcUaStackCore/Utility/IOThread.h"
#include "OpcUaStackClient/ServiceSet/ServiceSetManager.h"
#include "OpcUaStackClient/ApplicationUtility/ClientMonitoredItem.h"
#include <map>
#include <set>
#include <vector>
#include <stdint.h>

namespace OpcUaStackClient
{

	class DLLEXPORT ClientSubscriptionIf
	{
	  public:
		ClientSubscriptionIf(void) {}
		virtual ~ClientSubscriptionIf(void) {}

		virtual void dataChangeNotification(ClientMonitoredItem::SPtr& clientMonitoredItem, OpcUaStackCore::OpcUaDataValue& dataValue) = 0;
	};


	class DLLEXPORT ClientSubscription
	{
	  public:
		typedef boost::shared_ptr<ClientSubscription> SPtr;
		typedef std::map<std::string, ClientSubscription::SPtr> Map;
		typedef std::set<ClientSubscription::SPtr> Set;
		typedef std::map<uint32_t, uint32_t> NamespaceMap;

		typedef enum {
			S_Error,
			S_Close,
			S_Opening,
			S_Open,
			S_Closing,
		} State;

		ClientSubscription(void);
		~ClientSubscription(void);

		void ioThread(OpcUaStackCore::IOThread::SPtr& ioThread);
		OpcUaStackCore::IOThread::SPtr& ioThread(void);
		std::string id(void);
		void id(const std::string& id);
		uint32_t publishingInterval(void);
		void publishingInterval(uint32_t publishingInterval);
		uint32_t livetimeCount(void);
		void livetimeCount(uint32_t livetimeCount);
		uint32_t maxKeepAliveCount(void);
		void maxKeepAliveCount(uint32_t maxKeepAliveCount);
		uint32_t maxNotificationsPerPublish(void);
		void maxNotificationsPerPublish(uint32_t maxNotificationsPerPublish);
		void serviceSetManager(ServiceSetManager* serviceSetManager);
		void sessionService(SessionService::SPtr& sessionService);

		void addMonitoredItem(ClientMonitoredItem::SPtr& clientMonitoredItem);

		void state(State state);
		State state(void);

		void open(NamespaceMap& namespaceMap);
		void close(void);
		void error(void);

	    void subscriptionServiceCreateSubscriptionResponse(OpcUaStackCore::ServiceTransactionCreateSubscription::SPtr serviceTransactionCreateSubscription);
	    void subscriptionServiceModifySubscriptionResponse(OpcUaStackCore::ServiceTransactionModifySubscription::SPtr serviceTransactionModifySubscription);
	    void subscriptionServiceTransferSubscriptionsResponse(OpcUaStackCore::ServiceTransactionTransferSubscriptions::SPtr serviceTransactionTransferSubscriptions);
	    void subscriptionServiceDeleteSubscriptionsResponse(OpcUaStackCore::ServiceTransactionDeleteSubscriptions::SPtr serviceTransactionDeleteSubscriptions);

		void dataChangeNotification(const OpcUaStackCore::MonitoredItemNotification::SPtr& monitoredItem);
		void subscriptionStateUpdate(SubscriptionState subscriptionState, uint32_t subscriptionId);

	    void monitoredItemServiceCreateMonitoredItemsResponse(OpcUaStackCore::ServiceTransactionCreateMonitoredItems::SPtr serviceTransactionCreateMonitoredItems);
	    void monitoredItemServiceDeleteMonitoredItemsResponse(OpcUaStackCore::ServiceTransactionDeleteMonitoredItems::SPtr serviceTransactionDeleteMonitoredItems);
	    void monitoredItemServiceModifyMonitoredItemsResponse(OpcUaStackCore::ServiceTransactionModifyMonitoredItems::SPtr serviceTransactionModifyMonitoredItems);
	    void monitoredItemServiceSetMonitoringModeResponse(OpcUaStackCore::ServiceTransactionSetMonitoringMode::SPtr serviceTransactionSetMonitoringMode);
	    void monitoredItemServiceSetTriggeringResponse(OpcUaStackCore::ServiceTransactionSetTriggering::SPtr serviceTransactionSetTriggering);

	  private:
		void init(void);
		void openMonitoredItems(void);
		void cleanUpMonitoredItems(void);
		void deleteMonitoredItems(void);

		// configuration parameters
		OpcUaStackCore::IOThread::SPtr ioThread_;
		std::string id_;
		uint32_t publishingInterval_;
		uint32_t livetimeCount_;
		uint32_t maxKeepAliveCount_;
		uint32_t maxNotificationsPerPublish_;

		// runtime parameters
		bool init_;
		State state_;
		uint32_t subscriptionId_;
		NamespaceMap* namespaceMap_;
		ServiceSetManager* serviceSetManager_;
		SessionService::SPtr sessionService_;

		SubscriptionService::SPtr subscriptionService_;
		MonitoredItemService::SPtr monitoredItemService_;

		ClientMonitoredItem::IdMap clientMonitoredItemMap_;
		ClientSubscriptionIf* clientSubscriptionIf_;
	};

}

#endif
