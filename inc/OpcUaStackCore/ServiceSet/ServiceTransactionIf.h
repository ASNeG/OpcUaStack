#ifndef __OpcUaStackCore_ServiceTransactionIf_h__
#define __OpcUaStackCore_ServiceTransactionIf_h__

#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaNodeId.h"
#include "OpcUaStackCore/ServiceSet/ServiceTransaction.h"

namespace OpcUaStackCore
{

	class DLLEXPORT ServiceTransactionIf
	{
	  public:
		virtual void receive(OpcUaNodeId& typeId, ServiceTransaction::SPtr serviceTransaction) = 0;
	};

};

#endif