#include "OpcUaStackCore/ServiceSet/HistoryUpdateResult.h"

namespace OpcUaStackCore
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// OpcUa HistoryUpdateResult
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------

	HistoryUpdateResult::HistoryUpdateResult(void)
	: ObjectPool<HistoryUpdateResult>()
	, statusCode_()
	, operationResultArraySPtr_(OpcUaStatusCodeArray::construct())
	, diagnosticInfoArraySPtr_(OpcUaDiagnosticInfoArray::construct())
	{
	}

	HistoryUpdateResult::~HistoryUpdateResult(void)
	{
	}

	void 
	HistoryUpdateResult::statusCode(const OpcUaStatusCode& statusCode)
	{
		statusCode_ = statusCode;
	}
	
	OpcUaStatusCode& 
	HistoryUpdateResult::statusCode(void)
	{
		return statusCode_;
	}

	void 
	HistoryUpdateResult::operationResults(const OpcUaStatusCodeArray::SPtr operationResults)
	{
		operationResultArraySPtr_ = operationResults;
	}
	
	OpcUaStatusCodeArray::SPtr 
	HistoryUpdateResult::operationResults(void) const
	{
		return operationResultArraySPtr_;
	}
	
	void 
	HistoryUpdateResult::diagnosticInfos(const OpcUaDiagnosticInfoArray::SPtr diagnosticInfos)
	{
		diagnosticInfoArraySPtr_ = diagnosticInfos;
	}
	
	OpcUaDiagnosticInfoArray::SPtr 
	HistoryUpdateResult::diagnosticInfos(void) const
	{
		return diagnosticInfoArraySPtr_;
	}

	void 
	HistoryUpdateResult::opcUaBinaryEncode(std::ostream& os) const
	{
		OpcUaNumber::opcUaBinaryEncode(os, (OpcUaUInt32)statusCode_);
		operationResultArraySPtr_->opcUaBinaryEncode(os);
		diagnosticInfoArraySPtr_->opcUaBinaryEncode(os);
	}
	
	void 
	HistoryUpdateResult::opcUaBinaryDecode(std::istream& is)
	{
		OpcUaUInt32 tmp;
		OpcUaNumber::opcUaBinaryDecode(is, tmp);
		statusCode_ = (OpcUaStatusCode)tmp;
		operationResultArraySPtr_->opcUaBinaryDecode(is);
		diagnosticInfoArraySPtr_->opcUaBinaryDecode(is);
	}

}