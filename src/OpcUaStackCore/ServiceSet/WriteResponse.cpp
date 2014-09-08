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
	, statusCodeArraySPtr_(OpcUaStatusCodeArray::construct())
	, diagnosticInfoArraySPtr_(OpcUaDiagnosticInfoArray::construct())
	{
	}

	WriteResponse::~WriteResponse(void)
	{
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

	bool
	WriteResponse::opcUaBinaryEncode(std::ostream& os) const
	{
		statusCodeArraySPtr_->opcUaBinaryEncode(os);
		diagnosticInfoArraySPtr_->opcUaBinaryEncode(os);
		return true;
	}
	
	bool
	WriteResponse::opcUaBinaryDecode(std::istream& is)
	{
		statusCodeArraySPtr_->opcUaBinaryDecode(is);
		diagnosticInfoArraySPtr_->opcUaBinaryDecode(is);
		return true;
	}
}