#include "OpcUaStackCore/ServiceSet/RegisterNodesResponse.h"

namespace OpcUaStackCore
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// OpcUa RegisterNodesResponse
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------

	RegisterNodesResponse::RegisterNodesResponse(void)
	: ObjectPool<RegisterNodesResponse>()
	, registeredNodeIdArraySPtr_(OpcUaNodeIdArray::construct())
	{
	}

	RegisterNodesResponse::~RegisterNodesResponse(void)
	{
	}

	void 
	RegisterNodesResponse::registeredNodeIds(const OpcUaNodeIdArray::SPtr registeredNodeIds)
	{
		registeredNodeIdArraySPtr_ = registeredNodeIds;
	}
	
	OpcUaNodeIdArray::SPtr 
	RegisterNodesResponse::registeredNodeIds(void) const
	{
		return registeredNodeIdArraySPtr_;
	}

	void 
	RegisterNodesResponse::opcUaBinaryEncode(std::ostream& os) const
	{
		registeredNodeIdArraySPtr_->opcUaBinaryEncode(os);
	}
	
	void 
	RegisterNodesResponse::opcUaBinaryDecode(std::istream& is)
	{
		registeredNodeIdArraySPtr_->opcUaBinaryDecode(is);
	}
}