#ifndef __OpcUaStackServer_QueryService_h__
#define __OpcUaStackServer_QueryService_h__

#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/ServiceSet/ServiceTransactionIf.h"
#include "OpcUaStackCore/ServiceSet/ServiceTransactionRead.h"

namespace OpcUaStackServer
{

	class DLLEXPORT QueryService : public ServiceTransactionIf
	{
	  public:
		QueryService(void);
		~QueryService(void);

		//- ServiceTransactionIf ------------------------------------------------------
		void receive(OpcUaNodeId& typeId, ServiceTransaction::SPtr serviceTransaction);
		//- ServiceTransactionIf ------------------------------------------------------

	  private:
		void receiveQueryFirstRequest(OpcUaNodeId& typeId, ServiceTransaction::SPtr serviceTransaction);
		void receiveQueryNextRequest(OpcUaNodeId& typeId, ServiceTransaction::SPtr serviceTransaction);
	};

}

#endif