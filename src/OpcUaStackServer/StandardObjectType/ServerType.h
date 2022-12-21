/*
    ObjectTypeClass: ServerType

    Generated Source Code - please do not change this source code

    ObjectTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

    Autor:     Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackServer_ServerType_h__
#define __OpcUaStackServer_ServerType_h__

#include "OpcUaStackServer/StandardVariableType/VariableBase.h"
#include "OpcUaStackServer/StandardObjectType/ObjectBase.h"

namespace OpcUaStackServer
{
   
   class DLLEXPORT ServerType
   : public ObjectBase
   {
     public:
       typedef boost::shared_ptr<ServerType> SPtr;
       typedef std::vector<ServerType::SPtr> Vec;
   
       ServerType(void);
       ServerType(const ServerType& value);
       virtual ~ServerType(void);

        //
        // Boolean
        //
        void auditing_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& auditing_Variable(void);
        bool get_Auditing_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_Auditing_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // DateTime
        //
        void estimatedReturnTime_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& estimatedReturnTime_Variable(void);
        bool get_EstimatedReturnTime_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_EstimatedReturnTime_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // TimeZoneDataType
        //
        void localTime_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& localTime_Variable(void);
        bool get_LocalTime_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_LocalTime_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // String (Array)
        //
        void namespaceArray_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& namespaceArray_Variable(void);
        bool get_NamespaceArray_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_NamespaceArray_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // String (Array)
        //
        void serverArray_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& serverArray_Variable(void);
        bool get_ServerArray_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_ServerArray_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // LocaleId (Array)
        //
        void serverCapabilities_LocaleIdArray_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& serverCapabilities_LocaleIdArray_Variable(void);
        bool get_ServerCapabilities_LocaleIdArray_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_ServerCapabilities_LocaleIdArray_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // UInt16
        //
        void serverCapabilities_MaxBrowseContinuationPoints_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& serverCapabilities_MaxBrowseContinuationPoints_Variable(void);
        bool get_ServerCapabilities_MaxBrowseContinuationPoints_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_ServerCapabilities_MaxBrowseContinuationPoints_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // UInt16
        //
        void serverCapabilities_MaxHistoryContinuationPoints_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& serverCapabilities_MaxHistoryContinuationPoints_Variable(void);
        bool get_ServerCapabilities_MaxHistoryContinuationPoints_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_ServerCapabilities_MaxHistoryContinuationPoints_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // UInt16
        //
        void serverCapabilities_MaxQueryContinuationPoints_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& serverCapabilities_MaxQueryContinuationPoints_Variable(void);
        bool get_ServerCapabilities_MaxQueryContinuationPoints_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_ServerCapabilities_MaxQueryContinuationPoints_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // Duration
        //
        void serverCapabilities_MinSupportedSampleRate_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& serverCapabilities_MinSupportedSampleRate_Variable(void);
        bool get_ServerCapabilities_MinSupportedSampleRate_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_ServerCapabilities_MinSupportedSampleRate_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // String (Array)
        //
        void serverCapabilities_ServerProfileArray_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& serverCapabilities_ServerProfileArray_Variable(void);
        bool get_ServerCapabilities_ServerProfileArray_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_ServerCapabilities_ServerProfileArray_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // SignedSoftwareCertificate (Array)
        //
        void serverCapabilities_SoftwareCertificates_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& serverCapabilities_SoftwareCertificates_Variable(void);
        bool get_ServerCapabilities_SoftwareCertificates_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_ServerCapabilities_SoftwareCertificates_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // Boolean
        //
        void serverDiagnostics_EnabledFlag_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& serverDiagnostics_EnabledFlag_Variable(void);
        bool get_ServerDiagnostics_EnabledFlag_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_ServerDiagnostics_EnabledFlag_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // UInt32
        //
        void serverDiagnostics_ServerDiagnosticsSummary_CumulatedSessionCount_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& serverDiagnostics_ServerDiagnosticsSummary_CumulatedSessionCount_Variable(void);
        bool get_ServerDiagnostics_ServerDiagnosticsSummary_CumulatedSessionCount_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_ServerDiagnostics_ServerDiagnosticsSummary_CumulatedSessionCount_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // UInt32
        //
        void serverDiagnostics_ServerDiagnosticsSummary_CumulatedSubscriptionCount_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& serverDiagnostics_ServerDiagnosticsSummary_CumulatedSubscriptionCount_Variable(void);
        bool get_ServerDiagnostics_ServerDiagnosticsSummary_CumulatedSubscriptionCount_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_ServerDiagnostics_ServerDiagnosticsSummary_CumulatedSubscriptionCount_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // UInt32
        //
        void serverDiagnostics_ServerDiagnosticsSummary_CurrentSessionCount_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& serverDiagnostics_ServerDiagnosticsSummary_CurrentSessionCount_Variable(void);
        bool get_ServerDiagnostics_ServerDiagnosticsSummary_CurrentSessionCount_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_ServerDiagnostics_ServerDiagnosticsSummary_CurrentSessionCount_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // UInt32
        //
        void serverDiagnostics_ServerDiagnosticsSummary_CurrentSubscriptionCount_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& serverDiagnostics_ServerDiagnosticsSummary_CurrentSubscriptionCount_Variable(void);
        bool get_ServerDiagnostics_ServerDiagnosticsSummary_CurrentSubscriptionCount_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_ServerDiagnostics_ServerDiagnosticsSummary_CurrentSubscriptionCount_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // UInt32
        //
        void serverDiagnostics_ServerDiagnosticsSummary_PublishingIntervalCount_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& serverDiagnostics_ServerDiagnosticsSummary_PublishingIntervalCount_Variable(void);
        bool get_ServerDiagnostics_ServerDiagnosticsSummary_PublishingIntervalCount_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_ServerDiagnostics_ServerDiagnosticsSummary_PublishingIntervalCount_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // UInt32
        //
        void serverDiagnostics_ServerDiagnosticsSummary_RejectedRequestsCount_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& serverDiagnostics_ServerDiagnosticsSummary_RejectedRequestsCount_Variable(void);
        bool get_ServerDiagnostics_ServerDiagnosticsSummary_RejectedRequestsCount_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_ServerDiagnostics_ServerDiagnosticsSummary_RejectedRequestsCount_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // UInt32
        //
        void serverDiagnostics_ServerDiagnosticsSummary_RejectedSessionCount_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& serverDiagnostics_ServerDiagnosticsSummary_RejectedSessionCount_Variable(void);
        bool get_ServerDiagnostics_ServerDiagnosticsSummary_RejectedSessionCount_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_ServerDiagnostics_ServerDiagnosticsSummary_RejectedSessionCount_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // UInt32
        //
        void serverDiagnostics_ServerDiagnosticsSummary_SecurityRejectedRequestsCount_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& serverDiagnostics_ServerDiagnosticsSummary_SecurityRejectedRequestsCount_Variable(void);
        bool get_ServerDiagnostics_ServerDiagnosticsSummary_SecurityRejectedRequestsCount_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_ServerDiagnostics_ServerDiagnosticsSummary_SecurityRejectedRequestsCount_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // UInt32
        //
        void serverDiagnostics_ServerDiagnosticsSummary_SecurityRejectedSessionCount_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& serverDiagnostics_ServerDiagnosticsSummary_SecurityRejectedSessionCount_Variable(void);
        bool get_ServerDiagnostics_ServerDiagnosticsSummary_SecurityRejectedSessionCount_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_ServerDiagnostics_ServerDiagnosticsSummary_SecurityRejectedSessionCount_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // UInt32
        //
        void serverDiagnostics_ServerDiagnosticsSummary_ServerViewCount_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& serverDiagnostics_ServerDiagnosticsSummary_ServerViewCount_Variable(void);
        bool get_ServerDiagnostics_ServerDiagnosticsSummary_ServerViewCount_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_ServerDiagnostics_ServerDiagnosticsSummary_ServerViewCount_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // UInt32
        //
        void serverDiagnostics_ServerDiagnosticsSummary_SessionAbortCount_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& serverDiagnostics_ServerDiagnosticsSummary_SessionAbortCount_Variable(void);
        bool get_ServerDiagnostics_ServerDiagnosticsSummary_SessionAbortCount_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_ServerDiagnostics_ServerDiagnosticsSummary_SessionAbortCount_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // UInt32
        //
        void serverDiagnostics_ServerDiagnosticsSummary_SessionTimeoutCount_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& serverDiagnostics_ServerDiagnosticsSummary_SessionTimeoutCount_Variable(void);
        bool get_ServerDiagnostics_ServerDiagnosticsSummary_SessionTimeoutCount_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_ServerDiagnostics_ServerDiagnosticsSummary_SessionTimeoutCount_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // ServerDiagnosticsSummaryDataType
        //
        void serverDiagnostics_ServerDiagnosticsSummary_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& serverDiagnostics_ServerDiagnosticsSummary_Variable(void);
        bool get_ServerDiagnostics_ServerDiagnosticsSummary_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_ServerDiagnostics_ServerDiagnosticsSummary_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // SessionDiagnosticsDataType (Array)
        //
        void serverDiagnostics_SessionsDiagnosticsSummary_SessionDiagnosticsArray_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& serverDiagnostics_SessionsDiagnosticsSummary_SessionDiagnosticsArray_Variable(void);
        bool get_ServerDiagnostics_SessionsDiagnosticsSummary_SessionDiagnosticsArray_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_ServerDiagnostics_SessionsDiagnosticsSummary_SessionDiagnosticsArray_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // SessionSecurityDiagnosticsDataType (Array)
        //
        void serverDiagnostics_SessionsDiagnosticsSummary_SessionSecurityDiagnosticsArray_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& serverDiagnostics_SessionsDiagnosticsSummary_SessionSecurityDiagnosticsArray_Variable(void);
        bool get_ServerDiagnostics_SessionsDiagnosticsSummary_SessionSecurityDiagnosticsArray_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_ServerDiagnostics_SessionsDiagnosticsSummary_SessionSecurityDiagnosticsArray_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // SubscriptionDiagnosticsDataType (Array)
        //
        void serverDiagnostics_SubscriptionDiagnosticsArray_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& serverDiagnostics_SubscriptionDiagnosticsArray_Variable(void);
        bool get_ServerDiagnostics_SubscriptionDiagnosticsArray_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_ServerDiagnostics_SubscriptionDiagnosticsArray_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // RedundancySupport
        //
        void serverRedundancy_RedundancySupport_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& serverRedundancy_RedundancySupport_Variable(void);
        bool get_ServerRedundancy_RedundancySupport_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_ServerRedundancy_RedundancySupport_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // UtcTime
        //
        void serverStatus_BuildInfo_BuildDate_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& serverStatus_BuildInfo_BuildDate_Variable(void);
        bool get_ServerStatus_BuildInfo_BuildDate_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_ServerStatus_BuildInfo_BuildDate_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // String
        //
        void serverStatus_BuildInfo_BuildNumber_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& serverStatus_BuildInfo_BuildNumber_Variable(void);
        bool get_ServerStatus_BuildInfo_BuildNumber_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_ServerStatus_BuildInfo_BuildNumber_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // String
        //
        void serverStatus_BuildInfo_ManufacturerName_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& serverStatus_BuildInfo_ManufacturerName_Variable(void);
        bool get_ServerStatus_BuildInfo_ManufacturerName_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_ServerStatus_BuildInfo_ManufacturerName_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // String
        //
        void serverStatus_BuildInfo_ProductName_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& serverStatus_BuildInfo_ProductName_Variable(void);
        bool get_ServerStatus_BuildInfo_ProductName_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_ServerStatus_BuildInfo_ProductName_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // String
        //
        void serverStatus_BuildInfo_ProductUri_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& serverStatus_BuildInfo_ProductUri_Variable(void);
        bool get_ServerStatus_BuildInfo_ProductUri_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_ServerStatus_BuildInfo_ProductUri_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // String
        //
        void serverStatus_BuildInfo_SoftwareVersion_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& serverStatus_BuildInfo_SoftwareVersion_Variable(void);
        bool get_ServerStatus_BuildInfo_SoftwareVersion_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_ServerStatus_BuildInfo_SoftwareVersion_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // BuildInfo
        //
        void serverStatus_BuildInfo_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& serverStatus_BuildInfo_Variable(void);
        bool get_ServerStatus_BuildInfo_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_ServerStatus_BuildInfo_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // UtcTime
        //
        void serverStatus_CurrentTime_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& serverStatus_CurrentTime_Variable(void);
        bool get_ServerStatus_CurrentTime_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_ServerStatus_CurrentTime_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // UInt32
        //
        void serverStatus_SecondsTillShutdown_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& serverStatus_SecondsTillShutdown_Variable(void);
        bool get_ServerStatus_SecondsTillShutdown_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_ServerStatus_SecondsTillShutdown_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // LocalizedText
        //
        void serverStatus_ShutdownReason_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& serverStatus_ShutdownReason_Variable(void);
        bool get_ServerStatus_ShutdownReason_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_ServerStatus_ShutdownReason_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // UtcTime
        //
        void serverStatus_StartTime_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& serverStatus_StartTime_Variable(void);
        bool get_ServerStatus_StartTime_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_ServerStatus_StartTime_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // ServerState
        //
        void serverStatus_State_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& serverStatus_State_Variable(void);
        bool get_ServerStatus_State_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_ServerStatus_State_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // ServerStatusDataType
        //
        void serverStatus_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& serverStatus_Variable(void);
        bool get_ServerStatus_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_ServerStatus_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // Byte
        //
        void serviceLevel_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& serviceLevel_Variable(void);
        bool get_ServiceLevel_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_ServiceLevel_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // VersionTime
        //
        void urisVersion_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& urisVersion_Variable(void);
        bool get_UrisVersion_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_UrisVersion_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        virtual void call_GetMonitoredItems_Method(OpcUaStackCore::ApplicationMethodContext* applicationMethodContext);

        virtual void call_RequestServerStateChange_Method(OpcUaStackCore::ApplicationMethodContext* applicationMethodContext);

        virtual void call_ResendData_Method(OpcUaStackCore::ApplicationMethodContext* applicationMethodContext);

        virtual void call_SetSubscriptionDurable_Method(OpcUaStackCore::ApplicationMethodContext* applicationMethodContext);
    
      private:
        ServerVariable::SPtr auditing_Variable_;
        ServerVariable::SPtr estimatedReturnTime_Variable_;
        ServerVariable::SPtr localTime_Variable_;
        ServerVariable::SPtr namespaceArray_Variable_;
        ServerVariable::SPtr serverArray_Variable_;
        ServerVariable::SPtr serverCapabilities_LocaleIdArray_Variable_;
        ServerVariable::SPtr serverCapabilities_MaxBrowseContinuationPoints_Variable_;
        ServerVariable::SPtr serverCapabilities_MaxHistoryContinuationPoints_Variable_;
        ServerVariable::SPtr serverCapabilities_MaxQueryContinuationPoints_Variable_;
        ServerVariable::SPtr serverCapabilities_MinSupportedSampleRate_Variable_;
        ServerVariable::SPtr serverCapabilities_ServerProfileArray_Variable_;
        ServerVariable::SPtr serverCapabilities_SoftwareCertificates_Variable_;
        ServerVariable::SPtr serverDiagnostics_EnabledFlag_Variable_;
        ServerVariable::SPtr serverDiagnostics_ServerDiagnosticsSummary_CumulatedSessionCount_Variable_;
        ServerVariable::SPtr serverDiagnostics_ServerDiagnosticsSummary_CumulatedSubscriptionCount_Variable_;
        ServerVariable::SPtr serverDiagnostics_ServerDiagnosticsSummary_CurrentSessionCount_Variable_;
        ServerVariable::SPtr serverDiagnostics_ServerDiagnosticsSummary_CurrentSubscriptionCount_Variable_;
        ServerVariable::SPtr serverDiagnostics_ServerDiagnosticsSummary_PublishingIntervalCount_Variable_;
        ServerVariable::SPtr serverDiagnostics_ServerDiagnosticsSummary_RejectedRequestsCount_Variable_;
        ServerVariable::SPtr serverDiagnostics_ServerDiagnosticsSummary_RejectedSessionCount_Variable_;
        ServerVariable::SPtr serverDiagnostics_ServerDiagnosticsSummary_SecurityRejectedRequestsCount_Variable_;
        ServerVariable::SPtr serverDiagnostics_ServerDiagnosticsSummary_SecurityRejectedSessionCount_Variable_;
        ServerVariable::SPtr serverDiagnostics_ServerDiagnosticsSummary_ServerViewCount_Variable_;
        ServerVariable::SPtr serverDiagnostics_ServerDiagnosticsSummary_SessionAbortCount_Variable_;
        ServerVariable::SPtr serverDiagnostics_ServerDiagnosticsSummary_SessionTimeoutCount_Variable_;
        ServerVariable::SPtr serverDiagnostics_ServerDiagnosticsSummary_Variable_;
        ServerVariable::SPtr serverDiagnostics_SessionsDiagnosticsSummary_SessionDiagnosticsArray_Variable_;
        ServerVariable::SPtr serverDiagnostics_SessionsDiagnosticsSummary_SessionSecurityDiagnosticsArray_Variable_;
        ServerVariable::SPtr serverDiagnostics_SubscriptionDiagnosticsArray_Variable_;
        ServerVariable::SPtr serverRedundancy_RedundancySupport_Variable_;
        ServerVariable::SPtr serverStatus_BuildInfo_BuildDate_Variable_;
        ServerVariable::SPtr serverStatus_BuildInfo_BuildNumber_Variable_;
        ServerVariable::SPtr serverStatus_BuildInfo_ManufacturerName_Variable_;
        ServerVariable::SPtr serverStatus_BuildInfo_ProductName_Variable_;
        ServerVariable::SPtr serverStatus_BuildInfo_ProductUri_Variable_;
        ServerVariable::SPtr serverStatus_BuildInfo_SoftwareVersion_Variable_;
        ServerVariable::SPtr serverStatus_BuildInfo_Variable_;
        ServerVariable::SPtr serverStatus_CurrentTime_Variable_;
        ServerVariable::SPtr serverStatus_SecondsTillShutdown_Variable_;
        ServerVariable::SPtr serverStatus_ShutdownReason_Variable_;
        ServerVariable::SPtr serverStatus_StartTime_Variable_;
        ServerVariable::SPtr serverStatus_State_Variable_;
        ServerVariable::SPtr serverStatus_Variable_;
        ServerVariable::SPtr serviceLevel_Variable_;
        ServerVariable::SPtr urisVersion_Variable_;
        ServerMethod::SPtr getMonitoredItems_Method_;
        ServerMethod::SPtr requestServerStateChange_Method_;
        ServerMethod::SPtr resendData_Method_;
        ServerMethod::SPtr setSubscriptionDurable_Method_;
   
   };

}

#endif
