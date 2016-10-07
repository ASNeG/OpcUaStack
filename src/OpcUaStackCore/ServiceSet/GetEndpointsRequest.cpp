/*
   Copyright 2015 Kai Huebl (kai@huebl-sgh.de)

   Lizenziert gemäß Apache Licence Version 2.0 (die „Lizenz“); Nutzung dieser
   Datei nur in Übereinstimmung mit der Lizenz erlaubt.
   Eine Kopie der Lizenz erhalten Sie auf http://www.apache.org/licenses/LICENSE-2.0.

   Sofern nicht gemäß geltendem Recht vorgeschrieben oder schriftlich vereinbart,
   erfolgt die Bereitstellung der im Rahmen der Lizenz verbreiteten Software OHNE
   GEWÄHR ODER VORBEHALTE – ganz gleich, ob ausdrücklich oder stillschweigend.

   Informationen über die jeweiligen Bedingungen für Genehmigungen und Einschränkungen
   im Rahmen der Lizenz finden Sie in der Lizenz.

   Autor: Kai Huebl (kai@huebl-sgh.de)
 */

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
	, requestHeaderSPtr_(RequestHeader::construct())
	, endpointUrl_()
	, localeIdArraySPtr_(constructSPtr<OpcUaStringArray>())
	, profileUriArraySPtr_(constructSPtr<OpcUaStringArray>())
	{
	}

	GetEndpointsRequest::~GetEndpointsRequest(void)
	{
	}

	void
	GetEndpointsRequest::requestHeader(const RequestHeader::SPtr requestHeaderSPtr)
	{
		requestHeaderSPtr_ = requestHeaderSPtr;
	}

	RequestHeader::SPtr
	GetEndpointsRequest::requestHeader(void) const
	{
		return requestHeaderSPtr_;
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
		//requestHeaderSPtr_->opcUaBinaryEncode(os);
		endpointUrl_.opcUaBinaryEncode(os);
		localeIdArraySPtr_->opcUaBinaryEncode(os);
		profileUriArraySPtr_->opcUaBinaryEncode(os);
	}
	
	void 
	GetEndpointsRequest::opcUaBinaryDecode(std::istream& is)
	{
		//requestHeaderSPtr_->opcUaBinaryDecode(is);
		endpointUrl_.opcUaBinaryDecode(is);
		localeIdArraySPtr_->opcUaBinaryDecode(is);
		profileUriArraySPtr_->opcUaBinaryDecode(is);
	}

}
