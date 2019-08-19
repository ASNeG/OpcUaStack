/*
   Copyright 2016-2019 Kai Huebl (kai@huebl-sgh.de)

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

#include "OpcUaClient/ClientService/ClientServiceManager.h"

using namespace OpcUaStackCore;

namespace OpcUaClient
{

	ClientServiceManager::ClientServiceManager(void)
	: clientAccessObjectMap_()
	{
	}

	ClientServiceManager::~ClientServiceManager(void)
	{
	}

	ClientAccessObject::SPtr
	ClientServiceManager::getClientAccessObject(const std::string& clientAccessObjectName)
	{
		ClientAccessObject::Map::iterator it;
		it = clientAccessObjectMap_.find(clientAccessObjectName);
		if (it != clientAccessObjectMap_.end()) return it->second;

		ClientAccessObject::SPtr clientAccessObject;
		return clientAccessObject;
	}

	ClientAccessObject::SPtr
	ClientServiceManager::createClientAccessObject(const std::string& clientAccessObjectName)
	{
		ClientAccessObject::SPtr clientAccessObject;
		ClientAccessObject::Map::iterator it;
		it = clientAccessObjectMap_.find(clientAccessObjectName);
		if (it != clientAccessObjectMap_.end()) {

			return clientAccessObject;
		}
		clientAccessObject = boost::make_shared<ClientAccessObject>();
		clientAccessObjectMap_.insert(std::make_pair(clientAccessObjectName, clientAccessObject));
		return clientAccessObject;
	}


	ClientAccessObject::SPtr
	ClientServiceManager::getOrCreateClientAccessObject(const std::string& clientAccessObjectName)
	{
		ClientAccessObject::SPtr clientAccessObject;
		clientAccessObject = getClientAccessObject(clientAccessObjectName);
		if (clientAccessObject.get() != nullptr) return clientAccessObject;
		return createClientAccessObject(clientAccessObjectName);
	}

}

