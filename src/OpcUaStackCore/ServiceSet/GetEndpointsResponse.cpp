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
	: Object()
	, responseHeader_(boost::make_shared<ResponseHeader>())
	, endpointArraySPtr_(boost::make_shared<EndpointDescriptionArray>())
	{
	}

	GetEndpointsResponse::~GetEndpointsResponse(void)
	{
	}

	void
	GetEndpointsResponse::responseHeader(const ResponseHeader::SPtr requestHeader)
	{
		responseHeader_ = requestHeader;
	}

	ResponseHeader::SPtr
	GetEndpointsResponse::responseHeader(void) const
	{
		return responseHeader_;
	}

	void 
	GetEndpointsResponse::endpoints(const EndpointDescriptionArray::SPtr& endpoints)
	{
		endpointArraySPtr_ = endpoints;
	}
	
	EndpointDescriptionArray::SPtr&
	GetEndpointsResponse::endpoints(void)
	{
		return endpointArraySPtr_;
	}

	bool
	GetEndpointsResponse::opcUaBinaryEncode(std::ostream& os) const
	{
		return endpointArraySPtr_->opcUaBinaryEncode(os);
	}
	
	bool
	GetEndpointsResponse::opcUaBinaryDecode(std::istream& is)
	{
		return endpointArraySPtr_->opcUaBinaryDecode(is);
	}

	bool
	GetEndpointsResponse::jsonEncodeImpl(boost::property_tree::ptree &pt) const {
		return jsonObjectSPtrEncode(pt, endpointArraySPtr_, "Endpoints");
	}

	bool
	GetEndpointsResponse::jsonDecodeImpl(const boost::property_tree::ptree &pt) {
		return jsonObjectSPtrDecode(pt, endpointArraySPtr_, "Endpoints");
	}

}
