/*
   Copyright 2015-2018 Kai Huebl (kai@huebl-sgh.de)

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

#include "OpcUaStackCore/ServiceSet/CreateSessionRequest.h"

namespace OpcUaStackCore
{

	CreateSessionRequest::CreateSessionRequest(void)
	: requestHeaderSPtr_(constructSPtr<RequestHeader>())
	, clientDescriptionSPtr_(constructSPtr<ApplicationDescription>())
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

	OpcUaByteString&
	CreateSessionRequest::clientNonce(void)
	{
		return clientNonce_;
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

	OpcUaByteString&
	CreateSessionRequest::clientCertificate(void)
	{
		return clientCertificate_;
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
		//requestHeaderSPtr_->opcUaBinaryEncode(os);
		clientDescriptionSPtr_->opcUaBinaryEncode(os);
		serverUri_.opcUaBinaryEncode(os);
		endpointUrl_.opcUaBinaryEncode(os);
		sessionName_.opcUaBinaryEncode(os);
		clientNonce_.opcUaBinaryEncode(os);
		clientCertificate_.opcUaBinaryEncode(os);
		OpcUaNumber::opcUaBinaryEncode(os, requestSessionTimeout_);
		OpcUaNumber::opcUaBinaryEncode(os, maxResponseMessageSize_);
	}

	void 
	CreateSessionRequest::opcUaBinaryDecode(std::istream& is)
	{
		//requestHeaderSPtr_->opcUaBinaryDecode(is);
		clientDescriptionSPtr_->opcUaBinaryDecode(is);
		serverUri_.opcUaBinaryDecode(is);
		endpointUrl_.opcUaBinaryDecode(is);
		sessionName_.opcUaBinaryDecode(is);
		clientNonce_.opcUaBinaryDecode(is);
		clientCertificate_.opcUaBinaryDecode(is);
		OpcUaNumber::opcUaBinaryDecode(is, requestSessionTimeout_);
		OpcUaNumber::opcUaBinaryDecode(is, maxResponseMessageSize_);
	}

}
