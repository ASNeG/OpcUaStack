/*
    VariableTypeClass: SessionDiagnosticsVariableType

    Generated Source Code - please do not change this source code

    VariableTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackServer/StandardVariableType/SessionDiagnosticsVariableType.h"

namespace OpcUaStackServer
{
    
    SessionDiagnosticsVariableType::SessionDiagnosticsVariableType(void)
    : VariableBase()
    , actualSessionTimeout_Variable_(constructSPtr<ServerVariable>("ActualSessionTimeout_Variable"))
    , addNodesCount_Variable_(constructSPtr<ServerVariable>("AddNodesCount_Variable"))
    , addReferencesCount_Variable_(constructSPtr<ServerVariable>("AddReferencesCount_Variable"))
    , browseCount_Variable_(constructSPtr<ServerVariable>("BrowseCount_Variable"))
    , browseNextCount_Variable_(constructSPtr<ServerVariable>("BrowseNextCount_Variable"))
    , callCount_Variable_(constructSPtr<ServerVariable>("CallCount_Variable"))
    , clientConnectionTime_Variable_(constructSPtr<ServerVariable>("ClientConnectionTime_Variable"))
    , clientDescription_Variable_(constructSPtr<ServerVariable>("ClientDescription_Variable"))
    , clientLastContactTime_Variable_(constructSPtr<ServerVariable>("ClientLastContactTime_Variable"))
    , createMonitoredItemsCount_Variable_(constructSPtr<ServerVariable>("CreateMonitoredItemsCount_Variable"))
    , createSubscriptionCount_Variable_(constructSPtr<ServerVariable>("CreateSubscriptionCount_Variable"))
    , currentMonitoredItemsCount_Variable_(constructSPtr<ServerVariable>("CurrentMonitoredItemsCount_Variable"))
    , currentPublishRequestsInQueue_Variable_(constructSPtr<ServerVariable>("CurrentPublishRequestsInQueue_Variable"))
    , currentSubscriptionsCount_Variable_(constructSPtr<ServerVariable>("CurrentSubscriptionsCount_Variable"))
    , deleteMonitoredItemsCount_Variable_(constructSPtr<ServerVariable>("DeleteMonitoredItemsCount_Variable"))
    , deleteNodesCount_Variable_(constructSPtr<ServerVariable>("DeleteNodesCount_Variable"))
    , deleteReferencesCount_Variable_(constructSPtr<ServerVariable>("DeleteReferencesCount_Variable"))
    , deleteSubscriptionsCount_Variable_(constructSPtr<ServerVariable>("DeleteSubscriptionsCount_Variable"))
    , endpointUrl_Variable_(constructSPtr<ServerVariable>("EndpointUrl_Variable"))
    , historyReadCount_Variable_(constructSPtr<ServerVariable>("HistoryReadCount_Variable"))
    , historyUpdateCount_Variable_(constructSPtr<ServerVariable>("HistoryUpdateCount_Variable"))
    , localeIds_Variable_(constructSPtr<ServerVariable>("LocaleIds_Variable"))
    , maxResponseMessageSize_Variable_(constructSPtr<ServerVariable>("MaxResponseMessageSize_Variable"))
    , modifyMonitoredItemsCount_Variable_(constructSPtr<ServerVariable>("ModifyMonitoredItemsCount_Variable"))
    , modifySubscriptionCount_Variable_(constructSPtr<ServerVariable>("ModifySubscriptionCount_Variable"))
    , publishCount_Variable_(constructSPtr<ServerVariable>("PublishCount_Variable"))
    , queryFirstCount_Variable_(constructSPtr<ServerVariable>("QueryFirstCount_Variable"))
    , queryNextCount_Variable_(constructSPtr<ServerVariable>("QueryNextCount_Variable"))
    , readCount_Variable_(constructSPtr<ServerVariable>("ReadCount_Variable"))
    , registerNodesCount_Variable_(constructSPtr<ServerVariable>("RegisterNodesCount_Variable"))
    , republishCount_Variable_(constructSPtr<ServerVariable>("RepublishCount_Variable"))
    , serverUri_Variable_(constructSPtr<ServerVariable>("ServerUri_Variable"))
    , sessionId_Variable_(constructSPtr<ServerVariable>("SessionId_Variable"))
    , sessionName_Variable_(constructSPtr<ServerVariable>("SessionName_Variable"))
    , setMonitoringModeCount_Variable_(constructSPtr<ServerVariable>("SetMonitoringModeCount_Variable"))
    , setPublishingModeCount_Variable_(constructSPtr<ServerVariable>("SetPublishingModeCount_Variable"))
    , setTriggeringCount_Variable_(constructSPtr<ServerVariable>("SetTriggeringCount_Variable"))
    , totalRequestCount_Variable_(constructSPtr<ServerVariable>("TotalRequestCount_Variable"))
    , transferSubscriptionsCount_Variable_(constructSPtr<ServerVariable>("TransferSubscriptionsCount_Variable"))
    , translateBrowsePathsToNodeIdsCount_Variable_(constructSPtr<ServerVariable>("TranslateBrowsePathsToNodeIdsCount_Variable"))
    , unauthorizedRequestCount_Variable_(constructSPtr<ServerVariable>("UnauthorizedRequestCount_Variable"))
    , unregisterNodesCount_Variable_(constructSPtr<ServerVariable>("UnregisterNodesCount_Variable"))
    , variable_(constructSPtr<ServerVariable>("Variable"))
    , writeCount_Variable_(constructSPtr<ServerVariable>("WriteCount_Variable"))
    {
        variableTypeNamespaceName("http://opcfoundation.org/UA/");
        variableTypeNodeId((OpcUaUInt32)2197);
        setServerVariable(actualSessionTimeout_Variable_);
        setServerVariable(addNodesCount_Variable_);
        setServerVariable(addReferencesCount_Variable_);
        setServerVariable(browseCount_Variable_);
        setServerVariable(browseNextCount_Variable_);
        setServerVariable(callCount_Variable_);
        setServerVariable(clientConnectionTime_Variable_);
        setServerVariable(clientDescription_Variable_);
        setServerVariable(clientLastContactTime_Variable_);
        setServerVariable(createMonitoredItemsCount_Variable_);
        setServerVariable(createSubscriptionCount_Variable_);
        setServerVariable(currentMonitoredItemsCount_Variable_);
        setServerVariable(currentPublishRequestsInQueue_Variable_);
        setServerVariable(currentSubscriptionsCount_Variable_);
        setServerVariable(deleteMonitoredItemsCount_Variable_);
        setServerVariable(deleteNodesCount_Variable_);
        setServerVariable(deleteReferencesCount_Variable_);
        setServerVariable(deleteSubscriptionsCount_Variable_);
        setServerVariable(endpointUrl_Variable_);
        setServerVariable(historyReadCount_Variable_);
        setServerVariable(historyUpdateCount_Variable_);
        setServerVariable(localeIds_Variable_);
        setServerVariable(maxResponseMessageSize_Variable_);
        setServerVariable(modifyMonitoredItemsCount_Variable_);
        setServerVariable(modifySubscriptionCount_Variable_);
        setServerVariable(publishCount_Variable_);
        setServerVariable(queryFirstCount_Variable_);
        setServerVariable(queryNextCount_Variable_);
        setServerVariable(readCount_Variable_);
        setServerVariable(registerNodesCount_Variable_);
        setServerVariable(republishCount_Variable_);
        setServerVariable(serverUri_Variable_);
        setServerVariable(sessionId_Variable_);
        setServerVariable(sessionName_Variable_);
        setServerVariable(setMonitoringModeCount_Variable_);
        setServerVariable(setPublishingModeCount_Variable_);
        setServerVariable(setTriggeringCount_Variable_);
        setServerVariable(totalRequestCount_Variable_);
        setServerVariable(transferSubscriptionsCount_Variable_);
        setServerVariable(translateBrowsePathsToNodeIdsCount_Variable_);
        setServerVariable(unauthorizedRequestCount_Variable_);
        setServerVariable(unregisterNodesCount_Variable_);
        setServerVariable(variable_);
        setServerVariable(writeCount_Variable_);
    }
    
    SessionDiagnosticsVariableType::SessionDiagnosticsVariableType(const SessionDiagnosticsVariableType& value)
    : VariableBase()
    , actualSessionTimeout_Variable_(constructSPtr<ServerVariable>("ActualSessionTimeout_Variable"))
    , addNodesCount_Variable_(constructSPtr<ServerVariable>("AddNodesCount_Variable"))
    , addReferencesCount_Variable_(constructSPtr<ServerVariable>("AddReferencesCount_Variable"))
    , browseCount_Variable_(constructSPtr<ServerVariable>("BrowseCount_Variable"))
    , browseNextCount_Variable_(constructSPtr<ServerVariable>("BrowseNextCount_Variable"))
    , callCount_Variable_(constructSPtr<ServerVariable>("CallCount_Variable"))
    , clientConnectionTime_Variable_(constructSPtr<ServerVariable>("ClientConnectionTime_Variable"))
    , clientDescription_Variable_(constructSPtr<ServerVariable>("ClientDescription_Variable"))
    , clientLastContactTime_Variable_(constructSPtr<ServerVariable>("ClientLastContactTime_Variable"))
    , createMonitoredItemsCount_Variable_(constructSPtr<ServerVariable>("CreateMonitoredItemsCount_Variable"))
    , createSubscriptionCount_Variable_(constructSPtr<ServerVariable>("CreateSubscriptionCount_Variable"))
    , currentMonitoredItemsCount_Variable_(constructSPtr<ServerVariable>("CurrentMonitoredItemsCount_Variable"))
    , currentPublishRequestsInQueue_Variable_(constructSPtr<ServerVariable>("CurrentPublishRequestsInQueue_Variable"))
    , currentSubscriptionsCount_Variable_(constructSPtr<ServerVariable>("CurrentSubscriptionsCount_Variable"))
    , deleteMonitoredItemsCount_Variable_(constructSPtr<ServerVariable>("DeleteMonitoredItemsCount_Variable"))
    , deleteNodesCount_Variable_(constructSPtr<ServerVariable>("DeleteNodesCount_Variable"))
    , deleteReferencesCount_Variable_(constructSPtr<ServerVariable>("DeleteReferencesCount_Variable"))
    , deleteSubscriptionsCount_Variable_(constructSPtr<ServerVariable>("DeleteSubscriptionsCount_Variable"))
    , endpointUrl_Variable_(constructSPtr<ServerVariable>("EndpointUrl_Variable"))
    , historyReadCount_Variable_(constructSPtr<ServerVariable>("HistoryReadCount_Variable"))
    , historyUpdateCount_Variable_(constructSPtr<ServerVariable>("HistoryUpdateCount_Variable"))
    , localeIds_Variable_(constructSPtr<ServerVariable>("LocaleIds_Variable"))
    , maxResponseMessageSize_Variable_(constructSPtr<ServerVariable>("MaxResponseMessageSize_Variable"))
    , modifyMonitoredItemsCount_Variable_(constructSPtr<ServerVariable>("ModifyMonitoredItemsCount_Variable"))
    , modifySubscriptionCount_Variable_(constructSPtr<ServerVariable>("ModifySubscriptionCount_Variable"))
    , publishCount_Variable_(constructSPtr<ServerVariable>("PublishCount_Variable"))
    , queryFirstCount_Variable_(constructSPtr<ServerVariable>("QueryFirstCount_Variable"))
    , queryNextCount_Variable_(constructSPtr<ServerVariable>("QueryNextCount_Variable"))
    , readCount_Variable_(constructSPtr<ServerVariable>("ReadCount_Variable"))
    , registerNodesCount_Variable_(constructSPtr<ServerVariable>("RegisterNodesCount_Variable"))
    , republishCount_Variable_(constructSPtr<ServerVariable>("RepublishCount_Variable"))
    , serverUri_Variable_(constructSPtr<ServerVariable>("ServerUri_Variable"))
    , sessionId_Variable_(constructSPtr<ServerVariable>("SessionId_Variable"))
    , sessionName_Variable_(constructSPtr<ServerVariable>("SessionName_Variable"))
    , setMonitoringModeCount_Variable_(constructSPtr<ServerVariable>("SetMonitoringModeCount_Variable"))
    , setPublishingModeCount_Variable_(constructSPtr<ServerVariable>("SetPublishingModeCount_Variable"))
    , setTriggeringCount_Variable_(constructSPtr<ServerVariable>("SetTriggeringCount_Variable"))
    , totalRequestCount_Variable_(constructSPtr<ServerVariable>("TotalRequestCount_Variable"))
    , transferSubscriptionsCount_Variable_(constructSPtr<ServerVariable>("TransferSubscriptionsCount_Variable"))
    , translateBrowsePathsToNodeIdsCount_Variable_(constructSPtr<ServerVariable>("TranslateBrowsePathsToNodeIdsCount_Variable"))
    , unauthorizedRequestCount_Variable_(constructSPtr<ServerVariable>("UnauthorizedRequestCount_Variable"))
    , unregisterNodesCount_Variable_(constructSPtr<ServerVariable>("UnregisterNodesCount_Variable"))
    , variable_(constructSPtr<ServerVariable>("Variable"))
    , writeCount_Variable_(constructSPtr<ServerVariable>("WriteCount_Variable"))
    {
        variableTypeNamespaceName("http://opcfoundation.org/UA/");
        variableTypeNodeId((OpcUaUInt32)2197);
        setServerVariable(actualSessionTimeout_Variable_);
        setServerVariable(addNodesCount_Variable_);
        setServerVariable(addReferencesCount_Variable_);
        setServerVariable(browseCount_Variable_);
        setServerVariable(browseNextCount_Variable_);
        setServerVariable(callCount_Variable_);
        setServerVariable(clientConnectionTime_Variable_);
        setServerVariable(clientDescription_Variable_);
        setServerVariable(clientLastContactTime_Variable_);
        setServerVariable(createMonitoredItemsCount_Variable_);
        setServerVariable(createSubscriptionCount_Variable_);
        setServerVariable(currentMonitoredItemsCount_Variable_);
        setServerVariable(currentPublishRequestsInQueue_Variable_);
        setServerVariable(currentSubscriptionsCount_Variable_);
        setServerVariable(deleteMonitoredItemsCount_Variable_);
        setServerVariable(deleteNodesCount_Variable_);
        setServerVariable(deleteReferencesCount_Variable_);
        setServerVariable(deleteSubscriptionsCount_Variable_);
        setServerVariable(endpointUrl_Variable_);
        setServerVariable(historyReadCount_Variable_);
        setServerVariable(historyUpdateCount_Variable_);
        setServerVariable(localeIds_Variable_);
        setServerVariable(maxResponseMessageSize_Variable_);
        setServerVariable(modifyMonitoredItemsCount_Variable_);
        setServerVariable(modifySubscriptionCount_Variable_);
        setServerVariable(publishCount_Variable_);
        setServerVariable(queryFirstCount_Variable_);
        setServerVariable(queryNextCount_Variable_);
        setServerVariable(readCount_Variable_);
        setServerVariable(registerNodesCount_Variable_);
        setServerVariable(republishCount_Variable_);
        setServerVariable(serverUri_Variable_);
        setServerVariable(sessionId_Variable_);
        setServerVariable(sessionName_Variable_);
        setServerVariable(setMonitoringModeCount_Variable_);
        setServerVariable(setPublishingModeCount_Variable_);
        setServerVariable(setTriggeringCount_Variable_);
        setServerVariable(totalRequestCount_Variable_);
        setServerVariable(transferSubscriptionsCount_Variable_);
        setServerVariable(translateBrowsePathsToNodeIdsCount_Variable_);
        setServerVariable(unauthorizedRequestCount_Variable_);
        setServerVariable(unregisterNodesCount_Variable_);
        setServerVariable(variable_);
        setServerVariable(writeCount_Variable_);
    }
    
    SessionDiagnosticsVariableType::~SessionDiagnosticsVariableType(void)
    {
    }

    ServerVariable::SPtr&
    SessionDiagnosticsVariableType::actualSessionTimeout_Variable(void)
    {
        return actualSessionTimeout_Variable_;
    }

    ServerVariable::SPtr&
    SessionDiagnosticsVariableType::addNodesCount_Variable(void)
    {
        return addNodesCount_Variable_;
    }

    ServerVariable::SPtr&
    SessionDiagnosticsVariableType::addReferencesCount_Variable(void)
    {
        return addReferencesCount_Variable_;
    }

    ServerVariable::SPtr&
    SessionDiagnosticsVariableType::browseCount_Variable(void)
    {
        return browseCount_Variable_;
    }

    ServerVariable::SPtr&
    SessionDiagnosticsVariableType::browseNextCount_Variable(void)
    {
        return browseNextCount_Variable_;
    }

    ServerVariable::SPtr&
    SessionDiagnosticsVariableType::callCount_Variable(void)
    {
        return callCount_Variable_;
    }

    ServerVariable::SPtr&
    SessionDiagnosticsVariableType::clientConnectionTime_Variable(void)
    {
        return clientConnectionTime_Variable_;
    }

    ServerVariable::SPtr&
    SessionDiagnosticsVariableType::clientDescription_Variable(void)
    {
        return clientDescription_Variable_;
    }

    ServerVariable::SPtr&
    SessionDiagnosticsVariableType::clientLastContactTime_Variable(void)
    {
        return clientLastContactTime_Variable_;
    }

    ServerVariable::SPtr&
    SessionDiagnosticsVariableType::createMonitoredItemsCount_Variable(void)
    {
        return createMonitoredItemsCount_Variable_;
    }

    ServerVariable::SPtr&
    SessionDiagnosticsVariableType::createSubscriptionCount_Variable(void)
    {
        return createSubscriptionCount_Variable_;
    }

    ServerVariable::SPtr&
    SessionDiagnosticsVariableType::currentMonitoredItemsCount_Variable(void)
    {
        return currentMonitoredItemsCount_Variable_;
    }

    ServerVariable::SPtr&
    SessionDiagnosticsVariableType::currentPublishRequestsInQueue_Variable(void)
    {
        return currentPublishRequestsInQueue_Variable_;
    }

    ServerVariable::SPtr&
    SessionDiagnosticsVariableType::currentSubscriptionsCount_Variable(void)
    {
        return currentSubscriptionsCount_Variable_;
    }

    ServerVariable::SPtr&
    SessionDiagnosticsVariableType::deleteMonitoredItemsCount_Variable(void)
    {
        return deleteMonitoredItemsCount_Variable_;
    }

    ServerVariable::SPtr&
    SessionDiagnosticsVariableType::deleteNodesCount_Variable(void)
    {
        return deleteNodesCount_Variable_;
    }

    ServerVariable::SPtr&
    SessionDiagnosticsVariableType::deleteReferencesCount_Variable(void)
    {
        return deleteReferencesCount_Variable_;
    }

    ServerVariable::SPtr&
    SessionDiagnosticsVariableType::deleteSubscriptionsCount_Variable(void)
    {
        return deleteSubscriptionsCount_Variable_;
    }

    ServerVariable::SPtr&
    SessionDiagnosticsVariableType::endpointUrl_Variable(void)
    {
        return endpointUrl_Variable_;
    }

    ServerVariable::SPtr&
    SessionDiagnosticsVariableType::historyReadCount_Variable(void)
    {
        return historyReadCount_Variable_;
    }

    ServerVariable::SPtr&
    SessionDiagnosticsVariableType::historyUpdateCount_Variable(void)
    {
        return historyUpdateCount_Variable_;
    }

    ServerVariable::SPtr&
    SessionDiagnosticsVariableType::localeIds_Variable(void)
    {
        return localeIds_Variable_;
    }

    ServerVariable::SPtr&
    SessionDiagnosticsVariableType::maxResponseMessageSize_Variable(void)
    {
        return maxResponseMessageSize_Variable_;
    }

    ServerVariable::SPtr&
    SessionDiagnosticsVariableType::modifyMonitoredItemsCount_Variable(void)
    {
        return modifyMonitoredItemsCount_Variable_;
    }

    ServerVariable::SPtr&
    SessionDiagnosticsVariableType::modifySubscriptionCount_Variable(void)
    {
        return modifySubscriptionCount_Variable_;
    }

    ServerVariable::SPtr&
    SessionDiagnosticsVariableType::publishCount_Variable(void)
    {
        return publishCount_Variable_;
    }

    ServerVariable::SPtr&
    SessionDiagnosticsVariableType::queryFirstCount_Variable(void)
    {
        return queryFirstCount_Variable_;
    }

    ServerVariable::SPtr&
    SessionDiagnosticsVariableType::queryNextCount_Variable(void)
    {
        return queryNextCount_Variable_;
    }

    ServerVariable::SPtr&
    SessionDiagnosticsVariableType::readCount_Variable(void)
    {
        return readCount_Variable_;
    }

    ServerVariable::SPtr&
    SessionDiagnosticsVariableType::registerNodesCount_Variable(void)
    {
        return registerNodesCount_Variable_;
    }

    ServerVariable::SPtr&
    SessionDiagnosticsVariableType::republishCount_Variable(void)
    {
        return republishCount_Variable_;
    }

    ServerVariable::SPtr&
    SessionDiagnosticsVariableType::serverUri_Variable(void)
    {
        return serverUri_Variable_;
    }

    ServerVariable::SPtr&
    SessionDiagnosticsVariableType::sessionId_Variable(void)
    {
        return sessionId_Variable_;
    }

    ServerVariable::SPtr&
    SessionDiagnosticsVariableType::sessionName_Variable(void)
    {
        return sessionName_Variable_;
    }

    ServerVariable::SPtr&
    SessionDiagnosticsVariableType::setMonitoringModeCount_Variable(void)
    {
        return setMonitoringModeCount_Variable_;
    }

    ServerVariable::SPtr&
    SessionDiagnosticsVariableType::setPublishingModeCount_Variable(void)
    {
        return setPublishingModeCount_Variable_;
    }

    ServerVariable::SPtr&
    SessionDiagnosticsVariableType::setTriggeringCount_Variable(void)
    {
        return setTriggeringCount_Variable_;
    }

    ServerVariable::SPtr&
    SessionDiagnosticsVariableType::totalRequestCount_Variable(void)
    {
        return totalRequestCount_Variable_;
    }

    ServerVariable::SPtr&
    SessionDiagnosticsVariableType::transferSubscriptionsCount_Variable(void)
    {
        return transferSubscriptionsCount_Variable_;
    }

    ServerVariable::SPtr&
    SessionDiagnosticsVariableType::translateBrowsePathsToNodeIdsCount_Variable(void)
    {
        return translateBrowsePathsToNodeIdsCount_Variable_;
    }

    ServerVariable::SPtr&
    SessionDiagnosticsVariableType::unauthorizedRequestCount_Variable(void)
    {
        return unauthorizedRequestCount_Variable_;
    }

    ServerVariable::SPtr&
    SessionDiagnosticsVariableType::unregisterNodesCount_Variable(void)
    {
        return unregisterNodesCount_Variable_;
    }

    ServerVariable::SPtr&
    SessionDiagnosticsVariableType::variable(void)
    {
        return variable_;
    }

    ServerVariable::SPtr&
    SessionDiagnosticsVariableType::writeCount_Variable(void)
    {
        return writeCount_Variable_;
    }

    void
    SessionDiagnosticsVariableType::actualSessionTimeout_Variable(ServerVariable::SPtr& serverVariable)
    {
        actualSessionTimeout_Variable_ = serverVariable;
    }

    void
    SessionDiagnosticsVariableType::addNodesCount_Variable(ServerVariable::SPtr& serverVariable)
    {
        addNodesCount_Variable_ = serverVariable;
    }

    void
    SessionDiagnosticsVariableType::addReferencesCount_Variable(ServerVariable::SPtr& serverVariable)
    {
        addReferencesCount_Variable_ = serverVariable;
    }

    void
    SessionDiagnosticsVariableType::browseCount_Variable(ServerVariable::SPtr& serverVariable)
    {
        browseCount_Variable_ = serverVariable;
    }

    void
    SessionDiagnosticsVariableType::browseNextCount_Variable(ServerVariable::SPtr& serverVariable)
    {
        browseNextCount_Variable_ = serverVariable;
    }

    void
    SessionDiagnosticsVariableType::callCount_Variable(ServerVariable::SPtr& serverVariable)
    {
        callCount_Variable_ = serverVariable;
    }

    void
    SessionDiagnosticsVariableType::clientConnectionTime_Variable(ServerVariable::SPtr& serverVariable)
    {
        clientConnectionTime_Variable_ = serverVariable;
    }

    void
    SessionDiagnosticsVariableType::clientDescription_Variable(ServerVariable::SPtr& serverVariable)
    {
        clientDescription_Variable_ = serverVariable;
    }

    void
    SessionDiagnosticsVariableType::clientLastContactTime_Variable(ServerVariable::SPtr& serverVariable)
    {
        clientLastContactTime_Variable_ = serverVariable;
    }

    void
    SessionDiagnosticsVariableType::createMonitoredItemsCount_Variable(ServerVariable::SPtr& serverVariable)
    {
        createMonitoredItemsCount_Variable_ = serverVariable;
    }

    void
    SessionDiagnosticsVariableType::createSubscriptionCount_Variable(ServerVariable::SPtr& serverVariable)
    {
        createSubscriptionCount_Variable_ = serverVariable;
    }

    void
    SessionDiagnosticsVariableType::currentMonitoredItemsCount_Variable(ServerVariable::SPtr& serverVariable)
    {
        currentMonitoredItemsCount_Variable_ = serverVariable;
    }

    void
    SessionDiagnosticsVariableType::currentPublishRequestsInQueue_Variable(ServerVariable::SPtr& serverVariable)
    {
        currentPublishRequestsInQueue_Variable_ = serverVariable;
    }

    void
    SessionDiagnosticsVariableType::currentSubscriptionsCount_Variable(ServerVariable::SPtr& serverVariable)
    {
        currentSubscriptionsCount_Variable_ = serverVariable;
    }

    void
    SessionDiagnosticsVariableType::deleteMonitoredItemsCount_Variable(ServerVariable::SPtr& serverVariable)
    {
        deleteMonitoredItemsCount_Variable_ = serverVariable;
    }

    void
    SessionDiagnosticsVariableType::deleteNodesCount_Variable(ServerVariable::SPtr& serverVariable)
    {
        deleteNodesCount_Variable_ = serverVariable;
    }

    void
    SessionDiagnosticsVariableType::deleteReferencesCount_Variable(ServerVariable::SPtr& serverVariable)
    {
        deleteReferencesCount_Variable_ = serverVariable;
    }

    void
    SessionDiagnosticsVariableType::deleteSubscriptionsCount_Variable(ServerVariable::SPtr& serverVariable)
    {
        deleteSubscriptionsCount_Variable_ = serverVariable;
    }

    void
    SessionDiagnosticsVariableType::endpointUrl_Variable(ServerVariable::SPtr& serverVariable)
    {
        endpointUrl_Variable_ = serverVariable;
    }

    void
    SessionDiagnosticsVariableType::historyReadCount_Variable(ServerVariable::SPtr& serverVariable)
    {
        historyReadCount_Variable_ = serverVariable;
    }

    void
    SessionDiagnosticsVariableType::historyUpdateCount_Variable(ServerVariable::SPtr& serverVariable)
    {
        historyUpdateCount_Variable_ = serverVariable;
    }

    void
    SessionDiagnosticsVariableType::localeIds_Variable(ServerVariable::SPtr& serverVariable)
    {
        localeIds_Variable_ = serverVariable;
    }

    void
    SessionDiagnosticsVariableType::maxResponseMessageSize_Variable(ServerVariable::SPtr& serverVariable)
    {
        maxResponseMessageSize_Variable_ = serverVariable;
    }

    void
    SessionDiagnosticsVariableType::modifyMonitoredItemsCount_Variable(ServerVariable::SPtr& serverVariable)
    {
        modifyMonitoredItemsCount_Variable_ = serverVariable;
    }

    void
    SessionDiagnosticsVariableType::modifySubscriptionCount_Variable(ServerVariable::SPtr& serverVariable)
    {
        modifySubscriptionCount_Variable_ = serverVariable;
    }

    void
    SessionDiagnosticsVariableType::publishCount_Variable(ServerVariable::SPtr& serverVariable)
    {
        publishCount_Variable_ = serverVariable;
    }

    void
    SessionDiagnosticsVariableType::queryFirstCount_Variable(ServerVariable::SPtr& serverVariable)
    {
        queryFirstCount_Variable_ = serverVariable;
    }

    void
    SessionDiagnosticsVariableType::queryNextCount_Variable(ServerVariable::SPtr& serverVariable)
    {
        queryNextCount_Variable_ = serverVariable;
    }

    void
    SessionDiagnosticsVariableType::readCount_Variable(ServerVariable::SPtr& serverVariable)
    {
        readCount_Variable_ = serverVariable;
    }

    void
    SessionDiagnosticsVariableType::registerNodesCount_Variable(ServerVariable::SPtr& serverVariable)
    {
        registerNodesCount_Variable_ = serverVariable;
    }

    void
    SessionDiagnosticsVariableType::republishCount_Variable(ServerVariable::SPtr& serverVariable)
    {
        republishCount_Variable_ = serverVariable;
    }

    void
    SessionDiagnosticsVariableType::serverUri_Variable(ServerVariable::SPtr& serverVariable)
    {
        serverUri_Variable_ = serverVariable;
    }

    void
    SessionDiagnosticsVariableType::sessionId_Variable(ServerVariable::SPtr& serverVariable)
    {
        sessionId_Variable_ = serverVariable;
    }

    void
    SessionDiagnosticsVariableType::sessionName_Variable(ServerVariable::SPtr& serverVariable)
    {
        sessionName_Variable_ = serverVariable;
    }

    void
    SessionDiagnosticsVariableType::setMonitoringModeCount_Variable(ServerVariable::SPtr& serverVariable)
    {
        setMonitoringModeCount_Variable_ = serverVariable;
    }

    void
    SessionDiagnosticsVariableType::setPublishingModeCount_Variable(ServerVariable::SPtr& serverVariable)
    {
        setPublishingModeCount_Variable_ = serverVariable;
    }

    void
    SessionDiagnosticsVariableType::setTriggeringCount_Variable(ServerVariable::SPtr& serverVariable)
    {
        setTriggeringCount_Variable_ = serverVariable;
    }

    void
    SessionDiagnosticsVariableType::totalRequestCount_Variable(ServerVariable::SPtr& serverVariable)
    {
        totalRequestCount_Variable_ = serverVariable;
    }

    void
    SessionDiagnosticsVariableType::transferSubscriptionsCount_Variable(ServerVariable::SPtr& serverVariable)
    {
        transferSubscriptionsCount_Variable_ = serverVariable;
    }

    void
    SessionDiagnosticsVariableType::translateBrowsePathsToNodeIdsCount_Variable(ServerVariable::SPtr& serverVariable)
    {
        translateBrowsePathsToNodeIdsCount_Variable_ = serverVariable;
    }

    void
    SessionDiagnosticsVariableType::unauthorizedRequestCount_Variable(ServerVariable::SPtr& serverVariable)
    {
        unauthorizedRequestCount_Variable_ = serverVariable;
    }

    void
    SessionDiagnosticsVariableType::unregisterNodesCount_Variable(ServerVariable::SPtr& serverVariable)
    {
        unregisterNodesCount_Variable_ = serverVariable;
    }

    void
    SessionDiagnosticsVariableType::variable(ServerVariable::SPtr& serverVariable)
    {
        variable_ = serverVariable;
    }

    void
    SessionDiagnosticsVariableType::writeCount_Variable(ServerVariable::SPtr& serverVariable)
    {
        writeCount_Variable_ = serverVariable;
    }

    bool
    SessionDiagnosticsVariableType::get_ActualSessionTimeout_Variable(OpcUaDataValue& dataValue)
    {
        return actualSessionTimeout_Variable_->getDataValue(dataValue);
    }

    bool
    SessionDiagnosticsVariableType::get_AddNodesCount_Variable(OpcUaDataValue& dataValue)
    {
        return addNodesCount_Variable_->getDataValue(dataValue);
    }

    bool
    SessionDiagnosticsVariableType::get_AddReferencesCount_Variable(OpcUaDataValue& dataValue)
    {
        return addReferencesCount_Variable_->getDataValue(dataValue);
    }

    bool
    SessionDiagnosticsVariableType::get_BrowseCount_Variable(OpcUaDataValue& dataValue)
    {
        return browseCount_Variable_->getDataValue(dataValue);
    }

    bool
    SessionDiagnosticsVariableType::get_BrowseNextCount_Variable(OpcUaDataValue& dataValue)
    {
        return browseNextCount_Variable_->getDataValue(dataValue);
    }

    bool
    SessionDiagnosticsVariableType::get_CallCount_Variable(OpcUaDataValue& dataValue)
    {
        return callCount_Variable_->getDataValue(dataValue);
    }

    bool
    SessionDiagnosticsVariableType::get_ClientConnectionTime_Variable(OpcUaDataValue& dataValue)
    {
        return clientConnectionTime_Variable_->getDataValue(dataValue);
    }

    bool
    SessionDiagnosticsVariableType::get_ClientDescription_Variable(OpcUaDataValue& dataValue)
    {
        return clientDescription_Variable_->getDataValue(dataValue);
    }

    bool
    SessionDiagnosticsVariableType::get_ClientLastContactTime_Variable(OpcUaDataValue& dataValue)
    {
        return clientLastContactTime_Variable_->getDataValue(dataValue);
    }

    bool
    SessionDiagnosticsVariableType::get_CreateMonitoredItemsCount_Variable(OpcUaDataValue& dataValue)
    {
        return createMonitoredItemsCount_Variable_->getDataValue(dataValue);
    }

    bool
    SessionDiagnosticsVariableType::get_CreateSubscriptionCount_Variable(OpcUaDataValue& dataValue)
    {
        return createSubscriptionCount_Variable_->getDataValue(dataValue);
    }

    bool
    SessionDiagnosticsVariableType::get_CurrentMonitoredItemsCount_Variable(OpcUaDataValue& dataValue)
    {
        return currentMonitoredItemsCount_Variable_->getDataValue(dataValue);
    }

    bool
    SessionDiagnosticsVariableType::get_CurrentPublishRequestsInQueue_Variable(OpcUaDataValue& dataValue)
    {
        return currentPublishRequestsInQueue_Variable_->getDataValue(dataValue);
    }

    bool
    SessionDiagnosticsVariableType::get_CurrentSubscriptionsCount_Variable(OpcUaDataValue& dataValue)
    {
        return currentSubscriptionsCount_Variable_->getDataValue(dataValue);
    }

    bool
    SessionDiagnosticsVariableType::get_DeleteMonitoredItemsCount_Variable(OpcUaDataValue& dataValue)
    {
        return deleteMonitoredItemsCount_Variable_->getDataValue(dataValue);
    }

    bool
    SessionDiagnosticsVariableType::get_DeleteNodesCount_Variable(OpcUaDataValue& dataValue)
    {
        return deleteNodesCount_Variable_->getDataValue(dataValue);
    }

    bool
    SessionDiagnosticsVariableType::get_DeleteReferencesCount_Variable(OpcUaDataValue& dataValue)
    {
        return deleteReferencesCount_Variable_->getDataValue(dataValue);
    }

    bool
    SessionDiagnosticsVariableType::get_DeleteSubscriptionsCount_Variable(OpcUaDataValue& dataValue)
    {
        return deleteSubscriptionsCount_Variable_->getDataValue(dataValue);
    }

    bool
    SessionDiagnosticsVariableType::get_EndpointUrl_Variable(OpcUaDataValue& dataValue)
    {
        return endpointUrl_Variable_->getDataValue(dataValue);
    }

    bool
    SessionDiagnosticsVariableType::get_HistoryReadCount_Variable(OpcUaDataValue& dataValue)
    {
        return historyReadCount_Variable_->getDataValue(dataValue);
    }

    bool
    SessionDiagnosticsVariableType::get_HistoryUpdateCount_Variable(OpcUaDataValue& dataValue)
    {
        return historyUpdateCount_Variable_->getDataValue(dataValue);
    }

    bool
    SessionDiagnosticsVariableType::get_LocaleIds_Variable(OpcUaDataValue& dataValue)
    {
        return localeIds_Variable_->getDataValue(dataValue);
    }

    bool
    SessionDiagnosticsVariableType::get_MaxResponseMessageSize_Variable(OpcUaDataValue& dataValue)
    {
        return maxResponseMessageSize_Variable_->getDataValue(dataValue);
    }

    bool
    SessionDiagnosticsVariableType::get_ModifyMonitoredItemsCount_Variable(OpcUaDataValue& dataValue)
    {
        return modifyMonitoredItemsCount_Variable_->getDataValue(dataValue);
    }

    bool
    SessionDiagnosticsVariableType::get_ModifySubscriptionCount_Variable(OpcUaDataValue& dataValue)
    {
        return modifySubscriptionCount_Variable_->getDataValue(dataValue);
    }

    bool
    SessionDiagnosticsVariableType::get_PublishCount_Variable(OpcUaDataValue& dataValue)
    {
        return publishCount_Variable_->getDataValue(dataValue);
    }

    bool
    SessionDiagnosticsVariableType::get_QueryFirstCount_Variable(OpcUaDataValue& dataValue)
    {
        return queryFirstCount_Variable_->getDataValue(dataValue);
    }

    bool
    SessionDiagnosticsVariableType::get_QueryNextCount_Variable(OpcUaDataValue& dataValue)
    {
        return queryNextCount_Variable_->getDataValue(dataValue);
    }

    bool
    SessionDiagnosticsVariableType::get_ReadCount_Variable(OpcUaDataValue& dataValue)
    {
        return readCount_Variable_->getDataValue(dataValue);
    }

    bool
    SessionDiagnosticsVariableType::get_RegisterNodesCount_Variable(OpcUaDataValue& dataValue)
    {
        return registerNodesCount_Variable_->getDataValue(dataValue);
    }

    bool
    SessionDiagnosticsVariableType::get_RepublishCount_Variable(OpcUaDataValue& dataValue)
    {
        return republishCount_Variable_->getDataValue(dataValue);
    }

    bool
    SessionDiagnosticsVariableType::get_ServerUri_Variable(OpcUaDataValue& dataValue)
    {
        return serverUri_Variable_->getDataValue(dataValue);
    }

    bool
    SessionDiagnosticsVariableType::get_SessionId_Variable(OpcUaDataValue& dataValue)
    {
        return sessionId_Variable_->getDataValue(dataValue);
    }

    bool
    SessionDiagnosticsVariableType::get_SessionName_Variable(OpcUaDataValue& dataValue)
    {
        return sessionName_Variable_->getDataValue(dataValue);
    }

    bool
    SessionDiagnosticsVariableType::get_SetMonitoringModeCount_Variable(OpcUaDataValue& dataValue)
    {
        return setMonitoringModeCount_Variable_->getDataValue(dataValue);
    }

    bool
    SessionDiagnosticsVariableType::get_SetPublishingModeCount_Variable(OpcUaDataValue& dataValue)
    {
        return setPublishingModeCount_Variable_->getDataValue(dataValue);
    }

    bool
    SessionDiagnosticsVariableType::get_SetTriggeringCount_Variable(OpcUaDataValue& dataValue)
    {
        return setTriggeringCount_Variable_->getDataValue(dataValue);
    }

    bool
    SessionDiagnosticsVariableType::get_TotalRequestCount_Variable(OpcUaDataValue& dataValue)
    {
        return totalRequestCount_Variable_->getDataValue(dataValue);
    }

    bool
    SessionDiagnosticsVariableType::get_TransferSubscriptionsCount_Variable(OpcUaDataValue& dataValue)
    {
        return transferSubscriptionsCount_Variable_->getDataValue(dataValue);
    }

    bool
    SessionDiagnosticsVariableType::get_TranslateBrowsePathsToNodeIdsCount_Variable(OpcUaDataValue& dataValue)
    {
        return translateBrowsePathsToNodeIdsCount_Variable_->getDataValue(dataValue);
    }

    bool
    SessionDiagnosticsVariableType::get_UnauthorizedRequestCount_Variable(OpcUaDataValue& dataValue)
    {
        return unauthorizedRequestCount_Variable_->getDataValue(dataValue);
    }

    bool
    SessionDiagnosticsVariableType::get_UnregisterNodesCount_Variable(OpcUaDataValue& dataValue)
    {
        return unregisterNodesCount_Variable_->getDataValue(dataValue);
    }

    bool
    SessionDiagnosticsVariableType::get_Variable(OpcUaDataValue& dataValue)
    {
        return variable_->getDataValue(dataValue);
    }

    bool
    SessionDiagnosticsVariableType::get_WriteCount_Variable(OpcUaDataValue& dataValue)
    {
        return writeCount_Variable_->getDataValue(dataValue);
    }

    bool
    SessionDiagnosticsVariableType::set_ActualSessionTimeout_Variable(const OpcUaDataValue& dataValue)
    {
        return actualSessionTimeout_Variable_->setDataValue(dataValue);
    }

    bool
    SessionDiagnosticsVariableType::set_AddNodesCount_Variable(const OpcUaDataValue& dataValue)
    {
        return addNodesCount_Variable_->setDataValue(dataValue);
    }

    bool
    SessionDiagnosticsVariableType::set_AddReferencesCount_Variable(const OpcUaDataValue& dataValue)
    {
        return addReferencesCount_Variable_->setDataValue(dataValue);
    }

    bool
    SessionDiagnosticsVariableType::set_BrowseCount_Variable(const OpcUaDataValue& dataValue)
    {
        return browseCount_Variable_->setDataValue(dataValue);
    }

    bool
    SessionDiagnosticsVariableType::set_BrowseNextCount_Variable(const OpcUaDataValue& dataValue)
    {
        return browseNextCount_Variable_->setDataValue(dataValue);
    }

    bool
    SessionDiagnosticsVariableType::set_CallCount_Variable(const OpcUaDataValue& dataValue)
    {
        return callCount_Variable_->setDataValue(dataValue);
    }

    bool
    SessionDiagnosticsVariableType::set_ClientConnectionTime_Variable(const OpcUaDataValue& dataValue)
    {
        return clientConnectionTime_Variable_->setDataValue(dataValue);
    }

    bool
    SessionDiagnosticsVariableType::set_ClientDescription_Variable(const OpcUaDataValue& dataValue)
    {
        return clientDescription_Variable_->setDataValue(dataValue);
    }

    bool
    SessionDiagnosticsVariableType::set_ClientLastContactTime_Variable(const OpcUaDataValue& dataValue)
    {
        return clientLastContactTime_Variable_->setDataValue(dataValue);
    }

    bool
    SessionDiagnosticsVariableType::set_CreateMonitoredItemsCount_Variable(const OpcUaDataValue& dataValue)
    {
        return createMonitoredItemsCount_Variable_->setDataValue(dataValue);
    }

    bool
    SessionDiagnosticsVariableType::set_CreateSubscriptionCount_Variable(const OpcUaDataValue& dataValue)
    {
        return createSubscriptionCount_Variable_->setDataValue(dataValue);
    }

    bool
    SessionDiagnosticsVariableType::set_CurrentMonitoredItemsCount_Variable(const OpcUaDataValue& dataValue)
    {
        return currentMonitoredItemsCount_Variable_->setDataValue(dataValue);
    }

    bool
    SessionDiagnosticsVariableType::set_CurrentPublishRequestsInQueue_Variable(const OpcUaDataValue& dataValue)
    {
        return currentPublishRequestsInQueue_Variable_->setDataValue(dataValue);
    }

    bool
    SessionDiagnosticsVariableType::set_CurrentSubscriptionsCount_Variable(const OpcUaDataValue& dataValue)
    {
        return currentSubscriptionsCount_Variable_->setDataValue(dataValue);
    }

    bool
    SessionDiagnosticsVariableType::set_DeleteMonitoredItemsCount_Variable(const OpcUaDataValue& dataValue)
    {
        return deleteMonitoredItemsCount_Variable_->setDataValue(dataValue);
    }

    bool
    SessionDiagnosticsVariableType::set_DeleteNodesCount_Variable(const OpcUaDataValue& dataValue)
    {
        return deleteNodesCount_Variable_->setDataValue(dataValue);
    }

    bool
    SessionDiagnosticsVariableType::set_DeleteReferencesCount_Variable(const OpcUaDataValue& dataValue)
    {
        return deleteReferencesCount_Variable_->setDataValue(dataValue);
    }

    bool
    SessionDiagnosticsVariableType::set_DeleteSubscriptionsCount_Variable(const OpcUaDataValue& dataValue)
    {
        return deleteSubscriptionsCount_Variable_->setDataValue(dataValue);
    }

    bool
    SessionDiagnosticsVariableType::set_EndpointUrl_Variable(const OpcUaDataValue& dataValue)
    {
        return endpointUrl_Variable_->setDataValue(dataValue);
    }

    bool
    SessionDiagnosticsVariableType::set_HistoryReadCount_Variable(const OpcUaDataValue& dataValue)
    {
        return historyReadCount_Variable_->setDataValue(dataValue);
    }

    bool
    SessionDiagnosticsVariableType::set_HistoryUpdateCount_Variable(const OpcUaDataValue& dataValue)
    {
        return historyUpdateCount_Variable_->setDataValue(dataValue);
    }

    bool
    SessionDiagnosticsVariableType::set_LocaleIds_Variable(const OpcUaDataValue& dataValue)
    {
        return localeIds_Variable_->setDataValue(dataValue);
    }

    bool
    SessionDiagnosticsVariableType::set_MaxResponseMessageSize_Variable(const OpcUaDataValue& dataValue)
    {
        return maxResponseMessageSize_Variable_->setDataValue(dataValue);
    }

    bool
    SessionDiagnosticsVariableType::set_ModifyMonitoredItemsCount_Variable(const OpcUaDataValue& dataValue)
    {
        return modifyMonitoredItemsCount_Variable_->setDataValue(dataValue);
    }

    bool
    SessionDiagnosticsVariableType::set_ModifySubscriptionCount_Variable(const OpcUaDataValue& dataValue)
    {
        return modifySubscriptionCount_Variable_->setDataValue(dataValue);
    }

    bool
    SessionDiagnosticsVariableType::set_PublishCount_Variable(const OpcUaDataValue& dataValue)
    {
        return publishCount_Variable_->setDataValue(dataValue);
    }

    bool
    SessionDiagnosticsVariableType::set_QueryFirstCount_Variable(const OpcUaDataValue& dataValue)
    {
        return queryFirstCount_Variable_->setDataValue(dataValue);
    }

    bool
    SessionDiagnosticsVariableType::set_QueryNextCount_Variable(const OpcUaDataValue& dataValue)
    {
        return queryNextCount_Variable_->setDataValue(dataValue);
    }

    bool
    SessionDiagnosticsVariableType::set_ReadCount_Variable(const OpcUaDataValue& dataValue)
    {
        return readCount_Variable_->setDataValue(dataValue);
    }

    bool
    SessionDiagnosticsVariableType::set_RegisterNodesCount_Variable(const OpcUaDataValue& dataValue)
    {
        return registerNodesCount_Variable_->setDataValue(dataValue);
    }

    bool
    SessionDiagnosticsVariableType::set_RepublishCount_Variable(const OpcUaDataValue& dataValue)
    {
        return republishCount_Variable_->setDataValue(dataValue);
    }

    bool
    SessionDiagnosticsVariableType::set_ServerUri_Variable(const OpcUaDataValue& dataValue)
    {
        return serverUri_Variable_->setDataValue(dataValue);
    }

    bool
    SessionDiagnosticsVariableType::set_SessionId_Variable(const OpcUaDataValue& dataValue)
    {
        return sessionId_Variable_->setDataValue(dataValue);
    }

    bool
    SessionDiagnosticsVariableType::set_SessionName_Variable(const OpcUaDataValue& dataValue)
    {
        return sessionName_Variable_->setDataValue(dataValue);
    }

    bool
    SessionDiagnosticsVariableType::set_SetMonitoringModeCount_Variable(const OpcUaDataValue& dataValue)
    {
        return setMonitoringModeCount_Variable_->setDataValue(dataValue);
    }

    bool
    SessionDiagnosticsVariableType::set_SetPublishingModeCount_Variable(const OpcUaDataValue& dataValue)
    {
        return setPublishingModeCount_Variable_->setDataValue(dataValue);
    }

    bool
    SessionDiagnosticsVariableType::set_SetTriggeringCount_Variable(const OpcUaDataValue& dataValue)
    {
        return setTriggeringCount_Variable_->setDataValue(dataValue);
    }

    bool
    SessionDiagnosticsVariableType::set_TotalRequestCount_Variable(const OpcUaDataValue& dataValue)
    {
        return totalRequestCount_Variable_->setDataValue(dataValue);
    }

    bool
    SessionDiagnosticsVariableType::set_TransferSubscriptionsCount_Variable(const OpcUaDataValue& dataValue)
    {
        return transferSubscriptionsCount_Variable_->setDataValue(dataValue);
    }

    bool
    SessionDiagnosticsVariableType::set_TranslateBrowsePathsToNodeIdsCount_Variable(const OpcUaDataValue& dataValue)
    {
        return translateBrowsePathsToNodeIdsCount_Variable_->setDataValue(dataValue);
    }

    bool
    SessionDiagnosticsVariableType::set_UnauthorizedRequestCount_Variable(const OpcUaDataValue& dataValue)
    {
        return unauthorizedRequestCount_Variable_->setDataValue(dataValue);
    }

    bool
    SessionDiagnosticsVariableType::set_UnregisterNodesCount_Variable(const OpcUaDataValue& dataValue)
    {
        return unregisterNodesCount_Variable_->setDataValue(dataValue);
    }

    bool
    SessionDiagnosticsVariableType::set_Variable(const OpcUaDataValue& dataValue)
    {
        return variable_->setDataValue(dataValue);
    }

    bool
    SessionDiagnosticsVariableType::set_WriteCount_Variable(const OpcUaDataValue& dataValue)
    {
        return writeCount_Variable_->setDataValue(dataValue);
    }

}
