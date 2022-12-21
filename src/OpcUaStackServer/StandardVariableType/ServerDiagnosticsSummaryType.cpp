/*
    VariableTypeClass: ServerDiagnosticsSummaryType

    Generated Source Code - please do not change this source code

    VariableTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackServer/StandardVariableType/ServerDiagnosticsSummaryType.h"
using namespace OpcUaStackCore;

namespace OpcUaStackServer
{
    
    ServerDiagnosticsSummaryType::ServerDiagnosticsSummaryType(void)
    : VariableBase()
    , cumulatedSessionCount_Variable_(boost::make_shared<ServerVariable>("CumulatedSessionCount_Variable"))
    , cumulatedSubscriptionCount_Variable_(boost::make_shared<ServerVariable>("CumulatedSubscriptionCount_Variable"))
    , currentSessionCount_Variable_(boost::make_shared<ServerVariable>("CurrentSessionCount_Variable"))
    , currentSubscriptionCount_Variable_(boost::make_shared<ServerVariable>("CurrentSubscriptionCount_Variable"))
    , publishingIntervalCount_Variable_(boost::make_shared<ServerVariable>("PublishingIntervalCount_Variable"))
    , rejectedRequestsCount_Variable_(boost::make_shared<ServerVariable>("RejectedRequestsCount_Variable"))
    , rejectedSessionCount_Variable_(boost::make_shared<ServerVariable>("RejectedSessionCount_Variable"))
    , securityRejectedRequestsCount_Variable_(boost::make_shared<ServerVariable>("SecurityRejectedRequestsCount_Variable"))
    , securityRejectedSessionCount_Variable_(boost::make_shared<ServerVariable>("SecurityRejectedSessionCount_Variable"))
    , serverViewCount_Variable_(boost::make_shared<ServerVariable>("ServerViewCount_Variable"))
    , sessionAbortCount_Variable_(boost::make_shared<ServerVariable>("SessionAbortCount_Variable"))
    , sessionTimeoutCount_Variable_(boost::make_shared<ServerVariable>("SessionTimeoutCount_Variable"))
    , variable_(boost::make_shared<ServerVariable>("Variable"))
    {
        variableTypeNamespaceName("http://opcfoundation.org/UA/");
        variableTypeNodeId((OpcUaUInt32)2150);
        setServerVariable(cumulatedSessionCount_Variable_);
        setServerVariable(cumulatedSubscriptionCount_Variable_);
        setServerVariable(currentSessionCount_Variable_);
        setServerVariable(currentSubscriptionCount_Variable_);
        setServerVariable(publishingIntervalCount_Variable_);
        setServerVariable(rejectedRequestsCount_Variable_);
        setServerVariable(rejectedSessionCount_Variable_);
        setServerVariable(securityRejectedRequestsCount_Variable_);
        setServerVariable(securityRejectedSessionCount_Variable_);
        setServerVariable(serverViewCount_Variable_);
        setServerVariable(sessionAbortCount_Variable_);
        setServerVariable(sessionTimeoutCount_Variable_);
        setServerVariable(variable_);
    }
    
    ServerDiagnosticsSummaryType::ServerDiagnosticsSummaryType(const ServerDiagnosticsSummaryType& value)
    : VariableBase()
    , cumulatedSessionCount_Variable_(boost::make_shared<ServerVariable>("CumulatedSessionCount_Variable"))
    , cumulatedSubscriptionCount_Variable_(boost::make_shared<ServerVariable>("CumulatedSubscriptionCount_Variable"))
    , currentSessionCount_Variable_(boost::make_shared<ServerVariable>("CurrentSessionCount_Variable"))
    , currentSubscriptionCount_Variable_(boost::make_shared<ServerVariable>("CurrentSubscriptionCount_Variable"))
    , publishingIntervalCount_Variable_(boost::make_shared<ServerVariable>("PublishingIntervalCount_Variable"))
    , rejectedRequestsCount_Variable_(boost::make_shared<ServerVariable>("RejectedRequestsCount_Variable"))
    , rejectedSessionCount_Variable_(boost::make_shared<ServerVariable>("RejectedSessionCount_Variable"))
    , securityRejectedRequestsCount_Variable_(boost::make_shared<ServerVariable>("SecurityRejectedRequestsCount_Variable"))
    , securityRejectedSessionCount_Variable_(boost::make_shared<ServerVariable>("SecurityRejectedSessionCount_Variable"))
    , serverViewCount_Variable_(boost::make_shared<ServerVariable>("ServerViewCount_Variable"))
    , sessionAbortCount_Variable_(boost::make_shared<ServerVariable>("SessionAbortCount_Variable"))
    , sessionTimeoutCount_Variable_(boost::make_shared<ServerVariable>("SessionTimeoutCount_Variable"))
    , variable_(boost::make_shared<ServerVariable>("Variable"))
    {
        variableTypeNamespaceName("http://opcfoundation.org/UA/");
        variableTypeNodeId((OpcUaUInt32)2150);
        setServerVariable(cumulatedSessionCount_Variable_);
        setServerVariable(cumulatedSubscriptionCount_Variable_);
        setServerVariable(currentSessionCount_Variable_);
        setServerVariable(currentSubscriptionCount_Variable_);
        setServerVariable(publishingIntervalCount_Variable_);
        setServerVariable(rejectedRequestsCount_Variable_);
        setServerVariable(rejectedSessionCount_Variable_);
        setServerVariable(securityRejectedRequestsCount_Variable_);
        setServerVariable(securityRejectedSessionCount_Variable_);
        setServerVariable(serverViewCount_Variable_);
        setServerVariable(sessionAbortCount_Variable_);
        setServerVariable(sessionTimeoutCount_Variable_);
        setServerVariable(variable_);
    }
    
    ServerDiagnosticsSummaryType::~ServerDiagnosticsSummaryType(void)
    {
    }

    ServerVariable::SPtr&
    ServerDiagnosticsSummaryType::cumulatedSessionCount_Variable(void)
    {
        return cumulatedSessionCount_Variable_;
    }

    ServerVariable::SPtr&
    ServerDiagnosticsSummaryType::cumulatedSubscriptionCount_Variable(void)
    {
        return cumulatedSubscriptionCount_Variable_;
    }

    ServerVariable::SPtr&
    ServerDiagnosticsSummaryType::currentSessionCount_Variable(void)
    {
        return currentSessionCount_Variable_;
    }

    ServerVariable::SPtr&
    ServerDiagnosticsSummaryType::currentSubscriptionCount_Variable(void)
    {
        return currentSubscriptionCount_Variable_;
    }

    ServerVariable::SPtr&
    ServerDiagnosticsSummaryType::publishingIntervalCount_Variable(void)
    {
        return publishingIntervalCount_Variable_;
    }

    ServerVariable::SPtr&
    ServerDiagnosticsSummaryType::rejectedRequestsCount_Variable(void)
    {
        return rejectedRequestsCount_Variable_;
    }

    ServerVariable::SPtr&
    ServerDiagnosticsSummaryType::rejectedSessionCount_Variable(void)
    {
        return rejectedSessionCount_Variable_;
    }

    ServerVariable::SPtr&
    ServerDiagnosticsSummaryType::securityRejectedRequestsCount_Variable(void)
    {
        return securityRejectedRequestsCount_Variable_;
    }

    ServerVariable::SPtr&
    ServerDiagnosticsSummaryType::securityRejectedSessionCount_Variable(void)
    {
        return securityRejectedSessionCount_Variable_;
    }

    ServerVariable::SPtr&
    ServerDiagnosticsSummaryType::serverViewCount_Variable(void)
    {
        return serverViewCount_Variable_;
    }

    ServerVariable::SPtr&
    ServerDiagnosticsSummaryType::sessionAbortCount_Variable(void)
    {
        return sessionAbortCount_Variable_;
    }

    ServerVariable::SPtr&
    ServerDiagnosticsSummaryType::sessionTimeoutCount_Variable(void)
    {
        return sessionTimeoutCount_Variable_;
    }

    ServerVariable::SPtr&
    ServerDiagnosticsSummaryType::variable(void)
    {
        return variable_;
    }

    void
    ServerDiagnosticsSummaryType::cumulatedSessionCount_Variable(ServerVariable::SPtr& serverVariable)
    {
        cumulatedSessionCount_Variable_ = serverVariable;
    }

    void
    ServerDiagnosticsSummaryType::cumulatedSubscriptionCount_Variable(ServerVariable::SPtr& serverVariable)
    {
        cumulatedSubscriptionCount_Variable_ = serverVariable;
    }

    void
    ServerDiagnosticsSummaryType::currentSessionCount_Variable(ServerVariable::SPtr& serverVariable)
    {
        currentSessionCount_Variable_ = serverVariable;
    }

    void
    ServerDiagnosticsSummaryType::currentSubscriptionCount_Variable(ServerVariable::SPtr& serverVariable)
    {
        currentSubscriptionCount_Variable_ = serverVariable;
    }

    void
    ServerDiagnosticsSummaryType::publishingIntervalCount_Variable(ServerVariable::SPtr& serverVariable)
    {
        publishingIntervalCount_Variable_ = serverVariable;
    }

    void
    ServerDiagnosticsSummaryType::rejectedRequestsCount_Variable(ServerVariable::SPtr& serverVariable)
    {
        rejectedRequestsCount_Variable_ = serverVariable;
    }

    void
    ServerDiagnosticsSummaryType::rejectedSessionCount_Variable(ServerVariable::SPtr& serverVariable)
    {
        rejectedSessionCount_Variable_ = serverVariable;
    }

    void
    ServerDiagnosticsSummaryType::securityRejectedRequestsCount_Variable(ServerVariable::SPtr& serverVariable)
    {
        securityRejectedRequestsCount_Variable_ = serverVariable;
    }

    void
    ServerDiagnosticsSummaryType::securityRejectedSessionCount_Variable(ServerVariable::SPtr& serverVariable)
    {
        securityRejectedSessionCount_Variable_ = serverVariable;
    }

    void
    ServerDiagnosticsSummaryType::serverViewCount_Variable(ServerVariable::SPtr& serverVariable)
    {
        serverViewCount_Variable_ = serverVariable;
    }

    void
    ServerDiagnosticsSummaryType::sessionAbortCount_Variable(ServerVariable::SPtr& serverVariable)
    {
        sessionAbortCount_Variable_ = serverVariable;
    }

    void
    ServerDiagnosticsSummaryType::sessionTimeoutCount_Variable(ServerVariable::SPtr& serverVariable)
    {
        sessionTimeoutCount_Variable_ = serverVariable;
    }

    void
    ServerDiagnosticsSummaryType::variable(ServerVariable::SPtr& serverVariable)
    {
        variable_ = serverVariable;
    }

    bool
    ServerDiagnosticsSummaryType::get_CumulatedSessionCount_Variable(OpcUaDataValue& dataValue)
    {
        return cumulatedSessionCount_Variable_->getDataValue(dataValue);
    }

    bool
    ServerDiagnosticsSummaryType::get_CumulatedSubscriptionCount_Variable(OpcUaDataValue& dataValue)
    {
        return cumulatedSubscriptionCount_Variable_->getDataValue(dataValue);
    }

    bool
    ServerDiagnosticsSummaryType::get_CurrentSessionCount_Variable(OpcUaDataValue& dataValue)
    {
        return currentSessionCount_Variable_->getDataValue(dataValue);
    }

    bool
    ServerDiagnosticsSummaryType::get_CurrentSubscriptionCount_Variable(OpcUaDataValue& dataValue)
    {
        return currentSubscriptionCount_Variable_->getDataValue(dataValue);
    }

    bool
    ServerDiagnosticsSummaryType::get_PublishingIntervalCount_Variable(OpcUaDataValue& dataValue)
    {
        return publishingIntervalCount_Variable_->getDataValue(dataValue);
    }

    bool
    ServerDiagnosticsSummaryType::get_RejectedRequestsCount_Variable(OpcUaDataValue& dataValue)
    {
        return rejectedRequestsCount_Variable_->getDataValue(dataValue);
    }

    bool
    ServerDiagnosticsSummaryType::get_RejectedSessionCount_Variable(OpcUaDataValue& dataValue)
    {
        return rejectedSessionCount_Variable_->getDataValue(dataValue);
    }

    bool
    ServerDiagnosticsSummaryType::get_SecurityRejectedRequestsCount_Variable(OpcUaDataValue& dataValue)
    {
        return securityRejectedRequestsCount_Variable_->getDataValue(dataValue);
    }

    bool
    ServerDiagnosticsSummaryType::get_SecurityRejectedSessionCount_Variable(OpcUaDataValue& dataValue)
    {
        return securityRejectedSessionCount_Variable_->getDataValue(dataValue);
    }

    bool
    ServerDiagnosticsSummaryType::get_ServerViewCount_Variable(OpcUaDataValue& dataValue)
    {
        return serverViewCount_Variable_->getDataValue(dataValue);
    }

    bool
    ServerDiagnosticsSummaryType::get_SessionAbortCount_Variable(OpcUaDataValue& dataValue)
    {
        return sessionAbortCount_Variable_->getDataValue(dataValue);
    }

    bool
    ServerDiagnosticsSummaryType::get_SessionTimeoutCount_Variable(OpcUaDataValue& dataValue)
    {
        return sessionTimeoutCount_Variable_->getDataValue(dataValue);
    }

    bool
    ServerDiagnosticsSummaryType::get_Variable(OpcUaDataValue& dataValue)
    {
        return variable_->getDataValue(dataValue);
    }

    bool
    ServerDiagnosticsSummaryType::set_CumulatedSessionCount_Variable(const OpcUaDataValue& dataValue)
    {
        return cumulatedSessionCount_Variable_->setDataValue(dataValue);
    }

    bool
    ServerDiagnosticsSummaryType::set_CumulatedSubscriptionCount_Variable(const OpcUaDataValue& dataValue)
    {
        return cumulatedSubscriptionCount_Variable_->setDataValue(dataValue);
    }

    bool
    ServerDiagnosticsSummaryType::set_CurrentSessionCount_Variable(const OpcUaDataValue& dataValue)
    {
        return currentSessionCount_Variable_->setDataValue(dataValue);
    }

    bool
    ServerDiagnosticsSummaryType::set_CurrentSubscriptionCount_Variable(const OpcUaDataValue& dataValue)
    {
        return currentSubscriptionCount_Variable_->setDataValue(dataValue);
    }

    bool
    ServerDiagnosticsSummaryType::set_PublishingIntervalCount_Variable(const OpcUaDataValue& dataValue)
    {
        return publishingIntervalCount_Variable_->setDataValue(dataValue);
    }

    bool
    ServerDiagnosticsSummaryType::set_RejectedRequestsCount_Variable(const OpcUaDataValue& dataValue)
    {
        return rejectedRequestsCount_Variable_->setDataValue(dataValue);
    }

    bool
    ServerDiagnosticsSummaryType::set_RejectedSessionCount_Variable(const OpcUaDataValue& dataValue)
    {
        return rejectedSessionCount_Variable_->setDataValue(dataValue);
    }

    bool
    ServerDiagnosticsSummaryType::set_SecurityRejectedRequestsCount_Variable(const OpcUaDataValue& dataValue)
    {
        return securityRejectedRequestsCount_Variable_->setDataValue(dataValue);
    }

    bool
    ServerDiagnosticsSummaryType::set_SecurityRejectedSessionCount_Variable(const OpcUaDataValue& dataValue)
    {
        return securityRejectedSessionCount_Variable_->setDataValue(dataValue);
    }

    bool
    ServerDiagnosticsSummaryType::set_ServerViewCount_Variable(const OpcUaDataValue& dataValue)
    {
        return serverViewCount_Variable_->setDataValue(dataValue);
    }

    bool
    ServerDiagnosticsSummaryType::set_SessionAbortCount_Variable(const OpcUaDataValue& dataValue)
    {
        return sessionAbortCount_Variable_->setDataValue(dataValue);
    }

    bool
    ServerDiagnosticsSummaryType::set_SessionTimeoutCount_Variable(const OpcUaDataValue& dataValue)
    {
        return sessionTimeoutCount_Variable_->setDataValue(dataValue);
    }

    bool
    ServerDiagnosticsSummaryType::set_Variable(const OpcUaDataValue& dataValue)
    {
        return variable_->setDataValue(dataValue);
    }

}
