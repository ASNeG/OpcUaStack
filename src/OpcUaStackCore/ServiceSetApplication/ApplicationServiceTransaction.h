#ifndef __OpcUaStackCore_ApplicationServiceTransaction_h__
#define __OpcUaStackCore_ApplicationServiceTransaction_h__

#include "OpcUaStackCore/BuildInTypes/OpcUaIdentifier.h"
#include "OpcUaStackCore/ServiceSet/ServiceTransactionTemplate.h"
#include "OpcUaStackCore/ServiceSetApplication/RegisterForwardRequest.h"
#include "OpcUaStackCore/ServiceSetApplication/RegisterForwardResponse.h"
#include "OpcUaStackCore/ServiceSetApplication/GetNodeReferenceRequest.h"
#include "OpcUaStackCore/ServiceSetApplication/GetNodeReferenceResponse.h"
#include "OpcUaStackCore/ServiceSetApplication/NamespaceInfoRequest.h"
#include "OpcUaStackCore/ServiceSetApplication/NamespaceInfoResponse.h"

namespace OpcUaStackCore
{
	
	typedef ServiceTransactionTemplate<
		RegisterForwardRequest,
		RegisterForwardResponse,
		OpcUaId_RegisterForwardRequest_Encoding_DefaultBinary,
		OpcUaId_RegisterForwardResponse_Encoding_DefaultBinary
	> ServiceTransactionRegisterForward;

	typedef ServiceTransactionTemplate<
		GetNodeReferenceRequest,
		GetNodeReferenceResponse,
		OpcUaId_GetNodeReferenceRequest_Encoding_DefaultBinary,
		OpcUaId_GetNodeReferenceResponse_Encoding_DefaultBinary
	> ServiceTransactionGetNodeReference;

	typedef ServiceTransactionTemplate<
		NamespaceInfoRequest,
		NamespaceInfoResponse,
		OpcUaId_NamespaceInfoRequest_Encoding_DefaultBinary,
		OpcUaId_NamespaceInfoResponse_Encoding_DefaultBinary
	> ServiceTransactionNamespaceInfo;

}

#endif
