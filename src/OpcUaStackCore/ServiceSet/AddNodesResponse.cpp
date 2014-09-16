#include "OpcUaStackCore/ServiceSet/AddNodesResponse.h"

namespace OpcUaStackCore
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// AddNodesResponse
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	AddNodesResponse::AddNodesResponse(void)
		: responseHeaderSPtr_(ResponseHeader::construct()),
		addNodesResultArraySPtr_(AddNodesResultArray::construct()),
		diagnosticInfoArraySPtr_(OpcUaDiagnosticInfoArray::construct())
	{
	}

	AddNodesResponse::~AddNodesResponse(void)
	{
	}

	void
	AddNodesResponse::responseHeader(
		const ResponseHeader::SPtr responseHeaderSPtr)
	{
		responseHeaderSPtr_ = responseHeaderSPtr;
	}

	ResponseHeader::SPtr
	AddNodesResponse::responseHeader(void) const
	{
		return responseHeaderSPtr_;
	}


	void
	AddNodesResponse::results(
		const AddNodesResultArray::SPtr addNodesResultArraySPtr)
	{
		addNodesResultArraySPtr_ = addNodesResultArraySPtr;
	}

	AddNodesResultArray::SPtr
	AddNodesResponse::results() const
	{
		return addNodesResultArraySPtr_;
	}


	void
	AddNodesResponse::diagnosticInfos(
		const OpcUaDiagnosticInfoArray::SPtr diagnosticInfosSPtr)
	{
		diagnosticInfoArraySPtr_ = diagnosticInfosSPtr;
	}

	OpcUaDiagnosticInfoArray::SPtr
	AddNodesResponse::diagnosticInfos(void) const
	{
		return diagnosticInfoArraySPtr_;
	}
		

	void 
	AddNodesResponse::opcUaBinaryEncode(
		std::ostream& os) const
	{
		responseHeaderSPtr_->opcUaBinaryEncode(os);
		addNodesResultArraySPtr_->opcUaBinaryEncode(os);
		diagnosticInfoArraySPtr_->opcUaBinaryEncode(os);
	}
	
	void 
	AddNodesResponse::opcUaBinaryDecode(
		std::istream& is)
	{
		responseHeaderSPtr_->opcUaBinaryDecode(is);
		addNodesResultArraySPtr_->opcUaBinaryDecode(is);
		diagnosticInfoArraySPtr_->opcUaBinaryDecode(is);
	}

}