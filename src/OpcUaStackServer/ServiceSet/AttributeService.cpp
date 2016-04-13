/*
   Copyright 2015 Kai Huebl (kai@huebl-sgh.de)

   Lizenziert gemäß Apache Licence Version 2.0 (die „Lizenz“); Nutzung dieser
   Datei nur in Übereinstimmung mit der Lizenz erlaubt.
   Eine Kopie der Lizenz erhalten Sie auf http://www.apache.org/licenses/LICENSE-2.0.

   Sofern nicht gemäß geltendem Recht vorgeschrieben oder schriftlich vereinbart,
   erfolgt die Bereitstellung der im Rahmen der Lizenz verbreiteten Software OHNE
   GEWÄHR ODER VORBEHALTE – ganz gleich, ob ausdrücklich oder stillschweigend.

   Informationen über die jeweiligen Bedingungen für Genehmigungen und Einschränkungen
   im Rahmen der Lizenz finden Sie in der Lizenz.

   Autor: Kai Huebl (kai@huebl-sgh.de)
 */

#include "OpcUaStackCore/Base/Log.h"
#include "OpcUaStackCore/ServiceSet/AttributeServiceTransaction.h"
#include "OpcUaStackCore/Application/ApplicationReadContext.h"
#include "OpcUaStackCore/Application/ApplicationHReadContext.h"
#include "OpcUaStackCore/Application/ApplicationWriteContext.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaIdentifier.h"
#include "OpcUaStackCore/ServiceSet/ReadRawModifiedDetails.h"
#include "OpcUaStackCore/ServiceSet/HistoryData.h"
#include "OpcUaStackServer/ServiceSet/AttributeService.h"
#include "OpcUaStackServer/AddressSpaceModel/AttributeAccess.h"

namespace OpcUaStackServer
{

	AttributeService::AttributeService(void)
	{
	}

	AttributeService::~AttributeService(void)
	{
	}

