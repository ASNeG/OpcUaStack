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
	CreateSessionResponse::serverSoftwareCertificate(const SignedSoftwareCertificateArray::SPtr serverSoftwareCertificate)
	{
		serverSoftwareCertificate_ = serverSoftwareCertificate;
	}

	SignedSoftwareCertificateArray::SPtr 
	CreateSessionResponse::serverSoftwareCertificate(void) const
	{
		return serverSoftwareCertificate_;
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
		OpcUaStackCore::opcUaBinaryEncode(os, sessionId_);
		OpcUaStackCore::opcUaBinaryEncode(os, authenticationToken_);
		OpcUaStackCore::opcUaBinaryEncode(os, receivedSessionTimeout_);
		OpcUaStackCore::opcUaBinaryEncode(os, serverNonce_);
		OpcUaStackCore::opcUaBinaryEncode(os, serverCertificate_);
		serverEndpoints_->opcUaBinaryEncode(os);
		serverSoftwareCertificate_->opcUaBinaryEncode(os);
		signatureData_->opcUaBinaryEncode(os);
		OpcUaStackCore::opcUaBinaryEncode(os, maxRequestMessageSize_);
	}

	void 
	CreateSessionResponse::opcUaBinaryDecode(std::istream& is)
	{
		responseHeader_->opcUaBinaryDecode(is);
		OpcUaStackCore::opcUaBinaryDecode(is, sessionId_);
		OpcUaStackCore::opcUaBinaryDecode(is, authenticationToken_);
		OpcUaStackCore::opcUaBinaryDecode(is, receivedSessionTimeout_);
		OpcUaStackCore::opcUaBinaryDecode(is, serverNonce_);
		OpcUaStackCore::opcUaBinaryDecode(is, serverCertificate_);
		serverEndpoints_->opcUaBinaryDecode(is);
		serverSoftwareCertificate_->opcUaBinaryDecode(is);
		signatureData_->opcUaBinaryDecode(is);
		OpcUaStackCore::opcUaBinaryDecode(is, maxRequestMessageSize_);
	}

}