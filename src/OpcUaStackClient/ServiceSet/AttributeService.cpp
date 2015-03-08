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
	AttributeService::sendSync(ServiceTransactionRead::SPtr serviceTransactionRead)
	{
		serviceTransactionRead->sync(true);
		serviceTransactionRead->conditionBool().conditionInit();
		send(serviceTransactionRead);
		serviceTransactionRead->conditionBool().waitForCondition();
	}

	void 
	AttributeService::send(ServiceTransactionRead::SPtr serviceTransactionRead)
	{
		serviceTransactionRead->componentService(this); 
		componentSession_->send(serviceTransactionRead);
	}

	void 
	AttributeService::sendSync(ServiceTransactionWrite::SPtr serviceTransactionWrite)
	{
		serviceTransactionWrite->sync(true);
		serviceTransactionWrite->conditionBool().conditionInit();
		send(serviceTransactionWrite);
		serviceTransactionWrite->conditionBool().waitForCondition();
	}

	void 
	AttributeService::send(ServiceTransactionWrite::SPtr serviceTransactionWrite)
	{
		serviceTransactionWrite->componentService(this); 
		componentSession_->send(serviceTransactionWrite);
	}

	void 
	AttributeService::sendSync(ServiceTransactionHistoryRead::SPtr serviceTransactionHistoryRead)
	{
		serviceTransactionHistoryRead->sync(true);
		serviceTransactionHistoryRead->conditionBool().conditionInit();
		send(serviceTransactionHistoryRead);
		serviceTransactionHistoryRead->conditionBool().waitForCondition();
	}

	void 
	AttributeService::send(ServiceTransactionHistoryRead::SPtr serviceTransactionHistoryRead)
	{
		serviceTransactionHistoryRead->componentService(this); 
		componentSession_->send(serviceTransactionHistoryRead);
	}

	void 
	AttributeService::sendSync(ServiceTransactionHistoryUpdate::SPtr serviceTransactionHistoryUpdate)
	{
		serviceTransactionHistoryUpdate->sync(true);
		serviceTransactionHistoryUpdate->conditionBool().conditionInit();
		send(serviceTransactionHistoryUpdate);
		serviceTransactionHistoryUpdate->conditionBool().waitForCondition();
	}

	void 
	AttributeService::send(ServiceTransactionHistoryUpdate::SPtr serviceTransactionHistoryUpdate)
	{
		serviceTransactionHistoryUpdate->componentService(this); 
		componentSession_->send(serviceTransactionHistoryUpdate);
	}

	void 
	AttributeService::receive(Message::SPtr message)
	{
		ServiceTransaction::SPtr serviceTransaction = boost::static_pointer_cast<ServiceTransaction>(message);
		
		// check if transaction is synchron
		if (serviceTransaction->sync()) {
			serviceTransaction->conditionBool().conditionTrue();
			return;
		}
		
		switch (serviceTransaction->nodeTypeResponse().nodeId<uint32_t>())
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
			case OpcUaId_WriteResponse_Encoding_DefaultBinary:
			{
				if (attributeServiceIf_ != nullptr) {
					attributeServiceIf_->attributeServiceWriteResponse(
						boost::static_pointer_cast<ServiceTransactionWrite>(serviceTransaction)
					);
				}
				break;
			}
			case OpcUaId_HistoryReadResponse_Encoding_DefaultBinary:
			{
				if (attributeServiceIf_ != nullptr) {
					attributeServiceIf_->attributeServiceHistoryReadResponse(
						boost::static_pointer_cast<ServiceTransactionHistoryRead>(serviceTransaction)
					);
				}
				break;
			}
			case OpcUaId_HistoryUpdateResponse_Encoding_DefaultBinary:
				{
				if (attributeServiceIf_ != nullptr) {
					attributeServiceIf_->attributeServiceHistoryUpdateResponse(
						boost::static_pointer_cast<ServiceTransactionHistoryUpdate>(serviceTransaction)
					);
				}
				break;
			}
			default:
				Log(Error, "attribute service received unknown message type")
					.parameter("TypeId", serviceTransaction->nodeTypeRequest());
		}
	}

}
