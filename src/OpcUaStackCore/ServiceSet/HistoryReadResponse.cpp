#include "OpcUaStackCore/ServiceSet/HistoryReadResponse.h"

namespace OpcUaStackCore
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// OpcUa HistoryReadResponse
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------

	HistoryReadResponse::HistoryReadResponse(void)
	: ObjectPool<HistoryReadResponse>()
	, resultArraySPtr_(HistoryReadResultArray::construct())
	, diagnosticInfoArraySPtr_(OpcUaDiagnosticInfoArray::construct())
	{
	}

	HistoryReadResponse::~HistoryReadResponse(void)
	{
	}

	void 
	HistoryReadResponse::results(const HistoryReadResultArray::SPtr results)
	{
		resultArraySPtr_ = results;
	}
	
	HistoryReadResultArray::SPtr 
	HistoryReadResponse::results(void) const
	{
		return resultArraySPtr_;
	}

	void 
	HistoryReadResponse::diagnosticInfos(const OpcUaDiagnosticInfoArray::SPtr diagnosticInfoArraySPtr)
	{
		diagnosticInfoArraySPtr_ = diagnosticInfoArraySPtr;
	}

	OpcUaDiagnosticInfoArray::SPtr 
	HistoryReadResponse::diagnosticInfos(void) const
	{
		return diagnosticInfoArraySPtr_;
	}

	bool 
	HistoryReadResponse::opcUaBinaryEncode(std::ostream& os) const
	{
		resultArraySPtr_->opcUaBinaryEncode(os);
		diagnosticInfoArraySPtr_->opcUaBinaryEncode(os);
		return true;
	}
	
	bool 
	HistoryReadResponse::opcUaBinaryDecode(std::istream& is)
	{
		resultArraySPtr_->opcUaBinaryDecode(is);
		diagnosticInfoArraySPtr_->opcUaBinaryDecode(is);
		return true;
	}

}