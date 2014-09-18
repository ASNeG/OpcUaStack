#ifndef __OpcUaStackCore_DiscoveryServiceTransaction_h__
#define __OpcUaStackCore_DiscoveryServiceTransaction_h__

#include "OpcUaStackCore/BuildInTypes/OpcUaIdentifier.h"
#include "OpcUaStackCore/ServiceSet/ServiceTransactionTemplate.h"
#include "OpcUaStackCore/ServiceSet/FindServersRequest.h"
#include "OpcUaStackCore/ServiceSet/FindServersResponse.h"
#include "OpcUaStackCore/ServiceSet/GetEndpointsRequest.h"
#include "OpcUaStackCore/ServiceSet/GetEndpointsResponse.h"
#include "OpcUaStackCore/ServiceSet/RegisterServerRequest.h"
#include "OpcUaStackCore/ServiceSet/RegisterServerResponse.h"

namespace OpcUaStackCore
{

	typedef ServiceTransactionTemplate<
		FindServersRequest, 
		FindServersResponse, 
		OpcUaId_FindServersRequest_Encoding_DefaultBinary, 
		OpcUaId_FindServersResponse_Encoding_DefaultBinary
	> ServiceTransactionFindServers;

	typedef ServiceTransactionTemplate<
		GetEndpointsRequest, 
		GetEndpointsResponse, 
		OpcUaId_GetEndpointsRequest_Encoding_DefaultBinary, 
		OpcUaId_GetEndpointsResponse_Encoding_DefaultBinary
	> ServiceTransactionGetEndpoints;

	typedef ServiceTransactionTemplate<
		RegisterServerRequest, 
		RegisterServerResponse, 
		OpcUaId_RegisterServerRequest_Encoding_DefaultBinary, 
		OpcUaId_RegisterServerResponse_Encoding_DefaultBinary
	> ServiceTransactionRegisterServer;

}

#endif