/*
    VariableTypeClass: SubscriptionDiagnosticsType

    Generated Source Code - please do not change this source code

    VariableTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

    Autor:     Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackServer_SubscriptionDiagnosticsType_h__
#define __OpcUaStackServer_SubscriptionDiagnosticsType_h__

#include "OpcUaStackServer/StandardVariableType/VariableBase.h"

using namespace OpcUaStackCore;

namespace OpcUaStackServer
{
   
   class DLLEXPORT SubscriptionDiagnosticsType
   : public VariableBase
   {
     public:
       typedef boost::shared_ptr<SubscriptionDiagnosticsType> SPtr;
       typedef std::vector<SubscriptionDiagnosticsType::SPtr> Vec;
   
       SubscriptionDiagnosticsType(void);
       SubscriptionDiagnosticsType(const SubscriptionDiagnosticsType& value);
       virtual ~SubscriptionDiagnosticsType(void);

        //
        // UInt32
        //
        void currentKeepAliveCount_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& currentKeepAliveCount_Variable(void);
        bool get_CurrentKeepAliveCount_Variable(OpcUaDataValue& dataValue);
        bool set_CurrentKeepAliveCount_Variable(const OpcUaDataValue& dataValue);

        //
        // UInt32
        //
        void currentLifetimeCount_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& currentLifetimeCount_Variable(void);
        bool get_CurrentLifetimeCount_Variable(OpcUaDataValue& dataValue);
        bool set_CurrentLifetimeCount_Variable(const OpcUaDataValue& dataValue);

        //
        // UInt32
        //
        void dataChangeNotificationsCount_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& dataChangeNotificationsCount_Variable(void);
        bool get_DataChangeNotificationsCount_Variable(OpcUaDataValue& dataValue);
        bool set_DataChangeNotificationsCount_Variable(const OpcUaDataValue& dataValue);

        //
        // UInt32
        //
        void disableCount_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& disableCount_Variable(void);
        bool get_DisableCount_Variable(OpcUaDataValue& dataValue);
        bool set_DisableCount_Variable(const OpcUaDataValue& dataValue);

        //
        // UInt32
        //
        void disabledMonitoredItemCount_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& disabledMonitoredItemCount_Variable(void);
        bool get_DisabledMonitoredItemCount_Variable(OpcUaDataValue& dataValue);
        bool set_DisabledMonitoredItemCount_Variable(const OpcUaDataValue& dataValue);

        //
        // UInt32
        //
        void discardedMessageCount_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& discardedMessageCount_Variable(void);
        bool get_DiscardedMessageCount_Variable(OpcUaDataValue& dataValue);
        bool set_DiscardedMessageCount_Variable(const OpcUaDataValue& dataValue);

        //
        // UInt32
        //
        void enableCount_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& enableCount_Variable(void);
        bool get_EnableCount_Variable(OpcUaDataValue& dataValue);
        bool set_EnableCount_Variable(const OpcUaDataValue& dataValue);

        //
        // UInt32
        //
        void eventNotificationsCount_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& eventNotificationsCount_Variable(void);
        bool get_EventNotificationsCount_Variable(OpcUaDataValue& dataValue);
        bool set_EventNotificationsCount_Variable(const OpcUaDataValue& dataValue);

        //
        // UInt32
        //
        void eventQueueOverflowCount_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& eventQueueOverflowCount_Variable(void);
        bool get_EventQueueOverflowCount_Variable(OpcUaDataValue& dataValue);
        bool set_EventQueueOverflowCount_Variable(const OpcUaDataValue& dataValue);

        //
        // UInt32
        //
        void latePublishRequestCount_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& latePublishRequestCount_Variable(void);
        bool get_LatePublishRequestCount_Variable(OpcUaDataValue& dataValue);
        bool set_LatePublishRequestCount_Variable(const OpcUaDataValue& dataValue);

        //
        // UInt32
        //
        void maxKeepAliveCount_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& maxKeepAliveCount_Variable(void);
        bool get_MaxKeepAliveCount_Variable(OpcUaDataValue& dataValue);
        bool set_MaxKeepAliveCount_Variable(const OpcUaDataValue& dataValue);

        //
        // UInt32
        //
        void maxLifetimeCount_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& maxLifetimeCount_Variable(void);
        bool get_MaxLifetimeCount_Variable(OpcUaDataValue& dataValue);
        bool set_MaxLifetimeCount_Variable(const OpcUaDataValue& dataValue);

        //
        // UInt32
        //
        void maxNotificationsPerPublish_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& maxNotificationsPerPublish_Variable(void);
        bool get_MaxNotificationsPerPublish_Variable(OpcUaDataValue& dataValue);
        bool set_MaxNotificationsPerPublish_Variable(const OpcUaDataValue& dataValue);

        //
        // UInt32
        //
        void modifyCount_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& modifyCount_Variable(void);
        bool get_ModifyCount_Variable(OpcUaDataValue& dataValue);
        bool set_ModifyCount_Variable(const OpcUaDataValue& dataValue);

        //
        // UInt32
        //
        void monitoredItemCount_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& monitoredItemCount_Variable(void);
        bool get_MonitoredItemCount_Variable(OpcUaDataValue& dataValue);
        bool set_MonitoredItemCount_Variable(const OpcUaDataValue& dataValue);

        //
        // UInt32
        //
        void monitoringQueueOverflowCount_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& monitoringQueueOverflowCount_Variable(void);
        bool get_MonitoringQueueOverflowCount_Variable(OpcUaDataValue& dataValue);
        bool set_MonitoringQueueOverflowCount_Variable(const OpcUaDataValue& dataValue);

        //
        // UInt32
        //
        void nextSequenceNumber_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& nextSequenceNumber_Variable(void);
        bool get_NextSequenceNumber_Variable(OpcUaDataValue& dataValue);
        bool set_NextSequenceNumber_Variable(const OpcUaDataValue& dataValue);

        //
        // UInt32
        //
        void notificationsCount_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& notificationsCount_Variable(void);
        bool get_NotificationsCount_Variable(OpcUaDataValue& dataValue);
        bool set_NotificationsCount_Variable(const OpcUaDataValue& dataValue);

        //
        // Byte
        //
        void priority_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& priority_Variable(void);
        bool get_Priority_Variable(OpcUaDataValue& dataValue);
        bool set_Priority_Variable(const OpcUaDataValue& dataValue);

        //
        // UInt32
        //
        void publishRequestCount_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& publishRequestCount_Variable(void);
        bool get_PublishRequestCount_Variable(OpcUaDataValue& dataValue);
        bool set_PublishRequestCount_Variable(const OpcUaDataValue& dataValue);

        //
        // Boolean
        //
        void publishingEnabled_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& publishingEnabled_Variable(void);
        bool get_PublishingEnabled_Variable(OpcUaDataValue& dataValue);
        bool set_PublishingEnabled_Variable(const OpcUaDataValue& dataValue);

        //
        // Double
        //
        void publishingInterval_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& publishingInterval_Variable(void);
        bool get_PublishingInterval_Variable(OpcUaDataValue& dataValue);
        bool set_PublishingInterval_Variable(const OpcUaDataValue& dataValue);

        //
        // UInt32
        //
        void republishMessageCount_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& republishMessageCount_Variable(void);
        bool get_RepublishMessageCount_Variable(OpcUaDataValue& dataValue);
        bool set_RepublishMessageCount_Variable(const OpcUaDataValue& dataValue);

        //
        // UInt32
        //
        void republishMessageRequestCount_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& republishMessageRequestCount_Variable(void);
        bool get_RepublishMessageRequestCount_Variable(OpcUaDataValue& dataValue);
        bool set_RepublishMessageRequestCount_Variable(const OpcUaDataValue& dataValue);

        //
        // UInt32
        //
        void republishRequestCount_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& republishRequestCount_Variable(void);
        bool get_RepublishRequestCount_Variable(OpcUaDataValue& dataValue);
        bool set_RepublishRequestCount_Variable(const OpcUaDataValue& dataValue);

        //
        // NodeId
        //
        void sessionId_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& sessionId_Variable(void);
        bool get_SessionId_Variable(OpcUaDataValue& dataValue);
        bool set_SessionId_Variable(const OpcUaDataValue& dataValue);

        //
        // UInt32
        //
        void subscriptionId_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& subscriptionId_Variable(void);
        bool get_SubscriptionId_Variable(OpcUaDataValue& dataValue);
        bool set_SubscriptionId_Variable(const OpcUaDataValue& dataValue);

        //
        // UInt32
        //
        void transferRequestCount_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& transferRequestCount_Variable(void);
        bool get_TransferRequestCount_Variable(OpcUaDataValue& dataValue);
        bool set_TransferRequestCount_Variable(const OpcUaDataValue& dataValue);

        //
        // UInt32
        //
        void transferredToAltClientCount_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& transferredToAltClientCount_Variable(void);
        bool get_TransferredToAltClientCount_Variable(OpcUaDataValue& dataValue);
        bool set_TransferredToAltClientCount_Variable(const OpcUaDataValue& dataValue);

        //
        // UInt32
        //
        void transferredToSameClientCount_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& transferredToSameClientCount_Variable(void);
        bool get_TransferredToSameClientCount_Variable(OpcUaDataValue& dataValue);
        bool set_TransferredToSameClientCount_Variable(const OpcUaDataValue& dataValue);

        //
        // UInt32
        //
        void unacknowledgedMessageCount_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& unacknowledgedMessageCount_Variable(void);
        bool get_UnacknowledgedMessageCount_Variable(OpcUaDataValue& dataValue);
        bool set_UnacknowledgedMessageCount_Variable(const OpcUaDataValue& dataValue);

        //
        // SubscriptionDiagnosticsDataType (Array)
        //
        void variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& variable(void);
        bool get_Variable(OpcUaDataValue& dataValue);
        bool set_Variable(const OpcUaDataValue& dataValue);
    
      private:
        ServerVariable::SPtr currentKeepAliveCount_Variable_;
        ServerVariable::SPtr currentLifetimeCount_Variable_;
        ServerVariable::SPtr dataChangeNotificationsCount_Variable_;
        ServerVariable::SPtr disableCount_Variable_;
        ServerVariable::SPtr disabledMonitoredItemCount_Variable_;
        ServerVariable::SPtr discardedMessageCount_Variable_;
        ServerVariable::SPtr enableCount_Variable_;
        ServerVariable::SPtr eventNotificationsCount_Variable_;
        ServerVariable::SPtr eventQueueOverflowCount_Variable_;
        ServerVariable::SPtr latePublishRequestCount_Variable_;
        ServerVariable::SPtr maxKeepAliveCount_Variable_;
        ServerVariable::SPtr maxLifetimeCount_Variable_;
        ServerVariable::SPtr maxNotificationsPerPublish_Variable_;
        ServerVariable::SPtr modifyCount_Variable_;
        ServerVariable::SPtr monitoredItemCount_Variable_;
        ServerVariable::SPtr monitoringQueueOverflowCount_Variable_;
        ServerVariable::SPtr nextSequenceNumber_Variable_;
        ServerVariable::SPtr notificationsCount_Variable_;
        ServerVariable::SPtr priority_Variable_;
        ServerVariable::SPtr publishRequestCount_Variable_;
        ServerVariable::SPtr publishingEnabled_Variable_;
        ServerVariable::SPtr publishingInterval_Variable_;
        ServerVariable::SPtr republishMessageCount_Variable_;
        ServerVariable::SPtr republishMessageRequestCount_Variable_;
        ServerVariable::SPtr republishRequestCount_Variable_;
        ServerVariable::SPtr sessionId_Variable_;
        ServerVariable::SPtr subscriptionId_Variable_;
        ServerVariable::SPtr transferRequestCount_Variable_;
        ServerVariable::SPtr transferredToAltClientCount_Variable_;
        ServerVariable::SPtr transferredToSameClientCount_Variable_;
        ServerVariable::SPtr unacknowledgedMessageCount_Variable_;
        ServerVariable::SPtr variable_;
   
   };

}

#endif
