#include "OpcUaStackCore/ServiceSet/UnregisterNodesResponse.h"

namespace OpcUaStackCore
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// OpcUa UnregisterNodesResponse
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	UnregisterNodesResponse::UnregisterNodesResponse(void)
	: ObjectPool<UnregisterNodesResponse>()
	{
	}

	UnregisterNodesResponse::~UnregisterNodesResponse(void)
	{
	}

	void 
	UnregisterNodesResponse::opcUaBinaryEncode(std::ostream& os) const
	{
	}
	
	void 
	UnregisterNodesResponse::opcUaBinaryDecode(std::istream& is)
	{
	}
}