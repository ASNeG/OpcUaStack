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
#include "OpcUaStackClient/ServiceSet/MonitoredItemService.h"

using namespace OpcUaStackCore;

namespace OpcUaStackClient
{

	MonitoredItemService::MonitoredItemService(
		const std::string& serviceName,
		IOThread* ioThread,
		MessageBus::SPtr& messageBus
	)
	{
		// set parameter in client service base
		serviceName_ = serviceName;
		ClientServiceBase::ioThread_ = ioThread;
		strand_ = ioThread->createStrand();
		messageBus_ = messageBus;
	}

	MonitoredItemService::~MonitoredItemService(void)
	{
		// deactivate receiver
		deactivateReceiver();
	}

	void
	MonitoredItemService::setConfiguration(
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
			[this](const OpcUaStackCore::MessageBusMember::WPtr& handleFrom, Message::SPtr& message){
				receive(handleFrom, message);
			}
		);
	}

	void
	MonitoredItemService::syncSend(const ServiceTransactionCreateMonitoredItems::SPtr& serviceTransactionCreateMonitoredItems)
	{
		ClientServiceBase::syncSend(sessionMember_, serviceTransactionCreateMonitoredItems);
	}

	void
	MonitoredItemService::asyncSend(const ServiceTransactionCreateMonitoredItems::SPtr& serviceTransactionCreateMonitoredItems)
	{
		ClientServiceBase::asyncSend(sessionMember_, serviceTransactionCreateMonitoredItems);
	}

	void
	MonitoredItemService::syncSend(const ServiceTransactionDeleteMonitoredItems::SPtr& serviceTransactionDeleteMonitoredItems)
	{
		ClientServiceBase::syncSend(sessionMember_, serviceTransactionDeleteMonitoredItems);
	}

	void
	MonitoredItemService::asyncSend(const ServiceTransactionDeleteMonitoredItems::SPtr& serviceTransactionDeleteMonitoredItems)
	{
		ClientServiceBase::asyncSend(sessionMember_, serviceTransactionDeleteMonitoredItems);
	}

	void
	MonitoredItemService::syncSend(const ServiceTransactionModifyMonitoredItems::SPtr& serviceTransactionModifyMonitoredItems)
	{
		ClientServiceBase::syncSend(sessionMember_, serviceTransactionModifyMonitoredItems);
	}

	void
	MonitoredItemService::asyncSend(const ServiceTransactionModifyMonitoredItems::SPtr& serviceTransactionModifyMonitoredItems)
	{
		ClientServiceBase::asyncSend(sessionMember_, serviceTransactionModifyMonitoredItems);
	}

	void
	MonitoredItemService::syncSend(const ServiceTransactionSetMonitoringMode::SPtr& serviceTransactionSetMonitoringMode)
	{
		ClientServiceBase::syncSend(sessionMember_, serviceTransactionSetMonitoringMode);
	}

	void
	MonitoredItemService::asyncSend(const ServiceTransactionSetMonitoringMode::SPtr& serviceTransactionSetMonitoringMode)
	{
		ClientServiceBase::asyncSend(sessionMember_, serviceTransactionSetMonitoringMode);
	}

	void
	MonitoredItemService::syncSend(const ServiceTransactionSetTriggering::SPtr& serviceTransactionSetTriggering)
	{
		ClientServiceBase::syncSend(sessionMember_, serviceTransactionSetTriggering);
	}

	void
	MonitoredItemService::asyncSend(const ServiceTransactionSetTriggering::SPtr& serviceTransactionSetTriggering)
	{
		ClientServiceBase::asyncSend(sessionMember_, serviceTransactionSetTriggering);
	}

	void
	MonitoredItemService::receive(
		const OpcUaStackCore::MessageBusMember::WPtr& handleFrom,
		Message::SPtr message
	)
	{
		ServiceTransaction::SPtr serviceTransaction = boost::static_pointer_cast<ServiceTransaction>(message);

		// check if transaction is synchron
		if (serviceTransaction->sync()) {
			serviceTransaction->promise().set_value(true);
			return;
		}

		switch (serviceTransaction->nodeTypeResponse().nodeId<uint32_t>())
		{
			case OpcUaId_CreateMonitoredItemsResponse_Encoding_DefaultBinary:
			{
				auto trx = boost::static_pointer_cast<ServiceTransactionCreateMonitoredItems>(serviceTransaction);
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

			case OpcUaId_DeleteMonitoredItemsResponse_Encoding_DefaultBinary:
			{
				auto trx = boost::static_pointer_cast<ServiceTransactionDeleteMonitoredItems>(serviceTransaction);
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

			case OpcUaId_ModifyMonitoredItemsResponse_Encoding_DefaultBinary:
			{
				auto trx = boost::static_pointer_cast<ServiceTransactionModifyMonitoredItems>(serviceTransaction);
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

			case OpcUaId_SetMonitoringModeResponse_Encoding_DefaultBinary:
			{
				auto trx = boost::static_pointer_cast<ServiceTransactionSetMonitoringMode>(serviceTransaction);
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

			case OpcUaId_SetTriggeringResponse_Encoding_DefaultBinary:
			{
				auto trx = boost::static_pointer_cast<ServiceTransactionSetTriggering>(serviceTransaction);
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
				Log(Error, "monitored item service received unknown message type")
					.parameter("TypeId", serviceTransaction->nodeTypeRequest());
				break;
		}
	}

}
