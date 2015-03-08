#include "OpcUaStackCore/BuildInTypes/OpcUaIdentifier.h"
#include "OpcUaStackServer/ServiceSet/QueryService.h"

namespace OpcUaStackServer
{

	QueryService::QueryService(void)
	{
	}

	QueryService::~QueryService(void)
	{
	}

	void 
	QueryService::receive(Message::SPtr message)
	{
		ServiceTransaction::SPtr serviceTransaction = boost::static_pointer_cast<ServiceTransaction>(message);
		switch (serviceTransaction->nodeTypeRequest().nodeId<uint32_t>()) 
		{
			case OpcUaId_QueryFirstRequest_Encoding_DefaultBinary:
				receiveQueryFirstRequest(serviceTransaction);
				break;
			case OpcUaId_QueryNextRequest_Encoding_DefaultBinary:
				receiveQueryNextRequest(serviceTransaction);
				break;
			default:
				serviceTransaction->statusCode(BadInternalError);
				serviceTransaction->componentSession()->send(serviceTransaction);
		}
	}

	void 
	QueryService::receiveQueryFirstRequest(ServiceTransaction::SPtr serviceTransaction)
	{
		// FIXME:
		serviceTransaction->statusCode(BadInternalError);
		serviceTransaction->componentSession()->send(serviceTransaction);
	}

	void 
	QueryService::receiveQueryNextRequest(ServiceTransaction::SPtr serviceTransaction)
	{
		// FIXME:
		serviceTransaction->statusCode(BadInternalError);
		serviceTransaction->componentSession()->send(serviceTransaction);
	}

}
