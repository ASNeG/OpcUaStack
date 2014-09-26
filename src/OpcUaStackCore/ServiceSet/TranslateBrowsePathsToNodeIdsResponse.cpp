#include "OpcUaStackCore/ServiceSet/TranslateBrowsePathsToNodeIdsResponse.h"

namespace OpcUaStackCore
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// OpcUa TranslateBrowsePathsToNodeIdsResponse
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------

	TranslateBrowsePathsToNodeIdsResponse::TranslateBrowsePathsToNodeIdsResponse(void)
	: ObjectPool<TranslateBrowsePathsToNodeIdsResponse>()
	, resultArraySPtr_(BrowsePathResultArray::construct())
	, diagnosticInfoArraySPtr_(OpcUaDiagnosticInfoArray::construct())
	{
	}

	TranslateBrowsePathsToNodeIdsResponse::~TranslateBrowsePathsToNodeIdsResponse(void)
	{
	}

	void 
	TranslateBrowsePathsToNodeIdsResponse::results(const BrowsePathResultArray::SPtr results)
	{
		resultArraySPtr_ = results;
	}
	
	BrowsePathResultArray::SPtr 
	TranslateBrowsePathsToNodeIdsResponse::results(void) const
	{
		return resultArraySPtr_;
	}
	
	void 
	TranslateBrowsePathsToNodeIdsResponse::diagnosticInfos(const OpcUaDiagnosticInfoArray::SPtr diagnosticInfos)
	{
		diagnosticInfoArraySPtr_ = diagnosticInfos;
	}

	OpcUaDiagnosticInfoArray::SPtr 
	TranslateBrowsePathsToNodeIdsResponse::diagnosticInfos(void) const
	{
		return diagnosticInfoArraySPtr_;
	}

	void 
	TranslateBrowsePathsToNodeIdsResponse::opcUaBinaryEncode(std::ostream& os) const
	{
		resultArraySPtr_->opcUaBinaryEncode(os);
		diagnosticInfoArraySPtr_->opcUaBinaryEncode(os);
	}
	
	void 
	TranslateBrowsePathsToNodeIdsResponse::opcUaBinaryDecode(std::istream& is)
	{
		resultArraySPtr_->opcUaBinaryDecode(is);
		diagnosticInfoArraySPtr_->opcUaBinaryDecode(is);
	}
}