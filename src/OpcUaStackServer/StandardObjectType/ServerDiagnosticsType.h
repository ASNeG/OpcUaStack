/*
    ObjectTypeClass: ServerDiagnosticsType

    Generated Source Code - please do not change this source code

    ObjectTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

    Autor:     Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackServer_ServerDiagnosticsType_h__
#define __OpcUaStackServer_ServerDiagnosticsType_h__

#include "OpcUaStackServer/StandardVariableType/VariableBase.h"
#include "OpcUaStackServer/StandardObjectType/ObjectBase.h"

namespace OpcUaStackServer
{
   
   class DLLEXPORT ServerDiagnosticsType
   : public ObjectBase
   {
     public:
       typedef boost::shared_ptr<ServerDiagnosticsType> SPtr;
       typedef std::vector<ServerDiagnosticsType::SPtr> Vec;
   
       ServerDiagnosticsType(void);
       ServerDiagnosticsType(const ServerDiagnosticsType& value);
       virtual ~ServerDiagnosticsType(void);

        //
        // Boolean
        //
        void enabledFlag_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& enabledFlag_Variable(void);
        bool get_EnabledFlag_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_EnabledFlag_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // SamplingIntervalDiagnosticsDataType (Array)
        //
        void samplingIntervalDiagnosticsArray_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& samplingIntervalDiagnosticsArray_Variable(void);
        bool get_SamplingIntervalDiagnosticsArray_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_SamplingIntervalDiagnosticsArray_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // UInt32
        //
        void serverDiagnosticsSummary_CumulatedSessionCount_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& serverDiagnosticsSummary_CumulatedSessionCount_Variable(void);
        bool get_ServerDiagnosticsSummary_CumulatedSessionCount_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_ServerDiagnosticsSummary_CumulatedSessionCount_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // UInt32
        //
        void serverDiagnosticsSummary_CumulatedSubscriptionCount_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& serverDiagnosticsSummary_CumulatedSubscriptionCount_Variable(void);
        bool get_ServerDiagnosticsSummary_CumulatedSubscriptionCount_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_ServerDiagnosticsSummary_CumulatedSubscriptionCount_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // UInt32
        //
        void serverDiagnosticsSummary_CurrentSessionCount_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& serverDiagnosticsSummary_CurrentSessionCount_Variable(void);
        bool get_ServerDiagnosticsSummary_CurrentSessionCount_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_ServerDiagnosticsSummary_CurrentSessionCount_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // UInt32
        //
        void serverDiagnosticsSummary_CurrentSubscriptionCount_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& serverDiagnosticsSummary_CurrentSubscriptionCount_Variable(void);
        bool get_ServerDiagnosticsSummary_CurrentSubscriptionCount_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_ServerDiagnosticsSummary_CurrentSubscriptionCount_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // UInt32
        //
        void serverDiagnosticsSummary_PublishingIntervalCount_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& serverDiagnosticsSummary_PublishingIntervalCount_Variable(void);
        bool get_ServerDiagnosticsSummary_PublishingIntervalCount_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_ServerDiagnosticsSummary_PublishingIntervalCount_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // UInt32
        //
        void serverDiagnosticsSummary_RejectedRequestsCount_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& serverDiagnosticsSummary_RejectedRequestsCount_Variable(void);
        bool get_ServerDiagnosticsSummary_RejectedRequestsCount_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_ServerDiagnosticsSummary_RejectedRequestsCount_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // UInt32
        //
        void serverDiagnosticsSummary_RejectedSessionCount_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& serverDiagnosticsSummary_RejectedSessionCount_Variable(void);
        bool get_ServerDiagnosticsSummary_RejectedSessionCount_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_ServerDiagnosticsSummary_RejectedSessionCount_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // UInt32
        //
        void serverDiagnosticsSummary_SecurityRejectedRequestsCount_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& serverDiagnosticsSummary_SecurityRejectedRequestsCount_Variable(void);
        bool get_ServerDiagnosticsSummary_SecurityRejectedRequestsCount_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_ServerDiagnosticsSummary_SecurityRejectedRequestsCount_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // UInt32
        //
        void serverDiagnosticsSummary_SecurityRejectedSessionCount_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& serverDiagnosticsSummary_SecurityRejectedSessionCount_Variable(void);
        bool get_ServerDiagnosticsSummary_SecurityRejectedSessionCount_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_ServerDiagnosticsSummary_SecurityRejectedSessionCount_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // UInt32
        //
        void serverDiagnosticsSummary_ServerViewCount_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& serverDiagnosticsSummary_ServerViewCount_Variable(void);
        bool get_ServerDiagnosticsSummary_ServerViewCount_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_ServerDiagnosticsSummary_ServerViewCount_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // UInt32
        //
        void serverDiagnosticsSummary_SessionAbortCount_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& serverDiagnosticsSummary_SessionAbortCount_Variable(void);
        bool get_ServerDiagnosticsSummary_SessionAbortCount_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_ServerDiagnosticsSummary_SessionAbortCount_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // UInt32
        //
        void serverDiagnosticsSummary_SessionTimeoutCount_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& serverDiagnosticsSummary_SessionTimeoutCount_Variable(void);
        bool get_ServerDiagnosticsSummary_SessionTimeoutCount_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_ServerDiagnosticsSummary_SessionTimeoutCount_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // ServerDiagnosticsSummaryDataType
        //
        void serverDiagnosticsSummary_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& serverDiagnosticsSummary_Variable(void);
        bool get_ServerDiagnosticsSummary_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_ServerDiagnosticsSummary_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // SessionDiagnosticsDataType (Array)
        //
        void sessionsDiagnosticsSummary_SessionDiagnosticsArray_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& sessionsDiagnosticsSummary_SessionDiagnosticsArray_Variable(void);
        bool get_SessionsDiagnosticsSummary_SessionDiagnosticsArray_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_SessionsDiagnosticsSummary_SessionDiagnosticsArray_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // SessionSecurityDiagnosticsDataType (Array)
        //
        void sessionsDiagnosticsSummary_SessionSecurityDiagnosticsArray_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& sessionsDiagnosticsSummary_SessionSecurityDiagnosticsArray_Variable(void);
        bool get_SessionsDiagnosticsSummary_SessionSecurityDiagnosticsArray_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_SessionsDiagnosticsSummary_SessionSecurityDiagnosticsArray_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // SubscriptionDiagnosticsDataType (Array)
        //
        void subscriptionDiagnosticsArray_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& subscriptionDiagnosticsArray_Variable(void);
        bool get_SubscriptionDiagnosticsArray_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_SubscriptionDiagnosticsArray_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);
    
      private:
        ServerVariable::SPtr enabledFlag_Variable_;
        ServerVariable::SPtr samplingIntervalDiagnosticsArray_Variable_;
        ServerVariable::SPtr serverDiagnosticsSummary_CumulatedSessionCount_Variable_;
        ServerVariable::SPtr serverDiagnosticsSummary_CumulatedSubscriptionCount_Variable_;
        ServerVariable::SPtr serverDiagnosticsSummary_CurrentSessionCount_Variable_;
        ServerVariable::SPtr serverDiagnosticsSummary_CurrentSubscriptionCount_Variable_;
        ServerVariable::SPtr serverDiagnosticsSummary_PublishingIntervalCount_Variable_;
        ServerVariable::SPtr serverDiagnosticsSummary_RejectedRequestsCount_Variable_;
        ServerVariable::SPtr serverDiagnosticsSummary_RejectedSessionCount_Variable_;
        ServerVariable::SPtr serverDiagnosticsSummary_SecurityRejectedRequestsCount_Variable_;
        ServerVariable::SPtr serverDiagnosticsSummary_SecurityRejectedSessionCount_Variable_;
        ServerVariable::SPtr serverDiagnosticsSummary_ServerViewCount_Variable_;
        ServerVariable::SPtr serverDiagnosticsSummary_SessionAbortCount_Variable_;
        ServerVariable::SPtr serverDiagnosticsSummary_SessionTimeoutCount_Variable_;
        ServerVariable::SPtr serverDiagnosticsSummary_Variable_;
        ServerVariable::SPtr sessionsDiagnosticsSummary_SessionDiagnosticsArray_Variable_;
        ServerVariable::SPtr sessionsDiagnosticsSummary_SessionSecurityDiagnosticsArray_Variable_;
        ServerVariable::SPtr subscriptionDiagnosticsArray_Variable_;
   
   };

}

#endif
