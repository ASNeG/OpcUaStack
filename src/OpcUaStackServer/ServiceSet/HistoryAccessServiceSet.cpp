#include "OpcUaStackCore/ServiceSet/ServiceTransactionRead.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaIdentifier.h"
#include "OpcUaStackServer/ServiceSet/HistoryAccessServiceSet.h"

namespace OpcUaStackServer
{

	HistoryAccessServiceSet::HistoryAccessServiceSet(void)
	{
	}

	HistoryAccessServiceSet::~HistoryAccessServiceSet(void)
	{
	}

	void 
	HistoryAccessServiceSet::receive(OpcUaNodeId& typeId, ServiceTransaction::SPtr serviceTransaction)
	{
		std::cout << "not implemented" << std::endl;
	}

}