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

#include "OpcUaStackCore/Base/Log.h"
#include "OpcUaStackClient/ServiceSet/ViewService.h"

using namespace OpcUaStackCore;

namespace OpcUaStackClient
{

	ViewService::ViewService(IOThread* ioThread)
	: componentSession_(nullptr)
	, viewServiceIf_(nullptr)
	{
		Component::ioThread(ioThread);
	}

	ViewService::~ViewService(void)
	{
	}

	void
	ViewService::setConfiguration(
		Component* componentSession,
		ViewServiceIf* viewServiceIf
	)
	{
		this->componentSession(componentSession);
		viewServiceIf_ = viewServiceIf;
	}

	void 
	ViewService::componentSession(Component* componentSession)
	{
		componentSession_ = componentSession;
	}

	void 
	ViewService::viewServiceIf(ViewServiceIf* viewServiceIf)
	{
		viewServiceIf_ = viewServiceIf;
	}

	void 
	ViewService::syncSend(ServiceTransactionBrowse::SPtr serviceTransactionBrowse)
	{
		serviceTransactionBrowse->sync(true);
		serviceTransactionBrowse->conditionBool().conditionInit();
		asyncSend(serviceTransactionBrowse);
		serviceTransactionBrowse->conditionBool().waitForCondition();
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
		serviceTransactionBrowseNext->conditionBool().conditionInit();
		asyncSend(serviceTransactionBrowseNext);
		serviceTransactionBrowseNext->conditionBool().waitForCondition();
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
		serviceTransactionTranslateBrowsePathsToNodeIds->conditionBool().conditionInit();
		asyncSend(serviceTransactionTranslateBrowsePathsToNodeIds);
		serviceTransactionTranslateBrowsePathsToNodeIds->conditionBool().waitForCondition();
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
			serviceTransaction->conditionBool().conditionTrue();
			return;
		}

		switch (serviceTransaction->nodeTypeResponse().nodeId<uint32_t>())
		{
			case OpcUaId_BrowseResponse_Encoding_DefaultBinary:
			{
				if (viewServiceIf_ != nullptr) {
					viewServiceIf_->viewServiceBrowseResponse(
						boost::static_pointer_cast<ServiceTransactionBrowse>(serviceTransaction)
					);
				}
				break;
			}
			case OpcUaId_BrowseNextResponse_Encoding_DefaultBinary:
			{
				if (viewServiceIf_ != nullptr) {
					viewServiceIf_->viewServiceBrowseNextResponse(
						boost::static_pointer_cast<ServiceTransactionBrowseNext>(serviceTransaction)
					);
				}
				break;
			}
			case OpcUaId_TranslateBrowsePathsToNodeIdsResponse_Encoding_DefaultBinary:
			{
				if (viewServiceIf_ != nullptr) {
					viewServiceIf_->viewServiceTranslateBrowsePathsToNodeIdsResponse(
						boost::static_pointer_cast<ServiceTransactionTranslateBrowsePathsToNodeIds>(serviceTransaction)
					);
				}
				break;
			}

			default:
				Log(Error, "view service received unknown message type")
					.parameter("TypeId", serviceTransaction->nodeTypeRequest());
		}
	}

}
