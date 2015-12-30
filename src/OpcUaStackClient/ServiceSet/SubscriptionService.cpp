/*
   Copyright 2015 Kai Huebl (kai@huebl-sgh.de)

   Lizenziert gemäß Apache Licence Version 2.0 (die „Lizenz“); Nutzung dieser
   Datei nur in Übereinstimmung mit der Lizenz erlaubt.
   Eine Kopie der Lizenz erhalten Sie auf http://www.apache.org/licenses/LICENSE-2.0.

   Sofern nicht gemäß geltendem Recht vorgeschrieben oder schriftlich vereinbart,
   erfolgt die Bereitstellung der im Rahmen der Lizenz verbreiteten Software OHNE
   GEWÄHR ODER VORBEHALTE – ganz gleich, ob ausdrücklich oder stillschweigend.

   Informationen über die jeweiligen Bedingungen für Genehmigungen und Einschränkungen
   im Rahmen der Lizenz finden Sie in der Lizenz.

   Autor: Kai Huebl (kai@huebl-sgh.de)
 */

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
	SubscriptionService::sendSync(ServiceTransactionCreateSubscription::SPtr& serviceTransactionCreateSubscription)
	{
		serviceTransactionCreateSubscription->sync(true);
		serviceTransactionCreateSubscription->conditionBool().conditionInit();
		send(serviceTransactionCreateSubscription);
		serviceTransactionCreateSubscription->conditionBool().waitForCondition();
	}

	void
	SubscriptionService::send(ServiceTransactionCreateSubscription::SPtr& serviceTransactionCreateSubscription)
	{
		serviceTransactionCreateSubscription->componentService(this);
		componentSession_->sendAsync(serviceTransactionCreateSubscription);
	}

	void
	SubscriptionService::sendSync(ServiceTransactionModifySubscription::SPtr& serviceTransactionModifySubscription)
	{
		serviceTransactionModifySubscription->sync(true);
		serviceTransactionModifySubscription->conditionBool().conditionInit();
		send(serviceTransactionModifySubscription);
		serviceTransactionModifySubscription->conditionBool().waitForCondition();
	}

	void
	SubscriptionService::send(ServiceTransactionModifySubscription::SPtr& serviceTransactionModifySubscription)
	{
		serviceTransactionModifySubscription->componentService(this);
		componentSession_->sendAsync(serviceTransactionModifySubscription);
	}

	void
	SubscriptionService::sendSync(ServiceTransactionTransferSubscriptions::SPtr& serviceTransactionTransferSubscriptions)
	{
		serviceTransactionTransferSubscriptions->sync(true);
		serviceTransactionTransferSubscriptions->conditionBool().conditionInit();
		send(serviceTransactionTransferSubscriptions);
		serviceTransactionTransferSubscriptions->conditionBool().waitForCondition();
	}

	void
	SubscriptionService::send(ServiceTransactionTransferSubscriptions::SPtr& serviceTransactionTransferSubscriptions)
	{
		serviceTransactionTransferSubscriptions->componentService(this);
		componentSession_->sendAsync(serviceTransactionTransferSubscriptions);
	}

	void
	SubscriptionService::sendSync(ServiceTransactionDeleteSubscriptions::SPtr& serviceTransactionDeleteSubscriptions)
	{
		serviceTransactionDeleteSubscriptions->sync(true);
		serviceTransactionDeleteSubscriptions->conditionBool().conditionInit();
		send(serviceTransactionDeleteSubscriptions);
		serviceTransactionDeleteSubscriptions->conditionBool().waitForCondition();
	}

	void
	SubscriptionService::send(ServiceTransactionDeleteSubscriptions::SPtr& serviceTransactionDeleteSubscriptions)
	{
		serviceTransactionDeleteSubscriptions->componentService(this);
		componentSession_->sendAsync(serviceTransactionDeleteSubscriptions);
	}

	void
	SubscriptionService::sendSync(ServiceTransactionSetPublishingMode::SPtr& serviceTransactionSetPublishingMode)
	{
		serviceTransactionSetPublishingMode->sync(true);
		serviceTransactionSetPublishingMode->conditionBool().conditionInit();
		send(serviceTransactionSetPublishingMode);
		serviceTransactionSetPublishingMode->conditionBool().waitForCondition();
	}

	void
	SubscriptionService::send(ServiceTransactionSetPublishingMode::SPtr& serviceTransactionSetPublishingMode)
	{
		serviceTransactionSetPublishingMode->componentService(this);
		componentSession_->sendAsync(serviceTransactionSetPublishingMode);
	}

	void
	SubscriptionService::sendSync(ServiceTransactionPublish::SPtr& serviceTransactionPublish)
	{
		serviceTransactionPublish->sync(true);
		serviceTransactionPublish->conditionBool().conditionInit();
		send(serviceTransactionPublish);
		serviceTransactionPublish->conditionBool().waitForCondition();
	}

	void
	SubscriptionService::send(ServiceTransactionPublish::SPtr& serviceTransactionPublish)
	{
		serviceTransactionPublish->componentService(this);
		componentSession_->sendAsync(serviceTransactionPublish);
	}

	void
	SubscriptionService::sendSync(ServiceTransactionRepublish::SPtr& serviceTransactionRepublish)
	{
		serviceTransactionRepublish->sync(true);
		serviceTransactionRepublish->conditionBool().conditionInit();
		send(serviceTransactionRepublish);
		serviceTransactionRepublish->conditionBool().waitForCondition();
	}

	void
	SubscriptionService::send(ServiceTransactionRepublish::SPtr& serviceTransactionRepublish)
	{
		serviceTransactionRepublish->componentService(this);
		componentSession_->sendAsync(serviceTransactionRepublish);
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

			case OpcUaId_SetPublishingModeResponse_Encoding_DefaultBinary:
			{
				if (subscriptionServicePublishIf_ != nullptr) {
					subscriptionServicePublishIf_->subscriptionServiceSetPublishingModeResponse(
						boost::static_pointer_cast<ServiceTransactionSetPublishingMode>(serviceTransaction)
					);
				}
				break;
			}

			case OpcUaId_PublishResponse_Encoding_DefaultBinary:
			{
				if (subscriptionServicePublishIf_ != nullptr) {
					subscriptionServicePublishIf_->subscriptionServicePublishResponse(
						boost::static_pointer_cast<ServiceTransactionPublish>(serviceTransaction)
					);
				}
				break;
			}

			case OpcUaId_RepublishResponse_Encoding_DefaultBinary:
			{
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
