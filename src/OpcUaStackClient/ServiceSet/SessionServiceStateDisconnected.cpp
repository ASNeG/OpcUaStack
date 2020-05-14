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
#include "OpcUaStackCore/Base/Url.h"
#include "OpcUaStackCore/Utility/Environment.h"
#include "OpcUaStackCore/ServiceSet/ServiceTransaction.h"
#include "OpcUaStackClient/ServiceSet/SessionServiceStateDisconnected.h"
#include "OpcUaStackClient/ServiceSet/SessionService.h"

using namespace OpcUaStackCore;

namespace OpcUaStackClient
{

	SessionServiceStateDisconnected::SessionServiceStateDisconnected(void)
	: SessionServiceStateIf("Disconnected", SessionServiceStateId::Disconnected)
	{
	}

	SessionServiceStateDisconnected::~SessionServiceStateDisconnected(void)
	{
	}

	SessionServiceStateId
	SessionServiceStateDisconnected::asyncConnect(void)
	{
		// check configuration parameter
		assert(ctx_ != nullptr);
		assert(ctx_->secureChannelClientConfig_.get() != nullptr);
		assert(ctx_->sessionService_ != nullptr);

		Log(Debug, "async connect event")
			.parameter("SessId", ctx_->id_);

		// set session service mode
		//ctx_->secureChannelClientConfigBackup_ = ctx_->secureChannelClientConfig_;
		if (!ctx_->setSessionServiceMode()) {
			// We did not find an endpoint. After a timeout, a get endpoint request is send again.

			// start reconnect timer and delete endpoint description cache entry
			ctx_->startReconnectTimer();
			ctx_->endpointDescriptionCache_.deleteEndpointDescription(
				ctx_->secureChannelClientConfigBackup_->discoveryUrl()
			);

			return SessionServiceStateId::Disconnected;
		}

		auto clientConfig = ctx_->secureChannelClientConfig_;
		auto& secureChannelClient = ctx_->secureChannelClient_;
		auto secureChannel = ctx_->secureChannel_;
		auto sessionService = ctx_->sessionService_;

		// FIXME: workaround - begin, if endpoint address is 0.0.0.0
		Url url(clientConfig->endpointUrl());
		if (url.isAnyAddress()) {
			url.host(Environment::hostname());
			clientConfig->endpointUrl() = url.url();
		}
		// FIXME: workaround - end

		// check server uri. In case of an error inform the application
		Url endpointUrl(clientConfig->endpointUrl());
		if (!endpointUrl.good()) {
			Log(Error, "url error")
				.parameter("SessId", ctx_->id_)
				.parameter("EndpointUrl", clientConfig->endpointUrl());

			// start reconnect timer and delete endpoint description cache entry
			ctx_->startReconnectTimer();
			ctx_->endpointDescriptionCache_.deleteEndpointDescription(
				ctx_->secureChannelClientConfigBackup_->discoveryUrl()
			);

			return SessionServiceStateId::Disconnected;
		}

		// open secure channel
		secureChannelClient.secureChannelClientIf(sessionService);
		secureChannel = secureChannelClient.connect(clientConfig);
		if (secureChannel == nullptr) {
			Log(Error, "open secure channel error")
				.parameter("SessId", ctx_->id_)
				.parameter("EndpointUrl", clientConfig->endpointUrl());

			// start reconnect timer and delete endpoint description cache entry
			ctx_->startReconnectTimer();
			ctx_->endpointDescriptionCache_.deleteEndpointDescription(
				ctx_->secureChannelClientConfigBackup_->discoveryUrl()
			);

			return SessionServiceStateId::Disconnected;
		}

		return SessionServiceStateId::Connecting;
	}

	SessionServiceStateId
	SessionServiceStateDisconnected::asyncDisconnect(bool deleteSubscriptions)
	{
		// check configuration parameter
		assert(ctx_ != nullptr);

		Log(Debug, "async disconnect event")
			.parameter("SessId", ctx_->id_);

		// stop reconnect timer
		ctx_->stopReconnectTimer();

		return SessionServiceStateId::Disconnected;
	}

