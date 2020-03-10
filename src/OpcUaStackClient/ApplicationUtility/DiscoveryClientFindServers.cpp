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
#include "OpcUaStackClient/ApplicationUtility/DiscoveryClientFindServers.h"

using namespace OpcUaStackCore;

namespace OpcUaStackClient
{

	DiscoveryClientFindServers::DiscoveryClientFindServers(void)
	: ioThread_()
	, messageBus_()
	, discoveryUri_("")
	, serviceSetManager_()
	, sessionService_()
	, discoveryService_()
	, serverUri_("")
	, resultHandler_()
	, findResults_()
	, findStatusCode_(BadCommunicationError)
	, shutdown_()
	, shutdownProm_()
	, sessionStateId_(SessionServiceStateId::Disconnected)
	{
	}

	DiscoveryClientFindServers::~DiscoveryClientFindServers(void)
	{
	}

    void
    DiscoveryClientFindServers::ioThread(IOThread::SPtr& ioThread)
    {
    	ioThread_ = ioThread;
    }

    void
	DiscoveryClientFindServers::messageBus(OpcUaStackCore::MessageBus::SPtr& messageBus)
    {
    	messageBus_ = messageBus;
    }

    void
    DiscoveryClientFindServers::discoveryUri(const std::string& discoveryUri)
    {
    	discoveryUri_ = discoveryUri;
    }

	bool 
	DiscoveryClientFindServers::startup(void)
	{
		shutdownContext_ = nullptr;

		auto sessionStateUpdate = [this](SessionBase& session, SessionServiceStateId sessionState) {
			assert(strand_->running_in_this_thread());
			sessionState_ = sessionState;

			// ignore some states
			if (sessionState != SessionServiceStateId::Established &&
				sessionState != SessionServiceStateId::Disconnected) {
				return;
			}

			if (sessionState == SessionServiceStateId::Established) {
			     sendFindServersRequest();
			     return;
			}

			if (sessionState == SessionServiceStateId::Disconnected) {
			    disconnectSession();
			}
		};

		// register thread in service set manager. All services use the
		// same thread pool
		std::string id = UniqueId::createStringUniqueId();
		threadPoolName_ = std::string("DiscoveryClientFindServers_") + id;
		serviceSetManager_.registerIOThread(threadPoolName_, ioThread_);
		serviceSetManager_.messageBus(messageBus_);

		// create new strand
		strand_ = ioThread_->createStrand();

		// create service set manager
		SessionServiceConfig sessionServiceConfig;
		sessionServiceConfig.ioThreadName(threadPoolName_);
		sessionServiceConfig.secureChannelClient_->endpointUrl(discoveryUri_);
		sessionServiceConfig.sessionMode_ = SessionMode::SecureChannel;
		sessionServiceConfig.sessionServiceChangeHandler_ = sessionStateUpdate;
		sessionServiceConfig.sessionServiceChangeHandlerStrand_ = strand_;
		sessionServiceConfig.sessionServiceName_ = std::string("SessionService_") + id;
		sessionService_ = serviceSetManager_.sessionService(sessionServiceConfig);

		// create discovery service
		DiscoveryServiceConfig discoveryServiceConfig;
		discoveryServiceConfig.ioThreadName(threadPoolName_);
		discoveryServiceConfig.discoveryServiceName_ = std::string("DiscoveryService_") + id;
		discoveryService_ = serviceSetManager_.discoveryService(sessionService_, discoveryServiceConfig);

		return true;
	}

	void
	DiscoveryClientFindServers::asyncShutdown(const ShutdownCompleteCallback& shutdownCompleteCallback)
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

		// disconnect session
		disconnectSession();

    	// The function shutdownComplete is called asynchronously after
    	// session shutdown.
	}

	void
	DiscoveryClientFindServers::shutdownComplete(void)
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
	DiscoveryClientFindServers::syncShutdown(void)
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
	DiscoveryClientFindServers::asyncFind(
		const std::string& serverUri,
		const FindServerHandler& resultHandler
	)
	{
		findResults_.clear();
		findStatusCode_ = BadCommunicationError;

		serverUri_ = serverUri;
		resultHandler_ = resultHandler;
		sessionService_->asyncConnect();
	}

	void
	DiscoveryClientFindServers::sendFindServersRequest(void)
	{
		auto trx = boost::make_shared<ServiceTransactionFindServers>();
		auto req = trx->request();

		auto serverUris = boost::make_shared<OpcUaStringArray>();
		serverUris->resize(1);
		auto serverUri = boost::make_shared<OpcUaString>();
		serverUri->value(serverUri_);
		serverUris->push_back(serverUri);
		req->serverUris(serverUris);

		trx->resultHandlerStrand(strand_);
		trx->resultHandler(
			[this](ServiceTransactionFindServers::SPtr& trx) {
		        discoveryServiceFindServersResponse(trx);
			}
		);
		discoveryService_->asyncSend(trx);
	}

    void
    DiscoveryClientFindServers::discoveryServiceFindServersResponse(
    	ServiceTransactionFindServers::SPtr& serviceTransactionFindServers
	)
    {
		if (serviceTransactionFindServers->statusCode() != Success) {
			Log(Error, "receive find servers response error")
				.parameter("StatusCode", OpcUaStatusCodeMap::shortString(serviceTransactionFindServers->statusCode()));
		}

		else {
			auto res = serviceTransactionFindServers->response();

			findStatusCode_ = Success;
			findResults_.clear();
			for (uint32_t idx = 0; idx < res->servers()->size(); idx++) {
				ApplicationDescription::SPtr applicationDescription;
				res->servers()->get(idx, applicationDescription);
				findResults_.push_back(applicationDescription);
			}

		}

		disconnectSession();
    }

	void
	DiscoveryClientFindServers::disconnectSession(void)
	{
		if (sessionState_ != SessionServiceStateId::Disconnected) {
			sessionService_->asyncDisconnect();
			return;
		}

        if (resultHandler_) {
	        resultHandler_(findStatusCode_, findResults_);
	        resultHandler_ = nullptr;
        }

		if (shutdownContext_) {
	        shutdownComplete();
		}
	}

}
