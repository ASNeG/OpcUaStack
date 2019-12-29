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
	: Object()
	, requestHeaderSPtr_(boost::make_shared<RequestHeader>())
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

	bool
	RegisterServerRequest::opcUaBinaryEncode(std::ostream& os) const
	{
		return server_.opcUaBinaryEncode(os);
	}
	
	bool
	RegisterServerRequest::opcUaBinaryDecode(std::istream& is)
	{
		return server_.opcUaBinaryDecode(is);
	}

	bool
	RegisterServerRequest::jsonEncodeImpl(boost::property_tree::ptree &pt) const {
		return jsonObjectEncode(pt, server_, "Server");
	}

	bool
	RegisterServerRequest::jsonDecodeImpl(const boost::property_tree::ptree &pt) {
		return jsonObjectDecode(pt, server_, "Server");
	}

}
