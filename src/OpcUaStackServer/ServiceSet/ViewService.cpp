#include "OpcUaStackCore/ServiceSet/ServiceTransactionRead.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaIdentifier.h"
#include "OpcUaStackServer/ServiceSet/ViewService.h"

namespace OpcUaStackServer
{

	ViewService::ViewService(void)
	{
	}

	ViewService::~ViewService(void)
	{
	}

	void 
	ViewService::receive(OpcUaNodeId& typeId, ServiceTransaction::SPtr serviceTransaction)
	{
		switch (serviceTransaction->nodeTypeRequest().nodeId<uint32_t>()) 
		{
			case OpcUaId_BrowseRequest_Encoding_DefaultBinary:
				receiveBrowseRequest(typeId, serviceTransaction);
				break;
			case OpcUaId_BrowseNextRequest_Encoding_DefaultBinary:
				receiveBrowseNextRequest(typeId, serviceTransaction);
				break;
			case OpcUaId_TranslateBrowsePathsToNodeIdsRequest_Encoding_DefaultBinary:
				receiveTranslateBrowsePathsToNodeIdsRequest(typeId, serviceTransaction);
				break;
			case OpcUaId_RegisterNodesRequest_Encoding_DefaultBinary:
				receiveRegisterNodesRequest(typeId, serviceTransaction);
				break;
			case OpcUaId_UnregisterNodesRequest_Encoding_DefaultBinary:
				receiveUnregisterNodesRequest(typeId, serviceTransaction);
				break;
			default:
				serviceTransaction->statusCode(BadInternalError);
				serviceTransaction->serviceTransactionIfSession()->receive(typeId, serviceTransaction);
		}
	}

	void 
	ViewService::receiveBrowseRequest(OpcUaNodeId& typeId, ServiceTransaction::SPtr serviceTransaction)
	{
		// FIXME:
		serviceTransaction->statusCode(BadInternalError);
		serviceTransaction->serviceTransactionIfSession()->receive(typeId, serviceTransaction);
	}

	void 
	ViewService::receiveBrowseNextRequest(OpcUaNodeId& typeId, ServiceTransaction::SPtr serviceTransaction)
	{
		// FIXME:
		serviceTransaction->statusCode(BadInternalError);
		serviceTransaction->serviceTransactionIfSession()->receive(typeId, serviceTransaction);
	}

	void 
	ViewService::receiveTranslateBrowsePathsToNodeIdsRequest(OpcUaNodeId& typeId, ServiceTransaction::SPtr serviceTransaction)
	{
		// FIXME:
		serviceTransaction->statusCode(BadInternalError);
		serviceTransaction->serviceTransactionIfSession()->receive(typeId, serviceTransaction);
	}

	void 
	ViewService::receiveRegisterNodesRequest(OpcUaNodeId& typeId, ServiceTransaction::SPtr serviceTransaction)
	{
		// FIXME:
		serviceTransaction->statusCode(BadInternalError);
		serviceTransaction->serviceTransactionIfSession()->receive(typeId, serviceTransaction);
	}

	void 
	ViewService::receiveUnregisterNodesRequest(OpcUaNodeId& typeId, ServiceTransaction::SPtr serviceTransaction)
	{
		// FIXME:
		serviceTransaction->statusCode(BadInternalError);
		serviceTransaction->serviceTransactionIfSession()->receive(typeId, serviceTransaction);
	}


}