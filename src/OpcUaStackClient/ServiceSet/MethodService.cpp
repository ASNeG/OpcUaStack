#include "OpcUaStackCore/Base/Log.h"
#include "OpcUaStackClient/ServiceSet/MethodService.h"

using namespace OpcUaStackCore;

namespace OpcUaStackClient
{

	MethodService::MethodService(void)
	: componentSession_(nullptr)
	, methodServiceIf_(nullptr)
	{
	}

	MethodService::~MethodService(void)
	{
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
	MethodService::sendSync(ServiceTransactionCall::SPtr serviceTransactionCall)
	{
		serviceTransactionCall->sync(true);
		serviceTransactionCall->conditionBool().conditionInit();
		send(serviceTransactionCall);
		serviceTransactionCall->conditionBool().waitForCondition();
	}

	void 
	MethodService::send(ServiceTransactionCall::SPtr serviceTransactionCall)
	{
		serviceTransactionCall->componentService(this);
		OpcUaNodeId nodeId;
		componentSession_->send(nodeId, serviceTransactionCall);
	}


	void 
	MethodService::receive(OpcUaNodeId& typeId, Message::SPtr message)
	{
		ServiceTransaction::SPtr serviceTransaction = boost::static_pointer_cast<ServiceTransaction>(message);
		
		// check if transaction is synchron
		if (serviceTransaction->sync()) {
			serviceTransaction->conditionBool().conditionTrue();
			return;
		}
		
		switch (typeId.nodeId<uint32_t>()) 
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
