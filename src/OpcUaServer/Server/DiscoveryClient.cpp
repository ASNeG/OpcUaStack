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
#include "OpcUaStackCore/Base/Address.h"
#include "OpcUaStackCore/Base/Url.h"
#include "OpcUaServer/Server/DiscoveryClient.h"

using namespace OpcUaStackCore;

namespace OpcUaServer
{

	DiscoveryClient::DiscoveryClient(void)
	: config_(nullptr)
	, ioThread_()
	, discoveryClient_()
	, discoveryServerUrl_("")
	, enable_(false)
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

		Log(Info, "startup discovery client");

		//
		// read discovery server configuration
		//

		// check if the discovery registered service is enabled
		boost::optional<Config> dicoveryServerConfig = config.getChild("OpcUaServer.DiscoveryServer");
		if (!dicoveryServerConfig) {
			Log(Info, "discovery registered service is disabled");
			return true;
		}
		enable_ = true;
		Log(Info, "discovery registered service is enabled");

		// get element discovery url
		success = dicoveryServerConfig->getConfigParameter("DiscoveryUrl", discoveryServerUrl_);
		if (!success) {
			Log(Error, "element missing in config file")
				.parameter("Element", "OpcUaServer.DiscoveryServer.DiscoveryUrl")
				.parameter("ConfigFileName", config.configFileName());
			return false;
		}

		// get element register interval url
		dicoveryServerConfig->getConfigParameter("RegisterInterval", registerInterval_, "40000");

		//
		// read endpoint configuration
		//
		if (!parseEndpointConfiguration(config)) {
			return false;
		}

		//
		// startup discovery client service process
		//
		ioThread_ = constructSPtr<IOThread>();
		ioThread_->startup();

		discoveryClient_.ioThread(ioThread_);
		discoveryClient_.discoveryUri(discoveryServerUrl_);
		discoveryClient_.registerInterval(registerInterval_);
		discoveryClient_.startup();

		return true;
	}

	void 
	DiscoveryClient::shutdown(void)
	{
		Log(Info, "shutdown discovery client");

		if (!enable_) return;

		discoveryClient_.shutdown();
		ioThread_->shutdown();
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

			// create registered server structure
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
		// create discovery url and discovery server url
		Url url_discoveryUrl(discoveryUrl);

		// create discovery url address list
		std::vector<std::string> addressList;
		if (url_discoveryUrl.isAnyAddress()) {
			Address::getAllIPv4sFromHost(addressList);
		}
		else {
			addressList.push_back(url_discoveryUrl.host());
		}

		// create register Server entrie
		RegisteredServer::SPtr registeredServer = constructSPtr<RegisteredServer>();
		registeredServer->serverUri(applicationUri);
		registeredServer->productUri(productUri);
		OpcUaLocalizedText::SPtr serverName = constructSPtr<OpcUaLocalizedText>();
		serverName->set("en", applicationName);
		OpcUaLocalizedTextArray::SPtr serverNames = constructSPtr<OpcUaLocalizedTextArray>();
		serverNames->resize(1);
		serverNames->push_back(serverName);
		registeredServer->serverNames(serverNames);
		registeredServer->serverType(AT_Server);
		registeredServer->gatewayServerUri(gatewayServerUri);
		registeredServer->isOnline(true);

		OpcUaStringArray::SPtr discoveryUrls = constructSPtr<OpcUaStringArray>();
		discoveryUrls->resize(addressList.size());
		registeredServer->discoveryUrls(discoveryUrls);

		std::vector<std::string>::iterator it;
		for (it=addressList.begin(); it!=addressList.end(); it++) {

			url_discoveryUrl.host(*it);
			OpcUaString::SPtr url = constructSPtr<OpcUaString>();
			url->value(url_discoveryUrl.url());

			discoveryUrls->push_back(url);
		}

		registeredServerVec_.push_back(registeredServer);

		//
		// register server entry
		//
		discoveryClient_.addRegisteredServer(applicationName, registeredServer);

		return true;
	}

}
