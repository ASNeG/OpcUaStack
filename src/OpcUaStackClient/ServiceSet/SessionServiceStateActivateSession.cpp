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
#include "OpcUaStackCore/ServiceSet/ActivateSessionResponse.h"
#include "OpcUaStackCore/ServiceSet/ServiceTransaction.h"
#include "OpcUaStackClient/ServiceSet/SessionServiceStateActivateSession.h"
#include "OpcUaStackClient/ServiceSet/SessionService.h"

using namespace OpcUaStackCore;

namespace OpcUaStackClient
{

	SessionServiceStateActivateSession::SessionServiceStateActivateSession(void)
	: SessionServiceStateIf("ActivateSession", SessionServiceStateId::ActivateSession)
	{
	}

	SessionServiceStateActivateSession::~SessionServiceStateActivateSession(void)
	{
	}

	SessionServiceStateId
	SessionServiceStateActivateSession::asyncConnect(void)
	{
		assert(ctx_ != nullptr);

		Log(Warning, "async connect event in invalid state; ignore event")
			.parameter("SessId", ctx_->id_);

		return SessionServiceStateId::ActivateSession;
	}

	SessionServiceStateId
	SessionServiceStateActivateSession::asyncDisconnect(bool deleteSubscriptions)
	{
		assert(ctx_ != nullptr);
		assert(ctx_->secureChannel_ != nullptr);

		auto secureChannel = ctx_->secureChannel_;

		Log(Debug, "async disconnect event")
			.parameter("SessId", ctx_->id_);

		// close secure channel
		ctx_->secureChannelClient_.disconnect(secureChannel);

		return SessionServiceStateId::Disconnecting;
	}

	SessionServiceStateId
	SessionServiceStateActivateSession::asyncCancel(uint32_t requestHandle)
	{
		// FIXME: todo
		return SessionServiceStateId::ActivateSession;
	}

	SessionServiceStateId
	SessionServiceStateActivateSession::handleConnect(SecureChannel* secureChannel)
	{
		Log(Error, "handle connect event in invalid state; abort")
			.parameter("SessId", ctx_->id_);
		std::abort();

		return SessionServiceStateId::ActivateSession;
	}

	SessionServiceStateId
	SessionServiceStateActivateSession::handleDisconnect(SecureChannel* secureChannel)
	{
		Log(Debug, "handle disconnect event")
			.parameter("SessId", ctx_->id_);

		assert(ctx_ != nullptr);

		// start reconnect timer
		ctx_->startReconnectTimer();

		return SessionServiceStateId::Error;
	}

	SessionServiceStateId
	SessionServiceStateActivateSession::recvCreateSessionResponse(
		SecureChannel* secureChannel,
		const ResponseHeader::SPtr& responseHeader
	)
	{
		Log(Warning, "create session response event in invalid state; ignore event")
			.parameter("SessId", ctx_->id_);

		return SessionServiceStateId::ActivateSession;
	}

	SessionServiceStateId
	SessionServiceStateActivateSession::recvActivateSessionResponse(
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
			Log(Debug, "activate session response error; close secure channel")
				.parameter("SessId", ctx_->id_)
				.parameter("ResultStatus", OpcUaStatusCodeMap::shortString(responseHeader->serviceResult()));

			// close secure channel -
			ctx_->secureChannelClient_.disconnect(secureChannel);

			return SessionServiceStateId::Error;
		}

		// decode activate session response
		std::iostream ios(&trx->is_);
		ActivateSessionResponse activateSessionResponse;
		activateSessionResponse.opcUaBinaryDecode(ios);

		Log(Debug, "session recv ActivateSessionResponse")
			.parameter("SessId", ctx_->id_)
		    .parameter("RequestId", trx->requestId_)
		    .parameter("SessionName", sessionConfig->sessionName_)
		    .parameter("AuthenticationToken", ctx_->authenticationToken_);

		return SessionServiceStateId::Established;
	}

	SessionServiceStateId
	SessionServiceStateActivateSession::recvGetEndpointsResponse(
		SecureChannel* secureChannel,
		const ResponseHeader::SPtr& responseHeader
	)
	{
		Log(Warning, "get endpoints response event in invalid state; ignore event")
			.parameter("SessId", ctx_->id_);

		return SessionServiceStateId::Established;
	}

	SessionServiceStateId
	SessionServiceStateActivateSession::recvCloseSessionResponse(
		SecureChannel* secureChannel,
		const ResponseHeader::SPtr& responseHeader
	)
	{
		Log(Warning, "close session response event in invalid state; ignore event")
			.parameter("SessId", ctx_->id_);

		return SessionServiceStateId::ActivateSession;
	}

	SessionServiceStateId
	SessionServiceStateActivateSession::recvMessageResponse(
		SecureChannel* secureChannel,
		const ResponseHeader::SPtr& responseHeader
	)
	{
		Log(Warning, "message response event in invalid state; ignore event")
			.parameter("SessId", ctx_->id_);

		return SessionServiceStateId::ActivateSession;
	}

	SessionServiceStateId
	SessionServiceStateActivateSession::sendMessageRequest(Message::SPtr message)
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

		return SessionServiceStateId::ActivateSession;
	}

	SessionServiceStateId
	SessionServiceStateActivateSession::reconnectTimeout(void)
	{
		Log(Error, "reconnect timeout event in invalid state; abort")
			.parameter("SessId", ctx_->id_);
		std::abort();

		return SessionServiceStateId::ActivateSession;
	}

	SessionServiceStateId
	SessionServiceStateActivateSession::pendingQueueTimeout(const Object::SPtr& object)
	{
		Log(Error, "pending queue timeout event in invalid state; abort")
			.parameter("SessId", ctx_->id_);
		std::abort();

		return SessionServiceStateId::ActivateSession;
	}

}
