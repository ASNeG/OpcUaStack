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

#include "OpcUaStackCore/Base/Log.h"
#include "OpcUaServer/Server/DiscoveryClient.h"

using namespace OpcUaStackCore;

namespace OpcUaServer
{

	DiscoveryClient::DiscoveryClient(void)
	: config_(nullptr)
	, discoveryClient_()
	, discoveryUrl_("")
	{
	}

	DiscoveryClient::~DiscoveryClient(void)
	{
	}

	bool
	DiscoveryClient::startup(Config& config)
	{
		bool success;
		config_ = &config;

		//
		// read discovery server configuration
		//

		// check if the discovery registered service is enabled
		boost::optional<Config> dicoveryServerConfig = config.getChild("OpcUaServer.DiscoveryServer");
		if (!dicoveryServerConfig) {
			Log(Info, "discovery registered service is disabled");
			return true;
		}
		Log(Info, "discovery registered service is enabled");

		// get element discovery url
		success = dicoveryServerConfig->getConfigParameter("DiscoveryUrl", discoveryUrl_);
		if (!success) {
			Log(Error, "element missing in config file")
				.parameter("Element", "OpcUaServer.DiscoveryServer.DiscoveryUrl")
				.parameter("ConfigFileName", config.configFileName());
			return false;
		}

		//
		// read endpoint configuration
		//
		if (!parseEndpointConfiguration(config)) {
			return false;
		}



#if 0
	    void ioThread(IOThread::SPtr& ioThread);
	    void loopTime(uint32_t loopTime);
	    void discoveryUri(const std::string& discoveryUri);


#endif


		return true;
	}

	void 
	DiscoveryClient::shutdown(void)
	{
		// FIXME: todo
	}

	bool
	DiscoveryClient::parseEndpointConfiguration(Config& config)
	{
		bool success;

		// get endpoint elements
		std::vector<Config> childs;
		config.getChilds("OpcUaServer.Endpoints.EndpointDescription", childs);
		if (childs.size() == 0) {
			Log(Error, "element missing in config file")
				.parameter("Element", "OpcUaServer.Endpoints.EndpointDescription")
				.parameter("ConfigFileName", config.configFileName());
			return false;
		}

		std::vector<Config>::iterator it;
		for (it = childs.begin(); it != childs.end(); it++) {
			Config& endpointDescriptionConfig = *it;

			// get application uri element
			std::string applicationUri;
			success = endpointDescriptionConfig.getConfigParameter("ApplicationUri", applicationUri);
			if (!success) {
				Log(Error, "element missing in config file")
					.parameter("Element", "OpcUaServer.Endpoints.EndpointDescription.ApplicationUri")
					.parameter("ConfigFileName", config.configFileName());
				return false;
			}

			// get product uri element
			std::string productUri;
			success = endpointDescriptionConfig.getConfigParameter("ProductUri", productUri);
			if (!success) {
				Log(Error, "element missing in config file")
					.parameter("Element", "OpcUaServer.Endpoints.EndpointDescription.ProductUri")
					.parameter("ConfigFileName", config.configFileName());
				return false;
			}

			// get application name element
			std::string applicationName;
			success = endpointDescriptionConfig.getConfigParameter("ApplicationName", applicationName);
			if (!success) {
				Log(Error, "element missing in config file")
					.parameter("Element", "OpcUaServer.Endpoints.EndpointDescription.ApplicationName")
					.parameter("ConfigFileName", config.configFileName());
				return false;
			}

			// get discovery url element
			std::string discoveryUrl;
			success = endpointDescriptionConfig.getConfigParameter("DiscoveryUrl", discoveryUrl);
			if (!success) {
				Log(Error, "element missing in config file")
					.parameter("Element", "OpcUaServer.Endpoints.EndpointDescription.DiscoveryUrl")
					.parameter("ConfigFileName", config.configFileName());
				return false;
			}

			// gatewayServerUri_
			std::string gatewayServerUri;
			endpointDescriptionConfig.getConfigParameter("GatewayServerUri", gatewayServerUri, "");

			// create registered server structures
			success = createRegisteredServers(
				applicationUri,
				productUri,
				applicationName,
				discoveryUrl,
				gatewayServerUri
			);
			if (!success) {
				return false;
			}


		}

#if 0

	    <Endpoints>
	     <EndpointDescription>
	  	  <EndpointUrl>opc.tcp://0.0.0.0:8889</EndpointUrl>
	  	  <ApplicationUri>urn:0.0.0.0:ASNeG.de:ASNeG-Demo</ApplicationUri>
	  	  <ProductUri>urn:ASNeG.de:ASNeG-Demo</ProductUri>
	  	  <ApplicationName>ASNeG-Demo</ApplicationName>
	  	  <DiscoveryUrl>opc.tcp://0.0.0.0:8889</DiscoveryUrl>
	  	  <SecurityPolicyUri>http://opcfoundation.org/UA/SecurityPolicy#None</SecurityPolicyUri>
	  	  <UserTokenPolicy>
	  	    <PolicyId>OpcUaStack</PolicyId>
	  	    <TokenType>Anonymous</TokenType>
	  	  </UserTokenPolicy>
	  	  <TransportProfileUri>http://opcfoundation.org/UA-Profile/Transport/uatcp-uasc-uabinary</TransportProfileUri>
	  	  <SecurityLevel>0</SecurityLevel>
	  	</EndpointDescription>



		void serverUri(const OpcUaString& serverUri);
		void serverUri(const std::string& serverUri);
		OpcUaString& serverUri(void);
		void productUri(const OpcUaString& productUri);
		void productUri(const std::string& productUri);
		OpcUaString& productUri(void);
		void serverNames(const OpcUaLocalizedTextArray::SPtr serverNames);
		OpcUaLocalizedTextArray::SPtr serverNames(void) const;
		void serverType(const ApplicationType serverType);
		ApplicationType serverType(void);
		void gatewayServerUri(const OpcUaString& gatewayServerUri);
		void gatewayServerUri(const std::string& gatewayServerUri);
		OpcUaString& gatewayServerUri(void);
		void discoveryUrls(const OpcUaStringArray::SPtr discoveryUrls);
		OpcUaStringArray::SPtr discoveryUrls(void) const;
		void semaphoreFilePath(const OpcUaString& semaphoreFilePath);
		void semaphoreFilePath(const std::string& semaphoreFilePath);
		OpcUaString& semaphoreFilePath(void);
		void isOnline(const OpcUaBoolean& isOnline);
		OpcUaBoolean isOnline(void);
#endif

		return true;
	}

	bool
	DiscoveryClient::createRegisteredServers(
		const std::string& applicationUri,
		const std::string& productUri,
		const std::string& applicationName,
		const std::string& discoveryUrl,
		const std::string& gatewayServerUri
	)
	{
		// FIXME: todo
		return true;
	}

}
