#include "OpcUaStackCore/ServiceSet/RegisterServerRequest.h"

namespace OpcUaStackCore
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// OpcUa RegisterServerRequest
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------

	RegisterServerRequest::RegisterServerRequest(void)
	: ObjectPool<RegisterServerRequest>()
	, requestHeaderSPtr_(RequestHeader::construct())
	, server_()
	{
	}

	RegisterServerRequest::~RegisterServerRequest(void)
	{
	}

	void 
	RegisterServerRequest::requestHeader(const RequestHeader::SPtr requestHeaderSPtr)
	{
		requestHeaderSPtr_ = requestHeaderSPtr;
	}

	RequestHeader::SPtr 
	RegisterServerRequest::requestHeader(void) const
	{
		return requestHeaderSPtr_;
	}

	void 
	RegisterServerRequest::server(const RegisteredServer& server)
	{
		server_ = server;
	}
	
	RegisteredServer& 
	RegisterServerRequest::server(void)
	{
		return server_;
	}

	void 
	RegisterServerRequest::opcUaBinaryEncode(std::ostream& os) const
	{
		requestHeaderSPtr_->opcUaBinaryEncode(os);
		server_.opcUaBinaryEncode(os);
	}
	
	void 
	RegisterServerRequest::opcUaBinaryDecode(std::istream& is)
	{
		requestHeaderSPtr_->opcUaBinaryDecode(is);
		server_.opcUaBinaryDecode(is);
	}

}