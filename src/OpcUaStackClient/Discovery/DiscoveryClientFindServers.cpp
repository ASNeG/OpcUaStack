/*
   Copyright 2017 Kai Huebl (kai@huebl-sgh.de)

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
#include "OpcUaStackClient/Discovery/DiscoveryClientFindServers.h"

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
		// create service set manager
		SessionServiceConfig sessionServiceConfig;
		sessionServiceConfig.ioThreadName("DiscoveryIOThread");
		sessionServiceConfig.sessionServiceIf_ = this;
		sessionServiceConfig.secureChannelClient_->endpointUrl(discoveryUri_);
		sessionServiceConfig.session_->sessionName("DiscoveryClient");
		sessionServiceConfig.session_->reconnectTimeout(5000);
		sessionServiceConfig.mode_ = SessionService::M_SecureChannel;
		serviceSetManager_.registerIOThread("DiscoveryIOThread", ioThread_);
		serviceSetManager_.sessionService(sessionServiceConfig);

		// create session service
		sessionService_ = serviceSetManager_.sessionService(sessionServiceConfig);

		// create discovery service
		DiscoveryServiceConfig discoveryServiceConfig;
		discoveryServiceConfig.ioThreadName("DiscoveryIOThread");
		discoveryServiceConfig.discoveryServiceIf_ = this;
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

    	// deregister io thread from service set manager
    	serviceSetManager_.deregisterIOThread("DiscoveryIOThread");
	}

	void
	DiscoveryClientFindServers::find(const std::string serverUri, Callback& findResultCallback)
	{
		serverUri_ = serverUri;
		findResultCallback_ = findResultCallback;
		sessionService_->asyncConnect();
	}

	void
	DiscoveryClientFindServers::sessionStateUpdate(SessionBase& session, SessionState sessionState)
	{
		if (sessionState != SS_Connect) {
			findResultCallback_(BadCommunicationError); // FIXME: application description...
			return;
		}

		sendFindServersRequest();
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

		discoveryService_->asyncSend(trx);
	}

    void
    DiscoveryClientFindServers::discoveryServiceFindServersResponse(ServiceTransactionFindServers::SPtr serviceTransactionFindServers)
    {
		if (serviceTransactionFindServers->statusCode() != Success) {
			Log(Error, "receive find servers response error")
				.parameter("StatusCode", OpcUaStatusCodeMap::shortString(serviceTransactionFindServers->statusCode()));
			findResultCallback_(BadCommunicationError); // FIXME: application description...
		}

		else {
			FindServersResponse::SPtr res = serviceTransactionFindServers->response();

		}

		sessionService_->asyncDisconnect();
    }

}
