#include "OpcUaStackCore/ServiceSet/SetPublishingModeResponse.h"

namespace OpcUaStackCore
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// OpcUa SetPublishingModeResponse
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------

	SetPublishingModeResponse::SetPublishingModeResponse(void)
	: ObjectPool<SetPublishingModeResponse>()
	, responseHeaderSPtr_(ResponseHeader::construct())
	, statusCodeArraySPtr_(OpcUaStatusCodeArray::construct())
	, diagnosticInfoArraySPtr_(OpcUaDiagnosticInfoArray::construct())
	{
	}

	SetPublishingModeResponse::~SetPublishingModeResponse(void)
	{
	}

	void 
	SetPublishingModeResponse::responseHeader(const ResponseHeader::SPtr responseHeader)
	{
		responseHeaderSPtr_ = responseHeader;
	}

	ResponseHeader::SPtr 
	SetPublishingModeResponse::responseHeader(void) const
	{
		return responseHeaderSPtr_;
	}

	void 
	SetPublishingModeResponse::results(const OpcUaStatusCodeArray::SPtr results)
	{
		statusCodeArraySPtr_ = results;
	}
	
	OpcUaStatusCodeArray::SPtr 
	SetPublishingModeResponse::results(void) const
	{
		return statusCodeArraySPtr_;
	}
	
	void 
	SetPublishingModeResponse::diagnosticInfos(const OpcUaDiagnosticInfoArray::SPtr diagnosticInfos)
	{
		diagnosticInfoArraySPtr_ = diagnosticInfos;
	}

	OpcUaDiagnosticInfoArray::SPtr 
	SetPublishingModeResponse::diagnosticInfos(void) const
	{
		return diagnosticInfoArraySPtr_;
	}

	void 
	SetPublishingModeResponse::opcUaBinaryEncode(std::ostream& os) const
	{
		responseHeaderSPtr_->opcUaBinaryEncode(os);
		statusCodeArraySPtr_->opcUaBinaryEncode(os);
		diagnosticInfoArraySPtr_->opcUaBinaryEncode(os);
	}
	
	void 
	SetPublishingModeResponse::opcUaBinaryDecode(std::istream& is)
	{
		responseHeaderSPtr_->opcUaBinaryDecode(is);
		statusCodeArraySPtr_->opcUaBinaryDecode(is);
		diagnosticInfoArraySPtr_->opcUaBinaryDecode(is);
	}
}