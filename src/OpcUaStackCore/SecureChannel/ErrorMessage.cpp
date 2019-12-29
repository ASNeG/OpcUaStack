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

#include "OpcUaStackCore/SecureChannel/ErrorMessage.h"

namespace OpcUaStackCore
{

	ErrorMessage::ErrorMessage(void)
	: error_(0)
	, reason_()
	{
	}
		
	ErrorMessage::~ErrorMessage(void)
	{
	}

	void 
	ErrorMessage::error(const OpcUaUInt32& error)
	{
		error_ = error;
	}
		
	OpcUaUInt32 
	ErrorMessage::error(void) const
	{
		return error_;
	}
		
	void 
	ErrorMessage::reason(const std::string& reason)
	{
		reason_ = reason;
	}

	std::string 
	ErrorMessage::reason(void)
	{
		std::string reason = reason_;
		return reason;
	}

	bool
	ErrorMessage::opcUaBinaryEncode(std::ostream& os) const
	{
		bool rc = true;

		rc &= OpcUaNumber::opcUaBinaryEncode(os, error_);
		rc &= reason_.opcUaBinaryEncode(os);

		return rc;
	}

	bool
	ErrorMessage::opcUaBinaryDecode(std::istream& is)
	{
		bool rc = true;

		rc &= OpcUaNumber::opcUaBinaryDecode(is, error_);
		rc &= reason_.opcUaBinaryDecode(is);

		return rc;
	}

}
