#include "OpcUaStackCore/ServiceSet/BrowseNextResponse.h"

namespace OpcUaStackCore
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// OpcUa BrowseNextResponse
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------

	BrowseNextResponse::BrowseNextResponse(void)
	: ObjectPool<BrowseNextResponse>()
	, responseHeaderSPtr_(ResponseHeader::construct())
	, resultArraySPtr_(BrowseResultArray::construct())
	, diagnosticInfoArraySPtr_(OpcUaDiagnosticInfoArray::construct())
	{
	}

	BrowseNextResponse::~BrowseNextResponse(void)
	{
	}

	void 
	BrowseNextResponse::responseHeader(const ResponseHeader::SPtr responseHeader)
	{
		responseHeaderSPtr_ = responseHeader;
	}

	ResponseHeader::SPtr 
	BrowseNextResponse::responseHeader(void) const
	{
		return responseHeaderSPtr_;
	}

	void 
	BrowseNextResponse::results(const BrowseResultArray::SPtr results)
	{
		resultArraySPtr_ = results;
	}
	
	BrowseResultArray::SPtr 
	BrowseNextResponse::results(void) const
	{
		return resultArraySPtr_;
	}
	
	void 
	BrowseNextResponse::diagnosticInfos(const OpcUaDiagnosticInfoArray::SPtr diagnosticInfos)
	{
		diagnosticInfoArraySPtr_ = diagnosticInfos;
	}

	OpcUaDiagnosticInfoArray::SPtr 
	BrowseNextResponse::diagnosticInfos(void) const
	{
		return diagnosticInfoArraySPtr_;
	}

	void 
	BrowseNextResponse::opcUaBinaryEncode(std::ostream& os) const
	{
		responseHeaderSPtr_->opcUaBinaryEncode(os);
		resultArraySPtr_->opcUaBinaryEncode(os);
		diagnosticInfoArraySPtr_->opcUaBinaryEncode(os);
	}
	
	void 
	BrowseNextResponse::opcUaBinaryDecode(std::istream& is)
	{
		responseHeaderSPtr_->opcUaBinaryDecode(is);
		resultArraySPtr_->opcUaBinaryDecode(is);
		diagnosticInfoArraySPtr_->opcUaBinaryDecode(is);
	}
}