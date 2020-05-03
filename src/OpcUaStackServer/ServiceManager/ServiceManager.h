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

#ifndef __OpcUaStackServer_ServiceManager_h__
#define __OpcUaStackServer_ServiceManager_h__

#include "OpcUaStackCore/Base/IOService.h"
#include "OpcUaStackServer/InformationModel/InformationModel.h"
#include "OpcUaStackServer/ServiceSet/SessionManager.h"
#include "OpcUaStackServer/ServiceSet/AttributeService.h"
#include "OpcUaStackServer/ServiceSet/MethodService.h"
#include "OpcUaStackServer/ServiceSet/NodeManagementService.h"
#include "OpcUaStackServer/ServiceSet/MonitoredItemService.h"
#include "OpcUaStackServer/ServiceSet/QueryService.h"
#include "OpcUaStackServer/ServiceSet/SubscriptionService.h"
#include "OpcUaStackServer/ServiceSet/ViewService.h"
#include "OpcUaStackServer/ServiceSet/DiscoveryService.h"
#include "OpcUaStackServer/ServiceSetApplication/ApplicationService.h"

namespace OpcUaStackServer
{

	class DLLEXPORT ServiceManager
	{
	  public:
		ServiceManager(void);
		~ServiceManager(void);

		bool init(SessionManager& sessionManager);
		bool informationModel(InformationModel::SPtr informatinModel);
		bool ioThread(OpcUaStackCore::IOThread* ioThread);
		bool init(void);
		bool shutdown(void);

		ApplicationService::SPtr applicationService(void);
		DiscoveryService::SPtr discoveryService(void);

	  private:
		void initForwardGlobalSync(void);

		OpcUaStackCore::ForwardGlobalSync::SPtr forwardGlobalSync_;

		TransactionManager::SPtr transactionManager_;
		AttributeService::SPtr attributeService_;
		MethodService::SPtr methodService_;
		MonitoredItemService::SPtr monitoredItemService_;
		NodeManagementService::SPtr nodeManagementService_;
		QueryService::SPtr queryService_;
		SubscriptionService::SPtr subscriptionService_;
		ViewService::SPtr viewService_;
		ApplicationService::SPtr applicationService_;
		DiscoveryService::SPtr discoveryService_;
	};

}

#endif
