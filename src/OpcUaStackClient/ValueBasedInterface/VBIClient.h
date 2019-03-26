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

#ifndef __OpcUaStackClient_VBIClient_h__
#define __OpcUaStackClient_VBIClient_h__

#include <boost/date_time/posix_time/posix_time.hpp>
#include "OpcUaStackClient/ServiceSet/ServiceSetManager.h"
#include "OpcUaStackClient/ValueBasedInterface/VBIContext.h"
#include "OpcUaStackClient/ValueBasedInterface/VBITransaction.h"
#include "OpcUaStackClient/ServiceSet/ViewServiceBrowse.h"

using namespace OpcUaStackCore;
using namespace OpcUaStackClient;

namespace OpcUaStackClient
{

	class DLLEXPORT VBIClient
	{
	  public:
		VBIClient(void);
		~VBIClient(void);

		typedef std::function<
			void (SessionBase& session, SessionServiceStateId sessionState)
		> SessionChangeHandler;
		typedef std::function<
			void (SubscriptionState subscriptionState, uint32_t subscriptionId)
		> SubscriptionChangeHandler;
		typedef std::function<
			void (OpcUaUInt32 clientHandle, OpcUaDataValue& dataValue)
		> DataChangeHandler;

		void ioThreadName(const std::string& ioThreadName);

		// --------------------------------------------------------------------
		// --------------------------------------------------------------------
		//
		// SessionService
		//
		// --------------------------------------------------------------------
		// --------------------------------------------------------------------
		void setSessionChangeHandler(SessionChangeHandler sessionChangeHandler);

		OpcUaStatusCode syncConnect(ConnectContext& connectContext);
		void asyncConnect(ConnectContext& connectContext);

		OpcUaStatusCode syncDisconnect(void);
		void asyncDisconnect(void);


		// --------------------------------------------------------------------
		// --------------------------------------------------------------------
		//
		// AttributeService
		//
		// --------------------------------------------------------------------
		// --------------------------------------------------------------------

		// read
		ReadContext& defaultReadContext(void);
		OpcUaStatusCode syncRead(
			OpcUaNodeId& nodeId,
			OpcUaDataValue& dataValue
		);
		OpcUaStatusCode syncRead(
			OpcUaNodeId& nodeId,
			OpcUaDataValue& dataValue,
			ReadContext& readContext
		);
		void asyncRead(
			OpcUaNodeId& nodeId,
			const VBITransactionRead::VBIResultHandler& resultHandler
		);
		void asyncRead(
			OpcUaNodeId& nodeId,
			const VBITransactionRead::VBIResultHandler& resultHandler,
			ReadContext& readContext
		);


		// write
		WriteContext& defaultWriteContext(void);
		OpcUaStatusCode syncWrite(
			OpcUaNodeId& nodeId,
			OpcUaDataValue& dataValue
		);
		OpcUaStatusCode syncWrite(
			OpcUaNodeId& nodeId,
			OpcUaDataValue& dataValue,
			WriteContext& writeContext
		);
		void asyncWrite(
			OpcUaNodeId& nodeId,
			OpcUaDataValue& dataValue,
			const VBITransactionWrite::VBIResultHandler& resultHandler
		);
		void asyncWrite(
			OpcUaNodeId& nodeId,
			OpcUaDataValue& dataValue,
			const VBITransactionWrite::VBIResultHandler& resultHandler,
			WriteContext& writeContext
		);

		// history read
		HistoryReadContext& defaultHistoryReadContext(void);
		OpcUaStatusCode syncHistoryRead(
			OpcUaNodeId& nodeId,
			boost::posix_time::ptime startTime,
			boost::posix_time::ptime endTime,
			std::vector<OpcUaDataValue::SPtr>& dataValueVec
		);
		OpcUaStatusCode syncHistoryRead(
			OpcUaNodeId& nodeId,
			boost::posix_time::ptime startTime,
			boost::posix_time::ptime endTime,
			HistoryReadContext& historyReadContext,
			std::vector<OpcUaDataValue::SPtr>& dataValueVec
		);
		void asyncHistoryRead(
			OpcUaNodeId& nodeId,
			boost::posix_time::ptime startTime,
			boost::posix_time::ptime endTime,
			const VBITransactionHistoryRead::VBIResultHandler& resultHandler
		);
		void asyncHistoryRead(
			OpcUaNodeId& nodeId,
			boost::posix_time::ptime startTime,
			boost::posix_time::ptime endTime,
			const VBITransactionHistoryRead::VBIResultHandler& resultHandler,
			HistoryReadContext& historyReadContext
		);

