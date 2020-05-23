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
	{
		// set parameter in client service base
		serviceName_ = serviceName;
		ClientServiceBase::ioThread_ = ioThread;
		strand_ = ioThread->createStrand();
		messageBus_ = messageBus;
	}

	NodeManagementService::~NodeManagementService(void)
	{
		// deactivate receiver
		deactivateReceiver();
	}

	void
	NodeManagementService::setConfiguration(
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
	NodeManagementService::syncSend(const ServiceTransactionAddNodes::SPtr& serviceTransactionAddNodes)
	{
		ClientServiceBase::syncSend(sessionMember_, serviceTransactionAddNodes);
	}

	void 
	NodeManagementService::asyncSend(const ServiceTransactionAddNodes::SPtr& serviceTransactionAddNodes)
	{
		ClientServiceBase::asyncSend(sessionMember_, serviceTransactionAddNodes);
	}

	void 
	NodeManagementService::syncSend(const ServiceTransactionAddReferences::SPtr& serviceTransactionAddReferences)
	{
		ClientServiceBase::syncSend(sessionMember_, serviceTransactionAddReferences);
	}

	void 
	NodeManagementService::asyncSend(const ServiceTransactionAddReferences::SPtr& serviceTransactionAddReferences)
	{
		ClientServiceBase::asyncSend(sessionMember_, serviceTransactionAddReferences);
	}

	void 
	NodeManagementService::syncSend(const ServiceTransactionDeleteNodes::SPtr& serviceTransactionDeleteNodes)
	{
		ClientServiceBase::syncSend(sessionMember_, serviceTransactionDeleteNodes);
	}

	void 
	NodeManagementService::asyncSend(const ServiceTransactionDeleteNodes::SPtr& serviceTransactionDeleteNodes)
	{
		ClientServiceBase::asyncSend(sessionMember_, serviceTransactionDeleteNodes);
	}

	void
	NodeManagementService::syncSend(const ServiceTransactionDeleteReferences::SPtr& serviceTransactionDeleteReferences)
	{
		ClientServiceBase::syncSend(sessionMember_, serviceTransactionDeleteReferences);
	}

	void 
	NodeManagementService::asyncSend(const ServiceTransactionDeleteReferences::SPtr& serviceTransactionDeleteReferences)
	{
		ClientServiceBase::asyncSend(sessionMember_, serviceTransactionDeleteReferences);
	}

	void 
	NodeManagementService::receive(
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
			case OpcUaId_AddNodesResponse_Encoding_DefaultBinary:
			{
				auto trx = boost::static_pointer_cast<ServiceTransactionAddNodes>(serviceTransaction);
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
			case OpcUaId_AddReferencesResponse_Encoding_DefaultBinary:
			{
				auto trx = boost::static_pointer_cast<ServiceTransactionAddReferences>(serviceTransaction);
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
			case OpcUaId_DeleteNodesResponse_Encoding_DefaultBinary:
			{
				auto trx = boost::static_pointer_cast<ServiceTransactionDeleteNodes>(serviceTransaction);
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
			case OpcUaId_DeleteReferencesResponse_Encoding_DefaultBinary:
			{
				auto trx = boost::static_pointer_cast<ServiceTransactionDeleteReferences>(serviceTransaction);
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
				Log(Error, "nodeManagement service received unknown message type")
					.parameter("TypeId", serviceTransaction->nodeTypeRequest());
		}
	}

}
