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
#include "OpcUaStackClient/ServiceSet/ViewService.h"

using namespace OpcUaStackCore;

namespace OpcUaStackClient
{

	ViewService::ViewService(IOThread* ioThread)
	: componentSession_(nullptr)
	{
		Component::ioThread(ioThread);
	}

	ViewService::~ViewService(void)
	{
	}

	void
	ViewService::setConfiguration(
		Component* componentSession
	)
	{
		this->componentSession(componentSession);
	}

	void 
	ViewService::componentSession(Component* componentSession)
	{
		componentSession_ = componentSession;
	}

	void 
	ViewService::syncSend(ServiceTransactionBrowse::SPtr serviceTransactionBrowse)
	{
		serviceTransactionBrowse->sync(true);
		auto future = serviceTransactionBrowse->promise().get_future();
		asyncSend(serviceTransactionBrowse);
		future.wait();
	}

	void 
	ViewService::asyncSend(ServiceTransactionBrowse::SPtr serviceTransactionBrowse)
	{
		serviceTransactionBrowse->componentService(this); 
		OpcUaNodeId nodeId;
		componentSession_->send(serviceTransactionBrowse);
	}

	void
	ViewService::syncSend(ServiceTransactionBrowseNext::SPtr serviceTransactionBrowseNext)
	{
		serviceTransactionBrowseNext->sync(true);
		auto future = serviceTransactionBrowseNext->promise().get_future();
		asyncSend(serviceTransactionBrowseNext);
		future.wait();
	}

	void
	ViewService::asyncSend(ServiceTransactionBrowseNext::SPtr serviceTransactionBrowseNext)
	{
		serviceTransactionBrowseNext->componentService(this);
		componentSession_->send(serviceTransactionBrowseNext);
	}

	void
	ViewService::syncSend(ServiceTransactionTranslateBrowsePathsToNodeIds::SPtr serviceTransactionTranslateBrowsePathsToNodeIds)
	{
		serviceTransactionTranslateBrowsePathsToNodeIds->sync(true);
		auto future = serviceTransactionTranslateBrowsePathsToNodeIds->promise().get_future();
		asyncSend(serviceTransactionTranslateBrowsePathsToNodeIds);
		future.wait();
	}

	void
	ViewService::asyncSend(ServiceTransactionTranslateBrowsePathsToNodeIds::SPtr serviceTransactionTranslateBrowsePathsToNodeIds)
	{
		serviceTransactionTranslateBrowsePathsToNodeIds->componentService(this);
		componentSession_->send(serviceTransactionTranslateBrowsePathsToNodeIds);
	}

	void 
	ViewService::receive(Message::SPtr message)
	{
		ServiceTransaction::SPtr serviceTransaction = boost::static_pointer_cast<ServiceTransaction>(message);

		// check if transaction is synchron
		if (serviceTransaction->sync()) {
			serviceTransaction->promise().set_value(true);
			return;
		}

		switch (serviceTransaction->nodeTypeResponse().nodeId<uint32_t>())
		{
			case OpcUaId_BrowseResponse_Encoding_DefaultBinary:
			{
				auto trx = boost::static_pointer_cast<ServiceTransactionBrowse>(serviceTransaction);
				auto handler = trx->resultHandler();
				if (handler) {
					handler(trx);
				}
				break;
			}
			case OpcUaId_BrowseNextResponse_Encoding_DefaultBinary:
			{
				auto trx = boost::static_pointer_cast<ServiceTransactionBrowseNext>(serviceTransaction);
				auto handler = trx->resultHandler();
				if (handler) {
					handler(trx);
				}
				break;
			}
			case OpcUaId_TranslateBrowsePathsToNodeIdsResponse_Encoding_DefaultBinary:
			{
				auto trx = boost::static_pointer_cast<ServiceTransactionTranslateBrowsePathsToNodeIds>(serviceTransaction);
				auto handler = trx->resultHandler();
				if (handler) {
					handler(trx);
				}
				break;
			}

			default:
				Log(Error, "view service received unknown message type")
					.parameter("TypeId", serviceTransaction->nodeTypeRequest());
		}
	}

}