		// history write
		// FIXME: todo


		// --------------------------------------------------------------------
		// --------------------------------------------------------------------
		//
		// SubscriptionService
		//
		// --------------------------------------------------------------------
		// --------------------------------------------------------------------
		void setSubscriptionChangeHandler(const SubscriptionChangeHandler& subscriptionChangeHandler);
		void setDataChangeHandler(const DataChangeHandler& dataChangeHandler);

		// create subscription
		CreateSubscriptionContext& defaultCreateSubscriptionContext(void);
		OpcUaStatusCode syncCreateSubscription(
			uint32_t& subscriptionId
		);
		OpcUaStatusCode syncCreateSubscription(
			uint32_t& subscriptionId,
			CreateSubscriptionContext& createSubscriptionContext
		);
		void asyncCreateSubscription(
			const VBITransactionCreateSubscription::VBIResultHandler& resultHandler
		);
		void asyncCreateSubscription(
			const VBITransactionCreateSubscription::VBIResultHandler& resultHandler,
			CreateSubscriptionContext& createSubscriptionContext
		);

		// delete subscription
		DeleteSubscriptionContext& defaultDeleteSubscriptionContext(void);
		OpcUaStatusCode syncDeleteSubscription(
			uint32_t subscriptionId
		);
		OpcUaStatusCode syncDeleteSubscription(
			uint32_t subscriptionId,
			DeleteSubscriptionContext& deleteSubscriptionContext
		);
		void asyncDeleteSubscription(
			uint32_t subscriptionId,
			const VBITransactionDeleteSubscription::VBIResultHandler& resultHandler
		);
		void asyncDeleteSubscription(
			uint32_t subscriptionId,
			const VBITransactionDeleteSubscription::VBIResultHandler& resultHandler,
			DeleteSubscriptionContext& deleteSubscriptionContext
		);

		// modify subscription
		// FIXME: todo

		// transfer subscription
		// FIXME: todo


		// --------------------------------------------------------------------
		// --------------------------------------------------------------------
		//
		// MonitoredItemService
		//
		// --------------------------------------------------------------------
		// --------------------------------------------------------------------

		// create monitored item
		CreateMonitoredItemContext& defaultCreateMonitoredItemContext(void);
		OpcUaStatusCode syncCreateMonitoredItem(
			OpcUaNodeId& nodeId,
			uint32_t subscriptionId,
			uint32_t clientHandle,
			uint32_t& monitoredItemId
		);
		OpcUaStatusCode syncCreateMonitoredItem(
			OpcUaNodeId& nodeId,
			uint32_t subscriptionId,
			uint32_t clientHandle,
			uint32_t& monitoredItemId,
			CreateMonitoredItemContext& createMonitoredItemContext
		);
		void asyncCreateMonitoredItem(
			OpcUaNodeId& nodeId,
			uint32_t subscriptionId, uint32_t
			clientHandle,
			const VBITransactionCreateMonitoredItem::VBIResultHandler& resultHandler
		);
		void asyncCreateMonitoredItem(
			OpcUaNodeId& nodeId,
			uint32_t subscriptionId,
			uint32_t clientHandle,
			const VBITransactionCreateMonitoredItem::VBIResultHandler& resultHandler,
			CreateMonitoredItemContext& createMonitoredItemContext
		);

