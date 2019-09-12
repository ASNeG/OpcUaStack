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

#include "OpcUaClient/ClientCommand/CommandBrowsePathToNodeId.h"
#include "OpcUaClient/ClientService/ClientServiceBrowsePathToNodeId.h"

using namespace OpcUaStackCore;
using namespace OpcUaStackClient;

namespace OpcUaClient
{

	ClientServiceBrowsePathToNodeId::ClientServiceBrowsePathToNodeId(void)
	: ClientServiceBase()
	{
	}

	ClientServiceBrowsePathToNodeId::~ClientServiceBrowsePathToNodeId(void)
	{
	}

	ClientServiceBase::SPtr
	ClientServiceBrowsePathToNodeId::createClientService(void)
	{
		return boost::make_shared<ClientServiceBrowsePathToNodeId>();
	}

	bool
	ClientServiceBrowsePathToNodeId::run(ClientServiceManager& clientServiceManager, CommandBase::SPtr& commandBase)
	{
		OpcUaStatusCode statusCode;
		CommandBrowsePathToNodeId::SPtr commandBrowsePathToNodeId = boost::static_pointer_cast<CommandBrowsePathToNodeId>(commandBase);

		// create new or get existing client object
		ClientAccessObject::SPtr clientAccessObject;
		clientAccessObject = clientServiceManager.getClientAccessObject(commandBrowsePathToNodeId->session());
		if (clientAccessObject.get() == nullptr) {
			std::stringstream ss;
			ss << "get client access object failed:"
			   << " Session=" << commandBrowsePathToNodeId->session();
			errorMessage(ss.str());
			return false;
		}

		// check session
		if (clientAccessObject->sessionService_.get() == nullptr) {
			std::stringstream ss;
			ss << "session object not exist: "
			   << " Session=" << commandBrowsePathToNodeId->session();
			return false;
		}

		// get or create view service
		ViewService::SPtr viewService;
		viewService = clientAccessObject->getOrCreateViewService();
		if (viewService.get() == nullptr) {
			std::stringstream ss;
			ss << "get client view service failed"
			   << " Session=" << commandBrowsePathToNodeId->session();
			errorMessage(ss.str());
			return false;
		}

		// create browse path to node id request
		ServiceTransactionTranslateBrowsePathsToNodeIds::SPtr trx;
		trx = boost::make_shared<ServiceTransactionTranslateBrowsePathsToNodeIds>();
		TranslateBrowsePathsToNodeIdsRequest::SPtr req = trx->request();
		req->browsePaths()->resize(1);

		BrowsePath::SPtr browsePath;
		browsePath = boost::make_shared<BrowsePath>();
		req->browsePaths()->push_back(browsePath);
		browsePath->startingNode(commandBrowsePathToNodeId->nodeId());

		std::vector<OpcUaQualifiedName>::iterator it;
		browsePath->relativePath().elements().resize(commandBrowsePathToNodeId->browseNameVec().size());
		for (it = commandBrowsePathToNodeId->browseNameVec().begin();
			 it != commandBrowsePathToNodeId->browseNameVec().end();
			 it++)
		{
			RelativePathElement::SPtr element;
			element = boost::make_shared<RelativePathElement>();
			browsePath->relativePath().elements().push_back(element);
			element->targetName() = *it;
		}

		// send browse name to node id request
		viewService->syncSend(trx);

		// process read response
		statusCode = trx->statusCode();
		if (statusCode != Success) {
			std::stringstream ss;
			ss << "browse path to node id error: "
			   << " Session=" << commandBrowsePathToNodeId->session()
			   << " StatusCode=" << OpcUaStatusCodeMap::shortString(statusCode);
			errorMessage(ss.str());
			return false;
		}

		TranslateBrowsePathsToNodeIdsResponse::SPtr res = trx->response();
		if (res->results()->size() != 1) {
			std::stringstream ss;
			ss << "browse path to node id response length error: "
			   << " Session=" << commandBrowsePathToNodeId->session();
			errorMessage(ss.str());
			return false;
		}

		BrowsePathResult::SPtr browsePathResult;
		if (!res->results()->get(0, browsePathResult)) {
			std::stringstream ss;
			ss << "browse path to node id response error: "
			   << " Session=" << commandBrowsePathToNodeId->session();
			errorMessage(ss.str());
			return false;
		}

		if (browsePathResult->statusCode() != Success) {
			std::cout << OpcUaStatusCodeMap::shortString(browsePathResult->statusCode()) << std::endl;
			return true;
		}

		if (browsePathResult->targets()->size() != 1) {
			std::stringstream ss;
			ss << "browse path result target response length error: "
			   << " Session=" << commandBrowsePathToNodeId->session();
			errorMessage(ss.str());
			return false;
		}

		BrowsePathTarget::SPtr browsePathTarget;
		if (!browsePathResult->targets()->get(0, browsePathTarget)) {
			std::stringstream ss;
			ss << "browse path target response error: "
			   << " Session=" << commandBrowsePathToNodeId->session();
			errorMessage(ss.str());
			return false;
		}

		std::cout << browsePathTarget->targetId()->toString() << std::endl;

		return true;
	}

}

