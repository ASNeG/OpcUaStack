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
#include "OpcUaStackClient/Discovery/DiscoveryClientRegisteredServers.h"

using namespace OpcUaStackCore;

namespace OpcUaStackClient
{

	DiscoveryClientRegisteredServers::DiscoveryClientRegisteredServers(void)
	: registeredServerMap_()
	{
	}

	DiscoveryClientRegisteredServers::~DiscoveryClientRegisteredServers(void)
	{
	}

	bool 
	DiscoveryClientRegisteredServers::startup(void)
	{
	}

	void 
	DiscoveryClientRegisteredServers::shutdown(void)
	{
	}

	void
	DiscoveryClientRegisteredServers::addRegisteredServer(const std::string& name, RegisteredServer::SPtr& registeredServer)
	{
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
		// check existing registered server entry
		RegisteredServer::Map::iterator it;
		it = registeredServerMap_.find(name);
		if (it != registeredServerMap_.end()) {
			// remove existing registered server entry
			registeredServerMap_.erase(it);
		}
	}

}
