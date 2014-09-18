#include "OpcUaStackCore/ServiceSet/DeleteReferencesResponse.h"

namespace OpcUaStackCore
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// DeleteReferencesResponse
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	DeleteReferencesResponse::DeleteReferencesResponse(void)
		: responseHeaderSPtr_(ResponseHeader::construct()),
		deleteReferencesResultArraySPtr_(DeleteReferencesResultArray::construct()),
		diagnosticInfoArraySPtr_(OpcUaDiagnosticInfoArray::construct())
	{
	}

	DeleteReferencesResponse::~DeleteReferencesResponse(void)
	{
	}

	void
	DeleteReferencesResponse::responseHeader(
		const ResponseHeader::SPtr responseHeaderSPtr)
	{
		responseHeaderSPtr_ = responseHeaderSPtr;
	}

	ResponseHeader::SPtr
	DeleteReferencesResponse::responseHeader(void) const
	{
		return responseHeaderSPtr_;
	}


	void
	DeleteReferencesResponse::results(
		const DeleteReferencesResultArray::SPtr deleteReferencesResultArraySPtr)
	{
		deleteReferencesResultArraySPtr_ = deleteReferencesResultArraySPtr;
	}

	DeleteReferencesResultArray::SPtr
	DeleteReferencesResponse::results() const
	{
		return deleteReferencesResultArraySPtr_;
	}


	void
	DeleteReferencesResponse::diagnosticInfos(
		const OpcUaDiagnosticInfoArray::SPtr diagnosticInfosSPtr)
	{
		diagnosticInfoArraySPtr_ = diagnosticInfosSPtr;
	}

	OpcUaDiagnosticInfoArray::SPtr
	DeleteReferencesResponse::diagnosticInfos(void) const
	{
		return diagnosticInfoArraySPtr_;
	}
		

	void 
	DeleteReferencesResponse::opcUaBinaryEncode(
		std::ostream& os) const
	{
		responseHeaderSPtr_->opcUaBinaryEncode(os);
		deleteReferencesResultArraySPtr_->opcUaBinaryEncode(os);
		diagnosticInfoArraySPtr_->opcUaBinaryEncode(os);
	}
	
	void 
	DeleteReferencesResponse::opcUaBinaryDecode(
		std::istream& is)
	{
		responseHeaderSPtr_->opcUaBinaryDecode(is);
		deleteReferencesResultArraySPtr_->opcUaBinaryDecode(is);
		diagnosticInfoArraySPtr_->opcUaBinaryDecode(is);
	}

}