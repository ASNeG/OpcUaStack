/*
    ObjectTypeClass: AcknowledgeableConditionType

    Generated Source Code - please do not change this source code

    ObjectTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

    Autor:     Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackServer_AcknowledgeableConditionType_h__
#define __OpcUaStackServer_AcknowledgeableConditionType_h__

#include "OpcUaStackServer/StandardVariableType/VariableBase.h"
#include "OpcUaStackServer/StandardObjectType/ObjectBase.h"

namespace OpcUaStackServer
{
   
   class DLLEXPORT AcknowledgeableConditionType
   : public ObjectBase
   {
     public:
       typedef boost::shared_ptr<AcknowledgeableConditionType> SPtr;
       typedef std::vector<AcknowledgeableConditionType::SPtr> Vec;
   
       AcknowledgeableConditionType(void);
       AcknowledgeableConditionType(const AcknowledgeableConditionType& value);
       virtual ~AcknowledgeableConditionType(void);

        //
        // LocalizedText
        //
        void ackedState_FalseState_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& ackedState_FalseState_Variable(void);
        bool get_AckedState_FalseState_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_AckedState_FalseState_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // Boolean
        //
        void ackedState_Id_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& ackedState_Id_Variable(void);
        bool get_AckedState_Id_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_AckedState_Id_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // UtcTime
        //
        void ackedState_TransitionTime_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& ackedState_TransitionTime_Variable(void);
        bool get_AckedState_TransitionTime_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_AckedState_TransitionTime_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // LocalizedText
        //
        void ackedState_TrueState_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& ackedState_TrueState_Variable(void);
        bool get_AckedState_TrueState_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_AckedState_TrueState_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // LocalizedText
        //
        void ackedState_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& ackedState_Variable(void);
        bool get_AckedState_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_AckedState_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // NodeId
        //
        void branchId_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& branchId_Variable(void);
        bool get_BranchId_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_BranchId_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // String
        //
        void clientUserId_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& clientUserId_Variable(void);
        bool get_ClientUserId_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_ClientUserId_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // UtcTime
        //
        void comment_SourceTimestamp_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& comment_SourceTimestamp_Variable(void);
        bool get_Comment_SourceTimestamp_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_Comment_SourceTimestamp_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // LocalizedText
        //
        void comment_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& comment_Variable(void);
        bool get_Comment_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_Comment_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // NodeId
        //
        void conditionClassId_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& conditionClassId_Variable(void);
        bool get_ConditionClassId_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_ConditionClassId_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // LocalizedText
        //
        void conditionClassName_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& conditionClassName_Variable(void);
        bool get_ConditionClassName_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_ConditionClassName_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // String
        //
        void conditionName_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& conditionName_Variable(void);
        bool get_ConditionName_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_ConditionName_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // NodeId (Array)
        //
        void conditionSubClassId_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& conditionSubClassId_Variable(void);
        bool get_ConditionSubClassId_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_ConditionSubClassId_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // LocalizedText (Array)
        //
        void conditionSubClassName_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& conditionSubClassName_Variable(void);
        bool get_ConditionSubClassName_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_ConditionSubClassName_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // LocalizedText
        //
        void confirmedState_FalseState_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& confirmedState_FalseState_Variable(void);
        bool get_ConfirmedState_FalseState_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_ConfirmedState_FalseState_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // Boolean
        //
        void confirmedState_Id_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& confirmedState_Id_Variable(void);
        bool get_ConfirmedState_Id_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_ConfirmedState_Id_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // UtcTime
        //
        void confirmedState_TransitionTime_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& confirmedState_TransitionTime_Variable(void);
        bool get_ConfirmedState_TransitionTime_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_ConfirmedState_TransitionTime_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // LocalizedText
        //
        void confirmedState_TrueState_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& confirmedState_TrueState_Variable(void);
        bool get_ConfirmedState_TrueState_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_ConfirmedState_TrueState_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // LocalizedText
        //
        void confirmedState_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& confirmedState_Variable(void);
        bool get_ConfirmedState_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_ConfirmedState_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // LocalizedText
        //
        void enabledState_EffectiveDisplayName_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& enabledState_EffectiveDisplayName_Variable(void);
        bool get_EnabledState_EffectiveDisplayName_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_EnabledState_EffectiveDisplayName_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // UtcTime
        //
        void enabledState_EffectiveTransitionTime_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& enabledState_EffectiveTransitionTime_Variable(void);
        bool get_EnabledState_EffectiveTransitionTime_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_EnabledState_EffectiveTransitionTime_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // LocalizedText
        //
        void enabledState_FalseState_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& enabledState_FalseState_Variable(void);
        bool get_EnabledState_FalseState_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_EnabledState_FalseState_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // Boolean
        //
        void enabledState_Id_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& enabledState_Id_Variable(void);
        bool get_EnabledState_Id_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_EnabledState_Id_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // UtcTime
        //
        void enabledState_TransitionTime_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& enabledState_TransitionTime_Variable(void);
        bool get_EnabledState_TransitionTime_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_EnabledState_TransitionTime_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // LocalizedText
        //
        void enabledState_TrueState_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& enabledState_TrueState_Variable(void);
        bool get_EnabledState_TrueState_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_EnabledState_TrueState_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // LocalizedText
        //
        void enabledState_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& enabledState_Variable(void);
        bool get_EnabledState_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_EnabledState_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // ByteString
        //
        void eventId_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& eventId_Variable(void);
        bool get_EventId_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_EventId_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // NodeId
        //
        void eventType_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& eventType_Variable(void);
        bool get_EventType_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_EventType_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // UtcTime
        //
        void lastSeverity_SourceTimestamp_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& lastSeverity_SourceTimestamp_Variable(void);
        bool get_LastSeverity_SourceTimestamp_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_LastSeverity_SourceTimestamp_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // UInt16
        //
        void lastSeverity_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& lastSeverity_Variable(void);
        bool get_LastSeverity_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_LastSeverity_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // TimeZoneDataType
        //
        void localTime_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& localTime_Variable(void);
        bool get_LocalTime_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_LocalTime_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // LocalizedText
        //
        void message_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& message_Variable(void);
        bool get_Message_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_Message_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // UtcTime
        //
        void quality_SourceTimestamp_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& quality_SourceTimestamp_Variable(void);
        bool get_Quality_SourceTimestamp_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_Quality_SourceTimestamp_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // Status
        //
        void quality_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& quality_Variable(void);
        bool get_Quality_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_Quality_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // UtcTime
        //
        void receiveTime_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& receiveTime_Variable(void);
        bool get_ReceiveTime_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_ReceiveTime_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // Boolean
        //
        void retain_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& retain_Variable(void);
        bool get_Retain_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_Retain_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // UInt16
        //
        void severity_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& severity_Variable(void);
        bool get_Severity_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_Severity_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // String
        //
        void sourceName_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& sourceName_Variable(void);
        bool get_SourceName_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_SourceName_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // NodeId
        //
        void sourceNode_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& sourceNode_Variable(void);
        bool get_SourceNode_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_SourceNode_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // UtcTime
        //
        void time_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& time_Variable(void);
        bool get_Time_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_Time_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        virtual void call_Acknowledge_Method(OpcUaStackCore::ApplicationMethodContext* applicationMethodContext);

        virtual void call_AddComment_Method(OpcUaStackCore::ApplicationMethodContext* applicationMethodContext);

        virtual void call_Confirm_Method(OpcUaStackCore::ApplicationMethodContext* applicationMethodContext);

        virtual void call_Disable_Method(OpcUaStackCore::ApplicationMethodContext* applicationMethodContext);

        virtual void call_Enable_Method(OpcUaStackCore::ApplicationMethodContext* applicationMethodContext);
    
      private:
        ServerVariable::SPtr ackedState_FalseState_Variable_;
        ServerVariable::SPtr ackedState_Id_Variable_;
        ServerVariable::SPtr ackedState_TransitionTime_Variable_;
        ServerVariable::SPtr ackedState_TrueState_Variable_;
        ServerVariable::SPtr ackedState_Variable_;
        ServerVariable::SPtr branchId_Variable_;
        ServerVariable::SPtr clientUserId_Variable_;
        ServerVariable::SPtr comment_SourceTimestamp_Variable_;
        ServerVariable::SPtr comment_Variable_;
        ServerVariable::SPtr conditionClassId_Variable_;
        ServerVariable::SPtr conditionClassName_Variable_;
        ServerVariable::SPtr conditionName_Variable_;
        ServerVariable::SPtr conditionSubClassId_Variable_;
        ServerVariable::SPtr conditionSubClassName_Variable_;
        ServerVariable::SPtr confirmedState_FalseState_Variable_;
        ServerVariable::SPtr confirmedState_Id_Variable_;
        ServerVariable::SPtr confirmedState_TransitionTime_Variable_;
        ServerVariable::SPtr confirmedState_TrueState_Variable_;
        ServerVariable::SPtr confirmedState_Variable_;
        ServerVariable::SPtr enabledState_EffectiveDisplayName_Variable_;
        ServerVariable::SPtr enabledState_EffectiveTransitionTime_Variable_;
        ServerVariable::SPtr enabledState_FalseState_Variable_;
        ServerVariable::SPtr enabledState_Id_Variable_;
        ServerVariable::SPtr enabledState_TransitionTime_Variable_;
        ServerVariable::SPtr enabledState_TrueState_Variable_;
        ServerVariable::SPtr enabledState_Variable_;
        ServerVariable::SPtr eventId_Variable_;
        ServerVariable::SPtr eventType_Variable_;
        ServerVariable::SPtr lastSeverity_SourceTimestamp_Variable_;
        ServerVariable::SPtr lastSeverity_Variable_;
        ServerVariable::SPtr localTime_Variable_;
        ServerVariable::SPtr message_Variable_;
        ServerVariable::SPtr quality_SourceTimestamp_Variable_;
        ServerVariable::SPtr quality_Variable_;
        ServerVariable::SPtr receiveTime_Variable_;
        ServerVariable::SPtr retain_Variable_;
        ServerVariable::SPtr severity_Variable_;
        ServerVariable::SPtr sourceName_Variable_;
        ServerVariable::SPtr sourceNode_Variable_;
        ServerVariable::SPtr time_Variable_;
        ServerMethod::SPtr acknowledge_Method_;
        ServerMethod::SPtr addComment_Method_;
        ServerMethod::SPtr confirm_Method_;
        ServerMethod::SPtr disable_Method_;
        ServerMethod::SPtr enable_Method_;
   
   };

}

#endif
