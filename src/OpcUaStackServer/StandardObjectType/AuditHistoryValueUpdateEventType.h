/*
    ObjectTypeClass: AuditHistoryValueUpdateEventType

    Generated Source Code - please do not change this source code

    ObjectTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

    Autor:     Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackServer_AuditHistoryValueUpdateEventType_h__
#define __OpcUaStackServer_AuditHistoryValueUpdateEventType_h__

#include "OpcUaStackServer/StandardVariableType/VariableBase.h"
#include "OpcUaStackServer/StandardObjectType/ObjectBase.h"

namespace OpcUaStackServer
{
   
   class DLLEXPORT AuditHistoryValueUpdateEventType
   : public ObjectBase
   {
     public:
       typedef boost::shared_ptr<AuditHistoryValueUpdateEventType> SPtr;
       typedef std::vector<AuditHistoryValueUpdateEventType::SPtr> Vec;
   
       AuditHistoryValueUpdateEventType(void);
       AuditHistoryValueUpdateEventType(const AuditHistoryValueUpdateEventType& value);
       virtual ~AuditHistoryValueUpdateEventType(void);

        //
        // UtcTime
        //
        void actionTimeStamp_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& actionTimeStamp_Variable(void);
        bool get_ActionTimeStamp_Variable(OpcUaDataValue& dataValue);
        bool set_ActionTimeStamp_Variable(const OpcUaDataValue& dataValue);

        //
        // String
        //
        void clientAuditEntryId_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& clientAuditEntryId_Variable(void);
        bool get_ClientAuditEntryId_Variable(OpcUaDataValue& dataValue);
        bool set_ClientAuditEntryId_Variable(const OpcUaDataValue& dataValue);

        //
        // String
        //
        void clientUserId_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& clientUserId_Variable(void);
        bool get_ClientUserId_Variable(OpcUaDataValue& dataValue);
        bool set_ClientUserId_Variable(const OpcUaDataValue& dataValue);

        //
        // ByteString
        //
        void eventId_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& eventId_Variable(void);
        bool get_EventId_Variable(OpcUaDataValue& dataValue);
        bool set_EventId_Variable(const OpcUaDataValue& dataValue);

        //
        // NodeId
        //
        void eventType_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& eventType_Variable(void);
        bool get_EventType_Variable(OpcUaDataValue& dataValue);
        bool set_EventType_Variable(const OpcUaDataValue& dataValue);

        //
        // TimeZoneDataType
        //
        void localTime_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& localTime_Variable(void);
        bool get_LocalTime_Variable(OpcUaDataValue& dataValue);
        bool set_LocalTime_Variable(const OpcUaDataValue& dataValue);

        //
        // LocalizedText
        //
        void message_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& message_Variable(void);
        bool get_Message_Variable(OpcUaDataValue& dataValue);
        bool set_Message_Variable(const OpcUaDataValue& dataValue);

        //
        // DataValue (Array)
        //
        void newValues_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& newValues_Variable(void);
        bool get_NewValues_Variable(OpcUaDataValue& dataValue);
        bool set_NewValues_Variable(const OpcUaDataValue& dataValue);

        //
        // DataValue (Array)
        //
        void oldValues_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& oldValues_Variable(void);
        bool get_OldValues_Variable(OpcUaDataValue& dataValue);
        bool set_OldValues_Variable(const OpcUaDataValue& dataValue);

        //
        // NodeId
        //
        void parameterDataTypeId_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& parameterDataTypeId_Variable(void);
        bool get_ParameterDataTypeId_Variable(OpcUaDataValue& dataValue);
        bool set_ParameterDataTypeId_Variable(const OpcUaDataValue& dataValue);

        //
        // PerformUpdateType
        //
        void performInsertReplace_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& performInsertReplace_Variable(void);
        bool get_PerformInsertReplace_Variable(OpcUaDataValue& dataValue);
        bool set_PerformInsertReplace_Variable(const OpcUaDataValue& dataValue);

        //
        // UtcTime
        //
        void receiveTime_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& receiveTime_Variable(void);
        bool get_ReceiveTime_Variable(OpcUaDataValue& dataValue);
        bool set_ReceiveTime_Variable(const OpcUaDataValue& dataValue);

        //
        // String
        //
        void serverId_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& serverId_Variable(void);
        bool get_ServerId_Variable(OpcUaDataValue& dataValue);
        bool set_ServerId_Variable(const OpcUaDataValue& dataValue);

        //
        // UInt16
        //
        void severity_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& severity_Variable(void);
        bool get_Severity_Variable(OpcUaDataValue& dataValue);
        bool set_Severity_Variable(const OpcUaDataValue& dataValue);

        //
        // String
        //
        void sourceName_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& sourceName_Variable(void);
        bool get_SourceName_Variable(OpcUaDataValue& dataValue);
        bool set_SourceName_Variable(const OpcUaDataValue& dataValue);

        //
        // NodeId
        //
        void sourceNode_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& sourceNode_Variable(void);
        bool get_SourceNode_Variable(OpcUaDataValue& dataValue);
        bool set_SourceNode_Variable(const OpcUaDataValue& dataValue);

        //
        // Boolean
        //
        void status_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& status_Variable(void);
        bool get_Status_Variable(OpcUaDataValue& dataValue);
        bool set_Status_Variable(const OpcUaDataValue& dataValue);

        //
        // UtcTime
        //
        void time_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& time_Variable(void);
        bool get_Time_Variable(OpcUaDataValue& dataValue);
        bool set_Time_Variable(const OpcUaDataValue& dataValue);

        //
        // NodeId
        //
        void updatedNode_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& updatedNode_Variable(void);
        bool get_UpdatedNode_Variable(OpcUaDataValue& dataValue);
        bool set_UpdatedNode_Variable(const OpcUaDataValue& dataValue);
    
      private:
        ServerVariable::SPtr actionTimeStamp_Variable_;
        ServerVariable::SPtr clientAuditEntryId_Variable_;
        ServerVariable::SPtr clientUserId_Variable_;
        ServerVariable::SPtr eventId_Variable_;
        ServerVariable::SPtr eventType_Variable_;
        ServerVariable::SPtr localTime_Variable_;
        ServerVariable::SPtr message_Variable_;
        ServerVariable::SPtr newValues_Variable_;
        ServerVariable::SPtr oldValues_Variable_;
        ServerVariable::SPtr parameterDataTypeId_Variable_;
        ServerVariable::SPtr performInsertReplace_Variable_;
        ServerVariable::SPtr receiveTime_Variable_;
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
