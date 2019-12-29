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

#include "OpcUaStackCore/ServiceSet/RegisterServerResponse.h"

namespace OpcUaStackCore
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// OpcUa RegisterServerResponse
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------

	RegisterServerResponse::RegisterServerResponse(void)
	: Object()
	, responseHeaderSPtr_(boost::make_shared<ResponseHeader>())
	{
	}

	RegisterServerResponse::~RegisterServerResponse(void)
	{
	}

	void 
	RegisterServerResponse::responseHeader(const ResponseHeader::SPtr responseHeaderSPtr)
	{
		responseHeaderSPtr_ = responseHeaderSPtr;
	}

	ResponseHeader::SPtr 
	RegisterServerResponse::responseHeader(void) const
	{
		return responseHeaderSPtr_;
	}

	bool
	RegisterServerResponse::opcUaBinaryEncode(std::ostream& os) const
	{
		return responseHeaderSPtr_->opcUaBinaryEncode(os);
	}
	
	bool
	RegisterServerResponse::opcUaBinaryDecode(std::istream& is)
	{
		return responseHeaderSPtr_->opcUaBinaryDecode(is);
	}

	bool
	RegisterServerResponse::jsonEncodeImpl(boost::property_tree::ptree &pt) const {
		return true;
	}

	bool
	RegisterServerResponse::jsonDecodeImpl(const boost::property_tree::ptree &pt) {
		return true;
	}

}
