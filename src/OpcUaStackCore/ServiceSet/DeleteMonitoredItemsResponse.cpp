#include "OpcUaStackCore/ServiceSet/DeleteMonitoredItemsResponse.h"

namespace OpcUaStackCore
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// OpcUa DeleteMonitoredItemsResponse
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------

	DeleteMonitoredItemsResponse::DeleteMonitoredItemsResponse(void)
	: ObjectPool<DeleteMonitoredItemsResponse>()
	, responseHeaderSPtr_(ResponseHeader::construct())
	, resultArraySPtr_(OpcUaStatusCodeArray::construct())
	, diagnosticInfoArraySPtr_(OpcUaDiagnosticInfoArray::construct())
	{
	}

	DeleteMonitoredItemsResponse::~DeleteMonitoredItemsResponse(void)
	{
	}

	void 
	DeleteMonitoredItemsResponse::responseHeader(const ResponseHeader::SPtr responseHeader)
	{
		responseHeaderSPtr_ = responseHeader;
	}

	ResponseHeader::SPtr 
	DeleteMonitoredItemsResponse::responseHeader(void) const
	{
		return responseHeaderSPtr_;
	}

	void 
	DeleteMonitoredItemsResponse::results(const OpcUaStatusCodeArray::SPtr results)
	{
		resultArraySPtr_ = results;
	}
	
	OpcUaStatusCodeArray::SPtr
	DeleteMonitoredItemsResponse::results(void) const
	{
		return resultArraySPtr_;
	}	
	
	void 
	DeleteMonitoredItemsResponse::diagnosticInfos(const OpcUaDiagnosticInfoArray::SPtr diagnosticInfos)
	{
		diagnosticInfoArraySPtr_ = diagnosticInfos;
	}
	
	OpcUaDiagnosticInfoArray::SPtr 
	DeleteMonitoredItemsResponse::diagnosticInfos(void) const
	{
		return diagnosticInfoArraySPtr_;
	}

	void 
	DeleteMonitoredItemsResponse::opcUaBinaryEncode(std::ostream& os) const
	{
		responseHeaderSPtr_->opcUaBinaryEncode(os);
		resultArraySPtr_->opcUaBinaryEncode(os);
		diagnosticInfoArraySPtr_->opcUaBinaryEncode(os);
	}
	
	void 
	DeleteMonitoredItemsResponse::opcUaBinaryDecode(std::istream& is)
	{
		responseHeaderSPtr_->opcUaBinaryDecode(is);
		resultArraySPtr_->opcUaBinaryDecode(is);
		diagnosticInfoArraySPtr_->opcUaBinaryDecode(is);
	}
}