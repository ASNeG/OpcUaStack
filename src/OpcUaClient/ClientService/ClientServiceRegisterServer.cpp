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

#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaClient/ClientCommand/CommandRegisterServer.h"
#include "OpcUaClient/ClientService/ClientServiceRegisterServer.h"

using namespace OpcUaStackCore;

namespace OpcUaClient
{

	ClientServiceRegisterServer::ClientServiceRegisterServer(void)
	: ClientServiceBase()
	{
	}

	ClientServiceRegisterServer::~ClientServiceRegisterServer(void)
	{
	}

	ClientServiceBase::SPtr
	ClientServiceRegisterServer::createClientService(void)
	{
		return constructSPtr<ClientServiceRegisterServer>();
	}

	bool
	ClientServiceRegisterServer::run(ClientServiceManager& clientServiceManager, CommandBase::SPtr& commandBase)
	{
		OpcUaStatusCode statusCode;
		CommandRegisterServer::SPtr commandRegisterServer = boost::static_pointer_cast<CommandRegisterServer>(commandBase);

		// create new or get existing client object
		ClientAccessObject::SPtr clientAccessObject;
		clientAccessObject = clientServiceManager.getClientAccessObject(commandRegisterServer->session());
		if (clientAccessObject.get() == nullptr) {
			std::stringstream ss;
			ss << "get client access object failed:"
			   << " Session=" << commandRegisterServer->session();
			errorMessage(ss.str());
			return false;
		}

		// check session
		if (clientAccessObject->sessionService_.get() == nullptr) {
			std::stringstream ss;
			ss << "session object not exist: "
			   << " Session=" << commandRegisterServer->session();
			return false;
		}

		// get or create discovery service
		DiscoveryService::SPtr discoveryService;
		discoveryService = clientAccessObject->getOrCreateDiscoveryService();
		if (discoveryService.get() == nullptr) {
			std::stringstream ss;
			ss << "get client discovery service failed"
			   << " Session=" << commandRegisterServer->session();
			errorMessage(ss.str());
			return false;
		}

		// create register server request
		ServiceTransactionRegisterServer::SPtr trx;
		trx = constructSPtr<ServiceTransactionRegisterServer>();
		RegisterServerRequest::SPtr req = trx->request();

		// FIXME: command line parameter

		// send read request
		discoveryService->syncSend(trx);

		// process read response
		statusCode = trx->statusCode();
		if (statusCode != Success) {
			std::stringstream ss;
			ss << "discovery error: "
			   << " Session=" << commandRegisterServer->session()
			   << " StatusCode=" << OpcUaStatusCodeMap::shortString(statusCode);
			errorMessage(ss.str());
			return false;
		}

		return true;
	}

}

