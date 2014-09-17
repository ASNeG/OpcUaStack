#include "OpcUaStackCore/ServiceSet/ServiceTransactionRead.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaIdentifier.h"
#include "OpcUaStackServer/ServiceSet/ViewServiceSet.h"

namespace OpcUaStackServer
{

	ViewServiceSet::ViewServiceSet(void)
	{
	}

	ViewServiceSet::~ViewServiceSet(void)
	{
	}

	void 
	ViewServiceSet::receive(OpcUaNodeId& typeId, ServiceTransaction::SPtr serviceTransaction)
	{
		std::cout << "not implemented" << std::endl;
	}

}