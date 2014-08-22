#include "OpcUaStackCore/ServiceSet/ModifyMonitoredItemsResponse.h"

namespace OpcUaStackCore
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// OpcUa ModifyMonitoredItemsResponse
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------

	ModifyMonitoredItemsResponse::ModifyMonitoredItemsResponse(void)
	: ObjectPool<ModifyMonitoredItemsResponse>()
	, responseHeaderSPtr_(ResponseHeader::construct())
	, resultArraySPtr_(MonitoredItemModifyResultArray::construct())
	, diagnosticInfoArraySPtr_(OpcUaDiagnosticInfoArray::construct())
	{
	}

	ModifyMonitoredItemsResponse::~ModifyMonitoredItemsResponse(void)
	{
	}

	void 
	ModifyMonitoredItemsResponse::responseHeader(const ResponseHeader::SPtr responseHeader)
	{
		responseHeaderSPtr_ = responseHeader;
	}

	ResponseHeader::SPtr 
	ModifyMonitoredItemsResponse::responseHeader(void) const
	{
		return responseHeaderSPtr_;
	}

	void 
	ModifyMonitoredItemsResponse::results(const MonitoredItemModifyResultArray::SPtr results)
	{
		resultArraySPtr_ = results;
	}
	
	MonitoredItemModifyResultArray::SPtr 
	ModifyMonitoredItemsResponse::results(void) const
	{
		return resultArraySPtr_;
	}	
	
	void 
	ModifyMonitoredItemsResponse::diagnosticInfos(const OpcUaDiagnosticInfoArray::SPtr diagnosticInfos)
	{
		diagnosticInfoArraySPtr_ = diagnosticInfos;
	}
	
	OpcUaDiagnosticInfoArray::SPtr 
	ModifyMonitoredItemsResponse::diagnosticInfos(void) const
	{
		return diagnosticInfoArraySPtr_;
	}

	void 
	ModifyMonitoredItemsResponse::opcUaBinaryEncode(std::ostream& os) const
	{
		responseHeaderSPtr_->opcUaBinaryEncode(os);
		resultArraySPtr_->opcUaBinaryEncode(os);
		diagnosticInfoArraySPtr_->opcUaBinaryEncode(os);
	}
	
	void 
	ModifyMonitoredItemsResponse::opcUaBinaryDecode(std::istream& is)
	{
		responseHeaderSPtr_->opcUaBinaryDecode(is);
		resultArraySPtr_->opcUaBinaryDecode(is);
		diagnosticInfoArraySPtr_->opcUaBinaryDecode(is);
	}
}