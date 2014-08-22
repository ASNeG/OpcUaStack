#include "OpcUaStackCore/SecureChannel/OpenSecureChannelRequest.h"

namespace OpcUaStackCore
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// OpenSecureChannelRequest
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	OpenSecureChannelRequest::OpenSecureChannelRequest(void)
	: requestHeaderSPtr_(RequestHeader::construct())
	, clientProtocolVersion_(0)
	, requestType_()
	, securityMode_()
	, clientNonce_()
	, requestedLifetime_()
	{
	}
		
	OpenSecureChannelRequest::~OpenSecureChannelRequest(void)
	{
	}

	void 
	OpenSecureChannelRequest::requestHeader(const RequestHeader::SPtr requestHeaderSPtr)
	{
		requestHeaderSPtr_ = requestHeaderSPtr;
	}

	RequestHeader::SPtr  
	OpenSecureChannelRequest::requestHeader(void) const
	{
		return requestHeaderSPtr_;
	}

	void 
	OpenSecureChannelRequest::clientProtocolVersion(const OpcUaInt32& clientProtocolVersion)
	{
		clientProtocolVersion_ = clientProtocolVersion;
	}
		
	OpcUaInt32 
	OpenSecureChannelRequest::clientProtocolVersion(void)
	{
		return clientProtocolVersion_;
	}

	void  
	OpenSecureChannelRequest::requestType(const RequestType& requestType)
	{
		requestType_ = requestType;
	}

	RequestType  
	OpenSecureChannelRequest::requestType(void)
	{
		return requestType_;
	}

	void  
	OpenSecureChannelRequest::securityMode(const SecurityMode& securityMode)
	{
		securityMode_ = securityMode;
	}

	SecurityMode  
	OpenSecureChannelRequest::securityMode(void) const
	{
		return securityMode_;
	}

	void  
	OpenSecureChannelRequest::clientNonce(OpcUaByte *buf, OpcUaInt32 bufLen)
	{
		clientNonce_.value(buf, bufLen);
	}

	void  
	OpenSecureChannelRequest::clientNonce(OpcUaByte **buf, OpcUaInt32* bufLen) const
	{
		clientNonce_.value(buf, bufLen);
	}

	void  
	OpenSecureChannelRequest::requestedLifetime(const OpcUaInt32& requestedLifetime)
	{
		requestedLifetime_ = requestedLifetime;
	}

	OpcUaInt32  
	OpenSecureChannelRequest::requestedLifetime(void) const
	{
		return requestedLifetime_;
	}

	void 
	OpenSecureChannelRequest::opcUaBinaryEncode(std::ostream& os) const
	{
		requestHeaderSPtr_->opcUaBinaryEncode(os);
		OpcUaNumber::opcUaBinaryEncode(os, clientProtocolVersion_);
		OpcUaNumber::opcUaBinaryEncode(os, (OpcUaUInt32)requestType_);
		OpcUaNumber::opcUaBinaryEncode(os, (OpcUaUInt32)securityMode_);
		clientNonce_.opcUaBinaryEncode(os);
		OpcUaNumber::opcUaBinaryEncode(os, requestedLifetime_);
	}

	void 
	OpenSecureChannelRequest::opcUaBinaryDecode(std::istream& is)
	{
		OpcUaUInt32 tmp;
		requestHeaderSPtr_->opcUaBinaryDecode(is);
		OpcUaNumber::opcUaBinaryDecode(is, clientProtocolVersion_);
		OpcUaNumber::opcUaBinaryDecode(is, tmp); requestType_ = (RequestType)tmp;
		OpcUaNumber::opcUaBinaryDecode(is, tmp); securityMode_ = (SecurityMode)tmp;
		clientNonce_.opcUaBinaryDecode(is);
		OpcUaNumber::opcUaBinaryDecode(is, requestedLifetime_);
	}

}