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
	, nodeReferenceArray_(NodeReferenceArray::construct())
	{
	}

	GetNodeReferenceResponse::~GetNodeReferenceResponse(void)
	{
	}

	void 
	GetNodeReferenceResponse::nodeReferenceArray(const NodeReferenceArray::SPtr nodeReferenceArray)
	{
		nodeReferenceArray_ = nodeReferenceArray;
	}
	
	NodeReferenceArray::SPtr
	GetNodeReferenceResponse::nodeReferenceArray(void) const
	{
		return nodeReferenceArray_;
	}

	void 
	GetNodeReferenceResponse::opcUaBinaryEncode(std::ostream& os) const
	{
		//nodeReferenceArray_->opcUaBinaryEncode(os);
	}
	
	void 
	GetNodeReferenceResponse::opcUaBinaryDecode(std::istream& is)
	{
		//nodeReferenceArray_->opcUaBinaryDecode(is);
	}
}
