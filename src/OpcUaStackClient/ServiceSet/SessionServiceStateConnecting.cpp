/*
   Copyright 2019-2021 Kai Huebl (kai@huebl-sgh.de)

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
#include "OpcUaStackCore/ServiceSet/ServiceTransaction.h"
#include "OpcUaStackClient/ServiceSet/SessionServiceStateConnecting.h"
#include "OpcUaStackClient/ServiceSet/SessionService.h"

using namespace OpcUaStackCore;

namespace OpcUaStackClient
{

	SessionServiceStateConnecting::SessionServiceStateConnecting(void)
	: SessionServiceStateIf("Connecting", SessionServiceStateId::Connecting)
	{
	}

	SessionServiceStateConnecting::~SessionServiceStateConnecting(void)
	{
	}

	SessionServiceStateId
	SessionServiceStateConnecting::asyncConnect(void)
	{
		assert(ctx_ != nullptr);

		Log(Warning, "async connect event in invalid state; ignore event")
			.parameter("SessId", ctx_->id_)
			.parameter("State", "Connect");

		return SessionServiceStateId::Connecting;
	}

	SessionServiceStateId
	SessionServiceStateConnecting::asyncDisconnect(bool deleteSubscriptions)
	{
		assert(ctx_ != nullptr);
		assert(ctx_->secureChannel_ != nullptr);
		assert(ctx_->sessionService_ != nullptr);

		auto secureChannel = ctx_->secureChannel_;
		auto sessionService = ctx_->sessionService_;

		Log(Debug, "async disconnect event")
			.parameter("SessId", ctx_->id_);

		// close secure channel
		ctx_->secureChannelClient_.disconnect(secureChannel);

		return SessionServiceStateId::Disconnecting;
	}

	SessionServiceStateId
	SessionServiceStateConnecting::asyncCancel(uint32_t requestHandle)
	{
		// FIXME: todo
		return SessionServiceStateId::Connecting;
	}

	SessionServiceStateId
	SessionServiceStateConnecting::handleConnect(SecureChannel* secureChannel)
	{
		// check configuration parameter
		assert(ctx_ != nullptr);
		assert(ctx_->secureChannel_ != nullptr);
		assert(ctx_->sessionService_ != nullptr);

		auto sessionService = ctx_->sessionService_;

		Log(Debug, "session service handle connect")
			.parameter("SessId", ctx_->id_);

		// check if the session is in the get endpoint mode. In this mode no session
		// needs to be open.
		if (ctx_->sessionServiceMode() == SessionServiceMode::GetEndpoint) {

			// send get endpoint request
			ctx_->sendGetEndpointsRequest(secureChannel);
			return SessionServiceStateId::GetEndpoint;
		}

		// if we do not need a session we are ready.
		if (ctx_->sessionMode_ == SessionMode::SecureChannel) {
			return SessionServiceStateId::Established;
		}

		// create CreateSessionRequest
		ctx_->sendCreateSessionRequest(secureChannel);
		return SessionServiceStateId::CreateSession;
	}

	SessionServiceStateId
	SessionServiceStateConnecting::handleDisconnect(SecureChannel* secureChannel)
	{
		Log(Debug, "handle disconnect event")
			.parameter("SessId", ctx_->id_);

		assert(ctx_ != nullptr);

		// start reconnect timer and delete endpoint description entry
		ctx_->startReconnectTimer();
		ctx_->endpointDescriptionCache_.deleteEndpointDescription(
			ctx_->secureChannelClientConfigBackup_->discoveryUrl()
		);

		return SessionServiceStateId::Disconnected;
	}

	SessionServiceStateId
	SessionServiceStateConnecting::recvCreateSessionResponse(
		SecureChannel* secureChannel,
		const ResponseHeader::SPtr& responseHeader
	)
	{
		Log(Warning, "create session response event in invalid state; ignore event")
			.parameter("SessId", ctx_->id_)
			.parameter("State", "Connect");

		return SessionServiceStateId::Connecting;
	}

	SessionServiceStateId
	SessionServiceStateConnecting::recvActivateSessionResponse(
		SecureChannel* secureChannel,
		const ResponseHeader::SPtr& responseHeader
	)
	{
		Log(Warning, "activate session response event in invalid state; ignore event")
			.parameter("SessId", ctx_->id_)
			.parameter("State", "Connect");

		return SessionServiceStateId::Connecting;
	}

	SessionServiceStateId
	SessionServiceStateConnecting::recvGetEndpointsResponse(
		SecureChannel* secureChannel,
		const ResponseHeader::SPtr& responseHeader
	)
	{
		Log(Warning, "get endpoints response event in invalid state; ignore event")
			.parameter("SessId", ctx_->id_)
			.parameter("State", "Connect");

		return SessionServiceStateId::Connecting;
	}

	SessionServiceStateId
	SessionServiceStateConnecting::recvCloseSessionResponse(
		SecureChannel* secureChannel,
		const ResponseHeader::SPtr& responseHeader
	)
	{
		Log(Warning, "close session response event in invalid state; ignore event")
			.parameter("SessId", ctx_->id_)
			.parameter("State", "Connect");

		return SessionServiceStateId::Connecting;
	}

	SessionServiceStateId
	SessionServiceStateConnecting::recvMessageResponse(
		SecureChannel* secureChannel,
		const ResponseHeader::SPtr& responseHeader
	)
	{
		Log(Warning, "message response event in invalid state; ignore event")
			.parameter("SessId", ctx_->id_)
			.parameter("State", "Connect");

		return SessionServiceStateId::Connecting;
	}

	SessionServiceStateId
	SessionServiceStateConnecting::sendMessageRequest(Message::SPtr message)
	{
		assert(ctx_ != nullptr);
		assert(message.get() != nullptr);

		Log(Warning, "message request event in invalid state")
			.parameter("SessId", ctx_->id_)
			.parameter("State", "Connect");

		auto serviceTransaction = boost::static_pointer_cast<ServiceTransaction>(message);

		// send response
		serviceTransaction->statusCode(BadSessionClosed);
		ctx_->sendResponseToService(
			serviceTransaction->memberService(),
			serviceTransaction
		);

		return SessionServiceStateId::Connecting;
	}

	SessionServiceStateId
	SessionServiceStateConnecting::reconnectTimeout(void)
	{
		Log(Error, "reconnect timeout event in invalid state; abort")
			.parameter("SessId", ctx_->id_)
			.parameter("State", "Connect");
		std::abort();

		return SessionServiceStateId::Connecting;
	}

	SessionServiceStateId
	SessionServiceStateConnecting::pendingQueueTimeout(const Object::SPtr& object)
	{
		Log(Error, "pending queue timeout event in invalid state; abort")
			.parameter("SessId", ctx_->id_)
			.parameter("State", "Connect");
		std::abort();

		return SessionServiceStateId::Connecting;
	}

}
