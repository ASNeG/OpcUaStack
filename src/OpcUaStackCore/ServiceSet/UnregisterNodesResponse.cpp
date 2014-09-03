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
	, responseHeaderSPtr_(ResponseHeader::construct())
	{
	}

	UnregisterNodesResponse::~UnregisterNodesResponse(void)
	{
	}

	void 
	UnregisterNodesResponse::responseHeader(const ResponseHeader::SPtr responseHeader)
	{
		responseHeaderSPtr_ = responseHeader;
	}

	ResponseHeader::SPtr 
	UnregisterNodesResponse::responseHeader(void) const
	{
		return responseHeaderSPtr_;
	}

	void 
	UnregisterNodesResponse::opcUaBinaryEncode(std::ostream& os) const
	{
		responseHeaderSPtr_->opcUaBinaryEncode(os);
	}
	
	void 
	UnregisterNodesResponse::opcUaBinaryDecode(std::istream& is)
	{
		responseHeaderSPtr_->opcUaBinaryDecode(is);
	}
}