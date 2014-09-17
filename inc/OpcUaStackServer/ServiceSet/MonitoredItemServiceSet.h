#ifndef __OpcUaStackServer_MonitoredItemServiceSet_h__
#define __OpcUaStackServer_MonitoredItemServiceSet_h__

#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/ServiceSet/ServiceTransactionIf.h"
#include "OpcUaStackCore/ServiceSet/ServiceTransactionRead.h"

namespace OpcUaStackServer
{

	class DLLEXPORT MonitoredItemServiceSet : public ServiceTransactionIf
	{
	  public:
		MonitoredItemServiceSet(void);
		~MonitoredItemServiceSet(void);

		//- ServiceTransactionIf ------------------------------------------------------
		void receive(OpcUaNodeId& typeId, ServiceTransaction::SPtr serviceTransaction);
		//- ServiceTransactionIf ------------------------------------------------------

	  private:
	};

}

#endif