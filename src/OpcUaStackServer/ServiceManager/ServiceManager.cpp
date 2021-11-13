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
          Upendar Reddy Sama (upendarreddysama3@gmail.com)
 */

#include "OpcUaStackServer/ServiceManager/ServiceManager.h"

using namespace OpcUaStackCore;

namespace OpcUaStackServer
{

	ServiceManager::ServiceManager(void)
	: transactionManager_(boost::make_shared<TransactionManager>())
	, forwardGlobalSync_(boost::make_shared<ForwardGlobalSync>())
	{
		
	}

	ServiceManager::~ServiceManager(void)
	{
	}

	void
	ServiceManager::initServerInfoService(void)
	{
		serverInfoService_ = boost::make_shared<ServerInfoService>(
			"ServerInfoServiceServer",
			ioThread_,
			messageBus_
		);

		ServiceTransactionAddSession::name("AddSession");
		ServiceTransactionDelSession::name("DelSession");
		ServiceTransactionUpdSession::name("UpdSession");

		auto serviceTransactionAddSession = boost::make_shared<ServiceTransactionAddSession>();
		auto serviceTransactionDelSession = boost::make_shared<ServiceTransactionDelSession>();
		auto serviceTransactionUpdSession = boost::make_shared<ServiceTransactionUpdSession>();

		serviceTransactionAddSession->memberService(serverInfoService_->messageBusMember());
		serviceTransactionDelSession->memberService(serverInfoService_->messageBusMember());
		serviceTransactionUpdSession->memberService(serverInfoService_->messageBusMember());

		transactionManager_->registerTransaction(serviceTransactionAddSession);
		transactionManager_->registerTransaction(serviceTransactionDelSession);
		transactionManager_->registerTransaction(serviceTransactionUpdSession);
	}

	void
	ServiceManager::initAttributeService(void)
	{
		attributeService_ = boost::make_shared<AttributeService>(
			"AttributeServiceServer",
			ioThread_,
			messageBus_
		);
		attributeService_->forwardGlobalSync(forwardGlobalSync_);

		ServiceTransactionRead::name("Read");
		ServiceTransactionWrite::name("Write");
		ServiceTransactionHistoryRead::name("HistoryRead");
		ServiceTransactionHistoryUpdate::name("HistoryUpdate");

		auto serviceTransactionRead = boost::make_shared<ServiceTransactionRead>();
		auto serviceTransactionWrite = boost::make_shared<ServiceTransactionWrite>();
		auto serviceTransactionHistoryRead = boost::make_shared<ServiceTransactionHistoryRead>();
		auto serviceTransactionHistoryUpdate = boost::make_shared<ServiceTransactionHistoryUpdate>();

		serviceTransactionRead->memberService(attributeService_->messageBusMember());
		serviceTransactionWrite->memberService(attributeService_->messageBusMember());
		serviceTransactionHistoryRead->memberService(attributeService_->messageBusMember());
		serviceTransactionHistoryUpdate->memberService(attributeService_->messageBusMember());

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
		methodService_->forwardGlobalSync(forwardGlobalSync_);

		ServiceTransactionCall::name("Call");

		auto serviceTransactionCall = boost::make_shared<ServiceTransactionCall>();

		serviceTransactionCall->memberService(methodService_->messageBusMember());

		transactionManager_->registerTransaction(serviceTransactionCall);
	}

	void
	ServiceManager::initNodeManagementService(void)
	{
		nodeManagementService_ = boost::make_shared<NodeManagementService>(
			"NodeManagementServiceServer",
			ioThread_,
			messageBus_
		);
		nodeManagementService_->forwardGlobalSync(forwardGlobalSync_);

		ServiceTransactionAddNodes::name("AddNodes");
		ServiceTransactionAddReferences::name("AddReferences");
		ServiceTransactionDeleteNodes::name("DeleteNodes");
		ServiceTransactionDeleteReferences::name("DeleteReferences");

		auto serviceTransactionAddNodes = boost::make_shared<ServiceTransactionAddNodes>();
		auto serviceTransactionAddReferences = boost::make_shared<ServiceTransactionAddReferences>();
		auto serviceTransactionDeleteNodes = boost::make_shared<ServiceTransactionDeleteNodes>();
		auto serviceTransactionDeleteReferences = boost::make_shared<ServiceTransactionDeleteReferences>();

		serviceTransactionAddNodes->memberService(nodeManagementService_->messageBusMember());
		serviceTransactionAddReferences->memberService(nodeManagementService_->messageBusMember());
		serviceTransactionDeleteNodes->memberService(nodeManagementService_->messageBusMember());
		serviceTransactionDeleteReferences->memberService(nodeManagementService_->messageBusMember());

		transactionManager_->registerTransaction(serviceTransactionAddNodes);
		transactionManager_->registerTransaction(serviceTransactionAddReferences);
		transactionManager_->registerTransaction(serviceTransactionDeleteNodes);
		transactionManager_->registerTransaction(serviceTransactionDeleteReferences);
	}

