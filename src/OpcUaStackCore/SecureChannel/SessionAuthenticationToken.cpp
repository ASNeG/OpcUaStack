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

	void 
	SessionAuthenticationToken::opcUaBinaryEncode(std::ostream& os) const
	{
		OpcUaStackCore::opcUaBinaryEncode(os, token_);
	}

	void 
	SessionAuthenticationToken::opcUaBinaryDecode(std::istream& is)
	{
		OpcUaStackCore::opcUaBinaryDecode(is, token_);
	}
}