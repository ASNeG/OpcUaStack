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

#include <boost/make_shared.hpp>
#include "OpcUaStackCore/Base/Log.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaIdentifier.h"
#include "OpcUaStackCore/ServiceSet/ActivateSessionRequest.h"
#include "OpcUaStackCore/ServiceSet/ActivateSessionResponse.h"
#include "OpcUaStackCore/ServiceSet/CloseSessionRequest.h"
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
	: sm_()
	, ctx_(new SessionServiceContext())
	{
		Component::ioThread(ioThread);
		ctx_->slotTimerElement_ = boost::make_shared<SlotTimerElement>();
		ctx_->ioThread_ = ioThread;

		// init pending queue callback
		ctx_->pendingQueue_.ioService(*ioThread->ioService().get());
		ctx_->pendingQueue_.timeoutCallback().reset(
			boost::bind(&SessionService::pendingQueueTimeout, this, _1)
		);

		// init state machine
		sm_.setCtx(ctx_);
		sm_.setStateId(SessionServiceStateId::Disconnected);
	}

	SessionService::~SessionService(void)
	{
		// stop timer element
		if (ctx_->slotTimerElement_.get() != nullptr) {
			ctx_->ioThread_->slotTimer()->stop(ctx_->slotTimerElement_);
			ctx_->slotTimerElement_.reset();
		}

		delete ctx_;
		ctx_ = nullptr;
	}

	void
	SessionService::setConfiguration(
		SessionMode sessionMode,
		SessionServiceIf* sessionServiceIf,
		SecureChannelClientConfig::SPtr& secureChannelClientConfig,
		SessionConfig::SPtr& sessionConfig
	)
	{
		ctx_->sessionMode_ = sessionMode;
		ctx_->sessionServiceIf_ = sessionServiceIf;
		ctx_->secureChannelClientConfig_ = secureChannelClientConfig;
		ctx_->sessionConfig_ = sessionConfig;
	}

	void
	SessionService::updateEndpointUrl(const std::string& endpointUrl)
	{
		ctx_->secureChannelClientConfig_->endpointUrl(endpointUrl);
	}

	void
	SessionService::sessionServiceIf(SessionServiceIf* sessionServiceIf)
	{
		ctx_->sessionServiceIf_ = sessionServiceIf;
	}

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// manage secure channel and session
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------

	void
	SessionService::reconnectTimeout(void)
	{
		SessionTransaction::SPtr sessionTransaction;
		asyncConnectInternal(sessionTransaction);
	}

	void
	SessionService::asyncConnect(void)
	{
		SessionTransaction::SPtr sessionTransaction;
		ctx_->ioThread_->run(
			boost::bind(&SessionService::asyncConnectInternal, this, sessionTransaction)
		);
	}

	void
	SessionService::asyncConnectInternal(SessionTransaction::SPtr& sessionTransaction)
	{
		sm_.event(
			[this](SessionServiceStateIf* sssif) {
				return sssif->asyncConnect();
			}
		);
	}

	OpcUaStatusCode
	SessionService::syncConnect(void)
	{
		SessionTransaction::SPtr sessionTransaction = constructSPtr<SessionTransaction>();
		sessionTransaction->operation_ = SessionTransaction::OP_Connect;
		sessionTransaction->condition_.condition(1,0);
		ctx_->ioThread_->run(
			boost::bind(&SessionService::asyncConnectInternal, this, sessionTransaction)
		);
		sessionTransaction->condition_.waitForCondition();
		return sessionTransaction->statusCode_;
	}

	void
	SessionService::asyncDisconnect(bool deleteSubscriptions)
	{
		SessionTransaction::SPtr sessionTransaction;
		ctx_->ioThread_->run(
			boost::bind(&SessionService::asyncDisconnectInternal, this, sessionTransaction, deleteSubscriptions)
		);
	}

	void
	SessionService::asyncDisconnectInternal(SessionTransaction::SPtr& sessionTransaction, bool deleteSubscriptions)
	{
		sm_.event(
			[this, deleteSubscriptions](SessionServiceStateIf* sssif) {
				return sssif->asyncDisconnect(deleteSubscriptions);
			}
		);

#if 0
		// check secure channel state
		if (secureChannelState_ == SCS_Disconnecting || secureChannelState_ == SCS_Disconnected) {
			Log(Error, "disconnect operation in invalid state")
			    .parameter("SessionName", mode_ != M_SecureChannel ? sessionConfig_->sessionName_ : "None")
				.parameter("SecureChannelState", secureChannelState_);

			if (sessionTransaction.get() != nullptr) {
				sessionTransaction->statusCode_ = BadInvalidState;
				sessionTransaction->condition_.conditionValueDec();
			}
			return;
		}

		if (secureChannelState_ == SCS_DisconnectedWait) {
			ioThread_->slotTimer()->stop(slotTimerElement_);

			secureChannelState_ = SCS_Disconnected;
			if (sessionTransaction.get() != nullptr) {
				sessionTransaction->statusCode_ = Success;
				sessionTransaction->condition_.conditionValueDec();
			}
			return;
		}

		// check if a connect operation is running - stop the connect operation
		if (secureChannelState_ == SCS_Connecting) {
			if (sessionTransaction_.get() != nullptr) {
				sessionTransaction_->statusCode_ = BadSessionClosed;
				sessionTransaction_->condition_.conditionValueDec();
				//sessionTransaction_.reset();
			}
		}

		// set session transaction
		sessionTransaction_ = sessionTransaction;

		// FIXME: only if session is activated...
		if (secureChannelState_ == SCS_Connected && sessionConfig_.get() != nullptr) {
			sendCloseSessionRequest(deleteSubscriptions);
		}

		secureChannelState_ = SCS_Disconnecting;
		//secureChannelClient_.disconnect(secureChannel_);
#endif
	}

	OpcUaStatusCode
	SessionService::syncDisconnect(bool deleteSubscriptions)
	{
		//
		// Only a separate shutdown thread can be used. Do not use
		// the thread from io service
		//

		SessionTransaction::SPtr sessionTransaction = constructSPtr<SessionTransaction>();
		sessionTransaction->operation_ = SessionTransaction::OP_Disconnect;
		sessionTransaction->condition_.condition(1,0);
		ctx_->ioThread_->run(boost::bind(&SessionService::asyncDisconnectInternal, this, sessionTransaction, deleteSubscriptions));
		sessionTransaction->condition_.waitForCondition();
		return sessionTransaction->statusCode_;
	}

	void
	SessionService::asyncCancel(uint32_t requestHandle)
	{
		ctx_->ioThread_->run(
			boost::bind(&SessionService::asyncCancelInternal, this, requestHandle)
		);
	}

	void
	SessionService::asyncCancelInternal(uint32_t requestHandle)
	{
		ctx_->sendCancelRequest(ctx_->secureChannel_, requestHandle);
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
		ctx_->secureChannel_ = secureChannel;
		sm_.event(
			[this, secureChannel](SessionServiceStateIf* sssif) {
				return sssif->handleConnect(secureChannel);
			}
		);
	}

	void
	SessionService::handleDisconnect(SecureChannel* secureChannel)
	{
		sm_.event(
			[this, secureChannel](SessionServiceStateIf* sssif) {
				return sssif->handleDisconnect(secureChannel);
			}
		);

#if 0

		Log(Debug, "session service handle disconnect");

		secureChannelState_ = SCS_Disconnected;
		if (mode_ != M_SecureChannel) {
			if (sessionConfig_->reconnectTimeout() != 0) {

				// start reconnect timer
				slotTimerElement_->expireFromNow(sessionConfig_->reconnectTimeout());
				slotTimerElement_->callback().reset(
					boost::bind(&SessionService::reconnectTimeout, this)
				);
				ioThread_->slotTimer()->start(slotTimerElement_);
				secureChannelState_ = SCS_DisconnectedWait;
			}
		}

		sessionConnect_ = false;
		if (sessionServiceIf_) sessionServiceIf_->sessionStateUpdate(*this, SS_Disconnect);

		if (sessionTransaction_.get() != nullptr) {
			if (sessionTransaction_->operation_ == SessionTransaction::OP_Connect) {
				sessionTransaction_->statusCode_ = BadSessionClosed;
			}
			else {
				sessionTransaction_->statusCode_ = Success;
			}
			sessionTransaction_->condition_.conditionValueDec();
			//sessionTransaction_.reset();
			return;
		}
#endif
	}

	void
	SessionService::handleMessageResponse(SecureChannel* secureChannel)
	{
		// decode response header
		std::iostream ios(&secureChannel->secureChannelTransaction_->is_);
		ResponseHeader::SPtr responseHeader = constructSPtr<ResponseHeader>();
		responseHeader->opcUaBinaryDecode(ios);

		switch (secureChannel->secureChannelTransaction_->responseTypeNodeId_.nodeId<OpcUaUInt32>())
		{
			case OpcUaId_CreateSessionResponse_Encoding_DefaultBinary:
			{
				sm_.event(
					[this, secureChannel, responseHeader](SessionServiceStateIf* sssif) {
						return sssif->recvCreateSessionResponse(secureChannel, responseHeader);
					}
				);

				return;
			}
			case OpcUaId_ActivateSessionResponse_Encoding_DefaultBinary:
			{
				sm_.event(
					[this, secureChannel, responseHeader](SessionServiceStateIf* sssif) {
						return sssif->recvActivateSessionResponse(secureChannel, responseHeader);
					}
				);

				return;
			}
			case OpcUaId_CloseSessionResponse_Encoding_DefaultBinary:
			{
				sm_.event(
					[this, secureChannel, responseHeader](SessionServiceStateIf* sssif) {
						return sssif->recvCloseSessionResponse(secureChannel, responseHeader);
					}
				);

				return;
			}
		}

		sm_.event(
			[this, secureChannel, responseHeader](SessionServiceStateIf* sssif) {
				return sssif->recvMessageResponse(secureChannel, responseHeader);
			}
		);
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
		sm_.event(
			[this, message](SessionServiceStateIf* sssif) {
				return sssif->sendMessageRequest(message);
			}
		);

#if 0
		uint32_t requestTimeout = requestTimeout_;
		ServiceTransaction::SPtr serviceTransaction = boost::static_pointer_cast<ServiceTransaction>(message);
		serviceTransaction->calcRequestTimeout(requestTimeout);

		uint32_t requestType = serviceTransaction->nodeTypeRequest().nodeId<uint32_t>();
		uint32_t requestId = ++requestId_;
		Log(Debug, "session send request")
		    .parameter("RequestId", requestId)
		    .parameter("SessionName", mode_ != M_SecureChannel ? sessionConfig_->sessionName_ : "NoSession")
		    .parameter("AuthenticationToken", authenticationToken_)
		    .parameter("RequestType", OpcUaIdMap::longString(requestType));

		if (!sessionConnect_ &&
			requestType != OpcUaId_GetEndpointsRequest_Encoding_DefaultBinary &&
			requestType != OpcUaId_FindServersRequest_Encoding_DefaultBinary &&
			requestType != OpcUaId_RegisterServerRequest_Encoding_DefaultBinary
		) {
			serviceTransaction->statusCode(BadSessionClosed);
			Component* componentService = serviceTransaction->componentService();
			componentService->sendAsync(serviceTransaction);
			return;
		}

		if (secureChannelState_ != SCS_Connected) {
			serviceTransaction->statusCode(BadSecureChannelClosed);
			Component* componentService = serviceTransaction->componentService();
			componentService->sendAsync(serviceTransaction);
			return;
		}

		SecureChannelTransaction::SPtr secureChannelTransaction = constructSPtr<SecureChannelTransaction>();
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
#endif
	}

	void
	SessionService::pendingQueueTimeout(Object::SPtr object)
	{
		sm_.event(
			[this, object](SessionServiceStateIf* sssif) {
				return sssif->pendingQueueTimeout(object);
			}
		);

#if 0
		ServiceTransaction::SPtr serviceTransaction = boost::static_pointer_cast<ServiceTransaction>(object);

		Log(Debug, "session send request timeout")
		    .parameter("RequestId", serviceTransaction->requestId_)
	    	.parameter("SessionName", mode_ != M_SecureChannel ? sessionConfig_->sessionName_ : "NoSession")
	    	.parameter("AuthenticationToken", authenticationToken_)
			.parameter("NodeType", serviceTransaction->nodeTypeResponse())
			.parameter("RequestHandle", serviceTransaction->transactionId());

		OpcUaStatusCode statusCode = BadTimeout;
		if (!sessionConnect_) statusCode = BadSessionClosed;

		serviceTransaction->statusCode(statusCode);
		Component* componentService = serviceTransaction->componentService();
		componentService->sendAsync(serviceTransaction);
#endif
	}

