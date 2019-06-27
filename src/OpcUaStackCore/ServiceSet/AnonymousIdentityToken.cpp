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

#include "OpcUaStackCore/ServiceSet/AnonymousIdentityToken.h"

namespace OpcUaStackCore
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// AnonymousIdentityToken
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	AnonymousIdentityToken::AnonymousIdentityToken(void)
	: Object()
	, ExtensibleParameterBase()
	{
	}

	AnonymousIdentityToken::~AnonymousIdentityToken(void)
	{
	}

	void 
	AnonymousIdentityToken::policyId(const std::string& policyId)
	{
		policyId_ = policyId;
	}
		
	std::string 
	AnonymousIdentityToken::policyId(void) const
	{
		return policyId_.value();
	}

	ExtensibleParameterBase::SPtr
	AnonymousIdentityToken::factory(void)
	{
		return constructSPtr<AnonymousIdentityToken>();
	}

		
	void 
	AnonymousIdentityToken::opcUaBinaryEncode(std::ostream& os) const
	{
		policyId_.opcUaBinaryEncode(os);
	}
	
	void 
	AnonymousIdentityToken::opcUaBinaryDecode(std::istream& is)
	{
		policyId_.opcUaBinaryDecode(is);
	}

}
