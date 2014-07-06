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
	, tokenType_(UserIdentityTokenType::UserIdentityTokenType_Anonymous)
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
		OpcUaStackCore::opcUaBinaryEncode(os, policyId_);
		OpcUaStackCore::opcUaBinaryEncode(os, (OpcUaUInt32)tokenType_);
		OpcUaStackCore::opcUaBinaryEncode(os, issuedTokenType_);
		OpcUaStackCore::opcUaBinaryEncode(os, issuerEndpointUrl_);
		OpcUaStackCore::opcUaBinaryEncode(os, securityPolicyUri_);
	}

	void 
	UserTokenPolicy::opcUaBinaryDecode(std::istream& is)
	{
		OpcUaUInt32 tokenType;
		OpcUaStackCore::opcUaBinaryDecode(is, policyId_);
		OpcUaStackCore::opcUaBinaryDecode(is, tokenType);
		OpcUaStackCore::opcUaBinaryDecode(is, issuedTokenType_);
		OpcUaStackCore::opcUaBinaryDecode(is, issuerEndpointUrl_);
		OpcUaStackCore::opcUaBinaryDecode(is, securityPolicyUri_);
		tokenType_ = (UserIdentityTokenType)tokenType;
	}

	void opcUaBinaryEncode(std::ostream& os, const UserTokenPolicy& value)
	{
		value.opcUaBinaryEncode(os);
	}

	void opcUaBinaryDecode(std::istream& is, UserTokenPolicy& value)
	{
		value.opcUaBinaryDecode(is);
	}


	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// UserTokenPolicyArray
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	void opcUaBinaryEncode(std::ostream& os, const UserTokenPolicyArray& value)
	{
		value.opcUaBinaryEncode(os);
	}

	void opcUaBinaryEncode(std::ostream& os, const UserTokenPolicyArray::SPtr& value)
	{
		value->opcUaBinaryEncode(os);
	}
	
	void opcUaBinaryDecode(std::istream& is, UserTokenPolicyArray& value)
	{
		value.opcUaBinaryDecode(is);
	}

	void opcUaBinaryDecode(std::istream& is, UserTokenPolicyArray::SPtr& value)
	{
		value->opcUaBinaryDecode(is);
	}
}