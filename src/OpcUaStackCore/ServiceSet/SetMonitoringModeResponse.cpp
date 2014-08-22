#include "OpcUaStackCore/ServiceSet/SetMonitoringModeResponse.h"

namespace OpcUaStackCore
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// OpcUa SetMonitoringModeResponse
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------

	SetMonitoringModeResponse::SetMonitoringModeResponse(void)
	: ObjectPool<SetMonitoringModeResponse>()
	, responseHeaderSPtr_(ResponseHeader::construct())
	, resultArraySPtr_(OpcUaStatusCodeArray::construct())
	, diagnosticInfoArraySPtr_(OpcUaDiagnosticInfoArray::construct())
	{
	}

	SetMonitoringModeResponse::~SetMonitoringModeResponse(void)
	{
	}

	void 
	SetMonitoringModeResponse::responseHeader(const ResponseHeader::SPtr responseHeader)
	{
		responseHeaderSPtr_ = responseHeader;
	}

	ResponseHeader::SPtr 
	SetMonitoringModeResponse::responseHeader(void) const
	{
		return responseHeaderSPtr_;
	}

	void 
	SetMonitoringModeResponse::results(const OpcUaStatusCodeArray::SPtr results)
	{
		resultArraySPtr_ = results;
	}
	
	OpcUaStatusCodeArray::SPtr
	SetMonitoringModeResponse::results(void) const
	{
		return resultArraySPtr_;
	}	
	
	void 
	SetMonitoringModeResponse::diagnosticInfos(const OpcUaDiagnosticInfoArray::SPtr diagnosticInfos)
	{
		diagnosticInfoArraySPtr_ = diagnosticInfos;
	}
	
	OpcUaDiagnosticInfoArray::SPtr 
	SetMonitoringModeResponse::diagnosticInfos(void) const
	{
		return diagnosticInfoArraySPtr_;
	}

	void 
	SetMonitoringModeResponse::opcUaBinaryEncode(std::ostream& os) const
	{
		responseHeaderSPtr_->opcUaBinaryEncode(os);
		resultArraySPtr_->opcUaBinaryEncode(os);
		diagnosticInfoArraySPtr_->opcUaBinaryEncode(os);
	}
	
	void 
	SetMonitoringModeResponse::opcUaBinaryDecode(std::istream& is)
	{
		responseHeaderSPtr_->opcUaBinaryDecode(is);
		resultArraySPtr_->opcUaBinaryDecode(is);
		diagnosticInfoArraySPtr_->opcUaBinaryDecode(is);
	}
}