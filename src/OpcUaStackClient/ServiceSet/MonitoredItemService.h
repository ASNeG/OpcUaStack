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

#ifndef __OpcUaStackClient_MonitoredItemService_h__
#define __OpcUaStackClient_MonitoredItemService_h__

#include "OpcUaStackCore/Component/MessageBus.h"
#include "OpcUaStackClient/ServiceSet/ClientServiceBase.h"
#include "OpcUaStackCore/ServiceSet/MonitoredItemServiceTransaction.h"

namespace OpcUaStackClient
{
	class DLLEXPORT MonitoredItemService
	: public ClientServiceBase
	{
	  public:
		typedef boost::shared_ptr<MonitoredItemService> SPtr;

		MonitoredItemService(
			const std::string& serviceName,
			OpcUaStackCore::IOThread* ioThread,
			OpcUaStackCore::MessageBus::SPtr& messageBus
		);
		~MonitoredItemService(void);

		void setConfiguration(
			OpcUaStackCore::MessageBusMember::WPtr& sessionMember
		);

		void syncSend(OpcUaStackCore::ServiceTransactionCreateMonitoredItems::SPtr serviceTransactionCreateMonitoredItems);
		void asyncSend(OpcUaStackCore::ServiceTransactionCreateMonitoredItems::SPtr serviceTransactionCreateMonitoredItems);
		void syncSend(OpcUaStackCore::ServiceTransactionDeleteMonitoredItems::SPtr serviceTransactionDeleteMonitoredItems);
		void asyncSend(OpcUaStackCore::ServiceTransactionDeleteMonitoredItems::SPtr serviceTransactionDeleteMonitoredItems);
		void syncSend(OpcUaStackCore::ServiceTransactionModifyMonitoredItems::SPtr serviceTransactionModifyMonitoredItems);
		void asyncSend(OpcUaStackCore::ServiceTransactionModifyMonitoredItems::SPtr serviceTransactionModifyMonitoredItems);
		void syncSend(OpcUaStackCore::ServiceTransactionSetMonitoringMode::SPtr serviceTransactionSetMonitoringMode);
		void asyncSend(OpcUaStackCore::ServiceTransactionSetMonitoringMode::SPtr serviceTransactionSetMonitoringMode);
		void syncSend(OpcUaStackCore::ServiceTransactionSetTriggering::SPtr serviceTransactionSetTriggering);
		void asyncSend(OpcUaStackCore::ServiceTransactionSetTriggering::SPtr serviceTransactionSetTriggering);

		//- Component -----------------------------------------------------------------
		void receive(OpcUaStackCore::Message::SPtr message);
		//- Component -----------------------------------------------------------------

	  private:
		OpcUaStackCore::MessageBusMember::WPtr sessionMember_;
	};

}

#endif
