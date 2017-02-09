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
#include "OpcUaClient/Discovery/DiscoveryClientRegisteredServers.h"

using namespace OpcUaStackCore;

namespace OpcUaClient
{

	DiscoveryClientRegisteredServers::DiscoveryClientRegisteredServers(void)
	: ioThread_(nullptr)
	, mutex_()
	, registeredServerMap_()
	, slotTimerElement_()
	, loopTime_(40000)
	{
	}

	DiscoveryClientRegisteredServers::~DiscoveryClientRegisteredServers(void)
	{
	}

	void
	DiscoveryClientRegisteredServers::ioThread(IOThread* ioThread)
	{
		ioThread_ = ioThread;
	}

	void
	DiscoveryClientRegisteredServers::loopTime(uint32_t loopTime)
	{
		loopTime_ = loopTime;
	}

	bool 
	DiscoveryClientRegisteredServers::startup(void)
	{
	  	// start timer to check server entries
	  	slotTimerElement_ = constructSPtr<SlotTimerElement>();
	  	slotTimerElement_->callback().reset(boost::bind(&DiscoveryClientRegisteredServers::loop, this));
	  	slotTimerElement_->expireTime(boost::posix_time::microsec_clock::local_time(), loopTime_);
	  	ioThread_->slotTimer()->start(slotTimerElement_);

		return true;
	}

	void 
	DiscoveryClientRegisteredServers::shutdown(void)
	{
    	// stop timer
    	if (slotTimerElement_.get() != nullptr) {
    		ioThread_->slotTimer()->stop(slotTimerElement_);
    		slotTimerElement_.reset();
    	}
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
		Log(Debug, "register server loop");
    }

}
