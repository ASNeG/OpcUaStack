#include "OpcUaStackCore/ServiceSet/GetEndpointsRequest.h"

namespace OpcUaStackCore
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// OpcUa GetEndpointsRequest
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------

	GetEndpointsRequest::GetEndpointsRequest(void)
	: ObjectPool<GetEndpointsRequest>()
	, endpointUrl_()
	, localeIdArraySPtr_(OpcUaStringArray::construct())
	, profileUriArraySPtr_(OpcUaStringArray::construct())
	{
	}

	GetEndpointsRequest::~GetEndpointsRequest(void)
	{
	}

	void 
	GetEndpointsRequest::endpointUrl(const OpcUaString& endpointUrl)
	{
		endpointUrl_ = endpointUrl;
	}

	void 
	GetEndpointsRequest::endpointUrl(const std::string& endpointUrl)
	{
		endpointUrl_.value(endpointUrl);
	}
	
	OpcUaString& 
	GetEndpointsRequest::endpointUrl(void)
	{
		return endpointUrl_;
	}
	
	void 
	GetEndpointsRequest::localeIds(const OpcUaStringArray::SPtr localeIds)
	{
		localeIdArraySPtr_ = localeIds;
	}
	
	OpcUaStringArray::SPtr 
	GetEndpointsRequest::localeIds(void) const
	{
		return localeIdArraySPtr_;
	}
	
	void 
	GetEndpointsRequest::profileUris(const OpcUaStringArray::SPtr profileUris)
	{
		profileUriArraySPtr_ = profileUris;
	}
	
	OpcUaStringArray::SPtr 
	GetEndpointsRequest::profileUris(void) const
	{
		return profileUriArraySPtr_;
	}

	void 
	GetEndpointsRequest::opcUaBinaryEncode(std::ostream& os) const
	{
		endpointUrl_.opcUaBinaryEncode(os);
		localeIdArraySPtr_->opcUaBinaryEncode(os);
		profileUriArraySPtr_->opcUaBinaryEncode(os);
	}
	
	void 
	GetEndpointsRequest::opcUaBinaryDecode(std::istream& is)
	{
		endpointUrl_.opcUaBinaryDecode(is);
		localeIdArraySPtr_->opcUaBinaryDecode(is);
		profileUriArraySPtr_->opcUaBinaryDecode(is);
	}

}