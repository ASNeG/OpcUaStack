#ifndef __OpcUaStackClient_ServiceSetIf_h__
#define __OpcUaStackClient_ServiceSetIf_h__

#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaNodeId.h"
#include "OpcUaStackClient/ServiceSet/ServiceTransaction.h"

using namespace OpcUaStackCore;

namespace OpcUaStackClient
{

	class DLLEXPORT ServiceSetIf
	{
	  public:
		virtual void serviceSetIf(OpcUaNodeId& typeId, ServiceTransaction::SPtr serviceTransaction) = 0;
	};

};

#endif