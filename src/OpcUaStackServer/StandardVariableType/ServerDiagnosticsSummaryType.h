/*
    VariableTypeClass: ServerDiagnosticsSummaryType

    Generated Source Code - please do not change this source code

    VariableTypeCodeGenerator Version:
        OpcUaStackCore - 3.0.1

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackServer_ServerDiagnosticsSummaryType_h__
#define __OpcUaStackServer_ServerDiagnosticsSummaryType_h__

#include <boost/shared_ptr.hpp>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackServer/VariableType/ServerVariables.h"
#include "OpcUaStackServer/StandardVariableType/BaseDataVariableType.h"

namespace OpcUaStackServer
{
    
    class DLLEXPORT ServerDiagnosticsSummaryType
    : public BaseDataVariableType
    {
      public:
        typedef boost::shared_ptr<ServerDiagnosticsSummaryType> SPtr;
    
        ServerDiagnosticsSummaryType(void);
        virtual ~ServerDiagnosticsSummaryType(void);
        virtual bool linkInstanceWithModel(const OpcUaNodeId& nodeId);
        
        BaseNodeClass::SPtr serverViewCount(void);
        bool setServerViewCount(const OpcUaDataValue& dataValue);
        bool getServerViewCount(OpcUaDataValue& dataValue);
        void setUpdateCallbackServerViewCount(Callback::SPtr& callback);
        
        BaseNodeClass::SPtr currentSessionCount(void);
        bool setCurrentSessionCount(const OpcUaDataValue& dataValue);
        bool getCurrentSessionCount(OpcUaDataValue& dataValue);
        void setUpdateCallbackCurrentSessionCount(Callback::SPtr& callback);
        
        BaseNodeClass::SPtr cumulatedSessionCount(void);
        bool setCumulatedSessionCount(const OpcUaDataValue& dataValue);
        bool getCumulatedSessionCount(OpcUaDataValue& dataValue);
        void setUpdateCallbackCumulatedSessionCount(Callback::SPtr& callback);
        
        BaseNodeClass::SPtr securityRejectedSessionCount(void);
        bool setSecurityRejectedSessionCount(const OpcUaDataValue& dataValue);
        bool getSecurityRejectedSessionCount(OpcUaDataValue& dataValue);
        void setUpdateCallbackSecurityRejectedSessionCount(Callback::SPtr& callback);
        
        BaseNodeClass::SPtr rejectedSessionCount(void);
        bool setRejectedSessionCount(const OpcUaDataValue& dataValue);
        bool getRejectedSessionCount(OpcUaDataValue& dataValue);
        void setUpdateCallbackRejectedSessionCount(Callback::SPtr& callback);
        
        BaseNodeClass::SPtr sessionTimeoutCount(void);
        bool setSessionTimeoutCount(const OpcUaDataValue& dataValue);
        bool getSessionTimeoutCount(OpcUaDataValue& dataValue);
        void setUpdateCallbackSessionTimeoutCount(Callback::SPtr& callback);
        
        BaseNodeClass::SPtr sessionAbortCount(void);
        bool setSessionAbortCount(const OpcUaDataValue& dataValue);
        bool getSessionAbortCount(OpcUaDataValue& dataValue);
        void setUpdateCallbackSessionAbortCount(Callback::SPtr& callback);
        
        BaseNodeClass::SPtr publishingIntervalCount(void);
        bool setPublishingIntervalCount(const OpcUaDataValue& dataValue);
        bool getPublishingIntervalCount(OpcUaDataValue& dataValue);
        void setUpdateCallbackPublishingIntervalCount(Callback::SPtr& callback);
        
        BaseNodeClass::SPtr currentSubscriptionCount(void);
        bool setCurrentSubscriptionCount(const OpcUaDataValue& dataValue);
        bool getCurrentSubscriptionCount(OpcUaDataValue& dataValue);
        void setUpdateCallbackCurrentSubscriptionCount(Callback::SPtr& callback);
        
        BaseNodeClass::SPtr cumulatedSubscriptionCount(void);
        bool setCumulatedSubscriptionCount(const OpcUaDataValue& dataValue);
        bool getCumulatedSubscriptionCount(OpcUaDataValue& dataValue);
        void setUpdateCallbackCumulatedSubscriptionCount(Callback::SPtr& callback);
        
        BaseNodeClass::SPtr securityRejectedRequestsCount(void);
        bool setSecurityRejectedRequestsCount(const OpcUaDataValue& dataValue);
        bool getSecurityRejectedRequestsCount(OpcUaDataValue& dataValue);
        void setUpdateCallbackSecurityRejectedRequestsCount(Callback::SPtr& callback);
        
        BaseNodeClass::SPtr rejectedRequestsCount(void);
        bool setRejectedRequestsCount(const OpcUaDataValue& dataValue);
        bool getRejectedRequestsCount(OpcUaDataValue& dataValue);
        void setUpdateCallbackRejectedRequestsCount(Callback::SPtr& callback);
        
      private:
        std::string namespaceName_;
        uint16_t namespaceIndex_;
        ServerVariable::SPtr serverViewCount_;
        ServerVariable::SPtr currentSessionCount_;
        ServerVariable::SPtr cumulatedSessionCount_;
        ServerVariable::SPtr securityRejectedSessionCount_;
        ServerVariable::SPtr rejectedSessionCount_;
        ServerVariable::SPtr sessionTimeoutCount_;
        ServerVariable::SPtr sessionAbortCount_;
        ServerVariable::SPtr publishingIntervalCount_;
        ServerVariable::SPtr currentSubscriptionCount_;
        ServerVariable::SPtr cumulatedSubscriptionCount_;
        ServerVariable::SPtr securityRejectedRequestsCount_;
        ServerVariable::SPtr rejectedRequestsCount_;
    
    };

}

#endif
