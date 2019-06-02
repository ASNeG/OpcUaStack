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

using namespace OpcUaStackClient;

namespace OpcUaClient
{

	class DLLEXPORT ClientAccessObject
	{
	  public:
		typedef boost::shared_ptr<ClientAccessObject> SPtr;
		typedef std::map<std::string, ClientAccessObject::SPtr> Map;

		ClientAccessObject(void);
		~ClientAccessObject(void);

		AttributeService::SPtr createAttributeService(void);
		AttributeService::SPtr createAttributeService(AttributeServiceConfig& attributeServiceConfig);
		AttributeService::SPtr getOrCreateAttributeService(void);
		AttributeService::SPtr getOrCreateAttributeService(AttributeServiceConfig& attributeServiceConfig);

		ViewService::SPtr createViewService(void);
		ViewService::SPtr createViewService(ViewServiceConfig& viewServiceConfig);
		ViewService::SPtr getOrCreateViewService(void);
		ViewService::SPtr getOrCreateViewService(ViewServiceConfig& viewServiceConfig);

		MethodService::SPtr createMethodService(void);
		MethodService::SPtr createMethodService(MethodServiceConfig& methodServiceConfig);
		MethodService::SPtr getOrCreateMethodService(void);
		MethodService::SPtr getOrCreateMethodService(MethodServiceConfig& methodServiceConfig);

		DiscoveryService::SPtr createDiscoveryService(void);
		DiscoveryService::SPtr createDiscoveryService(DiscoveryServiceConfig& discoveryServiceConfig);
		DiscoveryService::SPtr getOrCreateDiscoveryService(void);
		DiscoveryService::SPtr getOrCreateDiscoveryService(DiscoveryServiceConfig& discoveryServiceConfig);

	  public:
		ServiceSetManager serviceSetManager_;

		SessionService::SPtr sessionService_;

		AttributeService::SPtr attributeService_;

		ViewService::SPtr viewService_;

		MethodService::SPtr methodService_;

		DiscoveryService::SPtr discoveryService_;
	};

}

#endif

