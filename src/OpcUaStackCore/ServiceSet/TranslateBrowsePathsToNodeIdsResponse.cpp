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
	, responseHeaderSPtr_(ResponseHeader::construct())
	, resultArraySPtr_(BrowsePathResultArray::construct())
	, diagnosticInfoArraySPtr_(OpcUaDiagnosticInfoArray::construct())
	{
	}

	TranslateBrowsePathsToNodeIdsResponse::~TranslateBrowsePathsToNodeIdsResponse(void)
	{
	}

	void 
	TranslateBrowsePathsToNodeIdsResponse::responseHeader(const ResponseHeader::SPtr responseHeader)
	{
		responseHeaderSPtr_ = responseHeader;
	}

	ResponseHeader::SPtr 
	TranslateBrowsePathsToNodeIdsResponse::responseHeader(void) const
	{
		return responseHeaderSPtr_;
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
		responseHeaderSPtr_->opcUaBinaryEncode(os);
		resultArraySPtr_->opcUaBinaryEncode(os);
		diagnosticInfoArraySPtr_->opcUaBinaryEncode(os);
	}
	
	void 
	TranslateBrowsePathsToNodeIdsResponse::opcUaBinaryDecode(std::istream& is)
	{
		responseHeaderSPtr_->opcUaBinaryDecode(is);
		resultArraySPtr_->opcUaBinaryDecode(is);
		diagnosticInfoArraySPtr_->opcUaBinaryDecode(is);
	}
}