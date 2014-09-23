#ifndef __OpcUaStackServer_MonitoredItemService_h__
#define __OpcUaStackServer_MonitoredItemService_h__

#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/ServiceSet/ServiceTransactionIf.h"
#include "OpcUaStackCore/ServiceSet/MonitoredItemServiceTransaction.h"
#include "OpcUaStackServer/ServiceSet/ServiceSetBase.h"

using namespace OpcUaStackCore;

namespace OpcUaStackServer
{

	class DLLEXPORT MonitoredItemService 
	: public ServiceSetBase
	, public ServiceTransactionIf
	, public ObjectPool<MonitoredItemService>
	{
	  public:
		MonitoredItemService(void);
		~MonitoredItemService(void);

		//- ServiceTransactionIf ------------------------------------------------------
		void receive(OpcUaNodeId& typeId, ServiceTransaction::SPtr serviceTransaction);
		//- ServiceTransactionIf ------------------------------------------------------

	  private:
		void receiveCreateMonitoredItemsRequest(OpcUaNodeId& typeId, ServiceTransaction::SPtr serviceTransaction);
		void receiveDeleteMonitoredItemsRequest(OpcUaNodeId& typeId, ServiceTransaction::SPtr serviceTransaction);
		void receiveModifyMonitoredItemsRequest(OpcUaNodeId& typeId, ServiceTransaction::SPtr serviceTransaction);
		void receiveSetmonitoringModeRequest(OpcUaNodeId& typeId, ServiceTransaction::SPtr serviceTransaction);
		void receiveSetTriggeringRequest(OpcUaNodeId& typeId, ServiceTransaction::SPtr serviceTransaction);

	};

}

#endif