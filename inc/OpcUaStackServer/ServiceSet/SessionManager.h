#ifndef __OpcUaStackServer_SessionManager_h__
#define __OpcUaStackServer_SessionManager_h__

#include <boost/thread/mutex.hpp>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/Base/Config.h"
#include "OpcUaStackCore/Base/IOService.h"
#include "OpcUaStackCore/TCPChannel/TCPAcceptor.h"
#include "OpcUaStackCore/Base/Url.h"
#include "OpcUaStackServer/SecureChannel/SecureChannelServerConfig.h"
#include "OpcUaStackServer/SecureChannel/SecureChannelManagerIf.h"
#include "OpcUaStackServer/SecureChannel/SecureChannelMap.h"
#include "OpcUaStackServer/ServiceSet/SessionConfig.h"
#include "OpcUaStackServer/ServiceSet/TransactionManager.h"
#include "OpcUaStackServer/ServiceSet/DiscoveryService.h"
#include "OpcUaStackServer/ServiceSet/SessionMap.h"
#include "OpcUaStackServer/ServiceSet/DiscoveryManagerIf.h"

using namespace OpcUaStackCore;

namespace OpcUaStackServer
{

	class DLLEXPORT SessionManager 
	: public SecureChannelManagerIf
	, public SessionManagerIf
	, public DiscoveryManagerIf
	{
	  public:
		static SessionManager* instance_;
		static SessionManager* instance(void);

		typedef boost::shared_ptr<SessionManager> SPtr;

		SessionManager(void);
		~SessionManager(void);

		void transactionManager(TransactionManager::SPtr transactionManagerSPtr);
		void discoveryService(DiscoveryService::SPtr discoveryService);
		void ioService(IOService* ioService);

		void openServerSocket(
			const std::string& prefixSessionConfig, Config& sessionConfig, 
			const std::string& prefixSecureChannelConfig, Config& secureChannelConfig
		);
		void closeServerSocket(void);

		//- SecureChannelManagerIf --------------------------------------------
		void connect(OpcUaUInt32 channelId);
		void disconnect(OpcUaUInt32 channelId);
		bool secureChannelMessage(boost::asio::streambuf& is, SecureChannelTransaction& secureChannelTransaction);
		//- SecureChannelManagerIf --------------------------------------------

		//- SessionManagerIf---------------------------------------------------
		void sessionMessage(boost::asio::streambuf& sb, SecureChannelTransaction& secureChannelTransaction);
		//- SessionManagerIf --------------------------------------------------

		//- DiscoveryManagerIf ------------------------------------------------
		void discoveryMessage(boost::asio::streambuf& sb, SecureChannelTransaction& secureChannelTransaction);
		//- DiscoveryManagerIf ------------------------------------------------

	  private:
		bool readConfiguration(void);
		bool openListenerSocket(void);

		SecureChannelServer::SPtr getSecureChannel(OpcUaUInt32 secureChannelId);

		Session::SPtr getSession(OpcUaUInt32 authenticationToken, bool createIfNotExist = false);
		Session::SPtr createSession(void);

		// function to handle secure channel
		void acceptNewChannel(void);
		void handleAccept(const boost::system::error_code& error, SecureChannelServer::SPtr secureChannel);

		IOService* ioService_;

		Url url_;
		TCPAcceptor::SPtr tcpAcceptor_;
		DiscoveryService::SPtr discoveryService_;
		TransactionManager::SPtr transactionManagerSPtr_;

		// server configuration
		std::string prefixSessionConfig_;
		std::string prefixSecureChannelConfig_; 
		Config* sessionConfig_; 
		Config* secureChannelConfig_;

		SecureChannelMap secureChannelMap_;
		SessionMap sessionMap_;
	};

}

#endif
