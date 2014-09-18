#ifndef __OpcUaStackCore_MethodServiceTransaction_h__
#define __OpcUaStackCore_MethodServiceTransaction_h__

#include "OpcUaStackCore/BuildInTypes/OpcUaIdentifier.h"
#include "OpcUaStackCore/ServiceSet/ServiceTransactionTemplate.h"
#include "OpcUaStackCore/ServiceSet/CallRequest.h"
#include "OpcUaStackCore/ServiceSet/CallResponse.h"

namespace OpcUaStackCore
{

	typedef ServiceTransactionTemplate<
		CallRequest, 
		CallResponse, 
		OpcUaId_CallRequest_Encoding_DefaultBinary, 
		OpcUaId_CallResponse_Encoding_DefaultBinary
	> ServiceTransactionCall;

}

#endif