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
#include "OpcUaStackClient/ServiceSet/AttributeService.h"

using namespace OpcUaStackCore;

namespace OpcUaStackClient
{

	AttributeService::AttributeService(
		const std::string& serviceName,
		IOThread* ioThread,
		MessageBus::SPtr& messageBus
	)
	: ClientServiceBase()
	{
		// set parameter in client service base
		serviceName_ = serviceName;
		ClientServiceBase::ioThread_ = ioThread;
		strand_ = ioThread->createStrand();
		messageBus_ = messageBus;
	}

	AttributeService::~AttributeService(void)
	{
		// deactivate receiver
		deactivateReceiver();
	}

	void
	AttributeService::setConfiguration(
		MessageBusMember::WPtr& sessionMember
	)
	{
		sessionMember_ = sessionMember;

		// register message bus receiver
		MessageBusMemberConfig messageBusMemberConfig;
		messageBusMemberConfig.strand(strand_);
		messageBusMember_ = messageBus_->registerMember(serviceName_, messageBusMemberConfig);

		// activate receiver
		activateReceiver(
			[this](const OpcUaStackCore::MessageBusMember::WPtr& handleFrom, Message::SPtr& message) {
				receive(handleFrom, message);
			}
		);
	}

	void 
	AttributeService::syncSend(const ServiceTransactionRead::SPtr& serviceTransactionRead)
	{
		ClientServiceBase::syncSend(sessionMember_, serviceTransactionRead);
	}

	void 
	AttributeService::asyncSend(const ServiceTransactionRead::SPtr& serviceTransactionRead)
	{
		ClientServiceBase::asyncSend(sessionMember_, serviceTransactionRead);
	}

	void 
	AttributeService::syncSend(const ServiceTransactionWrite::SPtr& serviceTransactionWrite)
	{
		ClientServiceBase::syncSend(sessionMember_, serviceTransactionWrite);
	}

	void 
	AttributeService::asyncSend(const ServiceTransactionWrite::SPtr& serviceTransactionWrite)
	{
		ClientServiceBase::asyncSend(sessionMember_, serviceTransactionWrite);
	}

	void 
	AttributeService::syncSend(const ServiceTransactionHistoryRead::SPtr& serviceTransactionHistoryRead)
	{
		ClientServiceBase::syncSend(sessionMember_, serviceTransactionHistoryRead);
	}

	void 
	AttributeService::asyncSend(const ServiceTransactionHistoryRead::SPtr& serviceTransactionHistoryRead)
	{
		ClientServiceBase::asyncSend(sessionMember_, serviceTransactionHistoryRead);
	}

	void 
	AttributeService::syncSend(const ServiceTransactionHistoryUpdate::SPtr& serviceTransactionHistoryUpdate)
	{
		ClientServiceBase::syncSend(sessionMember_, serviceTransactionHistoryUpdate);
	}

	void 
	AttributeService::asyncSend(const ServiceTransactionHistoryUpdate::SPtr& serviceTransactionHistoryUpdate)
	{
		ClientServiceBase::asyncSend(sessionMember_, serviceTransactionHistoryUpdate);
	}

	void 
	AttributeService::receive(
		const MessageBusMember::WPtr& handleFrom,
		Message::SPtr message
	)
	{
		auto serviceTransaction = boost::static_pointer_cast<ServiceTransaction>(message);
#if 1
		if (serviceTransaction->sync()) {
			serviceTransaction->promise().set_value(true);
			return;
		}
#endif

		switch (serviceTransaction->nodeTypeResponse().nodeId<uint32_t>())
		{
			case OpcUaId_ReadResponse_Encoding_DefaultBinary:
			{
				auto trx = boost::static_pointer_cast<ServiceTransactionRead>(serviceTransaction);
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
			case OpcUaId_WriteResponse_Encoding_DefaultBinary:
			{
				auto trx = boost::static_pointer_cast<ServiceTransactionWrite>(serviceTransaction);
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
			case OpcUaId_HistoryReadResponse_Encoding_DefaultBinary:
			{
				auto trx = boost::static_pointer_cast<ServiceTransactionHistoryRead>(serviceTransaction);
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
			case OpcUaId_HistoryUpdateResponse_Encoding_DefaultBinary:
			{
				auto trx = boost::static_pointer_cast<ServiceTransactionHistoryUpdate>(serviceTransaction);
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
			default:
				Log(Error, "attribute service received unknown message type")
					.parameter("TypeId", serviceTransaction->nodeTypeRequest());
		}
	}

}
