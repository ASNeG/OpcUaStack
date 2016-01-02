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
#ifndef __OpcUaStackClient_ServiceSetManager_h__
#define __OpcUaStackClient_ServiceSetManager_h__

#include "OpcUaStackCore/Base/os.h"
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

using namespace OpcUaStackCore;

namespace OpcUaStackClient
{

	class DLLEXPORT ServiceSetManager
	{
	  public:
		ServiceSetManager(void);
		~ServiceSetManager(void);

		// session
		SessionService::SPtr sessionService(
			SessionServiceConfig& sessionServiceConfig
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


	  private:
		IOThread::SPtr getIOThread(const std::string ioThreadName);
		void createIOThread(const std::string ioThreadName);
		void destroyIOThread(const std::string ioThreadName);

		IOThread::Map ioThreadMap_;
	};

}

#endif
