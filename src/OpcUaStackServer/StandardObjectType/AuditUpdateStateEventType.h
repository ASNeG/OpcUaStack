/*
    ObjectTypeClass: AuditUpdateStateEventType

    Generated Source Code - please do not change this source code

    ObjectTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

    Autor:     Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackServer_AuditUpdateStateEventType_h__
#define __OpcUaStackServer_AuditUpdateStateEventType_h__

#include "OpcUaStackServer/StandardVariableType/VariableBase.h"
#include "OpcUaStackServer/StandardObjectType/ObjectBase.h"

namespace OpcUaStackServer
{
   
   class DLLEXPORT AuditUpdateStateEventType
   : public ObjectBase
   {
     public:
       typedef boost::shared_ptr<AuditUpdateStateEventType> SPtr;
       typedef std::vector<AuditUpdateStateEventType::SPtr> Vec;
   
       AuditUpdateStateEventType(void);
       AuditUpdateStateEventType(const AuditUpdateStateEventType& value);
       virtual ~AuditUpdateStateEventType(void);

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
        // NodeId
        //
        void methodId_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& methodId_Variable(void);
        bool get_MethodId_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_MethodId_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // Variant
        //
        void newStateId_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& newStateId_Variable(void);
        bool get_NewStateId_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_NewStateId_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // Variant
        //
        void oldStateId_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& oldStateId_Variable(void);
        bool get_OldStateId_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_OldStateId_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

        //
        // UtcTime
        //
        void receiveTime_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& receiveTime_Variable(void);
        bool get_ReceiveTime_Variable(OpcUaStackCore::OpcUaDataValue& dataValue);
        bool set_ReceiveTime_Variable(const OpcUaStackCore::OpcUaDataValue& dataValue);

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
    
      private:
        ServerVariable::SPtr actionTimeStamp_Variable_;
        ServerVariable::SPtr clientAuditEntryId_Variable_;
        ServerVariable::SPtr clientUserId_Variable_;
        ServerVariable::SPtr eventId_Variable_;
        ServerVariable::SPtr eventType_Variable_;
        ServerVariable::SPtr localTime_Variable_;
        ServerVariable::SPtr message_Variable_;
        ServerVariable::SPtr methodId_Variable_;
        ServerVariable::SPtr newStateId_Variable_;
        ServerVariable::SPtr oldStateId_Variable_;
        ServerVariable::SPtr receiveTime_Variable_;
        ServerVariable::SPtr serverId_Variable_;
        ServerVariable::SPtr severity_Variable_;
        ServerVariable::SPtr sourceName_Variable_;
        ServerVariable::SPtr sourceNode_Variable_;
        ServerVariable::SPtr status_Variable_;
        ServerVariable::SPtr time_Variable_;
   
   };

}

#endif
