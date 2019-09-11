/*
    VariableTypeClass: ServerDiagnosticsType

    Generated Source Code - please do not change this source code

    VariableTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackServer/StandardObjectType/ServerDiagnosticsType.h"

namespace OpcUaStackServer
{
    
    /**
     * The diagnostics information for a server.
     */
    ServerDiagnosticsType::ServerDiagnosticsType(void)
    : ObjectBase()
    , enabledFlag_Variable_(boost::make_shared<ServerVariable>("EnabledFlag_Variable"))
    , samplingIntervalDiagnosticsArray_Variable_(boost::make_shared<ServerVariable>("SamplingIntervalDiagnosticsArray_Variable"))
    , serverDiagnosticsSummary_CumulatedSessionCount_Variable_(boost::make_shared<ServerVariable>("ServerDiagnosticsSummary_CumulatedSessionCount_Variable"))
    , serverDiagnosticsSummary_CumulatedSubscriptionCount_Variable_(boost::make_shared<ServerVariable>("ServerDiagnosticsSummary_CumulatedSubscriptionCount_Variable"))
    , serverDiagnosticsSummary_CurrentSessionCount_Variable_(boost::make_shared<ServerVariable>("ServerDiagnosticsSummary_CurrentSessionCount_Variable"))
    , serverDiagnosticsSummary_CurrentSubscriptionCount_Variable_(boost::make_shared<ServerVariable>("ServerDiagnosticsSummary_CurrentSubscriptionCount_Variable"))
    , serverDiagnosticsSummary_PublishingIntervalCount_Variable_(boost::make_shared<ServerVariable>("ServerDiagnosticsSummary_PublishingIntervalCount_Variable"))
    , serverDiagnosticsSummary_RejectedRequestsCount_Variable_(boost::make_shared<ServerVariable>("ServerDiagnosticsSummary_RejectedRequestsCount_Variable"))
    , serverDiagnosticsSummary_RejectedSessionCount_Variable_(boost::make_shared<ServerVariable>("ServerDiagnosticsSummary_RejectedSessionCount_Variable"))
    , serverDiagnosticsSummary_SecurityRejectedRequestsCount_Variable_(boost::make_shared<ServerVariable>("ServerDiagnosticsSummary_SecurityRejectedRequestsCount_Variable"))
    , serverDiagnosticsSummary_SecurityRejectedSessionCount_Variable_(boost::make_shared<ServerVariable>("ServerDiagnosticsSummary_SecurityRejectedSessionCount_Variable"))
    , serverDiagnosticsSummary_ServerViewCount_Variable_(boost::make_shared<ServerVariable>("ServerDiagnosticsSummary_ServerViewCount_Variable"))
    , serverDiagnosticsSummary_SessionAbortCount_Variable_(boost::make_shared<ServerVariable>("ServerDiagnosticsSummary_SessionAbortCount_Variable"))
    , serverDiagnosticsSummary_SessionTimeoutCount_Variable_(boost::make_shared<ServerVariable>("ServerDiagnosticsSummary_SessionTimeoutCount_Variable"))
    , serverDiagnosticsSummary_Variable_(boost::make_shared<ServerVariable>("ServerDiagnosticsSummary_Variable"))
    , sessionsDiagnosticsSummary_SessionDiagnosticsArray_Variable_(boost::make_shared<ServerVariable>("SessionsDiagnosticsSummary_SessionDiagnosticsArray_Variable"))
    , sessionsDiagnosticsSummary_SessionSecurityDiagnosticsArray_Variable_(boost::make_shared<ServerVariable>("SessionsDiagnosticsSummary_SessionSecurityDiagnosticsArray_Variable"))
    , subscriptionDiagnosticsArray_Variable_(boost::make_shared<ServerVariable>("SubscriptionDiagnosticsArray_Variable"))
    {
        objectTypeNamespaceName("http://opcfoundation.org/UA/");
        objectTypeNodeId((OpcUaUInt32)2020);
        setServerVariable(enabledFlag_Variable_);
        setServerVariable(samplingIntervalDiagnosticsArray_Variable_);
        setServerVariable(serverDiagnosticsSummary_CumulatedSessionCount_Variable_);
        setServerVariable(serverDiagnosticsSummary_CumulatedSubscriptionCount_Variable_);
        setServerVariable(serverDiagnosticsSummary_CurrentSessionCount_Variable_);
        setServerVariable(serverDiagnosticsSummary_CurrentSubscriptionCount_Variable_);
        setServerVariable(serverDiagnosticsSummary_PublishingIntervalCount_Variable_);
        setServerVariable(serverDiagnosticsSummary_RejectedRequestsCount_Variable_);
        setServerVariable(serverDiagnosticsSummary_RejectedSessionCount_Variable_);
        setServerVariable(serverDiagnosticsSummary_SecurityRejectedRequestsCount_Variable_);
        setServerVariable(serverDiagnosticsSummary_SecurityRejectedSessionCount_Variable_);
        setServerVariable(serverDiagnosticsSummary_ServerViewCount_Variable_);
        setServerVariable(serverDiagnosticsSummary_SessionAbortCount_Variable_);
        setServerVariable(serverDiagnosticsSummary_SessionTimeoutCount_Variable_);
        setServerVariable(serverDiagnosticsSummary_Variable_);
        setServerVariable(sessionsDiagnosticsSummary_SessionDiagnosticsArray_Variable_);
        setServerVariable(sessionsDiagnosticsSummary_SessionSecurityDiagnosticsArray_Variable_);
        setServerVariable(subscriptionDiagnosticsArray_Variable_);
    }
    
    /**
     * The diagnostics information for a server.
     */
    ServerDiagnosticsType::ServerDiagnosticsType(const ServerDiagnosticsType& value)
    : ObjectBase()
    , enabledFlag_Variable_(boost::make_shared<ServerVariable>("EnabledFlag_Variable"))
    , samplingIntervalDiagnosticsArray_Variable_(boost::make_shared<ServerVariable>("SamplingIntervalDiagnosticsArray_Variable"))
    , serverDiagnosticsSummary_CumulatedSessionCount_Variable_(boost::make_shared<ServerVariable>("ServerDiagnosticsSummary_CumulatedSessionCount_Variable"))
    , serverDiagnosticsSummary_CumulatedSubscriptionCount_Variable_(boost::make_shared<ServerVariable>("ServerDiagnosticsSummary_CumulatedSubscriptionCount_Variable"))
    , serverDiagnosticsSummary_CurrentSessionCount_Variable_(boost::make_shared<ServerVariable>("ServerDiagnosticsSummary_CurrentSessionCount_Variable"))
    , serverDiagnosticsSummary_CurrentSubscriptionCount_Variable_(boost::make_shared<ServerVariable>("ServerDiagnosticsSummary_CurrentSubscriptionCount_Variable"))
    , serverDiagnosticsSummary_PublishingIntervalCount_Variable_(boost::make_shared<ServerVariable>("ServerDiagnosticsSummary_PublishingIntervalCount_Variable"))
    , serverDiagnosticsSummary_RejectedRequestsCount_Variable_(boost::make_shared<ServerVariable>("ServerDiagnosticsSummary_RejectedRequestsCount_Variable"))
    , serverDiagnosticsSummary_RejectedSessionCount_Variable_(boost::make_shared<ServerVariable>("ServerDiagnosticsSummary_RejectedSessionCount_Variable"))
    , serverDiagnosticsSummary_SecurityRejectedRequestsCount_Variable_(boost::make_shared<ServerVariable>("ServerDiagnosticsSummary_SecurityRejectedRequestsCount_Variable"))
    , serverDiagnosticsSummary_SecurityRejectedSessionCount_Variable_(boost::make_shared<ServerVariable>("ServerDiagnosticsSummary_SecurityRejectedSessionCount_Variable"))
    , serverDiagnosticsSummary_ServerViewCount_Variable_(boost::make_shared<ServerVariable>("ServerDiagnosticsSummary_ServerViewCount_Variable"))
    , serverDiagnosticsSummary_SessionAbortCount_Variable_(boost::make_shared<ServerVariable>("ServerDiagnosticsSummary_SessionAbortCount_Variable"))
    , serverDiagnosticsSummary_SessionTimeoutCount_Variable_(boost::make_shared<ServerVariable>("ServerDiagnosticsSummary_SessionTimeoutCount_Variable"))
    , serverDiagnosticsSummary_Variable_(boost::make_shared<ServerVariable>("ServerDiagnosticsSummary_Variable"))
    , sessionsDiagnosticsSummary_SessionDiagnosticsArray_Variable_(boost::make_shared<ServerVariable>("SessionsDiagnosticsSummary_SessionDiagnosticsArray_Variable"))
    , sessionsDiagnosticsSummary_SessionSecurityDiagnosticsArray_Variable_(boost::make_shared<ServerVariable>("SessionsDiagnosticsSummary_SessionSecurityDiagnosticsArray_Variable"))
    , subscriptionDiagnosticsArray_Variable_(boost::make_shared<ServerVariable>("SubscriptionDiagnosticsArray_Variable"))
    {
        objectTypeNamespaceName("http://opcfoundation.org/UA/");
        objectTypeNodeId((OpcUaUInt32)2020);
        setServerVariable(enabledFlag_Variable_);
        setServerVariable(samplingIntervalDiagnosticsArray_Variable_);
        setServerVariable(serverDiagnosticsSummary_CumulatedSessionCount_Variable_);
        setServerVariable(serverDiagnosticsSummary_CumulatedSubscriptionCount_Variable_);
        setServerVariable(serverDiagnosticsSummary_CurrentSessionCount_Variable_);
        setServerVariable(serverDiagnosticsSummary_CurrentSubscriptionCount_Variable_);
        setServerVariable(serverDiagnosticsSummary_PublishingIntervalCount_Variable_);
        setServerVariable(serverDiagnosticsSummary_RejectedRequestsCount_Variable_);
        setServerVariable(serverDiagnosticsSummary_RejectedSessionCount_Variable_);
        setServerVariable(serverDiagnosticsSummary_SecurityRejectedRequestsCount_Variable_);
        setServerVariable(serverDiagnosticsSummary_SecurityRejectedSessionCount_Variable_);
        setServerVariable(serverDiagnosticsSummary_ServerViewCount_Variable_);
        setServerVariable(serverDiagnosticsSummary_SessionAbortCount_Variable_);
        setServerVariable(serverDiagnosticsSummary_SessionTimeoutCount_Variable_);
        setServerVariable(serverDiagnosticsSummary_Variable_);
        setServerVariable(sessionsDiagnosticsSummary_SessionDiagnosticsArray_Variable_);
        setServerVariable(sessionsDiagnosticsSummary_SessionSecurityDiagnosticsArray_Variable_);
        setServerVariable(subscriptionDiagnosticsArray_Variable_);
    }
    
    ServerDiagnosticsType::~ServerDiagnosticsType(void)
    {
    }

    ServerVariable::SPtr&
    ServerDiagnosticsType::enabledFlag_Variable(void)
    {
        return enabledFlag_Variable_;
    }

    ServerVariable::SPtr&
    ServerDiagnosticsType::samplingIntervalDiagnosticsArray_Variable(void)
    {
        return samplingIntervalDiagnosticsArray_Variable_;
    }

    ServerVariable::SPtr&
    ServerDiagnosticsType::serverDiagnosticsSummary_CumulatedSessionCount_Variable(void)
    {
        return serverDiagnosticsSummary_CumulatedSessionCount_Variable_;
    }

    ServerVariable::SPtr&
    ServerDiagnosticsType::serverDiagnosticsSummary_CumulatedSubscriptionCount_Variable(void)
    {
        return serverDiagnosticsSummary_CumulatedSubscriptionCount_Variable_;
    }

    ServerVariable::SPtr&
    ServerDiagnosticsType::serverDiagnosticsSummary_CurrentSessionCount_Variable(void)
    {
        return serverDiagnosticsSummary_CurrentSessionCount_Variable_;
    }

    ServerVariable::SPtr&
    ServerDiagnosticsType::serverDiagnosticsSummary_CurrentSubscriptionCount_Variable(void)
    {
        return serverDiagnosticsSummary_CurrentSubscriptionCount_Variable_;
    }

    ServerVariable::SPtr&
    ServerDiagnosticsType::serverDiagnosticsSummary_PublishingIntervalCount_Variable(void)
    {
        return serverDiagnosticsSummary_PublishingIntervalCount_Variable_;
    }

    ServerVariable::SPtr&
    ServerDiagnosticsType::serverDiagnosticsSummary_RejectedRequestsCount_Variable(void)
    {
        return serverDiagnosticsSummary_RejectedRequestsCount_Variable_;
    }

    ServerVariable::SPtr&
    ServerDiagnosticsType::serverDiagnosticsSummary_RejectedSessionCount_Variable(void)
    {
        return serverDiagnosticsSummary_RejectedSessionCount_Variable_;
    }

    ServerVariable::SPtr&
    ServerDiagnosticsType::serverDiagnosticsSummary_SecurityRejectedRequestsCount_Variable(void)
    {
        return serverDiagnosticsSummary_SecurityRejectedRequestsCount_Variable_;
    }

    ServerVariable::SPtr&
    ServerDiagnosticsType::serverDiagnosticsSummary_SecurityRejectedSessionCount_Variable(void)
    {
        return serverDiagnosticsSummary_SecurityRejectedSessionCount_Variable_;
    }

    ServerVariable::SPtr&
    ServerDiagnosticsType::serverDiagnosticsSummary_ServerViewCount_Variable(void)
    {
        return serverDiagnosticsSummary_ServerViewCount_Variable_;
    }

    ServerVariable::SPtr&
    ServerDiagnosticsType::serverDiagnosticsSummary_SessionAbortCount_Variable(void)
    {
        return serverDiagnosticsSummary_SessionAbortCount_Variable_;
    }

    ServerVariable::SPtr&
    ServerDiagnosticsType::serverDiagnosticsSummary_SessionTimeoutCount_Variable(void)
    {
        return serverDiagnosticsSummary_SessionTimeoutCount_Variable_;
    }

    ServerVariable::SPtr&
    ServerDiagnosticsType::serverDiagnosticsSummary_Variable(void)
    {
        return serverDiagnosticsSummary_Variable_;
    }

    ServerVariable::SPtr&
    ServerDiagnosticsType::sessionsDiagnosticsSummary_SessionDiagnosticsArray_Variable(void)
    {
        return sessionsDiagnosticsSummary_SessionDiagnosticsArray_Variable_;
    }

    ServerVariable::SPtr&
    ServerDiagnosticsType::sessionsDiagnosticsSummary_SessionSecurityDiagnosticsArray_Variable(void)
    {
        return sessionsDiagnosticsSummary_SessionSecurityDiagnosticsArray_Variable_;
    }

    ServerVariable::SPtr&
    ServerDiagnosticsType::subscriptionDiagnosticsArray_Variable(void)
    {
        return subscriptionDiagnosticsArray_Variable_;
    }

    void
    ServerDiagnosticsType::enabledFlag_Variable(ServerVariable::SPtr& serverVariable)
    {
        enabledFlag_Variable_ = serverVariable;
    }

    void
    ServerDiagnosticsType::samplingIntervalDiagnosticsArray_Variable(ServerVariable::SPtr& serverVariable)
    {
        samplingIntervalDiagnosticsArray_Variable_ = serverVariable;
    }

    void
    ServerDiagnosticsType::serverDiagnosticsSummary_CumulatedSessionCount_Variable(ServerVariable::SPtr& serverVariable)
    {
        serverDiagnosticsSummary_CumulatedSessionCount_Variable_ = serverVariable;
    }

    void
    ServerDiagnosticsType::serverDiagnosticsSummary_CumulatedSubscriptionCount_Variable(ServerVariable::SPtr& serverVariable)
    {
        serverDiagnosticsSummary_CumulatedSubscriptionCount_Variable_ = serverVariable;
    }

    void
    ServerDiagnosticsType::serverDiagnosticsSummary_CurrentSessionCount_Variable(ServerVariable::SPtr& serverVariable)
    {
        serverDiagnosticsSummary_CurrentSessionCount_Variable_ = serverVariable;
    }

    void
    ServerDiagnosticsType::serverDiagnosticsSummary_CurrentSubscriptionCount_Variable(ServerVariable::SPtr& serverVariable)
    {
        serverDiagnosticsSummary_CurrentSubscriptionCount_Variable_ = serverVariable;
    }

    void
    ServerDiagnosticsType::serverDiagnosticsSummary_PublishingIntervalCount_Variable(ServerVariable::SPtr& serverVariable)
    {
        serverDiagnosticsSummary_PublishingIntervalCount_Variable_ = serverVariable;
    }

    void
    ServerDiagnosticsType::serverDiagnosticsSummary_RejectedRequestsCount_Variable(ServerVariable::SPtr& serverVariable)
    {
        serverDiagnosticsSummary_RejectedRequestsCount_Variable_ = serverVariable;
    }

    void
    ServerDiagnosticsType::serverDiagnosticsSummary_RejectedSessionCount_Variable(ServerVariable::SPtr& serverVariable)
    {
        serverDiagnosticsSummary_RejectedSessionCount_Variable_ = serverVariable;
    }

    void
    ServerDiagnosticsType::serverDiagnosticsSummary_SecurityRejectedRequestsCount_Variable(ServerVariable::SPtr& serverVariable)
    {
        serverDiagnosticsSummary_SecurityRejectedRequestsCount_Variable_ = serverVariable;
    }

    void
    ServerDiagnosticsType::serverDiagnosticsSummary_SecurityRejectedSessionCount_Variable(ServerVariable::SPtr& serverVariable)
    {
        serverDiagnosticsSummary_SecurityRejectedSessionCount_Variable_ = serverVariable;
    }

    void
    ServerDiagnosticsType::serverDiagnosticsSummary_ServerViewCount_Variable(ServerVariable::SPtr& serverVariable)
    {
        serverDiagnosticsSummary_ServerViewCount_Variable_ = serverVariable;
    }

    void
    ServerDiagnosticsType::serverDiagnosticsSummary_SessionAbortCount_Variable(ServerVariable::SPtr& serverVariable)
    {
        serverDiagnosticsSummary_SessionAbortCount_Variable_ = serverVariable;
    }

    void
    ServerDiagnosticsType::serverDiagnosticsSummary_SessionTimeoutCount_Variable(ServerVariable::SPtr& serverVariable)
    {
        serverDiagnosticsSummary_SessionTimeoutCount_Variable_ = serverVariable;
    }

    void
    ServerDiagnosticsType::serverDiagnosticsSummary_Variable(ServerVariable::SPtr& serverVariable)
    {
        serverDiagnosticsSummary_Variable_ = serverVariable;
    }

    void
    ServerDiagnosticsType::sessionsDiagnosticsSummary_SessionDiagnosticsArray_Variable(ServerVariable::SPtr& serverVariable)
    {
        sessionsDiagnosticsSummary_SessionDiagnosticsArray_Variable_ = serverVariable;
    }

    void
    ServerDiagnosticsType::sessionsDiagnosticsSummary_SessionSecurityDiagnosticsArray_Variable(ServerVariable::SPtr& serverVariable)
    {
        sessionsDiagnosticsSummary_SessionSecurityDiagnosticsArray_Variable_ = serverVariable;
    }

    void
    ServerDiagnosticsType::subscriptionDiagnosticsArray_Variable(ServerVariable::SPtr& serverVariable)
    {
        subscriptionDiagnosticsArray_Variable_ = serverVariable;
    }

    bool
    ServerDiagnosticsType::get_EnabledFlag_Variable(OpcUaDataValue& dataValue)
    {
        return enabledFlag_Variable_->getDataValue(dataValue);
    }

    bool
    ServerDiagnosticsType::get_SamplingIntervalDiagnosticsArray_Variable(OpcUaDataValue& dataValue)
    {
        return samplingIntervalDiagnosticsArray_Variable_->getDataValue(dataValue);
    }

    bool
    ServerDiagnosticsType::get_ServerDiagnosticsSummary_CumulatedSessionCount_Variable(OpcUaDataValue& dataValue)
    {
        return serverDiagnosticsSummary_CumulatedSessionCount_Variable_->getDataValue(dataValue);
    }

    bool
    ServerDiagnosticsType::get_ServerDiagnosticsSummary_CumulatedSubscriptionCount_Variable(OpcUaDataValue& dataValue)
    {
        return serverDiagnosticsSummary_CumulatedSubscriptionCount_Variable_->getDataValue(dataValue);
    }

    bool
    ServerDiagnosticsType::get_ServerDiagnosticsSummary_CurrentSessionCount_Variable(OpcUaDataValue& dataValue)
    {
        return serverDiagnosticsSummary_CurrentSessionCount_Variable_->getDataValue(dataValue);
    }

    bool
    ServerDiagnosticsType::get_ServerDiagnosticsSummary_CurrentSubscriptionCount_Variable(OpcUaDataValue& dataValue)
    {
        return serverDiagnosticsSummary_CurrentSubscriptionCount_Variable_->getDataValue(dataValue);
    }

    bool
    ServerDiagnosticsType::get_ServerDiagnosticsSummary_PublishingIntervalCount_Variable(OpcUaDataValue& dataValue)
    {
        return serverDiagnosticsSummary_PublishingIntervalCount_Variable_->getDataValue(dataValue);
    }

    bool
    ServerDiagnosticsType::get_ServerDiagnosticsSummary_RejectedRequestsCount_Variable(OpcUaDataValue& dataValue)
    {
        return serverDiagnosticsSummary_RejectedRequestsCount_Variable_->getDataValue(dataValue);
    }

    bool
    ServerDiagnosticsType::get_ServerDiagnosticsSummary_RejectedSessionCount_Variable(OpcUaDataValue& dataValue)
    {
        return serverDiagnosticsSummary_RejectedSessionCount_Variable_->getDataValue(dataValue);
    }

    bool
    ServerDiagnosticsType::get_ServerDiagnosticsSummary_SecurityRejectedRequestsCount_Variable(OpcUaDataValue& dataValue)
    {
        return serverDiagnosticsSummary_SecurityRejectedRequestsCount_Variable_->getDataValue(dataValue);
    }

    bool
    ServerDiagnosticsType::get_ServerDiagnosticsSummary_SecurityRejectedSessionCount_Variable(OpcUaDataValue& dataValue)
    {
        return serverDiagnosticsSummary_SecurityRejectedSessionCount_Variable_->getDataValue(dataValue);
    }

    bool
    ServerDiagnosticsType::get_ServerDiagnosticsSummary_ServerViewCount_Variable(OpcUaDataValue& dataValue)
    {
        return serverDiagnosticsSummary_ServerViewCount_Variable_->getDataValue(dataValue);
    }

    bool
    ServerDiagnosticsType::get_ServerDiagnosticsSummary_SessionAbortCount_Variable(OpcUaDataValue& dataValue)
    {
        return serverDiagnosticsSummary_SessionAbortCount_Variable_->getDataValue(dataValue);
    }

    bool
    ServerDiagnosticsType::get_ServerDiagnosticsSummary_SessionTimeoutCount_Variable(OpcUaDataValue& dataValue)
    {
        return serverDiagnosticsSummary_SessionTimeoutCount_Variable_->getDataValue(dataValue);
    }

    bool
    ServerDiagnosticsType::get_ServerDiagnosticsSummary_Variable(OpcUaDataValue& dataValue)
    {
        return serverDiagnosticsSummary_Variable_->getDataValue(dataValue);
    }

    bool
    ServerDiagnosticsType::get_SessionsDiagnosticsSummary_SessionDiagnosticsArray_Variable(OpcUaDataValue& dataValue)
    {
        return sessionsDiagnosticsSummary_SessionDiagnosticsArray_Variable_->getDataValue(dataValue);
    }

    bool
    ServerDiagnosticsType::get_SessionsDiagnosticsSummary_SessionSecurityDiagnosticsArray_Variable(OpcUaDataValue& dataValue)
    {
        return sessionsDiagnosticsSummary_SessionSecurityDiagnosticsArray_Variable_->getDataValue(dataValue);
    }

    bool
    ServerDiagnosticsType::get_SubscriptionDiagnosticsArray_Variable(OpcUaDataValue& dataValue)
    {
        return subscriptionDiagnosticsArray_Variable_->getDataValue(dataValue);
    }

    bool
    ServerDiagnosticsType::set_EnabledFlag_Variable(const OpcUaDataValue& dataValue)
    {
        return enabledFlag_Variable_->setDataValue(dataValue);
    }

    bool
    ServerDiagnosticsType::set_SamplingIntervalDiagnosticsArray_Variable(const OpcUaDataValue& dataValue)
    {
        return samplingIntervalDiagnosticsArray_Variable_->setDataValue(dataValue);
    }

    bool
    ServerDiagnosticsType::set_ServerDiagnosticsSummary_CumulatedSessionCount_Variable(const OpcUaDataValue& dataValue)
    {
        return serverDiagnosticsSummary_CumulatedSessionCount_Variable_->setDataValue(dataValue);
    }

    bool
    ServerDiagnosticsType::set_ServerDiagnosticsSummary_CumulatedSubscriptionCount_Variable(const OpcUaDataValue& dataValue)
    {
        return serverDiagnosticsSummary_CumulatedSubscriptionCount_Variable_->setDataValue(dataValue);
    }

    bool
    ServerDiagnosticsType::set_ServerDiagnosticsSummary_CurrentSessionCount_Variable(const OpcUaDataValue& dataValue)
    {
        return serverDiagnosticsSummary_CurrentSessionCount_Variable_->setDataValue(dataValue);
    }

    bool
    ServerDiagnosticsType::set_ServerDiagnosticsSummary_CurrentSubscriptionCount_Variable(const OpcUaDataValue& dataValue)
    {
        return serverDiagnosticsSummary_CurrentSubscriptionCount_Variable_->setDataValue(dataValue);
    }

    bool
    ServerDiagnosticsType::set_ServerDiagnosticsSummary_PublishingIntervalCount_Variable(const OpcUaDataValue& dataValue)
    {
        return serverDiagnosticsSummary_PublishingIntervalCount_Variable_->setDataValue(dataValue);
    }

    bool
    ServerDiagnosticsType::set_ServerDiagnosticsSummary_RejectedRequestsCount_Variable(const OpcUaDataValue& dataValue)
    {
        return serverDiagnosticsSummary_RejectedRequestsCount_Variable_->setDataValue(dataValue);
    }

    bool
    ServerDiagnosticsType::set_ServerDiagnosticsSummary_RejectedSessionCount_Variable(const OpcUaDataValue& dataValue)
    {
        return serverDiagnosticsSummary_RejectedSessionCount_Variable_->setDataValue(dataValue);
    }

    bool
    ServerDiagnosticsType::set_ServerDiagnosticsSummary_SecurityRejectedRequestsCount_Variable(const OpcUaDataValue& dataValue)
    {
        return serverDiagnosticsSummary_SecurityRejectedRequestsCount_Variable_->setDataValue(dataValue);
    }

    bool
    ServerDiagnosticsType::set_ServerDiagnosticsSummary_SecurityRejectedSessionCount_Variable(const OpcUaDataValue& dataValue)
    {
        return serverDiagnosticsSummary_SecurityRejectedSessionCount_Variable_->setDataValue(dataValue);
    }

    bool
    ServerDiagnosticsType::set_ServerDiagnosticsSummary_ServerViewCount_Variable(const OpcUaDataValue& dataValue)
    {
        return serverDiagnosticsSummary_ServerViewCount_Variable_->setDataValue(dataValue);
    }

    bool
    ServerDiagnosticsType::set_ServerDiagnosticsSummary_SessionAbortCount_Variable(const OpcUaDataValue& dataValue)
    {
        return serverDiagnosticsSummary_SessionAbortCount_Variable_->setDataValue(dataValue);
    }

    bool
    ServerDiagnosticsType::set_ServerDiagnosticsSummary_SessionTimeoutCount_Variable(const OpcUaDataValue& dataValue)
    {
        return serverDiagnosticsSummary_SessionTimeoutCount_Variable_->setDataValue(dataValue);
    }

    bool
    ServerDiagnosticsType::set_ServerDiagnosticsSummary_Variable(const OpcUaDataValue& dataValue)
    {
        return serverDiagnosticsSummary_Variable_->setDataValue(dataValue);
    }

    bool
    ServerDiagnosticsType::set_SessionsDiagnosticsSummary_SessionDiagnosticsArray_Variable(const OpcUaDataValue& dataValue)
    {
        return sessionsDiagnosticsSummary_SessionDiagnosticsArray_Variable_->setDataValue(dataValue);
    }

    bool
    ServerDiagnosticsType::set_SessionsDiagnosticsSummary_SessionSecurityDiagnosticsArray_Variable(const OpcUaDataValue& dataValue)
    {
        return sessionsDiagnosticsSummary_SessionSecurityDiagnosticsArray_Variable_->setDataValue(dataValue);
    }

    bool
    ServerDiagnosticsType::set_SubscriptionDiagnosticsArray_Variable(const OpcUaDataValue& dataValue)
    {
        return subscriptionDiagnosticsArray_Variable_->setDataValue(dataValue);
    }

}
