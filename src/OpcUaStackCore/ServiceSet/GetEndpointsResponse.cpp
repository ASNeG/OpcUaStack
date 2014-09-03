#include "OpcUaStackCore/ServiceSet/GetEndpointsResponse.h"

namespace OpcUaStackCore
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// OpcUa GetEndpointsResponse
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------

	GetEndpointsResponse::GetEndpointsResponse(void)
	: ObjectPool<GetEndpointsResponse>()
	, responseHeaderSPtr_(ResponseHeader::construct())
	, endpointArraySPtr_(EndpointDescriptionArray::construct())
	{
	}

	GetEndpointsResponse::~GetEndpointsResponse(void)
	{
	}

	void 
	GetEndpointsResponse::responseHeader(const ResponseHeader::SPtr responseHeaderSPtr)
	{
		responseHeaderSPtr_ = responseHeaderSPtr;
	}

	ResponseHeader::SPtr 
	GetEndpointsResponse::responseHeader(void) const
	{
		return responseHeaderSPtr_;
	}
	
	void 
	GetEndpointsResponse::endpoints(const EndpointDescriptionArray::SPtr endpoints)
	{
		endpointArraySPtr_ = endpoints;
	}
	
	EndpointDescriptionArray::SPtr 
	GetEndpointsResponse::endpoints(void) const
	{
		return endpointArraySPtr_;
	}

	void 
	GetEndpointsResponse::opcUaBinaryEncode(std::ostream& os) const
	{
		responseHeaderSPtr_->opcUaBinaryEncode(os);
		endpointArraySPtr_->opcUaBinaryEncode(os);
	}
	
	void 
	GetEndpointsResponse::opcUaBinaryDecode(std::istream& is)
	{
		responseHeaderSPtr_->opcUaBinaryDecode(is);
		endpointArraySPtr_->opcUaBinaryDecode(is);
	}

}