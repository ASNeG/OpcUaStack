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

#include "OpcUaStackCore/SecureChannel/SessionAuthenticationToken.h"

namespace OpcUaStackCore
{

	SessionAuthenticationToken::SessionAuthenticationToken(void)
	: token_(0)
	{
	}

	SessionAuthenticationToken::~SessionAuthenticationToken(void)
	{
	}

	void 
	SessionAuthenticationToken::token(const OpcUaUInt32& token)
	{
		token_ = token;
	}

	OpcUaUInt32 
	SessionAuthenticationToken::token(void) const
	{
		return token_;
	}

	bool
	SessionAuthenticationToken::opcUaBinaryEncode(std::ostream& os) const
	{
		return  OpcUaNumber::opcUaBinaryEncode(os, token_);
	}

	bool
	SessionAuthenticationToken::opcUaBinaryDecode(std::istream& is)
	{
		return OpcUaNumber::opcUaBinaryDecode(is, token_);
	}
}
