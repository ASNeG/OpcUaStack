/*
   Copyright 2017-2019 Kai Huebl (kai@huebl-sgh.de)

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

#include <boost/make_shared.hpp>
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
	, secureChannelServerMap_()
	, config_(nullptr)
	, endpointDescriptionSet_()
	, cryptoManager_()
	, shutdownFlag_(false)
	, shutdownComplete_()
	, discoveryService_()
	, transactionManagerSPtr_()
	, channelSessionHandleMap_()
	, forwardGlobalSync_()
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
	SessionManager::cryptoManager(CryptoManager::SPtr& cryptoManager)
	{
		cryptoManager_ = cryptoManager;
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
	SessionManager::endpointDescriptionSet(EndpointDescriptionSet::SPtr& endpointDescriptionSet)
	{
		endpointDescriptionSet_ = endpointDescriptionSet;
	}

	void
	SessionManager::config(Config* config)
	{
		config_ = config;
	}

	void
	SessionManager::forwardGlobalSync(ForwardGlobalSync::SPtr& forwardGlobalSync)
	{
		forwardGlobalSync_ = forwardGlobalSync;
	}

	bool
	SessionManager::startup(void)
	{
		// read SecureChannelLog parameter from configuration file
		bool secureChannelLog = false;
		config_->getConfigParameter("OpcUaServer.Logging.SecureChannelLog", secureChannelLog, "0");

		// get all endpoint urls from endpoint description set
		std::vector<std::string> endpointUrls;
		endpointDescriptionSet_->getEndpointUrls(endpointUrls);

		// create secure channel server for each endpoint url
		for (auto it = endpointUrls.begin(); it != endpointUrls.end(); it++) {

			// get endpoint description array
			std::string endpointUrl = *it;
			auto endpointDescriptionArray = boost::make_shared<EndpointDescriptionArray>();
			endpointDescriptionSet_->getEndpoints(endpointUrl, endpointDescriptionArray);

			// create secure channel server configuration
			auto secureChannelServerConfig = constructSPtr<SecureChannelServerConfig>();
			secureChannelServerConfig->endpointDescriptionArray(endpointDescriptionArray);
			secureChannelServerConfig->endpointUrl(endpointUrl);
			secureChannelServerConfig->secureChannelLog(secureChannelLog);
			secureChannelServerConfig->cryptoManager(cryptoManager_);

			// create new secure channel
			auto secureChannelServer = constructSPtr<SecureChannelServer>(ioThread_);
			secureChannelServer->secureChannelServerIf(this);

			// open server socket
			if (!secureChannelServer->accept(secureChannelServerConfig)) {
				Log(Error, "open secure channel endpoint error")
					.parameter("EndpointUrl", endpointUrl);
				return false;
			}

			secureChannelServerMap_.insert(std::make_pair(endpointUrl, secureChannelServer));
		}

		return true;
	}

	bool
	SessionManager::shutdown(void)
	{
		// close acceptor socket
		shutdownFlag_ = true;
		auto future = shutdownComplete_.get_future();
		for (auto it = secureChannelServerMap_.begin(); it != secureChannelServerMap_.end(); it++) {
			SecureChannelServer::SPtr secureChannelServer = it->second;
			secureChannelServer->disconnect();
		}
		future.wait();

		// delete secure channel server
		secureChannelServerMap_.clear();

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

		// find secure channel server
		auto it = secureChannelServerMap_.find(secureChannel->endpointUrl_);
		if (it == secureChannelServerMap_.end()) {
			Log(Info, "secure channel server not found in handle connect")
				.parameter("EndpointUrl", secureChannel->endpointUrl_);
			return;
		}
		SecureChannelServer::SPtr secureChannelServer = it->second;

		// create new secure channel handle
		Object::SPtr handle = channelSessionHandleMap_.createSecureChannel(secureChannelServer, secureChannel);
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
		if (channelSessionHandleMap_.secureChannelSize() == 0 && shutdownFlag_) {
			shutdownComplete_.set_value(true);
		}
	}

	void
	SessionManager::handleMessageRequest(SecureChannel* secureChannel)
	{
		Log(Debug, "session manager handle message request");

		//
		// this function is called by the secure channel when a new request
		// message is received
		//

		// decode request header
		std::iostream ios(&secureChannel->secureChannelTransaction_->is_);
		auto requestHeader = constructSPtr<RequestHeader>();
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
		auto secureChannelServerConfig = boost::static_pointer_cast<SecureChannelServerConfig>(secureChannel->config_);
		auto endpointDescriptionArray = secureChannelServerConfig->endpointDescriptionArray();

		// create new session
		Session::SPtr session = constructSPtr<Session>();
		session->ioThread(ioThread_);
		session->sessionIf(this);
		session->cryptoManager(cryptoManager_);
		session->endpointDescriptionArray(endpointDescriptionArray);
		session->endpointDescription(secureChannel->securitySettings_.endpointDescription());
		session->transactionManager(transactionManagerSPtr_);
		session->forwardGlobalSync(forwardGlobalSync_);

		Object::SPtr handle = channelSessionHandleMap_.createSession(session, secureChannel);
		secureChannel->secureChannelTransaction_->handle_ = handle;

		// handle create session request
		session->createSessionRequest(requestHeader, secureChannel);
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
		auto secureChannelTransaction = secureChannel->secureChannelTransaction_;

		// get handle from secure channel
		secureChannel->secureChannelTransaction_->handle_ = secureChannel->handle();
		auto channelSessionHandle = boost::static_pointer_cast<ChannelSessionHandle>(secureChannel->secureChannelTransaction_->handle_);
		if (!channelSessionHandle->sessionIsValid()) {
			// session do not exist anymore - send error response

			errorActivateSessionRequest(secureChannel, requestHeader, BadSessionClosed);
			return;
		}
		auto session = channelSessionHandle->session();

		// handle activate session request
		session->activateSessionRequest(requestHeader, secureChannel);
	}

	void
	SessionManager::errorActivateSessionRequest(
		SecureChannel* secureChannel,
		RequestHeader::SPtr requestHeader,
		OpcUaStatusCode statusCode
	)
	{
		// added response type
		auto secureChannelTransaction = secureChannel->secureChannelTransaction_;
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
		auto responseHeader = activateSessionResponse.responseHeader();
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
		auto secureChannelTransaction = secureChannel->secureChannelTransaction_;

		// get handle from secure channel
		secureChannel->secureChannelTransaction_->handle_ = secureChannel->handle();
		auto channelSessionHandle = boost::static_pointer_cast<ChannelSessionHandle>(secureChannel->secureChannelTransaction_->handle_);
		if (!channelSessionHandle->sessionIsValid()) {
			// session do not exist anymore - send error response

			errorCloseSessionRequest(secureChannel, requestHeader, BadSessionClosed);
			return;
		}
		auto session = channelSessionHandle->session();

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
		auto secureChannelTransaction = secureChannel->secureChannelTransaction_;
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
		auto responseHeader = closeSessionResponse.responseHeader();
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
		auto secureChannelTransaction = secureChannel->secureChannelTransaction_;

		// get handle from secure channel
		secureChannel->secureChannelTransaction_->handle_ = secureChannel->handle();
		auto channelSessionHandle = boost::static_pointer_cast<ChannelSessionHandle>(secureChannel->secureChannelTransaction_->handle_);
		if (!channelSessionHandle->sessionIsValid()) {
			// session do not exist anymore - send error response

			errorCancelRequest(secureChannel, requestHeader, BadSessionClosed);
			return;
		}
		auto session = channelSessionHandle->session();

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
		auto secureChannelTransaction = secureChannel->secureChannelTransaction_;
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
		auto responseHeader = cancelResponse.responseHeader();
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
		auto secureChannelTransaction = secureChannel->secureChannelTransaction_;

		// get handle from secure channel
		secureChannel->secureChannelTransaction_->handle_ = secureChannel->handle();
		auto channelSessionHandle = boost::static_pointer_cast<ChannelSessionHandle>(secureChannel->secureChannelTransaction_->handle_);
		if (!channelSessionHandle->sessionIsValid()) {
			// session do not exist anymore - send error response

			errorMessageRequest(secureChannel, requestHeader, BadSessionClosed);
			return;
		}
		auto session = channelSessionHandle->session();

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
	SessionManager::handleEndpointOpen(const std::string& endpointUrl)
	{
		Log(Info, "open opc ua endpoint")
			.parameter("EndpointUrl", endpointUrl)
			.parameter("ChannelCount", channelSessionHandleMap_.secureChannelSize())
			.parameter("SessionCount", channelSessionHandleMap_.sessionSize());
	}

	void
	SessionManager::handleEndpointClose(const std::string& endpointUrl)
	{
		Log(Info, "close opc ua endpoint")
			.parameter("EndpointUrl", endpointUrl)
			.parameter("ChannelCount", channelSessionHandleMap_.secureChannelSize())
			.parameter("SessionCount", channelSessionHandleMap_.sessionSize());

		// find secure channel server
		SecureChannelServer::SPtr secureChannelServer;
		auto it0 = secureChannelServerMap_.find(endpointUrl);
		if (it0 == secureChannelServerMap_.end()) {
			Log(Info, "close opc ua endpoint error, because secure channel server not found")
				.parameter("EndpointUrl", endpointUrl);
		}
		else {
			secureChannelServer = it0->second;
		}

		//
		// close all channels
		//
		std::vector<SecureChannel*> secureChannelList;
		channelSessionHandleMap_.getSecureChannelList(secureChannelList);
		if (secureChannelServer.get() != nullptr) {
			for (auto it1 = secureChannelList.begin(); it1 != secureChannelList.end(); it1++) {
				SecureChannel* secureChannel = *it1;

				SecureChannelServerConfig::SPtr cfg = boost::static_pointer_cast<SecureChannelServerConfig>(secureChannel->config_);

				if (cfg->endpointUrl() != endpointUrl) {
					continue;
				}

				secureChannelServer->disconnect(secureChannel);
			}
		}

		if (secureChannelList.size() == 0 && shutdownFlag_) {
			shutdownComplete_.set_value(true);
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
		auto channelSessionHandle = boost::static_pointer_cast<ChannelSessionHandle>(secureChannelTransaction->handle_);
		if (!channelSessionHandle->secureChannelIsValid()) {
			// channel do not exist anymore - ignore response
			return;
		}

		// send response
		auto secureChannelServer = channelSessionHandle->secureChannelServer();
		secureChannelServer->sendResponse(
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
		auto channelSessionHandle = boost::static_pointer_cast<ChannelSessionHandle>(secureChannelTransaction->handle_);
		if (!channelSessionHandle->secureChannelIsValid()) {
			// channel do not exist anymore - ignore response
			return;
		}

		// send response
		channelSessionHandle->secureChannelServer()->sendResponse(
			channelSessionHandle->secureChannel(),
			secureChannelTransaction
		);
	}

}