		// delete monitored item
		DeleteMonitoredItemContext& defaultDeleteMonitoredItemContext(void);
		OpcUaStatusCode syncDeleteMonitoredItem(
			uint32_t subscriptionId,
			uint32_t monitoredItemId
		);
		OpcUaStatusCode syncDeleteMonitoredItem(
			uint32_t subscriptionId,
			uint32_t monitoredItemId,
			DeleteMonitoredItemContext& deleteMonitoredItemContext
		);
		void asyncDeleteMonitoredItem(
			uint32_t subscriptionId,
			uint32_t monitoredItemId,
			const VBITransactionDeleteMonitoredItem::VBIResultHandler& resultHandler
		);
		void asyncDeleteMonitoredItem(
			uint32_t subscriptionId,
			uint32_t monitoredItemId,
			const VBITransactionDeleteMonitoredItem::VBIResultHandler& resultHandler,
			DeleteMonitoredItemContext& deleteMonitoredItemContext
		);

		// modify monitored item
		// FIXME: todo

		// set monitoring mode
		// FIXME: todo

		// set triggering
		// FIXME: todo

		// --------------------------------------------------------------------
		// --------------------------------------------------------------------
		//
		// ViewServiceBrowse
		//
		// --------------------------------------------------------------------
		// --------------------------------------------------------------------

		OpcUaStatusCode syncViewServiceBrowse(OpcUaNodeId::SPtr& nodeId, ReferenceDescriptionArray::SPtr& references);

	  private:

        void attributeServiceReadResponse(ServiceTransactionRead::SPtr serviceTransactionRead);
		void attributeServiceWriteResponse(ServiceTransactionWrite::SPtr serviceTransactionWrite);
		void attributeServiceHistoryReadResponse(ServiceTransactionHistoryRead::SPtr serviceTransactionHistoryRead);
		void attributeServiceHistoryUpdateResponse(ServiceTransactionHistoryUpdate::SPtr serviceTransactionHistoryUpdate);

		void subscriptionServiceCreateSubscriptionResponse(ServiceTransactionCreateSubscription::SPtr serviceTransactionCreateSubscription);
		void subscriptionServiceModifySubscriptionResponse(ServiceTransactionModifySubscription::SPtr serviceTransactionModifySubscription);
		void subscriptionServiceTransferSubscriptionsResponse(ServiceTransactionTransferSubscriptions::SPtr serviceTransactionTransferSubscriptions);
		void subscriptionServiceDeleteSubscriptionsResponse(ServiceTransactionDeleteSubscriptions::SPtr serviceTransactionDeleteSubscriptions);
		void dataChangeNotification(const MonitoredItemNotification::SPtr& monitoredItem);
	    void subscriptionStateUpdate(SubscriptionState subscriptionState, uint32_t subscriptionId);

	    void monitoredItemServiceCreateMonitoredItemsResponse(ServiceTransactionCreateMonitoredItems::SPtr serviceTransactionCreateMonitoredItems);
	    void monitoredItemServiceDeleteMonitoredItemsResponse(ServiceTransactionDeleteMonitoredItems::SPtr serviceTransactionDeleteMonitoredItems);
	    void monitoredItemServiceModifyMonitoredItemsResponse(ServiceTransactionModifyMonitoredItems::SPtr serviceTransactionModifyMonitoredItems);
	    void monitoredItemServiceSetMonitoringModeResponse(ServiceTransactionSetMonitoringMode::SPtr serviceTransactionSetMonitoringMode);
	    void monitoredItemServiceSetTriggeringResponse(ServiceTransactionSetTriggering::SPtr serviceTransactionSetTriggering);

		ServiceSetManager serviceSetManager_;
		std::string ioThreadName_;

		SessionService::SPtr sessionService_;
		AttributeService::SPtr attributeService_;
		SubscriptionService::SPtr subscriptionService_;
		MonitoredItemService::SPtr monitoredItemService_;
		ViewService::SPtr viewService_;

		DataChangeHandler dataChangeHandler_;
		SubscriptionChangeHandler subscriptionChangeHandler_;
		SessionChangeHandler sessionChangeHandler_;

		ReadContext defaultReadContext_;
		WriteContext defaultWriteContext_;
		HistoryReadContext defaultHistoryReadContext_;
		CreateSubscriptionContext defaultCreateSubscriptionContext_;
		DeleteSubscriptionContext defaultDeleteSubscriptionContext_;
		CreateMonitoredItemContext defaultCreateMonitoredItemContext_;
		DeleteMonitoredItemContext defaultDeleteMonitoredItemContext_;
	};

}

#endif
