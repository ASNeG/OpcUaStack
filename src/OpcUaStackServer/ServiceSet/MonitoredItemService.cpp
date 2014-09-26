#include "OpcUaStackCore/BuildInTypes/OpcUaIdentifier.h"
#include "OpcUaStackCore/Base/Log.h"
#include "OpcUaStackServer/ServiceSet/MonitoredItemService.h"

namespace OpcUaStackServer
{

	MonitoredItemService::MonitoredItemService(void)
	{
	}

	MonitoredItemService::~MonitoredItemService(void)
	{
	}

	void 
	MonitoredItemService::receive(OpcUaNodeId& typeId, ServiceTransaction::SPtr serviceTransaction)
	{
		switch (serviceTransaction->nodeTypeRequest().nodeId<uint32_t>()) 
		{
			case OpcUaId_CreateMonitoredItemsRequest_Encoding_DefaultBinary:
				receiveCreateMonitoredItemsRequest(typeId, serviceTransaction);
				break;
			case OpcUaId_DeleteMonitoredItemsRequest_Encoding_DefaultBinary:
				receiveDeleteMonitoredItemsRequest(typeId, serviceTransaction);
				break;
			case OpcUaId_ModifyMonitoredItemsRequest_Encoding_DefaultBinary:
				receiveModifyMonitoredItemsRequest(typeId, serviceTransaction);
				break;
			case OpcUaId_SetMonitoringModeRequest_Encoding_DefaultBinary:
				receiveSetmonitoringModeRequest(typeId, serviceTransaction);
				break;
			case OpcUaId_SetTriggeringRequest_Encoding_DefaultBinary:
				receiveSetTriggeringRequest(typeId, serviceTransaction);
				break;
			default:
				serviceTransaction->statusCode(BadInternalError);
				serviceTransaction->serviceTransactionIfSession()->receive(typeId, serviceTransaction);
		}
	}

	static uint32_t itemId = 0;
	void 
	MonitoredItemService::receiveCreateMonitoredItemsRequest(OpcUaNodeId& typeId, ServiceTransaction::SPtr serviceTransaction)
	{
		// FIXME: dummy implementation

		ServiceTransactionCreateMonitoredItems::SPtr trx = boost::static_pointer_cast<ServiceTransactionCreateMonitoredItems>(serviceTransaction);
		CreateMonitoredItemsRequest::SPtr createMonitoredItemsRequest = trx->request();
		CreateMonitoredItemsResponse::SPtr createMonitoredItemsResponse = trx->response();

		uint32_t items = createMonitoredItemsRequest->itemsToCreate()->size();
		Log(Debug, "create monitored items")
			.parameter("SubscriptionId", createMonitoredItemsRequest->subscriptionId())
			.parameter("Items", items);

		if (items > 0) {
		    createMonitoredItemsResponse->results()->resize(items);

			for (uint32_t idx=0; idx<items; idx++) {
				MonitoredItemCreateRequest::SPtr monitoredItemCreateRequest;
				createMonitoredItemsRequest->itemsToCreate()->get(idx, monitoredItemCreateRequest);
				
				MonitoredItemCreateResult::SPtr monitoredItemCreateResult = MonitoredItemCreateResult::construct();
				createMonitoredItemsResponse->results()->set(idx, monitoredItemCreateResult);

				itemId++;
				Log(Debug, "create monitored item")
					.parameter("NodeId", monitoredItemCreateRequest->itemToMonitor().nodeId())
					.parameter("MonitoredItemId", itemId)
					.parameter("SamplingInterval", monitoredItemCreateRequest->requestedParameters().samplingInterval())
					.parameter("QueueSize", monitoredItemCreateRequest->requestedParameters().queueSize());

				monitoredItemCreateResult->statusCode(Success);
				monitoredItemCreateResult->monitoredItemId(itemId);
				monitoredItemCreateResult->revisedSamplingInterval(monitoredItemCreateRequest->requestedParameters().samplingInterval());
				monitoredItemCreateResult->revisedQueueSize(monitoredItemCreateRequest->requestedParameters().queueSize());
			}
		}

		serviceTransaction->statusCode(Success);
		serviceTransaction->serviceTransactionIfSession()->receive(typeId, serviceTransaction);
	}

	void 
	MonitoredItemService::receiveDeleteMonitoredItemsRequest(OpcUaNodeId& typeId, ServiceTransaction::SPtr serviceTransaction)
	{
		// FIXME:
		serviceTransaction->statusCode(BadInternalError);
		serviceTransaction->serviceTransactionIfSession()->receive(typeId, serviceTransaction);
	}

	void 
	MonitoredItemService::receiveModifyMonitoredItemsRequest(OpcUaNodeId& typeId, ServiceTransaction::SPtr serviceTransaction)
	{
		// FIXME:
		serviceTransaction->statusCode(BadInternalError);
		serviceTransaction->serviceTransactionIfSession()->receive(typeId, serviceTransaction);
	}

	void 
	MonitoredItemService::receiveSetmonitoringModeRequest(OpcUaNodeId& typeId, ServiceTransaction::SPtr serviceTransaction)
	{
		// FIXME:
		serviceTransaction->statusCode(BadInternalError);
		serviceTransaction->serviceTransactionIfSession()->receive(typeId, serviceTransaction);
	}

	void 
	MonitoredItemService::receiveSetTriggeringRequest(OpcUaNodeId& typeId, ServiceTransaction::SPtr serviceTransaction)
	{
		// FIXME:
		serviceTransaction->statusCode(BadInternalError);
		serviceTransaction->serviceTransactionIfSession()->receive(typeId, serviceTransaction);
	}

}