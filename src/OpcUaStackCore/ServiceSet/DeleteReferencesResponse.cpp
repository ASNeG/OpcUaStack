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
	: deleteReferencesResultArraySPtr_(DeleteReferencesResultArray::construct())
	, diagnosticInfoArraySPtr_(OpcUaDiagnosticInfoArray::construct())
	{
	}

	DeleteReferencesResponse::~DeleteReferencesResponse(void)
	{
	}

	void
	DeleteReferencesResponse::results(const DeleteReferencesResultArray::SPtr deleteReferencesResultArraySPtr)
	{
		deleteReferencesResultArraySPtr_ = deleteReferencesResultArraySPtr;
	}

	DeleteReferencesResultArray::SPtr
	DeleteReferencesResponse::results() const
	{
		return deleteReferencesResultArraySPtr_;
	}


	void
	DeleteReferencesResponse::diagnosticInfos(const OpcUaDiagnosticInfoArray::SPtr diagnosticInfosSPtr)
	{
		diagnosticInfoArraySPtr_ = diagnosticInfosSPtr;
	}

	OpcUaDiagnosticInfoArray::SPtr
	DeleteReferencesResponse::diagnosticInfos(void) const
	{
		return diagnosticInfoArraySPtr_;
	}
		

	void 
	DeleteReferencesResponse::opcUaBinaryEncode(std::ostream& os) const
	{
		deleteReferencesResultArraySPtr_->opcUaBinaryEncode(os);
		diagnosticInfoArraySPtr_->opcUaBinaryEncode(os);
	}
	
	void 
	DeleteReferencesResponse::opcUaBinaryDecode(std::istream& is)
	{
		deleteReferencesResultArraySPtr_->opcUaBinaryDecode(is);
		diagnosticInfoArraySPtr_->opcUaBinaryDecode(is);
	}

}