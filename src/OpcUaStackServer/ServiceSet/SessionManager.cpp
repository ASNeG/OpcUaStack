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

	bool
	SessionManager::openServerSocket(
		const std::string& prefixSessionConfig, Config& sessionConfig, 
		const std::string& prefixSecureChannelConfig, Config& secureChannelConfig
	)
	{
		bool rc;

		std::string configurationFileName = secureChannelConfig.getValue("Global.ConfigurationFileName", "Unknown");

		// get secure channel configuration
		boost::optional<Config> childSecureChannelConfig = secureChannelConfig.getChild(prefixSecureChannelConfig);
		if (!childSecureChannelConfig) {
			Log(Error, "secure channel server configuration not found")
				.parameter("ConfigurationFileName", configurationFileName)
				.parameter("ParameterPath", prefixSecureChannelConfig);
			return false;
		}

		// get endpoint url from configuration 
		std::string endpointUrl;
		if (childSecureChannelConfig->getConfigParameter("EndpointUrl", endpointUrl) == false) {
			Log(Error, "mandatory parameter not found in configuration")
				.parameter("ConfigurationFileName", configurationFileName)
				.parameter("ParameterPath", prefixSecureChannelConfig)
				.parameter("ParameterName", "EndpointUrl");
			return false;
		}

		// check endpoint url
		Url url;
		url.url(endpointUrl);
		if (!url.good()) {
			Log(Error, "invalid endpoint url in server configuration")
				.parameter("ConfigurationFileName", configurationFileName)
				.parameter("ParameterPath", prefixSecureChannelConfig)
				.parameter("EndpointUrl", endpointUrl);
			return false;

		}

		// create session 
		session_ = Session::construct();
		session_->transactionManager(transactionManagerSPtr_);
		session_->sessionSecureChannelIf(this);
		session_->sessionId(1);
		session_->authenticationToken(1);
		rc = SessionConfig::initial(session_, prefixSessionConfig, &sessionConfig);
		if (!rc) {
			session_.reset();

			Log(Error, "session server configuration  error")
				.parameter("ConfigurationFileName", configurationFileName)
				.parameter("ParameterPath", prefixSessionConfig);
			return false;
		}

		// create secure channel
		secureChannel_ = SecureChannelServer::construct(ioService_);
		secureChannel_->secureChannelIf(this);
		rc = SecureChannelServerConfig::initial(secureChannel_, prefixSecureChannelConfig, &secureChannelConfig);
		if (!rc) {
			secureChannel_.reset();
			session_.reset();

			Log(Error, "secure channel server configuration  error")
				.parameter("ConfigurationFileName", configurationFileName)
				.parameter("ParameterPath", prefixSecureChannelConfig);
			return false;
		}

		// bind server socket
		std::string host = url.host();
		boost::asio::io_service& io_service = ioService_.io_service();
		tcpAcceptor_ = TCPAcceptor::construct(io_service, host, url.port());
		tcpAcceptor_->listen();
		tcpAcceptor_->async_accept(
			secureChannel_->tcpConnection().socket(),
			boost::bind(&SessionManager::handleAccept, this, boost::asio::placeholders::error, secureChannel_)
		);

		return true;
	}


	void 
	SessionManager::closeServerSocket(void)
	{
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

			// FIXME: todo
		}
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
	}
	
	void 
	SessionManager::disconnect(void)
	{
		// FIXME:
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