#include "OpcUaStackCore/Base/Log.h"
#include "OpcUaStackClient/ServiceSet/ViewService.h"

using namespace OpcUaStackCore;

namespace OpcUaStackClient
{

	ViewService::ViewService(void)
	: componentSession_(nullptr)
	, viewServiceIf_(nullptr)
	{
	}

	ViewService::~ViewService(void)
	{
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
	ViewService::sendSync(ServiceTransactionBrowse::SPtr serviceTransactionBrowse)
	{
		serviceTransactionBrowse->sync(true);
		serviceTransactionBrowse->conditionBool().conditionInit();
		send(serviceTransactionBrowse);
		serviceTransactionBrowse->conditionBool().waitForCondition();
	}

	void 
	ViewService::send(ServiceTransactionBrowse::SPtr serviceTransactionBrowse)
	{
		serviceTransactionBrowse->componentService(this); 
		OpcUaNodeId nodeId;
		componentSession_->send(serviceTransactionBrowse);
	}

	void
	ViewService::sendSync(ServiceTransactionBrowseNext::SPtr serviceTransactionBrowseNext)
	{
		serviceTransactionBrowseNext->sync(true);
		serviceTransactionBrowseNext->conditionBool().conditionInit();
		send(serviceTransactionBrowseNext);
		serviceTransactionBrowseNext->conditionBool().waitForCondition();
	}

	void
	ViewService::send(ServiceTransactionBrowseNext::SPtr serviceTransactionBrowseNext)
	{
		serviceTransactionBrowseNext->componentService(this);
		OpcUaNodeId nodeId;
		componentSession_->send(serviceTransactionBrowseNext);
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
			default:
				Log(Error, "view service received unknown message type")
					.parameter("TypeId", serviceTransaction->nodeTypeRequest());
		}
	}

}
