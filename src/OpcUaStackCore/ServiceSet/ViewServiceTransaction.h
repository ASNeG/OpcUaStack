#ifndef __OpcUaStackCore_ViewServiceTransaction_h__
#define __OpcUaStackCore_ViewServiceTransaction_h__

#include "OpcUaStackCore/BuildInTypes/OpcUaIdentifier.h"
#include "OpcUaStackCore/ServiceSet/ServiceTransactionTemplate.h"
#include "OpcUaStackCore/ServiceSet/BrowseRequest.h"
#include "OpcUaStackCore/ServiceSet/BrowseResponse.h"
#include "OpcUaStackCore/ServiceSet/BrowseNextRequest.h"
#include "OpcUaStackCore/ServiceSet/BrowseNextResponse.h"
#include "OpcUaStackCore/ServiceSet/TranslateBrowsePathsToNodeIdsRequest.h"
#include "OpcUaStackCore/ServiceSet/TranslateBrowsePathsToNodeIdsResponse.h"
#include "OpcUaStackCore/ServiceSet/RegisterNodesRequest.h"
#include "OpcUaStackCore/ServiceSet/RegisterNodesResponse.h"
#include "OpcUaStackCore/ServiceSet/UnregisterNodesRequest.h"
#include "OpcUaStackCore/ServiceSet/UnregisterNodesResponse.h"

namespace OpcUaStackCore
{

	typedef ServiceTransactionTemplate<
		BrowseRequest, 
		BrowseResponse, 
		OpcUaId_BrowseRequest_Encoding_DefaultBinary, 
		OpcUaId_BrowseResponse_Encoding_DefaultBinary
	> ServiceTransactionBrowse;

	typedef ServiceTransactionTemplate<
		BrowseNextRequest, 
		BrowseNextResponse, 
		OpcUaId_BrowseNextRequest_Encoding_DefaultBinary, 
		OpcUaId_BrowseNextResponse_Encoding_DefaultBinary
	> ServiceTransactionBrowseNext;

	typedef ServiceTransactionTemplate<
		TranslateBrowsePathsToNodeIdsRequest, 
		TranslateBrowsePathsToNodeIdsResponse, 
		OpcUaId_TranslateBrowsePathsToNodeIdsRequest_Encoding_DefaultBinary, 
		OpcUaId_TranslateBrowsePathsToNodeIdsResponse_Encoding_DefaultBinary
	> ServiceTransactionTranslateBrowsePathsToNodeIds;

	typedef ServiceTransactionTemplate<
		RegisterNodesRequest, 
		RegisterNodesResponse, 
		OpcUaId_RegisterNodesRequest_Encoding_DefaultBinary, 
		OpcUaId_RegisterNodesResponse_Encoding_DefaultBinary
	> ServiceTransactionRegisterNodes;

	typedef ServiceTransactionTemplate<
		UnregisterNodesRequest, 
		UnregisterNodesResponse, 
		OpcUaId_UnregisterNodesRequest_Encoding_DefaultBinary, 
		OpcUaId_UnregisterNodesResponse_Encoding_DefaultBinary
	> ServiceTransactionUnregisterNodes;

}

#endif