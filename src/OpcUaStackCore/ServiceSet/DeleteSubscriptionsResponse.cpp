#include "OpcUaStackCore/ServiceSet/DeleteSubscriptionsResponse.h"

namespace OpcUaStackCore
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// OpcUa DeleteSubscriptionsResponse
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------

	DeleteSubscriptionsResponse::DeleteSubscriptionsResponse(void)
	: ObjectPool<DeleteSubscriptionsResponse>()
	, responseHeaderSPtr_(ResponseHeader::construct())
	, statusCodeArraySPtr_(OpcUaStatusCodeArray::construct())
	, diagnosticInfoArraySPtr_(OpcUaDiagnosticInfoArray::construct())
	{
	}

	DeleteSubscriptionsResponse::~DeleteSubscriptionsResponse(void)
	{
	}

	void 
	DeleteSubscriptionsResponse::responseHeader(const ResponseHeader::SPtr responseHeader)
	{
		responseHeaderSPtr_ = responseHeader;
	}

	ResponseHeader::SPtr 
	DeleteSubscriptionsResponse::responseHeader(void) const
	{
		return responseHeaderSPtr_;
	}

	void 
	DeleteSubscriptionsResponse::results(const OpcUaStatusCodeArray::SPtr results)
	{
		statusCodeArraySPtr_ = results;
	}
	
	OpcUaStatusCodeArray::SPtr 
	DeleteSubscriptionsResponse::results(void) const
	{
		return statusCodeArraySPtr_;
	}
	
	void 
	DeleteSubscriptionsResponse::diagnosticInfos(const OpcUaDiagnosticInfoArray::SPtr diagnosticInfos)
	{
		diagnosticInfoArraySPtr_ = diagnosticInfos;
	}

	OpcUaDiagnosticInfoArray::SPtr 
	DeleteSubscriptionsResponse::diagnosticInfos(void) const
	{
		return diagnosticInfoArraySPtr_;
	}

	void 
	DeleteSubscriptionsResponse::opcUaBinaryEncode(std::ostream& os) const
	{
		responseHeaderSPtr_->opcUaBinaryEncode(os);
		statusCodeArraySPtr_->opcUaBinaryEncode(os);
		diagnosticInfoArraySPtr_->opcUaBinaryEncode(os);
	}
	
	void 
	DeleteSubscriptionsResponse::opcUaBinaryDecode(std::istream& is)
	{
		responseHeaderSPtr_->opcUaBinaryDecode(is);
		statusCodeArraySPtr_->opcUaBinaryDecode(is);
		diagnosticInfoArraySPtr_->opcUaBinaryDecode(is);
	}
}