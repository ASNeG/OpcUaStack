#include "OpcUaStackCore/SecureChannel/OpenSecureChannelResponse.h"

namespace OpcUaStackCore
{

	OpenSecureChannelResponse::OpenSecureChannelResponse(void)
	: serverProtocolVersion_(0)
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
	OpenSecureChannelResponse::serverProtocolVersion(const OpcUaInt32& serverProtocolVersion)
	{
		serverProtocolVersion_ = serverProtocolVersion;
	}
		
	OpcUaInt32 
	OpenSecureChannelResponse::serverProtocolVersion(void) const
	{
		return serverProtocolVersion_;
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
		OpcUaNumber::opcUaBinaryEncode(os, serverProtocolVersion_);
		securityTokenSPtr_->opcUaBinaryEncode(os);
		serverNonce_.opcUaBinaryEncode(os);
	}

	void 
	OpenSecureChannelResponse::opcUaBinaryDecode(std::istream& is)
	{
		responseHeaderSPtr_->opcUaBinaryDecode(is);
		OpcUaNumber::opcUaBinaryDecode(is, serverProtocolVersion_);
		securityTokenSPtr_->opcUaBinaryDecode(is);
		serverNonce_.opcUaBinaryDecode(is);
	}

}