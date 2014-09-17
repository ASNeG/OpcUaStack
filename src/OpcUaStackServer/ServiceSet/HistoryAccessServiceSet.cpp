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
		switch (serviceTransaction->nodeTypeRequest().nodeId<uint32_t>()) 
		{
			case OpcUaId_ReadRequest_Encoding_DefaultBinary:
				//receiveReadRequest(typeId, serviceTransaction);
				break;
			default:
				serviceTransaction->statusCode(BadInternalError);
				serviceTransaction->serviceTransactionIfSession()->receive(typeId, serviceTransaction);
		}
	}

}