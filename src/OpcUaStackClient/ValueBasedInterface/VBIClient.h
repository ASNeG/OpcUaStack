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

#include "OpcUaStackClient/ServiceSet/ServiceSetManager.h"
#include "OpcUaStackClient/ValueBasedInterface/VBIContext.h"
#include "OpcUaStackClient/ServiceSet/ViewServiceBrowse.h"

using namespace OpcUaStackCore;
using namespace OpcUaStackClient;

namespace OpcUaStackClient
{

	class DLLEXPORT VBIClient
	: public SessionServiceIf
	, public AttributeServiceIf
	, public SubscriptionServiceIf
	, public MonitoredItemServiceIf
	{
	  public:
		VBIClient(void);
		~VBIClient(void);

		typedef std::function<
			void (SessionBase& session, SessionServiceStateId sessionState)
		> SessionChangeHandler;

		void ioThreadName(const std::string& ioThreadName);

		// --------------------------------------------------------------------
		// --------------------------------------------------------------------
		//
		// SessionService
		//
		// --------------------------------------------------------------------
		// --------------------------------------------------------------------
		template<typename HANDLER>
		  //[[deprecated("Replace by setSessionChangeHandler")]]
		  void setSessionChangeCallback(HANDLER handler) {
			  Callback callback = handler;
			  setSessionChangeCallback(callback);
		  }
		[[deprecated("Replace by setSessionChangeHandler")]]
		void setSessionChangeCallback(Callback& callback);
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
		OpcUaStatusCode syncRead(OpcUaNodeId& nodeId, OpcUaDataValue& dataValue);
		OpcUaStatusCode syncRead(OpcUaNodeId& nodeId, OpcUaDataValue& dataValue, ReadContext& readContext);
		void asyncRead(OpcUaNodeId& nodeId, Callback& callback);
		template<typename HANDLER>
		    void asyncRead(OpcUaNodeId& nodeId, HANDLER handler) {
				Callback callback = handler;
				asyncRead(nodeId, callback);
			}
		void asyncRead(OpcUaNodeId& nodeId, Callback& callback, ReadContext& readContext);
		template<typename HANDLER>
			void asyncRead(OpcUaNodeId& nodeId, HANDLER handler, ReadContext& readContext) {
				Callback callback = handler;
				asyncRead(nodeId, callback, readContext);
			}


		// write
		WriteContext& defaultWriteContext(void);
		OpcUaStatusCode syncWrite(OpcUaNodeId& nodeId, OpcUaDataValue& dataValue);
		OpcUaStatusCode syncWrite(OpcUaNodeId& nodeId, OpcUaDataValue& dataValue, WriteContext& writeContext);
		void asyncWrite(OpcUaNodeId& nodeId, OpcUaDataValue& dataValue, Callback& callback);
		template<typename HANDLER>
		    void asyncWrite(OpcUaNodeId& nodeId, OpcUaDataValue& dataValue, HANDLER handler) {
				Callback callback = handler;
				asyncWrite(nodeId, dataValue, callback);
			}
		void asyncWrite(OpcUaNodeId& nodeId, OpcUaDataValue& dataValue, Callback& callback, WriteContext& writeContext);
		template<typename HANDLER>
		    void asyncWrite(OpcUaNodeId& nodeId, OpcUaDataValue& dataValue, HANDLER handler, WriteContext& writeContext) {
				Callback callback = handler;
				asyncWrite(nodeId, dataValue, callback, writeContext);
			}

		// history read
		// FIXME: todo

		// history write
		// FIXME: todo


		// --------------------------------------------------------------------
		// --------------------------------------------------------------------
		//
		// SubscriptionService
		//
		// --------------------------------------------------------------------
		// --------------------------------------------------------------------

		template<typename HANDLER>
		  void setSubscriptionChangeCallback(HANDLER handler) {
			  Callback callback = handler;
			  setSubscriptionChangeCallback(callback);
		  }
		void setSubscriptionChangeCallback(Callback& callback);
		template<typename HANDLER>
		  void setDataChangeCallback(HANDLER handler) {
			  Callback callback = handler;
			  setDataChangeCallback(callback);
		  }
		void setDataChangeCallback(Callback& callback);

		// create subscription
		CreateSubscriptionContext& defaultCreateSubscriptionContext(void);
		OpcUaStatusCode syncCreateSubscription(uint32_t& subscriptionId);
		OpcUaStatusCode syncCreateSubscription(uint32_t& subscriptionId, CreateSubscriptionContext& createSubscriptionContext);
		void asyncCreateSubscription(Callback& callback);
		template<typename HANDLER>
		    void asyncCreateSubscription(HANDLER handler) {
				Callback callback = handler;
				asyncCreateSubscription(callback);
			}
		void asyncCreateSubscription(Callback& callback, CreateSubscriptionContext& createSubscriptionContext);
		template<typename HANDLER>
		    void asyncCreateSubscription(HANDLER handler, CreateSubscriptionContext& createSubscriptionContext) {
				Callback callback = handler;
				asyncCreateSubscription(callback, createSubscriptionContext);
			}

		// delete subscription
		DeleteSubscriptionContext& defaultDeleteSubscriptionContext(void);
		OpcUaStatusCode syncDeleteSubscription(uint32_t subscriptionId);
		OpcUaStatusCode syncDeleteSubscription(uint32_t subscriptionId, DeleteSubscriptionContext& deleteSubscriptionContext);
		void asyncDeleteSubscription(uint32_t subscriptionId, Callback& callback);
		template<typename HANDLER>
		    void asyncDeleteSubscription(uint32_t subscriptionId, HANDLER handler) {
				Callback callback = handler;
				asyncDeleteSubscription(subscriptionId, callback);
			}
		void asyncDeleteSubscription(uint32_t subscriptionId, Callback& callback, DeleteSubscriptionContext& deleteSubscriptionContext);
		template<typename HANDLER>
		    void asyncDeleteSubscription(uint32_t subscriptionId, HANDLER handler, DeleteSubscriptionContext& deleteSubscriptionContext) {
				Callback callback = handler;
				asyncDeleteSubscription(subscriptionId, callback, deleteSubscriptionContext);
			}

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
		OpcUaStatusCode syncCreateMonitoredItem(OpcUaNodeId& nodeId, uint32_t subscriptionId, uint32_t clientHandle, uint32_t& monitoredItemId);
		OpcUaStatusCode syncCreateMonitoredItem(OpcUaNodeId& nodeId, uint32_t subscriptionId, uint32_t clientHandle, uint32_t& monitoredItemId, CreateMonitoredItemContext& createMonitoredItemContext);
		void asyncCreateMonitoredItem(OpcUaNodeId& nodeId, uint32_t subscriptionId, uint32_t clientHandle, Callback& callback);
		template<typename HANDLER>
		    void asyncCreateMonitoredItem(OpcUaNodeId& nodeId, uint32_t subscriptionId, uint32_t clientHandle, HANDLER handler) {
				Callback callback = handler;
				asyncCreateMonitoredItem(nodeId, subscriptionId, clientHandle, callback);
			}
		void asyncCreateMonitoredItem(OpcUaNodeId& nodeId, uint32_t subscriptionId, uint32_t clientHandle, Callback& callback, CreateMonitoredItemContext& createMonitoredItemContext);
		template<typename HANDLER>
		    void asyncCreateMonitoredItem(OpcUaNodeId& nodeId, uint32_t subscriptionId, uint32_t clientHandle, HANDLER handler, CreateMonitoredItemContext& createMonitoredItemContext) {
				Callback callback = handler;
				asyncCreateMonitoredItem(nodeId, subscriptionId, clientHandle, callback, createMonitoredItemContext);
			}

		// delete monitored item
		DeleteMonitoredItemContext& defaultDeleteMonitoredItemContext(void);
		OpcUaStatusCode syncDeleteMonitoredItem(uint32_t subscriptionId, uint32_t monitoredItemId);
		OpcUaStatusCode syncDeleteMonitoredItem(uint32_t subscriptionId, uint32_t monitoredItemId, DeleteMonitoredItemContext& deleteMonitoredItemContext);
		void asyncDeleteMonitoredItem(uint32_t subscriptionId, uint32_t monitoredItemId, Callback& callback);
		template<typename HANDLER>
		    void asyncDeleteMonitoredItem(uint32_t subscriptionId, uint32_t monitoredItemId, HANDLER handler) {
				Callback callback = handler;
				asyncDeleteMonitoredItem(subscriptionId, monitoredItemId, callback);
			}
		void asyncDeleteMonitoredItem(uint32_t subscriptionId, uint32_t monitoredItemId, Callback& callback, DeleteMonitoredItemContext& deleteMonitoredItemContext);
		template<typename HANDLER>
		    void asyncDeleteMonitoredItem(uint32_t subscriptionId, uint32_t monitoredItemId, HANDLER handler, DeleteMonitoredItemContext& deleteMonitoredItemContext) {
				Callback callback = handler;
				asyncDeleteMonitoredItem(subscriptionId, monitoredItemId, callback, deleteMonitoredItemContext);
			}

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
		// BEGIN SessionServiceIf
		void sessionStateUpdate(SessionBase& session, SessionServiceStateId sessionState);
		// END SessionServiceIf

		// BEGIN AttributeServiceIf
        void attributeServiceReadResponse(ServiceTransactionRead::SPtr serviceTransactionRead);
		void attributeServiceWriteResponse(ServiceTransactionWrite::SPtr serviceTransactionWrite);
		void attributeServiceHistoryReadResponse(ServiceTransactionHistoryRead::SPtr serviceTransactionHistoryRead);
		void attributeServiceHistoryUpdateResponse(ServiceTransactionHistoryUpdate::SPtr serviceTransactionHistoryUpdate);
		// END AttributeServiceIf

		// BEGIN SubscriptionServiceIf
		void subscriptionServiceCreateSubscriptionResponse(ServiceTransactionCreateSubscription::SPtr serviceTransactionCreateSubscription);
		void subscriptionServiceModifySubscriptionResponse(ServiceTransactionModifySubscription::SPtr serviceTransactionModifySubscription);
		void subscriptionServiceTransferSubscriptionsResponse(ServiceTransactionTransferSubscriptions::SPtr serviceTransactionTransferSubscriptions);
		void subscriptionServiceDeleteSubscriptionsResponse(ServiceTransactionDeleteSubscriptions::SPtr serviceTransactionDeleteSubscriptions);
		void dataChangeNotification(const MonitoredItemNotification::SPtr& monitoredItem);
	    void subscriptionStateUpdate(SubscriptionState subscriptionState, uint32_t subscriptionId);
		// END SubscriptionServiceIf

	    // BEGIN MonitoredItemServiceIf
	    void monitoredItemServiceCreateMonitoredItemsResponse(ServiceTransactionCreateMonitoredItems::SPtr serviceTransactionCreateMonitoredItems);
	    void monitoredItemServiceDeleteMonitoredItemsResponse(ServiceTransactionDeleteMonitoredItems::SPtr serviceTransactionDeleteMonitoredItems);
	    void monitoredItemServiceModifyMonitoredItemsResponse(ServiceTransactionModifyMonitoredItems::SPtr serviceTransactionModifyMonitoredItems);
	    void monitoredItemServiceSetMonitoringModeResponse(ServiceTransactionSetMonitoringMode::SPtr serviceTransactionSetMonitoringMode);
	    void monitoredItemServiceSetTriggeringResponse(ServiceTransactionSetTriggering::SPtr serviceTransactionSetTriggering);
	    // END MonitoredItemServiceIf

		ServiceSetManager serviceSetManager_;
		std::string ioThreadName_;

		SessionService::SPtr sessionService_;
		AttributeService::SPtr attributeService_;
		SubscriptionService::SPtr subscriptionService_;
		MonitoredItemService::SPtr monitoredItemService_;
		ViewService::SPtr viewService_;

		Callback sessionCompleteCallback_;

		Callback sessionChangeCallback_;
		Callback subscriptionChangeCallback_;
		Callback dataChangeCallback_;

		SessionChangeHandler sessionChangeHandler_;

		ReadContext defaultReadContext_;
		WriteContext defaultWriteContext_;
		CreateSubscriptionContext defaultCreateSubscriptionContext_;
		DeleteSubscriptionContext defaultDeleteSubscriptionContext_;
		CreateMonitoredItemContext defaultCreateMonitoredItemContext_;
		DeleteMonitoredItemContext defaultDeleteMonitoredItemContext_;
	};

}

#endif
