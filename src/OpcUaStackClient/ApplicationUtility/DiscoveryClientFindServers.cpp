/*
   Copyright 2017-2019 Kai Huebl (kai@huebl-sgh.de)

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
#include "OpcUaStackClient/ApplicationUtility/DiscoveryClientFindServers.h"

using namespace OpcUaStackCore;

namespace OpcUaStackClient
{

	DiscoveryClientFindServers::DiscoveryClientFindServers(void)
	: ioThread_()
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
    DiscoveryClientFindServers::discoveryUri(const std::string& discoveryUri)
    {
    	discoveryUri_ = discoveryUri;
    }

	bool 
	DiscoveryClientFindServers::startup(void)
	{
		auto sessionStateUpdate = [this](SessionBase& session, SessionServiceStateId sessionState) {

			sessionStateId_ = sessionState;

			// ignore some states
			if (sessionState != SessionServiceStateId::Established &&
				sessionState != SessionServiceStateId::Disconnected) {
				return;
			}

			// the connection could not be opened
			if (sessionState == SessionServiceStateId::Disconnected) {

				if (shutdown_) {
					shutdownProm_.set_value();
					return;
				}

				if (resultHandler_) {
					resultHandler_(findStatusCode_, findResults_);
				}
				return;
			}

			// the connection has been opened
			sendFindServersRequest();
		};

		// create service set manager
		SessionServiceConfig sessionServiceConfig;
		sessionServiceConfig.ioThreadName("DiscoveryIOThread");
		sessionServiceConfig.secureChannelClient_->endpointUrl(discoveryUri_);
		sessionServiceConfig.sessionMode_ = SessionMode::SecureChannel;
		sessionServiceConfig.sessionServiceChangeHandler_ = sessionStateUpdate;
		sessionServiceConfig.sessionServiceName_ = "FindServersSession";

		serviceSetManager_.registerIOThread("DiscoveryIOThread", ioThread_);
		serviceSetManager_.sessionService(sessionServiceConfig);

		// create session service
		sessionService_ = serviceSetManager_.sessionService(sessionServiceConfig);

		// create discovery service
		DiscoveryServiceConfig discoveryServiceConfig;
		discoveryServiceConfig.ioThreadName("DiscoveryIOThread");
		discoveryService_ = serviceSetManager_.discoveryService(sessionService_, discoveryServiceConfig);

		return true;
	}

	void 
	DiscoveryClientFindServers::shutdown(void)
	{
		//
		// The shutdown thread and the communication thread (IO Thread) may not
		// be the same
		//

		// start shutdown task and wait for shutdown signal
		auto shutdownFuture = shutdownProm_.get_future();
	    ioThread_->run(
	    	[this](void) {
	    		shutdown_ = true;

	    		if (sessionStateId_ != SessionServiceStateId::Disconnected) {
	    			sessionService_->asyncDisconnect();
	    			return;
	    		}

	    		shutdownProm_.set_value();
	    	}
	    );
	    shutdownFuture.wait_for(std::chrono::milliseconds(3000));

    	// deregister io thread from service set manager
    	serviceSetManager_.deregisterIOThread("DiscoveryIOThread");
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

		sessionService_->asyncDisconnect();
    }

}
