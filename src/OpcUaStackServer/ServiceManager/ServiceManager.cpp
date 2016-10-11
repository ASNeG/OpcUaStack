/*
   Copyright 2015 Kai Huebl (kai@huebl-sgh.de)

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

#include "OpcUaStackServer/ServiceManager/ServiceManager.h"

namespace OpcUaStackServer
{

	ServiceManager::ServiceManager(void)
	: transactionManager_(constructSPtr<TransactionManager>())
	, attributeService_(constructSPtr<AttributeService>())
	, methodService_(constructSPtr<MethodService>())
	, monitoredItemService_(constructSPtr<MonitoredItemService>())
	, nodeManagementService_(constructSPtr<NodeManagementService>())
	, queryService_(constructSPtr<QueryService>())
	, subscriptionService_(constructSPtr<SubscriptionService>())
	, viewService_(constructSPtr<ViewService>())
	, applicationService_(constructSPtr<ApplicationService>())
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
	ServiceManager::init(SessionManagerOld& sessionManager)
	{
		//
		// attribute service
		//
		ServiceTransactionRead::name("Read");
		ServiceTransactionWrite::name("Write");
		ServiceTransactionHistoryRead::name("HistoryRead");
		ServiceTransactionHistoryUpdate::name("HistoryUpdate");

		ServiceTransactionRead::SPtr serviceTransactionRead = constructSPtr<ServiceTransactionRead>();
		ServiceTransactionWrite::SPtr serviceTransactionWrite = constructSPtr<ServiceTransactionWrite>();
		ServiceTransactionHistoryRead::SPtr serviceTransactionHistoryRead = constructSPtr<ServiceTransactionHistoryRead>();
		ServiceTransactionHistoryUpdate::SPtr serviceTransactionHistoryUpdate = constructSPtr<ServiceTransactionHistoryUpdate>();

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

		ServiceTransactionCall::SPtr serviceTransactionCall = constructSPtr<ServiceTransactionCall>();

		serviceTransactionCall->componentService(&*methodService_);

		transactionManager_->registerTransaction(serviceTransactionCall);


		//
		// node mangement service
		//
		ServiceTransactionAddNodes::name("AddNodes");
		ServiceTransactionAddReferences::name("AddReferences");
		ServiceTransactionDeleteNodes::name("DeleteNodes");
		ServiceTransactionDeleteReferences::name("DeleteReferences");

		ServiceTransactionAddNodes::SPtr serviceTransactionAddNodes = constructSPtr<ServiceTransactionAddNodes>();
		ServiceTransactionAddReferences::SPtr serviceTransactionAddReferences = constructSPtr<ServiceTransactionAddReferences>();
		ServiceTransactionDeleteNodes::SPtr serviceTransactionDeleteNodes = constructSPtr<ServiceTransactionDeleteNodes>();
		ServiceTransactionDeleteReferences::SPtr serviceTransactionDeleteReferences = constructSPtr<ServiceTransactionDeleteReferences>();

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

		ServiceTransactionCreateSubscription::SPtr serviceTransactionCreateSubscription = constructSPtr<ServiceTransactionCreateSubscription>();
		ServiceTransactionDeleteSubscriptions::SPtr serviceTransactionDeleteSubscriptions = constructSPtr<ServiceTransactionDeleteSubscriptions>();
		ServiceTransactionModifySubscription::SPtr serviceTransactionModifySubscription = constructSPtr<ServiceTransactionModifySubscription>();
		ServiceTransactionPublish::SPtr serviceTransactionPublish = constructSPtr<ServiceTransactionPublish>();
		ServiceTransactionRepublish::SPtr serviceTransactionRepublish = constructSPtr<ServiceTransactionRepublish>();
		ServiceTransactionSetPublishingMode::SPtr serviceTransactionSetPublishingMode = constructSPtr<ServiceTransactionSetPublishingMode>();
		ServiceTransactionTransferSubscriptions::SPtr serviceTransactionTransferSubscriptions = constructSPtr<ServiceTransactionTransferSubscriptions>();

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


		ServiceTransactionCreateMonitoredItems::SPtr serviceTransactionCreateMonitoredItems = constructSPtr<ServiceTransactionCreateMonitoredItems>();
		ServiceTransactionDeleteMonitoredItems::SPtr serviceTransactionDeleteMonitoredItems = constructSPtr<ServiceTransactionDeleteMonitoredItems>();
		ServiceTransactionModifyMonitoredItems::SPtr serviceTransactionModifyMonitoredItems = constructSPtr<ServiceTransactionModifyMonitoredItems>();
		ServiceTransactionSetMonitoringMode::SPtr serviceTransactionSetMonitoringMode = constructSPtr<ServiceTransactionSetMonitoringMode>();
		ServiceTransactionSetTriggering::SPtr serviceTransactionSetTriggering = constructSPtr<ServiceTransactionSetTriggering>();

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

		ServiceTransactionBrowse::SPtr serviceTransactionBrowse = constructSPtr<ServiceTransactionBrowse>();
		ServiceTransactionBrowseNext::SPtr serviceTransactionBrowseNext = constructSPtr<ServiceTransactionBrowseNext>();
		ServiceTransactionTranslateBrowsePathsToNodeIds::SPtr serviceTransactionTranslateBrowsePathsToNodeIds = constructSPtr<ServiceTransactionTranslateBrowsePathsToNodeIds>();
		ServiceTransactionRegisterNodes::SPtr serviceTransactionRegisterNodes = constructSPtr<ServiceTransactionRegisterNodes>();
		ServiceTransactionUnregisterNodes::SPtr serviceTransactionUnregisterNodes = constructSPtr<ServiceTransactionUnregisterNodes>();

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

		ServiceTransactionRegisterForward::SPtr serviceTransactionRegisterForward = constructSPtr<ServiceTransactionRegisterForward>();

		serviceTransactionRegisterForward->componentService(&*applicationService_);

		transactionManager_->registerTransaction(serviceTransactionRegisterForward);
	

		sessionManager.transactionManager(transactionManager_);
		return true;
	}

	bool 
	ServiceManager::informatinModel(InformationModel::SPtr informationModel)
	{
		attributeService_->informationModel(informationModel);
		methodService_->informationModel(informationModel);
		monitoredItemService_->informationModel(informationModel);
		nodeManagementService_->informationModel(informationModel);
		queryService_->informationModel(informationModel);
		subscriptionService_->informationModel(informationModel);
		viewService_->informationModel(informationModel);
		applicationService_->informationModel(informationModel);
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
		applicationService_->ioService(ioService);
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
		rc = rc && applicationService_->init();
		return rc;
	}

	bool
	ServiceManager::shutdown(void)
	{
		applicationService_->shutdown();
		viewService_->shutdown();
		subscriptionService_->shutdown();
		queryService_->shutdown();
		nodeManagementService_->shutdown();
		monitoredItemService_->shutdown();
		methodService_->shutdown();
		attributeService_->shutdown();
		return true;
	}

	ApplicationService::SPtr
	ServiceManager::applicationService(void)
	{
		return applicationService_;
	}

}
