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
#include "OpcUaStackCore/BuildInTypes/OpcUaIdentifier.h"
#include "OpcUaStackClient/ServiceSet/SessionServiceStateEstablished.h"
#include "OpcUaStackClient/ServiceSet/SessionService.h"

using namespace OpcUaStackCore;

namespace OpcUaStackClient
{

	SessionServiceStateEstablished::SessionServiceStateEstablished(void)
	: SessionServiceStateIf("Established", SessionServiceStateId::Established)
	{
	}

	SessionServiceStateEstablished::~SessionServiceStateEstablished(void)
	{
	}

	SessionServiceStateId
	SessionServiceStateEstablished::asyncConnect(void)
	{
		// FIXME: todo
		return SessionServiceStateId::Established;
	}

	SessionServiceStateId
	SessionServiceStateEstablished::asyncDisconnect(
		bool deleteSubscriptions)
	{
		assert(ctx_ != nullptr);

		// send close session request to server
		ctx_->sendCloseSessionRequest(
			ctx_->secureChannel_,
			deleteSubscriptions
		);

		return SessionServiceStateId::Disconnecting;
	}

	SessionServiceStateId
	SessionServiceStateEstablished::asyncCancel(uint32_t requestHandle)
	{
		// FIXME: todo
		return SessionServiceStateId::Established;
	}

	SessionServiceStateId
	SessionServiceStateEstablished::handleConnect(SecureChannel* secureChannel)
	{
		// FIXME: todo
		return SessionServiceStateId::Established;
	}

	SessionServiceStateId
	SessionServiceStateEstablished::handleDisconnect(SecureChannel* secureChannel)
	{
		// FIXME: todo
		return SessionServiceStateId::Established;
	}

	SessionServiceStateId
	SessionServiceStateEstablished::recvCreateSessionResponse(
		SecureChannel* secureChannel,
		ResponseHeader::SPtr& responseHeader
	)
	{
		// FIXME: todo
		return SessionServiceStateId::Established;
	}

	SessionServiceStateId
	SessionServiceStateEstablished::recvActivateSessionResponse(
		SecureChannel* secureChannel,
		ResponseHeader::SPtr& responseHeader
	)
	{
		// FIXME: todo
		return SessionServiceStateId::Established;
	}

	SessionServiceStateId
	SessionServiceStateEstablished::recvCloseSessionResponse(
		SecureChannel* secureChannel,
		ResponseHeader::SPtr& responseHeader
	)
	{
		// FIXME: todo
		return SessionServiceStateId::Established;
	}

	SessionServiceStateId
	SessionServiceStateEstablished::recvMessageResponse(
		SecureChannel* secureChannel,
		ResponseHeader::SPtr& responseHeader
	)
	{
		// FIXME: todo
		return SessionServiceStateId::Established;
	}

	SessionServiceStateId
	SessionServiceStateEstablished::sendMessageRequest(Message::SPtr message)
	{
		assert(ctx_ != nullptr);
		assert(message.get() != nullptr);

		auto serviceTransaction = boost::static_pointer_cast<ServiceTransaction>(message);

		uint32_t requestTimeout = 3000;
		serviceTransaction->calcRequestTimeout(requestTimeout);

		uint32_t requestType = serviceTransaction->nodeTypeRequest().nodeId<uint32_t>();
		uint32_t requestId = ctx_->requestId_++;

		// only the GetEndpointRequest, FindServerRequest and the RegisterServerRequest
		// may be send without a session.
		if (ctx_->sessionMode_ == SessionMode::SecureChannel) {
			if (
				requestType != OpcUaId_GetEndpointsRequest_Encoding_DefaultBinary &&
				requestType != OpcUaId_FindServersRequest_Encoding_DefaultBinary &&
				requestType != OpcUaId_RegisterServerRequest_Encoding_DefaultBinary
			) {
				Log(Error, "request send failed, because session is not available")
					.parameter("SessId", ctx_->id_)
					.parameter("RequestType", OpcUaIdMap::longString(requestType));

				serviceTransaction->statusCode(BadSessionClosed);
				Component* componentService = serviceTransaction->componentService();
				componentService->sendAsync(serviceTransaction);

				return SessionServiceStateId::Established;
			}
		}

		auto secureChannelTransaction = constructSPtr<SecureChannelTransaction>();
		secureChannelTransaction->requestTypeNodeId_ = serviceTransaction->nodeTypeRequest();
		secureChannelTransaction->requestId_ = requestId;
		std::iostream ios(&secureChannelTransaction->os_);

		RequestHeader::SPtr requestHeader = serviceTransaction->requestHeader();
		requestHeader->requestHandle(serviceTransaction->transactionId());
		requestHeader->sessionAuthenticationToken() = ctx_->authenticationToken_;
		requestHeader->timeoutHint(requestTimeout);
		requestHeader->opcUaBinaryEncode(ios);
		serviceTransaction->opcUaBinaryEncodeRequest(ios);

		// insert request into pending queue
		ctx_->pendingQueue_.insert(
			secureChannelTransaction->requestId_,
			serviceTransaction,
			requestTimeout
		);

		// send request to server
		Log(Debug, "session send request")
		    .parameter("SessId", ctx_->id_)
		    .parameter("RequestId", requestId)
		    .parameter("AuthenticationToken", ctx_->authenticationToken_)
		    .parameter("RequestType", OpcUaIdMap::longString(requestType));
		ctx_->secureChannelClient_.asyncWriteMessageRequest(
			ctx_->secureChannel_,
			secureChannelTransaction
		);

		return SessionServiceStateId::Established;
	}

	SessionServiceStateId
	SessionServiceStateEstablished::reconnectTimeout(void)
	{
		// FIXME: todo
		return SessionServiceStateId::Established;
	}

	SessionServiceStateId
	SessionServiceStateEstablished::pendingQueueTimeout(Object::SPtr& object)
	{
		auto trx = boost::static_pointer_cast<ServiceTransaction>(object);
		auto responseType = trx->nodeTypeResponse().nodeId<uint32_t>();

		Log(Debug, "session send request timeout")
			.parameter("SessId", ctx_->id_)
		    .parameter("RequestId", trx->requestId_)
	    	.parameter("AuthenticationToken", ctx_->authenticationToken_)
			.parameter("ResponseType", OpcUaIdMap::longString(responseType));

		trx->statusCode(BadTimeout);
		Component* componentService = trx->componentService();
		componentService->sendAsync(trx);

		return SessionServiceStateId::Established;
	}

}
