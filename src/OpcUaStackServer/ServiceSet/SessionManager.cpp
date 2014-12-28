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
	: session_()
	, secureChannel_()
	, prefixSessionConfig_("")
	, prefixSecureChannelConfig_("") 
	, sessionConfig_(nullptr)
	, secureChannelConfig_(nullptr)
	, ioService_(nullptr)
	, tcpAcceptor_()
	, url_()
	, secureChannelMap_()
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
		discoveryService_->sessionManagerIf(this);
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

	void
	SessionManager::createSession(void)
	{
		session_ = Session::construct();
		session_->transactionManager(transactionManagerSPtr_);
		session_->sessionManagerIf(this);
		session_->sessionId(1);
		session_->authenticationToken(1);
		bool rc = SessionConfig::initial(session_, prefixSessionConfig_, sessionConfig_);
		if (!rc) {
			session_.reset();

			Log(Error, "session server configuration  error")
				.parameter("ConfigurationFileName", secureChannelConfig_->configFileName())
				.parameter("ParameterPath", prefixSessionConfig_);
			return;
		}
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
			secureChannel.reset();
			session_.reset();

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

		secureChannel_ = secureChannel;
		createSession();
		acceptNewChannel();
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
	SessionManager::receive(OpcUaNodeId& nodeId, boost::asio::streambuf& is, SecureChannelTransaction& secureChannelTransaction)
	{
		if (nodeId.nodeId<uint32_t>() == OpcUaId_GetEndpointsRequest_Encoding_DefaultBinary) {
			return receiveGetEndpointsRequest(nodeId, is, secureChannelTransaction);
		}
		return session_->receive(nodeId, is, secureChannelTransaction);
	}

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// SessionSecureChannelIf
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	void 
	SessionManager::createSessionResponse(boost::asio::streambuf& sb, SecureChannelTransaction& secureChannelTransaction)
	{
		OpcUaNodeId typeId;
		typeId.set(OpcUaId_CreateSessionResponse_Encoding_DefaultBinary);
		secureChannel_->send(typeId, sb, secureChannelTransaction);
	}

	void 
	SessionManager::activateSessionResponse(boost::asio::streambuf& sb, SecureChannelTransaction& secureChannelTransaction)
	{
		OpcUaNodeId typeId;
		typeId.set(OpcUaId_ActivateSessionResponse_Encoding_DefaultBinary);
		secureChannel_->send(typeId, sb, secureChannelTransaction);
	}

	void 
	SessionManager::send(OpcUaNodeId& opcUaNodeId, boost::asio::streambuf& sb, SecureChannelTransaction& secureChannelTransaction)
	{
		secureChannel_->send(opcUaNodeId, sb, secureChannelTransaction);
	}

	bool
	SessionManager::receiveGetEndpointsRequest(OpcUaNodeId& nodeId, boost::asio::streambuf& sb, SecureChannelTransaction& secureChannelTransaction)
	{
		return discoveryService_->receiveGetEndpointsRequest(nodeId, sb, secureChannelTransaction);
	}

}