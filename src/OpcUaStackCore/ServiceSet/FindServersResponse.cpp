#include "OpcUaStackCore/ServiceSet/FindServersResponse.h"

namespace OpcUaStackCore
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// OpcUa FindServersResponse
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------

	FindServersResponse::FindServersResponse(void)
	: ObjectPool<FindServersResponse>()
	, responseHeaderSPtr_(ResponseHeader::construct())
	, serverArraySPtr_(ApplicationDescriptionArray::construct())
	{
	}

	FindServersResponse::~FindServersResponse(void)
	{
	}

	void 
	FindServersResponse::responseHeader(const ResponseHeader::SPtr responseHeaderSPtr)
	{
		responseHeaderSPtr_ = responseHeaderSPtr;
	}

	ResponseHeader::SPtr 
	FindServersResponse::responseHeader(void) const
	{
		return responseHeaderSPtr_;
	}
	
	void 
	FindServersResponse::servers(const ApplicationDescriptionArray::SPtr servers)
	{
		serverArraySPtr_ = servers;
	}
	
	ApplicationDescriptionArray::SPtr 
	FindServersResponse::servers(void) const
	{
		return serverArraySPtr_;
	}

	void 
	FindServersResponse::opcUaBinaryEncode(std::ostream& os) const
	{
		responseHeaderSPtr_->opcUaBinaryEncode(os);
		serverArraySPtr_->opcUaBinaryEncode(os);
	}
	
	void 
	FindServersResponse::opcUaBinaryDecode(std::istream& is)
	{
		responseHeaderSPtr_->opcUaBinaryDecode(is);
		serverArraySPtr_->opcUaBinaryDecode(is);
	}

}