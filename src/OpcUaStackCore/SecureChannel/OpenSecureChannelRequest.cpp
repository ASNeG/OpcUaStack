#include "OpcUaStackCore/SecureChannel/OpenSecureChannelRequest.h"

namespace OpcUaStackCore
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// ApplicationInstanceCertificate
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	ApplicationInstanceCertificate::ApplicationInstanceCertificate(void)
	{
	}

	ApplicationInstanceCertificate::~ApplicationInstanceCertificate(void)
	{
	}

	void 
	ApplicationInstanceCertificate::opcUaBinaryEncode(std::ostream& os) const
	{
	}

	void 
	ApplicationInstanceCertificate::opcUaBinaryDecode(std::istream& is)
	{
	}

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// OpenSecureChannelRequest
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	OpenSecureChannelRequest::OpenSecureChannelRequest(void)
	: requestHeaderSPtr_()
	, clientCertificate_()
	, requestType_()
	, secureChannelId_()
	, securityMode_()
	, securityPolicyUri_()
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
	OpenSecureChannelRequest::clientCertificate(const ApplicationInstanceCertificate::SPtr clientCertificate)
	{
		clientCertificate_ = clientCertificate;
	}

	ApplicationInstanceCertificate::SPtr  
	OpenSecureChannelRequest::clientCertificate(void) const
	{
		return clientCertificate_;
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
	OpenSecureChannelRequest::secureChannelId(const OpcUaByte *buf, OpcUaInt32 bufLen)
	{
		secureChannelId_.value(buf, bufLen);
	}

	void  
	OpenSecureChannelRequest::secureChannelId(OpcUaByte **buf, OpcUaInt32* bufLen) const
	{
		secureChannelId_.value(buf, bufLen);
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
	OpenSecureChannelRequest::securityPolicyUri(const std::string& securityPolicyUri)
	{
		securityPolicyUri_ = securityPolicyUri;
	}

	std::string  
	OpenSecureChannelRequest::securityPolicyUri(void) const
	{
		std::string str;
		//str = securityPolicyUri_;
		return str;
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
	OpenSecureChannelRequest::requestedLifetime(const Duration& requestedLifetime)
	{
		requestedLifetime_ = requestedLifetime;
	}

	Duration  
	OpenSecureChannelRequest::requestedLifetime(void) const
	{
		return requestedLifetime_;
	}

	void 
	OpenSecureChannelRequest::opcUaBinaryEncode(std::ostream& os) const
	{
		requestHeaderSPtr_->opcUaBinaryEncode(os);
		clientCertificate_->opcUaBinaryEncode(os);
		OpcUaStackCore::opcUaBinaryEncode(os, requestType_);
		OpcUaStackCore::opcUaBinaryEncode(os, secureChannelId_);
		OpcUaStackCore::opcUaBinaryEncode(os, securityMode_);
		OpcUaStackCore::opcUaBinaryEncode(os, securityPolicyUri_);
		OpcUaStackCore::opcUaBinaryEncode(os, clientNonce_);
		OpcUaStackCore::opcUaBinaryEncode(os, requestedLifetime_);
	}

	void 
	OpenSecureChannelRequest::opcUaBinaryDecode(std::istream& is)
	{
		OpcUaUInt32 tmp;
		requestHeaderSPtr_->opcUaBinaryDecode(is);
		clientCertificate_->opcUaBinaryDecode(is);
		OpcUaStackCore::opcUaBinaryDecode(is, tmp); requestType_ = (RequestType)tmp;
		OpcUaStackCore::opcUaBinaryDecode(is, secureChannelId_);
		OpcUaStackCore::opcUaBinaryDecode(is, tmp); securityMode_ = (SecurityMode)tmp;
		OpcUaStackCore::opcUaBinaryDecode(is, securityPolicyUri_);
		OpcUaStackCore::opcUaBinaryDecode(is, clientNonce_);
		OpcUaStackCore::opcUaBinaryDecode(is, requestedLifetime_);
	}

}