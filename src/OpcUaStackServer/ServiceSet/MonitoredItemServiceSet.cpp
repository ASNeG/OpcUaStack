#include "OpcUaStackCore/ServiceSet/ServiceTransactionRead.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaIdentifier.h"
#include "OpcUaStackServer/ServiceSet/MonitoredItemServiceSet.h"

namespace OpcUaStackServer
{

	MonitoredItemServiceSet::MonitoredItemServiceSet(void)
	{
	}

	MonitoredItemServiceSet::~MonitoredItemServiceSet(void)
	{
	}

	void 
	MonitoredItemServiceSet::receive(OpcUaNodeId& typeId, ServiceTransaction::SPtr serviceTransaction)
	{
		std::cout << "not implemented" << std::endl;
	}

}