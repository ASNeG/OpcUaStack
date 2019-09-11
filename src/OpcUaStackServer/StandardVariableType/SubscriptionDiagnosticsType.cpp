/*
    VariableTypeClass: SubscriptionDiagnosticsType

    Generated Source Code - please do not change this source code

    VariableTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackServer/StandardVariableType/SubscriptionDiagnosticsType.h"

namespace OpcUaStackServer
{
    
    SubscriptionDiagnosticsType::SubscriptionDiagnosticsType(void)
    : VariableBase()
    , currentKeepAliveCount_Variable_(boost::make_shared<ServerVariable>("CurrentKeepAliveCount_Variable"))
    , currentLifetimeCount_Variable_(boost::make_shared<ServerVariable>("CurrentLifetimeCount_Variable"))
    , dataChangeNotificationsCount_Variable_(boost::make_shared<ServerVariable>("DataChangeNotificationsCount_Variable"))
    , disableCount_Variable_(boost::make_shared<ServerVariable>("DisableCount_Variable"))
    , disabledMonitoredItemCount_Variable_(boost::make_shared<ServerVariable>("DisabledMonitoredItemCount_Variable"))
    , discardedMessageCount_Variable_(boost::make_shared<ServerVariable>("DiscardedMessageCount_Variable"))
    , enableCount_Variable_(boost::make_shared<ServerVariable>("EnableCount_Variable"))
    , eventNotificationsCount_Variable_(boost::make_shared<ServerVariable>("EventNotificationsCount_Variable"))
    , eventQueueOverflowCount_Variable_(boost::make_shared<ServerVariable>("EventQueueOverflowCount_Variable"))
    , latePublishRequestCount_Variable_(boost::make_shared<ServerVariable>("LatePublishRequestCount_Variable"))
    , maxKeepAliveCount_Variable_(boost::make_shared<ServerVariable>("MaxKeepAliveCount_Variable"))
    , maxLifetimeCount_Variable_(boost::make_shared<ServerVariable>("MaxLifetimeCount_Variable"))
    , maxNotificationsPerPublish_Variable_(boost::make_shared<ServerVariable>("MaxNotificationsPerPublish_Variable"))
    , modifyCount_Variable_(boost::make_shared<ServerVariable>("ModifyCount_Variable"))
    , monitoredItemCount_Variable_(boost::make_shared<ServerVariable>("MonitoredItemCount_Variable"))
    , monitoringQueueOverflowCount_Variable_(boost::make_shared<ServerVariable>("MonitoringQueueOverflowCount_Variable"))
    , nextSequenceNumber_Variable_(boost::make_shared<ServerVariable>("NextSequenceNumber_Variable"))
    , notificationsCount_Variable_(boost::make_shared<ServerVariable>("NotificationsCount_Variable"))
    , priority_Variable_(boost::make_shared<ServerVariable>("Priority_Variable"))
    , publishRequestCount_Variable_(boost::make_shared<ServerVariable>("PublishRequestCount_Variable"))
    , publishingEnabled_Variable_(boost::make_shared<ServerVariable>("PublishingEnabled_Variable"))
    , publishingInterval_Variable_(boost::make_shared<ServerVariable>("PublishingInterval_Variable"))
    , republishMessageCount_Variable_(boost::make_shared<ServerVariable>("RepublishMessageCount_Variable"))
    , republishMessageRequestCount_Variable_(boost::make_shared<ServerVariable>("RepublishMessageRequestCount_Variable"))
    , republishRequestCount_Variable_(boost::make_shared<ServerVariable>("RepublishRequestCount_Variable"))
    , sessionId_Variable_(boost::make_shared<ServerVariable>("SessionId_Variable"))
    , subscriptionId_Variable_(boost::make_shared<ServerVariable>("SubscriptionId_Variable"))
    , transferRequestCount_Variable_(boost::make_shared<ServerVariable>("TransferRequestCount_Variable"))
    , transferredToAltClientCount_Variable_(boost::make_shared<ServerVariable>("TransferredToAltClientCount_Variable"))
    , transferredToSameClientCount_Variable_(boost::make_shared<ServerVariable>("TransferredToSameClientCount_Variable"))
    , unacknowledgedMessageCount_Variable_(boost::make_shared<ServerVariable>("UnacknowledgedMessageCount_Variable"))
    , variable_(boost::make_shared<ServerVariable>("Variable"))
    {
        variableTypeNamespaceName("http://opcfoundation.org/UA/");
        variableTypeNodeId((OpcUaUInt32)2172);
        setServerVariable(currentKeepAliveCount_Variable_);
        setServerVariable(currentLifetimeCount_Variable_);
        setServerVariable(dataChangeNotificationsCount_Variable_);
        setServerVariable(disableCount_Variable_);
        setServerVariable(disabledMonitoredItemCount_Variable_);
        setServerVariable(discardedMessageCount_Variable_);
        setServerVariable(enableCount_Variable_);
        setServerVariable(eventNotificationsCount_Variable_);
        setServerVariable(eventQueueOverflowCount_Variable_);
        setServerVariable(latePublishRequestCount_Variable_);
        setServerVariable(maxKeepAliveCount_Variable_);
        setServerVariable(maxLifetimeCount_Variable_);
        setServerVariable(maxNotificationsPerPublish_Variable_);
        setServerVariable(modifyCount_Variable_);
        setServerVariable(monitoredItemCount_Variable_);
        setServerVariable(monitoringQueueOverflowCount_Variable_);
        setServerVariable(nextSequenceNumber_Variable_);
        setServerVariable(notificationsCount_Variable_);
        setServerVariable(priority_Variable_);
        setServerVariable(publishRequestCount_Variable_);
        setServerVariable(publishingEnabled_Variable_);
        setServerVariable(publishingInterval_Variable_);
        setServerVariable(republishMessageCount_Variable_);
        setServerVariable(republishMessageRequestCount_Variable_);
        setServerVariable(republishRequestCount_Variable_);
        setServerVariable(sessionId_Variable_);
        setServerVariable(subscriptionId_Variable_);
        setServerVariable(transferRequestCount_Variable_);
        setServerVariable(transferredToAltClientCount_Variable_);
        setServerVariable(transferredToSameClientCount_Variable_);
        setServerVariable(unacknowledgedMessageCount_Variable_);
        setServerVariable(variable_);
    }
    
    SubscriptionDiagnosticsType::SubscriptionDiagnosticsType(const SubscriptionDiagnosticsType& value)
    : VariableBase()
    , currentKeepAliveCount_Variable_(boost::make_shared<ServerVariable>("CurrentKeepAliveCount_Variable"))
    , currentLifetimeCount_Variable_(boost::make_shared<ServerVariable>("CurrentLifetimeCount_Variable"))
    , dataChangeNotificationsCount_Variable_(boost::make_shared<ServerVariable>("DataChangeNotificationsCount_Variable"))
    , disableCount_Variable_(boost::make_shared<ServerVariable>("DisableCount_Variable"))
    , disabledMonitoredItemCount_Variable_(boost::make_shared<ServerVariable>("DisabledMonitoredItemCount_Variable"))
    , discardedMessageCount_Variable_(boost::make_shared<ServerVariable>("DiscardedMessageCount_Variable"))
    , enableCount_Variable_(boost::make_shared<ServerVariable>("EnableCount_Variable"))
    , eventNotificationsCount_Variable_(boost::make_shared<ServerVariable>("EventNotificationsCount_Variable"))
    , eventQueueOverflowCount_Variable_(boost::make_shared<ServerVariable>("EventQueueOverflowCount_Variable"))
    , latePublishRequestCount_Variable_(boost::make_shared<ServerVariable>("LatePublishRequestCount_Variable"))
    , maxKeepAliveCount_Variable_(boost::make_shared<ServerVariable>("MaxKeepAliveCount_Variable"))
    , maxLifetimeCount_Variable_(boost::make_shared<ServerVariable>("MaxLifetimeCount_Variable"))
    , maxNotificationsPerPublish_Variable_(boost::make_shared<ServerVariable>("MaxNotificationsPerPublish_Variable"))
    , modifyCount_Variable_(boost::make_shared<ServerVariable>("ModifyCount_Variable"))
    , monitoredItemCount_Variable_(boost::make_shared<ServerVariable>("MonitoredItemCount_Variable"))
    , monitoringQueueOverflowCount_Variable_(boost::make_shared<ServerVariable>("MonitoringQueueOverflowCount_Variable"))
    , nextSequenceNumber_Variable_(boost::make_shared<ServerVariable>("NextSequenceNumber_Variable"))
    , notificationsCount_Variable_(boost::make_shared<ServerVariable>("NotificationsCount_Variable"))
    , priority_Variable_(boost::make_shared<ServerVariable>("Priority_Variable"))
    , publishRequestCount_Variable_(boost::make_shared<ServerVariable>("PublishRequestCount_Variable"))
    , publishingEnabled_Variable_(boost::make_shared<ServerVariable>("PublishingEnabled_Variable"))
    , publishingInterval_Variable_(boost::make_shared<ServerVariable>("PublishingInterval_Variable"))
    , republishMessageCount_Variable_(boost::make_shared<ServerVariable>("RepublishMessageCount_Variable"))
    , republishMessageRequestCount_Variable_(boost::make_shared<ServerVariable>("RepublishMessageRequestCount_Variable"))
    , republishRequestCount_Variable_(boost::make_shared<ServerVariable>("RepublishRequestCount_Variable"))
    , sessionId_Variable_(boost::make_shared<ServerVariable>("SessionId_Variable"))
    , subscriptionId_Variable_(boost::make_shared<ServerVariable>("SubscriptionId_Variable"))
    , transferRequestCount_Variable_(boost::make_shared<ServerVariable>("TransferRequestCount_Variable"))
    , transferredToAltClientCount_Variable_(boost::make_shared<ServerVariable>("TransferredToAltClientCount_Variable"))
    , transferredToSameClientCount_Variable_(boost::make_shared<ServerVariable>("TransferredToSameClientCount_Variable"))
    , unacknowledgedMessageCount_Variable_(boost::make_shared<ServerVariable>("UnacknowledgedMessageCount_Variable"))
    , variable_(boost::make_shared<ServerVariable>("Variable"))
    {
        variableTypeNamespaceName("http://opcfoundation.org/UA/");
        variableTypeNodeId((OpcUaUInt32)2172);
        setServerVariable(currentKeepAliveCount_Variable_);
        setServerVariable(currentLifetimeCount_Variable_);
        setServerVariable(dataChangeNotificationsCount_Variable_);
        setServerVariable(disableCount_Variable_);
        setServerVariable(disabledMonitoredItemCount_Variable_);
        setServerVariable(discardedMessageCount_Variable_);
        setServerVariable(enableCount_Variable_);
        setServerVariable(eventNotificationsCount_Variable_);
        setServerVariable(eventQueueOverflowCount_Variable_);
        setServerVariable(latePublishRequestCount_Variable_);
        setServerVariable(maxKeepAliveCount_Variable_);
        setServerVariable(maxLifetimeCount_Variable_);
        setServerVariable(maxNotificationsPerPublish_Variable_);
        setServerVariable(modifyCount_Variable_);
        setServerVariable(monitoredItemCount_Variable_);
        setServerVariable(monitoringQueueOverflowCount_Variable_);
        setServerVariable(nextSequenceNumber_Variable_);
        setServerVariable(notificationsCount_Variable_);
        setServerVariable(priority_Variable_);
        setServerVariable(publishRequestCount_Variable_);
        setServerVariable(publishingEnabled_Variable_);
        setServerVariable(publishingInterval_Variable_);
        setServerVariable(republishMessageCount_Variable_);
        setServerVariable(republishMessageRequestCount_Variable_);
        setServerVariable(republishRequestCount_Variable_);
        setServerVariable(sessionId_Variable_);
        setServerVariable(subscriptionId_Variable_);
        setServerVariable(transferRequestCount_Variable_);
        setServerVariable(transferredToAltClientCount_Variable_);
        setServerVariable(transferredToSameClientCount_Variable_);
        setServerVariable(unacknowledgedMessageCount_Variable_);
        setServerVariable(variable_);
    }
    
    SubscriptionDiagnosticsType::~SubscriptionDiagnosticsType(void)
    {
    }

    ServerVariable::SPtr&
    SubscriptionDiagnosticsType::currentKeepAliveCount_Variable(void)
    {
        return currentKeepAliveCount_Variable_;
    }

    ServerVariable::SPtr&
    SubscriptionDiagnosticsType::currentLifetimeCount_Variable(void)
    {
        return currentLifetimeCount_Variable_;
    }

    ServerVariable::SPtr&
    SubscriptionDiagnosticsType::dataChangeNotificationsCount_Variable(void)
    {
        return dataChangeNotificationsCount_Variable_;
    }

    ServerVariable::SPtr&
    SubscriptionDiagnosticsType::disableCount_Variable(void)
    {
        return disableCount_Variable_;
    }

    ServerVariable::SPtr&
    SubscriptionDiagnosticsType::disabledMonitoredItemCount_Variable(void)
    {
        return disabledMonitoredItemCount_Variable_;
    }

    ServerVariable::SPtr&
    SubscriptionDiagnosticsType::discardedMessageCount_Variable(void)
    {
        return discardedMessageCount_Variable_;
    }

    ServerVariable::SPtr&
    SubscriptionDiagnosticsType::enableCount_Variable(void)
    {
        return enableCount_Variable_;
    }

    ServerVariable::SPtr&
    SubscriptionDiagnosticsType::eventNotificationsCount_Variable(void)
    {
        return eventNotificationsCount_Variable_;
    }

    ServerVariable::SPtr&
    SubscriptionDiagnosticsType::eventQueueOverflowCount_Variable(void)
    {
        return eventQueueOverflowCount_Variable_;
    }

    ServerVariable::SPtr&
    SubscriptionDiagnosticsType::latePublishRequestCount_Variable(void)
    {
        return latePublishRequestCount_Variable_;
    }

    ServerVariable::SPtr&
    SubscriptionDiagnosticsType::maxKeepAliveCount_Variable(void)
    {
        return maxKeepAliveCount_Variable_;
    }

    ServerVariable::SPtr&
    SubscriptionDiagnosticsType::maxLifetimeCount_Variable(void)
    {
        return maxLifetimeCount_Variable_;
    }

    ServerVariable::SPtr&
    SubscriptionDiagnosticsType::maxNotificationsPerPublish_Variable(void)
    {
        return maxNotificationsPerPublish_Variable_;
    }

    ServerVariable::SPtr&
    SubscriptionDiagnosticsType::modifyCount_Variable(void)
    {
        return modifyCount_Variable_;
    }

    ServerVariable::SPtr&
    SubscriptionDiagnosticsType::monitoredItemCount_Variable(void)
    {
        return monitoredItemCount_Variable_;
    }

    ServerVariable::SPtr&
    SubscriptionDiagnosticsType::monitoringQueueOverflowCount_Variable(void)
    {
        return monitoringQueueOverflowCount_Variable_;
    }

    ServerVariable::SPtr&
    SubscriptionDiagnosticsType::nextSequenceNumber_Variable(void)
    {
        return nextSequenceNumber_Variable_;
    }

    ServerVariable::SPtr&
    SubscriptionDiagnosticsType::notificationsCount_Variable(void)
    {
        return notificationsCount_Variable_;
    }

    ServerVariable::SPtr&
    SubscriptionDiagnosticsType::priority_Variable(void)
    {
        return priority_Variable_;
    }

    ServerVariable::SPtr&
    SubscriptionDiagnosticsType::publishRequestCount_Variable(void)
    {
        return publishRequestCount_Variable_;
    }

    ServerVariable::SPtr&
    SubscriptionDiagnosticsType::publishingEnabled_Variable(void)
    {
        return publishingEnabled_Variable_;
    }

    ServerVariable::SPtr&
    SubscriptionDiagnosticsType::publishingInterval_Variable(void)
    {
        return publishingInterval_Variable_;
    }

    ServerVariable::SPtr&
    SubscriptionDiagnosticsType::republishMessageCount_Variable(void)
    {
        return republishMessageCount_Variable_;
    }

    ServerVariable::SPtr&
    SubscriptionDiagnosticsType::republishMessageRequestCount_Variable(void)
    {
        return republishMessageRequestCount_Variable_;
    }

    ServerVariable::SPtr&
    SubscriptionDiagnosticsType::republishRequestCount_Variable(void)
    {
        return republishRequestCount_Variable_;
    }

    ServerVariable::SPtr&
    SubscriptionDiagnosticsType::sessionId_Variable(void)
    {
        return sessionId_Variable_;
    }

    ServerVariable::SPtr&
    SubscriptionDiagnosticsType::subscriptionId_Variable(void)
    {
        return subscriptionId_Variable_;
    }

    ServerVariable::SPtr&
    SubscriptionDiagnosticsType::transferRequestCount_Variable(void)
    {
        return transferRequestCount_Variable_;
    }

    ServerVariable::SPtr&
    SubscriptionDiagnosticsType::transferredToAltClientCount_Variable(void)
    {
        return transferredToAltClientCount_Variable_;
    }

    ServerVariable::SPtr&
    SubscriptionDiagnosticsType::transferredToSameClientCount_Variable(void)
    {
        return transferredToSameClientCount_Variable_;
    }

    ServerVariable::SPtr&
    SubscriptionDiagnosticsType::unacknowledgedMessageCount_Variable(void)
    {
        return unacknowledgedMessageCount_Variable_;
    }

    ServerVariable::SPtr&
    SubscriptionDiagnosticsType::variable(void)
    {
        return variable_;
    }

    void
    SubscriptionDiagnosticsType::currentKeepAliveCount_Variable(ServerVariable::SPtr& serverVariable)
    {
        currentKeepAliveCount_Variable_ = serverVariable;
    }

    void
    SubscriptionDiagnosticsType::currentLifetimeCount_Variable(ServerVariable::SPtr& serverVariable)
    {
        currentLifetimeCount_Variable_ = serverVariable;
    }

    void
    SubscriptionDiagnosticsType::dataChangeNotificationsCount_Variable(ServerVariable::SPtr& serverVariable)
    {
        dataChangeNotificationsCount_Variable_ = serverVariable;
    }

    void
    SubscriptionDiagnosticsType::disableCount_Variable(ServerVariable::SPtr& serverVariable)
    {
        disableCount_Variable_ = serverVariable;
    }

    void
    SubscriptionDiagnosticsType::disabledMonitoredItemCount_Variable(ServerVariable::SPtr& serverVariable)
    {
        disabledMonitoredItemCount_Variable_ = serverVariable;
    }

    void
    SubscriptionDiagnosticsType::discardedMessageCount_Variable(ServerVariable::SPtr& serverVariable)
    {
        discardedMessageCount_Variable_ = serverVariable;
    }

    void
    SubscriptionDiagnosticsType::enableCount_Variable(ServerVariable::SPtr& serverVariable)
    {
        enableCount_Variable_ = serverVariable;
    }

    void
    SubscriptionDiagnosticsType::eventNotificationsCount_Variable(ServerVariable::SPtr& serverVariable)
    {
        eventNotificationsCount_Variable_ = serverVariable;
    }

    void
    SubscriptionDiagnosticsType::eventQueueOverflowCount_Variable(ServerVariable::SPtr& serverVariable)
    {
        eventQueueOverflowCount_Variable_ = serverVariable;
    }

    void
    SubscriptionDiagnosticsType::latePublishRequestCount_Variable(ServerVariable::SPtr& serverVariable)
    {
        latePublishRequestCount_Variable_ = serverVariable;
    }

    void
    SubscriptionDiagnosticsType::maxKeepAliveCount_Variable(ServerVariable::SPtr& serverVariable)
    {
        maxKeepAliveCount_Variable_ = serverVariable;
    }

    void
    SubscriptionDiagnosticsType::maxLifetimeCount_Variable(ServerVariable::SPtr& serverVariable)
    {
        maxLifetimeCount_Variable_ = serverVariable;
    }

    void
    SubscriptionDiagnosticsType::maxNotificationsPerPublish_Variable(ServerVariable::SPtr& serverVariable)
    {
        maxNotificationsPerPublish_Variable_ = serverVariable;
    }

    void
    SubscriptionDiagnosticsType::modifyCount_Variable(ServerVariable::SPtr& serverVariable)
    {
        modifyCount_Variable_ = serverVariable;
    }

    void
    SubscriptionDiagnosticsType::monitoredItemCount_Variable(ServerVariable::SPtr& serverVariable)
    {
        monitoredItemCount_Variable_ = serverVariable;
    }

    void
    SubscriptionDiagnosticsType::monitoringQueueOverflowCount_Variable(ServerVariable::SPtr& serverVariable)
    {
        monitoringQueueOverflowCount_Variable_ = serverVariable;
    }

    void
    SubscriptionDiagnosticsType::nextSequenceNumber_Variable(ServerVariable::SPtr& serverVariable)
    {
        nextSequenceNumber_Variable_ = serverVariable;
    }

    void
    SubscriptionDiagnosticsType::notificationsCount_Variable(ServerVariable::SPtr& serverVariable)
    {
        notificationsCount_Variable_ = serverVariable;
    }

    void
    SubscriptionDiagnosticsType::priority_Variable(ServerVariable::SPtr& serverVariable)
    {
        priority_Variable_ = serverVariable;
    }

    void
    SubscriptionDiagnosticsType::publishRequestCount_Variable(ServerVariable::SPtr& serverVariable)
    {
        publishRequestCount_Variable_ = serverVariable;
    }

    void
    SubscriptionDiagnosticsType::publishingEnabled_Variable(ServerVariable::SPtr& serverVariable)
    {
        publishingEnabled_Variable_ = serverVariable;
    }

    void
    SubscriptionDiagnosticsType::publishingInterval_Variable(ServerVariable::SPtr& serverVariable)
    {
        publishingInterval_Variable_ = serverVariable;
    }

    void
    SubscriptionDiagnosticsType::republishMessageCount_Variable(ServerVariable::SPtr& serverVariable)
    {
        republishMessageCount_Variable_ = serverVariable;
    }

    void
    SubscriptionDiagnosticsType::republishMessageRequestCount_Variable(ServerVariable::SPtr& serverVariable)
    {
        republishMessageRequestCount_Variable_ = serverVariable;
    }

    void
    SubscriptionDiagnosticsType::republishRequestCount_Variable(ServerVariable::SPtr& serverVariable)
    {
        republishRequestCount_Variable_ = serverVariable;
    }

    void
    SubscriptionDiagnosticsType::sessionId_Variable(ServerVariable::SPtr& serverVariable)
    {
        sessionId_Variable_ = serverVariable;
    }

    void
    SubscriptionDiagnosticsType::subscriptionId_Variable(ServerVariable::SPtr& serverVariable)
    {
        subscriptionId_Variable_ = serverVariable;
    }

    void
    SubscriptionDiagnosticsType::transferRequestCount_Variable(ServerVariable::SPtr& serverVariable)
    {
        transferRequestCount_Variable_ = serverVariable;
    }

    void
    SubscriptionDiagnosticsType::transferredToAltClientCount_Variable(ServerVariable::SPtr& serverVariable)
    {
        transferredToAltClientCount_Variable_ = serverVariable;
    }

    void
    SubscriptionDiagnosticsType::transferredToSameClientCount_Variable(ServerVariable::SPtr& serverVariable)
    {
        transferredToSameClientCount_Variable_ = serverVariable;
    }

    void
    SubscriptionDiagnosticsType::unacknowledgedMessageCount_Variable(ServerVariable::SPtr& serverVariable)
    {
        unacknowledgedMessageCount_Variable_ = serverVariable;
    }

    void
    SubscriptionDiagnosticsType::variable(ServerVariable::SPtr& serverVariable)
    {
        variable_ = serverVariable;
    }

    bool
    SubscriptionDiagnosticsType::get_CurrentKeepAliveCount_Variable(OpcUaDataValue& dataValue)
    {
        return currentKeepAliveCount_Variable_->getDataValue(dataValue);
    }

    bool
    SubscriptionDiagnosticsType::get_CurrentLifetimeCount_Variable(OpcUaDataValue& dataValue)
    {
        return currentLifetimeCount_Variable_->getDataValue(dataValue);
    }

    bool
    SubscriptionDiagnosticsType::get_DataChangeNotificationsCount_Variable(OpcUaDataValue& dataValue)
    {
        return dataChangeNotificationsCount_Variable_->getDataValue(dataValue);
    }

    bool
    SubscriptionDiagnosticsType::get_DisableCount_Variable(OpcUaDataValue& dataValue)
    {
        return disableCount_Variable_->getDataValue(dataValue);
    }

    bool
    SubscriptionDiagnosticsType::get_DisabledMonitoredItemCount_Variable(OpcUaDataValue& dataValue)
    {
        return disabledMonitoredItemCount_Variable_->getDataValue(dataValue);
    }

    bool
    SubscriptionDiagnosticsType::get_DiscardedMessageCount_Variable(OpcUaDataValue& dataValue)
    {
        return discardedMessageCount_Variable_->getDataValue(dataValue);
    }

    bool
    SubscriptionDiagnosticsType::get_EnableCount_Variable(OpcUaDataValue& dataValue)
    {
        return enableCount_Variable_->getDataValue(dataValue);
    }

    bool
    SubscriptionDiagnosticsType::get_EventNotificationsCount_Variable(OpcUaDataValue& dataValue)
    {
        return eventNotificationsCount_Variable_->getDataValue(dataValue);
    }

    bool
    SubscriptionDiagnosticsType::get_EventQueueOverflowCount_Variable(OpcUaDataValue& dataValue)
    {
        return eventQueueOverflowCount_Variable_->getDataValue(dataValue);
    }

    bool
    SubscriptionDiagnosticsType::get_LatePublishRequestCount_Variable(OpcUaDataValue& dataValue)
    {
        return latePublishRequestCount_Variable_->getDataValue(dataValue);
    }

    bool
    SubscriptionDiagnosticsType::get_MaxKeepAliveCount_Variable(OpcUaDataValue& dataValue)
    {
        return maxKeepAliveCount_Variable_->getDataValue(dataValue);
    }

    bool
    SubscriptionDiagnosticsType::get_MaxLifetimeCount_Variable(OpcUaDataValue& dataValue)
    {
        return maxLifetimeCount_Variable_->getDataValue(dataValue);
    }

    bool
    SubscriptionDiagnosticsType::get_MaxNotificationsPerPublish_Variable(OpcUaDataValue& dataValue)
    {
        return maxNotificationsPerPublish_Variable_->getDataValue(dataValue);
    }

    bool
    SubscriptionDiagnosticsType::get_ModifyCount_Variable(OpcUaDataValue& dataValue)
    {
        return modifyCount_Variable_->getDataValue(dataValue);
    }

    bool
    SubscriptionDiagnosticsType::get_MonitoredItemCount_Variable(OpcUaDataValue& dataValue)
    {
        return monitoredItemCount_Variable_->getDataValue(dataValue);
    }

    bool
    SubscriptionDiagnosticsType::get_MonitoringQueueOverflowCount_Variable(OpcUaDataValue& dataValue)
    {
        return monitoringQueueOverflowCount_Variable_->getDataValue(dataValue);
    }

    bool
    SubscriptionDiagnosticsType::get_NextSequenceNumber_Variable(OpcUaDataValue& dataValue)
    {
        return nextSequenceNumber_Variable_->getDataValue(dataValue);
    }

    bool
    SubscriptionDiagnosticsType::get_NotificationsCount_Variable(OpcUaDataValue& dataValue)
    {
        return notificationsCount_Variable_->getDataValue(dataValue);
    }

    bool
    SubscriptionDiagnosticsType::get_Priority_Variable(OpcUaDataValue& dataValue)
    {
        return priority_Variable_->getDataValue(dataValue);
    }

    bool
    SubscriptionDiagnosticsType::get_PublishRequestCount_Variable(OpcUaDataValue& dataValue)
    {
        return publishRequestCount_Variable_->getDataValue(dataValue);
    }

    bool
    SubscriptionDiagnosticsType::get_PublishingEnabled_Variable(OpcUaDataValue& dataValue)
    {
        return publishingEnabled_Variable_->getDataValue(dataValue);
    }

    bool
    SubscriptionDiagnosticsType::get_PublishingInterval_Variable(OpcUaDataValue& dataValue)
    {
        return publishingInterval_Variable_->getDataValue(dataValue);
    }

    bool
    SubscriptionDiagnosticsType::get_RepublishMessageCount_Variable(OpcUaDataValue& dataValue)
    {
        return republishMessageCount_Variable_->getDataValue(dataValue);
    }

    bool
    SubscriptionDiagnosticsType::get_RepublishMessageRequestCount_Variable(OpcUaDataValue& dataValue)
    {
        return republishMessageRequestCount_Variable_->getDataValue(dataValue);
    }

    bool
    SubscriptionDiagnosticsType::get_RepublishRequestCount_Variable(OpcUaDataValue& dataValue)
    {
        return republishRequestCount_Variable_->getDataValue(dataValue);
    }

    bool
    SubscriptionDiagnosticsType::get_SessionId_Variable(OpcUaDataValue& dataValue)
    {
        return sessionId_Variable_->getDataValue(dataValue);
    }

    bool
    SubscriptionDiagnosticsType::get_SubscriptionId_Variable(OpcUaDataValue& dataValue)
    {
        return subscriptionId_Variable_->getDataValue(dataValue);
    }

    bool
    SubscriptionDiagnosticsType::get_TransferRequestCount_Variable(OpcUaDataValue& dataValue)
    {
        return transferRequestCount_Variable_->getDataValue(dataValue);
    }

    bool
    SubscriptionDiagnosticsType::get_TransferredToAltClientCount_Variable(OpcUaDataValue& dataValue)
    {
        return transferredToAltClientCount_Variable_->getDataValue(dataValue);
    }

    bool
    SubscriptionDiagnosticsType::get_TransferredToSameClientCount_Variable(OpcUaDataValue& dataValue)
    {
        return transferredToSameClientCount_Variable_->getDataValue(dataValue);
    }

    bool
    SubscriptionDiagnosticsType::get_UnacknowledgedMessageCount_Variable(OpcUaDataValue& dataValue)
    {
        return unacknowledgedMessageCount_Variable_->getDataValue(dataValue);
    }

    bool
    SubscriptionDiagnosticsType::get_Variable(OpcUaDataValue& dataValue)
    {
        return variable_->getDataValue(dataValue);
    }

    bool
    SubscriptionDiagnosticsType::set_CurrentKeepAliveCount_Variable(const OpcUaDataValue& dataValue)
    {
        return currentKeepAliveCount_Variable_->setDataValue(dataValue);
    }

    bool
    SubscriptionDiagnosticsType::set_CurrentLifetimeCount_Variable(const OpcUaDataValue& dataValue)
    {
        return currentLifetimeCount_Variable_->setDataValue(dataValue);
    }

    bool
    SubscriptionDiagnosticsType::set_DataChangeNotificationsCount_Variable(const OpcUaDataValue& dataValue)
    {
        return dataChangeNotificationsCount_Variable_->setDataValue(dataValue);
    }

    bool
    SubscriptionDiagnosticsType::set_DisableCount_Variable(const OpcUaDataValue& dataValue)
    {
        return disableCount_Variable_->setDataValue(dataValue);
    }

    bool
    SubscriptionDiagnosticsType::set_DisabledMonitoredItemCount_Variable(const OpcUaDataValue& dataValue)
    {
        return disabledMonitoredItemCount_Variable_->setDataValue(dataValue);
    }

    bool
    SubscriptionDiagnosticsType::set_DiscardedMessageCount_Variable(const OpcUaDataValue& dataValue)
    {
        return discardedMessageCount_Variable_->setDataValue(dataValue);
    }

    bool
    SubscriptionDiagnosticsType::set_EnableCount_Variable(const OpcUaDataValue& dataValue)
    {
        return enableCount_Variable_->setDataValue(dataValue);
    }

    bool
    SubscriptionDiagnosticsType::set_EventNotificationsCount_Variable(const OpcUaDataValue& dataValue)
    {
        return eventNotificationsCount_Variable_->setDataValue(dataValue);
    }

    bool
    SubscriptionDiagnosticsType::set_EventQueueOverflowCount_Variable(const OpcUaDataValue& dataValue)
    {
        return eventQueueOverflowCount_Variable_->setDataValue(dataValue);
    }

    bool
    SubscriptionDiagnosticsType::set_LatePublishRequestCount_Variable(const OpcUaDataValue& dataValue)
    {
        return latePublishRequestCount_Variable_->setDataValue(dataValue);
    }

    bool
    SubscriptionDiagnosticsType::set_MaxKeepAliveCount_Variable(const OpcUaDataValue& dataValue)
    {
        return maxKeepAliveCount_Variable_->setDataValue(dataValue);
    }

    bool
    SubscriptionDiagnosticsType::set_MaxLifetimeCount_Variable(const OpcUaDataValue& dataValue)
    {
        return maxLifetimeCount_Variable_->setDataValue(dataValue);
    }

    bool
    SubscriptionDiagnosticsType::set_MaxNotificationsPerPublish_Variable(const OpcUaDataValue& dataValue)
    {
        return maxNotificationsPerPublish_Variable_->setDataValue(dataValue);
    }

    bool
    SubscriptionDiagnosticsType::set_ModifyCount_Variable(const OpcUaDataValue& dataValue)
    {
        return modifyCount_Variable_->setDataValue(dataValue);
    }

    bool
    SubscriptionDiagnosticsType::set_MonitoredItemCount_Variable(const OpcUaDataValue& dataValue)
    {
        return monitoredItemCount_Variable_->setDataValue(dataValue);
    }

    bool
    SubscriptionDiagnosticsType::set_MonitoringQueueOverflowCount_Variable(const OpcUaDataValue& dataValue)
    {
        return monitoringQueueOverflowCount_Variable_->setDataValue(dataValue);
    }

    bool
    SubscriptionDiagnosticsType::set_NextSequenceNumber_Variable(const OpcUaDataValue& dataValue)
    {
        return nextSequenceNumber_Variable_->setDataValue(dataValue);
    }

    bool
    SubscriptionDiagnosticsType::set_NotificationsCount_Variable(const OpcUaDataValue& dataValue)
    {
        return notificationsCount_Variable_->setDataValue(dataValue);
    }

    bool
    SubscriptionDiagnosticsType::set_Priority_Variable(const OpcUaDataValue& dataValue)
    {
        return priority_Variable_->setDataValue(dataValue);
    }

    bool
    SubscriptionDiagnosticsType::set_PublishRequestCount_Variable(const OpcUaDataValue& dataValue)
    {
        return publishRequestCount_Variable_->setDataValue(dataValue);
    }

    bool
    SubscriptionDiagnosticsType::set_PublishingEnabled_Variable(const OpcUaDataValue& dataValue)
    {
        return publishingEnabled_Variable_->setDataValue(dataValue);
    }

    bool
    SubscriptionDiagnosticsType::set_PublishingInterval_Variable(const OpcUaDataValue& dataValue)
    {
        return publishingInterval_Variable_->setDataValue(dataValue);
    }

    bool
    SubscriptionDiagnosticsType::set_RepublishMessageCount_Variable(const OpcUaDataValue& dataValue)
    {
        return republishMessageCount_Variable_->setDataValue(dataValue);
    }

    bool
    SubscriptionDiagnosticsType::set_RepublishMessageRequestCount_Variable(const OpcUaDataValue& dataValue)
    {
        return republishMessageRequestCount_Variable_->setDataValue(dataValue);
    }

    bool
    SubscriptionDiagnosticsType::set_RepublishRequestCount_Variable(const OpcUaDataValue& dataValue)
    {
        return republishRequestCount_Variable_->setDataValue(dataValue);
    }

    bool
    SubscriptionDiagnosticsType::set_SessionId_Variable(const OpcUaDataValue& dataValue)
    {
        return sessionId_Variable_->setDataValue(dataValue);
    }

    bool
    SubscriptionDiagnosticsType::set_SubscriptionId_Variable(const OpcUaDataValue& dataValue)
    {
        return subscriptionId_Variable_->setDataValue(dataValue);
    }

    bool
    SubscriptionDiagnosticsType::set_TransferRequestCount_Variable(const OpcUaDataValue& dataValue)
    {
        return transferRequestCount_Variable_->setDataValue(dataValue);
    }

    bool
    SubscriptionDiagnosticsType::set_TransferredToAltClientCount_Variable(const OpcUaDataValue& dataValue)
    {
        return transferredToAltClientCount_Variable_->setDataValue(dataValue);
    }

    bool
    SubscriptionDiagnosticsType::set_TransferredToSameClientCount_Variable(const OpcUaDataValue& dataValue)
    {
        return transferredToSameClientCount_Variable_->setDataValue(dataValue);
    }

    bool
    SubscriptionDiagnosticsType::set_UnacknowledgedMessageCount_Variable(const OpcUaDataValue& dataValue)
    {
        return unacknowledgedMessageCount_Variable_->setDataValue(dataValue);
    }

    bool
    SubscriptionDiagnosticsType::set_Variable(const OpcUaDataValue& dataValue)
    {
        return variable_->setDataValue(dataValue);
    }

}
