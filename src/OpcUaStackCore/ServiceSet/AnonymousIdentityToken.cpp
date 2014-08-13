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
		return AnonymousIdentityToken::construct();
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