#include "OpcUaStackServer/ServiceSet/SessionManager.h"
#include "OpcUaStackCore/Base/Log.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaIdentifier.h"

namespace OpcUaStackServer
{

	SessionManager* SessionManager::instance_ = nullptr;
	
	SessionManager* 
	SessionManager::instance(void)
	{
		if (instance_ == NULL) {
			instance_ = new SessionManager();
		}
		return instance_;
	}

	SessionManager::SessionManager(void)
	: prefixSessionConfig_("")
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

	SessionManager::~SessionManager(void)
	{
	}

	void 
	SessionManager::transactionManager(TransactionManager::SPtr transactionManagerSPtr)
	{
		transactionManagerSPtr_ = transactionManagerSPtr;
	}

	void 
	SessionManager::discoveryService(DiscoveryService::SPtr discoveryService)
	{
		discoveryService_ = discoveryService;
		discoveryService_->discoveryManagerIf(this);
	}

	void
	SessionManager::ioService(IOService* ioService)
	{
		ioService_ = ioService;
	}

	void
	SessionManager::openServerSocket(
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
	SessionManager::closeServerSocket(void)
	{
	}

	bool 
	SessionManager::readConfiguration(void)
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

	Session::SPtr
	SessionManager::createSession(void)
	{
		Session::SPtr session = Session::construct();
		session->transactionManager(transactionManagerSPtr_);
		session->sessionManagerIf(this);
		bool rc = SessionConfig::initial(session, prefixSessionConfig_, sessionConfig_);
		if (!rc) {
			Log(Error, "session server configuration  error")
				.parameter("ConfigurationFileName", secureChannelConfig_->configFileName())
				.parameter("ParameterPath", prefixSessionConfig_);
			
			Session::SPtr session;
			return session;
		}
		return session;
	}

	bool 
	SessionManager::openListenerSocket(void)
	{
		std::string host = url_.host();
		boost::asio::io_service& io_service = ioService_->io_service();
		tcpAcceptor_ = TCPAcceptor::construct(io_service, host, url_.port());
		tcpAcceptor_->listen();
		return true;
	}

	void 
	SessionManager::acceptNewChannel(void)
	{
		SecureChannelServer::SPtr secureChannel;
		bool rc;

		// create secure channel
		secureChannel = SecureChannelServer::construct(*ioService_);
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
			boost::bind(&SessionManager::handleAccept, this, boost::asio::placeholders::error, secureChannel)
		);
	}

	void 
	SessionManager::handleAccept(const boost::system::error_code& error, SecureChannelServer::SPtr secureChannel)
	{
		bool rc;

		boost::asio::ip::tcp::endpoint remoteEndpoint = secureChannel->tcpConnection().socket().remote_endpoint();
		boost::asio::ip::tcp::endpoint localEndpoint = secureChannel->tcpConnection().socket().local_endpoint();

		Log(Info, "server accept connection")
			.parameter("LocalAddress", localEndpoint.address().to_string())
			.parameter("LocalPort", localEndpoint.port())
			.parameter("PartnerAddress", remoteEndpoint.address().to_string())
			.parameter("PartnerPort", remoteEndpoint.port());

		rc = secureChannel->connect();
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

	Session::SPtr 
	SessionManager::getSession(OpcUaUInt32 authenticationToken, bool createIfNotExist)
	{
		Session::SPtr session = sessionMap_.get(authenticationToken);
		if (session.get() == nullptr && createIfNotExist) {
			Log(Debug, "session not exist")
				.parameter("AuthenticationToken", authenticationToken);

			session = createSession();
			sessionMap_.insert(session->authenticationToken(), session);
		}
		return session;
	}
	
	SecureChannelServer::SPtr 
	SessionManager::getSecureChannel(OpcUaUInt32 secureChannelId)
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
	SessionManager::connect(OpcUaUInt32 channelId)
	{
		secureChannelMap_.connect(channelId);
	}
	
	void 
	SessionManager::disconnect(OpcUaUInt32 channelId)
	{
		secureChannelMap_.disconnect(channelId);
	}
		
	bool 
	SessionManager::secureChannelMessage(SecureChannelTransaction& secureChannelTransaction)
	{
		switch (secureChannelTransaction.requestTypeNodeId_.nodeId<uint32_t>())
		{
			case OpcUaId_GetEndpointsRequest_Encoding_DefaultBinary:
			{
				return discoveryService_->message(secureChannelTransaction);
			}
		}

		Session::SPtr session = getSession(secureChannelTransaction.authenticationToken_, true);
		if (session.get() != nullptr) {
			return session->message(secureChannelTransaction);
		}

		Log(Error, "session not found")
			.parameter("AuthenticationToken", secureChannelTransaction.authenticationToken_)
			.parameter("ChannelId", secureChannelTransaction.channelId_);
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
	SessionManager::sessionMessage(boost::asio::streambuf& sb, SecureChannelTransaction& secureChannelTransaction)
	{
		SecureChannelServer::SPtr secureChannel = getSecureChannel(secureChannelTransaction.channelId_);
		if (secureChannel.get() != nullptr) {
			secureChannel->message(sb, secureChannelTransaction);
			return;
		}

		Log(Error, "secure channel not found (session service)")
			.parameter("AuthenticationToken", secureChannelTransaction.authenticationToken_)
			.parameter("ChannelId", secureChannelTransaction.channelId_);
	}

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// DiscoveryManagerIf
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	void 
	SessionManager::discoveryMessage(boost::asio::streambuf& sb, SecureChannelTransaction& secureChannelTransaction)
	{
		SecureChannelServer::SPtr secureChannel = getSecureChannel(secureChannelTransaction.channelId_);
		if (secureChannel.get() != nullptr) {
			secureChannel->message(sb, secureChannelTransaction);
			return;
		}

		Log(Error, "secure channel not found (discovers service)")
			.parameter("AuthenticationToken", secureChannelTransaction.authenticationToken_)
			.parameter("ChannelId", secureChannelTransaction.channelId_);
	}

}
