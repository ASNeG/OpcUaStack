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

#include "OpcUaClient/ClientCommand/CommandGetEndpoint.h"
#include "OpcUaClient/ClientService/ClientServiceGetEndpoint.h"

using namespace OpcUaStackCore;
using namespace OpcUaStackClient;

namespace OpcUaClient
{

	ClientServiceGetEndpoint::ClientServiceGetEndpoint(void)
	: ClientServiceBase()
	{
	}

	ClientServiceGetEndpoint::~ClientServiceGetEndpoint(void)
	{
	}

	ClientServiceBase::SPtr
	ClientServiceGetEndpoint::createClientService(void)
	{
		return boost::make_shared<ClientServiceGetEndpoint>();
	}

	bool
	ClientServiceGetEndpoint::run(ClientServiceManager& clientServiceManager, CommandBase::SPtr& commandBase)
	{
		OpcUaStatusCode statusCode;
		CommandGetEndpoint::SPtr commandGetEndpoint = boost::static_pointer_cast<CommandGetEndpoint>(commandBase);

		// create new or get existing client object
		ClientAccessObject::SPtr clientAccessObject;
		clientAccessObject = clientServiceManager.getClientAccessObject(commandGetEndpoint->session());
		if (clientAccessObject.get() == nullptr) {
			std::stringstream ss;
			ss << "get client access object failed:"
			   << " Session=" << commandGetEndpoint->session();
			errorMessage(ss.str());
			return false;
		}

		// check session
		if (clientAccessObject->sessionService_.get() == nullptr) {
			std::stringstream ss;
			ss << "session object not exist: "
			   << " Session=" << commandGetEndpoint->session();
			return false;
		}

		// get or create discovery service
		DiscoveryService::SPtr discoveryService;
		discoveryService = clientAccessObject->getOrCreateDiscoveryService();
		if (discoveryService.get() == nullptr) {
			std::stringstream ss;
			ss << "get client discovery service failed"
			   << " Session=" << commandGetEndpoint->session();
			errorMessage(ss.str());
			return false;
		}

		// create get endpoint request
		ServiceTransactionGetEndpoints::SPtr trx;
		trx = boost::make_shared<ServiceTransactionGetEndpoints>();
		GetEndpointsRequest::SPtr req = trx->request();

		// send read request
		discoveryService->syncSend(trx);

		// process read response
		statusCode = trx->statusCode();
		if (statusCode != Success) {
			std::stringstream ss;
			ss << "discovery error: "
			   << " Session=" << commandGetEndpoint->session()
			   << " StatusCode=" << OpcUaStatusCodeMap::shortString(statusCode);
			errorMessage(ss.str());
			return false;
		}

		GetEndpointsResponse::SPtr res = trx->response();
		if (res->endpoints()->size() == 0) {
			std::stringstream ss;
			ss << "discovery response length error: "
			   << " Session=" << commandGetEndpoint->session();
			errorMessage(ss.str());
			return false;
		}

		for (uint32_t idx=0; idx<res->endpoints()->size(); idx++) {
			EndpointDescription::SPtr endpoints;
			res->endpoints()->get(idx, endpoints);
			endpoints->out(std::cout); std::cout << std::endl;
		}

		return true;
	}

}

