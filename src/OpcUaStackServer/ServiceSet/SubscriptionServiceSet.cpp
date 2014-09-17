#include "OpcUaStackCore/ServiceSet/ServiceTransactionRead.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaIdentifier.h"
#include "OpcUaStackServer/ServiceSet/SubscriptionServiceSet.h"

namespace OpcUaStackServer
{

	SubscriptionServiceSet::SubscriptionServiceSet(void)
	{
	}

	SubscriptionServiceSet::~SubscriptionServiceSet(void)
	{
	}

	void 
	SubscriptionServiceSet::receive(OpcUaNodeId& typeId, ServiceTransaction::SPtr serviceTransaction)
	{
		std::cout << "not implemented" << std::endl;
	}

}