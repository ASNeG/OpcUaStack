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

#include "OpcUaClient/ClientCommand/CommandDisconnect.h"
#include "OpcUaClient/ClientService/ClientServiceDisconnect.h"

using namespace OpcUaStackCore;

namespace OpcUaClient
{

	ClientServiceDisconnect::ClientServiceDisconnect(void)
	: ClientServiceBase()
	{
	}

	ClientServiceDisconnect::~ClientServiceDisconnect(void)
	{
	}

	ClientServiceBase::SPtr
	ClientServiceDisconnect::createClientService(void)
	{
		return boost::make_shared<ClientServiceDisconnect>();
	}

	bool
	ClientServiceDisconnect::run(ClientServiceManager& clientServiceManager, CommandBase::SPtr& commandBase)
	{
		CommandDisconnect::SPtr commandDisconnect = boost::static_pointer_cast<CommandDisconnect>(commandBase);

		// create new or get existing client object
		ClientAccessObject::SPtr clientAccessObject;
		clientAccessObject = clientServiceManager.getClientAccessObject(commandDisconnect->session());
		if (clientAccessObject.get() == nullptr) {
			std::stringstream ss;
			ss << "get client access object failed for session " << commandDisconnect->session();
			errorMessage(ss.str());
			return false;
		}

		// check session
		if (clientAccessObject->sessionService_.get() == nullptr) {
			std::stringstream ss;
			ss << "session object not exist " << commandDisconnect->session();
			errorMessage(ss.str());
			return false;
		}

		// connect session
		OpcUaStatusCode statusCode;
		statusCode = clientAccessObject->sessionService_->syncDisconnect();
		if (statusCode != Success) {
			std::stringstream ss;
			ss << "disconnect error: "
			   << " Session=" << commandDisconnect->session()
			   << " StatusCode=" << OpcUaStatusCodeMap::shortString(statusCode);
			errorMessage(ss.str());
			return false;
		}

		return true;
	}

}

