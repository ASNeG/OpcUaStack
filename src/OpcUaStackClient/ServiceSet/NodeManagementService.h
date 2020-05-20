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

#ifndef __OpcUaStackClient_NodeManagementService_h__
#define __OpcUaStackClient_NodeManagementService_h__

#include <OpcUaStackCore/MessageBus/MessageBus.h>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/ServiceSet/NodeManagementServiceTransaction.h"
#include "OpcUaStackClient/ServiceSet/ClientServiceBase.h"

namespace OpcUaStackClient 
{

	class DLLEXPORT NodeManagementService
	: public ClientServiceBase
	{
	  public:
		typedef boost::shared_ptr<NodeManagementService> SPtr;

		NodeManagementService(
			const std::string& serviceName,
			OpcUaStackCore::IOThread* ioThread,
			OpcUaStackCore::MessageBus::SPtr& messageBus
		);
		~NodeManagementService(void);

		void setConfiguration(
			OpcUaStackCore::MessageBusMember::WPtr& sessionMember
		);

		void syncSend(const OpcUaStackCore::ServiceTransactionAddNodes::SPtr& serviceTransactionAddNodes);
		void asyncSend(const OpcUaStackCore::ServiceTransactionAddNodes::SPtr& serviceTransactionAddNodes);
		void syncSend(const OpcUaStackCore::ServiceTransactionAddReferences::SPtr& serviceTransactionAddReferences);
		void asyncSend(const OpcUaStackCore::ServiceTransactionAddReferences::SPtr& serviceTransactionAddReferences);
		void syncSend(const OpcUaStackCore::ServiceTransactionDeleteNodes::SPtr& serviceTransactionDeleteNodes);
		void asyncSend(const OpcUaStackCore::ServiceTransactionDeleteNodes::SPtr& serviceTransactionDeleteNodes);
		void syncSend(const OpcUaStackCore::ServiceTransactionDeleteReferences::SPtr& serviceTransactionDeleteReferences);
		void asyncSend(const OpcUaStackCore::ServiceTransactionDeleteReferences::SPtr& serviceTransactionDeleteReferences);

	  private:
		void receive(
			const OpcUaStackCore::MessageBusMember::WPtr& handleFrom,
			OpcUaStackCore::Message::SPtr message
		);
		OpcUaStackCore::MessageBusMember::WPtr sessionMember_;
	};

}

#endif
