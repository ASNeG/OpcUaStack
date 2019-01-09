/*
    VariableTypeClass: SubscriptionDiagnosticsArrayType

    Generated Source Code - please do not change this source code

    VariableTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackServer/StandardVariableType/SubscriptionDiagnosticsArrayType.h"

namespace OpcUaStackServer
{
    
    SubscriptionDiagnosticsArrayType::SubscriptionDiagnosticsArrayType(void)
    : VariableBase()
    , subscriptionDiagnostics_CurrentKeepAliveCount_Variable_(constructSPtr<ServerVariable>("SubscriptionDiagnostics_CurrentKeepAliveCount_Variable"))
    , subscriptionDiagnostics_CurrentLifetimeCount_Variable_(constructSPtr<ServerVariable>("SubscriptionDiagnostics_CurrentLifetimeCount_Variable"))
    , subscriptionDiagnostics_DataChangeNotificationsCount_Variable_(constructSPtr<ServerVariable>("SubscriptionDiagnostics_DataChangeNotificationsCount_Variable"))
    , subscriptionDiagnostics_DisableCount_Variable_(constructSPtr<ServerVariable>("SubscriptionDiagnostics_DisableCount_Variable"))
    , subscriptionDiagnostics_DisabledMonitoredItemCount_Variable_(constructSPtr<ServerVariable>("SubscriptionDiagnostics_DisabledMonitoredItemCount_Variable"))
    , subscriptionDiagnostics_DiscardedMessageCount_Variable_(constructSPtr<ServerVariable>("SubscriptionDiagnostics_DiscardedMessageCount_Variable"))
    , subscriptionDiagnostics_EnableCount_Variable_(constructSPtr<ServerVariable>("SubscriptionDiagnostics_EnableCount_Variable"))
    , subscriptionDiagnostics_EventNotificationsCount_Variable_(constructSPtr<ServerVariable>("SubscriptionDiagnostics_EventNotificationsCount_Variable"))
    , subscriptionDiagnostics_EventQueueOverflowCount_Variable_(constructSPtr<ServerVariable>("SubscriptionDiagnostics_EventQueueOverflowCount_Variable"))
    , subscriptionDiagnostics_LatePublishRequestCount_Variable_(constructSPtr<ServerVariable>("SubscriptionDiagnostics_LatePublishRequestCount_Variable"))
    , subscriptionDiagnostics_MaxKeepAliveCount_Variable_(constructSPtr<ServerVariable>("SubscriptionDiagnostics_MaxKeepAliveCount_Variable"))
    , subscriptionDiagnostics_MaxLifetimeCount_Variable_(constructSPtr<ServerVariable>("SubscriptionDiagnostics_MaxLifetimeCount_Variable"))
    , subscriptionDiagnostics_MaxNotificationsPerPublish_Variable_(constructSPtr<ServerVariable>("SubscriptionDiagnostics_MaxNotificationsPerPublish_Variable"))
    , subscriptionDiagnostics_ModifyCount_Variable_(constructSPtr<ServerVariable>("SubscriptionDiagnostics_ModifyCount_Variable"))
    , subscriptionDiagnostics_MonitoredItemCount_Variable_(constructSPtr<ServerVariable>("SubscriptionDiagnostics_MonitoredItemCount_Variable"))
    , subscriptionDiagnostics_MonitoringQueueOverflowCount_Variable_(constructSPtr<ServerVariable>("SubscriptionDiagnostics_MonitoringQueueOverflowCount_Variable"))
    , subscriptionDiagnostics_NextSequenceNumber_Variable_(constructSPtr<ServerVariable>("SubscriptionDiagnostics_NextSequenceNumber_Variable"))
    , subscriptionDiagnostics_NotificationsCount_Variable_(constructSPtr<ServerVariable>("SubscriptionDiagnostics_NotificationsCount_Variable"))
    , subscriptionDiagnostics_Priority_Variable_(constructSPtr<ServerVariable>("SubscriptionDiagnostics_Priority_Variable"))
    , subscriptionDiagnostics_PublishRequestCount_Variable_(constructSPtr<ServerVariable>("SubscriptionDiagnostics_PublishRequestCount_Variable"))
    , subscriptionDiagnostics_PublishingEnabled_Variable_(constructSPtr<ServerVariable>("SubscriptionDiagnostics_PublishingEnabled_Variable"))
    , subscriptionDiagnostics_PublishingInterval_Variable_(constructSPtr<ServerVariable>("SubscriptionDiagnostics_PublishingInterval_Variable"))
    , subscriptionDiagnostics_RepublishMessageCount_Variable_(constructSPtr<ServerVariable>("SubscriptionDiagnostics_RepublishMessageCount_Variable"))
    , subscriptionDiagnostics_RepublishMessageRequestCount_Variable_(constructSPtr<ServerVariable>("SubscriptionDiagnostics_RepublishMessageRequestCount_Variable"))
    , subscriptionDiagnostics_RepublishRequestCount_Variable_(constructSPtr<ServerVariable>("SubscriptionDiagnostics_RepublishRequestCount_Variable"))
    , subscriptionDiagnostics_SessionId_Variable_(constructSPtr<ServerVariable>("SubscriptionDiagnostics_SessionId_Variable"))
    , subscriptionDiagnostics_SubscriptionId_Variable_(constructSPtr<ServerVariable>("SubscriptionDiagnostics_SubscriptionId_Variable"))
    , subscriptionDiagnostics_TransferRequestCount_Variable_(constructSPtr<ServerVariable>("SubscriptionDiagnostics_TransferRequestCount_Variable"))
    , subscriptionDiagnostics_TransferredToAltClientCount_Variable_(constructSPtr<ServerVariable>("SubscriptionDiagnostics_TransferredToAltClientCount_Variable"))
    , subscriptionDiagnostics_TransferredToSameClientCount_Variable_(constructSPtr<ServerVariable>("SubscriptionDiagnostics_TransferredToSameClientCount_Variable"))
    , subscriptionDiagnostics_UnacknowledgedMessageCount_Variable_(constructSPtr<ServerVariable>("SubscriptionDiagnostics_UnacknowledgedMessageCount_Variable"))
    , subscriptionDiagnostics_Variable_(constructSPtr<ServerVariable>("SubscriptionDiagnostics_Variable"))
    , variable_(constructSPtr<ServerVariable>("Variable"))
    {
        variableTypeNamespaceName("http://opcfoundation.org/UA/");
        variableTypeNodeId((OpcUaUInt32)2171);
        setServerVariable(subscriptionDiagnostics_CurrentKeepAliveCount_Variable_);
        setServerVariable(subscriptionDiagnostics_CurrentLifetimeCount_Variable_);
        setServerVariable(subscriptionDiagnostics_DataChangeNotificationsCount_Variable_);
        setServerVariable(subscriptionDiagnostics_DisableCount_Variable_);
        setServerVariable(subscriptionDiagnostics_DisabledMonitoredItemCount_Variable_);
        setServerVariable(subscriptionDiagnostics_DiscardedMessageCount_Variable_);
        setServerVariable(subscriptionDiagnostics_EnableCount_Variable_);
        setServerVariable(subscriptionDiagnostics_EventNotificationsCount_Variable_);
        setServerVariable(subscriptionDiagnostics_EventQueueOverflowCount_Variable_);
        setServerVariable(subscriptionDiagnostics_LatePublishRequestCount_Variable_);
        setServerVariable(subscriptionDiagnostics_MaxKeepAliveCount_Variable_);
        setServerVariable(subscriptionDiagnostics_MaxLifetimeCount_Variable_);
        setServerVariable(subscriptionDiagnostics_MaxNotificationsPerPublish_Variable_);
        setServerVariable(subscriptionDiagnostics_ModifyCount_Variable_);
        setServerVariable(subscriptionDiagnostics_MonitoredItemCount_Variable_);
        setServerVariable(subscriptionDiagnostics_MonitoringQueueOverflowCount_Variable_);
        setServerVariable(subscriptionDiagnostics_NextSequenceNumber_Variable_);
        setServerVariable(subscriptionDiagnostics_NotificationsCount_Variable_);
        setServerVariable(subscriptionDiagnostics_Priority_Variable_);
        setServerVariable(subscriptionDiagnostics_PublishRequestCount_Variable_);
        setServerVariable(subscriptionDiagnostics_PublishingEnabled_Variable_);
        setServerVariable(subscriptionDiagnostics_PublishingInterval_Variable_);
        setServerVariable(subscriptionDiagnostics_RepublishMessageCount_Variable_);
        setServerVariable(subscriptionDiagnostics_RepublishMessageRequestCount_Variable_);
        setServerVariable(subscriptionDiagnostics_RepublishRequestCount_Variable_);
        setServerVariable(subscriptionDiagnostics_SessionId_Variable_);
        setServerVariable(subscriptionDiagnostics_SubscriptionId_Variable_);
        setServerVariable(subscriptionDiagnostics_TransferRequestCount_Variable_);
        setServerVariable(subscriptionDiagnostics_TransferredToAltClientCount_Variable_);
        setServerVariable(subscriptionDiagnostics_TransferredToSameClientCount_Variable_);
        setServerVariable(subscriptionDiagnostics_UnacknowledgedMessageCount_Variable_);
        setServerVariable(subscriptionDiagnostics_Variable_);
        setServerVariable(variable_);
    }
    
    SubscriptionDiagnosticsArrayType::SubscriptionDiagnosticsArrayType(const SubscriptionDiagnosticsArrayType& value)
    : VariableBase()
    , subscriptionDiagnostics_CurrentKeepAliveCount_Variable_(constructSPtr<ServerVariable>("SubscriptionDiagnostics_CurrentKeepAliveCount_Variable"))
    , subscriptionDiagnostics_CurrentLifetimeCount_Variable_(constructSPtr<ServerVariable>("SubscriptionDiagnostics_CurrentLifetimeCount_Variable"))
    , subscriptionDiagnostics_DataChangeNotificationsCount_Variable_(constructSPtr<ServerVariable>("SubscriptionDiagnostics_DataChangeNotificationsCount_Variable"))
    , subscriptionDiagnostics_DisableCount_Variable_(constructSPtr<ServerVariable>("SubscriptionDiagnostics_DisableCount_Variable"))
    , subscriptionDiagnostics_DisabledMonitoredItemCount_Variable_(constructSPtr<ServerVariable>("SubscriptionDiagnostics_DisabledMonitoredItemCount_Variable"))
    , subscriptionDiagnostics_DiscardedMessageCount_Variable_(constructSPtr<ServerVariable>("SubscriptionDiagnostics_DiscardedMessageCount_Variable"))
    , subscriptionDiagnostics_EnableCount_Variable_(constructSPtr<ServerVariable>("SubscriptionDiagnostics_EnableCount_Variable"))
    , subscriptionDiagnostics_EventNotificationsCount_Variable_(constructSPtr<ServerVariable>("SubscriptionDiagnostics_EventNotificationsCount_Variable"))
    , subscriptionDiagnostics_EventQueueOverflowCount_Variable_(constructSPtr<ServerVariable>("SubscriptionDiagnostics_EventQueueOverflowCount_Variable"))
    , subscriptionDiagnostics_LatePublishRequestCount_Variable_(constructSPtr<ServerVariable>("SubscriptionDiagnostics_LatePublishRequestCount_Variable"))
    , subscriptionDiagnostics_MaxKeepAliveCount_Variable_(constructSPtr<ServerVariable>("SubscriptionDiagnostics_MaxKeepAliveCount_Variable"))
    , subscriptionDiagnostics_MaxLifetimeCount_Variable_(constructSPtr<ServerVariable>("SubscriptionDiagnostics_MaxLifetimeCount_Variable"))
    , subscriptionDiagnostics_MaxNotificationsPerPublish_Variable_(constructSPtr<ServerVariable>("SubscriptionDiagnostics_MaxNotificationsPerPublish_Variable"))
    , subscriptionDiagnostics_ModifyCount_Variable_(constructSPtr<ServerVariable>("SubscriptionDiagnostics_ModifyCount_Variable"))
    , subscriptionDiagnostics_MonitoredItemCount_Variable_(constructSPtr<ServerVariable>("SubscriptionDiagnostics_MonitoredItemCount_Variable"))
    , subscriptionDiagnostics_MonitoringQueueOverflowCount_Variable_(constructSPtr<ServerVariable>("SubscriptionDiagnostics_MonitoringQueueOverflowCount_Variable"))
    , subscriptionDiagnostics_NextSequenceNumber_Variable_(constructSPtr<ServerVariable>("SubscriptionDiagnostics_NextSequenceNumber_Variable"))
    , subscriptionDiagnostics_NotificationsCount_Variable_(constructSPtr<ServerVariable>("SubscriptionDiagnostics_NotificationsCount_Variable"))
    , subscriptionDiagnostics_Priority_Variable_(constructSPtr<ServerVariable>("SubscriptionDiagnostics_Priority_Variable"))
    , subscriptionDiagnostics_PublishRequestCount_Variable_(constructSPtr<ServerVariable>("SubscriptionDiagnostics_PublishRequestCount_Variable"))
    , subscriptionDiagnostics_PublishingEnabled_Variable_(constructSPtr<ServerVariable>("SubscriptionDiagnostics_PublishingEnabled_Variable"))
    , subscriptionDiagnostics_PublishingInterval_Variable_(constructSPtr<ServerVariable>("SubscriptionDiagnostics_PublishingInterval_Variable"))
    , subscriptionDiagnostics_RepublishMessageCount_Variable_(constructSPtr<ServerVariable>("SubscriptionDiagnostics_RepublishMessageCount_Variable"))
    , subscriptionDiagnostics_RepublishMessageRequestCount_Variable_(constructSPtr<ServerVariable>("SubscriptionDiagnostics_RepublishMessageRequestCount_Variable"))
    , subscriptionDiagnostics_RepublishRequestCount_Variable_(constructSPtr<ServerVariable>("SubscriptionDiagnostics_RepublishRequestCount_Variable"))
    , subscriptionDiagnostics_SessionId_Variable_(constructSPtr<ServerVariable>("SubscriptionDiagnostics_SessionId_Variable"))
    , subscriptionDiagnostics_SubscriptionId_Variable_(constructSPtr<ServerVariable>("SubscriptionDiagnostics_SubscriptionId_Variable"))
    , subscriptionDiagnostics_TransferRequestCount_Variable_(constructSPtr<ServerVariable>("SubscriptionDiagnostics_TransferRequestCount_Variable"))
    , subscriptionDiagnostics_TransferredToAltClientCount_Variable_(constructSPtr<ServerVariable>("SubscriptionDiagnostics_TransferredToAltClientCount_Variable"))
    , subscriptionDiagnostics_TransferredToSameClientCount_Variable_(constructSPtr<ServerVariable>("SubscriptionDiagnostics_TransferredToSameClientCount_Variable"))
    , subscriptionDiagnostics_UnacknowledgedMessageCount_Variable_(constructSPtr<ServerVariable>("SubscriptionDiagnostics_UnacknowledgedMessageCount_Variable"))
    , subscriptionDiagnostics_Variable_(constructSPtr<ServerVariable>("SubscriptionDiagnostics_Variable"))
    , variable_(constructSPtr<ServerVariable>("Variable"))
    {
        variableTypeNamespaceName("http://opcfoundation.org/UA/");
        variableTypeNodeId((OpcUaUInt32)2171);
        setServerVariable(subscriptionDiagnostics_CurrentKeepAliveCount_Variable_);
        setServerVariable(subscriptionDiagnostics_CurrentLifetimeCount_Variable_);
        setServerVariable(subscriptionDiagnostics_DataChangeNotificationsCount_Variable_);
        setServerVariable(subscriptionDiagnostics_DisableCount_Variable_);
        setServerVariable(subscriptionDiagnostics_DisabledMonitoredItemCount_Variable_);
        setServerVariable(subscriptionDiagnostics_DiscardedMessageCount_Variable_);
        setServerVariable(subscriptionDiagnostics_EnableCount_Variable_);
        setServerVariable(subscriptionDiagnostics_EventNotificationsCount_Variable_);
        setServerVariable(subscriptionDiagnostics_EventQueueOverflowCount_Variable_);
        setServerVariable(subscriptionDiagnostics_LatePublishRequestCount_Variable_);
        setServerVariable(subscriptionDiagnostics_MaxKeepAliveCount_Variable_);
        setServerVariable(subscriptionDiagnostics_MaxLifetimeCount_Variable_);
        setServerVariable(subscriptionDiagnostics_MaxNotificationsPerPublish_Variable_);
        setServerVariable(subscriptionDiagnostics_ModifyCount_Variable_);
        setServerVariable(subscriptionDiagnostics_MonitoredItemCount_Variable_);
        setServerVariable(subscriptionDiagnostics_MonitoringQueueOverflowCount_Variable_);
        setServerVariable(subscriptionDiagnostics_NextSequenceNumber_Variable_);
        setServerVariable(subscriptionDiagnostics_NotificationsCount_Variable_);
        setServerVariable(subscriptionDiagnostics_Priority_Variable_);
        setServerVariable(subscriptionDiagnostics_PublishRequestCount_Variable_);
        setServerVariable(subscriptionDiagnostics_PublishingEnabled_Variable_);
        setServerVariable(subscriptionDiagnostics_PublishingInterval_Variable_);
        setServerVariable(subscriptionDiagnostics_RepublishMessageCount_Variable_);
        setServerVariable(subscriptionDiagnostics_RepublishMessageRequestCount_Variable_);
        setServerVariable(subscriptionDiagnostics_RepublishRequestCount_Variable_);
        setServerVariable(subscriptionDiagnostics_SessionId_Variable_);
        setServerVariable(subscriptionDiagnostics_SubscriptionId_Variable_);
        setServerVariable(subscriptionDiagnostics_TransferRequestCount_Variable_);
        setServerVariable(subscriptionDiagnostics_TransferredToAltClientCount_Variable_);
        setServerVariable(subscriptionDiagnostics_TransferredToSameClientCount_Variable_);
        setServerVariable(subscriptionDiagnostics_UnacknowledgedMessageCount_Variable_);
        setServerVariable(subscriptionDiagnostics_Variable_);
        setServerVariable(variable_);
    }
    
    SubscriptionDiagnosticsArrayType::~SubscriptionDiagnosticsArrayType(void)
    {
    }

    ServerVariable::SPtr&
    SubscriptionDiagnosticsArrayType::subscriptionDiagnostics_CurrentKeepAliveCount_Variable(void)
    {
        return subscriptionDiagnostics_CurrentKeepAliveCount_Variable_;
    }

    ServerVariable::SPtr&
    SubscriptionDiagnosticsArrayType::subscriptionDiagnostics_CurrentLifetimeCount_Variable(void)
    {
        return subscriptionDiagnostics_CurrentLifetimeCount_Variable_;
    }

    ServerVariable::SPtr&
    SubscriptionDiagnosticsArrayType::subscriptionDiagnostics_DataChangeNotificationsCount_Variable(void)
    {
        return subscriptionDiagnostics_DataChangeNotificationsCount_Variable_;
    }

    ServerVariable::SPtr&
    SubscriptionDiagnosticsArrayType::subscriptionDiagnostics_DisableCount_Variable(void)
    {
        return subscriptionDiagnostics_DisableCount_Variable_;
    }

    ServerVariable::SPtr&
    SubscriptionDiagnosticsArrayType::subscriptionDiagnostics_DisabledMonitoredItemCount_Variable(void)
    {
        return subscriptionDiagnostics_DisabledMonitoredItemCount_Variable_;
    }

    ServerVariable::SPtr&
    SubscriptionDiagnosticsArrayType::subscriptionDiagnostics_DiscardedMessageCount_Variable(void)
    {
        return subscriptionDiagnostics_DiscardedMessageCount_Variable_;
    }

    ServerVariable::SPtr&
    SubscriptionDiagnosticsArrayType::subscriptionDiagnostics_EnableCount_Variable(void)
    {
        return subscriptionDiagnostics_EnableCount_Variable_;
    }

    ServerVariable::SPtr&
    SubscriptionDiagnosticsArrayType::subscriptionDiagnostics_EventNotificationsCount_Variable(void)
    {
        return subscriptionDiagnostics_EventNotificationsCount_Variable_;
    }

    ServerVariable::SPtr&
    SubscriptionDiagnosticsArrayType::subscriptionDiagnostics_EventQueueOverflowCount_Variable(void)
    {
        return subscriptionDiagnostics_EventQueueOverflowCount_Variable_;
    }

    ServerVariable::SPtr&
    SubscriptionDiagnosticsArrayType::subscriptionDiagnostics_LatePublishRequestCount_Variable(void)
    {
        return subscriptionDiagnostics_LatePublishRequestCount_Variable_;
    }

    ServerVariable::SPtr&
    SubscriptionDiagnosticsArrayType::subscriptionDiagnostics_MaxKeepAliveCount_Variable(void)
    {
        return subscriptionDiagnostics_MaxKeepAliveCount_Variable_;
    }

    ServerVariable::SPtr&
    SubscriptionDiagnosticsArrayType::subscriptionDiagnostics_MaxLifetimeCount_Variable(void)
    {
        return subscriptionDiagnostics_MaxLifetimeCount_Variable_;
    }

    ServerVariable::SPtr&
    SubscriptionDiagnosticsArrayType::subscriptionDiagnostics_MaxNotificationsPerPublish_Variable(void)
    {
        return subscriptionDiagnostics_MaxNotificationsPerPublish_Variable_;
    }

    ServerVariable::SPtr&
    SubscriptionDiagnosticsArrayType::subscriptionDiagnostics_ModifyCount_Variable(void)
    {
        return subscriptionDiagnostics_ModifyCount_Variable_;
    }

    ServerVariable::SPtr&
    SubscriptionDiagnosticsArrayType::subscriptionDiagnostics_MonitoredItemCount_Variable(void)
    {
        return subscriptionDiagnostics_MonitoredItemCount_Variable_;
    }

    ServerVariable::SPtr&
    SubscriptionDiagnosticsArrayType::subscriptionDiagnostics_MonitoringQueueOverflowCount_Variable(void)
    {
        return subscriptionDiagnostics_MonitoringQueueOverflowCount_Variable_;
    }

    ServerVariable::SPtr&
    SubscriptionDiagnosticsArrayType::subscriptionDiagnostics_NextSequenceNumber_Variable(void)
    {
        return subscriptionDiagnostics_NextSequenceNumber_Variable_;
    }

    ServerVariable::SPtr&
    SubscriptionDiagnosticsArrayType::subscriptionDiagnostics_NotificationsCount_Variable(void)
    {
        return subscriptionDiagnostics_NotificationsCount_Variable_;
    }

    ServerVariable::SPtr&
    SubscriptionDiagnosticsArrayType::subscriptionDiagnostics_Priority_Variable(void)
    {
        return subscriptionDiagnostics_Priority_Variable_;
    }

    ServerVariable::SPtr&
    SubscriptionDiagnosticsArrayType::subscriptionDiagnostics_PublishRequestCount_Variable(void)
    {
        return subscriptionDiagnostics_PublishRequestCount_Variable_;
    }

    ServerVariable::SPtr&
    SubscriptionDiagnosticsArrayType::subscriptionDiagnostics_PublishingEnabled_Variable(void)
    {
        return subscriptionDiagnostics_PublishingEnabled_Variable_;
    }

    ServerVariable::SPtr&
    SubscriptionDiagnosticsArrayType::subscriptionDiagnostics_PublishingInterval_Variable(void)
    {
        return subscriptionDiagnostics_PublishingInterval_Variable_;
    }

    ServerVariable::SPtr&
    SubscriptionDiagnosticsArrayType::subscriptionDiagnostics_RepublishMessageCount_Variable(void)
    {
        return subscriptionDiagnostics_RepublishMessageCount_Variable_;
    }

    ServerVariable::SPtr&
    SubscriptionDiagnosticsArrayType::subscriptionDiagnostics_RepublishMessageRequestCount_Variable(void)
    {
        return subscriptionDiagnostics_RepublishMessageRequestCount_Variable_;
    }

    ServerVariable::SPtr&
    SubscriptionDiagnosticsArrayType::subscriptionDiagnostics_RepublishRequestCount_Variable(void)
    {
        return subscriptionDiagnostics_RepublishRequestCount_Variable_;
    }

    ServerVariable::SPtr&
    SubscriptionDiagnosticsArrayType::subscriptionDiagnostics_SessionId_Variable(void)
    {
        return subscriptionDiagnostics_SessionId_Variable_;
    }

    ServerVariable::SPtr&
    SubscriptionDiagnosticsArrayType::subscriptionDiagnostics_SubscriptionId_Variable(void)
    {
        return subscriptionDiagnostics_SubscriptionId_Variable_;
    }

    ServerVariable::SPtr&
    SubscriptionDiagnosticsArrayType::subscriptionDiagnostics_TransferRequestCount_Variable(void)
    {
        return subscriptionDiagnostics_TransferRequestCount_Variable_;
    }

    ServerVariable::SPtr&
    SubscriptionDiagnosticsArrayType::subscriptionDiagnostics_TransferredToAltClientCount_Variable(void)
    {
        return subscriptionDiagnostics_TransferredToAltClientCount_Variable_;
    }

    ServerVariable::SPtr&
    SubscriptionDiagnosticsArrayType::subscriptionDiagnostics_TransferredToSameClientCount_Variable(void)
    {
        return subscriptionDiagnostics_TransferredToSameClientCount_Variable_;
    }

    ServerVariable::SPtr&
    SubscriptionDiagnosticsArrayType::subscriptionDiagnostics_UnacknowledgedMessageCount_Variable(void)
    {
        return subscriptionDiagnostics_UnacknowledgedMessageCount_Variable_;
    }

    ServerVariable::SPtr&
    SubscriptionDiagnosticsArrayType::subscriptionDiagnostics_Variable(void)
    {
        return subscriptionDiagnostics_Variable_;
    }

    ServerVariable::SPtr&
    SubscriptionDiagnosticsArrayType::variable(void)
    {
        return variable_;
    }

    void
    SubscriptionDiagnosticsArrayType::subscriptionDiagnostics_CurrentKeepAliveCount_Variable(ServerVariable::SPtr& serverVariable)
    {
        subscriptionDiagnostics_CurrentKeepAliveCount_Variable_ = serverVariable;
    }

    void
    SubscriptionDiagnosticsArrayType::subscriptionDiagnostics_CurrentLifetimeCount_Variable(ServerVariable::SPtr& serverVariable)
    {
        subscriptionDiagnostics_CurrentLifetimeCount_Variable_ = serverVariable;
    }

    void
    SubscriptionDiagnosticsArrayType::subscriptionDiagnostics_DataChangeNotificationsCount_Variable(ServerVariable::SPtr& serverVariable)
    {
        subscriptionDiagnostics_DataChangeNotificationsCount_Variable_ = serverVariable;
    }

    void
    SubscriptionDiagnosticsArrayType::subscriptionDiagnostics_DisableCount_Variable(ServerVariable::SPtr& serverVariable)
    {
        subscriptionDiagnostics_DisableCount_Variable_ = serverVariable;
    }

    void
    SubscriptionDiagnosticsArrayType::subscriptionDiagnostics_DisabledMonitoredItemCount_Variable(ServerVariable::SPtr& serverVariable)
    {
        subscriptionDiagnostics_DisabledMonitoredItemCount_Variable_ = serverVariable;
    }

    void
    SubscriptionDiagnosticsArrayType::subscriptionDiagnostics_DiscardedMessageCount_Variable(ServerVariable::SPtr& serverVariable)
    {
        subscriptionDiagnostics_DiscardedMessageCount_Variable_ = serverVariable;
    }

    void
    SubscriptionDiagnosticsArrayType::subscriptionDiagnostics_EnableCount_Variable(ServerVariable::SPtr& serverVariable)
    {
        subscriptionDiagnostics_EnableCount_Variable_ = serverVariable;
    }

    void
    SubscriptionDiagnosticsArrayType::subscriptionDiagnostics_EventNotificationsCount_Variable(ServerVariable::SPtr& serverVariable)
    {
        subscriptionDiagnostics_EventNotificationsCount_Variable_ = serverVariable;
    }

    void
    SubscriptionDiagnosticsArrayType::subscriptionDiagnostics_EventQueueOverflowCount_Variable(ServerVariable::SPtr& serverVariable)
    {
        subscriptionDiagnostics_EventQueueOverflowCount_Variable_ = serverVariable;
    }

    void
    SubscriptionDiagnosticsArrayType::subscriptionDiagnostics_LatePublishRequestCount_Variable(ServerVariable::SPtr& serverVariable)
    {
        subscriptionDiagnostics_LatePublishRequestCount_Variable_ = serverVariable;
    }

    void
    SubscriptionDiagnosticsArrayType::subscriptionDiagnostics_MaxKeepAliveCount_Variable(ServerVariable::SPtr& serverVariable)
    {
        subscriptionDiagnostics_MaxKeepAliveCount_Variable_ = serverVariable;
    }

    void
    SubscriptionDiagnosticsArrayType::subscriptionDiagnostics_MaxLifetimeCount_Variable(ServerVariable::SPtr& serverVariable)
    {
        subscriptionDiagnostics_MaxLifetimeCount_Variable_ = serverVariable;
    }

    void
    SubscriptionDiagnosticsArrayType::subscriptionDiagnostics_MaxNotificationsPerPublish_Variable(ServerVariable::SPtr& serverVariable)
    {
        subscriptionDiagnostics_MaxNotificationsPerPublish_Variable_ = serverVariable;
    }

    void
    SubscriptionDiagnosticsArrayType::subscriptionDiagnostics_ModifyCount_Variable(ServerVariable::SPtr& serverVariable)
    {
        subscriptionDiagnostics_ModifyCount_Variable_ = serverVariable;
    }

    void
    SubscriptionDiagnosticsArrayType::subscriptionDiagnostics_MonitoredItemCount_Variable(ServerVariable::SPtr& serverVariable)
    {
        subscriptionDiagnostics_MonitoredItemCount_Variable_ = serverVariable;
    }

    void
    SubscriptionDiagnosticsArrayType::subscriptionDiagnostics_MonitoringQueueOverflowCount_Variable(ServerVariable::SPtr& serverVariable)
    {
        subscriptionDiagnostics_MonitoringQueueOverflowCount_Variable_ = serverVariable;
    }

    void
    SubscriptionDiagnosticsArrayType::subscriptionDiagnostics_NextSequenceNumber_Variable(ServerVariable::SPtr& serverVariable)
    {
        subscriptionDiagnostics_NextSequenceNumber_Variable_ = serverVariable;
    }

    void
    SubscriptionDiagnosticsArrayType::subscriptionDiagnostics_NotificationsCount_Variable(ServerVariable::SPtr& serverVariable)
    {
        subscriptionDiagnostics_NotificationsCount_Variable_ = serverVariable;
    }

    void
    SubscriptionDiagnosticsArrayType::subscriptionDiagnostics_Priority_Variable(ServerVariable::SPtr& serverVariable)
    {
        subscriptionDiagnostics_Priority_Variable_ = serverVariable;
    }

    void
    SubscriptionDiagnosticsArrayType::subscriptionDiagnostics_PublishRequestCount_Variable(ServerVariable::SPtr& serverVariable)
    {
        subscriptionDiagnostics_PublishRequestCount_Variable_ = serverVariable;
    }

    void
    SubscriptionDiagnosticsArrayType::subscriptionDiagnostics_PublishingEnabled_Variable(ServerVariable::SPtr& serverVariable)
    {
        subscriptionDiagnostics_PublishingEnabled_Variable_ = serverVariable;
    }

    void
    SubscriptionDiagnosticsArrayType::subscriptionDiagnostics_PublishingInterval_Variable(ServerVariable::SPtr& serverVariable)
    {
        subscriptionDiagnostics_PublishingInterval_Variable_ = serverVariable;
    }

    void
    SubscriptionDiagnosticsArrayType::subscriptionDiagnostics_RepublishMessageCount_Variable(ServerVariable::SPtr& serverVariable)
    {
        subscriptionDiagnostics_RepublishMessageCount_Variable_ = serverVariable;
    }

    void
    SubscriptionDiagnosticsArrayType::subscriptionDiagnostics_RepublishMessageRequestCount_Variable(ServerVariable::SPtr& serverVariable)
    {
        subscriptionDiagnostics_RepublishMessageRequestCount_Variable_ = serverVariable;
    }

    void
    SubscriptionDiagnosticsArrayType::subscriptionDiagnostics_RepublishRequestCount_Variable(ServerVariable::SPtr& serverVariable)
    {
        subscriptionDiagnostics_RepublishRequestCount_Variable_ = serverVariable;
    }

    void
    SubscriptionDiagnosticsArrayType::subscriptionDiagnostics_SessionId_Variable(ServerVariable::SPtr& serverVariable)
    {
        subscriptionDiagnostics_SessionId_Variable_ = serverVariable;
    }

    void
    SubscriptionDiagnosticsArrayType::subscriptionDiagnostics_SubscriptionId_Variable(ServerVariable::SPtr& serverVariable)
    {
        subscriptionDiagnostics_SubscriptionId_Variable_ = serverVariable;
    }

    void
    SubscriptionDiagnosticsArrayType::subscriptionDiagnostics_TransferRequestCount_Variable(ServerVariable::SPtr& serverVariable)
    {
        subscriptionDiagnostics_TransferRequestCount_Variable_ = serverVariable;
    }

    void
    SubscriptionDiagnosticsArrayType::subscriptionDiagnostics_TransferredToAltClientCount_Variable(ServerVariable::SPtr& serverVariable)
    {
        subscriptionDiagnostics_TransferredToAltClientCount_Variable_ = serverVariable;
    }

    void
    SubscriptionDiagnosticsArrayType::subscriptionDiagnostics_TransferredToSameClientCount_Variable(ServerVariable::SPtr& serverVariable)
    {
        subscriptionDiagnostics_TransferredToSameClientCount_Variable_ = serverVariable;
    }

    void
    SubscriptionDiagnosticsArrayType::subscriptionDiagnostics_UnacknowledgedMessageCount_Variable(ServerVariable::SPtr& serverVariable)
    {
        subscriptionDiagnostics_UnacknowledgedMessageCount_Variable_ = serverVariable;
    }

    void
    SubscriptionDiagnosticsArrayType::subscriptionDiagnostics_Variable(ServerVariable::SPtr& serverVariable)
    {
        subscriptionDiagnostics_Variable_ = serverVariable;
    }

    void
    SubscriptionDiagnosticsArrayType::variable(ServerVariable::SPtr& serverVariable)
    {
        variable_ = serverVariable;
    }

    bool
    SubscriptionDiagnosticsArrayType::get_SubscriptionDiagnostics_CurrentKeepAliveCount_Variable(OpcUaDataValue& dataValue)
    {
        return subscriptionDiagnostics_CurrentKeepAliveCount_Variable_->getDataValue(dataValue);
    }

    bool
    SubscriptionDiagnosticsArrayType::get_SubscriptionDiagnostics_CurrentLifetimeCount_Variable(OpcUaDataValue& dataValue)
    {
        return subscriptionDiagnostics_CurrentLifetimeCount_Variable_->getDataValue(dataValue);
    }

    bool
    SubscriptionDiagnosticsArrayType::get_SubscriptionDiagnostics_DataChangeNotificationsCount_Variable(OpcUaDataValue& dataValue)
    {
        return subscriptionDiagnostics_DataChangeNotificationsCount_Variable_->getDataValue(dataValue);
    }

    bool
    SubscriptionDiagnosticsArrayType::get_SubscriptionDiagnostics_DisableCount_Variable(OpcUaDataValue& dataValue)
    {
        return subscriptionDiagnostics_DisableCount_Variable_->getDataValue(dataValue);
    }

    bool
    SubscriptionDiagnosticsArrayType::get_SubscriptionDiagnostics_DisabledMonitoredItemCount_Variable(OpcUaDataValue& dataValue)
    {
        return subscriptionDiagnostics_DisabledMonitoredItemCount_Variable_->getDataValue(dataValue);
    }

    bool
    SubscriptionDiagnosticsArrayType::get_SubscriptionDiagnostics_DiscardedMessageCount_Variable(OpcUaDataValue& dataValue)
    {
        return subscriptionDiagnostics_DiscardedMessageCount_Variable_->getDataValue(dataValue);
    }

    bool
    SubscriptionDiagnosticsArrayType::get_SubscriptionDiagnostics_EnableCount_Variable(OpcUaDataValue& dataValue)
    {
        return subscriptionDiagnostics_EnableCount_Variable_->getDataValue(dataValue);
    }

    bool
    SubscriptionDiagnosticsArrayType::get_SubscriptionDiagnostics_EventNotificationsCount_Variable(OpcUaDataValue& dataValue)
    {
        return subscriptionDiagnostics_EventNotificationsCount_Variable_->getDataValue(dataValue);
    }

    bool
    SubscriptionDiagnosticsArrayType::get_SubscriptionDiagnostics_EventQueueOverflowCount_Variable(OpcUaDataValue& dataValue)
    {
        return subscriptionDiagnostics_EventQueueOverflowCount_Variable_->getDataValue(dataValue);
    }

    bool
    SubscriptionDiagnosticsArrayType::get_SubscriptionDiagnostics_LatePublishRequestCount_Variable(OpcUaDataValue& dataValue)
    {
        return subscriptionDiagnostics_LatePublishRequestCount_Variable_->getDataValue(dataValue);
    }

    bool
    SubscriptionDiagnosticsArrayType::get_SubscriptionDiagnostics_MaxKeepAliveCount_Variable(OpcUaDataValue& dataValue)
    {
        return subscriptionDiagnostics_MaxKeepAliveCount_Variable_->getDataValue(dataValue);
    }

    bool
    SubscriptionDiagnosticsArrayType::get_SubscriptionDiagnostics_MaxLifetimeCount_Variable(OpcUaDataValue& dataValue)
    {
        return subscriptionDiagnostics_MaxLifetimeCount_Variable_->getDataValue(dataValue);
    }

    bool
    SubscriptionDiagnosticsArrayType::get_SubscriptionDiagnostics_MaxNotificationsPerPublish_Variable(OpcUaDataValue& dataValue)
    {
        return subscriptionDiagnostics_MaxNotificationsPerPublish_Variable_->getDataValue(dataValue);
    }

    bool
    SubscriptionDiagnosticsArrayType::get_SubscriptionDiagnostics_ModifyCount_Variable(OpcUaDataValue& dataValue)
    {
        return subscriptionDiagnostics_ModifyCount_Variable_->getDataValue(dataValue);
    }

    bool
    SubscriptionDiagnosticsArrayType::get_SubscriptionDiagnostics_MonitoredItemCount_Variable(OpcUaDataValue& dataValue)
    {
        return subscriptionDiagnostics_MonitoredItemCount_Variable_->getDataValue(dataValue);
    }

    bool
    SubscriptionDiagnosticsArrayType::get_SubscriptionDiagnostics_MonitoringQueueOverflowCount_Variable(OpcUaDataValue& dataValue)
    {
        return subscriptionDiagnostics_MonitoringQueueOverflowCount_Variable_->getDataValue(dataValue);
    }

    bool
    SubscriptionDiagnosticsArrayType::get_SubscriptionDiagnostics_NextSequenceNumber_Variable(OpcUaDataValue& dataValue)
    {
        return subscriptionDiagnostics_NextSequenceNumber_Variable_->getDataValue(dataValue);
    }

    bool
    SubscriptionDiagnosticsArrayType::get_SubscriptionDiagnostics_NotificationsCount_Variable(OpcUaDataValue& dataValue)
    {
        return subscriptionDiagnostics_NotificationsCount_Variable_->getDataValue(dataValue);
    }

    bool
    SubscriptionDiagnosticsArrayType::get_SubscriptionDiagnostics_Priority_Variable(OpcUaDataValue& dataValue)
    {
        return subscriptionDiagnostics_Priority_Variable_->getDataValue(dataValue);
    }

    bool
    SubscriptionDiagnosticsArrayType::get_SubscriptionDiagnostics_PublishRequestCount_Variable(OpcUaDataValue& dataValue)
    {
        return subscriptionDiagnostics_PublishRequestCount_Variable_->getDataValue(dataValue);
    }

    bool
    SubscriptionDiagnosticsArrayType::get_SubscriptionDiagnostics_PublishingEnabled_Variable(OpcUaDataValue& dataValue)
    {
        return subscriptionDiagnostics_PublishingEnabled_Variable_->getDataValue(dataValue);
    }

    bool
    SubscriptionDiagnosticsArrayType::get_SubscriptionDiagnostics_PublishingInterval_Variable(OpcUaDataValue& dataValue)
    {
        return subscriptionDiagnostics_PublishingInterval_Variable_->getDataValue(dataValue);
    }

    bool
    SubscriptionDiagnosticsArrayType::get_SubscriptionDiagnostics_RepublishMessageCount_Variable(OpcUaDataValue& dataValue)
    {
        return subscriptionDiagnostics_RepublishMessageCount_Variable_->getDataValue(dataValue);
    }

    bool
    SubscriptionDiagnosticsArrayType::get_SubscriptionDiagnostics_RepublishMessageRequestCount_Variable(OpcUaDataValue& dataValue)
    {
        return subscriptionDiagnostics_RepublishMessageRequestCount_Variable_->getDataValue(dataValue);
    }

    bool
    SubscriptionDiagnosticsArrayType::get_SubscriptionDiagnostics_RepublishRequestCount_Variable(OpcUaDataValue& dataValue)
    {
        return subscriptionDiagnostics_RepublishRequestCount_Variable_->getDataValue(dataValue);
    }

    bool
    SubscriptionDiagnosticsArrayType::get_SubscriptionDiagnostics_SessionId_Variable(OpcUaDataValue& dataValue)
    {
        return subscriptionDiagnostics_SessionId_Variable_->getDataValue(dataValue);
    }

    bool
    SubscriptionDiagnosticsArrayType::get_SubscriptionDiagnostics_SubscriptionId_Variable(OpcUaDataValue& dataValue)
    {
        return subscriptionDiagnostics_SubscriptionId_Variable_->getDataValue(dataValue);
    }

    bool
    SubscriptionDiagnosticsArrayType::get_SubscriptionDiagnostics_TransferRequestCount_Variable(OpcUaDataValue& dataValue)
    {
        return subscriptionDiagnostics_TransferRequestCount_Variable_->getDataValue(dataValue);
    }

    bool
    SubscriptionDiagnosticsArrayType::get_SubscriptionDiagnostics_TransferredToAltClientCount_Variable(OpcUaDataValue& dataValue)
    {
        return subscriptionDiagnostics_TransferredToAltClientCount_Variable_->getDataValue(dataValue);
    }

    bool
    SubscriptionDiagnosticsArrayType::get_SubscriptionDiagnostics_TransferredToSameClientCount_Variable(OpcUaDataValue& dataValue)
    {
        return subscriptionDiagnostics_TransferredToSameClientCount_Variable_->getDataValue(dataValue);
    }

    bool
    SubscriptionDiagnosticsArrayType::get_SubscriptionDiagnostics_UnacknowledgedMessageCount_Variable(OpcUaDataValue& dataValue)
    {
        return subscriptionDiagnostics_UnacknowledgedMessageCount_Variable_->getDataValue(dataValue);
    }

    bool
    SubscriptionDiagnosticsArrayType::get_SubscriptionDiagnostics_Variable(OpcUaDataValue& dataValue)
    {
        return subscriptionDiagnostics_Variable_->getDataValue(dataValue);
    }

    bool
    SubscriptionDiagnosticsArrayType::get_Variable(OpcUaDataValue& dataValue)
    {
        return variable_->getDataValue(dataValue);
    }

    bool
    SubscriptionDiagnosticsArrayType::set_SubscriptionDiagnostics_CurrentKeepAliveCount_Variable(const OpcUaDataValue& dataValue)
    {
        return subscriptionDiagnostics_CurrentKeepAliveCount_Variable_->setDataValue(dataValue);
    }

    bool
    SubscriptionDiagnosticsArrayType::set_SubscriptionDiagnostics_CurrentLifetimeCount_Variable(const OpcUaDataValue& dataValue)
    {
        return subscriptionDiagnostics_CurrentLifetimeCount_Variable_->setDataValue(dataValue);
    }

    bool
    SubscriptionDiagnosticsArrayType::set_SubscriptionDiagnostics_DataChangeNotificationsCount_Variable(const OpcUaDataValue& dataValue)
    {
        return subscriptionDiagnostics_DataChangeNotificationsCount_Variable_->setDataValue(dataValue);
    }

    bool
    SubscriptionDiagnosticsArrayType::set_SubscriptionDiagnostics_DisableCount_Variable(const OpcUaDataValue& dataValue)
    {
        return subscriptionDiagnostics_DisableCount_Variable_->setDataValue(dataValue);
    }

    bool
    SubscriptionDiagnosticsArrayType::set_SubscriptionDiagnostics_DisabledMonitoredItemCount_Variable(const OpcUaDataValue& dataValue)
    {
        return subscriptionDiagnostics_DisabledMonitoredItemCount_Variable_->setDataValue(dataValue);
    }

    bool
    SubscriptionDiagnosticsArrayType::set_SubscriptionDiagnostics_DiscardedMessageCount_Variable(const OpcUaDataValue& dataValue)
    {
        return subscriptionDiagnostics_DiscardedMessageCount_Variable_->setDataValue(dataValue);
    }

    bool
    SubscriptionDiagnosticsArrayType::set_SubscriptionDiagnostics_EnableCount_Variable(const OpcUaDataValue& dataValue)
    {
        return subscriptionDiagnostics_EnableCount_Variable_->setDataValue(dataValue);
    }

    bool
    SubscriptionDiagnosticsArrayType::set_SubscriptionDiagnostics_EventNotificationsCount_Variable(const OpcUaDataValue& dataValue)
    {
        return subscriptionDiagnostics_EventNotificationsCount_Variable_->setDataValue(dataValue);
    }

    bool
    SubscriptionDiagnosticsArrayType::set_SubscriptionDiagnostics_EventQueueOverflowCount_Variable(const OpcUaDataValue& dataValue)
    {
        return subscriptionDiagnostics_EventQueueOverflowCount_Variable_->setDataValue(dataValue);
    }

    bool
    SubscriptionDiagnosticsArrayType::set_SubscriptionDiagnostics_LatePublishRequestCount_Variable(const OpcUaDataValue& dataValue)
    {
        return subscriptionDiagnostics_LatePublishRequestCount_Variable_->setDataValue(dataValue);
    }

    bool
    SubscriptionDiagnosticsArrayType::set_SubscriptionDiagnostics_MaxKeepAliveCount_Variable(const OpcUaDataValue& dataValue)
    {
        return subscriptionDiagnostics_MaxKeepAliveCount_Variable_->setDataValue(dataValue);
    }

    bool
    SubscriptionDiagnosticsArrayType::set_SubscriptionDiagnostics_MaxLifetimeCount_Variable(const OpcUaDataValue& dataValue)
    {
        return subscriptionDiagnostics_MaxLifetimeCount_Variable_->setDataValue(dataValue);
    }

    bool
    SubscriptionDiagnosticsArrayType::set_SubscriptionDiagnostics_MaxNotificationsPerPublish_Variable(const OpcUaDataValue& dataValue)
    {
        return subscriptionDiagnostics_MaxNotificationsPerPublish_Variable_->setDataValue(dataValue);
    }

    bool
    SubscriptionDiagnosticsArrayType::set_SubscriptionDiagnostics_ModifyCount_Variable(const OpcUaDataValue& dataValue)
    {
        return subscriptionDiagnostics_ModifyCount_Variable_->setDataValue(dataValue);
    }

    bool
    SubscriptionDiagnosticsArrayType::set_SubscriptionDiagnostics_MonitoredItemCount_Variable(const OpcUaDataValue& dataValue)
    {
        return subscriptionDiagnostics_MonitoredItemCount_Variable_->setDataValue(dataValue);
    }

    bool
    SubscriptionDiagnosticsArrayType::set_SubscriptionDiagnostics_MonitoringQueueOverflowCount_Variable(const OpcUaDataValue& dataValue)
    {
        return subscriptionDiagnostics_MonitoringQueueOverflowCount_Variable_->setDataValue(dataValue);
    }

    bool
    SubscriptionDiagnosticsArrayType::set_SubscriptionDiagnostics_NextSequenceNumber_Variable(const OpcUaDataValue& dataValue)
    {
        return subscriptionDiagnostics_NextSequenceNumber_Variable_->setDataValue(dataValue);
    }

    bool
    SubscriptionDiagnosticsArrayType::set_SubscriptionDiagnostics_NotificationsCount_Variable(const OpcUaDataValue& dataValue)
    {
        return subscriptionDiagnostics_NotificationsCount_Variable_->setDataValue(dataValue);
    }

    bool
    SubscriptionDiagnosticsArrayType::set_SubscriptionDiagnostics_Priority_Variable(const OpcUaDataValue& dataValue)
    {
        return subscriptionDiagnostics_Priority_Variable_->setDataValue(dataValue);
    }

    bool
    SubscriptionDiagnosticsArrayType::set_SubscriptionDiagnostics_PublishRequestCount_Variable(const OpcUaDataValue& dataValue)
    {
        return subscriptionDiagnostics_PublishRequestCount_Variable_->setDataValue(dataValue);
    }

    bool
    SubscriptionDiagnosticsArrayType::set_SubscriptionDiagnostics_PublishingEnabled_Variable(const OpcUaDataValue& dataValue)
    {
        return subscriptionDiagnostics_PublishingEnabled_Variable_->setDataValue(dataValue);
    }

    bool
    SubscriptionDiagnosticsArrayType::set_SubscriptionDiagnostics_PublishingInterval_Variable(const OpcUaDataValue& dataValue)
    {
        return subscriptionDiagnostics_PublishingInterval_Variable_->setDataValue(dataValue);
    }

    bool
    SubscriptionDiagnosticsArrayType::set_SubscriptionDiagnostics_RepublishMessageCount_Variable(const OpcUaDataValue& dataValue)
    {
        return subscriptionDiagnostics_RepublishMessageCount_Variable_->setDataValue(dataValue);
    }

    bool
    SubscriptionDiagnosticsArrayType::set_SubscriptionDiagnostics_RepublishMessageRequestCount_Variable(const OpcUaDataValue& dataValue)
    {
        return subscriptionDiagnostics_RepublishMessageRequestCount_Variable_->setDataValue(dataValue);
    }

    bool
    SubscriptionDiagnosticsArrayType::set_SubscriptionDiagnostics_RepublishRequestCount_Variable(const OpcUaDataValue& dataValue)
    {
        return subscriptionDiagnostics_RepublishRequestCount_Variable_->setDataValue(dataValue);
    }

    bool
    SubscriptionDiagnosticsArrayType::set_SubscriptionDiagnostics_SessionId_Variable(const OpcUaDataValue& dataValue)
    {
        return subscriptionDiagnostics_SessionId_Variable_->setDataValue(dataValue);
    }

    bool
    SubscriptionDiagnosticsArrayType::set_SubscriptionDiagnostics_SubscriptionId_Variable(const OpcUaDataValue& dataValue)
    {
        return subscriptionDiagnostics_SubscriptionId_Variable_->setDataValue(dataValue);
    }

    bool
    SubscriptionDiagnosticsArrayType::set_SubscriptionDiagnostics_TransferRequestCount_Variable(const OpcUaDataValue& dataValue)
    {
        return subscriptionDiagnostics_TransferRequestCount_Variable_->setDataValue(dataValue);
    }

    bool
    SubscriptionDiagnosticsArrayType::set_SubscriptionDiagnostics_TransferredToAltClientCount_Variable(const OpcUaDataValue& dataValue)
    {
        return subscriptionDiagnostics_TransferredToAltClientCount_Variable_->setDataValue(dataValue);
    }

    bool
    SubscriptionDiagnosticsArrayType::set_SubscriptionDiagnostics_TransferredToSameClientCount_Variable(const OpcUaDataValue& dataValue)
    {
        return subscriptionDiagnostics_TransferredToSameClientCount_Variable_->setDataValue(dataValue);
    }

    bool
    SubscriptionDiagnosticsArrayType::set_SubscriptionDiagnostics_UnacknowledgedMessageCount_Variable(const OpcUaDataValue& dataValue)
    {
        return subscriptionDiagnostics_UnacknowledgedMessageCount_Variable_->setDataValue(dataValue);
    }

    bool
    SubscriptionDiagnosticsArrayType::set_SubscriptionDiagnostics_Variable(const OpcUaDataValue& dataValue)
    {
        return subscriptionDiagnostics_Variable_->setDataValue(dataValue);
    }

    bool
    SubscriptionDiagnosticsArrayType::set_Variable(const OpcUaDataValue& dataValue)
    {
        return variable_->setDataValue(dataValue);
    }

}
