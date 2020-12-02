/*
   Copyright 2017-2020 Kai Huebl (kai@huebl-sgh.de)

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
#include "OpcUaStackCore/BuildInTypes/OpcUaIdentifier.h"
#include "OpcUaStackCore/Utility/UniqueId.h"
#include "OpcUaStackCore/ServiceSet/ActivateSessionResponse.h"
#include "OpcUaStackCore/ServiceSet/CloseSessionRequest.h"
#include "OpcUaStackCore/ServiceSet/CloseSessionResponse.h"
#include "OpcUaStackCore/ServiceSet/CancelRequest.h"
#include "OpcUaStackCore/ServiceSet/CancelResponse.h"
#include "OpcUaStackCore/ServiceSet/PublishRequest.h"
#include "OpcUaStackCore/ServiceSet/PublishResponse.h"
#include "OpcUaStackServer/ServiceSet/SessionManager.h"

using namespace OpcUaStackCore;

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
	, transactionManagerSPtr_()
	, channelSessionHandleMap_()
	, forwardGlobalSync_()
	{
	}

	SessionManager::~SessionManager(void)
	{
	}

	void
	SessionManager::getEndpointRequestCallback(const DiscoveryRequestCallback& getEndpointRequestCallback)
	{
		getEndpointRequestCallback_ = getEndpointRequestCallback;
	}
	void
	SessionManager::findServersRequestCallback(const DiscoveryRequestCallback& findServersRequestCallback)
	{
		findServersRequestCallback_ = findServersRequestCallback;
	}

	void
	SessionManager::registerServerRequestCallback(const DiscoveryRequestCallback& registerServerRequestCallback)
	{
		registerServerRequestCallback_ = registerServerRequestCallback;
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

		// create strand for use in secure channel server and session
		strand_ = ioThread_->createStrand();
	}

	void
	SessionManager::messageBus(OpcUaStackCore::MessageBus::SPtr& messageBus)
	{
		messageBus_ = messageBus;
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
		// get all endpoint urls from endpoint description set
		std::vector<std::string> endpointUrls;
		endpointDescriptionSet_->getEndpointUrls(endpointUrls);

		// create secure channel server for each endpoint url
		for(auto endpointUrl : endpointUrls) {
			if (!endpointOpen(endpointUrl)) {
				return false;
			}
		}

		return true;
	}

	bool
	SessionManager::endpointOpen(const std::string& endpointUrl)
	{
		// read SecureChannelLog parameter from configuration file
		bool secureChannelLog = false;
		config_->getConfigParameter("OpcUaServer.Logging.SecureChannelLog", secureChannelLog, "0");

		// get endpoint description array
		auto endpointDescriptionArray = boost::make_shared<EndpointDescriptionArray>();
		endpointDescriptionSet_->getEndpoints(endpointUrl, endpointDescriptionArray);

		// create secure channel server configuration
		auto secureChannelServerConfig = boost::make_shared<SecureChannelServerConfig>();
		secureChannelServerConfig->endpointDescriptionArray(endpointDescriptionArray);
		secureChannelServerConfig->endpointUrl(endpointUrl);
		secureChannelServerConfig->secureChannelLog(secureChannelLog);
		secureChannelServerConfig->cryptoManager(cryptoManager_);

		// create new secure channel
		auto secureChannelServer = boost::make_shared<SecureChannelServer>(ioThread_);
		secureChannelServer->strand(strand_);
		secureChannelServer->secureChannelServerIf(this);

		// open server socket
		if (!secureChannelServer->accept(secureChannelServerConfig)) {
			Log(Error, "open secure channel endpoint error")
				.parameter("EndpointUrl", endpointUrl);
			return false;
		}

		secureChannelServerMap_.insert(std::make_pair(endpointUrl, secureChannelServer));
		return true;
	}

	bool
	SessionManager::shutdown(void)
	{
		// stop reopen timer
		if (slotTimerElement_) {
			ioThread_->slotTimer()->stop(slotTimerElement_);
			slotTimerElement_.reset();
			disconnectedEndpointUrls_.clear();
		}

		// close acceptor socket
		shutdownFlag_ = true;
		auto future = shutdownComplete_.get_future();
		for (auto it = secureChannelServerMap_.begin(); it != secureChannelServerMap_.end(); it++) {
			auto secureChannelServer = it->second;
			secureChannelServer->disconnect();
		}
		future.wait();

		// delete all secure channel server
		secureChannelServerMap_.clear();

		// delete all sessions
		channelSessionHandleMap_.deleteSession();

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
		auto secureChannelServer = it->second;

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

		uint32_t requestType = secureChannel->secureChannelTransaction_->requestTypeNodeId_.nodeId<OpcUaStackCore::OpcUaUInt32>();
		Log(Debug, "session manager handle message request")
			.parameter("RequestType", OpcUaIdMap::shortString(requestType));

		//
		// this function is called by the secure channel when a new request
		// message is received
		//

		// decode request header
		std::iostream ios(&secureChannel->secureChannelTransaction_->is_);
		auto requestHeader = boost::make_shared<RequestHeader>();
		requestHeader->opcUaBinaryDecode(ios);

		// process request
		switch (secureChannel->secureChannelTransaction_->requestTypeNodeId_.nodeId<OpcUaUInt32>())
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
		auto session = boost::make_shared<Session>(
			std::string("Session_") + UniqueId::createStringUniqueId(),
			ioThread_,
			messageBus_,
			strand_
		);
		session->responseMessageCallback(
			[this](ResponseHeader::SPtr& header, SecureChannelTransaction::SPtr& trx) {
			    responseMessage(header, trx);
		    }
		);
		session->deleteSessionCallback(
			[this](uint32_t authenticationToken) {
				deleteSession(authenticationToken);
			}
		);
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
		Log(Debug, "activate session request error")
			.parameter("StatusCode", OpcUaStatusCodeMap::shortString(statusCode));

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
		activateSessionResponse.responseHeader()->requestHandle(requestHeader->requestHandle());
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
		auto secureChannelTransaction = secureChannel->secureChannelTransaction_;


		if (secureChannelTransaction->requestTypeNodeId_.nodeId<OpcUaUInt32>() == OpcUaId_PublishRequest_Encoding_DefaultBinary) {
			secureChannelTransaction->responseTypeNodeId_ = OpcUaId_PublishResponse_Encoding_DefaultBinary;

			// decode publish request
			std::iostream ios(&secureChannelTransaction->is_);
			PublishRequest publishRequest;
			publishRequest.opcUaBinaryDecode(ios);

			// create publish response
			std::iostream iosres(&secureChannelTransaction->os_);

			auto responseHeader = boost::make_shared<ResponseHeader>();
			responseHeader->requestHandle(requestHeader->requestHandle());
			responseHeader->serviceResult(BadNoSubscription);
			responseHeader->opcUaBinaryEncode(iosres);

			PublishResponse publishResponse;
			publishResponse.opcUaBinaryEncode(iosres);

			// send cancel response
			responseMessage(responseHeader, secureChannelTransaction);
			return;
		}
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
		ResponseHeader::SPtr responseHeader;
		getEndpointRequestCallback_(
			requestHeader,
			secureChannel->secureChannelTransaction_
		);

		// send response
		discoveryResponseMessage(secureChannel->secureChannelTransaction_);
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
		findServersRequestCallback_(requestHeader, secureChannel->secureChannelTransaction_);

		// send response
		discoveryResponseMessage(secureChannel->secureChannelTransaction_);
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
		registerServerRequestCallback_(requestHeader, secureChannel->secureChannelTransaction_);

		// send response
		discoveryResponseMessage(secureChannel->secureChannelTransaction_);
	}

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// send discovery response
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	void
	SessionManager::discoveryResponseMessage(
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

		// delete secure channel server
		secureChannelServerMap_.erase(endpointUrl);

		if (secureChannelList.size() == 0 && shutdownFlag_) {
			shutdownComplete_.set_value(true);
			return;
		}
		if (shutdownFlag_) {
			return;
		}

		// If we are not in the shutdown state, the opc ua server socket must
		// be open again. But we wait 20 seconds.
		disconnectedEndpointUrls_.push_back(endpointUrl);
		if (disconnectedEndpointUrls_.size() > 1) {
			// timer already running
			return;
		}

		slotTimerElement_ = boost::make_shared<SlotTimerElement>();
		slotTimerElement_->expireFromNow(20000);
		slotTimerElement_->timeoutCallback(
			strand_,
			[this](void) {
				for (auto endpointUrl : disconnectedEndpointUrls_) {
					Log(Info, "reopen opc ua endpoint")
						.parameter("EndpointUrl", endpointUrl);

					endpointOpen(endpointUrl);
				}
				disconnectedEndpointUrls_.clear();
		    }
		);
		ioThread_->slotTimer()->start(slotTimerElement_);
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

}
