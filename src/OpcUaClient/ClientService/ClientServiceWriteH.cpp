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
#include "OpcUaStackCore/StandardDataTypes/UpdateStructureDataDetails.h"
#include "OpcUaStackCore/StandardDataTypes/HistoryData.h"
#include "OpcUaClient/ClientCommand/CommandWriteH.h"
#include "OpcUaClient/ClientService/ClientServiceWriteH.h"

#define MAXValuesPerRequest		1000

using namespace OpcUaStackCore;
using namespace OpcUaStackClient;

namespace OpcUaClient
{

	ClientServiceWriteH::ClientServiceWriteH(void)
	: ClientServiceBase()
	{
	}

	ClientServiceWriteH::~ClientServiceWriteH(void)
	{
	}

	ClientServiceBase::SPtr
	ClientServiceWriteH::createClientService(void)
	{
		return boost::make_shared<ClientServiceWriteH>();
	}

	bool
	ClientServiceWriteH::run(ClientServiceManager& clientServiceManager, CommandBase::SPtr& commandBase)
	{
		OpcUaStatusCode statusCode;
		CommandWriteH::SPtr commandWriteH = boost::static_pointer_cast<CommandWriteH>(commandBase);

		// create new or get existing client object
		ClientAccessObject::SPtr clientAccessObject;
		clientAccessObject = clientServiceManager.getClientAccessObject(commandWriteH->session());
		if (clientAccessObject.get() == nullptr) {
			std::stringstream ss;
			ss << "get client access object failed:"
			   << " Session=" << commandWriteH->session();
			errorMessage(ss.str());
			return false;
		}

		// check session
		if (clientAccessObject->sessionService_.get() == nullptr) {
			std::stringstream ss;
			ss << "session object not exist: "
			   << " Session=" << commandWriteH->session();
			return false;
		}

		// get or create attribute service
		AttributeService::SPtr attributeService;
		attributeService = clientAccessObject->getOrCreateAttributeService();
		if (attributeService.get() == nullptr) {
			std::stringstream ss;
			ss << "get client attribute service failed"
			   << " Session=" << commandWriteH->session();
			errorMessage(ss.str());
			return false;
		}

		if (commandWriteH->inputType() == CommandWriteH::T_CSVFile) {
			return writeCSV(attributeService, commandWriteH);
		}
		else {
			return write(attributeService, commandWriteH);
		}
	}

	bool
	ClientServiceWriteH::write(
		AttributeService::SPtr& attributeService,
		CommandWriteH::SPtr& commandWriteH
	)
	{
		OpcUaStatusCode statusCode;

		// create update request
		ServiceTransactionHistoryUpdate::SPtr trx;
		trx = boost::make_shared<ServiceTransactionHistoryUpdate>();
		HistoryUpdateRequest::SPtr req = trx->request();

		req->historyUpdateDetails()->resize(1);
		OpcUaExtensibleParameter::SPtr extensibleParameter = boost::make_shared<OpcUaExtensibleParameter>();
		req->historyUpdateDetails()->push_back(extensibleParameter);

		UpdateStructureDataDetails::SPtr updateDetails;
		extensibleParameter->parameterTypeId().set((OpcUaUInt32)OpcUaId_UpdateStructureDataDetails_Encoding_DefaultBinary);
		updateDetails = extensibleParameter->parameter<UpdateStructureDataDetails>();

		updateDetails->nodeId() = commandWriteH->nodeId();
		updateDetails->performInsertReplace().enumeration(PerformUpdateType::EnumInsert);

		updateDetails->updateValues().resize(commandWriteH->dataValueVec().size());
		for (uint32_t idx=0; idx<commandWriteH->dataValueVec().size(); idx++) {
			updateDetails->updateValues().push_back(commandWriteH->dataValueVec()[idx]);
		}

		// send read history request
		attributeService->syncSend(trx);

		// process read response
		statusCode = trx->statusCode();
		if (statusCode != Success) {
			std::stringstream ss;
			ss << "write history error: "
			   << " Session=" << commandWriteH->session()
			   << " StatusCode=" << OpcUaStatusCodeMap::shortString(statusCode);
			errorMessage(ss.str());
			return false;
		}

		HistoryUpdateResponse::SPtr res = trx->response();
		if (res->results()->size() != 1) {
			std::stringstream ss;
			ss << "write history response length error: "
			   << " Session=" << commandWriteH->session();
			errorMessage(ss.str());
			return false;
		}

		HistoryUpdateResult::SPtr historyUpdateResult;
		res->results()->get(0, historyUpdateResult);
		if (historyUpdateResult->statusCode() != Success) {
			std::stringstream ss;
			ss << "write history result error: "
			   << " Session=" << commandWriteH->session()
			   << " StatusCode=" << OpcUaStatusCodeMap::shortString(historyUpdateResult->statusCode());
			errorMessage(ss.str());
			return false;
		}

		return true;
	}

