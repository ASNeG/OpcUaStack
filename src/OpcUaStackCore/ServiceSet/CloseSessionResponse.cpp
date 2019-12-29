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

   Autor: Kai Huebl (kai@huebl-sgh.de)
 */

#include "OpcUaStackCore/ServiceSet/CloseSessionResponse.h"

namespace OpcUaStackCore
{

	CloseSessionResponse::CloseSessionResponse(void)
	: Object()
	, responseHeader_(boost::make_shared<ResponseHeader>())
	{
	}

	CloseSessionResponse::~CloseSessionResponse(void)
	{
	}

	void 
	CloseSessionResponse::responseHeader(const ResponseHeader::SPtr requestHeader)
	{
		responseHeader_ = requestHeader;
	}

	ResponseHeader::SPtr 
	CloseSessionResponse::responseHeader(void)
	{
		return responseHeader_;
	}

	bool
	CloseSessionResponse::opcUaBinaryEncode(std::ostream& os) const
	{
		return true;
	}

	bool
	CloseSessionResponse::opcUaBinaryDecode(std::istream& is)
	{
		return true;
	}

}
