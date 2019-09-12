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

#include "OpcUaClient/ClientCommand/CommandFindServer.h"
#include "OpcUaClient/ClientService/ClientServiceFindServer.h"

using namespace OpcUaStackCore;
using namespace OpcUaStackClient;

namespace OpcUaClient
{

	ClientServiceFindServer::ClientServiceFindServer(void)
	: ClientServiceBase()
	{
	}

	ClientServiceFindServer::~ClientServiceFindServer(void)
	{
	}

	ClientServiceBase::SPtr
	ClientServiceFindServer::createClientService(void)
	{
		return boost::make_shared<ClientServiceFindServer>();
	}

	bool
	ClientServiceFindServer::run(ClientServiceManager& clientServiceManager, CommandBase::SPtr& commandBase)
	{
		OpcUaStatusCode statusCode;
		CommandFindServer::SPtr commandFindServer = boost::static_pointer_cast<CommandFindServer>(commandBase);

		// create new or get existing client object
		ClientAccessObject::SPtr clientAccessObject;
		clientAccessObject = clientServiceManager.getClientAccessObject(commandFindServer->session());
		if (clientAccessObject.get() == nullptr) {
			std::stringstream ss;
			ss << "get client access object failed:"
			   << " Session=" << commandFindServer->session();
			errorMessage(ss.str());
			return false;
		}

		// check session
		if (clientAccessObject->sessionService_.get() == nullptr) {
			std::stringstream ss;
			ss << "session object not exist: "
			   << " Session=" << commandFindServer->session();
			return false;
		}

		// get or create discovery service
		DiscoveryService::SPtr discoveryService;
		discoveryService = clientAccessObject->getOrCreateDiscoveryService();
		if (discoveryService.get() == nullptr) {
			std::stringstream ss;
			ss << "get client discovery service failed"
			   << " Session=" << commandFindServer->session();
			errorMessage(ss.str());
			return false;
		}

		// create get endpoint request
		ServiceTransactionFindServers::SPtr trx;
		trx = boost::make_shared<ServiceTransactionFindServers>();
		FindServersRequest::SPtr req = trx->request();

		// FIXME: set parameter

		// send read request
		discoveryService->syncSend(trx);

		// process read response
		statusCode = trx->statusCode();
		if (statusCode != Success) {
			std::stringstream ss;
			ss << "find server error: "
			   << " Session=" << commandFindServer->session()
			   << " StatusCode=" << OpcUaStatusCodeMap::shortString(statusCode);
			errorMessage(ss.str());
			return false;
		}

		FindServersResponse::SPtr res = trx->response();
		for (uint32_t idx=0; idx<res->servers()->size(); idx++) {
			ApplicationDescription::SPtr description;
			res->servers()->get(idx, description);
			description->out(std::cout); std::cout << std::endl;
		}

		return true;
	}

}

