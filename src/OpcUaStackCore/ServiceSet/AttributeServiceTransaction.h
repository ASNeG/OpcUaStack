#ifndef __OpcUaStackCore_AttributeServiceTransaction_h__
#define __OpcUaStackCore_AttributeServiceTransaction_h__

#include "OpcUaStackCore/BuildInTypes/OpcUaIdentifier.h"
#include "OpcUaStackCore/ServiceSet/ServiceTransactionTemplate.h"
#include "OpcUaStackCore/ServiceSet/ReadRequest.h"
#include "OpcUaStackCore/ServiceSet/ReadResponse.h"
#include "OpcUaStackCore/ServiceSet/WriteRequest.h"
#include "OpcUaStackCore/ServiceSet/WriteResponse.h"
#include "OpcUaStackCore/ServiceSet/HistoryReadRequest.h"
#include "OpcUaStackCore/ServiceSet/HistoryReadResponse.h"
#include "OpcUaStackCore/ServiceSet/HistoryUpdateRequest.h"
#include "OpcUaStackCore/ServiceSet/HistoryUpdateResponse.h"

namespace OpcUaStackCore
{
	
	typedef ServiceTransactionTemplate<
		ReadRequest, 
		ReadResponse, 
		OpcUaId_ReadRequest_Encoding_DefaultBinary, 
		OpcUaId_ReadResponse_Encoding_DefaultBinary
	> ServiceTransactionRead;

	typedef ServiceTransactionTemplate<
		WriteRequest, 
		WriteResponse, 
		OpcUaId_WriteRequest_Encoding_DefaultBinary, 
		OpcUaId_WriteResponse_Encoding_DefaultBinary
	> ServiceTransactionWrite;

	typedef ServiceTransactionTemplate<
		HistoryReadRequest, 
		HistoryReadResponse, 
		OpcUaId_HistoryReadRequest_Encoding_DefaultBinary, 
		OpcUaId_HistoryReadResponse_Encoding_DefaultBinary
	> ServiceTransactionHistoryRead;

	typedef ServiceTransactionTemplate<
		HistoryUpdateRequest, 
		HistoryUpdateResponse, 
		OpcUaId_HistoryUpdateRequest_Encoding_DefaultBinary, 
		OpcUaId_HistoryUpdateResponse_Encoding_DefaultBinary
	> ServiceTransactionHistoryUpdate;

}

#endif