/*
   Copyright 2017 Kai Huebl (kai@huebl-sgh.de)

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

#ifndef __OpcUaStackServer_EventManager_h__
#define __OpcUaStackServer_EventManager_h__

#include <stdint.h>

#include "OpcUaStackCore/BuildInTypes/OpcUaStatusCode.h"
#include "OpcUaStackCore/ServiceSet/MonitoredItemServiceTransaction.h"
#include "OpcUaStackCore/Base/IOService.h"
#include "OpcUaStackCore/Utility/SlotTimer.h"
#include "OpcUaStackServer/InformationModel/InformationModel.h"

using namespace OpcUaStackCore;

namespace OpcUaStackServer
{

	class EventManager
	{
	  public:
		EventManager(void);
		~EventManager(void);

		void ioService(IOService* ioService);
		void subscriptionId(uint32_t subscriptionId);
		uint32_t subscriptionId(void);
		void informationModel(InformationModel::SPtr informationModel);

		OpcUaStatusCode receive(ServiceTransactionCreateMonitoredItems::SPtr trx);
		OpcUaStatusCode receive(ServiceTransactionDeleteMonitoredItems::SPtr trx);

	  private:

		IOService* ioService_;
		uint32_t subscriptionId_;
		InformationModel::SPtr informationModel_;
	};

}

#endif
