#ifndef __OpcUaStackServer_SessionManager_h__
#define __OpcUaStackServer_SessionManager_h__

#include <boost/thread/mutex.hpp>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/Base/Config.h"
#include "OpcUaStackCore/Base/IOService.h"
#include "OpcUaStackCore/TCPChannel/TCPAcceptor.h"
#include "OpcUaStackServer/SecureChannel/SecureChannelServerConfig.h"
//#include "OpcUaStackServer/ServiceSet/SessionConfig.h"

using namespace OpcUaStackCore;

namespace OpcUaStackServer
{

	class DLLEXPORT SessionManager //: public SessionSecureChannelIf, public SecureChannelIf
	{
	  public:
		static SessionManager* instance_;
		static SessionManager* instance(void);

		SessionManager(void);
		~SessionManager(void);

		void start(void);
		void stop(void);

		bool openServerSocket(
			const std::string& prefixSessionConfig, Config& sessionConfig, 
			const std::string& prefixSecureChannelConfig, Config& secureChannelConfig
		);
		void closeServerSocket(void);

#if 0
		Session::SPtr getNewSession(
			const std::string& prefixSessionConfig, Config& sessionConfig, 
			const std::string& prefixSecureChannelConfig, Config& secureChannelConfig, 
			SessionIf* sessionIf,
			bool newSecureChannel = false
		);
		void deleteSession(void);

		//- SessionSecureChannelIf --------------------------------------------
		void connectToSecureChannel(void); 
	    void createSessionRequest(boost::asio::streambuf& sb);
		void activateSessionRequest(boost::asio::streambuf& sb);
		void send(OpcUaNodeId& opcUaNodeId, boost::asio::streambuf& sb);
		//- SessionSecurechannelIf --------------------------------------------

		//- SecureChannelIf ---------------------------------------------------
		void connect(void);
		void disconnect(void);
		bool receive(OpcUaNodeId& nodeId, boost::asio::streambuf& is);
		//- SecureChannelIf ---------------------------------------------------
#endif
	  private:
		void handleAccept(const boost::system::error_code& error, SecureChannelServer::SPtr secureChannel);

		IOService ioService_;

		TCPAcceptor::SPtr tcpAcceptor_;
		SecureChannelServer::SPtr secureChannel_;
#if 0
		Session::SPtr session_;
#endif
	};

}

#endif
