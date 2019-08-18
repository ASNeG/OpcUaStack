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
			void (OpcUaStackCore::OpcUaUInt32 clientHandle, OpcUaStackCore::OpcUaDataValue& dataValue)
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

		OpcUaStackCore::OpcUaStatusCode syncConnect(ConnectContext& connectContext);
		void asyncConnect(ConnectContext& connectContext);

		OpcUaStackCore::OpcUaStatusCode syncDisconnect(void);
		void asyncDisconnect(void);

		void deleteEndpointDescriptionCache(void);
		EndpointDescriptionCache& getEndpointDescriptionCache(void);


		// --------------------------------------------------------------------
		// --------------------------------------------------------------------
		//
		// AttributeService
		//
		// --------------------------------------------------------------------
		// --------------------------------------------------------------------

		// read
		ReadContext& defaultReadContext(void);
		OpcUaStackCore::OpcUaStatusCode syncRead(
			OpcUaStackCore::OpcUaNodeId& nodeId,
			OpcUaStackCore::OpcUaDataValue& dataValue
		);
		OpcUaStackCore::OpcUaStatusCode syncRead(
			OpcUaStackCore::OpcUaNodeId& nodeId,
			OpcUaStackCore::OpcUaDataValue& dataValue,
			ReadContext& readContext
		);
		void asyncRead(
			OpcUaStackCore::OpcUaNodeId& nodeId,
			const VBITransactionRead::VBIResultHandler& resultHandler
		);
		void asyncRead(
			OpcUaStackCore::OpcUaNodeId& nodeId,
			const VBITransactionRead::VBIResultHandler& resultHandler,
			ReadContext& readContext
		);


		// write
		WriteContext& defaultWriteContext(void);
		OpcUaStackCore::OpcUaStatusCode syncWrite(
			OpcUaStackCore::OpcUaNodeId& nodeId,
			OpcUaStackCore::OpcUaDataValue& dataValue
		);
		OpcUaStackCore::OpcUaStatusCode syncWrite(
			OpcUaStackCore::OpcUaNodeId& nodeId,
			OpcUaStackCore::OpcUaDataValue& dataValue,
			WriteContext& writeContext
		);
		void asyncWrite(
			OpcUaStackCore::OpcUaNodeId& nodeId,
			OpcUaStackCore::OpcUaDataValue& dataValue,
			const VBITransactionWrite::VBIResultHandler& resultHandler
		);
		void asyncWrite(
			OpcUaStackCore::OpcUaNodeId& nodeId,
			OpcUaStackCore::OpcUaDataValue& dataValue,
			const VBITransactionWrite::VBIResultHandler& resultHandler,
			WriteContext& writeContext
		);

		// history read
		HistoryReadContext& defaultHistoryReadContext(void);
		OpcUaStackCore::OpcUaStatusCode syncHistoryRead(
			const OpcUaStackCore::OpcUaNodeId& nodeId,
			boost::posix_time::ptime startTime,
			boost::posix_time::ptime endTime,
			std::vector<OpcUaStackCore::OpcUaDataValue::SPtr>& dataValueVec
		);
		OpcUaStackCore::OpcUaStatusCode syncHistoryRead(
			const OpcUaStackCore::OpcUaNodeId& nodeId,
			boost::posix_time::ptime startTime,
			boost::posix_time::ptime endTime,
			HistoryReadContext& historyReadContext,
			std::vector<OpcUaStackCore::OpcUaDataValue::SPtr>& dataValueVec
		);
		void asyncHistoryRead(
			const OpcUaStackCore::OpcUaNodeId& nodeId,
			boost::posix_time::ptime startTime,
			boost::posix_time::ptime endTime,
			const VBITransactionHistoryRead::VBIResultHandler& resultHandler
		);
		void asyncHistoryRead(
			const OpcUaStackCore::OpcUaNodeId& nodeId,
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
		OpcUaStackCore::OpcUaStatusCode syncCreateSubscription(
			uint32_t& subscriptionId
		);
		OpcUaStackCore::OpcUaStatusCode syncCreateSubscription(
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
		OpcUaStackCore::OpcUaStatusCode syncDeleteSubscription(
			uint32_t subscriptionId
		);
		OpcUaStackCore::OpcUaStatusCode syncDeleteSubscription(
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
		OpcUaStackCore::OpcUaStatusCode syncCreateMonitoredItem(
			OpcUaStackCore::OpcUaNodeId& nodeId,
			uint32_t subscriptionId,
			uint32_t clientHandle,
			uint32_t& monitoredItemId
		);
		OpcUaStackCore::OpcUaStatusCode syncCreateMonitoredItem(
			OpcUaStackCore::OpcUaNodeId& nodeId,
			uint32_t subscriptionId,
			uint32_t clientHandle,
			uint32_t& monitoredItemId,
			CreateMonitoredItemContext& createMonitoredItemContext
		);
		void asyncCreateMonitoredItem(
			OpcUaStackCore::OpcUaNodeId& nodeId,
			uint32_t subscriptionId, uint32_t
			clientHandle,
			const VBITransactionCreateMonitoredItem::VBIResultHandler& resultHandler
		);
		void asyncCreateMonitoredItem(
			OpcUaStackCore::OpcUaNodeId& nodeId,
			uint32_t subscriptionId,
			uint32_t clientHandle,
			const VBITransactionCreateMonitoredItem::VBIResultHandler& resultHandler,
			CreateMonitoredItemContext& createMonitoredItemContext
		);

		// delete monitored item
		DeleteMonitoredItemContext& defaultDeleteMonitoredItemContext(void);
		OpcUaStackCore::OpcUaStatusCode syncDeleteMonitoredItem(
			uint32_t subscriptionId,
			uint32_t monitoredItemId
		);
		OpcUaStackCore::OpcUaStatusCode syncDeleteMonitoredItem(
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

		OpcUaStackCore::OpcUaStatusCode syncViewServiceBrowse(OpcUaStackCore::OpcUaNodeId::SPtr& nodeId, OpcUaStackCore::ReferenceDescriptionArray::SPtr& references);

	  private:

        void attributeServiceReadResponse(OpcUaStackCore::ServiceTransactionRead::SPtr serviceTransactionRead);
		void attributeServiceWriteResponse(OpcUaStackCore::ServiceTransactionWrite::SPtr serviceTransactionWrite);
		void attributeServiceHistoryReadResponse(OpcUaStackCore::ServiceTransactionHistoryRead::SPtr serviceTransactionHistoryRead);
		void attributeServiceHistoryUpdateResponse(OpcUaStackCore::ServiceTransactionHistoryUpdate::SPtr serviceTransactionHistoryUpdate);

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
