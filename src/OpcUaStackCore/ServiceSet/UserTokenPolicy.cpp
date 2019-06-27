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

#include "OpcUaStackCore/ServiceSet/UserTokenPolicy.h"

namespace OpcUaStackCore
{

	// ---------------------------------------------------------------------------
	// ---------------------------------------------------------------------------
	//
	// UserTokenPolicy
	// 
	// ---------------------------------------------------------------------------
	// ---------------------------------------------------------------------------
	UserTokenPolicy::UserTokenPolicy(void)
	: policyId_()
	, tokenType_(UserIdentityTokenType_Anonymous)
	, issuedTokenType_()
	, issuerEndpointUrl_()
	, securityPolicyUri_()
	{
	}

	UserTokenPolicy::~UserTokenPolicy(void)
	{
	}

	void 
	UserTokenPolicy::policyId(const std::string& policyId)
	{
		policyId_ = policyId;
	}

	std::string UserTokenPolicy::policyId(void) const
	{
		return policyId_.value();
	}

	void 
	UserTokenPolicy::tokenType(const UserIdentityTokenType tokenType)
	{
		tokenType_ = tokenType;
	}

	UserIdentityTokenType 
	UserTokenPolicy::tokenType(void) const
	{
		return tokenType_;
	}

	void 
	UserTokenPolicy::issuedTokenType(const std::string& issuedTokenType)
	{
		issuedTokenType_ = issuedTokenType;
	}

	std::string 
	UserTokenPolicy::issuedTokenType(void) const
	{
		return issuedTokenType_.value();
	}

	void 
	UserTokenPolicy::issuerEndpointUrl(const std::string& issuerEndpointUrl)
	{
		issuerEndpointUrl_ = issuerEndpointUrl;
	}

	std::string 
	UserTokenPolicy::issuerEndpointUrl(void) const
	{
		return issuerEndpointUrl_.value();
	}

	void 
	UserTokenPolicy::securityPolicyUri(const std::string& securityPolicyUri)
	{
		securityPolicyUri_ = securityPolicyUri;
	}

	std::string 
	UserTokenPolicy::securityPolicyUri(void) const
	{
		return securityPolicyUri_.value();
	}

	void 
	UserTokenPolicy::opcUaBinaryEncode(std::ostream& os) const
	{
		policyId_.opcUaBinaryEncode(os);
		OpcUaNumber::opcUaBinaryEncode(os, (OpcUaUInt32)tokenType_);
		issuedTokenType_.opcUaBinaryEncode(os);
		issuerEndpointUrl_.opcUaBinaryEncode(os);
		securityPolicyUri_.opcUaBinaryEncode(os);
	}

	void 
	UserTokenPolicy::opcUaBinaryDecode(std::istream& is)
	{
		OpcUaUInt32 tokenType;
		policyId_.opcUaBinaryDecode(is);
		OpcUaNumber::opcUaBinaryDecode(is, tokenType);
		issuedTokenType_.opcUaBinaryDecode(is);
		issuerEndpointUrl_.opcUaBinaryDecode(is);
		securityPolicyUri_.opcUaBinaryDecode(is);
		tokenType_ = (UserIdentityTokenType)tokenType;
	}

}
