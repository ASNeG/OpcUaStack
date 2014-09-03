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
	, responseHeaderSPtr_(ResponseHeader::construct())
	, registeredNodeIdArraySPtr_(OpcUaNodeIdArray::construct())
	{
	}

	RegisterNodesResponse::~RegisterNodesResponse(void)
	{
	}

	void 
	RegisterNodesResponse::responseHeader(const ResponseHeader::SPtr responseHeader)
	{
		responseHeaderSPtr_ = responseHeader;
	}

	ResponseHeader::SPtr 
	RegisterNodesResponse::responseHeader(void) const
	{
		return responseHeaderSPtr_;
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
		responseHeaderSPtr_->opcUaBinaryEncode(os);
		registeredNodeIdArraySPtr_->opcUaBinaryEncode(os);
	}
	
	void 
	RegisterNodesResponse::opcUaBinaryDecode(std::istream& is)
	{
		responseHeaderSPtr_->opcUaBinaryDecode(is);
		registeredNodeIdArraySPtr_->opcUaBinaryDecode(is);
	}
}