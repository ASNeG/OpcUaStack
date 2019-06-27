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

#ifndef __OpcUaStackServer_MonitoredItemService_h__
#define __OpcUaStackServer_MonitoredItemService_h__

#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/ServiceSet/MonitoredItemServiceTransaction.h"
#include "OpcUaStackServer/ServiceSet/ServiceSetBase.h"

using namespace OpcUaStackCore;

namespace OpcUaStackServer
{

	class DLLEXPORT MonitoredItemService 
	: public ServiceSetBase
	, public Object
	{
	  public:
		typedef boost::shared_ptr<MonitoredItemService> SPtr;

		MonitoredItemService(void);
		~MonitoredItemService(void);

		//- Component -----------------------------------------------------------------
		void receive(Message::SPtr message);
		//- Component -----------------------------------------------------------------

	  private:
		void receiveCreateMonitoredItemsRequest(ServiceTransaction::SPtr serviceTransaction);
		void receiveDeleteMonitoredItemsRequest(ServiceTransaction::SPtr serviceTransaction);
		void receiveModifyMonitoredItemsRequest(ServiceTransaction::SPtr serviceTransaction);
		void receiveSetmonitoringModeRequest(ServiceTransaction::SPtr serviceTransaction);
		void receiveSetTriggeringRequest(ServiceTransaction::SPtr serviceTransaction);

	};

}

#endif
