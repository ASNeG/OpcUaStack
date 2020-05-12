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
	ServiceSetManager::messageBus(MessageBus::SPtr& messageBus)
	{
		messageBus_ = messageBus;
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
		// check parameter
		if (!sessionServiceConfig.session_) {
			Log(Error, "session create error, because session configuration empty");
			return nullptr;
		}

		// create new message bus if a message bus not exist in the
		// session service configuration.
		if (!messageBus_) {
			messageBus_ = boost::make_shared<MessageBus>();
		}
		messageBus_->debugLogging(true);  // FIXME: mus be moved into a configuration file or interface funtion

		// check if session service name already exist. Each session service must have
		// a unique name.
		if (messageBus_->existMember(sessionServiceConfig.sessionServiceName_)) {
			Log(Debug, "session create error, because session service name already exist")
			    .parameter("SessionServiceName", sessionServiceConfig.sessionServiceName_);
			return nullptr;
		}

		// create new session
		createIOThread(sessionServiceConfig.ioThreadName());
		auto ioThread = getIOThread(sessionServiceConfig.ioThreadName());
		auto sessionService = boost::make_shared<SessionService>(
			sessionServiceConfig.sessionServiceName_,
			ioThread.get(),
			messageBus_
		);

		// set session configuration
		sessionService->setConfiguration(
			sessionServiceConfig.sessionMode_,
			sessionServiceConfig.sessionServiceChangeHandler_,
			sessionServiceConfig.sessionServiceChangeHandlerStrand_,
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
		// check if discovery service name already exist. Each discovery service must have
		// a unique name.
		if (messageBus_->existMember(discoveryServiceConfig.discoveryServiceName_)) {
			Log(Debug, "discovery service create error, because discovery service name already exist")
			    .parameter("DiscoveryServiceName", discoveryServiceConfig.discoveryServiceName_);
			return nullptr;
		}

		// create discovery service
		createIOThread(discoveryServiceConfig.ioThreadName());
		auto ioThread = getIOThread(discoveryServiceConfig.ioThreadName());
		auto discoveryService = boost::make_shared<DiscoveryService>(
			discoveryServiceConfig.discoveryServiceName_,
			ioThread.get(),
			messageBus_
		);

		// set discovery configuration
		discoveryService->setConfiguration(
			sessionService->messageBusMember()
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
		// check if attribute service name already exist. Each attribute service must have
		// a unique name.
		if (messageBus_->existMember(attributeServiceConfig.attributeServiceName_)) {
			Log(Debug, "attribute service create error, because attribute service name already exist")
			    .parameter("AttributeServiceName", attributeServiceConfig.attributeServiceName_);
			return nullptr;
		}

		// create attribute service
		createIOThread(attributeServiceConfig.ioThreadName());
		auto ioThread = getIOThread(attributeServiceConfig.ioThreadName());
		auto attributeService = boost::make_shared<AttributeService>(
			attributeServiceConfig.attributeServiceName_,
			ioThread.get(),
			messageBus_
		);

		// set attribute configuration
		attributeService->setConfiguration(
			sessionService->messageBusMember()
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
		// check if subscription service name already exist. Each subscription service must have
		// a unique name.
		if (messageBus_->existMember(subscriptionServiceConfig.subscriptionServiceName_)) {
			Log(Debug, "subscription service create error, because subscription service name already exist")
			    .parameter("SubscriptionServiceName", subscriptionServiceConfig.subscriptionServiceName_);
			return nullptr;
		}

		// create subscription service
		createIOThread(subscriptionServiceConfig.ioThreadName());
		auto ioThread = getIOThread(subscriptionServiceConfig.ioThreadName());
		auto subscriptionService = boost::make_shared<SubscriptionService>(
			subscriptionServiceConfig.subscriptionServiceName_,
			ioThread.get(),
			messageBus_
		);

		// set subscription configuration
		subscriptionService->setConfiguration(
			sessionService->messageBusMember(),
			subscriptionServiceConfig.dataChangeNotificationHandler_,
			subscriptionServiceConfig.dataChangeNotificationHandlerStrand_,
			subscriptionServiceConfig.eventNotificationHandler_,
			subscriptionServiceConfig.eventNotificationHandlerStrand_,
			subscriptionServiceConfig.subscriptionStateUpdateHandler_,
			subscriptionServiceConfig.subscriptionStateUpdateHandlerStrand_,
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
		// check if monitored item service name already exist. Each monitored item service must have
		// a unique name.
		if (messageBus_->existMember(monitoredItemServiceConfig.monitoredItemServiceName_)) {
			Log(Debug, "monitored item service create error, because monitored item service name already exist")
			    .parameter("MonitoredItemServiceName", monitoredItemServiceConfig.monitoredItemServiceName_);
			return nullptr;
		}

		// create monitored item service
		createIOThread(monitoredItemServiceConfig.ioThreadName());
		auto ioThread = getIOThread(monitoredItemServiceConfig.ioThreadName());
		auto monitoredItemService = boost::make_shared<MonitoredItemService>(
			monitoredItemServiceConfig.monitoredItemServiceName_,
			ioThread.get(),
			messageBus_
		);

		// set monitored item configuration
		monitoredItemService->setConfiguration(
			sessionService->messageBusMember()
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
		// check if method service name already exist. Each method service must have
		// a unique name.
		if (messageBus_->existMember(methodServiceConfig.methodServiceName_)) {
			Log(Debug, "method service create error, because method service name already exist")
			    .parameter("MethodServiceName", methodServiceConfig.methodServiceName_);
			return nullptr;
		}

		// create monitored item service
		createIOThread(methodServiceConfig.ioThreadName());
		auto ioThread = getIOThread(methodServiceConfig.ioThreadName());
		auto methodService = boost::make_shared<MethodService>(
			methodServiceConfig.methodServiceName_,
			ioThread.get(),
			messageBus_
		);

		// set method configuration
		methodService->setConfiguration(
			sessionService->messageBusMember()
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
		// check if view service name already exist. Each view service must have
		// a unique name.
		if (messageBus_->existMember(viewServiceConfig.viewServiceName_)) {
			Log(Debug, "view service create error, because view service name already exist")
			    .parameter("ViewServiceName", viewServiceConfig.viewServiceName_);
			return nullptr;
		}

		// create view service
		createIOThread(viewServiceConfig.ioThreadName());
		auto ioThread = getIOThread(viewServiceConfig.ioThreadName());
		auto viewService = boost::make_shared<ViewService>(
			viewServiceConfig.viewServiceName_,
			ioThread.get(),
			messageBus_
		);

		// set view configuration
		viewService->setConfiguration(
			sessionService->messageBusMember()
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
		// check if query service name already exist. Each query service must have
		// a unique name.
		if (messageBus_->existMember(queryServiceConfig.queryServiceName_)) {
			Log(Debug, "query service create error, because query service name already exist")
			    .parameter("QueryServiceName", queryServiceConfig.queryServiceName_);
			return nullptr;
		}

		// create query service
		createIOThread(queryServiceConfig.ioThreadName());
		auto ioThread = getIOThread(queryServiceConfig.ioThreadName());
		auto queryService = boost::make_shared<QueryService>(
			queryServiceConfig.queryServiceName_,
			ioThread.get(),
			messageBus_
		);

		// set query configuration
		queryService->setConfiguration(
			sessionService->messageBusMember()
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
		NodeManagementServiceConfig& nodeManagementServiceConfig
	)
	{
		// check if node manafement service name already exist. Each node management service must have
		// a unique name.
		if (messageBus_->existMember(nodeManagementServiceConfig.nodeManagementServiceName_)) {
			Log(Debug, "node management service create error, because node management service name already exist")
			    .parameter("NodeManagementServiceName", nodeManagementServiceConfig.nodeManagementServiceName_);
			return nullptr;
		}

		// create node mangement service
		createIOThread(nodeManagementServiceConfig.ioThreadName());
		auto ioThread = getIOThread(nodeManagementServiceConfig.ioThreadName());
		auto nodeManagementService = boost::make_shared<NodeManagementService>(
			nodeManagementServiceConfig.nodeManagementServiceName_,
			ioThread.get(),
		    messageBus_
		);

		// set node management configuration
		nodeManagementService->setConfiguration(
			sessionService->messageBusMember()
		);

		return nodeManagementService;
	}

}
