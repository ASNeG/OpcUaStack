/*
   Copyright 2017-2021 Kai Huebl (kai@huebl-sgh.de)

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

#ifndef __OpcUaServer_DiscoveryClient_h__
#define __OpcUaServer_DiscoveryClient_h__

#include <OpcUaStackCore/MessageBus/MessageBus.h>
#include "OpcUaStackCore/Base/Config.h"
#include "OpcUaStackClient/ApplicationUtility/DiscoveryClientRegisteredServers.h"

namespace OpcUaServer
{

	class DLLEXPORT DiscoveryClient
	{
	  public:
		using SPtr = boost::shared_ptr<DiscoveryClient>;

		DiscoveryClient(void);
		~DiscoveryClient(void);

		void cryptoManager(OpcUaStackCore::CryptoManager::SPtr& cryptoManager);
		void ioThread(const OpcUaStackCore::IOThread::SPtr& ioThread);
		void messageBus(const OpcUaStackCore::MessageBus::SPtr& messageBus);

		bool startup(OpcUaStackCore::Config& config);
		void shutdown(void);
		
	  private:
		bool parseEndpointConfiguration(OpcUaStackCore::Config& config);
		bool createRegisteredServers(
			const std::string& applicationUri,
			const std::string& productUri,
			const std::string& applicationName,
			const std::string& discoveryUrl,
			const std::string& gatewayServerUri
		);

		bool enable_;
		std::string discoveryServerUrl_;
		uint32_t registerInterval_;

		bool ioThreadInt_ = false;
		bool messageBusInt_ = false;

		OpcUaStackCore::Config* config_;
		OpcUaStackCore::IOThread::SPtr ioThread_;
		OpcUaStackCore::MessageBus::SPtr messageBus_;
		OpcUaStackClient::DiscoveryClientRegisteredServers discoveryClient_;
		OpcUaStackCore::RegisteredServer::Vec registeredServerVec_;
		OpcUaStackCore::CryptoManager::SPtr cryptoManager_;
	};

}

#endif
