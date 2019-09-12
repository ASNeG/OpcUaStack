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

#include "OpcUaClient/ClientCommand/CommandBrowse.h"
#include "OpcUaClient/ClientService/ClientServiceBrowse.h"

using namespace OpcUaStackCore;
using namespace OpcUaStackClient;

namespace OpcUaClient
{

	ClientServiceBrowse::ClientServiceBrowse(void)
	: ClientServiceBase()
	, browseCompleted_()
	{
	}

	ClientServiceBrowse::~ClientServiceBrowse(void)
	{
	}

	ClientServiceBase::SPtr
	ClientServiceBrowse::createClientService(void)
	{
		return boost::make_shared<ClientServiceBrowse>();
	}

	bool
	ClientServiceBrowse::run(ClientServiceManager& clientServiceManager, CommandBase::SPtr& commandBase)
	{
		OpcUaStatusCode statusCode;
		CommandBrowse::SPtr commandBrowse = boost::static_pointer_cast<CommandBrowse>(commandBase);

		auto future = browseCompleted_.get_future();

		// create new or get existing client object
		ClientAccessObject::SPtr clientAccessObject;
		clientAccessObject = clientServiceManager.getClientAccessObject(commandBrowse->session());
		if (clientAccessObject.get() == nullptr) {
			std::stringstream ss;
			ss << "get client access object failed:"
			   << " Session=" << commandBrowse->session();
			errorMessage(ss.str());
			return false;
		}

		// check session
		if (clientAccessObject->sessionService_.get() == nullptr) {
			std::stringstream ss;
			ss << "session object not exist: "
			   << " Session=" << commandBrowse->session();
			return false;
		}

		// get or create view service
		ViewService::SPtr viewService;
		viewService = clientAccessObject->createViewService();
		if (viewService.get() == nullptr) {
			std::stringstream ss;
			ss << "get client view service failed"
			   << " Session=" << commandBrowse->session();
			errorMessage(ss.str());
			return false;
		}

		// browse opc ua server information model
		ViewServiceBrowse viewServiceBrowse;
		viewServiceBrowse.viewService(viewService);
		viewServiceBrowse.nodeIdVec(commandBrowse->nodeIdVec());
		viewServiceBrowse.direction(commandBrowse->direction());
		viewServiceBrowse.recursive(commandBrowse->recursive());
		viewServiceBrowse.viewServiceBrowseIf(this);
		viewServiceBrowse.asyncBrowse();

		// wait for the end of the browse command
		future.wait();

		return true;
	}

	void
	ClientServiceBrowse::viewServiceBrowseDone(OpcUaStatusCode statusCode)
	{
		browseCompleted_.set_value(true);
		std::cout << OpcUaStatusCodeMap::shortString(statusCode) << std::endl;
	}

	void
	ClientServiceBrowse::viewServiceBrowseResult(
		OpcUaStatusCode statusCode,
		OpcUaNodeId::SPtr& nodeId,
		ReferenceDescription::Vec& referenceDescriptionVec
	)
	{
		std::cout << nodeId->toString() << " " << OpcUaStatusCodeMap::shortString(statusCode) << std::endl;

		ReferenceDescription::Vec::iterator it;
		for (it = referenceDescriptionVec.begin(); it != referenceDescriptionVec.end(); it++) {
			ReferenceDescription::SPtr referenceDescription = *it;

			std::cout << "   "
				<< " " << referenceDescription->nodeClass()
				<< " " << referenceDescription->expandedNodeId()->toString()
				<< " " << referenceDescription->typeDefinition()->toString()
				<< " " << referenceDescription->referenceTypeId()->toString()
				<< " " << (referenceDescription->isForward() == 0x01 ? "true" : "true")
				<< " " << referenceDescription->displayName().toString()
				<< " " << referenceDescription->browseName().toString()
				<< std::endl;
		}
	}

}

