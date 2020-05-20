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

#ifndef __OpcUaStackClient_DiscoveryService_h__
#define __OpcUaStackClient_DiscoveryService_h__

#include <OpcUaStackCore/MessageBus/MessageBus.h>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackClient/ServiceSet/ClientServiceBase.h"
#include "OpcUaStackCore/ServiceSet/DiscoveryServiceTransaction.h"

namespace OpcUaStackClient 
{

	class DLLEXPORT DiscoveryService
	: public ClientServiceBase
	{
	  public:
		typedef boost::shared_ptr<DiscoveryService> SPtr;

		DiscoveryService(
			const std::string& serviceName,
			OpcUaStackCore::IOThread* ioThread,
			OpcUaStackCore::MessageBus::SPtr& messageBus
		);
		~DiscoveryService(void);

		void setConfiguration(
			OpcUaStackCore::MessageBusMember::WPtr& sessionMember
		);

		void syncSend(const OpcUaStackCore::ServiceTransactionFindServers::SPtr& serviceTransactionFindServers);
		void asyncSend(const OpcUaStackCore::ServiceTransactionFindServers::SPtr& serviceTransactionFindServers);
		void syncSend(const OpcUaStackCore::ServiceTransactionGetEndpoints::SPtr& serviceTransactionGetEndpoints);
		void asyncSend(const OpcUaStackCore::ServiceTransactionGetEndpoints::SPtr& serviceTransactionGetEndpoints);
		void syncSend(const OpcUaStackCore::ServiceTransactionRegisterServer::SPtr& serviceTransactionRegisterServer);
		void asyncSend(const OpcUaStackCore::ServiceTransactionRegisterServer::SPtr& serviceTransactionRegisterServer);

	  private:
		void receive(
			const OpcUaStackCore::MessageBusMember::WPtr& handleFrom,
			OpcUaStackCore::Message::SPtr message
		);
		OpcUaStackCore::MessageBusMember::WPtr sessionMember_;
	};

}

#endif
