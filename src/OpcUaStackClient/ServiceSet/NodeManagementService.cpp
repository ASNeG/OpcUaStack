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
#include "OpcUaStackClient/ServiceSet/NodeManagementService.h"

using namespace OpcUaStackCore;

namespace OpcUaStackClient
{

	NodeManagementService::NodeManagementService(
		const std::string& serviceName,
		IOThread* ioThread,
		MessageBus::SPtr& messageBus
	)
	: ClientServiceBase()
	, Component()
	, componentSession_(nullptr)
	{
		// set parameter in client service base
		serviceName_ = serviceName;
		ClientServiceBase::ioThread_ = ioThread;
		strand_ = ioThread->createStrand();
		messageBus_ = messageBus;


		Component::ioThread(ioThread);
	}

	NodeManagementService::~NodeManagementService(void)
	{
		// deactivate receiver
		deactivateReceiver();
	}

	void
	NodeManagementService::setConfiguration(
		MessageBusMember::WPtr& sessionMember,
		Component* componentSession
	)
	{
		sessionMember_ = sessionMember;
		this->componentSession(componentSession);

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
	NodeManagementService::componentSession(Component* componentSession)
	{
		componentSession_ = componentSession;
	}

	void 
	NodeManagementService::syncSend(ServiceTransactionAddNodes::SPtr serviceTransactionAddNodes)
	{
		serviceTransactionAddNodes->sync(true);
		auto future = serviceTransactionAddNodes->promise().get_future();
		asyncSend(serviceTransactionAddNodes);
		future.wait();
	}

	void 
	NodeManagementService::asyncSend(ServiceTransactionAddNodes::SPtr serviceTransactionAddNodes)
	{
		serviceTransactionAddNodes->memberService(messageBusMember_);
		messageBus_->messageSend(
			messageBusMember_,
			sessionMember_,
			serviceTransactionAddNodes
		);
	}

	void 
	NodeManagementService::syncSend(ServiceTransactionAddReferences::SPtr serviceTransactionAddReferences)
	{
		serviceTransactionAddReferences->sync(true);
		auto future = serviceTransactionAddReferences->promise().get_future();
		asyncSend(serviceTransactionAddReferences);
		future.wait();
	}

	void 
	NodeManagementService::asyncSend(ServiceTransactionAddReferences::SPtr serviceTransactionAddReferences)
	{
		serviceTransactionAddReferences->memberService(messageBusMember_);
		messageBus_->messageSend(
			messageBusMember_,
			sessionMember_,
			serviceTransactionAddReferences
		);
	}

	void 
	NodeManagementService::syncSend(ServiceTransactionDeleteNodes::SPtr serviceTransactionDeleteNodes)
	{
		serviceTransactionDeleteNodes->sync(true);
		auto future = serviceTransactionDeleteNodes->promise().get_future();
		asyncSend(serviceTransactionDeleteNodes);
		future.wait();
	}

	void 
	NodeManagementService::asyncSend(ServiceTransactionDeleteNodes::SPtr serviceTransactionDeleteNodes)
	{
		serviceTransactionDeleteNodes->memberService(messageBusMember_);
		messageBus_->messageSend(
			messageBusMember_,
			sessionMember_,
			serviceTransactionDeleteNodes
		);
	}

	void 
	NodeManagementService::syncSend(ServiceTransactionDeleteReferences::SPtr serviceTransactionDeleteReferences)
	{
		serviceTransactionDeleteReferences->sync(true);
		auto future = serviceTransactionDeleteReferences->promise().get_future();
		asyncSend(serviceTransactionDeleteReferences);
		future.wait();
	}

	void 
	NodeManagementService::asyncSend(ServiceTransactionDeleteReferences::SPtr serviceTransactionDeleteReferences)
	{
		serviceTransactionDeleteReferences->memberService(messageBusMember_);
		messageBus_->messageSend(
			messageBusMember_,
			sessionMember_,
			serviceTransactionDeleteReferences
		);
	}

	void 
	NodeManagementService::receive(Message::SPtr message)
	{
		ServiceTransaction::SPtr serviceTransaction = boost::static_pointer_cast<ServiceTransaction>(message);
		
		// check if transaction is synchron
		if (serviceTransaction->sync()) {
			serviceTransaction->promise().set_value(true);
			return;
		}
		
		switch (serviceTransaction->nodeTypeResponse().nodeId<uint32_t>())
		{
			case OpcUaId_AddNodesResponse_Encoding_DefaultBinary:
			{
				auto trx = boost::static_pointer_cast<ServiceTransactionAddNodes>(serviceTransaction);
				auto handler = trx->resultHandler();
				if (handler) {
					handler(trx);
				}
				break;
			}
			case OpcUaId_AddReferencesResponse_Encoding_DefaultBinary:
			{
				auto trx = boost::static_pointer_cast<ServiceTransactionAddReferences>(serviceTransaction);
				auto handler = trx->resultHandler();
				if (handler) {
					handler(trx);
				}
				break;
			}
			case OpcUaId_DeleteNodesResponse_Encoding_DefaultBinary:
			{
				auto trx = boost::static_pointer_cast<ServiceTransactionDeleteNodes>(serviceTransaction);
				auto handler = trx->resultHandler();
				if (handler) {
					handler(trx);
				}
				break;
			}
			case OpcUaId_DeleteReferencesResponse_Encoding_DefaultBinary:
			{
				auto trx = boost::static_pointer_cast<ServiceTransactionDeleteReferences>(serviceTransaction);
				auto handler = trx->resultHandler();
				if (handler) {
					handler(trx);
				}
				break;
			}
			default:
				Log(Error, "nodeManagement service received unknown message type")
					.parameter("TypeId", serviceTransaction->nodeTypeRequest());
		}
	}

}
