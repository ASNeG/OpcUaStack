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

#include "OpcUaClient/ClientCommand/CommandWrite.h"
#include "OpcUaClient/ClientService/ClientServiceWrite.h"

using namespace OpcUaStackCore;
using namespace OpcUaStackClient;

namespace OpcUaClient
{

	ClientServiceWrite::ClientServiceWrite(void)
	: ClientServiceBase()
	{
	}

	ClientServiceWrite::~ClientServiceWrite(void)
	{
	}

	ClientServiceBase::SPtr
	ClientServiceWrite::createClientService(void)
	{
		return boost::make_shared<ClientServiceWrite>();
	}

	bool
	ClientServiceWrite::run(ClientServiceManager& clientServiceManager, CommandBase::SPtr& commandBase)
	{
		OpcUaStatusCode statusCode;
		CommandWrite::SPtr commandWrite = boost::static_pointer_cast<CommandWrite>(commandBase);

		// create new or get existing client object
		ClientAccessObject::SPtr clientAccessObject;
		clientAccessObject = clientServiceManager.getClientAccessObject(commandWrite->session());
		if (clientAccessObject.get() == nullptr) {
			std::stringstream ss;
			ss << "get client access object failed:"
			   << " Session=" << commandWrite->session();
			errorMessage(ss.str());
			return false;
		}

		// check session
		if (clientAccessObject->sessionService_.get() == nullptr) {
			std::stringstream ss;
			ss << "session object not exist: "
			   << " Session=" << commandWrite->session();
			return false;
		}

		// get or create attribute service
		AttributeService::SPtr attributeService;
		attributeService = clientAccessObject->getOrCreateAttributeService();
		if (attributeService.get() == nullptr) {
			std::stringstream ss;
			ss << "get client attribute service failed"
			   << " Session=" << commandWrite->session();
			errorMessage(ss.str());
			return false;
		}

		// create read request
		ServiceTransactionWrite::SPtr trx;
		trx = boost::make_shared<ServiceTransactionWrite>();
		WriteRequest::SPtr req = trx->request();
		req->writeValueArray()->resize(commandWrite->nodeIdVec().size());
		for (uint32_t idx=0; idx<commandWrite->nodeIdVec().size(); idx++) {
			WriteValue::SPtr writeValue = boost::make_shared<WriteValue>();
			writeValue->nodeId()->copyFrom(*commandWrite->nodeIdVec()[idx]);
			writeValue->attributeId(commandWrite->attributeIdVec()[idx]);
			writeValue->dataValue().copyFrom(*commandWrite->dataValueVec()[idx]);
			req->writeValueArray()->push_back(writeValue);
		}

		// send read request
		attributeService->syncSend(trx);

		// process read response
		statusCode = trx->statusCode();
		if (statusCode != Success) {
			std::stringstream ss;
			ss << "read error: "
			   << " Session=" << commandWrite->session()
			   << " StatusCode=" << OpcUaStatusCodeMap::shortString(statusCode);
			errorMessage(ss.str());
			return false;
		}

		WriteResponse::SPtr res = trx->response();
		if (res->results()->size() == 0) {
			std::stringstream ss;
			ss << "write response length error: "
			   << " Session=" << commandWrite->session();
			errorMessage(ss.str());
			return false;
		}

		for (uint32_t idx=0; idx<res->results()->size(); idx++) {
			OpcUaStatusCode statusCode;
			res->results()->get(idx, statusCode);
			std::cout << OpcUaStatusCodeMap::shortString(statusCode) << std::endl;
		}

		return true;
	}

}

