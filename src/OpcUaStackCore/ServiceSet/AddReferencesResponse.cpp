#include "OpcUaStackCore/ServiceSet/AddReferencesResponse.h"

namespace OpcUaStackCore
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// AddNodesResponse
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	AddReferencesResponse::AddReferencesResponse(void)
		: responseHeaderSPtr_(ResponseHeader::construct()),
		addReferencesResultArraySPtr_(AddReferencesResultArray::construct()),
		diagnosticInfoArraySPtr_(OpcUaDiagnosticInfoArray::construct())
	{
	}

	AddReferencesResponse::~AddReferencesResponse(void)
	{
	}

	void
	AddReferencesResponse::responseHeader(
		const ResponseHeader::SPtr responseHeaderSPtr)
	{
		responseHeaderSPtr_ = responseHeaderSPtr;
	}

	ResponseHeader::SPtr
	AddReferencesResponse::responseHeader(void) const
	{
		return responseHeaderSPtr_;
	}


	void
	AddReferencesResponse::results(
		const AddReferencesResultArray::SPtr addReferencesResultArraySPtr)
	{
		addReferencesResultArraySPtr_ = addReferencesResultArraySPtr;
	}

	AddReferencesResultArray::SPtr
	AddReferencesResponse::results() const
	{
		return addReferencesResultArraySPtr_;
	}


	void
	AddReferencesResponse::diagnosticInfos(
		const OpcUaDiagnosticInfoArray::SPtr diagnosticInfosSPtr)
	{
		diagnosticInfoArraySPtr_ = diagnosticInfosSPtr;
	}

	OpcUaDiagnosticInfoArray::SPtr
	AddReferencesResponse::diagnosticInfos(void) const
	{
		return diagnosticInfoArraySPtr_;
	}
		

	void 
	AddReferencesResponse::opcUaBinaryEncode(
		std::ostream& os) const
	{
		responseHeaderSPtr_->opcUaBinaryEncode(os);
		addReferencesResultArraySPtr_->opcUaBinaryEncode(os);
		diagnosticInfoArraySPtr_->opcUaBinaryEncode(os);
	}
	
	void 
	AddReferencesResponse::opcUaBinaryDecode(
		std::istream& is)
	{
		responseHeaderSPtr_->opcUaBinaryDecode(is);
		addReferencesResultArraySPtr_->opcUaBinaryDecode(is);
		diagnosticInfoArraySPtr_->opcUaBinaryDecode(is);
	}

}