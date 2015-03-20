#include "OpcUaStackCore/Base/Log.h"
#include "OpcUaStackCore/ServiceSetApplication/ApplicationServiceTransaction.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaIdentifier.h"
#include "OpcUaStackServer/ServiceSetApplication/ApplicationService.h"
#include "OpcUaStackServer/AddressSpaceModel/AttributeAccess.h"

namespace OpcUaStackServer
{

	ApplicationService::ApplicationService(void)
	{
	}

	ApplicationService::~ApplicationService(void)
	{
	}

	void 
	ApplicationService::receive(Message::SPtr message)
	{
		ServiceTransaction::SPtr serviceTransaction = boost::static_pointer_cast<ServiceTransaction>(message);
		switch (serviceTransaction->nodeTypeRequest().nodeId<uint32_t>()) 
		{
			case OpcUaId_RegisterForwardRequest_Encoding_DefaultBinary:
				receiveRegisterForwardRequest(serviceTransaction);
				break;
			default:
				Log(Error, "application service received unknown message type")
					.parameter("TypeId", serviceTransaction->nodeTypeRequest());

				serviceTransaction->statusCode(BadInternalError);
				serviceTransaction->componentSession()->send(serviceTransaction);
		}
	}

	void 
	ApplicationService::receiveRegisterForwardRequest(ServiceTransaction::SPtr serviceTransaction)
	{
		ServiceTransactionRegisterForward::SPtr trx = boost::static_pointer_cast<ServiceTransactionRegisterForward>(serviceTransaction);

		RegisterForwardRequest::SPtr registerForwardRequest = trx->request();
		RegisterForwardResponse::SPtr registerForwardResponse = trx->response();

		Log(Debug, "application service register forward request")
			.parameter("Trx", serviceTransaction->transactionId())
			.parameter("NumberNodes", registerForwardRequest->nodesToRegister()->size());


		// FIXME:
		trx->responseHeader()->serviceResult(BadNothingToDo);
		trx->componentSession()->send(serviceTransaction);

	}

}
