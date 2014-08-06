#include "OpcUaStackCore/ServiceSet/CreateSessionRequest.h"

namespace OpcUaStackCore
{

	CreateSessionRequest::CreateSessionRequest(void)
	: requestHeaderSPtr_()
	, clientDescriptionSPtr_()
	, serverUri_()
	, endpointUrl_()
	, sessionName_()
	, clientNonce_()
	, clientCertificate_()
	, requestSessionTimeout_()
	, maxResponseMessageSize_()
	{
	}

	CreateSessionRequest::~CreateSessionRequest(void)
	{
	}

	void 
	CreateSessionRequest::requestHeader(const RequestHeader::SPtr requestHeaderSPtr)
	{
		requestHeaderSPtr_ = requestHeaderSPtr;
	}

	RequestHeader::SPtr 
	CreateSessionRequest::requestHeader(void) const
	{
		return requestHeaderSPtr_;
	}

	void 
	CreateSessionRequest::clientDescription(const ApplicationDescription::SPtr clientDescriptionSPtr)
	{
		clientDescriptionSPtr_ = clientDescriptionSPtr;
	}

	ApplicationDescription::SPtr 
	CreateSessionRequest::clientDescription(void) const
	{
		return clientDescriptionSPtr_;
	}

	void 
	CreateSessionRequest::serverUri(const std::string& serverUri)
	{
		serverUri_ = serverUri;
	}

	std::string 
	CreateSessionRequest::serverUri(void) const
	{
		return serverUri_.value();
	}

	void 
	CreateSessionRequest::endpointUrl(const std::string& endpointUrl)
	{
		endpointUrl_ = endpointUrl;
	}

	std::string 
	CreateSessionRequest::endpointUrl(void) const
	{
		return endpointUrl_.value();
	}

	void 
	CreateSessionRequest::sessionName(const std::string& sessionName)
	{
		sessionName_ = sessionName;
	}

	std::string 
	CreateSessionRequest::sessionName(void) const
	{
		return sessionName_.value();
	}

	void 
	CreateSessionRequest::clientNonce(const OpcUaByte *buf, OpcUaInt32 bufLen)
	{
		clientNonce_.value(buf, bufLen);
	}

	void 
	CreateSessionRequest::clientNonce(OpcUaByte **buf, OpcUaInt32* bufLen) const
	{
		clientNonce_.value(buf, bufLen);
	}

	void 
	CreateSessionRequest::clientCertificate(const OpcUaByte *buf, OpcUaInt32 bufLen)
	{
		clientCertificate_.value(buf, bufLen);
	}

	void 
	CreateSessionRequest::clientCertificate(OpcUaByte **buf, OpcUaInt32* bufLen) const
	{
		clientCertificate_.value(buf, bufLen);
	}

	void 
	CreateSessionRequest::requestSessionTimeout(const Duration requestSessionTimeout)
	{
		requestSessionTimeout_ = requestSessionTimeout;
	}

	Duration 
	CreateSessionRequest::requestSessionTimeout(void) const
	{
		return requestSessionTimeout_;
	}

	void 
	CreateSessionRequest::maxResponseMessageSize(const OpcUaUInt32& maxResponseMessageSize)
	{
		maxResponseMessageSize_ = maxResponseMessageSize;
	}

	OpcUaUInt32 CreateSessionRequest::maxResponseMessageSize(void) const
	{
		return maxResponseMessageSize_;
	}

	void 
	CreateSessionRequest::opcUaBinaryEncode(std::ostream& os) const
	{
		requestHeaderSPtr_->opcUaBinaryEncode(os);
		clientDescriptionSPtr_->opcUaBinaryEncode(os);
		OpcUaStackCore::opcUaBinaryEncode(os, serverUri_);
		OpcUaStackCore::opcUaBinaryEncode(os, endpointUrl_);
		OpcUaStackCore::opcUaBinaryEncode(os, sessionName_);
		OpcUaStackCore::opcUaBinaryEncode(os, clientNonce_);
		OpcUaStackCore::opcUaBinaryEncode(os, clientCertificate_);
		OpcUaStackCore::opcUaBinaryEncode(os, requestSessionTimeout_);
		OpcUaStackCore::opcUaBinaryEncode(os, maxResponseMessageSize_);
	}

	void 
	CreateSessionRequest::opcUaBinaryDecode(std::istream& is)
	{
		requestHeaderSPtr_->opcUaBinaryDecode(is);
		clientDescriptionSPtr_->opcUaBinaryDecode(is);
		OpcUaStackCore::opcUaBinaryDecode(is, serverUri_);
		OpcUaStackCore::opcUaBinaryDecode(is, endpointUrl_);
		OpcUaStackCore::opcUaBinaryDecode(is, sessionName_);
		OpcUaStackCore::opcUaBinaryDecode(is, clientNonce_);
		OpcUaStackCore::opcUaBinaryDecode(is, clientCertificate_);
		OpcUaStackCore::opcUaBinaryDecode(is, requestSessionTimeout_);
		OpcUaStackCore::opcUaBinaryDecode(is, maxResponseMessageSize_);
	}

}