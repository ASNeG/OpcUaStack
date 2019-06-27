/*
   Copyright 2015-2019 Kai Huebl (kai@huebl-sgh.de)

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
#include "OpcUaStackClient/ServiceSet/AttributeService.h"

using namespace OpcUaStackCore;

namespace OpcUaStackClient
{

	AttributeService::AttributeService(IOThread* ioThread)
	: Component()
	, componentSession_(nullptr)
	{
		Component::ioThread(ioThread);
	}

	AttributeService::~AttributeService(void)
	{
	}

	void
	AttributeService::setConfiguration(
		Component* componentSession
	)
	{
		this->componentSession(componentSession);
	}

	void 
	AttributeService::componentSession(Component* componentSession)
	{
		componentSession_ = componentSession;
	}

	void 
	AttributeService::syncSend(ServiceTransactionRead::SPtr serviceTransactionRead)
	{
		serviceTransactionRead->sync(true);
		auto future = serviceTransactionRead->promise().get_future();
		asyncSend(serviceTransactionRead);
		future.wait();
	}

	void 
	AttributeService::asyncSend(ServiceTransactionRead::SPtr serviceTransactionRead)
	{
		serviceTransactionRead->componentService(this); 
		componentSession_->sendAsync(serviceTransactionRead);
	}

	void 
	AttributeService::syncSend(ServiceTransactionWrite::SPtr serviceTransactionWrite)
	{
		serviceTransactionWrite->sync(true);
		auto future = serviceTransactionWrite->promise().get_future();
		asyncSend(serviceTransactionWrite);
		future.wait();
	}

	void 
	AttributeService::asyncSend(ServiceTransactionWrite::SPtr serviceTransactionWrite)
	{
		serviceTransactionWrite->componentService(this); 
		componentSession_->sendAsync(serviceTransactionWrite);
	}

	void 
	AttributeService::syncSend(ServiceTransactionHistoryRead::SPtr serviceTransactionHistoryRead)
	{
		serviceTransactionHistoryRead->sync(true);
		auto future = serviceTransactionHistoryRead->promise().get_future();
		asyncSend(serviceTransactionHistoryRead);
		future.wait();
	}

	void 
	AttributeService::asyncSend(ServiceTransactionHistoryRead::SPtr serviceTransactionHistoryRead)
	{
		serviceTransactionHistoryRead->componentService(this); 
		componentSession_->sendAsync(serviceTransactionHistoryRead);
	}

	void 
	AttributeService::syncSend(ServiceTransactionHistoryUpdate::SPtr serviceTransactionHistoryUpdate)
	{
		serviceTransactionHistoryUpdate->sync(true);
		auto future = serviceTransactionHistoryUpdate->promise().get_future();
		asyncSend(serviceTransactionHistoryUpdate);
		future.wait();
	}

	void 
	AttributeService::asyncSend(ServiceTransactionHistoryUpdate::SPtr serviceTransactionHistoryUpdate)
	{
		serviceTransactionHistoryUpdate->componentService(this); 
		componentSession_->sendAsync(serviceTransactionHistoryUpdate);
	}

	void 
	AttributeService::receive(Message::SPtr message)
	{
		ServiceTransaction::SPtr serviceTransaction = boost::static_pointer_cast<ServiceTransaction>(message);
		
		// check if transaction is synchron
		if (serviceTransaction->sync()) {
			serviceTransaction->promise().set_value(true);
			return;
		}
		
		switch (serviceTransaction->nodeTypeResponse().nodeId<uint32_t>())
		{
			case OpcUaId_ReadResponse_Encoding_DefaultBinary:
			{
				auto trx = boost::static_pointer_cast<ServiceTransactionRead>(serviceTransaction);
				auto handler = trx->resultHandler();
				if (handler) {
					handler(trx);
				}
				break;
			}
			case OpcUaId_WriteResponse_Encoding_DefaultBinary:
			{
				auto trx = boost::static_pointer_cast<ServiceTransactionWrite>(serviceTransaction);
				auto handler = trx->resultHandler();
				if (handler) {
					handler(trx);
				}
				break;
			}
			case OpcUaId_HistoryReadResponse_Encoding_DefaultBinary:
			{
				auto trx = boost::static_pointer_cast<ServiceTransactionHistoryRead>(serviceTransaction);
				auto handler = trx->resultHandler();
				if (handler) {
					handler(trx);
				}
				break;
			}
			case OpcUaId_HistoryUpdateResponse_Encoding_DefaultBinary:
			{
				auto trx = boost::static_pointer_cast<ServiceTransactionHistoryUpdate>(serviceTransaction);
				auto handler = trx->resultHandler();
				if (handler) {
					handler(trx);
				}
				break;
			}
			default:
				Log(Error, "attribute service received unknown message type")
					.parameter("TypeId", serviceTransaction->nodeTypeRequest());
		}
	}

}
