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
#include "OpcUaStackCore/Core/Core.h"
#include "OpcUaStackClient/ServiceSet/ServiceSetManager.h"

using namespace OpcUaStackCore;

namespace OpcUaStackClient
{

	ServiceSetManager::ServiceSetManager(void)
	: ioThreadMap_()
	{
		Core core;
		core.init();
	}

	ServiceSetManager::~ServiceSetManager(void)
	{
		while (ioThreadMap_.size() != 0) {
			destroyIOThread(ioThreadMap_.begin()->first);
		}
	}

	void
	ServiceSetManager::registerIOThread(const std::string ioThreadName, IOThread::SPtr ioThread)
	{
		Log(Debug, "service set manager register io thread")
		    .parameter("IOThreadName", ioThreadName);
		ioThreadMap_.insert(std::make_pair(ioThreadName, ioThread));
	}

	void
	ServiceSetManager::deregisterIOThread(const std::string ioThreadName)
	{
		Log(Debug, "service set manager deregister io thread")
		    .parameter("IOThreadName", ioThreadName);
		ioThreadMap_.erase(ioThreadName);
	}

	void
	ServiceSetManager::createIOThread(const std::string ioThreadName)
	{
		IOThread::SPtr ioThread = getIOThread(ioThreadName);
		if (ioThread.get() != nullptr) return;

		Log(Debug, "service set manager starts io thread")
		    .parameter("IOThreadName", ioThreadName);
		ioThread = constructSPtr<IOThread>();
		ioThreadMap_.insert(std::make_pair(ioThreadName, ioThread));
		ioThread->startup();
	}

	void
	ServiceSetManager::destroyIOThread(const std::string ioThreadName)
	{
		IOThread::Map::iterator it;
		it = ioThreadMap_.find(ioThreadName);
		if (it == ioThreadMap_.end()) return;

		Log(Debug, "service set manager stops io thread")
		    .parameter("IOThreadName", ioThreadName);
		IOThread::SPtr ioThread = it->second;
		ioThread->shutdown();
		ioThreadMap_.erase(it);
	}

	IOThread::SPtr
	ServiceSetManager::getIOThread(const std::string ioThreadName)
	{
		IOThread::SPtr ioThread;
		IOThread::Map::iterator it;
		it = ioThreadMap_.find(ioThreadName);
		if (it != ioThreadMap_.end()) ioThread = it->second;
		return ioThread;
	}

	SessionService::SPtr
	ServiceSetManager::sessionService(
		SessionServiceConfig& sessionServiceConfig
	)
	{
		// create new session
		createIOThread(sessionServiceConfig.ioThreadName());
		IOThread::SPtr ioThread = getIOThread(sessionServiceConfig.ioThreadName());
		SessionService::SPtr sessionService = constructSPtr<SessionService>(ioThread.get());

		// set session configuration
		sessionService->setConfiguration(
			sessionServiceConfig.sessionMode_,
			sessionServiceConfig.sessionServiceChangeHandler_,
			sessionServiceConfig.secureChannelClient_,
			sessionServiceConfig.session_
		);

		return sessionService;
	}

	void
	ServiceSetManager::updateEndpointUrl(
		SessionService::SPtr& sessionService,
		const std::string& endpointUrl
	)
	{
		sessionService->updateEndpointUrl(endpointUrl);
	}

	DiscoveryService::SPtr
	ServiceSetManager::discoveryService(SessionService::SPtr& sessionService)
	{
		DiscoveryServiceConfig discoveryServiceConfig;
		return discoveryService(sessionService, discoveryServiceConfig);
	}

	DiscoveryService::SPtr
	ServiceSetManager::discoveryService(
		SessionService::SPtr& sessionService,
		DiscoveryServiceConfig& discoveryServiceConfig)
	{
		// create discovery service
		createIOThread(discoveryServiceConfig.ioThreadName());
		IOThread::SPtr ioThread = getIOThread(discoveryServiceConfig.ioThreadName());
		DiscoveryService::SPtr discoveryService = constructSPtr<DiscoveryService>(ioThread.get());

		// set discovery configuration
		discoveryService->setConfiguration(
			sessionService->component()
		);

		return discoveryService;
	}

	AttributeService::SPtr
	ServiceSetManager::attributeService(SessionService::SPtr& sessionService)
	{
		AttributeServiceConfig attributeServiceConfig;
		return attributeService(sessionService, attributeServiceConfig);
	}

	AttributeService::SPtr
	ServiceSetManager::attributeService(
		SessionService::SPtr& sessionService,
		AttributeServiceConfig& attributeServiceConfig)
	{
		// create attribute service
		createIOThread(attributeServiceConfig.ioThreadName());
		auto ioThread = getIOThread(attributeServiceConfig.ioThreadName());
		auto attributeService = constructSPtr<AttributeService>(ioThread.get());

		// set attribute configuration
		attributeService->setConfiguration(
			sessionService->component()
		);

		return attributeService;
	}

	SubscriptionService::SPtr
	ServiceSetManager::subscriptionService(SessionService::SPtr& sessionService)
	{
		SubscriptionServiceConfig subscriptionServiceConfig;
		return subscriptionService(sessionService, subscriptionServiceConfig);
	}

