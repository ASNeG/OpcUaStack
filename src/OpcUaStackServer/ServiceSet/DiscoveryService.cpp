#include "OpcUaStackCore/BuildInTypes/OpcUaIdentifier.h"
#include "OpcUaStackServer/ServiceSet/DiscoveryService.h"

namespace OpcUaStackServer
{

	DiscoveryService::DiscoveryService(void)
	{
	}

	DiscoveryService::~DiscoveryService(void)
	{
	}

	void 
	DiscoveryService::receive(OpcUaNodeId& typeId, ServiceTransaction::SPtr serviceTransaction)
	{
		std::cout << "discovery services received request...." << std::endl;

#if 0
		if (serviceTransaction->nodeTypeRequest().nodeId<uint32_t>() == OpcUaId_ReadRequest_Encoding_DefaultBinary) {
			ServiceTransactionRead::SPtr trx = boost::static_pointer_cast<ServiceTransactionRead>(serviceTransaction);

			ReadResponse::SPtr readResponseSPtr = trx->response();
			OpcUaDateTime sourceTimestamp, serverTimestamp;
			sourceTimestamp.dateTime(boost::posix_time::microsec_clock::local_time());
			serverTimestamp.dateTime(boost::posix_time::microsec_clock::local_time());

			OpcUaDataValue::SPtr dataValueSPtr = OpcUaDataValue::construct();
			dataValueSPtr->variant()->variant((OpcUaFloat)321);
			dataValueSPtr->sourceTimestamp(sourceTimestamp);
			dataValueSPtr->serverTimestamp(serverTimestamp);
			readResponseSPtr->dataValueArray()->set(dataValueSPtr);

			trx->responseHeader()->serviceResult(Success);
			trx->serviceTransactionIfSession()->receive(typeId, serviceTransaction);
		}
#endif
	}

}