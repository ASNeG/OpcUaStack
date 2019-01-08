/*
    VariableTypeClass: ServerDiagnosticsSummaryType

    Generated Source Code - please do not change this source code

    VariableTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

    Autor:     Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackServer_ServerDiagnosticsSummaryType_h__
#define __OpcUaStackServer_ServerDiagnosticsSummaryType_h__

#include "OpcUaStackServer/StandardVariableType/VariableBase.h"

namespace OpcUaStackServer
{
   
   class DLLEXPORT ServerDiagnosticsSummaryType
   : public VariableBase
   {
     public:
       typedef boost::shared_ptr<ServerDiagnosticsSummaryType> SPtr;
       typedef std::vector<ServerDiagnosticsSummaryType::SPtr> Vec;
   
       ServerDiagnosticsSummaryType(void);
       ServerDiagnosticsSummaryType(const ServerDiagnosticsSummaryType& value);
       virtual ~ServerDiagnosticsSummaryType(void);

        //
        // UInt32
        //
        void cumulatedSessionCount_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& cumulatedSessionCount_Variable(void);
        bool get_CumulatedSessionCount_Variable(OpcUaDataValue& dataValue);
        bool set_CumulatedSessionCount_Variable(const OpcUaDataValue& dataValue);

        //
        // UInt32
        //
        void cumulatedSubscriptionCount_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& cumulatedSubscriptionCount_Variable(void);
        bool get_CumulatedSubscriptionCount_Variable(OpcUaDataValue& dataValue);
        bool set_CumulatedSubscriptionCount_Variable(const OpcUaDataValue& dataValue);

        //
        // UInt32
        //
        void currentSessionCount_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& currentSessionCount_Variable(void);
        bool get_CurrentSessionCount_Variable(OpcUaDataValue& dataValue);
        bool set_CurrentSessionCount_Variable(const OpcUaDataValue& dataValue);

        //
        // UInt32
        //
        void currentSubscriptionCount_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& currentSubscriptionCount_Variable(void);
        bool get_CurrentSubscriptionCount_Variable(OpcUaDataValue& dataValue);
        bool set_CurrentSubscriptionCount_Variable(const OpcUaDataValue& dataValue);

        //
        // UInt32
        //
        void publishingIntervalCount_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& publishingIntervalCount_Variable(void);
        bool get_PublishingIntervalCount_Variable(OpcUaDataValue& dataValue);
        bool set_PublishingIntervalCount_Variable(const OpcUaDataValue& dataValue);

        //
        // UInt32
        //
        void rejectedRequestsCount_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& rejectedRequestsCount_Variable(void);
        bool get_RejectedRequestsCount_Variable(OpcUaDataValue& dataValue);
        bool set_RejectedRequestsCount_Variable(const OpcUaDataValue& dataValue);

        //
        // UInt32
        //
        void rejectedSessionCount_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& rejectedSessionCount_Variable(void);
        bool get_RejectedSessionCount_Variable(OpcUaDataValue& dataValue);
        bool set_RejectedSessionCount_Variable(const OpcUaDataValue& dataValue);

        //
        // UInt32
        //
        void securityRejectedRequestsCount_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& securityRejectedRequestsCount_Variable(void);
        bool get_SecurityRejectedRequestsCount_Variable(OpcUaDataValue& dataValue);
        bool set_SecurityRejectedRequestsCount_Variable(const OpcUaDataValue& dataValue);

        //
        // UInt32
        //
        void securityRejectedSessionCount_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& securityRejectedSessionCount_Variable(void);
        bool get_SecurityRejectedSessionCount_Variable(OpcUaDataValue& dataValue);
        bool set_SecurityRejectedSessionCount_Variable(const OpcUaDataValue& dataValue);

        //
        // UInt32
        //
        void serverViewCount_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& serverViewCount_Variable(void);
        bool get_ServerViewCount_Variable(OpcUaDataValue& dataValue);
        bool set_ServerViewCount_Variable(const OpcUaDataValue& dataValue);

        //
        // UInt32
        //
        void sessionAbortCount_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& sessionAbortCount_Variable(void);
        bool get_SessionAbortCount_Variable(OpcUaDataValue& dataValue);
        bool set_SessionAbortCount_Variable(const OpcUaDataValue& dataValue);

        //
        // UInt32
        //
        void sessionTimeoutCount_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& sessionTimeoutCount_Variable(void);
        bool get_SessionTimeoutCount_Variable(OpcUaDataValue& dataValue);
        bool set_SessionTimeoutCount_Variable(const OpcUaDataValue& dataValue);

        //
        // ServerDiagnosticsSummaryDataType (Array)
        //
        void variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& variable(void);
        bool get_Variable(OpcUaDataValue& dataValue);
        bool set_Variable(const OpcUaDataValue& dataValue);
    
      private:
        ServerVariable::SPtr cumulatedSessionCount_Variable_;
        ServerVariable::SPtr cumulatedSubscriptionCount_Variable_;
        ServerVariable::SPtr currentSessionCount_Variable_;
        ServerVariable::SPtr currentSubscriptionCount_Variable_;
        ServerVariable::SPtr publishingIntervalCount_Variable_;
        ServerVariable::SPtr rejectedRequestsCount_Variable_;
        ServerVariable::SPtr rejectedSessionCount_Variable_;
        ServerVariable::SPtr securityRejectedRequestsCount_Variable_;
        ServerVariable::SPtr securityRejectedSessionCount_Variable_;
        ServerVariable::SPtr serverViewCount_Variable_;
        ServerVariable::SPtr sessionAbortCount_Variable_;
        ServerVariable::SPtr sessionTimeoutCount_Variable_;
        ServerVariable::SPtr variable_;
   
   };

}

#endif
