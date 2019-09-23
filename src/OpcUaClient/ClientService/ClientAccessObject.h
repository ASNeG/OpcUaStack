/*
   Copyright 2016-2019 Kai Huebl (kai@huebl-sgh.de)

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

#ifndef __OpcUaClient_ClientAccess_h__
#define __OpcUaClient_ClientAccess_h__

#include <boost/shared_ptr.hpp>
#include <map>
#include "OpcUaStackClient/ServiceSet/ServiceSetManager.h"

namespace OpcUaClient
{

	class DLLEXPORT ClientAccessObject
	{
	  public:
		typedef boost::shared_ptr<ClientAccessObject> SPtr;
		typedef std::map<std::string, ClientAccessObject::SPtr> Map;

		ClientAccessObject(void);
		~ClientAccessObject(void);

		OpcUaStackClient::AttributeService::SPtr createAttributeService(void);
		OpcUaStackClient::AttributeService::SPtr createAttributeService(
			OpcUaStackClient::AttributeServiceConfig& attributeServiceConfig
		);
		OpcUaStackClient::AttributeService::SPtr getOrCreateAttributeService(void);
		OpcUaStackClient::AttributeService::SPtr getOrCreateAttributeService(
			OpcUaStackClient::AttributeServiceConfig& attributeServiceConfig
		);

		OpcUaStackClient::ViewService::SPtr createViewService(void);
		OpcUaStackClient::ViewService::SPtr createViewService(
			OpcUaStackClient::ViewServiceConfig& viewServiceConfig
		);
		OpcUaStackClient::ViewService::SPtr getOrCreateViewService(void);
		OpcUaStackClient::ViewService::SPtr getOrCreateViewService(
			OpcUaStackClient::ViewServiceConfig& viewServiceConfig
		);

		OpcUaStackClient::MethodService::SPtr createMethodService(void);
		OpcUaStackClient::MethodService::SPtr createMethodService(
			OpcUaStackClient::MethodServiceConfig& methodServiceConfig
		);
		OpcUaStackClient::MethodService::SPtr getOrCreateMethodService(void);
		OpcUaStackClient::MethodService::SPtr getOrCreateMethodService(
			OpcUaStackClient::MethodServiceConfig& methodServiceConfig
		);

		OpcUaStackClient::DiscoveryService::SPtr createDiscoveryService(void);
		OpcUaStackClient::DiscoveryService::SPtr createDiscoveryService(
			OpcUaStackClient::DiscoveryServiceConfig& discoveryServiceConfig
		);
		OpcUaStackClient::DiscoveryService::SPtr getOrCreateDiscoveryService(void);
		OpcUaStackClient::DiscoveryService::SPtr getOrCreateDiscoveryService(
			OpcUaStackClient::DiscoveryServiceConfig& discoveryServiceConfig
		);

	  public:
		OpcUaStackClient::ServiceSetManager serviceSetManager_;

		OpcUaStackClient::SessionService::SPtr sessionService_;

		OpcUaStackClient::AttributeService::SPtr attributeService_;

		OpcUaStackClient::ViewService::SPtr viewService_;

		OpcUaStackClient::MethodService::SPtr methodService_;

		OpcUaStackClient::DiscoveryService::SPtr discoveryService_;
	};

}

#endif