	void
	ServiceManager::initSubscriptionService(void)
	{
		subscriptionService_ = boost::make_shared<SubscriptionService>(
			"SubscriptionServiceServer",
			ioThread_,
			messageBus_
		);
		subscriptionService_->forwardGlobalSync(forwardGlobalSync_);

		ServiceTransactionCreateSubscription::name("CreateSubscription");
		ServiceTransactionDeleteSubscriptions::name("DeleteSubscription");
		ServiceTransactionModifySubscription::name("ModifySubscription");
		ServiceTransactionPublish::name("Publish");
		ServiceTransactionRepublish::name("Republish");
		ServiceTransactionSetPublishingMode::name("SetPublishingMode");
		ServiceTransactionTransferSubscriptions::name("TransferSubscription");

		auto serviceTransactionCreateSubscription = boost::make_shared<ServiceTransactionCreateSubscription>();
		auto serviceTransactionDeleteSubscriptions = boost::make_shared<ServiceTransactionDeleteSubscriptions>();
		auto serviceTransactionModifySubscription = boost::make_shared<ServiceTransactionModifySubscription>();
		auto serviceTransactionPublish = boost::make_shared<ServiceTransactionPublish>();
		auto serviceTransactionRepublish = boost::make_shared<ServiceTransactionRepublish>();
		auto serviceTransactionSetPublishingMode = boost::make_shared<ServiceTransactionSetPublishingMode>();
		auto serviceTransactionTransferSubscriptions = boost::make_shared<ServiceTransactionTransferSubscriptions>();

		serviceTransactionCreateSubscription->memberService(subscriptionService_->messageBusMember());
		serviceTransactionDeleteSubscriptions->memberService(subscriptionService_->messageBusMember());
		serviceTransactionModifySubscription->memberService(subscriptionService_->messageBusMember());
		serviceTransactionPublish->memberService(subscriptionService_->messageBusMember());
		serviceTransactionRepublish->memberService(subscriptionService_->messageBusMember());
		serviceTransactionSetPublishingMode->memberService(subscriptionService_->messageBusMember());
		serviceTransactionTransferSubscriptions->memberService(subscriptionService_->messageBusMember());

		transactionManager_->registerTransaction(serviceTransactionCreateSubscription);
		transactionManager_->registerTransaction(serviceTransactionDeleteSubscriptions);
		transactionManager_->registerTransaction(serviceTransactionModifySubscription);
		transactionManager_->registerTransaction(serviceTransactionPublish);
		transactionManager_->registerTransaction(serviceTransactionRepublish);
		transactionManager_->registerTransaction(serviceTransactionSetPublishingMode);
		transactionManager_->registerTransaction(serviceTransactionTransferSubscriptions);
	}

	void
	ServiceManager::initMonitoredItemService(void)
	{
		monitoredItemService_ = boost::make_shared<MonitoredItemService>(
			"MonitoredItemServiceServer",
			ioThread_,
			messageBus_
		);
		monitoredItemService_->forwardGlobalSync(forwardGlobalSync_);

		ServiceTransactionCreateMonitoredItems::name("CreateMonitorItems");
		ServiceTransactionDeleteMonitoredItems::name("DeleteMonitorItems");
		ServiceTransactionModifyMonitoredItems::name("ModifyMonitorItems");
		ServiceTransactionSetMonitoringMode::name("SetMonitoringMode");
		ServiceTransactionSetTriggering::name("SetTriggering");

		auto serviceTransactionCreateMonitoredItems = boost::make_shared<ServiceTransactionCreateMonitoredItems>();
		auto serviceTransactionDeleteMonitoredItems = boost::make_shared<ServiceTransactionDeleteMonitoredItems>();
		auto serviceTransactionModifyMonitoredItems = boost::make_shared<ServiceTransactionModifyMonitoredItems>();
		auto serviceTransactionSetMonitoringMode = boost::make_shared<ServiceTransactionSetMonitoringMode>();
		auto serviceTransactionSetTriggering = boost::make_shared<ServiceTransactionSetTriggering>();

		serviceTransactionCreateMonitoredItems->memberService(subscriptionService_->messageBusMember());
		serviceTransactionDeleteMonitoredItems->memberService(subscriptionService_->messageBusMember());
		serviceTransactionModifyMonitoredItems->memberService(subscriptionService_->messageBusMember());
		serviceTransactionSetMonitoringMode->memberService(subscriptionService_->messageBusMember());
		serviceTransactionSetTriggering->memberService(subscriptionService_->messageBusMember());

		transactionManager_->registerTransaction(serviceTransactionCreateMonitoredItems);
		transactionManager_->registerTransaction(serviceTransactionDeleteMonitoredItems);
		transactionManager_->registerTransaction(serviceTransactionModifyMonitoredItems);
		transactionManager_->registerTransaction(serviceTransactionSetMonitoringMode);
		transactionManager_->registerTransaction(serviceTransactionSetTriggering);
	}

