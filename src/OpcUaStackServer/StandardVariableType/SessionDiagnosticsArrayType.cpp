/*
    VariableTypeClass: SessionDiagnosticsArrayType

    Generated Source Code - please do not change this source code

    VariableTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackServer/StandardVariableType/SessionDiagnosticsArrayType.h"

namespace OpcUaStackServer
{
    
    SessionDiagnosticsArrayType::SessionDiagnosticsArrayType(void)
    : VariableBase()
    , sessionDiagnostics_ActualSessionTimeout_Variable_(boost::make_shared<ServerVariable>("SessionDiagnostics_ActualSessionTimeout_Variable"))
    , sessionDiagnostics_AddNodesCount_Variable_(boost::make_shared<ServerVariable>("SessionDiagnostics_AddNodesCount_Variable"))
    , sessionDiagnostics_AddReferencesCount_Variable_(boost::make_shared<ServerVariable>("SessionDiagnostics_AddReferencesCount_Variable"))
    , sessionDiagnostics_BrowseCount_Variable_(boost::make_shared<ServerVariable>("SessionDiagnostics_BrowseCount_Variable"))
    , sessionDiagnostics_BrowseNextCount_Variable_(boost::make_shared<ServerVariable>("SessionDiagnostics_BrowseNextCount_Variable"))
    , sessionDiagnostics_CallCount_Variable_(boost::make_shared<ServerVariable>("SessionDiagnostics_CallCount_Variable"))
    , sessionDiagnostics_ClientConnectionTime_Variable_(boost::make_shared<ServerVariable>("SessionDiagnostics_ClientConnectionTime_Variable"))
    , sessionDiagnostics_ClientDescription_Variable_(boost::make_shared<ServerVariable>("SessionDiagnostics_ClientDescription_Variable"))
    , sessionDiagnostics_ClientLastContactTime_Variable_(boost::make_shared<ServerVariable>("SessionDiagnostics_ClientLastContactTime_Variable"))
    , sessionDiagnostics_CreateMonitoredItemsCount_Variable_(boost::make_shared<ServerVariable>("SessionDiagnostics_CreateMonitoredItemsCount_Variable"))
    , sessionDiagnostics_CreateSubscriptionCount_Variable_(boost::make_shared<ServerVariable>("SessionDiagnostics_CreateSubscriptionCount_Variable"))
    , sessionDiagnostics_CurrentMonitoredItemsCount_Variable_(boost::make_shared<ServerVariable>("SessionDiagnostics_CurrentMonitoredItemsCount_Variable"))
    , sessionDiagnostics_CurrentPublishRequestsInQueue_Variable_(boost::make_shared<ServerVariable>("SessionDiagnostics_CurrentPublishRequestsInQueue_Variable"))
    , sessionDiagnostics_CurrentSubscriptionsCount_Variable_(boost::make_shared<ServerVariable>("SessionDiagnostics_CurrentSubscriptionsCount_Variable"))
    , sessionDiagnostics_DeleteMonitoredItemsCount_Variable_(boost::make_shared<ServerVariable>("SessionDiagnostics_DeleteMonitoredItemsCount_Variable"))
    , sessionDiagnostics_DeleteNodesCount_Variable_(boost::make_shared<ServerVariable>("SessionDiagnostics_DeleteNodesCount_Variable"))
    , sessionDiagnostics_DeleteReferencesCount_Variable_(boost::make_shared<ServerVariable>("SessionDiagnostics_DeleteReferencesCount_Variable"))
    , sessionDiagnostics_DeleteSubscriptionsCount_Variable_(boost::make_shared<ServerVariable>("SessionDiagnostics_DeleteSubscriptionsCount_Variable"))
    , sessionDiagnostics_EndpointUrl_Variable_(boost::make_shared<ServerVariable>("SessionDiagnostics_EndpointUrl_Variable"))
    , sessionDiagnostics_HistoryReadCount_Variable_(boost::make_shared<ServerVariable>("SessionDiagnostics_HistoryReadCount_Variable"))
    , sessionDiagnostics_HistoryUpdateCount_Variable_(boost::make_shared<ServerVariable>("SessionDiagnostics_HistoryUpdateCount_Variable"))
    , sessionDiagnostics_LocaleIds_Variable_(boost::make_shared<ServerVariable>("SessionDiagnostics_LocaleIds_Variable"))
    , sessionDiagnostics_MaxResponseMessageSize_Variable_(boost::make_shared<ServerVariable>("SessionDiagnostics_MaxResponseMessageSize_Variable"))
    , sessionDiagnostics_ModifyMonitoredItemsCount_Variable_(boost::make_shared<ServerVariable>("SessionDiagnostics_ModifyMonitoredItemsCount_Variable"))
    , sessionDiagnostics_ModifySubscriptionCount_Variable_(boost::make_shared<ServerVariable>("SessionDiagnostics_ModifySubscriptionCount_Variable"))
    , sessionDiagnostics_PublishCount_Variable_(boost::make_shared<ServerVariable>("SessionDiagnostics_PublishCount_Variable"))
    , sessionDiagnostics_QueryFirstCount_Variable_(boost::make_shared<ServerVariable>("SessionDiagnostics_QueryFirstCount_Variable"))
    , sessionDiagnostics_QueryNextCount_Variable_(boost::make_shared<ServerVariable>("SessionDiagnostics_QueryNextCount_Variable"))
    , sessionDiagnostics_ReadCount_Variable_(boost::make_shared<ServerVariable>("SessionDiagnostics_ReadCount_Variable"))
    , sessionDiagnostics_RegisterNodesCount_Variable_(boost::make_shared<ServerVariable>("SessionDiagnostics_RegisterNodesCount_Variable"))
    , sessionDiagnostics_RepublishCount_Variable_(boost::make_shared<ServerVariable>("SessionDiagnostics_RepublishCount_Variable"))
    , sessionDiagnostics_ServerUri_Variable_(boost::make_shared<ServerVariable>("SessionDiagnostics_ServerUri_Variable"))
    , sessionDiagnostics_SessionId_Variable_(boost::make_shared<ServerVariable>("SessionDiagnostics_SessionId_Variable"))
    , sessionDiagnostics_SessionName_Variable_(boost::make_shared<ServerVariable>("SessionDiagnostics_SessionName_Variable"))
    , sessionDiagnostics_SetMonitoringModeCount_Variable_(boost::make_shared<ServerVariable>("SessionDiagnostics_SetMonitoringModeCount_Variable"))
    , sessionDiagnostics_SetPublishingModeCount_Variable_(boost::make_shared<ServerVariable>("SessionDiagnostics_SetPublishingModeCount_Variable"))
    , sessionDiagnostics_SetTriggeringCount_Variable_(boost::make_shared<ServerVariable>("SessionDiagnostics_SetTriggeringCount_Variable"))
    , sessionDiagnostics_TotalRequestCount_Variable_(boost::make_shared<ServerVariable>("SessionDiagnostics_TotalRequestCount_Variable"))
    , sessionDiagnostics_TransferSubscriptionsCount_Variable_(boost::make_shared<ServerVariable>("SessionDiagnostics_TransferSubscriptionsCount_Variable"))
    , sessionDiagnostics_TranslateBrowsePathsToNodeIdsCount_Variable_(boost::make_shared<ServerVariable>("SessionDiagnostics_TranslateBrowsePathsToNodeIdsCount_Variable"))
    , sessionDiagnostics_UnauthorizedRequestCount_Variable_(boost::make_shared<ServerVariable>("SessionDiagnostics_UnauthorizedRequestCount_Variable"))
    , sessionDiagnostics_UnregisterNodesCount_Variable_(boost::make_shared<ServerVariable>("SessionDiagnostics_UnregisterNodesCount_Variable"))
    , sessionDiagnostics_Variable_(boost::make_shared<ServerVariable>("SessionDiagnostics_Variable"))
    , sessionDiagnostics_WriteCount_Variable_(boost::make_shared<ServerVariable>("SessionDiagnostics_WriteCount_Variable"))
    , variable_(boost::make_shared<ServerVariable>("Variable"))
    {
        variableTypeNamespaceName("http://opcfoundation.org/UA/");
        variableTypeNodeId((OpcUaUInt32)2196);
        setServerVariable(sessionDiagnostics_ActualSessionTimeout_Variable_);
        setServerVariable(sessionDiagnostics_AddNodesCount_Variable_);
        setServerVariable(sessionDiagnostics_AddReferencesCount_Variable_);
        setServerVariable(sessionDiagnostics_BrowseCount_Variable_);
        setServerVariable(sessionDiagnostics_BrowseNextCount_Variable_);
        setServerVariable(sessionDiagnostics_CallCount_Variable_);
        setServerVariable(sessionDiagnostics_ClientConnectionTime_Variable_);
        setServerVariable(sessionDiagnostics_ClientDescription_Variable_);
        setServerVariable(sessionDiagnostics_ClientLastContactTime_Variable_);
        setServerVariable(sessionDiagnostics_CreateMonitoredItemsCount_Variable_);
        setServerVariable(sessionDiagnostics_CreateSubscriptionCount_Variable_);
        setServerVariable(sessionDiagnostics_CurrentMonitoredItemsCount_Variable_);
        setServerVariable(sessionDiagnostics_CurrentPublishRequestsInQueue_Variable_);
        setServerVariable(sessionDiagnostics_CurrentSubscriptionsCount_Variable_);
        setServerVariable(sessionDiagnostics_DeleteMonitoredItemsCount_Variable_);
        setServerVariable(sessionDiagnostics_DeleteNodesCount_Variable_);
        setServerVariable(sessionDiagnostics_DeleteReferencesCount_Variable_);
        setServerVariable(sessionDiagnostics_DeleteSubscriptionsCount_Variable_);
        setServerVariable(sessionDiagnostics_EndpointUrl_Variable_);
        setServerVariable(sessionDiagnostics_HistoryReadCount_Variable_);
        setServerVariable(sessionDiagnostics_HistoryUpdateCount_Variable_);
        setServerVariable(sessionDiagnostics_LocaleIds_Variable_);
        setServerVariable(sessionDiagnostics_MaxResponseMessageSize_Variable_);
        setServerVariable(sessionDiagnostics_ModifyMonitoredItemsCount_Variable_);
        setServerVariable(sessionDiagnostics_ModifySubscriptionCount_Variable_);
        setServerVariable(sessionDiagnostics_PublishCount_Variable_);
        setServerVariable(sessionDiagnostics_QueryFirstCount_Variable_);
        setServerVariable(sessionDiagnostics_QueryNextCount_Variable_);
        setServerVariable(sessionDiagnostics_ReadCount_Variable_);
        setServerVariable(sessionDiagnostics_RegisterNodesCount_Variable_);
        setServerVariable(sessionDiagnostics_RepublishCount_Variable_);
        setServerVariable(sessionDiagnostics_ServerUri_Variable_);
        setServerVariable(sessionDiagnostics_SessionId_Variable_);
        setServerVariable(sessionDiagnostics_SessionName_Variable_);
        setServerVariable(sessionDiagnostics_SetMonitoringModeCount_Variable_);
        setServerVariable(sessionDiagnostics_SetPublishingModeCount_Variable_);
        setServerVariable(sessionDiagnostics_SetTriggeringCount_Variable_);
        setServerVariable(sessionDiagnostics_TotalRequestCount_Variable_);
        setServerVariable(sessionDiagnostics_TransferSubscriptionsCount_Variable_);
        setServerVariable(sessionDiagnostics_TranslateBrowsePathsToNodeIdsCount_Variable_);
        setServerVariable(sessionDiagnostics_UnauthorizedRequestCount_Variable_);
        setServerVariable(sessionDiagnostics_UnregisterNodesCount_Variable_);
        setServerVariable(sessionDiagnostics_Variable_);
        setServerVariable(sessionDiagnostics_WriteCount_Variable_);
        setServerVariable(variable_);
    }
    
    SessionDiagnosticsArrayType::SessionDiagnosticsArrayType(const SessionDiagnosticsArrayType& value)
    : VariableBase()
    , sessionDiagnostics_ActualSessionTimeout_Variable_(boost::make_shared<ServerVariable>("SessionDiagnostics_ActualSessionTimeout_Variable"))
    , sessionDiagnostics_AddNodesCount_Variable_(boost::make_shared<ServerVariable>("SessionDiagnostics_AddNodesCount_Variable"))
    , sessionDiagnostics_AddReferencesCount_Variable_(boost::make_shared<ServerVariable>("SessionDiagnostics_AddReferencesCount_Variable"))
    , sessionDiagnostics_BrowseCount_Variable_(boost::make_shared<ServerVariable>("SessionDiagnostics_BrowseCount_Variable"))
    , sessionDiagnostics_BrowseNextCount_Variable_(boost::make_shared<ServerVariable>("SessionDiagnostics_BrowseNextCount_Variable"))
    , sessionDiagnostics_CallCount_Variable_(boost::make_shared<ServerVariable>("SessionDiagnostics_CallCount_Variable"))
    , sessionDiagnostics_ClientConnectionTime_Variable_(boost::make_shared<ServerVariable>("SessionDiagnostics_ClientConnectionTime_Variable"))
    , sessionDiagnostics_ClientDescription_Variable_(boost::make_shared<ServerVariable>("SessionDiagnostics_ClientDescription_Variable"))
    , sessionDiagnostics_ClientLastContactTime_Variable_(boost::make_shared<ServerVariable>("SessionDiagnostics_ClientLastContactTime_Variable"))
    , sessionDiagnostics_CreateMonitoredItemsCount_Variable_(boost::make_shared<ServerVariable>("SessionDiagnostics_CreateMonitoredItemsCount_Variable"))
    , sessionDiagnostics_CreateSubscriptionCount_Variable_(boost::make_shared<ServerVariable>("SessionDiagnostics_CreateSubscriptionCount_Variable"))
    , sessionDiagnostics_CurrentMonitoredItemsCount_Variable_(boost::make_shared<ServerVariable>("SessionDiagnostics_CurrentMonitoredItemsCount_Variable"))
    , sessionDiagnostics_CurrentPublishRequestsInQueue_Variable_(boost::make_shared<ServerVariable>("SessionDiagnostics_CurrentPublishRequestsInQueue_Variable"))
    , sessionDiagnostics_CurrentSubscriptionsCount_Variable_(boost::make_shared<ServerVariable>("SessionDiagnostics_CurrentSubscriptionsCount_Variable"))
    , sessionDiagnostics_DeleteMonitoredItemsCount_Variable_(boost::make_shared<ServerVariable>("SessionDiagnostics_DeleteMonitoredItemsCount_Variable"))
    , sessionDiagnostics_DeleteNodesCount_Variable_(boost::make_shared<ServerVariable>("SessionDiagnostics_DeleteNodesCount_Variable"))
    , sessionDiagnostics_DeleteReferencesCount_Variable_(boost::make_shared<ServerVariable>("SessionDiagnostics_DeleteReferencesCount_Variable"))
    , sessionDiagnostics_DeleteSubscriptionsCount_Variable_(boost::make_shared<ServerVariable>("SessionDiagnostics_DeleteSubscriptionsCount_Variable"))
    , sessionDiagnostics_EndpointUrl_Variable_(boost::make_shared<ServerVariable>("SessionDiagnostics_EndpointUrl_Variable"))
    , sessionDiagnostics_HistoryReadCount_Variable_(boost::make_shared<ServerVariable>("SessionDiagnostics_HistoryReadCount_Variable"))
    , sessionDiagnostics_HistoryUpdateCount_Variable_(boost::make_shared<ServerVariable>("SessionDiagnostics_HistoryUpdateCount_Variable"))
    , sessionDiagnostics_LocaleIds_Variable_(boost::make_shared<ServerVariable>("SessionDiagnostics_LocaleIds_Variable"))
    , sessionDiagnostics_MaxResponseMessageSize_Variable_(boost::make_shared<ServerVariable>("SessionDiagnostics_MaxResponseMessageSize_Variable"))
    , sessionDiagnostics_ModifyMonitoredItemsCount_Variable_(boost::make_shared<ServerVariable>("SessionDiagnostics_ModifyMonitoredItemsCount_Variable"))
    , sessionDiagnostics_ModifySubscriptionCount_Variable_(boost::make_shared<ServerVariable>("SessionDiagnostics_ModifySubscriptionCount_Variable"))
    , sessionDiagnostics_PublishCount_Variable_(boost::make_shared<ServerVariable>("SessionDiagnostics_PublishCount_Variable"))
    , sessionDiagnostics_QueryFirstCount_Variable_(boost::make_shared<ServerVariable>("SessionDiagnostics_QueryFirstCount_Variable"))
    , sessionDiagnostics_QueryNextCount_Variable_(boost::make_shared<ServerVariable>("SessionDiagnostics_QueryNextCount_Variable"))
    , sessionDiagnostics_ReadCount_Variable_(boost::make_shared<ServerVariable>("SessionDiagnostics_ReadCount_Variable"))
    , sessionDiagnostics_RegisterNodesCount_Variable_(boost::make_shared<ServerVariable>("SessionDiagnostics_RegisterNodesCount_Variable"))
    , sessionDiagnostics_RepublishCount_Variable_(boost::make_shared<ServerVariable>("SessionDiagnostics_RepublishCount_Variable"))
    , sessionDiagnostics_ServerUri_Variable_(boost::make_shared<ServerVariable>("SessionDiagnostics_ServerUri_Variable"))
    , sessionDiagnostics_SessionId_Variable_(boost::make_shared<ServerVariable>("SessionDiagnostics_SessionId_Variable"))
    , sessionDiagnostics_SessionName_Variable_(boost::make_shared<ServerVariable>("SessionDiagnostics_SessionName_Variable"))
    , sessionDiagnostics_SetMonitoringModeCount_Variable_(boost::make_shared<ServerVariable>("SessionDiagnostics_SetMonitoringModeCount_Variable"))
    , sessionDiagnostics_SetPublishingModeCount_Variable_(boost::make_shared<ServerVariable>("SessionDiagnostics_SetPublishingModeCount_Variable"))
    , sessionDiagnostics_SetTriggeringCount_Variable_(boost::make_shared<ServerVariable>("SessionDiagnostics_SetTriggeringCount_Variable"))
    , sessionDiagnostics_TotalRequestCount_Variable_(boost::make_shared<ServerVariable>("SessionDiagnostics_TotalRequestCount_Variable"))
    , sessionDiagnostics_TransferSubscriptionsCount_Variable_(boost::make_shared<ServerVariable>("SessionDiagnostics_TransferSubscriptionsCount_Variable"))
    , sessionDiagnostics_TranslateBrowsePathsToNodeIdsCount_Variable_(boost::make_shared<ServerVariable>("SessionDiagnostics_TranslateBrowsePathsToNodeIdsCount_Variable"))
    , sessionDiagnostics_UnauthorizedRequestCount_Variable_(boost::make_shared<ServerVariable>("SessionDiagnostics_UnauthorizedRequestCount_Variable"))
    , sessionDiagnostics_UnregisterNodesCount_Variable_(boost::make_shared<ServerVariable>("SessionDiagnostics_UnregisterNodesCount_Variable"))
    , sessionDiagnostics_Variable_(boost::make_shared<ServerVariable>("SessionDiagnostics_Variable"))
    , sessionDiagnostics_WriteCount_Variable_(boost::make_shared<ServerVariable>("SessionDiagnostics_WriteCount_Variable"))
    , variable_(boost::make_shared<ServerVariable>("Variable"))
    {
        variableTypeNamespaceName("http://opcfoundation.org/UA/");
        variableTypeNodeId((OpcUaUInt32)2196);
        setServerVariable(sessionDiagnostics_ActualSessionTimeout_Variable_);
        setServerVariable(sessionDiagnostics_AddNodesCount_Variable_);
        setServerVariable(sessionDiagnostics_AddReferencesCount_Variable_);
        setServerVariable(sessionDiagnostics_BrowseCount_Variable_);
        setServerVariable(sessionDiagnostics_BrowseNextCount_Variable_);
        setServerVariable(sessionDiagnostics_CallCount_Variable_);
        setServerVariable(sessionDiagnostics_ClientConnectionTime_Variable_);
        setServerVariable(sessionDiagnostics_ClientDescription_Variable_);
        setServerVariable(sessionDiagnostics_ClientLastContactTime_Variable_);
        setServerVariable(sessionDiagnostics_CreateMonitoredItemsCount_Variable_);
        setServerVariable(sessionDiagnostics_CreateSubscriptionCount_Variable_);
        setServerVariable(sessionDiagnostics_CurrentMonitoredItemsCount_Variable_);
        setServerVariable(sessionDiagnostics_CurrentPublishRequestsInQueue_Variable_);
        setServerVariable(sessionDiagnostics_CurrentSubscriptionsCount_Variable_);
        setServerVariable(sessionDiagnostics_DeleteMonitoredItemsCount_Variable_);
        setServerVariable(sessionDiagnostics_DeleteNodesCount_Variable_);
        setServerVariable(sessionDiagnostics_DeleteReferencesCount_Variable_);
        setServerVariable(sessionDiagnostics_DeleteSubscriptionsCount_Variable_);
        setServerVariable(sessionDiagnostics_EndpointUrl_Variable_);
        setServerVariable(sessionDiagnostics_HistoryReadCount_Variable_);
        setServerVariable(sessionDiagnostics_HistoryUpdateCount_Variable_);
        setServerVariable(sessionDiagnostics_LocaleIds_Variable_);
        setServerVariable(sessionDiagnostics_MaxResponseMessageSize_Variable_);
        setServerVariable(sessionDiagnostics_ModifyMonitoredItemsCount_Variable_);
        setServerVariable(sessionDiagnostics_ModifySubscriptionCount_Variable_);
        setServerVariable(sessionDiagnostics_PublishCount_Variable_);
        setServerVariable(sessionDiagnostics_QueryFirstCount_Variable_);
        setServerVariable(sessionDiagnostics_QueryNextCount_Variable_);
        setServerVariable(sessionDiagnostics_ReadCount_Variable_);
        setServerVariable(sessionDiagnostics_RegisterNodesCount_Variable_);
        setServerVariable(sessionDiagnostics_RepublishCount_Variable_);
        setServerVariable(sessionDiagnostics_ServerUri_Variable_);
        setServerVariable(sessionDiagnostics_SessionId_Variable_);
        setServerVariable(sessionDiagnostics_SessionName_Variable_);
        setServerVariable(sessionDiagnostics_SetMonitoringModeCount_Variable_);
        setServerVariable(sessionDiagnostics_SetPublishingModeCount_Variable_);
        setServerVariable(sessionDiagnostics_SetTriggeringCount_Variable_);
        setServerVariable(sessionDiagnostics_TotalRequestCount_Variable_);
        setServerVariable(sessionDiagnostics_TransferSubscriptionsCount_Variable_);
        setServerVariable(sessionDiagnostics_TranslateBrowsePathsToNodeIdsCount_Variable_);
        setServerVariable(sessionDiagnostics_UnauthorizedRequestCount_Variable_);
        setServerVariable(sessionDiagnostics_UnregisterNodesCount_Variable_);
        setServerVariable(sessionDiagnostics_Variable_);
        setServerVariable(sessionDiagnostics_WriteCount_Variable_);
        setServerVariable(variable_);
    }
    
    SessionDiagnosticsArrayType::~SessionDiagnosticsArrayType(void)
    {
    }

    ServerVariable::SPtr&
    SessionDiagnosticsArrayType::sessionDiagnostics_ActualSessionTimeout_Variable(void)
    {
        return sessionDiagnostics_ActualSessionTimeout_Variable_;
    }

    ServerVariable::SPtr&
    SessionDiagnosticsArrayType::sessionDiagnostics_AddNodesCount_Variable(void)
    {
        return sessionDiagnostics_AddNodesCount_Variable_;
    }

    ServerVariable::SPtr&
    SessionDiagnosticsArrayType::sessionDiagnostics_AddReferencesCount_Variable(void)
    {
        return sessionDiagnostics_AddReferencesCount_Variable_;
    }

    ServerVariable::SPtr&
    SessionDiagnosticsArrayType::sessionDiagnostics_BrowseCount_Variable(void)
    {
        return sessionDiagnostics_BrowseCount_Variable_;
    }

    ServerVariable::SPtr&
    SessionDiagnosticsArrayType::sessionDiagnostics_BrowseNextCount_Variable(void)
    {
        return sessionDiagnostics_BrowseNextCount_Variable_;
    }

    ServerVariable::SPtr&
    SessionDiagnosticsArrayType::sessionDiagnostics_CallCount_Variable(void)
    {
        return sessionDiagnostics_CallCount_Variable_;
    }

    ServerVariable::SPtr&
    SessionDiagnosticsArrayType::sessionDiagnostics_ClientConnectionTime_Variable(void)
    {
        return sessionDiagnostics_ClientConnectionTime_Variable_;
    }

    ServerVariable::SPtr&
    SessionDiagnosticsArrayType::sessionDiagnostics_ClientDescription_Variable(void)
    {
        return sessionDiagnostics_ClientDescription_Variable_;
    }

    ServerVariable::SPtr&
    SessionDiagnosticsArrayType::sessionDiagnostics_ClientLastContactTime_Variable(void)
    {
        return sessionDiagnostics_ClientLastContactTime_Variable_;
    }

    ServerVariable::SPtr&
    SessionDiagnosticsArrayType::sessionDiagnostics_CreateMonitoredItemsCount_Variable(void)
    {
        return sessionDiagnostics_CreateMonitoredItemsCount_Variable_;
    }

    ServerVariable::SPtr&
    SessionDiagnosticsArrayType::sessionDiagnostics_CreateSubscriptionCount_Variable(void)
    {
        return sessionDiagnostics_CreateSubscriptionCount_Variable_;
    }

    ServerVariable::SPtr&
    SessionDiagnosticsArrayType::sessionDiagnostics_CurrentMonitoredItemsCount_Variable(void)
    {
        return sessionDiagnostics_CurrentMonitoredItemsCount_Variable_;
    }

    ServerVariable::SPtr&
    SessionDiagnosticsArrayType::sessionDiagnostics_CurrentPublishRequestsInQueue_Variable(void)
    {
        return sessionDiagnostics_CurrentPublishRequestsInQueue_Variable_;
    }

    ServerVariable::SPtr&
    SessionDiagnosticsArrayType::sessionDiagnostics_CurrentSubscriptionsCount_Variable(void)
    {
        return sessionDiagnostics_CurrentSubscriptionsCount_Variable_;
    }

    ServerVariable::SPtr&
    SessionDiagnosticsArrayType::sessionDiagnostics_DeleteMonitoredItemsCount_Variable(void)
    {
        return sessionDiagnostics_DeleteMonitoredItemsCount_Variable_;
    }

    ServerVariable::SPtr&
    SessionDiagnosticsArrayType::sessionDiagnostics_DeleteNodesCount_Variable(void)
    {
        return sessionDiagnostics_DeleteNodesCount_Variable_;
    }

    ServerVariable::SPtr&
    SessionDiagnosticsArrayType::sessionDiagnostics_DeleteReferencesCount_Variable(void)
    {
        return sessionDiagnostics_DeleteReferencesCount_Variable_;
    }

    ServerVariable::SPtr&
    SessionDiagnosticsArrayType::sessionDiagnostics_DeleteSubscriptionsCount_Variable(void)
    {
        return sessionDiagnostics_DeleteSubscriptionsCount_Variable_;
    }

    ServerVariable::SPtr&
    SessionDiagnosticsArrayType::sessionDiagnostics_EndpointUrl_Variable(void)
    {
        return sessionDiagnostics_EndpointUrl_Variable_;
    }

    ServerVariable::SPtr&
    SessionDiagnosticsArrayType::sessionDiagnostics_HistoryReadCount_Variable(void)
    {
        return sessionDiagnostics_HistoryReadCount_Variable_;
    }

    ServerVariable::SPtr&
    SessionDiagnosticsArrayType::sessionDiagnostics_HistoryUpdateCount_Variable(void)
    {
        return sessionDiagnostics_HistoryUpdateCount_Variable_;
    }

    ServerVariable::SPtr&
    SessionDiagnosticsArrayType::sessionDiagnostics_LocaleIds_Variable(void)
    {
        return sessionDiagnostics_LocaleIds_Variable_;
    }

    ServerVariable::SPtr&
    SessionDiagnosticsArrayType::sessionDiagnostics_MaxResponseMessageSize_Variable(void)
    {
        return sessionDiagnostics_MaxResponseMessageSize_Variable_;
    }

    ServerVariable::SPtr&
    SessionDiagnosticsArrayType::sessionDiagnostics_ModifyMonitoredItemsCount_Variable(void)
    {
        return sessionDiagnostics_ModifyMonitoredItemsCount_Variable_;
    }

    ServerVariable::SPtr&
    SessionDiagnosticsArrayType::sessionDiagnostics_ModifySubscriptionCount_Variable(void)
    {
        return sessionDiagnostics_ModifySubscriptionCount_Variable_;
    }

    ServerVariable::SPtr&
    SessionDiagnosticsArrayType::sessionDiagnostics_PublishCount_Variable(void)
    {
        return sessionDiagnostics_PublishCount_Variable_;
    }

    ServerVariable::SPtr&
    SessionDiagnosticsArrayType::sessionDiagnostics_QueryFirstCount_Variable(void)
    {
        return sessionDiagnostics_QueryFirstCount_Variable_;
    }

    ServerVariable::SPtr&
    SessionDiagnosticsArrayType::sessionDiagnostics_QueryNextCount_Variable(void)
    {
        return sessionDiagnostics_QueryNextCount_Variable_;
    }

    ServerVariable::SPtr&
    SessionDiagnosticsArrayType::sessionDiagnostics_ReadCount_Variable(void)
    {
        return sessionDiagnostics_ReadCount_Variable_;
    }

    ServerVariable::SPtr&
    SessionDiagnosticsArrayType::sessionDiagnostics_RegisterNodesCount_Variable(void)
    {
        return sessionDiagnostics_RegisterNodesCount_Variable_;
    }

    ServerVariable::SPtr&
    SessionDiagnosticsArrayType::sessionDiagnostics_RepublishCount_Variable(void)
    {
        return sessionDiagnostics_RepublishCount_Variable_;
    }

    ServerVariable::SPtr&
    SessionDiagnosticsArrayType::sessionDiagnostics_ServerUri_Variable(void)
    {
        return sessionDiagnostics_ServerUri_Variable_;
    }

    ServerVariable::SPtr&
    SessionDiagnosticsArrayType::sessionDiagnostics_SessionId_Variable(void)
    {
        return sessionDiagnostics_SessionId_Variable_;
    }

    ServerVariable::SPtr&
    SessionDiagnosticsArrayType::sessionDiagnostics_SessionName_Variable(void)
    {
        return sessionDiagnostics_SessionName_Variable_;
    }

    ServerVariable::SPtr&
    SessionDiagnosticsArrayType::sessionDiagnostics_SetMonitoringModeCount_Variable(void)
    {
        return sessionDiagnostics_SetMonitoringModeCount_Variable_;
    }

    ServerVariable::SPtr&
    SessionDiagnosticsArrayType::sessionDiagnostics_SetPublishingModeCount_Variable(void)
    {
        return sessionDiagnostics_SetPublishingModeCount_Variable_;
    }

    ServerVariable::SPtr&
    SessionDiagnosticsArrayType::sessionDiagnostics_SetTriggeringCount_Variable(void)
    {
        return sessionDiagnostics_SetTriggeringCount_Variable_;
    }

    ServerVariable::SPtr&
    SessionDiagnosticsArrayType::sessionDiagnostics_TotalRequestCount_Variable(void)
    {
        return sessionDiagnostics_TotalRequestCount_Variable_;
    }

    ServerVariable::SPtr&
    SessionDiagnosticsArrayType::sessionDiagnostics_TransferSubscriptionsCount_Variable(void)
    {
        return sessionDiagnostics_TransferSubscriptionsCount_Variable_;
    }

    ServerVariable::SPtr&
    SessionDiagnosticsArrayType::sessionDiagnostics_TranslateBrowsePathsToNodeIdsCount_Variable(void)
    {
        return sessionDiagnostics_TranslateBrowsePathsToNodeIdsCount_Variable_;
    }

    ServerVariable::SPtr&
    SessionDiagnosticsArrayType::sessionDiagnostics_UnauthorizedRequestCount_Variable(void)
    {
        return sessionDiagnostics_UnauthorizedRequestCount_Variable_;
    }

    ServerVariable::SPtr&
    SessionDiagnosticsArrayType::sessionDiagnostics_UnregisterNodesCount_Variable(void)
    {
        return sessionDiagnostics_UnregisterNodesCount_Variable_;
    }

    ServerVariable::SPtr&
    SessionDiagnosticsArrayType::sessionDiagnostics_Variable(void)
    {
        return sessionDiagnostics_Variable_;
    }

    ServerVariable::SPtr&
    SessionDiagnosticsArrayType::sessionDiagnostics_WriteCount_Variable(void)
    {
        return sessionDiagnostics_WriteCount_Variable_;
    }

    ServerVariable::SPtr&
    SessionDiagnosticsArrayType::variable(void)
    {
        return variable_;
    }

    void
    SessionDiagnosticsArrayType::sessionDiagnostics_ActualSessionTimeout_Variable(ServerVariable::SPtr& serverVariable)
    {
        sessionDiagnostics_ActualSessionTimeout_Variable_ = serverVariable;
    }

    void
    SessionDiagnosticsArrayType::sessionDiagnostics_AddNodesCount_Variable(ServerVariable::SPtr& serverVariable)
    {
        sessionDiagnostics_AddNodesCount_Variable_ = serverVariable;
    }

    void
    SessionDiagnosticsArrayType::sessionDiagnostics_AddReferencesCount_Variable(ServerVariable::SPtr& serverVariable)
    {
        sessionDiagnostics_AddReferencesCount_Variable_ = serverVariable;
    }

    void
    SessionDiagnosticsArrayType::sessionDiagnostics_BrowseCount_Variable(ServerVariable::SPtr& serverVariable)
    {
        sessionDiagnostics_BrowseCount_Variable_ = serverVariable;
    }

    void
    SessionDiagnosticsArrayType::sessionDiagnostics_BrowseNextCount_Variable(ServerVariable::SPtr& serverVariable)
    {
        sessionDiagnostics_BrowseNextCount_Variable_ = serverVariable;
    }

    void
    SessionDiagnosticsArrayType::sessionDiagnostics_CallCount_Variable(ServerVariable::SPtr& serverVariable)
    {
        sessionDiagnostics_CallCount_Variable_ = serverVariable;
    }

    void
    SessionDiagnosticsArrayType::sessionDiagnostics_ClientConnectionTime_Variable(ServerVariable::SPtr& serverVariable)
    {
        sessionDiagnostics_ClientConnectionTime_Variable_ = serverVariable;
    }

    void
    SessionDiagnosticsArrayType::sessionDiagnostics_ClientDescription_Variable(ServerVariable::SPtr& serverVariable)
    {
        sessionDiagnostics_ClientDescription_Variable_ = serverVariable;
    }

    void
    SessionDiagnosticsArrayType::sessionDiagnostics_ClientLastContactTime_Variable(ServerVariable::SPtr& serverVariable)
    {
        sessionDiagnostics_ClientLastContactTime_Variable_ = serverVariable;
    }

    void
    SessionDiagnosticsArrayType::sessionDiagnostics_CreateMonitoredItemsCount_Variable(ServerVariable::SPtr& serverVariable)
    {
        sessionDiagnostics_CreateMonitoredItemsCount_Variable_ = serverVariable;
    }

    void
    SessionDiagnosticsArrayType::sessionDiagnostics_CreateSubscriptionCount_Variable(ServerVariable::SPtr& serverVariable)
    {
        sessionDiagnostics_CreateSubscriptionCount_Variable_ = serverVariable;
    }

    void
    SessionDiagnosticsArrayType::sessionDiagnostics_CurrentMonitoredItemsCount_Variable(ServerVariable::SPtr& serverVariable)
    {
        sessionDiagnostics_CurrentMonitoredItemsCount_Variable_ = serverVariable;
    }

    void
    SessionDiagnosticsArrayType::sessionDiagnostics_CurrentPublishRequestsInQueue_Variable(ServerVariable::SPtr& serverVariable)
    {
        sessionDiagnostics_CurrentPublishRequestsInQueue_Variable_ = serverVariable;
    }

    void
    SessionDiagnosticsArrayType::sessionDiagnostics_CurrentSubscriptionsCount_Variable(ServerVariable::SPtr& serverVariable)
    {
        sessionDiagnostics_CurrentSubscriptionsCount_Variable_ = serverVariable;
    }

    void
    SessionDiagnosticsArrayType::sessionDiagnostics_DeleteMonitoredItemsCount_Variable(ServerVariable::SPtr& serverVariable)
    {
        sessionDiagnostics_DeleteMonitoredItemsCount_Variable_ = serverVariable;
    }

    void
    SessionDiagnosticsArrayType::sessionDiagnostics_DeleteNodesCount_Variable(ServerVariable::SPtr& serverVariable)
    {
        sessionDiagnostics_DeleteNodesCount_Variable_ = serverVariable;
    }

    void
    SessionDiagnosticsArrayType::sessionDiagnostics_DeleteReferencesCount_Variable(ServerVariable::SPtr& serverVariable)
    {
        sessionDiagnostics_DeleteReferencesCount_Variable_ = serverVariable;
    }

    void
    SessionDiagnosticsArrayType::sessionDiagnostics_DeleteSubscriptionsCount_Variable(ServerVariable::SPtr& serverVariable)
    {
        sessionDiagnostics_DeleteSubscriptionsCount_Variable_ = serverVariable;
    }

    void
    SessionDiagnosticsArrayType::sessionDiagnostics_EndpointUrl_Variable(ServerVariable::SPtr& serverVariable)
    {
        sessionDiagnostics_EndpointUrl_Variable_ = serverVariable;
    }

    void
    SessionDiagnosticsArrayType::sessionDiagnostics_HistoryReadCount_Variable(ServerVariable::SPtr& serverVariable)
    {
        sessionDiagnostics_HistoryReadCount_Variable_ = serverVariable;
    }

    void
    SessionDiagnosticsArrayType::sessionDiagnostics_HistoryUpdateCount_Variable(ServerVariable::SPtr& serverVariable)
    {
        sessionDiagnostics_HistoryUpdateCount_Variable_ = serverVariable;
    }

    void
    SessionDiagnosticsArrayType::sessionDiagnostics_LocaleIds_Variable(ServerVariable::SPtr& serverVariable)
    {
        sessionDiagnostics_LocaleIds_Variable_ = serverVariable;
    }

    void
    SessionDiagnosticsArrayType::sessionDiagnostics_MaxResponseMessageSize_Variable(ServerVariable::SPtr& serverVariable)
    {
        sessionDiagnostics_MaxResponseMessageSize_Variable_ = serverVariable;
    }

    void
    SessionDiagnosticsArrayType::sessionDiagnostics_ModifyMonitoredItemsCount_Variable(ServerVariable::SPtr& serverVariable)
    {
        sessionDiagnostics_ModifyMonitoredItemsCount_Variable_ = serverVariable;
    }

    void
    SessionDiagnosticsArrayType::sessionDiagnostics_ModifySubscriptionCount_Variable(ServerVariable::SPtr& serverVariable)
    {
        sessionDiagnostics_ModifySubscriptionCount_Variable_ = serverVariable;
    }

    void
    SessionDiagnosticsArrayType::sessionDiagnostics_PublishCount_Variable(ServerVariable::SPtr& serverVariable)
    {
        sessionDiagnostics_PublishCount_Variable_ = serverVariable;
    }

    void
    SessionDiagnosticsArrayType::sessionDiagnostics_QueryFirstCount_Variable(ServerVariable::SPtr& serverVariable)
    {
        sessionDiagnostics_QueryFirstCount_Variable_ = serverVariable;
    }

    void
    SessionDiagnosticsArrayType::sessionDiagnostics_QueryNextCount_Variable(ServerVariable::SPtr& serverVariable)
    {
        sessionDiagnostics_QueryNextCount_Variable_ = serverVariable;
    }

    void
    SessionDiagnosticsArrayType::sessionDiagnostics_ReadCount_Variable(ServerVariable::SPtr& serverVariable)
    {
        sessionDiagnostics_ReadCount_Variable_ = serverVariable;
    }

    void
    SessionDiagnosticsArrayType::sessionDiagnostics_RegisterNodesCount_Variable(ServerVariable::SPtr& serverVariable)
    {
        sessionDiagnostics_RegisterNodesCount_Variable_ = serverVariable;
    }

    void
    SessionDiagnosticsArrayType::sessionDiagnostics_RepublishCount_Variable(ServerVariable::SPtr& serverVariable)
    {
        sessionDiagnostics_RepublishCount_Variable_ = serverVariable;
    }

    void
    SessionDiagnosticsArrayType::sessionDiagnostics_ServerUri_Variable(ServerVariable::SPtr& serverVariable)
    {
        sessionDiagnostics_ServerUri_Variable_ = serverVariable;
    }

    void
    SessionDiagnosticsArrayType::sessionDiagnostics_SessionId_Variable(ServerVariable::SPtr& serverVariable)
    {
        sessionDiagnostics_SessionId_Variable_ = serverVariable;
    }

    void
    SessionDiagnosticsArrayType::sessionDiagnostics_SessionName_Variable(ServerVariable::SPtr& serverVariable)
    {
        sessionDiagnostics_SessionName_Variable_ = serverVariable;
    }

    void
    SessionDiagnosticsArrayType::sessionDiagnostics_SetMonitoringModeCount_Variable(ServerVariable::SPtr& serverVariable)
    {
        sessionDiagnostics_SetMonitoringModeCount_Variable_ = serverVariable;
    }

    void
    SessionDiagnosticsArrayType::sessionDiagnostics_SetPublishingModeCount_Variable(ServerVariable::SPtr& serverVariable)
    {
        sessionDiagnostics_SetPublishingModeCount_Variable_ = serverVariable;
    }

    void
    SessionDiagnosticsArrayType::sessionDiagnostics_SetTriggeringCount_Variable(ServerVariable::SPtr& serverVariable)
    {
        sessionDiagnostics_SetTriggeringCount_Variable_ = serverVariable;
    }

    void
    SessionDiagnosticsArrayType::sessionDiagnostics_TotalRequestCount_Variable(ServerVariable::SPtr& serverVariable)
    {
        sessionDiagnostics_TotalRequestCount_Variable_ = serverVariable;
    }

    void
    SessionDiagnosticsArrayType::sessionDiagnostics_TransferSubscriptionsCount_Variable(ServerVariable::SPtr& serverVariable)
    {
        sessionDiagnostics_TransferSubscriptionsCount_Variable_ = serverVariable;
    }

    void
    SessionDiagnosticsArrayType::sessionDiagnostics_TranslateBrowsePathsToNodeIdsCount_Variable(ServerVariable::SPtr& serverVariable)
    {
        sessionDiagnostics_TranslateBrowsePathsToNodeIdsCount_Variable_ = serverVariable;
    }

    void
    SessionDiagnosticsArrayType::sessionDiagnostics_UnauthorizedRequestCount_Variable(ServerVariable::SPtr& serverVariable)
    {
        sessionDiagnostics_UnauthorizedRequestCount_Variable_ = serverVariable;
    }

    void
    SessionDiagnosticsArrayType::sessionDiagnostics_UnregisterNodesCount_Variable(ServerVariable::SPtr& serverVariable)
    {
        sessionDiagnostics_UnregisterNodesCount_Variable_ = serverVariable;
    }

    void
    SessionDiagnosticsArrayType::sessionDiagnostics_Variable(ServerVariable::SPtr& serverVariable)
    {
        sessionDiagnostics_Variable_ = serverVariable;
    }

    void
    SessionDiagnosticsArrayType::sessionDiagnostics_WriteCount_Variable(ServerVariable::SPtr& serverVariable)
    {
        sessionDiagnostics_WriteCount_Variable_ = serverVariable;
    }

    void
    SessionDiagnosticsArrayType::variable(ServerVariable::SPtr& serverVariable)
    {
        variable_ = serverVariable;
    }

    bool
    SessionDiagnosticsArrayType::get_SessionDiagnostics_ActualSessionTimeout_Variable(OpcUaDataValue& dataValue)
    {
        return sessionDiagnostics_ActualSessionTimeout_Variable_->getDataValue(dataValue);
    }

    bool
    SessionDiagnosticsArrayType::get_SessionDiagnostics_AddNodesCount_Variable(OpcUaDataValue& dataValue)
    {
        return sessionDiagnostics_AddNodesCount_Variable_->getDataValue(dataValue);
    }

    bool
    SessionDiagnosticsArrayType::get_SessionDiagnostics_AddReferencesCount_Variable(OpcUaDataValue& dataValue)
    {
        return sessionDiagnostics_AddReferencesCount_Variable_->getDataValue(dataValue);
    }

    bool
    SessionDiagnosticsArrayType::get_SessionDiagnostics_BrowseCount_Variable(OpcUaDataValue& dataValue)
    {
        return sessionDiagnostics_BrowseCount_Variable_->getDataValue(dataValue);
    }

    bool
    SessionDiagnosticsArrayType::get_SessionDiagnostics_BrowseNextCount_Variable(OpcUaDataValue& dataValue)
    {
        return sessionDiagnostics_BrowseNextCount_Variable_->getDataValue(dataValue);
    }

    bool
    SessionDiagnosticsArrayType::get_SessionDiagnostics_CallCount_Variable(OpcUaDataValue& dataValue)
    {
        return sessionDiagnostics_CallCount_Variable_->getDataValue(dataValue);
    }

    bool
    SessionDiagnosticsArrayType::get_SessionDiagnostics_ClientConnectionTime_Variable(OpcUaDataValue& dataValue)
    {
        return sessionDiagnostics_ClientConnectionTime_Variable_->getDataValue(dataValue);
    }

    bool
    SessionDiagnosticsArrayType::get_SessionDiagnostics_ClientDescription_Variable(OpcUaDataValue& dataValue)
    {
        return sessionDiagnostics_ClientDescription_Variable_->getDataValue(dataValue);
    }

    bool
    SessionDiagnosticsArrayType::get_SessionDiagnostics_ClientLastContactTime_Variable(OpcUaDataValue& dataValue)
    {
        return sessionDiagnostics_ClientLastContactTime_Variable_->getDataValue(dataValue);
    }

    bool
    SessionDiagnosticsArrayType::get_SessionDiagnostics_CreateMonitoredItemsCount_Variable(OpcUaDataValue& dataValue)
    {
        return sessionDiagnostics_CreateMonitoredItemsCount_Variable_->getDataValue(dataValue);
    }

    bool
    SessionDiagnosticsArrayType::get_SessionDiagnostics_CreateSubscriptionCount_Variable(OpcUaDataValue& dataValue)
    {
        return sessionDiagnostics_CreateSubscriptionCount_Variable_->getDataValue(dataValue);
    }

    bool
    SessionDiagnosticsArrayType::get_SessionDiagnostics_CurrentMonitoredItemsCount_Variable(OpcUaDataValue& dataValue)
    {
        return sessionDiagnostics_CurrentMonitoredItemsCount_Variable_->getDataValue(dataValue);
    }

    bool
    SessionDiagnosticsArrayType::get_SessionDiagnostics_CurrentPublishRequestsInQueue_Variable(OpcUaDataValue& dataValue)
    {
        return sessionDiagnostics_CurrentPublishRequestsInQueue_Variable_->getDataValue(dataValue);
    }

    bool
    SessionDiagnosticsArrayType::get_SessionDiagnostics_CurrentSubscriptionsCount_Variable(OpcUaDataValue& dataValue)
    {
        return sessionDiagnostics_CurrentSubscriptionsCount_Variable_->getDataValue(dataValue);
    }

    bool
    SessionDiagnosticsArrayType::get_SessionDiagnostics_DeleteMonitoredItemsCount_Variable(OpcUaDataValue& dataValue)
    {
        return sessionDiagnostics_DeleteMonitoredItemsCount_Variable_->getDataValue(dataValue);
    }

    bool
    SessionDiagnosticsArrayType::get_SessionDiagnostics_DeleteNodesCount_Variable(OpcUaDataValue& dataValue)
    {
        return sessionDiagnostics_DeleteNodesCount_Variable_->getDataValue(dataValue);
    }

    bool
    SessionDiagnosticsArrayType::get_SessionDiagnostics_DeleteReferencesCount_Variable(OpcUaDataValue& dataValue)
    {
        return sessionDiagnostics_DeleteReferencesCount_Variable_->getDataValue(dataValue);
    }

    bool
    SessionDiagnosticsArrayType::get_SessionDiagnostics_DeleteSubscriptionsCount_Variable(OpcUaDataValue& dataValue)
    {
        return sessionDiagnostics_DeleteSubscriptionsCount_Variable_->getDataValue(dataValue);
    }

    bool
    SessionDiagnosticsArrayType::get_SessionDiagnostics_EndpointUrl_Variable(OpcUaDataValue& dataValue)
    {
        return sessionDiagnostics_EndpointUrl_Variable_->getDataValue(dataValue);
    }

    bool
    SessionDiagnosticsArrayType::get_SessionDiagnostics_HistoryReadCount_Variable(OpcUaDataValue& dataValue)
    {
        return sessionDiagnostics_HistoryReadCount_Variable_->getDataValue(dataValue);
    }

    bool
    SessionDiagnosticsArrayType::get_SessionDiagnostics_HistoryUpdateCount_Variable(OpcUaDataValue& dataValue)
    {
        return sessionDiagnostics_HistoryUpdateCount_Variable_->getDataValue(dataValue);
    }

    bool
    SessionDiagnosticsArrayType::get_SessionDiagnostics_LocaleIds_Variable(OpcUaDataValue& dataValue)
    {
        return sessionDiagnostics_LocaleIds_Variable_->getDataValue(dataValue);
    }

    bool
    SessionDiagnosticsArrayType::get_SessionDiagnostics_MaxResponseMessageSize_Variable(OpcUaDataValue& dataValue)
    {
        return sessionDiagnostics_MaxResponseMessageSize_Variable_->getDataValue(dataValue);
    }

    bool
    SessionDiagnosticsArrayType::get_SessionDiagnostics_ModifyMonitoredItemsCount_Variable(OpcUaDataValue& dataValue)
    {
        return sessionDiagnostics_ModifyMonitoredItemsCount_Variable_->getDataValue(dataValue);
    }

    bool
    SessionDiagnosticsArrayType::get_SessionDiagnostics_ModifySubscriptionCount_Variable(OpcUaDataValue& dataValue)
    {
        return sessionDiagnostics_ModifySubscriptionCount_Variable_->getDataValue(dataValue);
    }

    bool
    SessionDiagnosticsArrayType::get_SessionDiagnostics_PublishCount_Variable(OpcUaDataValue& dataValue)
    {
        return sessionDiagnostics_PublishCount_Variable_->getDataValue(dataValue);
    }

    bool
    SessionDiagnosticsArrayType::get_SessionDiagnostics_QueryFirstCount_Variable(OpcUaDataValue& dataValue)
    {
        return sessionDiagnostics_QueryFirstCount_Variable_->getDataValue(dataValue);
    }

    bool
    SessionDiagnosticsArrayType::get_SessionDiagnostics_QueryNextCount_Variable(OpcUaDataValue& dataValue)
    {
        return sessionDiagnostics_QueryNextCount_Variable_->getDataValue(dataValue);
    }

    bool
    SessionDiagnosticsArrayType::get_SessionDiagnostics_ReadCount_Variable(OpcUaDataValue& dataValue)
    {
        return sessionDiagnostics_ReadCount_Variable_->getDataValue(dataValue);
    }

    bool
    SessionDiagnosticsArrayType::get_SessionDiagnostics_RegisterNodesCount_Variable(OpcUaDataValue& dataValue)
    {
        return sessionDiagnostics_RegisterNodesCount_Variable_->getDataValue(dataValue);
    }

    bool
    SessionDiagnosticsArrayType::get_SessionDiagnostics_RepublishCount_Variable(OpcUaDataValue& dataValue)
    {
        return sessionDiagnostics_RepublishCount_Variable_->getDataValue(dataValue);
    }

    bool
    SessionDiagnosticsArrayType::get_SessionDiagnostics_ServerUri_Variable(OpcUaDataValue& dataValue)
    {
        return sessionDiagnostics_ServerUri_Variable_->getDataValue(dataValue);
    }

    bool
    SessionDiagnosticsArrayType::get_SessionDiagnostics_SessionId_Variable(OpcUaDataValue& dataValue)
    {
        return sessionDiagnostics_SessionId_Variable_->getDataValue(dataValue);
    }

    bool
    SessionDiagnosticsArrayType::get_SessionDiagnostics_SessionName_Variable(OpcUaDataValue& dataValue)
    {
        return sessionDiagnostics_SessionName_Variable_->getDataValue(dataValue);
    }

    bool
    SessionDiagnosticsArrayType::get_SessionDiagnostics_SetMonitoringModeCount_Variable(OpcUaDataValue& dataValue)
    {
        return sessionDiagnostics_SetMonitoringModeCount_Variable_->getDataValue(dataValue);
    }

    bool
    SessionDiagnosticsArrayType::get_SessionDiagnostics_SetPublishingModeCount_Variable(OpcUaDataValue& dataValue)
    {
        return sessionDiagnostics_SetPublishingModeCount_Variable_->getDataValue(dataValue);
    }

    bool
    SessionDiagnosticsArrayType::get_SessionDiagnostics_SetTriggeringCount_Variable(OpcUaDataValue& dataValue)
    {
        return sessionDiagnostics_SetTriggeringCount_Variable_->getDataValue(dataValue);
    }

    bool
    SessionDiagnosticsArrayType::get_SessionDiagnostics_TotalRequestCount_Variable(OpcUaDataValue& dataValue)
    {
        return sessionDiagnostics_TotalRequestCount_Variable_->getDataValue(dataValue);
    }

    bool
    SessionDiagnosticsArrayType::get_SessionDiagnostics_TransferSubscriptionsCount_Variable(OpcUaDataValue& dataValue)
    {
        return sessionDiagnostics_TransferSubscriptionsCount_Variable_->getDataValue(dataValue);
    }

    bool
    SessionDiagnosticsArrayType::get_SessionDiagnostics_TranslateBrowsePathsToNodeIdsCount_Variable(OpcUaDataValue& dataValue)
    {
        return sessionDiagnostics_TranslateBrowsePathsToNodeIdsCount_Variable_->getDataValue(dataValue);
    }

    bool
    SessionDiagnosticsArrayType::get_SessionDiagnostics_UnauthorizedRequestCount_Variable(OpcUaDataValue& dataValue)
    {
        return sessionDiagnostics_UnauthorizedRequestCount_Variable_->getDataValue(dataValue);
    }

    bool
    SessionDiagnosticsArrayType::get_SessionDiagnostics_UnregisterNodesCount_Variable(OpcUaDataValue& dataValue)
    {
        return sessionDiagnostics_UnregisterNodesCount_Variable_->getDataValue(dataValue);
    }

    bool
    SessionDiagnosticsArrayType::get_SessionDiagnostics_Variable(OpcUaDataValue& dataValue)
    {
        return sessionDiagnostics_Variable_->getDataValue(dataValue);
    }

    bool
    SessionDiagnosticsArrayType::get_SessionDiagnostics_WriteCount_Variable(OpcUaDataValue& dataValue)
    {
        return sessionDiagnostics_WriteCount_Variable_->getDataValue(dataValue);
    }

    bool
    SessionDiagnosticsArrayType::get_Variable(OpcUaDataValue& dataValue)
    {
        return variable_->getDataValue(dataValue);
    }

    bool
    SessionDiagnosticsArrayType::set_SessionDiagnostics_ActualSessionTimeout_Variable(const OpcUaDataValue& dataValue)
    {
        return sessionDiagnostics_ActualSessionTimeout_Variable_->setDataValue(dataValue);
    }

    bool
    SessionDiagnosticsArrayType::set_SessionDiagnostics_AddNodesCount_Variable(const OpcUaDataValue& dataValue)
    {
        return sessionDiagnostics_AddNodesCount_Variable_->setDataValue(dataValue);
    }

    bool
    SessionDiagnosticsArrayType::set_SessionDiagnostics_AddReferencesCount_Variable(const OpcUaDataValue& dataValue)
    {
        return sessionDiagnostics_AddReferencesCount_Variable_->setDataValue(dataValue);
    }

    bool
    SessionDiagnosticsArrayType::set_SessionDiagnostics_BrowseCount_Variable(const OpcUaDataValue& dataValue)
    {
        return sessionDiagnostics_BrowseCount_Variable_->setDataValue(dataValue);
    }

    bool
    SessionDiagnosticsArrayType::set_SessionDiagnostics_BrowseNextCount_Variable(const OpcUaDataValue& dataValue)
    {
        return sessionDiagnostics_BrowseNextCount_Variable_->setDataValue(dataValue);
    }

    bool
    SessionDiagnosticsArrayType::set_SessionDiagnostics_CallCount_Variable(const OpcUaDataValue& dataValue)
    {
        return sessionDiagnostics_CallCount_Variable_->setDataValue(dataValue);
    }

    bool
    SessionDiagnosticsArrayType::set_SessionDiagnostics_ClientConnectionTime_Variable(const OpcUaDataValue& dataValue)
    {
        return sessionDiagnostics_ClientConnectionTime_Variable_->setDataValue(dataValue);
    }

    bool
    SessionDiagnosticsArrayType::set_SessionDiagnostics_ClientDescription_Variable(const OpcUaDataValue& dataValue)
    {
        return sessionDiagnostics_ClientDescription_Variable_->setDataValue(dataValue);
    }

    bool
    SessionDiagnosticsArrayType::set_SessionDiagnostics_ClientLastContactTime_Variable(const OpcUaDataValue& dataValue)
    {
        return sessionDiagnostics_ClientLastContactTime_Variable_->setDataValue(dataValue);
    }

    bool
    SessionDiagnosticsArrayType::set_SessionDiagnostics_CreateMonitoredItemsCount_Variable(const OpcUaDataValue& dataValue)
    {
        return sessionDiagnostics_CreateMonitoredItemsCount_Variable_->setDataValue(dataValue);
    }

    bool
    SessionDiagnosticsArrayType::set_SessionDiagnostics_CreateSubscriptionCount_Variable(const OpcUaDataValue& dataValue)
    {
        return sessionDiagnostics_CreateSubscriptionCount_Variable_->setDataValue(dataValue);
    }

    bool
    SessionDiagnosticsArrayType::set_SessionDiagnostics_CurrentMonitoredItemsCount_Variable(const OpcUaDataValue& dataValue)
    {
        return sessionDiagnostics_CurrentMonitoredItemsCount_Variable_->setDataValue(dataValue);
    }

    bool
    SessionDiagnosticsArrayType::set_SessionDiagnostics_CurrentPublishRequestsInQueue_Variable(const OpcUaDataValue& dataValue)
    {
        return sessionDiagnostics_CurrentPublishRequestsInQueue_Variable_->setDataValue(dataValue);
    }

    bool
    SessionDiagnosticsArrayType::set_SessionDiagnostics_CurrentSubscriptionsCount_Variable(const OpcUaDataValue& dataValue)
    {
        return sessionDiagnostics_CurrentSubscriptionsCount_Variable_->setDataValue(dataValue);
    }

    bool
    SessionDiagnosticsArrayType::set_SessionDiagnostics_DeleteMonitoredItemsCount_Variable(const OpcUaDataValue& dataValue)
    {
        return sessionDiagnostics_DeleteMonitoredItemsCount_Variable_->setDataValue(dataValue);
    }

    bool
    SessionDiagnosticsArrayType::set_SessionDiagnostics_DeleteNodesCount_Variable(const OpcUaDataValue& dataValue)
    {
        return sessionDiagnostics_DeleteNodesCount_Variable_->setDataValue(dataValue);
    }

    bool
    SessionDiagnosticsArrayType::set_SessionDiagnostics_DeleteReferencesCount_Variable(const OpcUaDataValue& dataValue)
    {
        return sessionDiagnostics_DeleteReferencesCount_Variable_->setDataValue(dataValue);
    }

    bool
    SessionDiagnosticsArrayType::set_SessionDiagnostics_DeleteSubscriptionsCount_Variable(const OpcUaDataValue& dataValue)
    {
        return sessionDiagnostics_DeleteSubscriptionsCount_Variable_->setDataValue(dataValue);
    }

    bool
    SessionDiagnosticsArrayType::set_SessionDiagnostics_EndpointUrl_Variable(const OpcUaDataValue& dataValue)
    {
        return sessionDiagnostics_EndpointUrl_Variable_->setDataValue(dataValue);
    }

    bool
    SessionDiagnosticsArrayType::set_SessionDiagnostics_HistoryReadCount_Variable(const OpcUaDataValue& dataValue)
    {
        return sessionDiagnostics_HistoryReadCount_Variable_->setDataValue(dataValue);
    }

    bool
    SessionDiagnosticsArrayType::set_SessionDiagnostics_HistoryUpdateCount_Variable(const OpcUaDataValue& dataValue)
    {
        return sessionDiagnostics_HistoryUpdateCount_Variable_->setDataValue(dataValue);
    }

    bool
    SessionDiagnosticsArrayType::set_SessionDiagnostics_LocaleIds_Variable(const OpcUaDataValue& dataValue)
    {
        return sessionDiagnostics_LocaleIds_Variable_->setDataValue(dataValue);
    }

    bool
    SessionDiagnosticsArrayType::set_SessionDiagnostics_MaxResponseMessageSize_Variable(const OpcUaDataValue& dataValue)
    {
        return sessionDiagnostics_MaxResponseMessageSize_Variable_->setDataValue(dataValue);
    }

    bool
    SessionDiagnosticsArrayType::set_SessionDiagnostics_ModifyMonitoredItemsCount_Variable(const OpcUaDataValue& dataValue)
    {
        return sessionDiagnostics_ModifyMonitoredItemsCount_Variable_->setDataValue(dataValue);
    }

    bool
    SessionDiagnosticsArrayType::set_SessionDiagnostics_ModifySubscriptionCount_Variable(const OpcUaDataValue& dataValue)
    {
        return sessionDiagnostics_ModifySubscriptionCount_Variable_->setDataValue(dataValue);
    }

    bool
    SessionDiagnosticsArrayType::set_SessionDiagnostics_PublishCount_Variable(const OpcUaDataValue& dataValue)
    {
        return sessionDiagnostics_PublishCount_Variable_->setDataValue(dataValue);
    }

    bool
    SessionDiagnosticsArrayType::set_SessionDiagnostics_QueryFirstCount_Variable(const OpcUaDataValue& dataValue)
    {
        return sessionDiagnostics_QueryFirstCount_Variable_->setDataValue(dataValue);
    }

    bool
    SessionDiagnosticsArrayType::set_SessionDiagnostics_QueryNextCount_Variable(const OpcUaDataValue& dataValue)
    {
        return sessionDiagnostics_QueryNextCount_Variable_->setDataValue(dataValue);
    }

    bool
    SessionDiagnosticsArrayType::set_SessionDiagnostics_ReadCount_Variable(const OpcUaDataValue& dataValue)
    {
        return sessionDiagnostics_ReadCount_Variable_->setDataValue(dataValue);
    }

    bool
    SessionDiagnosticsArrayType::set_SessionDiagnostics_RegisterNodesCount_Variable(const OpcUaDataValue& dataValue)
    {
        return sessionDiagnostics_RegisterNodesCount_Variable_->setDataValue(dataValue);
    }

    bool
    SessionDiagnosticsArrayType::set_SessionDiagnostics_RepublishCount_Variable(const OpcUaDataValue& dataValue)
    {
        return sessionDiagnostics_RepublishCount_Variable_->setDataValue(dataValue);
    }

    bool
    SessionDiagnosticsArrayType::set_SessionDiagnostics_ServerUri_Variable(const OpcUaDataValue& dataValue)
    {
        return sessionDiagnostics_ServerUri_Variable_->setDataValue(dataValue);
    }

    bool
    SessionDiagnosticsArrayType::set_SessionDiagnostics_SessionId_Variable(const OpcUaDataValue& dataValue)
    {
        return sessionDiagnostics_SessionId_Variable_->setDataValue(dataValue);
    }

    bool
    SessionDiagnosticsArrayType::set_SessionDiagnostics_SessionName_Variable(const OpcUaDataValue& dataValue)
    {
        return sessionDiagnostics_SessionName_Variable_->setDataValue(dataValue);
    }

    bool
    SessionDiagnosticsArrayType::set_SessionDiagnostics_SetMonitoringModeCount_Variable(const OpcUaDataValue& dataValue)
    {
        return sessionDiagnostics_SetMonitoringModeCount_Variable_->setDataValue(dataValue);
    }

    bool
    SessionDiagnosticsArrayType::set_SessionDiagnostics_SetPublishingModeCount_Variable(const OpcUaDataValue& dataValue)
    {
        return sessionDiagnostics_SetPublishingModeCount_Variable_->setDataValue(dataValue);
    }

    bool
    SessionDiagnosticsArrayType::set_SessionDiagnostics_SetTriggeringCount_Variable(const OpcUaDataValue& dataValue)
    {
        return sessionDiagnostics_SetTriggeringCount_Variable_->setDataValue(dataValue);
    }

    bool
    SessionDiagnosticsArrayType::set_SessionDiagnostics_TotalRequestCount_Variable(const OpcUaDataValue& dataValue)
    {
        return sessionDiagnostics_TotalRequestCount_Variable_->setDataValue(dataValue);
    }

    bool
    SessionDiagnosticsArrayType::set_SessionDiagnostics_TransferSubscriptionsCount_Variable(const OpcUaDataValue& dataValue)
    {
        return sessionDiagnostics_TransferSubscriptionsCount_Variable_->setDataValue(dataValue);
    }

    bool
    SessionDiagnosticsArrayType::set_SessionDiagnostics_TranslateBrowsePathsToNodeIdsCount_Variable(const OpcUaDataValue& dataValue)
    {
        return sessionDiagnostics_TranslateBrowsePathsToNodeIdsCount_Variable_->setDataValue(dataValue);
    }

    bool
    SessionDiagnosticsArrayType::set_SessionDiagnostics_UnauthorizedRequestCount_Variable(const OpcUaDataValue& dataValue)
    {
        return sessionDiagnostics_UnauthorizedRequestCount_Variable_->setDataValue(dataValue);
    }

    bool
    SessionDiagnosticsArrayType::set_SessionDiagnostics_UnregisterNodesCount_Variable(const OpcUaDataValue& dataValue)
    {
        return sessionDiagnostics_UnregisterNodesCount_Variable_->setDataValue(dataValue);
    }

    bool
    SessionDiagnosticsArrayType::set_SessionDiagnostics_Variable(const OpcUaDataValue& dataValue)
    {
        return sessionDiagnostics_Variable_->setDataValue(dataValue);
    }

    bool
    SessionDiagnosticsArrayType::set_SessionDiagnostics_WriteCount_Variable(const OpcUaDataValue& dataValue)
    {
        return sessionDiagnostics_WriteCount_Variable_->setDataValue(dataValue);
    }

    bool
    SessionDiagnosticsArrayType::set_Variable(const OpcUaDataValue& dataValue)
    {
        return variable_->setDataValue(dataValue);
    }

}
