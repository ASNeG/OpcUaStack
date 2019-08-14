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

#ifndef __OpcUaStackClient_ClientConfig_h__
#define __OpcUaStackClient_ClientConfig_h__

#include "OpcUaStackCore/Base/ConfigXmlManager.h"
#include "OpcUaStackCore/StandardDataTypes/DataChangeTrigger.h"
#include "OpcUaStackClient/ApplicationUtility/ConfigBase.h"

namespace OpcUaStackClient
{

	class DLLEXPORT ClientMonitoredItemConfig
	{
	  public:
		typedef boost::shared_ptr<ClientMonitoredItemConfig> SPtr;
		typedef std::map<std::string, ClientMonitoredItemConfig::SPtr> Map;

		ClientMonitoredItemConfig(void);
		~ClientMonitoredItemConfig(void);

		std::string& id(void);
		void id(const std::string& id);
		uint32_t samplingInterval(void);
		void samplingInterval(uint32_t samplingInterval);
		uint32_t queueSize(void);
		void queueSize(uint32_t queueSize);
		OpcUaStackCore::DataChangeTrigger dataChangeFilter(void);
		void dataChangeFilter(OpcUaStackCore::DataChangeTrigger dataChangeFilter);

		bool decode(OpcUaStackCore::Config& config, ConfigBase& configBase);

	  private:
		std::string id_;
		uint32_t samplingInterval_;
		uint32_t queueSize_;
		OpcUaStackCore::DataChangeTrigger dataChangeFilter_;
	};


	class DLLEXPORT ClientSubscriptionConfig
	{
	  public:
		typedef boost::shared_ptr<ClientSubscriptionConfig> SPtr;
		typedef std::map<std::string, ClientSubscriptionConfig::SPtr> Map;

		ClientSubscriptionConfig(void);
		~ClientSubscriptionConfig(void);

		std::string id(void);
		void id(const std::string& id);
		uint32_t publishingInterval(void);
		void publisingInterval(uint32_t publishingInterval);
		uint32_t livetimeCount(void);
		void livetimeCount(uint32_t livetimeCount);
		uint32_t maxKeepAliveCount(void);
		void maxKeepAliveCount(uint32_t maxKeepAliveCount);
		uint32_t maxNotificationsPerPublish(void);
		void maxNotificationsPerPublish(uint32_t maxNotificationsPerPublish);
		ClientMonitoredItemConfig::Map& clientNodeConfigMap(void);

		bool decode(OpcUaStackCore::Config& config, ConfigBase& configBase);

	  private:
		std::string id_;
		uint32_t publishingInterval_;
		uint32_t livetimeCount_;
		uint32_t maxKeepAliveCount_;
		uint32_t maxNotificationsPerPublish_;
		ClientMonitoredItemConfig::Map clientMonitoredItemConfigMap_;
	};


	class DLLEXPORT ClientEndpointConfig
	{
	  public:
		ClientEndpointConfig(void);
		~ClientEndpointConfig(void);

		void serverUrn(const std::string& serverUrn);
		std::string& serverUrn(void);
		void serverUri(const std::string& serverUri);
		std::string& serverUri(void);
		void reconnectTimeout(uint32_t reconnectTimeout);
		uint32_t reconnectTimeout(void);

		bool decode(OpcUaStackCore::Config& config, ConfigBase& configBase);

	  private:
		std::string serverUrn_;
		std::string serverUri_;
		uint32_t reconnectTimeout_;
	};


	class DLLEXPORT ClientConfig
	{
	  public:
		ClientConfig(void);
		~ClientConfig(void);

		std::string id(void);
		void id(const std::string& id);
		ClientEndpointConfig& clientEndpointConfig(void);
		ClientSubscriptionConfig::Map& clientSubscriptionMap(void);

		bool decode(const std::string& configFileName, OpcUaStackCore::ConfigXmlManager& configXmlManager);

	  private:
		bool decodeEndpoint(OpcUaStackCore::Config::SPtr& config);
		bool decodeSubscriptions(OpcUaStackCore::Config::SPtr& config);
		bool decodeSubscription(OpcUaStackCore::Config& config);
		bool decodeMonitoredItems(OpcUaStackCore::Config& config, ClientMonitoredItemConfig::Map& clientMonitoredItemConfigMap);

		std::string id_;
		ClientEndpointConfig clientEndpointConfig_;
		ClientSubscriptionConfig::Map clientSubscriptionConfigMap_;
	};

}

#endif
