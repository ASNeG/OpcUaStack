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

#include "OpcUaStackCore/ServiceSet/CancelResponse.h"

namespace OpcUaStackCore
{

	CancelResponse::CancelResponse(void)
	: Object()
	, responseHeader_(boost::make_shared<ResponseHeader>())
	{
	}

	CancelResponse::~CancelResponse(void)
	{
	}

	void 
	CancelResponse::responseHeader(const ResponseHeader::SPtr requestHeader)
	{
		responseHeader_ = requestHeader;
	}

	ResponseHeader::SPtr 
	CancelResponse::responseHeader(void) const
	{
		return responseHeader_;
	}

	void
	CancelResponse::cancelCount(const OpcUaInt32& cancelCount)
	{
		cancelCount_ = cancelCount;
	}

	OpcUaInt32 
	CancelResponse::cancelCount(void) const
	{
		return cancelCount_;
	}

	bool
	CancelResponse::opcUaBinaryEncode(std::ostream& os) const
	{
		bool rc = true;

		rc &= responseHeader_->opcUaBinaryEncode(os);
		rc &= OpcUaNumber::opcUaBinaryEncode(os, cancelCount_);

		return rc;
	}

	bool
	CancelResponse::opcUaBinaryDecode(std::istream& is)
	{
		bool rc = true;

		rc &= responseHeader_->opcUaBinaryDecode(is);
		rc &= OpcUaNumber::opcUaBinaryDecode(is, cancelCount_);

		return rc;
	}

}
