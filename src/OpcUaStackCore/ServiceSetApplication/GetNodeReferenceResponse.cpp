#include "OpcUaStackCore/ServiceSetApplication/GetNodeReferenceResponse.h"

namespace OpcUaStackCore
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// OpcUa GetNodeReferenceResponse
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------

	GetNodeReferenceResponse::GetNodeReferenceResponse(void)
	: ObjectPool<GetNodeReferenceResponse>()
	, statusCodeArraySPtr_(OpcUaStatusCodeArray::construct())
	{
	}

	GetNodeReferenceResponse::~GetNodeReferenceResponse(void)
	{
	}

	void 
	GetNodeReferenceResponse::statusCodeArray(const OpcUaStatusCodeArray::SPtr statusCodeArray)
	{
		statusCodeArraySPtr_ = statusCodeArray;
	}
	
	OpcUaStatusCodeArray::SPtr
	GetNodeReferenceResponse::statusCodeArray(void) const
	{
		return statusCodeArraySPtr_;
	}

	void 
	GetNodeReferenceResponse::opcUaBinaryEncode(std::ostream& os) const
	{
		statusCodeArraySPtr_->opcUaBinaryEncode(os);
	}
	
	void 
	GetNodeReferenceResponse::opcUaBinaryDecode(std::istream& is)
	{
		statusCodeArraySPtr_->opcUaBinaryDecode(is);
	}
}
