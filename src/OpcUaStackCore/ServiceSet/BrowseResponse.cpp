#include "OpcUaStackCore/ServiceSet/BrowseResponse.h"

namespace OpcUaStackCore
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// OpcUa BrowseResponse
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------

	BrowseResponse::BrowseResponse(void)
	: ObjectPool<BrowseResponse>()
	, resultArraySPtr_(BrowseResultArray::construct())
	, diagnosticInfoArraySPtr_(OpcUaDiagnosticInfoArray::construct())
	{
	}

	BrowseResponse::~BrowseResponse(void)
	{
	}

	void 
	BrowseResponse::results(const BrowseResultArray::SPtr results)
	{
		resultArraySPtr_ = results;
	}
	
	BrowseResultArray::SPtr 
	BrowseResponse::results(void) const
	{
		return resultArraySPtr_;
	}
	
	void 
	BrowseResponse::diagnosticInfos(const OpcUaDiagnosticInfoArray::SPtr diagnosticInfos)
	{
		diagnosticInfoArraySPtr_ = diagnosticInfos;
	}

	OpcUaDiagnosticInfoArray::SPtr 
	BrowseResponse::diagnosticInfos(void) const
	{
		return diagnosticInfoArraySPtr_;
	}

	void 
	BrowseResponse::opcUaBinaryEncode(std::ostream& os) const
	{
		resultArraySPtr_->opcUaBinaryEncode(os);
		diagnosticInfoArraySPtr_->opcUaBinaryEncode(os);
	}
	
	void 
	BrowseResponse::opcUaBinaryDecode(std::istream& is)
	{
		resultArraySPtr_->opcUaBinaryDecode(is);
		diagnosticInfoArraySPtr_->opcUaBinaryDecode(is);
	}
}