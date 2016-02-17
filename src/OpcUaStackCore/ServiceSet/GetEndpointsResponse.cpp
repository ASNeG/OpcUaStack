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
	, responseHeader_(constructSPtr<ResponseHeader>())
	, endpointArraySPtr_(constructSPtr<EndpointDescriptionArray>())
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
		//responseHeader_->opcUaBinaryEncode(os);
		endpointArraySPtr_->opcUaBinaryEncode(os);
	}
	
	void 
	GetEndpointsResponse::opcUaBinaryDecode(std::istream& is)
	{
		//responseHeader_->opcUaBinaryDecode(is);
		endpointArraySPtr_->opcUaBinaryDecode(is);
	}

}
