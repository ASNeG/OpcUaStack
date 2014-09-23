#ifndef __OpcUaStackServer_QueryService_h__
#define __OpcUaStackServer_QueryService_h__

#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/ServiceSet/ServiceTransactionIf.h"
#include "OpcUaStackCore/ServiceSet/QueryServiceTransaction.h"
#include "OpcUaStackServer/ServiceSet/ServiceSetBase.h"

using namespace OpcUaStackCore;

namespace OpcUaStackServer
{

	class DLLEXPORT QueryService 
	: public ServiceSetBase
	, public ServiceTransactionIf
	, public ObjectPool<QueryService>
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