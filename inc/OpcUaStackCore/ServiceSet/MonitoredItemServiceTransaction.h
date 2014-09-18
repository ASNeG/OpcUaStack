#ifndef __OpcUaStackCore_MonitoredItemServiceTransaction_h__
#define __OpcUaStackCore_MonitoredItemServiceTransaction_h__

#include "OpcUaStackCore/BuildInTypes/OpcUaIdentifier.h"
#include "OpcUaStackCore/ServiceSet/ServiceTransactionTemplate.h"
#include "OpcUaStackCore/ServiceSet/CreateMonitoredItemsRequest.h"
#include "OpcUaStackCore/ServiceSet/CreateMonitoredItemsResponse.h"
#include "OpcUaStackCore/ServiceSet/DeleteMonitoredItemsRequest.h"
#include "OpcUaStackCore/ServiceSet/DeleteMonitoredItemsResponse.h"
#include "OpcUaStackCore/ServiceSet/ModifyMonitoredItemsRequest.h"
#include "OpcUaStackCore/ServiceSet/ModifyMonitoredItemsResponse.h"
#include "OpcUaStackCore/ServiceSet/SetMonitoringModeRequest.h"
#include "OpcUaStackCore/ServiceSet/SetMonitoringModeResponse.h"
#include "OpcUaStackCore/ServiceSet/SetTriggeringRequest.h"
#include "OpcUaStackCore/ServiceSet/SetTriggeringResponse.h"


namespace OpcUaStackCore
{

	typedef ServiceTransactionTemplate<
		CreateMonitoredItemsRequest, 
		CreateMonitoredItemsResponse, 
		OpcUaId_CreateMonitoredItemsRequest_Encoding_DefaultBinary, 
		OpcUaId_CreateMonitoredItemsResponse_Encoding_DefaultBinary
	> ServiceTransactionCreateMonitoredItems;

	typedef ServiceTransactionTemplate<
		DeleteMonitoredItemsRequest, 
		DeleteMonitoredItemsResponse, 
		OpcUaId_DeleteMonitoredItemsRequest_Encoding_DefaultBinary, 
		OpcUaId_DeleteMonitoredItemsResponse_Encoding_DefaultBinary
	> ServiceTransactionDeleteMonitoredItems;

	typedef ServiceTransactionTemplate<
		ModifyMonitoredItemsRequest, 
		ModifyMonitoredItemsResponse, 
		OpcUaId_ModifyMonitoredItemsRequest_Encoding_DefaultBinary, 
		OpcUaId_ModifyMonitoredItemsResponse_Encoding_DefaultBinary
	> ServiceTransactionModifyMonitoredItems;

	typedef ServiceTransactionTemplate<
		SetMonitoringModeRequest, 
		SetMonitoringModeResponse, 
		OpcUaId_SetMonitoringModeRequest_Encoding_DefaultBinary, 
		OpcUaId_SetMonitoringModeResponse_Encoding_DefaultBinary
	> ServiceTransactionSetMonitoringMode;

	typedef ServiceTransactionTemplate<
		SetTriggeringRequest, 
		SetTriggeringResponse, 
		OpcUaId_SetTriggeringRequest_Encoding_DefaultBinary, 
		OpcUaId_SetTriggeringResponse_Encoding_DefaultBinary
	> ServiceTransactionSetTriggering;

}

#endif