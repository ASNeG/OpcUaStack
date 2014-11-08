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
		return true;
	}

	void 
	SubscriptionService::receive(OpcUaNodeId& typeId, Message::SPtr message)
	{
		ServiceTransaction::SPtr serviceTransaction = boost::static_pointer_cast<ServiceTransaction>(message);
		switch (serviceTransaction->nodeTypeRequest().nodeId<uint32_t>()) 
		{
			//
			// subscription
			//
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

			//
			// monitorted item
			//
			case OpcUaId_CreateMonitoredItemsRequest_Encoding_DefaultBinary:
				receiveCreateMonitoredItemsRequest(typeId, serviceTransaction);
				break;
			case OpcUaId_DeleteMonitoredItemsRequest_Encoding_DefaultBinary:
				receiveDeleteMonitoredItemsRequest(typeId, serviceTransaction);
				break;
			case OpcUaId_ModifyMonitoredItemsRequest_Encoding_DefaultBinary:
				receiveModifyMonitoredItemsRequest(typeId, serviceTransaction);
				break;
			case OpcUaId_SetMonitoringModeRequest_Encoding_DefaultBinary:
				receiveSetMonitoringModeRequest(typeId, serviceTransaction);
				break;
			case OpcUaId_SetTriggeringRequest_Encoding_DefaultBinary:
				receiveSetTriggeringRequest(typeId, serviceTransaction);
				break;

			default:
				serviceTransaction->statusCode(BadInternalError);
				serviceTransaction->componentSession()->send(typeId, serviceTransaction);
		}
	}

	void 
	SubscriptionService::receiveCreateSubscriptionRequest(OpcUaNodeId& typeId, ServiceTransaction::SPtr serviceTransaction)
	{
		typeId.set(OpcUaId_CreateSubscriptionResponse_Encoding_DefaultBinary);
		ServiceTransactionCreateSubscription::SPtr trx = boost::static_pointer_cast<ServiceTransactionCreateSubscription>(serviceTransaction);
		CreateSubscriptionRequest::SPtr createSubscriptionRequest = trx->request();
		CreateSubscriptionResponse::SPtr createSubscriptionResponse = trx->response();

		Log(Debug, "create subscription")
			.parameter("Trx", serviceTransaction->transactionId())
			.parameter("PublisingInterval", createSubscriptionRequest->requestedPublishingInterval())
			.parameter("LifetimeCount", createSubscriptionRequest->requestedLifetimeCount())
			.parameter("MaxKeepAliveCount", createSubscriptionRequest->requestedMaxKeepAliveCount())
			.parameter("SessionId", trx->sessionId());

		// find subscription manager
		SubscriptionManager::SPtr subscriptionManager;
		SubscriptionManagerMap::iterator it = subscriptionManagerMap_.find(trx->sessionId());
		if (it == subscriptionManagerMap_.end()) {
			subscriptionManager = SubscriptionManager::construct();
			subscriptionManager->ioService(ioService());
			subscriptionManager->sessionId(trx->sessionId());
			subscriptionManagerMap_.insert(std::make_pair(trx->sessionId(), subscriptionManager));
		}
		else {
			subscriptionManager = it->second;
		}

		serviceTransaction->statusCode(subscriptionManager->receive(trx));
		serviceTransaction->componentSession()->send(typeId, serviceTransaction);
	}

	void 
	SubscriptionService::receiveDeleteSubscriptionsRequest(OpcUaNodeId& typeId, ServiceTransaction::SPtr serviceTransaction)
	{
		typeId.set(OpcUaId_DeleteSubscriptionsResponse_Encoding_DefaultBinary);
		ServiceTransactionDeleteSubscriptions::SPtr trx = boost::static_pointer_cast<ServiceTransactionDeleteSubscriptions>(serviceTransaction);
		DeleteSubscriptionsRequest::SPtr deleteSubscriptionsRequest = trx->request();
		DeleteSubscriptionsResponse::SPtr deleteSubscriptionsResponse = trx->response();

		Log(Debug, "delete subscription")
			.parameter("Trx", serviceTransaction->transactionId());

		// find subscription manager
		SubscriptionManager::SPtr subscriptionManager;
		SubscriptionManagerMap::iterator it = subscriptionManagerMap_.find(trx->sessionId());
		if (it == subscriptionManagerMap_.end()) {
			serviceTransaction->statusCode(BadNothingToDo);
			serviceTransaction->componentSession()->send(typeId, serviceTransaction);
			return;
		}
		subscriptionManager = it->second;
		
		serviceTransaction->statusCode(subscriptionManager->receive(trx));
		serviceTransaction->componentSession()->send(typeId, serviceTransaction);

		if (subscriptionManager->size() == 0) {
			subscriptionManagerMap_.erase(it);
		}
	}

	void 
	SubscriptionService::receiveModifySubscriptionRequest(OpcUaNodeId& typeId, ServiceTransaction::SPtr serviceTransaction)
	{
		// FIXME:
		serviceTransaction->statusCode(BadInternalError);
		serviceTransaction->componentSession()->send(typeId, serviceTransaction);
	}

	void 
	SubscriptionService::receivePublishRequest(OpcUaNodeId& typeId, ServiceTransaction::SPtr serviceTransaction)
	{
		typeId.set(OpcUaId_PublishRequest_Encoding_DefaultBinary);
		ServiceTransactionPublish::SPtr trx = boost::static_pointer_cast<ServiceTransactionPublish>(serviceTransaction);
		PublishRequest::SPtr publishRequest = trx->request();
		PublishResponse::SPtr publishResponse = trx->response();

		Log(Debug, "publish")
			.parameter("Trx", serviceTransaction->transactionId());

		// find subscription manager
		SubscriptionManager::SPtr subscriptionManager;
		SubscriptionManagerMap::iterator it = subscriptionManagerMap_.find(trx->sessionId());
		if (it == subscriptionManagerMap_.end()) {
			serviceTransaction->statusCode(BadNothingToDo);
			serviceTransaction->componentSession()->send(typeId, serviceTransaction);
			return;
		}
		subscriptionManager = it->second;

		subscriptionManager->receive(trx);
	}

	void 
	SubscriptionService::receiveRepublishRequest(OpcUaNodeId& typeId, ServiceTransaction::SPtr serviceTransaction)
	{
		// FIXME:
		serviceTransaction->statusCode(BadInternalError);
		serviceTransaction->componentSession()->send(typeId, serviceTransaction);
	}

	void 
	SubscriptionService::receiveSetPublishingModeRequest(OpcUaNodeId& typeId, ServiceTransaction::SPtr serviceTransaction)
	{
		// FIXME:
		serviceTransaction->statusCode(BadInternalError);
		serviceTransaction->componentSession()->send(typeId, serviceTransaction);
	}

	void 
	SubscriptionService::receiveTransferSubscriptionsRequest(OpcUaNodeId& typeId, ServiceTransaction::SPtr serviceTransaction)
	{
		// FIXME:
		serviceTransaction->statusCode(BadInternalError);
		serviceTransaction->componentSession()->send(typeId, serviceTransaction);
	}



	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// monitored item service
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	void 
	SubscriptionService::receiveCreateMonitoredItemsRequest(OpcUaNodeId& typeId, ServiceTransaction::SPtr serviceTransaction)
	{
		typeId.set(OpcUaId_CreateMonitoredItemsResponse_Encoding_DefaultBinary);
		ServiceTransactionCreateMonitoredItems::SPtr trx = boost::static_pointer_cast<ServiceTransactionCreateMonitoredItems>(serviceTransaction);

		// find subscription manager
		SubscriptionManager::SPtr subscriptionManager;
		SubscriptionManagerMap::iterator it = subscriptionManagerMap_.find(trx->sessionId());
		if (it == subscriptionManagerMap_.end()) {
			serviceTransaction->statusCode(BadSubscriptionIdInvalid);
			serviceTransaction->componentSession()->send(typeId, serviceTransaction);
			return;
		}
		subscriptionManager = it->second;
		
		// call service function in subscription manager
		serviceTransaction->statusCode(subscriptionManager->receive(trx));
		serviceTransaction->componentSession()->send(typeId, serviceTransaction);
	}

	void 
	SubscriptionService::receiveDeleteMonitoredItemsRequest(OpcUaNodeId& typeId, ServiceTransaction::SPtr serviceTransaction)
	{
		typeId.set(OpcUaId_DeleteMonitoredItemsResponse_Encoding_DefaultBinary);
		ServiceTransactionDeleteMonitoredItems::SPtr trx = boost::static_pointer_cast<ServiceTransactionDeleteMonitoredItems>(serviceTransaction);
		
		// find subscription manager
		SubscriptionManager::SPtr subscriptionManager;
		SubscriptionManagerMap::iterator it = subscriptionManagerMap_.find(trx->sessionId());
		if (it == subscriptionManagerMap_.end()) {
			serviceTransaction->statusCode(BadSubscriptionIdInvalid);
			serviceTransaction->componentSession()->send(typeId, serviceTransaction);
			return;
		}
		subscriptionManager = it->second;
		
		// call service function in subscription manager
		serviceTransaction->statusCode(subscriptionManager->receive(trx));
		serviceTransaction->componentSession()->send(typeId, serviceTransaction);
	}

	void 
	SubscriptionService::receiveModifyMonitoredItemsRequest(OpcUaNodeId& typeId, ServiceTransaction::SPtr serviceTransaction)
	{
		typeId.set(OpcUaId_ModifyMonitoredItemsResponse_Encoding_DefaultBinary);
		ServiceTransactionModifyMonitoredItems::SPtr trx = boost::static_pointer_cast<ServiceTransactionModifyMonitoredItems>(serviceTransaction);

		// find subscription manager
		SubscriptionManager::SPtr subscriptionManager;
		SubscriptionManagerMap::iterator it = subscriptionManagerMap_.find(trx->sessionId());
		if (it == subscriptionManagerMap_.end()) {
			serviceTransaction->statusCode(BadSubscriptionIdInvalid);
			serviceTransaction->componentSession()->send(typeId, serviceTransaction);
			return;
		}
		subscriptionManager = it->second;
		
		// call service function in subscription manager
		serviceTransaction->statusCode(subscriptionManager->receive(trx));
		serviceTransaction->componentSession()->send(typeId, serviceTransaction);
	}

	void 
	SubscriptionService::receiveSetMonitoringModeRequest(OpcUaNodeId& typeId, ServiceTransaction::SPtr serviceTransaction)
	{
		typeId.set(OpcUaId_SetMonitoringModeResponse_Encoding_DefaultBinary);
		ServiceTransactionSetMonitoringMode::SPtr trx = boost::static_pointer_cast<ServiceTransactionSetMonitoringMode>(serviceTransaction);

		// find subscription manager
		SubscriptionManager::SPtr subscriptionManager;
		SubscriptionManagerMap::iterator it = subscriptionManagerMap_.find(trx->sessionId());
		if (it == subscriptionManagerMap_.end()) {
			serviceTransaction->statusCode(BadSubscriptionIdInvalid);
			serviceTransaction->componentSession()->send(typeId, serviceTransaction);
			return;
		}
		subscriptionManager = it->second;
		
		// call service function in subscription manager
		serviceTransaction->statusCode(subscriptionManager->receive(trx));
		serviceTransaction->componentSession()->send(typeId, serviceTransaction);
	}

	void 
	SubscriptionService::receiveSetTriggeringRequest(OpcUaNodeId& typeId, ServiceTransaction::SPtr serviceTransaction)
	{
		typeId.set(OpcUaId_SetTriggeringResponse_Encoding_DefaultBinary);
		ServiceTransactionSetTriggering::SPtr trx = boost::static_pointer_cast<ServiceTransactionSetTriggering>(serviceTransaction);

		// find subscription manager
		SubscriptionManager::SPtr subscriptionManager;
		SubscriptionManagerMap::iterator it = subscriptionManagerMap_.find(trx->sessionId());
		if (it == subscriptionManagerMap_.end()) {
			serviceTransaction->statusCode(BadSubscriptionIdInvalid);
			serviceTransaction->componentSession()->send(typeId, serviceTransaction);
			return;
		}
		subscriptionManager = it->second;
		
		// call service function in subscription manager
		serviceTransaction->statusCode(subscriptionManager->receive(trx));
		serviceTransaction->componentSession()->send(typeId, serviceTransaction);
	}

}