#include "OpcUaStackCore/ServiceSet/UnregisterNodesRequest.h"

namespace OpcUaStackCore
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// OpcUa UnregisterNodesRequest
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------

	UnregisterNodesRequest::UnregisterNodesRequest(void)
	: ObjectPool<UnregisterNodesRequest>()
	, nodesToUnregisterArraySPtr_(OpcUaNodeIdArray::construct())
	{
	}

	UnregisterNodesRequest::~UnregisterNodesRequest(void)
	{
	}

	void 
	UnregisterNodesRequest::nodesToUnregister(const OpcUaNodeIdArray::SPtr nodesToUnregister)
	{
		nodesToUnregisterArraySPtr_ = nodesToUnregister;
	}
	
	OpcUaNodeIdArray::SPtr 
	UnregisterNodesRequest::nodesToUnregister(void) const
	{
		return nodesToUnregisterArraySPtr_;
	}

	void 
	UnregisterNodesRequest::opcUaBinaryEncode(std::ostream& os) const
	{
		nodesToUnregisterArraySPtr_->opcUaBinaryEncode(os);	
	}
	
	void 
	UnregisterNodesRequest::opcUaBinaryDecode(std::istream& is)
	{
		nodesToUnregisterArraySPtr_->opcUaBinaryDecode(is);
	}

}