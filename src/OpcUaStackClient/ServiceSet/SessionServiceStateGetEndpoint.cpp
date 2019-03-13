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
#include "OpcUaStackCore/ServiceSet/ServiceTransaction.h"
#include "OpcUaStackClient/ServiceSet/SessionServiceStateGetEndpoint.h"
#include "OpcUaStackClient/ServiceSet/SessionService.h"

using namespace OpcUaStackCore;

namespace OpcUaStackClient
{

	SessionServiceStateGetEndpoint::SessionServiceStateGetEndpoint(void)
	: SessionServiceStateIf("GetEndpoint", SessionServiceStateId::GetEndpoint)
	{
	}

	SessionServiceStateGetEndpoint::~SessionServiceStateGetEndpoint(void)
	{
	}

	SessionServiceStateId
	SessionServiceStateGetEndpoint::asyncConnect(void)
	{
		assert(ctx_ != nullptr);

		Log(Warning, "async connect event in invalid state; ignore event")
			.parameter("SessId", ctx_->id_);

		return SessionServiceStateId::GetEndpoint;
	}

	SessionServiceStateId
	SessionServiceStateGetEndpoint::asyncDisconnect(bool deleteSubscriptions)
	{
		assert(ctx_ != nullptr);
		assert(ctx_->secureChannel_ != nullptr);
		assert(ctx_->sessionServiceIf_ != nullptr);
		assert(ctx_->sessionService_ != nullptr);

		auto secureChannel = ctx_->secureChannel_;
		auto sessionServiceIf = ctx_->sessionServiceIf_;
		auto sessionService = ctx_->sessionService_;

		Log(Debug, "async disconnect event")
			.parameter("SessId", ctx_->id_);

		// close secure channel
		ctx_->secureChannelClient_.disconnect(secureChannel);

		return SessionServiceStateId::Disconnecting;
	}

	SessionServiceStateId
	SessionServiceStateGetEndpoint::asyncCancel(uint32_t requestHandle)
	{
		// FIXME: todo
		return SessionServiceStateId::GetEndpoint;
	}

	SessionServiceStateId
	SessionServiceStateGetEndpoint::handleConnect(SecureChannel* secureChannel)
	{
		Log(Warning, "handle connect event in invalid state; ignore event")
			.parameter("SessId", ctx_->id_);

		return SessionServiceStateId::GetEndpoint;
	}

	SessionServiceStateId
	SessionServiceStateGetEndpoint::handleDisconnect(SecureChannel* secureChannel)
	{
		Log(Debug, "handle disconnect event")
			.parameter("SessId", ctx_->id_);

		assert(ctx_ != nullptr);
		assert(ctx_->sessionServiceIf_ != nullptr);
		assert(ctx_->sessionService_ != nullptr);

		auto sessionServiceIf = ctx_->sessionServiceIf_;
		auto sessionService = ctx_->sessionService_;

		// start reconnect timer
		ctx_->startReconnectTimer();

		return SessionServiceStateId::Error;
	}

	SessionServiceStateId
	SessionServiceStateGetEndpoint::recvCreateSessionResponse(
		SecureChannel* secureChannel,
		const ResponseHeader::SPtr& responseHeader
	)
	{
		Log(Warning, "create session response event in invalid state; ignore event")
			.parameter("SessId", ctx_->id_);

		return SessionServiceStateId::GetEndpoint;
	}

	SessionServiceStateId
	SessionServiceStateGetEndpoint::recvActivateSessionResponse(
		SecureChannel* secureChannel,
		const ResponseHeader::SPtr& responseHeader
	)
	{
		Log(Warning, "activate session response event in invalid state; ignore event")
			.parameter("SessId", ctx_->id_);

		return SessionServiceStateId::GetEndpoint;
	}

	SessionServiceStateId
	SessionServiceStateGetEndpoint::recvCloseSessionResponse(
		SecureChannel* secureChannel,
		const ResponseHeader::SPtr& responseHeader
	)
	{
		Log(Warning, "close session response event in invalid state; ignore event")
			.parameter("SessId", ctx_->id_);

		return SessionServiceStateId::GetEndpoint;
	}

	SessionServiceStateId
	SessionServiceStateGetEndpoint::recvMessageResponse(
		SecureChannel* secureChannel,
		const ResponseHeader::SPtr& responseHeader
	)
	{
		Log(Warning, "message response event in invalid state; ignore event")
			.parameter("SessId", ctx_->id_);

		return SessionServiceStateId::GetEndpoint;
	}

	SessionServiceStateId
	SessionServiceStateGetEndpoint::sendMessageRequest(Message::SPtr message)
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

		return SessionServiceStateId::GetEndpoint;
	}

	SessionServiceStateId
	SessionServiceStateGetEndpoint::reconnectTimeout(void)
	{
		Log(Error, "reconnect timeout event in invalid state; abort")
			.parameter("SessId", ctx_->id_);
		std::abort();

		return SessionServiceStateId::GetEndpoint;
	}

	SessionServiceStateId
	SessionServiceStateGetEndpoint::pendingQueueTimeout(const Object::SPtr& object)
	{
		Log(Error, "pending queue timeout event in invalid state; abort")
			.parameter("SessId", ctx_->id_);
		std::abort();

		return SessionServiceStateId::GetEndpoint;
	}

}
