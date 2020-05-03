/*
   Copyright 2015-2020 Kai Huebl (kai@huebl-sgh.de)

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

using namespace OpcUaStackCore;

namespace OpcUaStackServer
{

	ServiceManager::ServiceManager(void)
	: transactionManager_(boost::make_shared<TransactionManager>())
	, monitoredItemService_(boost::make_shared<MonitoredItemService>())
	, nodeManagementService_(boost::make_shared<NodeManagementService>())
	, queryService_(boost::make_shared<QueryService>())
	, subscriptionService_(boost::make_shared<SubscriptionService>())
	, viewService_(boost::make_shared<ViewService>())
	, applicationService_(boost::make_shared<ApplicationService>())
	, discoveryService_(boost::make_shared<DiscoveryService>())
	, forwardGlobalSync_(boost::make_shared<ForwardGlobalSync>())
	{
		monitoredItemService_->componentName("MonitoredItemService");
		nodeManagementService_->componentName("NodeManagementService");
		queryService_->componentName("QueryService");
		subscriptionService_->componentName("SubscriptionService");
		viewService_->componentName("ViewService");
		applicationService_->componentName("ApplicationService");
		discoveryService_->componentName("DiscoveryService");

		initForwardGlobalSync();
	}

	ServiceManager::~ServiceManager(void)
	{
	}

	void
	ServiceManager::initForwardGlobalSync(void)
	{
		monitoredItemService_->forwardGlobalSync(forwardGlobalSync_);
		nodeManagementService_->forwardGlobalSync(forwardGlobalSync_);
		queryService_->forwardGlobalSync(forwardGlobalSync_);
		subscriptionService_->forwardGlobalSync(forwardGlobalSync_);
		viewService_->forwardGlobalSync(forwardGlobalSync_);
		applicationService_->forwardGlobalSync(forwardGlobalSync_);
		discoveryService_->forwardGlobalSync(forwardGlobalSync_);
	}

	void
	ServiceManager::initAttributeService(void)
	{
		attributeService_ = boost::make_shared<AttributeService>(
			"AttributeServiceServer",
			ioThread_,
			messageBus_
		);
		attributeService_->componentName("AttributeService");		// FIXME: obsolete
		attributeService_->forwardGlobalSync(forwardGlobalSync_);

		ServiceTransactionRead::name("Read");
		ServiceTransactionWrite::name("Write");
		ServiceTransactionHistoryRead::name("HistoryRead");
		ServiceTransactionHistoryUpdate::name("HistoryUpdate");

		auto serviceTransactionRead = boost::make_shared<ServiceTransactionRead>();
		auto serviceTransactionWrite = boost::make_shared<ServiceTransactionWrite>();
		auto serviceTransactionHistoryRead = boost::make_shared<ServiceTransactionHistoryRead>();
		auto serviceTransactionHistoryUpdate = boost::make_shared<ServiceTransactionHistoryUpdate>();

		serviceTransactionRead->componentService(&*attributeService_);
		serviceTransactionWrite->componentService(&*attributeService_);
		serviceTransactionHistoryRead->componentService(&*attributeService_);
		serviceTransactionHistoryUpdate->componentService(&*attributeService_);

		transactionManager_->registerTransaction(serviceTransactionRead);
		transactionManager_->registerTransaction(serviceTransactionWrite);
		transactionManager_->registerTransaction(serviceTransactionHistoryRead);
		transactionManager_->registerTransaction(serviceTransactionHistoryUpdate);
	}

	void
	ServiceManager::initMethodService(void)
	{
		methodService_ = boost::make_shared<MethodService>(
			"MethodServiceServer",
			ioThread_,
			messageBus_
		);
		methodService_->componentName("MethodService");		// FIXME: obsolete
		methodService_->forwardGlobalSync(forwardGlobalSync_);

		ServiceTransactionCall::name("Call");

		auto serviceTransactionCall = boost::make_shared<ServiceTransactionCall>();

		serviceTransactionCall->componentService(&*methodService_);

		transactionManager_->registerTransaction(serviceTransactionCall);
	}

	bool
	ServiceManager::init(SessionManager& sessionManager)
	{
		initAttributeService();
		initMethodService();

		//
		// node mangement service
		//
		ServiceTransactionAddNodes::name("AddNodes");
		ServiceTransactionAddReferences::name("AddReferences");
		ServiceTransactionDeleteNodes::name("DeleteNodes");
		ServiceTransactionDeleteReferences::name("DeleteReferences");

		ServiceTransactionAddNodes::SPtr serviceTransactionAddNodes = boost::make_shared<ServiceTransactionAddNodes>();
		ServiceTransactionAddReferences::SPtr serviceTransactionAddReferences = boost::make_shared<ServiceTransactionAddReferences>();
		ServiceTransactionDeleteNodes::SPtr serviceTransactionDeleteNodes = boost::make_shared<ServiceTransactionDeleteNodes>();
		ServiceTransactionDeleteReferences::SPtr serviceTransactionDeleteReferences = boost::make_shared<ServiceTransactionDeleteReferences>();

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

		ServiceTransactionCreateSubscription::SPtr serviceTransactionCreateSubscription = boost::make_shared<ServiceTransactionCreateSubscription>();
		ServiceTransactionDeleteSubscriptions::SPtr serviceTransactionDeleteSubscriptions = boost::make_shared<ServiceTransactionDeleteSubscriptions>();
		ServiceTransactionModifySubscription::SPtr serviceTransactionModifySubscription = boost::make_shared<ServiceTransactionModifySubscription>();
		ServiceTransactionPublish::SPtr serviceTransactionPublish = boost::make_shared<ServiceTransactionPublish>();
		ServiceTransactionRepublish::SPtr serviceTransactionRepublish = boost::make_shared<ServiceTransactionRepublish>();
		ServiceTransactionSetPublishingMode::SPtr serviceTransactionSetPublishingMode = boost::make_shared<ServiceTransactionSetPublishingMode>();
		ServiceTransactionTransferSubscriptions::SPtr serviceTransactionTransferSubscriptions = boost::make_shared<ServiceTransactionTransferSubscriptions>();

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


		ServiceTransactionCreateMonitoredItems::SPtr serviceTransactionCreateMonitoredItems = boost::make_shared<ServiceTransactionCreateMonitoredItems>();
		ServiceTransactionDeleteMonitoredItems::SPtr serviceTransactionDeleteMonitoredItems = boost::make_shared<ServiceTransactionDeleteMonitoredItems>();
		ServiceTransactionModifyMonitoredItems::SPtr serviceTransactionModifyMonitoredItems = boost::make_shared<ServiceTransactionModifyMonitoredItems>();
		ServiceTransactionSetMonitoringMode::SPtr serviceTransactionSetMonitoringMode = boost::make_shared<ServiceTransactionSetMonitoringMode>();
		ServiceTransactionSetTriggering::SPtr serviceTransactionSetTriggering = boost::make_shared<ServiceTransactionSetTriggering>();

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

		ServiceTransactionBrowse::SPtr serviceTransactionBrowse = boost::make_shared<ServiceTransactionBrowse>();
		ServiceTransactionBrowseNext::SPtr serviceTransactionBrowseNext = boost::make_shared<ServiceTransactionBrowseNext>();
		ServiceTransactionTranslateBrowsePathsToNodeIds::SPtr serviceTransactionTranslateBrowsePathsToNodeIds = boost::make_shared<ServiceTransactionTranslateBrowsePathsToNodeIds>();
		ServiceTransactionRegisterNodes::SPtr serviceTransactionRegisterNodes = boost::make_shared<ServiceTransactionRegisterNodes>();
		ServiceTransactionUnregisterNodes::SPtr serviceTransactionUnregisterNodes = boost::make_shared<ServiceTransactionUnregisterNodes>();

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
		// discovery service service
		//
		ServiceTransactionRegisterServer::name("RegisterServer");

		ServiceTransactionRegisterServer::SPtr serviceTransactionRegisterServer = boost::make_shared<ServiceTransactionRegisterServer>();

		serviceTransactionRegisterServer->componentService(&*discoveryService_);

		transactionManager_->registerTransaction(serviceTransactionRegisterServer);

		//
		// application service
		//
		ServiceTransactionRegisterForwardNode::name("RegisterForwardNode");
		ServiceTransactionRegisterForwardMethod::name("RegisterForwardMethod");
		ServiceTransactionRegisterForwardGlobal::name("RegisterForwardGlobal");

		ServiceTransactionRegisterForwardNode::SPtr serviceTransactionRegisterForwardNode = boost::make_shared<ServiceTransactionRegisterForwardNode>();
		ServiceTransactionRegisterForwardMethod::SPtr serviceTransactionRegisterForwardMethod = boost::make_shared<ServiceTransactionRegisterForwardMethod>();
		ServiceTransactionRegisterForwardGlobal::SPtr serviceTransactionRegisterForwardGlobal = boost::make_shared<ServiceTransactionRegisterForwardGlobal>();

		serviceTransactionRegisterForwardNode->componentService(&*applicationService_);
		serviceTransactionRegisterForwardMethod->componentService(&*applicationService_);
		serviceTransactionRegisterForwardGlobal->componentService(&*applicationService_);

		transactionManager_->registerTransaction(serviceTransactionRegisterForwardNode);
		transactionManager_->registerTransaction(serviceTransactionRegisterForwardMethod);
		transactionManager_->registerTransaction(serviceTransactionRegisterForwardGlobal);
	
		sessionManager.discoveryService(discoveryService_);
		sessionManager.transactionManager(transactionManager_);
		sessionManager.forwardGlobalSync(forwardGlobalSync_);
		return true;
	}

	bool 
	ServiceManager::informationModel(InformationModel::SPtr informationModel)
	{
		attributeService_->informationModel(informationModel);
		methodService_->informationModel(informationModel);
		monitoredItemService_->informationModel(informationModel);
		nodeManagementService_->informationModel(informationModel);
		queryService_->informationModel(informationModel);
		subscriptionService_->informationModel(informationModel);
		viewService_->informationModel(informationModel);
		applicationService_->informationModel(informationModel);
		discoveryService_->informationModel(informationModel);
		return true;
	}

	bool 
	ServiceManager::ioThread(IOThread::SPtr& ioThread)
	{
		ioThread_ = ioThread;

		// FIXME: use IOThread in services...
		monitoredItemService_->ioThread(ioThread.get());
		nodeManagementService_->ioThread(ioThread.get());
		queryService_->ioThread(ioThread.get());
		subscriptionService_->ioThread(ioThread.get());
		viewService_->ioThread(ioThread.get());
		applicationService_->ioThread(ioThread.get());
		discoveryService_->ioThread(ioThread.get());
		return true;
	}

	bool
	ServiceManager::messageBus(OpcUaStackCore::MessageBus::SPtr& messageBus)
	{
		messageBus_ = messageBus;
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
		rc = rc && discoveryService_->init();
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
		discoveryService_->shutdown();
		return true;
	}

	ApplicationService::SPtr
	ServiceManager::applicationService(void)
	{
		return applicationService_;
	}

	DiscoveryService::SPtr
	ServiceManager::discoveryService(void)
	{
		return discoveryService_;
	}

}
