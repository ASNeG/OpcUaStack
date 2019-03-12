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
		// FIXME: todo
		return SessionServiceStateId::Connecting;
	}

	SessionServiceStateId
	SessionServiceStateConnecting::asyncDisconnect(bool deleteSubscriptions)
	{
		// FIXME: todo
		return SessionServiceStateId::Connecting;
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
		assert(ctx_->sessionServiceIf_ != nullptr);
		assert(ctx_->sessionService_ != nullptr);

		auto sessionServiceIf = ctx_->sessionServiceIf_;
		auto sessionService = ctx_->sessionService_;

		Log(Debug, "session service handle connect")
			.parameter("SessId", ctx_->id_);

		// if we do not need a session we are ready.
		if (ctx_->sessionMode_ == SessionMode::SecureChannel) {

			sessionServiceIf->sessionStateUpdate(*sessionService, SessionState::Established);
			return SessionServiceStateId::Established;
		}

		// create CreateSessionRequest
		ctx_->sendCreateSessionRequest(secureChannel);
		return SessionServiceStateId::CreateSession;
	}

	SessionServiceStateId
	SessionServiceStateConnecting::handleDisconnect(SecureChannel* secureChannel)
	{
		// FIXME: todo
		return SessionServiceStateId::Connecting;
	}

	SessionServiceStateId
	SessionServiceStateConnecting::recvCreateSessionResponse(
		SecureChannel* secureChannel,
		const ResponseHeader::SPtr& responseHeader
	)
	{
		// FIXME: todo
		return SessionServiceStateId::Connecting;
	}

	SessionServiceStateId
	SessionServiceStateConnecting::recvActivateSessionResponse(
		SecureChannel* secureChannel,
		const ResponseHeader::SPtr& responseHeader
	)
	{
		// FIXME: todo
		return SessionServiceStateId::Connecting;
	}

	SessionServiceStateId
	SessionServiceStateConnecting::recvCloseSessionResponse(
		SecureChannel* secureChannel,
		const ResponseHeader::SPtr& responseHeader
	)
	{
		// FIXME: todo
		return SessionServiceStateId::Connecting;
	}

	SessionServiceStateId
	SessionServiceStateConnecting::recvMessageResponse(
		SecureChannel* secureChannel,
		const ResponseHeader::SPtr& responseHeader
	)
	{
		// FIXME: todo
		return SessionServiceStateId::Connecting;
	}

	SessionServiceStateId
	SessionServiceStateConnecting::sendMessageRequest(Message::SPtr message)
	{
		// FIXME: todo
		return SessionServiceStateId::Connecting;
	}

	SessionServiceStateId
	SessionServiceStateConnecting::reconnectTimeout(void)
	{
		// FIXME: todo
		return SessionServiceStateId::Connecting;
	}

	SessionServiceStateId
	SessionServiceStateConnecting::pendingQueueTimeout(const Object::SPtr& object)
	{
		// FIXME: todo
		return SessionServiceStateId::Connecting;
	}

}
