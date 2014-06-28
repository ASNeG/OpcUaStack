#include "OpcUaStackCore/SecureChannel/OpenSecureChannelResponse.h"

namespace OpcUaStackCore
{

	OpenSecureChannelResponse::OpenSecureChannelResponse(void)
	{
	}
		
	OpenSecureChannelResponse::~OpenSecureChannelResponse(void)
	{
	}

	void 
	OpenSecureChannelResponse::responseHeader(const ResponseHeader::SPtr responseHeaderSPtr)
	{
		responseHeaderSPtr_ = responseHeaderSPtr;
	}

	ResponseHeader::SPtr  
	OpenSecureChannelResponse::responseHeader(void) const
	{
		return responseHeaderSPtr_;
	}

	void  
	OpenSecureChannelResponse::securityToken(const SecurityToken::SPtr securityToken)
	{
		securityTokenSPtr_ = securityToken;
	}

	SecurityToken::SPtr  
	OpenSecureChannelResponse::securityToken(void)
	{
		return securityTokenSPtr_;
	}

	void 
	OpenSecureChannelResponse::serverNonce(const OpcUaByte* buf, OpcUaInt32 bufLen)
	{
		serverNonce_.value(buf, bufLen);
	}

	void 
	OpenSecureChannelResponse::serverNonce(OpcUaByte** buf, OpcUaInt32 *bufLen) const
	{
		serverNonce_.value(buf, bufLen);
	}

	void 
	OpenSecureChannelResponse::opcUaBinaryEncode(std::ostream& os) const
	{
		responseHeaderSPtr_->opcUaBinaryEncode(os);
		securityTokenSPtr_->opcUaBinaryEncode(os);
		OpcUaStackCore::opcUaBinaryEncode(os, serverNonce_);
	}

	void 
	OpenSecureChannelResponse::opcUaBinaryDecode(std::istream& is)
	{
		responseHeaderSPtr_->opcUaBinaryDecode(is);
		securityTokenSPtr_->opcUaBinaryDecode(is);
		OpcUaStackCore::opcUaBinaryDecode(is, serverNonce_);
	}

}