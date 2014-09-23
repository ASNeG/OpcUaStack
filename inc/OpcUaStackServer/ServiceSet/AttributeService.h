#ifndef __OpcUaStackServer_AttributeService_h__
#define __OpcUaStackServer_AttributeService_h__

#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackServer/ServiceSet/ServiceSetBase.h"
#include "OpcUaStackCore/ServiceSet/ServiceTransactionIf.h"
#include "OpcUaStackCore/ServiceSet/AttributeServiceTransaction.h"

using namespace OpcUaStackCore;

namespace OpcUaStackServer
{

	class DLLEXPORT AttributeService 
	: public ServiceSetBase
	, public ServiceTransactionIf
	, public ObjectPool<AttributeService>
	{
	  public:
		AttributeService(void);
		~AttributeService(void);

		//- ServiceTransactionIf ------------------------------------------------------
		void receive(OpcUaNodeId& typeId, ServiceTransaction::SPtr serviceTransaction);
		//- ServiceTransactionIf ------------------------------------------------------

	  private:
		void receiveReadRequest(OpcUaNodeId& typeId, ServiceTransaction::SPtr serviceTransaction);
		void receiveWriteRequest(OpcUaNodeId& typeId, ServiceTransaction::SPtr serviceTransaction);
		void receiveHistoryReadRequest(OpcUaNodeId& typeId, ServiceTransaction::SPtr serviceTransaction);
		void receiveHistoryUpdateRequest(OpcUaNodeId& typeId, ServiceTransaction::SPtr serviceTransaction);
	};

}

#endif