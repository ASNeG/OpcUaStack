#ifndef __OpcUaStackCore_QueryServiceTransaction_h__
#define __OpcUaStackCore_QueryServiceTransaction_h__

#include "OpcUaStackCore/BuildInTypes/OpcUaIdentifier.h"
#include "OpcUaStackCore/ServiceSet/ServiceTransactionTemplate.h"
#include "OpcUaStackCore/ServiceSet/QueryFirstRequest.h"
#include "OpcUaStackCore/ServiceSet/QueryFirstResponse.h"
#include "OpcUaStackCore/ServiceSet/QueryNextRequest.h"
#include "OpcUaStackCore/ServiceSet/QueryNextResponse.h"

namespace OpcUaStackCore
{

	typedef ServiceTransactionTemplate<
		QueryFirstRequest, 
		QueryFirstResponse, 
		OpcUaId_QueryFirstRequest_Encoding_DefaultBinary, 
		OpcUaId_QueryFirstResponse_Encoding_DefaultBinary
	> ServiceTransactionQueryFirst;

	typedef ServiceTransactionTemplate<
		QueryNextRequest, 
		QueryNextResponse, 
		OpcUaId_QueryNextRequest_Encoding_DefaultBinary, 
		OpcUaId_QueryNextResponse_Encoding_DefaultBinary
	> ServiceTransactionQueryNext;

}

#endif