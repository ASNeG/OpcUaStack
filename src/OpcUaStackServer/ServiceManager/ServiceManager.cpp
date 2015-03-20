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
	, applicationService_(ApplicationService::construct())
	{
		attributeService_->componentName("AttributeService");
		methodService_->componentName("MethodService");
		monitoredItemService_->componentName("MonitoredItemService");
		nodeManagementService_->componentName("NodeManagementService");
		queryService_->componentName("QueryService");
		subscriptionService_->componentName("SubscriptionService");
		viewService_->componentName("ViewService");
		applicationService_->componentName("ApplicationService");
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

		serviceTransactionRead->componentService(&*attributeService_);
		serviceTransactionWrite->componentService(&*attributeService_);
		serviceTransactionHistoryRead->componentService(&*attributeService_);
		serviceTransactionHistoryUpdate->componentService(&*attributeService_);

		transactionManager_->registerTransaction(serviceTransactionRead);
		transactionManager_->registerTransaction(serviceTransactionWrite);
		transactionManager_->registerTransaction(serviceTransactionHistoryRead);
		transactionManager_->registerTransaction(serviceTransactionHistoryUpdate);


		//
		// method service
		//
		ServiceTransactionCall::name("Call");

		ServiceTransactionCall::SPtr serviceTransactionCall = ServiceTransactionCall::construct();

		serviceTransactionCall->componentService(&*methodService_);

		transactionManager_->registerTransaction(serviceTransactionCall);


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

		serviceTransactionAddNodes->componentService(&*nodeManagementService_);
		serviceTransactionAddReferences->componentService(&*nodeManagementService_);
		serviceTransactionDeleteNodes->componentService(&*nodeManagementService_);
		serviceTransactionDeleteReferences->componentService(&*nodeManagementService_);

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

		serviceTransactionCreateSubscription->componentService(&*subscriptionService_);
		serviceTransactionDeleteSubscriptions->componentService(&*subscriptionService_);
		serviceTransactionModifySubscription->componentService(&*subscriptionService_);
		serviceTransactionPublish->componentService(&*subscriptionService_);
		serviceTransactionRepublish->componentService(&*subscriptionService_);
		serviceTransactionSetPublishingMode->componentService(&*subscriptionService_);
		serviceTransactionTransferSubscriptions->componentService(&*subscriptionService_);

		transactionManager_->registerTransaction(serviceTransactionCreateSubscription);
		transactionManager_->registerTransaction(serviceTransactionDeleteSubscriptions);
		transactionManager_->registerTransaction(serviceTransactionModifySubscription);
		transactionManager_->registerTransaction(serviceTransactionPublish);
		transactionManager_->registerTransaction(serviceTransactionRepublish);
		transactionManager_->registerTransaction(serviceTransactionSetPublishingMode);
		transactionManager_->registerTransaction(serviceTransactionTransferSubscriptions);


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

		serviceTransactionCreateMonitoredItems->componentService(&*subscriptionService_);
		serviceTransactionDeleteMonitoredItems->componentService(&*subscriptionService_);
		serviceTransactionModifyMonitoredItems->componentService(&*subscriptionService_);
		serviceTransactionSetMonitoringMode->componentService(&*subscriptionService_);
		serviceTransactionSetTriggering->componentService(&*subscriptionService_);

		transactionManager_->registerTransaction(serviceTransactionCreateMonitoredItems);
		transactionManager_->registerTransaction(serviceTransactionDeleteMonitoredItems);
		transactionManager_->registerTransaction(serviceTransactionModifyMonitoredItems);
		transactionManager_->registerTransaction(serviceTransactionSetMonitoringMode);
		transactionManager_->registerTransaction(serviceTransactionSetTriggering);


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

		serviceTransactionBrowse->componentService(&*viewService_);
		serviceTransactionBrowseNext->componentService(&*viewService_);
		serviceTransactionTranslateBrowsePathsToNodeIds->componentService(&*viewService_);
		serviceTransactionRegisterNodes->componentService(&*viewService_);
		serviceTransactionUnregisterNodes->componentService(&*viewService_);

		transactionManager_->registerTransaction(serviceTransactionBrowse);
		transactionManager_->registerTransaction(serviceTransactionBrowseNext);
		transactionManager_->registerTransaction(serviceTransactionTranslateBrowsePathsToNodeIds);
		transactionManager_->registerTransaction(serviceTransactionRegisterNodes);
		transactionManager_->registerTransaction(serviceTransactionUnregisterNodes);

		//
		// application service
		//
		ServiceTransactionRegisterForward::name("RegisterForward");

		ServiceTransactionRegisterForward::SPtr serviceTransactionRegisterForward = ServiceTransactionRegisterForward::construct();

		serviceTransactionRegisterForward->componentService(&*applicationService_);

		transactionManager_->registerTransaction(serviceTransactionRegisterForward);
	

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

	bool
	ServiceManager::init(void)
	{
		bool rc = true;
		rc = rc && attributeService_->init();
		rc = rc && methodService_->init();
		rc = rc && monitoredItemService_->init();
		rc = rc && nodeManagementService_->init();
		rc = rc && queryService_->init();
		rc = rc && subscriptionService_->init();
		rc = rc && viewService_->init();
		return rc;
	}

}
