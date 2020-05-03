/*
   Copyright 2017-2020 Kai Huebl (kai@huebl-sgh.de)

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

#ifndef __OpcUaStackClient_DiscoveryClientRegisteredServers_h__
#define __OpcUaStackClient_DiscoveryClientRegisteredServers_h__

#include "OpcUaStackCore/Core/Core.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/StandardDataTypes/RegisteredServer.h"
#include "OpcUaStackCore/Utility/IOThread.h"
#include "OpcUaStackClient/ServiceSet/ServiceSetManager.h"

namespace OpcUaStackClient
{

	typedef std::map<std::string, OpcUaStackCore::RegisteredServer::SPtr> RegisteredServerMap;

	/**
	 * The discovery client registered server is used to register all endpoints.
	 */
	class DLLEXPORT DiscoveryClientRegisteredServers
	{
	  public:
		using SPtr = boost::shared_ptr<DiscoveryClientRegisteredServers>;
		using ShutdownCompleteCallback = std::function<void (void)>;

		class ShutdownContext
		{
		  public:
			using SPtr = boost::shared_ptr<ShutdownContext>;
			ShutdownCompleteCallback shutdownCompleteCallback_;
		};

		DiscoveryClientRegisteredServers(void);
	    ~DiscoveryClientRegisteredServers(void);

	    void cryptoManager(OpcUaStackCore::CryptoManager::SPtr& cryptoManager);
	    void ioThread(OpcUaStackCore::IOThread::SPtr& ioThread);
	    void messageBus(OpcUaStackCore::MessageBus::SPtr& messageBus);
	    void discoveryUri(const std::string& discoveryUri);
	    void registerInterval(uint32_t registerInterval);

		bool startup(void);
		void asyncShutdown(const ShutdownCompleteCallback& shutdownCompleteCallback);
		void syncShutdown(void);

		void addRegisteredServer(
			const std::string& name,
			OpcUaStackCore::RegisteredServer::SPtr& registeredServer
		);
		void removeRegisteredServer(
			const std::string& name
		);

	  private:
		void shutdownComplete(void);
		void discoveryServiceRegisterServerResponse(
			OpcUaStackCore::ServiceTransactionRegisterServer::SPtr& serviceTransactionRegisterServer
		);
        void sendDiscoveryServiceRegisterServer(void);
        void deregisterServers(void);
        void disconnectSession(void);

		ShutdownContext::SPtr shutdownContext_ = nullptr;
		SessionServiceStateId sessionState_ = SessionServiceStateId::Disconnected;

		boost::shared_ptr<boost::asio::io_service::strand> strand_;
		OpcUaStackCore::MessageBus::SPtr messageBus_;
		OpcUaStackCore::IOThread::SPtr ioThread_;
		std::string threadPoolName_;
		OpcUaStackCore::SlotTimerElement::SPtr slotTimerElement_;
		RegisteredServerMap registeredServerMap_;

		std::string discoveryUri_;
		uint32_t registerInterval_;

		OpcUaStackCore::CryptoManager::SPtr cryptoManager_;
		ServiceSetManager serviceSetManager_;
		SessionService::SPtr sessionService_;
		DiscoveryService::SPtr discoveryService_;
	};

}

#endif
