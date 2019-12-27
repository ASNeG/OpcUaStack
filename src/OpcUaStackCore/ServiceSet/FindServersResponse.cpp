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

#include "OpcUaStackCore/ServiceSet/FindServersResponse.h"

namespace OpcUaStackCore
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// OpcUa FindServersResponse
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------

	FindServersResponse::FindServersResponse(void)
	: Object()
	, responseHeaderSPtr_(boost::make_shared<ResponseHeader>())
	, serverArraySPtr_(boost::make_shared<ApplicationDescriptionArray>())
	{
	}

	FindServersResponse::~FindServersResponse(void)
	{
	}

	void 
	FindServersResponse::responseHeader(const ResponseHeader::SPtr responseHeaderSPtr)
	{
		responseHeaderSPtr_ = responseHeaderSPtr;
	}

	ResponseHeader::SPtr 
	FindServersResponse::responseHeader(void) const
	{
		return responseHeaderSPtr_;
	}
	
	void 
	FindServersResponse::servers(const ApplicationDescriptionArray::SPtr servers)
	{
		serverArraySPtr_ = servers;
	}
	
	ApplicationDescriptionArray::SPtr 
	FindServersResponse::servers(void) const
	{
		return serverArraySPtr_;
	}

	bool
	FindServersResponse::opcUaBinaryEncode(std::ostream& os) const
	{
		return serverArraySPtr_->opcUaBinaryEncode(os);
	}
	
	bool
	FindServersResponse::opcUaBinaryDecode(std::istream& is)
	{
		return serverArraySPtr_->opcUaBinaryDecode(is);
	}

	bool
	FindServersResponse::jsonEncodeImpl(boost::property_tree::ptree &pt) const {
		return jsonObjectSPtrEncode(pt, serverArraySPtr_, "Servers");
	}

	bool
	FindServersResponse::jsonDecodeImpl(const boost::property_tree::ptree &pt) {
		return jsonObjectSPtrDecode(pt, serverArraySPtr_, "Servers");
	}

}
