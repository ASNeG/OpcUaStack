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
#include "OpcUaStackClient/ServiceSet/QueryService.h"

using namespace OpcUaStackCore;

namespace OpcUaStackClient
{

	QueryService::QueryService(
		const std::string& serviceName,
		IOThread* ioThread,
		MessageBus::SPtr& messageBus
	)
	: ClientServiceBase()
    , componentSession_(nullptr)
	{
		// set parameter in client service base
		serviceName_ = serviceName;
		ClientServiceBase::ioThread_ = ioThread;
		strand_ = ioThread->createStrand();
		messageBus_ = messageBus;

		Component::ioThread(ioThread);
	}

	QueryService::~QueryService(void)
	{
	}

	void
	QueryService::setConfiguration(
		MessageBusMember::WPtr& sessionMember,
		Component* componentSession
	)
	{
		sessionMember_ = sessionMember;

		this->componentSession(componentSession);
	}

	void 
	QueryService::componentSession(Component* componentSession)
	{
		componentSession_ = componentSession;
	}

	void 
	QueryService::syncSend(ServiceTransactionQueryFirst::SPtr serviceTransactionQueryFirst)
	{
		serviceTransactionQueryFirst->sync(true);
		auto future = serviceTransactionQueryFirst->promise().get_future();
		asyncSend(serviceTransactionQueryFirst);
		future.wait();
	}

	void 
	QueryService::asyncSend(ServiceTransactionQueryFirst::SPtr serviceTransactionQueryFirst)
	{
		serviceTransactionQueryFirst->componentService(this);
		componentSession_->sendAsync(serviceTransactionQueryFirst);
	}

	void
	QueryService::syncSend(ServiceTransactionQueryNext::SPtr serviceTransactionQueryNext)
	{
		serviceTransactionQueryNext->sync(true);
		auto future = serviceTransactionQueryNext->promise().get_future();
		asyncSend(serviceTransactionQueryNext);
		future.wait();
	}

	void
	QueryService::asyncSend(ServiceTransactionQueryNext::SPtr serviceTransactionQueryNext)
	{
		serviceTransactionQueryNext->componentService(this);
		componentSession_->sendAsync(serviceTransactionQueryNext);
	}


	void 
	QueryService::receive(Message::SPtr message)
	{
		ServiceTransaction::SPtr serviceTransaction = boost::static_pointer_cast<ServiceTransaction>(message);
		
		// check if transaction is synchron
		if (serviceTransaction->sync()) {
			serviceTransaction->promise().set_value(true);
			return;
		}
		
		switch (serviceTransaction->nodeTypeResponse().nodeId<uint32_t>())
		{
			case OpcUaId_QueryFirstResponse_Encoding_DefaultBinary:
			{
				auto trx = boost::static_pointer_cast<ServiceTransactionQueryFirst>(serviceTransaction);
				auto handler = trx->resultHandler();
				if (handler) {
					handler(trx);
				}
				break;
			}

			case OpcUaId_QueryNextResponse_Encoding_DefaultBinary:
			{
				auto trx = boost::static_pointer_cast<ServiceTransactionQueryNext>(serviceTransaction);
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
