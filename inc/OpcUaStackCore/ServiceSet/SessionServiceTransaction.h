#ifndef __OpcUaStackCore_SessionServiceTransaction_h__
#define __OpcUaStackCore_SessionServiceTransaction_h__

#include "OpcUaStackCore/BuildInTypes/OpcUaIdentifier.h"
#include "OpcUaStackCore/ServiceSet/ServiceTransactionTemplate.h"
#include "OpcUaStackCore/ServiceSet/CreateSessionRequest.h"
#include "OpcUaStackCore/ServiceSet/CreateSessionResponse.h"
#include "OpcUaStackCore/ServiceSet/ActivateSessionRequest.h"
#include "OpcUaStackCore/ServiceSet/ActivateSessionResponse.h"
#include "OpcUaStackCore/ServiceSet/CloseSessionRequest.h"
#include "OpcUaStackCore/ServiceSet/CloseSessionResponse.h"
#include "OpcUaStackCore/ServiceSet/CancelRequest.h"
#include "OpcUaStackCore/ServiceSet/CancelResponse.h"

namespace OpcUaStackCore
{

	typedef ServiceTransactionTemplate<
		CreateSessionRequest, 
		CreateSessionResponse, 
		OpcUaId_CreateSessionRequest_Encoding_DefaultBinary, 
		OpcUaId_CreateSessionResponse_Encoding_DefaultBinary
	> ServiceTransactionCreateSession;

	typedef ServiceTransactionTemplate<
		ActivateSessionRequest, 
		ActivateSessionResponse, 
		OpcUaId_ActivateSessionRequest_Encoding_DefaultBinary, 
		OpcUaId_ActivateSessionResponse_Encoding_DefaultBinary
	> ServiceTransactionActivateSession;

	typedef ServiceTransactionTemplate<
		CloseSessionRequest, 
		CloseSessionResponse, 
		OpcUaId_CloseSessionRequest_Encoding_DefaultBinary, 
		OpcUaId_CloseSessionResponse_Encoding_DefaultBinary
	> ServiceTransactionCloseSession;

	typedef ServiceTransactionTemplate<
		CancelRequest, 
		CancelResponse, 
		OpcUaId_CancelRequest_Encoding_DefaultBinary, 
		OpcUaId_CancelResponse_Encoding_DefaultBinary
	> ServiceTransactionCancel;

}

#endif