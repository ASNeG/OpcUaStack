/*
    ObjectTypeClass: SessionDiagnosticsObjectType

    Generated Source Code - please do not change this source code

    ObjectTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

    Autor:     Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackServer_SessionDiagnosticsObjectType_h__
#define __OpcUaStackServer_SessionDiagnosticsObjectType_h__

#include "OpcUaStackServer/StandardVariableType/VariableBase.h"
#include "OpcUaStackServer/StandardObjectType/ObjectBase.h"

namespace OpcUaStackServer
{
   
   class DLLEXPORT SessionDiagnosticsObjectType
   : public ObjectBase
   {
     public:
       typedef boost::shared_ptr<SessionDiagnosticsObjectType> SPtr;
       typedef std::vector<SessionDiagnosticsObjectType::SPtr> Vec;
   
       SessionDiagnosticsObjectType(void);
       SessionDiagnosticsObjectType(const SessionDiagnosticsObjectType& value);
       virtual ~SessionDiagnosticsObjectType(void);

        //
        // Duration
        //
        void sessionDiagnostics_ActualSessionTimeout_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& sessionDiagnostics_ActualSessionTimeout_Variable(void);
        bool get_SessionDiagnostics_ActualSessionTimeout_Variable(OpcUaDataValue& dataValue);
        bool set_SessionDiagnostics_ActualSessionTimeout_Variable(const OpcUaDataValue& dataValue);

        //
        // ServiceCounterDataType
        //
        void sessionDiagnostics_AddNodesCount_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& sessionDiagnostics_AddNodesCount_Variable(void);
        bool get_SessionDiagnostics_AddNodesCount_Variable(OpcUaDataValue& dataValue);
        bool set_SessionDiagnostics_AddNodesCount_Variable(const OpcUaDataValue& dataValue);

        //
        // ServiceCounterDataType
        //
        void sessionDiagnostics_AddReferencesCount_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& sessionDiagnostics_AddReferencesCount_Variable(void);
        bool get_SessionDiagnostics_AddReferencesCount_Variable(OpcUaDataValue& dataValue);
        bool set_SessionDiagnostics_AddReferencesCount_Variable(const OpcUaDataValue& dataValue);

        //
        // ServiceCounterDataType
        //
        void sessionDiagnostics_BrowseCount_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& sessionDiagnostics_BrowseCount_Variable(void);
        bool get_SessionDiagnostics_BrowseCount_Variable(OpcUaDataValue& dataValue);
        bool set_SessionDiagnostics_BrowseCount_Variable(const OpcUaDataValue& dataValue);

        //
        // ServiceCounterDataType
        //
        void sessionDiagnostics_BrowseNextCount_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& sessionDiagnostics_BrowseNextCount_Variable(void);
        bool get_SessionDiagnostics_BrowseNextCount_Variable(OpcUaDataValue& dataValue);
        bool set_SessionDiagnostics_BrowseNextCount_Variable(const OpcUaDataValue& dataValue);

        //
        // ServiceCounterDataType
        //
        void sessionDiagnostics_CallCount_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& sessionDiagnostics_CallCount_Variable(void);
        bool get_SessionDiagnostics_CallCount_Variable(OpcUaDataValue& dataValue);
        bool set_SessionDiagnostics_CallCount_Variable(const OpcUaDataValue& dataValue);

        //
        // UtcTime
        //
        void sessionDiagnostics_ClientConnectionTime_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& sessionDiagnostics_ClientConnectionTime_Variable(void);
        bool get_SessionDiagnostics_ClientConnectionTime_Variable(OpcUaDataValue& dataValue);
        bool set_SessionDiagnostics_ClientConnectionTime_Variable(const OpcUaDataValue& dataValue);

        //
        // ApplicationDescription
        //
        void sessionDiagnostics_ClientDescription_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& sessionDiagnostics_ClientDescription_Variable(void);
        bool get_SessionDiagnostics_ClientDescription_Variable(OpcUaDataValue& dataValue);
        bool set_SessionDiagnostics_ClientDescription_Variable(const OpcUaDataValue& dataValue);

        //
        // UtcTime
        //
        void sessionDiagnostics_ClientLastContactTime_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& sessionDiagnostics_ClientLastContactTime_Variable(void);
        bool get_SessionDiagnostics_ClientLastContactTime_Variable(OpcUaDataValue& dataValue);
        bool set_SessionDiagnostics_ClientLastContactTime_Variable(const OpcUaDataValue& dataValue);

        //
        // ServiceCounterDataType
        //
        void sessionDiagnostics_CreateMonitoredItemsCount_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& sessionDiagnostics_CreateMonitoredItemsCount_Variable(void);
        bool get_SessionDiagnostics_CreateMonitoredItemsCount_Variable(OpcUaDataValue& dataValue);
        bool set_SessionDiagnostics_CreateMonitoredItemsCount_Variable(const OpcUaDataValue& dataValue);

        //
        // ServiceCounterDataType
        //
        void sessionDiagnostics_CreateSubscriptionCount_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& sessionDiagnostics_CreateSubscriptionCount_Variable(void);
        bool get_SessionDiagnostics_CreateSubscriptionCount_Variable(OpcUaDataValue& dataValue);
        bool set_SessionDiagnostics_CreateSubscriptionCount_Variable(const OpcUaDataValue& dataValue);

        //
        // UInt32
        //
        void sessionDiagnostics_CurrentMonitoredItemsCount_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& sessionDiagnostics_CurrentMonitoredItemsCount_Variable(void);
        bool get_SessionDiagnostics_CurrentMonitoredItemsCount_Variable(OpcUaDataValue& dataValue);
        bool set_SessionDiagnostics_CurrentMonitoredItemsCount_Variable(const OpcUaDataValue& dataValue);

        //
        // UInt32
        //
        void sessionDiagnostics_CurrentPublishRequestsInQueue_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& sessionDiagnostics_CurrentPublishRequestsInQueue_Variable(void);
        bool get_SessionDiagnostics_CurrentPublishRequestsInQueue_Variable(OpcUaDataValue& dataValue);
        bool set_SessionDiagnostics_CurrentPublishRequestsInQueue_Variable(const OpcUaDataValue& dataValue);

        //
        // UInt32
        //
        void sessionDiagnostics_CurrentSubscriptionsCount_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& sessionDiagnostics_CurrentSubscriptionsCount_Variable(void);
        bool get_SessionDiagnostics_CurrentSubscriptionsCount_Variable(OpcUaDataValue& dataValue);
        bool set_SessionDiagnostics_CurrentSubscriptionsCount_Variable(const OpcUaDataValue& dataValue);

        //
        // ServiceCounterDataType
        //
        void sessionDiagnostics_DeleteMonitoredItemsCount_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& sessionDiagnostics_DeleteMonitoredItemsCount_Variable(void);
        bool get_SessionDiagnostics_DeleteMonitoredItemsCount_Variable(OpcUaDataValue& dataValue);
        bool set_SessionDiagnostics_DeleteMonitoredItemsCount_Variable(const OpcUaDataValue& dataValue);

        //
        // ServiceCounterDataType
        //
        void sessionDiagnostics_DeleteNodesCount_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& sessionDiagnostics_DeleteNodesCount_Variable(void);
        bool get_SessionDiagnostics_DeleteNodesCount_Variable(OpcUaDataValue& dataValue);
        bool set_SessionDiagnostics_DeleteNodesCount_Variable(const OpcUaDataValue& dataValue);

        //
        // ServiceCounterDataType
        //
        void sessionDiagnostics_DeleteReferencesCount_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& sessionDiagnostics_DeleteReferencesCount_Variable(void);
        bool get_SessionDiagnostics_DeleteReferencesCount_Variable(OpcUaDataValue& dataValue);
        bool set_SessionDiagnostics_DeleteReferencesCount_Variable(const OpcUaDataValue& dataValue);

        //
        // ServiceCounterDataType
        //
        void sessionDiagnostics_DeleteSubscriptionsCount_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& sessionDiagnostics_DeleteSubscriptionsCount_Variable(void);
        bool get_SessionDiagnostics_DeleteSubscriptionsCount_Variable(OpcUaDataValue& dataValue);
        bool set_SessionDiagnostics_DeleteSubscriptionsCount_Variable(const OpcUaDataValue& dataValue);

        //
        // String
        //
        void sessionDiagnostics_EndpointUrl_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& sessionDiagnostics_EndpointUrl_Variable(void);
        bool get_SessionDiagnostics_EndpointUrl_Variable(OpcUaDataValue& dataValue);
        bool set_SessionDiagnostics_EndpointUrl_Variable(const OpcUaDataValue& dataValue);

        //
        // ServiceCounterDataType
        //
        void sessionDiagnostics_HistoryReadCount_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& sessionDiagnostics_HistoryReadCount_Variable(void);
        bool get_SessionDiagnostics_HistoryReadCount_Variable(OpcUaDataValue& dataValue);
        bool set_SessionDiagnostics_HistoryReadCount_Variable(const OpcUaDataValue& dataValue);

        //
        // ServiceCounterDataType
        //
        void sessionDiagnostics_HistoryUpdateCount_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& sessionDiagnostics_HistoryUpdateCount_Variable(void);
        bool get_SessionDiagnostics_HistoryUpdateCount_Variable(OpcUaDataValue& dataValue);
        bool set_SessionDiagnostics_HistoryUpdateCount_Variable(const OpcUaDataValue& dataValue);

        //
        // LocaleId (Array)
        //
        void sessionDiagnostics_LocaleIds_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& sessionDiagnostics_LocaleIds_Variable(void);
        bool get_SessionDiagnostics_LocaleIds_Variable(OpcUaDataValue& dataValue);
        bool set_SessionDiagnostics_LocaleIds_Variable(const OpcUaDataValue& dataValue);

        //
        // UInt32
        //
        void sessionDiagnostics_MaxResponseMessageSize_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& sessionDiagnostics_MaxResponseMessageSize_Variable(void);
        bool get_SessionDiagnostics_MaxResponseMessageSize_Variable(OpcUaDataValue& dataValue);
        bool set_SessionDiagnostics_MaxResponseMessageSize_Variable(const OpcUaDataValue& dataValue);

        //
        // ServiceCounterDataType
        //
        void sessionDiagnostics_ModifyMonitoredItemsCount_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& sessionDiagnostics_ModifyMonitoredItemsCount_Variable(void);
        bool get_SessionDiagnostics_ModifyMonitoredItemsCount_Variable(OpcUaDataValue& dataValue);
        bool set_SessionDiagnostics_ModifyMonitoredItemsCount_Variable(const OpcUaDataValue& dataValue);

        //
        // ServiceCounterDataType
        //
        void sessionDiagnostics_ModifySubscriptionCount_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& sessionDiagnostics_ModifySubscriptionCount_Variable(void);
        bool get_SessionDiagnostics_ModifySubscriptionCount_Variable(OpcUaDataValue& dataValue);
        bool set_SessionDiagnostics_ModifySubscriptionCount_Variable(const OpcUaDataValue& dataValue);

        //
        // ServiceCounterDataType
        //
        void sessionDiagnostics_PublishCount_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& sessionDiagnostics_PublishCount_Variable(void);
        bool get_SessionDiagnostics_PublishCount_Variable(OpcUaDataValue& dataValue);
        bool set_SessionDiagnostics_PublishCount_Variable(const OpcUaDataValue& dataValue);

        //
        // ServiceCounterDataType
        //
        void sessionDiagnostics_QueryFirstCount_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& sessionDiagnostics_QueryFirstCount_Variable(void);
        bool get_SessionDiagnostics_QueryFirstCount_Variable(OpcUaDataValue& dataValue);
        bool set_SessionDiagnostics_QueryFirstCount_Variable(const OpcUaDataValue& dataValue);

        //
        // ServiceCounterDataType
        //
        void sessionDiagnostics_QueryNextCount_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& sessionDiagnostics_QueryNextCount_Variable(void);
        bool get_SessionDiagnostics_QueryNextCount_Variable(OpcUaDataValue& dataValue);
        bool set_SessionDiagnostics_QueryNextCount_Variable(const OpcUaDataValue& dataValue);

        //
        // ServiceCounterDataType
        //
        void sessionDiagnostics_ReadCount_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& sessionDiagnostics_ReadCount_Variable(void);
        bool get_SessionDiagnostics_ReadCount_Variable(OpcUaDataValue& dataValue);
        bool set_SessionDiagnostics_ReadCount_Variable(const OpcUaDataValue& dataValue);

        //
        // ServiceCounterDataType
        //
        void sessionDiagnostics_RegisterNodesCount_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& sessionDiagnostics_RegisterNodesCount_Variable(void);
        bool get_SessionDiagnostics_RegisterNodesCount_Variable(OpcUaDataValue& dataValue);
        bool set_SessionDiagnostics_RegisterNodesCount_Variable(const OpcUaDataValue& dataValue);

        //
        // ServiceCounterDataType
        //
        void sessionDiagnostics_RepublishCount_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& sessionDiagnostics_RepublishCount_Variable(void);
        bool get_SessionDiagnostics_RepublishCount_Variable(OpcUaDataValue& dataValue);
        bool set_SessionDiagnostics_RepublishCount_Variable(const OpcUaDataValue& dataValue);

        //
        // String
        //
        void sessionDiagnostics_ServerUri_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& sessionDiagnostics_ServerUri_Variable(void);
        bool get_SessionDiagnostics_ServerUri_Variable(OpcUaDataValue& dataValue);
        bool set_SessionDiagnostics_ServerUri_Variable(const OpcUaDataValue& dataValue);

        //
        // NodeId
        //
        void sessionDiagnostics_SessionId_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& sessionDiagnostics_SessionId_Variable(void);
        bool get_SessionDiagnostics_SessionId_Variable(OpcUaDataValue& dataValue);
        bool set_SessionDiagnostics_SessionId_Variable(const OpcUaDataValue& dataValue);

        //
        // String
        //
        void sessionDiagnostics_SessionName_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& sessionDiagnostics_SessionName_Variable(void);
        bool get_SessionDiagnostics_SessionName_Variable(OpcUaDataValue& dataValue);
        bool set_SessionDiagnostics_SessionName_Variable(const OpcUaDataValue& dataValue);

        //
        // ServiceCounterDataType
        //
        void sessionDiagnostics_SetMonitoringModeCount_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& sessionDiagnostics_SetMonitoringModeCount_Variable(void);
        bool get_SessionDiagnostics_SetMonitoringModeCount_Variable(OpcUaDataValue& dataValue);
        bool set_SessionDiagnostics_SetMonitoringModeCount_Variable(const OpcUaDataValue& dataValue);

        //
        // ServiceCounterDataType
        //
        void sessionDiagnostics_SetPublishingModeCount_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& sessionDiagnostics_SetPublishingModeCount_Variable(void);
        bool get_SessionDiagnostics_SetPublishingModeCount_Variable(OpcUaDataValue& dataValue);
        bool set_SessionDiagnostics_SetPublishingModeCount_Variable(const OpcUaDataValue& dataValue);

        //
        // ServiceCounterDataType
        //
        void sessionDiagnostics_SetTriggeringCount_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& sessionDiagnostics_SetTriggeringCount_Variable(void);
        bool get_SessionDiagnostics_SetTriggeringCount_Variable(OpcUaDataValue& dataValue);
        bool set_SessionDiagnostics_SetTriggeringCount_Variable(const OpcUaDataValue& dataValue);

        //
        // ServiceCounterDataType
        //
        void sessionDiagnostics_TotalRequestCount_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& sessionDiagnostics_TotalRequestCount_Variable(void);
        bool get_SessionDiagnostics_TotalRequestCount_Variable(OpcUaDataValue& dataValue);
        bool set_SessionDiagnostics_TotalRequestCount_Variable(const OpcUaDataValue& dataValue);

        //
        // ServiceCounterDataType
        //
        void sessionDiagnostics_TransferSubscriptionsCount_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& sessionDiagnostics_TransferSubscriptionsCount_Variable(void);
        bool get_SessionDiagnostics_TransferSubscriptionsCount_Variable(OpcUaDataValue& dataValue);
        bool set_SessionDiagnostics_TransferSubscriptionsCount_Variable(const OpcUaDataValue& dataValue);

        //
        // ServiceCounterDataType
        //
        void sessionDiagnostics_TranslateBrowsePathsToNodeIdsCount_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& sessionDiagnostics_TranslateBrowsePathsToNodeIdsCount_Variable(void);
        bool get_SessionDiagnostics_TranslateBrowsePathsToNodeIdsCount_Variable(OpcUaDataValue& dataValue);
        bool set_SessionDiagnostics_TranslateBrowsePathsToNodeIdsCount_Variable(const OpcUaDataValue& dataValue);

        //
        // UInt32
        //
        void sessionDiagnostics_UnauthorizedRequestCount_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& sessionDiagnostics_UnauthorizedRequestCount_Variable(void);
        bool get_SessionDiagnostics_UnauthorizedRequestCount_Variable(OpcUaDataValue& dataValue);
        bool set_SessionDiagnostics_UnauthorizedRequestCount_Variable(const OpcUaDataValue& dataValue);

        //
        // ServiceCounterDataType
        //
        void sessionDiagnostics_UnregisterNodesCount_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& sessionDiagnostics_UnregisterNodesCount_Variable(void);
        bool get_SessionDiagnostics_UnregisterNodesCount_Variable(OpcUaDataValue& dataValue);
        bool set_SessionDiagnostics_UnregisterNodesCount_Variable(const OpcUaDataValue& dataValue);

        //
        // SessionDiagnosticsDataType
        //
        void sessionDiagnostics_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& sessionDiagnostics_Variable(void);
        bool get_SessionDiagnostics_Variable(OpcUaDataValue& dataValue);
        bool set_SessionDiagnostics_Variable(const OpcUaDataValue& dataValue);

        //
        // ServiceCounterDataType
        //
        void sessionDiagnostics_WriteCount_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& sessionDiagnostics_WriteCount_Variable(void);
        bool get_SessionDiagnostics_WriteCount_Variable(OpcUaDataValue& dataValue);
        bool set_SessionDiagnostics_WriteCount_Variable(const OpcUaDataValue& dataValue);

        //
        // String
        //
        void sessionSecurityDiagnostics_AuthenticationMechanism_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& sessionSecurityDiagnostics_AuthenticationMechanism_Variable(void);
        bool get_SessionSecurityDiagnostics_AuthenticationMechanism_Variable(OpcUaDataValue& dataValue);
        bool set_SessionSecurityDiagnostics_AuthenticationMechanism_Variable(const OpcUaDataValue& dataValue);

        //
        // ByteString
        //
        void sessionSecurityDiagnostics_ClientCertificate_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& sessionSecurityDiagnostics_ClientCertificate_Variable(void);
        bool get_SessionSecurityDiagnostics_ClientCertificate_Variable(OpcUaDataValue& dataValue);
        bool set_SessionSecurityDiagnostics_ClientCertificate_Variable(const OpcUaDataValue& dataValue);

        //
        // String (Array)
        //
        void sessionSecurityDiagnostics_ClientUserIdHistory_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& sessionSecurityDiagnostics_ClientUserIdHistory_Variable(void);
        bool get_SessionSecurityDiagnostics_ClientUserIdHistory_Variable(OpcUaDataValue& dataValue);
        bool set_SessionSecurityDiagnostics_ClientUserIdHistory_Variable(const OpcUaDataValue& dataValue);

        //
        // String
        //
        void sessionSecurityDiagnostics_ClientUserIdOfSession_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& sessionSecurityDiagnostics_ClientUserIdOfSession_Variable(void);
        bool get_SessionSecurityDiagnostics_ClientUserIdOfSession_Variable(OpcUaDataValue& dataValue);
        bool set_SessionSecurityDiagnostics_ClientUserIdOfSession_Variable(const OpcUaDataValue& dataValue);

        //
        // String
        //
        void sessionSecurityDiagnostics_Encoding_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& sessionSecurityDiagnostics_Encoding_Variable(void);
        bool get_SessionSecurityDiagnostics_Encoding_Variable(OpcUaDataValue& dataValue);
        bool set_SessionSecurityDiagnostics_Encoding_Variable(const OpcUaDataValue& dataValue);

        //
        // MessageSecurityMode
        //
        void sessionSecurityDiagnostics_SecurityMode_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& sessionSecurityDiagnostics_SecurityMode_Variable(void);
        bool get_SessionSecurityDiagnostics_SecurityMode_Variable(OpcUaDataValue& dataValue);
        bool set_SessionSecurityDiagnostics_SecurityMode_Variable(const OpcUaDataValue& dataValue);

        //
        // String
        //
        void sessionSecurityDiagnostics_SecurityPolicyUri_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& sessionSecurityDiagnostics_SecurityPolicyUri_Variable(void);
        bool get_SessionSecurityDiagnostics_SecurityPolicyUri_Variable(OpcUaDataValue& dataValue);
        bool set_SessionSecurityDiagnostics_SecurityPolicyUri_Variable(const OpcUaDataValue& dataValue);

        //
        // NodeId
        //
        void sessionSecurityDiagnostics_SessionId_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& sessionSecurityDiagnostics_SessionId_Variable(void);
        bool get_SessionSecurityDiagnostics_SessionId_Variable(OpcUaDataValue& dataValue);
        bool set_SessionSecurityDiagnostics_SessionId_Variable(const OpcUaDataValue& dataValue);

        //
        // String
        //
        void sessionSecurityDiagnostics_TransportProtocol_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& sessionSecurityDiagnostics_TransportProtocol_Variable(void);
        bool get_SessionSecurityDiagnostics_TransportProtocol_Variable(OpcUaDataValue& dataValue);
        bool set_SessionSecurityDiagnostics_TransportProtocol_Variable(const OpcUaDataValue& dataValue);

        //
        // SessionSecurityDiagnosticsDataType
        //
        void sessionSecurityDiagnostics_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& sessionSecurityDiagnostics_Variable(void);
        bool get_SessionSecurityDiagnostics_Variable(OpcUaDataValue& dataValue);
        bool set_SessionSecurityDiagnostics_Variable(const OpcUaDataValue& dataValue);

        //
        // SubscriptionDiagnosticsDataType (Array)
        //
        void subscriptionDiagnosticsArray_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& subscriptionDiagnosticsArray_Variable(void);
        bool get_SubscriptionDiagnosticsArray_Variable(OpcUaDataValue& dataValue);
        bool set_SubscriptionDiagnosticsArray_Variable(const OpcUaDataValue& dataValue);
    
      private:
        ServerVariable::SPtr sessionDiagnostics_ActualSessionTimeout_Variable_;
        ServerVariable::SPtr sessionDiagnostics_AddNodesCount_Variable_;
        ServerVariable::SPtr sessionDiagnostics_AddReferencesCount_Variable_;
        ServerVariable::SPtr sessionDiagnostics_BrowseCount_Variable_;
        ServerVariable::SPtr sessionDiagnostics_BrowseNextCount_Variable_;
        ServerVariable::SPtr sessionDiagnostics_CallCount_Variable_;
        ServerVariable::SPtr sessionDiagnostics_ClientConnectionTime_Variable_;
        ServerVariable::SPtr sessionDiagnostics_ClientDescription_Variable_;
        ServerVariable::SPtr sessionDiagnostics_ClientLastContactTime_Variable_;
        ServerVariable::SPtr sessionDiagnostics_CreateMonitoredItemsCount_Variable_;
        ServerVariable::SPtr sessionDiagnostics_CreateSubscriptionCount_Variable_;
        ServerVariable::SPtr sessionDiagnostics_CurrentMonitoredItemsCount_Variable_;
        ServerVariable::SPtr sessionDiagnostics_CurrentPublishRequestsInQueue_Variable_;
        ServerVariable::SPtr sessionDiagnostics_CurrentSubscriptionsCount_Variable_;
        ServerVariable::SPtr sessionDiagnostics_DeleteMonitoredItemsCount_Variable_;
        ServerVariable::SPtr sessionDiagnostics_DeleteNodesCount_Variable_;
        ServerVariable::SPtr sessionDiagnostics_DeleteReferencesCount_Variable_;
        ServerVariable::SPtr sessionDiagnostics_DeleteSubscriptionsCount_Variable_;
        ServerVariable::SPtr sessionDiagnostics_EndpointUrl_Variable_;
        ServerVariable::SPtr sessionDiagnostics_HistoryReadCount_Variable_;
        ServerVariable::SPtr sessionDiagnostics_HistoryUpdateCount_Variable_;
        ServerVariable::SPtr sessionDiagnostics_LocaleIds_Variable_;
        ServerVariable::SPtr sessionDiagnostics_MaxResponseMessageSize_Variable_;
        ServerVariable::SPtr sessionDiagnostics_ModifyMonitoredItemsCount_Variable_;
        ServerVariable::SPtr sessionDiagnostics_ModifySubscriptionCount_Variable_;
        ServerVariable::SPtr sessionDiagnostics_PublishCount_Variable_;
        ServerVariable::SPtr sessionDiagnostics_QueryFirstCount_Variable_;
        ServerVariable::SPtr sessionDiagnostics_QueryNextCount_Variable_;
        ServerVariable::SPtr sessionDiagnostics_ReadCount_Variable_;
        ServerVariable::SPtr sessionDiagnostics_RegisterNodesCount_Variable_;
        ServerVariable::SPtr sessionDiagnostics_RepublishCount_Variable_;
        ServerVariable::SPtr sessionDiagnostics_ServerUri_Variable_;
        ServerVariable::SPtr sessionDiagnostics_SessionId_Variable_;
        ServerVariable::SPtr sessionDiagnostics_SessionName_Variable_;
        ServerVariable::SPtr sessionDiagnostics_SetMonitoringModeCount_Variable_;
        ServerVariable::SPtr sessionDiagnostics_SetPublishingModeCount_Variable_;
        ServerVariable::SPtr sessionDiagnostics_SetTriggeringCount_Variable_;
        ServerVariable::SPtr sessionDiagnostics_TotalRequestCount_Variable_;
        ServerVariable::SPtr sessionDiagnostics_TransferSubscriptionsCount_Variable_;
        ServerVariable::SPtr sessionDiagnostics_TranslateBrowsePathsToNodeIdsCount_Variable_;
        ServerVariable::SPtr sessionDiagnostics_UnauthorizedRequestCount_Variable_;
        ServerVariable::SPtr sessionDiagnostics_UnregisterNodesCount_Variable_;
        ServerVariable::SPtr sessionDiagnostics_Variable_;
        ServerVariable::SPtr sessionDiagnostics_WriteCount_Variable_;
        ServerVariable::SPtr sessionSecurityDiagnostics_AuthenticationMechanism_Variable_;
        ServerVariable::SPtr sessionSecurityDiagnostics_ClientCertificate_Variable_;
        ServerVariable::SPtr sessionSecurityDiagnostics_ClientUserIdHistory_Variable_;
        ServerVariable::SPtr sessionSecurityDiagnostics_ClientUserIdOfSession_Variable_;
        ServerVariable::SPtr sessionSecurityDiagnostics_Encoding_Variable_;
        ServerVariable::SPtr sessionSecurityDiagnostics_SecurityMode_Variable_;
        ServerVariable::SPtr sessionSecurityDiagnostics_SecurityPolicyUri_Variable_;
        ServerVariable::SPtr sessionSecurityDiagnostics_SessionId_Variable_;
        ServerVariable::SPtr sessionSecurityDiagnostics_TransportProtocol_Variable_;
        ServerVariable::SPtr sessionSecurityDiagnostics_Variable_;
        ServerVariable::SPtr subscriptionDiagnosticsArray_Variable_;
   
   };

}

#endif
