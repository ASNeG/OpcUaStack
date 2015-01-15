#include "OpcUaStackClient/ServiceSet/AttributeService.h"

namespace OpcUaStackClient
{

	AttributeService::AttributeService(void)
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
	AttributeService::send(ServiceTransactionRead::SPtr serviceTransactionRead)
	{
		serviceTransactionRead->componentService(this); 
		OpcUaNodeId nodeId;
		componentSession_->send(nodeId, serviceTransactionRead);
	}

	void 
	AttributeService::receive(OpcUaNodeId& typeId, Message::SPtr message)
	{
		std::cout << "attribute services received response...." << std::endl;
	}

}
