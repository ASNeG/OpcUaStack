/*
   Copyright 2017-2018 Kai Huebl (kai@huebl-sgh.de)

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

#include "OpcUaStackCore/ServiceSet/ActivateSessionResponse.h"
#include "OpcUaStackCore/ServiceSet/CloseSessionRequest.h"
#include "OpcUaStackCore/ServiceSet/CloseSessionResponse.h"
#include "OpcUaStackCore/ServiceSet/CancelRequest.h"
#include "OpcUaStackCore/ServiceSet/CancelResponse.h"
#include "OpcUaStackServer/ServiceSet/SessionManager.h"

namespace OpcUaStackServer
{

	SessionManager::SessionManager(void)
	: ioThread_(nullptr)
	, secureChannelServerConfig_()
	, secureChannelServer_()
	, config_(nullptr)
	, endpointDescriptionArray_()
	, secureChannelServerShutdown_()
	, discoveryService_()
	, transactionManagerSPtr_()
	, channelSessionHandleMap_()
	{
	}

	SessionManager::~SessionManager(void)
	{
	}

	void
	SessionManager::discoveryService(DiscoveryService::SPtr& discoveryService)
	{
		discoveryService_ = discoveryService;
		discoveryService_->discoveryIf(this);
	}

	void
	SessionManager::transactionManager(TransactionManager::SPtr transactionManagerSPtr)
	{
		transactionManagerSPtr_ = transactionManagerSPtr;
	}

	void
	SessionManager::ioThread(IOThread* ioThread)
	{
		ioThread_ = ioThread;
	}

	void
	SessionManager::endpointDescriptionArray(EndpointDescriptionArray::SPtr& endpointDescriptionArray)
	{
		endpointDescriptionArray_ = endpointDescriptionArray;
	}

	void
	SessionManager::config(Config* config)
	{
		config_ = config;
	}

	bool
	SessionManager::startup(void)
	{
		// get endpoint configuration
		EndpointDescription::SPtr endpointDescription;
		if (!endpointDescriptionArray_->get(endpointDescription)) {
			Log(Error, "read server configuration error - endpoint description array");
			return false;
		}
		secureChannelServerConfig_ = constructSPtr<SecureChannelServerConfig>();
		if (!getSecureChannelServerConfig(secureChannelServerConfig_, endpointDescription)) {
			Log(Error, "read server configuration error - get endpoint description");
			return false;
		}

		// create secure channel server
		secureChannelServer_ = constructSPtr<SecureChannelServer>(ioThread_);

		// init secure channel server
		secureChannelServer_->secureChannelServerIf(this);

		// open acceptor socket
		if (!secureChannelServer_->accept(secureChannelServerConfig_)) {
			Log(Error, "open secure channel endpoint error")
				.parameter("Url", secureChannelServerConfig_->endpointUrl());
			return false;
		}

		return true;
	}

	bool
	SessionManager::shutdown(void)
	{
		// close acceptor socket
		if (secureChannelServer_.get() != nullptr) {
			secureChannelServerShutdown_.start();
			secureChannelServer_->disconnect();
			secureChannelServerShutdown_.waitForReady();
		}

		// delete secure channel server
		if (secureChannelServer_.get() != nullptr) {
			secureChannelServer_.reset();
		}

		return true;
	}

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// SecureChannelServerIf
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	void
	SessionManager::handleConnect(SecureChannel* secureChannel)
	{
		Log(Info, "open opc ua secure channel")
			.parameter("OwnAddress", secureChannel->local_.address().to_string())
			.parameter("PartnerAddress", secureChannel->partner_.address().to_string())
			.parameter("ChannelCount", channelSessionHandleMap_.secureChannelSize())
			.parameter("SessionCount", channelSessionHandleMap_.sessionSize());

		// create new secure channel handle
		Object::SPtr handle = channelSessionHandleMap_.createSecureChannel(secureChannel);
		secureChannel->handle(handle);
	}

	void
	SessionManager::handleDisconnect(SecureChannel* secureChannel)
	{
		// delete secure channel handle
		secureChannel->handleReset();
		channelSessionHandleMap_.deleteSecureChannel(secureChannel);

		Log(Info, "close opc ua secure channel")
			.parameter("OwnAddress", secureChannel->local_.address().to_string())
			.parameter("PartnerAddress", secureChannel->partner_.address().to_string())
			.parameter("ChannelCount", channelSessionHandleMap_.secureChannelSize())
			.parameter("SessionCount", channelSessionHandleMap_.sessionSize());

		// no further secure channel handle available
		if (channelSessionHandleMap_.secureChannelSize() == 0) {
			secureChannelServerShutdown_.ready();
		}
	}

	void
	SessionManager::handleMessageRequest(SecureChannel* secureChannel)
	{
		//
		// this function is called by the secure channel when a new request
		// message is received
		//

		// decode request header
		std::iostream ios(&secureChannel->secureChannelTransaction_->is_);
		RequestHeader::SPtr requestHeader = constructSPtr<RequestHeader>();
		requestHeader->opcUaBinaryDecode(ios);

		// process request
		switch (secureChannel->secureChannelTransaction_->requestTypeNodeId_.nodeId<OpcUaStackCore::OpcUaUInt32>())
		{
			case OpcUaId_RegisterServerRequest_Encoding_DefaultBinary:
			{
				registerServerRequest(secureChannel, requestHeader);
				break;
			}
			case OpcUaId_GetEndpointsRequest_Encoding_DefaultBinary:
			{
				getEndpointsRequest(secureChannel, requestHeader);
				break;
			}
			case OpcUaId_FindServersRequest_Encoding_DefaultBinary:
			{
				findServersRequest(secureChannel, requestHeader);
				break;
			}
			case OpcUaId_CreateSessionRequest_Encoding_DefaultBinary:
			{
				createSessionRequest(secureChannel, requestHeader);
				break;
			}
			case OpcUaId_ActivateSessionRequest_Encoding_DefaultBinary:
			{
				activateSessionRequest(secureChannel, requestHeader);
				break;
			}
			case OpcUaId_CloseSessionRequest_Encoding_DefaultBinary:
			{
				closeSessionRequest(secureChannel, requestHeader);
				break;
			}
			case OpcUaId_CancelRequest_Encoding_DefaultBinary:
			{
				cancelRequest(secureChannel, requestHeader);
				break;
			}
			default:
			{
				messageRequest(secureChannel, requestHeader);
			}
		}
	}

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// create session request
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	void
	SessionManager::createSessionRequest(
		SecureChannel* secureChannel,
		RequestHeader::SPtr requestHeader
	)
	{
		// create new session
		Session::SPtr session = constructSPtr<Session>();
		session->ioThread(ioThread_);
		session->sessionIf(this);
		session->endpointDescriptionArray(endpointDescriptionArray_);
		session->transactionManager(transactionManagerSPtr_);

		Object::SPtr handle = channelSessionHandleMap_.createSession(session, secureChannel);
		secureChannel->secureChannelTransaction_->handle_ = handle;

		// handle create session request
		session->createSessionRequest(requestHeader, secureChannel->secureChannelTransaction_);
	}

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// activate session request
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	void
	SessionManager::activateSessionRequest(
		SecureChannel* secureChannel,
		RequestHeader::SPtr requestHeader
	)
	{
		SecureChannelTransaction::SPtr secureChannelTransaction = secureChannel->secureChannelTransaction_;

		// get handle from secure channel
		secureChannel->secureChannelTransaction_->handle_ = secureChannel->handle();
		ChannelSessionHandle::SPtr channelSessionHandle;
		channelSessionHandle = boost::static_pointer_cast<ChannelSessionHandle>(secureChannel->secureChannelTransaction_->handle_);
		if (!channelSessionHandle->sessionIsValid()) {
			// session do not exist anymore - send error response

			errorActivateSessionRequest(secureChannel, requestHeader, BadSessionClosed);
			return;
		}
		Session::SPtr session = channelSessionHandle->session();

		// handle activate session request
		session->activateSessionRequest(requestHeader, secureChannel->secureChannelTransaction_);
	}

	void
	SessionManager::errorActivateSessionRequest(
		SecureChannel* secureChannel,
		RequestHeader::SPtr requestHeader,
		OpcUaStatusCode statusCode
	)
	{
		// added response type
		SecureChannelTransaction::SPtr secureChannelTransaction = secureChannel->secureChannelTransaction_;
		secureChannelTransaction->responseTypeNodeId_ = OpcUaId_ActivateSessionResponse_Encoding_DefaultBinary;

		// get activate session request
		std::iostream ios(&secureChannelTransaction->is_);
		ActivateSessionRequest activateSessionRequest;
		activateSessionRequest.opcUaBinaryDecode(ios);

		// create activate session response
		std::iostream iosres(&secureChannelTransaction->os_);

		ActivateSessionResponse activateSessionResponse;
		activateSessionResponse.responseHeader()->requestHandle(activateSessionRequest.requestHeader()->requestHandle());
		activateSessionResponse.responseHeader()->serviceResult(statusCode);

		activateSessionResponse.responseHeader()->opcUaBinaryEncode(iosres);
		activateSessionResponse.opcUaBinaryEncode(iosres);

		// send activate session response
		ResponseHeader::SPtr responseHeader = activateSessionResponse.responseHeader();
		responseMessage(responseHeader, secureChannelTransaction);
	}

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// close session request
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	void
	SessionManager::closeSessionRequest(
		SecureChannel* secureChannel,
		RequestHeader::SPtr requestHeader
	)
	{
		SecureChannelTransaction::SPtr secureChannelTransaction = secureChannel->secureChannelTransaction_;

		// get handle from secure channel
		secureChannel->secureChannelTransaction_->handle_ = secureChannel->handle();
		ChannelSessionHandle::SPtr channelSessionHandle;
		channelSessionHandle = boost::static_pointer_cast<ChannelSessionHandle>(secureChannel->secureChannelTransaction_->handle_);
		if (!channelSessionHandle->sessionIsValid()) {
			// session do not exist anymore - send error response

			errorCloseSessionRequest(secureChannel, requestHeader, BadSessionClosed);
			return;
		}
		Session::SPtr session = channelSessionHandle->session();

		// handle activate session request
		session->closeSessionRequest(requestHeader, secureChannel->secureChannelTransaction_);
	}

	void
	SessionManager::errorCloseSessionRequest(
		SecureChannel* secureChannel,
		RequestHeader::SPtr requestHeader,
		OpcUaStatusCode statusCode
	)
	{
		// added response type
		SecureChannelTransaction::SPtr secureChannelTransaction = secureChannel->secureChannelTransaction_;
		secureChannelTransaction->responseTypeNodeId_ = OpcUaId_CloseSessionResponse_Encoding_DefaultBinary;

		// get activate session request
		std::iostream ios(&secureChannelTransaction->is_);
		CloseSessionRequest closeSessionRequest;
		closeSessionRequest.opcUaBinaryDecode(ios);

		// create close session response
		std::iostream iosres(&secureChannelTransaction->os_);

		CloseSessionResponse closeSessionResponse;
		closeSessionResponse.responseHeader()->requestHandle(closeSessionRequest.requestHeader()->requestHandle());
		closeSessionResponse.responseHeader()->serviceResult(statusCode);

		closeSessionResponse.responseHeader()->opcUaBinaryEncode(iosres);
		closeSessionResponse.opcUaBinaryEncode(iosres);

		// send close session response
		ResponseHeader::SPtr responseHeader = closeSessionResponse.responseHeader();
		responseMessage(responseHeader, secureChannelTransaction);
	}

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// cancel request
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	void
	SessionManager::cancelRequest(
		SecureChannel* secureChannel,
		RequestHeader::SPtr requestHeader
	)
	{
		SecureChannelTransaction::SPtr secureChannelTransaction = secureChannel->secureChannelTransaction_;

		// get handle from secure channel
		secureChannel->secureChannelTransaction_->handle_ = secureChannel->handle();
		ChannelSessionHandle::SPtr channelSessionHandle;
		channelSessionHandle = boost::static_pointer_cast<ChannelSessionHandle>(secureChannel->secureChannelTransaction_->handle_);
		if (!channelSessionHandle->sessionIsValid()) {
			// session do not exist anymore - send error response

			errorCancelRequest(secureChannel, requestHeader, BadSessionClosed);
			return;
		}
		Session::SPtr session = channelSessionHandle->session();

		// handle cancel request
		session->cancelRequest(requestHeader, secureChannel->secureChannelTransaction_);
	}

	void
	SessionManager::errorCancelRequest(
		SecureChannel* secureChannel,
		RequestHeader::SPtr requestHeader,
		OpcUaStatusCode statusCode
	)
	{
		// added response type
		SecureChannelTransaction::SPtr secureChannelTransaction = secureChannel->secureChannelTransaction_;
		secureChannelTransaction->responseTypeNodeId_ = OpcUaId_CancelResponse_Encoding_DefaultBinary;

		// get cancel request
		std::iostream ios(&secureChannelTransaction->is_);
		CancelRequest cancelRequest;
		cancelRequest.opcUaBinaryDecode(ios);

		// create cancel response
		std::iostream iosres(&secureChannelTransaction->os_);

		CancelResponse cancelResponse;
		cancelResponse.responseHeader()->requestHandle(cancelRequest.requestHeader()->requestHandle());
		cancelResponse.responseHeader()->serviceResult(statusCode);

		cancelResponse.responseHeader()->opcUaBinaryEncode(iosres);
		cancelResponse.opcUaBinaryEncode(iosres);

		// send cancel response
		ResponseHeader::SPtr responseHeader = cancelResponse.responseHeader();
		responseMessage(responseHeader, secureChannelTransaction);
	}

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// message request
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	void
	SessionManager::messageRequest(
		SecureChannel* secureChannel,
		RequestHeader::SPtr requestHeader
	)
	{
		SecureChannelTransaction::SPtr secureChannelTransaction = secureChannel->secureChannelTransaction_;

		// get handle from secure channel
		secureChannel->secureChannelTransaction_->handle_ = secureChannel->handle();
		ChannelSessionHandle::SPtr channelSessionHandle;
		channelSessionHandle = boost::static_pointer_cast<ChannelSessionHandle>(secureChannel->secureChannelTransaction_->handle_);
		if (!channelSessionHandle->sessionIsValid()) {
			// session do not exist anymore - send error response

			errorMessageRequest(secureChannel, requestHeader, BadSessionClosed);
			return;
		}
		Session::SPtr session = channelSessionHandle->session();

		// handle message request
		session->messageRequest(requestHeader, secureChannel->secureChannelTransaction_);
	}

	void
	SessionManager::errorMessageRequest(
		SecureChannel* secureChannel,
		RequestHeader::SPtr requestHeader,
		OpcUaStatusCode statusCode
	)
	{
		// FIXME: todo
	}

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// get endpoints request
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	void
	SessionManager::getEndpointsRequest(
		SecureChannel* secureChannel,
		RequestHeader::SPtr requestHeader
	)
	{
		// get handle from secure channel
		secureChannel->secureChannelTransaction_->handle_ = secureChannel->handle();

		// handle get endpoints request
		discoveryService_->getEndpointRequest(requestHeader, secureChannel->secureChannelTransaction_);
	}

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// find servers request
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	void
	SessionManager::findServersRequest(
		SecureChannel* secureChannel,
		RequestHeader::SPtr requestHeader
	)
	{
		// get handle from secure channel
		secureChannel->secureChannelTransaction_->handle_ = secureChannel->handle();

		// handle find servers request
		discoveryService_->findServersRequest(requestHeader, secureChannel->secureChannelTransaction_);
	}

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// register service request
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	void
	SessionManager::registerServerRequest(
		SecureChannel* secureChannel,
		RequestHeader::SPtr requestHeader
	)
	{
		// get handle from secure channel
		secureChannel->secureChannelTransaction_->handle_ = secureChannel->handle();

		// handle register server request
		discoveryService_->registerServerRequest(requestHeader, secureChannel->secureChannelTransaction_);
	}


	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// handle endpoint callbacks
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	void
	SessionManager::handleEndpointOpen(void)
	{
		Log(Info, "open opc ua endpoint")
			.parameter("EndpointUrl", secureChannelServerConfig_->endpointUrl())
			.parameter("ChannelCount", channelSessionHandleMap_.secureChannelSize())
			.parameter("SessionCount", channelSessionHandleMap_.sessionSize());
	}

	void
	SessionManager::handleEndpointClose(void)
	{
		Log(Info, "close opc ua endpoint")
			.parameter("EndpointUrl", secureChannelServerConfig_->endpointUrl())
			.parameter("ChannelCount", channelSessionHandleMap_.secureChannelSize())
			.parameter("SessionCount", channelSessionHandleMap_.sessionSize());

		//
		// close all channels
		//
		std::vector<SecureChannel*> secureChannelList;
		std::vector<SecureChannel*>::iterator it;
		channelSessionHandleMap_.getSecureChannelList(secureChannelList);
		for (it = secureChannelList.begin(); it != secureChannelList.end(); it++) {
			secureChannelServer_->disconnect(*it);
		}

		if (secureChannelList.size() == 0) {
			secureChannelServerShutdown_.ready();
		}
	}

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// SessionIf
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	void
	SessionManager::responseMessage(
		ResponseHeader::SPtr& responseHeader,
		SecureChannelTransaction::SPtr& secureChannelTransaction
	)
	{
		// get channel session handle
		ChannelSessionHandle::SPtr channelSessionHandle;
		channelSessionHandle = boost::static_pointer_cast<ChannelSessionHandle>(secureChannelTransaction->handle_);
		if (!channelSessionHandle->secureChannelIsValid()) {
			// channel do not exist anymore - ignore response
			return;
		}

		// send response
		secureChannelServer_->sendResponse(
			channelSessionHandle->secureChannel(),
			secureChannelTransaction
		);
	}

	void
	SessionManager::deleteSession(
		uint32_t authenticationToken
	)
	{
		channelSessionHandleMap_.deleteSession(authenticationToken);
	}

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// DiscoveryIf
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	void
	SessionManager::discoveryResponseMessage(
		ResponseHeader::SPtr& responseHeader,
		SecureChannelTransaction::SPtr& secureChannelTransaction
	)
	{
		// get channel session handle
		ChannelSessionHandle::SPtr channelSessionHandle;
		channelSessionHandle = boost::static_pointer_cast<ChannelSessionHandle>(secureChannelTransaction->handle_);
		if (!channelSessionHandle->secureChannelIsValid()) {
			// channel do not exist anymore - ignore response
			return;
		}

		// send response
		secureChannelServer_->sendResponse(
			channelSessionHandle->secureChannel(),
			secureChannelTransaction
		);
	}

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// DiscoveryManagerIf
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	void
	SessionManager::discoveryMessage(SecureChannelTransactionOld::SPtr secureChannelTransaction)
	{
		// FIXME: todo
	}

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// private functions
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	bool
	SessionManager::getSecureChannelServerConfig(
		SecureChannelServerConfig::SPtr& secureChannelServerConfig,
		EndpointDescription::SPtr& endpointDescription
	)
	{
		// set endpoint url
		secureChannelServerConfig->endpointUrl(endpointDescription->endpointUrl());

		// set security mode
		secureChannelServerConfig->securityMode(endpointDescription->messageSecurityMode());

		// set security policy
		secureChannelServerConfig->securityPolicy(endpointDescription->securityPolicy());

		return true;
	}

}
