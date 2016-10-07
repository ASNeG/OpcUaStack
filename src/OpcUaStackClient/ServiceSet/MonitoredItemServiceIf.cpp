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


#include "OpcUaStackClient/ServiceSet/MonitoredItemServiceIf.h"

namespace OpcUaStackClient
{
	MonitoredItemServiceIfTestHandler::MonitoredItemServiceIfTestHandler(void)
	: MonitoredItemServiceIf()
	, monitoredItemServiceCreateMonitoredItemsResponse_()
	, monitoredItemServiceDeleteMonitoredItemsResponse_()
	, monitoredItemServiceModifyMonitoredItemsResponse_()
	, monitoredItemServiceSetMonitoringModeResponse_()
	, monitoredItemServiceSetTriggeringResponse_()
	{
	}

	MonitoredItemServiceIfTestHandler::~MonitoredItemServiceIfTestHandler(void)
	{
	}

    void
    MonitoredItemServiceIfTestHandler::monitoredItemServiceCreateMonitoredItemsResponse(ServiceTransactionCreateMonitoredItems::SPtr serviceTransactionCreateMonitoredItems)
    {
    	monitoredItemServiceCreateMonitoredItemsResponse_.conditionValueDec();
    }

    void
    MonitoredItemServiceIfTestHandler::monitoredItemServiceDeleteMonitoredItemsResponse(ServiceTransactionDeleteMonitoredItems::SPtr serviceTransactionDeleteMonitoredItems)
    {
    	monitoredItemServiceDeleteMonitoredItemsResponse_.conditionValueDec();
    }

    void
    MonitoredItemServiceIfTestHandler::monitoredItemServiceModifyMonitoredItemsResponse(ServiceTransactionModifyMonitoredItems::SPtr serviceTransactionModifyMonitoredItems)
    {
    	monitoredItemServiceModifyMonitoredItemsResponse_.conditionValueDec();
    }

    void
    MonitoredItemServiceIfTestHandler::monitoredItemServiceSetMonitoringModeResponse(ServiceTransactionSetMonitoringMode::SPtr serviceTransactionSetMonitoringMode)
    {
    	monitoredItemServiceSetMonitoringModeResponse_.conditionValueDec();
    }

    void
    MonitoredItemServiceIfTestHandler::monitoredItemServiceSetTriggeringResponse(ServiceTransactionSetTriggering::SPtr serviceTransactionSetTriggering)
    {
    	monitoredItemServiceSetTriggeringResponse_.conditionValueDec();
    }
}
