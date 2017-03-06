/*
   Copyright 2017 Kai Huebl (kai@huebl-sgh.de)

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

#include "OpcUaStackCore/Base/Config.h"
#include "OpcUaStackClient/ApplicationUtility/DiscoveryClientRegisteredServers.h"

using namespace OpcUaStackCore;
using namespace OpcUaStackClient;

namespace OpcUaServer
{

	class DiscoveryClient
	{
	  public:
		DiscoveryClient(void);
		~DiscoveryClient(void);

		bool startup(Config& config);
		void shutdown(void);
		
	  private:
		bool parseEndpointConfiguration(Config& config);
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

		Config* config_;
		IOThread::SPtr ioThread_;
		DiscoveryClientRegisteredServers discoveryClient_;
		RegisteredServer::Vec registeredServerVec_;
	};

}

#endif
