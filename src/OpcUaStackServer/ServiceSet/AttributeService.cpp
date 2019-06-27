/*
   Copyright 2015-2018 Kai Huebl (kai@huebl-sgh.de)

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
#include "OpcUaStackCore/Application/ApplicationAutorizationContext.h"
#include "OpcUaStackCore/Application/ApplicationReadContext.h"
#include "OpcUaStackCore/Application/ApplicationHReadContext.h"
#include "OpcUaStackCore/Application/ApplicationHReadEventContext.h"
#include "OpcUaStackCore/Application/ApplicationWriteContext.h"
#include "OpcUaStackCore/Application/ApplicationHWriteContext.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaIdentifier.h"
#include "OpcUaStackCore/StandardDataTypes/HistoryEvent.h"
#include "OpcUaStackCore/StandardDataTypes/ReadEventDetails.h"
#include "OpcUaStackCore/StandardDataTypes/ReadRawModifiedDetails.h"
#include "OpcUaStackCore/StandardDataTypes/HistoryData.h"
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
		OpcUaStatusCode statusCode;

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
		if (readRequest->readValueIdArray()->size() > 3000) { // FIXME: todo
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

			// autorization
			statusCode = forwardAuthorizationRead(serviceTransaction->userContext(), readValueId);
			if (statusCode != Success) {
				dataValue->statusCode(statusCode);
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

			boost::shared_lock<boost::shared_mutex> lock(baseNodeClass->mutex());

			// forward read request
			forwardRead(
				serviceTransaction->userContext(),
				baseNodeClass,
				readRequest,
				readValueId
			);

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

	OpcUaStatusCode
	AttributeService::forwardAuthorizationRead(UserContext::SPtr& userContext, ReadValueId::SPtr& readValueId)
	{
		if (forwardGlobalSync().get() == nullptr) return Success;
		if (!forwardGlobalSync()->autorizationService().isCallback()) return Success;

		ApplicationAutorizationContext context;
		context.userContext_ = userContext;
		context.serviceOperation_ = ServiceOperation::Read;
		context.nodeId_ = *readValueId->nodeId();
		context.attributeId_ = readValueId->attributeId();

		forwardGlobalSync()->autorizationService().callback()(&context);

		return context.statusCode_;
	}

	void
	AttributeService::forwardRead(
		UserContext::SPtr& userContext,
		BaseNodeClass::SPtr baseNodeClass,
		ReadRequest::SPtr readRequest,
		ReadValueId::SPtr readValueId
	)
	{
		if ((AttributeId)readValueId->attributeId() != AttributeId_Value) return;

		ForwardNodeSync::SPtr forwardNodeSync = baseNodeClass->forwardNodeSync();
		if (forwardNodeSync.get() == nullptr) return;
		if (!forwardNodeSync->readService().isCallback()) return;

		ApplicationReadContext applicationReadContext;
		applicationReadContext.nodeId_ = *readValueId->nodeId();
		applicationReadContext.attributeId_ = readValueId->attributeId();
		applicationReadContext.statusCode_ = Success;
		applicationReadContext.applicationContext_ = forwardNodeSync->readService().applicationContext();
		applicationReadContext.userContext_ = userContext;

		forwardNodeSync->readService().callback()(&applicationReadContext);

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
		OpcUaStatusCode statusCode;

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
		if (writeRequest->writeValueArray()->size() > 3000) {  // FIXME: todo
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

			// autorization
			statusCode = forwardAuthorizationWrite(serviceTransaction->userContext(), writeValue);
			if (statusCode != Success) {
				writeResponse->results()->set(idx, statusCode);
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

			boost::unique_lock<boost::shared_mutex> lock(baseNodeClass->mutex());

			OpcUaStatusCode statusCode = forwardWrite(
				serviceTransaction->userContext(),
				baseNodeClass,
				writeRequest,
				writeValue
			);
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
	AttributeService::forwardAuthorizationWrite(UserContext::SPtr& userContext, WriteValue::SPtr& writeValue)
	{
		if (forwardGlobalSync().get() == nullptr) return Success;
		if (!forwardGlobalSync()->autorizationService().isCallback()) return Success;

		ApplicationAutorizationContext context;
		context.userContext_ = userContext;
		context.serviceOperation_ = ServiceOperation::Write;
		context.nodeId_ = *writeValue->nodeId();
		context.attributeId_ = writeValue->attributeId();

		forwardGlobalSync()->autorizationService().callback()(&context);

		return context.statusCode_;
	}

	OpcUaStatusCode
	AttributeService::forwardWrite(
		UserContext::SPtr& userContext,
		BaseNodeClass::SPtr baseNodeClass,
		WriteRequest::SPtr writeRequest,
		WriteValue::SPtr writeValue
	)
	{
		if ((AttributeId)writeValue->attributeId() != AttributeId_Value) return Success;

		ForwardNodeSync::SPtr forwardNodeSync = baseNodeClass->forwardNodeSync();
		if (forwardNodeSync.get() == nullptr) return Success;
		if (!forwardNodeSync->writeService().isCallback()) return Success;

		ApplicationWriteContext applicationWriteContext;
		applicationWriteContext.nodeId_ = *writeValue->nodeId();
		applicationWriteContext.attributeId_ = writeValue->attributeId();
		writeValue->dataValue().copyTo(applicationWriteContext.dataValue_);
		applicationWriteContext.statusCode_ = Success;
		applicationWriteContext.applicationContext_ = forwardNodeSync->writeService().applicationContext();
		applicationWriteContext.userContext_ = userContext;

		forwardNodeSync->writeService().callback()(&applicationWriteContext);

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
		OpcUaStatusCode statusCode;

		ServiceTransactionHistoryRead::SPtr trx = boost::static_pointer_cast<ServiceTransactionHistoryRead>(serviceTransaction);
		HistoryReadRequest::SPtr readRequest = trx->request();
		HistoryReadResponse::SPtr readResponse = trx->response();

		Log(Debug, "attribute service historical read request")
			.parameter("Trx", serviceTransaction->transactionId())
			.parameter("NumberNodes", readRequest->nodesToRead()->size())
			.parameter("ParameterTypeId", readRequest->historyReadDetails()->parameterTypeId());

		// check timestampsToReturn attribute
		if (readRequest->timestampsToReturn() == TimestampsToReturn_Neither) {
			trx->statusCode(BadInvalidTimestampArgument);
			trx->componentSession()->send(serviceTransaction);
			return;
		}

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
		if (parameterTypeId == readRequest->historyReadDetails()->parameterTypeId()) {
			receiveHistoryReadRawRequest(
				serviceTransaction,
				trx,
				readRequest,
				readResponse
			);
			return;
		}

		// check type of history event
		parameterTypeId.set((OpcUaUInt32)OpcUaId_ReadEventDetails_Encoding_DefaultBinary);
		if (parameterTypeId == readRequest->historyReadDetails()->parameterTypeId()) {
			receiveHistoryReadEventRequest(
				serviceTransaction,
				trx,
				readRequest,
				readResponse
			);
			return;
		}

		Log(Error, "receive invalid attribute history read details");
		trx->statusCode(BadServiceUnsupported);
		trx->componentSession()->send(serviceTransaction);
	}

	void
	AttributeService::receiveHistoryReadRawRequest(
		ServiceTransaction::SPtr& serviceTransaction,
		ServiceTransactionHistoryRead::SPtr& trx,
		HistoryReadRequest::SPtr readRequest,
		HistoryReadResponse::SPtr readResponse
	)
	{
		OpcUaStatusCode statusCode;

		ReadRawModifiedDetails::SPtr readDetails;
		readDetails = readRequest->historyReadDetails()->parameter<ReadRawModifiedDetails>();
		uint32_t numValuesPerNode = readDetails->numValuesPerNode();

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

			// autorization
			statusCode = forwardAuthorizationHistoricalRead(serviceTransaction->userContext(), readValueId);
			if (statusCode != Success) {
				readResult->statusCode(statusCode);
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
			ForwardNodeSync::SPtr forwardNodeSync = baseNodeClass->forwardNodeSync();
			if (forwardNodeSync.get() == nullptr) {
				readResult->statusCode(BadServiceUnsupported);
				Log(Debug, "history read value error, because service not supported (1)")
					.parameter("Trx", serviceTransaction->transactionId())
					.parameter("Idx", idx)
					.parameter("Node", *readValueId->nodeId());
				continue;
			}
			if (!forwardNodeSync->readHService().isCallback()) {
				readResult->statusCode(BadServiceUnsupported);
				Log(Debug, "history read value error, because service not supported (2)")
					.parameter("Trx", serviceTransaction->transactionId())
					.parameter("Idx", idx)
					.parameter("Node", *readValueId->nodeId());
				continue;
			}

			// get continous point
			std::string continousPoint = "";
			if (readValueId->continuationPoint().exist()) {
				continousPoint = readValueId->continuationPoint().toString();
			}

			// call forward calbacks
			ApplicationHReadContext applicationReadContext;
			applicationReadContext.nodeId_ = *readValueId->nodeId();
			applicationReadContext.startTime_ = readDetails->startTime().dateTime();
			applicationReadContext.stopTime_ = readDetails->endTime().dateTime();
			applicationReadContext.timestampsToReturn_ = readRequest->timestampsToReturn();
			applicationReadContext.statusCode_ = Success;
			applicationReadContext.applicationContext_ = forwardNodeSync->readHService().applicationContext();
			applicationReadContext.releaseContinuationPoints_ = readRequest->releaseContinuationPoints();
			applicationReadContext.continousPoint_ = continousPoint;
			applicationReadContext.numValuesPerNode_ = numValuesPerNode;
			applicationReadContext.userContext_ = serviceTransaction->userContext();

			forwardNodeSync->readHService().callback()(&applicationReadContext);

			// check response
			readResult->statusCode(applicationReadContext.statusCode_);

			if (!applicationReadContext.continousPoint_.empty()) {
				readResult->continuationPoint().value(applicationReadContext.continousPoint_);
			}

			if (applicationReadContext.statusCode_ != Success) {
				readResult->statusCode(BadInternalError);
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
			applicationReadContext.dataValueArray_->copyTo(historyData->dataValues());
		}

		trx->statusCode(Success);
		trx->componentSession()->send(serviceTransaction);
	}

	void
	AttributeService::receiveHistoryReadEventRequest(
		ServiceTransaction::SPtr& serviceTransaction,
		ServiceTransactionHistoryRead::SPtr& trx,
		HistoryReadRequest::SPtr readRequest,
		HistoryReadResponse::SPtr readResponse
	)
	{
		OpcUaStatusCode statusCode;

		ReadEventDetails::SPtr readDetails;
		readDetails = readRequest->historyReadDetails()->parameter<ReadEventDetails>();
		uint32_t numValuesPerNode = readDetails->numValuesPerNode();

		// read values
		readResponse->results()->resize(readRequest->nodesToRead()->size());
		for (uint32_t idx = 0; idx < readRequest->nodesToRead()->size(); idx++) {
			HistoryReadResult::SPtr readResult = constructSPtr<HistoryReadResult>();
			readResponse->results()->set(idx, readResult);

			// determine node information
			HistoryReadValueId::SPtr readValueId;
			if (!readRequest->nodesToRead()->get(idx, readValueId)) {
				readResult->statusCode(BadNodeIdInvalid);
				Log(Debug, "history read event error, because node request parameter invalid")
					.parameter("Trx", serviceTransaction->transactionId())
					.parameter("Idx", idx);
				continue;
			}

			// autorization
			statusCode = forwardAuthorizationHistoricalRead(serviceTransaction->userContext(), readValueId);
			if (statusCode != Success) {
				readResult->statusCode(statusCode);
				continue;
			}

			// find node class instance for the node
			BaseNodeClass::SPtr baseNodeClass = informationModel_->find(readValueId->nodeId());
			if (baseNodeClass.get() == nullptr) {
				readResult->statusCode(BadNodeIdUnknown);
				Log(Debug, "history read event error, because node not exist in information model")
					.parameter("Trx", serviceTransaction->transactionId())
					.parameter("Idx", idx)
					.parameter("Node", *readValueId->nodeId());
				continue;
			}

			// check if forward callback exists
			ForwardNodeSync::SPtr forwardNodeSync = baseNodeClass->forwardNodeSync();
			if (forwardNodeSync.get() == nullptr) {
				readResult->statusCode(BadServiceUnsupported);
				Log(Debug, "history read event error, because service not supported")
					.parameter("Trx", serviceTransaction->transactionId())
					.parameter("Idx", idx)
					.parameter("Node", *readValueId->nodeId());
				continue;
			}
			if (!forwardNodeSync->readHEService().isCallback()) {
				readResult->statusCode(BadServiceUnsupported);
				Log(Debug, "history read event error, because service not supported")
					.parameter("Trx", serviceTransaction->transactionId())
					.parameter("Idx", idx)
					.parameter("Node", *readValueId->nodeId());
				continue;
			}

			// get continous point
			std::string continousPoint = "";
			if (readValueId->continuationPoint().exist()) {
				continousPoint = readValueId->continuationPoint().toString();
			}

			// call forward calbacks
			ApplicationHReadEventContext applicationReadContext;
			applicationReadContext.nodeId_ = *readValueId->nodeId();
			applicationReadContext.startTime_ = readDetails->startTime().dateTime();
			applicationReadContext.stopTime_ = readDetails->endTime().dateTime();
			applicationReadContext.timestampsToReturn_ = readRequest->timestampsToReturn();
			applicationReadContext.filter_ = readDetails->filter();
			applicationReadContext.statusCode_ = Success;
			applicationReadContext.applicationContext_ = forwardNodeSync->readHEService().applicationContext();
			applicationReadContext.releaseContinuationPoints_ = readRequest->releaseContinuationPoints();
			applicationReadContext.continousPoint_ = continousPoint;
			applicationReadContext.numValuesPerNode_ = numValuesPerNode;
			applicationReadContext.userContext_ = serviceTransaction->userContext();

			forwardNodeSync->readHEService().callback()(&applicationReadContext);

			// check response
			readResult->statusCode(applicationReadContext.statusCode_);

			if (!applicationReadContext.continousPoint_.empty()) {
				readResult->continuationPoint().value(applicationReadContext.continousPoint_);
			}

			if (applicationReadContext.statusCode_ != Success) {
				readResult->statusCode(BadInternalError);
				Log(Debug, "history read event error, because service process failed")
					.parameter("Trx", serviceTransaction->transactionId())
					.parameter("Idx", idx)
					.parameter("Node", *readValueId->nodeId())
					.parameter("StatusCode", OpcUaStatusCodeMap::shortString(applicationReadContext.statusCode_));
				continue;
			}

			// process response
			HistoryEvent::SPtr historyEvent;
			readResult->historyData()->parameterTypeId().set((OpcUaUInt32)OpcUaId_HistoryEvent_Encoding_DefaultBinary);
			historyEvent = readResult->historyData()->parameter<HistoryEvent>();
			applicationReadContext.eventFieldArray_->copyTo(historyEvent->events());
		}

		trx->statusCode(Success);
		trx->componentSession()->send(serviceTransaction);
	}

	OpcUaStatusCode
	AttributeService::forwardAuthorizationHistoricalRead(UserContext::SPtr& userContext, HistoryReadValueId::SPtr& readValueId)
	{
		if (forwardGlobalSync().get() == nullptr) return Success;
		if (!forwardGlobalSync()->autorizationService().isCallback()) return Success;

		ApplicationAutorizationContext context;
		context.userContext_ = userContext;
		context.serviceOperation_ = ServiceOperation::HRead;
		context.nodeId_ = *readValueId->nodeId();
		context.attributeId_ = AttributeId_Value;

		forwardGlobalSync()->autorizationService().callback()(&context);

		return context.statusCode_;
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
		OpcUaStatusCode statusCode;

		ServiceTransactionHistoryUpdate::SPtr trx = boost::static_pointer_cast<ServiceTransactionHistoryUpdate>(serviceTransaction);
		HistoryUpdateRequest::SPtr updateRequest = trx->request();
		HistoryUpdateResponse::SPtr updateResponse = trx->response();

		Log(Debug, "attribute service historical update request")
			.parameter("Trx", serviceTransaction->transactionId())
			.parameter("NumberNodes", updateRequest->historyUpdateDetails()->size());

		// check data array
		if (updateRequest->historyUpdateDetails()->size() == 0) {
			trx->statusCode(BadNothingToDo);
			trx->componentSession()->send(serviceTransaction);
			return;
		}
		if (updateRequest->historyUpdateDetails()->size() > 1000) { // FIXME: todo
			trx->statusCode(BadTooManyOperations);
			trx->componentSession()->send(serviceTransaction);
			return;
		}

		updateResponse->results()->resize(updateRequest->historyUpdateDetails()->size());
		for (uint32_t idx=0; idx<updateRequest->historyUpdateDetails()->size(); idx++) {

			// create result package
			HistoryUpdateResult::SPtr writeResult = constructSPtr<HistoryUpdateResult>();
			updateResponse->results()->push_back(writeResult);

			// check type of history update details
			OpcUaExtensibleParameter::SPtr extensibleParameter;
			updateRequest->historyUpdateDetails()->get(idx, extensibleParameter);

			OpcUaNodeId parameterTypeId;
			parameterTypeId.set((OpcUaUInt32)OpcUaId_UpdateStructureDataDetails_Encoding_DefaultBinary);
			if (parameterTypeId != extensibleParameter->parameterTypeId()) {
				writeResult->statusCode(BadServiceUnsupported);
				Log(Debug, "history write value error, because invalid parameter type id")
					.parameter("Trx", serviceTransaction->transactionId())
					.parameter("Idx", idx)
					.parameter("ParameterTypeId", extensibleParameter->parameterTypeId());
				continue;
			}
			UpdateStructureDataDetails::SPtr dataDetails;
			dataDetails = extensibleParameter->parameter<UpdateStructureDataDetails>();

			// autorization
			statusCode = forwardAuthorizationHistoricalWrite(serviceTransaction->userContext(), dataDetails);
			if (statusCode != Success) {
				writeResult->statusCode(statusCode);
				continue;
			}

			// check operation type
			if (dataDetails->performInsertReplace().enumeration() != PerformUpdateType::EnumInsert) {
				writeResult->statusCode(BadServiceUnsupported);
				Log(Debug, "history write value error, because invalid operation type")
					.parameter("Trx", serviceTransaction->transactionId())
					.parameter("Idx", idx)
					.parameter("Node", dataDetails->nodeId())
					.parameter("OperationType", dataDetails->performInsertReplace().toString());
				continue;
			}

			// check data array
			if (dataDetails->updateValues().size() == 0) {
				writeResult->statusCode(BadNothingToDo);
				continue;
			}

			// find node class instance for the node
			BaseNodeClass::SPtr baseNodeClass = informationModel_->find(dataDetails->nodeId());
			if (baseNodeClass.get() == nullptr) {
				writeResult->statusCode(BadNodeIdUnknown);
				Log(Debug, "history write value error, because node not exist in information model")
					.parameter("Trx", serviceTransaction->transactionId())
					.parameter("Idx", idx)
					.parameter("Node", dataDetails->nodeId());
				continue;
			}

			// check if forward callback exists
			ForwardNodeSync::SPtr forwardNodeSync = baseNodeClass->forwardNodeSync();
			if (forwardNodeSync.get() == nullptr) {
				writeResult->statusCode(BadServiceUnsupported);
				Log(Debug, "history write value error, because service not supported")
					.parameter("Trx", serviceTransaction->transactionId())
					.parameter("Idx", idx)
					.parameter("Node", dataDetails->nodeId());
				continue;
			}
			if (!forwardNodeSync->writeHService().isCallback()) {
				writeResult->statusCode(BadServiceUnsupported);
				Log(Debug, "history write value error, because service not supported")
					.parameter("Trx", serviceTransaction->transactionId())
					.parameter("Idx", idx)
					.parameter("Node", dataDetails->nodeId());
				continue;
			}

			// call forward callback
			ApplicationHWriteContext applicationWriteContext;
			applicationWriteContext.nodeId_ = dataDetails->nodeId();
			dataDetails->updateValues().copyTo(*applicationWriteContext.dataValueArray_);
			applicationWriteContext.statusCode_ = Success;
			applicationWriteContext.applicationContext_ = forwardNodeSync->writeHService().applicationContext();
			applicationWriteContext.userContext_ = serviceTransaction->userContext();

			forwardNodeSync->writeHService().callback()(&applicationWriteContext);
			writeResult->statusCode(applicationWriteContext.statusCode_);
		}

		serviceTransaction->statusCode(Success);
		serviceTransaction->componentSession()->send(serviceTransaction);
	}

	OpcUaStatusCode
	AttributeService::forwardAuthorizationHistoricalWrite(UserContext::SPtr& userContext, UpdateStructureDataDetails::SPtr& updateStructureDataDetails)
	{
		if (forwardGlobalSync().get() == nullptr) return Success;
		if (!forwardGlobalSync()->autorizationService().isCallback()) return Success;

		ApplicationAutorizationContext context;
		context.userContext_ = userContext;
		context.serviceOperation_ = ServiceOperation::HWrite;
		context.nodeId_ = updateStructureDataDetails->nodeId();
		context.attributeId_ = AttributeId_Value;

		forwardGlobalSync()->autorizationService().callback()(&context);

		return context.statusCode_;
	}

}
