/*
   Copyright 2015-2019 Kai Huebl (kai@huebl-sgh.de)

   Lizenziert gemäß Apache Licence Version 2.0 (die „Lizenz“); Nutzung dieser
   Datei nur in Übereinstimmung mit der Lizenz erlaubt.
   Eine Kopie der Lizenz erhalten Sie auf http://www.apache.org/licenses/LICENSE-2.0.

   Sofern nicht gemäß geltendem Recht vorgeschrieben oder schriftlich vereinbart,
   erfolgt die Bereitstellung der im Rahmen der Lizenz verbreiteten Software OHNE
   GEWÄHR ODER VORBEHALTE – ganz gleich, ob ausdrücklich oder stillschweigend.

   Informationen über die jeweiligen Bedingungen für Genehmigungen und Einschränkungen
   im Rahmen der Lizenz finden Sie in der Lizenz.

   Autor: Kai Huebl (kai@huebl-sgh.de), Aleksey Timin (atimin@gmail.com)
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
	: Object()
	, requestHeaderSPtr_(boost::make_shared<RequestHeader>())
	, endpointUrl_()
	, localeIdArraySPtr_(boost::make_shared<OpcUaStringArray>())
	, profileUriArraySPtr_(boost::make_shared<OpcUaStringArray>())
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

	bool
	GetEndpointsRequest::opcUaBinaryEncode(std::ostream& os) const
	{
		bool rc = true;

		rc &= endpointUrl_.opcUaBinaryEncode(os);
		rc &= localeIdArraySPtr_->opcUaBinaryEncode(os);
		rc &= profileUriArraySPtr_->opcUaBinaryEncode(os);

		return rc;
	}
	
	bool
	GetEndpointsRequest::opcUaBinaryDecode(std::istream& is)
	{
		bool rc = true;

		rc &= endpointUrl_.opcUaBinaryDecode(is);
		rc &= localeIdArraySPtr_->opcUaBinaryDecode(is);
		rc &= profileUriArraySPtr_->opcUaBinaryDecode(is);

		return rc;
	}

	bool
	GetEndpointsRequest::jsonEncodeImpl(boost::property_tree::ptree &pt) const {
		bool rc = jsonObjectEncode(pt, endpointUrl_, "EndpointUrl");
		rc &= jsonObjectSPtrEncode(pt, localeIdArraySPtr_, "LocaleIds");
		rc &= jsonObjectSPtrEncode(pt, profileUriArraySPtr_, "ProfileUris");
		return rc;
	}

	bool
	GetEndpointsRequest::jsonDecodeImpl(const boost::property_tree::ptree &pt) {
		bool rc = jsonObjectDecode(pt, endpointUrl_, "EndpointUrl");
		rc &= jsonObjectSPtrDecode(pt, localeIdArraySPtr_, "LocaleIds");
		rc &= jsonObjectSPtrDecode(pt, profileUriArraySPtr_, "ProfileUris");
		return rc;
	}

}
