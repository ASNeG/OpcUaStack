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
		switch (serviceTransaction->nodeTypeRequest().nodeId<uint32_t>()) 
		{
			case OpcUaId_ReadRequest_Encoding_DefaultBinary:
				receiveReadRequest(typeId, serviceTransaction);
				break;
			case OpcUaId_WriteRequest_Encoding_DefaultBinary:
				receiveWriteRequest(typeId, serviceTransaction);
				break;
			case OpcUaId_HistoryReadRequest_Encoding_DefaultBinary:
				receiveHistoryReadRequest(typeId, serviceTransaction);
				break;
			case OpcUaId_HistoryUpdateRequest_Encoding_DefaultBinary:
				receiveHistoryUpdateRequest(typeId, serviceTransaction);
				break;
			default:
				serviceTransaction->statusCode(BadInternalError);
				serviceTransaction->serviceTransactionIfSession()->receive(typeId, serviceTransaction);
		}
	}

	void 
	AttributeService::receiveReadRequest(OpcUaNodeId& typeId, ServiceTransaction::SPtr serviceTransaction)
	{
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

	void 
	AttributeService::receiveWriteRequest(OpcUaNodeId& typeId, ServiceTransaction::SPtr serviceTransaction)
	{
		// FIXME:
		serviceTransaction->statusCode(BadInternalError);
		serviceTransaction->serviceTransactionIfSession()->receive(typeId, serviceTransaction);
	}

	void 
	AttributeService::receiveHistoryReadRequest(OpcUaNodeId& typeId, ServiceTransaction::SPtr serviceTransaction)
	{
		// FIXME:
		serviceTransaction->statusCode(BadInternalError);
		serviceTransaction->serviceTransactionIfSession()->receive(typeId, serviceTransaction);
	}

	void 
	AttributeService::receiveHistoryUpdateRequest(OpcUaNodeId& typeId, ServiceTransaction::SPtr serviceTransaction)
	{
		// FIXME:
		serviceTransaction->statusCode(BadInternalError);
		serviceTransaction->serviceTransactionIfSession()->receive(typeId, serviceTransaction);
	}

}