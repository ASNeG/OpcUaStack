/*
   Copyright 2017-2020 Kai Huebl (kai@huebl-sgh.de)

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
#include "OpcUaStackCore/Utility/UniqueId.h"
#include "OpcUaStackClient/ApplicationUtility/DiscoveryClientRegisteredServers.h"

using namespace OpcUaStackCore;

namespace OpcUaStackClient
{

	DiscoveryClientRegisteredServers::DiscoveryClientRegisteredServers(void)
	: ioThread_()
	, registeredServerMap_()
	, slotTimerElement_()
	, registerInterval_(40000)
	, discoveryUri_("")
	, sessionService_()
	, cryptoManager_()
	{
	}

	DiscoveryClientRegisteredServers::~DiscoveryClientRegisteredServers(void)
	{
    	if (slotTimerElement_.get() != nullptr) {
    		slotTimerElement_.reset();
    	}
	}

	void
	DiscoveryClientRegisteredServers::cryptoManager(CryptoManager::SPtr& cryptoManager)
	{
		cryptoManager_ = cryptoManager;
	}

	void
	DiscoveryClientRegisteredServers::ioThread(IOThread::SPtr& ioThread)
	{
		ioThread_ = ioThread;
	}

	void
	DiscoveryClientRegisteredServers::messageBus(OpcUaStackCore::MessageBus::SPtr& messageBus)
	{
		messageBus_ = messageBus;
	}

	void
	DiscoveryClientRegisteredServers::discoveryUri(const std::string& discoveryUri)
	{
		discoveryUri_ = discoveryUri;
	}

	void
	DiscoveryClientRegisteredServers::registerInterval(uint32_t registerInterval)
	{
		registerInterval_ = registerInterval;
	}

	bool
	DiscoveryClientRegisteredServers::startup(void)
	{
		shutdownContext_ = nullptr;

		auto sessionStateUpdate = [this](SessionBase& session, SessionServiceStateId sessionState) {
			sessionState_ = sessionState;

			if (sessionState != SessionServiceStateId::Established &&
				sessionState != SessionServiceStateId::Disconnected) {
				return;
			}

		    if (sessionState == SessionServiceStateId::Established) {
		        sendDiscoveryServiceRegisterServer();
				return;
		    }

		    if (sessionState == SessionServiceStateId::Disconnected) {
				disconnectSession();
		    }
		};

		// register thread in service set manager. All services use the
		// same thread pool
		std::string id = UniqueId::createStringUniqueId();
		threadPoolName_ = std::string("DiscoveryClientRegisteredServers_") + id;
		serviceSetManager_.registerIOThread(threadPoolName_, ioThread_);
		serviceSetManager_.messageBus(messageBus_);

		// create new strand
		strand_ = ioThread_->createStrand();

		// create session service
		SessionServiceConfig sessionServiceConfig;
		sessionServiceConfig.ioThreadName(threadPoolName_);
		sessionServiceConfig.secureChannelClient_->endpointUrl(discoveryUri_);
		sessionServiceConfig.secureChannelClient_->cryptoManager(cryptoManager_);
		sessionServiceConfig.sessionMode_ = SessionMode::SecureChannel;
		sessionServiceConfig.sessionServiceChangeHandler_ = sessionStateUpdate;
		sessionServiceConfig.sessionServiceChangeHandlerStrand_ = strand_;
		sessionServiceConfig.session_->reconnectTimeout(0);
		sessionServiceConfig.sessionServiceName_ = std::string("SessionService_") + id;
		sessionService_ = serviceSetManager_.sessionService(sessionServiceConfig);

		// create discovery service
		DiscoveryServiceConfig discoveryServiceConfig;
		discoveryServiceConfig.ioThreadName(threadPoolName_);
		discoveryServiceConfig.discoveryServiceName_ = std::string("DiscoveryService_") + id;
		discoveryService_ = serviceSetManager_.discoveryService(sessionService_, discoveryServiceConfig);

	  	// start timer to check server entries
	  	slotTimerElement_ = boost::make_shared<SlotTimerElement>();
	  	slotTimerElement_->timeoutCallback(
	  		strand_,
	  		[this](void) {
	  		    sessionService_->asyncConnect();
	  	    }
	  	);
	  	slotTimerElement_->expireTime(boost::posix_time::microsec_clock::local_time(), registerInterval_);
	  	ioThread_->slotTimer()->start(slotTimerElement_);

		return true;
	}

	void 
	DiscoveryClientRegisteredServers::asyncShutdown(const ShutdownCompleteCallback& shutdownCompleteCallback)
	{
		// check if the function is called outside the strand
		if (!strand_->running_in_this_thread()) {
			strand_->dispatch(
				[this, shutdownCompleteCallback]() {
					asyncShutdown(shutdownCompleteCallback);
			    }
			);
			return;
		}

		// init shutdown context
		shutdownContext_ = boost::make_shared<ShutdownContext>();
		shutdownContext_->shutdownCompleteCallback_ = shutdownCompleteCallback;

		// stop timer
    	if (slotTimerElement_.get() != nullptr) {
    		ioThread_->slotTimer()->stop(slotTimerElement_);
    	}

    	// deregister servers
    	deregisterServers();

    	// The function shutdownComplete is called asynchronously after
    	// session shutdown.
	}

	void
	DiscoveryClientRegisteredServers::shutdownComplete(void)
	{
    	// delete services
    	discoveryService_.reset();
    	sessionService_.reset();

    	// deregister io thread from service set manager
    	serviceSetManager_.deregisterIOThread(threadPoolName_);

    	// call shutdown complete callback
    	auto shutdownCompleteCallback = shutdownContext_->shutdownCompleteCallback_;
    	shutdownContext_ = nullptr;
    	shutdownCompleteCallback();
	}

	void
	DiscoveryClientRegisteredServers::syncShutdown(void)
	{
		assert(!strand_->running_in_this_thread());

		std::promise<void> promise;
		std::future<void> future = promise.get_future();
		asyncShutdown(
			[this, &promise](void) {
			    promise.set_value();
				return;
			}
		);
		future.wait();
	}

    void
	DiscoveryClientRegisteredServers::addRegisteredServer(const std::string& name, RegisteredServer::SPtr& registeredServer)
	{
    	// if the strand exist we must synchronize the call with a strand
		if (strand_ && !strand_->running_in_this_thread()) {
			std::promise<void> promise;
			std::future<void> future = promise.get_future();
			strand_->dispatch(
				[this, &promise, &name, &registeredServer](void) {
				    addRegisteredServer(name, registeredServer);
					promise.set_value();
			    }
			);
			future.wait();
		}

		// check existing registered server entry
		auto it = registeredServerMap_.find(name);
		if (it != registeredServerMap_.end()) {
			// remove existing registered server entry
			registeredServerMap_.erase(it);
		}

		// insert new registered server entry
		registeredServerMap_.insert(std::make_pair(name, registeredServer));
	}

	void
	DiscoveryClientRegisteredServers::removeRegisteredServer(const std::string& name)
	{
    	// if the strand exist we must synchronize the call with a strand
		if (strand_ && !strand_->running_in_this_thread()) {
			std::promise<void> promise;
			std::future<void> future = promise.get_future();
			strand_->dispatch(
				[this, &promise, &name](void) {
				removeRegisteredServer(name);
					promise.set_value();
			    }
			);
			future.wait();
		}

		// check existing registered server entry
		auto it = registeredServerMap_.find(name);
		if (it == registeredServerMap_.end()) {
			return;
		}

		// set online flag off
		auto registeredServer = it->second;
		registeredServer->isOnline() = false;
	}

	void
	DiscoveryClientRegisteredServers::sendDiscoveryServiceRegisterServer(void)
	{
		if (registeredServerMap_.size() == 0) {
			disconnectSession();
			return;
		}

		for (auto it = registeredServerMap_.begin(); it != registeredServerMap_.end(); it++) {

			auto trx = boost::make_shared<ServiceTransactionRegisterServer>();
			auto req = trx->request();

			it->second->copyTo(req->server());

			trx->resultHandlerStrand(strand_);
			trx->resultHandler(
			    [this](ServiceTransactionRegisterServer::SPtr& trx) {
				    discoveryServiceRegisterServerResponse(trx);
			    }
			);
			discoveryService_->asyncSend(trx);
		}

	}

	void
	DiscoveryClientRegisteredServers::discoveryServiceRegisterServerResponse(
		ServiceTransactionRegisterServer::SPtr& serviceTransactionRegisterServer
	)
	{
		if (serviceTransactionRegisterServer->statusCode() != Success) {
			Log(Error, "receive register server response error")
				.parameter("StatusCode", OpcUaStatusCodeMap::shortString(serviceTransactionRegisterServer->statusCode()));

		}

		disconnectSession();
	}

	void
	DiscoveryClientRegisteredServers::deregisterServers(void)
	{
		// all server entries must be deregister from dicovery server. We must
		// disable the isOnline flag
		for (auto it = registeredServerMap_.begin(); it != registeredServerMap_.end(); it++) {
			RegisteredServer::SPtr rs = it->second;
			rs->isOnline() = false;
		}
		disconnectSession();
	}

	void
	DiscoveryClientRegisteredServers::disconnectSession(void)
	{
		if (sessionState_ != SessionServiceStateId::Disconnected) {
			sessionService_->asyncDisconnect();
			return;
		}

		if (shutdownContext_) {
	        shutdownComplete();
		}
	}

}
