/*
   Copyright 2017 Kai Huebl (kai@huebl-sgh.de)

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
		discoveryService_->discoveryManagerIf(this);
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
		// FIXME: todo
		std::cout << "handleConnect..." << std::endl;

		Log(Info, "open opc ua secure channel")
			.parameter("OwnAddress", secureChannel->local_.address().to_string())
			.parameter("PartnerAddress", secureChannel->partner_.address().to_string())
			.parameter("ChannelCount", channelSessionHandleMap_.secureChannelSize())
			.parameter("SessionCount", channelSessionHandleMap_.sessionSize());

		// create new secure channel handle
		channelSessionHandleMap_.createSecureChannel(secureChannel);
	}

	void
	SessionManager::handleDisconnect(SecureChannel* secureChannel)
	{
		// FIXME: todo
		std::cout << "handleDisconnect..." << std::endl;

		// delete secure channel handle
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

		std::cout << requestHeader->sessionAuthenticationToken().toString() << std::endl;
		std::cout << secureChannel->secureChannelTransaction_->requestTypeNodeId_ << std::endl;

		// process request
		switch (secureChannel->secureChannelTransaction_->requestTypeNodeId_.nodeId<OpcUaStackCore::OpcUaUInt32>())
		{
			case OpcUaId_CreateSessionRequest_Encoding_DefaultBinary:
			{
				std::cout << "CreateSessionRequest" << std::endl;

				// create new session
				Session::SPtr session = constructSPtr<Session>();
				// FIXME: todo...
				channelSessionHandleMap_.createSession(session, secureChannel);

				// handle create session request
				session->createSessionRequest(requestHeader, secureChannel->secureChannelTransaction_);
				break;
			}
			case OpcUaId_ActivateSessionRequest_Encoding_DefaultBinary:
			{
				std::cout << "ActivateSessionRequest" << std::endl;
				break;
			}
			case OpcUaId_CloseSessionRequest_Encoding_DefaultBinary:
			{
				std::cout << "CloseSessionRequest" << std::endl;
				break;
			}
			case OpcUaId_CancelRequest_Encoding_DefaultBinary:
			{
				std::cout << "CancelSessionRequest" << std::endl;
				break;
			}
			default:
			{
				std::cout << "Message" << std::endl;
			}
		}
	}

	void
	SessionManager::handleEndpointOpen(void)
	{
		Log(Info, "open opc ua endpoint")
			.parameter("EndpointUrl", secureChannelServerConfig_->endpointUrl())
			.parameter("ChannelCount", channelSessionHandleMap_.secureChannelSize())
			.parameter("SessionCount", channelSessionHandleMap_.sessionSize());



		std::cout << "handleEndpointOpen..." << std::endl;
		// FIXME: todo
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

		std::cout << "handleEndpointClose..." << std::endl;
		// FIXME: todo
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
