/*
    ObjectTypeClass: TransitionEventType

    Generated Source Code - please do not change this source code

    ObjectTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

    Autor:     Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackServer_TransitionEventType_h__
#define __OpcUaStackServer_TransitionEventType_h__

#include "OpcUaStackServer/StandardVariableType/VariableBase.h"
#include "OpcUaStackServer/StandardObjectType/ObjectBase.h"

namespace OpcUaStackServer
{
   
   class DLLEXPORT TransitionEventType
   : public ObjectBase
   {
     public:
       typedef boost::shared_ptr<TransitionEventType> SPtr;
       typedef std::vector<TransitionEventType::SPtr> Vec;
   
       TransitionEventType(void);
       TransitionEventType(const TransitionEventType& value);
       virtual ~TransitionEventType(void);

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
        // Variant
        //
        void fromState_Id_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& fromState_Id_Variable(void);
        bool get_FromState_Id_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_FromState_Id_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // LocalizedText
        //
        void fromState_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& fromState_Variable(void);
        bool get_FromState_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_FromState_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

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
        void receiveTime_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& receiveTime_Variable(void);
        bool get_ReceiveTime_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_ReceiveTime_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

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

        //
        // Variant
        //
        void toState_Id_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& toState_Id_Variable(void);
        bool get_ToState_Id_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_ToState_Id_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // LocalizedText
        //
        void toState_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& toState_Variable(void);
        bool get_ToState_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_ToState_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // Variant
        //
        void transition_Id_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& transition_Id_Variable(void);
        bool get_Transition_Id_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_Transition_Id_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // LocalizedText
        //
        void transition_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& transition_Variable(void);
        bool get_Transition_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_Transition_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);
    
      private:
        ServerVariable::SPtr eventId_Variable_;
        ServerVariable::SPtr eventType_Variable_;
        ServerVariable::SPtr fromState_Id_Variable_;
        ServerVariable::SPtr fromState_Variable_;
        ServerVariable::SPtr localTime_Variable_;
        ServerVariable::SPtr message_Variable_;
        ServerVariable::SPtr receiveTime_Variable_;
        ServerVariable::SPtr severity_Variable_;
        ServerVariable::SPtr sourceName_Variable_;
        ServerVariable::SPtr sourceNode_Variable_;
        ServerVariable::SPtr time_Variable_;
        ServerVariable::SPtr toState_Id_Variable_;
        ServerVariable::SPtr toState_Variable_;
        ServerVariable::SPtr transition_Id_Variable_;
        ServerVariable::SPtr transition_Variable_;
   
   };

}

#endif
