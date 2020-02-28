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
	: componentSession_(nullptr)
	{
		// set parameter in client service base
		serviceName_ = serviceName;
		ClientServiceBase::ioThread_ = ioThread;
		strand_ = ioThread->createStrand();
		messageBus_ = messageBus;

		Component::ioThread(ioThread);
	}

	MonitoredItemService::~MonitoredItemService(void)
	{
		// deactivate receiver
		deactivateReceiver();
	}

	void
	MonitoredItemService::setConfiguration(
		MessageBusMember::WPtr& sessionMember,
		Component* componentSession
	)
	{
		sessionMember_ = sessionMember;
		this->componentSession(componentSession);

		// activate receiver
		activateReceiver(
			[this](Message::SPtr& message){
				receive(message);
			}
		);
	}

	void
	MonitoredItemService::componentSession(Component* componentSession)
	{
		componentSession_ = componentSession;
	}

	void
	MonitoredItemService::syncSend(ServiceTransactionCreateMonitoredItems::SPtr serviceTransactionCreateMonitoredItems)
	{
		serviceTransactionCreateMonitoredItems->sync(true);
		auto future = serviceTransactionCreateMonitoredItems->promise().get_future();
		asyncSend(serviceTransactionCreateMonitoredItems);
		future.wait();
	}

	void
	MonitoredItemService::asyncSend(ServiceTransactionCreateMonitoredItems::SPtr serviceTransactionCreateMonitoredItems)
	{
		serviceTransactionCreateMonitoredItems->componentService(this);
		componentSession_->sendAsync(serviceTransactionCreateMonitoredItems);
	}

	void
	MonitoredItemService::syncSend(ServiceTransactionDeleteMonitoredItems::SPtr serviceTransactionDeleteMonitoredItems)
	{
		serviceTransactionDeleteMonitoredItems->sync(true);
		auto future = serviceTransactionDeleteMonitoredItems->promise().get_future();
		asyncSend(serviceTransactionDeleteMonitoredItems);
		future.wait();
	}

	void
	MonitoredItemService::asyncSend(ServiceTransactionDeleteMonitoredItems::SPtr serviceTransactionDeleteMonitoredItems)
	{
		serviceTransactionDeleteMonitoredItems->componentService(this);
		componentSession_->sendAsync(serviceTransactionDeleteMonitoredItems);
	}

	void
	MonitoredItemService::syncSend(ServiceTransactionModifyMonitoredItems::SPtr serviceTransactionModifyMonitoredItems)
	{
		serviceTransactionModifyMonitoredItems->sync(true);
		auto future = serviceTransactionModifyMonitoredItems->promise().get_future();
		asyncSend(serviceTransactionModifyMonitoredItems);
		future.wait();
	}

	void
	MonitoredItemService::asyncSend(ServiceTransactionModifyMonitoredItems::SPtr serviceTransactionModifyMonitoredItems)
	{
		serviceTransactionModifyMonitoredItems->componentService(this);
		componentSession_->sendAsync(serviceTransactionModifyMonitoredItems);
	}

	void
	MonitoredItemService::syncSend(ServiceTransactionSetMonitoringMode::SPtr serviceTransactionSetMonitoringMode)
	{
		serviceTransactionSetMonitoringMode->sync(true);
		auto future = serviceTransactionSetMonitoringMode->promise().get_future();
		asyncSend(serviceTransactionSetMonitoringMode);
		future.wait();
	}

	void
	MonitoredItemService::asyncSend(ServiceTransactionSetMonitoringMode::SPtr serviceTransactionSetMonitoringMode)
	{
		serviceTransactionSetMonitoringMode->componentService(this);
		componentSession_->sendAsync(serviceTransactionSetMonitoringMode);
	}

	void
	MonitoredItemService::syncSend(ServiceTransactionSetTriggering::SPtr serviceTransactionSetTriggering)
	{
		serviceTransactionSetTriggering->sync(true);
		auto future = serviceTransactionSetTriggering->promise().get_future();
		asyncSend(serviceTransactionSetTriggering);
		future.wait();
	}

	void
	MonitoredItemService::asyncSend(ServiceTransactionSetTriggering::SPtr serviceTransactionSetTriggering)
	{
		serviceTransactionSetTriggering->componentService(this);
		componentSession_->sendAsync(serviceTransactionSetTriggering);
	}

	void
	MonitoredItemService::receive(Message::SPtr message)
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
				if (handler) {
					handler(trx);
				}
				break;
			}

			case OpcUaId_DeleteMonitoredItemsResponse_Encoding_DefaultBinary:
			{
				auto trx = boost::static_pointer_cast<ServiceTransactionDeleteMonitoredItems>(serviceTransaction);
				auto handler = trx->resultHandler();
				if (handler) {
					handler(trx);
				}
				break;
			}

			case OpcUaId_ModifyMonitoredItemsResponse_Encoding_DefaultBinary:
			{
				auto trx = boost::static_pointer_cast<ServiceTransactionModifyMonitoredItems>(serviceTransaction);
				auto handler = trx->resultHandler();
				if (handler) {
					handler(trx);
				}
				break;
			}

			case OpcUaId_SetMonitoringModeResponse_Encoding_DefaultBinary:
			{
				auto trx = boost::static_pointer_cast<ServiceTransactionSetMonitoringMode>(serviceTransaction);
				auto handler = trx->resultHandler();
				if (handler) {
					handler(trx);
				}
				break;
			}

			case OpcUaId_SetTriggeringResponse_Encoding_DefaultBinary:
			{
				auto trx = boost::static_pointer_cast<ServiceTransactionSetTriggering>(serviceTransaction);
				auto handler = trx->resultHandler();
				if (handler) {
					handler(trx);
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
