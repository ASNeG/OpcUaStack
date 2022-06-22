/*
    ObjectTypeClass: AuditHistoryAtTimeDeleteEventType

    Generated Source Code - please do not change this source code

    ObjectTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

    Autor:     Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackServer_AuditHistoryAtTimeDeleteEventType_h__
#define __OpcUaStackServer_AuditHistoryAtTimeDeleteEventType_h__

#include "OpcUaStackServer/StandardVariableType/VariableBase.h"
#include "OpcUaStackServer/StandardObjectType/ObjectBase.h"

namespace OpcUaStackServer
{
   
   class DLLEXPORT AuditHistoryAtTimeDeleteEventType
   : public ObjectBase
   {
     public:
       typedef boost::shared_ptr<AuditHistoryAtTimeDeleteEventType> SPtr;
       typedef std::vector<AuditHistoryAtTimeDeleteEventType::SPtr> Vec;
   
       AuditHistoryAtTimeDeleteEventType(void);
       AuditHistoryAtTimeDeleteEventType(const AuditHistoryAtTimeDeleteEventType& value);
       virtual ~AuditHistoryAtTimeDeleteEventType(void);

        //
        // UtcTime
        //
        void actionTimeStamp_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& actionTimeStamp_Variable(void);
        bool get_ActionTimeStamp_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_ActionTimeStamp_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // String
        //
        void clientAuditEntryId_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& clientAuditEntryId_Variable(void);
        bool get_ClientAuditEntryId_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_ClientAuditEntryId_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // String
        //
        void clientUserId_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& clientUserId_Variable(void);
        bool get_ClientUserId_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_ClientUserId_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

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
        // DataValue (Array)
        //
        void oldValues_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& oldValues_Variable(void);
        bool get_OldValues_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_OldValues_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // NodeId
        //
        void parameterDataTypeId_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& parameterDataTypeId_Variable(void);
        bool get_ParameterDataTypeId_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_ParameterDataTypeId_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // UtcTime
        //
        void receiveTime_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& receiveTime_Variable(void);
        bool get_ReceiveTime_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_ReceiveTime_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // UtcTime (Array)
        //
        void reqTimes_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& reqTimes_Variable(void);
        bool get_ReqTimes_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_ReqTimes_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // String
        //
        void serverId_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& serverId_Variable(void);
        bool get_ServerId_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_ServerId_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

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
        // Boolean
        //
        void status_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& status_Variable(void);
        bool get_Status_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_Status_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // UtcTime
        //
        void time_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& time_Variable(void);
        bool get_Time_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_Time_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // NodeId
        //
        void updatedNode_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& updatedNode_Variable(void);
        bool get_UpdatedNode_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_UpdatedNode_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);
    
      private:
        ServerVariable::SPtr actionTimeStamp_Variable_;
        ServerVariable::SPtr clientAuditEntryId_Variable_;
        ServerVariable::SPtr clientUserId_Variable_;
        ServerVariable::SPtr eventId_Variable_;
        ServerVariable::SPtr eventType_Variable_;
        ServerVariable::SPtr localTime_Variable_;
        ServerVariable::SPtr message_Variable_;
        ServerVariable::SPtr oldValues_Variable_;
        ServerVariable::SPtr parameterDataTypeId_Variable_;
        ServerVariable::SPtr receiveTime_Variable_;
        ServerVariable::SPtr reqTimes_Variable_;
        ServerVariable::SPtr serverId_Variable_;
        ServerVariable::SPtr severity_Variable_;
        ServerVariable::SPtr sourceName_Variable_;
        ServerVariable::SPtr sourceNode_Variable_;
        ServerVariable::SPtr status_Variable_;
        ServerVariable::SPtr time_Variable_;
        ServerVariable::SPtr updatedNode_Variable_;
   
   };

}

#endif
