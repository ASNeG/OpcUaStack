#include "OpcUaStackServer/ServiceSet/TransactionManager.h"

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
		serviceTransactionSPtr->serviceTransactionIfService(it->second->serviceTransactionIfService());
		return serviceTransactionSPtr;
	}

}