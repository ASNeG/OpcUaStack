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
	, endpointArraySPtr_(EndpointDescriptionArray::construct())
	{
	}

	GetEndpointsResponse::~GetEndpointsResponse(void)
	{
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
		endpointArraySPtr_->opcUaBinaryEncode(os);
	}
	
	void 
	GetEndpointsResponse::opcUaBinaryDecode(std::istream& is)
	{
		endpointArraySPtr_->opcUaBinaryDecode(is);
	}

}