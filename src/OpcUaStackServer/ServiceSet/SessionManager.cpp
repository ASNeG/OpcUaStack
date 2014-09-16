#include "OpcUaStackServer/ServiceSet/SessionManager.h"
#include "OpcUaStackCore/Base/Log.h"
#include "OpcUaStackCore/Base/Url.h"
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
		discoveryService_->sessionSecureChannelIf(this);
	}

	void 
	SessionManager::start(void)
	{
		ioService_.start();
	}
		
	void 
	SessionManager::stop(void)
	{
		ioService_.stop();
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

		acceptNewChannel();
	}


	void 
	SessionManager::closeServerSocket(void)
	{
	}

	void 
	SessionManager::acceptNewChannel(void)
	{
		SecureChannelServer::SPtr secureChannel;
		Session::SPtr session;
		bool rc;

		std::string configurationFileName = secureChannelConfig_->getValue("Global.ConfigurationFileName", "Unknown");

		// get secure channel configuration
		boost::optional<Config> childSecureChannelConfig = secureChannelConfig_->getChild(prefixSecureChannelConfig_);
		if (!childSecureChannelConfig) {
			Log(Error, "secure channel server configuration not found")
				.parameter("ConfigurationFileName", configurationFileName)
				.parameter("ParameterPath", prefixSecureChannelConfig_);
			return;
		}

		// get endpoint url from configuration 
		std::string endpointUrl;
		if (childSecureChannelConfig->getConfigParameter("EndpointUrl", endpointUrl) == false) {
			Log(Error, "mandatory parameter not found in configuration")
				.parameter("ConfigurationFileName", configurationFileName)
				.parameter("ParameterPath", prefixSecureChannelConfig_)
				.parameter("ParameterName", "EndpointUrl");
			return;
		}

		// check endpoint url
		Url url;
		url.url(endpointUrl);
		if (!url.good()) {
			Log(Error, "invalid endpoint url in server configuration")
				.parameter("ConfigurationFileName", configurationFileName)
				.parameter("ParameterPath", prefixSecureChannelConfig_)
				.parameter("EndpointUrl", endpointUrl);
			return;

		}

		// create session 
		session = Session::construct();
		session->transactionManager(transactionManagerSPtr_);
		session->sessionSecureChannelIf(this);
		session->sessionId(1);
		session->authenticationToken(1);
		rc = SessionConfig::initial(session, prefixSessionConfig_, sessionConfig_);
		if (!rc) {
			session.reset();

			Log(Error, "session server configuration  error")
				.parameter("ConfigurationFileName", configurationFileName)
				.parameter("ParameterPath", prefixSessionConfig_);
			return;
		}

		// create secure channel
		secureChannel = SecureChannelServer::construct(ioService_);
		secureChannel->secureChannelIf(this);
		rc = SecureChannelServerConfig::initial(secureChannel, prefixSecureChannelConfig_, secureChannelConfig_);
		if (!rc) {
			secureChannel.reset();
			session.reset();

			Log(Error, "secure channel server configuration  error")
				.parameter("ConfigurationFileName", configurationFileName)
				.parameter("ParameterPath", prefixSecureChannelConfig_);
			return;
		}

		// bind server socket
		std::string host = url.host();
		boost::asio::io_service& io_service = ioService_.io_service();
		tcpAcceptor_ = TCPAcceptor::construct(io_service, host, url.port());
		tcpAcceptor_->listen();
		tcpAcceptor_->async_accept(
			secureChannel->tcpConnection().socket(),
			boost::bind(&SessionManager::handleAccept, this, boost::asio::placeholders::error, secureChannel, session)
		);
	}

	void 
	SessionManager::handleAccept(const boost::system::error_code& error, SecureChannelServer::SPtr secureChannel, Session::SPtr session)
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

			// FIXME: todo
		}

		secureChannel_ = secureChannel;
		session_ = session;
		acceptNewChannel();
	}


	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// SecureChannelIf
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	void 
	SessionManager::connect(void)
	{
		std::cout << "SECURE CHANNEL CONNECT" << std::endl;
	}
	
	void 
	SessionManager::disconnect(void)
	{
		std::cout << "SECURE CHANNEL DISCONNECT" << std::endl;
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