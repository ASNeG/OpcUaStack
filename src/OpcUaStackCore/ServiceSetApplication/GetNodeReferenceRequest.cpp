#include "OpcUaStackCore/ServiceSetApplication/GetNodeReferenceRequest.h"

namespace OpcUaStackCore
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// OpcUa GetNodeReferenceRequest
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------

	GetNodeReferenceRequest::GetNodeReferenceRequest(void)
	: ObjectPool<GetNodeReferenceRequest>()
	, nodes_(OpcUaNodeIdArray::construct())
	{
	}

	GetNodeReferenceRequest::~GetNodeReferenceRequest(void)
	{
	}

	void 
	GetNodeReferenceRequest::nodes(const OpcUaNodeIdArray::SPtr nodes)
	{
		nodes_ = nodes;
	}
	
	OpcUaNodeIdArray::SPtr 
	GetNodeReferenceRequest::nodes(void) const
	{
		return nodes_;
	}

	void 
	GetNodeReferenceRequest::opcUaBinaryEncode(std::ostream& os) const
	{
		nodes_->opcUaBinaryEncode(os);
	}
	
	void 
	GetNodeReferenceRequest::opcUaBinaryDecode(std::istream& is)
	{
		nodes_->opcUaBinaryDecode(is);
	}


}
