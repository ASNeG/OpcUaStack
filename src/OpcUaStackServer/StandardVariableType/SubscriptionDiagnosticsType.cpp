/*
    VariableTypeClass: SubscriptionDiagnosticsType

    Generated Source Code - please do not change this source code

    VariableTypeCodeGenerator Version:
        OpcUaStackCore - 3.0.1

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackServer/StandardVariableType/SubscriptionDiagnosticsType.h"

namespace OpcUaStackServer
{
    
    SubscriptionDiagnosticsType::SubscriptionDiagnosticsType(void)
    : BaseDataVariableType()
    , namespaceName_("http://opcfoundation.org/UA/")
    , namespaceIndex_(0)
    , sessionId_(constructSPtr<ServerVariable>("SessionId"))
    , subscriptionId_(constructSPtr<ServerVariable>("SubscriptionId"))
    , priority_(constructSPtr<ServerVariable>("Priority"))
    , publishingInterval_(constructSPtr<ServerVariable>("PublishingInterval"))
    , maxKeepAliveCount_(constructSPtr<ServerVariable>("MaxKeepAliveCount"))
    , maxLifetimeCount_(constructSPtr<ServerVariable>("MaxLifetimeCount"))
    , maxNotificationsPerPublish_(constructSPtr<ServerVariable>("MaxNotificationsPerPublish"))
    , publishingEnabled_(constructSPtr<ServerVariable>("PublishingEnabled"))
    , modifyCount_(constructSPtr<ServerVariable>("ModifyCount"))
    , enableCount_(constructSPtr<ServerVariable>("EnableCount"))
    , disableCount_(constructSPtr<ServerVariable>("DisableCount"))
    , republishRequestCount_(constructSPtr<ServerVariable>("RepublishRequestCount"))
    , republishMessageRequestCount_(constructSPtr<ServerVariable>("RepublishMessageRequestCount"))
    , republishMessageCount_(constructSPtr<ServerVariable>("RepublishMessageCount"))
    , transferRequestCount_(constructSPtr<ServerVariable>("TransferRequestCount"))
    , transferredToAltClientCount_(constructSPtr<ServerVariable>("TransferredToAltClientCount"))
    , transferredToSameClientCount_(constructSPtr<ServerVariable>("TransferredToSameClientCount"))
    , publishRequestCount_(constructSPtr<ServerVariable>("PublishRequestCount"))
    , dataChangeNotificationsCount_(constructSPtr<ServerVariable>("DataChangeNotificationsCount"))
    , eventNotificationsCount_(constructSPtr<ServerVariable>("EventNotificationsCount"))
    , notificationsCount_(constructSPtr<ServerVariable>("NotificationsCount"))
    , latePublishRequestCount_(constructSPtr<ServerVariable>("LatePublishRequestCount"))
    , currentKeepAliveCount_(constructSPtr<ServerVariable>("CurrentKeepAliveCount"))
    , currentLifetimeCount_(constructSPtr<ServerVariable>("CurrentLifetimeCount"))
    , unacknowledgedMessageCount_(constructSPtr<ServerVariable>("UnacknowledgedMessageCount"))
    , discardedMessageCount_(constructSPtr<ServerVariable>("DiscardedMessageCount"))
    , monitoredItemCount_(constructSPtr<ServerVariable>("MonitoredItemCount"))
    , disabledMonitoredItemCount_(constructSPtr<ServerVariable>("DisabledMonitoredItemCount"))
    , monitoringQueueOverflowCount_(constructSPtr<ServerVariable>("MonitoringQueueOverflowCount"))
    , nextSequenceNumber_(constructSPtr<ServerVariable>("NextSequenceNumber"))
    , eventQueueOverFlowCount_(constructSPtr<ServerVariable>("EventQueueOverFlowCount"))
    {
        variableTypeNamespace(namespaceName_);
        variableType(OpcUaNodeId(2172));
        serverVariables().registerServerVariable(sessionId_);
        serverVariables().registerServerVariable(subscriptionId_);
        serverVariables().registerServerVariable(priority_);
        serverVariables().registerServerVariable(publishingInterval_);
        serverVariables().registerServerVariable(maxKeepAliveCount_);
        serverVariables().registerServerVariable(maxLifetimeCount_);
        serverVariables().registerServerVariable(maxNotificationsPerPublish_);
        serverVariables().registerServerVariable(publishingEnabled_);
        serverVariables().registerServerVariable(modifyCount_);
        serverVariables().registerServerVariable(enableCount_);
        serverVariables().registerServerVariable(disableCount_);
        serverVariables().registerServerVariable(republishRequestCount_);
        serverVariables().registerServerVariable(republishMessageRequestCount_);
        serverVariables().registerServerVariable(republishMessageCount_);
        serverVariables().registerServerVariable(transferRequestCount_);
        serverVariables().registerServerVariable(transferredToAltClientCount_);
        serverVariables().registerServerVariable(transferredToSameClientCount_);
        serverVariables().registerServerVariable(publishRequestCount_);
        serverVariables().registerServerVariable(dataChangeNotificationsCount_);
        serverVariables().registerServerVariable(eventNotificationsCount_);
        serverVariables().registerServerVariable(notificationsCount_);
        serverVariables().registerServerVariable(latePublishRequestCount_);
        serverVariables().registerServerVariable(currentKeepAliveCount_);
        serverVariables().registerServerVariable(currentLifetimeCount_);
        serverVariables().registerServerVariable(unacknowledgedMessageCount_);
        serverVariables().registerServerVariable(discardedMessageCount_);
        serverVariables().registerServerVariable(monitoredItemCount_);
        serverVariables().registerServerVariable(disabledMonitoredItemCount_);
        serverVariables().registerServerVariable(monitoringQueueOverflowCount_);
        serverVariables().registerServerVariable(nextSequenceNumber_);
        serverVariables().registerServerVariable(eventQueueOverFlowCount_);
    }
    
    SubscriptionDiagnosticsType::~SubscriptionDiagnosticsType(void)
    {
    }
    
    bool
    SubscriptionDiagnosticsType::linkInstanceWithModel(const OpcUaNodeId& nodeId)
    {
        if (!getNamespaceIndexFromNamespaceName(namespaceName_, namespaceIndex_)) return false;
        sessionId_->addBrowsePath(nodeId, OpcUaQualifiedName("SessionId", namespaceIndex_));
        subscriptionId_->addBrowsePath(nodeId, OpcUaQualifiedName("SubscriptionId", namespaceIndex_));
        priority_->addBrowsePath(nodeId, OpcUaQualifiedName("Priority", namespaceIndex_));
        publishingInterval_->addBrowsePath(nodeId, OpcUaQualifiedName("PublishingInterval", namespaceIndex_));
        maxKeepAliveCount_->addBrowsePath(nodeId, OpcUaQualifiedName("MaxKeepAliveCount", namespaceIndex_));
        maxLifetimeCount_->addBrowsePath(nodeId, OpcUaQualifiedName("MaxLifetimeCount", namespaceIndex_));
        maxNotificationsPerPublish_->addBrowsePath(nodeId, OpcUaQualifiedName("MaxNotificationsPerPublish", namespaceIndex_));
        publishingEnabled_->addBrowsePath(nodeId, OpcUaQualifiedName("PublishingEnabled", namespaceIndex_));
        modifyCount_->addBrowsePath(nodeId, OpcUaQualifiedName("ModifyCount", namespaceIndex_));
        enableCount_->addBrowsePath(nodeId, OpcUaQualifiedName("EnableCount", namespaceIndex_));
        disableCount_->addBrowsePath(nodeId, OpcUaQualifiedName("DisableCount", namespaceIndex_));
        republishRequestCount_->addBrowsePath(nodeId, OpcUaQualifiedName("RepublishRequestCount", namespaceIndex_));
        republishMessageRequestCount_->addBrowsePath(nodeId, OpcUaQualifiedName("RepublishMessageRequestCount", namespaceIndex_));
        republishMessageCount_->addBrowsePath(nodeId, OpcUaQualifiedName("RepublishMessageCount", namespaceIndex_));
        transferRequestCount_->addBrowsePath(nodeId, OpcUaQualifiedName("TransferRequestCount", namespaceIndex_));
        transferredToAltClientCount_->addBrowsePath(nodeId, OpcUaQualifiedName("TransferredToAltClientCount", namespaceIndex_));
        transferredToSameClientCount_->addBrowsePath(nodeId, OpcUaQualifiedName("TransferredToSameClientCount", namespaceIndex_));
        publishRequestCount_->addBrowsePath(nodeId, OpcUaQualifiedName("PublishRequestCount", namespaceIndex_));
        dataChangeNotificationsCount_->addBrowsePath(nodeId, OpcUaQualifiedName("DataChangeNotificationsCount", namespaceIndex_));
        eventNotificationsCount_->addBrowsePath(nodeId, OpcUaQualifiedName("EventNotificationsCount", namespaceIndex_));
        notificationsCount_->addBrowsePath(nodeId, OpcUaQualifiedName("NotificationsCount", namespaceIndex_));
        latePublishRequestCount_->addBrowsePath(nodeId, OpcUaQualifiedName("LatePublishRequestCount", namespaceIndex_));
        currentKeepAliveCount_->addBrowsePath(nodeId, OpcUaQualifiedName("CurrentKeepAliveCount", namespaceIndex_));
        currentLifetimeCount_->addBrowsePath(nodeId, OpcUaQualifiedName("CurrentLifetimeCount", namespaceIndex_));
        unacknowledgedMessageCount_->addBrowsePath(nodeId, OpcUaQualifiedName("UnacknowledgedMessageCount", namespaceIndex_));
        discardedMessageCount_->addBrowsePath(nodeId, OpcUaQualifiedName("DiscardedMessageCount", namespaceIndex_));
        monitoredItemCount_->addBrowsePath(nodeId, OpcUaQualifiedName("MonitoredItemCount", namespaceIndex_));
        disabledMonitoredItemCount_->addBrowsePath(nodeId, OpcUaQualifiedName("DisabledMonitoredItemCount", namespaceIndex_));
        monitoringQueueOverflowCount_->addBrowsePath(nodeId, OpcUaQualifiedName("MonitoringQueueOverflowCount", namespaceIndex_));
        nextSequenceNumber_->addBrowsePath(nodeId, OpcUaQualifiedName("NextSequenceNumber", namespaceIndex_));
        eventQueueOverFlowCount_->addBrowsePath(nodeId, OpcUaQualifiedName("EventQueueOverFlowCount", namespaceIndex_));
        BaseDataVariableType::linkInstanceWithModel(nodeId);
    }
    
    BaseNodeClass::SPtr
    SubscriptionDiagnosticsType::sessionId(void)
    {
        return sessionId_->baseNode().lock();
    }
    
    bool
    SubscriptionDiagnosticsType::setSessionId(const OpcUaDataValue& dataValue)
    {
        return sessionId_->setDataValue(dataValue);
    }
    
    bool
    SubscriptionDiagnosticsType::getSessionId(OpcUaDataValue& dataValue)
    {
        return sessionId_->getDataValue(dataValue);
    }
    
    void
    SubscriptionDiagnosticsType::setUpdateCallbackSessionId(Callback::SPtr& callback)
    {
        sessionId_->callback(callback);
    }
    
    BaseNodeClass::SPtr
    SubscriptionDiagnosticsType::subscriptionId(void)
    {
        return subscriptionId_->baseNode().lock();
    }
    
    bool
    SubscriptionDiagnosticsType::setSubscriptionId(const OpcUaDataValue& dataValue)
    {
        return subscriptionId_->setDataValue(dataValue);
    }
    
    bool
    SubscriptionDiagnosticsType::getSubscriptionId(OpcUaDataValue& dataValue)
    {
        return subscriptionId_->getDataValue(dataValue);
    }
    
    void
    SubscriptionDiagnosticsType::setUpdateCallbackSubscriptionId(Callback::SPtr& callback)
    {
        subscriptionId_->callback(callback);
    }
    
    BaseNodeClass::SPtr
    SubscriptionDiagnosticsType::priority(void)
    {
        return priority_->baseNode().lock();
    }
    
    bool
    SubscriptionDiagnosticsType::setPriority(const OpcUaDataValue& dataValue)
    {
        return priority_->setDataValue(dataValue);
    }
    
    bool
    SubscriptionDiagnosticsType::getPriority(OpcUaDataValue& dataValue)
    {
        return priority_->getDataValue(dataValue);
    }
    
    void
    SubscriptionDiagnosticsType::setUpdateCallbackPriority(Callback::SPtr& callback)
    {
        priority_->callback(callback);
    }
    
    BaseNodeClass::SPtr
    SubscriptionDiagnosticsType::publishingInterval(void)
    {
        return publishingInterval_->baseNode().lock();
    }
    
    bool
    SubscriptionDiagnosticsType::setPublishingInterval(const OpcUaDataValue& dataValue)
    {
        return publishingInterval_->setDataValue(dataValue);
    }
    
    bool
    SubscriptionDiagnosticsType::getPublishingInterval(OpcUaDataValue& dataValue)
    {
        return publishingInterval_->getDataValue(dataValue);
    }
    
    void
    SubscriptionDiagnosticsType::setUpdateCallbackPublishingInterval(Callback::SPtr& callback)
    {
        publishingInterval_->callback(callback);
    }
    
    BaseNodeClass::SPtr
    SubscriptionDiagnosticsType::maxKeepAliveCount(void)
    {
        return maxKeepAliveCount_->baseNode().lock();
    }
    
    bool
    SubscriptionDiagnosticsType::setMaxKeepAliveCount(const OpcUaDataValue& dataValue)
    {
        return maxKeepAliveCount_->setDataValue(dataValue);
    }
    
    bool
    SubscriptionDiagnosticsType::getMaxKeepAliveCount(OpcUaDataValue& dataValue)
    {
        return maxKeepAliveCount_->getDataValue(dataValue);
    }
    
    void
    SubscriptionDiagnosticsType::setUpdateCallbackMaxKeepAliveCount(Callback::SPtr& callback)
    {
        maxKeepAliveCount_->callback(callback);
    }
    
    BaseNodeClass::SPtr
    SubscriptionDiagnosticsType::maxLifetimeCount(void)
    {
        return maxLifetimeCount_->baseNode().lock();
    }
    
    bool
    SubscriptionDiagnosticsType::setMaxLifetimeCount(const OpcUaDataValue& dataValue)
    {
        return maxLifetimeCount_->setDataValue(dataValue);
    }
    
    bool
    SubscriptionDiagnosticsType::getMaxLifetimeCount(OpcUaDataValue& dataValue)
    {
        return maxLifetimeCount_->getDataValue(dataValue);
    }
    
    void
    SubscriptionDiagnosticsType::setUpdateCallbackMaxLifetimeCount(Callback::SPtr& callback)
    {
        maxLifetimeCount_->callback(callback);
    }
    
    BaseNodeClass::SPtr
    SubscriptionDiagnosticsType::maxNotificationsPerPublish(void)
    {
        return maxNotificationsPerPublish_->baseNode().lock();
    }
    
    bool
    SubscriptionDiagnosticsType::setMaxNotificationsPerPublish(const OpcUaDataValue& dataValue)
    {
        return maxNotificationsPerPublish_->setDataValue(dataValue);
    }
    
    bool
    SubscriptionDiagnosticsType::getMaxNotificationsPerPublish(OpcUaDataValue& dataValue)
    {
        return maxNotificationsPerPublish_->getDataValue(dataValue);
    }
    
    void
    SubscriptionDiagnosticsType::setUpdateCallbackMaxNotificationsPerPublish(Callback::SPtr& callback)
    {
        maxNotificationsPerPublish_->callback(callback);
    }
    
    BaseNodeClass::SPtr
    SubscriptionDiagnosticsType::publishingEnabled(void)
    {
        return publishingEnabled_->baseNode().lock();
    }
    
    bool
    SubscriptionDiagnosticsType::setPublishingEnabled(const OpcUaDataValue& dataValue)
    {
        return publishingEnabled_->setDataValue(dataValue);
    }
    
    bool
    SubscriptionDiagnosticsType::getPublishingEnabled(OpcUaDataValue& dataValue)
    {
        return publishingEnabled_->getDataValue(dataValue);
    }
    
    void
    SubscriptionDiagnosticsType::setUpdateCallbackPublishingEnabled(Callback::SPtr& callback)
    {
        publishingEnabled_->callback(callback);
    }
    
    BaseNodeClass::SPtr
    SubscriptionDiagnosticsType::modifyCount(void)
    {
        return modifyCount_->baseNode().lock();
    }
    
    bool
    SubscriptionDiagnosticsType::setModifyCount(const OpcUaDataValue& dataValue)
    {
        return modifyCount_->setDataValue(dataValue);
    }
    
    bool
    SubscriptionDiagnosticsType::getModifyCount(OpcUaDataValue& dataValue)
    {
        return modifyCount_->getDataValue(dataValue);
    }
    
    void
    SubscriptionDiagnosticsType::setUpdateCallbackModifyCount(Callback::SPtr& callback)
    {
        modifyCount_->callback(callback);
    }
    
    BaseNodeClass::SPtr
    SubscriptionDiagnosticsType::enableCount(void)
    {
        return enableCount_->baseNode().lock();
    }
    
    bool
    SubscriptionDiagnosticsType::setEnableCount(const OpcUaDataValue& dataValue)
    {
        return enableCount_->setDataValue(dataValue);
    }
    
    bool
    SubscriptionDiagnosticsType::getEnableCount(OpcUaDataValue& dataValue)
    {
        return enableCount_->getDataValue(dataValue);
    }
    
    void
    SubscriptionDiagnosticsType::setUpdateCallbackEnableCount(Callback::SPtr& callback)
    {
        enableCount_->callback(callback);
    }
    
    BaseNodeClass::SPtr
    SubscriptionDiagnosticsType::disableCount(void)
    {
        return disableCount_->baseNode().lock();
    }
    
    bool
    SubscriptionDiagnosticsType::setDisableCount(const OpcUaDataValue& dataValue)
    {
        return disableCount_->setDataValue(dataValue);
    }
    
    bool
    SubscriptionDiagnosticsType::getDisableCount(OpcUaDataValue& dataValue)
    {
        return disableCount_->getDataValue(dataValue);
    }
    
    void
    SubscriptionDiagnosticsType::setUpdateCallbackDisableCount(Callback::SPtr& callback)
    {
        disableCount_->callback(callback);
    }
    
    BaseNodeClass::SPtr
    SubscriptionDiagnosticsType::republishRequestCount(void)
    {
        return republishRequestCount_->baseNode().lock();
    }
    
    bool
    SubscriptionDiagnosticsType::setRepublishRequestCount(const OpcUaDataValue& dataValue)
    {
        return republishRequestCount_->setDataValue(dataValue);
    }
    
    bool
    SubscriptionDiagnosticsType::getRepublishRequestCount(OpcUaDataValue& dataValue)
    {
        return republishRequestCount_->getDataValue(dataValue);
    }
    
    void
    SubscriptionDiagnosticsType::setUpdateCallbackRepublishRequestCount(Callback::SPtr& callback)
    {
        republishRequestCount_->callback(callback);
    }
    
    BaseNodeClass::SPtr
    SubscriptionDiagnosticsType::republishMessageRequestCount(void)
    {
        return republishMessageRequestCount_->baseNode().lock();
    }
    
    bool
    SubscriptionDiagnosticsType::setRepublishMessageRequestCount(const OpcUaDataValue& dataValue)
    {
        return republishMessageRequestCount_->setDataValue(dataValue);
    }
    
    bool
    SubscriptionDiagnosticsType::getRepublishMessageRequestCount(OpcUaDataValue& dataValue)
    {
        return republishMessageRequestCount_->getDataValue(dataValue);
    }
    
    void
    SubscriptionDiagnosticsType::setUpdateCallbackRepublishMessageRequestCount(Callback::SPtr& callback)
    {
        republishMessageRequestCount_->callback(callback);
    }
    
    BaseNodeClass::SPtr
    SubscriptionDiagnosticsType::republishMessageCount(void)
    {
        return republishMessageCount_->baseNode().lock();
    }
    
    bool
    SubscriptionDiagnosticsType::setRepublishMessageCount(const OpcUaDataValue& dataValue)
    {
        return republishMessageCount_->setDataValue(dataValue);
    }
    
    bool
    SubscriptionDiagnosticsType::getRepublishMessageCount(OpcUaDataValue& dataValue)
    {
        return republishMessageCount_->getDataValue(dataValue);
    }
    
    void
    SubscriptionDiagnosticsType::setUpdateCallbackRepublishMessageCount(Callback::SPtr& callback)
    {
        republishMessageCount_->callback(callback);
    }
    
    BaseNodeClass::SPtr
    SubscriptionDiagnosticsType::transferRequestCount(void)
    {
        return transferRequestCount_->baseNode().lock();
    }
    
    bool
    SubscriptionDiagnosticsType::setTransferRequestCount(const OpcUaDataValue& dataValue)
    {
        return transferRequestCount_->setDataValue(dataValue);
    }
    
    bool
    SubscriptionDiagnosticsType::getTransferRequestCount(OpcUaDataValue& dataValue)
    {
        return transferRequestCount_->getDataValue(dataValue);
    }
    
    void
    SubscriptionDiagnosticsType::setUpdateCallbackTransferRequestCount(Callback::SPtr& callback)
    {
        transferRequestCount_->callback(callback);
    }
    
    BaseNodeClass::SPtr
    SubscriptionDiagnosticsType::transferredToAltClientCount(void)
    {
        return transferredToAltClientCount_->baseNode().lock();
    }
    
    bool
    SubscriptionDiagnosticsType::setTransferredToAltClientCount(const OpcUaDataValue& dataValue)
    {
        return transferredToAltClientCount_->setDataValue(dataValue);
    }
    
    bool
    SubscriptionDiagnosticsType::getTransferredToAltClientCount(OpcUaDataValue& dataValue)
    {
        return transferredToAltClientCount_->getDataValue(dataValue);
    }
    
    void
    SubscriptionDiagnosticsType::setUpdateCallbackTransferredToAltClientCount(Callback::SPtr& callback)
    {
        transferredToAltClientCount_->callback(callback);
    }
    
    BaseNodeClass::SPtr
    SubscriptionDiagnosticsType::transferredToSameClientCount(void)
    {
        return transferredToSameClientCount_->baseNode().lock();
    }
    
    bool
    SubscriptionDiagnosticsType::setTransferredToSameClientCount(const OpcUaDataValue& dataValue)
    {
        return transferredToSameClientCount_->setDataValue(dataValue);
    }
    
    bool
    SubscriptionDiagnosticsType::getTransferredToSameClientCount(OpcUaDataValue& dataValue)
    {
        return transferredToSameClientCount_->getDataValue(dataValue);
    }
    
    void
    SubscriptionDiagnosticsType::setUpdateCallbackTransferredToSameClientCount(Callback::SPtr& callback)
    {
        transferredToSameClientCount_->callback(callback);
    }
    
    BaseNodeClass::SPtr
    SubscriptionDiagnosticsType::publishRequestCount(void)
    {
        return publishRequestCount_->baseNode().lock();
    }
    
    bool
    SubscriptionDiagnosticsType::setPublishRequestCount(const OpcUaDataValue& dataValue)
    {
        return publishRequestCount_->setDataValue(dataValue);
    }
    
    bool
    SubscriptionDiagnosticsType::getPublishRequestCount(OpcUaDataValue& dataValue)
    {
        return publishRequestCount_->getDataValue(dataValue);
    }
    
    void
    SubscriptionDiagnosticsType::setUpdateCallbackPublishRequestCount(Callback::SPtr& callback)
    {
        publishRequestCount_->callback(callback);
    }
    
    BaseNodeClass::SPtr
    SubscriptionDiagnosticsType::dataChangeNotificationsCount(void)
    {
        return dataChangeNotificationsCount_->baseNode().lock();
    }
    
    bool
    SubscriptionDiagnosticsType::setDataChangeNotificationsCount(const OpcUaDataValue& dataValue)
    {
        return dataChangeNotificationsCount_->setDataValue(dataValue);
    }
    
    bool
    SubscriptionDiagnosticsType::getDataChangeNotificationsCount(OpcUaDataValue& dataValue)
    {
        return dataChangeNotificationsCount_->getDataValue(dataValue);
    }
    
    void
    SubscriptionDiagnosticsType::setUpdateCallbackDataChangeNotificationsCount(Callback::SPtr& callback)
    {
        dataChangeNotificationsCount_->callback(callback);
    }
    
    BaseNodeClass::SPtr
    SubscriptionDiagnosticsType::eventNotificationsCount(void)
    {
        return eventNotificationsCount_->baseNode().lock();
    }
    
    bool
    SubscriptionDiagnosticsType::setEventNotificationsCount(const OpcUaDataValue& dataValue)
    {
        return eventNotificationsCount_->setDataValue(dataValue);
    }
    
    bool
    SubscriptionDiagnosticsType::getEventNotificationsCount(OpcUaDataValue& dataValue)
    {
        return eventNotificationsCount_->getDataValue(dataValue);
    }
    
    void
    SubscriptionDiagnosticsType::setUpdateCallbackEventNotificationsCount(Callback::SPtr& callback)
    {
        eventNotificationsCount_->callback(callback);
    }
    
    BaseNodeClass::SPtr
    SubscriptionDiagnosticsType::notificationsCount(void)
    {
        return notificationsCount_->baseNode().lock();
    }
    
    bool
    SubscriptionDiagnosticsType::setNotificationsCount(const OpcUaDataValue& dataValue)
    {
        return notificationsCount_->setDataValue(dataValue);
    }
    
    bool
    SubscriptionDiagnosticsType::getNotificationsCount(OpcUaDataValue& dataValue)
    {
        return notificationsCount_->getDataValue(dataValue);
    }
    
    void
    SubscriptionDiagnosticsType::setUpdateCallbackNotificationsCount(Callback::SPtr& callback)
    {
        notificationsCount_->callback(callback);
    }
    
    BaseNodeClass::SPtr
    SubscriptionDiagnosticsType::latePublishRequestCount(void)
    {
        return latePublishRequestCount_->baseNode().lock();
    }
    
    bool
    SubscriptionDiagnosticsType::setLatePublishRequestCount(const OpcUaDataValue& dataValue)
    {
        return latePublishRequestCount_->setDataValue(dataValue);
    }
    
    bool
    SubscriptionDiagnosticsType::getLatePublishRequestCount(OpcUaDataValue& dataValue)
    {
        return latePublishRequestCount_->getDataValue(dataValue);
    }
    
    void
    SubscriptionDiagnosticsType::setUpdateCallbackLatePublishRequestCount(Callback::SPtr& callback)
    {
        latePublishRequestCount_->callback(callback);
    }
    
    BaseNodeClass::SPtr
    SubscriptionDiagnosticsType::currentKeepAliveCount(void)
    {
        return currentKeepAliveCount_->baseNode().lock();
    }
    
    bool
    SubscriptionDiagnosticsType::setCurrentKeepAliveCount(const OpcUaDataValue& dataValue)
    {
        return currentKeepAliveCount_->setDataValue(dataValue);
    }
    
    bool
    SubscriptionDiagnosticsType::getCurrentKeepAliveCount(OpcUaDataValue& dataValue)
    {
        return currentKeepAliveCount_->getDataValue(dataValue);
    }
    
    void
    SubscriptionDiagnosticsType::setUpdateCallbackCurrentKeepAliveCount(Callback::SPtr& callback)
    {
        currentKeepAliveCount_->callback(callback);
    }
    
    BaseNodeClass::SPtr
    SubscriptionDiagnosticsType::currentLifetimeCount(void)
    {
        return currentLifetimeCount_->baseNode().lock();
    }
    
    bool
    SubscriptionDiagnosticsType::setCurrentLifetimeCount(const OpcUaDataValue& dataValue)
    {
        return currentLifetimeCount_->setDataValue(dataValue);
    }
    
    bool
    SubscriptionDiagnosticsType::getCurrentLifetimeCount(OpcUaDataValue& dataValue)
    {
        return currentLifetimeCount_->getDataValue(dataValue);
    }
    
    void
    SubscriptionDiagnosticsType::setUpdateCallbackCurrentLifetimeCount(Callback::SPtr& callback)
    {
        currentLifetimeCount_->callback(callback);
    }
    
    BaseNodeClass::SPtr
    SubscriptionDiagnosticsType::unacknowledgedMessageCount(void)
    {
        return unacknowledgedMessageCount_->baseNode().lock();
    }
    
    bool
    SubscriptionDiagnosticsType::setUnacknowledgedMessageCount(const OpcUaDataValue& dataValue)
    {
        return unacknowledgedMessageCount_->setDataValue(dataValue);
    }
    
    bool
    SubscriptionDiagnosticsType::getUnacknowledgedMessageCount(OpcUaDataValue& dataValue)
    {
        return unacknowledgedMessageCount_->getDataValue(dataValue);
    }
    
    void
    SubscriptionDiagnosticsType::setUpdateCallbackUnacknowledgedMessageCount(Callback::SPtr& callback)
    {
        unacknowledgedMessageCount_->callback(callback);
    }
    
    BaseNodeClass::SPtr
    SubscriptionDiagnosticsType::discardedMessageCount(void)
    {
        return discardedMessageCount_->baseNode().lock();
    }
    
    bool
    SubscriptionDiagnosticsType::setDiscardedMessageCount(const OpcUaDataValue& dataValue)
    {
        return discardedMessageCount_->setDataValue(dataValue);
    }
    
    bool
    SubscriptionDiagnosticsType::getDiscardedMessageCount(OpcUaDataValue& dataValue)
    {
        return discardedMessageCount_->getDataValue(dataValue);
    }
    
    void
    SubscriptionDiagnosticsType::setUpdateCallbackDiscardedMessageCount(Callback::SPtr& callback)
    {
        discardedMessageCount_->callback(callback);
    }
    
    BaseNodeClass::SPtr
    SubscriptionDiagnosticsType::monitoredItemCount(void)
    {
        return monitoredItemCount_->baseNode().lock();
    }
    
    bool
    SubscriptionDiagnosticsType::setMonitoredItemCount(const OpcUaDataValue& dataValue)
    {
        return monitoredItemCount_->setDataValue(dataValue);
    }
    
    bool
    SubscriptionDiagnosticsType::getMonitoredItemCount(OpcUaDataValue& dataValue)
    {
        return monitoredItemCount_->getDataValue(dataValue);
    }
    
    void
    SubscriptionDiagnosticsType::setUpdateCallbackMonitoredItemCount(Callback::SPtr& callback)
    {
        monitoredItemCount_->callback(callback);
    }
    
    BaseNodeClass::SPtr
    SubscriptionDiagnosticsType::disabledMonitoredItemCount(void)
    {
        return disabledMonitoredItemCount_->baseNode().lock();
    }
    
    bool
    SubscriptionDiagnosticsType::setDisabledMonitoredItemCount(const OpcUaDataValue& dataValue)
    {
        return disabledMonitoredItemCount_->setDataValue(dataValue);
    }
    
    bool
    SubscriptionDiagnosticsType::getDisabledMonitoredItemCount(OpcUaDataValue& dataValue)
    {
        return disabledMonitoredItemCount_->getDataValue(dataValue);
    }
    
    void
    SubscriptionDiagnosticsType::setUpdateCallbackDisabledMonitoredItemCount(Callback::SPtr& callback)
    {
        disabledMonitoredItemCount_->callback(callback);
    }
    
    BaseNodeClass::SPtr
    SubscriptionDiagnosticsType::monitoringQueueOverflowCount(void)
    {
        return monitoringQueueOverflowCount_->baseNode().lock();
    }
    
    bool
    SubscriptionDiagnosticsType::setMonitoringQueueOverflowCount(const OpcUaDataValue& dataValue)
    {
        return monitoringQueueOverflowCount_->setDataValue(dataValue);
    }
    
    bool
    SubscriptionDiagnosticsType::getMonitoringQueueOverflowCount(OpcUaDataValue& dataValue)
    {
        return monitoringQueueOverflowCount_->getDataValue(dataValue);
    }
    
    void
    SubscriptionDiagnosticsType::setUpdateCallbackMonitoringQueueOverflowCount(Callback::SPtr& callback)
    {
        monitoringQueueOverflowCount_->callback(callback);
    }
    
    BaseNodeClass::SPtr
    SubscriptionDiagnosticsType::nextSequenceNumber(void)
    {
        return nextSequenceNumber_->baseNode().lock();
    }
    
    bool
    SubscriptionDiagnosticsType::setNextSequenceNumber(const OpcUaDataValue& dataValue)
    {
        return nextSequenceNumber_->setDataValue(dataValue);
    }
    
    bool
    SubscriptionDiagnosticsType::getNextSequenceNumber(OpcUaDataValue& dataValue)
    {
        return nextSequenceNumber_->getDataValue(dataValue);
    }
    
    void
    SubscriptionDiagnosticsType::setUpdateCallbackNextSequenceNumber(Callback::SPtr& callback)
    {
        nextSequenceNumber_->callback(callback);
    }
    
    BaseNodeClass::SPtr
    SubscriptionDiagnosticsType::eventQueueOverFlowCount(void)
    {
        return eventQueueOverFlowCount_->baseNode().lock();
    }
    
    bool
    SubscriptionDiagnosticsType::setEventQueueOverFlowCount(const OpcUaDataValue& dataValue)
    {
        return eventQueueOverFlowCount_->setDataValue(dataValue);
    }
    
    bool
    SubscriptionDiagnosticsType::getEventQueueOverFlowCount(OpcUaDataValue& dataValue)
    {
        return eventQueueOverFlowCount_->getDataValue(dataValue);
    }
    
    void
    SubscriptionDiagnosticsType::setUpdateCallbackEventQueueOverFlowCount(Callback::SPtr& callback)
    {
        eventQueueOverFlowCount_->callback(callback);
    }

}
