/*
   Copyright 2015-2021 Kai Huebl (kai@huebl-sgh.de)

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

#include "OpcUaStackServer/ServiceSet/TransactionManager.h"

using namespace OpcUaStackCore;

namespace OpcUaStackServer
{

	TransactionManager::TransactionManager(void)
	: serviceTransactionMap_()
	{
	}

	TransactionManager::~TransactionManager(void)
	{
	}

	void
	TransactionManager::clear(void)
	{
		serviceTransactionMap_.clear();
	}

	bool 
	TransactionManager::registerTransaction(ServiceTransaction::SPtr serviceTransactionSPtr)
	{
		auto typeIdRequest = serviceTransactionSPtr->nodeTypeRequest();
		auto typeIdResponse = serviceTransactionSPtr->nodeTypeResponse();

		auto it = serviceTransactionMap_.find(typeIdRequest);
		if (it != serviceTransactionMap_.end()) {
			Log(Error, "register transaction error, because request type already exist")
				.parameter("TypeIdRequest", typeIdRequest);
			return false;
		}

		it = serviceTransactionMap_.find(typeIdResponse);
		if (it != serviceTransactionMap_.end()) {
			Log(Error, "register transaction error, because response type already exist")
				.parameter("TypeIdResponse", typeIdResponse);
			return false;
		}

		serviceTransactionMap_.insert(std::make_pair(typeIdRequest, serviceTransactionSPtr));
		serviceTransactionMap_.insert(std::make_pair(typeIdResponse, serviceTransactionSPtr));
		return true;
	}

	OpcUaStackCore::ServiceTransaction::SPtr
	TransactionManager::getTransaction(uint32_t typeId)
	{
		return getTransaction(OpcUaNodeId(typeId));
	}
		
	ServiceTransaction::SPtr 
	TransactionManager::getTransaction(const OpcUaNodeId& typeId)
	{
		ServiceTransaction::SPtr serviceTransactionSPtr;

		auto it = serviceTransactionMap_.find(typeId);
		if (it == serviceTransactionMap_.end()) {
			Log(Error, "get transaction error, because no transaction exist")
				.parameter("TypeId", typeId);
			return serviceTransactionSPtr;
		}

		serviceTransactionSPtr = it->second->constructTransaction();
		serviceTransactionSPtr->memberService(it->second->memberService());
		return serviceTransactionSPtr;
	}

}
