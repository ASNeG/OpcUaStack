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
	, findResultCallback_()
	, findResults_()
	, findStatusCode_(BadCommunicationError)
	, shutdown_()
	, shutdownCond_()
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
			if (sessionState != SessionServiceStateId::Established) {

				if (shutdown_) {
					shutdownCond_.conditionValueDec();
					return;
				}

				findResultCallback_(findStatusCode_, findResults_);
				return;
			}

			sendFindServersRequest();
		};

		// create service set manager
		SessionServiceConfig sessionServiceConfig;
		sessionServiceConfig.ioThreadName("DiscoveryIOThread");
		sessionServiceConfig.secureChannelClient_->endpointUrl(discoveryUri_);
		sessionServiceConfig.sessionMode_ = SessionMode::SecureChannel;
		sessionServiceConfig.sessionServiceChangeHandler_ = sessionStateUpdate;

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
	   	shutdownCond_.condition(1,0);
	    ioThread_->run(
	    	boost::bind(&DiscoveryClientFindServers::shutdownTask, this)
	    );
	    shutdownCond_.waitForCondition(3000);

    	// deregister io thread from service set manager
    	serviceSetManager_.deregisterIOThread("DiscoveryIOThread");
	}

	void
	DiscoveryClientFindServers::shutdownTask(void)
	{
		shutdown_ = true;

		// FIXME: todo
		//if (sessionService_->secureChannelState() != SessionService::SCS_Disconnected) {
			sessionService_->asyncDisconnect();
			return;
		//}

		shutdownCond_.conditionValueDec();
	}

	void
	DiscoveryClientFindServers::asyncFind(const std::string serverUri, Callback& findResultCallback)
	{
		findResults_.clear();
		findStatusCode_ = BadCommunicationError;

		serverUri_ = serverUri;
		findResultCallback_ = findResultCallback;
		sessionService_->asyncConnect();
	}

	void
	DiscoveryClientFindServers::sendFindServersRequest(void)
	{
		ServiceTransactionFindServers::SPtr trx;
		trx = constructSPtr<ServiceTransactionFindServers>();
		FindServersRequest::SPtr req = trx->request();

		OpcUaStringArray::SPtr serverUris = constructSPtr<OpcUaStringArray>();
		serverUris->resize(1);
		OpcUaString::SPtr serverUri = constructSPtr<OpcUaString>();
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
    	ServiceTransactionFindServers::SPtr serviceTransactionFindServers
	)
    {
		if (serviceTransactionFindServers->statusCode() != Success) {
			Log(Error, "receive find servers response error")
				.parameter("StatusCode", OpcUaStatusCodeMap::shortString(serviceTransactionFindServers->statusCode()));
		}

		else {
			FindServersResponse::SPtr res = serviceTransactionFindServers->response();

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
