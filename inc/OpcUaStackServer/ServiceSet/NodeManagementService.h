#ifndef __OpcUaStackServer_NodeManagementService_h__
#define __OpcUaStackServer_NodeManagementService_h__

#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/ServiceSet/ServiceTransactionIf.h"
#include "OpcUaStackCore/ServiceSet/ServiceTransactionRead.h"

namespace OpcUaStackServer
{

	class DLLEXPORT NodeManagementService : public ServiceTransactionIf
	{
	  public:
		NodeManagementService(void);
		~NodeManagementService(void);

		//- ServiceTransactionIf ------------------------------------------------------
		void receive(OpcUaNodeId& typeId, ServiceTransaction::SPtr serviceTransaction);
		//- ServiceTransactionIf ------------------------------------------------------

	  private:
		void receiveAddNodesRequest(OpcUaNodeId& typeId, ServiceTransaction::SPtr serviceTransaction);
		void receiveAddReferencesRequest(OpcUaNodeId& typeId, ServiceTransaction::SPtr serviceTransaction);
		void receiveDeleteNodesRequest(OpcUaNodeId& typeId, ServiceTransaction::SPtr serviceTransaction);
		void receiveDeleteReferencesRequest(OpcUaNodeId& typeId, ServiceTransaction::SPtr serviceTransaction);
	};

}

#endif