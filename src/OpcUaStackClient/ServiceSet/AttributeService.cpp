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
	AttributeService::send(boost::shared_ptr<ServiceTransactionRead> serviceTransactionRead)
	{
		serviceTransactionRead->componentService(this); 
		componentSession_->send(OpcUaNodeId(), serviceTransactionRead);
	}

	void 
	AttributeService::receive(OpcUaNodeId& typeId, Message::SPtr message)
	{
		std::cout << "attribute services received response...." << std::endl;
	}

}