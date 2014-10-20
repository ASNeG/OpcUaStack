#include "OpcUaStackServer/ServiceManager/ServiceManager.h"

namespace OpcUaStackServer
{

	ServiceManager::ServiceManager(void)
	: transactionManager_(TransactionManager::construct())
	, attributeService_(AttributeService::construct())
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
		ServiceTransactionRead::name("Read");
		ServiceTransactionWrite::name("Write");
		ServiceTransactionHistoryRead::name("HistoryRead");
		ServiceTransactionHistoryUpdate::name("HistoryUpdate");

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
		// method service
		//
		ServiceTransactionCall::name("Call");

		ServiceTransactionCall::SPtr serviceTransactionCall = ServiceTransactionCall::construct();

		serviceTransactionCall->serviceTransactionIfService(&*methodService_);

		transactionManager_->registerTransaction(serviceTransactionCall);


		//
		// monitored service
		//
		ServiceTransactionCreateMonitoredItems::name("CreateMonitorItems");
		ServiceTransactionDeleteMonitoredItems::name("DeleteMonitorItems");
		ServiceTransactionModifyMonitoredItems::name("ModifyMonitorItems");
		ServiceTransactionSetMonitoringMode::name("SetMonitoringMode");
		ServiceTransactionSetTriggering::name("SetTriggering");


		ServiceTransactionCreateMonitoredItems::SPtr serviceTransactionCreateMonitoredItems = ServiceTransactionCreateMonitoredItems::construct();
		ServiceTransactionDeleteMonitoredItems::SPtr serviceTransactionDeleteMonitoredItems = ServiceTransactionDeleteMonitoredItems::construct();
		ServiceTransactionModifyMonitoredItems::SPtr serviceTransactionModifyMonitoredItems = ServiceTransactionModifyMonitoredItems::construct();
		ServiceTransactionSetMonitoringMode::SPtr serviceTransactionSetMonitoringMode = ServiceTransactionSetMonitoringMode::construct();
		ServiceTransactionSetTriggering::SPtr serviceTransactionSetTriggering = ServiceTransactionSetTriggering::construct();

		serviceTransactionCreateMonitoredItems->serviceTransactionIfService(&*monitoredItemService_);
		serviceTransactionDeleteMonitoredItems->serviceTransactionIfService(&*monitoredItemService_);
		serviceTransactionModifyMonitoredItems->serviceTransactionIfService(&*monitoredItemService_);
		serviceTransactionSetMonitoringMode->serviceTransactionIfService(&*monitoredItemService_);
		serviceTransactionSetTriggering->serviceTransactionIfService(&*monitoredItemService_);

		transactionManager_->registerTransaction(serviceTransactionCreateMonitoredItems);
		transactionManager_->registerTransaction(serviceTransactionDeleteMonitoredItems);
		transactionManager_->registerTransaction(serviceTransactionModifyMonitoredItems);
		transactionManager_->registerTransaction(serviceTransactionSetMonitoringMode);
		transactionManager_->registerTransaction(serviceTransactionSetTriggering);


		//
		// node mangement service
		//
		ServiceTransactionAddNodes::name("AddNodes");
		ServiceTransactionAddReferences::name("AddReferences");
		ServiceTransactionDeleteNodes::name("DeleteNodes");
		ServiceTransactionDeleteReferences::name("DeleteReferences");

		ServiceTransactionAddNodes::SPtr serviceTransactionAddNodes = ServiceTransactionAddNodes::construct();
		ServiceTransactionAddReferences::SPtr serviceTransactionAddReferences = ServiceTransactionAddReferences::construct();
		ServiceTransactionDeleteNodes::SPtr serviceTransactionDeleteNodes = ServiceTransactionDeleteNodes::construct();
		ServiceTransactionDeleteReferences::SPtr serviceTransactionDeleteReferences = ServiceTransactionDeleteReferences::construct();

		serviceTransactionAddNodes->serviceTransactionIfService(&*nodeManagementService_);
		serviceTransactionAddReferences->serviceTransactionIfService(&*nodeManagementService_);
		serviceTransactionDeleteNodes->serviceTransactionIfService(&*nodeManagementService_);
		serviceTransactionDeleteReferences->serviceTransactionIfService(&*nodeManagementService_);

		transactionManager_->registerTransaction(serviceTransactionAddNodes);
		transactionManager_->registerTransaction(serviceTransactionAddReferences);
		transactionManager_->registerTransaction(serviceTransactionDeleteNodes);
		transactionManager_->registerTransaction(serviceTransactionDeleteReferences);


		//
		// subscription service
		//
		ServiceTransactionCreateSubscription::name("CreateSubscription");
		ServiceTransactionDeleteSubscriptions::name("DeleteSubscription");
		ServiceTransactionModifySubscription::name("ModifySubscription");
		ServiceTransactionPublish::name("Publish");
		ServiceTransactionRepublish::name("Republish");
		ServiceTransactionSetPublishingMode::name("SetPublishingMode");
		ServiceTransactionTransferSubscriptions::name("TransferSubscription");

