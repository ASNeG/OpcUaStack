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

#ifndef __OpcUaStackServer_SessionManager_h__
#define __OpcUaStackServer_SessionManager_h__

#include <boost/thread/mutex.hpp>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/Base/Config.h"
#include "OpcUaStackCore/Base/IOService.h"
#include "OpcUaStackCore/TCPChannel/TCPAcceptor.h"
#include "OpcUaStackCore/Base/Url.h"
#include "OpcUaStackCore/Base/ConditionProcess.h"
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
		virtual ~SessionManager(void);

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
		bool secureChannelMessage(SecureChannelTransaction::SPtr secureChannelTransaction);
		//- SecureChannelManagerIf --------------------------------------------

		//- SessionManagerIf---------------------------------------------------
		void sessionMessage(SecureChannelTransaction::SPtr secureChannelTransaction);
		void sessionDelete(uint32_t authenticationToken);
		//- SessionManagerIf --------------------------------------------------

		//- DiscoveryManagerIf ------------------------------------------------
		void discoveryMessage(SecureChannelTransaction::SPtr secureChannelTransaction);
		//- DiscoveryManagerIf ------------------------------------------------

	  private:
		bool readConfiguration(void);
		bool openListenerSocket(void);
		bool closeListenerSocket(void);

		SecureChannelServer::SPtr getSecureChannel(OpcUaUInt32 secureChannelId);

		Session::SPtr getSession(OpcUaUInt32 authenticationToken, bool createIfNotExist = false);
		Session::SPtr createSession(void);

		// function to handle secure channel
		void acceptNewChannel(void);
		void handleAccept(const boost::system::error_code& error, SecureChannelServer::SPtr secureChannel);

		IOService* ioService_;
		ConditionProcess shutdown_;

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
