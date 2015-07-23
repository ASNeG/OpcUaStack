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
	SubscriptionService::subscriptionServicePublishIf(SubscriptionServicePublishIf* subscriptionServicePublishIf)
	{
		subscriptionServicePublishIf_ = subscriptionServicePublishIf;
	}

	void
	SubscriptionService::sendSync(ServiceTransactionCreateSubscription::SPtr serviceTransactionCreateSubscription)
	{
		serviceTransactionCreateSubscription->sync(true);
		serviceTransactionCreateSubscription->conditionBool().conditionInit();
		send(serviceTransactionCreateSubscription);
		serviceTransactionCreateSubscription->conditionBool().waitForCondition();
		Log(Debug, "receive create subscription response");
	}

	void
	SubscriptionService::send(ServiceTransactionCreateSubscription::SPtr serviceTransactionCreateSubscription)
	{
		Log(Debug, "send create subscription request");
		serviceTransactionCreateSubscription->componentService(this);
		componentSession_->send(serviceTransactionCreateSubscription);
	}

	void
	SubscriptionService::sendSync(ServiceTransactionModifySubscription::SPtr serviceTransactionModifySubscription)
	{
		serviceTransactionModifySubscription->sync(true);
		serviceTransactionModifySubscription->conditionBool().conditionInit();
		send(serviceTransactionModifySubscription);
		serviceTransactionModifySubscription->conditionBool().waitForCondition();
		Log(Debug, "receive modify subscription response");
	}

	void
	SubscriptionService::send(ServiceTransactionModifySubscription::SPtr serviceTransactionModifySubscription)
	{
		Log(Debug, "send modify subscription request");
		serviceTransactionModifySubscription->componentService(this);
		componentSession_->send(serviceTransactionModifySubscription);
	}

	void
	SubscriptionService::sendSync(ServiceTransactionTransferSubscriptions::SPtr serviceTransactionTransferSubscriptions)
	{
		serviceTransactionTransferSubscriptions->sync(true);
		serviceTransactionTransferSubscriptions->conditionBool().conditionInit();
		send(serviceTransactionTransferSubscriptions);
		serviceTransactionTransferSubscriptions->conditionBool().waitForCondition();
		Log(Debug, "receive transfer subscription response");
	}

	void
	SubscriptionService::send(ServiceTransactionTransferSubscriptions::SPtr serviceTransactionTransferSubscriptions)
	{
		Log(Debug, "send transfer subscription request");
		serviceTransactionTransferSubscriptions->componentService(this);
		componentSession_->send(serviceTransactionTransferSubscriptions);
	}

	void
	SubscriptionService::sendSync(ServiceTransactionDeleteSubscriptions::SPtr serviceTransactionDeleteSubscriptions)
	{
		serviceTransactionDeleteSubscriptions->sync(true);
		serviceTransactionDeleteSubscriptions->conditionBool().conditionInit();
		send(serviceTransactionDeleteSubscriptions);
		serviceTransactionDeleteSubscriptions->conditionBool().waitForCondition();
		Log(Debug, "receive delete subscriptions response");
	}

	void
	SubscriptionService::send(ServiceTransactionDeleteSubscriptions::SPtr serviceTransactionDeleteSubscriptions)
	{
		Log(Debug, "send delete subscriptions request");
		serviceTransactionDeleteSubscriptions->componentService(this);
		componentSession_->send(serviceTransactionDeleteSubscriptions);
	}

	void
	SubscriptionService::sendSync(ServiceTransactionSetPublishingMode::SPtr serviceTransactionSetPublishingMode)
	{
		serviceTransactionSetPublishingMode->sync(true);
		serviceTransactionSetPublishingMode->conditionBool().conditionInit();
		send(serviceTransactionSetPublishingMode);
		serviceTransactionSetPublishingMode->conditionBool().waitForCondition();
		Log(Debug, "receive set publishing mode response");
	}

	void
	SubscriptionService::send(ServiceTransactionSetPublishingMode::SPtr serviceTransactionSetPublishingMode)
	{
		Log(Debug, "send set publishing mode request");
		serviceTransactionSetPublishingMode->componentService(this);
		componentSession_->send(serviceTransactionSetPublishingMode);
	}

	void
	SubscriptionService::sendSync(ServiceTransactionPublish::SPtr serviceTransactionPublish)
	{
		serviceTransactionPublish->sync(true);
		serviceTransactionPublish->conditionBool().conditionInit();
		send(serviceTransactionPublish);
		serviceTransactionPublish->conditionBool().waitForCondition();
		Log(Debug, "receive publish response");
	}

	void
	SubscriptionService::send(ServiceTransactionPublish::SPtr serviceTransactionPublish)
	{
		Log(Debug, "send publish request");
		serviceTransactionPublish->componentService(this);
		componentSession_->send(serviceTransactionPublish);
	}

	void
	SubscriptionService::sendSync(ServiceTransactionRepublish::SPtr serviceTransactionRepublish)
	{
		serviceTransactionRepublish->sync(true);
		serviceTransactionRepublish->conditionBool().conditionInit();
		send(serviceTransactionRepublish);
		serviceTransactionRepublish->conditionBool().waitForCondition();
		Log(Debug, "receive republish response");
	}

	void
	SubscriptionService::send(ServiceTransactionRepublish::SPtr serviceTransactionRepublish)
	{
		Log(Debug, "send republish request");
		serviceTransactionRepublish->componentService(this);
		componentSession_->send(serviceTransactionRepublish);
	}

	void
	SubscriptionService::receive(Message::SPtr message)
	{
		ServiceTransaction::SPtr serviceTransaction = boost::static_pointer_cast<ServiceTransaction>(message);

		// check if transaction is synchron
		if (serviceTransaction->sync()) {
			serviceTransaction->conditionBool().conditionTrue();
			return;
		}

		switch (serviceTransaction->nodeTypeResponse().nodeId<uint32_t>())
		{
			case OpcUaId_CreateSubscriptionResponse_Encoding_DefaultBinary:
			{
				Log(Debug, "receive create subscription response");
				if (subscriptionServiceIf_ != nullptr) {
					subscriptionServiceIf_->subscriptionServiceCreateSubscriptionResponse(
						boost::static_pointer_cast<ServiceTransactionCreateSubscription>(serviceTransaction)
					);
				}
				break;
			}

			case OpcUaId_ModifySubscriptionResponse_Encoding_DefaultBinary:
			{
				Log(Debug, "receive modify subscription response");
				if (subscriptionServiceIf_ != nullptr) {
					subscriptionServiceIf_->subscriptionServiceModifySubscriptionResponse(
						boost::static_pointer_cast<ServiceTransactionModifySubscription>(serviceTransaction)
					);
				}
				break;
			}

			case OpcUaId_TransferSubscriptionsResponse_Encoding_DefaultBinary:
			{
				Log(Debug, "receive transfer subscription response");
				if (subscriptionServiceIf_ != nullptr) {
					subscriptionServiceIf_->subscriptionServiceTransferSubscriptionsResponse(
						boost::static_pointer_cast<ServiceTransactionTransferSubscriptions>(serviceTransaction)
					);
				}
				break;
			}

			case OpcUaId_DeleteSubscriptionsResponse_Encoding_DefaultBinary:
			{
				Log(Debug, "receive delete subscriptions response");
				if (subscriptionServiceIf_ != nullptr) {
					subscriptionServiceIf_->subscriptionServiceDeleteSubscriptionsResponse(
						boost::static_pointer_cast<ServiceTransactionDeleteSubscriptions>(serviceTransaction)
					);
				}
				break;
			}

			case OpcUaId_SetPublishingModeResponse_Encoding_DefaultBinary:
			{
				Log(Debug, "receive set publishing mode response");
				if (subscriptionServicePublishIf_ != nullptr) {
					subscriptionServicePublishIf_->subscriptionServiceSetPublishingModeResponse(
						boost::static_pointer_cast<ServiceTransactionSetPublishingMode>(serviceTransaction)
					);
				}
				break;
			}

			case OpcUaId_PublishResponse_Encoding_DefaultBinary:
			{
				Log(Debug, "receive publish response");
				if (subscriptionServicePublishIf_ != nullptr) {
					subscriptionServicePublishIf_->subscriptionServicePublishResponse(
						boost::static_pointer_cast<ServiceTransactionPublish>(serviceTransaction)
					);
				}
				break;
			}

			case OpcUaId_RepublishResponse_Encoding_DefaultBinary:
			{
				Log(Debug, "receive republish response");
				if (subscriptionServicePublishIf_ != nullptr) {
					subscriptionServicePublishIf_->subscriptionServiceRepublishResponse(
						boost::static_pointer_cast<ServiceTransactionRepublish>(serviceTransaction)
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
