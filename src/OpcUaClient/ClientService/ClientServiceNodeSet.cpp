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
#include "OpcUaStackCore/Base/Log.h"
#include "OpcUaClient/ClientCommand/CommandNodeSet.h"
#include "OpcUaClient/ClientService/ClientServiceNodeSet.h"

using namespace OpcUaStackCore;

namespace OpcUaClient
{

	ClientServiceNodeSet::ClientServiceNodeSet(void)
	: ClientServiceBase()
	, browseCompleted_()
	, attributeService_()
	{
	}

	ClientServiceNodeSet::~ClientServiceNodeSet(void)
	{
	}

	ClientServiceBase::SPtr
	ClientServiceNodeSet::createClientService(void)
	{
		return constructSPtr<ClientServiceNodeSet>();
	}

	bool
	ClientServiceNodeSet::run(ClientServiceManager& clientServiceManager, CommandBase::SPtr& commandBase)
	{
		OpcUaStatusCode statusCode;
		CommandNodeSet::SPtr commandNodeSet = boost::static_pointer_cast<CommandNodeSet>(commandBase);

		// create new or get existing client object
		ClientAccessObject::SPtr clientAccessObject;
		clientAccessObject = clientServiceManager.getClientAccessObject(commandNodeSet->session());
		if (clientAccessObject.get() == nullptr) {
			std::stringstream ss;
			ss << "get client access object failed:"
			   << " Session=" << commandNodeSet->session();
			errorMessage(ss.str());
			return false;
		}

		// check session
		if (clientAccessObject->sessionService_.get() == nullptr) {
			std::stringstream ss;
			ss << "session object not exist: "
			   << " Session=" << commandNodeSet->session();
			return false;
		}

		// get or create attribute service
		attributeService_ = clientAccessObject->getOrCreateAttributeService();
		if (attributeService_.get() == nullptr) {
			std::stringstream ss;
			ss << "get client attribute service failed"
			   << " Session=" << commandNodeSet->session();
			errorMessage(ss.str());
			return false;
		}

		// get or create view service
		ViewService::SPtr viewService;
		viewService = clientAccessObject->createViewService();
		if (viewService.get() == nullptr) {
			std::stringstream ss;
			ss << "get client view service failed"
			   << " Session=" << commandNodeSet->session();
			errorMessage(ss.str());
			return false;
		}

		// browse opc ua server information model
		OpcUaNodeId::Vec nodeIdVec;
		OpcUaNodeId::SPtr nodeId = constructSPtr<OpcUaNodeId>();
		nodeId->copyFrom(commandNodeSet->nodeId());
		nodeIdVec.push_back(nodeId);
		commandNodeSet->validateCommand();
		std::cout << "XXXX" << commandNodeSet->nodeId().toString() << std::endl;
		std::cout << "XXXX" << nodeId->toString() << std::endl;

		ViewServiceBrowse viewServiceBrowse;
		viewServiceBrowse.viewService(viewService);
		viewServiceBrowse.nodeIdVec(nodeIdVec);
		viewServiceBrowse.recursive(true);
		viewServiceBrowse.viewServiceBrowseIf(this);
		viewServiceBrowse.asyncBrowse();

		// wait for the end of the browse command
		browseCompleted_.waitForCondition();

		return true;
	}

	void
	ClientServiceNodeSet::done(OpcUaStatusCode statusCode)
	{
		browseCompleted_.conditionTrue();
		std::cout << OpcUaStatusCodeMap::shortString(statusCode) << std::endl;
	}

	void
	ClientServiceNodeSet::browseResult(
		OpcUaStatusCode statusCode,
		OpcUaNodeId::SPtr& nodeId,
		ReferenceDescription::Vec& referenceDescriptionVec
	)
	{
		// check status code
		if (statusCode != Success) {
			Log(Error, "browse result node error")
				.parameter("NodeId", nodeId->toString())
				.parameter("StatusCode", OpcUaStatusCodeMap::shortString(statusCode));
			return;
		}

		std::cout << "browseResult.." << std::endl;
	}

}

