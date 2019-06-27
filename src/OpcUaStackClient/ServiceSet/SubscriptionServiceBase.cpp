/*
   Copyright 2015-2019 Kai Huebl (kai@huebl-sgh.de)

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
#include "OpcUaStackClient/ServiceSet/SubscriptionServiceBase.h"

using namespace OpcUaStackCore;

namespace OpcUaStackClient
{

	SubscriptionServiceBase::SubscriptionServiceBase(void)
	: componentSession_(nullptr)
	, subscriptionServicePublishIf_(nullptr)
	{
	}

	SubscriptionServiceBase::~SubscriptionServiceBase(void)
	{
	}

	void
	SubscriptionServiceBase::componentSession(Component* componentSession)
	{
		componentSession_ = componentSession;
	}
	void
	SubscriptionServiceBase::subscriptionServicePublishIf(SubscriptionServicePublishIf* subscriptionServicePublishIf)
	{
		subscriptionServicePublishIf_ = subscriptionServicePublishIf;
	}

	void
	SubscriptionServiceBase::syncSend(ServiceTransactionCreateSubscription::SPtr& serviceTransactionCreateSubscription)
	{
		serviceTransactionCreateSubscription->sync(true);
		auto future = serviceTransactionCreateSubscription->promise().get_future();
		asyncSend(serviceTransactionCreateSubscription);
		future.wait();
	}

	void
	SubscriptionServiceBase::asyncSend(ServiceTransactionCreateSubscription::SPtr& serviceTransactionCreateSubscription)
	{
		serviceTransactionCreateSubscription->componentService(this);
		componentSession_->sendAsync(serviceTransactionCreateSubscription);
	}

	void
	SubscriptionServiceBase::syncSend(ServiceTransactionModifySubscription::SPtr& serviceTransactionModifySubscription)
	{
		serviceTransactionModifySubscription->sync(true);
		auto future = serviceTransactionModifySubscription->promise().get_future();
		asyncSend(serviceTransactionModifySubscription);
		future.wait();
	}

	void
	SubscriptionServiceBase::asyncSend(ServiceTransactionModifySubscription::SPtr& serviceTransactionModifySubscription)
	{
		serviceTransactionModifySubscription->componentService(this);
		componentSession_->sendAsync(serviceTransactionModifySubscription);
	}

	void
	SubscriptionServiceBase::syncSend(ServiceTransactionTransferSubscriptions::SPtr& serviceTransactionTransferSubscriptions)
	{
		serviceTransactionTransferSubscriptions->sync(true);
		auto future = serviceTransactionTransferSubscriptions->promise().get_future();
		asyncSend(serviceTransactionTransferSubscriptions);
		future.wait();
	}

	void
	SubscriptionServiceBase::asyncSend(ServiceTransactionTransferSubscriptions::SPtr& serviceTransactionTransferSubscriptions)
	{
		serviceTransactionTransferSubscriptions->componentService(this);
		componentSession_->sendAsync(serviceTransactionTransferSubscriptions);
	}

	void
	SubscriptionServiceBase::syncSend(ServiceTransactionDeleteSubscriptions::SPtr& serviceTransactionDeleteSubscriptions)
	{
		serviceTransactionDeleteSubscriptions->sync(true);
		auto future = serviceTransactionDeleteSubscriptions->promise().get_future();
		asyncSend(serviceTransactionDeleteSubscriptions);
		future.wait();
	}

	void
	SubscriptionServiceBase::asyncSend(ServiceTransactionDeleteSubscriptions::SPtr& serviceTransactionDeleteSubscriptions)
	{
		serviceTransactionDeleteSubscriptions->componentService(this);
		componentSession_->sendAsync(serviceTransactionDeleteSubscriptions);
	}

	void
	SubscriptionServiceBase::syncSend(ServiceTransactionSetPublishingMode::SPtr& serviceTransactionSetPublishingMode)
	{
		serviceTransactionSetPublishingMode->sync(true);
		auto future = serviceTransactionSetPublishingMode->promise().get_future();
		asyncSend(serviceTransactionSetPublishingMode);
		future.wait();
	}

	void
	SubscriptionServiceBase::asyncSend(ServiceTransactionSetPublishingMode::SPtr& serviceTransactionSetPublishingMode)
	{
		serviceTransactionSetPublishingMode->componentService(this);
		componentSession_->sendAsync(serviceTransactionSetPublishingMode);
	}

	void
	SubscriptionServiceBase::syncSend(ServiceTransactionPublish::SPtr& serviceTransactionPublish)
	{
		serviceTransactionPublish->sync(true);
		auto future = serviceTransactionPublish->promise().get_future();
		asyncSend(serviceTransactionPublish);
		future.wait();
	}

	void
	SubscriptionServiceBase::asyncSend(ServiceTransactionPublish::SPtr& serviceTransactionPublish)
	{
		serviceTransactionPublish->componentService(this);
		componentSession_->sendAsync(serviceTransactionPublish);
	}

	void
	SubscriptionServiceBase::syncSend(ServiceTransactionRepublish::SPtr& serviceTransactionRepublish)
	{
		serviceTransactionRepublish->sync(true);
		auto future = serviceTransactionRepublish->promise().get_future();
		asyncSend(serviceTransactionRepublish);
		future.wait();
	}

	void
	SubscriptionServiceBase::asyncSend(ServiceTransactionRepublish::SPtr& serviceTransactionRepublish)
	{
		serviceTransactionRepublish->componentService(this);
		componentSession_->sendAsync(serviceTransactionRepublish);
	}

	void
	SubscriptionServiceBase::receive(Message::SPtr message)
	{
		auto serviceTransaction = boost::static_pointer_cast<ServiceTransaction>(message);

		// check if transaction is synchron
		if (serviceTransaction->sync()) {
			serviceTransaction->promise().set_value(true);
			return;
		}

		switch (serviceTransaction->nodeTypeResponse().nodeId<uint32_t>())
		{
			case OpcUaId_CreateSubscriptionResponse_Encoding_DefaultBinary:
			{
				auto trx = boost::static_pointer_cast<ServiceTransactionCreateSubscription>(serviceTransaction);
				auto handler = trx->resultHandler();
				if (handler) {
					handler(trx);
				}
				break;
			}

			case OpcUaId_ModifySubscriptionResponse_Encoding_DefaultBinary:
			{
				auto trx = boost::static_pointer_cast<ServiceTransactionModifySubscription>(serviceTransaction);
				auto handler = trx->resultHandler();
				if (handler) {
					handler(trx);
				}
				break;
			}

			case OpcUaId_TransferSubscriptionsResponse_Encoding_DefaultBinary:
			{
				auto trx = boost::static_pointer_cast<ServiceTransactionTransferSubscriptions>(serviceTransaction);
				auto handler = trx->resultHandler();
				if (handler) {
					handler(trx);
				}
				break;
			}

			case OpcUaId_DeleteSubscriptionsResponse_Encoding_DefaultBinary:
			{
				auto trx = boost::static_pointer_cast<ServiceTransactionDeleteSubscriptions>(serviceTransaction);
				auto handler = trx->resultHandler();
				if (handler) {
					handler(trx);
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
