#include "OpcUaStackCore/ServiceSet/WriteResponse.h"

namespace OpcUaStackCore
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// OpcUa WriteResponse
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------

	WriteResponse::WriteResponse(void)
	: ObjectPool<WriteResponse>()
	, responseHeaderSPtr_(ResponseHeader::construct())
	, statusCodeArraySPtr_(OpcUaStatusCodeArray::construct())
	, diagnosticInfoArraySPtr_(OpcUaDiagnosticInfoArray::construct())
	{
	}

	WriteResponse::~WriteResponse(void)
	{
	}

	void 
	WriteResponse::responseHeader(const ResponseHeader::SPtr responseHeader)
	{
		responseHeaderSPtr_ = responseHeader;
	}

	ResponseHeader::SPtr 
	WriteResponse::responseHeader(void) const
	{
		return responseHeaderSPtr_;
	}

	void 
	WriteResponse::results(const OpcUaStatusCodeArray::SPtr statusCodes)
	{
		statusCodeArraySPtr_ = statusCodes;
	}

	OpcUaStatusCodeArray::SPtr 
	WriteResponse::results(void) const
	{
		return statusCodeArraySPtr_;
	}
	
	void 
	WriteResponse::diagnosticInfos(const OpcUaDiagnosticInfoArray::SPtr diagnosticInfos)
	{
		diagnosticInfoArraySPtr_ = diagnosticInfos;
	}

	OpcUaDiagnosticInfoArray::SPtr 
	WriteResponse::diagnosticInfos(void) const
	{
		return diagnosticInfoArraySPtr_;
	}

	void 
	WriteResponse::opcUaBinaryEncode(std::ostream& os) const
	{
		responseHeaderSPtr_->opcUaBinaryEncode(os);
		statusCodeArraySPtr_->opcUaBinaryEncode(os);
		diagnosticInfoArraySPtr_->opcUaBinaryEncode(os);
	}
	
	void 
	WriteResponse::opcUaBinaryDecode(std::istream& is)
	{
		responseHeaderSPtr_->opcUaBinaryDecode(is);
		statusCodeArraySPtr_->opcUaBinaryDecode(is);
		diagnosticInfoArraySPtr_->opcUaBinaryDecode(is);
	}
}