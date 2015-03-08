#ifndef __OpcUaStackServer_MonitoredItemService_h__
#define __OpcUaStackServer_MonitoredItemService_h__

#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/ServiceSet/MonitoredItemServiceTransaction.h"
#include "OpcUaStackServer/ServiceSet/ServiceSetBase.h"

using namespace OpcUaStackCore;

namespace OpcUaStackServer
{

	class DLLEXPORT MonitoredItemService 
	: public ServiceSetBase
	, public ObjectPool<MonitoredItemService>
	{
	  public:
		typedef boost::shared_ptr<MonitoredItemService> SPtr;

		MonitoredItemService(void);
		~MonitoredItemService(void);

		//- Component -----------------------------------------------------------------
		void receive(Message::SPtr message);
		//- Component -----------------------------------------------------------------

	  private:
		void receiveCreateMonitoredItemsRequest(ServiceTransaction::SPtr serviceTransaction);
		void receiveDeleteMonitoredItemsRequest(ServiceTransaction::SPtr serviceTransaction);
		void receiveModifyMonitoredItemsRequest(ServiceTransaction::SPtr serviceTransaction);
		void receiveSetmonitoringModeRequest(ServiceTransaction::SPtr serviceTransaction);
		void receiveSetTriggeringRequest(ServiceTransaction::SPtr serviceTransaction);

	};

}

#endif