	void 
	AttributeService::receive(Message::SPtr message)
	{
		ServiceTransaction::SPtr serviceTransaction = boost::static_pointer_cast<ServiceTransaction>(message);
		switch (serviceTransaction->nodeTypeRequest().nodeId<uint32_t>()) 
		{
			case OpcUaId_ReadRequest_Encoding_DefaultBinary:
				receiveReadRequest(serviceTransaction);
				break;
			case OpcUaId_WriteRequest_Encoding_DefaultBinary:
				receiveWriteRequest(serviceTransaction);
				break;
			case OpcUaId_HistoryReadRequest_Encoding_DefaultBinary:
				receiveHistoryReadRequest( serviceTransaction);
				break;
			case OpcUaId_HistoryUpdateRequest_Encoding_DefaultBinary:
				receiveHistoryUpdateRequest(serviceTransaction);
				break;
			default:
				Log(Error, "attribute service received unknown message type")
					.parameter("TypeId", serviceTransaction->nodeTypeRequest());

				serviceTransaction->statusCode(BadInternalError);
				serviceTransaction->componentSession()->send(serviceTransaction);
		}
	}

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// read service
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	void 
	AttributeService::receiveReadRequest(ServiceTransaction::SPtr serviceTransaction)
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
			trx->statusCode(BadNothingToDo);
			trx->componentSession()->send(serviceTransaction);
			return;
		}
		if (readRequest->readValueIdArray()->size() > 1000) { // FIXME: todo
			trx->statusCode(BadTooManyOperations);
			trx->componentSession()->send(serviceTransaction);
			return;
		}

		// read values
		readResponse->dataValueArray()->resize(readRequest->readValueIdArray()->size());
		for (uint32_t idx = 0; idx < readRequest->readValueIdArray()->size(); idx++) {
			OpcUaDataValue::SPtr dataValue = constructSPtr<OpcUaDataValue>();
			readResponse->dataValueArray()->set(idx, dataValue);

			// determine node information
			ReadValueId::SPtr readValueId;
			if (!readRequest->readValueIdArray()->get(idx, readValueId)) {
				dataValue->statusCode(BadNodeIdInvalid);
				Log(Debug, "read value error, because node request parameter invalid")
					.parameter("Trx", serviceTransaction->transactionId())
					.parameter("Idx", idx);
				continue;
			}

			// find node class instance for the node
			BaseNodeClass::SPtr baseNodeClass = informationModel_->find(readValueId->nodeId());
			if (baseNodeClass.get() == nullptr) {
				dataValue->statusCode(BadNodeIdUnknown);
				Log(Debug, "read value error, because node not exist in information model")
					.parameter("Trx", serviceTransaction->transactionId())
					.parameter("Idx", idx)
					.parameter("Node", *readValueId->nodeId())
					.parameter("Attr", readValueId->attributeId());
				continue;
			}

			// forward read request
			forwardRead(baseNodeClass, readRequest, readValueId);

			// determine the attribute to be read
			Attribute* attribute = baseNodeClass->attribute((AttributeId)readValueId->attributeId());
			if (attribute == nullptr) {
				dataValue->statusCode(BadAttributeIdInvalid);
				Log(Debug, "read value error, because node attribute not exist in node")
					.parameter("Trx", serviceTransaction->transactionId())
					.parameter("Idx", idx)
					.parameter("Node", *readValueId->nodeId())
					.parameter("Attr", readValueId->attributeId())
					.parameter("Class", baseNodeClass->nodeClass().data());
				continue;
			}

			if (attribute->exist() == false) {
				Log(Debug, "read value error, because node attribute is empty")
					.parameter("Trx", serviceTransaction->transactionId())
					.parameter("Idx", idx)
					.parameter("Node", *readValueId->nodeId())
					.parameter("Attr", readValueId->attributeId())
					.parameter("Class", baseNodeClass->nodeClass().data());
				dataValue->statusCode(BadNotReadable);
				continue;
			}

			if (!AttributeAccess::copy(*attribute, *dataValue)) {
				Log(Debug, "read value error, because value error")
					.parameter("Trx", serviceTransaction->transactionId())
					.parameter("Idx", idx)
					.parameter("Node", *readValueId->nodeId())
					.parameter("Attr", readValueId->attributeId())
					.parameter("Class", baseNodeClass->nodeClass().data());
				dataValue->reset();
				dataValue->statusCode(BadAttributeIdInvalid);
				continue;
			}

			Log(Debug, "read value")
				.parameter("Trx", serviceTransaction->transactionId())
				.parameter("Idx", idx)
				.parameter("Node", *readValueId->nodeId())
				.parameter("Attr", readValueId->attributeId())
				.parameter("Class", baseNodeClass->nodeClass().data())
				.parameter("Data", *dataValue)
				.parameter("Type", attribute->type());
		}

		trx->statusCode(Success);
		trx->componentSession()->send(serviceTransaction);
	}

	void
	AttributeService::forwardRead(BaseNodeClass::SPtr baseNodeClass, ReadRequest::SPtr readRequest, ReadValueId::SPtr readValueId)
	{
		if ((AttributeId)readValueId->attributeId() != AttributeId_Value) return;

		ForwardInfoSync::SPtr forwardInfoSync = baseNodeClass->forwardInfoSync();
		if (forwardInfoSync.get() == nullptr) return;
		if (!forwardInfoSync->isReadCallback()) return;

		ApplicationReadContext applicationReadContext;
		applicationReadContext.nodeId_ = *readValueId->nodeId();
		applicationReadContext.attributeId_ = readValueId->attributeId();
		applicationReadContext.statusCode_ = Success;
		applicationReadContext.applicationContext_ = forwardInfoSync->applicationContext();

		forwardInfoSync->readCallback()(&applicationReadContext);

		if (applicationReadContext.statusCode_ != Success) return;
		baseNodeClass->setValue(applicationReadContext.dataValue_);
	}

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// write service
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	void 
	AttributeService::receiveWriteRequest(ServiceTransaction::SPtr serviceTransaction)
	{
		ServiceTransactionWrite::SPtr trx = boost::static_pointer_cast<ServiceTransactionWrite>(serviceTransaction);
		WriteRequest::SPtr writeRequest = trx->request();
		WriteResponse::SPtr writeResponse = trx->response();

		Log(Debug, "attribute service write request")
			.parameter("Trx", serviceTransaction->transactionId())
			.parameter("NumberNodes", writeRequest->writeValueArray()->size());


		// check node id array
		if (writeRequest->writeValueArray()->size() == 0) {
			trx->statusCode(BadNothingToDo);
			trx->componentSession()->send(serviceTransaction);
			return;
		}
		if (writeRequest->writeValueArray()->size() > 1000) { // FIXME: todo
			trx->statusCode(BadTooManyOperations);
			trx->componentSession()->receive(serviceTransaction);
			return;
		}

		// read values
		writeResponse->results()->resize(writeRequest->writeValueArray()->size());
		for (uint32_t idx=0; idx<writeRequest->writeValueArray()->size(); idx++) {

			WriteValue::SPtr writeValue;
			if (!writeRequest->writeValueArray()->get(idx, writeValue)) {
				writeResponse->results()->set(idx, BadNodeIdInvalid);
				Log(Debug, "write value error, because node request parameter invalid")
					.parameter("Trx", serviceTransaction->transactionId())
					.parameter("Idx", idx);
				continue;
			}

			BaseNodeClass::SPtr baseNodeClass = informationModel_->find(writeValue->nodeId());
			if (baseNodeClass.get() == nullptr) {
				writeResponse->results()->set(idx, BadNodeIdUnknown);
				Log(Debug, "write value error, because node not exist in information model")
					.parameter("Trx", serviceTransaction->transactionId())
					.parameter("Idx", idx)
					.parameter("Node", *writeValue->nodeId())
					.parameter("Attr", writeValue->attributeId());
				continue;
			}

			Attribute* attribute = baseNodeClass->attribute((AttributeId)writeValue->attributeId());
			if (attribute == nullptr) {
				writeResponse->results()->set(idx, BadAttributeIdInvalid);
				Log(Debug, "write value error, because node attribute not exist in node")
					.parameter("Trx", serviceTransaction->transactionId())
					.parameter("Idx", idx)
					.parameter("Node", *writeValue->nodeId())
					.parameter("Attr", writeValue->attributeId())
					.parameter("Class", baseNodeClass->nodeClass().data());
				continue;
			}

			OpcUaStatusCode statusCode = forwardWrite(baseNodeClass, writeRequest, writeValue);
			if (statusCode != Success) {
				writeResponse->results()->set(idx, statusCode);
				Log(Debug, "write value error, because invalid status code from library")
					.parameter("Trx", serviceTransaction->transactionId())
					.parameter("Idx", idx)
					.parameter("Node", *writeValue->nodeId())
					.parameter("StatusCode", OpcUaStatusCodeMap::shortString(statusCode));
				continue;
			}

			if (!AttributeAccess::copy(writeValue->dataValue(), *attribute)) {
				Log(Debug, "write value error, because value error")
					.parameter("Trx", serviceTransaction->transactionId())
					.parameter("Idx", idx)
					.parameter("Node", *writeValue->nodeId())
					.parameter("Attr", writeValue->attributeId())
					.parameter("Class", baseNodeClass->nodeClass().data());
				writeResponse->results()->set(idx, BadAttributeIdInvalid);
				continue;
			}

			Log(Debug, "write value")
				.parameter("Trx", serviceTransaction->transactionId())
				.parameter("Idx", idx)
				.parameter("Node", *writeValue->nodeId())
				.parameter("Attr", writeValue->attributeId())
				.parameter("Class", baseNodeClass->nodeClass().data())
				.parameter("Data", writeValue->dataValue());

			writeResponse->results()->set(idx, Success);
		}

		serviceTransaction->statusCode(Success);
		serviceTransaction->componentSession()->send(serviceTransaction);
	}

	OpcUaStatusCode
	AttributeService::forwardWrite(BaseNodeClass::SPtr baseNodeClass, WriteRequest::SPtr writeRequest, WriteValue::SPtr writeValue)
	{
		if ((AttributeId)writeValue->attributeId() != AttributeId_Value) return Success;

		ForwardInfoSync::SPtr forwardInfoSync = baseNodeClass->forwardInfoSync();
		if (forwardInfoSync.get() == nullptr) return Success;
		if (!forwardInfoSync->isWriteCallback()) return Success;

		ApplicationWriteContext applicationWriteContext;
		applicationWriteContext.nodeId_ = *writeValue->nodeId();
		applicationWriteContext.attributeId_ = writeValue->attributeId();
		writeValue->dataValue().copyTo(applicationWriteContext.dataValue_);
		applicationWriteContext.statusCode_ = Success;
		applicationWriteContext.applicationContext_ = forwardInfoSync->applicationContext();

		forwardInfoSync->writeCallback()(&applicationWriteContext);

		return applicationWriteContext.statusCode_;
	}

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// history read service
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	void 
	AttributeService::receiveHistoryReadRequest(ServiceTransaction::SPtr serviceTransaction)
	{
		ServiceTransactionHistoryRead::SPtr trx = boost::static_pointer_cast<ServiceTransactionHistoryRead>(serviceTransaction);
		HistoryReadRequest::SPtr readRequest = trx->request();
		HistoryReadResponse::SPtr readResponse = trx->response();

		Log(Debug, "attribute service historical read request")
			.parameter("Trx", serviceTransaction->transactionId())
			.parameter("NumberNodes", readRequest->nodesToRead()->size());

		// check node id array
		if (readRequest->nodesToRead()->size() == 0) {
			trx->statusCode(BadNothingToDo);
			trx->componentSession()->send(serviceTransaction);
			return;
		}
		if (readRequest->nodesToRead()->size() > 1000) { // FIXME: todo
			trx->statusCode(BadTooManyOperations);
			trx->componentSession()->send(serviceTransaction);
			return;
		}

		// check type of history read details
		OpcUaNodeId parameterTypeId;
		parameterTypeId.set((OpcUaUInt32)OpcUaId_ReadRawModifiedDetails_Encoding_DefaultBinary);
		if (parameterTypeId != readRequest->historyReadDetails()->parameterTypeId()) {
			trx->statusCode(BadServiceUnsupported);
			trx->componentSession()->send(serviceTransaction);
			return;
		}
		ReadRawModifiedDetails::SPtr readDetails;
		readDetails = readRequest->historyReadDetails()->parameter<ReadRawModifiedDetails>();

		// read values
		readResponse->results()->resize(readRequest->nodesToRead()->size());
		for (uint32_t idx = 0; idx < readRequest->nodesToRead()->size(); idx++) {
			HistoryReadResult::SPtr readResult = constructSPtr<HistoryReadResult>();
			readResponse->results()->set(idx, readResult);

			// determine node information
			HistoryReadValueId::SPtr readValueId;
			if (!readRequest->nodesToRead()->get(idx, readValueId)) {
				readResult->statusCode(BadNodeIdInvalid);
				Log(Debug, "history read value error, because node request parameter invalid")
					.parameter("Trx", serviceTransaction->transactionId())
					.parameter("Idx", idx);
				continue;
			}

			// find node class instance for the node
			BaseNodeClass::SPtr baseNodeClass = informationModel_->find(readValueId->nodeId());
			if (baseNodeClass.get() == nullptr) {
				readResult->statusCode(BadNodeIdUnknown);
				Log(Debug, "history read value error, because node not exist in information model")
					.parameter("Trx", serviceTransaction->transactionId())
					.parameter("Idx", idx)
					.parameter("Node", *readValueId->nodeId());
				continue;
			}

			// check if forward callback exists
			ForwardInfoSync::SPtr forwardInfoSync = baseNodeClass->forwardInfoSync();
			if (forwardInfoSync.get() == nullptr) {
				readResult->statusCode(BadServiceUnsupported);
				Log(Debug, "history read value error, because service not supported")
					.parameter("Trx", serviceTransaction->transactionId())
					.parameter("Idx", idx)
					.parameter("Node", *readValueId->nodeId());
				continue;
			}
			if (!forwardInfoSync->isReadHCallback()) {
				readResult->statusCode(BadServiceUnsupported);
				Log(Debug, "history read value error, because service not supported")
					.parameter("Trx", serviceTransaction->transactionId())
					.parameter("Idx", idx)
					.parameter("Node", *readValueId->nodeId());
				continue;
			}

			// call forward calbacks
			ApplicationHReadContext applicationReadContext;
			applicationReadContext.nodeId_ = *readValueId->nodeId();
			applicationReadContext.startTime_ = readDetails->startTime().dateTime();
			applicationReadContext.stopTime_ = readDetails->endTime().dateTime();
			applicationReadContext.statusCode_ = Success;
			applicationReadContext.applicationContext_ = forwardInfoSync->applicationContext();
			forwardInfoSync->readHCallback()(&applicationReadContext);

			// check response
			readResult->statusCode(applicationReadContext.statusCode_);
			if (applicationReadContext.statusCode_ != Success) {
				Log(Debug, "history read value error, because service process failed")
					.parameter("Trx", serviceTransaction->transactionId())
					.parameter("Idx", idx)
					.parameter("Node", *readValueId->nodeId())
					.parameter("StatusCode", OpcUaStatusCodeMap::shortString(applicationReadContext.statusCode_));
				continue;
			}

			// process response
			HistoryData::SPtr historyData;
			readResult->historyData()->parameterTypeId().set((OpcUaUInt32)OpcUaId_HistoryData_Encoding_DefaultBinary);
			historyData = readResult->historyData()->parameter<HistoryData>();
			historyData->dataValues(applicationReadContext.dataValueArray_);
		}

		trx->statusCode(Success);
		trx->componentSession()->send(serviceTransaction);
	}

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// history write service
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	void 
	AttributeService::receiveHistoryUpdateRequest(ServiceTransaction::SPtr serviceTransaction)
	{
		ServiceTransactionHistoryUpdate::SPtr trx = boost::static_pointer_cast<ServiceTransactionHistoryUpdate>(serviceTransaction);
		HistoryUpdateRequest::SPtr updateRequest = trx->request();
		HistoryUpdateResponse::SPtr updateResponse = trx->response();

		// FIXME:
		serviceTransaction->statusCode(BadInternalError);
		serviceTransaction->componentSession()->send(serviceTransaction);
	}

}
