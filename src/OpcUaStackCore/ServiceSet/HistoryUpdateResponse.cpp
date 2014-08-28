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
	, responseHeaderSPtr_(ResponseHeader::construct())
	, resultArraySPtr_(HistoryUpdateResultArray::construct())
	, diagnosticInfoArraySPtr_(OpcUaDiagnosticInfoArray::construct())
	{
	}

	HistoryUpdateResponse::~HistoryUpdateResponse(void)
	{
	}

	void 
	HistoryUpdateResponse::responseHeader(const ResponseHeader::SPtr responseHeaderSPtr)
	{
		responseHeaderSPtr_ = responseHeaderSPtr;
	}

	ResponseHeader::SPtr 
	HistoryUpdateResponse::responseHeader(void) const
	{
		return responseHeaderSPtr_;
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

	void 
	HistoryUpdateResponse::opcUaBinaryEncode(std::ostream& os) const
	{
		responseHeaderSPtr_->opcUaBinaryEncode(os);
		resultArraySPtr_->opcUaBinaryEncode(os);
		diagnosticInfoArraySPtr_->opcUaBinaryEncode(os);
	}
	
	void 
	HistoryUpdateResponse::opcUaBinaryDecode(std::istream& is)
	{
		responseHeaderSPtr_->opcUaBinaryDecode(is);
		resultArraySPtr_->opcUaBinaryDecode(is);
		diagnosticInfoArraySPtr_->opcUaBinaryDecode(is);
	}

}