#include "OpcUaStackCore/BuildInTypes/OpcUaIdentifier.h"
#include "OpcUaStackServer/ServiceSet/NodeManagementService.h"

namespace OpcUaStackServer
{

	NodeManagementService::NodeManagementService(void)
	{
	}

	NodeManagementService::~NodeManagementService(void)
	{
	}

	void 
	NodeManagementService::receive(OpcUaNodeId& typeId, Message::SPtr message)
	{
		ServiceTransaction::SPtr serviceTransaction = boost::static_pointer_cast<ServiceTransaction>(message);
		switch (serviceTransaction->nodeTypeRequest().nodeId<uint32_t>()) 
		{
			case OpcUaId_AddNodesRequest_Encoding_DefaultBinary:
				receiveAddNodesRequest(typeId, serviceTransaction);
				break;
			case OpcUaId_AddReferencesRequest_Encoding_DefaultBinary:
				receiveAddReferencesRequest(typeId, serviceTransaction);
				break;
			case OpcUaId_DeleteNodesRequest_Encoding_DefaultBinary:
				receiveDeleteNodesRequest(typeId, serviceTransaction);
				break;
			case OpcUaId_DeleteReferencesRequest_Encoding_DefaultBinary:
				receiveDeleteReferencesRequest(typeId, serviceTransaction);
				break;
			default:
				serviceTransaction->statusCode(BadInternalError);
				serviceTransaction->componentSession()->send(typeId, serviceTransaction);
		}
	}

	void 
	NodeManagementService::receiveAddNodesRequest(OpcUaNodeId& typeId, ServiceTransaction::SPtr serviceTransaction)
	{
		// FIXME:
		serviceTransaction->statusCode(BadInternalError);
		serviceTransaction->componentSession()->send(typeId, serviceTransaction);
	}

	void 
	NodeManagementService::receiveAddReferencesRequest(OpcUaNodeId& typeId, ServiceTransaction::SPtr serviceTransaction)
	{
		// FIXME:
		serviceTransaction->statusCode(BadInternalError);
		serviceTransaction->componentSession()->send(typeId, serviceTransaction);
	}

	void 
	NodeManagementService::receiveDeleteNodesRequest(OpcUaNodeId& typeId, ServiceTransaction::SPtr serviceTransaction)
	{
		// FIXME:
		serviceTransaction->statusCode(BadInternalError);
		serviceTransaction->componentSession()->send(typeId, serviceTransaction);
	}

	void 
	NodeManagementService::receiveDeleteReferencesRequest(OpcUaNodeId& typeId, ServiceTransaction::SPtr serviceTransaction)
	{
		// FIXME:
		serviceTransaction->statusCode(BadInternalError);
		serviceTransaction->componentSession()->send(typeId, serviceTransaction);
	}

}