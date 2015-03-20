#include "OpcUaStackCore/ServiceSet/RegisterForwardResponse.h"

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
	, registeredNodeIdArraySPtr_(OpcUaNodeIdArray::construct())
	{
	}

	RegisterForwardResponse::~RegisterForwardResponse(void)
	{
	}

	void 
	RegisterForwardResponse::registeredNodeIds(const OpcUaNodeIdArray::SPtr registeredNodeIds)
	{
		registeredNodeIdArraySPtr_ = registeredNodeIds;
	}
	
	OpcUaNodeIdArray::SPtr 
	RegisterForwardResponse::registeredNodeIds(void) const
	{
		return registeredNodeIdArraySPtr_;
	}

	void 
	RegisterForwardResponse::opcUaBinaryEncode(std::ostream& os) const
	{
		registeredNodeIdArraySPtr_->opcUaBinaryEncode(os);
	}
	
	void 
	RegisterForwardResponse::opcUaBinaryDecode(std::istream& is)
	{
		registeredNodeIdArraySPtr_->opcUaBinaryDecode(is);
	}
}
