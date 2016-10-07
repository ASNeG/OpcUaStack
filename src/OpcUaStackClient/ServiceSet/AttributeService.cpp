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
#include "OpcUaStackClient/ServiceSet/AttributeService.h"

using namespace OpcUaStackCore;

namespace OpcUaStackClient
{

	AttributeService::AttributeService(IOThread* ioThread)
	: Component()
	, componentSession_(nullptr)
	, attributeServiceIf_(nullptr)
	{
		Component::ioThread(ioThread);
	}

	AttributeService::~AttributeService(void)
	{
	}

	void
	AttributeService::setConfiguration(
		Component* componentSession,
		AttributeServiceIf* attributeServiceIf
	)
	{
		this->componentSession(componentSession);
		attributeServiceIf_ = attributeServiceIf;
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
	AttributeService::syncSend(ServiceTransactionRead::SPtr serviceTransactionRead)
	{
		serviceTransactionRead->sync(true);
		serviceTransactionRead->conditionBool().conditionInit();
		asyncSend(serviceTransactionRead);
		serviceTransactionRead->conditionBool().waitForCondition();
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
		serviceTransactionWrite->conditionBool().conditionInit();
		asyncSend(serviceTransactionWrite);
		serviceTransactionWrite->conditionBool().waitForCondition();
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
		serviceTransactionHistoryRead->conditionBool().conditionInit();
		asyncSend(serviceTransactionHistoryRead);
		serviceTransactionHistoryRead->conditionBool().waitForCondition();
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
		serviceTransactionHistoryUpdate->conditionBool().conditionInit();
		asyncSend(serviceTransactionHistoryUpdate);
		serviceTransactionHistoryUpdate->conditionBool().waitForCondition();
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