#if 0
	void
	SessionService::receiveMessage(SecureChannelTransaction::SPtr secureChannelTransaction, ResponseHeader::SPtr responseHeader)
	{
		if (secureChannelTransaction->responseTypeNodeId_ == OpcUaNodeId(OpcUaId_CloseSessionResponse_Encoding_DefaultBinary)) {
			Log(Debug, "receive close session response");

			secureChannelClient_.disconnect(secureChannel_);

			return;
		}

		std::iostream ios(&secureChannelTransaction->is_);

		Object::SPtr objectSPtr = pendingQueue_.remove(secureChannelTransaction->requestId_);
		if (objectSPtr.get() == nullptr) {
			Log(Error, "session pending queue error, because element not exist")
				.parameter("RequestId", secureChannelTransaction->requestId_)
				.parameter("SessionName", mode_ != M_SecureChannel ? sessionConfig_->sessionName_ : "NoSession")
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
	    	.parameter("SessionName", mode_ != M_SecureChannel ? sessionConfig_->sessionName_ : "NoSession")
	    	.parameter("AuthenticationToken", authenticationToken_)
			.parameter("ResponseType", OpcUaIdMap::longString(serviceTransaction->nodeTypeResponse().nodeId<uint32_t>()))
			.parameter("ServiceResult", OpcUaStatusCodeMap::shortString(serviceTransaction->responseHeader()->serviceResult()));

		Component* componentService = serviceTransaction->componentService();
		componentService->sendAsync(serviceTransaction);
	}
#endif

}
