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

   Autor: Kai Huebl (kai@huebl-sgh.de), Aleksey Timin (atimin@gmail.com)
 */

#ifndef __OpcUaStackServer_MonitorManager_h__
#define __OpcUaStackServer_MonitorManager_h__

#include <stdint.h>

#include "OpcUaStackCore/BuildInTypes/OpcUaStatusCode.h"
#include "OpcUaStackCore/ServiceSet/MonitoredItemServiceTransaction.h"
#include "OpcUaStackCore/Base/IOService.h"
#include "OpcUaStackCore/Utility/SlotTimer.h"
#include "OpcUaStackCore/StandardDataTypes/MonitoredItemNotification.h"
#include "OpcUaStackServer/ServiceSetApplication/ForwardGlobalSync.h"
#include "OpcUaStackServer/ServiceSet/MonitorItem.h"
#include "OpcUaStackServer/ServiceSet/EventItem.h"
#include "OpcUaStackServer/InformationModel/InformationModel.h"

namespace OpcUaStackServer
{

	class DLLEXPORT MonitorManager
	{
	  public:
		using MonitoredItemIdVector = std::map<OpcUaStackCore::OpcUaNodeId,std::vector<uint32_t> >;

		MonitorManager(void);
		~MonitorManager(void);

		void ioThread(OpcUaStackCore::IOThread* ioThread);
		void strand(boost::shared_ptr<boost::asio::io_service::strand>& strand);
		void subscriptionId(uint32_t subscriptionId);
		uint32_t subscriptionId(void);
		void informationModel(InformationModel::SPtr informationModel);
		void forwardGlobalSync(ForwardGlobalSync::SPtr& forwardGlobalSync);
		uint32_t noticicationNumber(void);
		bool notificationAvailable(void);

		MonitoredItemIdVector monitoredItemIds();


		OpcUaStackCore::OpcUaStatusCode receive(OpcUaStackCore::ServiceTransactionCreateMonitoredItems::SPtr& trx);
		OpcUaStackCore::OpcUaStatusCode receive(OpcUaStackCore::ServiceTransactionDeleteMonitoredItems::SPtr& trx);
		OpcUaStackCore::OpcUaStatusCode receive(OpcUaStackCore::ServiceTransactionModifyMonitoredItems::SPtr& trx);
		OpcUaStackCore::OpcUaStatusCode receive(OpcUaStackCore::ServiceTransactionSetMonitoringMode::SPtr& trx);
		OpcUaStackCore::OpcUaStatusCode receive(OpcUaStackCore::ServiceTransactionSetTriggering::SPtr& trx);
		OpcUaStackCore::OpcUaStatusCode receive(OpcUaStackCore::MonitoredItemNotificationArray& monitoredItemNotificationArray);
		OpcUaStackCore::OpcUaStatusCode receive(OpcUaStackCore::EventFieldListArray& eventFieldListArray);

	  private:
		OpcUaStackCore::OpcUaStatusCode forwardAutorizationCreateMonitoredItem(OpcUaStackCore::UserContext::SPtr& userContext, OpcUaStackCore::ReadValueId& readValueId);
		OpcUaStackCore::OpcUaStatusCode forwardAutorizationCreateEventItem(OpcUaStackCore::UserContext::SPtr& userContext, OpcUaStackCore::ReadValueId& readValueId);

		void createMonitoredItem(
			uint32_t idx,
			OpcUaStackCore::ServiceTransactionCreateMonitoredItems::SPtr& trx,
			OpcUaStackCore::CreateMonitoredItemsRequest::SPtr& createMonitorItemRequest,
			OpcUaStackCore::CreateMonitoredItemsResponse::SPtr& createMonitorItemResponse
		);
		void createEventItem(
			uint32_t idx,
			OpcUaStackCore::ServiceTransactionCreateMonitoredItems::SPtr& trx,
			OpcUaStackCore::CreateMonitoredItemsRequest::SPtr& createMonitorItemRequest,
			OpcUaStackCore::CreateMonitoredItemsResponse::SPtr& createMonitorItemResponse
		);
		void forwardStartMonitoredItem(
			OpcUaStackCore::UserContext::SPtr& userContext,
			BaseNodeClass::SPtr baseNodeClass,
			uint32_t monitoredItemId
		);
		void forwardStopMonitoredItem(
			OpcUaStackCore::UserContext::SPtr& userContext,
			BaseNodeClass::SPtr baseNodeClass,
			uint32_t monitoredItemId
		);
		void sampleTimeout(MonitorItem::SPtr monitorItem);

		OpcUaStackCore::IOThread* ioThread_ = nullptr;
		boost::shared_ptr<boost::asio::io_service::strand> strand_ = nullptr;
		uint32_t subscriptionId_;
		MonitorItemMap monitorItemMap_;
		EventItem::Map eventItemMap_;
		InformationModel::SPtr informationModel_;
		ForwardGlobalSync::SPtr forwardGlobalSync_;

		MonitoredItemIdVector monitoredItemIds_;
	};

}

#endif
