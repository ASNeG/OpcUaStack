/*
   Copyright 2015-2020 Kai Huebl (kai@huebl-sgh.de)

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
#ifndef __OpcUaStackClient_ServiceSetManager_h__
#define __OpcUaStackClient_ServiceSetManager_h__

#include "OpcUaStackCore/Utility/IOThread.h"
#include "OpcUaStackClient/ServiceSet/SessionService.h"
#include "OpcUaStackClient/ServiceSet/SessionServiceConfig.h"
#include "OpcUaStackClient/ServiceSet/DiscoveryService.h"
#include "OpcUaStackClient/ServiceSet/DiscoveryServiceConfig.h"
#include "OpcUaStackClient/ServiceSet/AttributeService.h"
#include "OpcUaStackClient/ServiceSet/AttributeServiceConfig.h"
#include "OpcUaStackClient/ServiceSet/SubscriptionService.h"
#include "OpcUaStackClient/ServiceSet/SubscriptionServiceConfig.h"
#include "OpcUaStackClient/ServiceSet/MonitoredItemService.h"
#include "OpcUaStackClient/ServiceSet/MonitoredItemServiceConfig.h"
#include "OpcUaStackClient/ServiceSet/MethodService.h"
#include "OpcUaStackClient/ServiceSet/MethodServiceConfig.h"
#include "OpcUaStackClient/ServiceSet/ViewService.h"
#include "OpcUaStackClient/ServiceSet/ViewServiceConfig.h"
#include "OpcUaStackClient/ServiceSet/QueryService.h"
#include "OpcUaStackClient/ServiceSet/QueryServiceConfig.h"
#include "OpcUaStackClient/ServiceSet/NodeManagementService.h"
#include "OpcUaStackClient/ServiceSet/NodeManagementServiceConfig.h"

namespace OpcUaStackClient
{

	class DLLEXPORT ServiceSetManager
	{
	  public:
		ServiceSetManager(void);
		~ServiceSetManager(void);

		void start(void) {}
		void stop(void) {}

		void registerIOThread(const std::string ioThreadName, OpcUaStackCore::IOThread::SPtr ioThread);
		void deregisterIOThread(const std::string ioThreadName);
		void messageBus(OpcUaStackCore::MessageBus::SPtr& messageBus);

		// session
		SessionService::SPtr sessionService(
			SessionServiceConfig& sessionServiceConfig
		);
		void updateEndpointUrl(
			SessionService::SPtr& sessionService,
			const std::string& endpointUrl
		);

		// discovery
		DiscoveryService::SPtr discoveryService(
			SessionService::SPtr& sessionService
		);
		DiscoveryService::SPtr discoveryService(
			SessionService::SPtr& sessionService,
			DiscoveryServiceConfig& discoveryServiceConfig
		);

		// attribute
		AttributeService::SPtr attributeService(
			SessionService::SPtr& sessionService
		);
		AttributeService::SPtr attributeService(
			SessionService::SPtr& sessionService,
			AttributeServiceConfig& attributeServiceConfig
		);

		// subscription
		SubscriptionService::SPtr subscriptionService(
			SessionService::SPtr& sessionService
		);
		SubscriptionService::SPtr subscriptionService(
			SessionService::SPtr& sessionService,
			SubscriptionServiceConfig& subscriptionServiceConfig
		);

		// monitored item
		MonitoredItemService::SPtr monitoredItemService(
			SessionService::SPtr& sessionService
		);
		MonitoredItemService::SPtr monitoredItemService(
			SessionService::SPtr& sessionService,
			MonitoredItemServiceConfig& monitoredItemServiceConfig
		);

		// method
		MethodService::SPtr methodService(
			SessionService::SPtr& sessionService
		);
		MethodService::SPtr methodService(
			SessionService::SPtr& sessionService,
			MethodServiceConfig& methodServiceConfig
		);

		// view
		ViewService::SPtr viewService(
			SessionService::SPtr& sessionService
		);
		ViewService::SPtr viewService(
			SessionService::SPtr& sessionService,
			ViewServiceConfig& viewServiceConfig
		);

		// query
		QueryService::SPtr queryService(
			SessionService::SPtr& sessionService
		);
		QueryService::SPtr queryService(
			SessionService::SPtr& sessionService,
			QueryServiceConfig& queryServiceConfig
		);

		// node management
		NodeManagementService::SPtr nodeManagementService(
			SessionService::SPtr& sessionService
		);
		NodeManagementService::SPtr nodeManagementService(
			SessionService::SPtr& sessionService,
			NodeManagementServiceConfig& nodeManagementServiceConfig
		);

	  private:
		OpcUaStackCore::IOThread::SPtr getIOThread(const std::string ioThreadName);
		void createIOThread(const std::string ioThreadName);
		void destroyIOThread(const std::string ioThreadName);

		OpcUaStackCore::MessageBus::SPtr messageBus_ = nullptr;
		OpcUaStackCore::IOThread::Map ioThreadMap_;
	};

}

#endif
