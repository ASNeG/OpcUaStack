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

#include <boost/make_shared.hpp>
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
		// destroy all io threads
		while (ioThreadMap_.size() != 0) {
			destroyIOThread(ioThreadMap_.begin()->first);
		}

		// remove message bus if exist
		if (messageBus_) {
			messageBus_.reset();
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
		auto ioThread = getIOThread(ioThreadName);
		if (ioThread.get() != nullptr) return;

		Log(Debug, "service set manager starts io thread")
		    .parameter("IOThreadName", ioThreadName);
		ioThread = boost::make_shared<IOThread>();
		ioThreadMap_.insert(std::make_pair(ioThreadName, ioThread));
		ioThread->startup();
	}

	void
	ServiceSetManager::destroyIOThread(const std::string ioThreadName)
	{
		auto it = ioThreadMap_.find(ioThreadName);
		if (it == ioThreadMap_.end()) return;

		Log(Debug, "service set manager stops io thread")
		    .parameter("IOThreadName", ioThreadName);
		auto ioThread = it->second;
		ioThread->shutdown();
		ioThreadMap_.erase(it);
	}

	IOThread::SPtr
	ServiceSetManager::getIOThread(const std::string ioThreadName)
	{
		IOThread::SPtr ioThread;
		auto it = ioThreadMap_.find(ioThreadName);
		if (it != ioThreadMap_.end()) {
			ioThread = it->second;
		}
		return ioThread;
	}

	SessionService::SPtr
	ServiceSetManager::sessionService(
		SessionServiceConfig& sessionServiceConfig
	)
	{
		// create new message bus if a message bus not exist in session the
		// session service configuration.
		messageBus_ = sessionServiceConfig.messageBus_;
		if (!messageBus_) {
			messageBus_ = boost::make_shared<MessageBus>();
			sessionServiceConfig.messageBus_ = messageBus_;
		}

		// create new session
		createIOThread(sessionServiceConfig.ioThreadName());
		auto ioThread = getIOThread(sessionServiceConfig.ioThreadName());
		auto sessionService = boost::make_shared<SessionService>(ioThread.get());

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
		DiscoveryService::SPtr discoveryService = boost::make_shared<DiscoveryService>(ioThread.get());

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
		auto attributeService = boost::make_shared<AttributeService>(ioThread.get());

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
		auto ioThread = getIOThread(subscriptionServiceConfig.ioThreadName());
		auto subscriptionService = boost::make_shared<SubscriptionService>(ioThread.get());

		// set subscription configuration
		subscriptionService->setConfiguration(
			sessionService->component(),
			subscriptionServiceConfig.dataChangeNotificationHandler_,
			subscriptionServiceConfig.eventNotificationHandler_,
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
		MonitoredItemService::SPtr monitoredItemService = boost::make_shared<MonitoredItemService>(ioThread.get());

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
		auto methodService = boost::make_shared<MethodService>(ioThread.get());

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
		ViewService::SPtr viewService = boost::make_shared<ViewService>(ioThread.get());

		// set view configuration
		viewService->setConfiguration(
			sessionService->component()
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
		QueryService::SPtr queryService = boost::make_shared<QueryService>(ioThread.get());

		// set query configuration
		queryService->setConfiguration(
			sessionService->component()
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
		auto ioThread = getIOThread(nodeManagementServiceConfig.ioThreadName());
		auto nodeManagementService = boost::make_shared<NodeManagementService>(ioThread.get());

		// set node management configuration
		nodeManagementService->setConfiguration(
			sessionService->component()
		);

		return nodeManagementService;
	}

}
