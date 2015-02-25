#ifndef __OpcUaStackServer_MonitorManager_h__
#define __OpcUaStackServer_MonitorManager_h__

#include <stdint.h>

#include "OpcUaStackCore/BuildInTypes/OpcUaStatusCode.h"
#include "OpcUaStackCore/ServiceSet/MonitoredItemServiceTransaction.h"
#include "OpcUaStackCore/Base/IOService.h"
#include "OpcUaStackCore/Utility/SlotTimer.h"
#include "OpcUaStackCore/ServiceSet/MonitoredItemNotification.h"
#include "OpcUaStackServer/ServiceSet/MonitorItem.h"
#include "OpcUaStackServer/InformationModel/InformationModel.h"

using namespace OpcUaStackCore;

namespace OpcUaStackServer
{

	class MonitorManager
	{
	  public:
		MonitorManager(void);
		~MonitorManager(void);

		void ioService(IOService* ioService);
		void subscriptionId(uint32_t subscriptionId);
		uint32_t subscriptionId(void);
		void informationModel(InformationModel::SPtr informationModel);
		uint32_t noticicationNumber(void);
		bool notificationAvailable(void);

		OpcUaStatusCode receive(ServiceTransactionCreateMonitoredItems::SPtr trx);
		OpcUaStatusCode receive(ServiceTransactionDeleteMonitoredItems::SPtr trx);
		OpcUaStatusCode receive(ServiceTransactionModifyMonitoredItems::SPtr trx);
		OpcUaStatusCode receive(ServiceTransactionSetMonitoringMode::SPtr trx);
		OpcUaStatusCode receive(ServiceTransactionSetTriggering::SPtr trx);
		OpcUaStatusCode receive(MonitoredItemNotificationArray::SPtr monitoredItemNotificationArray);

	  private:
		void sampleTimeout(MonitorItem::SPtr monitorItem);

		IOService* ioService_;
		uint32_t subscriptionId_;
		MonitorItemMap monitorItemMap_;
		InformationModel::SPtr informationModel_;
		SlotTimer::SPtr slotTimer_;
	};

}

#endif