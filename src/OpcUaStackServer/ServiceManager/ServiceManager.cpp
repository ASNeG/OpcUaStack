#include "OpcUaStackServer/ServiceManager/ServiceManager.h"

namespace OpcUaStackServer
{

	ServiceManager::ServiceManager(void)
	: transactionManager_(TransactionManager::construct())
	, attributeService_(AttributeService::construct())
	, discoveryService_(DiscoveryService::construct())
	, methodService_(MethodService::construct())
	, monitoredItemService_(MonitoredItemService::construct())
	, nodeManagementService_(NodeManagementService::construct())
	, queryService_(QueryService::construct())
	, subscriptionService_(SubscriptionService::construct())
	, viewService_(ViewService::construct())
	{
	}

	ServiceManager::~ServiceManager(void)
	{
	}

	bool
	ServiceManager::init(SessionManager& sessionManager)
	{
		//
		// attribute service
		//
		ServiceTransactionRead::SPtr serviceTransactionRead = ServiceTransactionRead::construct();
		ServiceTransactionWrite::SPtr serviceTransactionWrite = ServiceTransactionWrite::construct();
		ServiceTransactionHistoryRead::SPtr serviceTransactionHistoryRead = ServiceTransactionHistoryRead::construct();
		ServiceTransactionHistoryUpdate::SPtr serviceTransactionHistoryUpdate = ServiceTransactionHistoryUpdate::construct();

		serviceTransactionRead->serviceTransactionIfService(&*attributeService_);
		serviceTransactionWrite->serviceTransactionIfService(&*attributeService_);
		serviceTransactionHistoryRead->serviceTransactionIfService(&*attributeService_);
		serviceTransactionHistoryUpdate->serviceTransactionIfService(&*attributeService_);

		transactionManager_->registerTransaction(serviceTransactionRead);
		transactionManager_->registerTransaction(serviceTransactionWrite);
		transactionManager_->registerTransaction(serviceTransactionHistoryRead);
		transactionManager_->registerTransaction(serviceTransactionHistoryUpdate);

		//
		// discovery service
		//

		sessionManager.transactionManager(transactionManager_);
		return true;
	}

#if 0

	

		DiscoveryService::SPtr discoveryService_;
		MethodService::SPtr methodService_;
		MonitoredItemService::SPtr monitoredItemService_;
		NodeManagementService::SPtr nodeManagementService_;
		QueryService::SPtr queryService_;
		SubscriptionService::SPtr subscriptionService_;
		ViewService::SPtr viewService_;

#endif

}