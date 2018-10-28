/*
    VariableTypeClass: ServerDiagnosticsSummaryType

    Generated Source Code - please do not change this source code

    VariableTypeCodeGenerator Version:
        OpcUaStackCore - 3.0.1

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackServer/StandardVariableType/ServerDiagnosticsSummaryType.h"

namespace OpcUaStackServer
{
    
    ServerDiagnosticsSummaryType::ServerDiagnosticsSummaryType(void)
    : BaseDataVariableType()
    , namespaceName_("http://opcfoundation.org/UA/")
    , namespaceIndex_(0)
    , serverViewCount_(constructSPtr<ServerVariable>("ServerViewCount"))
    , currentSessionCount_(constructSPtr<ServerVariable>("CurrentSessionCount"))
    , cumulatedSessionCount_(constructSPtr<ServerVariable>("CumulatedSessionCount"))
    , securityRejectedSessionCount_(constructSPtr<ServerVariable>("SecurityRejectedSessionCount"))
    , rejectedSessionCount_(constructSPtr<ServerVariable>("RejectedSessionCount"))
    , sessionTimeoutCount_(constructSPtr<ServerVariable>("SessionTimeoutCount"))
    , sessionAbortCount_(constructSPtr<ServerVariable>("SessionAbortCount"))
    , publishingIntervalCount_(constructSPtr<ServerVariable>("PublishingIntervalCount"))
    , currentSubscriptionCount_(constructSPtr<ServerVariable>("CurrentSubscriptionCount"))
    , cumulatedSubscriptionCount_(constructSPtr<ServerVariable>("CumulatedSubscriptionCount"))
    , securityRejectedRequestsCount_(constructSPtr<ServerVariable>("SecurityRejectedRequestsCount"))
    , rejectedRequestsCount_(constructSPtr<ServerVariable>("RejectedRequestsCount"))
    {
        variableTypeNamespace(namespaceName_);
        variableType(OpcUaNodeId(2150));
        serverVariables().registerServerVariable(serverViewCount_);
        serverVariables().registerServerVariable(currentSessionCount_);
        serverVariables().registerServerVariable(cumulatedSessionCount_);
        serverVariables().registerServerVariable(securityRejectedSessionCount_);
        serverVariables().registerServerVariable(rejectedSessionCount_);
        serverVariables().registerServerVariable(sessionTimeoutCount_);
        serverVariables().registerServerVariable(sessionAbortCount_);
        serverVariables().registerServerVariable(publishingIntervalCount_);
        serverVariables().registerServerVariable(currentSubscriptionCount_);
        serverVariables().registerServerVariable(cumulatedSubscriptionCount_);
        serverVariables().registerServerVariable(securityRejectedRequestsCount_);
        serverVariables().registerServerVariable(rejectedRequestsCount_);
    }
    
    ServerDiagnosticsSummaryType::~ServerDiagnosticsSummaryType(void)
    {
    }
    
    bool
    ServerDiagnosticsSummaryType::linkInstanceWithModel(const OpcUaNodeId& nodeId)
    {
        if (!getNamespaceIndexFromNamespaceName(namespaceName_, namespaceIndex_)) return false;
        serverViewCount_->addBrowsePath(nodeId, OpcUaQualifiedName("ServerViewCount", namespaceIndex_));
        currentSessionCount_->addBrowsePath(nodeId, OpcUaQualifiedName("CurrentSessionCount", namespaceIndex_));
        cumulatedSessionCount_->addBrowsePath(nodeId, OpcUaQualifiedName("CumulatedSessionCount", namespaceIndex_));
        securityRejectedSessionCount_->addBrowsePath(nodeId, OpcUaQualifiedName("SecurityRejectedSessionCount", namespaceIndex_));
        rejectedSessionCount_->addBrowsePath(nodeId, OpcUaQualifiedName("RejectedSessionCount", namespaceIndex_));
        sessionTimeoutCount_->addBrowsePath(nodeId, OpcUaQualifiedName("SessionTimeoutCount", namespaceIndex_));
        sessionAbortCount_->addBrowsePath(nodeId, OpcUaQualifiedName("SessionAbortCount", namespaceIndex_));
        publishingIntervalCount_->addBrowsePath(nodeId, OpcUaQualifiedName("PublishingIntervalCount", namespaceIndex_));
        currentSubscriptionCount_->addBrowsePath(nodeId, OpcUaQualifiedName("CurrentSubscriptionCount", namespaceIndex_));
        cumulatedSubscriptionCount_->addBrowsePath(nodeId, OpcUaQualifiedName("CumulatedSubscriptionCount", namespaceIndex_));
        securityRejectedRequestsCount_->addBrowsePath(nodeId, OpcUaQualifiedName("SecurityRejectedRequestsCount", namespaceIndex_));
        rejectedRequestsCount_->addBrowsePath(nodeId, OpcUaQualifiedName("RejectedRequestsCount", namespaceIndex_));
        BaseDataVariableType::linkInstanceWithModel(nodeId);
    }
    
    BaseNodeClass::SPtr
    ServerDiagnosticsSummaryType::serverViewCount(void)
    {
        return serverViewCount_->baseNode().lock();
    }
    
    bool
    ServerDiagnosticsSummaryType::setServerViewCount(const OpcUaDataValue& dataValue)
    {
        return serverViewCount_->setDataValue(dataValue);
    }
    
    bool
    ServerDiagnosticsSummaryType::getServerViewCount(OpcUaDataValue& dataValue)
    {
        return serverViewCount_->getDataValue(dataValue);
    }
    
    void
    ServerDiagnosticsSummaryType::setUpdateCallbackServerViewCount(Callback::SPtr& callback)
    {
        serverViewCount_->callback(callback);
    }
    
    BaseNodeClass::SPtr
    ServerDiagnosticsSummaryType::currentSessionCount(void)
    {
        return currentSessionCount_->baseNode().lock();
    }
    
    bool
    ServerDiagnosticsSummaryType::setCurrentSessionCount(const OpcUaDataValue& dataValue)
    {
        return currentSessionCount_->setDataValue(dataValue);
    }
    
    bool
    ServerDiagnosticsSummaryType::getCurrentSessionCount(OpcUaDataValue& dataValue)
    {
        return currentSessionCount_->getDataValue(dataValue);
    }
    
    void
    ServerDiagnosticsSummaryType::setUpdateCallbackCurrentSessionCount(Callback::SPtr& callback)
    {
        currentSessionCount_->callback(callback);
    }
    
    BaseNodeClass::SPtr
    ServerDiagnosticsSummaryType::cumulatedSessionCount(void)
    {
        return cumulatedSessionCount_->baseNode().lock();
    }
    
    bool
    ServerDiagnosticsSummaryType::setCumulatedSessionCount(const OpcUaDataValue& dataValue)
    {
        return cumulatedSessionCount_->setDataValue(dataValue);
    }
    
    bool
    ServerDiagnosticsSummaryType::getCumulatedSessionCount(OpcUaDataValue& dataValue)
    {
        return cumulatedSessionCount_->getDataValue(dataValue);
    }
    
    void
    ServerDiagnosticsSummaryType::setUpdateCallbackCumulatedSessionCount(Callback::SPtr& callback)
    {
        cumulatedSessionCount_->callback(callback);
    }
    
    BaseNodeClass::SPtr
    ServerDiagnosticsSummaryType::securityRejectedSessionCount(void)
    {
        return securityRejectedSessionCount_->baseNode().lock();
    }
    
    bool
    ServerDiagnosticsSummaryType::setSecurityRejectedSessionCount(const OpcUaDataValue& dataValue)
    {
        return securityRejectedSessionCount_->setDataValue(dataValue);
    }
    
    bool
    ServerDiagnosticsSummaryType::getSecurityRejectedSessionCount(OpcUaDataValue& dataValue)
    {
        return securityRejectedSessionCount_->getDataValue(dataValue);
    }
    
    void
    ServerDiagnosticsSummaryType::setUpdateCallbackSecurityRejectedSessionCount(Callback::SPtr& callback)
    {
        securityRejectedSessionCount_->callback(callback);
    }
    
    BaseNodeClass::SPtr
    ServerDiagnosticsSummaryType::rejectedSessionCount(void)
    {
        return rejectedSessionCount_->baseNode().lock();
    }
    
    bool
    ServerDiagnosticsSummaryType::setRejectedSessionCount(const OpcUaDataValue& dataValue)
    {
        return rejectedSessionCount_->setDataValue(dataValue);
    }
    
    bool
    ServerDiagnosticsSummaryType::getRejectedSessionCount(OpcUaDataValue& dataValue)
    {
        return rejectedSessionCount_->getDataValue(dataValue);
    }
    
    void
    ServerDiagnosticsSummaryType::setUpdateCallbackRejectedSessionCount(Callback::SPtr& callback)
    {
        rejectedSessionCount_->callback(callback);
    }
    
    BaseNodeClass::SPtr
    ServerDiagnosticsSummaryType::sessionTimeoutCount(void)
    {
        return sessionTimeoutCount_->baseNode().lock();
    }
    
    bool
    ServerDiagnosticsSummaryType::setSessionTimeoutCount(const OpcUaDataValue& dataValue)
    {
        return sessionTimeoutCount_->setDataValue(dataValue);
    }
    
    bool
    ServerDiagnosticsSummaryType::getSessionTimeoutCount(OpcUaDataValue& dataValue)
    {
        return sessionTimeoutCount_->getDataValue(dataValue);
    }
    
    void
    ServerDiagnosticsSummaryType::setUpdateCallbackSessionTimeoutCount(Callback::SPtr& callback)
    {
        sessionTimeoutCount_->callback(callback);
    }
    
    BaseNodeClass::SPtr
    ServerDiagnosticsSummaryType::sessionAbortCount(void)
    {
        return sessionAbortCount_->baseNode().lock();
    }
    
    bool
    ServerDiagnosticsSummaryType::setSessionAbortCount(const OpcUaDataValue& dataValue)
    {
        return sessionAbortCount_->setDataValue(dataValue);
    }
    
    bool
    ServerDiagnosticsSummaryType::getSessionAbortCount(OpcUaDataValue& dataValue)
    {
        return sessionAbortCount_->getDataValue(dataValue);
    }
    
    void
    ServerDiagnosticsSummaryType::setUpdateCallbackSessionAbortCount(Callback::SPtr& callback)
    {
        sessionAbortCount_->callback(callback);
    }
    
    BaseNodeClass::SPtr
    ServerDiagnosticsSummaryType::publishingIntervalCount(void)
    {
        return publishingIntervalCount_->baseNode().lock();
    }
    
    bool
    ServerDiagnosticsSummaryType::setPublishingIntervalCount(const OpcUaDataValue& dataValue)
    {
        return publishingIntervalCount_->setDataValue(dataValue);
    }
    
    bool
    ServerDiagnosticsSummaryType::getPublishingIntervalCount(OpcUaDataValue& dataValue)
    {
        return publishingIntervalCount_->getDataValue(dataValue);
    }
    
    void
    ServerDiagnosticsSummaryType::setUpdateCallbackPublishingIntervalCount(Callback::SPtr& callback)
    {
        publishingIntervalCount_->callback(callback);
    }
    
    BaseNodeClass::SPtr
    ServerDiagnosticsSummaryType::currentSubscriptionCount(void)
    {
        return currentSubscriptionCount_->baseNode().lock();
    }
    
    bool
    ServerDiagnosticsSummaryType::setCurrentSubscriptionCount(const OpcUaDataValue& dataValue)
    {
        return currentSubscriptionCount_->setDataValue(dataValue);
    }
    
    bool
    ServerDiagnosticsSummaryType::getCurrentSubscriptionCount(OpcUaDataValue& dataValue)
    {
        return currentSubscriptionCount_->getDataValue(dataValue);
    }
    
    void
    ServerDiagnosticsSummaryType::setUpdateCallbackCurrentSubscriptionCount(Callback::SPtr& callback)
    {
        currentSubscriptionCount_->callback(callback);
    }
    
    BaseNodeClass::SPtr
    ServerDiagnosticsSummaryType::cumulatedSubscriptionCount(void)
    {
        return cumulatedSubscriptionCount_->baseNode().lock();
    }
    
    bool
    ServerDiagnosticsSummaryType::setCumulatedSubscriptionCount(const OpcUaDataValue& dataValue)
    {
        return cumulatedSubscriptionCount_->setDataValue(dataValue);
    }
    
    bool
    ServerDiagnosticsSummaryType::getCumulatedSubscriptionCount(OpcUaDataValue& dataValue)
    {
        return cumulatedSubscriptionCount_->getDataValue(dataValue);
    }
    
    void
    ServerDiagnosticsSummaryType::setUpdateCallbackCumulatedSubscriptionCount(Callback::SPtr& callback)
    {
        cumulatedSubscriptionCount_->callback(callback);
    }
    
    BaseNodeClass::SPtr
    ServerDiagnosticsSummaryType::securityRejectedRequestsCount(void)
    {
        return securityRejectedRequestsCount_->baseNode().lock();
    }
    
    bool
    ServerDiagnosticsSummaryType::setSecurityRejectedRequestsCount(const OpcUaDataValue& dataValue)
    {
        return securityRejectedRequestsCount_->setDataValue(dataValue);
    }
    
    bool
    ServerDiagnosticsSummaryType::getSecurityRejectedRequestsCount(OpcUaDataValue& dataValue)
    {
        return securityRejectedRequestsCount_->getDataValue(dataValue);
    }
    
    void
    ServerDiagnosticsSummaryType::setUpdateCallbackSecurityRejectedRequestsCount(Callback::SPtr& callback)
    {
        securityRejectedRequestsCount_->callback(callback);
    }
    
    BaseNodeClass::SPtr
    ServerDiagnosticsSummaryType::rejectedRequestsCount(void)
    {
        return rejectedRequestsCount_->baseNode().lock();
    }
    
    bool
    ServerDiagnosticsSummaryType::setRejectedRequestsCount(const OpcUaDataValue& dataValue)
    {
        return rejectedRequestsCount_->setDataValue(dataValue);
    }
    
    bool
    ServerDiagnosticsSummaryType::getRejectedRequestsCount(OpcUaDataValue& dataValue)
    {
        return rejectedRequestsCount_->getDataValue(dataValue);
    }
    
    void
    ServerDiagnosticsSummaryType::setUpdateCallbackRejectedRequestsCount(Callback::SPtr& callback)
    {
        rejectedRequestsCount_->callback(callback);
    }

}
