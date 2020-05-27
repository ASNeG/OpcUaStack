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

#include "OpcUaStackCore/BuildInTypes/OpcUaIdentifier.h"
#include "OpcUaStackCore/Base/Log.h"
#include "OpcUaStackServer/ServiceSet/MonitoredItemService.h"

using namespace OpcUaStackCore;

namespace OpcUaStackServer
{

	MonitoredItemService::MonitoredItemService(
		const std::string& serviceName,
		OpcUaStackCore::IOThread::SPtr& ioThread,
		OpcUaStackCore::MessageBus::SPtr& messageBus
	)
	: ServerServiceBase()
	{
		// set parameter in server service base
		serviceName_ = serviceName;
		ServerServiceBase::ioThread_ = ioThread.get();
		strand_ = ioThread->createStrand();
		messageBus_ = messageBus;

		// register message bus receiver
		MessageBusMemberConfig messageBusMemberConfig;
		messageBusMemberConfig.strand(strand_);
		messageBusMember_ = messageBus_->registerMember(serviceName_, messageBusMemberConfig);

		// activate receiver
		activateReceiver(
			[this](const MessageBusMember::WPtr& handleFrom, Message::SPtr& message){
				receive(handleFrom, message);
			}
		);
	}

	MonitoredItemService::~MonitoredItemService(void)
	{
		// deactivate receiver
		deactivateReceiver();
		messageBus_->deregisterMember(messageBusMember_);
	}

	void 
	MonitoredItemService::receive(
		const MessageBusMember::WPtr& handleFrom,
		Message::SPtr& message
	)
	{
		// We have to remember the sender of the message. This enables us to
		// send a reply for the received message later
		auto serviceTransaction = boost::static_pointer_cast<ServiceTransaction>(message);
		serviceTransaction->memberServiceSession(handleFrom);

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
				sendAnswer(serviceTransaction);
		}
	}

	void
	MonitoredItemService::sendAnswer(OpcUaStackCore::ServiceTransaction::SPtr& serviceTransaction)
	{
		messageBus_->messageSend(
			messageBusMember_,
			serviceTransaction->memberServiceSession(),
			serviceTransaction
		);
	}

	static uint32_t itemId = 0;
	void 
	MonitoredItemService::receiveCreateMonitoredItemsRequest(ServiceTransaction::SPtr serviceTransaction)
	{
		// FIXME: dummy implementation

		auto trx = boost::static_pointer_cast<ServiceTransactionCreateMonitoredItems>(serviceTransaction);
		auto createMonitoredItemsRequest = trx->request();
		auto createMonitoredItemsResponse = trx->response();

		uint32_t items = createMonitoredItemsRequest->itemsToCreate()->size();
		Log(Debug, "create monitored items")
			.parameter("SubscriptionId", createMonitoredItemsRequest->subscriptionId())
			.parameter("Items", items);

		if (items > 0) {
		    createMonitoredItemsResponse->results()->resize(items);

			for (uint32_t idx=0; idx<items; idx++) {
				MonitoredItemCreateRequest::SPtr monitoredItemCreateRequest;
				createMonitoredItemsRequest->itemsToCreate()->get(idx, monitoredItemCreateRequest);
				
				MonitoredItemCreateResult::SPtr monitoredItemCreateResult = boost::make_shared<MonitoredItemCreateResult>();
				createMonitoredItemsResponse->results()->set(idx, monitoredItemCreateResult);

				itemId++;
				Log(Debug, "create monitored item")
					.parameter("NodeId", monitoredItemCreateRequest->itemToMonitor().nodeId())
					.parameter("MonitoredItemId", itemId)
					.parameter("SamplingInterval", monitoredItemCreateRequest->requestedParameters().samplingInterval())
					.parameter("QueueSize", monitoredItemCreateRequest->requestedParameters().queueSize());

				monitoredItemCreateResult->statusCode().enumeration(Success);
				monitoredItemCreateResult->monitoredItemId() = itemId;
				monitoredItemCreateResult->revisedSamplingInterval() = monitoredItemCreateRequest->requestedParameters().samplingInterval();
				monitoredItemCreateResult->revisedQueueSize() =  monitoredItemCreateRequest->requestedParameters().queueSize();
			}
		}

		serviceTransaction->statusCode(Success);
		sendAnswer(serviceTransaction);
	}

	void 
	MonitoredItemService::receiveDeleteMonitoredItemsRequest(ServiceTransaction::SPtr serviceTransaction)
	{
		// FIXME:
		serviceTransaction->statusCode(BadInternalError);
		sendAnswer(serviceTransaction);
	}

	void 
	MonitoredItemService::receiveModifyMonitoredItemsRequest(ServiceTransaction::SPtr serviceTransaction)
	{
		// FIXME:
		serviceTransaction->statusCode(BadInternalError);
		sendAnswer(serviceTransaction);
	}

	void 
	MonitoredItemService::receiveSetmonitoringModeRequest(ServiceTransaction::SPtr serviceTransaction)
	{
		// FIXME:
		serviceTransaction->statusCode(BadInternalError);
		sendAnswer(serviceTransaction);
	}

	void 
	MonitoredItemService::receiveSetTriggeringRequest(ServiceTransaction::SPtr serviceTransaction)
	{
		// FIXME:
		serviceTransaction->statusCode(BadInternalError);
		sendAnswer(serviceTransaction);
	}

}
