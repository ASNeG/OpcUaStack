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

#include "OpcUaStackCore/Base/Callback.h"
#include "OpcUaStackCore/Utility/IOThread.h"
#include "OpcUaStackClient/ServiceSet/ServiceSetManager.h"
#include "OpcUaStackClient/ApplicationUtility/ClientMonitoredItem.h"
#include <map>
#include <set>
#include <vector>
#include <stdint.h>

using namespace OpcUaStackCore;
using namespace OpcUaStackClient;

namespace OpcUaStackClient
{

	class DLLEXPORT ClientSubscriptionIf
	{
	  public:
		ClientSubscriptionIf(void) {}
		virtual ~ClientSubscriptionIf(void) {}

		virtual void dataChangeNotification(ClientMonitoredItem::SPtr& clientMonitoredItem, OpcUaDataValue& dataValue) = 0;
	};


	class DLLEXPORT ClientSubscription
	: public MonitoredItemServiceIf
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

		void ioThread(IOThread::SPtr& ioThread);
		IOThread::SPtr& ioThread(void);
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
		void clientSubscriptionIf(ClientSubscriptionIf* clientSubscriptionIf);

		void addMonitoredItem(ClientMonitoredItem::SPtr& clientMonitoredItem);

		void state(State state);
		State state(void);

		void open(NamespaceMap& namespaceMap);
		void close(void);
		void error(void);

	    void subscriptionServiceCreateSubscriptionResponse(ServiceTransactionCreateSubscription::SPtr serviceTransactionCreateSubscription);
	    void subscriptionServiceModifySubscriptionResponse(ServiceTransactionModifySubscription::SPtr serviceTransactionModifySubscription);
	    void subscriptionServiceTransferSubscriptionsResponse(ServiceTransactionTransferSubscriptions::SPtr serviceTransactionTransferSubscriptions);
	    void subscriptionServiceDeleteSubscriptionsResponse(ServiceTransactionDeleteSubscriptions::SPtr serviceTransactionDeleteSubscriptions);

		void dataChangeNotification(const MonitoredItemNotification::SPtr& monitoredItem);
		void subscriptionStateUpdate(SubscriptionState subscriptionState, uint32_t subscriptionId);
		//- SubscriptionServiceIf ---------------------------------------------

		//- MonitoredItemServiceIf --------------------------------------------
	    virtual void monitoredItemServiceCreateMonitoredItemsResponse(ServiceTransactionCreateMonitoredItems::SPtr serviceTransactionCreateMonitoredItems);
	    virtual void monitoredItemServiceDeleteMonitoredItemsResponse(ServiceTransactionDeleteMonitoredItems::SPtr serviceTransactionDeleteMonitoredItems);
	    virtual void monitoredItemServiceModifyMonitoredItemsResponse(ServiceTransactionModifyMonitoredItems::SPtr serviceTransactionModifyMonitoredItems);
	    virtual void monitoredItemServiceSetMonitoringModeResponse(ServiceTransactionSetMonitoringMode::SPtr serviceTransactionSetMonitoringMode);
	    virtual void monitoredItemServiceSetTriggeringResponse(ServiceTransactionSetTriggering::SPtr serviceTransactionSetTriggering);
		//- MonitoredItemServiceIf --------------------------------------------

	  private:
		void init(void);
		void openMonitoredItems(void);
		void cleanUpMonitoredItems(void);
		void deleteMonitoredItems(void);

		// configuration parameters
		IOThread::SPtr ioThread_;
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
