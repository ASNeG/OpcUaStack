#include "OpcUaStackCore/ServiceSetApplication/RegisterForwardResponse.h"

namespace OpcUaStackCore
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// OpcUa RegisterForwardResponse
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------

	RegisterForwardResponse::RegisterForwardResponse(void)
	: ObjectPool<RegisterForwardResponse>()
	, statusCodeArraySPtr_(OpcUaStatusCodeArray::construct())
	{
	}

	RegisterForwardResponse::~RegisterForwardResponse(void)
	{
	}

	void 
	RegisterForwardResponse::statusCodeArray(const OpcUaStatusCodeArray::SPtr statusCodeArray)
	{
		statusCodeArraySPtr_ = statusCodeArray;
	}
	
	OpcUaStatusCodeArray::SPtr
	RegisterForwardResponse::statusCodeArray(void) const
	{
		return statusCodeArraySPtr_;
	}

	void 
	RegisterForwardResponse::opcUaBinaryEncode(std::ostream& os) const
	{
		statusCodeArraySPtr_->opcUaBinaryEncode(os);
	}
	
	void 
	RegisterForwardResponse::opcUaBinaryDecode(std::istream& is)
	{
		statusCodeArraySPtr_->opcUaBinaryDecode(is);
	}
}
