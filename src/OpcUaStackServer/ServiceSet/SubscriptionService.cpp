#include "OpcUaStackCore/BuildInTypes/OpcUaIdentifier.h"
#include "OpcUaStackCore/Base/Log.h"
#include "OpcUaStackServer/ServiceSet/SubscriptionService.h"

namespace OpcUaStackServer
{

	SubscriptionService::SubscriptionService(void)
	{
	}

	SubscriptionService::~SubscriptionService(void)
	{
	}

	bool
	SubscriptionService::init(void)
	{
		subscriptionManager_.ioService(ioService());
		return true;
	}

	void 
	SubscriptionService::receive(OpcUaNodeId& typeId, ServiceTransaction::SPtr serviceTransaction)
	{
		switch (serviceTransaction->nodeTypeRequest().nodeId<uint32_t>()) 
		{
			case OpcUaId_CreateSubscriptionRequest_Encoding_DefaultBinary:
				receiveCreateSubscriptionRequest(typeId, serviceTransaction);
				break;
			case OpcUaId_DeleteSubscriptionsRequest_Encoding_DefaultBinary:
				receiveDeleteSubscriptionsRequest(typeId, serviceTransaction);
				break;
			case OpcUaId_ModifySubscriptionRequest_Encoding_DefaultBinary:
				receiveModifySubscriptionRequest(typeId, serviceTransaction);
				break;
			case OpcUaId_PublishRequest_Encoding_DefaultBinary:
				receivePublishRequest(typeId, serviceTransaction);
				break;
			case OpcUaId_RepublishRequest_Encoding_DefaultBinary:
				receiveRepublishRequest(typeId, serviceTransaction);
				break;
			case OpcUaId_SetPublishingModeRequest_Encoding_DefaultBinary:
				receiveSetPublishingModeRequest(typeId, serviceTransaction);
				break;
			case OpcUaId_TransferSubscriptionsRequest_Encoding_DefaultBinary:
				receiveTransferSubscriptionsRequest(typeId, serviceTransaction);
				break;
			default:
				serviceTransaction->statusCode(BadInternalError);
				serviceTransaction->serviceTransactionIfSession()->receive(typeId, serviceTransaction);
		}
	}

	void 
	SubscriptionService::receiveCreateSubscriptionRequest(OpcUaNodeId& typeId, ServiceTransaction::SPtr serviceTransaction)
	{
		ServiceTransactionCreateSubscription::SPtr trx = boost::static_pointer_cast<ServiceTransactionCreateSubscription>(serviceTransaction);
		CreateSubscriptionRequest::SPtr createSubscriptionRequest = trx->request();
		CreateSubscriptionResponse::SPtr createSubscriptionResponse = trx->response();

		Log(Debug, "create subscription")
			.parameter("Trx", serviceTransaction->transactionId())
			.parameter("PublisingInterval", createSubscriptionRequest->requestedPublishingInterval())
			.parameter("LifetimeCount", createSubscriptionRequest->requestedLifetimeCount())
			.parameter("MaxKeepAliveCount", createSubscriptionRequest->requestedMaxKeepAliveCount());

		serviceTransaction->statusCode(subscriptionManager_.receive(trx));
		serviceTransaction->serviceTransactionIfSession()->receive(typeId, serviceTransaction);
	}

	void 
	SubscriptionService::receiveDeleteSubscriptionsRequest(OpcUaNodeId& typeId, ServiceTransaction::SPtr serviceTransaction)
	{
		ServiceTransactionDeleteSubscriptions::SPtr trx = boost::static_pointer_cast<ServiceTransactionDeleteSubscriptions>(serviceTransaction);
		DeleteSubscriptionsRequest::SPtr deleteSubscriptionsRequest = trx->request();
		DeleteSubscriptionsResponse::SPtr deleteSubscriptionsResponse = trx->response();

		Log(Debug, "create subscription")
			.parameter("Trx", serviceTransaction->transactionId());

		serviceTransaction->statusCode(subscriptionManager_.receive(trx));
		serviceTransaction->serviceTransactionIfSession()->receive(typeId, serviceTransaction);
	}

	void 
	SubscriptionService::receiveModifySubscriptionRequest(OpcUaNodeId& typeId, ServiceTransaction::SPtr serviceTransaction)
	{
		// FIXME:
		serviceTransaction->statusCode(BadInternalError);
		serviceTransaction->serviceTransactionIfSession()->receive(typeId, serviceTransaction);
	}

	void 
	SubscriptionService::receivePublishRequest(OpcUaNodeId& typeId, ServiceTransaction::SPtr serviceTransaction)
	{
		ServiceTransactionPublish::SPtr trx = boost::static_pointer_cast<ServiceTransactionPublish>(serviceTransaction);
		PublishRequest::SPtr publishRequest = trx->request();
		PublishResponse::SPtr publishResponse = trx->response();

		Log(Debug, "publish")
			.parameter("Trx", serviceTransaction->transactionId());

		subscriptionManager_.receive(trx);
	}

	void 
	SubscriptionService::receiveRepublishRequest(OpcUaNodeId& typeId, ServiceTransaction::SPtr serviceTransaction)
	{
		// FIXME:
		serviceTransaction->statusCode(BadInternalError);
		serviceTransaction->serviceTransactionIfSession()->receive(typeId, serviceTransaction);
	}

	void 
	SubscriptionService::receiveSetPublishingModeRequest(OpcUaNodeId& typeId, ServiceTransaction::SPtr serviceTransaction)
	{
		// FIXME:
		serviceTransaction->statusCode(BadInternalError);
		serviceTransaction->serviceTransactionIfSession()->receive(typeId, serviceTransaction);
	}

	void 
	SubscriptionService::receiveTransferSubscriptionsRequest(OpcUaNodeId& typeId, ServiceTransaction::SPtr serviceTransaction)
	{
		// FIXME:
		serviceTransaction->statusCode(BadInternalError);
		serviceTransaction->serviceTransactionIfSession()->receive(typeId, serviceTransaction);
	}


}