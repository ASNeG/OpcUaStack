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
#include "OpcUaStackClient/ServiceSet/DiscoveryService.h"

using namespace OpcUaStackCore;

namespace OpcUaStackClient
{

	DiscoveryService::DiscoveryService(
		const std::string& serviceName,
		IOThread* ioThread,
		OpcUaStackCore::MessageBus::SPtr& messageBus
	)
	: ClientServiceBase()
	{
		// set parameter in client service base
		serviceName_ = serviceName;
		ClientServiceBase::ioThread_ = ioThread;
		strand_ = ioThread->createStrand();
		messageBus_ = messageBus;
	}

	DiscoveryService::~DiscoveryService(void)
	{
		// deactivate receiver
		deactivateReceiver();
	}

	void
	DiscoveryService::setConfiguration(
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
			[this](Message::SPtr& message){
				receive(message);
			}
		);
	}

	void 
	DiscoveryService::syncSend(ServiceTransactionFindServers::SPtr serviceTransactionFindServers)
	{
		serviceTransactionFindServers->sync(true);
		auto future = serviceTransactionFindServers->promise().get_future();
		asyncSend(serviceTransactionFindServers);
		future.wait();
	}

	void 
	DiscoveryService::asyncSend(ServiceTransactionFindServers::SPtr serviceTransactionFindServers)
	{
		serviceTransactionFindServers->memberService(messageBusMember_);
		messageBus_->messageSend(
			messageBusMember_,
			sessionMember_,
			serviceTransactionFindServers
		);
	}

	void
	DiscoveryService::syncSend(ServiceTransactionGetEndpoints::SPtr serviceTransactionGetEndpoints)
	{
		serviceTransactionGetEndpoints->sync(true);
		auto future = serviceTransactionGetEndpoints->promise().get_future();
		asyncSend(serviceTransactionGetEndpoints);
		future.wait();
	}

	void
	DiscoveryService::asyncSend(ServiceTransactionGetEndpoints::SPtr serviceTransactionGetEndpoints)
	{
		serviceTransactionGetEndpoints->memberService(messageBusMember_);
		messageBus_->messageSend(
			messageBusMember_,
			sessionMember_,
			serviceTransactionGetEndpoints
		);
	}

	void
	DiscoveryService::syncSend(ServiceTransactionRegisterServer::SPtr serviceTransactionRegisterServer)
	{
		serviceTransactionRegisterServer->sync(true);
		auto future = serviceTransactionRegisterServer->promise().get_future();
		asyncSend(serviceTransactionRegisterServer);
		future.wait();
	}

	void
	DiscoveryService::asyncSend(ServiceTransactionRegisterServer::SPtr serviceTransactionRegisterServer)
	{
		serviceTransactionRegisterServer->memberService(messageBusMember_);
		messageBus_->messageSend(
			messageBusMember_,
			sessionMember_,
			serviceTransactionRegisterServer
		);
	}

	void 
	DiscoveryService::receive(Message::SPtr message)
	{
		auto serviceTransaction = boost::static_pointer_cast<ServiceTransaction>(message);
		
		// check if transaction is synchron
		if (serviceTransaction->sync()) {
			serviceTransaction->promise().set_value(true);
			return;
		}
		
		switch (serviceTransaction->nodeTypeResponse().nodeId<uint32_t>())
		{
			case OpcUaId_FindServersResponse_Encoding_DefaultBinary:
			{
				auto trx = boost::static_pointer_cast<ServiceTransactionFindServers>(serviceTransaction);
				auto handler = trx->resultHandler();
				if (handler) {
					handler(trx);
				}
				break;
			}

			case OpcUaId_GetEndpointsResponse_Encoding_DefaultBinary:
			{
				auto trx = boost::static_pointer_cast<ServiceTransactionGetEndpoints>(serviceTransaction);
				auto handler = trx->resultHandler();
				if (handler) {
					handler(trx);
				}
				break;
			}

			case OpcUaId_RegisterServerResponse_Encoding_DefaultBinary:
			{
				auto trx = boost::static_pointer_cast<ServiceTransactionRegisterServer>(serviceTransaction);
				auto handler = trx->resultHandler();
				if (handler) {
					handler(trx);
				}
				break;
			}

			default:
				Log(Error, "call service received unknown message type")
					.parameter("TypeId", serviceTransaction->nodeTypeRequest());
		}
	}

}
