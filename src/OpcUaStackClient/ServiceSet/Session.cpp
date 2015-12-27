/*
   Copyright 2015 Kai Huebl (kai@huebl-sgh.de)

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


#include "OpcUaStackCore/Base/Log.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaIdentifier.h"
#include "OpcUaStackCore/ServiceSet/CreateSessionRequest.h"
#include "OpcUaStackCore/ServiceSet/CreateSessionResponse.h"
#include "OpcUaStackCore/ServiceSet/ActivateSessionRequest.h"
#include "OpcUaStackCore/ServiceSet/ActivateSessionResponse.h"
#include "OpcUaStackCore/ServiceSet/CloseSessionRequest.h"
#include "OpcUaStackCore/ServiceSet/CancelRequest.h"
#include "OpcUaStackCore/ServiceSet/AnonymousIdentityToken.h"
#include "OpcUaStackClient/ServiceSet/Session.h"

using namespace OpcUaStackCore;

namespace OpcUaStackClient
{

	Session::Session(IOService& ioService)
	: ioService_(&ioService)
	, sessionIf_(nullptr)
	, sessionConfig_()

	, secureChannelConnect_(false)
	, secureChannelClientConfig_()
	, secureChannelClient_(&ioService)
	, secureChannel_(nullptr)

	, requestHandle_(0)
	, sessionTimeout_(0)
	, maxResponseMessageSize_(0)

	, requestId_(0)
	, authenticationToken_()
	{
	}

	Session::~Session(void)
	{
	}

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// manage secure channel and session
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	void
	Session::sessionIf(SessionIf* sessionIf)
	{
		sessionIf_ = sessionIf;
	}

	void
	Session::asyncConnect(SecureChannelClientConfig::SPtr& secureChannelClientConfig)
	{
		SessionConfig::SPtr sessionConfig;
		asyncConnect(sessionConfig, secureChannelClientConfig);
	}

	void
	Session::asyncConnect(SessionConfig::SPtr& sessionConfig, SecureChannelClientConfig::SPtr& secureChannelClientConfig)
	{
		sessionConfig_ = sessionConfig;
		secureChannelClientConfig_ = secureChannelClientConfig;

		secureChannelClient_.secureChannelClientIf(this);
		secureChannel_ = secureChannelClient_.connect(secureChannelClientConfig);
	}

	void
	Session::asyncDisconnect(bool deleteSubscriptions)
	{
		if (secureChannelConnect_ && sessionConfig_.get() != nullptr) {
			sendCloseSessionRequest(deleteSubscriptions);
		}
		secureChannelClient_.disconnect(secureChannel_);
	}

	void
	Session::asyncCancel(uint32_t requestHandle)
	{
		if (secureChannelConnect_) {
			sendCancelRequest(requestHandle);
		}
	}

	void
	Session::sendCreateSessionRequest(void)
	{
		SecureChannelTransaction::SPtr secureChannelTransaction = construct<SecureChannelTransaction>();
		secureChannelTransaction->requestTypeNodeId_.nodeId(OpcUaId_CreateSessionRequest_Encoding_DefaultBinary);
		secureChannelTransaction->requestId_ = ++requestId_;
		std::iostream ios(&secureChannelTransaction->os_);

		CreateSessionRequest createSessionRequest;
		createSessionRequest.requestHeader()->requestHandle(++requestHandle_);
		createSessionRequest.clientDescription(sessionConfig_->applicationDescription_);
		createSessionRequest.endpointUrl(secureChannelClientConfig_->endpointUrl());
		createSessionRequest.sessionName(sessionConfig_->sessionName_);
		createSessionRequest.clientNonce((OpcUaStackCore::OpcUaByte*)"\000", 1);
		createSessionRequest.requestSessionTimeout(sessionConfig_->sessionTimeout_);
		createSessionRequest.maxResponseMessageSize(sessionConfig_->maxResponseMessageSize_);
		createSessionRequest.opcUaBinaryEncode(ios);

		Log(Debug, "session send CreateSessionRequest")
		    .parameter("SessionName", sessionConfig_->sessionName_);
		secureChannelClient_.asyncWriteMessageRequest(secureChannel_, secureChannelTransaction);
	}

	void
	Session::recvCreateSessionResponse(SecureChannelTransaction::SPtr secureChannelTransaction)
	{
		std::iostream ios(&secureChannelTransaction->is_);
		CreateSessionResponse createSessionResponse;
		createSessionResponse.opcUaBinaryDecode(ios);

		sessionTimeout_ = createSessionResponse.receivedSessionTimeout();
		maxResponseMessageSize_ = createSessionResponse.maxRequestMessageSize();
		authenticationToken_ = createSessionResponse.authenticationToken();

		Log(Debug, "session recv CreateSessionResponse")
		    .parameter("SessionName", sessionConfig_->sessionName_)
		    .parameter("AuthenticationToken", authenticationToken_);

		sendActivateSessionRequest();
	}

	void
	Session::sendActivateSessionRequest(void)
	{
		SecureChannelTransaction::SPtr secureChannelTransaction = construct<SecureChannelTransaction>();
		secureChannelTransaction->requestTypeNodeId_.nodeId(OpcUaId_ActivateSessionRequest_Encoding_DefaultBinary);
		secureChannelTransaction->requestId_ = ++requestId_;
		std::iostream ios(&secureChannelTransaction->os_);

		OpcUaString::SPtr localeIdSPtr = OpcUaString::construct();
		*localeIdSPtr = "en";

		ActivateSessionRequest activateSessionRequest;
		activateSessionRequest.requestHeader()->requestHandle(++requestHandle_);
		activateSessionRequest.requestHeader()->sessionAuthenticationToken() = authenticationToken_;
		activateSessionRequest.localeIds()->resize(1);
		activateSessionRequest.localeIds()->push_back(localeIdSPtr);

		// user identity token
		activateSessionRequest.userIdentityToken()->parameterTypeId().nodeId(OpcUaId_AnonymousIdentityToken_Encoding_DefaultBinary);
		AnonymousIdentityToken::SPtr anonymousIdentityToken = activateSessionRequest.userIdentityToken()->parameter<AnonymousIdentityToken>();
		anonymousIdentityToken->policyId("Anonymous_Policy");
		activateSessionRequest.opcUaBinaryEncode(ios);

		Log(Debug, "session send ActivateSessionRequest")
		    .parameter("SessionName", sessionConfig_->sessionName_)
		    .parameter("AuthenticationToken", authenticationToken_);
		secureChannelClient_.asyncWriteMessageRequest(secureChannel_, secureChannelTransaction);
	}

	void
	Session::recvActivateSessionResponse(SecureChannelTransaction::SPtr secureChannelTransaction)
	{
		std::iostream ios(&secureChannelTransaction->is_);
		ActivateSessionResponse activateSessionResponse;
		activateSessionResponse.opcUaBinaryDecode(ios);

		Log(Debug, "session recv ActivateSessionResponse")
		    .parameter("SessionName", sessionConfig_->sessionName_)
		    .parameter("AuthenticationToken", authenticationToken_);

		if (sessionIf_) sessionIf_->sessionStateUpdate(*this, SS_Connect);
	}

	void
	Session::sendCloseSessionRequest(bool deleteSubscriptions)
	{
		SecureChannelTransaction::SPtr secureChannelTransaction = construct<SecureChannelTransaction>();
		secureChannelTransaction->requestTypeNodeId_.nodeId(OpcUaId_CloseSessionRequest_Encoding_DefaultBinary);
		secureChannelTransaction->requestId_ = ++requestId_;
		std::iostream ios(&secureChannelTransaction->os_);

		CloseSessionRequest closeSessionRequest;
		closeSessionRequest.requestHeader()->requestHandle(++requestHandle_);
		closeSessionRequest.requestHeader()->sessionAuthenticationToken() = authenticationToken_;
		closeSessionRequest.deleteSubscriptions(deleteSubscriptions);

		Log(Debug, "session send CloseSessionRequest")
		    .parameter("SessionName", sessionConfig_->sessionName_)
		    .parameter("AuthenticationToken", authenticationToken_);
		secureChannelClient_.asyncWriteMessageRequest(secureChannel_, secureChannelTransaction);
	}

	void
	Session::sendCancelRequest(uint32_t requestHandle)
	{
		SecureChannelTransaction::SPtr secureChannelTransaction = construct<SecureChannelTransaction>();
		secureChannelTransaction->requestTypeNodeId_.nodeId(OpcUaId_CloseSessionRequest_Encoding_DefaultBinary);
		secureChannelTransaction->requestId_ = ++requestId_;
		std::iostream ios(&secureChannelTransaction->os_);

		CancelRequest cancelRequest;
		cancelRequest.requestHeader()->requestHandle(++requestHandle_);
		cancelRequest.requestHeader()->sessionAuthenticationToken() = authenticationToken_;
		cancelRequest.requestHandle(requestHandle);

		Log(Debug, "session send CancelRequest")
		    .parameter("SessionName", sessionConfig_->sessionName_)
		    .parameter("AuthenticationToken", authenticationToken_);
		secureChannelClient_.asyncWriteMessageRequest(secureChannel_, secureChannelTransaction);
	}

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// SecureChannelClientIf
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	void
	Session::handleConnect(SecureChannel* secureChannel)
	{
		secureChannelConnect_ = true;
		if (sessionConfig_.get() == nullptr) {
			if (sessionIf_) sessionIf_->sessionStateUpdate(*this, SS_Connect);
			return;
		}

		// create CreateSessionRequest
		sendCreateSessionRequest();
	}

	void
	Session::handleDisconnect(SecureChannel* secureChannel)
	{
		secureChannelConnect_ = false;
		if (sessionIf_) sessionIf_->sessionStateUpdate(*this, SS_Disconnect);
	}

	void
	Session::handleMessageResponse(SecureChannel* secureChannel)
	{
		std::cout << "handleMessageResponse" << std::endl;

		switch (secureChannel->secureChannelTransaction_->responseTypeNodeId_.nodeId<OpcUaUInt32>())
		{
			case OpcUaId_CreateSessionResponse_Encoding_DefaultBinary:
			{
				recvCreateSessionResponse(secureChannel->secureChannelTransaction_);
				return;
			}
			case OpcUaId_ActivateSessionResponse_Encoding_DefaultBinary:
			{
				recvActivateSessionResponse(secureChannel->secureChannelTransaction_);
				return;
			}
		}

	}

}
