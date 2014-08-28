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
	, responseHeaderSPtr_(ResponseHeader::construct())
	, resultArraySPtr_(HistoryReadResultArray::construct())
	, diagnosticInfoArraySPtr_(OpcUaDiagnosticInfoArray::construct())
	{
	}

	HistoryReadResponse::~HistoryReadResponse(void)
	{
	}

	void 
	HistoryReadResponse::responseHeader(const ResponseHeader::SPtr responseHeaderSPtr)
	{
		responseHeaderSPtr_ = responseHeaderSPtr;
	}

	ResponseHeader::SPtr 
	HistoryReadResponse::responseHeader(void) const
	{
		return responseHeaderSPtr_;
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

	void 
	HistoryReadResponse::opcUaBinaryEncode(std::ostream& os) const
	{
		responseHeaderSPtr_->opcUaBinaryEncode(os);
		resultArraySPtr_->opcUaBinaryEncode(os);
		diagnosticInfoArraySPtr_->opcUaBinaryEncode(os);
	}
	
	void 
	HistoryReadResponse::opcUaBinaryDecode(std::istream& is)
	{
		responseHeaderSPtr_->opcUaBinaryDecode(is);
		resultArraySPtr_->opcUaBinaryDecode(is);
		diagnosticInfoArraySPtr_->opcUaBinaryDecode(is);
	}

}