	void
	ServiceManager::initViewService(void)
	{
		viewService_ = boost::make_shared<ViewService>(
			"ViewServiceServer",
			ioThread_,
			messageBus_,
			continuationPointManager_
		);
		viewService_->forwardGlobalSync(forwardGlobalSync_);

		ServiceTransactionBrowse::name("Browse");
		ServiceTransactionBrowseNext::name("BrowseNext");
		ServiceTransactionTranslateBrowsePathsToNodeIds::name("TranslateBrowsePathsToNodeIds");
		ServiceTransactionRegisterNodes::name("RegisterNodes");
		ServiceTransactionUnregisterNodes::name("UnregisterNodes");

		auto serviceTransactionBrowse = boost::make_shared<ServiceTransactionBrowse>();
		auto serviceTransactionBrowseNext = boost::make_shared<ServiceTransactionBrowseNext>();
		auto serviceTransactionTranslateBrowsePathsToNodeIds = boost::make_shared<ServiceTransactionTranslateBrowsePathsToNodeIds>();
		auto serviceTransactionRegisterNodes = boost::make_shared<ServiceTransactionRegisterNodes>();
		auto serviceTransactionUnregisterNodes = boost::make_shared<ServiceTransactionUnregisterNodes>();

		serviceTransactionBrowse->memberService(viewService_->messageBusMember());
		serviceTransactionBrowseNext->memberService(viewService_->messageBusMember());
		serviceTransactionTranslateBrowsePathsToNodeIds->memberService(viewService_->messageBusMember());
		serviceTransactionRegisterNodes->memberService(viewService_->messageBusMember());
		serviceTransactionUnregisterNodes->memberService(viewService_->messageBusMember());

		transactionManager_->registerTransaction(serviceTransactionBrowse);
		transactionManager_->registerTransaction(serviceTransactionBrowseNext);
		transactionManager_->registerTransaction(serviceTransactionTranslateBrowsePathsToNodeIds);
		transactionManager_->registerTransaction(serviceTransactionRegisterNodes);
		transactionManager_->registerTransaction(serviceTransactionUnregisterNodes);
	}

	void
	ServiceManager::initQueryService(void)
	{
		queryService_ = boost::make_shared<QueryService>(
			"QueryServiceServer",
			ioThread_,
			messageBus_
		);
		queryService_->forwardGlobalSync(forwardGlobalSync_);
	}

	void
	ServiceManager::initDiscoveryService(void)
	{
		discoveryService_ = boost::make_shared<DiscoveryService>(
			"DiscoveryServiceServer",
			ioThread_,
			messageBus_
		);
		discoveryService_->forwardGlobalSync(forwardGlobalSync_);

		ServiceTransactionRegisterServer::name("RegisterServer");

		auto serviceTransactionRegisterServer = boost::make_shared<ServiceTransactionRegisterServer>();

		serviceTransactionRegisterServer->memberService(discoveryService_->messageBusMember());

		transactionManager_->registerTransaction(serviceTransactionRegisterServer);

		discoveryService_->endpointDescriptionSet(endpointDescriptionSet_);
		discoveryService_->cryptoManager(cryptoManager_);
	}

