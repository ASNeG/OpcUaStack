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


#include "OpcUaStackCore/Base/Log.h"
#include "OpcUaStackClient/ServiceSet/ServiceSetManager.h"

using namespace OpcUaStackCore;

namespace OpcUaStackClient
{

	ServiceSetManager::ServiceSetManager(void)
	: ioThreadMap_()
	{
	}

	ServiceSetManager::~ServiceSetManager(void)
	{
		while (ioThreadMap_.size() != 0) {
			destroyIOThread(ioThreadMap_.begin()->first);
		}
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
		createIOThread(sessionServiceConfig.ioThreadName_);
		IOThread::SPtr ioThread = getIOThread(sessionServiceConfig.ioThreadName_);
		SessionService::SPtr sessionService = constructSPtr<SessionService>(ioThread.get());

		// set session configuration
		sessionService->setConfiguration(
			sessionServiceConfig.mode_,
			sessionServiceConfig.sessionServiceIf_,
			sessionServiceConfig.secureChannelClient_,
			sessionServiceConfig.session_
		);

		return sessionService;
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
		createIOThread(discoveryServiceConfig.ioThreadName_);
		IOThread::SPtr ioThread = getIOThread(discoveryServiceConfig.ioThreadName_);
		DiscoveryService::SPtr discoveryService = constructSPtr<DiscoveryService>(ioThread.get());

		// set discovery configuration
		discoveryService->setConfiguration(
			sessionService->component(),
			discoveryServiceConfig.discoveryServiceIf_
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
		createIOThread(attributeServiceConfig.ioThreadName_);
		IOThread::SPtr ioThread = getIOThread(attributeServiceConfig.ioThreadName_);
		AttributeService::SPtr attributeService = constructSPtr<AttributeService>(ioThread.get());

		// set attribute configuration
		attributeService->setConfiguration(
			sessionService->component(),
			attributeServiceConfig.attributeServiceIf_
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
		// create attribute service
		createIOThread(subscriptionServiceConfig.ioThreadName_);
		IOThread::SPtr ioThread = getIOThread(subscriptionServiceConfig.ioThreadName_);
		SubscriptionService::SPtr subscriptionService = constructSPtr<SubscriptionService>(ioThread.get());

		// set subscription configuration
		subscriptionService->setConfiguration(
			sessionService->component(),
			subscriptionServiceConfig.publishCount_,
			subscriptionServiceConfig.subscriptionServiceIf_
		);

		return subscriptionService;
	}

}