	bool
	ClientServiceWriteH::writeCSV(
		AttributeService::SPtr& attributeService,
		CommandWriteH::SPtr& commandWriteH
	)
	{
		// open csv file
		if (!openCSVFile(commandWriteH->csvFileName())) {
			return false;
		}

		bool ready = false;
		while (!ready)
		{

			// ----------------------------------------------------------------
			// read lines from csv file
			// ----------------------------------------------------------------
			OpcUaDataValue::Vec dataValueVec;
			bool success = readCSVLines(
				commandWriteH->csvFileName(),
				commandWriteH->valueType(),
				dataValueVec
			);

			// error occurred
			if (!success) {
				return false;
			}

			// eof
			if (dataValueVec.empty()) {
				return true;
			}

			//
			// create history write request and set it to the opc ua server
			//
			OpcUaStatusCode statusCode;

			// create update request
			ServiceTransactionHistoryUpdate::SPtr trx;
			trx = boost::make_shared<ServiceTransactionHistoryUpdate>();
			HistoryUpdateRequest::SPtr req = trx->request();

			req->historyUpdateDetails()->resize(1);
			OpcUaExtensibleParameter::SPtr extensibleParameter = boost::make_shared<OpcUaExtensibleParameter>();
			req->historyUpdateDetails()->push_back(extensibleParameter);

			UpdateStructureDataDetails::SPtr updateDetails;
			extensibleParameter->parameterTypeId().set((OpcUaUInt32)OpcUaId_UpdateStructureDataDetails_Encoding_DefaultBinary);
			updateDetails = extensibleParameter->parameter<UpdateStructureDataDetails>();

			updateDetails->nodeId() = commandWriteH->nodeId();
			updateDetails->performInsertReplace().enumeration(PerformUpdateType::EnumInsert);

			updateDetails->updateValues().resize(dataValueVec.size());
			for (uint32_t idx=0; idx<dataValueVec.size(); idx++) {
				updateDetails->updateValues().push_back(dataValueVec[idx]);
			}

			// send read history request
			attributeService->syncSend(trx);

			// process read response
			statusCode = trx->statusCode();
			if (statusCode != Success) {
				std::stringstream ss;
				ss << "write history error: "
				   << " Session=" << commandWriteH->session()
				   << " StatusCode=" << OpcUaStatusCodeMap::shortString(statusCode);
				errorMessage(ss.str());
				return false;
			}

			HistoryUpdateResponse::SPtr res = trx->response();
			if (res->results()->size() != 1) {
				std::stringstream ss;
				ss << "write history response length error: "
				   << " Session=" << commandWriteH->session();
				errorMessage(ss.str());
				return false;
			}

			HistoryUpdateResult::SPtr historyUpdateResult;
			res->results()->get(0, historyUpdateResult);
			if (historyUpdateResult->statusCode() != Success) {
				std::stringstream ss;
				ss << "write history result error: "
				   << " Session=" << commandWriteH->session()
				   << " StatusCode=" << OpcUaStatusCodeMap::shortString(historyUpdateResult->statusCode());
				errorMessage(ss.str());
				return false;
			}
		}

		closeCSVFile();

		return true;
	}

	bool
	ClientServiceWriteH::openCSVFile(const std::string& fileName)
	{
		// open csv file
		Log(Debug, "read csv file")
		    .parameter("CSVFileName", fileName);

		csv_ = boost::make_shared<CSV>();
		bool success = csv_->open(fileName, CSV::M_Read);
		if (!success) {
			Log(Error, "open csv file error")
				.parameter("CSVFileName", fileName);
			return false;
		}

		return true;
	}

	bool
	ClientServiceWriteH::closeCSVFile(void)
	{
		csv_->close();
		csv_.reset();
		return true;
	}

	bool
	ClientServiceWriteH::readCSVLines(const std::string& fileName, OpcUaBuildInType valueType, OpcUaDataValue::Vec& dataValueVec)
	{
		uint32_t maxValues = MAXValuesPerRequest;
		CSV::Line line;
		while (maxValues > 0) {
			maxValues--;

			line.clear();
			CSV::State state = csv_->readLine(line);
			if (state == CSV::S_EndOfFile) {
				return true;
			}
			if (state != CSV::S_Ok) {
				Log(Error, "csv file error")
					.parameter("CSVFileName", fileName)
					.parameter("LineNumber", csv_->lineNumber());
				return false;
			}

			//
			// create new data value entry
			//
			OpcUaDataValue::SPtr dataValue = boost::make_shared<OpcUaDataValue>();
			dataValueVec.push_back(dataValue);

			// read status code
			try {
				uint32_t statusCode = boost::lexical_cast<uint32_t>(line[0]);
				dataValue->statusCode((OpcUaStatusCode)statusCode);
			} catch(...)
			{
				Log(Error, "status code error in csv file")
					.parameter("CSVFileName", fileName)
					.parameter("LineNumber", csv_->lineNumber());
				return false;
			}

			// read variable
			if (line[1] != "---") {
				bool isArray = false;
				if (line[1][0] == '[') {
					isArray = true;
				}

				OpcUaVariant variant;
				if (!dataValue->variant()->fromString(valueType, isArray, line[1])) {
					Log(Error, "variable error in csv file")
						.parameter("CSVFileName", fileName)
						.parameter("LineNumber", csv_->lineNumber());
					return false;
				}
			}

			// read source timestamp
			if (line[2] != "---") {
				if (!dataValue->sourceTimestamp().fromISOString(line[2])) {
					Log(Error, "source timestamp error in csv file")
						.parameter("CSVFileName", fileName)
						.parameter("LineNumber", csv_->lineNumber());
					return false;
				}
			}

			// read server timestamp
			if (line[3] != "---") {
				if (!dataValue->serverTimestamp().fromISOString(line[3])) {
					Log(Error, "server timestamp error in csv file")
						.parameter("CSVFileName", fileName)
						.parameter("LineNumber", csv_->lineNumber());
					return false;
				}
			}

			//dataValue->out(std::cout); std::cout << std::endl;
		}
		return true;
	}

}

