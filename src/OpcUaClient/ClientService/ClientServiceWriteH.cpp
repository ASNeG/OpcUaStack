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
#include "OpcUaStackCore/ServiceSet/UpdateStructureDataDetails.h"
#include "OpcUaStackCore/ServiceSet/HistoryData.h"
#include "OpcUaClient/ClientCommand/CommandWriteH.h"
#include "OpcUaClient/ClientService/ClientServiceWriteH.h"

#define MAXValuesPerRequest		1000

using namespace OpcUaStackCore;

namespace OpcUaClient
{

	ClientServiceWriteH::ClientServiceWriteH(void)
	: ClientServiceBase()
	{
	}

	ClientServiceWriteH::~ClientServiceWriteH(void)
	{
	}

	ClientServiceBase::SPtr
	ClientServiceWriteH::createClientService(void)
	{
		return constructSPtr<ClientServiceWriteH>();
	}

	bool
	ClientServiceWriteH::run(ClientServiceManager& clientServiceManager, CommandBase::SPtr& commandBase)
	{
		OpcUaStatusCode statusCode;
		CommandWriteH::SPtr commandWriteH = boost::static_pointer_cast<CommandWriteH>(commandBase);

		// create new or get existing client object
		ClientAccessObject::SPtr clientAccessObject;
		clientAccessObject = clientServiceManager.getClientAccessObject(commandWriteH->session());
		if (clientAccessObject.get() == nullptr) {
			std::stringstream ss;
			ss << "get client access object failed:"
			   << " Session=" << commandWriteH->session();
			errorMessage(ss.str());
			return false;
		}

		// check session
		if (clientAccessObject->sessionService_.get() == nullptr) {
			std::stringstream ss;
			ss << "session object not exist: "
			   << " Session=" << commandWriteH->session();
			return false;
		}

		// get or create attribute service
		AttributeService::SPtr attributeService;
		attributeService = clientAccessObject->getOrCreateAttributeService();
		if (attributeService.get() == nullptr) {
			std::stringstream ss;
			ss << "get client attribute service failed"
			   << " Session=" << commandWriteH->session();
			errorMessage(ss.str());
			return false;
		}

		return write(attributeService, commandWriteH);
	}


	bool
	ClientServiceWriteH::write(
		AttributeService::SPtr& attributeService,
		CommandWriteH::SPtr& commandWriteH
	)
	{
		OpcUaStatusCode statusCode;

		// create update request
		ServiceTransactionHistoryUpdate::SPtr trx;
		trx = constructSPtr<ServiceTransactionHistoryUpdate>();
		HistoryUpdateRequest::SPtr req = trx->request();

		req->historyUpdateDetails()->resize(1);
		ExtensibleParameter::SPtr extensibleParameter = constructSPtr<ExtensibleParameter>();
		req->historyUpdateDetails()->push_back(extensibleParameter);

		UpdateStructureDataDetails::SPtr updateDetails;
		extensibleParameter->parameterTypeId().set((OpcUaUInt32)OpcUaId_UpdateStructureDataDetails_Encoding_DefaultBinary);
		updateDetails = extensibleParameter->parameter<UpdateStructureDataDetails>();

		updateDetails->nodeId(commandWriteH->nodeId());
		updateDetails->performInsertReplace(PerformUpdateEnumeration_Insert);

		updateDetails->updateValue()->resize(commandWriteH->dataValueVec().size());
		for (uint32_t idx=0; idx<commandWriteH->dataValueVec().size(); idx++) {
			updateDetails->updateValue()->push_back(commandWriteH->dataValueVec()[idx]);
		}

		// send read history request
		attributeService->syncSend(trx);

		// process read response
		statusCode = trx->statusCode();
		if (statusCode != Success) {
			std::stringstream ss;
			ss << "write history error: "
			   << " Session=" << commandWriteH->session()
			   << " StatusCode=" << OpcUaStatusCodeMap::shortString(statusCode);
			errorMessage(ss.str());
			return false;
		}

		HistoryUpdateResponse::SPtr res = trx->response();
		if (res->results()->size() != 1) {
			std::stringstream ss;
			ss << "write history response length error: "
			   << " Session=" << commandWriteH->session();
			errorMessage(ss.str());
			return false;
		}

		HistoryUpdateResult::SPtr historyUpdateResult;
		res->results()->get(0, historyUpdateResult);
		if (historyUpdateResult->statusCode() != Success) {
			std::stringstream ss;
			ss << "write history result error: "
			   << " Session=" << commandWriteH->session()
			   << " StatusCode=" << OpcUaStatusCodeMap::shortString(historyUpdateResult->statusCode());
			errorMessage(ss.str());
			return false;
		}

		return true;
	}
}

