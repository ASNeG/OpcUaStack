/*
   Copyright 2015-2018 Kai Huebl (kai@huebl-sgh.de)

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

#ifndef __OpcUaStackServer_MonitorManager_h__
#define __OpcUaStackServer_MonitorManager_h__

#include <stdint.h>

#include "OpcUaStackCore/BuildInTypes/OpcUaStatusCode.h"
#include "OpcUaStackCore/ServiceSet/MonitoredItemServiceTransaction.h"
#include "OpcUaStackCore/Base/IOService.h"
#include "OpcUaStackCore/Utility/SlotTimer.h"
#include "OpcUaStackCore/ServiceSetApplication/ForwardGlobalSync.h"
#include "OpcUaStackCore/ServiceSet/MonitoredItemNotification.h"
#include "OpcUaStackServer/ServiceSet/MonitorItem.h"
#include "OpcUaStackServer/ServiceSet/EventItem.h"
#include "OpcUaStackServer/InformationModel/InformationModel.h"

using namespace OpcUaStackCore;

namespace OpcUaStackServer
{

	class MonitorManager
	{
	  public:
		typedef std::map<OpcUaNodeId,std::vector<uint32_t> > MonitoredItemIds;

		MonitorManager(void);
		~MonitorManager(void);

		void ioThread(IOThread* ioThread);
		void subscriptionId(uint32_t subscriptionId);
		uint32_t subscriptionId(void);
		void informationModel(InformationModel::SPtr informationModel);
		void forwardGlobalSync(ForwardGlobalSync::SPtr& forwardGlobalSync);
		uint32_t noticicationNumber(void);
		bool notificationAvailable(void);


		OpcUaStatusCode receive(ServiceTransactionCreateMonitoredItems::SPtr trx);
		OpcUaStatusCode receive(ServiceTransactionDeleteMonitoredItems::SPtr trx);
		OpcUaStatusCode receive(ServiceTransactionModifyMonitoredItems::SPtr trx);
		OpcUaStatusCode receive(ServiceTransactionSetMonitoringMode::SPtr trx);
		OpcUaStatusCode receive(ServiceTransactionSetTriggering::SPtr trx);
		OpcUaStatusCode receive(MonitoredItemNotificationArray::SPtr monitoredItemNotificationArray);
		OpcUaStatusCode receive(EventFieldListArray::SPtr eventFieldListArray);

	  private:
		void createMonitoredItem(
			uint32_t idx,
			ServiceTransactionCreateMonitoredItems::SPtr& trx,
			CreateMonitoredItemsRequest::SPtr& createMonitorItemRequest,
			CreateMonitoredItemsResponse::SPtr& createMonitorItemResponse
		);
		void createEventItem(
			uint32_t idx,
			ServiceTransactionCreateMonitoredItems::SPtr& trx,
			CreateMonitoredItemsRequest::SPtr& createMonitorItemRequest,
			CreateMonitoredItemsResponse::SPtr& createMonitorItemResponse
		);
		void forwardStartMonitoredItem(BaseNodeClass::SPtr baseNodeClass, uint32_t monitoredItemId);
		void forwardStopMonitoredItem(BaseNodeClass::SPtr baseNodeClass, uint32_t monitoredItemId);
		void sampleTimeout(MonitorItem::SPtr monitorItem);

		IOThread* ioThread_;
		uint32_t subscriptionId_;
		MonitorItemMap monitorItemMap_;
		EventItem::Map eventItemMap_;
		InformationModel::SPtr informationModel_;
		ForwardGlobalSync::SPtr forwardGlobalSync_;

		MonitoredItemIds monitoredItemIds_;
	};

}

#endif
