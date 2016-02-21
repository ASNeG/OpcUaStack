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
#include "OpcUaClient/ClientCommand/CommandRead.h"
#include "OpcUaClient/ClientService/ClientServiceRead.h"

using namespace OpcUaStackCore;

namespace OpcUaClient
{

	ClientServiceRead::ClientServiceRead(void)
	: ClientServiceBase()
	{
	}

	ClientServiceRead::~ClientServiceRead(void)
	{
	}

	ClientServiceBase::SPtr
	ClientServiceRead::createClientService(void)
	{
		return constructSPtr<ClientServiceRead>();
	}

	bool
	ClientServiceRead::run(ClientServiceManager& clientServiceManager, CommandBase::SPtr& commandBase)
	{
		std::cout << "run read..." << std::endl;

		CommandRead::SPtr commandRead = boost::static_pointer_cast<CommandRead>(commandBase);

		// create new or get existing client object
		ClientAccessObject::SPtr clientAccessObject;
		clientAccessObject = clientServiceManager.getClientAccessObject(commandRead->session());
		if (clientAccessObject.get() == nullptr) {
			std::stringstream ss;
			ss << "get client access object failed for session " << commandRead->session();
			errorMessage(ss.str());
			return false;
		}

		// check session
		if (clientAccessObject->sessionService_.get() == nullptr) {
			std::stringstream ss;
			ss << "session object not exist " << commandRead->session();
			return false;
		}

		// get or create attribute service
		AttributeService::SPtr attributeService;
		attributeService = clientAccessObject->getOrCreateAttributeService();
		if (attributeService.get() == nullptr) {
			std::stringstream ss;
			ss << "get client attribute service failed for session " << commandRead->session();
			errorMessage(ss.str());
			return false;
		}

		// create read request

		// send read request

		// process read response

		return true;
	}

}

