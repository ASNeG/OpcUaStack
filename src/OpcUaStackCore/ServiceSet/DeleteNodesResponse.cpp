#include "OpcUaStackCore/ServiceSet/DeleteNodesResponse.h"

namespace OpcUaStackCore
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// DeleteNodesResponse
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	DeleteNodesResponse::DeleteNodesResponse(void)
	: deleteNodesResultArraySPtr_(DeleteNodesResultArray::construct())
	, diagnosticInfoArraySPtr_(OpcUaDiagnosticInfoArray::construct())
	{
	}

	DeleteNodesResponse::~DeleteNodesResponse(void)
	{
	}

	void
	DeleteNodesResponse::results(
		const DeleteNodesResultArray::SPtr deleteNodesResultArraySPtr)
	{
		deleteNodesResultArraySPtr_ = deleteNodesResultArraySPtr;
	}

	DeleteNodesResultArray::SPtr
	DeleteNodesResponse::results() const
	{
		return deleteNodesResultArraySPtr_;
	}


	void
	DeleteNodesResponse::diagnosticInfos(const OpcUaDiagnosticInfoArray::SPtr diagnosticInfosSPtr)
	{
		diagnosticInfoArraySPtr_ = diagnosticInfosSPtr;
	}

	OpcUaDiagnosticInfoArray::SPtr
	DeleteNodesResponse::diagnosticInfos(void) const
	{
		return diagnosticInfoArraySPtr_;
	}
		

	void 
	DeleteNodesResponse::opcUaBinaryEncode(std::ostream& os) const
	{
		deleteNodesResultArraySPtr_->opcUaBinaryEncode(os);
		diagnosticInfoArraySPtr_->opcUaBinaryEncode(os);
	}
	
	void 
	DeleteNodesResponse::opcUaBinaryDecode(std::istream& is)
	{
		deleteNodesResultArraySPtr_->opcUaBinaryDecode(is);
		diagnosticInfoArraySPtr_->opcUaBinaryDecode(is);
	}

}