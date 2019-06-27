/*
    VariableTypeClass: SubscriptionDiagnosticsArrayType

    Generated Source Code - please do not change this source code

    VariableTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

    Autor:     Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackServer_SubscriptionDiagnosticsArrayType_h__
#define __OpcUaStackServer_SubscriptionDiagnosticsArrayType_h__

#include "OpcUaStackServer/StandardVariableType/VariableBase.h"

namespace OpcUaStackServer
{
   
   class DLLEXPORT SubscriptionDiagnosticsArrayType
   : public VariableBase
   {
     public:
       typedef boost::shared_ptr<SubscriptionDiagnosticsArrayType> SPtr;
       typedef std::vector<SubscriptionDiagnosticsArrayType::SPtr> Vec;
   
       SubscriptionDiagnosticsArrayType(void);
       SubscriptionDiagnosticsArrayType(const SubscriptionDiagnosticsArrayType& value);
       virtual ~SubscriptionDiagnosticsArrayType(void);

        //
        // UInt32
        //
        void subscriptionDiagnostics_CurrentKeepAliveCount_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& subscriptionDiagnostics_CurrentKeepAliveCount_Variable(void);
        bool get_SubscriptionDiagnostics_CurrentKeepAliveCount_Variable(OpcUaDataValue& dataValue);
        bool set_SubscriptionDiagnostics_CurrentKeepAliveCount_Variable(const OpcUaDataValue& dataValue);

        //
        // UInt32
        //
        void subscriptionDiagnostics_CurrentLifetimeCount_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& subscriptionDiagnostics_CurrentLifetimeCount_Variable(void);
        bool get_SubscriptionDiagnostics_CurrentLifetimeCount_Variable(OpcUaDataValue& dataValue);
        bool set_SubscriptionDiagnostics_CurrentLifetimeCount_Variable(const OpcUaDataValue& dataValue);

        //
        // UInt32
        //
        void subscriptionDiagnostics_DataChangeNotificationsCount_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& subscriptionDiagnostics_DataChangeNotificationsCount_Variable(void);
        bool get_SubscriptionDiagnostics_DataChangeNotificationsCount_Variable(OpcUaDataValue& dataValue);
        bool set_SubscriptionDiagnostics_DataChangeNotificationsCount_Variable(const OpcUaDataValue& dataValue);

        //
        // UInt32
        //
        void subscriptionDiagnostics_DisableCount_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& subscriptionDiagnostics_DisableCount_Variable(void);
        bool get_SubscriptionDiagnostics_DisableCount_Variable(OpcUaDataValue& dataValue);
        bool set_SubscriptionDiagnostics_DisableCount_Variable(const OpcUaDataValue& dataValue);

        //
        // UInt32
        //
        void subscriptionDiagnostics_DisabledMonitoredItemCount_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& subscriptionDiagnostics_DisabledMonitoredItemCount_Variable(void);
        bool get_SubscriptionDiagnostics_DisabledMonitoredItemCount_Variable(OpcUaDataValue& dataValue);
        bool set_SubscriptionDiagnostics_DisabledMonitoredItemCount_Variable(const OpcUaDataValue& dataValue);

        //
        // UInt32
        //
        void subscriptionDiagnostics_DiscardedMessageCount_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& subscriptionDiagnostics_DiscardedMessageCount_Variable(void);
        bool get_SubscriptionDiagnostics_DiscardedMessageCount_Variable(OpcUaDataValue& dataValue);
        bool set_SubscriptionDiagnostics_DiscardedMessageCount_Variable(const OpcUaDataValue& dataValue);

        //
        // UInt32
        //
        void subscriptionDiagnostics_EnableCount_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& subscriptionDiagnostics_EnableCount_Variable(void);
        bool get_SubscriptionDiagnostics_EnableCount_Variable(OpcUaDataValue& dataValue);
        bool set_SubscriptionDiagnostics_EnableCount_Variable(const OpcUaDataValue& dataValue);

        //
        // UInt32
        //
        void subscriptionDiagnostics_EventNotificationsCount_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& subscriptionDiagnostics_EventNotificationsCount_Variable(void);
        bool get_SubscriptionDiagnostics_EventNotificationsCount_Variable(OpcUaDataValue& dataValue);
        bool set_SubscriptionDiagnostics_EventNotificationsCount_Variable(const OpcUaDataValue& dataValue);

        //
        // UInt32
        //
        void subscriptionDiagnostics_EventQueueOverflowCount_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& subscriptionDiagnostics_EventQueueOverflowCount_Variable(void);
        bool get_SubscriptionDiagnostics_EventQueueOverflowCount_Variable(OpcUaDataValue& dataValue);
        bool set_SubscriptionDiagnostics_EventQueueOverflowCount_Variable(const OpcUaDataValue& dataValue);

        //
        // UInt32
        //
        void subscriptionDiagnostics_LatePublishRequestCount_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& subscriptionDiagnostics_LatePublishRequestCount_Variable(void);
        bool get_SubscriptionDiagnostics_LatePublishRequestCount_Variable(OpcUaDataValue& dataValue);
        bool set_SubscriptionDiagnostics_LatePublishRequestCount_Variable(const OpcUaDataValue& dataValue);

        //
        // UInt32
        //
        void subscriptionDiagnostics_MaxKeepAliveCount_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& subscriptionDiagnostics_MaxKeepAliveCount_Variable(void);
        bool get_SubscriptionDiagnostics_MaxKeepAliveCount_Variable(OpcUaDataValue& dataValue);
        bool set_SubscriptionDiagnostics_MaxKeepAliveCount_Variable(const OpcUaDataValue& dataValue);

        //
        // UInt32
        //
        void subscriptionDiagnostics_MaxLifetimeCount_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& subscriptionDiagnostics_MaxLifetimeCount_Variable(void);
        bool get_SubscriptionDiagnostics_MaxLifetimeCount_Variable(OpcUaDataValue& dataValue);
        bool set_SubscriptionDiagnostics_MaxLifetimeCount_Variable(const OpcUaDataValue& dataValue);

        //
        // UInt32
        //
        void subscriptionDiagnostics_MaxNotificationsPerPublish_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& subscriptionDiagnostics_MaxNotificationsPerPublish_Variable(void);
        bool get_SubscriptionDiagnostics_MaxNotificationsPerPublish_Variable(OpcUaDataValue& dataValue);
        bool set_SubscriptionDiagnostics_MaxNotificationsPerPublish_Variable(const OpcUaDataValue& dataValue);

        //
        // UInt32
        //
        void subscriptionDiagnostics_ModifyCount_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& subscriptionDiagnostics_ModifyCount_Variable(void);
        bool get_SubscriptionDiagnostics_ModifyCount_Variable(OpcUaDataValue& dataValue);
        bool set_SubscriptionDiagnostics_ModifyCount_Variable(const OpcUaDataValue& dataValue);

        //
        // UInt32
        //
        void subscriptionDiagnostics_MonitoredItemCount_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& subscriptionDiagnostics_MonitoredItemCount_Variable(void);
        bool get_SubscriptionDiagnostics_MonitoredItemCount_Variable(OpcUaDataValue& dataValue);
        bool set_SubscriptionDiagnostics_MonitoredItemCount_Variable(const OpcUaDataValue& dataValue);

        //
        // UInt32
        //
        void subscriptionDiagnostics_MonitoringQueueOverflowCount_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& subscriptionDiagnostics_MonitoringQueueOverflowCount_Variable(void);
        bool get_SubscriptionDiagnostics_MonitoringQueueOverflowCount_Variable(OpcUaDataValue& dataValue);
        bool set_SubscriptionDiagnostics_MonitoringQueueOverflowCount_Variable(const OpcUaDataValue& dataValue);

        //
        // UInt32
        //
        void subscriptionDiagnostics_NextSequenceNumber_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& subscriptionDiagnostics_NextSequenceNumber_Variable(void);
        bool get_SubscriptionDiagnostics_NextSequenceNumber_Variable(OpcUaDataValue& dataValue);
        bool set_SubscriptionDiagnostics_NextSequenceNumber_Variable(const OpcUaDataValue& dataValue);

        //
        // UInt32
        //
        void subscriptionDiagnostics_NotificationsCount_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& subscriptionDiagnostics_NotificationsCount_Variable(void);
        bool get_SubscriptionDiagnostics_NotificationsCount_Variable(OpcUaDataValue& dataValue);
        bool set_SubscriptionDiagnostics_NotificationsCount_Variable(const OpcUaDataValue& dataValue);

        //
        // Byte
        //
        void subscriptionDiagnostics_Priority_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& subscriptionDiagnostics_Priority_Variable(void);
        bool get_SubscriptionDiagnostics_Priority_Variable(OpcUaDataValue& dataValue);
        bool set_SubscriptionDiagnostics_Priority_Variable(const OpcUaDataValue& dataValue);

        //
        // UInt32
        //
        void subscriptionDiagnostics_PublishRequestCount_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& subscriptionDiagnostics_PublishRequestCount_Variable(void);
        bool get_SubscriptionDiagnostics_PublishRequestCount_Variable(OpcUaDataValue& dataValue);
        bool set_SubscriptionDiagnostics_PublishRequestCount_Variable(const OpcUaDataValue& dataValue);

        //
        // Boolean
        //
        void subscriptionDiagnostics_PublishingEnabled_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& subscriptionDiagnostics_PublishingEnabled_Variable(void);
        bool get_SubscriptionDiagnostics_PublishingEnabled_Variable(OpcUaDataValue& dataValue);
        bool set_SubscriptionDiagnostics_PublishingEnabled_Variable(const OpcUaDataValue& dataValue);

        //
        // Double
        //
        void subscriptionDiagnostics_PublishingInterval_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& subscriptionDiagnostics_PublishingInterval_Variable(void);
        bool get_SubscriptionDiagnostics_PublishingInterval_Variable(OpcUaDataValue& dataValue);
        bool set_SubscriptionDiagnostics_PublishingInterval_Variable(const OpcUaDataValue& dataValue);

        //
        // UInt32
        //
        void subscriptionDiagnostics_RepublishMessageCount_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& subscriptionDiagnostics_RepublishMessageCount_Variable(void);
        bool get_SubscriptionDiagnostics_RepublishMessageCount_Variable(OpcUaDataValue& dataValue);
        bool set_SubscriptionDiagnostics_RepublishMessageCount_Variable(const OpcUaDataValue& dataValue);

        //
        // UInt32
        //
        void subscriptionDiagnostics_RepublishMessageRequestCount_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& subscriptionDiagnostics_RepublishMessageRequestCount_Variable(void);
        bool get_SubscriptionDiagnostics_RepublishMessageRequestCount_Variable(OpcUaDataValue& dataValue);
        bool set_SubscriptionDiagnostics_RepublishMessageRequestCount_Variable(const OpcUaDataValue& dataValue);

        //
        // UInt32
        //
        void subscriptionDiagnostics_RepublishRequestCount_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& subscriptionDiagnostics_RepublishRequestCount_Variable(void);
        bool get_SubscriptionDiagnostics_RepublishRequestCount_Variable(OpcUaDataValue& dataValue);
        bool set_SubscriptionDiagnostics_RepublishRequestCount_Variable(const OpcUaDataValue& dataValue);

        //
        // NodeId
        //
        void subscriptionDiagnostics_SessionId_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& subscriptionDiagnostics_SessionId_Variable(void);
        bool get_SubscriptionDiagnostics_SessionId_Variable(OpcUaDataValue& dataValue);
        bool set_SubscriptionDiagnostics_SessionId_Variable(const OpcUaDataValue& dataValue);

        //
        // UInt32
        //
        void subscriptionDiagnostics_SubscriptionId_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& subscriptionDiagnostics_SubscriptionId_Variable(void);
        bool get_SubscriptionDiagnostics_SubscriptionId_Variable(OpcUaDataValue& dataValue);
        bool set_SubscriptionDiagnostics_SubscriptionId_Variable(const OpcUaDataValue& dataValue);

        //
        // UInt32
        //
        void subscriptionDiagnostics_TransferRequestCount_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& subscriptionDiagnostics_TransferRequestCount_Variable(void);
        bool get_SubscriptionDiagnostics_TransferRequestCount_Variable(OpcUaDataValue& dataValue);
        bool set_SubscriptionDiagnostics_TransferRequestCount_Variable(const OpcUaDataValue& dataValue);

        //
        // UInt32
        //
        void subscriptionDiagnostics_TransferredToAltClientCount_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& subscriptionDiagnostics_TransferredToAltClientCount_Variable(void);
        bool get_SubscriptionDiagnostics_TransferredToAltClientCount_Variable(OpcUaDataValue& dataValue);
        bool set_SubscriptionDiagnostics_TransferredToAltClientCount_Variable(const OpcUaDataValue& dataValue);

        //
        // UInt32
        //
        void subscriptionDiagnostics_TransferredToSameClientCount_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& subscriptionDiagnostics_TransferredToSameClientCount_Variable(void);
        bool get_SubscriptionDiagnostics_TransferredToSameClientCount_Variable(OpcUaDataValue& dataValue);
        bool set_SubscriptionDiagnostics_TransferredToSameClientCount_Variable(const OpcUaDataValue& dataValue);

        //
        // UInt32
        //
        void subscriptionDiagnostics_UnacknowledgedMessageCount_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& subscriptionDiagnostics_UnacknowledgedMessageCount_Variable(void);
        bool get_SubscriptionDiagnostics_UnacknowledgedMessageCount_Variable(OpcUaDataValue& dataValue);
        bool set_SubscriptionDiagnostics_UnacknowledgedMessageCount_Variable(const OpcUaDataValue& dataValue);

        //
        // SubscriptionDiagnosticsDataType
        //
        void subscriptionDiagnostics_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& subscriptionDiagnostics_Variable(void);
        bool get_SubscriptionDiagnostics_Variable(OpcUaDataValue& dataValue);
        bool set_SubscriptionDiagnostics_Variable(const OpcUaDataValue& dataValue);

        //
        // SubscriptionDiagnosticsDataType (Array)
        //
        void variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& variable(void);
        bool get_Variable(OpcUaDataValue& dataValue);
        bool set_Variable(const OpcUaDataValue& dataValue);
    
      private:
        ServerVariable::SPtr subscriptionDiagnostics_CurrentKeepAliveCount_Variable_;
        ServerVariable::SPtr subscriptionDiagnostics_CurrentLifetimeCount_Variable_;
        ServerVariable::SPtr subscriptionDiagnostics_DataChangeNotificationsCount_Variable_;
        ServerVariable::SPtr subscriptionDiagnostics_DisableCount_Variable_;
        ServerVariable::SPtr subscriptionDiagnostics_DisabledMonitoredItemCount_Variable_;
        ServerVariable::SPtr subscriptionDiagnostics_DiscardedMessageCount_Variable_;
        ServerVariable::SPtr subscriptionDiagnostics_EnableCount_Variable_;
        ServerVariable::SPtr subscriptionDiagnostics_EventNotificationsCount_Variable_;
        ServerVariable::SPtr subscriptionDiagnostics_EventQueueOverflowCount_Variable_;
        ServerVariable::SPtr subscriptionDiagnostics_LatePublishRequestCount_Variable_;
        ServerVariable::SPtr subscriptionDiagnostics_MaxKeepAliveCount_Variable_;
        ServerVariable::SPtr subscriptionDiagnostics_MaxLifetimeCount_Variable_;
        ServerVariable::SPtr subscriptionDiagnostics_MaxNotificationsPerPublish_Variable_;
        ServerVariable::SPtr subscriptionDiagnostics_ModifyCount_Variable_;
        ServerVariable::SPtr subscriptionDiagnostics_MonitoredItemCount_Variable_;
        ServerVariable::SPtr subscriptionDiagnostics_MonitoringQueueOverflowCount_Variable_;
        ServerVariable::SPtr subscriptionDiagnostics_NextSequenceNumber_Variable_;
        ServerVariable::SPtr subscriptionDiagnostics_NotificationsCount_Variable_;
        ServerVariable::SPtr subscriptionDiagnostics_Priority_Variable_;
        ServerVariable::SPtr subscriptionDiagnostics_PublishRequestCount_Variable_;
        ServerVariable::SPtr subscriptionDiagnostics_PublishingEnabled_Variable_;
        ServerVariable::SPtr subscriptionDiagnostics_PublishingInterval_Variable_;
        ServerVariable::SPtr subscriptionDiagnostics_RepublishMessageCount_Variable_;
        ServerVariable::SPtr subscriptionDiagnostics_RepublishMessageRequestCount_Variable_;
        ServerVariable::SPtr subscriptionDiagnostics_RepublishRequestCount_Variable_;
        ServerVariable::SPtr subscriptionDiagnostics_SessionId_Variable_;
        ServerVariable::SPtr subscriptionDiagnostics_SubscriptionId_Variable_;
        ServerVariable::SPtr subscriptionDiagnostics_TransferRequestCount_Variable_;
        ServerVariable::SPtr subscriptionDiagnostics_TransferredToAltClientCount_Variable_;
        ServerVariable::SPtr subscriptionDiagnostics_TransferredToSameClientCount_Variable_;
        ServerVariable::SPtr subscriptionDiagnostics_UnacknowledgedMessageCount_Variable_;
        ServerVariable::SPtr subscriptionDiagnostics_Variable_;
        ServerVariable::SPtr variable_;
   
   };

}

#endif
