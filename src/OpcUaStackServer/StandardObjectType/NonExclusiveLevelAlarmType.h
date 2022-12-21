/*
    ObjectTypeClass: NonExclusiveLevelAlarmType

    Generated Source Code - please do not change this source code

    ObjectTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

    Autor:     Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackServer_NonExclusiveLevelAlarmType_h__
#define __OpcUaStackServer_NonExclusiveLevelAlarmType_h__

#include "OpcUaStackServer/StandardVariableType/VariableBase.h"
#include "OpcUaStackServer/StandardObjectType/ObjectBase.h"

namespace OpcUaStackServer
{
   
   class DLLEXPORT NonExclusiveLevelAlarmType
   : public ObjectBase
   {
     public:
       typedef boost::shared_ptr<NonExclusiveLevelAlarmType> SPtr;
       typedef std::vector<NonExclusiveLevelAlarmType::SPtr> Vec;
   
       NonExclusiveLevelAlarmType(void);
       NonExclusiveLevelAlarmType(const NonExclusiveLevelAlarmType& value);
       virtual ~NonExclusiveLevelAlarmType(void);

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
        // LocalizedText
        //
        void activeState_EffectiveDisplayName_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& activeState_EffectiveDisplayName_Variable(void);
        bool get_ActiveState_EffectiveDisplayName_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_ActiveState_EffectiveDisplayName_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // UtcTime
        //
        void activeState_EffectiveTransitionTime_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& activeState_EffectiveTransitionTime_Variable(void);
        bool get_ActiveState_EffectiveTransitionTime_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_ActiveState_EffectiveTransitionTime_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // LocalizedText
        //
        void activeState_FalseState_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& activeState_FalseState_Variable(void);
        bool get_ActiveState_FalseState_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_ActiveState_FalseState_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // Boolean
        //
        void activeState_Id_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& activeState_Id_Variable(void);
        bool get_ActiveState_Id_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_ActiveState_Id_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // UtcTime
        //
        void activeState_TransitionTime_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& activeState_TransitionTime_Variable(void);
        bool get_ActiveState_TransitionTime_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_ActiveState_TransitionTime_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // LocalizedText
        //
        void activeState_TrueState_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& activeState_TrueState_Variable(void);
        bool get_ActiveState_TrueState_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_ActiveState_TrueState_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // LocalizedText
        //
        void activeState_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& activeState_Variable(void);
        bool get_ActiveState_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_ActiveState_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // Boolean
        //
        void audibleEnabled_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& audibleEnabled_Variable(void);
        bool get_AudibleEnabled_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_AudibleEnabled_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // AudioDataType
        //
        void audibleSound_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& audibleSound_Variable(void);
        bool get_AudibleSound_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_AudibleSound_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // Double
        //
        void baseHighHighLimit_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& baseHighHighLimit_Variable(void);
        bool get_BaseHighHighLimit_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_BaseHighHighLimit_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // Double
        //
        void baseHighLimit_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& baseHighLimit_Variable(void);
        bool get_BaseHighLimit_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_BaseHighLimit_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // Double
        //
        void baseLowLimit_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& baseLowLimit_Variable(void);
        bool get_BaseLowLimit_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_BaseLowLimit_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // Double
        //
        void baseLowLowLimit_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& baseLowLowLimit_Variable(void);
        bool get_BaseLowLowLimit_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_BaseLowLowLimit_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

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
        // Boolean
        //
        void firstInGroupFlag_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& firstInGroupFlag_Variable(void);
        bool get_FirstInGroupFlag_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_FirstInGroupFlag_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // Double
        //
        void highHighLimit_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& highHighLimit_Variable(void);
        bool get_HighHighLimit_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_HighHighLimit_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // LocalizedText
        //
        void highHighState_FalseState_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& highHighState_FalseState_Variable(void);
        bool get_HighHighState_FalseState_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_HighHighState_FalseState_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // Boolean
        //
        void highHighState_Id_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& highHighState_Id_Variable(void);
        bool get_HighHighState_Id_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_HighHighState_Id_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // UtcTime
        //
        void highHighState_TransitionTime_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& highHighState_TransitionTime_Variable(void);
        bool get_HighHighState_TransitionTime_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_HighHighState_TransitionTime_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // LocalizedText
        //
        void highHighState_TrueState_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& highHighState_TrueState_Variable(void);
        bool get_HighHighState_TrueState_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_HighHighState_TrueState_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // LocalizedText
        //
        void highHighState_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& highHighState_Variable(void);
        bool get_HighHighState_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_HighHighState_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // Double
        //
        void highLimit_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& highLimit_Variable(void);
        bool get_HighLimit_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_HighLimit_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // LocalizedText
        //
        void highState_FalseState_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& highState_FalseState_Variable(void);
        bool get_HighState_FalseState_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_HighState_FalseState_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // Boolean
        //
        void highState_Id_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& highState_Id_Variable(void);
        bool get_HighState_Id_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_HighState_Id_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // UtcTime
        //
        void highState_TransitionTime_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& highState_TransitionTime_Variable(void);
        bool get_HighState_TransitionTime_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_HighState_TransitionTime_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // LocalizedText
        //
        void highState_TrueState_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& highState_TrueState_Variable(void);
        bool get_HighState_TrueState_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_HighState_TrueState_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // LocalizedText
        //
        void highState_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& highState_Variable(void);
        bool get_HighState_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_HighState_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // NodeId
        //
        void inputNode_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& inputNode_Variable(void);
        bool get_InputNode_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_InputNode_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

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
        // LocalizedText
        //
        void latchedState_FalseState_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& latchedState_FalseState_Variable(void);
        bool get_LatchedState_FalseState_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_LatchedState_FalseState_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // Boolean
        //
        void latchedState_Id_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& latchedState_Id_Variable(void);
        bool get_LatchedState_Id_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_LatchedState_Id_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // UtcTime
        //
        void latchedState_TransitionTime_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& latchedState_TransitionTime_Variable(void);
        bool get_LatchedState_TransitionTime_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_LatchedState_TransitionTime_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // LocalizedText
        //
        void latchedState_TrueState_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& latchedState_TrueState_Variable(void);
        bool get_LatchedState_TrueState_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_LatchedState_TrueState_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // LocalizedText
        //
        void latchedState_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& latchedState_Variable(void);
        bool get_LatchedState_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_LatchedState_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // TimeZoneDataType
        //
        void localTime_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& localTime_Variable(void);
        bool get_LocalTime_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_LocalTime_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // Double
        //
        void lowLimit_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& lowLimit_Variable(void);
        bool get_LowLimit_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_LowLimit_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // Double
        //
        void lowLowLimit_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& lowLowLimit_Variable(void);
        bool get_LowLowLimit_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_LowLowLimit_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // LocalizedText
        //
        void lowLowState_FalseState_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& lowLowState_FalseState_Variable(void);
        bool get_LowLowState_FalseState_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_LowLowState_FalseState_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // Boolean
        //
        void lowLowState_Id_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& lowLowState_Id_Variable(void);
        bool get_LowLowState_Id_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_LowLowState_Id_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // UtcTime
        //
        void lowLowState_TransitionTime_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& lowLowState_TransitionTime_Variable(void);
        bool get_LowLowState_TransitionTime_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_LowLowState_TransitionTime_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // LocalizedText
        //
        void lowLowState_TrueState_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& lowLowState_TrueState_Variable(void);
        bool get_LowLowState_TrueState_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_LowLowState_TrueState_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // LocalizedText
        //
        void lowLowState_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& lowLowState_Variable(void);
        bool get_LowLowState_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_LowLowState_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // LocalizedText
        //
        void lowState_FalseState_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& lowState_FalseState_Variable(void);
        bool get_LowState_FalseState_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_LowState_FalseState_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // Boolean
        //
        void lowState_Id_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& lowState_Id_Variable(void);
        bool get_LowState_Id_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_LowState_Id_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // UtcTime
        //
        void lowState_TransitionTime_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& lowState_TransitionTime_Variable(void);
        bool get_LowState_TransitionTime_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_LowState_TransitionTime_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // LocalizedText
        //
        void lowState_TrueState_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& lowState_TrueState_Variable(void);
        bool get_LowState_TrueState_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_LowState_TrueState_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // LocalizedText
        //
        void lowState_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& lowState_Variable(void);
        bool get_LowState_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_LowState_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // Duration
        //
        void maxTimeShelved_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& maxTimeShelved_Variable(void);
        bool get_MaxTimeShelved_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_MaxTimeShelved_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // LocalizedText
        //
        void message_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& message_Variable(void);
        bool get_Message_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_Message_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // Duration
        //
        void offDelay_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& offDelay_Variable(void);
        bool get_OffDelay_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_OffDelay_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // Duration
        //
        void onDelay_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& onDelay_Variable(void);
        bool get_OnDelay_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_OnDelay_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // LocalizedText
        //
        void outOfServiceState_FalseState_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& outOfServiceState_FalseState_Variable(void);
        bool get_OutOfServiceState_FalseState_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_OutOfServiceState_FalseState_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // Boolean
        //
        void outOfServiceState_Id_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& outOfServiceState_Id_Variable(void);
        bool get_OutOfServiceState_Id_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_OutOfServiceState_Id_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // UtcTime
        //
        void outOfServiceState_TransitionTime_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& outOfServiceState_TransitionTime_Variable(void);
        bool get_OutOfServiceState_TransitionTime_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_OutOfServiceState_TransitionTime_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // LocalizedText
        //
        void outOfServiceState_TrueState_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& outOfServiceState_TrueState_Variable(void);
        bool get_OutOfServiceState_TrueState_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_OutOfServiceState_TrueState_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // LocalizedText
        //
        void outOfServiceState_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& outOfServiceState_Variable(void);
        bool get_OutOfServiceState_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_OutOfServiceState_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

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
        // Int16
        //
        void reAlarmRepeatCount_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& reAlarmRepeatCount_Variable(void);
        bool get_ReAlarmRepeatCount_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_ReAlarmRepeatCount_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // Duration
        //
        void reAlarmTime_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& reAlarmTime_Variable(void);
        bool get_ReAlarmTime_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_ReAlarmTime_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

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
        // NodeId
        //
        void shelvingState_CurrentState_Id_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& shelvingState_CurrentState_Id_Variable(void);
        bool get_ShelvingState_CurrentState_Id_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_ShelvingState_CurrentState_Id_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // LocalizedText
        //
        void shelvingState_CurrentState_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& shelvingState_CurrentState_Variable(void);
        bool get_ShelvingState_CurrentState_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_ShelvingState_CurrentState_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // NodeId
        //
        void shelvingState_LastTransition_Id_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& shelvingState_LastTransition_Id_Variable(void);
        bool get_ShelvingState_LastTransition_Id_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_ShelvingState_LastTransition_Id_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // UtcTime
        //
        void shelvingState_LastTransition_TransitionTime_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& shelvingState_LastTransition_TransitionTime_Variable(void);
        bool get_ShelvingState_LastTransition_TransitionTime_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_ShelvingState_LastTransition_TransitionTime_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // LocalizedText
        //
        void shelvingState_LastTransition_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& shelvingState_LastTransition_Variable(void);
        bool get_ShelvingState_LastTransition_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_ShelvingState_LastTransition_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // Duration
        //
        void shelvingState_UnshelveTime_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& shelvingState_UnshelveTime_Variable(void);
        bool get_ShelvingState_UnshelveTime_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_ShelvingState_UnshelveTime_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // LocalizedText
        //
        void silenceState_FalseState_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& silenceState_FalseState_Variable(void);
        bool get_SilenceState_FalseState_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_SilenceState_FalseState_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // Boolean
        //
        void silenceState_Id_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& silenceState_Id_Variable(void);
        bool get_SilenceState_Id_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_SilenceState_Id_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // UtcTime
        //
        void silenceState_TransitionTime_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& silenceState_TransitionTime_Variable(void);
        bool get_SilenceState_TransitionTime_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_SilenceState_TransitionTime_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // LocalizedText
        //
        void silenceState_TrueState_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& silenceState_TrueState_Variable(void);
        bool get_SilenceState_TrueState_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_SilenceState_TrueState_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // LocalizedText
        //
        void silenceState_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& silenceState_Variable(void);
        bool get_SilenceState_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_SilenceState_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

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
        // Boolean
        //
        void suppressedOrShelved_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& suppressedOrShelved_Variable(void);
        bool get_SuppressedOrShelved_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_SuppressedOrShelved_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // LocalizedText
        //
        void suppressedState_FalseState_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& suppressedState_FalseState_Variable(void);
        bool get_SuppressedState_FalseState_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_SuppressedState_FalseState_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // Boolean
        //
        void suppressedState_Id_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& suppressedState_Id_Variable(void);
        bool get_SuppressedState_Id_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_SuppressedState_Id_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // UtcTime
        //
        void suppressedState_TransitionTime_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& suppressedState_TransitionTime_Variable(void);
        bool get_SuppressedState_TransitionTime_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_SuppressedState_TransitionTime_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // LocalizedText
        //
        void suppressedState_TrueState_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& suppressedState_TrueState_Variable(void);
        bool get_SuppressedState_TrueState_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_SuppressedState_TrueState_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // LocalizedText
        //
        void suppressedState_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& suppressedState_Variable(void);
        bool get_SuppressedState_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_SuppressedState_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

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

        virtual void call_PlaceInService_Method(OpcUaStackCore::ApplicationMethodContext* applicationMethodContext);

        virtual void call_RemoveFromService_Method(OpcUaStackCore::ApplicationMethodContext* applicationMethodContext);

        virtual void call_Reset_Method(OpcUaStackCore::ApplicationMethodContext* applicationMethodContext);

        virtual void call_ShelvingState_OneShotShelve_Method(OpcUaStackCore::ApplicationMethodContext* applicationMethodContext);

        virtual void call_ShelvingState_TimedShelve_Method(OpcUaStackCore::ApplicationMethodContext* applicationMethodContext);

        virtual void call_ShelvingState_Unshelve_Method(OpcUaStackCore::ApplicationMethodContext* applicationMethodContext);

        virtual void call_Silence_Method(OpcUaStackCore::ApplicationMethodContext* applicationMethodContext);

        virtual void call_Suppress_Method(OpcUaStackCore::ApplicationMethodContext* applicationMethodContext);

        virtual void call_Unsuppress_Method(OpcUaStackCore::ApplicationMethodContext* applicationMethodContext);
    
      private:
        ServerVariable::SPtr ackedState_FalseState_Variable_;
        ServerVariable::SPtr ackedState_Id_Variable_;
        ServerVariable::SPtr ackedState_TransitionTime_Variable_;
        ServerVariable::SPtr ackedState_TrueState_Variable_;
        ServerVariable::SPtr ackedState_Variable_;
        ServerVariable::SPtr activeState_EffectiveDisplayName_Variable_;
        ServerVariable::SPtr activeState_EffectiveTransitionTime_Variable_;
        ServerVariable::SPtr activeState_FalseState_Variable_;
        ServerVariable::SPtr activeState_Id_Variable_;
        ServerVariable::SPtr activeState_TransitionTime_Variable_;
        ServerVariable::SPtr activeState_TrueState_Variable_;
        ServerVariable::SPtr activeState_Variable_;
        ServerVariable::SPtr audibleEnabled_Variable_;
        ServerVariable::SPtr audibleSound_Variable_;
        ServerVariable::SPtr baseHighHighLimit_Variable_;
        ServerVariable::SPtr baseHighLimit_Variable_;
        ServerVariable::SPtr baseLowLimit_Variable_;
        ServerVariable::SPtr baseLowLowLimit_Variable_;
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
        ServerVariable::SPtr firstInGroupFlag_Variable_;
        ServerVariable::SPtr highHighLimit_Variable_;
        ServerVariable::SPtr highHighState_FalseState_Variable_;
        ServerVariable::SPtr highHighState_Id_Variable_;
        ServerVariable::SPtr highHighState_TransitionTime_Variable_;
        ServerVariable::SPtr highHighState_TrueState_Variable_;
        ServerVariable::SPtr highHighState_Variable_;
        ServerVariable::SPtr highLimit_Variable_;
        ServerVariable::SPtr highState_FalseState_Variable_;
        ServerVariable::SPtr highState_Id_Variable_;
        ServerVariable::SPtr highState_TransitionTime_Variable_;
        ServerVariable::SPtr highState_TrueState_Variable_;
        ServerVariable::SPtr highState_Variable_;
        ServerVariable::SPtr inputNode_Variable_;
        ServerVariable::SPtr lastSeverity_SourceTimestamp_Variable_;
        ServerVariable::SPtr lastSeverity_Variable_;
        ServerVariable::SPtr latchedState_FalseState_Variable_;
        ServerVariable::SPtr latchedState_Id_Variable_;
        ServerVariable::SPtr latchedState_TransitionTime_Variable_;
        ServerVariable::SPtr latchedState_TrueState_Variable_;
        ServerVariable::SPtr latchedState_Variable_;
        ServerVariable::SPtr localTime_Variable_;
        ServerVariable::SPtr lowLimit_Variable_;
        ServerVariable::SPtr lowLowLimit_Variable_;
        ServerVariable::SPtr lowLowState_FalseState_Variable_;
        ServerVariable::SPtr lowLowState_Id_Variable_;
        ServerVariable::SPtr lowLowState_TransitionTime_Variable_;
        ServerVariable::SPtr lowLowState_TrueState_Variable_;
        ServerVariable::SPtr lowLowState_Variable_;
        ServerVariable::SPtr lowState_FalseState_Variable_;
        ServerVariable::SPtr lowState_Id_Variable_;
        ServerVariable::SPtr lowState_TransitionTime_Variable_;
        ServerVariable::SPtr lowState_TrueState_Variable_;
        ServerVariable::SPtr lowState_Variable_;
        ServerVariable::SPtr maxTimeShelved_Variable_;
        ServerVariable::SPtr message_Variable_;
        ServerVariable::SPtr offDelay_Variable_;
        ServerVariable::SPtr onDelay_Variable_;
        ServerVariable::SPtr outOfServiceState_FalseState_Variable_;
        ServerVariable::SPtr outOfServiceState_Id_Variable_;
        ServerVariable::SPtr outOfServiceState_TransitionTime_Variable_;
        ServerVariable::SPtr outOfServiceState_TrueState_Variable_;
        ServerVariable::SPtr outOfServiceState_Variable_;
        ServerVariable::SPtr quality_SourceTimestamp_Variable_;
        ServerVariable::SPtr quality_Variable_;
        ServerVariable::SPtr reAlarmRepeatCount_Variable_;
        ServerVariable::SPtr reAlarmTime_Variable_;
        ServerVariable::SPtr receiveTime_Variable_;
        ServerVariable::SPtr retain_Variable_;
        ServerVariable::SPtr severity_Variable_;
        ServerVariable::SPtr shelvingState_CurrentState_Id_Variable_;
        ServerVariable::SPtr shelvingState_CurrentState_Variable_;
        ServerVariable::SPtr shelvingState_LastTransition_Id_Variable_;
        ServerVariable::SPtr shelvingState_LastTransition_TransitionTime_Variable_;
        ServerVariable::SPtr shelvingState_LastTransition_Variable_;
        ServerVariable::SPtr shelvingState_UnshelveTime_Variable_;
        ServerVariable::SPtr silenceState_FalseState_Variable_;
        ServerVariable::SPtr silenceState_Id_Variable_;
        ServerVariable::SPtr silenceState_TransitionTime_Variable_;
        ServerVariable::SPtr silenceState_TrueState_Variable_;
        ServerVariable::SPtr silenceState_Variable_;
        ServerVariable::SPtr sourceName_Variable_;
        ServerVariable::SPtr sourceNode_Variable_;
        ServerVariable::SPtr suppressedOrShelved_Variable_;
        ServerVariable::SPtr suppressedState_FalseState_Variable_;
        ServerVariable::SPtr suppressedState_Id_Variable_;
        ServerVariable::SPtr suppressedState_TransitionTime_Variable_;
        ServerVariable::SPtr suppressedState_TrueState_Variable_;
        ServerVariable::SPtr suppressedState_Variable_;
        ServerVariable::SPtr time_Variable_;
        ServerMethod::SPtr acknowledge_Method_;
        ServerMethod::SPtr addComment_Method_;
        ServerMethod::SPtr confirm_Method_;
        ServerMethod::SPtr disable_Method_;
        ServerMethod::SPtr enable_Method_;
        ServerMethod::SPtr placeInService_Method_;
        ServerMethod::SPtr removeFromService_Method_;
        ServerMethod::SPtr reset_Method_;
        ServerMethod::SPtr shelvingState_OneShotShelve_Method_;
        ServerMethod::SPtr shelvingState_TimedShelve_Method_;
        ServerMethod::SPtr shelvingState_Unshelve_Method_;
        ServerMethod::SPtr silence_Method_;
        ServerMethod::SPtr suppress_Method_;
        ServerMethod::SPtr unsuppress_Method_;
   
   };

}

#endif
