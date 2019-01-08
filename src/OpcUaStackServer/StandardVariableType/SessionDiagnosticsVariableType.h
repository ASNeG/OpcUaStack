/*
    VariableTypeClass: SessionDiagnosticsVariableType

    Generated Source Code - please do not change this source code

    VariableTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

    Autor:     Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackServer_SessionDiagnosticsVariableType_h__
#define __OpcUaStackServer_SessionDiagnosticsVariableType_h__

#include "OpcUaStackServer/StandardVariableType/VariableBase.h"

namespace OpcUaStackServer
{
   
   class DLLEXPORT SessionDiagnosticsVariableType
   : public VariableBase
   {
     public:
       typedef boost::shared_ptr<SessionDiagnosticsVariableType> SPtr;
       typedef std::vector<SessionDiagnosticsVariableType::SPtr> Vec;
   
       SessionDiagnosticsVariableType(void);
       SessionDiagnosticsVariableType(const SessionDiagnosticsVariableType& value);
       virtual ~SessionDiagnosticsVariableType(void);

        //
        // Duration
        //
        void actualSessionTimeout_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& actualSessionTimeout_Variable(void);
        bool get_ActualSessionTimeout_Variable(OpcUaDataValue& dataValue);
        bool set_ActualSessionTimeout_Variable(const OpcUaDataValue& dataValue);

        //
        // ServiceCounterDataType
        //
        void addNodesCount_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& addNodesCount_Variable(void);
        bool get_AddNodesCount_Variable(OpcUaDataValue& dataValue);
        bool set_AddNodesCount_Variable(const OpcUaDataValue& dataValue);

        //
        // ServiceCounterDataType
        //
        void addReferencesCount_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& addReferencesCount_Variable(void);
        bool get_AddReferencesCount_Variable(OpcUaDataValue& dataValue);
        bool set_AddReferencesCount_Variable(const OpcUaDataValue& dataValue);

        //
        // ServiceCounterDataType
        //
        void browseCount_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& browseCount_Variable(void);
        bool get_BrowseCount_Variable(OpcUaDataValue& dataValue);
        bool set_BrowseCount_Variable(const OpcUaDataValue& dataValue);

        //
        // ServiceCounterDataType
        //
        void browseNextCount_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& browseNextCount_Variable(void);
        bool get_BrowseNextCount_Variable(OpcUaDataValue& dataValue);
        bool set_BrowseNextCount_Variable(const OpcUaDataValue& dataValue);

        //
        // ServiceCounterDataType
        //
        void callCount_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& callCount_Variable(void);
        bool get_CallCount_Variable(OpcUaDataValue& dataValue);
        bool set_CallCount_Variable(const OpcUaDataValue& dataValue);

        //
        // UtcTime
        //
        void clientConnectionTime_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& clientConnectionTime_Variable(void);
        bool get_ClientConnectionTime_Variable(OpcUaDataValue& dataValue);
        bool set_ClientConnectionTime_Variable(const OpcUaDataValue& dataValue);

        //
        // ApplicationDescription
        //
        void clientDescription_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& clientDescription_Variable(void);
        bool get_ClientDescription_Variable(OpcUaDataValue& dataValue);
        bool set_ClientDescription_Variable(const OpcUaDataValue& dataValue);

        //
        // UtcTime
        //
        void clientLastContactTime_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& clientLastContactTime_Variable(void);
        bool get_ClientLastContactTime_Variable(OpcUaDataValue& dataValue);
        bool set_ClientLastContactTime_Variable(const OpcUaDataValue& dataValue);

        //
        // ServiceCounterDataType
        //
        void createMonitoredItemsCount_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& createMonitoredItemsCount_Variable(void);
        bool get_CreateMonitoredItemsCount_Variable(OpcUaDataValue& dataValue);
        bool set_CreateMonitoredItemsCount_Variable(const OpcUaDataValue& dataValue);

        //
        // ServiceCounterDataType
        //
        void createSubscriptionCount_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& createSubscriptionCount_Variable(void);
        bool get_CreateSubscriptionCount_Variable(OpcUaDataValue& dataValue);
        bool set_CreateSubscriptionCount_Variable(const OpcUaDataValue& dataValue);

        //
        // UInt32
        //
        void currentMonitoredItemsCount_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& currentMonitoredItemsCount_Variable(void);
        bool get_CurrentMonitoredItemsCount_Variable(OpcUaDataValue& dataValue);
        bool set_CurrentMonitoredItemsCount_Variable(const OpcUaDataValue& dataValue);

        //
        // UInt32
        //
        void currentPublishRequestsInQueue_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& currentPublishRequestsInQueue_Variable(void);
        bool get_CurrentPublishRequestsInQueue_Variable(OpcUaDataValue& dataValue);
        bool set_CurrentPublishRequestsInQueue_Variable(const OpcUaDataValue& dataValue);

        //
        // UInt32
        //
        void currentSubscriptionsCount_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& currentSubscriptionsCount_Variable(void);
        bool get_CurrentSubscriptionsCount_Variable(OpcUaDataValue& dataValue);
        bool set_CurrentSubscriptionsCount_Variable(const OpcUaDataValue& dataValue);

        //
        // ServiceCounterDataType
        //
        void deleteMonitoredItemsCount_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& deleteMonitoredItemsCount_Variable(void);
        bool get_DeleteMonitoredItemsCount_Variable(OpcUaDataValue& dataValue);
        bool set_DeleteMonitoredItemsCount_Variable(const OpcUaDataValue& dataValue);

        //
        // ServiceCounterDataType
        //
        void deleteNodesCount_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& deleteNodesCount_Variable(void);
        bool get_DeleteNodesCount_Variable(OpcUaDataValue& dataValue);
        bool set_DeleteNodesCount_Variable(const OpcUaDataValue& dataValue);

        //
        // ServiceCounterDataType
        //
        void deleteReferencesCount_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& deleteReferencesCount_Variable(void);
        bool get_DeleteReferencesCount_Variable(OpcUaDataValue& dataValue);
        bool set_DeleteReferencesCount_Variable(const OpcUaDataValue& dataValue);

        //
        // ServiceCounterDataType
        //
        void deleteSubscriptionsCount_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& deleteSubscriptionsCount_Variable(void);
        bool get_DeleteSubscriptionsCount_Variable(OpcUaDataValue& dataValue);
        bool set_DeleteSubscriptionsCount_Variable(const OpcUaDataValue& dataValue);

        //
        // String
        //
        void endpointUrl_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& endpointUrl_Variable(void);
        bool get_EndpointUrl_Variable(OpcUaDataValue& dataValue);
        bool set_EndpointUrl_Variable(const OpcUaDataValue& dataValue);

        //
        // ServiceCounterDataType
        //
        void historyReadCount_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& historyReadCount_Variable(void);
        bool get_HistoryReadCount_Variable(OpcUaDataValue& dataValue);
        bool set_HistoryReadCount_Variable(const OpcUaDataValue& dataValue);

        //
        // ServiceCounterDataType
        //
        void historyUpdateCount_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& historyUpdateCount_Variable(void);
        bool get_HistoryUpdateCount_Variable(OpcUaDataValue& dataValue);
        bool set_HistoryUpdateCount_Variable(const OpcUaDataValue& dataValue);

        //
        // LocaleId (Array)
        //
        void localeIds_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& localeIds_Variable(void);
        bool get_LocaleIds_Variable(OpcUaDataValue& dataValue);
        bool set_LocaleIds_Variable(const OpcUaDataValue& dataValue);

        //
        // UInt32
        //
        void maxResponseMessageSize_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& maxResponseMessageSize_Variable(void);
        bool get_MaxResponseMessageSize_Variable(OpcUaDataValue& dataValue);
        bool set_MaxResponseMessageSize_Variable(const OpcUaDataValue& dataValue);

        //
        // ServiceCounterDataType
        //
        void modifyMonitoredItemsCount_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& modifyMonitoredItemsCount_Variable(void);
        bool get_ModifyMonitoredItemsCount_Variable(OpcUaDataValue& dataValue);
        bool set_ModifyMonitoredItemsCount_Variable(const OpcUaDataValue& dataValue);

        //
        // ServiceCounterDataType
        //
        void modifySubscriptionCount_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& modifySubscriptionCount_Variable(void);
        bool get_ModifySubscriptionCount_Variable(OpcUaDataValue& dataValue);
        bool set_ModifySubscriptionCount_Variable(const OpcUaDataValue& dataValue);

        //
        // ServiceCounterDataType
        //
        void publishCount_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& publishCount_Variable(void);
        bool get_PublishCount_Variable(OpcUaDataValue& dataValue);
        bool set_PublishCount_Variable(const OpcUaDataValue& dataValue);

        //
        // ServiceCounterDataType
        //
        void queryFirstCount_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& queryFirstCount_Variable(void);
        bool get_QueryFirstCount_Variable(OpcUaDataValue& dataValue);
        bool set_QueryFirstCount_Variable(const OpcUaDataValue& dataValue);

        //
        // ServiceCounterDataType
        //
        void queryNextCount_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& queryNextCount_Variable(void);
        bool get_QueryNextCount_Variable(OpcUaDataValue& dataValue);
        bool set_QueryNextCount_Variable(const OpcUaDataValue& dataValue);

        //
        // ServiceCounterDataType
        //
        void readCount_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& readCount_Variable(void);
        bool get_ReadCount_Variable(OpcUaDataValue& dataValue);
        bool set_ReadCount_Variable(const OpcUaDataValue& dataValue);

        //
        // ServiceCounterDataType
        //
        void registerNodesCount_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& registerNodesCount_Variable(void);
        bool get_RegisterNodesCount_Variable(OpcUaDataValue& dataValue);
        bool set_RegisterNodesCount_Variable(const OpcUaDataValue& dataValue);

        //
        // ServiceCounterDataType
        //
        void republishCount_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& republishCount_Variable(void);
        bool get_RepublishCount_Variable(OpcUaDataValue& dataValue);
        bool set_RepublishCount_Variable(const OpcUaDataValue& dataValue);

        //
        // String
        //
        void serverUri_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& serverUri_Variable(void);
        bool get_ServerUri_Variable(OpcUaDataValue& dataValue);
        bool set_ServerUri_Variable(const OpcUaDataValue& dataValue);

        //
        // NodeId
        //
        void sessionId_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& sessionId_Variable(void);
        bool get_SessionId_Variable(OpcUaDataValue& dataValue);
        bool set_SessionId_Variable(const OpcUaDataValue& dataValue);

        //
        // String
        //
        void sessionName_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& sessionName_Variable(void);
        bool get_SessionName_Variable(OpcUaDataValue& dataValue);
        bool set_SessionName_Variable(const OpcUaDataValue& dataValue);

        //
        // ServiceCounterDataType
        //
        void setMonitoringModeCount_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& setMonitoringModeCount_Variable(void);
        bool get_SetMonitoringModeCount_Variable(OpcUaDataValue& dataValue);
        bool set_SetMonitoringModeCount_Variable(const OpcUaDataValue& dataValue);

        //
        // ServiceCounterDataType
        //
        void setPublishingModeCount_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& setPublishingModeCount_Variable(void);
        bool get_SetPublishingModeCount_Variable(OpcUaDataValue& dataValue);
        bool set_SetPublishingModeCount_Variable(const OpcUaDataValue& dataValue);

        //
        // ServiceCounterDataType
        //
        void setTriggeringCount_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& setTriggeringCount_Variable(void);
        bool get_SetTriggeringCount_Variable(OpcUaDataValue& dataValue);
        bool set_SetTriggeringCount_Variable(const OpcUaDataValue& dataValue);

        //
        // ServiceCounterDataType
        //
        void totalRequestCount_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& totalRequestCount_Variable(void);
        bool get_TotalRequestCount_Variable(OpcUaDataValue& dataValue);
        bool set_TotalRequestCount_Variable(const OpcUaDataValue& dataValue);

        //
        // ServiceCounterDataType
        //
        void transferSubscriptionsCount_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& transferSubscriptionsCount_Variable(void);
        bool get_TransferSubscriptionsCount_Variable(OpcUaDataValue& dataValue);
        bool set_TransferSubscriptionsCount_Variable(const OpcUaDataValue& dataValue);

        //
        // ServiceCounterDataType
        //
        void translateBrowsePathsToNodeIdsCount_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& translateBrowsePathsToNodeIdsCount_Variable(void);
        bool get_TranslateBrowsePathsToNodeIdsCount_Variable(OpcUaDataValue& dataValue);
        bool set_TranslateBrowsePathsToNodeIdsCount_Variable(const OpcUaDataValue& dataValue);

        //
        // UInt32
        //
        void unauthorizedRequestCount_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& unauthorizedRequestCount_Variable(void);
        bool get_UnauthorizedRequestCount_Variable(OpcUaDataValue& dataValue);
        bool set_UnauthorizedRequestCount_Variable(const OpcUaDataValue& dataValue);

        //
        // ServiceCounterDataType
        //
        void unregisterNodesCount_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& unregisterNodesCount_Variable(void);
        bool get_UnregisterNodesCount_Variable(OpcUaDataValue& dataValue);
        bool set_UnregisterNodesCount_Variable(const OpcUaDataValue& dataValue);

        //
        // SessionDiagnosticsDataType (Array)
        //
        void variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& variable(void);
        bool get_Variable(OpcUaDataValue& dataValue);
        bool set_Variable(const OpcUaDataValue& dataValue);

        //
        // ServiceCounterDataType
        //
        void writeCount_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& writeCount_Variable(void);
        bool get_WriteCount_Variable(OpcUaDataValue& dataValue);
        bool set_WriteCount_Variable(const OpcUaDataValue& dataValue);
    
      private:
        ServerVariable::SPtr actualSessionTimeout_Variable_;
        ServerVariable::SPtr addNodesCount_Variable_;
        ServerVariable::SPtr addReferencesCount_Variable_;
        ServerVariable::SPtr browseCount_Variable_;
        ServerVariable::SPtr browseNextCount_Variable_;
        ServerVariable::SPtr callCount_Variable_;
        ServerVariable::SPtr clientConnectionTime_Variable_;
        ServerVariable::SPtr clientDescription_Variable_;
        ServerVariable::SPtr clientLastContactTime_Variable_;
        ServerVariable::SPtr createMonitoredItemsCount_Variable_;
        ServerVariable::SPtr createSubscriptionCount_Variable_;
        ServerVariable::SPtr currentMonitoredItemsCount_Variable_;
        ServerVariable::SPtr currentPublishRequestsInQueue_Variable_;
        ServerVariable::SPtr currentSubscriptionsCount_Variable_;
        ServerVariable::SPtr deleteMonitoredItemsCount_Variable_;
        ServerVariable::SPtr deleteNodesCount_Variable_;
        ServerVariable::SPtr deleteReferencesCount_Variable_;
        ServerVariable::SPtr deleteSubscriptionsCount_Variable_;
        ServerVariable::SPtr endpointUrl_Variable_;
        ServerVariable::SPtr historyReadCount_Variable_;
        ServerVariable::SPtr historyUpdateCount_Variable_;
        ServerVariable::SPtr localeIds_Variable_;
        ServerVariable::SPtr maxResponseMessageSize_Variable_;
        ServerVariable::SPtr modifyMonitoredItemsCount_Variable_;
        ServerVariable::SPtr modifySubscriptionCount_Variable_;
        ServerVariable::SPtr publishCount_Variable_;
        ServerVariable::SPtr queryFirstCount_Variable_;
        ServerVariable::SPtr queryNextCount_Variable_;
        ServerVariable::SPtr readCount_Variable_;
        ServerVariable::SPtr registerNodesCount_Variable_;
        ServerVariable::SPtr republishCount_Variable_;
        ServerVariable::SPtr serverUri_Variable_;
        ServerVariable::SPtr sessionId_Variable_;
        ServerVariable::SPtr sessionName_Variable_;
        ServerVariable::SPtr setMonitoringModeCount_Variable_;
        ServerVariable::SPtr setPublishingModeCount_Variable_;
        ServerVariable::SPtr setTriggeringCount_Variable_;
        ServerVariable::SPtr totalRequestCount_Variable_;
        ServerVariable::SPtr transferSubscriptionsCount_Variable_;
        ServerVariable::SPtr translateBrowsePathsToNodeIdsCount_Variable_;
        ServerVariable::SPtr unauthorizedRequestCount_Variable_;
        ServerVariable::SPtr unregisterNodesCount_Variable_;
        ServerVariable::SPtr variable_;
        ServerVariable::SPtr writeCount_Variable_;
   
   };

}

#endif
