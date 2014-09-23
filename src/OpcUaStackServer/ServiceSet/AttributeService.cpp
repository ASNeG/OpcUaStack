#include "OpcUaStackCore/Base/Log.h"
#include "OpcUaStackCore/ServiceSet/AttributeServiceTransaction.h"
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
				Log(Error, "attribute service received unknown message type")
					.parameter("TypeId", serviceTransaction->nodeTypeRequest());

				serviceTransaction->statusCode(BadInternalError);
				serviceTransaction->serviceTransactionIfSession()->receive(typeId, serviceTransaction);
		}
	}

	void 
	AttributeService::receiveReadRequest(OpcUaNodeId& typeId, ServiceTransaction::SPtr serviceTransaction)
	{
		ServiceTransactionRead::SPtr trx = boost::static_pointer_cast<ServiceTransactionRead>(serviceTransaction);
		ReadRequest::SPtr readRequest = trx->request();
		ReadResponse::SPtr readResponse = trx->response();

		Log(Debug, "attribute service read request")
			.parameter("Trx", serviceTransaction->transactionId())
			.parameter("NumberNodes", readRequest->readValueIdArray()->size());

		// check attribute maxAge
		// FIXME: todo 

		// check attribute timestampToReturn
		// FIXME: todo

		// check node id array
		if (readRequest->readValueIdArray()->size() == 0) {
			trx->responseHeader()->serviceResult(BadNothingToDo);
			trx->serviceTransactionIfSession()->receive(typeId, serviceTransaction);
			return;
		}
		if (readRequest->readValueIdArray()->size() > 1000) { // FIXME: todo
			trx->responseHeader()->serviceResult(BadTooManyOperations);
			trx->serviceTransactionIfSession()->receive(typeId, serviceTransaction);
			return;
		}

		// read values
		readResponse->dataValueArray()->resize(readRequest->readValueIdArray()->size());
		for (uint32_t idx = 0; idx < readRequest->readValueIdArray()->size(); idx++) {
			OpcUaDataValue::SPtr dataValue = OpcUaDataValue::construct();
			readResponse->dataValueArray()->set(idx, dataValue);

			ReadValueId::SPtr readValueId;
			if (!readRequest->readValueIdArray()->get(idx, readValueId)) {
				dataValue->statusCode(BadNodeIdInvalid);
				continue;
			}

			BaseNodeClass::SPtr baseNodeClass = informationModel_->find(readValueId->nodeId());
			if (baseNodeClass.get() == nullptr) {
				dataValue->statusCode(BadNodeIdUnknown);
				continue;
			}

			OpcUaDateTime sourceTimestamp, serverTimestamp;
			sourceTimestamp.dateTime(boost::posix_time::microsec_clock::local_time());
			serverTimestamp.dateTime(boost::posix_time::microsec_clock::local_time());
			dataValue->variant()->variant((OpcUaFloat)321);
			dataValue->sourceTimestamp(sourceTimestamp);
			dataValue->serverTimestamp(serverTimestamp);
		}

#if 0
ReadValueId:
		OpcUaNodeId::SPtr nodeIdSPtr_;
		OpcUaInt32 attributeId_;
		OpcUaString indexRange_;
		OpcUaQualifiedName dataEncoding_;

		
		OpcUaVariant::SPtr opcUaVariantSPtr_;
		OpcUaStatusCode opcUaStatusCode_;
		OpcUaDateTime sourceTimestamp_;
		OpcUaInt16 sourcePicoseconds_;
		OpcUaDateTime serverTimestamp_;
		OpcUaInt16 serverPicoseconds_;

#endif

#if 0
		ReadResponse::SPtr readResponseSPtr = trx->response();
		OpcUaDateTime sourceTimestamp, serverTimestamp;
		sourceTimestamp.dateTime(boost::posix_time::microsec_clock::local_time());
		serverTimestamp.dateTime(boost::posix_time::microsec_clock::local_time());

		OpcUaDataValue::SPtr dataValueSPtr = OpcUaDataValue::construct();
		dataValueSPtr->variant()->variant((OpcUaFloat)321);
		dataValueSPtr->sourceTimestamp(sourceTimestamp);
		dataValueSPtr->serverTimestamp(serverTimestamp);
		readResponseSPtr->dataValueArray()->set(dataValueSPtr);
#endif

		trx->responseHeader()->serviceResult(Success);
		trx->serviceTransactionIfSession()->receive(typeId, serviceTransaction);

#if 0
		void maxAge(const OpcUaDouble& maxAge);
		OpcUaDouble maxAge(void) const;
		void timestampsToReturn(const OpcUaInt32& timestampsToReturn);
		OpcUaInt32 timestampsToReturn(void) const;
		void readValueIdArray(const ReadValueIdArray::SPtr readValueIdArray);
		ReadValueIdArray::SPtr readValueIdArray(void) const;
#endif
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