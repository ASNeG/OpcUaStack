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

#ifndef __OpcUaStackClient_DiscoveryService_h__
#define __OpcUaStackClient_DiscoveryService_h__

#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/Component/Component.h"
#include "OpcUaStackCore/ServiceSet/DiscoveryServiceTransaction.h"
#include "OpcUaStackClient/ServiceSet/Session.h"

using namespace OpcUaStackCore;

namespace OpcUaStackClient 
{

	class DLLEXPORT DiscoveryServiceIf
	{
	  public:
		DiscoveryServiceIf(void) {}
		virtual ~DiscoveryServiceIf(void) {}

        virtual void discoveryServiceFindServersResponse(ServiceTransactionFindServers::SPtr serviceTransactionFindServers) {};
        virtual void discoveryServiceGetEndpointsResponse(ServiceTransactionGetEndpoints::SPtr serviceTransactionGetEndpoints) {};
        virtual void discoveryServiceRegisterServerResponse(ServiceTransactionRegisterServer::SPtr serviceTransactionRegisterServer) {};
	};

	class DLLEXPORT DiscoveryService
	: public Component
	{
	  public:
		boost::shared_ptr<DiscoveryService> SPtr;

		DiscoveryService(void);
		~DiscoveryService(void);

		void componentSession(Component* componentSession);
		void discoveryServiceIf(DiscoveryServiceIf* discoveryServiceIf);

		void syncSend(ServiceTransactionFindServers::SPtr serviceTransactionFindServers);
		void asyncSend(ServiceTransactionFindServers::SPtr serviceTransactionFindServers);
		void syncSend(ServiceTransactionGetEndpoints::SPtr serviceTransactionGetEndpoints);
		void asyncSend(ServiceTransactionGetEndpoints::SPtr serviceTransactionGetEndpoints);
		void syncSend(ServiceTransactionRegisterServer::SPtr serviceTransactionRegisterServer);
		void asyncSend(ServiceTransactionRegisterServer::SPtr serviceTransactionRegisterServer);

		//- Component -----------------------------------------------------------------
		void receive(Message::SPtr message);
		//- Component -----------------------------------------------------------------

	  private:
		Component* componentSession_;

		DiscoveryServiceIf* discoveryServiceIf_;
	};

}

#endif
