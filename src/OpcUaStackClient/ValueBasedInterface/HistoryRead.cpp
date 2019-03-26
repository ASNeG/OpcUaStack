/*
   Copyright 2019 Kai Huebl (kai@huebl-sgh.de)

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

#include <boost/make_shared.hpp>
#include "OpcUaStackCore/Base/Log.h"
#include "OpcUaStackCore/StandardDataTypes/ReadRawModifiedDetails.h"
#include "OpcUaStackCore/StandardDataTypes/HistoryData.h"
#include "OpcUaStackClient/ValueBasedInterface/HistoryRead.h"

using namespace OpcUaStackCore;

namespace OpcUaStackClient
{

	HistoryRead::HistoryRead(void)
	: nodeId_()
	, startTime_()
	, endTime_()
	, resultHandler_()
	, dataValueVec_()
	, attributeService_()
	, cancel_(false)
	, releaseContinuationPoint_(false)
	, timestampToReturn_(TimestampsToReturn_Both)
	, maxNumResultValuesPerRequest_(0)
	, maxNumResultValuesPerNode_(0)
	, actNumResultValuesPerNode_(0)
	, continuationPoint_()
	{
	}

	HistoryRead::~HistoryRead(void)
	{
	}

	void
	HistoryRead::attributeService(AttributeService::SPtr& attributeService)
	{
		attributeService_ = attributeService;
	}

	void
	HistoryRead::maxNumResultValuesPerRequest(uint32_t maxNumResultValuesPerRequest)
	{
		maxNumResultValuesPerRequest_ = maxNumResultValuesPerRequest;
	}

	void
	HistoryRead::maxNumResultValuesPerNode(uint32_t maxNumResultValuesPerNode)
	{
		maxNumResultValuesPerNode_ = maxNumResultValuesPerNode;
	}

	OpcUaStatusCode
	HistoryRead::syncHistoryRead(
		const OpcUaNodeId& nodeId,
		boost::posix_time::ptime startTime,
		boost::posix_time::ptime endTime,
		OpcUaDataValue::Vec& dataValueVec
	)
	{
		// FIXME: todo
		return Success;
	}

	void
	HistoryRead::asyncHistoryRead(
		const OpcUaNodeId& nodeId,
		boost::posix_time::ptime startTime,
		boost::posix_time::ptime endTime,
		ResultHandler& resultHandler
	)
	{
		// set input parameter
		nodeId_ = nodeId;
		startTime_ = startTime;
		endTime_ = endTime;
		resultHandler_ = resultHandler;

		return asyncHistoryRead();
	}

	void
	HistoryRead::syncCancel(void)
	{
		// FIXME: todo
	}

	void
	HistoryRead::asyncCancel(void)
	{
		// FIXME: todo
	}

	void
	HistoryRead::asyncHistoryRead(void)
	{
		// check if next request can be sent.
		bool releaseContinuationPoints = false;
		if (maxNumResultValuesPerNode_ != 0) {
			if (actNumResultValuesPerNode_ >= maxNumResultValuesPerNode_) {
				releaseContinuationPoints = true;
			}
		}

		// calculate limits
		uint32_t limitValuesPerRequest = maxNumResultValuesPerRequest_;
		if (maxNumResultValuesPerNode_ != 0) {
			if (maxNumResultValuesPerNode_ > limitValuesPerRequest) {
				limitValuesPerRequest = maxNumResultValuesPerNode_;
			}
		}

		// create transaction
		auto trx = boost::make_shared<ServiceTransactionHistoryRead>();
		auto req = trx->request();

		// create request
		req->historyReadDetails()->parameterTypeId().set((OpcUaUInt32)OpcUaId_ReadRawModifiedDetails_Encoding_DefaultBinary);
		req->timestampsToReturn(timestampToReturn_);
		req->releaseContinuationPoints(releaseContinuationPoints);
		auto readDetails = req->historyReadDetails()->parameter<ReadRawModifiedDetails>();
		readDetails->startTime() = startTime_;
		readDetails->endTime() = endTime_;
		readDetails->numValuesPerNode() = limitValuesPerRequest;

		auto readValueId = boost::make_shared<HistoryReadValueId>();
		readValueId->nodeId(boost::make_shared<OpcUaNodeId>(nodeId_));
		readValueId->dataEncoding().namespaceIndex((OpcUaInt16) 0);
		if (continuationPoint_.exist()) {
			readValueId->continuationPoint(continuationPoint_);
		}

		req->nodesToRead()->resize(1);
		req->nodesToRead()->push_back(readValueId);

		// send historical read request to server
		trx->resultHandler(
			[this, releaseContinuationPoints](ServiceTransactionHistoryRead::SPtr& trx) {
				asyncHistoryReadComplete(releaseContinuationPoints, trx);
			}
		);
		attributeService_->asyncSend(trx);
	}

	void
	HistoryRead::asyncHistoryReadComplete(
		bool releaseContinuationPoints,
		ServiceTransactionHistoryRead::SPtr& trx
	)
	{
		// check result code
		if (trx->statusCode() != Success) {
			Log(Error, "historical read transaction error")
				.parameter("NodeId", nodeId_)
				.parameter("StatusCode", OpcUaStatusCodeMap::shortString(trx->statusCode()));
			resultHandler_(trx->statusCode(), dataValueVec_);
			return;
		}
		auto res = trx->response();
		if (res->results()->size() != 1) {
			Log(Error, "historical read result size error")
				.parameter("NodeId", nodeId_);
			resultHandler_(trx->statusCode(), dataValueVec_);
			return;
		}

		// handle response
		HistoryReadResult::SPtr readResult;
		res->results()->get(0, readResult);
		if (readResult->statusCode() != Success) {
			Log(Error, "historical read result error")
				.parameter("NodeId", nodeId_)
				.parameter("StatusCode", OpcUaStatusCodeMap::shortString(trx->statusCode()));
			resultHandler_(trx->statusCode(), dataValueVec_);
			return;
		}

		// read data values
		auto historyData = readResult->historyData()->parameter<HistoryData>();
		for (auto idx=0; idx<historyData->dataValues().size(); idx++) {
			OpcUaDataValue::SPtr dataValue;
			historyData->dataValues().get(idx, dataValue);
			dataValueVec_.push_back(dataValue);
		}
		actNumResultValuesPerNode_ += historyData->dataValues().size();

		// read continuation point
		continuationPoint_.reset();
		if (readResult->continuationPoint().exist() && readResult->continuationPoint().size() > 0) {
			continuationPoint_ = readResult->continuationPoint();
		}

		// continuation point not exist - answer inquiry
		if (!continuationPoint_.exist() || releaseContinuationPoints) {
			resultHandler_(Success, dataValueVec_);
			return;
		}

		asyncHistoryRead();
	}

}
