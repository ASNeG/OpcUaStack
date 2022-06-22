/*
    VariableTypeClass: ServerType

    Generated Source Code - please do not change this source code

    VariableTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackServer/StandardObjectType/ServerType.h"
using namespace OpcUaStackCore;

namespace OpcUaStackServer
{
    
    /**
     * Specifies the current status and capabilities of the server.
     */
    ServerType::ServerType(void)
    : ObjectBase()
    , auditing_Variable_(boost::make_shared<ServerVariable>("Auditing_Variable"))
    , estimatedReturnTime_Variable_(boost::make_shared<ServerVariable>("EstimatedReturnTime_Variable"))
    , localTime_Variable_(boost::make_shared<ServerVariable>("LocalTime_Variable"))
    , namespaceArray_Variable_(boost::make_shared<ServerVariable>("NamespaceArray_Variable"))
    , serverArray_Variable_(boost::make_shared<ServerVariable>("ServerArray_Variable"))
    , serverCapabilities_LocaleIdArray_Variable_(boost::make_shared<ServerVariable>("ServerCapabilities_LocaleIdArray_Variable"))
    , serverCapabilities_MaxBrowseContinuationPoints_Variable_(boost::make_shared<ServerVariable>("ServerCapabilities_MaxBrowseContinuationPoints_Variable"))
    , serverCapabilities_MaxHistoryContinuationPoints_Variable_(boost::make_shared<ServerVariable>("ServerCapabilities_MaxHistoryContinuationPoints_Variable"))
    , serverCapabilities_MaxQueryContinuationPoints_Variable_(boost::make_shared<ServerVariable>("ServerCapabilities_MaxQueryContinuationPoints_Variable"))
    , serverCapabilities_MinSupportedSampleRate_Variable_(boost::make_shared<ServerVariable>("ServerCapabilities_MinSupportedSampleRate_Variable"))
    , serverCapabilities_ServerProfileArray_Variable_(boost::make_shared<ServerVariable>("ServerCapabilities_ServerProfileArray_Variable"))
    , serverCapabilities_SoftwareCertificates_Variable_(boost::make_shared<ServerVariable>("ServerCapabilities_SoftwareCertificates_Variable"))
    , serverDiagnostics_EnabledFlag_Variable_(boost::make_shared<ServerVariable>("ServerDiagnostics_EnabledFlag_Variable"))
    , serverDiagnostics_ServerDiagnosticsSummary_CumulatedSessionCount_Variable_(boost::make_shared<ServerVariable>("ServerDiagnostics_ServerDiagnosticsSummary_CumulatedSessionCount_Variable"))
    , serverDiagnostics_ServerDiagnosticsSummary_CumulatedSubscriptionCount_Variable_(boost::make_shared<ServerVariable>("ServerDiagnostics_ServerDiagnosticsSummary_CumulatedSubscriptionCount_Variable"))
    , serverDiagnostics_ServerDiagnosticsSummary_CurrentSessionCount_Variable_(boost::make_shared<ServerVariable>("ServerDiagnostics_ServerDiagnosticsSummary_CurrentSessionCount_Variable"))
    , serverDiagnostics_ServerDiagnosticsSummary_CurrentSubscriptionCount_Variable_(boost::make_shared<ServerVariable>("ServerDiagnostics_ServerDiagnosticsSummary_CurrentSubscriptionCount_Variable"))
    , serverDiagnostics_ServerDiagnosticsSummary_PublishingIntervalCount_Variable_(boost::make_shared<ServerVariable>("ServerDiagnostics_ServerDiagnosticsSummary_PublishingIntervalCount_Variable"))
    , serverDiagnostics_ServerDiagnosticsSummary_RejectedRequestsCount_Variable_(boost::make_shared<ServerVariable>("ServerDiagnostics_ServerDiagnosticsSummary_RejectedRequestsCount_Variable"))
    , serverDiagnostics_ServerDiagnosticsSummary_RejectedSessionCount_Variable_(boost::make_shared<ServerVariable>("ServerDiagnostics_ServerDiagnosticsSummary_RejectedSessionCount_Variable"))
    , serverDiagnostics_ServerDiagnosticsSummary_SecurityRejectedRequestsCount_Variable_(boost::make_shared<ServerVariable>("ServerDiagnostics_ServerDiagnosticsSummary_SecurityRejectedRequestsCount_Variable"))
    , serverDiagnostics_ServerDiagnosticsSummary_SecurityRejectedSessionCount_Variable_(boost::make_shared<ServerVariable>("ServerDiagnostics_ServerDiagnosticsSummary_SecurityRejectedSessionCount_Variable"))
    , serverDiagnostics_ServerDiagnosticsSummary_ServerViewCount_Variable_(boost::make_shared<ServerVariable>("ServerDiagnostics_ServerDiagnosticsSummary_ServerViewCount_Variable"))
    , serverDiagnostics_ServerDiagnosticsSummary_SessionAbortCount_Variable_(boost::make_shared<ServerVariable>("ServerDiagnostics_ServerDiagnosticsSummary_SessionAbortCount_Variable"))
    , serverDiagnostics_ServerDiagnosticsSummary_SessionTimeoutCount_Variable_(boost::make_shared<ServerVariable>("ServerDiagnostics_ServerDiagnosticsSummary_SessionTimeoutCount_Variable"))
    , serverDiagnostics_ServerDiagnosticsSummary_Variable_(boost::make_shared<ServerVariable>("ServerDiagnostics_ServerDiagnosticsSummary_Variable"))
    , serverDiagnostics_SessionsDiagnosticsSummary_SessionDiagnosticsArray_Variable_(boost::make_shared<ServerVariable>("ServerDiagnostics_SessionsDiagnosticsSummary_SessionDiagnosticsArray_Variable"))
    , serverDiagnostics_SessionsDiagnosticsSummary_SessionSecurityDiagnosticsArray_Variable_(boost::make_shared<ServerVariable>("ServerDiagnostics_SessionsDiagnosticsSummary_SessionSecurityDiagnosticsArray_Variable"))
    , serverDiagnostics_SubscriptionDiagnosticsArray_Variable_(boost::make_shared<ServerVariable>("ServerDiagnostics_SubscriptionDiagnosticsArray_Variable"))
    , serverRedundancy_RedundancySupport_Variable_(boost::make_shared<ServerVariable>("ServerRedundancy_RedundancySupport_Variable"))
    , serverStatus_BuildInfo_BuildDate_Variable_(boost::make_shared<ServerVariable>("ServerStatus_BuildInfo_BuildDate_Variable"))
    , serverStatus_BuildInfo_BuildNumber_Variable_(boost::make_shared<ServerVariable>("ServerStatus_BuildInfo_BuildNumber_Variable"))
    , serverStatus_BuildInfo_ManufacturerName_Variable_(boost::make_shared<ServerVariable>("ServerStatus_BuildInfo_ManufacturerName_Variable"))
    , serverStatus_BuildInfo_ProductName_Variable_(boost::make_shared<ServerVariable>("ServerStatus_BuildInfo_ProductName_Variable"))
    , serverStatus_BuildInfo_ProductUri_Variable_(boost::make_shared<ServerVariable>("ServerStatus_BuildInfo_ProductUri_Variable"))
    , serverStatus_BuildInfo_SoftwareVersion_Variable_(boost::make_shared<ServerVariable>("ServerStatus_BuildInfo_SoftwareVersion_Variable"))
    , serverStatus_BuildInfo_Variable_(boost::make_shared<ServerVariable>("ServerStatus_BuildInfo_Variable"))
    , serverStatus_CurrentTime_Variable_(boost::make_shared<ServerVariable>("ServerStatus_CurrentTime_Variable"))
    , serverStatus_SecondsTillShutdown_Variable_(boost::make_shared<ServerVariable>("ServerStatus_SecondsTillShutdown_Variable"))
    , serverStatus_ShutdownReason_Variable_(boost::make_shared<ServerVariable>("ServerStatus_ShutdownReason_Variable"))
    , serverStatus_StartTime_Variable_(boost::make_shared<ServerVariable>("ServerStatus_StartTime_Variable"))
    , serverStatus_State_Variable_(boost::make_shared<ServerVariable>("ServerStatus_State_Variable"))
    , serverStatus_Variable_(boost::make_shared<ServerVariable>("ServerStatus_Variable"))
    , serviceLevel_Variable_(boost::make_shared<ServerVariable>("ServiceLevel_Variable"))
    , urisVersion_Variable_(boost::make_shared<ServerVariable>("UrisVersion_Variable"))
    , getMonitoredItems_Method_(boost::make_shared<ServerMethod>("GetMonitoredItems_Method"))
    , requestServerStateChange_Method_(boost::make_shared<ServerMethod>("RequestServerStateChange_Method"))
    , resendData_Method_(boost::make_shared<ServerMethod>("ResendData_Method"))
    , setSubscriptionDurable_Method_(boost::make_shared<ServerMethod>("SetSubscriptionDurable_Method"))
    {
        objectTypeNamespaceName("http://opcfoundation.org/UA/");
        objectTypeNodeId((OpcUaUInt32)2004);
        setServerVariable(auditing_Variable_);
        setServerVariable(estimatedReturnTime_Variable_);
        setServerVariable(localTime_Variable_);
        setServerVariable(namespaceArray_Variable_);
        setServerVariable(serverArray_Variable_);
        setServerVariable(serverCapabilities_LocaleIdArray_Variable_);
        setServerVariable(serverCapabilities_MaxBrowseContinuationPoints_Variable_);
        setServerVariable(serverCapabilities_MaxHistoryContinuationPoints_Variable_);
        setServerVariable(serverCapabilities_MaxQueryContinuationPoints_Variable_);
        setServerVariable(serverCapabilities_MinSupportedSampleRate_Variable_);
        setServerVariable(serverCapabilities_ServerProfileArray_Variable_);
        setServerVariable(serverCapabilities_SoftwareCertificates_Variable_);
        setServerVariable(serverDiagnostics_EnabledFlag_Variable_);
        setServerVariable(serverDiagnostics_ServerDiagnosticsSummary_CumulatedSessionCount_Variable_);
        setServerVariable(serverDiagnostics_ServerDiagnosticsSummary_CumulatedSubscriptionCount_Variable_);
        setServerVariable(serverDiagnostics_ServerDiagnosticsSummary_CurrentSessionCount_Variable_);
        setServerVariable(serverDiagnostics_ServerDiagnosticsSummary_CurrentSubscriptionCount_Variable_);
        setServerVariable(serverDiagnostics_ServerDiagnosticsSummary_PublishingIntervalCount_Variable_);
        setServerVariable(serverDiagnostics_ServerDiagnosticsSummary_RejectedRequestsCount_Variable_);
        setServerVariable(serverDiagnostics_ServerDiagnosticsSummary_RejectedSessionCount_Variable_);
        setServerVariable(serverDiagnostics_ServerDiagnosticsSummary_SecurityRejectedRequestsCount_Variable_);
        setServerVariable(serverDiagnostics_ServerDiagnosticsSummary_SecurityRejectedSessionCount_Variable_);
        setServerVariable(serverDiagnostics_ServerDiagnosticsSummary_ServerViewCount_Variable_);
        setServerVariable(serverDiagnostics_ServerDiagnosticsSummary_SessionAbortCount_Variable_);
        setServerVariable(serverDiagnostics_ServerDiagnosticsSummary_SessionTimeoutCount_Variable_);
        setServerVariable(serverDiagnostics_ServerDiagnosticsSummary_Variable_);
        setServerVariable(serverDiagnostics_SessionsDiagnosticsSummary_SessionDiagnosticsArray_Variable_);
        setServerVariable(serverDiagnostics_SessionsDiagnosticsSummary_SessionSecurityDiagnosticsArray_Variable_);
        setServerVariable(serverDiagnostics_SubscriptionDiagnosticsArray_Variable_);
        setServerVariable(serverRedundancy_RedundancySupport_Variable_);
        setServerVariable(serverStatus_BuildInfo_BuildDate_Variable_);
        setServerVariable(serverStatus_BuildInfo_BuildNumber_Variable_);
        setServerVariable(serverStatus_BuildInfo_ManufacturerName_Variable_);
        setServerVariable(serverStatus_BuildInfo_ProductName_Variable_);
        setServerVariable(serverStatus_BuildInfo_ProductUri_Variable_);
        setServerVariable(serverStatus_BuildInfo_SoftwareVersion_Variable_);
        setServerVariable(serverStatus_BuildInfo_Variable_);
        setServerVariable(serverStatus_CurrentTime_Variable_);
        setServerVariable(serverStatus_SecondsTillShutdown_Variable_);
        setServerVariable(serverStatus_ShutdownReason_Variable_);
        setServerVariable(serverStatus_StartTime_Variable_);
        setServerVariable(serverStatus_State_Variable_);
        setServerVariable(serverStatus_Variable_);
        setServerVariable(serviceLevel_Variable_);
        setServerVariable(urisVersion_Variable_);
        setServerMethod(getMonitoredItems_Method_);
        setServerMethod(requestServerStateChange_Method_);
        setServerMethod(resendData_Method_);
        setServerMethod(setSubscriptionDurable_Method_);
        getMonitoredItems_Method_->registerMethod(boost::bind(&ServerType::call_GetMonitoredItems_Method, this, boost::placeholders::_1));
        requestServerStateChange_Method_->registerMethod(boost::bind(&ServerType::call_RequestServerStateChange_Method, this, boost::placeholders::_1));
        resendData_Method_->registerMethod(boost::bind(&ServerType::call_ResendData_Method, this, boost::placeholders::_1));
        setSubscriptionDurable_Method_->registerMethod(boost::bind(&ServerType::call_SetSubscriptionDurable_Method, this, boost::placeholders::_1));
    }
    
    /**
     * Specifies the current status and capabilities of the server.
     */
    ServerType::ServerType(const ServerType& value)
    : ObjectBase()
    , auditing_Variable_(boost::make_shared<ServerVariable>("Auditing_Variable"))
    , estimatedReturnTime_Variable_(boost::make_shared<ServerVariable>("EstimatedReturnTime_Variable"))
    , localTime_Variable_(boost::make_shared<ServerVariable>("LocalTime_Variable"))
    , namespaceArray_Variable_(boost::make_shared<ServerVariable>("NamespaceArray_Variable"))
    , serverArray_Variable_(boost::make_shared<ServerVariable>("ServerArray_Variable"))
    , serverCapabilities_LocaleIdArray_Variable_(boost::make_shared<ServerVariable>("ServerCapabilities_LocaleIdArray_Variable"))
    , serverCapabilities_MaxBrowseContinuationPoints_Variable_(boost::make_shared<ServerVariable>("ServerCapabilities_MaxBrowseContinuationPoints_Variable"))
    , serverCapabilities_MaxHistoryContinuationPoints_Variable_(boost::make_shared<ServerVariable>("ServerCapabilities_MaxHistoryContinuationPoints_Variable"))
    , serverCapabilities_MaxQueryContinuationPoints_Variable_(boost::make_shared<ServerVariable>("ServerCapabilities_MaxQueryContinuationPoints_Variable"))
    , serverCapabilities_MinSupportedSampleRate_Variable_(boost::make_shared<ServerVariable>("ServerCapabilities_MinSupportedSampleRate_Variable"))
    , serverCapabilities_ServerProfileArray_Variable_(boost::make_shared<ServerVariable>("ServerCapabilities_ServerProfileArray_Variable"))
    , serverCapabilities_SoftwareCertificates_Variable_(boost::make_shared<ServerVariable>("ServerCapabilities_SoftwareCertificates_Variable"))
    , serverDiagnostics_EnabledFlag_Variable_(boost::make_shared<ServerVariable>("ServerDiagnostics_EnabledFlag_Variable"))
    , serverDiagnostics_ServerDiagnosticsSummary_CumulatedSessionCount_Variable_(boost::make_shared<ServerVariable>("ServerDiagnostics_ServerDiagnosticsSummary_CumulatedSessionCount_Variable"))
    , serverDiagnostics_ServerDiagnosticsSummary_CumulatedSubscriptionCount_Variable_(boost::make_shared<ServerVariable>("ServerDiagnostics_ServerDiagnosticsSummary_CumulatedSubscriptionCount_Variable"))
    , serverDiagnostics_ServerDiagnosticsSummary_CurrentSessionCount_Variable_(boost::make_shared<ServerVariable>("ServerDiagnostics_ServerDiagnosticsSummary_CurrentSessionCount_Variable"))
    , serverDiagnostics_ServerDiagnosticsSummary_CurrentSubscriptionCount_Variable_(boost::make_shared<ServerVariable>("ServerDiagnostics_ServerDiagnosticsSummary_CurrentSubscriptionCount_Variable"))
    , serverDiagnostics_ServerDiagnosticsSummary_PublishingIntervalCount_Variable_(boost::make_shared<ServerVariable>("ServerDiagnostics_ServerDiagnosticsSummary_PublishingIntervalCount_Variable"))
    , serverDiagnostics_ServerDiagnosticsSummary_RejectedRequestsCount_Variable_(boost::make_shared<ServerVariable>("ServerDiagnostics_ServerDiagnosticsSummary_RejectedRequestsCount_Variable"))
    , serverDiagnostics_ServerDiagnosticsSummary_RejectedSessionCount_Variable_(boost::make_shared<ServerVariable>("ServerDiagnostics_ServerDiagnosticsSummary_RejectedSessionCount_Variable"))
    , serverDiagnostics_ServerDiagnosticsSummary_SecurityRejectedRequestsCount_Variable_(boost::make_shared<ServerVariable>("ServerDiagnostics_ServerDiagnosticsSummary_SecurityRejectedRequestsCount_Variable"))
    , serverDiagnostics_ServerDiagnosticsSummary_SecurityRejectedSessionCount_Variable_(boost::make_shared<ServerVariable>("ServerDiagnostics_ServerDiagnosticsSummary_SecurityRejectedSessionCount_Variable"))
    , serverDiagnostics_ServerDiagnosticsSummary_ServerViewCount_Variable_(boost::make_shared<ServerVariable>("ServerDiagnostics_ServerDiagnosticsSummary_ServerViewCount_Variable"))
    , serverDiagnostics_ServerDiagnosticsSummary_SessionAbortCount_Variable_(boost::make_shared<ServerVariable>("ServerDiagnostics_ServerDiagnosticsSummary_SessionAbortCount_Variable"))
    , serverDiagnostics_ServerDiagnosticsSummary_SessionTimeoutCount_Variable_(boost::make_shared<ServerVariable>("ServerDiagnostics_ServerDiagnosticsSummary_SessionTimeoutCount_Variable"))
    , serverDiagnostics_ServerDiagnosticsSummary_Variable_(boost::make_shared<ServerVariable>("ServerDiagnostics_ServerDiagnosticsSummary_Variable"))
    , serverDiagnostics_SessionsDiagnosticsSummary_SessionDiagnosticsArray_Variable_(boost::make_shared<ServerVariable>("ServerDiagnostics_SessionsDiagnosticsSummary_SessionDiagnosticsArray_Variable"))
    , serverDiagnostics_SessionsDiagnosticsSummary_SessionSecurityDiagnosticsArray_Variable_(boost::make_shared<ServerVariable>("ServerDiagnostics_SessionsDiagnosticsSummary_SessionSecurityDiagnosticsArray_Variable"))
    , serverDiagnostics_SubscriptionDiagnosticsArray_Variable_(boost::make_shared<ServerVariable>("ServerDiagnostics_SubscriptionDiagnosticsArray_Variable"))
    , serverRedundancy_RedundancySupport_Variable_(boost::make_shared<ServerVariable>("ServerRedundancy_RedundancySupport_Variable"))
    , serverStatus_BuildInfo_BuildDate_Variable_(boost::make_shared<ServerVariable>("ServerStatus_BuildInfo_BuildDate_Variable"))
    , serverStatus_BuildInfo_BuildNumber_Variable_(boost::make_shared<ServerVariable>("ServerStatus_BuildInfo_BuildNumber_Variable"))
    , serverStatus_BuildInfo_ManufacturerName_Variable_(boost::make_shared<ServerVariable>("ServerStatus_BuildInfo_ManufacturerName_Variable"))
    , serverStatus_BuildInfo_ProductName_Variable_(boost::make_shared<ServerVariable>("ServerStatus_BuildInfo_ProductName_Variable"))
    , serverStatus_BuildInfo_ProductUri_Variable_(boost::make_shared<ServerVariable>("ServerStatus_BuildInfo_ProductUri_Variable"))
    , serverStatus_BuildInfo_SoftwareVersion_Variable_(boost::make_shared<ServerVariable>("ServerStatus_BuildInfo_SoftwareVersion_Variable"))
    , serverStatus_BuildInfo_Variable_(boost::make_shared<ServerVariable>("ServerStatus_BuildInfo_Variable"))
    , serverStatus_CurrentTime_Variable_(boost::make_shared<ServerVariable>("ServerStatus_CurrentTime_Variable"))
    , serverStatus_SecondsTillShutdown_Variable_(boost::make_shared<ServerVariable>("ServerStatus_SecondsTillShutdown_Variable"))
    , serverStatus_ShutdownReason_Variable_(boost::make_shared<ServerVariable>("ServerStatus_ShutdownReason_Variable"))
    , serverStatus_StartTime_Variable_(boost::make_shared<ServerVariable>("ServerStatus_StartTime_Variable"))
    , serverStatus_State_Variable_(boost::make_shared<ServerVariable>("ServerStatus_State_Variable"))
    , serverStatus_Variable_(boost::make_shared<ServerVariable>("ServerStatus_Variable"))
    , serviceLevel_Variable_(boost::make_shared<ServerVariable>("ServiceLevel_Variable"))
    , urisVersion_Variable_(boost::make_shared<ServerVariable>("UrisVersion_Variable"))
    , getMonitoredItems_Method_(boost::make_shared<ServerMethod>("GetMonitoredItems_Method"))
    , requestServerStateChange_Method_(boost::make_shared<ServerMethod>("RequestServerStateChange_Method"))
    , resendData_Method_(boost::make_shared<ServerMethod>("ResendData_Method"))
    , setSubscriptionDurable_Method_(boost::make_shared<ServerMethod>("SetSubscriptionDurable_Method"))
    {
        objectTypeNamespaceName("http://opcfoundation.org/UA/");
        objectTypeNodeId((OpcUaUInt32)2004);
        setServerVariable(auditing_Variable_);
        setServerVariable(estimatedReturnTime_Variable_);
        setServerVariable(localTime_Variable_);
        setServerVariable(namespaceArray_Variable_);
        setServerVariable(serverArray_Variable_);
        setServerVariable(serverCapabilities_LocaleIdArray_Variable_);
        setServerVariable(serverCapabilities_MaxBrowseContinuationPoints_Variable_);
        setServerVariable(serverCapabilities_MaxHistoryContinuationPoints_Variable_);
        setServerVariable(serverCapabilities_MaxQueryContinuationPoints_Variable_);
        setServerVariable(serverCapabilities_MinSupportedSampleRate_Variable_);
        setServerVariable(serverCapabilities_ServerProfileArray_Variable_);
        setServerVariable(serverCapabilities_SoftwareCertificates_Variable_);
        setServerVariable(serverDiagnostics_EnabledFlag_Variable_);
        setServerVariable(serverDiagnostics_ServerDiagnosticsSummary_CumulatedSessionCount_Variable_);
        setServerVariable(serverDiagnostics_ServerDiagnosticsSummary_CumulatedSubscriptionCount_Variable_);
        setServerVariable(serverDiagnostics_ServerDiagnosticsSummary_CurrentSessionCount_Variable_);
        setServerVariable(serverDiagnostics_ServerDiagnosticsSummary_CurrentSubscriptionCount_Variable_);
        setServerVariable(serverDiagnostics_ServerDiagnosticsSummary_PublishingIntervalCount_Variable_);
        setServerVariable(serverDiagnostics_ServerDiagnosticsSummary_RejectedRequestsCount_Variable_);
        setServerVariable(serverDiagnostics_ServerDiagnosticsSummary_RejectedSessionCount_Variable_);
        setServerVariable(serverDiagnostics_ServerDiagnosticsSummary_SecurityRejectedRequestsCount_Variable_);
        setServerVariable(serverDiagnostics_ServerDiagnosticsSummary_SecurityRejectedSessionCount_Variable_);
        setServerVariable(serverDiagnostics_ServerDiagnosticsSummary_ServerViewCount_Variable_);
        setServerVariable(serverDiagnostics_ServerDiagnosticsSummary_SessionAbortCount_Variable_);
        setServerVariable(serverDiagnostics_ServerDiagnosticsSummary_SessionTimeoutCount_Variable_);
        setServerVariable(serverDiagnostics_ServerDiagnosticsSummary_Variable_);
        setServerVariable(serverDiagnostics_SessionsDiagnosticsSummary_SessionDiagnosticsArray_Variable_);
        setServerVariable(serverDiagnostics_SessionsDiagnosticsSummary_SessionSecurityDiagnosticsArray_Variable_);
        setServerVariable(serverDiagnostics_SubscriptionDiagnosticsArray_Variable_);
        setServerVariable(serverRedundancy_RedundancySupport_Variable_);
        setServerVariable(serverStatus_BuildInfo_BuildDate_Variable_);
        setServerVariable(serverStatus_BuildInfo_BuildNumber_Variable_);
        setServerVariable(serverStatus_BuildInfo_ManufacturerName_Variable_);
        setServerVariable(serverStatus_BuildInfo_ProductName_Variable_);
        setServerVariable(serverStatus_BuildInfo_ProductUri_Variable_);
        setServerVariable(serverStatus_BuildInfo_SoftwareVersion_Variable_);
        setServerVariable(serverStatus_BuildInfo_Variable_);
        setServerVariable(serverStatus_CurrentTime_Variable_);
        setServerVariable(serverStatus_SecondsTillShutdown_Variable_);
        setServerVariable(serverStatus_ShutdownReason_Variable_);
        setServerVariable(serverStatus_StartTime_Variable_);
        setServerVariable(serverStatus_State_Variable_);
        setServerVariable(serverStatus_Variable_);
        setServerVariable(serviceLevel_Variable_);
        setServerVariable(urisVersion_Variable_);
        setServerMethod(getMonitoredItems_Method_);
        setServerMethod(requestServerStateChange_Method_);
        setServerMethod(resendData_Method_);
        setServerMethod(setSubscriptionDurable_Method_);
        getMonitoredItems_Method_->registerMethod(boost::bind(&ServerType::call_GetMonitoredItems_Method, this, boost::placeholders::_1));
        requestServerStateChange_Method_->registerMethod(boost::bind(&ServerType::call_RequestServerStateChange_Method, this, boost::placeholders::_1));
        resendData_Method_->registerMethod(boost::bind(&ServerType::call_ResendData_Method, this, boost::placeholders::_1));
        setSubscriptionDurable_Method_->registerMethod(boost::bind(&ServerType::call_SetSubscriptionDurable_Method, this, boost::placeholders::_1));
    }
    
    ServerType::~ServerType(void)
    {
    }

    ServerVariable::SPtr&
    ServerType::auditing_Variable(void)
    {
        return auditing_Variable_;
    }

    ServerVariable::SPtr&
    ServerType::estimatedReturnTime_Variable(void)
    {
        return estimatedReturnTime_Variable_;
    }

    ServerVariable::SPtr&
    ServerType::localTime_Variable(void)
    {
        return localTime_Variable_;
    }

    ServerVariable::SPtr&
    ServerType::namespaceArray_Variable(void)
    {
        return namespaceArray_Variable_;
    }

    ServerVariable::SPtr&
    ServerType::serverArray_Variable(void)
    {
        return serverArray_Variable_;
    }

    ServerVariable::SPtr&
    ServerType::serverCapabilities_LocaleIdArray_Variable(void)
    {
        return serverCapabilities_LocaleIdArray_Variable_;
    }

    ServerVariable::SPtr&
    ServerType::serverCapabilities_MaxBrowseContinuationPoints_Variable(void)
    {
        return serverCapabilities_MaxBrowseContinuationPoints_Variable_;
    }

    ServerVariable::SPtr&
    ServerType::serverCapabilities_MaxHistoryContinuationPoints_Variable(void)
    {
        return serverCapabilities_MaxHistoryContinuationPoints_Variable_;
    }

    ServerVariable::SPtr&
    ServerType::serverCapabilities_MaxQueryContinuationPoints_Variable(void)
    {
        return serverCapabilities_MaxQueryContinuationPoints_Variable_;
    }

    ServerVariable::SPtr&
    ServerType::serverCapabilities_MinSupportedSampleRate_Variable(void)
    {
        return serverCapabilities_MinSupportedSampleRate_Variable_;
    }

    ServerVariable::SPtr&
    ServerType::serverCapabilities_ServerProfileArray_Variable(void)
    {
        return serverCapabilities_ServerProfileArray_Variable_;
    }

    ServerVariable::SPtr&
    ServerType::serverCapabilities_SoftwareCertificates_Variable(void)
    {
        return serverCapabilities_SoftwareCertificates_Variable_;
    }

    ServerVariable::SPtr&
    ServerType::serverDiagnostics_EnabledFlag_Variable(void)
    {
        return serverDiagnostics_EnabledFlag_Variable_;
    }

    ServerVariable::SPtr&
    ServerType::serverDiagnostics_ServerDiagnosticsSummary_CumulatedSessionCount_Variable(void)
    {
        return serverDiagnostics_ServerDiagnosticsSummary_CumulatedSessionCount_Variable_;
    }

    ServerVariable::SPtr&
    ServerType::serverDiagnostics_ServerDiagnosticsSummary_CumulatedSubscriptionCount_Variable(void)
    {
        return serverDiagnostics_ServerDiagnosticsSummary_CumulatedSubscriptionCount_Variable_;
    }

    ServerVariable::SPtr&
    ServerType::serverDiagnostics_ServerDiagnosticsSummary_CurrentSessionCount_Variable(void)
    {
        return serverDiagnostics_ServerDiagnosticsSummary_CurrentSessionCount_Variable_;
    }

    ServerVariable::SPtr&
    ServerType::serverDiagnostics_ServerDiagnosticsSummary_CurrentSubscriptionCount_Variable(void)
    {
        return serverDiagnostics_ServerDiagnosticsSummary_CurrentSubscriptionCount_Variable_;
    }

    ServerVariable::SPtr&
    ServerType::serverDiagnostics_ServerDiagnosticsSummary_PublishingIntervalCount_Variable(void)
    {
        return serverDiagnostics_ServerDiagnosticsSummary_PublishingIntervalCount_Variable_;
    }

    ServerVariable::SPtr&
    ServerType::serverDiagnostics_ServerDiagnosticsSummary_RejectedRequestsCount_Variable(void)
    {
        return serverDiagnostics_ServerDiagnosticsSummary_RejectedRequestsCount_Variable_;
    }

    ServerVariable::SPtr&
    ServerType::serverDiagnostics_ServerDiagnosticsSummary_RejectedSessionCount_Variable(void)
    {
        return serverDiagnostics_ServerDiagnosticsSummary_RejectedSessionCount_Variable_;
    }

    ServerVariable::SPtr&
    ServerType::serverDiagnostics_ServerDiagnosticsSummary_SecurityRejectedRequestsCount_Variable(void)
    {
        return serverDiagnostics_ServerDiagnosticsSummary_SecurityRejectedRequestsCount_Variable_;
    }

    ServerVariable::SPtr&
    ServerType::serverDiagnostics_ServerDiagnosticsSummary_SecurityRejectedSessionCount_Variable(void)
    {
        return serverDiagnostics_ServerDiagnosticsSummary_SecurityRejectedSessionCount_Variable_;
    }

    ServerVariable::SPtr&
    ServerType::serverDiagnostics_ServerDiagnosticsSummary_ServerViewCount_Variable(void)
    {
        return serverDiagnostics_ServerDiagnosticsSummary_ServerViewCount_Variable_;
    }

    ServerVariable::SPtr&
    ServerType::serverDiagnostics_ServerDiagnosticsSummary_SessionAbortCount_Variable(void)
    {
        return serverDiagnostics_ServerDiagnosticsSummary_SessionAbortCount_Variable_;
    }

    ServerVariable::SPtr&
    ServerType::serverDiagnostics_ServerDiagnosticsSummary_SessionTimeoutCount_Variable(void)
    {
        return serverDiagnostics_ServerDiagnosticsSummary_SessionTimeoutCount_Variable_;
    }

    ServerVariable::SPtr&
    ServerType::serverDiagnostics_ServerDiagnosticsSummary_Variable(void)
    {
        return serverDiagnostics_ServerDiagnosticsSummary_Variable_;
    }

    ServerVariable::SPtr&
    ServerType::serverDiagnostics_SessionsDiagnosticsSummary_SessionDiagnosticsArray_Variable(void)
    {
        return serverDiagnostics_SessionsDiagnosticsSummary_SessionDiagnosticsArray_Variable_;
    }

    ServerVariable::SPtr&
    ServerType::serverDiagnostics_SessionsDiagnosticsSummary_SessionSecurityDiagnosticsArray_Variable(void)
    {
        return serverDiagnostics_SessionsDiagnosticsSummary_SessionSecurityDiagnosticsArray_Variable_;
    }

    ServerVariable::SPtr&
    ServerType::serverDiagnostics_SubscriptionDiagnosticsArray_Variable(void)
    {
        return serverDiagnostics_SubscriptionDiagnosticsArray_Variable_;
    }

    ServerVariable::SPtr&
    ServerType::serverRedundancy_RedundancySupport_Variable(void)
    {
        return serverRedundancy_RedundancySupport_Variable_;
    }

    ServerVariable::SPtr&
    ServerType::serverStatus_BuildInfo_BuildDate_Variable(void)
    {
        return serverStatus_BuildInfo_BuildDate_Variable_;
    }

    ServerVariable::SPtr&
    ServerType::serverStatus_BuildInfo_BuildNumber_Variable(void)
    {
        return serverStatus_BuildInfo_BuildNumber_Variable_;
    }

    ServerVariable::SPtr&
    ServerType::serverStatus_BuildInfo_ManufacturerName_Variable(void)
    {
        return serverStatus_BuildInfo_ManufacturerName_Variable_;
    }

    ServerVariable::SPtr&
    ServerType::serverStatus_BuildInfo_ProductName_Variable(void)
    {
        return serverStatus_BuildInfo_ProductName_Variable_;
    }

    ServerVariable::SPtr&
    ServerType::serverStatus_BuildInfo_ProductUri_Variable(void)
    {
        return serverStatus_BuildInfo_ProductUri_Variable_;
    }

    ServerVariable::SPtr&
    ServerType::serverStatus_BuildInfo_SoftwareVersion_Variable(void)
    {
        return serverStatus_BuildInfo_SoftwareVersion_Variable_;
    }

    ServerVariable::SPtr&
    ServerType::serverStatus_BuildInfo_Variable(void)
    {
        return serverStatus_BuildInfo_Variable_;
    }

    ServerVariable::SPtr&
    ServerType::serverStatus_CurrentTime_Variable(void)
    {
        return serverStatus_CurrentTime_Variable_;
    }

    ServerVariable::SPtr&
    ServerType::serverStatus_SecondsTillShutdown_Variable(void)
    {
        return serverStatus_SecondsTillShutdown_Variable_;
    }

    ServerVariable::SPtr&
    ServerType::serverStatus_ShutdownReason_Variable(void)
    {
        return serverStatus_ShutdownReason_Variable_;
    }

    ServerVariable::SPtr&
    ServerType::serverStatus_StartTime_Variable(void)
    {
        return serverStatus_StartTime_Variable_;
    }

    ServerVariable::SPtr&
    ServerType::serverStatus_State_Variable(void)
    {
        return serverStatus_State_Variable_;
    }

    ServerVariable::SPtr&
    ServerType::serverStatus_Variable(void)
    {
        return serverStatus_Variable_;
    }

    ServerVariable::SPtr&
    ServerType::serviceLevel_Variable(void)
    {
        return serviceLevel_Variable_;
    }

    ServerVariable::SPtr&
    ServerType::urisVersion_Variable(void)
    {
        return urisVersion_Variable_;
    }

    void
    ServerType::auditing_Variable(ServerVariable::SPtr& serverVariable)
    {
        auditing_Variable_ = serverVariable;
    }

    void
    ServerType::estimatedReturnTime_Variable(ServerVariable::SPtr& serverVariable)
    {
        estimatedReturnTime_Variable_ = serverVariable;
    }

    void
    ServerType::localTime_Variable(ServerVariable::SPtr& serverVariable)
    {
        localTime_Variable_ = serverVariable;
    }

    void
    ServerType::namespaceArray_Variable(ServerVariable::SPtr& serverVariable)
    {
        namespaceArray_Variable_ = serverVariable;
    }

    void
    ServerType::serverArray_Variable(ServerVariable::SPtr& serverVariable)
    {
        serverArray_Variable_ = serverVariable;
    }

    void
    ServerType::serverCapabilities_LocaleIdArray_Variable(ServerVariable::SPtr& serverVariable)
    {
        serverCapabilities_LocaleIdArray_Variable_ = serverVariable;
    }

    void
    ServerType::serverCapabilities_MaxBrowseContinuationPoints_Variable(ServerVariable::SPtr& serverVariable)
    {
        serverCapabilities_MaxBrowseContinuationPoints_Variable_ = serverVariable;
    }

    void
    ServerType::serverCapabilities_MaxHistoryContinuationPoints_Variable(ServerVariable::SPtr& serverVariable)
    {
        serverCapabilities_MaxHistoryContinuationPoints_Variable_ = serverVariable;
    }

    void
    ServerType::serverCapabilities_MaxQueryContinuationPoints_Variable(ServerVariable::SPtr& serverVariable)
    {
        serverCapabilities_MaxQueryContinuationPoints_Variable_ = serverVariable;
    }

    void
    ServerType::serverCapabilities_MinSupportedSampleRate_Variable(ServerVariable::SPtr& serverVariable)
    {
        serverCapabilities_MinSupportedSampleRate_Variable_ = serverVariable;
    }

    void
    ServerType::serverCapabilities_ServerProfileArray_Variable(ServerVariable::SPtr& serverVariable)
    {
        serverCapabilities_ServerProfileArray_Variable_ = serverVariable;
    }

    void
    ServerType::serverCapabilities_SoftwareCertificates_Variable(ServerVariable::SPtr& serverVariable)
    {
        serverCapabilities_SoftwareCertificates_Variable_ = serverVariable;
    }

    void
    ServerType::serverDiagnostics_EnabledFlag_Variable(ServerVariable::SPtr& serverVariable)
    {
        serverDiagnostics_EnabledFlag_Variable_ = serverVariable;
    }

    void
    ServerType::serverDiagnostics_ServerDiagnosticsSummary_CumulatedSessionCount_Variable(ServerVariable::SPtr& serverVariable)
    {
        serverDiagnostics_ServerDiagnosticsSummary_CumulatedSessionCount_Variable_ = serverVariable;
    }

    void
    ServerType::serverDiagnostics_ServerDiagnosticsSummary_CumulatedSubscriptionCount_Variable(ServerVariable::SPtr& serverVariable)
    {
        serverDiagnostics_ServerDiagnosticsSummary_CumulatedSubscriptionCount_Variable_ = serverVariable;
    }

    void
    ServerType::serverDiagnostics_ServerDiagnosticsSummary_CurrentSessionCount_Variable(ServerVariable::SPtr& serverVariable)
    {
        serverDiagnostics_ServerDiagnosticsSummary_CurrentSessionCount_Variable_ = serverVariable;
    }

    void
    ServerType::serverDiagnostics_ServerDiagnosticsSummary_CurrentSubscriptionCount_Variable(ServerVariable::SPtr& serverVariable)
    {
        serverDiagnostics_ServerDiagnosticsSummary_CurrentSubscriptionCount_Variable_ = serverVariable;
    }

    void
    ServerType::serverDiagnostics_ServerDiagnosticsSummary_PublishingIntervalCount_Variable(ServerVariable::SPtr& serverVariable)
    {
        serverDiagnostics_ServerDiagnosticsSummary_PublishingIntervalCount_Variable_ = serverVariable;
    }

    void
    ServerType::serverDiagnostics_ServerDiagnosticsSummary_RejectedRequestsCount_Variable(ServerVariable::SPtr& serverVariable)
    {
        serverDiagnostics_ServerDiagnosticsSummary_RejectedRequestsCount_Variable_ = serverVariable;
    }

    void
    ServerType::serverDiagnostics_ServerDiagnosticsSummary_RejectedSessionCount_Variable(ServerVariable::SPtr& serverVariable)
    {
        serverDiagnostics_ServerDiagnosticsSummary_RejectedSessionCount_Variable_ = serverVariable;
    }

    void
    ServerType::serverDiagnostics_ServerDiagnosticsSummary_SecurityRejectedRequestsCount_Variable(ServerVariable::SPtr& serverVariable)
    {
        serverDiagnostics_ServerDiagnosticsSummary_SecurityRejectedRequestsCount_Variable_ = serverVariable;
    }

    void
    ServerType::serverDiagnostics_ServerDiagnosticsSummary_SecurityRejectedSessionCount_Variable(ServerVariable::SPtr& serverVariable)
    {
        serverDiagnostics_ServerDiagnosticsSummary_SecurityRejectedSessionCount_Variable_ = serverVariable;
    }

    void
    ServerType::serverDiagnostics_ServerDiagnosticsSummary_ServerViewCount_Variable(ServerVariable::SPtr& serverVariable)
    {
        serverDiagnostics_ServerDiagnosticsSummary_ServerViewCount_Variable_ = serverVariable;
    }

    void
    ServerType::serverDiagnostics_ServerDiagnosticsSummary_SessionAbortCount_Variable(ServerVariable::SPtr& serverVariable)
    {
        serverDiagnostics_ServerDiagnosticsSummary_SessionAbortCount_Variable_ = serverVariable;
    }

    void
    ServerType::serverDiagnostics_ServerDiagnosticsSummary_SessionTimeoutCount_Variable(ServerVariable::SPtr& serverVariable)
    {
        serverDiagnostics_ServerDiagnosticsSummary_SessionTimeoutCount_Variable_ = serverVariable;
    }

    void
    ServerType::serverDiagnostics_ServerDiagnosticsSummary_Variable(ServerVariable::SPtr& serverVariable)
    {
        serverDiagnostics_ServerDiagnosticsSummary_Variable_ = serverVariable;
    }

    void
    ServerType::serverDiagnostics_SessionsDiagnosticsSummary_SessionDiagnosticsArray_Variable(ServerVariable::SPtr& serverVariable)
    {
        serverDiagnostics_SessionsDiagnosticsSummary_SessionDiagnosticsArray_Variable_ = serverVariable;
    }

    void
    ServerType::serverDiagnostics_SessionsDiagnosticsSummary_SessionSecurityDiagnosticsArray_Variable(ServerVariable::SPtr& serverVariable)
    {
        serverDiagnostics_SessionsDiagnosticsSummary_SessionSecurityDiagnosticsArray_Variable_ = serverVariable;
    }

    void
    ServerType::serverDiagnostics_SubscriptionDiagnosticsArray_Variable(ServerVariable::SPtr& serverVariable)
    {
        serverDiagnostics_SubscriptionDiagnosticsArray_Variable_ = serverVariable;
    }

    void
    ServerType::serverRedundancy_RedundancySupport_Variable(ServerVariable::SPtr& serverVariable)
    {
        serverRedundancy_RedundancySupport_Variable_ = serverVariable;
    }

    void
    ServerType::serverStatus_BuildInfo_BuildDate_Variable(ServerVariable::SPtr& serverVariable)
    {
        serverStatus_BuildInfo_BuildDate_Variable_ = serverVariable;
    }

    void
    ServerType::serverStatus_BuildInfo_BuildNumber_Variable(ServerVariable::SPtr& serverVariable)
    {
        serverStatus_BuildInfo_BuildNumber_Variable_ = serverVariable;
    }

    void
    ServerType::serverStatus_BuildInfo_ManufacturerName_Variable(ServerVariable::SPtr& serverVariable)
    {
        serverStatus_BuildInfo_ManufacturerName_Variable_ = serverVariable;
    }

    void
    ServerType::serverStatus_BuildInfo_ProductName_Variable(ServerVariable::SPtr& serverVariable)
    {
        serverStatus_BuildInfo_ProductName_Variable_ = serverVariable;
    }

    void
    ServerType::serverStatus_BuildInfo_ProductUri_Variable(ServerVariable::SPtr& serverVariable)
    {
        serverStatus_BuildInfo_ProductUri_Variable_ = serverVariable;
    }

    void
    ServerType::serverStatus_BuildInfo_SoftwareVersion_Variable(ServerVariable::SPtr& serverVariable)
    {
        serverStatus_BuildInfo_SoftwareVersion_Variable_ = serverVariable;
    }

    void
    ServerType::serverStatus_BuildInfo_Variable(ServerVariable::SPtr& serverVariable)
    {
        serverStatus_BuildInfo_Variable_ = serverVariable;
    }

    void
    ServerType::serverStatus_CurrentTime_Variable(ServerVariable::SPtr& serverVariable)
    {
        serverStatus_CurrentTime_Variable_ = serverVariable;
    }

    void
    ServerType::serverStatus_SecondsTillShutdown_Variable(ServerVariable::SPtr& serverVariable)
    {
        serverStatus_SecondsTillShutdown_Variable_ = serverVariable;
    }

    void
    ServerType::serverStatus_ShutdownReason_Variable(ServerVariable::SPtr& serverVariable)
    {
        serverStatus_ShutdownReason_Variable_ = serverVariable;
    }

    void
    ServerType::serverStatus_StartTime_Variable(ServerVariable::SPtr& serverVariable)
    {
        serverStatus_StartTime_Variable_ = serverVariable;
    }

    void
    ServerType::serverStatus_State_Variable(ServerVariable::SPtr& serverVariable)
    {
        serverStatus_State_Variable_ = serverVariable;
    }

    void
    ServerType::serverStatus_Variable(ServerVariable::SPtr& serverVariable)
    {
        serverStatus_Variable_ = serverVariable;
    }

    void
    ServerType::serviceLevel_Variable(ServerVariable::SPtr& serverVariable)
    {
        serviceLevel_Variable_ = serverVariable;
    }

    void
    ServerType::urisVersion_Variable(ServerVariable::SPtr& serverVariable)
    {
        urisVersion_Variable_ = serverVariable;
    }

    bool
    ServerType::get_Auditing_Variable(OpcUaDataValue& dataValue)
    {
        return auditing_Variable_->getDataValue(dataValue);
    }

    bool
    ServerType::get_EstimatedReturnTime_Variable(OpcUaDataValue& dataValue)
    {
        return estimatedReturnTime_Variable_->getDataValue(dataValue);
    }

    bool
    ServerType::get_LocalTime_Variable(OpcUaDataValue& dataValue)
    {
        return localTime_Variable_->getDataValue(dataValue);
    }

    bool
    ServerType::get_NamespaceArray_Variable(OpcUaDataValue& dataValue)
    {
        return namespaceArray_Variable_->getDataValue(dataValue);
    }

    bool
    ServerType::get_ServerArray_Variable(OpcUaDataValue& dataValue)
    {
        return serverArray_Variable_->getDataValue(dataValue);
    }

    bool
    ServerType::get_ServerCapabilities_LocaleIdArray_Variable(OpcUaDataValue& dataValue)
    {
        return serverCapabilities_LocaleIdArray_Variable_->getDataValue(dataValue);
    }

    bool
    ServerType::get_ServerCapabilities_MaxBrowseContinuationPoints_Variable(OpcUaDataValue& dataValue)
    {
        return serverCapabilities_MaxBrowseContinuationPoints_Variable_->getDataValue(dataValue);
    }

    bool
    ServerType::get_ServerCapabilities_MaxHistoryContinuationPoints_Variable(OpcUaDataValue& dataValue)
    {
        return serverCapabilities_MaxHistoryContinuationPoints_Variable_->getDataValue(dataValue);
    }

    bool
    ServerType::get_ServerCapabilities_MaxQueryContinuationPoints_Variable(OpcUaDataValue& dataValue)
    {
        return serverCapabilities_MaxQueryContinuationPoints_Variable_->getDataValue(dataValue);
    }

    bool
    ServerType::get_ServerCapabilities_MinSupportedSampleRate_Variable(OpcUaDataValue& dataValue)
    {
        return serverCapabilities_MinSupportedSampleRate_Variable_->getDataValue(dataValue);
    }

    bool
    ServerType::get_ServerCapabilities_ServerProfileArray_Variable(OpcUaDataValue& dataValue)
    {
        return serverCapabilities_ServerProfileArray_Variable_->getDataValue(dataValue);
    }

    bool
    ServerType::get_ServerCapabilities_SoftwareCertificates_Variable(OpcUaDataValue& dataValue)
    {
        return serverCapabilities_SoftwareCertificates_Variable_->getDataValue(dataValue);
    }

    bool
    ServerType::get_ServerDiagnostics_EnabledFlag_Variable(OpcUaDataValue& dataValue)
    {
        return serverDiagnostics_EnabledFlag_Variable_->getDataValue(dataValue);
    }

    bool
    ServerType::get_ServerDiagnostics_ServerDiagnosticsSummary_CumulatedSessionCount_Variable(OpcUaDataValue& dataValue)
    {
        return serverDiagnostics_ServerDiagnosticsSummary_CumulatedSessionCount_Variable_->getDataValue(dataValue);
    }

    bool
    ServerType::get_ServerDiagnostics_ServerDiagnosticsSummary_CumulatedSubscriptionCount_Variable(OpcUaDataValue& dataValue)
    {
        return serverDiagnostics_ServerDiagnosticsSummary_CumulatedSubscriptionCount_Variable_->getDataValue(dataValue);
    }

    bool
    ServerType::get_ServerDiagnostics_ServerDiagnosticsSummary_CurrentSessionCount_Variable(OpcUaDataValue& dataValue)
    {
        return serverDiagnostics_ServerDiagnosticsSummary_CurrentSessionCount_Variable_->getDataValue(dataValue);
    }

    bool
    ServerType::get_ServerDiagnostics_ServerDiagnosticsSummary_CurrentSubscriptionCount_Variable(OpcUaDataValue& dataValue)
    {
        return serverDiagnostics_ServerDiagnosticsSummary_CurrentSubscriptionCount_Variable_->getDataValue(dataValue);
    }

    bool
    ServerType::get_ServerDiagnostics_ServerDiagnosticsSummary_PublishingIntervalCount_Variable(OpcUaDataValue& dataValue)
    {
        return serverDiagnostics_ServerDiagnosticsSummary_PublishingIntervalCount_Variable_->getDataValue(dataValue);
    }

    bool
    ServerType::get_ServerDiagnostics_ServerDiagnosticsSummary_RejectedRequestsCount_Variable(OpcUaDataValue& dataValue)
    {
        return serverDiagnostics_ServerDiagnosticsSummary_RejectedRequestsCount_Variable_->getDataValue(dataValue);
    }

    bool
    ServerType::get_ServerDiagnostics_ServerDiagnosticsSummary_RejectedSessionCount_Variable(OpcUaDataValue& dataValue)
    {
        return serverDiagnostics_ServerDiagnosticsSummary_RejectedSessionCount_Variable_->getDataValue(dataValue);
    }

    bool
    ServerType::get_ServerDiagnostics_ServerDiagnosticsSummary_SecurityRejectedRequestsCount_Variable(OpcUaDataValue& dataValue)
    {
        return serverDiagnostics_ServerDiagnosticsSummary_SecurityRejectedRequestsCount_Variable_->getDataValue(dataValue);
    }

    bool
    ServerType::get_ServerDiagnostics_ServerDiagnosticsSummary_SecurityRejectedSessionCount_Variable(OpcUaDataValue& dataValue)
    {
        return serverDiagnostics_ServerDiagnosticsSummary_SecurityRejectedSessionCount_Variable_->getDataValue(dataValue);
    }

    bool
    ServerType::get_ServerDiagnostics_ServerDiagnosticsSummary_ServerViewCount_Variable(OpcUaDataValue& dataValue)
    {
        return serverDiagnostics_ServerDiagnosticsSummary_ServerViewCount_Variable_->getDataValue(dataValue);
    }

    bool
    ServerType::get_ServerDiagnostics_ServerDiagnosticsSummary_SessionAbortCount_Variable(OpcUaDataValue& dataValue)
    {
        return serverDiagnostics_ServerDiagnosticsSummary_SessionAbortCount_Variable_->getDataValue(dataValue);
    }

    bool
    ServerType::get_ServerDiagnostics_ServerDiagnosticsSummary_SessionTimeoutCount_Variable(OpcUaDataValue& dataValue)
    {
        return serverDiagnostics_ServerDiagnosticsSummary_SessionTimeoutCount_Variable_->getDataValue(dataValue);
    }

    bool
    ServerType::get_ServerDiagnostics_ServerDiagnosticsSummary_Variable(OpcUaDataValue& dataValue)
    {
        return serverDiagnostics_ServerDiagnosticsSummary_Variable_->getDataValue(dataValue);
    }

    bool
    ServerType::get_ServerDiagnostics_SessionsDiagnosticsSummary_SessionDiagnosticsArray_Variable(OpcUaDataValue& dataValue)
    {
        return serverDiagnostics_SessionsDiagnosticsSummary_SessionDiagnosticsArray_Variable_->getDataValue(dataValue);
    }

    bool
    ServerType::get_ServerDiagnostics_SessionsDiagnosticsSummary_SessionSecurityDiagnosticsArray_Variable(OpcUaDataValue& dataValue)
    {
        return serverDiagnostics_SessionsDiagnosticsSummary_SessionSecurityDiagnosticsArray_Variable_->getDataValue(dataValue);
    }

    bool
    ServerType::get_ServerDiagnostics_SubscriptionDiagnosticsArray_Variable(OpcUaDataValue& dataValue)
    {
        return serverDiagnostics_SubscriptionDiagnosticsArray_Variable_->getDataValue(dataValue);
    }

    bool
    ServerType::get_ServerRedundancy_RedundancySupport_Variable(OpcUaDataValue& dataValue)
    {
        return serverRedundancy_RedundancySupport_Variable_->getDataValue(dataValue);
    }

    bool
    ServerType::get_ServerStatus_BuildInfo_BuildDate_Variable(OpcUaDataValue& dataValue)
    {
        return serverStatus_BuildInfo_BuildDate_Variable_->getDataValue(dataValue);
    }

    bool
    ServerType::get_ServerStatus_BuildInfo_BuildNumber_Variable(OpcUaDataValue& dataValue)
    {
        return serverStatus_BuildInfo_BuildNumber_Variable_->getDataValue(dataValue);
    }

    bool
    ServerType::get_ServerStatus_BuildInfo_ManufacturerName_Variable(OpcUaDataValue& dataValue)
    {
        return serverStatus_BuildInfo_ManufacturerName_Variable_->getDataValue(dataValue);
    }

    bool
    ServerType::get_ServerStatus_BuildInfo_ProductName_Variable(OpcUaDataValue& dataValue)
    {
        return serverStatus_BuildInfo_ProductName_Variable_->getDataValue(dataValue);
    }

    bool
    ServerType::get_ServerStatus_BuildInfo_ProductUri_Variable(OpcUaDataValue& dataValue)
    {
        return serverStatus_BuildInfo_ProductUri_Variable_->getDataValue(dataValue);
    }

    bool
    ServerType::get_ServerStatus_BuildInfo_SoftwareVersion_Variable(OpcUaDataValue& dataValue)
    {
        return serverStatus_BuildInfo_SoftwareVersion_Variable_->getDataValue(dataValue);
    }

    bool
    ServerType::get_ServerStatus_BuildInfo_Variable(OpcUaDataValue& dataValue)
    {
        return serverStatus_BuildInfo_Variable_->getDataValue(dataValue);
    }

    bool
    ServerType::get_ServerStatus_CurrentTime_Variable(OpcUaDataValue& dataValue)
    {
        return serverStatus_CurrentTime_Variable_->getDataValue(dataValue);
    }

    bool
    ServerType::get_ServerStatus_SecondsTillShutdown_Variable(OpcUaDataValue& dataValue)
    {
        return serverStatus_SecondsTillShutdown_Variable_->getDataValue(dataValue);
    }

    bool
    ServerType::get_ServerStatus_ShutdownReason_Variable(OpcUaDataValue& dataValue)
    {
        return serverStatus_ShutdownReason_Variable_->getDataValue(dataValue);
    }

    bool
    ServerType::get_ServerStatus_StartTime_Variable(OpcUaDataValue& dataValue)
    {
        return serverStatus_StartTime_Variable_->getDataValue(dataValue);
    }

    bool
    ServerType::get_ServerStatus_State_Variable(OpcUaDataValue& dataValue)
    {
        return serverStatus_State_Variable_->getDataValue(dataValue);
    }

    bool
    ServerType::get_ServerStatus_Variable(OpcUaDataValue& dataValue)
    {
        return serverStatus_Variable_->getDataValue(dataValue);
    }

    bool
    ServerType::get_ServiceLevel_Variable(OpcUaDataValue& dataValue)
    {
        return serviceLevel_Variable_->getDataValue(dataValue);
    }

    bool
    ServerType::get_UrisVersion_Variable(OpcUaDataValue& dataValue)
    {
        return urisVersion_Variable_->getDataValue(dataValue);
    }

    bool
    ServerType::set_Auditing_Variable(const OpcUaDataValue& dataValue)
    {
        return auditing_Variable_->setDataValue(dataValue);
    }

    bool
    ServerType::set_EstimatedReturnTime_Variable(const OpcUaDataValue& dataValue)
    {
        return estimatedReturnTime_Variable_->setDataValue(dataValue);
    }

    bool
    ServerType::set_LocalTime_Variable(const OpcUaDataValue& dataValue)
    {
        return localTime_Variable_->setDataValue(dataValue);
    }

    bool
    ServerType::set_NamespaceArray_Variable(const OpcUaDataValue& dataValue)
    {
        return namespaceArray_Variable_->setDataValue(dataValue);
    }

    bool
    ServerType::set_ServerArray_Variable(const OpcUaDataValue& dataValue)
    {
        return serverArray_Variable_->setDataValue(dataValue);
    }

    bool
    ServerType::set_ServerCapabilities_LocaleIdArray_Variable(const OpcUaDataValue& dataValue)
    {
        return serverCapabilities_LocaleIdArray_Variable_->setDataValue(dataValue);
    }

    bool
    ServerType::set_ServerCapabilities_MaxBrowseContinuationPoints_Variable(const OpcUaDataValue& dataValue)
    {
        return serverCapabilities_MaxBrowseContinuationPoints_Variable_->setDataValue(dataValue);
    }

    bool
    ServerType::set_ServerCapabilities_MaxHistoryContinuationPoints_Variable(const OpcUaDataValue& dataValue)
    {
        return serverCapabilities_MaxHistoryContinuationPoints_Variable_->setDataValue(dataValue);
    }

    bool
    ServerType::set_ServerCapabilities_MaxQueryContinuationPoints_Variable(const OpcUaDataValue& dataValue)
    {
        return serverCapabilities_MaxQueryContinuationPoints_Variable_->setDataValue(dataValue);
    }

    bool
    ServerType::set_ServerCapabilities_MinSupportedSampleRate_Variable(const OpcUaDataValue& dataValue)
    {
        return serverCapabilities_MinSupportedSampleRate_Variable_->setDataValue(dataValue);
    }

    bool
    ServerType::set_ServerCapabilities_ServerProfileArray_Variable(const OpcUaDataValue& dataValue)
    {
        return serverCapabilities_ServerProfileArray_Variable_->setDataValue(dataValue);
    }

    bool
    ServerType::set_ServerCapabilities_SoftwareCertificates_Variable(const OpcUaDataValue& dataValue)
    {
        return serverCapabilities_SoftwareCertificates_Variable_->setDataValue(dataValue);
    }

    bool
    ServerType::set_ServerDiagnostics_EnabledFlag_Variable(const OpcUaDataValue& dataValue)
    {
        return serverDiagnostics_EnabledFlag_Variable_->setDataValue(dataValue);
    }

    bool
    ServerType::set_ServerDiagnostics_ServerDiagnosticsSummary_CumulatedSessionCount_Variable(const OpcUaDataValue& dataValue)
    {
        return serverDiagnostics_ServerDiagnosticsSummary_CumulatedSessionCount_Variable_->setDataValue(dataValue);
    }

    bool
    ServerType::set_ServerDiagnostics_ServerDiagnosticsSummary_CumulatedSubscriptionCount_Variable(const OpcUaDataValue& dataValue)
    {
        return serverDiagnostics_ServerDiagnosticsSummary_CumulatedSubscriptionCount_Variable_->setDataValue(dataValue);
    }

    bool
    ServerType::set_ServerDiagnostics_ServerDiagnosticsSummary_CurrentSessionCount_Variable(const OpcUaDataValue& dataValue)
    {
        return serverDiagnostics_ServerDiagnosticsSummary_CurrentSessionCount_Variable_->setDataValue(dataValue);
    }

    bool
    ServerType::set_ServerDiagnostics_ServerDiagnosticsSummary_CurrentSubscriptionCount_Variable(const OpcUaDataValue& dataValue)
    {
        return serverDiagnostics_ServerDiagnosticsSummary_CurrentSubscriptionCount_Variable_->setDataValue(dataValue);
    }

    bool
    ServerType::set_ServerDiagnostics_ServerDiagnosticsSummary_PublishingIntervalCount_Variable(const OpcUaDataValue& dataValue)
    {
        return serverDiagnostics_ServerDiagnosticsSummary_PublishingIntervalCount_Variable_->setDataValue(dataValue);
    }

    bool
    ServerType::set_ServerDiagnostics_ServerDiagnosticsSummary_RejectedRequestsCount_Variable(const OpcUaDataValue& dataValue)
    {
        return serverDiagnostics_ServerDiagnosticsSummary_RejectedRequestsCount_Variable_->setDataValue(dataValue);
    }

    bool
    ServerType::set_ServerDiagnostics_ServerDiagnosticsSummary_RejectedSessionCount_Variable(const OpcUaDataValue& dataValue)
    {
        return serverDiagnostics_ServerDiagnosticsSummary_RejectedSessionCount_Variable_->setDataValue(dataValue);
    }

    bool
    ServerType::set_ServerDiagnostics_ServerDiagnosticsSummary_SecurityRejectedRequestsCount_Variable(const OpcUaDataValue& dataValue)
    {
        return serverDiagnostics_ServerDiagnosticsSummary_SecurityRejectedRequestsCount_Variable_->setDataValue(dataValue);
    }

    bool
    ServerType::set_ServerDiagnostics_ServerDiagnosticsSummary_SecurityRejectedSessionCount_Variable(const OpcUaDataValue& dataValue)
    {
        return serverDiagnostics_ServerDiagnosticsSummary_SecurityRejectedSessionCount_Variable_->setDataValue(dataValue);
    }

    bool
    ServerType::set_ServerDiagnostics_ServerDiagnosticsSummary_ServerViewCount_Variable(const OpcUaDataValue& dataValue)
    {
        return serverDiagnostics_ServerDiagnosticsSummary_ServerViewCount_Variable_->setDataValue(dataValue);
    }

    bool
    ServerType::set_ServerDiagnostics_ServerDiagnosticsSummary_SessionAbortCount_Variable(const OpcUaDataValue& dataValue)
    {
        return serverDiagnostics_ServerDiagnosticsSummary_SessionAbortCount_Variable_->setDataValue(dataValue);
    }

    bool
    ServerType::set_ServerDiagnostics_ServerDiagnosticsSummary_SessionTimeoutCount_Variable(const OpcUaDataValue& dataValue)
    {
        return serverDiagnostics_ServerDiagnosticsSummary_SessionTimeoutCount_Variable_->setDataValue(dataValue);
    }

    bool
    ServerType::set_ServerDiagnostics_ServerDiagnosticsSummary_Variable(const OpcUaDataValue& dataValue)
    {
        return serverDiagnostics_ServerDiagnosticsSummary_Variable_->setDataValue(dataValue);
    }

    bool
    ServerType::set_ServerDiagnostics_SessionsDiagnosticsSummary_SessionDiagnosticsArray_Variable(const OpcUaDataValue& dataValue)
    {
        return serverDiagnostics_SessionsDiagnosticsSummary_SessionDiagnosticsArray_Variable_->setDataValue(dataValue);
    }

    bool
    ServerType::set_ServerDiagnostics_SessionsDiagnosticsSummary_SessionSecurityDiagnosticsArray_Variable(const OpcUaDataValue& dataValue)
    {
        return serverDiagnostics_SessionsDiagnosticsSummary_SessionSecurityDiagnosticsArray_Variable_->setDataValue(dataValue);
    }

    bool
    ServerType::set_ServerDiagnostics_SubscriptionDiagnosticsArray_Variable(const OpcUaDataValue& dataValue)
    {
        return serverDiagnostics_SubscriptionDiagnosticsArray_Variable_->setDataValue(dataValue);
    }

    bool
    ServerType::set_ServerRedundancy_RedundancySupport_Variable(const OpcUaDataValue& dataValue)
    {
        return serverRedundancy_RedundancySupport_Variable_->setDataValue(dataValue);
    }

    bool
    ServerType::set_ServerStatus_BuildInfo_BuildDate_Variable(const OpcUaDataValue& dataValue)
    {
        return serverStatus_BuildInfo_BuildDate_Variable_->setDataValue(dataValue);
    }

    bool
    ServerType::set_ServerStatus_BuildInfo_BuildNumber_Variable(const OpcUaDataValue& dataValue)
    {
        return serverStatus_BuildInfo_BuildNumber_Variable_->setDataValue(dataValue);
    }

    bool
    ServerType::set_ServerStatus_BuildInfo_ManufacturerName_Variable(const OpcUaDataValue& dataValue)
    {
        return serverStatus_BuildInfo_ManufacturerName_Variable_->setDataValue(dataValue);
    }

    bool
    ServerType::set_ServerStatus_BuildInfo_ProductName_Variable(const OpcUaDataValue& dataValue)
    {
        return serverStatus_BuildInfo_ProductName_Variable_->setDataValue(dataValue);
    }

    bool
    ServerType::set_ServerStatus_BuildInfo_ProductUri_Variable(const OpcUaDataValue& dataValue)
    {
        return serverStatus_BuildInfo_ProductUri_Variable_->setDataValue(dataValue);
    }

    bool
    ServerType::set_ServerStatus_BuildInfo_SoftwareVersion_Variable(const OpcUaDataValue& dataValue)
    {
        return serverStatus_BuildInfo_SoftwareVersion_Variable_->setDataValue(dataValue);
    }

    bool
    ServerType::set_ServerStatus_BuildInfo_Variable(const OpcUaDataValue& dataValue)
    {
        return serverStatus_BuildInfo_Variable_->setDataValue(dataValue);
    }

    bool
    ServerType::set_ServerStatus_CurrentTime_Variable(const OpcUaDataValue& dataValue)
    {
        return serverStatus_CurrentTime_Variable_->setDataValue(dataValue);
    }

    bool
    ServerType::set_ServerStatus_SecondsTillShutdown_Variable(const OpcUaDataValue& dataValue)
    {
        return serverStatus_SecondsTillShutdown_Variable_->setDataValue(dataValue);
    }

    bool
    ServerType::set_ServerStatus_ShutdownReason_Variable(const OpcUaDataValue& dataValue)
    {
        return serverStatus_ShutdownReason_Variable_->setDataValue(dataValue);
    }

    bool
    ServerType::set_ServerStatus_StartTime_Variable(const OpcUaDataValue& dataValue)
    {
        return serverStatus_StartTime_Variable_->setDataValue(dataValue);
    }

    bool
    ServerType::set_ServerStatus_State_Variable(const OpcUaDataValue& dataValue)
    {
        return serverStatus_State_Variable_->setDataValue(dataValue);
    }

    bool
    ServerType::set_ServerStatus_Variable(const OpcUaDataValue& dataValue)
    {
        return serverStatus_Variable_->setDataValue(dataValue);
    }

    bool
    ServerType::set_ServiceLevel_Variable(const OpcUaDataValue& dataValue)
    {
        return serviceLevel_Variable_->setDataValue(dataValue);
    }

    bool
    ServerType::set_UrisVersion_Variable(const OpcUaDataValue& dataValue)
    {
        return urisVersion_Variable_->setDataValue(dataValue);
    }

    void
    ServerType::call_GetMonitoredItems_Method(ApplicationMethodContext* applicationMethodContext)
    {
        applicationMethodContext->statusCode_ = BadNotSupported;
    }

    void
    ServerType::call_RequestServerStateChange_Method(ApplicationMethodContext* applicationMethodContext)
    {
        applicationMethodContext->statusCode_ = BadNotSupported;
    }

    void
    ServerType::call_ResendData_Method(ApplicationMethodContext* applicationMethodContext)
    {
        applicationMethodContext->statusCode_ = BadNotSupported;
    }

    void
    ServerType::call_SetSubscriptionDurable_Method(ApplicationMethodContext* applicationMethodContext)
    {
        applicationMethodContext->statusCode_ = BadNotSupported;
    }

}
