#include "OpcUaStackCore/Base/Log.h"
#include "OpcUaStackClient/ServiceSet/MonitoredItemService.h"

using namespace OpcUaStackCore;

namespace OpcUaStackClient
{

	MonitoredItemService::MonitoredItemService(void)
	: componentSession_(nullptr)
	, monitoredItemServiceIf_(nullptr)
	{
	}

	MonitoredItemService::~MonitoredItemService(void)
	{
	}

	void
	MonitoredItemService::componentSession(Component* componentSession)
	{
		componentSession_ = componentSession;
	}

	void
	MonitoredItemService::monitoredItemServiceIf(MonitoredItemServiceIf* monitoredItemServiceIf)
	{
		monitoredItemServiceIf_ = monitoredItemServiceIf;
	}

	void
	MonitoredItemService::sendSync(ServiceTransactionCreateMonitoredItems::SPtr serviceTransactionCreateMonitoredItems)
	{
		serviceTransactionCreateMonitoredItems->sync(true);
		serviceTransactionCreateMonitoredItems->conditionBool().conditionInit();
		send(serviceTransactionCreateMonitoredItems);
		serviceTransactionCreateMonitoredItems->conditionBool().waitForCondition();
		Log(Debug, "receive create monitored items response");
	}

	void
	MonitoredItemService::send(ServiceTransactionCreateMonitoredItems::SPtr serviceTransactionCreateMonitoredItems)
	{
		Log(Debug, "send create monitored items request");
		serviceTransactionCreateMonitoredItems->componentService(this);
		componentSession_->send(serviceTransactionCreateMonitoredItems);
	}

	void
	MonitoredItemService::sendSync(ServiceTransactionDeleteMonitoredItems::SPtr serviceTransactionDeleteMonitoredItems)
	{
		serviceTransactionDeleteMonitoredItems->sync(true);
		serviceTransactionDeleteMonitoredItems->conditionBool().conditionInit();
		send(serviceTransactionDeleteMonitoredItems);
		serviceTransactionDeleteMonitoredItems->conditionBool().waitForCondition();
		Log(Debug, "receive delete monitored items response");
	}

	void
	MonitoredItemService::send(ServiceTransactionDeleteMonitoredItems::SPtr serviceTransactionDeleteMonitoredItems)
	{
		Log(Debug, "send delete monitored items request");
		serviceTransactionDeleteMonitoredItems->componentService(this);
		componentSession_->send(serviceTransactionDeleteMonitoredItems);
	}

	void
	MonitoredItemService::sendSync(ServiceTransactionModifyMonitoredItems::SPtr serviceTransactionModifyMonitoredItems)
	{
		serviceTransactionModifyMonitoredItems->sync(true);
		serviceTransactionModifyMonitoredItems->conditionBool().conditionInit();
		send(serviceTransactionModifyMonitoredItems);
		serviceTransactionModifyMonitoredItems->conditionBool().waitForCondition();
		Log(Debug, "receive modify monitored items response");
	}

	void
	MonitoredItemService::send(ServiceTransactionModifyMonitoredItems::SPtr serviceTransactionModifyMonitoredItems)
	{
		Log(Debug, "send modify monitored items request");
		serviceTransactionModifyMonitoredItems->componentService(this);
		componentSession_->send(serviceTransactionModifyMonitoredItems);
	}

	void
	MonitoredItemService::sendSync(ServiceTransactionSetMonitoringMode::SPtr serviceTransactionSetMonitoringMode)
	{
		serviceTransactionSetMonitoringMode->sync(true);
		serviceTransactionSetMonitoringMode->conditionBool().conditionInit();
		send(serviceTransactionSetMonitoringMode);
		serviceTransactionSetMonitoringMode->conditionBool().waitForCondition();
		Log(Debug, "receive set monitoring mode response");
	}

	void
	MonitoredItemService::send(ServiceTransactionSetMonitoringMode::SPtr serviceTransactionSetMonitoringMode)
	{
		Log(Debug, "send set monitoring mode request");
		serviceTransactionSetMonitoringMode->componentService(this);
		componentSession_->send(serviceTransactionSetMonitoringMode);
	}

	void
	MonitoredItemService::sendSync(ServiceTransactionSetTriggering::SPtr serviceTransactionSetTriggering)
	{
		serviceTransactionSetTriggering->sync(true);
		serviceTransactionSetTriggering->conditionBool().conditionInit();
		send(serviceTransactionSetTriggering);
		serviceTransactionSetTriggering->conditionBool().waitForCondition();
		Log(Debug, "receive set triggering response");
	}

	void
	MonitoredItemService::send(ServiceTransactionSetTriggering::SPtr serviceTransactionSetTriggering)
	{
		Log(Debug, "send set triggering request");
		serviceTransactionSetTriggering->componentService(this);
		componentSession_->send(serviceTransactionSetTriggering);
	}

	void
	MonitoredItemService::receive(Message::SPtr message)
	{
		ServiceTransaction::SPtr serviceTransaction = boost::static_pointer_cast<ServiceTransaction>(message);

		// check if transaction is synchron
		if (serviceTransaction->sync()) {
			serviceTransaction->conditionBool().conditionTrue();
			return;
		}

		switch (serviceTransaction->nodeTypeResponse().nodeId<uint32_t>())
		{
			case OpcUaId_CreateMonitoredItemsResponse_Encoding_DefaultBinary:
			{
				Log(Debug, "receive create monitored items response");
				if (monitoredItemServiceIf_ != nullptr) {
					monitoredItemServiceIf_->monitoredItemServiceCreateMonitoredItemsResponse(
						boost::static_pointer_cast<ServiceTransactionCreateMonitoredItems>(serviceTransaction)
					);
				}
				break;
			}

			case OpcUaId_DeleteMonitoredItemsResponse_Encoding_DefaultBinary:
			{
				Log(Debug, "receive delete monitored items response");
				if (monitoredItemServiceIf_ != nullptr) {
					monitoredItemServiceIf_->monitoredItemServiceDeleteMonitoredItemsResponse(
						boost::static_pointer_cast<ServiceTransactionDeleteMonitoredItems>(serviceTransaction)
					);
				}
				break;
			}

			case OpcUaId_ModifyMonitoredItemsResponse_Encoding_DefaultBinary:
			{
				Log(Debug, "receive modify monitored items response");
				if (monitoredItemServiceIf_ != nullptr) {
					monitoredItemServiceIf_->monitoredItemServiceModifyMonitoredItemsResponse(
						boost::static_pointer_cast<ServiceTransactionModifyMonitoredItems>(serviceTransaction)
					);
				}
				break;
			}

			case OpcUaId_SetMonitoringModeResponse_Encoding_DefaultBinary:
			{
				Log(Debug, "receive set monitoring response");
				if (monitoredItemServiceIf_ != nullptr) {
					monitoredItemServiceIf_->monitoredItemServiceSetMonitoringModeResponse(
						boost::static_pointer_cast<ServiceTransactionSetMonitoringMode>(serviceTransaction)
					);
				}
				break;
			}

			case OpcUaId_SetTriggeringResponse_Encoding_DefaultBinary:
			{
				Log(Debug, "receive set triggering response");
				if (monitoredItemServiceIf_ != nullptr) {
					monitoredItemServiceIf_->monitoredItemServiceSetTriggeringResponse(
						boost::static_pointer_cast<ServiceTransactionSetTriggering>(serviceTransaction)
					);
				}
				break;
			}

			default:
				Log(Error, "call service received unknown message type")
					.parameter("TypeId", serviceTransaction->nodeTypeRequest());
				break;
		}
	}

}
