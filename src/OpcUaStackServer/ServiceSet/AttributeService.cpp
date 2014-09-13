#include "OpcUaStackCore/ServiceSet/ServiceTransactionRead.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaIdentifier.h"
#include "OpcUaStackServer/ServiceSet/AttributeService.h"

namespace OpcUaStackServer
{

	AttributeService::AttributeService(void)
	{
	}

	AttributeService::~AttributeService(void)
	{
	}

	void 
	AttributeService::receive(OpcUaNodeId& typeId, ServiceTransaction::SPtr serviceTransaction)
	{
		std::cout << "attribute services received request...." << std::endl;

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
	}

}