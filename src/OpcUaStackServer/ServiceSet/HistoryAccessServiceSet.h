#ifndef __OpcUaStackServer_HistoryAccessServiceSet_h__
#define __OpcUaStackServer_HistoryAccessServiceSet_h__

#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/ServiceSet/ServiceTransactionIf.h"
#include "OpcUaStackCore/ServiceSet/ServiceTransactionRead.h"

namespace OpcUaStackServer
{

	class DLLEXPORT HistoryAccessServiceSet : public ServiceTransactionIf
	{
	  public:
		HistoryAccessServiceSet(void);
		~HistoryAccessServiceSet(void);

		//- ServiceTransactionIf ------------------------------------------------------
		void receive(OpcUaNodeId& typeId, ServiceTransaction::SPtr serviceTransaction);
		//- ServiceTransactionIf ------------------------------------------------------

	  private:
	};

}

#endif