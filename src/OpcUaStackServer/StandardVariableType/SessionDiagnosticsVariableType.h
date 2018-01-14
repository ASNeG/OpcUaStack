/*
    VariableTypeClass: SessionDiagnosticsVariableType

    Generated Source Code - please do not change this source code

    VariableTypeCodeGenerator Version:
        OpcUaStackCore - 3.0.1

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackServer_SessionDiagnosticsVariableType_h__
#define __OpcUaStackServer_SessionDiagnosticsVariableType_h__

#include <boost/shared_ptr.hpp>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackServer/VariableType/ServerVariables.h"
#include "OpcUaStackServer/StandardVariableType/BaseDataVariableType.h"

namespace OpcUaStackServer
{
    
    class DLLEXPORT SessionDiagnosticsVariableType
    : public BaseDataVariableType
    {
      public:
        typedef boost::shared_ptr<SessionDiagnosticsVariableType> SPtr;
    
        SessionDiagnosticsVariableType(void);
        virtual ~SessionDiagnosticsVariableType(void);
        virtual bool linkInstanceWithModel(const OpcUaNodeId& nodeId);
        
        BaseNodeClass::SPtr sessionId(void);
        bool setSessionId(const OpcUaDataValue& dataValue);
        bool getSessionId(OpcUaDataValue& dataValue);
        void setUpdateCallbackSessionId(Callback::SPtr& callback);
        
        BaseNodeClass::SPtr sessionName(void);
        bool setSessionName(const OpcUaDataValue& dataValue);
        bool getSessionName(OpcUaDataValue& dataValue);
        void setUpdateCallbackSessionName(Callback::SPtr& callback);
        
        BaseNodeClass::SPtr clientDescription(void);
        bool setClientDescription(const OpcUaDataValue& dataValue);
        bool getClientDescription(OpcUaDataValue& dataValue);
        void setUpdateCallbackClientDescription(Callback::SPtr& callback);
        
        BaseNodeClass::SPtr serverUri(void);
        bool setServerUri(const OpcUaDataValue& dataValue);
        bool getServerUri(OpcUaDataValue& dataValue);
        void setUpdateCallbackServerUri(Callback::SPtr& callback);
        
        BaseNodeClass::SPtr endpointUrl(void);
        bool setEndpointUrl(const OpcUaDataValue& dataValue);
        bool getEndpointUrl(OpcUaDataValue& dataValue);
        void setUpdateCallbackEndpointUrl(Callback::SPtr& callback);
        
        BaseNodeClass::SPtr localeIds(void);
        bool setLocaleIds(const OpcUaDataValue& dataValue);
        bool getLocaleIds(OpcUaDataValue& dataValue);
        void setUpdateCallbackLocaleIds(Callback::SPtr& callback);
        
        BaseNodeClass::SPtr actualSessionTimeout(void);
        bool setActualSessionTimeout(const OpcUaDataValue& dataValue);
        bool getActualSessionTimeout(OpcUaDataValue& dataValue);
        void setUpdateCallbackActualSessionTimeout(Callback::SPtr& callback);
        
        BaseNodeClass::SPtr maxResponseMessageSize(void);
        bool setMaxResponseMessageSize(const OpcUaDataValue& dataValue);
        bool getMaxResponseMessageSize(OpcUaDataValue& dataValue);
        void setUpdateCallbackMaxResponseMessageSize(Callback::SPtr& callback);
        
        BaseNodeClass::SPtr clientConnectionTime(void);
        bool setClientConnectionTime(const OpcUaDataValue& dataValue);
        bool getClientConnectionTime(OpcUaDataValue& dataValue);
        void setUpdateCallbackClientConnectionTime(Callback::SPtr& callback);
        
        BaseNodeClass::SPtr clientLastContactTime(void);
        bool setClientLastContactTime(const OpcUaDataValue& dataValue);
        bool getClientLastContactTime(OpcUaDataValue& dataValue);
        void setUpdateCallbackClientLastContactTime(Callback::SPtr& callback);
        
        BaseNodeClass::SPtr currentSubscriptionsCount(void);
        bool setCurrentSubscriptionsCount(const OpcUaDataValue& dataValue);
        bool getCurrentSubscriptionsCount(OpcUaDataValue& dataValue);
        void setUpdateCallbackCurrentSubscriptionsCount(Callback::SPtr& callback);
        
        BaseNodeClass::SPtr currentMonitoredItemsCount(void);
        bool setCurrentMonitoredItemsCount(const OpcUaDataValue& dataValue);
        bool getCurrentMonitoredItemsCount(OpcUaDataValue& dataValue);
        void setUpdateCallbackCurrentMonitoredItemsCount(Callback::SPtr& callback);
        
        BaseNodeClass::SPtr currentPublishRequestsInQueue(void);
        bool setCurrentPublishRequestsInQueue(const OpcUaDataValue& dataValue);
        bool getCurrentPublishRequestsInQueue(OpcUaDataValue& dataValue);
        void setUpdateCallbackCurrentPublishRequestsInQueue(Callback::SPtr& callback);
        
        BaseNodeClass::SPtr totalRequestCount(void);
        bool setTotalRequestCount(const OpcUaDataValue& dataValue);
        bool getTotalRequestCount(OpcUaDataValue& dataValue);
        void setUpdateCallbackTotalRequestCount(Callback::SPtr& callback);
        
        BaseNodeClass::SPtr unauthorizedRequestCount(void);
        bool setUnauthorizedRequestCount(const OpcUaDataValue& dataValue);
        bool getUnauthorizedRequestCount(OpcUaDataValue& dataValue);
        void setUpdateCallbackUnauthorizedRequestCount(Callback::SPtr& callback);
        
        BaseNodeClass::SPtr readCount(void);
        bool setReadCount(const OpcUaDataValue& dataValue);
        bool getReadCount(OpcUaDataValue& dataValue);
        void setUpdateCallbackReadCount(Callback::SPtr& callback);
        
        BaseNodeClass::SPtr historyReadCount(void);
        bool setHistoryReadCount(const OpcUaDataValue& dataValue);
        bool getHistoryReadCount(OpcUaDataValue& dataValue);
        void setUpdateCallbackHistoryReadCount(Callback::SPtr& callback);
        
        BaseNodeClass::SPtr writeCount(void);
        bool setWriteCount(const OpcUaDataValue& dataValue);
        bool getWriteCount(OpcUaDataValue& dataValue);
        void setUpdateCallbackWriteCount(Callback::SPtr& callback);
        
        BaseNodeClass::SPtr historyUpdateCount(void);
        bool setHistoryUpdateCount(const OpcUaDataValue& dataValue);
        bool getHistoryUpdateCount(OpcUaDataValue& dataValue);
        void setUpdateCallbackHistoryUpdateCount(Callback::SPtr& callback);
        
        BaseNodeClass::SPtr callCount(void);
        bool setCallCount(const OpcUaDataValue& dataValue);
        bool getCallCount(OpcUaDataValue& dataValue);
        void setUpdateCallbackCallCount(Callback::SPtr& callback);
        
        BaseNodeClass::SPtr createMonitoredItemsCount(void);
        bool setCreateMonitoredItemsCount(const OpcUaDataValue& dataValue);
        bool getCreateMonitoredItemsCount(OpcUaDataValue& dataValue);
        void setUpdateCallbackCreateMonitoredItemsCount(Callback::SPtr& callback);
        
        BaseNodeClass::SPtr modifyMonitoredItemsCount(void);
        bool setModifyMonitoredItemsCount(const OpcUaDataValue& dataValue);
        bool getModifyMonitoredItemsCount(OpcUaDataValue& dataValue);
        void setUpdateCallbackModifyMonitoredItemsCount(Callback::SPtr& callback);
        
        BaseNodeClass::SPtr setMonitoringModeCount(void);
        bool setSetMonitoringModeCount(const OpcUaDataValue& dataValue);
        bool getSetMonitoringModeCount(OpcUaDataValue& dataValue);
        void setUpdateCallbackSetMonitoringModeCount(Callback::SPtr& callback);
        
        BaseNodeClass::SPtr setTriggeringCount(void);
        bool setSetTriggeringCount(const OpcUaDataValue& dataValue);
        bool getSetTriggeringCount(OpcUaDataValue& dataValue);
        void setUpdateCallbackSetTriggeringCount(Callback::SPtr& callback);
        
        BaseNodeClass::SPtr deleteMonitoredItemsCount(void);
        bool setDeleteMonitoredItemsCount(const OpcUaDataValue& dataValue);
        bool getDeleteMonitoredItemsCount(OpcUaDataValue& dataValue);
        void setUpdateCallbackDeleteMonitoredItemsCount(Callback::SPtr& callback);
        
        BaseNodeClass::SPtr createSubscriptionCount(void);
        bool setCreateSubscriptionCount(const OpcUaDataValue& dataValue);
        bool getCreateSubscriptionCount(OpcUaDataValue& dataValue);
        void setUpdateCallbackCreateSubscriptionCount(Callback::SPtr& callback);
        
        BaseNodeClass::SPtr modifySubscriptionCount(void);
        bool setModifySubscriptionCount(const OpcUaDataValue& dataValue);
        bool getModifySubscriptionCount(OpcUaDataValue& dataValue);
        void setUpdateCallbackModifySubscriptionCount(Callback::SPtr& callback);
        
        BaseNodeClass::SPtr setPublishingModeCount(void);
        bool setSetPublishingModeCount(const OpcUaDataValue& dataValue);
        bool getSetPublishingModeCount(OpcUaDataValue& dataValue);
        void setUpdateCallbackSetPublishingModeCount(Callback::SPtr& callback);
        
        BaseNodeClass::SPtr publishCount(void);
        bool setPublishCount(const OpcUaDataValue& dataValue);
        bool getPublishCount(OpcUaDataValue& dataValue);
        void setUpdateCallbackPublishCount(Callback::SPtr& callback);
        
        BaseNodeClass::SPtr republishCount(void);
        bool setRepublishCount(const OpcUaDataValue& dataValue);
        bool getRepublishCount(OpcUaDataValue& dataValue);
        void setUpdateCallbackRepublishCount(Callback::SPtr& callback);
        
        BaseNodeClass::SPtr transferSubscriptionsCount(void);
        bool setTransferSubscriptionsCount(const OpcUaDataValue& dataValue);
        bool getTransferSubscriptionsCount(OpcUaDataValue& dataValue);
        void setUpdateCallbackTransferSubscriptionsCount(Callback::SPtr& callback);
        
        BaseNodeClass::SPtr deleteSubscriptionsCount(void);
        bool setDeleteSubscriptionsCount(const OpcUaDataValue& dataValue);
        bool getDeleteSubscriptionsCount(OpcUaDataValue& dataValue);
        void setUpdateCallbackDeleteSubscriptionsCount(Callback::SPtr& callback);
        
        BaseNodeClass::SPtr addNodesCount(void);
        bool setAddNodesCount(const OpcUaDataValue& dataValue);
        bool getAddNodesCount(OpcUaDataValue& dataValue);
        void setUpdateCallbackAddNodesCount(Callback::SPtr& callback);
        
        BaseNodeClass::SPtr addReferencesCount(void);
        bool setAddReferencesCount(const OpcUaDataValue& dataValue);
        bool getAddReferencesCount(OpcUaDataValue& dataValue);
        void setUpdateCallbackAddReferencesCount(Callback::SPtr& callback);
        
        BaseNodeClass::SPtr deleteNodesCount(void);
        bool setDeleteNodesCount(const OpcUaDataValue& dataValue);
        bool getDeleteNodesCount(OpcUaDataValue& dataValue);
        void setUpdateCallbackDeleteNodesCount(Callback::SPtr& callback);
        
        BaseNodeClass::SPtr deleteReferencesCount(void);
        bool setDeleteReferencesCount(const OpcUaDataValue& dataValue);
        bool getDeleteReferencesCount(OpcUaDataValue& dataValue);
        void setUpdateCallbackDeleteReferencesCount(Callback::SPtr& callback);
        
        BaseNodeClass::SPtr browseCount(void);
        bool setBrowseCount(const OpcUaDataValue& dataValue);
        bool getBrowseCount(OpcUaDataValue& dataValue);
        void setUpdateCallbackBrowseCount(Callback::SPtr& callback);
        
        BaseNodeClass::SPtr browseNextCount(void);
        bool setBrowseNextCount(const OpcUaDataValue& dataValue);
        bool getBrowseNextCount(OpcUaDataValue& dataValue);
        void setUpdateCallbackBrowseNextCount(Callback::SPtr& callback);
        
        BaseNodeClass::SPtr translateBrowsePathsToNodeIdsCount(void);
        bool setTranslateBrowsePathsToNodeIdsCount(const OpcUaDataValue& dataValue);
        bool getTranslateBrowsePathsToNodeIdsCount(OpcUaDataValue& dataValue);
        void setUpdateCallbackTranslateBrowsePathsToNodeIdsCount(Callback::SPtr& callback);
        
        BaseNodeClass::SPtr queryFirstCount(void);
        bool setQueryFirstCount(const OpcUaDataValue& dataValue);
        bool getQueryFirstCount(OpcUaDataValue& dataValue);
        void setUpdateCallbackQueryFirstCount(Callback::SPtr& callback);
        
        BaseNodeClass::SPtr queryNextCount(void);
        bool setQueryNextCount(const OpcUaDataValue& dataValue);
        bool getQueryNextCount(OpcUaDataValue& dataValue);
        void setUpdateCallbackQueryNextCount(Callback::SPtr& callback);
        
        BaseNodeClass::SPtr registerNodesCount(void);
        bool setRegisterNodesCount(const OpcUaDataValue& dataValue);
        bool getRegisterNodesCount(OpcUaDataValue& dataValue);
        void setUpdateCallbackRegisterNodesCount(Callback::SPtr& callback);
        
        BaseNodeClass::SPtr unregisterNodesCount(void);
        bool setUnregisterNodesCount(const OpcUaDataValue& dataValue);
        bool getUnregisterNodesCount(OpcUaDataValue& dataValue);
        void setUpdateCallbackUnregisterNodesCount(Callback::SPtr& callback);
        
      private:
        std::string namespaceName_;
        uint16_t namespaceIndex_;
        ServerVariable::SPtr sessionId_;
        ServerVariable::SPtr sessionName_;
        ServerVariable::SPtr clientDescription_;
        ServerVariable::SPtr serverUri_;
        ServerVariable::SPtr endpointUrl_;
        ServerVariable::SPtr localeIds_;
        ServerVariable::SPtr actualSessionTimeout_;
        ServerVariable::SPtr maxResponseMessageSize_;
        ServerVariable::SPtr clientConnectionTime_;
        ServerVariable::SPtr clientLastContactTime_;
        ServerVariable::SPtr currentSubscriptionsCount_;
        ServerVariable::SPtr currentMonitoredItemsCount_;
        ServerVariable::SPtr currentPublishRequestsInQueue_;
        ServerVariable::SPtr totalRequestCount_;
        ServerVariable::SPtr unauthorizedRequestCount_;
        ServerVariable::SPtr readCount_;
        ServerVariable::SPtr historyReadCount_;
        ServerVariable::SPtr writeCount_;
        ServerVariable::SPtr historyUpdateCount_;
        ServerVariable::SPtr callCount_;
        ServerVariable::SPtr createMonitoredItemsCount_;
        ServerVariable::SPtr modifyMonitoredItemsCount_;
        ServerVariable::SPtr setMonitoringModeCount_;
        ServerVariable::SPtr setTriggeringCount_;
        ServerVariable::SPtr deleteMonitoredItemsCount_;
        ServerVariable::SPtr createSubscriptionCount_;
        ServerVariable::SPtr modifySubscriptionCount_;
        ServerVariable::SPtr setPublishingModeCount_;
        ServerVariable::SPtr publishCount_;
        ServerVariable::SPtr republishCount_;
        ServerVariable::SPtr transferSubscriptionsCount_;
        ServerVariable::SPtr deleteSubscriptionsCount_;
        ServerVariable::SPtr addNodesCount_;
        ServerVariable::SPtr addReferencesCount_;
        ServerVariable::SPtr deleteNodesCount_;
        ServerVariable::SPtr deleteReferencesCount_;
        ServerVariable::SPtr browseCount_;
        ServerVariable::SPtr browseNextCount_;
        ServerVariable::SPtr translateBrowsePathsToNodeIdsCount_;
        ServerVariable::SPtr queryFirstCount_;
        ServerVariable::SPtr queryNextCount_;
        ServerVariable::SPtr registerNodesCount_;
        ServerVariable::SPtr unregisterNodesCount_;
    
    };

}

#endif
