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
#include "OpcUaStackCore/BuildInTypes/OpcUaStatusCode.h"
#include "OpcUaStackCore/ServiceSet/ServiceTransaction.h"
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
		assert(ctx_ != nullptr);

		Log(Warning, "async connect event in invalid state; ignore event")
			.parameter("SessId", ctx_->id_)
			.parameter("State", "Established");

		return SessionServiceStateId::Established;
	}

	SessionServiceStateId
	SessionServiceStateEstablished::asyncDisconnect(bool deleteSubscriptions)
	{
		Log(Debug, "async disconnect event")
			.parameter("SessId", ctx_->id_);

		assert(ctx_ != nullptr);
		assert(ctx_->secureChannel_ != nullptr);

		auto secureChannel = ctx_->secureChannel_;

		// remove all requests from pending queue
		removeAllRequestsFromPendingQueue();

		// check if session exists
		if (ctx_->sessionMode_ == SessionMode::SecureChannel) {

			// no session exists - close secure channel
			ctx_->secureChannelClient_.disconnect(secureChannel);
		}
		else {

			// session exists send close session request to server
			ctx_->sendCloseSessionRequest(
				ctx_->secureChannel_,
				deleteSubscriptions
			);
		}

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
		Log(Error, "handle connect event in invalid state; abort")
			.parameter("SessId", ctx_->id_)
			.parameter("State", "Established");
		std::abort();

		return SessionServiceStateId::Established;
	}

	SessionServiceStateId
	SessionServiceStateEstablished::handleDisconnect(SecureChannel* secureChannel)
	{
		Log(Debug, "handle disconnect event")
			.parameter("SessId", ctx_->id_);

		assert(ctx_ != nullptr);

		// remove all requests from pending queue
		removeAllRequestsFromPendingQueue();

		// start reconnect timer
		ctx_->startReconnectTimer();

		return SessionServiceStateId::Disconnected;
	}

	SessionServiceStateId
	SessionServiceStateEstablished::recvCreateSessionResponse(
		SecureChannel* secureChannel,
		const ResponseHeader::SPtr& responseHeader
	)
	{
		assert(ctx_ != nullptr);

		Log(Warning, "create session response in invalid state; close secure channel")
			.parameter("SessId", ctx_->id_)
			.parameter("State", "Established")
			.parameter("ResultStatus", OpcUaStatusCodeMap::shortString(responseHeader->serviceResult()));

		// remove all requests from pending queue
		removeAllRequestsFromPendingQueue();

		// close secure channel
		ctx_->secureChannelClient_.disconnect(secureChannel);

		return SessionServiceStateId::Error;
	}

	SessionServiceStateId
	SessionServiceStateEstablished::recvActivateSessionResponse(
		SecureChannel* secureChannel,
		const ResponseHeader::SPtr& responseHeader
	)
	{
		assert(ctx_ != nullptr);

		Log(Warning, "activate session response in invalid state; close secure channel")
			.parameter("SessId", ctx_->id_)
			.parameter("State", "Established")
			.parameter("ResultStatus", OpcUaStatusCodeMap::shortString(responseHeader->serviceResult()));

		// remove all requests from pending queue
		removeAllRequestsFromPendingQueue();

		// close secure channel
		ctx_->secureChannelClient_.disconnect(secureChannel);

		return SessionServiceStateId::Error;
	}

	SessionServiceStateId
	SessionServiceStateEstablished::recvGetEndpointsResponse(
		SecureChannel* secureChannel,
		const ResponseHeader::SPtr& responseHeader
	)
	{
		Log(Warning, "get endpoints response event in invalid state; ignore event")
			.parameter("SessId", ctx_->id_)
			.parameter("State", "Established");

		return SessionServiceStateId::Established;
	}

	SessionServiceStateId
	SessionServiceStateEstablished::recvCloseSessionResponse(
		SecureChannel* secureChannel,
		const ResponseHeader::SPtr& responseHeader
	)
	{
		assert(ctx_ != nullptr);

		Log(Warning, "receive close session response in invalid state; close secure channel")
			.parameter("SessId", ctx_->id_)
			.parameter("State", "Established")
			.parameter("ResultStatus", OpcUaStatusCodeMap::shortString(responseHeader->serviceResult()));

		// remove all requests from pending queue
		removeAllRequestsFromPendingQueue();

		// close secure channel
		ctx_->secureChannelClient_.disconnect(secureChannel);

		return SessionServiceStateId::Error;
	}

	SessionServiceStateId
	SessionServiceStateEstablished::recvMessageResponse(
		SecureChannel* secureChannel,
		const ResponseHeader::SPtr& responseHeader
	)
	{
		assert(ctx_ != nullptr);
		assert(secureChannel != nullptr);
		assert(secureChannel->secureChannelTransaction_.get() != nullptr);

		auto secureChannelTransaction = secureChannel->secureChannelTransaction_;
		uint32_t responseType = secureChannelTransaction->responseTypeNodeId_.nodeId<uint32_t>();

		std::iostream ios(&secureChannelTransaction->is_);

		// remove associated request from pending queue
		Object::SPtr objectSPtr = ctx_->pendingQueue_.remove(secureChannelTransaction->requestId_);
		if (objectSPtr.get() == nullptr) {
			Log(Error, "receive message response error, because the request has already expired")
				.parameter("SessId", ctx_->id_)
				.parameter("RequestId", secureChannelTransaction->requestId_)
				.parameter("AuthenticationToken", ctx_->authenticationToken_)
				.parameter("ResponseType",  OpcUaIdMap::shortString(responseType))
				.parameter("RequestHandle", responseHeader->requestHandle());
			char c; while (ios.get(c));
			return SessionServiceStateId::Established;
		}

		auto trx = boost::static_pointer_cast<ServiceTransaction>(objectSPtr);
		trx->opcUaBinaryDecodeResponse(ios);
		trx->responseHeader(responseHeader);
		trx->statusCode(responseHeader->serviceResult());

		Log(Debug, "session receive response")
			.parameter("SessId", ctx_->id_)
		    .parameter("RequestId", secureChannelTransaction->requestId_)
	    	.parameter("AuthenticationToken", ctx_->authenticationToken_)
			.parameter("ResponseType",  OpcUaIdMap::shortString(responseType))
			.parameter("ServiceResult", OpcUaStatusCodeMap::shortString(responseHeader->serviceResult()));

		Component* componentService = trx->componentService();
		componentService->sendAsync(trx);

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

		auto secureChannelTransaction = boost::make_shared<SecureChannelTransaction>();
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
		Log(Error, "reconnect timeout event in invalid state; abort")
			.parameter("SessId", ctx_->id_);
		std::abort();

		return SessionServiceStateId::Established;
	}

	SessionServiceStateId
	SessionServiceStateEstablished::pendingQueueTimeout(const Object::SPtr& object)
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

	void
	SessionServiceStateEstablished::removeAllRequestsFromPendingQueue(void)
	{
		std::vector<uint32_t> keys;
		ctx_->pendingQueue_.keys(keys);
		for (auto key : keys) {
			auto object = ctx_->pendingQueue_.remove(key);
			auto trx = boost::static_pointer_cast<ServiceTransaction>(object);
			auto responseType = trx->nodeTypeResponse().nodeId<uint32_t>();

			Log(Debug, "remove request from pending queue, because session closed")
				.parameter("SessId", ctx_->id_)
			    .parameter("RequestId", trx->requestId_)
		    	.parameter("AuthenticationToken", ctx_->authenticationToken_)
				.parameter("ResponseType", OpcUaIdMap::longString(responseType));

			trx->statusCode(BadSessionClosed);
			Component* componentService = trx->componentService();
			componentService->sendAsync(trx);
		}
	}

}
