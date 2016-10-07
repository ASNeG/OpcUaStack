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

#ifndef __OpcUaStackClient_MonitoredItemService_h__
#define __OpcUaStackClient_MonitoredItemService_h__

#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/Component/Component.h"
#include "OpcUaStackCore/ServiceSet/MonitoredItemServiceTransaction.h"
#include "OpcUaStackClient/ServiceSet/MonitoredItemServiceIf.h"

using namespace OpcUaStackCore;

namespace OpcUaStackClient
{
	class DLLEXPORT MonitoredItemService
	: public Component
	{
	  public:
		typedef boost::shared_ptr<MonitoredItemService> SPtr;

		MonitoredItemService(IOThread* ioThread);
		~MonitoredItemService(void);

		void setConfiguration(
			Component* componentSession,
			MonitoredItemServiceIf* monitoredItemServiceIf
		);
		void componentSession(Component* componentSession);
		void monitoredItemServiceIf(MonitoredItemServiceIf* monitoredItemServiceIf);

		void syncSend(ServiceTransactionCreateMonitoredItems::SPtr serviceTransactionCreateMonitoredItems);
		void asyncSend(ServiceTransactionCreateMonitoredItems::SPtr serviceTransactionCreateMonitoredItems);
		void syncSend(ServiceTransactionDeleteMonitoredItems::SPtr serviceTransactionDeleteMonitoredItems);
		void asyncSend(ServiceTransactionDeleteMonitoredItems::SPtr serviceTransactionDeleteMonitoredItems);
		void syncSend(ServiceTransactionModifyMonitoredItems::SPtr serviceTransactionModifyMonitoredItems);
		void asyncSend(ServiceTransactionModifyMonitoredItems::SPtr serviceTransactionModifyMonitoredItems);
		void syncSend(ServiceTransactionSetMonitoringMode::SPtr serviceTransactionSetMonitoringMode);
		void asyncSend(ServiceTransactionSetMonitoringMode::SPtr serviceTransactionSetMonitoringMode);
		void syncSend(ServiceTransactionSetTriggering::SPtr serviceTransactionSetTriggering);
		void asyncSend(ServiceTransactionSetTriggering::SPtr serviceTransactionSetTriggering);

		//- Component -----------------------------------------------------------------
		void receive(Message::SPtr message);
		//- Component -----------------------------------------------------------------

	  private:
		Component* componentSession_;

		MonitoredItemServiceIf* monitoredItemServiceIf_;
	};

}

#endif