		ServiceTransactionCreateSubscription::SPtr serviceTransactionCreateSubscription = ServiceTransactionCreateSubscription::construct();
		ServiceTransactionDeleteSubscriptions::SPtr serviceTransactionDeleteSubscriptions = ServiceTransactionDeleteSubscriptions::construct();
		ServiceTransactionModifySubscription::SPtr serviceTransactionModifySubscription = ServiceTransactionModifySubscription::construct();
		ServiceTransactionPublish::SPtr serviceTransactionPublish = ServiceTransactionPublish::construct();
		ServiceTransactionRepublish::SPtr serviceTransactionRepublish = ServiceTransactionRepublish::construct();
		ServiceTransactionSetPublishingMode::SPtr serviceTransactionSetPublishingMode = ServiceTransactionSetPublishingMode::construct();
		ServiceTransactionTransferSubscriptions::SPtr serviceTransactionTransferSubscriptions = ServiceTransactionTransferSubscriptions::construct();

		serviceTransactionCreateSubscription->serviceTransactionIfService(&*subscriptionService_);
		serviceTransactionDeleteSubscriptions->serviceTransactionIfService(&*subscriptionService_);
		serviceTransactionModifySubscription->serviceTransactionIfService(&*subscriptionService_);
		serviceTransactionPublish->serviceTransactionIfService(&*subscriptionService_);
		serviceTransactionRepublish->serviceTransactionIfService(&*subscriptionService_);
		serviceTransactionSetPublishingMode->serviceTransactionIfService(&*subscriptionService_);
		serviceTransactionTransferSubscriptions->serviceTransactionIfService(&*subscriptionService_);

		transactionManager_->registerTransaction(serviceTransactionCreateSubscription);
		transactionManager_->registerTransaction(serviceTransactionDeleteSubscriptions);
		transactionManager_->registerTransaction(serviceTransactionModifySubscription);
		transactionManager_->registerTransaction(serviceTransactionPublish);
		transactionManager_->registerTransaction(serviceTransactionRepublish);
		transactionManager_->registerTransaction(serviceTransactionSetPublishingMode);
		transactionManager_->registerTransaction(serviceTransactionTransferSubscriptions);


		//
		// view service
		//
		ServiceTransactionBrowse::name("Browse");
		ServiceTransactionBrowseNext::name("BrowseNext");
		ServiceTransactionTranslateBrowsePathsToNodeIds::name("TranslateBrowsePathsToNodeIds");
		ServiceTransactionRegisterNodes::name("RegisterNodes");
		ServiceTransactionUnregisterNodes::name("UnregisterNodes");

		ServiceTransactionBrowse::SPtr serviceTransactionBrowse = ServiceTransactionBrowse::construct();
		ServiceTransactionBrowseNext::SPtr serviceTransactionBrowseNext = ServiceTransactionBrowseNext::construct();
		ServiceTransactionTranslateBrowsePathsToNodeIds::SPtr serviceTransactionTranslateBrowsePathsToNodeIds = ServiceTransactionTranslateBrowsePathsToNodeIds::construct();
		ServiceTransactionRegisterNodes::SPtr serviceTransactionRegisterNodes = ServiceTransactionRegisterNodes::construct();
		ServiceTransactionUnregisterNodes::SPtr serviceTransactionUnregisterNodes = ServiceTransactionUnregisterNodes::construct();

		serviceTransactionBrowse->serviceTransactionIfService(&*viewService_);
		serviceTransactionBrowseNext->serviceTransactionIfService(&*viewService_);
		serviceTransactionTranslateBrowsePathsToNodeIds->serviceTransactionIfService(&*viewService_);
		serviceTransactionRegisterNodes->serviceTransactionIfService(&*viewService_);
		serviceTransactionUnregisterNodes->serviceTransactionIfService(&*viewService_);

		transactionManager_->registerTransaction(serviceTransactionBrowse);
		transactionManager_->registerTransaction(serviceTransactionBrowseNext);
		transactionManager_->registerTransaction(serviceTransactionTranslateBrowsePathsToNodeIds);
		transactionManager_->registerTransaction(serviceTransactionRegisterNodes);
		transactionManager_->registerTransaction(serviceTransactionUnregisterNodes);
	

		sessionManager.transactionManager(transactionManager_);
		return true;
	}

	bool 
	ServiceManager::informatinModel(InformationModel::SPtr informatinModel)
	{
		attributeService_->informationModel(informatinModel);
		methodService_->informationModel(informatinModel);
		monitoredItemService_->informationModel(informatinModel);
		nodeManagementService_->informationModel(informatinModel);
		queryService_->informationModel(informatinModel);
		subscriptionService_->informationModel(informatinModel);
		viewService_->informationModel(informatinModel);
		return true;
	}

	bool 
	ServiceManager::ioService(IOService* ioService)
	{
		attributeService_->ioService(ioService);
		methodService_->ioService(ioService);
		monitoredItemService_->ioService(ioService);
		nodeManagementService_->ioService(ioService);
		queryService_->ioService(ioService);
		subscriptionService_->ioService(ioService);
		viewService_->ioService(ioService);
		return true;
	}

	void
	ServiceManager::init(void)
	{
		attributeService_->init();
		methodService_->init();
		monitoredItemService_->init();
		nodeManagementService_->init();
		queryService_->init();
		subscriptionService_->init();
		viewService_->init();
	}

}