	SessionServiceStateId
	SessionServiceStateDisconnected::asyncCancel(uint32_t requestHandle)
	{
		// FIXME: todo
		return SessionServiceStateId::Disconnected;
	}

	SessionServiceStateId
	SessionServiceStateDisconnected::handleConnect(SecureChannel* secureChannel)
	{
		Log(Error, "handle connect event in invalid state; abort")
			.parameter("SessId", ctx_->id_);
		std::abort();

		return SessionServiceStateId::Disconnected;
	}

	SessionServiceStateId
	SessionServiceStateDisconnected::handleDisconnect(SecureChannel* secureChannel)
	{
		Log(Error, "handle disconnect event in invalid state; abort")
			.parameter("SessId", ctx_->id_);
		std::abort();

		return SessionServiceStateId::Disconnected;
	}

	SessionServiceStateId
	SessionServiceStateDisconnected::recvCreateSessionResponse(
		SecureChannel* secureChannel,
		const ResponseHeader::SPtr& responseHeader
	)
	{
		Log(Warning, "create session response event in invalid state; ignore event")
			.parameter("SessId", ctx_->id_);

		return SessionServiceStateId::Disconnected;
	}

	SessionServiceStateId
	SessionServiceStateDisconnected::recvActivateSessionResponse(
		SecureChannel* secureChannel,
		const ResponseHeader::SPtr& responseHeader
	)
	{
		Log(Warning, "activate session response event in invalid state; ignore event")
			.parameter("SessId", ctx_->id_);

		return SessionServiceStateId::Disconnected;
	}

	SessionServiceStateId
	SessionServiceStateDisconnected::recvGetEndpointsResponse(
		SecureChannel* secureChannel,
		const ResponseHeader::SPtr& responseHeader
	)
	{
		Log(Warning, "get endpoints response event in invalid state; ignore event")
			.parameter("SessId", ctx_->id_);

		return SessionServiceStateId::Disconnected;
	}

	SessionServiceStateId
	SessionServiceStateDisconnected::recvCloseSessionResponse(
		SecureChannel* secureChannel,
		const ResponseHeader::SPtr& responseHeader
	)
	{
		Log(Warning, "close session response event in invalid state; ignore event")
			.parameter("SessId", ctx_->id_);

		return SessionServiceStateId::Disconnected;
	}

	SessionServiceStateId
	SessionServiceStateDisconnected::recvMessageResponse(
		SecureChannel* secureChannel,
		const ResponseHeader::SPtr& responseHeader
	)
	{
		Log(Warning, "message response event in invalid state; ignore event")
			.parameter("SessId", ctx_->id_);

		return SessionServiceStateId::Disconnected;
	}

	SessionServiceStateId
	SessionServiceStateDisconnected::sendMessageRequest(Message::SPtr message)
	{
		assert(ctx_ != nullptr);
		assert(message.get() != nullptr);

		Log(Warning, "message request event in invalid state")
			.parameter("SessId", ctx_->id_);

		auto serviceTransaction = boost::static_pointer_cast<ServiceTransaction>(message);

		// send response
		serviceTransaction->statusCode(BadSessionClosed);

		ctx_->sendResponseToService(
			serviceTransaction->memberService(),
			serviceTransaction
		);

		return SessionServiceStateId::Disconnected;
	}

	SessionServiceStateId
	SessionServiceStateDisconnected::reconnectTimeout(void)
	{
		Log(Debug, "reconnect timeout event")
			.parameter("SessId", ctx_->id_);

		ctx_->setSessionServiceMode();
		return asyncConnect();
	}

	SessionServiceStateId
	SessionServiceStateDisconnected::pendingQueueTimeout(const Object::SPtr& object)
	{
		Log(Error, "pending queue timeout event in invalid state; abort")
			.parameter("SessId", ctx_->id_);
		std::abort();

		return SessionServiceStateId::Disconnected;
	}

}
