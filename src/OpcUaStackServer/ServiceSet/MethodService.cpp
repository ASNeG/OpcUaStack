#include "OpcUaStackCore/BuildInTypes/OpcUaIdentifier.h"
#include "OpcUaStackServer/ServiceSet/MethodService.h"

namespace OpcUaStackServer
{

	MethodService::MethodService(void)
	{
	}

	MethodService::~MethodService(void)
	{
	}

	void 
	MethodService::receive(OpcUaNodeId& typeId, Message::SPtr message)
	{
		ServiceTransaction::SPtr serviceTransaction = boost::static_pointer_cast<ServiceTransaction>(message);
		switch (serviceTransaction->nodeTypeRequest().nodeId<uint32_t>()) 
		{
			case OpcUaId_CallRequest_Encoding_DefaultBinary:
				receiveCallRequest(typeId, serviceTransaction);
				break;
			default:
				serviceTransaction->statusCode(BadInternalError);
				serviceTransaction->componentSession()->send(typeId, serviceTransaction);
		}
	}

	void 
	MethodService::receiveCallRequest(OpcUaNodeId& typeId, ServiceTransaction::SPtr serviceTransaction)
	{
		// FIXME:
		serviceTransaction->statusCode(BadInternalError);
		serviceTransaction->componentSession()->send(typeId, serviceTransaction);
	}

}