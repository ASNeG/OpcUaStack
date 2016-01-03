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
#include "OpcUaStackClient/ServiceSet/SessionService.h"

using namespace OpcUaStackCore;

namespace OpcUaStackClient
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// SessionTransaction
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	SessionTransaction::SessionTransaction(void)
	: condition_()
	, statusCode_(Success)
	{
	}

	SessionTransaction::~SessionTransaction(void)
	{
	}

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// SessionService
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	SessionService::SessionService(IOThread* ioThread)
	: mode_(M_SecureChannelAndSession)
	, sessionServiceIf_(nullptr)
	, sessionConfig_()
	, secureChannelClientConfig_()

	, ioThread_(ioThread)
	, secureChannelConnect_(false)
	, sessionConnect_(false)

	, secureChannelClient_(ioThread_)
	, secureChannel_(nullptr)

	, sessionTransaction_()
	, requestHandle_(0)
	, sessionTimeout_(0)
	, maxResponseMessageSize_(0)

	, requestId_(0)
	, authenticationToken_()

	, requestTimeout_(3000)
	, pendingQueue_(*ioThread->ioService().get())
	{
		Component::ioThread(ioThread);

		// init pending queue callback
		pendingQueue_.timeoutCallback().reset(
			boost::bind(&SessionService::pendingQueueTimeout, this, _1)
		);
	}

	SessionService::~SessionService(void)
	{
	}

	void
	SessionService::setConfiguration(
		Mode mode,
		SessionServiceIf* sessionServiceIf,
		SecureChannelClientConfig::SPtr& secureChannelClientConfig,
		SessionConfig::SPtr& sessionConfig
	)
	{
		mode_ = mode;
		sessionServiceIf_ = sessionServiceIf;
		secureChannelClientConfig_ = secureChannelClientConfig;
		sessionConfig_ = sessionConfig;
	}

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// manage secure channel and session
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	void
	SessionService::sessionServiceIf(SessionServiceIf* sessionServiceIf)
	{
		sessionServiceIf_ = sessionServiceIf;
	}

	void
	SessionService::asyncConnect(void)
	{
		ioThread_->run(boost::bind(&SessionService::asyncConnectInternal, this));
	}

	void
	SessionService::asyncConnectInternal(void)
	{
		assert(sessionServiceIf_ != nullptr);
		assert(secureChannelClientConfig_.get() != nullptr);

		if (mode_ == M_SecureChannel) {
			sessionConfig_.reset();
			assert(sessionConfig_.get() == nullptr);
		}
		else {
			assert(sessionConfig_.get() != nullptr);
		}

		if (sessionConfig_.get() != nullptr) {
			requestTimeout_ = sessionConfig_->requestTimeout_;
		}

		secureChannelClient_.secureChannelClientIf(this);
		secureChannel_ = secureChannelClient_.connect(secureChannelClientConfig_);
	}

	OpcUaStatusCode
	SessionService::syncConnect(void)
	{
		SessionTransaction::SPtr sessionTransaction = constructSPtr<SessionTransaction>();
		sessionTransaction->condition_.condition(1,0);
		// FIXME: ...
		sessionTransaction->condition_.waitForCondition();
		return sessionTransaction->statusCode_;
	}

	void
	SessionService::asyncDisconnect(bool deleteSubscriptions)
	{
		ioThread_->run(boost::bind(&SessionService::asyncDisconnectInternal, this, deleteSubscriptions));
	}

	OpcUaStatusCode
	SessionService::syncDisconnect(bool deleteSubscriptions)
	{
		return Success;
	}


	void
	SessionService::asyncDisconnectInternal(bool deleteSubscriptions)
	{
		if (secureChannelConnect_ && sessionConfig_.get() != nullptr) {
			sendCloseSessionRequest(deleteSubscriptions);
		}
		secureChannelClient_.disconnect(secureChannel_);
	}

	void
	SessionService::asyncCancel(uint32_t requestHandle)
	{
		ioThread_->run(boost::bind(&SessionService::asyncCancelInternal, this, requestHandle));
	}

	void
	SessionService::asyncCancelInternal(uint32_t requestHandle)
	{
		if (secureChannelConnect_) {
			sendCancelRequest(requestHandle);
		}
	}

	void
	SessionService::sendCreateSessionRequest(void)
	{
		SecureChannelTransaction::SPtr secureChannelTransaction = constructSPtr<SecureChannelTransaction>();
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
		    .parameter("RequestId", secureChannelTransaction->requestId_)
		    .parameter("SessionName", sessionConfig_->sessionName_);
		secureChannelClient_.asyncWriteMessageRequest(secureChannel_, secureChannelTransaction);
	}

	void
	SessionService::recvCreateSessionResponse(SecureChannelTransaction::SPtr secureChannelTransaction)
	{
		std::iostream ios(&secureChannelTransaction->is_);
		CreateSessionResponse createSessionResponse;
		createSessionResponse.opcUaBinaryDecode(ios);

		sessionTimeout_ = createSessionResponse.receivedSessionTimeout();
		maxResponseMessageSize_ = createSessionResponse.maxRequestMessageSize();
		authenticationToken_ = createSessionResponse.authenticationToken();

		Log(Debug, "session recv CreateSessionResponse")
		    .parameter("RequestId", secureChannelTransaction->requestId_)
		    .parameter("SessionName", sessionConfig_->sessionName_)
		    .parameter("AuthenticationToken", authenticationToken_);

		sendActivateSessionRequest();
	}

	void
	SessionService::sendActivateSessionRequest(void)
	{
		SecureChannelTransaction::SPtr secureChannelTransaction = constructSPtr<SecureChannelTransaction>();
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
		.parameter("RequestId", secureChannelTransaction->requestId_)
		    .parameter("SessionName", sessionConfig_->sessionName_)
		    .parameter("AuthenticationToken", authenticationToken_);
		secureChannelClient_.asyncWriteMessageRequest(secureChannel_, secureChannelTransaction);
	}

	void
	SessionService::recvActivateSessionResponse(SecureChannelTransaction::SPtr secureChannelTransaction)
	{
		std::iostream ios(&secureChannelTransaction->is_);
		ActivateSessionResponse activateSessionResponse;
		activateSessionResponse.opcUaBinaryDecode(ios);

		Log(Debug, "session recv ActivateSessionResponse")
		    .parameter("RequestId", secureChannelTransaction->requestId_)
		    .parameter("SessionName", sessionConfig_->sessionName_)
		    .parameter("AuthenticationToken", authenticationToken_);

		sessionConnect_ = true;
		if (sessionServiceIf_) sessionServiceIf_->sessionStateUpdate(*this, SS_Connect);
	}

	void
	SessionService::sendCloseSessionRequest(bool deleteSubscriptions)
	{
		SecureChannelTransaction::SPtr secureChannelTransaction = constructSPtr<SecureChannelTransaction>();
		secureChannelTransaction->requestTypeNodeId_.nodeId(OpcUaId_CloseSessionRequest_Encoding_DefaultBinary);
		secureChannelTransaction->requestId_ = ++requestId_;
		std::iostream ios(&secureChannelTransaction->os_);

		CloseSessionRequest closeSessionRequest;
		closeSessionRequest.requestHeader()->requestHandle(++requestHandle_);
		closeSessionRequest.requestHeader()->sessionAuthenticationToken() = authenticationToken_;
		closeSessionRequest.deleteSubscriptions(deleteSubscriptions);
		closeSessionRequest.opcUaBinaryEncode(ios);

		Log(Debug, "session send CloseSessionRequest")
		    .parameter("RequestId", secureChannelTransaction->requestId_)
		    .parameter("SessionName", sessionConfig_->sessionName_)
		    .parameter("AuthenticationToken", authenticationToken_);
		secureChannelClient_.asyncWriteMessageRequest(secureChannel_, secureChannelTransaction);
	}

	void
	SessionService::sendCancelRequest(uint32_t requestHandle)
	{
		SecureChannelTransaction::SPtr secureChannelTransaction = constructSPtr<SecureChannelTransaction>();
		secureChannelTransaction->requestTypeNodeId_.nodeId(OpcUaId_CloseSessionRequest_Encoding_DefaultBinary);
		secureChannelTransaction->requestId_ = ++requestId_;
		std::iostream ios(&secureChannelTransaction->os_);

		CancelRequest cancelRequest;
		cancelRequest.requestHeader()->requestHandle(++requestHandle_);
		cancelRequest.requestHeader()->sessionAuthenticationToken() = authenticationToken_;
		cancelRequest.requestHandle(requestHandle);

		Log(Debug, "session send CancelRequest")
		    .parameter("RequestId", secureChannelTransaction->requestId_)
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
	SessionService::handleConnect(SecureChannel* secureChannel)
	{
		secureChannelConnect_ = true;
		if (sessionConfig_.get() == nullptr) {
			if (sessionServiceIf_) sessionServiceIf_->sessionStateUpdate(*this, SS_Connect);
			return;
		}

		// create CreateSessionRequest
		sendCreateSessionRequest();
	}

	void
	SessionService::handleDisconnect(SecureChannel* secureChannel)
	{
		secureChannelConnect_ = false;
		sessionConnect_ = false;
		if (sessionServiceIf_) sessionServiceIf_->sessionStateUpdate(*this, SS_Disconnect);
	}

	void
	SessionService::handleMessageResponse(SecureChannel* secureChannel)
	{
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

		receiveMessage(secureChannel->secureChannelTransaction_);
	}

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// message handling
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	void
	SessionService::receive(Message::SPtr message)
	{
		uint32_t requestTimeout = requestTimeout_;
		ServiceTransaction::SPtr serviceTransaction = boost::static_pointer_cast<ServiceTransaction>(message);
		serviceTransaction->calcRequestTimeout(requestTimeout);

		uint32_t requestType = serviceTransaction->nodeTypeRequest().nodeId<uint32_t>();
		uint32_t requestId = ++requestId_;
		Log(Debug, "session send request")
		    .parameter("RequestId", requestId)
		    .parameter("SessionName", sessionConfig_.get() != nullptr ? sessionConfig_->sessionName_ : "NoSession")
		    .parameter("AuthenticationToken", authenticationToken_)
		    .parameter("RequestType", OpcUaIdMap::longString(requestType));

		if (!sessionConnect_ &&
			requestType != OpcUaId_GetEndpointsRequest_Encoding_DefaultBinary &&
			requestType != OpcUaId_FindServersRequest_Encoding_DefaultBinary
		) {
			serviceTransaction->statusCode(BadSessionClosed);
			Component* componentService = serviceTransaction->componentService();
			componentService->sendAsync(serviceTransaction);
			return;
		}

		if (!secureChannelConnect_) {
			serviceTransaction->statusCode(BadSecureChannelClosed);
			Component* componentService = serviceTransaction->componentService();
			componentService->sendAsync(serviceTransaction);
			return;
		}

		SecureChannelTransaction::SPtr secureChannelTransaction = SecureChannelTransaction::construct();
		secureChannelTransaction->requestTypeNodeId_ = serviceTransaction->nodeTypeRequest();
		secureChannelTransaction->requestId_ = requestId;
		std::iostream ios(&secureChannelTransaction->os_);

		RequestHeader::SPtr requestHeader = serviceTransaction->requestHeader();
		requestHeader->requestHandle(serviceTransaction->transactionId());
		requestHeader->sessionAuthenticationToken() = authenticationToken_;
		requestHeader->timeoutHint(requestTimeout);
		requestHeader->opcUaBinaryEncode(ios);
		serviceTransaction->opcUaBinaryEncodeRequest(ios);

		pendingQueue_.insert(
			secureChannelTransaction->requestId_,
			serviceTransaction,
			requestTimeout
		);

		secureChannelClient_.asyncWriteMessageRequest(secureChannel_, secureChannelTransaction);
	}

	void
	SessionService::pendingQueueTimeout(Object::SPtr object)
	{
		ServiceTransaction::SPtr serviceTransaction = boost::static_pointer_cast<ServiceTransaction>(object);

		Log(Debug, "session send request timeout")
		    .parameter("RequestId", serviceTransaction->requestId_)
	    	.parameter("SessionName", sessionConfig_.get() != nullptr ? sessionConfig_->sessionName_ : "NoSession")
	    	.parameter("AuthenticationToken", authenticationToken_)
			.parameter("NodeType", serviceTransaction->nodeTypeResponse())
			.parameter("RequestHandle", serviceTransaction->transactionId());

		serviceTransaction->statusCode(BadTimeout);
		Component* componentService = serviceTransaction->componentService();
		componentService->sendAsync(serviceTransaction);
	}

	void
	SessionService::receiveMessage(SecureChannelTransaction::SPtr secureChannelTransaction)
	{
		std::iostream ios(&secureChannelTransaction->is_);
		ResponseHeader::SPtr responseHeader = ResponseHeader::construct();
		responseHeader->opcUaBinaryDecode(ios);

		Object::SPtr objectSPtr = pendingQueue_.remove(secureChannelTransaction->requestId_);
		if (objectSPtr.get() == nullptr) {
			Log(Error, "session pending queue error, because element not exist")
				.parameter("RequestId", secureChannelTransaction->requestId_)
				.parameter("SessionName", sessionConfig_.get() != nullptr ? sessionConfig_->sessionName_ : "NoSession")
				.parameter("AuthenticationToken", authenticationToken_)
				.parameter("TypeId", secureChannelTransaction->responseTypeNodeId_)
				.parameter("RequestHandle", responseHeader->requestHandle());
			char c; while (ios.get(c));
			return;
		}

		ServiceTransaction::SPtr serviceTransaction = boost::static_pointer_cast<ServiceTransaction>(objectSPtr);
		serviceTransaction->opcUaBinaryDecodeResponse(ios);
		serviceTransaction->responseHeader(responseHeader);
		serviceTransaction->statusCode(responseHeader->serviceResult());

		Log(Debug, "session receive response")
		    .parameter("RequestId", secureChannelTransaction->requestId_)
	    	.parameter("SessionName", sessionConfig_.get() != nullptr ? sessionConfig_->sessionName_ : "NoSession")
	    	.parameter("AuthenticationToken", authenticationToken_)
			.parameter("ResponseType", OpcUaIdMap::longString(serviceTransaction->nodeTypeResponse().nodeId<uint32_t>()))
			.parameter("ServiceResult", OpcUaStatusCodeMap::shortString(serviceTransaction->responseHeader()->serviceResult()));

		Component* componentService = serviceTransaction->componentService();
		componentService->sendAsync(serviceTransaction);
	}

}
