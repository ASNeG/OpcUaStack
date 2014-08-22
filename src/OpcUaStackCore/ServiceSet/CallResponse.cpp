#include "OpcUaStackCore/ServiceSet/CallResponse.h"

namespace OpcUaStackCore
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// OpcUa CallResponse
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------

	CallResponse::CallResponse(void)
	: ObjectPool<CallResponse>()
	, responseHeaderSPtr_(ResponseHeader::construct())
	, callMethodResultArraySPtr_(CallMethodResultArray::construct())
	, diagnosticInfoArraySPtr_(OpcUaDiagnosticInfoArray::construct())
	{
	}

	CallResponse::~CallResponse(void)
	{
	}

	void 
	CallResponse::responseHeader(const ResponseHeader::SPtr responseHeader)
	{
		responseHeaderSPtr_ = responseHeader;
	}

	ResponseHeader::SPtr 
	CallResponse::responseHeader(void) const
	{
		return responseHeaderSPtr_;
	}

	void 
	CallResponse::results(const CallMethodResultArray::SPtr results)
	{
		callMethodResultArraySPtr_ = results;
	}
	
	CallMethodResultArray::SPtr 
	CallResponse::results(void) const
	{
		return callMethodResultArraySPtr_;
	}
	
	void 
	CallResponse::diagnosticInfos(const OpcUaDiagnosticInfoArray::SPtr diagnosticInfos)
	{
		diagnosticInfoArraySPtr_ = diagnosticInfos;
	}
	
	OpcUaDiagnosticInfoArray::SPtr 
	CallResponse::diagnosticInfos(void) const
	{
		return diagnosticInfoArraySPtr_;
	}

	void 
	CallResponse::opcUaBinaryEncode(std::ostream& os) const
	{
		responseHeaderSPtr_->opcUaBinaryEncode(os);
		callMethodResultArraySPtr_->opcUaBinaryEncode(os);
		diagnosticInfoArraySPtr_->opcUaBinaryEncode(os);
	}
	
	void 
	CallResponse::opcUaBinaryDecode(std::istream& is)
	{
		responseHeaderSPtr_->opcUaBinaryDecode(is);
		callMethodResultArraySPtr_->opcUaBinaryDecode(is);
		diagnosticInfoArraySPtr_->opcUaBinaryDecode(is);
	}
}