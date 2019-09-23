/*
   Copyright 2016-2019 Kai Huebl (kai@huebl-sgh.de)

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
#include "OpcUaStackCore/StandardDataTypes/ReadRawModifiedDetails.h"
#include "OpcUaStackCore/StandardDataTypes/HistoryData.h"
#include "OpcUaClient/ClientCommand/CommandReadH.h"
#include "OpcUaClient/ClientService/ClientServiceReadH.h"

using namespace OpcUaStackCore;
using namespace OpcUaStackClient;

namespace OpcUaClient
{

	ClientServiceReadH::ClientServiceReadH(void)
	: ClientServiceBase()
	, csv_()
	{
	}

	ClientServiceReadH::~ClientServiceReadH(void)
	{
	}

	ClientServiceBase::SPtr
	ClientServiceReadH::createClientService(void)
	{
		return boost::make_shared<ClientServiceReadH>();
	}

	bool
	ClientServiceReadH::run(ClientServiceManager& clientServiceManager, CommandBase::SPtr& commandBase)
	{
		OpcUaStatusCode statusCode;
		CommandReadH::SPtr commandReadH = boost::static_pointer_cast<CommandReadH>(commandBase);

		// create new or get existing client object
		ClientAccessObject::SPtr clientAccessObject;
		clientAccessObject = clientServiceManager.getClientAccessObject(commandReadH->session());
		if (clientAccessObject.get() == nullptr) {
			std::stringstream ss;
			ss << "get client access object failed:"
			   << " Session=" << commandReadH->session();
			errorMessage(ss.str());
			return false;
		}

		// check session
		if (clientAccessObject->sessionService_.get() == nullptr) {
			std::stringstream ss;
			ss << "session object not exist: "
			   << " Session=" << commandReadH->session();
			return false;
		}

		// get or create attribute service
		AttributeService::SPtr attributeService;
		attributeService = clientAccessObject->getOrCreateAttributeService();
		if (attributeService.get() == nullptr) {
			std::stringstream ss;
			ss << "get client attribute service failed"
			   << " Session=" << commandReadH->session();
			errorMessage(ss.str());
			return false;
		}

		// read historical data from server
		return hRead(attributeService, commandReadH);
	}

	bool
	ClientServiceReadH::hRead(
		AttributeService::SPtr& attributeService,
		CommandReadH::SPtr& commandReadH
	)
	{
		if (commandReadH->maxNumRequests() > 0) {
			commandReadH->maxNumRequestsDec();
		}

		OpcUaStatusCode statusCode;
		ServiceTransactionHistoryRead::SPtr trx;
		trx = boost::make_shared<ServiceTransactionHistoryRead>();
		HistoryReadRequest::SPtr req = trx->request();

		ReadRawModifiedDetails::SPtr readDetails;
		req->historyReadDetails()->parameterTypeId().set((OpcUaUInt32)OpcUaId_ReadRawModifiedDetails_Encoding_DefaultBinary);
		req->timestampsToReturn(commandReadH->timestampsToReturn());
		readDetails = req->historyReadDetails()->parameter<ReadRawModifiedDetails>();
		readDetails->startTime() = commandReadH->startTime();
		readDetails->endTime() = commandReadH->endTime();
		readDetails->numValuesPerNode() = commandReadH->maxNumResultValuesPerNode();

		req->nodesToRead()->resize(commandReadH->nodeIdVec().size());
		for (uint32_t idx=0; idx<commandReadH->nodeIdVec().size(); idx++) {
			HistoryReadValueId::SPtr readValueId = boost::make_shared<HistoryReadValueId>();
			readValueId->nodeId()->copyFrom(*commandReadH->nodeIdVec()[idx]);
			readValueId->dataEncoding().namespaceIndex((OpcUaInt16) 0);
			req->nodesToRead()->push_back(readValueId);
		}

		// send read history request
		attributeService->syncSend(trx);

		// process read response
		statusCode = trx->statusCode();
		if (statusCode != Success) {
			std::stringstream ss;
			ss << "read error: "
			   << " Session=" << commandReadH->session()
			   << " StatusCode=" << OpcUaStatusCodeMap::shortString(statusCode);
			errorMessage(ss.str());
			return false;
		}

		HistoryReadResponse::SPtr res = trx->response();
		if (res->results()->size() == 0) {
			std::stringstream ss;
			ss << "read history response length error: "
			   << " Session=" << commandReadH->session();
			errorMessage(ss.str());
			return false;
		}

		ReadNextNode::Vec readNextNodeVec;
		for (uint32_t idx=0; idx<res->results()->size(); idx++) {
			HistoryReadResult::SPtr readResult;
			res->results()->get(idx, readResult);
			if (readResult->statusCode() != Success) {
				std::cout << "Status=" << OpcUaStatusCodeMap::shortString(readResult->statusCode()) << std::endl;;
				continue;
			}


			OpcUaNodeId typeId = readResult->historyData()->parameterTypeId();
			uint32_t id = typeId.nodeId<OpcUaUInt32>();
			if (id != OpcUaId_HistoryData_Encoding_DefaultBinary) {
				std::stringstream ss;
				ss << "receive invalid message type: "
				   << " Session=" << commandReadH->session()
				   << " TypeNodeId=" << typeId.toString();
				errorMessage(ss.str());
				return false;
			}

			HistoryData::SPtr historyData = readResult->historyData()->parameter<HistoryData>();
			for (uint32_t idxv=0; idxv<historyData->dataValues().size(); idxv++) {
				OpcUaDataValue::SPtr dataValue;
				historyData->dataValues().get(idxv, dataValue);
				output(*dataValue, commandReadH);
			}


			if (readResult->continuationPoint().exist()  && historyData->dataValues().size() > 0) {
				HistoryReadValueId::SPtr readValueId;
				req->nodesToRead()->get(idx, readValueId);

				ReadNextNode readNextNode;
				readNextNode.nodeId_.copyFrom(*readValueId->nodeId());
				readNextNode.continousPoint_ = readResult->continuationPoint().toString();
				readNextNodeVec.push_back(readNextNode);
			}
		}

		if (!readNextNodeVec.empty()) {
			if (commandReadH->maxNumRequests() == 0) {
				return hDelete(attributeService, commandReadH, readNextNodeVec);
			}
			else {
				return hReadNext(attributeService, commandReadH, readNextNodeVec);
			}
		}

		return true;
	}

	bool
	ClientServiceReadH::hReadNext(
		AttributeService::SPtr& attributeService,
		CommandReadH::SPtr& commandReadH,
		ReadNextNode::Vec& readNextNodeVec
	)
	{

		if (commandReadH->maxNumRequests() > 0) {
			commandReadH->maxNumRequestsDec();
		}

		OpcUaStatusCode statusCode;
		ServiceTransactionHistoryRead::SPtr trx;
		trx = boost::make_shared<ServiceTransactionHistoryRead>();
		HistoryReadRequest::SPtr req = trx->request();

		ReadRawModifiedDetails::SPtr readDetails;
		req->historyReadDetails()->parameterTypeId().set((OpcUaUInt32)OpcUaId_ReadRawModifiedDetails_Encoding_DefaultBinary);
		req->timestampsToReturn(commandReadH->timestampsToReturn());
		readDetails = req->historyReadDetails()->parameter<ReadRawModifiedDetails>();
		readDetails->startTime() = commandReadH->startTime();
		readDetails->endTime() = commandReadH->endTime();
		readDetails->numValuesPerNode() = commandReadH->maxNumResultValuesPerNode();

		req->nodesToRead()->resize(readNextNodeVec.size());
		for (uint32_t idx=0; idx<readNextNodeVec.size(); idx++) {
			OpcUaByteString continousPoint;
			continousPoint.value(readNextNodeVec[idx].continousPoint_);

			HistoryReadValueId::SPtr readValueId = boost::make_shared<HistoryReadValueId>();
			readValueId->nodeId()->copyFrom(readNextNodeVec[idx].nodeId_);
			readValueId->dataEncoding().namespaceIndex((OpcUaInt16) 0);
			continousPoint.copyTo(readValueId->continuationPoint());

			req->nodesToRead()->push_back(readValueId);
		}

		// send read history request
		attributeService->syncSend(trx);

		// process read response
		statusCode = trx->statusCode();
		if (statusCode != Success) {
			std::stringstream ss;
			ss << "read error: "
			   << " Session=" << commandReadH->session()
			   << " StatusCode=" << OpcUaStatusCodeMap::shortString(statusCode);
			errorMessage(ss.str());
			return false;
		}

		HistoryReadResponse::SPtr res = trx->response();
		if (res->results()->size() == 0) {
			std::stringstream ss;
			ss << "read history response length error: "
			   << " Session=" << commandReadH->session();
			errorMessage(ss.str());
			return false;
		}

		readNextNodeVec.clear();
		for (uint32_t idx=0; idx<res->results()->size(); idx++) {
			HistoryReadResult::SPtr readResult;
			res->results()->get(idx, readResult);
			if (readResult->statusCode() != Success) {
				std::cout << "Status=" << OpcUaStatusCodeMap::shortString(readResult->statusCode()) << std::endl;;
				continue;
			}


			OpcUaNodeId typeId = readResult->historyData()->parameterTypeId();
			uint32_t id = typeId.nodeId<OpcUaUInt32>();
			if (id != OpcUaId_HistoryData_Encoding_DefaultBinary) {
				std::stringstream ss;
				ss << "receive invalid message type: "
				   << " Session=" << commandReadH->session()
				   << " TypeNodeId=" << typeId.toString();
				errorMessage(ss.str());
				return false;
			}

			HistoryData::SPtr historyData = readResult->historyData()->parameter<HistoryData>();
			for (uint32_t idxv=0; idxv<historyData->dataValues().size(); idxv++) {
				OpcUaDataValue::SPtr dataValue;
				historyData->dataValues().get(idxv, dataValue);
				output(*dataValue, commandReadH);
			}


			if (readResult->continuationPoint().exist() && historyData->dataValues().size() > 0) {
				HistoryReadValueId::SPtr readValueId;
				req->nodesToRead()->get(idx, readValueId);

				ReadNextNode readNextNode;
				readNextNode.nodeId_.copyFrom(*readValueId->nodeId());
				readNextNode.continousPoint_ = readResult->continuationPoint().toString();
				readNextNodeVec.push_back(readNextNode);
			}
		}

		if (!readNextNodeVec.empty()) {
			if (commandReadH->maxNumRequests() == 0) {
				return hDelete(attributeService, commandReadH, readNextNodeVec);
			}
			else {
				return hReadNext(attributeService, commandReadH, readNextNodeVec);
			}
		}
		return true;
	}

	bool
	ClientServiceReadH::hDelete(
		AttributeService::SPtr& attributeService,
		CommandReadH::SPtr& commandReadH,
		ReadNextNode::Vec& readNextNodeVec
	)
	{
		OpcUaStatusCode statusCode;
		ServiceTransactionHistoryRead::SPtr trx;
		trx = boost::make_shared<ServiceTransactionHistoryRead>();
		HistoryReadRequest::SPtr req = trx->request();

		ReadRawModifiedDetails::SPtr readDetails;
		req->historyReadDetails()->parameterTypeId().set((OpcUaUInt32)OpcUaId_ReadRawModifiedDetails_Encoding_DefaultBinary);
		req->timestampsToReturn(commandReadH->timestampsToReturn());
		req->releaseContinuationPoints(true);
		readDetails = req->historyReadDetails()->parameter<ReadRawModifiedDetails>();
		readDetails->startTime() = commandReadH->startTime();
		readDetails->endTime() = commandReadH->endTime();
		readDetails->numValuesPerNode() = commandReadH->maxNumResultValuesPerNode();

		req->nodesToRead()->resize(readNextNodeVec.size());
		for (uint32_t idx=0; idx<readNextNodeVec.size(); idx++) {
			OpcUaByteString continousPoint;
			continousPoint.value(readNextNodeVec[idx].continousPoint_);

			HistoryReadValueId::SPtr readValueId = boost::make_shared<HistoryReadValueId>();
			readValueId->nodeId()->copyFrom(readNextNodeVec[idx].nodeId_);
			readValueId->dataEncoding().namespaceIndex((OpcUaInt16) 0);
			continousPoint.copyTo(readValueId->continuationPoint());

			req->nodesToRead()->push_back(readValueId);
		}

		// send read history request
		attributeService->syncSend(trx);

		// process read response
		statusCode = trx->statusCode();
		if (statusCode != Success) {
			std::stringstream ss;
			ss << "read error: "
			   << " Session=" << commandReadH->session()
			   << " StatusCode=" << OpcUaStatusCodeMap::shortString(statusCode);
			errorMessage(ss.str());
			return false;
		}

		HistoryReadResponse::SPtr res = trx->response();
		if (res->results()->size() == 0) {
			std::stringstream ss;
			ss << "read history response length error: "
			   << " Session=" << commandReadH->session();
			errorMessage(ss.str());
			return false;
		}

		return true;
	}

	bool
	ClientServiceReadH::output(
		OpcUaDataValue& dataValue,
		CommandReadH::SPtr& commandReadH
	)
	{
		switch (commandReadH->outputType())
		{
			case CommandReadH::T_CSVFile:
			{
				if (!outputCSV(dataValue, commandReadH)) {
					dataValue.out(std::cout); std::cout << std::endl;
					commandReadH->outputType(CommandReadH::T_Stdout);
				}
				break;
			}
			default:
			{
				dataValue.out(std::cout); std::cout << std::endl;
				break;
			}
		}
		return true;
	}

	bool
	ClientServiceReadH::outputCSV(
		OpcUaDataValue& dataValue,
		CommandReadH::SPtr& commandReadH
	)
	{
		// if necessaray initializing csv output
		if (csv_.get() == nullptr) {
			csv_ = boost::make_shared<CSV>();
			bool success = csv_->open(commandReadH->csvFileName(), CSV::M_Write);
			if (!success) {
				Log(Error, "open csv file error")
					.parameter("CSVFileName", commandReadH->csvFileName());
				csv_.reset();
				return false;
			}
		}

		// create line to write to the csv file
		CSV::Line line;

		std::stringstream statusCode;
		statusCode << (uint32_t)dataValue.statusCode();
		line.push_back(statusCode.str());

		if (dataValue.statusCode() == Success) {
			std::stringstream variable;
			dataValue.variant()->out(variable);
			line.push_back(variable.str());
		}
		else {
			line.push_back("---");
		}

		if (dataValue.sourceTimestamp().exist()) {
			line.push_back(dataValue.sourceTimestamp().toISOString());
		}
		else {
			line.push_back("---");
		}

		if (dataValue.serverTimestamp().exist()) {
			line.push_back(dataValue.serverTimestamp().toISOString());
		}
		else {
			line.push_back("---");
		}

		// write line to csv file
		if (csv_->writeLine(line) != CSV::S_Ok) {
			Log(Error, "write csv file error")
				.parameter("CSVFileName", commandReadH->csvFileName());
			csv_.reset();
			return false;
		}

		return true;
	}

}

