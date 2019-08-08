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
#include "OpcUaStackClient/ServiceSet/SessionServiceStateDisconnecting.h"
#include "OpcUaStackClient/ServiceSet/SessionService.h"

using namespace OpcUaStackCore;

namespace OpcUaStackClient
{

	SessionServiceStateDisconnecting::SessionServiceStateDisconnecting(void)
	: SessionServiceStateIf("Disconnecting", SessionServiceStateId::Disconnecting)
	{
	}

	SessionServiceStateDisconnecting::~SessionServiceStateDisconnecting(void)
	{
	}

	SessionServiceStateId
	SessionServiceStateDisconnecting::asyncConnect(void)
	{
		assert(ctx_ != nullptr);

		Log(Warning, "async connect event in invalid state; ignore event")
			.parameter("SessId", ctx_->id_);

		return SessionServiceStateId::Disconnecting;
	}

	SessionServiceStateId
	SessionServiceStateDisconnecting::asyncDisconnect(bool deleteSubscriptions)
	{
		return SessionServiceStateId::Disconnecting;
	}

	SessionServiceStateId
	SessionServiceStateDisconnecting::asyncCancel(uint32_t requestHandle)
	{
		// FIXME: todo
		return SessionServiceStateId::Disconnecting;
	}

	SessionServiceStateId
	SessionServiceStateDisconnecting::handleConnect(SecureChannel* secureChannel)
	{
		Log(Error, "handle connect event in invalid state; abort")
			.parameter("SessId", ctx_->id_);
		std::abort();

		return SessionServiceStateId::Disconnecting;
	}

	SessionServiceStateId
	SessionServiceStateDisconnecting::handleDisconnect(SecureChannel* secureChannel)
	{
		Log(Debug, "handle disconnect event")
			.parameter("SessId", ctx_->id_);

		assert(ctx_ != nullptr);

		return SessionServiceStateId::Disconnected;
	}

	SessionServiceStateId
	SessionServiceStateDisconnecting::recvCreateSessionResponse(
		SecureChannel* secureChannel,
		const ResponseHeader::SPtr& responseHeader
	)
	{
		Log(Warning, "create session response event in invalid state; ignore event")
			.parameter("SessId", ctx_->id_);

		return SessionServiceStateId::Disconnecting;
	}

	SessionServiceStateId
	SessionServiceStateDisconnecting::recvActivateSessionResponse(
		SecureChannel* secureChannel,
		const ResponseHeader::SPtr& responseHeader
	)
	{
		Log(Warning, "activate session response event in invalid state; ignore event")
			.parameter("SessId", ctx_->id_);

		return SessionServiceStateId::Disconnecting;
	}

	SessionServiceStateId
	SessionServiceStateDisconnecting::recvGetEndpointsResponse(
		SecureChannel* secureChannel,
		const ResponseHeader::SPtr& responseHeader
	)
	{
		Log(Warning, "get endpoints response event in invalid state; ignore event")
			.parameter("SessId", ctx_->id_);

		return SessionServiceStateId::Disconnecting;
	}

	SessionServiceStateId
	SessionServiceStateDisconnecting::recvCloseSessionResponse(
		SecureChannel* secureChannel,
		const ResponseHeader::SPtr& responseHeader
	)
	{
		assert(ctx_ != nullptr);

		Log(Debug, "close session response event")
			.parameter("SessId", ctx_->id_);

		// close secure channel
		ctx_->secureChannelClient_.disconnect(secureChannel);

		return SessionServiceStateId::Disconnecting;
	}

	SessionServiceStateId
	SessionServiceStateDisconnecting::recvMessageResponse(
		SecureChannel* secureChannel,
		const ResponseHeader::SPtr& responseHeader
	)
	{
		Log(Warning, "message response event in invalid state; ignore event")
			.parameter("SessId", ctx_->id_);

		return SessionServiceStateId::Disconnecting;
	}

	SessionServiceStateId
	SessionServiceStateDisconnecting::sendMessageRequest(Message::SPtr message)
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

		return SessionServiceStateId::Disconnecting;
	}

	SessionServiceStateId
	SessionServiceStateDisconnecting::reconnectTimeout(void)
	{
		Log(Error, "reconnect timeout event in invalid state; abort")
			.parameter("SessId", ctx_->id_);
		std::abort();

		return SessionServiceStateId::Disconnecting;
	}

	SessionServiceStateId
	SessionServiceStateDisconnecting::pendingQueueTimeout(const Object::SPtr& object)
	{
		Log(Error, "pending queue timeout event in invalid state; abort")
			.parameter("SessId", ctx_->id_);
		std::abort();

		return SessionServiceStateId::Disconnecting;
	}

}
