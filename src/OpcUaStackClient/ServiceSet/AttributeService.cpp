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
	AttributeService::session(Session::SPtr session)
	{
		session_ = session;
	}

	void 
	AttributeService::send(boost::shared_ptr<ServiceTransactionRead> serviceTransactionRead)
	{
		serviceTransactionRead->serviceTransactionIfService(this); 
		session_->send(serviceTransactionRead);
	}

	void 
	AttributeService::receive(OpcUaNodeId& typeId, ServiceTransaction::SPtr serviceTransaction)
	{
		std::cout << "attribute services received response...." << std::endl;
	}

}