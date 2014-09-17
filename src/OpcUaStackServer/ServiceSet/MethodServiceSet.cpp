#include "OpcUaStackCore/ServiceSet/ServiceTransactionRead.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaIdentifier.h"
#include "OpcUaStackServer/ServiceSet/MethodServiceSet.h"

namespace OpcUaStackServer
{

	MethodServiceSet::MethodServiceSet(void)
	{
	}

	MethodServiceSet::~MethodServiceSet(void)
	{
	}

	void 
	MethodServiceSet::receive(OpcUaNodeId& typeId, ServiceTransaction::SPtr serviceTransaction)
	{
		std::cout << "not implemented" << std::endl;
	}

}