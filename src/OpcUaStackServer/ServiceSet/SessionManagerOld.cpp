/*
   Copyright 2015 Kai Huebl (kai@huebl-sgh.de)

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

#include "OpcUaStackServer/ServiceSet/SessionManagerOld.h"
#include "OpcUaStackCore/Base/Log.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaIdentifier.h"

namespace OpcUaStackServer
{

	SessionManagerOld* SessionManagerOld::instance_ = nullptr;
	
	SessionManagerOld*
	SessionManagerOld::instance(void)
	{
		if (instance_ == NULL) {
			instance_ = new SessionManagerOld();
		}
		return instance_;
	}

	SessionManagerOld::SessionManagerOld(void)
	: shutdown_()
	, prefixSessionConfig_("")
	, prefixSecureChannelConfig_("") 
	, sessionConfig_(nullptr)
	, secureChannelConfig_(nullptr)
	, ioService_(nullptr)
	, tcpAcceptor_()
	, url_()
	, secureChannelMap_()
	, sessionMap_()
	{
	}

	SessionManagerOld::~SessionManagerOld(void)
	{
	}

	void 
	SessionManagerOld::transactionManager(TransactionManager::SPtr transactionManagerSPtr)
	{
		transactionManagerSPtr_ = transactionManagerSPtr;
	}

	void 
	SessionManagerOld::discoveryService(DiscoveryService::SPtr discoveryService)
	{
		discoveryService_ = discoveryService;
		discoveryService_->discoveryManagerIf(this);
	}

	void
	SessionManagerOld::ioService(IOService* ioService)
	{
		ioService_ = ioService;
	}

	void
	SessionManagerOld::openServerSocket(
		const std::string& prefixSessionConfig, Config& sessionConfig, 
		const std::string& prefixSecureChannelConfig, Config& secureChannelConfig
	)
	{
		prefixSessionConfig_ = prefixSessionConfig;
		prefixSecureChannelConfig_ = prefixSecureChannelConfig;
		sessionConfig_ = &sessionConfig;
		secureChannelConfig_ = &secureChannelConfig;

		// read configuration
		if (!readConfiguration()) {
			return;
		}

		// open listener socket
		if (!openListenerSocket()) {
			return;
		}

		acceptNewChannel();
	}


	void 
	SessionManagerOld::closeServerSocket(void)
	{
		shutdown_.start();
		closeListenerSocket();
		shutdown_.waitForReady();
	}

	bool 
	SessionManagerOld::readConfiguration(void)
	{
		// get secure channel configuration
		boost::optional<Config> childSecureChannelConfig = secureChannelConfig_->getChild(prefixSecureChannelConfig_);
		if (!childSecureChannelConfig) {
			Log(Error, "secure channel server configuration not found")
				.parameter("ConfigurationFileName", secureChannelConfig_->configFileName())
				.parameter("ParameterPath", prefixSecureChannelConfig_);
			return false;
		}

		// get endpoint url from configuration 
		std::string endpointUrl;
		if (childSecureChannelConfig->getConfigParameter("EndpointUrl", endpointUrl) == false) {
			Log(Error, "mandatory parameter not found in configuration")
				.parameter("ConfigurationFileName", secureChannelConfig_->configFileName())
				.parameter("ParameterPath", prefixSecureChannelConfig_)
				.parameter("ParameterName", "EndpointUrl");
			return false;
		}

		// check endpoint url
		url_.url(endpointUrl);
		if (!url_.good()) {
			Log(Error, "invalid endpoint url in server configuration")
				.parameter("ConfigurationFileName", secureChannelConfig_->configFileName())
				.parameter("ParameterPath", prefixSecureChannelConfig_)
				.parameter("EndpointUrl", endpointUrl);
			return false;

		}
		return true;
	}

	SessionOld::SPtr
	SessionManagerOld::createSession(void)
	{
		SessionOld::SPtr session = constructSPtr<SessionOld>();
		session->transactionManager(transactionManagerSPtr_);
		session->sessionManagerIf(this);
		bool rc = SessionConfig::initial(session, prefixSessionConfig_, sessionConfig_);
		if (!rc) {
			Log(Error, "session server configuration  error")
				.parameter("ConfigurationFileName", secureChannelConfig_->configFileName())
				.parameter("ParameterPath", prefixSessionConfig_);
			
			SessionOld::SPtr session;
			return session;
		}
		return session;
	}

	bool 
	SessionManagerOld::openListenerSocket(void)
	{
		std::string host = url_.host();
		boost::asio::io_service& io_service = ioService_->io_service();
		tcpAcceptor_ = constructSPtr<TCPAcceptor>(io_service, host, url_.port());
		tcpAcceptor_->listen();

		Log(Info, "open opc ua listener socket")
			.parameter("Address", url_.host())
			.parameter("Port", url_.port());

		return true;
	}

	bool
	SessionManagerOld::closeListenerSocket(void)
	{
		tcpAcceptor_->close();
		return true;
	}

	void 
	SessionManagerOld::acceptNewChannel(void)
	{
		SecureChannelServer::SPtr secureChannel;
		bool rc;

		// create secure channel
		secureChannel = constructSPtr<SecureChannelServer>(*ioService_);
		secureChannel->secureChannelManagerIf(this);
		rc = SecureChannelServerConfig::initial(secureChannel, prefixSecureChannelConfig_, secureChannelConfig_);
		if (!rc) {
			Log(Error, "secure channel server configuration  error")
				.parameter("ConfigurationFileName", secureChannelConfig_->configFileName())
				.parameter("ParameterPath", prefixSecureChannelConfig_);
			return;
		}

		// save channel
		secureChannelMap_.insert(secureChannel->channelId(), secureChannel);

		// accept new channel
		tcpAcceptor_->async_accept(
			secureChannel->tcpConnection().socket(),
			boost::bind(&SessionManagerOld::handleAccept, this, boost::asio::placeholders::error, secureChannel)
		);
	}

	void 
	SessionManagerOld::handleAccept(const boost::system::error_code& error, SecureChannelServer::SPtr secureChannel)
	{
		if (shutdown_.isStart()) {
			shutdown_.ready();
			return;
		}

		boost::asio::ip::tcp::endpoint remoteEndpoint = secureChannel->tcpConnection().socket().remote_endpoint();
		boost::asio::ip::tcp::endpoint localEndpoint = secureChannel->tcpConnection().socket().local_endpoint();
		if (error) {
			Log(Error, "server socket error")
				.parameter("LocalAddress", localEndpoint.address().to_string())
				.parameter("LocalPort", localEndpoint.port())
				.parameter("PartnerAddress", remoteEndpoint.address().to_string())
				.parameter("PartnerPort", remoteEndpoint.port());

			// FIXME: what doing now?

			return;
		}

		Log(Info, "server accept connection")
			.parameter("LocalAddress", localEndpoint.address().to_string())
			.parameter("LocalPort", localEndpoint.port())
			.parameter("PartnerAddress", remoteEndpoint.address().to_string())
			.parameter("PartnerPort", remoteEndpoint.port());

		bool rc = secureChannel->connect();
		if (!rc) {
			Log(Error, "cannot accept connection from client")
				.parameter("LocalAddress", localEndpoint.address().to_string())
				.parameter("LocalPort", localEndpoint.port())
				.parameter("PartnerAddress", remoteEndpoint.address().to_string())
				.parameter("PartnerPort", remoteEndpoint.port());

			secureChannelMap_.disconnect(secureChannel->channelId());
			acceptNewChannel();
			return;
		}

		acceptNewChannel();
	}

	SessionOld::SPtr
	SessionManagerOld::getSession(OpcUaUInt32 authenticationToken, bool createIfNotExist)
	{
		SessionOld::SPtr session = sessionMap_.get(authenticationToken);
		if (session.get() == nullptr && createIfNotExist) {
			Log(Debug, "session not exist")
				.parameter("AuthenticationToken", authenticationToken);

			session = createSession();
			sessionMap_.insert(session->authenticationToken(), session);
		}
		return session;
	}
	
	SecureChannelServer::SPtr 
	SessionManagerOld::getSecureChannel(OpcUaUInt32 secureChannelId)
	{
		SecureChannelServer::SPtr secureChannel = secureChannelMap_.get(secureChannelId);
		return secureChannel;
	}

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// SecureChannelManagerIf
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	void 
	SessionManagerOld::connect(OpcUaUInt32 channelId)
	{
		secureChannelMap_.connect(channelId);
	}
	
	void 
	SessionManagerOld::disconnect(OpcUaUInt32 channelId)
	{
		secureChannelMap_.disconnect(channelId);
	}
		
	bool 
	SessionManagerOld::secureChannelMessage(SecureChannelTransaction::SPtr secureChannelTransaction)
	{
		switch (secureChannelTransaction->requestTypeNodeId_.nodeId<uint32_t>())
		{
			case OpcUaId_GetEndpointsRequest_Encoding_DefaultBinary:
			{
				return discoveryService_->message(secureChannelTransaction);
			}
		}

		SessionOld::SPtr session = getSession(secureChannelTransaction->authenticationToken_, true);
		if (session.get() != nullptr) {
			return session->message(secureChannelTransaction);
		}

		Log(Error, "session not found")
			.parameter("AuthenticationToken", secureChannelTransaction->authenticationToken_)
			.parameter("ChannelId", secureChannelTransaction->channelId_);
		return false;
	}

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// SessionManagerIf
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	void 
	SessionManagerOld::sessionMessage(SecureChannelTransaction::SPtr secureChannelTransaction)
	{
		SecureChannelServer::SPtr secureChannel = getSecureChannel(secureChannelTransaction->channelId_);
		if (secureChannel.get() != nullptr) {
			secureChannel->message(secureChannelTransaction);
			return;
		}

		Log(Error, "secure channel not found (session service)")
			.parameter("AuthenticationToken", secureChannelTransaction->authenticationToken_)
			.parameter("ChannelId", secureChannelTransaction->channelId_);
	}

	void
	SessionManagerOld::sessionDelete(uint32_t authenticationToken)
	{
		sessionMap_.remove(authenticationToken);
	}

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// DiscoveryManagerIf
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	void 
	SessionManagerOld::discoveryMessage(SecureChannelTransaction::SPtr secureChannelTransaction)
	{
		SecureChannelServer::SPtr secureChannel = getSecureChannel(secureChannelTransaction->channelId_);
		if (secureChannel.get() != nullptr) {
			secureChannel->message(secureChannelTransaction);
			return;
		}

		Log(Error, "secure channel not found (discovers service)")
			.parameter("AuthenticationToken", secureChannelTransaction->authenticationToken_)
			.parameter("ChannelId", secureChannelTransaction->channelId_);
	}

}
