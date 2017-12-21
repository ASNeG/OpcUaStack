/*
    VariableTypeClass: SubscriptionDiagnosticsType

    Generated Source Code - please do not change this source code

    VariableTypeCodeGenerator Version:
        OpcUaStackCore - 3.0.1

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackServer_SubscriptionDiagnosticsType_h__
#define __OpcUaStackServer_SubscriptionDiagnosticsType_h__

#include <boost/shared_ptr.hpp>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackServer/VariableType/ServerVariables.h"
#include "OpcUaStackServer/StandardVariableType/BaseDataVariableType.h"

namespace OpcUaStackServer
{
    
    class DLLEXPORT SubscriptionDiagnosticsType
    : public BaseDataVariableType
    {
      public:
        typedef boost::shared_ptr<SubscriptionDiagnosticsType> SPtr;
    
        SubscriptionDiagnosticsType(void);
        virtual ~SubscriptionDiagnosticsType(void);
        virtual bool linkInstanceWithModel(const OpcUaNodeId& nodeId);
        
        BaseNodeClass::SPtr sessionId(void);
        bool setSessionId(const OpcUaDataValue& dataValue);
        bool getSessionId(OpcUaDataValue& dataValue);
        void setUpdateCallbackSessionId(Callback::SPtr& callback);
        
        BaseNodeClass::SPtr subscriptionId(void);
        bool setSubscriptionId(const OpcUaDataValue& dataValue);
        bool getSubscriptionId(OpcUaDataValue& dataValue);
        void setUpdateCallbackSubscriptionId(Callback::SPtr& callback);
        
        BaseNodeClass::SPtr priority(void);
        bool setPriority(const OpcUaDataValue& dataValue);
        bool getPriority(OpcUaDataValue& dataValue);
        void setUpdateCallbackPriority(Callback::SPtr& callback);
        
        BaseNodeClass::SPtr publishingInterval(void);
        bool setPublishingInterval(const OpcUaDataValue& dataValue);
        bool getPublishingInterval(OpcUaDataValue& dataValue);
        void setUpdateCallbackPublishingInterval(Callback::SPtr& callback);
        
        BaseNodeClass::SPtr maxKeepAliveCount(void);
        bool setMaxKeepAliveCount(const OpcUaDataValue& dataValue);
        bool getMaxKeepAliveCount(OpcUaDataValue& dataValue);
        void setUpdateCallbackMaxKeepAliveCount(Callback::SPtr& callback);
        
        BaseNodeClass::SPtr maxLifetimeCount(void);
        bool setMaxLifetimeCount(const OpcUaDataValue& dataValue);
        bool getMaxLifetimeCount(OpcUaDataValue& dataValue);
        void setUpdateCallbackMaxLifetimeCount(Callback::SPtr& callback);
        
        BaseNodeClass::SPtr maxNotificationsPerPublish(void);
        bool setMaxNotificationsPerPublish(const OpcUaDataValue& dataValue);
        bool getMaxNotificationsPerPublish(OpcUaDataValue& dataValue);
        void setUpdateCallbackMaxNotificationsPerPublish(Callback::SPtr& callback);
        
        BaseNodeClass::SPtr publishingEnabled(void);
        bool setPublishingEnabled(const OpcUaDataValue& dataValue);
        bool getPublishingEnabled(OpcUaDataValue& dataValue);
        void setUpdateCallbackPublishingEnabled(Callback::SPtr& callback);
        
        BaseNodeClass::SPtr modifyCount(void);
        bool setModifyCount(const OpcUaDataValue& dataValue);
        bool getModifyCount(OpcUaDataValue& dataValue);
        void setUpdateCallbackModifyCount(Callback::SPtr& callback);
        
        BaseNodeClass::SPtr enableCount(void);
        bool setEnableCount(const OpcUaDataValue& dataValue);
        bool getEnableCount(OpcUaDataValue& dataValue);
        void setUpdateCallbackEnableCount(Callback::SPtr& callback);
        
        BaseNodeClass::SPtr disableCount(void);
        bool setDisableCount(const OpcUaDataValue& dataValue);
        bool getDisableCount(OpcUaDataValue& dataValue);
        void setUpdateCallbackDisableCount(Callback::SPtr& callback);
        
        BaseNodeClass::SPtr republishRequestCount(void);
        bool setRepublishRequestCount(const OpcUaDataValue& dataValue);
        bool getRepublishRequestCount(OpcUaDataValue& dataValue);
        void setUpdateCallbackRepublishRequestCount(Callback::SPtr& callback);
        
        BaseNodeClass::SPtr republishMessageRequestCount(void);
        bool setRepublishMessageRequestCount(const OpcUaDataValue& dataValue);
        bool getRepublishMessageRequestCount(OpcUaDataValue& dataValue);
        void setUpdateCallbackRepublishMessageRequestCount(Callback::SPtr& callback);
        
        BaseNodeClass::SPtr republishMessageCount(void);
        bool setRepublishMessageCount(const OpcUaDataValue& dataValue);
        bool getRepublishMessageCount(OpcUaDataValue& dataValue);
        void setUpdateCallbackRepublishMessageCount(Callback::SPtr& callback);
        
        BaseNodeClass::SPtr transferRequestCount(void);
        bool setTransferRequestCount(const OpcUaDataValue& dataValue);
        bool getTransferRequestCount(OpcUaDataValue& dataValue);
        void setUpdateCallbackTransferRequestCount(Callback::SPtr& callback);
        
        BaseNodeClass::SPtr transferredToAltClientCount(void);
        bool setTransferredToAltClientCount(const OpcUaDataValue& dataValue);
        bool getTransferredToAltClientCount(OpcUaDataValue& dataValue);
        void setUpdateCallbackTransferredToAltClientCount(Callback::SPtr& callback);
        
        BaseNodeClass::SPtr transferredToSameClientCount(void);
        bool setTransferredToSameClientCount(const OpcUaDataValue& dataValue);
        bool getTransferredToSameClientCount(OpcUaDataValue& dataValue);
        void setUpdateCallbackTransferredToSameClientCount(Callback::SPtr& callback);
        
        BaseNodeClass::SPtr publishRequestCount(void);
        bool setPublishRequestCount(const OpcUaDataValue& dataValue);
        bool getPublishRequestCount(OpcUaDataValue& dataValue);
        void setUpdateCallbackPublishRequestCount(Callback::SPtr& callback);
        
        BaseNodeClass::SPtr dataChangeNotificationsCount(void);
        bool setDataChangeNotificationsCount(const OpcUaDataValue& dataValue);
        bool getDataChangeNotificationsCount(OpcUaDataValue& dataValue);
        void setUpdateCallbackDataChangeNotificationsCount(Callback::SPtr& callback);
        
        BaseNodeClass::SPtr eventNotificationsCount(void);
        bool setEventNotificationsCount(const OpcUaDataValue& dataValue);
        bool getEventNotificationsCount(OpcUaDataValue& dataValue);
        void setUpdateCallbackEventNotificationsCount(Callback::SPtr& callback);
        
        BaseNodeClass::SPtr notificationsCount(void);
        bool setNotificationsCount(const OpcUaDataValue& dataValue);
        bool getNotificationsCount(OpcUaDataValue& dataValue);
        void setUpdateCallbackNotificationsCount(Callback::SPtr& callback);
        
        BaseNodeClass::SPtr latePublishRequestCount(void);
        bool setLatePublishRequestCount(const OpcUaDataValue& dataValue);
        bool getLatePublishRequestCount(OpcUaDataValue& dataValue);
        void setUpdateCallbackLatePublishRequestCount(Callback::SPtr& callback);
        
        BaseNodeClass::SPtr currentKeepAliveCount(void);
        bool setCurrentKeepAliveCount(const OpcUaDataValue& dataValue);
        bool getCurrentKeepAliveCount(OpcUaDataValue& dataValue);
        void setUpdateCallbackCurrentKeepAliveCount(Callback::SPtr& callback);
        
        BaseNodeClass::SPtr currentLifetimeCount(void);
        bool setCurrentLifetimeCount(const OpcUaDataValue& dataValue);
        bool getCurrentLifetimeCount(OpcUaDataValue& dataValue);
        void setUpdateCallbackCurrentLifetimeCount(Callback::SPtr& callback);
        
        BaseNodeClass::SPtr unacknowledgedMessageCount(void);
        bool setUnacknowledgedMessageCount(const OpcUaDataValue& dataValue);
        bool getUnacknowledgedMessageCount(OpcUaDataValue& dataValue);
        void setUpdateCallbackUnacknowledgedMessageCount(Callback::SPtr& callback);
        
        BaseNodeClass::SPtr discardedMessageCount(void);
        bool setDiscardedMessageCount(const OpcUaDataValue& dataValue);
        bool getDiscardedMessageCount(OpcUaDataValue& dataValue);
        void setUpdateCallbackDiscardedMessageCount(Callback::SPtr& callback);
        
        BaseNodeClass::SPtr monitoredItemCount(void);
        bool setMonitoredItemCount(const OpcUaDataValue& dataValue);
        bool getMonitoredItemCount(OpcUaDataValue& dataValue);
        void setUpdateCallbackMonitoredItemCount(Callback::SPtr& callback);
        
        BaseNodeClass::SPtr disabledMonitoredItemCount(void);
        bool setDisabledMonitoredItemCount(const OpcUaDataValue& dataValue);
        bool getDisabledMonitoredItemCount(OpcUaDataValue& dataValue);
        void setUpdateCallbackDisabledMonitoredItemCount(Callback::SPtr& callback);
        
        BaseNodeClass::SPtr monitoringQueueOverflowCount(void);
        bool setMonitoringQueueOverflowCount(const OpcUaDataValue& dataValue);
        bool getMonitoringQueueOverflowCount(OpcUaDataValue& dataValue);
        void setUpdateCallbackMonitoringQueueOverflowCount(Callback::SPtr& callback);
        
        BaseNodeClass::SPtr nextSequenceNumber(void);
        bool setNextSequenceNumber(const OpcUaDataValue& dataValue);
        bool getNextSequenceNumber(OpcUaDataValue& dataValue);
        void setUpdateCallbackNextSequenceNumber(Callback::SPtr& callback);
        
        BaseNodeClass::SPtr eventQueueOverFlowCount(void);
        bool setEventQueueOverFlowCount(const OpcUaDataValue& dataValue);
        bool getEventQueueOverFlowCount(OpcUaDataValue& dataValue);
        void setUpdateCallbackEventQueueOverFlowCount(Callback::SPtr& callback);
        
      private:
        std::string namespaceName_;
        uint16_t namespaceIndex_;
        ServerVariable::SPtr sessionId_;
        ServerVariable::SPtr subscriptionId_;
        ServerVariable::SPtr priority_;
        ServerVariable::SPtr publishingInterval_;
        ServerVariable::SPtr maxKeepAliveCount_;
        ServerVariable::SPtr maxLifetimeCount_;
        ServerVariable::SPtr maxNotificationsPerPublish_;
        ServerVariable::SPtr publishingEnabled_;
        ServerVariable::SPtr modifyCount_;
        ServerVariable::SPtr enableCount_;
        ServerVariable::SPtr disableCount_;
        ServerVariable::SPtr republishRequestCount_;
        ServerVariable::SPtr republishMessageRequestCount_;
        ServerVariable::SPtr republishMessageCount_;
        ServerVariable::SPtr transferRequestCount_;
        ServerVariable::SPtr transferredToAltClientCount_;
        ServerVariable::SPtr transferredToSameClientCount_;
        ServerVariable::SPtr publishRequestCount_;
        ServerVariable::SPtr dataChangeNotificationsCount_;
        ServerVariable::SPtr eventNotificationsCount_;
        ServerVariable::SPtr notificationsCount_;
        ServerVariable::SPtr latePublishRequestCount_;
        ServerVariable::SPtr currentKeepAliveCount_;
        ServerVariable::SPtr currentLifetimeCount_;
        ServerVariable::SPtr unacknowledgedMessageCount_;
        ServerVariable::SPtr discardedMessageCount_;
        ServerVariable::SPtr monitoredItemCount_;
        ServerVariable::SPtr disabledMonitoredItemCount_;
        ServerVariable::SPtr monitoringQueueOverflowCount_;
        ServerVariable::SPtr nextSequenceNumber_;
        ServerVariable::SPtr eventQueueOverFlowCount_;
    
    };

}

#endif
