#include "OpcUaStackCore/Base/Log.h"
#include "OpcUaStackClient/ServiceSet/SubscriptionService.h"

using namespace OpcUaStackCore;

namespace OpcUaStackClient
{

	SubscriptionService::SubscriptionService(void)
	: componentSession_(nullptr)
	, subscriptionServiceIf_(nullptr)
	{
	}

	SubscriptionService::~SubscriptionService(void)
	{
	}

	void
	SubscriptionService::componentSession(Component* componentSession)
	{
		componentSession_ = componentSession;
	}

	void
	SubscriptionService::subscriptionServiceIf(SubscriptionServiceIf* subscriptionServiceIf)
	{
		subscriptionServiceIf_ = subscriptionServiceIf;
	}

	void
	SubscriptionService::sendSync(ServiceTransactionCreateSubscription::SPtr serviceTransactionCreateSubscription)
	{
		serviceTransactionCreateSubscription->sync(true);
		serviceTransactionCreateSubscription->conditionBool().conditionInit();
		send(serviceTransactionCreateSubscription);
		serviceTransactionCreateSubscription->conditionBool().waitForCondition();
	}

	void
	SubscriptionService::send(ServiceTransactionCreateSubscription::SPtr serviceTransactionCreateSubscription)
	{
		serviceTransactionCreateSubscription->componentService(this);
		OpcUaNodeId nodeId;
		componentSession_->send(serviceTransactionCreateSubscription);
	}

	void
	SubscriptionService::sendSync(ServiceTransactionModifySubscription::SPtr serviceTransactionModifySubscription)
	{
		serviceTransactionModifySubscription->sync(true);
		serviceTransactionModifySubscription->conditionBool().conditionInit();
		send(serviceTransactionModifySubscription);
		serviceTransactionModifySubscription->conditionBool().waitForCondition();
	}

	void
	SubscriptionService::send(ServiceTransactionModifySubscription::SPtr serviceTransactionModifySubscription)
	{
		serviceTransactionModifySubscription->componentService(this);
		OpcUaNodeId nodeId;
		componentSession_->send(serviceTransactionModifySubscription);
	}

	void
	SubscriptionService::sendSync(ServiceTransactionTransferSubscriptions::SPtr serviceTransactionTransferSubscriptions)
	{
		serviceTransactionTransferSubscriptions->sync(true);
		serviceTransactionTransferSubscriptions->conditionBool().conditionInit();
		send(serviceTransactionTransferSubscriptions);
		serviceTransactionTransferSubscriptions->conditionBool().waitForCondition();
	}

	void
	SubscriptionService::send(ServiceTransactionTransferSubscriptions::SPtr serviceTransactionTransferSubscriptions)
	{
		serviceTransactionTransferSubscriptions->componentService(this);
		OpcUaNodeId nodeId;
		componentSession_->send(serviceTransactionTransferSubscriptions);
	}

	void
	SubscriptionService::sendSync(ServiceTransactionDeleteSubscriptions::SPtr serviceTransactionDeleteSubscriptions)
	{
		serviceTransactionDeleteSubscriptions->sync(true);
		serviceTransactionDeleteSubscriptions->conditionBool().conditionInit();
		send(serviceTransactionDeleteSubscriptions);
		serviceTransactionDeleteSubscriptions->conditionBool().waitForCondition();
	}

	void
	SubscriptionService::send(ServiceTransactionDeleteSubscriptions::SPtr serviceTransactionDeleteSubscriptions)
	{
		serviceTransactionDeleteSubscriptions->componentService(this);
		OpcUaNodeId nodeId;
		componentSession_->send(serviceTransactionDeleteSubscriptions);
	}

	void
	SubscriptionService::receive(OpcUaNodeId& typeId, Message::SPtr message)
	{
		ServiceTransaction::SPtr serviceTransaction = boost::static_pointer_cast<ServiceTransaction>(message);

		// check if transaction is synchron
		if (serviceTransaction->sync()) {
			serviceTransaction->conditionBool().conditionTrue();
			return;
		}

		switch (typeId.nodeId<uint32_t>())
		{
			case OpcUaId_CreateSubscriptionResponse_Encoding_DefaultBinary:
			{
				if (subscriptionServiceIf_ != nullptr) {
					subscriptionServiceIf_->subscriptionServiceCreateSubscriptionResponse(
						boost::static_pointer_cast<ServiceTransactionCreateSubscription>(serviceTransaction)
					);
				}
				break;
			}

			case OpcUaId_ModifySubscriptionResponse_Encoding_DefaultBinary:
			{
				if (subscriptionServiceIf_ != nullptr) {
					subscriptionServiceIf_->subscriptionServiceModifySubscriptionResponse(
						boost::static_pointer_cast<ServiceTransactionModifySubscription>(serviceTransaction)
					);
				}
				break;
			}

			case OpcUaId_TransferSubscriptionsResponse_Encoding_DefaultBinary:
			{
				if (subscriptionServiceIf_ != nullptr) {
					subscriptionServiceIf_->subscriptionServiceTransferSubscriptionsResponse(
						boost::static_pointer_cast<ServiceTransactionTransferSubscriptions>(serviceTransaction)
					);
				}
				break;
			}

			case OpcUaId_DeleteSubscriptionsResponse_Encoding_DefaultBinary:
			{
				if (subscriptionServiceIf_ != nullptr) {
					subscriptionServiceIf_->subscriptionServiceDeleteSubscriptionsResponse(
						boost::static_pointer_cast<ServiceTransactionDeleteSubscriptions>(serviceTransaction)
					);
				}
				break;
			}

			default:
				Log(Error, "call service received unknown message type")
					.parameter("TypeId", serviceTransaction->nodeTypeRequest());
		}
	}

}
