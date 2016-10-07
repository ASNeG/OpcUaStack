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
#include "OpcUaStackClient/ServiceSet/MethodService.h"

using namespace OpcUaStackCore;

namespace OpcUaStackClient
{

	MethodService::MethodService(IOThread* ioThread)
	: componentSession_(nullptr)
	, methodServiceIf_(nullptr)
	{
		Component::ioThread(ioThread);
	}

	MethodService::~MethodService(void)
	{
	}

	void
	MethodService::setConfiguration(
		Component* componentSession,
		MethodServiceIf* methodServiceIf
	)
	{
		this->componentSession(componentSession);
		methodServiceIf_ = methodServiceIf;
	}

	void 
	MethodService::componentSession(Component* componentSession)
	{
		componentSession_ = componentSession;
	}

	void 
	MethodService::methodServiceIf(MethodServiceIf* methodServiceIf)
	{
		methodServiceIf_ = methodServiceIf;
	}

	void 
	MethodService::syncSend(ServiceTransactionCall::SPtr serviceTransactionCall)
	{
		serviceTransactionCall->sync(true);
		serviceTransactionCall->conditionBool().conditionInit();
		asyncSend(serviceTransactionCall);
		serviceTransactionCall->conditionBool().waitForCondition();
	}

	void 
	MethodService::asyncSend(ServiceTransactionCall::SPtr serviceTransactionCall)
	{
		serviceTransactionCall->componentService(this);
		OpcUaNodeId nodeId;
		componentSession_->sendAsync(serviceTransactionCall);
	}


	void 
	MethodService::receive(Message::SPtr message)
	{
		ServiceTransaction::SPtr serviceTransaction = boost::static_pointer_cast<ServiceTransaction>(message);
		
		// check if transaction is synchron
		if (serviceTransaction->sync()) {
			serviceTransaction->conditionBool().conditionTrue();
			return;
		}
		
		switch (serviceTransaction->nodeTypeResponse().nodeId<uint32_t>())
		{
			case OpcUaId_CallResponse_Encoding_DefaultBinary:
			{
				if (methodServiceIf_ != nullptr) {
					methodServiceIf_->methodServiceCallResponse(
						boost::static_pointer_cast<ServiceTransactionCall>(serviceTransaction)
					);
				}
				break;
			}

			default:
				Log(Error, "call service received unknown message type")
					.parameter("TypeId", serviceTransaction->nodeTypeRequest());
		}
	}

}