	void
	ServiceManager::initApplicationService(void)
	{
		applicationService_ = boost::make_shared<ApplicationService>(
			"ApplicationServiceServer",
			ioThread_,
			messageBus_
		);
		applicationService_->forwardGlobalSync(forwardGlobalSync_);

		ServiceTransactionRegisterForwardNode::name("RegisterForwardNode");
		ServiceTransactionRegisterForwardMethod::name("RegisterForwardMethod");
		ServiceTransactionRegisterForwardGlobal::name("RegisterForwardGlobal");

		auto serviceTransactionRegisterForwardNode = boost::make_shared<ServiceTransactionRegisterForwardNode>();
		auto serviceTransactionRegisterForwardMethod = boost::make_shared<ServiceTransactionRegisterForwardMethod>();
		auto serviceTransactionRegisterForwardGlobal = boost::make_shared<ServiceTransactionRegisterForwardGlobal>();

		serviceTransactionRegisterForwardNode->memberService(applicationService_->messageBusMember());
		serviceTransactionRegisterForwardMethod->memberService(applicationService_->messageBusMember());
		serviceTransactionRegisterForwardGlobal->memberService(applicationService_->messageBusMember());

		transactionManager_->registerTransaction(serviceTransactionRegisterForwardNode);
		transactionManager_->registerTransaction(serviceTransactionRegisterForwardMethod);
		transactionManager_->registerTransaction(serviceTransactionRegisterForwardGlobal);
	}

	bool
	ServiceManager::initService(SessionManager::SPtr& sessionManager)
	{
		continuationPointManager_ = boost::make_shared<OpcUaStackCore::ContinuationPointManager>(ioThread_);

		initServerInfoService();
		initAttributeService();
		initMethodService();
		initNodeManagementService();
		initSubscriptionService();
		initMonitoredItemService();
		initViewService();
		initQueryService();
		initDiscoveryService();
		initApplicationService();

		sessionManager->getEndpointRequestCallback(
			[this](OpcUaStackCore::RequestHeader::SPtr& requestHeader,
				   OpcUaStackCore::SecureChannelTransaction::SPtr secureChannelTransaction) {
				discoveryService_->getEndpointRequest(requestHeader, secureChannelTransaction);
		    }
		);

		sessionManager->findServersRequestCallback(
			[this](OpcUaStackCore::RequestHeader::SPtr& requestHeader,
				   OpcUaStackCore::SecureChannelTransaction::SPtr secureChannelTransaction) {
				discoveryService_->findServersRequest(requestHeader, secureChannelTransaction);
		    }
		);

		sessionManager->registerServerRequestCallback(
			[this](OpcUaStackCore::RequestHeader::SPtr& requestHeader,
				   OpcUaStackCore::SecureChannelTransaction::SPtr secureChannelTransaction) {
				discoveryService_->registerServerRequest(requestHeader, secureChannelTransaction);
		    }
		);

		sessionManager->transactionManager(transactionManager_);
		sessionManager->forwardGlobalSync(forwardGlobalSync_);

		return true;
	}

	void
	ServiceManager::informationModel(InformationModel::SPtr informationModel)
	{
		serverInfoService_->informationModel(informationModel);
		attributeService_->informationModel(informationModel);
		methodService_->informationModel(informationModel);
		monitoredItemService_->informationModel(informationModel);
		nodeManagementService_->informationModel(informationModel);
		queryService_->informationModel(informationModel);
		subscriptionService_->informationModel(informationModel);
		viewService_->informationModel(informationModel);
		applicationService_->informationModel(informationModel);
		discoveryService_->informationModel(informationModel);
	}

	void
	ServiceManager::ioThread(IOThread::SPtr& ioThread)
	{
		ioThread_ = ioThread;
	}

	void
	ServiceManager::messageBus(OpcUaStackCore::MessageBus::SPtr& messageBus)
	{
		messageBus_ = messageBus;
	}
	void
	ServiceManager::endpointDescriptionSet(EndpointDescriptionSet::SPtr& endpointDescriptionSet)
	{
		endpointDescriptionSet_ = endpointDescriptionSet;
	}

	void
	ServiceManager::cryptoManager(CryptoManager::SPtr& cryptoManager)
	{
		cryptoManager_ = cryptoManager;
	}

	bool
	ServiceManager::init(void)
	{
		bool rc = true;
		
		rc = rc && serverInfoService_->init();
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
	ServiceManager::startup(void)
	{
		continuationPointManager_->startup();
		return true;
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
		serverInfoService_->shutdown();

		applicationService_.reset();
		viewService_.reset();
		subscriptionService_.reset();
		queryService_.reset();
		nodeManagementService_.reset();
		monitoredItemService_.reset();
		methodService_.reset();
		attributeService_.reset();
		discoveryService_.reset();
		serverInfoService_.reset();

		continuationPointManager_->shutdown();

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
