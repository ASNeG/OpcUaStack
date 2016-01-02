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

#ifndef __OpcUaStackClient_MonitoredItemServiceIf_h__
#define __OpcUaStackClient_MonitoredItemServiceIf_h__

#include "OpcUaStackCore/Base/Condition.h"
#include "OpcUaStackCore/ServiceSet/MonitoredItemServiceTransaction.h"
#include "OpcUaStackCore/ServiceSet/MonitoredItemNotification.h"

using namespace OpcUaStackCore;

namespace OpcUaStackClient
{

	class DLLEXPORT MonitoredItemServiceIf
	{
	  public:
		MonitoredItemServiceIf(void) {}
		virtual ~MonitoredItemServiceIf(void) {}

	    virtual void monitoredItemServiceCreateMonitoredItemsResponse(ServiceTransactionCreateMonitoredItems::SPtr serviceTransactionCreateMonitoredItems) {};
	    virtual void monitoredItemServiceDeleteMonitoredItemsResponse(ServiceTransactionDeleteMonitoredItems::SPtr serviceTransactionDeleteMonitoredItems) {};
	    virtual void monitoredItemServiceModifyMonitoredItemsResponse(ServiceTransactionModifyMonitoredItems::SPtr serviceTransactionModifyMonitoredItems) {};
	    virtual void monitoredItemServiceSetMonitoringModeResponse(ServiceTransactionSetMonitoringMode::SPtr serviceTransactionSetMonitoringMode) {};
	    virtual void monitoredItemServiceSetTriggeringResponse(ServiceTransactionSetTriggering::SPtr serviceTransactionSetTriggering) {};
	};

	class DLLEXPORT MonitoredItemServiceIfTestHandler
	: public MonitoredItemServiceIf
	{
	  public:
		MonitoredItemServiceIfTestHandler(void);
		virtual ~MonitoredItemServiceIfTestHandler(void);

		Condition monitoredItemServiceCreateMonitoredItemsResponse_;
	    void monitoredItemServiceCreateMonitoredItemsResponse(ServiceTransactionCreateMonitoredItems::SPtr serviceTransactionCreateMonitoredItems);
	    Condition monitoredItemServiceDeleteMonitoredItemsResponse_;
	    void monitoredItemServiceDeleteMonitoredItemsResponse(ServiceTransactionDeleteMonitoredItems::SPtr serviceTransactionDeleteMonitoredItems);
	    Condition monitoredItemServiceModifyMonitoredItemsResponse_;
	    void monitoredItemServiceModifyMonitoredItemsResponse(ServiceTransactionModifyMonitoredItems::SPtr serviceTransactionModifyMonitoredItems);
	    Condition monitoredItemServiceSetMonitoringModeResponse_;
	    void monitoredItemServiceSetMonitoringModeResponse(ServiceTransactionSetMonitoringMode::SPtr serviceTransactionSetMonitoringMode);
	    Condition monitoredItemServiceSetTriggeringResponse_;
	    void monitoredItemServiceSetTriggeringResponse(ServiceTransactionSetTriggering::SPtr serviceTransactionSetTriggering);
	};

}

#endif
