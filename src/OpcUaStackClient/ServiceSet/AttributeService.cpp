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
	AttributeService::send(ServiceTransactionRead::SPtr serviceTransactionRead)
	{
		session_->send(serviceTransactionRead);
	}

}