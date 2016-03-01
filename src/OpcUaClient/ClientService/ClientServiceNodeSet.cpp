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
#include "OpcUaClient/ClientCommand/CommandNodeSet.h"
#include "OpcUaClient/ClientService/ClientServiceNodeSet.h"

using namespace OpcUaStackCore;

namespace OpcUaClient
{

	ClientServiceNodeSet::ClientServiceNodeSet(void)
	: ClientServiceBase()
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

#if 0
		// get or create attribute service
		AttributeService::SPtr attributeService;
		attributeService = clientAccessObject->getOrCreateAttributeService();
		if (attributeService.get() == nullptr) {
			std::stringstream ss;
			ss << "get client attribute service failed"
			   << " Session=" << commandNodeSet->session();
			errorMessage(ss.str());
			return false;
		}

		// create read request
		ServiceTransactionRead::SPtr trx;
		trx = constructSPtr<ServiceTransactionRead>();
		ReadRequest::SPtr req = trx->request();
		req->readValueIdArray()->resize(commandNodeSet->nodeIdVec().size());
		for (uint32_t idx=0; idx<commandNodeSet->nodeIdVec().size(); idx++) {
			ReadValueId::SPtr readValueIdSPtr = ReadValueId::construct();
			readValueIdSPtr->nodeId()->copyFrom(*commandNodeSet->nodeIdVec()[idx]);
			readValueIdSPtr->attributeId(commandNodeSet->attributeIdVec()[idx]);
			readValueIdSPtr->dataEncoding().namespaceIndex((OpcUaInt16) 0);
			req->readValueIdArray()->push_back(readValueIdSPtr);
		}

		// send read request
		attributeService->syncSend(trx);

		// process read response
		statusCode = trx->statusCode();
		if (statusCode != Success) {
			std::stringstream ss;
			ss << "read error: "
			   << " Session=" << commandNodeSet->session()
			   << " StatusCode=" << OpcUaStatusCodeMap::shortString(statusCode);
			errorMessage(ss.str());
			return false;
		}

		ReadResponse::SPtr res = trx->response();
		if (res->dataValueArray()->size() == 0) {
			std::stringstream ss;
			ss << "read response length error: "
			   << " Session=" << commandNodeSet->session();
			errorMessage(ss.str());
			return false;
		}

		for (uint32_t idx=0; idx<res->dataValueArray()->size(); idx++) {
			OpcUaDataValue::SPtr dataValue;
			res->dataValueArray()->get(idx, dataValue);
			dataValue->out(std::cout); std::cout << std::endl;
		}
#endif

		return true;
	}

}

