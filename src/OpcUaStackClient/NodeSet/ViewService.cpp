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
	ViewService::send(ServiceTransactionBrowse::SPtr serviceTransactionBrowse)
	{
		serviceTransactionBrowse->componentService(this); 
		OpcUaNodeId nodeId;
		componentSession_->send(nodeId, serviceTransactionBrowse);
	}

	void 
	ViewService::receive(OpcUaNodeId& typeId, Message::SPtr message)
	{
		ServiceTransaction::SPtr serviceTransaction = boost::static_pointer_cast<ServiceTransaction>(message);
		switch (typeId.nodeId<uint32_t>()) 
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
			default:
				Log(Error, "view service received unknown message type")
					.parameter("TypeId", serviceTransaction->nodeTypeRequest());
		}
	}

}
