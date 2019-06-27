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

		// added request parameter
		std::vector<std::string>::iterator it;
		req->server().serverUri(commandRegisterServer->serverUri());
		req->server().productUri(commandRegisterServer->productUri());
		req->server().serverNames(constructSPtr<OpcUaLocalizedTextArray>());
		req->server().serverNames()->resize(commandRegisterServer->serverNames().size());
		for (it=commandRegisterServer->serverNames().begin(); it!=commandRegisterServer->serverNames().end(); it++) {
			OpcUaLocalizedText::SPtr serverName = constructSPtr<OpcUaLocalizedText>();
			serverName->set("en", *it);
			req->server().serverNames()->push_back(serverName);
		}
		if (commandRegisterServer->serverType() == "CLIENT") {
			req->server().serverType(AT_Client);
		}
		if (commandRegisterServer->serverType() == "SERVER") {
			req->server().serverType(AT_Server);
		}
		else {
			req->server().serverType(AT_ClientAndServer);
		}
		req->server().gatewayServerUri(commandRegisterServer->gatewayServerUri());
		req->server().discoveryUrls(constructSPtr<OpcUaStringArray>());
		req->server().discoveryUrls()->resize(commandRegisterServer->discoveryUrls().size());
		for (it=commandRegisterServer->discoveryUrls().begin(); it!=commandRegisterServer->discoveryUrls().end(); it++) {
			OpcUaString::SPtr discoveryUrl = constructSPtr<OpcUaString>();
			discoveryUrl->value(*it);
			req->server().discoveryUrls()->push_back(discoveryUrl);
		}
		req->server().semaphoreFilePath(commandRegisterServer->semaphoreFilePath());
		req->server().isOnline(commandRegisterServer->isOnline());

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

