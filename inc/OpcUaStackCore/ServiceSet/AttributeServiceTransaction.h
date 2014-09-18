#ifndef __OpcUaStackCore_AttributeServiceTransaction_h__
#define __OpcUaStackCore_AttributeServiceTransaction_h__

#include "OpcUaStackCore/BuildInTypes/OpcUaIdentifier.h"
#include "OpcUaStackCore/ServiceSet/ServiceTransactionTemplate.h"
#include "OpcUaStackCore/ServiceSet/ReadRequest.h"
#include "OpcUaStackCore/ServiceSet/ReadResponse.h"

namespace OpcUaStackCore
{
	
	typedef ServiceTransactionTemplate<
		ReadRequest, 
		ReadResponse, 
		OpcUaId_ReadRequest_Encoding_DefaultBinary, 
		OpcUaId_ReadResponse_Encoding_DefaultBinary
	> ServiceTransactionRead;

}

#endif