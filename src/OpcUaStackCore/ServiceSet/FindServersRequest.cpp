#include "OpcUaStackCore/ServiceSet/FindServersRequest.h"

namespace OpcUaStackCore
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// OpcUa FindServersRequest
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------

	FindServersRequest::FindServersRequest(void)
	: ObjectPool<FindServersRequest>()
	, requestHeaderSPtr_(RequestHeader::construct())
	, endpointUrl_()
	, localeIdArraySPtr_(OpcUaStringArray::construct())
	, serverUriArraySPtr_(OpcUaStringArray::construct())
	{
	}

	FindServersRequest::~FindServersRequest(void)
	{
	}

	void 
	FindServersRequest::requestHeader(const RequestHeader::SPtr requestHeaderSPtr)
	{
		requestHeaderSPtr_ = requestHeaderSPtr;
	}

	RequestHeader::SPtr 
	FindServersRequest::requestHeader(void) const
	{
		return requestHeaderSPtr_;
	}

	void 
	FindServersRequest::endpointUrl(const OpcUaString& endpointUrl)
	{
		endpointUrl_ = endpointUrl;
	}

	void 
	FindServersRequest::endpointUrl(const std::string& endpointUrl)
	{
		endpointUrl_.value(endpointUrl);
	}
	
	OpcUaString& 
	FindServersRequest::endpointUrl(void)
	{
		return endpointUrl_;
	}
	
	void 
	FindServersRequest::localeIds(const OpcUaStringArray::SPtr localeIds)
	{
		localeIdArraySPtr_ = localeIds;
	}
	
	OpcUaStringArray::SPtr 
	FindServersRequest::localeIds(void) const
	{
		return localeIdArraySPtr_;
	}
	
	void 
	FindServersRequest::serverUris(const OpcUaStringArray::SPtr serverUris)
	{
		serverUriArraySPtr_ = serverUris;
	}
	
	OpcUaStringArray::SPtr 
	FindServersRequest::serverUris(void) const
	{
		return serverUriArraySPtr_;
	}

	void 
	FindServersRequest::opcUaBinaryEncode(std::ostream& os) const
	{
		requestHeaderSPtr_->opcUaBinaryEncode(os);
		endpointUrl_.opcUaBinaryEncode(os);
		localeIdArraySPtr_->opcUaBinaryEncode(os);
		serverUriArraySPtr_->opcUaBinaryEncode(os);
	}
	
	void 
	FindServersRequest::opcUaBinaryDecode(std::istream& is)
	{
		requestHeaderSPtr_->opcUaBinaryDecode(is);
		endpointUrl_.opcUaBinaryDecode(is);
		localeIdArraySPtr_->opcUaBinaryDecode(is);
		serverUriArraySPtr_->opcUaBinaryDecode(is);
	}

}