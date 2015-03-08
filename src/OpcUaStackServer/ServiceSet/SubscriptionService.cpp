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
	SubscriptionService::receive(Message::SPtr message)
	{
		ServiceTransaction::SPtr serviceTransaction = boost::static_pointer_cast<ServiceTransaction>(message);
		switch (serviceTransaction->nodeTypeRequest().nodeId<uint32_t>()) 
		{
			//
			// subscription
			//
			case OpcUaId_CreateSubscriptionRequest_Encoding_DefaultBinary:
				receiveCreateSubscriptionRequest(serviceTransaction);
				break;
			case OpcUaId_DeleteSubscriptionsRequest_Encoding_DefaultBinary:
				receiveDeleteSubscriptionsRequest(serviceTransaction);
				break;
			case OpcUaId_ModifySubscriptionRequest_Encoding_DefaultBinary:
				receiveModifySubscriptionRequest(serviceTransaction);
				break;
			case OpcUaId_PublishRequest_Encoding_DefaultBinary:
				receivePublishRequest(serviceTransaction);
				break;
			case OpcUaId_RepublishRequest_Encoding_DefaultBinary:
				receiveRepublishRequest(serviceTransaction);
				break;
			case OpcUaId_SetPublishingModeRequest_Encoding_DefaultBinary:
				receiveSetPublishingModeRequest(serviceTransaction);
				break;
			case OpcUaId_TransferSubscriptionsRequest_Encoding_DefaultBinary:
				receiveTransferSubscriptionsRequest(serviceTransaction);
				break;

			//
			// monitorted item
			//
			case OpcUaId_CreateMonitoredItemsRequest_Encoding_DefaultBinary:
				receiveCreateMonitoredItemsRequest(serviceTransaction);
				break;
			case OpcUaId_DeleteMonitoredItemsRequest_Encoding_DefaultBinary:
				receiveDeleteMonitoredItemsRequest(serviceTransaction);
				break;
			case OpcUaId_ModifyMonitoredItemsRequest_Encoding_DefaultBinary:
				receiveModifyMonitoredItemsRequest(serviceTransaction);
				break;
			case OpcUaId_SetMonitoringModeRequest_Encoding_DefaultBinary:
				receiveSetMonitoringModeRequest(serviceTransaction);
				break;
			case OpcUaId_SetTriggeringRequest_Encoding_DefaultBinary:
				receiveSetTriggeringRequest(serviceTransaction);
				break;

			default:
				serviceTransaction->statusCode(BadInternalError);
				serviceTransaction->componentSession()->send(serviceTransaction);
		}
	}

	void 
	SubscriptionService::receiveCreateSubscriptionRequest(ServiceTransaction::SPtr serviceTransaction)
	{
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
			subscriptionManager->informationModel(informationModel_);
			subscriptionManager->sessionId(trx->sessionId());
			subscriptionManagerMap_.insert(std::make_pair(trx->sessionId(), subscriptionManager));
		}
		else {
			subscriptionManager = it->second;
		}

		serviceTransaction->statusCode(subscriptionManager->receive(trx));
		serviceTransaction->componentSession()->send(serviceTransaction);
	}

	void 
	SubscriptionService::receiveDeleteSubscriptionsRequest(ServiceTransaction::SPtr serviceTransaction)
	{
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
			serviceTransaction->componentSession()->send(serviceTransaction);
			return;
		}
		subscriptionManager = it->second;
		
		serviceTransaction->statusCode(subscriptionManager->receive(trx));
		serviceTransaction->componentSession()->send(serviceTransaction);

		if (subscriptionManager->size() == 0) {
			subscriptionManagerMap_.erase(it);
		}
	}

	void 
	SubscriptionService::receiveModifySubscriptionRequest(ServiceTransaction::SPtr serviceTransaction)
	{
		// FIXME:
		serviceTransaction->statusCode(BadInternalError);
		serviceTransaction->componentSession()->send(serviceTransaction);
	}

	void 
	SubscriptionService::receivePublishRequest(ServiceTransaction::SPtr serviceTransaction)
	{
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
			serviceTransaction->componentSession()->send(serviceTransaction);
			return;
		}
		subscriptionManager = it->second;

		subscriptionManager->receive(trx);
	}

	void 
	SubscriptionService::receiveRepublishRequest(ServiceTransaction::SPtr serviceTransaction)
	{
		// FIXME:
		serviceTransaction->statusCode(BadInternalError);
		serviceTransaction->componentSession()->send(serviceTransaction);
	}

	void 
	SubscriptionService::receiveSetPublishingModeRequest(ServiceTransaction::SPtr serviceTransaction)
	{
		// FIXME:
		serviceTransaction->statusCode(BadInternalError);
		serviceTransaction->componentSession()->send(serviceTransaction);
	}

	void 
	SubscriptionService::receiveTransferSubscriptionsRequest(ServiceTransaction::SPtr serviceTransaction)
	{
		// FIXME:
		serviceTransaction->statusCode(BadInternalError);
		serviceTransaction->componentSession()->send(serviceTransaction);
	}



	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// monitored item service
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	void 
	SubscriptionService::receiveCreateMonitoredItemsRequest(ServiceTransaction::SPtr serviceTransaction)
	{
		ServiceTransactionCreateMonitoredItems::SPtr trx = boost::static_pointer_cast<ServiceTransactionCreateMonitoredItems>(serviceTransaction);

		// find subscription manager
		SubscriptionManager::SPtr subscriptionManager;
		SubscriptionManagerMap::iterator it = subscriptionManagerMap_.find(trx->sessionId());
		if (it == subscriptionManagerMap_.end()) {
			serviceTransaction->statusCode(BadSubscriptionIdInvalid);
			serviceTransaction->componentSession()->send(serviceTransaction);
			return;
		}
		subscriptionManager = it->second;
		
		// call service function in subscription manager
		serviceTransaction->statusCode(subscriptionManager->receive(trx));
		serviceTransaction->componentSession()->send(serviceTransaction);
	}

	void 
	SubscriptionService::receiveDeleteMonitoredItemsRequest(ServiceTransaction::SPtr serviceTransaction)
	{
		ServiceTransactionDeleteMonitoredItems::SPtr trx = boost::static_pointer_cast<ServiceTransactionDeleteMonitoredItems>(serviceTransaction);
		
		// find subscription manager
		SubscriptionManager::SPtr subscriptionManager;
		SubscriptionManagerMap::iterator it = subscriptionManagerMap_.find(trx->sessionId());
		if (it == subscriptionManagerMap_.end()) {
			serviceTransaction->statusCode(BadSubscriptionIdInvalid);
			serviceTransaction->componentSession()->send(serviceTransaction);
			return;
		}
		subscriptionManager = it->second;
		
		// call service function in subscription manager
		serviceTransaction->statusCode(subscriptionManager->receive(trx));
		serviceTransaction->componentSession()->send(serviceTransaction);
	}

	void 
	SubscriptionService::receiveModifyMonitoredItemsRequest(ServiceTransaction::SPtr serviceTransaction)
	{
		ServiceTransactionModifyMonitoredItems::SPtr trx = boost::static_pointer_cast<ServiceTransactionModifyMonitoredItems>(serviceTransaction);

		// find subscription manager
		SubscriptionManager::SPtr subscriptionManager;
		SubscriptionManagerMap::iterator it = subscriptionManagerMap_.find(trx->sessionId());
		if (it == subscriptionManagerMap_.end()) {
			serviceTransaction->statusCode(BadSubscriptionIdInvalid);
			serviceTransaction->componentSession()->send(serviceTransaction);
			return;
		}
		subscriptionManager = it->second;
		
		// call service function in subscription manager
		serviceTransaction->statusCode(subscriptionManager->receive(trx));
		serviceTransaction->componentSession()->send(serviceTransaction);
	}

	void 
	SubscriptionService::receiveSetMonitoringModeRequest(ServiceTransaction::SPtr serviceTransaction)
	{
		ServiceTransactionSetMonitoringMode::SPtr trx = boost::static_pointer_cast<ServiceTransactionSetMonitoringMode>(serviceTransaction);

		// find subscription manager
		SubscriptionManager::SPtr subscriptionManager;
		SubscriptionManagerMap::iterator it = subscriptionManagerMap_.find(trx->sessionId());
		if (it == subscriptionManagerMap_.end()) {
			serviceTransaction->statusCode(BadSubscriptionIdInvalid);
			serviceTransaction->componentSession()->send(serviceTransaction);
			return;
		}
		subscriptionManager = it->second;
		
		// call service function in subscription manager
		serviceTransaction->statusCode(subscriptionManager->receive(trx));
		serviceTransaction->componentSession()->send(serviceTransaction);
	}

	void 
	SubscriptionService::receiveSetTriggeringRequest(ServiceTransaction::SPtr serviceTransaction)
	{
		ServiceTransactionSetTriggering::SPtr trx = boost::static_pointer_cast<ServiceTransactionSetTriggering>(serviceTransaction);

		// find subscription manager
		SubscriptionManager::SPtr subscriptionManager;
		SubscriptionManagerMap::iterator it = subscriptionManagerMap_.find(trx->sessionId());
		if (it == subscriptionManagerMap_.end()) {
			serviceTransaction->statusCode(BadSubscriptionIdInvalid);
			serviceTransaction->componentSession()->send(serviceTransaction);
			return;
		}
		subscriptionManager = it->second;
		
		// call service function in subscription manager
		serviceTransaction->statusCode(subscriptionManager->receive(trx));
		serviceTransaction->componentSession()->send(serviceTransaction);
	}

}
