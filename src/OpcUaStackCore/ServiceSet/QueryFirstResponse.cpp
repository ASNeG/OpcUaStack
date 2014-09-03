#include "OpcUaStackCore/ServiceSet/QueryFirstResponse.h"

namespace OpcUaStackCore
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// OpcUa QueryFirstResponse
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------

	QueryFirstResponse::QueryFirstResponse(void)
	: ObjectPool<QueryFirstResponse>()
	, responseHeaderSPtr_(ResponseHeader::construct())
	, queryDataSetArraySPtr_(QueryDataSetArray::construct())
	, continuationPoint_()
	, parsingResultArraySPtr_(ParsingResultArray::construct())
	, diagnosticInfoArraySPtr_(OpcUaDiagnosticInfoArray::construct())
	, filterResult_()
	{
	}

	QueryFirstResponse::~QueryFirstResponse(void)
	{
	}

	void 
	QueryFirstResponse::responseHeader(const ResponseHeader::SPtr responseHeader)
	{
		responseHeaderSPtr_ = responseHeader;
	}

	ResponseHeader::SPtr 
	QueryFirstResponse::responseHeader(void) const
	{
		return responseHeaderSPtr_;
	}


	void 
	QueryFirstResponse::queryDataSets(const QueryDataSetArray::SPtr queryDataSets)
	{
		queryDataSetArraySPtr_ = queryDataSets;
	}
	
	QueryDataSetArray::SPtr 
	QueryFirstResponse::queryDataSets(void) const
	{
		return queryDataSetArraySPtr_;
	}
	
	void 
	QueryFirstResponse::continuationPoint(const OpcUaByteString& continuationPoint)
	{
		continuationPoint_ = continuationPoint;
	}
	
	OpcUaByteString& 
	QueryFirstResponse::continuationPoint(void)
	{
		return continuationPoint_;
	}
	
	void 
	QueryFirstResponse::parsingResults(const ParsingResultArray::SPtr parsingResults)
	{
		parsingResultArraySPtr_ = parsingResults;
	}
	
	ParsingResultArray::SPtr 
	QueryFirstResponse::parsingResults(void) const
	{
		return parsingResultArraySPtr_;
	}
		
	void 
	QueryFirstResponse::diagnosticInfos(const OpcUaDiagnosticInfoArray::SPtr diagnosticInfos)
	{
		diagnosticInfoArraySPtr_ = diagnosticInfos;
	}

	OpcUaDiagnosticInfoArray::SPtr 
	QueryFirstResponse::diagnosticInfos(void) const
	{
		return diagnosticInfoArraySPtr_;
	}

	void 
	QueryFirstResponse::filterResult(const ContentFilterResult& filterResult)
	{
		filterResult_ = filterResult;
	}
	
	ContentFilterResult& 
	QueryFirstResponse::filterResult(void)
	{
		return filterResult_;
	}
	
	void 
	QueryFirstResponse::opcUaBinaryEncode(std::ostream& os) const
	{
		responseHeaderSPtr_->opcUaBinaryEncode(os);
		queryDataSetArraySPtr_->opcUaBinaryEncode(os);
		continuationPoint_.opcUaBinaryEncode(os);
		parsingResultArraySPtr_->opcUaBinaryEncode(os);
		diagnosticInfoArraySPtr_->opcUaBinaryEncode(os);
		filterResult_.opcUaBinaryEncode(os);
	}
	
	void 
	QueryFirstResponse::opcUaBinaryDecode(std::istream& is)
	{
		responseHeaderSPtr_->opcUaBinaryDecode(is);
		queryDataSetArraySPtr_->opcUaBinaryDecode(is);
		continuationPoint_.opcUaBinaryDecode(is);
		parsingResultArraySPtr_->opcUaBinaryDecode(is);
		diagnosticInfoArraySPtr_->opcUaBinaryDecode(is);
		filterResult_.opcUaBinaryDecode(is);
	}
}