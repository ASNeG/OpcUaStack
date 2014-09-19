#ifndef __OpcUaStackCore_NodeManagementServiceTransaction_h__
#define __OpcUaStackCore_NodeManagementServiceTransaction_h__

#include "OpcUaStackCore/BuildInTypes/OpcUaIdentifier.h"
#include "OpcUaStackCore/ServiceSet/ServiceTransactionTemplate.h"
#include "OpcUaStackCore/ServiceSet/AddNodesRequest.h"
#include "OpcUaStackCore/ServiceSet/AddNodesResponse.h"
#include "OpcUaStackCore/ServiceSet/AddReferencesRequest.h"
#include "OpcUaStackCore/ServiceSet/AddReferencesResponse.h"
#include "OpcUaStackCore/ServiceSet/DeleteNodesRequest.h"
#include "OpcUaStackCore/ServiceSet/DeleteNodesResponse.h"
#include "OpcUaStackCore/ServiceSet/DeleteReferencesRequest.h"
#include "OpcUaStackCore/ServiceSet/DeleteReferencesResponse.h"

namespace OpcUaStackCore
{

	typedef ServiceTransactionTemplate<
		AddNodesRequest, 
		AddNodesResponse, 
		OpcUaId_AddNodesRequest_Encoding_DefaultBinary, 
		OpcUaId_AddNodesResponse_Encoding_DefaultBinary
	> ServiceTransactionAddNodes;

	typedef ServiceTransactionTemplate<
		AddReferencesRequest, 
		AddReferencesResponse, 
		OpcUaId_AddReferencesRequest_Encoding_DefaultBinary, 
		OpcUaId_AddReferencesResponse_Encoding_DefaultBinary
	> ServiceTransactionAddReferences;

	typedef ServiceTransactionTemplate<
		DeleteNodesRequest, 
		DeleteNodesResponse, 
		OpcUaId_DeleteNodesRequest_Encoding_DefaultBinary, 
		OpcUaId_DeleteNodesResponse_Encoding_DefaultBinary
	> ServiceTransactionDeleteNodes;

	typedef ServiceTransactionTemplate<
		DeleteReferencesRequest, 
		DeleteReferencesResponse, 
		OpcUaId_DeleteReferencesRequest_Encoding_DefaultBinary, 
		OpcUaId_DeleteReferencesResponse_Encoding_DefaultBinary
	> ServiceTransactionDeleteReferences;

}

#endif