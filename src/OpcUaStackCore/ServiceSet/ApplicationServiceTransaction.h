#ifndef __OpcUaStackCore_ApplicationServiceTransaction_h__
#define __OpcUaStackCore_ApplicationServiceTransaction_h__

#include "OpcUaStackCore/BuildInTypes/OpcUaIdentifier.h"
#include "OpcUaStackCore/ServiceSet/ServiceTransactionTemplate.h"
#include "OpcUaStackCore/ServiceSet/RegisterForwardRequest.h"
#include "OpcUaStackCore/ServiceSet/RegisterForwardResponse.h"

namespace OpcUaStackCore
{
	
	typedef ServiceTransactionTemplate<
		RegisterForwardRequest,
		RegisterForwardResponse,
		OpcUaId_RegisterForwardRequest_Encoding_DefaultBinary,
		OpcUaId_RegisterForwardResponse_Encoding_DefaultBinary
	> ServiceTransactionRegisterForward;

}

#endif
