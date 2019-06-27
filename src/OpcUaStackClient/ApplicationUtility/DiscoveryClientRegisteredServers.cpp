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
#include "OpcUaStackClient/ApplicationUtility/DiscoveryClientRegisteredServers.h"

using namespace OpcUaStackCore;

namespace OpcUaStackClient
{

	DiscoveryClientRegisteredServers::DiscoveryClientRegisteredServers(void)
	: ioThread_()
	, mutex_()
	, registeredServerMap_()
	, slotTimerElement_()
	, registerInterval_(40000)
	, discoveryUri_("")
	, sessionService_()
	, shutdown_(false)
	, shutdownCond_()
	{
	}

	DiscoveryClientRegisteredServers::~DiscoveryClientRegisteredServers(void)
	{
    	if (slotTimerElement_.get() != nullptr) {
    		slotTimerElement_.reset();
    	}
	}

	void
	DiscoveryClientRegisteredServers::ioThread(IOThread::SPtr& ioThread)
	{
		ioThread_ = ioThread;
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
		// create service set manager
		SessionServiceConfig sessionServiceConfig;
		sessionServiceConfig.ioThreadName("DiscoveryIOThread");
		sessionServiceConfig.sessionServiceIf_ = this;
		sessionServiceConfig.secureChannelClient_->endpointUrl(discoveryUri_);
		sessionServiceConfig.mode_ = SessionService::M_SecureChannel;
		sessionServiceConfig.session_->reconnectTimeout_ = 0;
		serviceSetManager_.registerIOThread("DiscoveryIOThread", ioThread_);
		serviceSetManager_.sessionService(sessionServiceConfig);

		// create session service
		sessionService_ = serviceSetManager_.sessionService(sessionServiceConfig);

		// create discovery service
		DiscoveryServiceConfig discoveryServiceConfig;
		discoveryServiceConfig.ioThreadName("DiscoveryIOThread");
		discoveryServiceConfig.discoveryServiceIf_ = this;
		discoveryService_ = serviceSetManager_.discoveryService(sessionService_, discoveryServiceConfig);

	  	// start timer to check server entries
	  	slotTimerElement_ = constructSPtr<SlotTimerElement>();
	  	slotTimerElement_->callback().reset(boost::bind(&DiscoveryClientRegisteredServers::loop, this));
	  	slotTimerElement_->expireTime(boost::posix_time::microsec_clock::local_time(), registerInterval_);
	  	ioThread_->slotTimer()->start(slotTimerElement_);

		return true;
	}

	void 
	DiscoveryClientRegisteredServers::shutdown(void)
	{
		//
		// The shutdown thread and the communication thread (IO Thread) may not
		// be the same
		//

    	// stop timer
    	if (slotTimerElement_.get() != nullptr) {
    		ioThread_->slotTimer()->stop(slotTimerElement_);
    	}

    	// deregister server entries from discovery server and wait of the
    	// end of the process
    	shutdownCond_.condition(1,0);
    	ioThread_->run(
    		boost::bind(&DiscoveryClientRegisteredServers::shutdownLoop, this)
    	);
    	if (!shutdownCond_.waitForCondition(3000)) {
    		Log(Error, "discovery client registered server shutdown timeout");
    	}

    	// deregister io thread from service set manager
    	serviceSetManager_.deregisterIOThread("DiscoveryIOThread");
	}

    void
	DiscoveryClientRegisteredServers::addRegisteredServer(const std::string& name, RegisteredServer::SPtr& registeredServer)
	{
		boost::mutex::scoped_lock g(mutex_);

		// check existing registered server entry
		RegisteredServer::Map::iterator it;
		it = registeredServerMap_.find(name);
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
		boost::mutex::scoped_lock g(mutex_);

		// check existing registered server entry
		RegisteredServer::Map::iterator it;
		it = registeredServerMap_.find(name);
		if (it == registeredServerMap_.end()) {
			return;
		}

		// set online flag off
		RegisteredServer::SPtr registeredServer = it->second;
		registeredServer->isOnline(false);
	}

    void
    DiscoveryClientRegisteredServers::loop(void)
    {
		Log(Debug, "register server discovery loop");
		sessionService_->asyncConnect();
    }

    void
    DiscoveryClientRegisteredServers::shutdownLoop(void)
    {
		Log(Debug, "deregister server discovery loop");
		shutdown_ = true;
		deregisterServers();
	    sessionService_->asyncDisconnect();
	    shutdownCond_.conditionValueDec();
    }

	void
	DiscoveryClientRegisteredServers::sessionStateUpdate(SessionBase& session, SessionState sessionState)
	{
		if (sessionState == SS_Connect) {
			sendDiscoveryServiceRegisterServer();
			return;
		}

		if (shutdown_) {
			shutdownCond_.conditionValueDec();
		}
	}

	void
	DiscoveryClientRegisteredServers::sendDiscoveryServiceRegisterServer(void)
	{
		if (registeredServerMap_.size() == 0) {
			sessionService_->asyncDisconnect();
		}

		RegisteredServer::Map::iterator it;
		for (it = registeredServerMap_.begin(); it != registeredServerMap_.end(); it++) {

			ServiceTransactionRegisterServer::SPtr trx;
			trx = constructSPtr<ServiceTransactionRegisterServer>();
			RegisterServerRequest::SPtr req = trx->request();

			it->second->copyTo(req->server());

			discoveryService_->asyncSend(trx);
		}

	}

	void
	DiscoveryClientRegisteredServers::discoveryServiceRegisterServerResponse(ServiceTransactionRegisterServer::SPtr serviceTransactionRegisterServer)
	{
		if (serviceTransactionRegisterServer->statusCode() != Success) {
			Log(Error, "receive register server response error")
				.parameter("StatusCode", OpcUaStatusCodeMap::shortString(serviceTransactionRegisterServer->statusCode()));

		}

		sessionService_->asyncDisconnect();
	}

	void
	DiscoveryClientRegisteredServers::deregisterServers(void)
	{
		// all server entries must be deregister from dicovery server. We must
		// disable the isOnline flag
		RegisteredServer::Map::iterator it;
		for (it = registeredServerMap_.begin(); it != registeredServerMap_.end(); it++) {
			RegisteredServer::SPtr rs = it->second;
			rs->isOnline(false);
		}

		;
	}

}
