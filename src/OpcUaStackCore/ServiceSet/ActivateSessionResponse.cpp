#include "OpcUaStackCore/ServiceSet/ActivateSessionResponse.h"

namespace OpcUaStackCore
{

	ActivateSessionResponse::ActivateSessionResponse(void)
	: responseHeader_()
	, serverNonce_()
	, results_()
	, diagnosticInfos_()
	{
	}

	ActivateSessionResponse::~ActivateSessionResponse(void)
	{
	}

	void 
	ActivateSessionResponse::responseHeader(const ResponseHeader::SPtr requestHeader)
	{
		responseHeader_ = requestHeader;
	}

	ResponseHeader::SPtr 
	ActivateSessionResponse::responseHeader(void) const
	{
		return responseHeader_;
	}

	void 
	ActivateSessionResponse::serverNonce(const OpcUaByte* buf, OpcUaInt32 bufLen)
	{
		serverNonce_.value(buf, bufLen);
	}

	void 
	ActivateSessionResponse::serverNonce(OpcUaByte** buf, OpcUaInt32* bufLen)
	{
		serverNonce_.value(buf, bufLen);
	}

	void 
	ActivateSessionResponse::results(const OpcUaStatusCodeArray::SPtr results)
	{
		results_ = results;
	}

	OpcUaStatusCodeArray::SPtr 
	ActivateSessionResponse::results(void) const
	{
		return results_;
	}

	void 
	ActivateSessionResponse::diagnosticInfos(const OpcUaDiagnosticInfoArray::SPtr diagnosticInfos)
	{
		diagnosticInfos_ = diagnosticInfos;
	}

	OpcUaDiagnosticInfoArray::SPtr 
	ActivateSessionResponse::diagnosticInfos(void) const
	{
		return diagnosticInfos_;
	}

	void 
	ActivateSessionResponse::opcUaBinaryEncode(std::ostream& os) const
	{
		responseHeader_->opcUaBinaryEncode(os);
		serverNonce_.opcUaBinaryEncode(os);
		results_->opcUaBinaryEncode(os);
		diagnosticInfos_->opcUaBinaryEncode(os);
	}

	void 
	ActivateSessionResponse::opcUaBinaryDecode(std::istream& is)
	{
		responseHeader_->opcUaBinaryDecode(is);
		serverNonce_.opcUaBinaryDecode(is);
		results_->opcUaBinaryDecode(is);
		diagnosticInfos_->opcUaBinaryDecode(is);
	}

}