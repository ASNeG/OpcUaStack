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
	MonitoredItemService::receive(Message::SPtr message)
	{
		ServiceTransaction::SPtr serviceTransaction = boost::static_pointer_cast<ServiceTransaction>(message);
		switch (serviceTransaction->nodeTypeRequest().nodeId<uint32_t>()) 
		{
			case OpcUaId_CreateMonitoredItemsRequest_Encoding_DefaultBinary:
				receiveCreateMonitoredItemsRequest(serviceTransaction);
				break;
			case OpcUaId_DeleteMonitoredItemsRequest_Encoding_DefaultBinary:
				receiveDeleteMonitoredItemsRequest(serviceTransaction);
				break;
			case OpcUaId_ModifyMonitoredItemsRequest_Encoding_DefaultBinary:
				receiveModifyMonitoredItemsRequest(serviceTransaction);
				break;
			case OpcUaId_SetMonitoringModeRequest_Encoding_DefaultBinary:
				receiveSetmonitoringModeRequest(serviceTransaction);
				break;
			case OpcUaId_SetTriggeringRequest_Encoding_DefaultBinary:
				receiveSetTriggeringRequest(serviceTransaction);
				break;
			default:
				serviceTransaction->statusCode(BadInternalError);
				serviceTransaction->componentSession()->send(serviceTransaction);
		}
	}

	static uint32_t itemId = 0;
	void 
	MonitoredItemService::receiveCreateMonitoredItemsRequest(ServiceTransaction::SPtr serviceTransaction)
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
				
				MonitoredItemCreateResult::SPtr monitoredItemCreateResult = constructSPtr<MonitoredItemCreateResult>();
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
		serviceTransaction->componentSession()->send(serviceTransaction);
	}

	void 
	MonitoredItemService::receiveDeleteMonitoredItemsRequest(ServiceTransaction::SPtr serviceTransaction)
	{
		// FIXME:
		serviceTransaction->statusCode(BadInternalError);
		serviceTransaction->componentSession()->send(serviceTransaction);
	}

	void 
	MonitoredItemService::receiveModifyMonitoredItemsRequest(ServiceTransaction::SPtr serviceTransaction)
	{
		// FIXME:
		serviceTransaction->statusCode(BadInternalError);
		serviceTransaction->componentSession()->send(serviceTransaction);
	}

	void 
	MonitoredItemService::receiveSetmonitoringModeRequest(ServiceTransaction::SPtr serviceTransaction)
	{
		// FIXME:
		serviceTransaction->statusCode(BadInternalError);
		serviceTransaction->componentSession()->send(serviceTransaction);
	}

	void 
	MonitoredItemService::receiveSetTriggeringRequest(ServiceTransaction::SPtr serviceTransaction)
	{
		// FIXME:
		serviceTransaction->statusCode(BadInternalError);
		serviceTransaction->componentSession()->send(serviceTransaction);
	}

}
