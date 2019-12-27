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
	: Object()
	, requestHeaderSPtr_(boost::make_shared<RequestHeader>())
	, endpointUrl_()
	, localeIdArraySPtr_(boost::make_shared<OpcUaStringArray>())
	, serverUriArraySPtr_(boost::make_shared<OpcUaStringArray>())
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

	bool
	FindServersRequest::opcUaBinaryEncode(std::ostream& os) const
	{
		bool rc = true;

		rc &= endpointUrl_.opcUaBinaryEncode(os);
		rc &= localeIdArraySPtr_->opcUaBinaryEncode(os);
		rc &= serverUriArraySPtr_->opcUaBinaryEncode(os);

		return rc;
	}
	
	bool
	FindServersRequest::opcUaBinaryDecode(std::istream& is)
	{
		bool rc = true;

		rc &= endpointUrl_.opcUaBinaryDecode(is);
		rc &= localeIdArraySPtr_->opcUaBinaryDecode(is);
		rc &= serverUriArraySPtr_->opcUaBinaryDecode(is);

		return rc;
	}

	bool
	FindServersRequest::jsonEncodeImpl(boost::property_tree::ptree &pt) const {
		bool rc = jsonObjectEncode(pt, endpointUrl_, "EndpointUrl");
		rc &= jsonObjectSPtrEncode(pt, localeIdArraySPtr_, "LocaleIds");
		rc &= jsonObjectSPtrEncode(pt, serverUriArraySPtr_, "ServerUris");
		return rc;
	}

	bool
	FindServersRequest::jsonDecodeImpl(const boost::property_tree::ptree &pt) {
		bool rc = jsonObjectDecode(pt, endpointUrl_, "EndpointUrl");
		rc &= jsonObjectSPtrDecode(pt, localeIdArraySPtr_, "LocaleIds");
		rc &= jsonObjectSPtrDecode(pt, serverUriArraySPtr_, "ServerUris");
		return rc;
	}

}
