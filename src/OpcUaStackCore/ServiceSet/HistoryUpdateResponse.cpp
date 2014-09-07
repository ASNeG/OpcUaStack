#include "OpcUaStackCore/ServiceSet/HistoryUpdateResponse.h"

namespace OpcUaStackCore
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// OpcUa HistoryUpdateResponse
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------

	HistoryUpdateResponse::HistoryUpdateResponse(void)
	: ObjectPool<HistoryUpdateResponse>()
	, resultArraySPtr_(HistoryUpdateResultArray::construct())
	, diagnosticInfoArraySPtr_(OpcUaDiagnosticInfoArray::construct())
	{
	}

	HistoryUpdateResponse::~HistoryUpdateResponse(void)
	{
	}

	void 
	HistoryUpdateResponse::results(const HistoryUpdateResultArray::SPtr results)
	{
		resultArraySPtr_ = results;
	}
	
	HistoryUpdateResultArray::SPtr 
	HistoryUpdateResponse::results(void) const
	{
		return resultArraySPtr_;
	}

	void 
	HistoryUpdateResponse::diagnosticInfos(const OpcUaDiagnosticInfoArray::SPtr diagnosticInfoArraySPtr)
	{
		diagnosticInfoArraySPtr_ = diagnosticInfoArraySPtr;
	}

	OpcUaDiagnosticInfoArray::SPtr 
	HistoryUpdateResponse::diagnosticInfos(void) const
	{
		return diagnosticInfoArraySPtr_;
	}

	bool 
	HistoryUpdateResponse::opcUaBinaryEncode(std::ostream& os) const
	{
		resultArraySPtr_->opcUaBinaryEncode(os);
		diagnosticInfoArraySPtr_->opcUaBinaryEncode(os);
		return true;
	}
	
	bool 
	HistoryUpdateResponse::opcUaBinaryDecode(std::istream& is)
	{
		resultArraySPtr_->opcUaBinaryDecode(is);
		diagnosticInfoArraySPtr_->opcUaBinaryDecode(is);
		return true;
	}

}