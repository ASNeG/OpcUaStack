#ifndef __OpcUaStackServer_SessionManager_h__
#define __OpcUaStackServer_SessionManager_h__

#include <boost/thread/mutex.hpp>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/Base/Config.h"
#include "OpcUaStackCore/Base/IOService.h"
#include "OpcUaStackCore/TCPChannel/TCPAcceptor.h"
#include "OpcUaStackServer/SecureChannel/SecureChannelServerConfig.h"
#include "OpcUaStackServer/SecureChannel/SecureChannelIf.h"
#include "OpcUaStackServer/ServiceSet/SessionConfig.h"
#include "OpcUaStackServer/ServiceSet/TransactionManager.h"

using namespace OpcUaStackCore;

namespace OpcUaStackServer
{

	class DLLEXPORT SessionManager : public SecureChannelIf, public SessionSecureChannelIf
	{
	  public:
		static SessionManager* instance_;
		static SessionManager* instance(void);

		SessionManager(void);
		~SessionManager(void);

		void transactionManager(TransactionManager::SPtr transactionManagerSPtr);

		void start(void);
		void stop(void);

		bool openServerSocket(
			const std::string& prefixSessionConfig, Config& sessionConfig, 
			const std::string& prefixSecureChannelConfig, Config& secureChannelConfig
		);
		void closeServerSocket(void);

		//- SecureChannelIf ---------------------------------------------------
		void connect(void);
		void disconnect(void);
		bool receive(OpcUaNodeId& nodeId, boost::asio::streambuf& is);
		//- SecureChannelIf ---------------------------------------------------

		//- SessionSecureChannelIf --------------------------------------------
		void createSessionResponse(boost::asio::streambuf& sb);
		void activateSessionResponse(boost::asio::streambuf& sb);
		void send(OpcUaNodeId& opcUaNodeId, boost::asio::streambuf& sb);
		//- SessionSecurechannelIf --------------------------------------------

	  private:
		void handleAccept(const boost::system::error_code& error, SecureChannelServer::SPtr secureChannel);

		bool receiveGetEndpointsRequest(OpcUaNodeId& nodeId, boost::asio::streambuf& is);

		IOService ioService_;

		TCPAcceptor::SPtr tcpAcceptor_;
		SecureChannelServer::SPtr secureChannel_;
		Session::SPtr session_;

		TransactionManager::SPtr transactionManagerSPtr_;
	};

}

#endif
