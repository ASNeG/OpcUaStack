/*
   Copyright 2015-2019 Kai Huebl (kai@huebl-sgh.de)

   Lizenziert gemäß Apache Licence Version 2.0 (die „Lizenz“); Nutzung dieser
   Datei nur in Übereinstimmung mit der Lizenz erlaubt.
   Eine Kopie der Lizenz erhalten Sie auf http://www.apache.org/licenses/LICENSE-2.0.

   Sofern nicht gemäß geltendem Recht vorgeschrieben oder schriftlich vereinbart,
   erfolgt die Bereitstellung der im Rahmen der Lizenz verbreiteten Software OHNE
   GEWÄHR ODER VORBEHALTE – ganz gleich, ob ausdrücklich oder stillschweigend.

   Informationen über die jeweiligen Bedingungen für Genehmigungen und Einschränkungen
   im Rahmen der Lizenz finden Sie in der Lizenz.

   Autor: Kai Huebl (kai@huebl-sgh.de)
 */

#include "OpcUaStackCore/ServiceSet/CreateSessionResponse.h"
#include "OpcUaStackCore/Base/Utility.h"

namespace OpcUaStackCore
{

	CreateSessionResponse::CreateSessionResponse(void)
	: Object()
	, responseHeader_(boost::make_shared<ResponseHeader>())
	, sessionId_()
	, authenticationToken_()
	, receivedSessionTimeout_()
	, serverNonce_()
	, serverCertificate_()
	, serverEndpoints_(boost::make_shared<EndpointDescriptionArray>())
	, serverSoftwareCertificate_()
	, signatureData_(boost::make_shared<SignatureData>())
	, maxRequestMessageSize_(65536)
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
	CreateSessionResponse::receivedSessionTimeout(const OpcUaDuration receivedSessionTimeout)
	{
		receivedSessionTimeout_ = receivedSessionTimeout;
	}

	OpcUaDuration
	CreateSessionResponse::receivedSessionTimeout(void) const
	{
		return receivedSessionTimeout_;
	}

	OpcUaByteString&
	CreateSessionResponse::serverNonce(void)
	{
		return serverNonce_;
	}

	void
	CreateSessionResponse::serverNonce(const OpcUaByte* buf, OpcUaInt32 bufLen)
	{
		serverNonce_.value(buf, bufLen);
	}
	
	void
	CreateSessionResponse::serverNonce(OpcUaByte** buf, OpcUaInt32* bufLen) const
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

	OpcUaByteString&
	CreateSessionResponse::serverCertificate(void)
	{
		return serverCertificate_;
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

	OpcUaByteString&
	CreateSessionResponse::serverSoftwareCertificate(void)
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

	bool
	CreateSessionResponse::opcUaBinaryEncode(std::ostream& os) const
	{
		bool rc = true;

		rc &= sessionId_.opcUaBinaryEncode(os);
		rc &= authenticationToken_.opcUaBinaryEncode(os);
		rc &= OpcUaNumber::opcUaBinaryEncode(os, receivedSessionTimeout_);
		rc &= serverNonce_.opcUaBinaryEncode(os);
		rc &= serverCertificate_.opcUaBinaryEncode(os);
		rc &= serverEndpoints_->opcUaBinaryEncode(os);
		rc &= serverSoftwareCertificate_.opcUaBinaryEncode(os);
		rc &= signatureData_->opcUaBinaryEncode(os);
		rc &= OpcUaNumber::opcUaBinaryEncode(os, maxRequestMessageSize_);

		return rc;
	}

	bool
	CreateSessionResponse::opcUaBinaryDecode(std::istream& is)
	{
		bool rc = true;

		rc &= sessionId_.opcUaBinaryDecode(is);
		rc &= authenticationToken_.opcUaBinaryDecode(is);
		rc &= OpcUaNumber::opcUaBinaryDecode(is, receivedSessionTimeout_);
		rc &= serverNonce_.opcUaBinaryDecode(is);
		rc &= serverCertificate_.opcUaBinaryDecode(is);
		rc &= serverEndpoints_->opcUaBinaryDecode(is);
		rc &= serverSoftwareCertificate_.opcUaBinaryDecode(is);
		rc &= signatureData_->opcUaBinaryDecode(is);
		rc &= OpcUaNumber::opcUaBinaryDecode(is, maxRequestMessageSize_);

		return rc;
	}

}
