#ifndef __OpcUaStackCore_ServiceSetIf_h__
#define __OpcUaStackCore_ServiceSetIf_h__

#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaNodeId.h"
#include "OpcUaStackCore/ServiceSet/ServiceTransaction.h"

namespace OpcUaStackCore
{

	class DLLEXPORT ServiceSetIf
	{
	  public:
		virtual void serviceSetIf(OpcUaNodeId& typeId, ServiceTransaction::SPtr serviceTransaction) = 0;
	};

};

#endif