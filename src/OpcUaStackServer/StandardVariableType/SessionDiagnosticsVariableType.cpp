/*
    VariableTypeClass: SessionDiagnosticsVariableType

    Generated Source Code - please do not change this source code

    VariableTypeCodeGenerator Version:
        OpcUaStackCore - 3.0.1

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackServer/StandardVariableType/SessionDiagnosticsVariableType.h"

namespace OpcUaStackServer
{
    
    SessionDiagnosticsVariableType::SessionDiagnosticsVariableType(void)
    : BaseDataVariableType()
    , namespaceName_("http://opcfoundation.org/UA/")
    , namespaceIndex_(0)
    , sessionId_(constructSPtr<ServerVariable>("SessionId"))
    , sessionName_(constructSPtr<ServerVariable>("SessionName"))
    , clientDescription_(constructSPtr<ServerVariable>("ClientDescription"))
    , serverUri_(constructSPtr<ServerVariable>("ServerUri"))
    , endpointUrl_(constructSPtr<ServerVariable>("EndpointUrl"))
    , localeIds_(constructSPtr<ServerVariable>("LocaleIds"))
    , actualSessionTimeout_(constructSPtr<ServerVariable>("ActualSessionTimeout"))
    , maxResponseMessageSize_(constructSPtr<ServerVariable>("MaxResponseMessageSize"))
    , clientConnectionTime_(constructSPtr<ServerVariable>("ClientConnectionTime"))
    , clientLastContactTime_(constructSPtr<ServerVariable>("ClientLastContactTime"))
    , currentSubscriptionsCount_(constructSPtr<ServerVariable>("CurrentSubscriptionsCount"))
    , currentMonitoredItemsCount_(constructSPtr<ServerVariable>("CurrentMonitoredItemsCount"))
    , currentPublishRequestsInQueue_(constructSPtr<ServerVariable>("CurrentPublishRequestsInQueue"))
    , totalRequestCount_(constructSPtr<ServerVariable>("TotalRequestCount"))
    , unauthorizedRequestCount_(constructSPtr<ServerVariable>("UnauthorizedRequestCount"))
    , readCount_(constructSPtr<ServerVariable>("ReadCount"))
    , historyReadCount_(constructSPtr<ServerVariable>("HistoryReadCount"))
    , writeCount_(constructSPtr<ServerVariable>("WriteCount"))
    , historyUpdateCount_(constructSPtr<ServerVariable>("HistoryUpdateCount"))
    , callCount_(constructSPtr<ServerVariable>("CallCount"))
    , createMonitoredItemsCount_(constructSPtr<ServerVariable>("CreateMonitoredItemsCount"))
    , modifyMonitoredItemsCount_(constructSPtr<ServerVariable>("ModifyMonitoredItemsCount"))
    , setMonitoringModeCount_(constructSPtr<ServerVariable>("SetMonitoringModeCount"))
    , setTriggeringCount_(constructSPtr<ServerVariable>("SetTriggeringCount"))
    , deleteMonitoredItemsCount_(constructSPtr<ServerVariable>("DeleteMonitoredItemsCount"))
    , createSubscriptionCount_(constructSPtr<ServerVariable>("CreateSubscriptionCount"))
    , modifySubscriptionCount_(constructSPtr<ServerVariable>("ModifySubscriptionCount"))
    , setPublishingModeCount_(constructSPtr<ServerVariable>("SetPublishingModeCount"))
    , publishCount_(constructSPtr<ServerVariable>("PublishCount"))
    , republishCount_(constructSPtr<ServerVariable>("RepublishCount"))
    , transferSubscriptionsCount_(constructSPtr<ServerVariable>("TransferSubscriptionsCount"))
    , deleteSubscriptionsCount_(constructSPtr<ServerVariable>("DeleteSubscriptionsCount"))
    , addNodesCount_(constructSPtr<ServerVariable>("AddNodesCount"))
    , addReferencesCount_(constructSPtr<ServerVariable>("AddReferencesCount"))
    , deleteNodesCount_(constructSPtr<ServerVariable>("DeleteNodesCount"))
    , deleteReferencesCount_(constructSPtr<ServerVariable>("DeleteReferencesCount"))
    , browseCount_(constructSPtr<ServerVariable>("BrowseCount"))
    , browseNextCount_(constructSPtr<ServerVariable>("BrowseNextCount"))
    , translateBrowsePathsToNodeIdsCount_(constructSPtr<ServerVariable>("TranslateBrowsePathsToNodeIdsCount"))
    , queryFirstCount_(constructSPtr<ServerVariable>("QueryFirstCount"))
    , queryNextCount_(constructSPtr<ServerVariable>("QueryNextCount"))
    , registerNodesCount_(constructSPtr<ServerVariable>("RegisterNodesCount"))
    , unregisterNodesCount_(constructSPtr<ServerVariable>("UnregisterNodesCount"))
    {
        variableTypeNamespace(namespaceName_);
        variableType(OpcUaNodeId(2197));
        serverVariables().registerServerVariable(sessionId_);
        serverVariables().registerServerVariable(sessionName_);
        serverVariables().registerServerVariable(clientDescription_);
        serverVariables().registerServerVariable(serverUri_);
        serverVariables().registerServerVariable(endpointUrl_);
        serverVariables().registerServerVariable(localeIds_);
        serverVariables().registerServerVariable(actualSessionTimeout_);
        serverVariables().registerServerVariable(maxResponseMessageSize_);
        serverVariables().registerServerVariable(clientConnectionTime_);
        serverVariables().registerServerVariable(clientLastContactTime_);
        serverVariables().registerServerVariable(currentSubscriptionsCount_);
        serverVariables().registerServerVariable(currentMonitoredItemsCount_);
        serverVariables().registerServerVariable(currentPublishRequestsInQueue_);
        serverVariables().registerServerVariable(totalRequestCount_);
        serverVariables().registerServerVariable(unauthorizedRequestCount_);
        serverVariables().registerServerVariable(readCount_);
        serverVariables().registerServerVariable(historyReadCount_);
        serverVariables().registerServerVariable(writeCount_);
        serverVariables().registerServerVariable(historyUpdateCount_);
        serverVariables().registerServerVariable(callCount_);
        serverVariables().registerServerVariable(createMonitoredItemsCount_);
        serverVariables().registerServerVariable(modifyMonitoredItemsCount_);
        serverVariables().registerServerVariable(setMonitoringModeCount_);
        serverVariables().registerServerVariable(setTriggeringCount_);
        serverVariables().registerServerVariable(deleteMonitoredItemsCount_);
        serverVariables().registerServerVariable(createSubscriptionCount_);
        serverVariables().registerServerVariable(modifySubscriptionCount_);
        serverVariables().registerServerVariable(setPublishingModeCount_);
        serverVariables().registerServerVariable(publishCount_);
        serverVariables().registerServerVariable(republishCount_);
        serverVariables().registerServerVariable(transferSubscriptionsCount_);
        serverVariables().registerServerVariable(deleteSubscriptionsCount_);
        serverVariables().registerServerVariable(addNodesCount_);
        serverVariables().registerServerVariable(addReferencesCount_);
        serverVariables().registerServerVariable(deleteNodesCount_);
        serverVariables().registerServerVariable(deleteReferencesCount_);
        serverVariables().registerServerVariable(browseCount_);
        serverVariables().registerServerVariable(browseNextCount_);
        serverVariables().registerServerVariable(translateBrowsePathsToNodeIdsCount_);
        serverVariables().registerServerVariable(queryFirstCount_);
        serverVariables().registerServerVariable(queryNextCount_);
        serverVariables().registerServerVariable(registerNodesCount_);
        serverVariables().registerServerVariable(unregisterNodesCount_);
    }
    
    SessionDiagnosticsVariableType::~SessionDiagnosticsVariableType(void)
    {
    }
    
    bool
    SessionDiagnosticsVariableType::linkInstanceWithModel(const OpcUaNodeId& nodeId)
    {
        if (!getNamespaceIndexFromNamespaceName(namespaceName_, namespaceIndex_)) return false;
        sessionId_->addBrowsePath(nodeId, OpcUaQualifiedName("SessionId", namespaceIndex_));
        sessionName_->addBrowsePath(nodeId, OpcUaQualifiedName("SessionName", namespaceIndex_));
        clientDescription_->addBrowsePath(nodeId, OpcUaQualifiedName("ClientDescription", namespaceIndex_));
        serverUri_->addBrowsePath(nodeId, OpcUaQualifiedName("ServerUri", namespaceIndex_));
        endpointUrl_->addBrowsePath(nodeId, OpcUaQualifiedName("EndpointUrl", namespaceIndex_));
        localeIds_->addBrowsePath(nodeId, OpcUaQualifiedName("LocaleIds", namespaceIndex_));
        actualSessionTimeout_->addBrowsePath(nodeId, OpcUaQualifiedName("ActualSessionTimeout", namespaceIndex_));
        maxResponseMessageSize_->addBrowsePath(nodeId, OpcUaQualifiedName("MaxResponseMessageSize", namespaceIndex_));
        clientConnectionTime_->addBrowsePath(nodeId, OpcUaQualifiedName("ClientConnectionTime", namespaceIndex_));
        clientLastContactTime_->addBrowsePath(nodeId, OpcUaQualifiedName("ClientLastContactTime", namespaceIndex_));
        currentSubscriptionsCount_->addBrowsePath(nodeId, OpcUaQualifiedName("CurrentSubscriptionsCount", namespaceIndex_));
        currentMonitoredItemsCount_->addBrowsePath(nodeId, OpcUaQualifiedName("CurrentMonitoredItemsCount", namespaceIndex_));
        currentPublishRequestsInQueue_->addBrowsePath(nodeId, OpcUaQualifiedName("CurrentPublishRequestsInQueue", namespaceIndex_));
        totalRequestCount_->addBrowsePath(nodeId, OpcUaQualifiedName("TotalRequestCount", namespaceIndex_));
        unauthorizedRequestCount_->addBrowsePath(nodeId, OpcUaQualifiedName("UnauthorizedRequestCount", namespaceIndex_));
        readCount_->addBrowsePath(nodeId, OpcUaQualifiedName("ReadCount", namespaceIndex_));
        historyReadCount_->addBrowsePath(nodeId, OpcUaQualifiedName("HistoryReadCount", namespaceIndex_));
        writeCount_->addBrowsePath(nodeId, OpcUaQualifiedName("WriteCount", namespaceIndex_));
        historyUpdateCount_->addBrowsePath(nodeId, OpcUaQualifiedName("HistoryUpdateCount", namespaceIndex_));
        callCount_->addBrowsePath(nodeId, OpcUaQualifiedName("CallCount", namespaceIndex_));
        createMonitoredItemsCount_->addBrowsePath(nodeId, OpcUaQualifiedName("CreateMonitoredItemsCount", namespaceIndex_));
        modifyMonitoredItemsCount_->addBrowsePath(nodeId, OpcUaQualifiedName("ModifyMonitoredItemsCount", namespaceIndex_));
        setMonitoringModeCount_->addBrowsePath(nodeId, OpcUaQualifiedName("SetMonitoringModeCount", namespaceIndex_));
        setTriggeringCount_->addBrowsePath(nodeId, OpcUaQualifiedName("SetTriggeringCount", namespaceIndex_));
        deleteMonitoredItemsCount_->addBrowsePath(nodeId, OpcUaQualifiedName("DeleteMonitoredItemsCount", namespaceIndex_));
        createSubscriptionCount_->addBrowsePath(nodeId, OpcUaQualifiedName("CreateSubscriptionCount", namespaceIndex_));
        modifySubscriptionCount_->addBrowsePath(nodeId, OpcUaQualifiedName("ModifySubscriptionCount", namespaceIndex_));
        setPublishingModeCount_->addBrowsePath(nodeId, OpcUaQualifiedName("SetPublishingModeCount", namespaceIndex_));
        publishCount_->addBrowsePath(nodeId, OpcUaQualifiedName("PublishCount", namespaceIndex_));
        republishCount_->addBrowsePath(nodeId, OpcUaQualifiedName("RepublishCount", namespaceIndex_));
        transferSubscriptionsCount_->addBrowsePath(nodeId, OpcUaQualifiedName("TransferSubscriptionsCount", namespaceIndex_));
        deleteSubscriptionsCount_->addBrowsePath(nodeId, OpcUaQualifiedName("DeleteSubscriptionsCount", namespaceIndex_));
        addNodesCount_->addBrowsePath(nodeId, OpcUaQualifiedName("AddNodesCount", namespaceIndex_));
        addReferencesCount_->addBrowsePath(nodeId, OpcUaQualifiedName("AddReferencesCount", namespaceIndex_));
        deleteNodesCount_->addBrowsePath(nodeId, OpcUaQualifiedName("DeleteNodesCount", namespaceIndex_));
        deleteReferencesCount_->addBrowsePath(nodeId, OpcUaQualifiedName("DeleteReferencesCount", namespaceIndex_));
        browseCount_->addBrowsePath(nodeId, OpcUaQualifiedName("BrowseCount", namespaceIndex_));
        browseNextCount_->addBrowsePath(nodeId, OpcUaQualifiedName("BrowseNextCount", namespaceIndex_));
        translateBrowsePathsToNodeIdsCount_->addBrowsePath(nodeId, OpcUaQualifiedName("TranslateBrowsePathsToNodeIdsCount", namespaceIndex_));
        queryFirstCount_->addBrowsePath(nodeId, OpcUaQualifiedName("QueryFirstCount", namespaceIndex_));
        queryNextCount_->addBrowsePath(nodeId, OpcUaQualifiedName("QueryNextCount", namespaceIndex_));
        registerNodesCount_->addBrowsePath(nodeId, OpcUaQualifiedName("RegisterNodesCount", namespaceIndex_));
        unregisterNodesCount_->addBrowsePath(nodeId, OpcUaQualifiedName("UnregisterNodesCount", namespaceIndex_));
        BaseDataVariableType::linkInstanceWithModel(nodeId);
    }
    
    BaseNodeClass::SPtr
    SessionDiagnosticsVariableType::sessionId(void)
    {
        return sessionId_->baseNode().lock();
    }
    
    bool
    SessionDiagnosticsVariableType::setSessionId(const OpcUaDataValue& dataValue)
    {
        return sessionId_->setDataValue(dataValue);
    }
    
    bool
    SessionDiagnosticsVariableType::getSessionId(OpcUaDataValue& dataValue)
    {
        return sessionId_->getDataValue(dataValue);
    }
    
    void
    SessionDiagnosticsVariableType::setUpdateCallbackSessionId(Callback::SPtr& callback)
    {
        sessionId_->callback(callback);
    }
    
    BaseNodeClass::SPtr
    SessionDiagnosticsVariableType::sessionName(void)
    {
        return sessionName_->baseNode().lock();
    }
    
    bool
    SessionDiagnosticsVariableType::setSessionName(const OpcUaDataValue& dataValue)
    {
        return sessionName_->setDataValue(dataValue);
    }
    
    bool
    SessionDiagnosticsVariableType::getSessionName(OpcUaDataValue& dataValue)
    {
        return sessionName_->getDataValue(dataValue);
    }
    
    void
    SessionDiagnosticsVariableType::setUpdateCallbackSessionName(Callback::SPtr& callback)
    {
        sessionName_->callback(callback);
    }
    
    BaseNodeClass::SPtr
    SessionDiagnosticsVariableType::clientDescription(void)
    {
        return clientDescription_->baseNode().lock();
    }
    
    bool
    SessionDiagnosticsVariableType::setClientDescription(const OpcUaDataValue& dataValue)
    {
        return clientDescription_->setDataValue(dataValue);
    }
    
    bool
    SessionDiagnosticsVariableType::getClientDescription(OpcUaDataValue& dataValue)
    {
        return clientDescription_->getDataValue(dataValue);
    }
    
    void
    SessionDiagnosticsVariableType::setUpdateCallbackClientDescription(Callback::SPtr& callback)
    {
        clientDescription_->callback(callback);
    }
    
    BaseNodeClass::SPtr
    SessionDiagnosticsVariableType::serverUri(void)
    {
        return serverUri_->baseNode().lock();
    }
    
    bool
    SessionDiagnosticsVariableType::setServerUri(const OpcUaDataValue& dataValue)
    {
        return serverUri_->setDataValue(dataValue);
    }
    
    bool
    SessionDiagnosticsVariableType::getServerUri(OpcUaDataValue& dataValue)
    {
        return serverUri_->getDataValue(dataValue);
    }
    
    void
    SessionDiagnosticsVariableType::setUpdateCallbackServerUri(Callback::SPtr& callback)
    {
        serverUri_->callback(callback);
    }
    
    BaseNodeClass::SPtr
    SessionDiagnosticsVariableType::endpointUrl(void)
    {
        return endpointUrl_->baseNode().lock();
    }
    
    bool
    SessionDiagnosticsVariableType::setEndpointUrl(const OpcUaDataValue& dataValue)
    {
        return endpointUrl_->setDataValue(dataValue);
    }
    
    bool
    SessionDiagnosticsVariableType::getEndpointUrl(OpcUaDataValue& dataValue)
    {
        return endpointUrl_->getDataValue(dataValue);
    }
    
    void
    SessionDiagnosticsVariableType::setUpdateCallbackEndpointUrl(Callback::SPtr& callback)
    {
        endpointUrl_->callback(callback);
    }
    
    BaseNodeClass::SPtr
    SessionDiagnosticsVariableType::localeIds(void)
    {
        return localeIds_->baseNode().lock();
    }
    
    bool
    SessionDiagnosticsVariableType::setLocaleIds(const OpcUaDataValue& dataValue)
    {
        return localeIds_->setDataValue(dataValue);
    }
    
    bool
    SessionDiagnosticsVariableType::getLocaleIds(OpcUaDataValue& dataValue)
    {
        return localeIds_->getDataValue(dataValue);
    }
    
    void
    SessionDiagnosticsVariableType::setUpdateCallbackLocaleIds(Callback::SPtr& callback)
    {
        localeIds_->callback(callback);
    }
    
    BaseNodeClass::SPtr
    SessionDiagnosticsVariableType::actualSessionTimeout(void)
    {
        return actualSessionTimeout_->baseNode().lock();
    }
    
    bool
    SessionDiagnosticsVariableType::setActualSessionTimeout(const OpcUaDataValue& dataValue)
    {
        return actualSessionTimeout_->setDataValue(dataValue);
    }
    
    bool
    SessionDiagnosticsVariableType::getActualSessionTimeout(OpcUaDataValue& dataValue)
    {
        return actualSessionTimeout_->getDataValue(dataValue);
    }
    
    void
    SessionDiagnosticsVariableType::setUpdateCallbackActualSessionTimeout(Callback::SPtr& callback)
    {
        actualSessionTimeout_->callback(callback);
    }
    
    BaseNodeClass::SPtr
    SessionDiagnosticsVariableType::maxResponseMessageSize(void)
    {
        return maxResponseMessageSize_->baseNode().lock();
    }
    
    bool
    SessionDiagnosticsVariableType::setMaxResponseMessageSize(const OpcUaDataValue& dataValue)
    {
        return maxResponseMessageSize_->setDataValue(dataValue);
    }
    
    bool
    SessionDiagnosticsVariableType::getMaxResponseMessageSize(OpcUaDataValue& dataValue)
    {
        return maxResponseMessageSize_->getDataValue(dataValue);
    }
    
    void
    SessionDiagnosticsVariableType::setUpdateCallbackMaxResponseMessageSize(Callback::SPtr& callback)
    {
        maxResponseMessageSize_->callback(callback);
    }
    
    BaseNodeClass::SPtr
    SessionDiagnosticsVariableType::clientConnectionTime(void)
    {
        return clientConnectionTime_->baseNode().lock();
    }
    
    bool
    SessionDiagnosticsVariableType::setClientConnectionTime(const OpcUaDataValue& dataValue)
    {
        return clientConnectionTime_->setDataValue(dataValue);
    }
    
    bool
    SessionDiagnosticsVariableType::getClientConnectionTime(OpcUaDataValue& dataValue)
    {
        return clientConnectionTime_->getDataValue(dataValue);
    }
    
    void
    SessionDiagnosticsVariableType::setUpdateCallbackClientConnectionTime(Callback::SPtr& callback)
    {
        clientConnectionTime_->callback(callback);
    }
    
    BaseNodeClass::SPtr
    SessionDiagnosticsVariableType::clientLastContactTime(void)
    {
        return clientLastContactTime_->baseNode().lock();
    }
    
    bool
    SessionDiagnosticsVariableType::setClientLastContactTime(const OpcUaDataValue& dataValue)
    {
        return clientLastContactTime_->setDataValue(dataValue);
    }
    
    bool
    SessionDiagnosticsVariableType::getClientLastContactTime(OpcUaDataValue& dataValue)
    {
        return clientLastContactTime_->getDataValue(dataValue);
    }
    
    void
    SessionDiagnosticsVariableType::setUpdateCallbackClientLastContactTime(Callback::SPtr& callback)
    {
        clientLastContactTime_->callback(callback);
    }
    
    BaseNodeClass::SPtr
    SessionDiagnosticsVariableType::currentSubscriptionsCount(void)
    {
        return currentSubscriptionsCount_->baseNode().lock();
    }
    
    bool
    SessionDiagnosticsVariableType::setCurrentSubscriptionsCount(const OpcUaDataValue& dataValue)
    {
        return currentSubscriptionsCount_->setDataValue(dataValue);
    }
    
    bool
    SessionDiagnosticsVariableType::getCurrentSubscriptionsCount(OpcUaDataValue& dataValue)
    {
        return currentSubscriptionsCount_->getDataValue(dataValue);
    }
    
    void
    SessionDiagnosticsVariableType::setUpdateCallbackCurrentSubscriptionsCount(Callback::SPtr& callback)
    {
        currentSubscriptionsCount_->callback(callback);
    }
    
    BaseNodeClass::SPtr
    SessionDiagnosticsVariableType::currentMonitoredItemsCount(void)
    {
        return currentMonitoredItemsCount_->baseNode().lock();
    }
    
    bool
    SessionDiagnosticsVariableType::setCurrentMonitoredItemsCount(const OpcUaDataValue& dataValue)
    {
        return currentMonitoredItemsCount_->setDataValue(dataValue);
    }
    
    bool
    SessionDiagnosticsVariableType::getCurrentMonitoredItemsCount(OpcUaDataValue& dataValue)
    {
        return currentMonitoredItemsCount_->getDataValue(dataValue);
    }
    
    void
    SessionDiagnosticsVariableType::setUpdateCallbackCurrentMonitoredItemsCount(Callback::SPtr& callback)
    {
        currentMonitoredItemsCount_->callback(callback);
    }
    
    BaseNodeClass::SPtr
    SessionDiagnosticsVariableType::currentPublishRequestsInQueue(void)
    {
        return currentPublishRequestsInQueue_->baseNode().lock();
    }
    
    bool
    SessionDiagnosticsVariableType::setCurrentPublishRequestsInQueue(const OpcUaDataValue& dataValue)
    {
        return currentPublishRequestsInQueue_->setDataValue(dataValue);
    }
    
    bool
    SessionDiagnosticsVariableType::getCurrentPublishRequestsInQueue(OpcUaDataValue& dataValue)
    {
        return currentPublishRequestsInQueue_->getDataValue(dataValue);
    }
    
    void
    SessionDiagnosticsVariableType::setUpdateCallbackCurrentPublishRequestsInQueue(Callback::SPtr& callback)
    {
        currentPublishRequestsInQueue_->callback(callback);
    }
    
    BaseNodeClass::SPtr
    SessionDiagnosticsVariableType::totalRequestCount(void)
    {
        return totalRequestCount_->baseNode().lock();
    }
    
    bool
    SessionDiagnosticsVariableType::setTotalRequestCount(const OpcUaDataValue& dataValue)
    {
        return totalRequestCount_->setDataValue(dataValue);
    }
    
    bool
    SessionDiagnosticsVariableType::getTotalRequestCount(OpcUaDataValue& dataValue)
    {
        return totalRequestCount_->getDataValue(dataValue);
    }
    
    void
    SessionDiagnosticsVariableType::setUpdateCallbackTotalRequestCount(Callback::SPtr& callback)
    {
        totalRequestCount_->callback(callback);
    }
    
    BaseNodeClass::SPtr
    SessionDiagnosticsVariableType::unauthorizedRequestCount(void)
    {
        return unauthorizedRequestCount_->baseNode().lock();
    }
    
    bool
    SessionDiagnosticsVariableType::setUnauthorizedRequestCount(const OpcUaDataValue& dataValue)
    {
        return unauthorizedRequestCount_->setDataValue(dataValue);
    }
    
    bool
    SessionDiagnosticsVariableType::getUnauthorizedRequestCount(OpcUaDataValue& dataValue)
    {
        return unauthorizedRequestCount_->getDataValue(dataValue);
    }
    
    void
    SessionDiagnosticsVariableType::setUpdateCallbackUnauthorizedRequestCount(Callback::SPtr& callback)
    {
        unauthorizedRequestCount_->callback(callback);
    }
    
    BaseNodeClass::SPtr
    SessionDiagnosticsVariableType::readCount(void)
    {
        return readCount_->baseNode().lock();
    }
    
    bool
    SessionDiagnosticsVariableType::setReadCount(const OpcUaDataValue& dataValue)
    {
        return readCount_->setDataValue(dataValue);
    }
    
    bool
    SessionDiagnosticsVariableType::getReadCount(OpcUaDataValue& dataValue)
    {
        return readCount_->getDataValue(dataValue);
    }
    
    void
    SessionDiagnosticsVariableType::setUpdateCallbackReadCount(Callback::SPtr& callback)
    {
        readCount_->callback(callback);
    }
    
    BaseNodeClass::SPtr
    SessionDiagnosticsVariableType::historyReadCount(void)
    {
        return historyReadCount_->baseNode().lock();
    }
    
    bool
    SessionDiagnosticsVariableType::setHistoryReadCount(const OpcUaDataValue& dataValue)
    {
        return historyReadCount_->setDataValue(dataValue);
    }
    
    bool
    SessionDiagnosticsVariableType::getHistoryReadCount(OpcUaDataValue& dataValue)
    {
        return historyReadCount_->getDataValue(dataValue);
    }
    
    void
    SessionDiagnosticsVariableType::setUpdateCallbackHistoryReadCount(Callback::SPtr& callback)
    {
        historyReadCount_->callback(callback);
    }
    
    BaseNodeClass::SPtr
    SessionDiagnosticsVariableType::writeCount(void)
    {
        return writeCount_->baseNode().lock();
    }
    
    bool
    SessionDiagnosticsVariableType::setWriteCount(const OpcUaDataValue& dataValue)
    {
        return writeCount_->setDataValue(dataValue);
    }
    
    bool
    SessionDiagnosticsVariableType::getWriteCount(OpcUaDataValue& dataValue)
    {
        return writeCount_->getDataValue(dataValue);
    }
    
    void
    SessionDiagnosticsVariableType::setUpdateCallbackWriteCount(Callback::SPtr& callback)
    {
        writeCount_->callback(callback);
    }
    
    BaseNodeClass::SPtr
    SessionDiagnosticsVariableType::historyUpdateCount(void)
    {
        return historyUpdateCount_->baseNode().lock();
    }
    
    bool
    SessionDiagnosticsVariableType::setHistoryUpdateCount(const OpcUaDataValue& dataValue)
    {
        return historyUpdateCount_->setDataValue(dataValue);
    }
    
    bool
    SessionDiagnosticsVariableType::getHistoryUpdateCount(OpcUaDataValue& dataValue)
    {
        return historyUpdateCount_->getDataValue(dataValue);
    }
    
    void
    SessionDiagnosticsVariableType::setUpdateCallbackHistoryUpdateCount(Callback::SPtr& callback)
    {
        historyUpdateCount_->callback(callback);
    }
    
    BaseNodeClass::SPtr
    SessionDiagnosticsVariableType::callCount(void)
    {
        return callCount_->baseNode().lock();
    }
    
    bool
    SessionDiagnosticsVariableType::setCallCount(const OpcUaDataValue& dataValue)
    {
        return callCount_->setDataValue(dataValue);
    }
    
    bool
    SessionDiagnosticsVariableType::getCallCount(OpcUaDataValue& dataValue)
    {
        return callCount_->getDataValue(dataValue);
    }
    
    void
    SessionDiagnosticsVariableType::setUpdateCallbackCallCount(Callback::SPtr& callback)
    {
        callCount_->callback(callback);
    }
    
    BaseNodeClass::SPtr
    SessionDiagnosticsVariableType::createMonitoredItemsCount(void)
    {
        return createMonitoredItemsCount_->baseNode().lock();
    }
    
    bool
    SessionDiagnosticsVariableType::setCreateMonitoredItemsCount(const OpcUaDataValue& dataValue)
    {
        return createMonitoredItemsCount_->setDataValue(dataValue);
    }
    
    bool
    SessionDiagnosticsVariableType::getCreateMonitoredItemsCount(OpcUaDataValue& dataValue)
    {
        return createMonitoredItemsCount_->getDataValue(dataValue);
    }
    
    void
    SessionDiagnosticsVariableType::setUpdateCallbackCreateMonitoredItemsCount(Callback::SPtr& callback)
    {
        createMonitoredItemsCount_->callback(callback);
    }
    
    BaseNodeClass::SPtr
    SessionDiagnosticsVariableType::modifyMonitoredItemsCount(void)
    {
        return modifyMonitoredItemsCount_->baseNode().lock();
    }
    
    bool
    SessionDiagnosticsVariableType::setModifyMonitoredItemsCount(const OpcUaDataValue& dataValue)
    {
        return modifyMonitoredItemsCount_->setDataValue(dataValue);
    }
    
    bool
    SessionDiagnosticsVariableType::getModifyMonitoredItemsCount(OpcUaDataValue& dataValue)
    {
        return modifyMonitoredItemsCount_->getDataValue(dataValue);
    }
    
    void
    SessionDiagnosticsVariableType::setUpdateCallbackModifyMonitoredItemsCount(Callback::SPtr& callback)
    {
        modifyMonitoredItemsCount_->callback(callback);
    }
    
    BaseNodeClass::SPtr
    SessionDiagnosticsVariableType::setMonitoringModeCount(void)
    {
        return setMonitoringModeCount_->baseNode().lock();
    }
    
    bool
    SessionDiagnosticsVariableType::setSetMonitoringModeCount(const OpcUaDataValue& dataValue)
    {
        return setMonitoringModeCount_->setDataValue(dataValue);
    }
    
    bool
    SessionDiagnosticsVariableType::getSetMonitoringModeCount(OpcUaDataValue& dataValue)
    {
        return setMonitoringModeCount_->getDataValue(dataValue);
    }
    
    void
    SessionDiagnosticsVariableType::setUpdateCallbackSetMonitoringModeCount(Callback::SPtr& callback)
    {
        setMonitoringModeCount_->callback(callback);
    }
    
    BaseNodeClass::SPtr
    SessionDiagnosticsVariableType::setTriggeringCount(void)
    {
        return setTriggeringCount_->baseNode().lock();
    }
    
    bool
    SessionDiagnosticsVariableType::setSetTriggeringCount(const OpcUaDataValue& dataValue)
    {
        return setTriggeringCount_->setDataValue(dataValue);
    }
    
    bool
    SessionDiagnosticsVariableType::getSetTriggeringCount(OpcUaDataValue& dataValue)
    {
        return setTriggeringCount_->getDataValue(dataValue);
    }
    
    void
    SessionDiagnosticsVariableType::setUpdateCallbackSetTriggeringCount(Callback::SPtr& callback)
    {
        setTriggeringCount_->callback(callback);
    }
    
    BaseNodeClass::SPtr
    SessionDiagnosticsVariableType::deleteMonitoredItemsCount(void)
    {
        return deleteMonitoredItemsCount_->baseNode().lock();
    }
    
    bool
    SessionDiagnosticsVariableType::setDeleteMonitoredItemsCount(const OpcUaDataValue& dataValue)
    {
        return deleteMonitoredItemsCount_->setDataValue(dataValue);
    }
    
    bool
    SessionDiagnosticsVariableType::getDeleteMonitoredItemsCount(OpcUaDataValue& dataValue)
    {
        return deleteMonitoredItemsCount_->getDataValue(dataValue);
    }
    
    void
    SessionDiagnosticsVariableType::setUpdateCallbackDeleteMonitoredItemsCount(Callback::SPtr& callback)
    {
        deleteMonitoredItemsCount_->callback(callback);
    }
    
    BaseNodeClass::SPtr
    SessionDiagnosticsVariableType::createSubscriptionCount(void)
    {
        return createSubscriptionCount_->baseNode().lock();
    }
    
    bool
    SessionDiagnosticsVariableType::setCreateSubscriptionCount(const OpcUaDataValue& dataValue)
    {
        return createSubscriptionCount_->setDataValue(dataValue);
    }
    
    bool
    SessionDiagnosticsVariableType::getCreateSubscriptionCount(OpcUaDataValue& dataValue)
    {
        return createSubscriptionCount_->getDataValue(dataValue);
    }
    
    void
    SessionDiagnosticsVariableType::setUpdateCallbackCreateSubscriptionCount(Callback::SPtr& callback)
    {
        createSubscriptionCount_->callback(callback);
    }
    
    BaseNodeClass::SPtr
    SessionDiagnosticsVariableType::modifySubscriptionCount(void)
    {
        return modifySubscriptionCount_->baseNode().lock();
    }
    
    bool
    SessionDiagnosticsVariableType::setModifySubscriptionCount(const OpcUaDataValue& dataValue)
    {
        return modifySubscriptionCount_->setDataValue(dataValue);
    }
    
    bool
    SessionDiagnosticsVariableType::getModifySubscriptionCount(OpcUaDataValue& dataValue)
    {
        return modifySubscriptionCount_->getDataValue(dataValue);
    }
    
    void
    SessionDiagnosticsVariableType::setUpdateCallbackModifySubscriptionCount(Callback::SPtr& callback)
    {
        modifySubscriptionCount_->callback(callback);
    }
    
    BaseNodeClass::SPtr
    SessionDiagnosticsVariableType::setPublishingModeCount(void)
    {
        return setPublishingModeCount_->baseNode().lock();
    }
    
    bool
    SessionDiagnosticsVariableType::setSetPublishingModeCount(const OpcUaDataValue& dataValue)
    {
        return setPublishingModeCount_->setDataValue(dataValue);
    }
    
    bool
    SessionDiagnosticsVariableType::getSetPublishingModeCount(OpcUaDataValue& dataValue)
    {
        return setPublishingModeCount_->getDataValue(dataValue);
    }
    
    void
    SessionDiagnosticsVariableType::setUpdateCallbackSetPublishingModeCount(Callback::SPtr& callback)
    {
        setPublishingModeCount_->callback(callback);
    }
    
    BaseNodeClass::SPtr
    SessionDiagnosticsVariableType::publishCount(void)
    {
        return publishCount_->baseNode().lock();
    }
    
    bool
    SessionDiagnosticsVariableType::setPublishCount(const OpcUaDataValue& dataValue)
    {
        return publishCount_->setDataValue(dataValue);
    }
    
    bool
    SessionDiagnosticsVariableType::getPublishCount(OpcUaDataValue& dataValue)
    {
        return publishCount_->getDataValue(dataValue);
    }
    
    void
    SessionDiagnosticsVariableType::setUpdateCallbackPublishCount(Callback::SPtr& callback)
    {
        publishCount_->callback(callback);
    }
    
    BaseNodeClass::SPtr
    SessionDiagnosticsVariableType::republishCount(void)
    {
        return republishCount_->baseNode().lock();
    }
    
    bool
    SessionDiagnosticsVariableType::setRepublishCount(const OpcUaDataValue& dataValue)
    {
        return republishCount_->setDataValue(dataValue);
    }
    
    bool
    SessionDiagnosticsVariableType::getRepublishCount(OpcUaDataValue& dataValue)
    {
        return republishCount_->getDataValue(dataValue);
    }
    
    void
    SessionDiagnosticsVariableType::setUpdateCallbackRepublishCount(Callback::SPtr& callback)
    {
        republishCount_->callback(callback);
    }
    
    BaseNodeClass::SPtr
    SessionDiagnosticsVariableType::transferSubscriptionsCount(void)
    {
        return transferSubscriptionsCount_->baseNode().lock();
    }
    
    bool
    SessionDiagnosticsVariableType::setTransferSubscriptionsCount(const OpcUaDataValue& dataValue)
    {
        return transferSubscriptionsCount_->setDataValue(dataValue);
    }
    
    bool
    SessionDiagnosticsVariableType::getTransferSubscriptionsCount(OpcUaDataValue& dataValue)
    {
        return transferSubscriptionsCount_->getDataValue(dataValue);
    }
    
    void
    SessionDiagnosticsVariableType::setUpdateCallbackTransferSubscriptionsCount(Callback::SPtr& callback)
    {
        transferSubscriptionsCount_->callback(callback);
    }
    
    BaseNodeClass::SPtr
    SessionDiagnosticsVariableType::deleteSubscriptionsCount(void)
    {
        return deleteSubscriptionsCount_->baseNode().lock();
    }
    
    bool
    SessionDiagnosticsVariableType::setDeleteSubscriptionsCount(const OpcUaDataValue& dataValue)
    {
        return deleteSubscriptionsCount_->setDataValue(dataValue);
    }
    
    bool
    SessionDiagnosticsVariableType::getDeleteSubscriptionsCount(OpcUaDataValue& dataValue)
    {
        return deleteSubscriptionsCount_->getDataValue(dataValue);
    }
    
    void
    SessionDiagnosticsVariableType::setUpdateCallbackDeleteSubscriptionsCount(Callback::SPtr& callback)
    {
        deleteSubscriptionsCount_->callback(callback);
    }
    
    BaseNodeClass::SPtr
    SessionDiagnosticsVariableType::addNodesCount(void)
    {
        return addNodesCount_->baseNode().lock();
    }
    
    bool
    SessionDiagnosticsVariableType::setAddNodesCount(const OpcUaDataValue& dataValue)
    {
        return addNodesCount_->setDataValue(dataValue);
    }
    
    bool
    SessionDiagnosticsVariableType::getAddNodesCount(OpcUaDataValue& dataValue)
    {
        return addNodesCount_->getDataValue(dataValue);
    }
    
    void
    SessionDiagnosticsVariableType::setUpdateCallbackAddNodesCount(Callback::SPtr& callback)
    {
        addNodesCount_->callback(callback);
    }
    
    BaseNodeClass::SPtr
    SessionDiagnosticsVariableType::addReferencesCount(void)
    {
        return addReferencesCount_->baseNode().lock();
    }
    
    bool
    SessionDiagnosticsVariableType::setAddReferencesCount(const OpcUaDataValue& dataValue)
    {
        return addReferencesCount_->setDataValue(dataValue);
    }
    
    bool
    SessionDiagnosticsVariableType::getAddReferencesCount(OpcUaDataValue& dataValue)
    {
        return addReferencesCount_->getDataValue(dataValue);
    }
    
    void
    SessionDiagnosticsVariableType::setUpdateCallbackAddReferencesCount(Callback::SPtr& callback)
    {
        addReferencesCount_->callback(callback);
    }
    
    BaseNodeClass::SPtr
    SessionDiagnosticsVariableType::deleteNodesCount(void)
    {
        return deleteNodesCount_->baseNode().lock();
    }
    
    bool
    SessionDiagnosticsVariableType::setDeleteNodesCount(const OpcUaDataValue& dataValue)
    {
        return deleteNodesCount_->setDataValue(dataValue);
    }
    
    bool
    SessionDiagnosticsVariableType::getDeleteNodesCount(OpcUaDataValue& dataValue)
    {
        return deleteNodesCount_->getDataValue(dataValue);
    }
    
    void
    SessionDiagnosticsVariableType::setUpdateCallbackDeleteNodesCount(Callback::SPtr& callback)
    {
        deleteNodesCount_->callback(callback);
    }
    
    BaseNodeClass::SPtr
    SessionDiagnosticsVariableType::deleteReferencesCount(void)
    {
        return deleteReferencesCount_->baseNode().lock();
    }
    
    bool
    SessionDiagnosticsVariableType::setDeleteReferencesCount(const OpcUaDataValue& dataValue)
    {
        return deleteReferencesCount_->setDataValue(dataValue);
    }
    
    bool
    SessionDiagnosticsVariableType::getDeleteReferencesCount(OpcUaDataValue& dataValue)
    {
        return deleteReferencesCount_->getDataValue(dataValue);
    }
    
    void
    SessionDiagnosticsVariableType::setUpdateCallbackDeleteReferencesCount(Callback::SPtr& callback)
    {
        deleteReferencesCount_->callback(callback);
    }
    
    BaseNodeClass::SPtr
    SessionDiagnosticsVariableType::browseCount(void)
    {
        return browseCount_->baseNode().lock();
    }
    
    bool
    SessionDiagnosticsVariableType::setBrowseCount(const OpcUaDataValue& dataValue)
    {
        return browseCount_->setDataValue(dataValue);
    }
    
    bool
    SessionDiagnosticsVariableType::getBrowseCount(OpcUaDataValue& dataValue)
    {
        return browseCount_->getDataValue(dataValue);
    }
    
    void
    SessionDiagnosticsVariableType::setUpdateCallbackBrowseCount(Callback::SPtr& callback)
    {
        browseCount_->callback(callback);
    }
    
    BaseNodeClass::SPtr
    SessionDiagnosticsVariableType::browseNextCount(void)
    {
        return browseNextCount_->baseNode().lock();
    }
    
    bool
    SessionDiagnosticsVariableType::setBrowseNextCount(const OpcUaDataValue& dataValue)
    {
        return browseNextCount_->setDataValue(dataValue);
    }
    
    bool
    SessionDiagnosticsVariableType::getBrowseNextCount(OpcUaDataValue& dataValue)
    {
        return browseNextCount_->getDataValue(dataValue);
    }
    
    void
    SessionDiagnosticsVariableType::setUpdateCallbackBrowseNextCount(Callback::SPtr& callback)
    {
        browseNextCount_->callback(callback);
    }
    
    BaseNodeClass::SPtr
    SessionDiagnosticsVariableType::translateBrowsePathsToNodeIdsCount(void)
    {
        return translateBrowsePathsToNodeIdsCount_->baseNode().lock();
    }
    
    bool
    SessionDiagnosticsVariableType::setTranslateBrowsePathsToNodeIdsCount(const OpcUaDataValue& dataValue)
    {
        return translateBrowsePathsToNodeIdsCount_->setDataValue(dataValue);
    }
    
    bool
    SessionDiagnosticsVariableType::getTranslateBrowsePathsToNodeIdsCount(OpcUaDataValue& dataValue)
    {
        return translateBrowsePathsToNodeIdsCount_->getDataValue(dataValue);
    }
    
    void
    SessionDiagnosticsVariableType::setUpdateCallbackTranslateBrowsePathsToNodeIdsCount(Callback::SPtr& callback)
    {
        translateBrowsePathsToNodeIdsCount_->callback(callback);
    }
    
    BaseNodeClass::SPtr
    SessionDiagnosticsVariableType::queryFirstCount(void)
    {
        return queryFirstCount_->baseNode().lock();
    }
    
    bool
    SessionDiagnosticsVariableType::setQueryFirstCount(const OpcUaDataValue& dataValue)
    {
        return queryFirstCount_->setDataValue(dataValue);
    }
    
    bool
    SessionDiagnosticsVariableType::getQueryFirstCount(OpcUaDataValue& dataValue)
    {
        return queryFirstCount_->getDataValue(dataValue);
    }
    
    void
    SessionDiagnosticsVariableType::setUpdateCallbackQueryFirstCount(Callback::SPtr& callback)
    {
        queryFirstCount_->callback(callback);
    }
    
    BaseNodeClass::SPtr
    SessionDiagnosticsVariableType::queryNextCount(void)
    {
        return queryNextCount_->baseNode().lock();
    }
    
    bool
    SessionDiagnosticsVariableType::setQueryNextCount(const OpcUaDataValue& dataValue)
    {
        return queryNextCount_->setDataValue(dataValue);
    }
    
    bool
    SessionDiagnosticsVariableType::getQueryNextCount(OpcUaDataValue& dataValue)
    {
        return queryNextCount_->getDataValue(dataValue);
    }
    
    void
    SessionDiagnosticsVariableType::setUpdateCallbackQueryNextCount(Callback::SPtr& callback)
    {
        queryNextCount_->callback(callback);
    }
    
    BaseNodeClass::SPtr
    SessionDiagnosticsVariableType::registerNodesCount(void)
    {
        return registerNodesCount_->baseNode().lock();
    }
    
    bool
    SessionDiagnosticsVariableType::setRegisterNodesCount(const OpcUaDataValue& dataValue)
    {
        return registerNodesCount_->setDataValue(dataValue);
    }
    
    bool
    SessionDiagnosticsVariableType::getRegisterNodesCount(OpcUaDataValue& dataValue)
    {
        return registerNodesCount_->getDataValue(dataValue);
    }
    
    void
    SessionDiagnosticsVariableType::setUpdateCallbackRegisterNodesCount(Callback::SPtr& callback)
    {
        registerNodesCount_->callback(callback);
    }
    
    BaseNodeClass::SPtr
    SessionDiagnosticsVariableType::unregisterNodesCount(void)
    {
        return unregisterNodesCount_->baseNode().lock();
    }
    
    bool
    SessionDiagnosticsVariableType::setUnregisterNodesCount(const OpcUaDataValue& dataValue)
    {
        return unregisterNodesCount_->setDataValue(dataValue);
    }
    
    bool
    SessionDiagnosticsVariableType::getUnregisterNodesCount(OpcUaDataValue& dataValue)
    {
        return unregisterNodesCount_->getDataValue(dataValue);
    }
    
    void
    SessionDiagnosticsVariableType::setUpdateCallbackUnregisterNodesCount(Callback::SPtr& callback)
    {
        unregisterNodesCount_->callback(callback);
    }

}
