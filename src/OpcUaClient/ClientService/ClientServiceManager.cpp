/*
   Copyright 2016 Kai Huebl (kai@huebl-sgh.de)

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

#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaClient/ClientService/ClientServiceManager.h"

using namespace OpcUaStackCore;

namespace OpcUaClient
{

	ClientServiceManager::ClientServiceManager(void)
	: clientAccessMap_()
	{
	}

	ClientServiceManager::~ClientServiceManager(void)
	{
	}

	ClientAccess::SPtr
	ClientServiceManager::getClientAccess(const std::string& clientAccessName)
	{
		ClientAccess::Map::iterator it;
		it = clientAccessMap_.find(clientAccessName);
		if (it != clientAccessMap_.end()) return it->second;

		ClientAccess::SPtr clientAccess;
		return clientAccess;
	}

	ClientAccess::SPtr
	ClientServiceManager::createClientAccess(const std::string& clientAccessName)
	{
		ClientAccess::SPtr clientAccess;
		ClientAccess::Map::iterator it;
		it = clientAccessMap_.find(clientAccessName);
		if (it != clientAccessMap_.end()) {

			return clientAccess;
		}
		ClientAccess = constructSPtr<ClientAccess>();
		clientAccessMap_.insert(std::make_pair(clientAccessName, clientAccess));
		return clientAccess;
	}


	ClientAccess::SPtr
	ClientServiceManager::getOrCreateClientAccess(const std::string& clientAccessName)
	{
		ClientAccess::SPtr clientAccess;
		clientAccess = getClientAccess(clientAccessName);
		if (clientAccess.get() != nullptr) return clientAccess;
		return createClientAccess(clientAccessName);
	}

}

