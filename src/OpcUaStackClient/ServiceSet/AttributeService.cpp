#include "OpcUaStackCore/Base/Log.h"
#include "OpcUaStackClient/ServiceSet/AttributeService.h"

using namespace OpcUaStackCore;

namespace OpcUaStackClient
{

	AttributeService::AttributeService(void)
	: componentSession_(nullptr)
	, attributeServiceIf_(nullptr)
	{
	}

	AttributeService::~AttributeService(void)
	{
	}

	void 
	AttributeService::componentSession(Component* componentSession)
	{
		componentSession_ = componentSession;
	}

	void 
	AttributeService::attributeServiceIf(AttributeServiceIf* attributeServiceIf)
	{
		attributeServiceIf_ = attributeServiceIf;
	}

	void 
	AttributeService::send(ServiceTransactionRead::SPtr serviceTransactionRead)
	{
		serviceTransactionRead->componentService(this); 
		OpcUaNodeId nodeId;
		componentSession_->send(nodeId, serviceTransactionRead);
	}

	void 
	AttributeService::send(ServiceTransactionWrite::SPtr serviceTransactionWrite)
	{
		serviceTransactionWrite->componentService(this); 
		OpcUaNodeId nodeId;
		componentSession_->send(nodeId, serviceTransactionWrite);
	}

	void 
	AttributeService::receive(OpcUaNodeId& typeId, Message::SPtr message)
	{
		ServiceTransaction::SPtr serviceTransaction = boost::static_pointer_cast<ServiceTransaction>(message);
		switch (typeId.nodeId<uint32_t>()) 
		{
			case OpcUaId_ReadResponse_Encoding_DefaultBinary:
			{
				if (attributeServiceIf_ != nullptr) {
					attributeServiceIf_->attributeServiceReadResponse(
						boost::static_pointer_cast<ServiceTransactionRead>(serviceTransaction)
					);
				}
				break;
			}
			case OpcUaId_WriteRequest_Encoding_DefaultBinary:
			{
				if (attributeServiceIf_ != nullptr) {
					attributeServiceIf_->attributeServiceWriteResponse(
						boost::static_pointer_cast<ServiceTransactionWrite>(serviceTransaction)
					);
				}
				break;
			}
			case OpcUaId_HistoryReadRequest_Encoding_DefaultBinary:
			case OpcUaId_HistoryUpdateRequest_Encoding_DefaultBinary:
			default:
				Log(Error, "attribute service received unknown message type")
					.parameter("TypeId", serviceTransaction->nodeTypeRequest());
		}
	}

}
