/*
   Copyright 2019 Kai Huebl (kai@huebl-sgh.de)

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
#include "OpcUaStackCore/ServiceSet/CreateSessionResponse.h"
#include "OpcUaStackCore/ServiceSet/ServiceTransaction.h"
#include "OpcUaStackClient/ServiceSet/SessionServiceStateCreateSession.h"
#include "OpcUaStackClient/ServiceSet/SessionService.h"

using namespace OpcUaStackCore;

namespace OpcUaStackClient
{

	SessionServiceStateCreateSession::SessionServiceStateCreateSession(void)
	: SessionServiceStateIf("CreateSession", SessionServiceStateId::CreateSession)
	{
	}

	SessionServiceStateCreateSession::~SessionServiceStateCreateSession(void)
	{
	}

	SessionServiceStateId
	SessionServiceStateCreateSession::asyncConnect(void)
	{
		assert(ctx_ != nullptr);

		Log(Warning, "async connect event in invalid state; ignore event")
			.parameter("SessId", ctx_->id_);

		return SessionServiceStateId::CreateSession;
	}

	SessionServiceStateId
	SessionServiceStateCreateSession::asyncDisconnect(bool deleteSubscriptions)
	{
		assert(ctx_ != nullptr);
		assert(ctx_->secureChannel_ != nullptr);
		assert(ctx_->sessionService_ != nullptr);

		auto secureChannel = ctx_->secureChannel_;

		Log(Debug, "async disconnect event")
			.parameter("SessId", ctx_->id_);

		// close secure channel
		ctx_->secureChannelClient_.disconnect(secureChannel);

		return SessionServiceStateId::Disconnecting;
	}

	SessionServiceStateId
	SessionServiceStateCreateSession::asyncCancel(uint32_t requestHandle)
	{
		// FIXME: todo
		return SessionServiceStateId::CreateSession;
	}

	SessionServiceStateId
	SessionServiceStateCreateSession::handleConnect(SecureChannel* secureChannel)
	{
		Log(Error, "handle connect event in invalid state; abort")
			.parameter("SessId", ctx_->id_);
		std::abort();

		return SessionServiceStateId::CreateSession;
	}

	SessionServiceStateId
	SessionServiceStateCreateSession::handleDisconnect(SecureChannel* secureChannel)
	{
		Log(Debug, "handle disconnect event")
			.parameter("SessId", ctx_->id_);

		assert(ctx_ != nullptr);

		// start reconnect timer
		ctx_->startReconnectTimer();

		return SessionServiceStateId::Error;
	}

	SessionServiceStateId
	SessionServiceStateCreateSession::recvCreateSessionResponse(
		SecureChannel* secureChannel,
		const ResponseHeader::SPtr& responseHeader
	)
	{
		assert(ctx_ != nullptr);
		assert(ctx_->sessionConfig_ != nullptr);
		assert(secureChannel != nullptr);
		assert(secureChannel->secureChannelTransaction_.get() != nullptr);
		assert(responseHeader.get() != nullptr);

		auto& securitySettings = secureChannel->securitySettings_;
		auto trx = secureChannel->secureChannelTransaction_;
		auto sessionConfig = ctx_->sessionConfig_;

		// check service result
		if (responseHeader->serviceResult() != Success) {
			Log(Debug, "create session response error; close secure channel")
				.parameter("SessId", ctx_->id_)
				.parameter("ResultStatus", OpcUaStatusCodeMap::shortString(responseHeader->serviceResult()));

			// close secure channel -
			ctx_->secureChannelClient_.disconnect(secureChannel);

			return SessionServiceStateId::Error;
		}

		// decode create session response
		std::iostream ios(&trx->is_);
		CreateSessionResponse createSessionResponse;
		createSessionResponse.opcUaBinaryDecode(ios);

		ctx_->sessionTimeout_ = createSessionResponse.receivedSessionTimeout();
		ctx_->maxResponseMessageSize_ = createSessionResponse.maxRequestMessageSize();
		ctx_->authenticationToken_ = createSessionResponse.authenticationToken();

		// check server signature
		Certificate::SPtr certificate = securitySettings.ownCertificateChain().getCertificate();
		if (certificate.get() != nullptr) {
			ctx_->serverNonce_ = createSessionResponse.serverNonce();

			ctx_->serverCertificate_.fromDERBuf(
				createSessionResponse.serverCertificate().memBuf(),
				createSessionResponse.serverCertificate().size()
			);

			// get client certificate
			MemoryBuffer clientCertificate;
			certificate->toDERBuf(clientCertificate);

			// verify signature
			MemoryBuffer clientNonce(ctx_->clientNonce_, 32);
			PublicKey publicKey = ctx_->serverCertificate_.publicKey();
			OpcUaStatusCode statusCode = createSessionResponse.signatureData()->verifySignature(
				clientCertificate,
				clientNonce,
				publicKey,
				*securitySettings.cryptoBase()
			);

			if (statusCode != Success) {
				Log(Error, "validate server signature error; close secure channel")
					.parameter("SessId", ctx_->id_);

				// close secure channel -
				ctx_->secureChannelClient_.disconnect(secureChannel);

				return SessionServiceStateId::Error;
			}
		}

		Log(Debug, "session recv CreateSessionResponse")
		    .parameter("SessId", ctx_->id_)
		    .parameter("RequestId", trx->requestId_)
		    .parameter("SessionName", sessionConfig->sessionName_)
		    .parameter("AuthenticationToken", ctx_->authenticationToken_);

		// send activate session request
		auto statusCode = ctx_->sendActivateSessionRequest(secureChannel);
		if (statusCode != Success) {
			Log(Error, "send activate session request error; close secure channel")
				.parameter("SessId", ctx_->id_);

			// close secure channel -
			ctx_->secureChannelClient_.disconnect(secureChannel);

			return SessionServiceStateId::Error;
		}

		return SessionServiceStateId::ActivateSession;
	}

	SessionServiceStateId
	SessionServiceStateCreateSession::recvActivateSessionResponse(
		SecureChannel* secureChannel,
		const ResponseHeader::SPtr& responseHeader
	)
	{
		Log(Warning, "activate session response event in invalid state; ignore event")
			.parameter("SessId", ctx_->id_);

		return SessionServiceStateId::CreateSession;
	}

	SessionServiceStateId
	SessionServiceStateCreateSession::recvGetEndpointsResponse(
		SecureChannel* secureChannel,
		const ResponseHeader::SPtr& responseHeader
	)
	{
		Log(Warning, "get endpoints response event in invalid state; ignore event")
			.parameter("SessId", ctx_->id_);

		return SessionServiceStateId::CreateSession;
	}

	SessionServiceStateId
	SessionServiceStateCreateSession::recvCloseSessionResponse(
		SecureChannel* secureChannel,
		const ResponseHeader::SPtr& responseHeader
	)
	{
		Log(Warning, "close session response event in invalid state; ignore event")
			.parameter("SessId", ctx_->id_);

		return SessionServiceStateId::CreateSession;
	}

	SessionServiceStateId
	SessionServiceStateCreateSession::recvMessageResponse(
		SecureChannel* secureChannel,
		const ResponseHeader::SPtr& responseHeader
	)
	{
		Log(Warning, "message response event in invalid state; ignore event")
			.parameter("SessId", ctx_->id_);

		return SessionServiceStateId::CreateSession;
	}

	SessionServiceStateId
	SessionServiceStateCreateSession::sendMessageRequest(Message::SPtr message)
	{
		assert(ctx_ != nullptr);
		assert(message.get() != nullptr);

		Log(Warning, "message request event in invalid state")
			.parameter("SessId", ctx_->id_);

		auto serviceTransaction = boost::static_pointer_cast<ServiceTransaction>(message);

		// send response
		serviceTransaction->statusCode(BadSessionClosed);
		Component* componentService = serviceTransaction->componentService();
		componentService->sendAsync(serviceTransaction);

		return SessionServiceStateId::CreateSession;
	}

	SessionServiceStateId
	SessionServiceStateCreateSession::reconnectTimeout(void)
	{
		Log(Error, "reconnect timeout event in invalid state; abort")
			.parameter("SessId", ctx_->id_);
		std::abort();

		return SessionServiceStateId::CreateSession;
	}

	SessionServiceStateId
	SessionServiceStateCreateSession::pendingQueueTimeout(const Object::SPtr& object)
	{
		Log(Error, "pending queue timeout event in invalid state; abort")
			.parameter("SessId", ctx_->id_);
		std::abort();

		return SessionServiceStateId::CreateSession;
	}

}