	SubscriptionService::SPtr
	ServiceSetManager::subscriptionService(
		SessionService::SPtr& sessionService,
		SubscriptionServiceConfig& subscriptionServiceConfig)
	{
		// create subscription service
		createIOThread(subscriptionServiceConfig.ioThreadName());
		IOThread::SPtr ioThread = getIOThread(subscriptionServiceConfig.ioThreadName());
		SubscriptionService::SPtr subscriptionService = constructSPtr<SubscriptionService>(ioThread.get());

		// set subscription configuration
		subscriptionService->setConfiguration(
			sessionService->component(),
			subscriptionServiceConfig.dataChangeNotificationHandler_,
			subscriptionServiceConfig.subscriptionStateUpdateHandler_,
			subscriptionServiceConfig.publishCount_,
			subscriptionServiceConfig.requestTimeout_
		);

		return subscriptionService;
	}

	MonitoredItemService::SPtr
	ServiceSetManager::monitoredItemService(SessionService::SPtr& sessionService)
	{
		MonitoredItemServiceConfig monitoredItemServiceConfig;
		return monitoredItemService(sessionService, monitoredItemServiceConfig);
	}

	MonitoredItemService::SPtr
	ServiceSetManager::monitoredItemService(
		SessionService::SPtr& sessionService,
		MonitoredItemServiceConfig& monitoredItemServiceConfig)
	{
		// create monitored item service
		createIOThread(monitoredItemServiceConfig.ioThreadName());
		IOThread::SPtr ioThread = getIOThread(monitoredItemServiceConfig.ioThreadName());
		MonitoredItemService::SPtr monitoredItemService = constructSPtr<MonitoredItemService>(ioThread.get());

		// set monitored item configuration
		monitoredItemService->setConfiguration(
			sessionService->component()
		);

		return monitoredItemService;
	}

	MethodService::SPtr
	ServiceSetManager::methodService(SessionService::SPtr& sessionService)
	{
		MethodServiceConfig methodServiceConfig;
		return methodService(sessionService, methodServiceConfig);
	}

	MethodService::SPtr
	ServiceSetManager::methodService(
		SessionService::SPtr& sessionService,
		MethodServiceConfig& methodServiceConfig)
	{
		// create monitored item service
		createIOThread(methodServiceConfig.ioThreadName());
		auto ioThread = getIOThread(methodServiceConfig.ioThreadName());
		auto methodService = constructSPtr<MethodService>(ioThread.get());

		// set method configuration
		methodService->setConfiguration(
			sessionService->component()
		);

		return methodService;
	}

	ViewService::SPtr
	ServiceSetManager::viewService(SessionService::SPtr& sessionService)
	{
		ViewServiceConfig viewServiceConfig;
		return viewService(sessionService, viewServiceConfig);
	}

	ViewService::SPtr
	ServiceSetManager::viewService(
		SessionService::SPtr& sessionService,
		ViewServiceConfig& viewServiceConfig)
	{
		// create view service
		createIOThread(viewServiceConfig.ioThreadName());
		IOThread::SPtr ioThread = getIOThread(viewServiceConfig.ioThreadName());
		ViewService::SPtr viewService = constructSPtr<ViewService>(ioThread.get());

		// set view configuration
		viewService->setConfiguration(
			sessionService->component(),
			viewServiceConfig.viewServiceIf_
		);

		return viewService;
	}

	QueryService::SPtr
	ServiceSetManager::queryService(SessionService::SPtr& sessionService)
	{
		QueryServiceConfig queryServiceConfig;
		return queryService(sessionService, queryServiceConfig);
	}

	QueryService::SPtr
	ServiceSetManager::queryService(
		SessionService::SPtr& sessionService,
		QueryServiceConfig& queryServiceConfig)
	{
		// create query service
		createIOThread(queryServiceConfig.ioThreadName());
		IOThread::SPtr ioThread = getIOThread(queryServiceConfig.ioThreadName());
		QueryService::SPtr queryService = constructSPtr<QueryService>(ioThread.get());

		// set query configuration
		queryService->setConfiguration(
			sessionService->component(),
			queryServiceConfig.queryServiceIf_
		);

		return queryService;
	}

	NodeManagementService::SPtr
	ServiceSetManager::nodeManagementService(SessionService::SPtr& sessionService)
	{
		NodeManagementServiceConfig nodeManagementServiceConfig;
		return nodeManagementService(sessionService, nodeManagementServiceConfig);
	}

	NodeManagementService::SPtr
	ServiceSetManager::nodeManagementService(
		SessionService::SPtr& sessionService,
		NodeManagementServiceConfig& nodeManagementServiceConfig)
	{
		// create node mangement service
		createIOThread(nodeManagementServiceConfig.ioThreadName());
		IOThread::SPtr ioThread = getIOThread(nodeManagementServiceConfig.ioThreadName());
		NodeManagementService::SPtr nodeManagementService = constructSPtr<NodeManagementService>(ioThread.get());

		// set node management configuration
		nodeManagementService->setConfiguration(
			sessionService->component(),
			nodeManagementServiceConfig.nodeManagementServiceIf_
		);

		return nodeManagementService;
	}

}
