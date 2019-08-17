/*
   Copyright 2015-2019 Kai Huebl (kai@huebl-sgh.de)

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

	bool 
	TransactionManager::registerTransaction(ServiceTransaction::SPtr serviceTransactionSPtr)
	{
		ServiceTransactionMap::iterator it;
		OpcUaNodeId typeIdRequest = serviceTransactionSPtr->nodeTypeRequest();
		OpcUaNodeId typeIdResponse = serviceTransactionSPtr->nodeTypeResponse();

		it = serviceTransactionMap_.find(typeIdRequest);
		if (it != serviceTransactionMap_.end()) {
			return false;
		}

		it = serviceTransactionMap_.find(typeIdResponse);
		if (it != serviceTransactionMap_.end()) {
			return false;
		}

		serviceTransactionMap_.insert(std::make_pair(typeIdRequest, serviceTransactionSPtr));
		serviceTransactionMap_.insert(std::make_pair(typeIdResponse, serviceTransactionSPtr));
		return false;
	}
		
	ServiceTransaction::SPtr 
	TransactionManager::getTransaction(OpcUaNodeId& typeId)
	{
		ServiceTransaction::SPtr serviceTransactionSPtr;

		ServiceTransactionMap::iterator it;
		it = serviceTransactionMap_.find(typeId);
		if (it == serviceTransactionMap_.end()) {
			return serviceTransactionSPtr;
		}

		serviceTransactionSPtr = it->second->constructTransaction();
		serviceTransactionSPtr->componentService(it->second->componentService());
		return serviceTransactionSPtr;
	}

}
