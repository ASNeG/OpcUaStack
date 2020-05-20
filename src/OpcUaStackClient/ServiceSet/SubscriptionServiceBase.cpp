/*
   Copyright 2015-2020 Kai Huebl (kai@huebl-sgh.de)

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
	: ClientServiceBase()
	, subscriptionServicePublishIf_(nullptr)
	{
	}

	SubscriptionServiceBase::~SubscriptionServiceBase(void)
	{
	}

	void
	SubscriptionServiceBase::subscriptionServicePublishIf(SubscriptionServicePublishIf* subscriptionServicePublishIf)
	{
		subscriptionServicePublishIf_ = subscriptionServicePublishIf;
	}

	void
	SubscriptionServiceBase::syncSend(const ServiceTransactionCreateSubscription::SPtr& serviceTransactionCreateSubscription)
	{
		ClientServiceBase::syncSend(sessionMember_, serviceTransactionCreateSubscription);
	}

	void
	SubscriptionServiceBase::asyncSend(const ServiceTransactionCreateSubscription::SPtr& serviceTransactionCreateSubscription)
	{
		ClientServiceBase::asyncSend(sessionMember_, serviceTransactionCreateSubscription);
	}

	void
	SubscriptionServiceBase::syncSend(const ServiceTransactionModifySubscription::SPtr& serviceTransactionModifySubscription)
	{
		ClientServiceBase::syncSend(sessionMember_, serviceTransactionModifySubscription);
	}

	void
	SubscriptionServiceBase::asyncSend(const ServiceTransactionModifySubscription::SPtr& serviceTransactionModifySubscription)
	{
		ClientServiceBase::asyncSend(sessionMember_, serviceTransactionModifySubscription);
	}

	void
	SubscriptionServiceBase::syncSend(const ServiceTransactionTransferSubscriptions::SPtr& serviceTransactionTransferSubscriptions)
	{
		ClientServiceBase::syncSend(sessionMember_, serviceTransactionTransferSubscriptions);
	}

	void
	SubscriptionServiceBase::asyncSend(const ServiceTransactionTransferSubscriptions::SPtr& serviceTransactionTransferSubscriptions)
	{
		ClientServiceBase::asyncSend(sessionMember_, serviceTransactionTransferSubscriptions);
	}

	void
	SubscriptionServiceBase::syncSend(const ServiceTransactionDeleteSubscriptions::SPtr& serviceTransactionDeleteSubscriptions)
	{
		ClientServiceBase::syncSend(sessionMember_, serviceTransactionDeleteSubscriptions);
	}

	void
	SubscriptionServiceBase::asyncSend(const ServiceTransactionDeleteSubscriptions::SPtr& serviceTransactionDeleteSubscriptions)
	{
		ClientServiceBase::asyncSend(sessionMember_, serviceTransactionDeleteSubscriptions);
	}

	void
	SubscriptionServiceBase::syncSend(const ServiceTransactionSetPublishingMode::SPtr& serviceTransactionSetPublishingMode)
	{
		ClientServiceBase::syncSend(sessionMember_, serviceTransactionSetPublishingMode);
	}

	void
	SubscriptionServiceBase::asyncSend(const ServiceTransactionSetPublishingMode::SPtr& serviceTransactionSetPublishingMode)
	{
		ClientServiceBase::asyncSend(sessionMember_, serviceTransactionSetPublishingMode);
	}

	void
	SubscriptionServiceBase::syncSend(const ServiceTransactionPublish::SPtr& serviceTransactionPublish)
	{
		ClientServiceBase::syncSend(sessionMember_, serviceTransactionPublish);
	}

	void
	SubscriptionServiceBase::asyncSend(const ServiceTransactionPublish::SPtr& serviceTransactionPublish)
	{
		ClientServiceBase::asyncSend(sessionMember_, serviceTransactionPublish);
	}

	void
	SubscriptionServiceBase::syncSend(const ServiceTransactionRepublish::SPtr& serviceTransactionRepublish)
	{
		ClientServiceBase::syncSend(sessionMember_, serviceTransactionRepublish);
	}

	void
	SubscriptionServiceBase::asyncSend(const ServiceTransactionRepublish::SPtr& serviceTransactionRepublish)
	{
		ClientServiceBase::asyncSend(sessionMember_, serviceTransactionRepublish);
	}

	void
	SubscriptionServiceBase::receive(
		const OpcUaStackCore::MessageBusMember::WPtr& handleFrom,
		Message::SPtr message
	)
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
				auto handlerStrand = trx->resultHandlerStrand();
				if (handler) {
					if (handlerStrand) {
						handlerStrand->dispatch(
							[this, handler, trx](void) mutable {
							    handler(trx);
						    }
						);
					}
					else {
					    handler(trx);
					}
				}
				break;
			}

			case OpcUaId_ModifySubscriptionResponse_Encoding_DefaultBinary:
			{
				auto trx = boost::static_pointer_cast<ServiceTransactionModifySubscription>(serviceTransaction);
				auto handler = trx->resultHandler();
				auto handlerStrand = trx->resultHandlerStrand();
				if (handler) {
					if (handlerStrand) {
						handlerStrand->dispatch(
							[this, handler, trx](void) mutable {
							    handler(trx);
						    }
						);
					}
					else {
					    handler(trx);
					}
				}
				break;
			}

			case OpcUaId_TransferSubscriptionsResponse_Encoding_DefaultBinary:
			{
				auto trx = boost::static_pointer_cast<ServiceTransactionTransferSubscriptions>(serviceTransaction);
				auto handler = trx->resultHandler();
				auto handlerStrand = trx->resultHandlerStrand();
				if (handler) {
					if (handlerStrand) {
						handlerStrand->dispatch(
							[this, handler, trx](void) mutable {
							    handler(trx);
						    }
						);
					}
					else {
					    handler(trx);
					}
				}
				break;
			}

			case OpcUaId_DeleteSubscriptionsResponse_Encoding_DefaultBinary:
			{
				auto trx = boost::static_pointer_cast<ServiceTransactionDeleteSubscriptions>(serviceTransaction);
				auto handler = trx->resultHandler();
				auto handlerStrand = trx->resultHandlerStrand();
				if (handler) {
					if (handlerStrand) {
						handlerStrand->dispatch(
							[this, handler, trx](void) mutable {
							    handler(trx);
						    }
						);
					}
					else {
					    handler(trx);
					}
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
