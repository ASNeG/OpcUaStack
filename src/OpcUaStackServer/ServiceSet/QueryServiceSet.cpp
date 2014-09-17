#include "OpcUaStackCore/ServiceSet/ServiceTransactionRead.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaIdentifier.h"
#include "OpcUaStackServer/ServiceSet/QueryServiceSet.h"

namespace OpcUaStackServer
{

	QueryServiceSet::QueryServiceSet(void)
	{
	}

	QueryServiceSet::~QueryServiceSet(void)
	{
	}

	void 
	QueryServiceSet::receive(OpcUaNodeId& typeId, ServiceTransaction::SPtr serviceTransaction)
	{
		std::cout << "not implemented" << std::endl;
	}

}