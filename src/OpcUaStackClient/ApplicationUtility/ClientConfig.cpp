/*
   Copyright 2015-2019 Kai Huebl (kai@huebl-sgh.de)

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
#include "OpcUaStackClient/ApplicationUtility/ClientConfig.h"

using namespace OpcUaStackCore;

namespace OpcUaStackClient
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// class ClientMonitoredItemConfig
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	ClientMonitoredItemConfig::ClientMonitoredItemConfig(void)
	: id_("")
	, samplingInterval_(0)
	, queueSize_(0)
	, dataChangeFilter_(DataChangeTrigger::EnumStatusValue)
	{
	}

	ClientMonitoredItemConfig::~ClientMonitoredItemConfig(void)
	{
	}

	std::string&
	ClientMonitoredItemConfig::id(void)
	{
		return id_;
	}

	void
	ClientMonitoredItemConfig::id(const std::string& id)
	{
		id_ = id;
	}

	uint32_t
	ClientMonitoredItemConfig::samplingInterval(void)
	{
		return samplingInterval_;
	}

	void
	ClientMonitoredItemConfig::samplingInterval(uint32_t samplingInterval)
	{
		samplingInterval_ = samplingInterval;
	}

	uint32_t
	ClientMonitoredItemConfig::queueSize(void)
	{
		return queueSize_;
	}

	void
	ClientMonitoredItemConfig::queueSize(uint32_t queueSize)
	{
		queueSize_ = queueSize;
	}

	DataChangeTrigger
	ClientMonitoredItemConfig::dataChangeFilter(void)
	{
		return dataChangeFilter_;
	}

	void
	ClientMonitoredItemConfig::dataChangeFilter(DataChangeTrigger dataChangeFilter)
	{
		dataChangeFilter_ = dataChangeFilter;
	}

	bool
	ClientMonitoredItemConfig::decode(Config& config, ConfigBase& configBase)
	{
		// monitored item id
		if (!config.getConfigParameter("<xmlattr>.Id", id_)) {
			Log(Error, "attribute missing in config file")
				.parameter("Element", configBase.elementPrefix())
				.parameter("Attribute", "Id")
				.parameter("ConfigFileName", configBase.configFileName());
			return false;
		}

		// sampling interval
		if (!config.getConfigParameter("SamplingInterval", samplingInterval_)) {
			Log(Error, "element missing in config file")
				.parameter("Element", configBase.elementPrefix() + ".SamplingInterval")
				.parameter("MonitoredItemId", id_)
				.parameter("ConfigFileName", configBase.configFileName());
			return false;
		}

		// queue size
		if (!config.getConfigParameter("QueueSize", queueSize_)) {
			Log(Error, "element missing in config file")
				.parameter("Element", configBase.elementPrefix() + ".QueueSize")
				.parameter("MonitoredItemId", id_)
				.parameter("ConfigFileName", configBase.configFileName());
			return false;
		}

		// data change filter
		std::string dataChangeFilter;
		DataChangeTrigger dataChangeFilterType;
		if (!config.getConfigParameter("DataChangeFilter", dataChangeFilter)) {
			Log(Error, "element missing in config file")
				.parameter("Element", configBase.elementPrefix() + ".DataChangeFilter")
				.parameter("MonitoredItemId", id_)
				.parameter("ConfigFileName", configBase.configFileName());
			return false;
		}
		if (dataChangeFilter == "status") {
			dataChangeFilter_.enumeration(DataChangeTrigger::EnumStatus);
		}
		else if (dataChangeFilter == "status-value") {
			dataChangeFilter_.enumeration(DataChangeTrigger::EnumStatusValue);
		}
		else if (dataChangeFilter == "status-value-timestamp") {
			dataChangeFilter_.enumeration(DataChangeTrigger::EnumStatusValueTimestamp);
		}
		else {
			Log(Error, "element invalid in config file")
				.parameter("Element", configBase.elementPrefix() + ".DataChangeTrigger")
				.parameter("MonitoredItemId", id_)
				.parameter("DataChangeTrigger", dataChangeFilter)
				.parameter("ConfigFileName", configBase.configFileName());
			return false;
		}

		return true;
	}

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// class ClientSubscriptionConfig
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	ClientSubscriptionConfig::ClientSubscriptionConfig(void)
	: id_("")
	, publishingInterval_(0)
	, livetimeCount_(0)
	, maxKeepAliveCount_(0)
	, maxNotificationsPerPublish_(0)
	, clientMonitoredItemConfigMap_()
	{
	}

	ClientSubscriptionConfig::~ClientSubscriptionConfig(void)
	{
	}

	std::string
	ClientSubscriptionConfig::id(void)
	{
		return id_;
	}

	void
	ClientSubscriptionConfig::id(const std::string& id)
	{
		id_ = id;
	}

	uint32_t
	ClientSubscriptionConfig::publishingInterval(void)
	{
		return publishingInterval_;
	}

	void
	ClientSubscriptionConfig::publisingInterval(uint32_t publishingInterval)
	{
		publishingInterval_ =publishingInterval;
	}

	uint32_t
	ClientSubscriptionConfig::livetimeCount(void)
	{
		return livetimeCount_;
	}

	void
	ClientSubscriptionConfig::livetimeCount(uint32_t livetimeCount)
	{
		livetimeCount_ = livetimeCount;
	}

	uint32_t
	ClientSubscriptionConfig::maxKeepAliveCount(void)
	{
		return maxKeepAliveCount_;
	}

	void
	ClientSubscriptionConfig::maxKeepAliveCount(uint32_t maxKeepAliveCount)
	{
		maxKeepAliveCount_ = maxKeepAliveCount;
	}

	uint32_t
	ClientSubscriptionConfig::maxNotificationsPerPublish(void)
	{
		return maxNotificationsPerPublish_;
	}

	void
	ClientSubscriptionConfig::maxNotificationsPerPublish(uint32_t maxNotificationsPerPublish)
	{
		maxNotificationsPerPublish_ = maxNotificationsPerPublish;
	}

	ClientMonitoredItemConfig::Map&
	ClientSubscriptionConfig::clientNodeConfigMap(void)
	{
		return clientMonitoredItemConfigMap_;
	}

	bool
	ClientSubscriptionConfig::decode(Config& config, ConfigBase& configBase)
	{
		// subscription id
		if (!config.getConfigParameter("<xmlattr>.Id", id_)) {
			Log(Error, "attribute missing in config file")
				.parameter("Element", configBase.elementPrefix())
				.parameter("Attribute", "Id")
				.parameter("ConfigFileName", configBase.configFileName());
			return false;
		}

		// publishing interval
		if (!config.getConfigParameter("PublishingInterval", publishingInterval_)) {
			Log(Error, "element missing in config file")
				.parameter("Element", configBase.elementPrefix() + ".PublishingInterval")
				.parameter("SubscriptionItemId", id_)
				.parameter("ConfigFileName", configBase.configFileName());
			return false;
		}

		// max keepalive count
		if (!config.getConfigParameter("MaxKeepAliveCount", maxKeepAliveCount_)) {
			Log(Error, "element missing in config file")
				.parameter("Element", configBase.elementPrefix() + ".MaxKeepAliveCount")
				.parameter("SubscriptionItemId", id_)
				.parameter("ConfigFileName", configBase.configFileName());
			return false;
		}

		// max notification per publish
		if (!config.getConfigParameter("MaxNotificationsPerPublish", maxNotificationsPerPublish_)) {
			Log(Error, "element missing in config file")
				.parameter("Element", configBase.elementPrefix() + ".MaxNotificationsPerPublish")
				.parameter("SubscriptionItemId", id_)
				.parameter("ConfigFileName", configBase.configFileName());
			return false;
		}

		// monitored items
		std::vector<Config> childs;
		config.getChilds("MonitoredItem", childs);
		if (childs.size() == 0) {
			Log(Error, "element missing in config file")
				.parameter("Element", configBase.elementPrefix() + ".MonitoredItem")
				.parameter("SubscriptionItemId", id_)
				.parameter("ConfigFileName", configBase.configFileName());
			return false;
		}

		std::vector<Config>::iterator it;
		for (it = childs.begin(); it != childs.end(); it++) {
			ClientMonitoredItemConfig::SPtr monitoredItem  = boost::make_shared<ClientMonitoredItemConfig>();

			ConfigBase cb(configBase, ".MonitoredItem");
			if (!monitoredItem->decode(*it, cb)) {
				return false;
			}

			ClientMonitoredItemConfig::Map::iterator it;
			it = clientMonitoredItemConfigMap_.find(monitoredItem->id());
			if (it != clientMonitoredItemConfigMap_.end()) {
				Log(Error, "dublicate monitored item id in config file")
					.parameter("Element", configBase.elementPrefix() + ".MonitoredItem")
					.parameter("MonitoredItemId", monitoredItem->id())
					.parameter("SubscriptionItemId", id_)
					.parameter("ConfigFileName", configBase.configFileName());
				return false;
			}
			clientMonitoredItemConfigMap_.insert(std::make_pair(monitoredItem->id(), monitoredItem));
		}

		return true;
	}


	// -----------------------------------------------------------------------
	// -----------------------------------------------------------------------
	//
	// class ClientEndpointConfig
	//
	// -----------------------------------------------------------------------
	// -----------------------------------------------------------------------
	ClientEndpointConfig::ClientEndpointConfig(void)
	: serverUrn_("")
	, serverUri_("")
	, reconnectTimeout_(5000)
	{
	}

	ClientEndpointConfig::~ClientEndpointConfig(void)
	{
	}

	void
	ClientEndpointConfig::serverUrn(const std::string& serverUrn)
	{
		serverUrn_ = serverUrn;
	}

	std::string&
	ClientEndpointConfig::serverUrn(void)
	{
		return serverUrn_;
	}

	void
	ClientEndpointConfig::serverUri(const std::string& serverUri)
	{
		serverUri_ = serverUri;
	}

	std::string&
	ClientEndpointConfig::serverUri(void)
	{
		return serverUri_;
	}

	void
	ClientEndpointConfig::reconnectTimeout(uint32_t reconnectTimeout)
	{
		reconnectTimeout_ = reconnectTimeout;
	}

	uint32_t
	ClientEndpointConfig::reconnectTimeout(void)
	{
		return reconnectTimeout_;
	}

	bool
	ClientEndpointConfig::decode(Config& config, ConfigBase& configBase)
	{

		// ServerUrn
		config.getConfigParameter("ServerUrn", serverUrn_, "");

		// ServerUri
		config.getConfigParameter("ServerUri", serverUri_, "");

		// ReconnectTimeout
		if (!config.getConfigParameter("ReconnectTimeout", reconnectTimeout_)) {
			Log(Error, "element missing in config file")
				.parameter("Element", configBase.elementPrefix() + ".ReconnectTimeout")
				.parameter("ConfigFileName", configBase.configFileName());
			return false;
		}

		return true;
	}


	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// class HistoryClientConfig
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	ClientConfig::ClientConfig(void)
	: id_("")
	, clientEndpointConfig_()
	, clientSubscriptionConfigMap_()
	{
	}

	ClientConfig::~ClientConfig(void)
	{
	}

	std::string
	ClientConfig::id(void)
	{
		return id_;
	}

	void
	ClientConfig::id(const std::string& id)
	{
		id_ = id;
	}

	ClientEndpointConfig&
	ClientConfig::clientEndpointConfig(void)
	{
		return clientEndpointConfig_;
	}

	ClientSubscriptionConfig::Map&
	ClientConfig::clientSubscriptionMap(void)
	{
		return clientSubscriptionConfigMap_;
	}

	bool
	ClientConfig::decode(const std::string& configFileName, ConfigXmlManager& configXmlManager)
	{
		bool success;
		ConfigBase configBase;

		//
		// read configuration file
		//
        Log(Info, "read configuration file")
            .parameter("ConfigFileName", configFileName);
		Config::SPtr config;
		success = configXmlManager.registerConfiguration(configFileName, config);
		if (!success) {
			Log(Error, "read configuration file error")
			   .parameter("ConfigFile", configFileName);
			   return false;
		}
		configBase.configFileName(configFileName);

		// client id
		if (!config->getConfigParameter("OpcUaClientModel.<xmlattr>.Id", id_)) {
			Log(Error, "attribute missing in config file")
				.parameter("Element", "OpcUaClientModel")
				.parameter("Attribute", "Id")
				.parameter("ConfigFile", configFileName);
			return false;
		}

		// client endpoint
		boost::optional<Config> child = config->getChild("OpcUaClientModel.Endpoint");
		if (!child) {
			Log(Error, "element missing in config file")
				.parameter("Element", "OpcUaClientMode.Endpoint")
				.parameter("ConfigFile", configFileName);
			return false;
		}
		configBase.elementPrefix("OpcUaClientModel.Endpoint");
		if (!clientEndpointConfig_.decode(*child, configBase)) {
			return false;
		}

		// client subscription
		configBase.elementPrefix("OpcUaClientModel.Subscription");
		std::vector<Config> childs;
		config->getChilds("OpcUaClientModel.Subscription", childs);
		if (childs.size() == 0) {
			Log(Error, "element missing in config file")
						.parameter("Element", "OpcUaClientMode.Subscription")
						.parameter("ConfigFile", configFileName);
			return false;
		}

		std::vector<Config>::iterator it;
		for (it = childs.begin(); it != childs.end(); it++) {
			ClientSubscriptionConfig::SPtr subscription = boost::make_shared<ClientSubscriptionConfig>();

			if (!subscription->decode(*it, configBase)) {
				return false;
			}

			ClientSubscriptionConfig::Map::iterator it;
			it = clientSubscriptionConfigMap_.find(subscription->id());
			if (it != clientSubscriptionConfigMap_.end()) {
				Log(Error, "dublicate subscription id in config file")
					.parameter("Element", configBase.elementPrefix())
					.parameter("SubscriptionId", subscription->id())
					.parameter("ConfigFileName", configBase.configFileName());
				return false;
			}
			clientSubscriptionConfigMap_.insert(std::make_pair(subscription->id(), subscription));
		}

		return true;
	}

}
