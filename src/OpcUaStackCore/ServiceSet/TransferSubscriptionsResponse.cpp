#include "OpcUaStackCore/ServiceSet/TransferSubscriptionsResponse.h"

namespace OpcUaStackCore
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// OpcUa TransferSubscriptionsResponse
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------

	TransferSubscriptionsResponse::TransferSubscriptionsResponse(void)
	: ObjectPool<TransferSubscriptionsResponse>()
	, transferResultArraySPtr_(TransferResultArray::construct())
	, diagnosticInfoArraySPtr_(OpcUaDiagnosticInfoArray::construct())
	{
	}

	TransferSubscriptionsResponse::~TransferSubscriptionsResponse(void)
	{
	}

	void 
	TransferSubscriptionsResponse::results(const TransferResultArray::SPtr results)
	{
		transferResultArraySPtr_ = results;
	}
	
	TransferResultArray::SPtr 
	TransferSubscriptionsResponse::results(void) const
	{
		return transferResultArraySPtr_;
	}
		
	void 
	TransferSubscriptionsResponse::diagnosticInfos(const OpcUaDiagnosticInfoArray::SPtr diagnosticInfos)
	{
		diagnosticInfoArraySPtr_ = diagnosticInfos;
	}

	OpcUaDiagnosticInfoArray::SPtr 
	TransferSubscriptionsResponse::diagnosticInfos(void) const
	{
		return diagnosticInfoArraySPtr_;
	}

	void 
	TransferSubscriptionsResponse::opcUaBinaryEncode(std::ostream& os) const
	{
		transferResultArraySPtr_->opcUaBinaryEncode(os);
		diagnosticInfoArraySPtr_->opcUaBinaryEncode(os);
	}
	
	void 
	TransferSubscriptionsResponse::opcUaBinaryDecode(std::istream& is)
	{
		transferResultArraySPtr_->opcUaBinaryDecode(is);
		diagnosticInfoArraySPtr_->opcUaBinaryDecode(is);
	}
}