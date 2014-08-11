#include "OpcUaStackCore/ServiceSet/CreateSessionResponse.h"

namespace OpcUaStackCore
{

	CreateSessionResponse::CreateSessionResponse(void)
	: responseHeader_()
	, sessionId_()
	, authenticationToken_()
	, receivedSessionTimeout_()
	, serverNonce_()
	, serverCertificate_()
	, serverEndpoints_()
	, serverSoftwareCertificate_()
	, signatureData_()
	, maxRequestMessageSize_()
	{
	}

	CreateSessionResponse::~CreateSessionResponse(void)
	{
	}

	void 
	CreateSessionResponse::responseHeader(const ResponseHeader::SPtr responseHeader)
	{
		responseHeader_ = responseHeader;
	}

	ResponseHeader::SPtr 
	CreateSessionResponse::responseHeader(void) const
	{
		return responseHeader_;
	}
	
	OpcUaNodeId&
	CreateSessionResponse::sessionId(void) 
	{
		return sessionId_;
	}

	OpcUaNodeId& 
	CreateSessionResponse::authenticationToken(void) 
	{
		return authenticationToken_;
	}

	void 
	CreateSessionResponse::receivedSessionTimeout(const Duration receivedSessionTimeout)
	{
		receivedSessionTimeout_ = receivedSessionTimeout;
	}

	Duration 
	CreateSessionResponse::receivedSessionTimeout(void) const
	{
		return receivedSessionTimeout_;
	}

	void CreateSessionResponse::serverNonce(const OpcUaByte* buf, OpcUaInt32 bufLen)
	{
		serverNonce_.value(buf, bufLen);
	}
	
	void CreateSessionResponse::serverNonce(OpcUaByte** buf, OpcUaInt32* bufLen) const
	{
		serverNonce_.value(buf, bufLen);
	}

	void 
	CreateSessionResponse::serverCertificate(OpcUaByte** buf, OpcUaInt32* bufLen) const
	{
		serverCertificate_.value(buf, bufLen);
	}

	void 
	CreateSessionResponse::serverCertificate(const OpcUaByte* buf, OpcUaInt32 bufLen)
	{
		serverCertificate_.value(buf, bufLen);
	}

	void 
	CreateSessionResponse::serverEndpoints(const EndpointDescriptionArray::SPtr serverEndpoints)
	{
		serverEndpoints_ = serverEndpoints;
	}

	EndpointDescriptionArray::SPtr 
	CreateSessionResponse::serverEndpoints(void) const
	{
		return serverEndpoints_;
	}

	void 
	CreateSessionResponse::serverSoftwareCertificate(OpcUaByte** buf, OpcUaInt32* bufLen) const
	{
		serverSoftwareCertificate_.value(buf, bufLen);
	}

	void 
	CreateSessionResponse::serverSoftwareCertificate(const OpcUaByte* buf, OpcUaInt32 bufLen)
	{
		serverSoftwareCertificate_.value(buf, bufLen);
	}

	void 
	CreateSessionResponse::signatureData(const SignatureData::SPtr signatureData)
	{
		signatureData_ = signatureData;
	}

	SignatureData::SPtr 
	CreateSessionResponse::signatureData(void) const
	{
		return signatureData_;
	}

	void 
	CreateSessionResponse::maxRequestMessageSize(const OpcUaUInt32 maxRequestMessageSize)
	{
		maxRequestMessageSize_ = maxRequestMessageSize;
	}

	OpcUaUInt32 
	CreateSessionResponse::maxRequestMessageSize(void) const
	{
		return maxRequestMessageSize_;
	}

	void 
	CreateSessionResponse::opcUaBinaryEncode(std::ostream& os) const
	{
		responseHeader_->opcUaBinaryEncode(os);
		sessionId_.opcUaBinaryEncode(os);
		authenticationToken_.opcUaBinaryEncode(os);
		OpcUaNumber::opcUaBinaryEncode(os, receivedSessionTimeout_);
		serverNonce_.opcUaBinaryEncode(os);
		serverCertificate_.opcUaBinaryEncode(os);
		serverEndpoints_->opcUaBinaryEncode(os);
		serverSoftwareCertificate_.opcUaBinaryEncode(os);
		signatureData_->opcUaBinaryEncode(os);
		OpcUaNumber::opcUaBinaryEncode(os, maxRequestMessageSize_);
	}

	void 
	CreateSessionResponse::opcUaBinaryDecode(std::istream& is)
	{
		responseHeader_->opcUaBinaryDecode(is);
		sessionId_.opcUaBinaryDecode(is);
		authenticationToken_.opcUaBinaryDecode(is);
		OpcUaNumber::opcUaBinaryDecode(is, receivedSessionTimeout_);
		serverNonce_.opcUaBinaryDecode(is);
		serverCertificate_.opcUaBinaryDecode(is);
		serverEndpoints_->opcUaBinaryDecode(is);
		serverSoftwareCertificate_.opcUaBinaryDecode(is);
		signatureData_->opcUaBinaryDecode(is);
		OpcUaNumber::opcUaBinaryDecode(is, maxRequestMessageSize_);
	}

}