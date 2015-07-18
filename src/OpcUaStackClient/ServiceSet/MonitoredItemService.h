#ifndef __OpcUaStackClient_MonitoredItemService_h__
#define __OpcUaStackClient_MonitoredItemService_h__

#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/Component/Component.h"
#include "OpcUaStackCore/ServiceSet/MonitoredItemServiceTransaction.h"
#include "OpcUaStackClient/ServiceSet/Session.h"

using namespace OpcUaStackCore;

namespace OpcUaStackClient
{

	class DLLEXPORT MonitoredItemServiceIf
	{
	  public:
		virtual ~MonitoredItemServiceIf(void) {}

        virtual void monitoredItemServiceCreateMonitoredItemsResponse(ServiceTransactionCreateMonitoredItems::SPtr serviceTransactionCreateMonitoredItems) {};
        virtual void monitoredItemServiceDeleteMonitoredItemsResponse(ServiceTransactionDeleteMonitoredItems::SPtr serviceTransactionDeleteMonitoredItems) {};
        virtual void monitoredItemServiceModifyMonitoredItemsResponse(ServiceTransactionModifyMonitoredItems::SPtr serviceTransactionModifyMonitoredItems) {};
        virtual void monitoredItemServiceSetMonitoringModeResponse(ServiceTransactionSetMonitoringMode::SPtr serviceTransactionSetMonitoringMode) {};
        virtual void monitoredItemServiceSetTriggeringResponse(ServiceTransactionSetTriggering::SPtr serviceTransactionSetTriggering) {};
	};

	class DLLEXPORT MonitoredItemService
	: public Component
	{
	  public:
		boost::shared_ptr<MonitoredItemService> SPtr;

		MonitoredItemService(void);
		~MonitoredItemService(void);

		void componentSession(Component* componentSession);
		void monitoredItemServiceIf(MonitoredItemServiceIf* monitoredItemServiceIf);

		void sendSync(ServiceTransactionCreateMonitoredItems::SPtr serviceTransactionCreateMonitoredItems);
		void send(ServiceTransactionCreateMonitoredItems::SPtr serviceTransactionCreateMonitoredItems);
		void sendSync(ServiceTransactionDeleteMonitoredItems::SPtr serviceTransactionDeleteMonitoredItems);
		void send(ServiceTransactionDeleteMonitoredItems::SPtr serviceTransactionDeleteMonitoredItems);
		void sendSync(ServiceTransactionModifyMonitoredItems::SPtr serviceTransactionModifyMonitoredItems);
		void send(ServiceTransactionModifyMonitoredItems::SPtr serviceTransactionModifyMonitoredItems);
		void sendSync(ServiceTransactionSetMonitoringMode::SPtr serviceTransactionSetMonitoringMode);
		void send(ServiceTransactionSetMonitoringMode::SPtr serviceTransactionSetMonitoringMode);
		void sendSync(ServiceTransactionSetTriggering::SPtr serviceTransactionSetTriggering);
		void send(ServiceTransactionSetTriggering::SPtr serviceTransactionSetTriggering);

		//- Component -----------------------------------------------------------------
		void receive(OpcUaNodeId& typeId, Message::SPtr message);
		//- Component -----------------------------------------------------------------

	  private:
		Component* componentSession_;

		MonitoredItemServiceIf* monitoredItemServiceIf_;
	};

}

#endif
