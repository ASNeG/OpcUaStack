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
	, requestHeaderSPtr_(constructSPtr<RequestHeader>())
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

	void 
	RegisterServerRequest::opcUaBinaryEncode(std::ostream& os) const
	{
		//requestHeaderSPtr_->opcUaBinaryEncode(os);
		server_.opcUaBinaryEncode(os);
	}
	
	void 
	RegisterServerRequest::opcUaBinaryDecode(std::istream& is)
	{
		//requestHeaderSPtr_->opcUaBinaryDecode(is);
		server_.opcUaBinaryDecode(is);
	}

}
